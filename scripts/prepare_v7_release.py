"""Local review bundle at the observed vendor image path; never install it."""
import hashlib
import json
import shutil
import zipfile
from build_native_ui_v7_tv import OUT,guard,verified_packaging_records

EXPECTED='3291477403bd9d1961a1e27a45d974fcb7e1bdef54bacc676e10c11bfb0c5e71'
verified_packaging_records()
package=OUT/'package';source=package/'GM_SWImage_UI_v7_OFFLINE_UNVERIFIED.bin'
guard(source)
if source.stat().st_size!=42483736 or hashlib.sha256(source.read_bytes()).hexdigest()!=EXPECTED:
    raise ValueError('Reviewed V7 BIN differs')
readback=json.loads((package/'independent-readback.json').read_text())
if readback['status']!='PASS_OFFLINE_ONLY' or readback['container_sha256']!=EXPECTED:raise ValueError('Independent readback missing')
review=OUT/'review-bundle';target=review/'Target_GM/image/GM_SWImage.bin';archive=package/'V7_INCELEME_ADAYI.zip'
for p in (review,target,archive):
    guard(p)
    if p.exists():raise FileExistsError('Refusing existing release output')
target.parent.mkdir(parents=True);shutil.copyfile(source,target)
notice='''V7 — YALNIZ SES PANELI VE RAKAMLA KANAL GIRISI

Ana menu, menu ikonlari, ayarlar, kanal listesi ve bilgi bandi orijinaldir.
Bu dosya gercek firmware kapsayicisidir; HTML arayuzu degildir.

CEVRIMDISI INCELEME ADAYI — TV'DE TEST EDILMEDI / FLASH_READY=FALSE
Dosya, payload, CRC ve metaveri kontrolleri gecti. Fiziksel TV acilisi,
bootloader kabul ve aktif cihazla uyumluluk dogrulanmadi. Sifir hata
veya guvenli kurulum garantisi verilmez.

Target_GM/image/GM_SWImage.bin yolu kaynak paketteki goreli yoldur.
Bu klasor eksiksiz otomatik USB yukleyici degildir. Bootloader,
kimlik/HDCP/MAC/panel/kalibrasyon scriptleri eklenmemistir.
Yukleme tuslari/proseduru tahmin edilmedi; herhangi bir script calistirilmadi.

Guncel ayrinti: docs/UI_NATIVE_V7_TV_ADAYI.md
'''
(review/'README_TR.txt').write_text(notice,encoding='utf-8')
(review/'SHA256.txt').write_text(EXPECTED+'  Target_GM/image/GM_SWImage.bin\n',encoding='ascii')
with zipfile.ZipFile(archive,'x',compression=zipfile.ZIP_DEFLATED,compresslevel=6) as z:
    for path in sorted(review.rglob('*')):
        if path.is_file():guard(path);z.write(path,path.relative_to(review).as_posix())
with zipfile.ZipFile(archive) as z:
    if z.testzip() is not None:raise ValueError('Archive CRC mismatch')
    if hashlib.sha256(z.read('Target_GM/image/GM_SWImage.bin')).hexdigest()!=EXPECTED:raise ValueError('ZIP image hash mismatch')
if hashlib.sha256(target.read_bytes()).hexdigest()!=EXPECTED:raise ValueError('Release copy differs')
result=dict(status='pass',bin_sha256=EXPECTED,zip_sha256=hashlib.sha256(archive.read_bytes()).hexdigest(),
    zip_bytes=archive.stat().st_size,vendor_image_relative_path='Target_GM/image/GM_SWImage.bin',
    complete_usb_installer=False,television_tested=False,flash_ready=False)
(package/'review-bundle-validation.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result))
