# Soft UI native resource candidates

These are new SVG source drawings and reproducible **offline resource candidates**, not an installable firmware image. Original extracted assets are read only. No Num/Color/resource table, ELF, update image or TV is modified.

Build on the current Windows workspace (Pillow, Playwright and Chrome already installed):

```powershell
python scripts/build_soft_ui_assets.py prepare
node scripts/render_soft_ui_assets.mjs
python scripts/build_soft_ui_assets.py finalize
python scripts/test_soft_ui_assets.py
# Optional full local reproducibility check:
python scripts/test_soft_ui_assets.py --rebuild
```

`build-plan.json` pins the OEM image table SHA256 and maps all Image IDs to real OEM paths. `manifest.json` pins original, SVG and candidate hashes. `validation.json` checks dimensions, PNG color type/bit depth, palette/alpha capability, all PNG chunk CRCs and decoded memory estimates. Renderer versions are recorded in `render-environment.json`. Rasterization depends on installed Chrome/Pillow versions; reruns on the pinned local environment can be compared by candidate hashes.

The six existing non-network Home widget candidates each retain normal/focus resources: video 985/986, sound 973/974, source 975/976, lock 967/968, schedule 979/982 and settings 983/984. Lock/schedule are existing code candidates, not confirmed device-visible screens. The original catalogue also has Wi-Fi 987/988, but the user confirms this TV has no network/Web feature: those two IDs are excluded from the candidate. No network, Web or app function is added. The drawings use thin rounded strokes, restrained blue focus, soft light surfaces and no expensive blur. Labels remain native text outside icon resources.

Volume Image IDs 0x2a2, 0x2a8, 0x2a9, 0x2aa and ARC IDs 4/5/6 retain original dimensions and PNG formats. ARC stays monochrome LA8. Opaque palette resources remain opaque: the existing 69×620 P4 background cannot acquire transparent rounded exterior corners from this asset substitution alone. No claim is made that this alone shortens the native panel. Geometry proposals are deliberately separate in `geometry-proposal.json`; focus/layout/animation/range and MUF alpha behavior still need native integration and device validation.

The candidate tree contains only 19 changed PNGs under `candidate/08_APP/rc/ARimages/`. Copying these files into a TV or update image is not performed or authorized by this build. Browser interactions and visual effects are not evidence of native event/audio/CEC execution. `TV_tested` remains false.
