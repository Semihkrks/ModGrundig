"""Export UI-only Turkish labels and the SAME staged PNG bytes for local preview."""
from pathlib import Path
import hashlib,json,struct,shutil
ROOT=Path(__file__).resolve().parents[1]
table=ROOT/'analiz/dosya-sistemleri-tam/08_APP/rc/rc_Turkish/bin/Str_res.bin'
data=table.read_bytes();assert data[:4]==b'_tsm'
count=struct.unpack_from('<I',data,28)[0];pos=56;records=[]
for i in range(count):
    n=struct.unpack_from('<I',data,pos)[0];assert n>0 and pos+4+n<=len(data)
    raw=data[pos+4:pos+4+n-1];records.append({'id':i,'offset':pos+4,'text':raw.decode('utf-8')});pos+=4+n
assert pos==len(data)
manifest=json.loads((ROOT/'ui-assets/manifest.json').read_text(encoding='utf-8'))
by_id={a['image_id']:a for a in manifest['assets']}
cards=[('video',0xea3,985,986),('sound',0xf9d,973,974),('source',0xffb,975,976),('settings',0x8d,983,984)]
result={'source':'GMGRMR V03.017.04 offline resources','turkish_table_sha256':hashlib.sha256(data).hexdigest(),
        'tv_parity_verified':False,'native_geometry_applied':False,'network_web_enabled':False,
        'menu_title':records[0xf49],'channel_list_title':records[0xfdb],
        'volume':{'height':420,'track_height':200,'track_y':88,'icon_y':320,'number_font':36},'volume_images':{},'cards':[]}
dest=ROOT/'ui-preview/assets';dest.mkdir(exist_ok=True)
for kind,label_id,normal,focus in cards:
    entry={'kind':kind,'label':records[label_id],'images':{}}
    for slot,image_id in [('normal',normal),('focus',focus)]:
        a=by_id[image_id];src=(ROOT/a['candidate']).resolve()
        assert src.is_relative_to((ROOT/'ui-assets/candidate').resolve())
        value=src.read_bytes();assert hashlib.sha256(value).hexdigest()==a['candidate_sha256']
        out=dest/f'image-{image_id}.png';shutil.copyfile(src,out)
        entry['images'][slot]={'id':image_id,'path':f'./assets/image-{image_id}.png','sha256':a['candidate_sha256']}
    result['cards'].append(entry)
for name,image_id in [('background',0x2a2),('mute',0x2a8),('knob',0x2a9),('speaker',0x2aa)]:
    a=by_id[image_id];src=(ROOT/a['candidate']).resolve();assert src.is_relative_to((ROOT/'ui-assets/candidate').resolve())
    assert hashlib.sha256(src.read_bytes()).hexdigest()==a['candidate_sha256']
    shutil.copyfile(src,dest/f'image-{image_id}.png')
    result['volume_images'][name]={'id':image_id,'path':f'./assets/image-{image_id}.png','sha256':a['candidate_sha256']}
(ROOT/'ui-preview/native-profile.js').write_text('// Generated from retained firmware resource tables; do not hand-edit.\nexport const PROFILE='+json.dumps(result,ensure_ascii=False,indent=2)+';\n',encoding='utf-8')
(ROOT/'analiz/ui-modernizasyon/shared-resource-profile.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print({'labels':[c['label']['text']for c in result['cards']],'same_candidate_PNGs':12,'volume_height':420,'tv_parity_verified':False})
