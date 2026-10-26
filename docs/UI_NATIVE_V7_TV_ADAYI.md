# V7 TV adayı — yalnız ses ve numara ekranı

**Sonraki cihaz gözlemi, 25 Ekim:** Kullanıcı bu V7'yi yükleyip TV açılışı, yayın ve ses panelini bildirdi. Fotoğraflarda köşeli/kenara yakın ses paneli ve kırpılmış numara kartı görüldü. Aşağıdaki test öncesi durum tarihsel kayıttır; güncel düzeltme ve test adayı [V7.1 belgesindedir](UI_NATIVE_V71_TV_DUZELTMELERI.md). V7.1 cihazda henüz denenmedi.

25 Ekim 2026. Kullanıcının son kararı uygulanır: **ana menü, menü ikonları, ayarlar, kanal listesi ve bilgi bandı orijinaldir**. V8 menü çalışması iptal edilerek ayrı arşivde korunmuştur. Bu aday V7'nin ses/numara kaynaklarını kullanır; V7 araştırma overlay'indeki12 modern menü ikonu özellikle çıkarılmıştır.

## Dosya ve kapsam

[Doğrulanmış BIN adayı](../analiz/native-ui-candidate/v7-tv/package/GM_SWImage_UI_v7_OFFLINE_UNVERIFIED.bin),42.483.736 bayt.

SHA256: `3291477403bd9d1961a1e27a45d974fcb7e1bdef54bacc676e10c11bfb0c5e71`.

Overlay12 dosyadır:11 özgün dosya değişir,1 sayısal arka plan PNG'si eklenir. ELF'te orijinale göre32 instruction word farkı vardır. Değişen Num ID'leri yalnız ses `0x5a3e..0x5a79` ve numara `0x98f..0x99a` aralıklarındadır. Önceki2179 Image kaydının gövdesi aynıdır; sona yalnız numeric2179 eklenir. Global Color/font tabloları ve mevcut menü resource ID'leri korunur.

- Ses kapsülü68×450, hoparlör/mute44×44; DINPro-CondMedium36 korunur. Ses0 ve açık mute için ID680 seçimi gerçek `RefreshVolumeUI0xfb7d18` yürütmesiyle kontrol edildi. ARC yönlendirme/event kodu değiştirilmedi.
- Sayı kartı310×224, kavisli gerçek PNG, DejaVu Sans58 ve daha açık başlık/rakam aralığı. Gerçek mevcut `ChannelControlFrame` widget'ları kullanılır; rakam/timeout/kanal seçimi işleyicileri aynı kalır.
- Kanal adı köprüsü kurulmadı. Tarayıcıdaki örnek kanal eşleştirmesi bu firmware'e eklenmiş gibi sunulmaz. Fake kanal, HTML uygulaması veya yeni menü servisi pakete konmaz.

ELF SHA256: `9ededb627b8548d0b12f6495d66bac4a0943fb3d92e83a2f3547a86b1ec33dc3`. Num SHA256: `d293c1c7aeec39c4384915a66aa42be0c37b1fd52b726e74022551707d122cfa`.

[Üretici](../scripts/build_native_ui_v7_tv.py), [manifest](../analiz/native-ui-candidate/v7-tv/manifest.json), [kodda sabitlenen dosya kimlikleri](../scripts/native_ui_v7_tv_pins.py).

## Paket doğrulaması

| Kontrol | Sonuç |
|---|---|
| APP dosya/metaveri |2.372 dosya,2.775 kayıt yeniden çıkarılıp karşılaştırıldı;2.360 özgün dosya aynı |
| Orijinal menü koruması |12 eski menü PNG hash'i, bütün message tabloları,1.000'den fazla FDE handler gövdesi ve menü dışına taşmayan Num/Image değişiklikleri kontrol edildi |
| V7 TV kapsam testleri |4/4 geçti |
| Native çizim |16 geçti; iptal edilen V8 menü testi1 atlandı, geçmiş sayılmadı |
| Native ses/mute/mode |32/32 sınırlı MIPS senaryosu döndü; yerel sıfır/mute ikonları doğrulandı |
| HTTP / JS / Chrome |6/6 HTTP,9/9 JS;4 gerçek tarayıcı kontrolü,0 konsol/HTTP hatası |
| APP host yardımcı testleri |8/8; bağımsız metaveri politikası6/6 |
| Kapsayıcı |14/14 payload açıldı, diğer13 aynı; bütün offsetler, dış CRC'ler ve APP CRC doğrulandı |
| Bağımsız diskten okuma |PASS_OFFLINE_ONLY; özgün APP'den metaveri tekrar okundu |

APP39.108.608 bayt, SHA256 `7ac44846e741976f9f359f5c415e31a8647456e211558cdabfdcc0312ec80958`. Format4/flags0/min_io2048/LEB126976/maxLEB321;308 LEB kullanılır.

APP'yi iki kez sıkıştırmanın sabit kapsayıcı alanını aşması üzerine, yalnız ELF'in UBIFS DATA blokları sıkıştırmasız, diğer dosyalar LZO ile tutuldu. Dosya baytları ve izin/sahip/zaman/nlink metaverileri yeniden karşılaştırıldı. Kullanılan0/1 codec'ler özgün APP'de de vardır; yeni kernel codec'i gerekmez. [Gerçek host davranışı deneyi](../analiz/native-ui-port-v8/selective-compression-probe.json) ve [yeni APP codec kontrolü](../analiz/native-ui-candidate/v7-tv/package/storage-validation.json). Bu, dosya sistemi yerleşimini değiştirir; fiziksel performans/mount testi değildir.

Dış LZMA biçimi aynı64MiB/lc3/lp0/pb2, bilinen çıktı boyutu ve BE-EF son eki kullanır. Sıkıştırılmış APP16.753.083 bayt; özgün17.432.576 baytlık slotta679.493 bayt kalır. Hiçbir bölüm offset'i taşınmadı.

Kanıtlar: [APP](../analiz/native-ui-candidate/v7-tv/package/app-build-validation.json), [kapsayıcı](../analiz/native-ui-candidate/v7-tv/package/container-validation.json), [bağımsız geri okuma](../analiz/native-ui-candidate/v7-tv/package/independent-readback.json), [32 native senaryo](../analiz/native-ui-candidate/v7-tv/native-volume-cases.json), [Chrome](../analiz/native-ui-candidate/v7-tv/native-browser-tests.json).

## TV kurulumu açısından durum

**Bu, çevrimdışı kontrollerden geçmiş test adayıdır; fiziksel TV'de doğrulanmış/sıfır hatalı nihai sürüm değildir.** Orijinal RAR'ın aktif cihaz dump'ıyla ve gerçek bootloader kabulüyle eşliği doğrulanmadı. CRC eşleşmesi kriptografik kabul veya güvenli yükleme garantisi vermez. TV'ye yazılmadı; gömülü güncelleme scriptleri çalıştırılmadı.

İnceleme klasöründe doğru kaynak yolu `Target_GM/image/GM_SWImage.bin` korunur. Bu klasör otomatik/eksiksiz USB yükleyici sayılmaz; bootloader veya fabrika kimlik/kalibrasyon scriptleri eklenmez ve yükleme tuşları/prosedürü tahmin edilmez. Özgün dosyalar, önceki V7 ve iptal edilmiş V8 deneyi ayrıdır.

Yerel [native test yüzeyi](http://127.0.0.1:4174/) yalnız ses/sayı karelerini gösterir; tam TV açılışı, video düzlemi veya donanım ses çıkışı değildir. Kullanılan beceri `reverse-engineer-anything`; son koruma/kapsam testleri ana ajan tarafından tamamlandı.

İnceleme arşivi: [V7_INCELEME_ADAYI.zip](../analiz/native-ui-candidate/v7-tv/package/V7_INCELEME_ADAYI.zip). [Klasörde doğru adlı GM_SWImage.bin](../analiz/native-ui-candidate/v7-tv/review-bundle/Target_GM/image/GM_SWImage.bin). ZIP CRC’si ve içindeki BIN’in SHA256 eşliği doğrulandı; bu bir otomatik kurulum onayı değildir. [Aşama kaydı](../analiz/native-ui-candidate/v7-tv/phase-results.json).

25 Ekim ek kontrolü: [Orijinal RAR'ın 17 dosya/11 dizin envanteri ve V7 ZIP farkları](FIRMWARE_RAR_PAKET_YAPISI.md) doğrudan arşivle karşılaştırıldı. Servis scriptlerinin beklediği 12 harici dosya kaynak RAR'da da yoktur; bu durum sıradan güncelleme için zorunlu olduklarını kanıtlamaz. Ayrı GM_Boot dosyasının ZIP'e eklenmemiş olması, SWImage içindeki mboot güncelleme ifadelerini devre dışı bırakmaz. Bu aşamada mevcut V7 BIN/ZIP değiştirilmedi.

USB mesajı araştırması: [Dosya bulma kodu ve doğru kök yolu](USB_GUNCELLEME_DOSYA_BULMA.md). Kaynak yapısını koruyan [V7 RAR](../analiz/native-ui-candidate/v7-tv/package/GMGRMR.-.-.-.-.V03.017.04_V7_TEST.rar), 17 dosya/11 dizin, 7-Zip ve WinRAR testlerinden geçti. Yeni RAR'da yalnız SWImage değişti; orijinal boot ve servis dosyaları korunur. Sürüm 05 yapılmadı: USB menüsünün dosya bulunamadığında gösterdiği “daha yeni sürüm” metni statik olarak çözüldü; sonraki bootloader kabulü hâlâ doğrulanmadı.
