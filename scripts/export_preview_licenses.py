"""Copy only explicitly named public font licenses into the offline UI catalogue."""
from pathlib import Path
import hashlib
import json

root=Path(__file__).resolve().parents[1]
names=['analiz/dosya-sistemleri-tam/08_APP/rc/rc/LICENSE',
       'analiz/dosya-sistemleri-tam/08_APP/rc/rc/DroidSans/NOTICE']
sources=[]
pages=[]
for name in names:
    data=(root/name).read_bytes()
    text=data.decode('utf-8').replace('\r\n','\n')
    sources.append({'file':name,'sha256':hashlib.sha256(data).hexdigest(),'bytes':len(data)})
    lines=text.splitlines()
    for start in range(0,len(lines),18):
        pages.append({'file':name,'text':'\n'.join(lines[start:start+18]),'firstLine':start+1})
(root/'ui-preview/license-data.js').write_text(
    '// Generated public font notices, not the full product EULA.\n'
    'export const LICENSE_SOURCES='+json.dumps(sources,ensure_ascii=False)+';\n'
    'export const LICENSE_PAGES='+json.dumps(pages,ensure_ascii=False)+';\n',encoding='utf-8')
print(json.dumps({'sources':len(sources),'pages':len(pages)}))
