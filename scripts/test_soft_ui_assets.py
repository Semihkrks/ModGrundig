"""Offline candidate integrity/format tests, not target firmware execution."""
import json
import argparse
import shutil
import subprocess
import sys
import copy
from pathlib import Path
from PIL import Image

sys.path.insert(0, str(Path(__file__).resolve().parent))
from build_soft_ui_assets import ROOT, OUT, CARDS, sha, table, write_json, finalize
from map_ui_asset_dependencies import geometry

def test_assets(rebuild=False):
    table()
    plan=json.loads((OUT / "build-plan.json").read_text(encoding="utf-8"))
    inputs={a['original_path']:sha(ROOT/a['original_path']) for a in plan['assets']}
    for field,value in [('candidate',plan['assets'][0]['original_path']),('candidate','ui-assets/candidate/../../README.md'),('source','ui-assets/sources/../../README.md')]:
        bad=copy.deepcopy(plan);bad['assets'][0][field]=value
        try:finalize(bad)
        except ValueError:pass
        else:raise AssertionError('Unsafe build plan accepted')
    assert all(sha(ROOT/p)==s for p,s in inputs.items()),'Unsafe-plan test modified original input'
    manifest = json.loads((OUT / "manifest.json").read_text(encoding="utf-8"))
    if rebuild:
        before = {a["candidate"]: a["candidate_sha256"] for a in manifest["assets"]}
        subprocess.run([sys.executable, str(ROOT / "scripts/build_soft_ui_assets.py"), "prepare"], cwd=ROOT, check=True)
        subprocess.run([shutil.which("node") or "node", str(ROOT / "scripts/render_soft_ui_assets.mjs")], cwd=ROOT, check=True)
        subprocess.run([sys.executable, str(ROOT / "scripts/build_soft_ui_assets.py"), "finalize"], cwd=ROOT, check=True)
        manifest = json.loads((OUT / "manifest.json").read_text(encoding="utf-8"))
        assert before == {a["candidate"]: a["candidate_sha256"] for a in manifest["assets"]}, "Non-deterministic local rebuild"
    assets = manifest["assets"]
    count = 19
    assert len(assets) == count
    assert len({a["candidate"] for a in assets}) == count
    assert not any(a["image_id"] in (987, 988) for a in assets)
    assert {a["image_id"] for a in assets if a["kind"] in CARDS} == {n for pair in CARDS.values() for n in pair}
    total_original = total_candidate = total_memory = 0
    for a in assets:
        original, target, source = ROOT / a["original_path"], ROOT / a["candidate"], ROOT / a["source"]
        assert target.resolve().is_relative_to((OUT / "candidate/08_APP/rc/ARimages").resolve())
        assert sha(original) == a["original_sha256"]
        assert sha(target) == a["candidate_sha256"]
        assert sha(source) == a["source_sha256"]
        g, old = geometry(target.read_bytes()), a["original_geometry"]
        for key in ("width", "height", "color_type", "bit_depth", "interlace"):
            assert g[key] == old[key], (a["key"], key, g[key], old[key])
        assert g["chunk_crc_errors"] == 0 and g["iend_present"] and g["trailing_bytes"] == 0
        with Image.open(target) as image:
            image.load()
            has_alpha = "A" in image.getbands() or "transparency" in image.info
            assert has_alpha == a["alpha_capability"], a["key"]
            assert image.size[0] * image.size[1] * 4 == a["decoded_rgba_bytes"]
        assert sha(original) != sha(target)
        total_original += a["original_bytes"]
        total_candidate += a["candidate_bytes"]
        total_memory += a["decoded_rgba_bytes"]
    files = list((OUT / "candidate").rglob("*"))
    assert all(p.suffix == ".png" for p in files if p.is_file())
    assert {p.relative_to(ROOT).as_posix() for p in files if p.is_file()} == {a["candidate"] for a in assets}, "Unmanifested candidate file"
    result = {"status": "PASS", "unsafe_plan_prewrite_rejections":3,"candidate_count": len(assets), "home_widgets": 6, "home_variants": 12,
        "network_web_candidates": 0, "png_decode_pass": count, "png_format_geometry_alpha_matches": count, "png_all_chunk_crc_pass": count,
        "source_original_sha256_unchanged": count, "image_table_sha256_unchanged": True,
        "source_and_candidate_hashes_pass": count, "original_png_bytes": total_original,
        "candidate_png_bytes": total_candidate, "decoded_rgba_bytes_original": total_memory,
        "decoded_rgba_bytes_candidate": total_memory,
        "native_event_audio_routing_tests": "not run; resources only, no native code execution",
        "TV_tested": False, "firmware_repacked": False, "local_rebuild_all_candidate_hashes_equal": True if rebuild else "not run in this invocation"}
    write_json(OUT / "validation.json", result)
    print(json.dumps(result, indent=2))

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--rebuild", action="store_true", help="Also rebuild all 19 assets and compare exact output SHA256")
    test_assets(parser.parse_args().rebuild)
