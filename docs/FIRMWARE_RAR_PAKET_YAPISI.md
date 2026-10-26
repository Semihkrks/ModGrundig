# Orijinal RAR ve V7 inceleme ZIP'i

25 Ekim 2026. `reverse-engineer-anything` becerisi doğrultusunda yerel arşiv/metin incelemesi yapıldı. Bu kayıt REA MCP Evidence değildir. Orijinal dosyalar değiştirilmedi; arşivdeki programlar, servis scriptleri ve cihaz yazma komutları çalıştırılmadı.

Kaynak: [GMGRMR.-.-.-.-.V03.017.04.rar](../devir-paketi/Kaynaklar/GMGRMR.-.-.-.-.V03.017.04.rar), 42.604.212 bayt, SHA256 `dd0d297d0611f240e1336042483ee46ec73a7b9f669510f45664677f4950a46c`.

## Doğrulanan içerik

7-Zip 26.04 bütünlük testi geçti: **17 dosya, 11 dizin**. Önceden doğrulanmış çıkarımdaki 17 dosyanın boyutu ve CRC32'si tekrar doğrudan RAR envanteriyle karşılaştırıldı; tamamı eşleşti. Yeniden gereksiz tam çıkarım yapılmadı.

```text
Release info.txt
Target_GM/
  ProjectReleaseVersion.txt
  image/
    GM_SWImage.bin          42.483.736 bayt
    GM_Boot.bin              2.288.972 bayt
  script/
    [[key_all
    [[key_acoustic, [[key_chasis, [[key_ci, [[key_gamma
    [[key_hdcp, [[key_hdmi13, [[key_hdmi23, [[key_hdmi33
    [[key_mac, [[key_panel, [[key_productcode, [[key_productserial
  BIN_FILES/
    CI_Plus/, GM_ACOUSTIC_FILES/, GM_EDID_FILES/, GM_GAMMA_FILES/
    GM_PANEL_FILES/, keys/, panel/
```

`BIN_FILES` altındaki yedi yaprak dizin RAR'da boştur; bunların altında dosya kaydı yoktur. Sürüm kaydı `Target_GM/ProjectReleaseVersion.txt:1–3`: Main/Boot `V03.017.04`, Release HEAD `3061`. `Release info.txt:1` mağaza modundaki enerji sınıfı bilgisinin kaldırılmasını belirtir; kurulum kılavuzu değildir.

## Servis scriptleri neye bağlı?

12 tekil script `fatload usb` ile `/Target_GM/BIN_FILES/keys/…` altındaki dosyalara başvurur. Örnek: `script/[[key_panel:6`, `script/[[key_mac:6`, `script/[[key_hdcp:6`. Bu başvuruların hedef dosyaları RAR'da yoktur. Tam dosya/line listesi [JSON kaydındadır](../analiz/vendor-rar-inspection.json); gerçek anahtar/kimlik değerleri kaydedilmez.

`script/[[key_all:10–32` on iki `udstar_prkey` çağrısı içerir; tekil scriptlerde `setenv`, `run`, `saveenv` bulunur. Bunlar normal ses/numara UI kaynakları değildir. Komut metninin mevcut olması normal yazılım güncellemesinde bu scriptlerin zorunlu çalıştığını kanıtlamaz. Güncelleme başlangıcıyla aralarındaki çağrı bağlantısı burada kurulmadı.

**Dolayısıyla orijinal RAR da bütün fabrika anahtar/kalibrasyon girdilerini taşıyan bir paket değildir.** Boş klasörleri doldurmak için dosya veya cihaz kimliği uydurulmaz. Eksik servis girdileri, tek başına normal yazılım güncellemesinin çalışmayacağını da kanıtlamaz.

## RAR/ZIP ve BIN ayrımı

Bu kaynakta RAR dağıtım arşividir; gerçek yazılım kapsayıcısı `Target_GM/image/GM_SWImage.bin` dosyasıdır. RAR envanteri TV'nin RAR veya ZIP'i doğrudan okuyabildiğini, hangi USB kökünü taradığını veya hangi tuşla yüklemeye girdiğini kanıtlamaz. Bunlar ayrıca bootloader giriş kodundan/cihazda gözlemden doğrulanmalıdır.

Hazırlanan [V7 inceleme ZIP'i](../analiz/native-ui-candidate/v7-tv/package/V7_INCELEME_ADAYI.zip) yalnız aynı yoldaki V7 `GM_SWImage.bin`, `README_TR.txt` ve `SHA256.txt` dosyalarını içerir. **Orijinal RAR'ın bütün dosyalarını içeren birebir paket değildir.** Ayrı `GM_Boot.bin`, servis scriptleri, boş servis klasörleri ve sürüm notları bu ZIP'te bulunmaz. V7 BIN SHA256: `3291477403bd9d1961a1e27a45d974fcb7e1bdef54bacc676e10c11bfb0c5e71`.

Önemli sınır: ZIP'e ayrı `GM_Boot.bin` koymamak, `GM_SWImage.bin` üzerinden bootloader güncellemesini otomatik olarak devre dışı bırakmaz. Orijinal SWImage, beş mboot payload'ı ve NAND/UBI güncelleme ifadelerini kendi içinde taşır. V7 bu diğer payload'ları değiştirmeden korur. [Tablo ve komut ofsetleri](bilgi-tabani/BOOT_EK_KANITLAR.md), [V7 kapsamı ve bağımsız geri okuma](UI_NATIVE_V7_TV_ADAYI.md).

Bu inceleme kaynak arşivin yapısını açıklığa kavuşturur; V7'nin fiziksel TV tarafından kabul edildiğini veya sorunsuz açılacağını doğrulamaz. Sadece uzantıyı değiştirmek ya da RAR'ı ZIP'e çevirmek bu doğrulamaların yerini tutmaz.

Tekrarlanabilir kontrol: `python scripts/inspect_vendor_rar.py`. Makine çıktısı: [vendor-rar-inspection.json](../analiz/vendor-rar-inspection.json).
