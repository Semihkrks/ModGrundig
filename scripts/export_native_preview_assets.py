"""Copy only five pinned public UI inputs for standalone browser preview."""
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
SOURCE=ROOT/'analiz/dosya-sistemleri-tam'
OVERLAY=ROOT/'analiz/native-ui-candidate/v6/overlay'
FILES=(
    ('native-fonts/DINPro-CondMedium.otf',SOURCE/'08_APP/rc/font/DINPro-CondMedium.otf','1e00616ed6d74da0eb3105683da02722e697c52f4a7461c1d0bd891ae344aa75'),
    ('native-fonts/DejaVuSans.ttf',SOURCE/'08_APP/rc/rc/DejaVuSans.ttf','f4d46af3f8b795d13cffe2ab07d639e0f116412a18f9706ee87f94770b1dd5b2'),
    ('native-assets/volume-background.png',OVERLAY/'08_APP/rc/ARimages/Common/popups/volumeControl/bg.png','db95b29b413e60c2e7d6a9de3497cecd417c3edf5dc3224820e8da250b32b7f6'),
    ('native-assets/volume-speaker.png',OVERLAY/'08_APP/rc/ARimages/Grundig/volume/volume_icon.png','aa1c3918d73338f4065285fbc634fe56169dcc7019af99753b907a897796b099'),
    ('native-assets/volume-mute.png',OVERLAY/'08_APP/rc/ARimages/Grundig/volume/mute_icon.png','703208975d4b1424f003a2998e89c164116968e47e6d05dac6551e3f38698696'),
)

def main():
    records=[]
    for relative,source,expected in FILES:
        raw=source.read_bytes()
        if hashlib.sha256(raw).hexdigest()!=expected:raise ValueError('Pinned public UI input mismatch')
        target=ROOT/'ui-preview'/relative
        if target.is_symlink() or not target.resolve().is_relative_to((ROOT/'ui-preview').resolve()):raise ValueError('Output boundary')
        target.parent.mkdir(parents=True,exist_ok=True)
        if target.exists():
            if target.stat().st_nlink!=1 or target.read_bytes()!=raw:raise ValueError('Refusing divergent preview asset')
        else:
            with target.open('xb') as out:out.write(raw)
        records.append(dict(path=relative,sha256=expected,source=source.relative_to(ROOT).as_posix()))
    manifest=ROOT/'ui-preview/native-assets/source-manifest.json'
    if manifest.is_symlink() or (manifest.exists() and manifest.stat().st_nlink!=1):raise ValueError('Aliased manifest')
    manifest.write_text(json.dumps(dict(scope='Pinned native graphics/fonts; browser widget and full TV behavior parity not proven',files=records),indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'files':len(records)}))

if __name__=='__main__':main()
