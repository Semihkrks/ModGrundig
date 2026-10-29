"""SVG-only speaker variants for approval; never modifies native UI resources."""
import base64
import hashlib
import json
from pathlib import Path
import xml.etree.ElementTree as ET

from playwright.sync_api import sync_playwright

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'analiz/ui-volume-review/v79-icons'
CHROME = 'C:/Program Files/Google/Chrome/Application/chrome.exe'
BODY = 'M4 12h6l7-6v20l-7-6H4Z'
CURVES = {
    'low': [(22, 11, 27, 16, 22, 21)],
    'medium': [(22, 11, 27, 16, 22, 21), (26, 7, 34, 16, 26, 25)],
    'high': [(21, 12, 25, 16, 21, 20), (24.5, 9.5, 31, 16, 24.5, 22.5),
             (28, 6.5, 37, 16, 28, 25.5)],
}


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def write(name, raw):
    path = OUT / name
    if not path.resolve().is_relative_to(OUT.resolve()) or path.is_symlink():
        raise ValueError('Preview output escapes its directory')
    if path.exists() and path.stat().st_nlink != 1:
        raise ValueError('Aliased output')
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(raw if isinstance(raw, bytes) else raw.encode('utf-8'))


def svg(name):
    waves = ''.join(f'M{x} {y}Q{cx} {cy} {ex} {ey}' for x, y, cx, cy, ex, ey in CURVES[name])
    # Exact existing 100px native source geometry: 80px symbol translated10px.
    return ('<svg xmlns="http://www.w3.org/2000/svg" width="100" height="100" viewBox="0 0 100 100">'
            '<rect width="100" height="100" fill="#f5f5f5"/>'
            '<g transform="translate(10 10) scale(2.5)" fill="none" stroke="#1687df" '
            'stroke-width="2" stroke-linecap="round" stroke-linejoin="round">'
            f'<path d="{BODY}"/><path d="{waves}"/></g></svg>')


def data(raw, mime):
    return 'data:'+mime+';base64,'+base64.b64encode(raw).decode('ascii')


def assert_curve_bounds():
    boxes = {}
    for key, curves in CURVES.items():
        points = []
        for x, y, cx, cy, ex, ey in curves:
            for i in range(1001):
                t = i/1000
                points.append((10+2.5*((1-t)**2*x+2*(1-t)*t*cx+t*t*ex),
                               10+2.5*((1-t)**2*y+2*(1-t)*t*cy+t*t*ey)))
        # Round cap and stroke radius2.5px in the actual100px asset.
        box = [min(p[0] for p in points)-2.5, min(p[1] for p in points)-2.5,
               max(p[0] for p in points)+2.5, max(p[1] for p in points)+2.5]
        assert 0 <= box[0] < box[2] <= 100 and 0 <= box[1] < box[3] <= 100
        boxes[key] = box
    return boxes


def main():
    symbol_raw = (ROOT/'ui-preview/tv-icons.svg').read_bytes()
    assert sha(symbol_raw) == 'b2f3a2e3392392f1aa4acf207e4c28efa93f9db9c1803a589b3574fc709744bc'
    root = ET.fromstring(symbol_raw)
    symbol = next(e for e in root if e.attrib.get('id') == 'icon-speaker')
    assert symbol[0].attrib['d'] == BODY
    assert symbol[1].attrib['d'] == 'M22 11Q27 16 22 21M26 7Q34 16 26 25'
    bounds = assert_curve_bounds()
    volume_root = ROOT/'analiz/native-ui-candidate/v7.8-tv/overlay/08_APP/rc/ARimages/Grundig/volume'
    current = (volume_root/'volume_icon.png').read_bytes()
    muted = (volume_root/'mute_icon.png').read_bytes()
    assert sha(current) == 'aa1c3918d73338f4065285fbc634fe56169dcc7019af99753b907a897796b099'
    assert sha(muted) == '82445d3755d20ba59fa325fc3bebc7505124f59531b0b7dbd3c1470b30a5417c'
    sources = {}
    for name in CURVES:
        raw = svg(name)
        write(name+'.svg', raw)
        sources[name] = data(raw.encode('utf-8'), 'image/svg+xml')
    sources['mute'] = data(muted, 'image/png')
    states = [('mute', '0 / sessiz', 'Mevcut gri sessiz simgesi', 'Dalga yok'),
              ('low', '1–20', 'Düşük ses', '1 dalga'),
              ('medium', '21–60', 'Normal ses', '2 dalga · mevcut ikon'),
              ('high', '61–100', 'Yüksek ses', '3 dalga')]
    cells = []
    for name, number, label, wave in states:
        alt = f'{label}, {wave}'
        cells.append(f'<section class="state"><p class="range">{number}</p>'
                     f'<div class="large"><img src="{sources[name]}" alt="{alt}" width="150" height="150"></div>'
                     f'<h2>{label}</h2><p class="detail">{wave}</p>'
                     f'<div class="actual"><img src="{sources[name]}" alt="44 piksel boyutunda {alt}" width="44" height="44">'
                     '<span>44 × 44 px</span></div></section>')
    html = f'''<!doctype html><html lang="tr"><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<title>ModGrundig · Ses ikonları onay taslağı</title><style>
*{{box-sizing:border-box}}body{{margin:0;background:#eeefef;color:#18222b;font-family:"Segoe UI",sans-serif}}
main{{max-width:1400px;margin:0 auto;padding:50px 56px 38px}}header{{display:flex;align-items:center;justify-content:space-between;gap:28px;border-bottom:1px solid #d5dadd;padding-bottom:30px}}
.eyebrow{{margin:0 0 12px;font-size:12px;font-weight:700;letter-spacing:.18em;color:#6a747c}}h1{{margin:0;font-size:34px;letter-spacing:-1px;font-weight:600;line-height:1.2}}.intro{{margin:12px 0 0;max-width:760px;font-size:16px;line-height:1.6;color:#53616b}}
.current{{display:flex;align-items:center;gap:12px;flex-shrink:0;background:#f5f5f5;padding:16px 20px;border-radius:16px}}.current img{{width:66px;height:66px}}.current p{{margin:0;font-size:13px;font-weight:600}}.current span{{display:block;color:#6d7982;font-size:12px;margin-top:5px;font-weight:400}}
.states{{display:grid;grid-template-columns:repeat(4,1fr);padding-top:30px}}.state{{padding:12px 26px 0;border-right:1px solid #d5dadd;text-align:center}}.state:last-child{{border-right:0}}.range{{font-size:27px;font-weight:600;letter-spacing:-.7px;margin:0 0 20px;font-variant-numeric:tabular-nums}}.large{{height:198px;display:flex;align-items:center;justify-content:center;background:#f5f5f5;border-radius:24px}}
h2{{margin:23px 0 7px;font-size:18px;font-weight:600}}.detail{{margin:0;color:#6b7882;font-size:13px}}.actual{{margin-top:30px;display:flex;flex-direction:column;align-items:center;gap:10px}}.actual img{{background:#f5f5f5;border-radius:8px}}.actual span{{font-size:11px;color:#6f7b83}}footer{{margin-top:34px;padding-top:22px;border-top:1px solid #d5dadd;display:flex;justify-content:space-between;gap:25px;font-size:13px;line-height:1.6;color:#626f79}}footer strong{{color:#34434d;font-weight:600}}footer p{{margin:0}}.status{{white-space:nowrap;color:#1687df;font-weight:600}}
@media(max-width:800px){{main{{padding:25px 20px}}header{{align-items:flex-start;flex-direction:column}}.states{{grid-template-columns:repeat(2,minmax(0,1fr));row-gap:36px}}.state{{padding:8px;min-width:0}}.large img{{max-width:100%;height:auto}}.state:nth-child(2){{border-right:0}}h1{{font-size:29px}}footer{{flex-direction:column}}}}
</style><main><header><div><p class="eyebrow">MODGRUNDIG / SES GÖSTERGESİ</p><h1>Aynı hoparlör, sese göre dalga.</h1><p class="intro">Sevdiğin ikonun gövdesi, mavi tonu ve çizgi kalınlığı korunuyor.<br>Yalnızca ses yükseldikçe yanındaki dalga sayısı değişiyor.</p></div><div class="current"><img src="{data(current,'image/png')}" alt="Şu an televizyonda kullanılan ses ikonu"><p>Mevcut ikon<span>21–60 aralığında aynı kalır</span></p></div></header><div class="states">{''.join(cells)}</div><footer><p><strong>İkonlar onay için gösteriliyor.</strong> Üsttekiler ayrıntıyı görmek için büyütülmüştür.<br>Alt sıra, 1920 × 1080 kaynak düzenindeki 44 × 44 piksel widget ölçüsünü gösterir.</p><p class="status">Taslak · firmware'e uygulanmadı</p></footer></main></html>'''
    write('index.html', html)
    errors = []
    with sync_playwright() as pw:
        browser = pw.chromium.launch(executable_path=CHROME, headless=True)
        try:
            page = browser.new_page(viewport=dict(width=1440, height=830), device_scale_factor=1)
            page.on('pageerror', lambda e: errors.append(str(e)))
            page.route('http://**/*', lambda route: route.abort())
            page.route('https://**/*', lambda route: route.abort())
            page.set_content(html, wait_until='load')
            page.evaluate('document.fonts.ready')
            assert page.locator('img').evaluate_all('(imgs)=>imgs.every(i=>i.complete&&i.naturalWidth>0)')
            assert page.locator('.actual img').evaluate_all('(imgs)=>imgs.every(i=>i.getBoundingClientRect().width===44&&i.getBoundingClientRect().height===44)')
            assert page.evaluate('document.documentElement.scrollWidth<=innerWidth')
            page.screenshot(path=str(OUT/'icon-approval-board.png'), full_page=True, animations='disabled')
            page.set_viewport_size(dict(width=390, height=844))
            assert page.evaluate('document.documentElement.scrollWidth<=innerWidth')
            page.screenshot(path=str(OUT/'icon-approval-mobile.png'), full_page=True, animations='disabled')
            assert not errors
            browser_version = browser.version
        finally:
            browser.close()
    report = dict(status='PASS_PREVIEW_ONLY_NOT_INSTALLED', skill='redesign-existing-projects',
                  thresholds=dict(mute='0 or muted', low='1–20', medium='21–60', high='61–100'),
                  wave_counts=dict(low=1, medium=2, high=3), speaker_body=BODY,
                  existing_two_wave_shape_preserved=True, medium_source_matches_existing_svg=True,
                  current_png_sha256=sha(current), muted_png_sha256=sha(muted),
                  native_source_canvas=[100, 100], source_symbol_side=80, native_widget_preview=[44, 44],
                  curve_stroke_bounds=bounds, native_assets_modified=False, runtime_dispatch_implemented=False,
                  physical_tv_tested=False, chromium=browser_version, page_errors=errors,
                  checks=['pinned SVG and existing PNG identities', 'same speaker body for all proposed levels',
                          '1/2/3 wave counts', 'curve+stroke native100px containment', 'all images loaded',
                          'exact44px actual-size row', 'desktop and390px no horizontal overflow', 'no browser page errors'])
    write('verification.json', json.dumps(report, ensure_ascii=False, indent=2)+'\n')
    print(json.dumps(dict(status=report['status'], preview=str(OUT/'icon-approval-board.png'), checks=len(report['checks'])), ensure_ascii=False))


if __name__ == '__main__':
    main()
