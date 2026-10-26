"""Prepare exact retained Chrome glyphs at native resource dimensions; no overlay writes."""
from pathlib import Path
import json,hashlib,struct,copy,xml.etree.ElementTree as ET

ROOT=Path(__file__).resolve().parents[3]
OUT=Path(__file__).resolve().parent
NS='http://www.w3.org/2000/svg';ET.register_namespace('',NS)
def sha(data):return hashlib.sha256(data).hexdigest()

def main():
    svg=ROOT/'ui-preview/tv-icons.svg';css=ROOT/'ui-preview/styles.css';app=ROOT/'ui-preview/app.js'
    symbols=ET.fromstring(svg.read_bytes());source={x.attrib['id']:x for x in symbols}
    specs={
        963:('edit',64,180,180),964:('edit',64,180,180),
        967:('lock',48,170,180),968:('lock',48,170,180),
        969:('record',64,180,180),970:('record',64,180,180),
        971:('settings',64,180,180),972:('settings',64,180,180),
        973:('speaker',48,170,180),974:('speaker',48,170,180),
        975:('source',48,170,180),976:('source',48,170,180),
        977:('media',64,180,180),978:('media',64,180,180),
        979:('timer',48,170,180),982:('timer',48,170,180),
        980:('timer',64,180,180),981:('timer',64,180,180),
        983:('settings',48,170,180),984:('settings',48,170,180),
        985:('picture',48,170,160),986:('picture',48,170,160)}
    focused={964,968,970,972,974,976,978,981,982,984,986}
    records=[]
    for old_id,(symbol,display,expand_w,expand_h) in sorted(specs.items()):
        color='#056fc2' if old_id in focused else '#203447'
        # Compensate native nonuniform StretchBlit: final SVG box remains48/64 square.
        box_w=display*190/expand_w;box_h=display*190/expand_h
        root=ET.Element(f'{{{NS}}}svg',width='190',height='190',viewBox='0 0 190 190')
        inner=ET.SubElement(root,f'{{{NS}}}svg',x=str((190-box_w)/2),y=str((190-box_h)/2),width=str(box_w),height=str(box_h),viewBox='0 0 32 32',preserveAspectRatio='none',style=f'color:{color};stroke-width:1.8')
        selected=copy.deepcopy(source['icon-'+symbol])
        allowed={'symbol','path','rect','circle','ellipse','g','line','polyline','polygon'}
        for e in selected.iter():
            if e.tag.rsplit('}',1)[-1] not in allowed:raise ValueError('Active SVG element rejected')
            for key,value in e.attrib.items():
                if key.lower().startswith('on') or 'href' in key or 'url(' in value:raise ValueError('External SVG reference rejected')
        group=ET.SubElement(inner,f'{{{NS}}}g',{k:v for k,v in selected.attrib.items() if k not in ['id','viewBox']})
        group.extend(selected)
        raw=ET.tostring(root,encoding='utf-8',xml_declaration=True)
        target=OUT/'sources'/f'icon-{old_id}.svg';target.parent.mkdir(parents=True,exist_ok=True)
        target.write_bytes(raw)
        records.append(dict(old_id=old_id,symbol='icon-'+symbol,source='ui-preview/tv-icons.svg',focused=old_id in focused,color=color,
                            chrome_svg_box=display,native_expand=[expand_w,expand_h],native_canvas=[190,190],
                            compensated_svg_box=[box_w,box_h],svg=target.relative_to(ROOT).as_posix(),svg_sha256=sha(raw)))
    plan=dict(svg_sha256=sha(svg.read_bytes()),css_sha256=sha(css.read_bytes()),app_sha256=sha(app.read_bytes()),
              records=records,unmapped_native_ids=[950,951,952,953,954,955,959,960,961,962,965,966,987,988],
              unmapped_policy='OEM alpha silhouette recolored; no active Chrome counterpart, no invented glyph or claimed Chrome parity',
              native_layout_changed=False,original_firmware_modified=False)
    (OUT/'render-plan.json').write_text(json.dumps(plan,indent=2)+'\n',encoding='utf-8')
    print('Prepared22 exact local SVG glyph resources,14 explicit unmapped OEM silhouettes')

if __name__=='__main__':main()
