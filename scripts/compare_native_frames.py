"""Make a labeled diagnostic crop comparison of already-rendered native frames."""
from pathlib import Path
from PIL import Image, ImageDraw, ImageFont

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT/'analiz/native-ui-port-v4/volume-before-after.png'

def main():
    canvas = Image.new('RGB', (520, 1160), '#19202a')
    draw = ImageDraw.Draw(canvas)
    label_font = ImageFont.truetype('C:/Windows/Fonts/segoeui.ttf', 24)
    for index, (version, label) in enumerate((('v3', 'Önce · v3'), ('v4', 'Sonra · v4'))):
        frame = ROOT/f'analiz/native-frame-rehost/{version}-volume-35.png'
        with Image.open(frame) as image:
            # Same unaltered framebuffer coordinates in both versions; 2x pixel zoom.
            crop = image.convert('RGB').crop((0, 150, 112, 710))
        crop = crop.resize((224, 1120), Image.Resampling.NEAREST)
        x = 16+index*260
        draw.text((x, 7), label, fill='#edf1f6', font=label_font)
        canvas.paste(crop, (x, 40))
    OUT.parent.mkdir(parents=True, exist_ok=True)
    if OUT.is_symlink() or (OUT.exists() and OUT.stat().st_nlink != 1):
        raise ValueError('Comparison output must be a regular dedicated file')
    canvas.save(OUT)
    print(OUT)

if __name__ == '__main__':
    main()
