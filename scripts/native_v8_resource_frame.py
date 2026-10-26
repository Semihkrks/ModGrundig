"""MUF-rendered v8 resource specimens, never a substitute full TV menu."""
import io
import json
from PIL import Image
from native_frame_rehost import NativePainter,SOURCE,ROOT,sha,FONT_SHA
from build_native_ui_v8 import verified_packaging_records,OUT,IMAGE_REL

def render_resources():
    from map_ui_asset_dependencies import parse_table,CACHE
    verified_packaging_records()
    table=OUT/'overlay'/IMAGE_REL;CACHE.pop(table,None)
    _,records=parse_table(table)
    p=NativePainter();inputs=[]
    def paint(identifier,rect):
        relative='08_APP/rc/'+records[identifier]['resource_path'].removeprefix('../rc/')
        path=OUT/'overlay'/relative
        if not path.is_file():raise ValueError('Expected pinned private resource')
        raw=path.read_bytes();inputs.append(dict(id=identifier,path=path.relative_to(ROOT).as_posix(),sha256=sha(raw)))
        with Image.open(io.BytesIO(raw)) as image:p.paint(f'private Image{identifier}',rect,image=image)
    font=SOURCE/'08_APP/rc/rc/DejaVuSans.ttf'
    if sha(font.read_bytes())!=FONT_SHA[0x4b0]:raise ValueError('Pinned specimen font changed')
    def text(value,rect,color=0xff203447,size=28):p.text('specimen annotation (host label)',rect,value,font,size,color,align=0x11)
    paint(2180,(0,0,1920,1080))
    text('v8 · Native MUF kaynak testi',(72,42,1776,54),size=38)
    text('Bu düzen bir kaynak karşılaştırmasıdır; TV menüsünün çalışma zamanı yerleşimi değildir.',(72,104,1776,44),size=25)
    # These rectangles are an explicitly host-arranged test plate. Native
    # OnCreate positions/events are not simulated or claimed to have executed.
    names=['Görüntü','Ses','Kaynak','Ebeveyn','Zamanlayıcı','TV Ayarları']
    original_ids=[985,973,975,967,979,983]
    manifest=json.loads((OUT/'manifest.json').read_text(encoding='utf-8'))
    home_assets=manifest['changes']['components']['home']['assets']
    mapping={r['old_id']:r['id'] for r in home_assets}
    for i,(name,old_id) in enumerate(zip(names,original_ids)):
        x=72+i*300;paint(2182 if i==0 else 2181,(x,206,270,226))
        paint(mapping[old_id],(x+60,220,150,150));text(name,(x+15,379,240,42),size=25)
    text('Ayar odağı · yerel MImg bağlaması2224',(72,480,1776,44),size=27)
    paint(2224,(72,540,1776,90));text('Görüntü Ayarları',(102,563,1700,48),color=0xfff5f5f5,size=31)
    text('Kanal paneli2184 / bilgi bandı2185',(72,678,1776,44),size=27)
    paint(2184,(72,740,820,240));text('Hazır Değil',(104,782,750,60),size=36)
    paint(2185,(930,740,918,240));text('Özgün kanal ve EPG işleyicileri korunur',(960,790,850,80),color=0xfff5f5f5,size=27)
    evidence=p.evidence();evidence.update(variant='v8',scene='resources',input_assets=inputs,
        specimen_layout='host-arranged resource plate, not native OnCreate geometry',
        full_native_menu_executed=False,native_event_loop_executed=False,television_tested=False,
        channel_database_used=False,source_overlay='analiz/native-ui-candidate/v8/overlay')
    return p.canvas,evidence

if __name__=='__main__':
    image,evidence=render_resources();output=ROOT/'analiz/native-frame-rehost'
    output.mkdir(parents=True,exist_ok=True);image.save(output/'v8-native-resources.png')
    (output/'v8-native-resources.json').write_text(json.dumps(evidence,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(image=str(output/'v8-native-resources.png'),callbacks=len(evidence['callbacks']),full_native_menu_executed=False)))
