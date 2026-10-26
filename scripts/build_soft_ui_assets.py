"""Prepare/render-finalize new native UI candidates without writing OEM resources.

Run: python scripts/build_soft_ui_assets.py prepare
     node scripts/render_soft_ui_assets.mjs
     python scripts/build_soft_ui_assets.py finalize
"""
from __future__ import annotations
import argparse
import hashlib
import json
import sys
from pathlib import Path
from PIL import Image

sys.path.insert(0, str(Path(__file__).resolve().parent))
from map_ui_asset_dependencies import RC, geometry, parse_table

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "ui-assets"
TABLE_SHA = "d6b1b9fde60c9cc4624f264a8e75da4245e6fb3e9dab7534ddce01706fbcd2f3"
CARDS = {
    "video": (985, 986), "sound": (973, 974), "source": (975, 976),
    "lock": (967, 968), "schedule": (979, 982),
    "settings": (983, 984),
}
# All paths are new vector drawings; no original raster is modified or traced.
PATHS = {
    "video": '<rect x="57" y="59" width="76" height="53" rx="10"/><path d="M78 129h34M95 112v17"/><path d="m83 80 9 9 15-16"/>',
    "sound": '<path d="M64 84h17l20-17v56l-20-17H64z"/><path d="M113 83q13 12 0 24m12-36q25 24 0 48"/>',
    "source": '<rect x="55" y="60" width="80" height="60" rx="10"/><path d="M79 132h32M95 120v12M66 90h43m-13-13 13 13-13 13"/>',
    "lock": '<rect x="64" y="84" width="62" height="49" rx="11"/><path d="M77 84V69a18 18 0 0 1 36 0v15m-18 19v12"/>',
    "schedule": '<rect x="58" y="63" width="74" height="67" rx="10"/><path d="M58 82h74M77 56v14m36-14v14M77 99h10m16 0h10m-36 15h10m16 0h10"/>',
    "settings": '<path d="M60 70h70M60 95h70M60 120h70"/><rect x="76" y="61" width="13" height="18" rx="5" fill="SURFACE"/><rect x="105" y="86" width="13" height="18" rx="5" fill="SURFACE"/><rect x="73" y="111" width="13" height="18" rx="5" fill="SURFACE"/>',
}

def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()

def contained(path: Path, boundary: Path, *, must_exist: bool = False) -> Path:
    """Reject traversals/junctions/symlinks escaping a lexically pinned boundary."""
    pinned = boundary.absolute()
    resolved = path.resolve(strict=must_exist)
    if not resolved.is_relative_to(pinned):
        raise ValueError(f"Out-of-scope path: {path}")
    return resolved

def write_json(path: Path, value: object) -> None:
    contained(path, OUT)
    path.parent.mkdir(parents=True, exist_ok=True)
    contained(path, OUT)
    path.write_text(json.dumps(value, indent=2, ensure_ascii=False) + "\n", encoding="utf-8", newline="\n")

def svg(w: int, h: int, body: str) -> str:
    return f'<svg xmlns="http://www.w3.org/2000/svg" width="{w}" height="{h}" viewBox="0 0 {w} {h}">{body}</svg>\n'

def speaker(mute: bool, color: str = "#64758d") -> str:
    waves = '<path d="m62 40 17 19m0-19L62 59"/>' if mute else '<path d="M63 40q10 10 0 20m9-28q18 18 0 36"/>'
    return f'<g fill="none" stroke="{color}" stroke-width="3.2" stroke-linecap="round" stroke-linejoin="round"><path d="M25 43h12l16-13v40L37 57H25z"/>{waves}</g>'

def drawing(name: str, width: int, height: int, focus: bool = False) -> str:
    if name in CARDS:
        surface = "#eaf5ff" if focus else "#f7f9fc"
        ink = "#1687df" if focus else "#66758b"
        edge = "#2398ee" if focus else "#e3e9ef"
        body = f'<rect x="9" y="9" width="172" height="172" rx="31" fill="{surface}" stroke="{edge}" stroke-width="{3 if focus else 1.5}"/>'
        body += f'<g fill="none" stroke="{ink}" stroke-width="3.8" stroke-linecap="round" stroke-linejoin="round">{PATHS[name].replace("SURFACE", surface)}</g>'
    elif name == "volume-background":
        # OEM P4 has no tRNS: the native full rectangle remains opaque.
        body = '<rect width="69" height="620" fill="#f5f7fb"/><rect x=".5" y=".5" width="68" height="619" rx="33" fill="#fafbfd" stroke="#dce5ee"/>'
    elif name == "volume-knob":
        body = '<circle cx="12.5" cy="12.5" r="11.5" fill="#68baff"/><circle cx="12.5" cy="12.5" r="6.5" fill="#a4d6ff"/>'
    elif name in ("volume", "mute"):
        body = ('<rect width="100" height="100" fill="#fafbfd"/>' if name == "volume" else "") + speaker(name == "mute", "#218ede" if name == "volume" else "#8a97a8")
    else:
        # ARC resources are LA: keep monochrome and alpha; do not invent a colored decoder format.
        symbol = speaker(name == "arc-mute", "#f5f7fa")
        sign = '<path d="M112 45h21"/>' + ('<path d="M122.5 34.5v21"/>' if name == "arc-up" else "")
        body = f'<g transform="translate(0 -6)">{symbol}</g>'
        if name != "arc-mute":
            body += f'<g fill="none" stroke="#f5f7fa" stroke-width="3" stroke-linecap="round">{sign}</g>'
    return svg(width, height, body)

def table() -> tuple[dict, list]:
    path = RC / "rc/bin/Image_res.bin"
    assert sha(path) == TABLE_SHA, "OEM Image table changed: review ID bindings before building"
    info, records = parse_table(path)
    assert info["status"] == "fully_parsed"
    return info, records

def specifications():
    return [(name, n, focus) for name, pair in CARDS.items() for focus, n in enumerate(pair)] + [
        ("volume-background", 0x2a2, 0), ("mute", 0x2a8, 0), ("volume-knob", 0x2a9, 0),
        ("volume", 0x2aa, 0), ("arc-down", 4, 0), ("arc-mute", 5, 0), ("arc-up", 6, 0)]

def validate_plan(plan: dict, records: list) -> None:
    """Validate every path against code + pinned OEM table BEFORE any output write."""
    if plan.get("image_table_sha256") != TABLE_SHA:
        raise ValueError("Plan does not use the pinned OEM table")
    expected = {n: (name, focus) for name, n, focus in specifications()}
    assets = plan.get("assets", [])
    if len(assets) != len(expected) or {a.get("image_id") for a in assets} != set(expected):
        raise ValueError("Plan asset IDs do not match the 19 supported resources")
    for asset in assets:
        name, focus = expected[asset["image_id"]]
        key = name + ("-focus" if focus else "-normal")
        rp = records[asset["image_id"]]["resource_path"]
        if not rp.startswith("../rc/ARimages/"):
            raise ValueError("Unexpected OEM path")
        relative = Path("08_APP/rc") / rp.removeprefix("../rc/")
        paths = {"original_path": (Path("analiz/dosya-sistemleri-tam") / relative).as_posix(),
            "source": f"ui-assets/sources/{key}.svg", "rendered": f"ui-assets/rendered/{key}.png",
            "candidate": (Path("ui-assets/candidate") / relative).as_posix()}
        if asset.get("key") != key or asset.get("kind") != name or asset.get("focus_variant") != bool(focus) or asset.get("resource_path") != rp:
            raise ValueError("Plan resource binding differs from trusted specification")
        for field, expected_path in paths.items():
            if asset.get(field) != expected_path:
                raise ValueError(f"Untrusted {field}: {asset.get(field)}")
        original = contained(ROOT / paths["original_path"], ROOT / "analiz/dosya-sistemleri-tam", must_exist=True)
        source = contained(ROOT / paths["source"], OUT / "sources", must_exist=True)
        rendered = contained(ROOT / paths["rendered"], OUT / "rendered", must_exist=True)
        candidate = contained(ROOT / paths["candidate"], OUT / "candidate/08_APP/rc/ARimages")
        if candidate == original or candidate == source or candidate == rendered:
            raise ValueError("Output aliases an input")
        if candidate.exists() and candidate.samefile(original):
            raise ValueError("Output hardlinks an original")
        if sha(original) != asset.get("original_sha256") or sha(source) != asset.get("source_sha256"):
            raise ValueError("Input hash mismatch")
        actual = geometry(original.read_bytes())
        if actual != asset.get("original_geometry"):
            raise ValueError("Untrusted geometry metadata")
        with Image.open(original) as im:
            if im.mode != asset.get("original_mode") or ("A" in im.getbands() or "transparency" in im.info) != asset.get("alpha_capability"):
                raise ValueError("Untrusted pixel format metadata")

def prepare() -> None:
    info, records = table()
    specs = specifications()
    assets = []
    for name, resource_id, focus in specs:
        resource_path = records[resource_id]["resource_path"]
        assert resource_path.startswith("../rc/ARimages/")
        relative = Path("08_APP/rc") / resource_path.removeprefix("../rc/")
        original = ROOT / "analiz/dosya-sistemleri-tam" / relative
        assert original.resolve().is_relative_to((ROOT / "analiz/dosya-sistemleri-tam").resolve())
        g = geometry(original.read_bytes())
        with Image.open(original) as image:
            image.load()
            mode = image.mode
            has_alpha = "A" in image.getbands() or "transparency" in image.info
        key = name + ("-focus" if focus else "-normal")
        source = OUT / "sources" / f"{key}.svg"
        contained(source, OUT / "sources")
        source.parent.mkdir(parents=True, exist_ok=True)
        contained(source, OUT / "sources")
        source.write_text(drawing(name, g["width"], g["height"], bool(focus)), encoding="utf-8", newline="\n")
        assets.append({"key": key, "kind": name, "focus_variant": bool(focus), "image_id": resource_id,
            "image_id_hex": hex(resource_id), "resource_path": resource_path,
            "original_path": original.relative_to(ROOT).as_posix(), "original_sha256": sha(original),
            "original_bytes": original.stat().st_size, "original_geometry": g, "original_mode": mode,
            "alpha_capability": has_alpha, "source": source.relative_to(ROOT).as_posix(),
            "source_sha256": sha(source), "rendered": f"ui-assets/rendered/{key}.png",
            "candidate": (Path("ui-assets/candidate") / relative).as_posix(),
            "decoded_rgba_bytes": g["width"] * g["height"] * 4,
            "feature_status": "existing_code_candidate_not_device_confirmed" if name in ("lock", "schedule") else "existing_resource_candidate"})
    write_json(OUT / "build-plan.json", {"schema_version": 1, "image_table_sha256": info["sha256"], "assets": assets})
    write_json(OUT / "geometry-proposal.json", {"status": "proposal_only_not_written_to_Num_resources", "coordinate_scaling": "runtime 1920-to-panel scaling remains unobserved",
        "volume": {"panel_height": 420, "track_height": 200, "icon_width": 100, "icon_height": 100, "icon_x": 0, "icon_y": 320,
            "status": "Original long geometry retained by latest user preference; no Num patch",
            "implementation_blocker": "MUF alpha/colorkey and final rendering still require verification; source PNG stays OEM 69x620"},
        "home": {"height": 444, "implementation_blocker": "LayoutItems can overwrite positions; native layout hook not implemented"},
        "untouched": ["Num_res.bin", "Color resource 25", "global font 3215", "event maps", "ARC audio routing"]})
    print(f"Prepared {len(assets)} new vector sources; original files untouched")

def finalize(plan_override=None) -> None:
    _, records = table()
    plan = plan_override if plan_override is not None else json.loads((OUT / "build-plan.json").read_text(encoding="utf-8"))
    validate_plan(plan, records)
    # Also validate metadata destinations before writing the first candidate.
    contained(OUT / "manifest.json", OUT)
    for asset in plan["assets"]:
        original, source = ROOT / asset["original_path"], ROOT / asset["source"]
        assert sha(original) == asset["original_sha256"]
        assert sha(source) == asset["source_sha256"]
        image = Image.open(ROOT / asset["rendered"]).convert("RGBA")
        g, mode = asset["original_geometry"], asset["original_mode"]
        assert image.size == (g["width"], g["height"])
        target = ROOT / asset["candidate"]
        target.parent.mkdir(parents=True, exist_ok=True)
        contained(target, OUT / "candidate/08_APP/rc/ARimages")
        if target.exists() and target.samefile(original):
            raise ValueError("Output hardlinks an original")
        if mode == "P":
            colors = 1 << g["bit_depth"]
            if asset["alpha_capability"]:
                image = image.quantize(colors=colors, method=Image.Quantize.FASTOCTREE, dither=Image.Dither.NONE)
            else:
                opaque = Image.new("RGBA", image.size, "#fafbfd")
                opaque.alpha_composite(image)
                image = opaque.convert("RGB").quantize(colors=colors, method=Image.Quantize.MEDIANCUT, dither=Image.Dither.NONE)
            image.save(target, format="PNG", bits=g["bit_depth"], optimize=False, compress_level=9)
        else:
            image.convert(mode).save(target, format="PNG", optimize=False, compress_level=9)
        asset.update(candidate_sha256=sha(target), candidate_bytes=target.stat().st_size,
                     candidate_geometry=geometry(target.read_bytes()))
        assert sha(original) == asset["original_sha256"]
    plan.update(status="offline_native_resource_candidates_not_TV_tested", firmware_repacked=False,
                original_files_changed=False, resource_tables_changed=False,
                renderer="new SVG rendered with Playwright + system Chrome; Pillow preserves OEM PNG pixel format",
                feature_policy={"device_has_network_web": False, "network_or_web_assets_added": False,
                    "wifi_ids_excluded": [987, 988], "original_catalogue_widgets": 7, "candidate_nonnetwork_widgets": 6},
                limitations=["Native UI positions, panel height, focus/event animation and display alpha behavior are not changed by these assets",
                    "69x620 volume background is opaque P4; floating transparent rounded corners need a verified MUF alpha/colorkey path",
                    "ARC assets are monochrome LA8; audio/CEC routing untouched", "Six existing non-network widget resource pairs; lock/schedule are code candidates, not confirmed device screens"])
    write_json(OUT / "manifest.json", plan)
    print(f"Finalized {len(plan['assets'])} offline candidates; not a firmware update")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("step", choices=("prepare", "finalize"))
    args = parser.parse_args()
    prepare() if args.step == "prepare" else finalize()
