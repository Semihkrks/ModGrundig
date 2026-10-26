"""Read-only native overlay PNG compression experiment; writes only beside itself."""
from pathlib import Path
import json, io, zlib, struct, hashlib
from PIL import Image
import zopfli.png, zopfli.zlib

ROOT=Path(__file__).resolve().parents[3]
BASE=ROOT/'analiz/native-ui-candidate/v8'
OUT=Path(__file__).resolve().parent/'20261025-fast3'

def chunk(kind,data):
    return struct.pack('>I',len(data))+kind+data+struct.pack('>I',zlib.crc32(kind+data)&0xffffffff)

def recompress(raw):
    pos=8;chunks=[];data=b''
    while pos<len(raw):
        size=struct.unpack_from('>I',raw,pos)[0];kind=raw[pos+4:pos+8];body=raw[pos+8:pos+8+size]
        chunks.append((kind,body));pos+=size+12
        if kind==b'IDAT':data+=body
    compressed=zopfli.zlib.compress(zlib.decompress(data),numiterations=5)
    output=raw[:8];inserted=False
    for kind,body in chunks:
        if kind==b'IDAT':
            if not inserted:output+=chunk(kind,compressed);inserted=True
        else:output+=chunk(kind,body)
    return output

def main():
    OUT.mkdir(exist_ok=False)
    manifest=json.loads((BASE/'manifest.json').read_text(encoding='utf-8'))
    records=[r for r in manifest['records'] if r['relative_path'].endswith('.png') and '/modern/' in r['relative_path']]
    assert len(records)==45
    results=[]
    for index,row in enumerate(records):
        source=BASE/'overlay'/row['relative_path'];raw=source.read_bytes()
        assert hashlib.sha256(raw).hexdigest()==row['candidate_sha256']
        image=Image.open(io.BytesIO(raw));pixels=image.convert('RGBA').tobytes()
        variants={'original':raw,'idat-zopfli':recompress(raw)}
        buffer=io.BytesIO();image.save(buffer,format='PNG',optimize=True,compress_level=9,bits=raw[24])
        variants['pillow-optimize']=buffer.getvalue()
        variants['zopflipng-zlib']=zopfli.png.optimize(raw,use_zopfli=False,lossy_transparent=False,lossy_8bit=False)
        for key,value in variants.items():
            check=Image.open(io.BytesIO(value))
            assert check.size==image.size and check.convert('RGBA').tobytes()==pixels,(row['relative_path'],key)
        strict=min(((key,value) for key,value in variants.items() if value[16:29]==raw[16:29]),key=lambda x:len(x[1]))
        relaxed=min(variants.items(),key=lambda x:len(x[1]))
        for label,(method,value) in [('strict',strict),('pixel-exact',relaxed)]:
            target=OUT/label/Path(row['relative_path']).name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(value)
        results.append({'relative_path':row['relative_path'],'original':len(raw),'strict':len(strict[1]),'strict_method':strict[0],
                        'pixel_exact':len(relaxed[1]),'pixel_exact_method':relaxed[0],
                        'old_ihdr':raw[16:29].hex(),'new_ihdr':relaxed[1][16:29].hex(),'rgba_pixels_exact':True})
        print(index+1,Path(row['relative_path']).name,len(raw),len(strict[1]),len(relaxed[1]),flush=True)
    summary={'files':len(results),'original_total':sum(r['original'] for r in results),'strict_total':sum(r['strict'] for r in results),
             'pixel_exact_total':sum(r['pixel_exact'] for r in results),'records':results,'overlay_modified':False,'native_decoder_verified_for_new_variants':False}
    summary['strict_savings']=summary['original_total']-summary['strict_total'];summary['pixel_exact_savings']=summary['original_total']-summary['pixel_exact_total']
    (OUT/'results.json').write_text(json.dumps(summary,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({key:value for key,value in summary.items() if key!='records'}),flush=True)

if __name__=='__main__':main()
