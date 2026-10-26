"""Read pinned candidates and create bounded MUF/Pillow preview evidence only."""
import json
from pathlib import Path
import sys
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'scripts'))
import native_frame_rehost as r
OUT=Path(__file__).resolve().parent
for variant in r.TV_VARIANTS:
    for scene, result in (('volume-27',r.render(variant,27)),('numeric-12',r.render_numeric(variant,'12'))):
        image,evidence=result
        stem=f'{variant}-{scene}'
        image.save(OUT/f'{stem}.png')
        (OUT/f'{stem}.json').write_text(json.dumps(evidence,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
        print(stem,evidence['surface_geometry'])
