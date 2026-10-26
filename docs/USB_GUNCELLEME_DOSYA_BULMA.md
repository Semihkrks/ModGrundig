# USB güncelleme: “Daha yeni sürüm” mesajının gerçek koşulu

25 Ekim 2026. Kullanıcı Ayarlar içindeki USB yazılım güncellemesinde yeni paket bulunmadığına benzer mesaj gözledi. Mesajın tam ekran görüntüsü yoktur; aşağıdaki eşleştirme orijinal GMGRMR V03.017.04 kodunun statik incelemesidir. `reverse-engineer-anything` yöntemi, mevcut Ghidra projesinde sınırlı ve salt okunur sorgularla uygulandı; REA MCP Evidence değildir. Güncelleme kodu ve cihazda yazma komutu çalıştırılmadı.

## Kanıtlanan kontrol

`ArTvSettingsManager::CheckUSBUpdate @ 0x005432f8`, bağlı disklerin mount yoluna **`/Target_GM/image/GM_SWImage.bin`** ekler ve `fopen(..., "rb")` çağırır. Dosyayı okuyarak sürüm veya header karşılaştırması yapmaz. Yol sabiti uygulama VA `0x00fe67bc`, dosya ofseti `0x00be67bc` adresindedir. Kaynak ELF SHA256 `51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916`.

| Dönüş | Kodda kanıtlanan koşul | USB menüsündeki karşılık |
|---|---|---|
| 0 | Mount listesi boş | `0x1018`: USB Disk Yok |
| 1 | Uygun disklerde beklenen dosya açılamadı | `0x0e44`: Daha yeni sürümün güncelleme verisi yoktur. |
| 2 | Dosya bulundu, environment manager alınamadı | Aynı `0x0e44` mesajı |
| 3 | Dosya bulundu ve update environment kaydedildi | `0x105a` yükleme mesajı dalı |

`SoftwareUpdateFrame::OnNtyClick_ImageButton_Manual_Item_USB @ 0x00ed09ac` bu dönüşleri eşler. `RcGetString(0x0e44)` ID yüklemesi `0x00ed0b90`, çağrı `0x00ed0b98` adresindedir. Dolayısıyla bu mesaj **aynı sürüm reddini kanıtlamaz**. Dosya yokluğu ile environment sorunu da bu metni gösterir. Bu ilk kontrolü geçmek için 04→05 sürüm değişikliği gereksinimi bulunmadı.

Kaynaklar: [dosya arama C çıktısı](../analiz/native/ui-targeted/usb-update-v1/005432f8.c), [USB tıklama handler'ı](../analiz/native/ui-targeted/usb-update-v2/00ed09ac.c), [adres/metin/hash kaydı](../analiz/native/ui-targeted/usb-update-v1/discovery-and-error-evidence.json). Türkçe `rc/rc_Turkish/bin/Str_res.bin`, ID `0xe44`, payload ofseti 62431: “Daha yeni sürümün güncelleme verisi yoktur.” İngilizce aynı ID, `rc/rc_English/bin/Str_res.bin`, payload ofseti 61107: “Update data of newer version is not detected.”

## Klasör yapısı ve hazırlanmış V7

Kodun aradığı dosya, USB köküne göre şöyledir:

```text
USB kökü/
  Target_GM/
    image/
      GM_SWImage.bin
```

Sadece RAR'ın köke konması veya `GMGRMR.-.-.-.-.V03.017.04/Target_GM/...` gibi fazladan üst klasör eklenmesi, bu fonksiyonun aradığı yolu sağlamaz. Bu fonksiyonda RAR açma/tarama işlemi yoktur. Arşiv dağıtım biçimidir.

Hazırlanmış **[V7 RAR](../analiz/native-ui-candidate/v7-tv/package/GMGRMR.-.-.-.-.V03.017.04_V7_TEST.rar)** özgün RAR4 biçimini, 17 dosya ve 11 klasörü korur. Yalnız `Target_GM/image/GM_SWImage.bin` V7 ile değiştirilmiştir; diğer 16 dosya ve onların sıkıştırılmış blokları aynıdır. SWImage girdisi RAR4 `m0` saklama yöntemiyle yazıldı; orijinal girdinin yöntemi `m3` idi. Bu nedenle arşiv boyutunun farklı olması beklenir. Başka dosya veya talimat arşivin içine eklenmedi.

RAR SHA256 `9eb32b0321a5252cd24029e8d3409f10aaba0d63fb923bc298f779c0978d3cbc`, boyut 43.141.176 bayt. 7-Zip ve WinRAR bütünlük testleri geçti; yeni klasöre çıkarılarak 17 dosyanın tamamı hash ile doğrulandı. [RAR doğrulama kaydı](../analiz/native-ui-candidate/v7-tv/package/vendor-rar-validation.json). Hazır çıkarım: [vendor-rar-readback](../analiz/native-ui-candidate/v7-tv/vendor-rar-readback/); buradaki `Target_GM` doğrudan kök düzeyindedir.

Kullanıcının düzenlediği kaynak RAR'a dokunulmadı. Önceki incelemeye göre değiştiği için paketleme, devir ZIP'inde hash'i doğrulanan özgün RAR'dan yapıldı. Kaynak klasördeki son arşiv ve hazır V7 kökünün karşılaştırması [USB denetim kaydındadır](../analiz/native-ui-candidate/v7-tv/package/usb-discovery-audit.json). Bu, gerçek USB'nin içeriğinin veya mount durumunun gözlemi değildir.

Sürüm, `ProjectReleaseVersion.txt`, bootloader ve kabul kapıları değiştirilmedi. Yeniden başlatmadan sonraki bootloader doğrulaması, aktif TV/anakart uyumu ve V7'nin fiziksel TV'de açılışı bu analizde doğrulanmadı. Önceki [V7 kapsamı ve test sınırları](UI_NATIVE_V7_TV_ADAYI.md) geçerlidir.

Tekrarlanabilir kontroller: `python scripts/audit_usb_update_discovery.py`; RAR üretimi için `scripts/prepare_v7_vendor_rar.py` mevcut çıktının üzerine yazmayı reddeder.

## Kullanıcının istediği D: USB hazırlığı

25 Ekim 2026. D: sürücüsünün FAT32/USB olduğu ve kökünde firmware dosyası bulunmadığı kontrol edildi. Disk aygıt durumu `Healthy/Online`; volume dirty bayrağı işaretliydi. Salt okunur CHKDSK dosya sistemi sorunu bulmadı. Format veya dosya sistemi onarımı yapılmadı.

Kullanıcının açık isteğiyle 17 doğrulanmış dosya ve 11 dizin doğrudan D: köküne kopyalandı; her dosya yazma sonrasında flush/fsync ve SHA256 geri okumasından geçti. Beklenen dosya **`D:/Target_GM/image/GM_SWImage.bin`** yolundadır ve hash'i V7 `3291477403bd9d1961a1e27a45d974fcb7e1bdef54bacc676e10c11bfb0c5e71` ile eşleşir. Önceden var olan dosyalara dokunulmadı. Sürüm/boot etiketleri değiştirilmedi.

Kontrol kaydı: [usb-drive-D-validation.json](../analiz/native-ui-candidate/v7-tv/package/usb-drive-D-validation.json). Bu kopyalama PC'deki dosya yerleşimini doğrular; TV'ye yazma veya TV'nin güncellemeyi kabul ettiğinin testi değildir. `scripts/prepare_v7_usb_drive.py` mevcut hedeflerin üzerine yazmayı reddeder.
