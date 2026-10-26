"""Labeled, unscaled crops of real native-rehost test frames for visual review."""
import hashlib
import json
from pathlib import Path
from PIL import Image, ImageDraw, ImageFont

ROOT=Path(__file__).resolve().parents[1]
OUT=ROOT/'analiz/native-ui-port-v5'

def main():
    canvas=Image.new('RGB',(740,630),'#19202a')
    draw=ImageDraw.Draw(canvas)
    font=ImageFont.truetype('C:/Windows/Fonts/segoeui.ttf',20)
    draw.text((24,14),'Native test karelerinden kesitler · v5',font=font,fill='#edf1f6')
    records=[]
    for name,label,crop,position in (
        ('v5-volume-35','Ses 35',(0,150,100,650),(28,90)),
        ('v5-volume-0','Ses 0 · sessiz',(0,150,100,650),(178,90)),
        ('v5-numeric-123','Kanal numarası',(1526,52,1860,188),(360,100)),
        ('v5-numeric-10000','5 haneli sınama',(1526,52,1860,188),(360,330)),
    ):
        source=ROOT/f'analiz/native-frame-rehost/{name}.png'
        with Image.open(source) as image:
            canvas.paste(image.convert('RGB').crop(crop),position)
        draw.text((position[0],position[1]-32),label,font=font,fill='#c3cfde')
        records.append(dict(source=source.relative_to(ROOT).as_posix(),sha256=hashlib.sha256(source.read_bytes()).hexdigest(),crop=crop,position=position))
    OUT.mkdir(parents=True,exist_ok=True)
    for target in (OUT/'native-review.png',OUT/'native-review.json'):
        if target.is_symlink() or (target.exists() and target.stat().st_nlink!=1):
            raise ValueError('Review outputs must be regular dedicated files')
    canvas.save(OUT/'native-review.png')
    (OUT/'native-review.json').write_text(json.dumps(dict(kind='Unscaled diagnostic crops of separate native test scenes; labels are host annotations',inputs=records),indent=2)+'\n',encoding='utf-8')
    print(OUT/'native-review.png')

if __name__=='__main__':main()
