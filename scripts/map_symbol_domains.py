"""Map static dynamic-symbol candidates within DT_NEEDED candidate closures.

Reads the existing local inventories only. No firmware files or external
services are opened; no target code is executed. These are naming-based
inferences and binding candidates, never observed calls or runtime bindings.
"""

from __future__ import annotations

import argparse
from collections import Counter, defaultdict, deque
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path, PurePosixPath
import re
import tempfile
from typing import Any


PROJECT = Path(__file__).resolve().parents[1]
DOMAIN_RULES = {
    "audio_volume_sound": r"audio|sound|volume|mute(?!x)|speaker|headphone|spdif|pcm|alsa|amplifier|I2S",
    "ir_key_remote": r"remote|keycode|keypress|keydown|keyup|keyevent|key_event|irkey|ir_key|(?-i:(?:^|_)IR(?:_|[A-Z]))|libdrvIR|mapi_IR|MDrv_IR|MApi_IR|RC5|RC6|KeyInput|KeyHandler|SendKey|GetKey|OnKey|ProcessKey",
    "cec_source_power": r"(?-i:CEC)|(?:^|_)cec(?:_|\.|$)|cec_Api|cec_Common|CecPhysical|(?:libapi|libar_|mapi_|MDrv_|MApi_)cec|HDMI|standby|power|wakeup|InputSource|SourceType|SwitchSource|SetSource|GetSource",
    "resource_brand_osd_directfb_muf": r"resource|brand|OSD|DirectFB|(?:^|_)MUF|font|bitmap|theme|logo|UiManager|UIManager|Draw|Widget|Window|Gui|GUI",
    "settings_database": r"setting|database|sqlite|iniparser|configuration|Config|Preference|SysDB|UserDB|SaveDB|LoadDB",
}
COMPILED_RULES = {name: re.compile(pattern, re.IGNORECASE) for name, pattern in DOMAIN_RULES.items()}
SUPPORT_RULES = {
    "network_connectivity": r"network|socket|ethernet|wifi|wlan|http|ssl|curl|upnp|dlna|dns|DHCP",
    "broadcast_tuner_demux": r"dvb|demod|tuner|demux|DMX|channel|serviceinfo|teletext|subtitle",
    "media_codec_player": r"codec|mpeg|ffmpeg|player|jpeg|png|vdec|vdplayer|mp3|avformat|avcodec",
    "system_runtime_storage": r"libc[.-]|libm[.-]|libpthread|ld[-.]|libstdc|libgcc|busybox|linux|filesystem|msfs|flash|zlib|libz[.-]",
}
COMPILED_SUPPORT = {name: re.compile(pattern, re.IGNORECASE) for name, pattern in SUPPORT_RULES.items()}
FOCUS_NAMES = {
    "libmuf.so", "libar_cec.so", "libMStarSDK.so", "libdevice_customer.so",
    "libapiCEC.so", "libdrvIR.so", "libapiAUDIO.so",
}
LIMITATIONS = [
    "DT_NEEDED and dynamic-symbol tables are static declarations, not observed calls, xrefs or runtime bindings.",
    "Mount map, dynamic-loader search order, interposition, weak-symbol selection and LD_PRELOAD are unverified.",
    "Only candidate ELF paths in the declared DT_NEEDED closure are considered; symlink candidates that have no matching SONAME ELF remain unresolved.",
    "Unversioned imports can match multiple versions; explicit import versions require an identical exported version name.",
    "Domain categories are inferred from filenames and symbol spelling; function names do not establish behavior or call sites.",
    "dlopen/dlsym-loaded providers, main-executable global scope and runtime-only modules can be absent from a module's DT_NEEDED closure.",
    "Defined symbols in the same module are not reported as dependency bindings. Symbol aliases, IFUNC and copy-relocation behavior require deeper analysis.",
]


def symbol_identity(name: str) -> tuple[str, str | None]:
    """Retain spelling while separating readelf's version index annotation."""
    selector = re.sub(r"\s+\(\d+\)$", "", name)
    if "@@" in selector:
        base, version = selector.split("@@", 1)
        return base, version
    if "@" in selector:
        base, version = selector.split("@", 1)
        return base, version
    return selector, None


def matching_domains(text: str) -> list[str]:
    return [name for name, pattern in COMPILED_RULES.items() if pattern.search(text)]


def import_rows(elf: dict[str, Any]) -> list[dict[str, Any]]:
    return [row for row in elf.get("symbols", []) if row["table"] == ".dynsym" and row["section"] == "UND" and row["name"] and row["binding"] != "LOCAL"]


def export_rows(elf: dict[str, Any]) -> list[dict[str, Any]]:
    return [row for row in elf.get("symbols", []) if row["table"] == ".dynsym" and row["section"] != "UND" and row["name"] and row["binding"] in {"GLOBAL", "WEAK", "UNIQUE"} and row["visibility"] in {"DEFAULT", "PROTECTED"}]


def dependency_graph(
    modules: dict[str, dict[str, Any]], dependency_inventory: dict[str, Any],
) -> tuple[dict[str, dict[str, list[str]]], list[dict[str, Any]]]:
    graph: dict[str, dict[str, list[str]]] = {path: {} for path in modules}
    unresolved = []
    for edge in dependency_inventory["edges"]:
        source = edge["source"]
        if source not in modules:
            continue
        targets = [item["path"] for item in edge["candidates"] if item["path"] in modules]
        if not targets:
            unresolved.append({"source": source, "needed": edge["needed"], "candidate_metadata": edge["candidates"], "status": "no_candidate_ELF_in_inventory"})
        for target in targets:
            graph[source].setdefault(target, []).append(edge["needed"])
    return graph, unresolved


def closure_paths(source: str, graph: dict[str, dict[str, list[str]]]) -> dict[str, list[str]]:
    """One shortest dependency-candidate path is a witness, not a loader order."""
    paths = {source: [source]}
    queue = deque([source])
    while queue:
        current = queue.popleft()
        for target in sorted(graph.get(current, {})):
            if target not in paths:
                paths[target] = paths[current] + [target]
                queue.append(target)
    paths.pop(source, None)
    return paths


def build_reports(elf_inventory: dict[str, Any], dependency_inventory: dict[str, Any]) -> tuple[dict[str, Any], dict[str, Any]]:
    modules = {elf["path"]: elf for elf in elf_inventory["elfs"]}
    graph, unresolved_dependencies = dependency_graph(modules, dependency_inventory)
    closures = {source: closure_paths(source, graph) for source in modules}
    exporters: dict[str, list[tuple[str, dict[str, Any], str | None]]] = defaultdict(list)
    for path, elf in modules.items():
        for symbol in export_rows(elf):
            base, version = symbol_identity(symbol["name"])
            exporters[base].append((path, symbol, version))

    bindings = []
    unmatched = []
    pair_witnesses: dict[tuple[str, str], list[dict[str, Any]]] = defaultdict(list)
    domain_counts: Counter[str] = Counter()
    source_counts: dict[str, Counter[str]] = defaultdict(Counter)
    for source in sorted(modules):
        for symbol in import_rows(modules[source]):
            base, version = symbol_identity(symbol["name"])
            domains = matching_domains(base)
            candidates = []
            for target, exported, exported_version in exporters.get(base, []):
                if target not in closures[source] or (version is not None and version != exported_version):
                    continue
                candidates.append({
                    "module": target, "export_name": exported["name"],
                    "export_symbol_index": exported["index"], "export_address": exported["value"],
                    "export_binding": exported["binding"], "export_visibility": exported["visibility"],
                    "version_match": "exact_explicit_version" if version else "unversioned_import_version_selection_unverified",
                    "dependency_path": closures[source][target],
                    "direct_DT_NEEDED_candidate": target in graph[source],
                    "status": "static_symbol_binding_candidate", "runtime_binding_verified": False,
                })
                if target in graph[source]:
                    pair_witnesses[(source, target)].append({
                        "import_name": symbol["name"], "import_symbol_index": symbol["index"],
                        "export_name": exported["name"], "export_address": exported["value"],
                        "domains_inferred": domains,
                    })
            source_counts[source]["import_rows"] += 1
            if candidates:
                source_counts[source]["with_candidates"] += 1
                for domain in domains:
                    domain_counts[domain] += 1
                bindings.append({
                    "source": source, "import_name": symbol["name"],
                    "import_symbol_index": symbol["index"], "import_binding": symbol["binding"],
                    "domains_inferred": domains, "candidates": candidates,
                    "candidate_count": len(candidates), "call_or_xref_observed": False,
                })
            else:
                source_counts[source]["without_candidates"] += 1
                unmatched.append({
                    "source": source, "import_name": symbol["name"], "import_symbol_index": symbol["index"],
                    "domains_inferred": domains, "status": "no_export_match_in_DT_NEEDED_candidate_closure",
                    "global_name_match_outside_closure": any(target != source and target not in closures[source] for target, _, _ in exporters.get(base, [])),
                })

    focused_paths = []
    roots = [source for source in modules if PurePosixPath(source).name == "dvbt_board"]
    focused_targets = [target for target in modules if PurePosixPath(target).name in FOCUS_NAMES or re.match(r"libmsrv_.*_customer\.so$", PurePosixPath(target).name)]
    for root in roots:
        for target in sorted(focused_targets):
            provided_domains = [
                {"name": row["name"], "address": row["value"], "domains_inferred": matching_domains(row["name"])}
                for row in export_rows(modules[target]) if matching_domains(row["name"])
            ]
            path = closures[root].get(target)
            if path is None:
                focused_paths.append({"root": root, "target": target, "status": "not_in_DT_NEEDED_candidate_closure"})
                continue
            hops = []
            for source, destination in zip(path, path[1:]):
                witnesses = pair_witnesses[(source, destination)]
                domain_witnesses = [row for row in witnesses if row["domains_inferred"]]
                selected = domain_witnesses if domain_witnesses else witnesses
                hops.append({
                    "source": source, "target": destination, "needed_names": graph[source][destination],
                    "matching_import_export_count": len(witnesses),
                    "domain_symbol_witnesses": selected[:24], "witnesses_shown": min(24, len(selected)),
                    "witnesses_total_in_selected_scope": len(selected), "witness_selection": "domain_matches" if domain_witnesses else "all_matching_symbols",
                    "status": "static_dependency_and_symbol_candidates", "call_or_xref_observed": False,
                })
            focused_paths.append({
                "root": root, "target": target, "dependency_path": path, "hops": hops,
                "target_domain_export_examples": provided_domains[:32],
                "target_domain_export_count": len(provided_domains),
                "target_exports_are_import_bindings": False,
                "status": "inferred_dependency_path_with_static_symbol_candidates",
            })

    focused_pairs = []
    focus_set = set(focused_targets) | set(roots)
    for source in sorted(focus_set):
        for target in sorted(graph[source]):
            if target in focus_set:
                witnesses = pair_witnesses[(source, target)]
                focused_pairs.append({
                    "source": source, "target": target, "needed_names": graph[source][target],
                    "symbol_witness_count": len(witnesses), "symbol_witnesses": witnesses,
                    "status": "direct_DT_NEEDED_candidate_with_static_symbol_candidates",
                    "call_or_xref_observed": False,
                })

    classifications = []
    for path in sorted(modules):
        elf = modules[path]
        symbol_names = [row["name"] for row in elf.get("symbols", []) if row["name"]]
        name_domains = matching_domains(PurePosixPath(path).name)
        symbol_matches: dict[str, list[str]] = {
            domain: sorted({name for name in symbol_names if pattern.search(name)})
            for domain, pattern in COMPILED_RULES.items()
        }
        categories = []
        for domain in DOMAIN_RULES:
            matches = symbol_matches[domain]
            if matches or domain in name_domains:
                categories.append({
                    "category": domain, "classification": "inferred", "confidence": "name_based_only",
                    "filename_match": domain in name_domains, "matching_symbol_count": len(matches),
                    "symbol_examples": matches[:16], "examples_are_complete": len(matches) <= 16,
                })
        support = [name for name, pattern in COMPILED_SUPPORT.items() if pattern.search(PurePosixPath(path).name)]
        classifications.append({
            "module": path, "sha256": elf.get("sha256"), "soname": elf.get("soname"),
            "header_type": elf.get("header", {}).get("Type"),
            "classification": "inferred", "categories": categories,
            "support_categories_inferred_from_filename": support,
            "unclassified_in_requested_domains": not categories,
            "counts": elf.get("counts"), "import_candidate_counts": dict(source_counts[path]),
            "DT_NEEDED_candidate_closure_size": len(closures[path]),
        })

    symbol_report = {
        "counts": {"modules": len(modules), "import_rows": sum(row["import_rows"] for row in source_counts.values()), "import_rows_with_candidates": len(bindings), "import_rows_without_candidates": len(unmatched), "total_candidate_bindings": sum(len(row["candidates"]) for row in bindings), "domain_import_rows_with_candidates": dict(domain_counts)},
        "bindings": bindings, "unmatched_imports": unmatched,
        "unresolved_DT_NEEDED": unresolved_dependencies,
        "focus_paths_from_dvbt_board": focused_paths,
        "focus_direct_pairs": focused_pairs,
    }
    category_report = {
        "counts": {"modules": len(classifications), "unclassified_in_requested_domains": sum(item["unclassified_in_requested_domains"] for item in classifications), "modules_by_domain": {domain: sum(any(category["category"] == domain for category in item["categories"]) for item in classifications) for domain in DOMAIN_RULES}},
        "domain_rules": DOMAIN_RULES, "support_rules": SUPPORT_RULES, "modules": classifications,
    }
    return symbol_report, category_report


def read_json(path: Path) -> tuple[dict[str, Any], str]:
    descriptor = os.open(path, os.O_RDONLY | os.O_NOFOLLOW)
    with os.fdopen(descriptor, "rb") as stream:
        content = stream.read()
    return json.loads(content), hashlib.sha256(content).hexdigest()


def write_json(path: Path, document: dict[str, Any]) -> None:
    temporary = None
    try:
        with tempfile.NamedTemporaryFile(mode="w", encoding="utf-8", dir=path.parent, prefix="." + path.name, suffix=".partial", delete=False) as stream:
            temporary = Path(stream.name)
            json.dump(document, stream, ensure_ascii=True, indent=2)
            stream.write("\n")
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temporary, path)
    finally:
        if temporary is not None and temporary.exists():
            temporary.unlink()


def self_test() -> None:
    def symbol(name: str, section: str, index: int = 1) -> dict[str, Any]:
        return {"table": ".dynsym", "section": section, "name": name, "binding": "GLOBAL", "visibility": "DEFAULT", "index": index, "value": "0x1000"}

    source = {"path": "app", "symbols": [symbol("SetVolume@V1 (2)", "UND"), symbol("RemoteKey", "UND", 2)]}
    bridge = {"path": "bridge.so", "symbols": []}
    provider = {"path": "libaudio.so", "symbols": [symbol("SetVolume@@V1", "12")]}
    wrong_version = {"path": "libwrong.so", "symbols": [symbol("SetVolume@@V2", "12")]}
    unrelated = {"path": "unrelated.so", "symbols": [symbol("RemoteKey", "12")]}
    deps = {"edges": [
        {"source": "app", "needed": "bridge.so", "candidates": [{"path": "bridge.so"}]},
        {"source": "bridge.so", "needed": "libaudio.so", "candidates": [{"path": "libaudio.so"}]},
        {"source": "bridge.so", "needed": "app", "candidates": [{"path": "app"}]},
        {"source": "app", "needed": "libwrong.so", "candidates": [{"path": "libwrong.so"}]},
    ]}
    report, categories = build_reports({"elfs": [source, bridge, provider, wrong_version, unrelated]}, deps)
    assert symbol_identity("SetVolume@@V1") == ("SetVolume", "V1")
    assert "audio_volume_sound" not in matching_domains("pthread_mutex_unlock_tracker")
    assert "cec_source_power" not in matching_domains("DeviceConfiguration")
    assert "cec_source_power" in matching_domains("MApi_CEC_Enabled")
    assert "cec_source_power" in matching_domains("libar_cec.so")
    assert len(report["bindings"]) == 1
    assert [row["module"] for row in report["bindings"][0]["candidates"]] == ["libaudio.so"]
    assert report["bindings"][0]["candidates"][0]["dependency_path"] == ["app", "bridge.so", "libaudio.so"]
    assert report["bindings"][0]["candidates"][0]["direct_DT_NEEDED_candidate"] is False
    assert report["unmatched_imports"][0]["global_name_match_outside_closure"]
    assert report["bindings"][0]["call_or_xref_observed"] is False
    assert categories["counts"]["modules"] == 5
    assert all(item["classification"] == "inferred" for item in categories["modules"])
    print(json.dumps({"self_test": "passed", "checks": ["versioned_symbols", "dependency_closure_restriction", "outside_closure_excluded", "inference_and_call_labels", "all_module_classification"]}))


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--analysis", type=Path, default=PROJECT / "analiz")
    parser.add_argument("--self-test", action="store_true")
    args = parser.parse_args()
    if args.self_test:
        self_test()
        return
    inventory, inventory_sha = read_json(args.analysis / "elf-envanteri.json")
    deps, dependency_sha = read_json(args.analysis / "bagimliliklar.json")
    symbols, categories = build_reports(inventory, deps)
    common = {
        "schema_version": 1, "generated_at_utc": datetime.now(timezone.utc).isoformat(),
        "inputs": {"elf-envanteri.json": inventory_sha, "bagimliliklar.json": dependency_sha},
        "offline_static_only": True, "firmware_executed": False, "call_or_xref_observed": False,
        "limitations": LIMITATIONS,
    }
    write_json(args.analysis / "sembol-baglantilari.json", {**common, **symbols})
    write_json(args.analysis / "modul-kategorileri.json", {**common, **categories})
    print(json.dumps({"symbol_counts": symbols["counts"], "category_counts": categories["counts"], "outputs": ["sembol-baglantilari.json", "modul-kategorileri.json"]}))


if __name__ == "__main__":
    main()
