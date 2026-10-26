# V7.3 — mevcut sessiz ikonunu koruyarak gri durum

**26 Ekim cihaz sonucu: REDDEDİLDİ — YÜKLEMEYİN.** Kullanıcı ses panelinin görünmediğini ve TV'nin donduğunu bildirdi; V7.1'in çalıştığını doğruladı. V7.3'ün atladığı GP geri yüklemesi regresyonda geçersiz bellek erişimi üretti. [V7.1 tabanlı V7.4 teşhis ve düzeltmesi](UI_NATIVE_V74_GP_DUZELTMESI.md). Aşağıdaki önceki çevrimdışı test sonuçları cihaz başarısı değildir.

25 Ekim 2026. Kullanıcı V7.2'de önerilen yeni çapraz ikonu istemediğini açıkladı: **V7.1'de beğenilen ikon şekli korunmalı; ses0 veya mute durumunda gri olmalı; panel kapandıktan sonra görünen mevcut sessiz göstergesinin kaynağı da güncellenmelidir.** V7.2 ara çıktısı dağıtım adayı olmaktan çıkarıldı. Güncel aday V7.3'tür.

## Son davranış

- Ses1–100, mute kapalı: mevcut beyaz kapsül ve mavi hoparlör.
- Ses0 veya mute açık: nötr gri kapsül `#E8E8E8`, **önceki sessiz ikonunun gri şekli**. Yeni slash tasarımı kullanılmaz.
- Mute kapanır / ses0'dan yükselir: normal kaynaklara döner.
- Panelin süresi dolduğunda, gerçek `IsMuted` açıksa firmware'in mevcut ayrı sessiz uygulaması aynı ortak gri ikonu kullanır. Sesin yalnız0 olması bu ayrı uygulamayı başlatmaz; mevcut zamanlayıcı kuralı korunmuştur.

Mute açıkken saklanan ses değeri değiştirilmez. Örneğin35'te mute açıldığında sayı35 kalır. Ses yönlendirmesi, ARC ve menüler bu görsel düzeltmeyle değiştirilmez.

## Gerçek dosya ve kod yolları

| Kullanım | Image ID / yol | Kanıt |
|---|---|---|
| Panel ve ayrı göstergenin normal sessiz ikonu | 680 → `/rc/ARimages/Grundig/volume/mute_icon.png` | Volume Refresh `0xfb7d18`; MuteControl OnCreate `0xdf8630`, setter `0xdf932c` |
| Ayrı göstergenin diğer üç görsel durumu | 401 → `/rc/ARimages/Grundig/volume/mute_button_grundig.png` | Setter'lar `0xdf9350`, `0xdf9374`, `0xdf9398` |
| Sessiz panel arka planı | 2180 → `/rc/ARimages/Grundig/modern/volume_muted_bg.png` | V7.2'den korunan normal-mode Refresh bloğu `0xfb8200..0xfb8358` |

Image680 için V7.1'in **100×99 P8** dosyası kaynak alındı. Bütün palet indeksleri ve alfa baytları aynıdır; yalnız RGB paleti nötr griye dönüştürülür. Böylece beğenilen şekil, antialias dağılımı ve şeffaf köşeler korunur. Paneldeki widget44×44, ayrı göstergedeki widget100×100'dür; kaynak PNG boyutu widget boyutuyla karıştırılmaz.

Image401, mevcut85×95 RGB boyutunu koruyarak aynı gri ikonla güncellenir. Image2180,68×450 RGBA ve yarıçap34 kalır; yalnız mavi-gri tonu nötr griye döner. V7.3'ün ELF/Num/Image baytları V7.2 ile birebir aynıdır. V7.3 yalnız bu üç PNG'yi değiştirir; mevcut401 dosyası overlay'e eklenerek toplam14 dosya olur. Özgün firmware'e göre12 dosya değişikliği ve2 özel PNG vardır.

## Mevcut kalıcı göstergenin yaşam döngüsü

`VolumeControlFrame::TimerEventHandler` (`0xfb7aec`) panel uygulamasını kapatır. `IsMuted` doğruysa mevcut `MuteControlFrame` yokken `MuteControlApp` oluşturup `Run(0x10ff,0)` çağırır (`0xfb7ca4`); varsa uygulamasını gösterir (`0xfb7ce8`). Yeni bir zamanlayıcı veya sahte gösterge eklenmedi.

`MuteControlFrame::OnCreate` (`0xdf8630`) içindeki normal ikon `frame+0x18c`, parent `+0x188` altındadır. Dış pencere `(0,435,160,230)`, normal kök `(0,0,165,230)`, alt panel `(0,25,158,165)`, ikon `(0,30,100,100)` olduğundan nominal ekran ikonu `(0,490,100,100)` olur. Bunlar1920×1080 mantıksal koordinatlardır; fiziksel ölçekleme/overscan ölçülmedi. `SetMuteInDeviceMode` (`0xdf8454`) ARC etkinliği/CEC/HDMI koşullarıyla ayrı ARC kökünü seçmeye devam eder.

Kaynaklar: [Timer C](../analiz/native/ui-targeted/dvbt_board/00fb7aec.c), [adres ve message map envanteri](../analiz/ui-yapi-haritasi.json), [gri asset üreticisi](../scripts/native_ui_v73_gray.py), [compositor](../scripts/build_native_ui_v73_tv.py), [manifest](../analiz/native-ui-candidate/v7.3-tv/manifest.json), [sabit kimlikler](../scripts/native_ui_v73_tv_pins.py).

## Doğrulama ve sınırlar

- Asset testleri4/4 geçti: eski indeks/alfa eşliği, bütün görünür RGB kanallarının gri olması, okunabilir ikon kontrastı, üç PNG dışındaki baytların korunması ve bozuk girdilerin reddi.
- Bağımsız Sol incelemesi14/14 pin/manifest eşliğini ve680/401/2180 bağlantılarını kontrol etti; somut kusur bulmadı.
- V7.2'den aynı kalan native seçici için220 sınırlı MIPS vakası ve5 ABI stres kontrolü geçerlidir; V7.3'te yeni native değişiklik yoktur. [V7.2 yöntem ve adres kanıtı](UI_NATIVE_V72_SESSIZ_DURUMU.md).
- Son önizleme turunda45 test geçti,1 tarihsel V8 testi atlandı. Yerel HTTP'de altı0/100/mute/normal geçişi ve ayrı `mute` test sahnesi doğru kaynakları döndürdü; JS sözdizimi geçti. [Son test raporu](../analiz/native-frame-rehost/v73/verification.json).
- Son APP2.373 dosya /2.776 metaveri kaydıyla yeniden çıkarılıp karşılaştırıldı;2.359 özgün dosya aynıdır. Diğer paket ölçümleri [aşama kaydındadır](../analiz/native-ui-candidate/v7.3-tv/phase-results.json).

[Normal35](../analiz/native-frame-rehost/v73/normal35.png), [mute35](../analiz/native-frame-rehost/v73/mute35.png), [ses0](../analiz/native-frame-rehost/v73/zero0.png), [ayrı mevcut ikon](../analiz/native-frame-rehost/v73/badge.png). İlk üç kare sınırlı native Refresh + MUF çizim fonksiyonlarıyla host Pillow yüzeyinde oluşur. Ayrı ikon sahnesi yalnız kanıtlanmış kaynak/konumun çizimidir; yaşam döngüsü ve eski gölge/border parçaları yürütülmez. Tam TV görüntüsü olarak sunulmaz. Ana ajan son mute ve ayrı ikon görsellerini gözle inceledi.

Bu tur Chrome klavye testi tamamlanmadı. Computer Use, Windows'ta mevcut URL'yi politika uygulamak için yeterli güvenle belirleyemediğinden UI işlemini durdurdu; GUI tekrar denenmedi. HTTP ve native testleri bu sınırla raporlanır. Paket içindeki `png-decoder-validation.json` eski üç girişli decoder deneyinin kopyasıdır; son PNG'lerin cihazda veya native PNG decoder'da çalıştırıldığı kanıtı değildir.

## Paket

[V7.3 RAR test paketi](../analiz/native-ui-candidate/v7.3-tv/package/GMGRMR.-.-.-.-.V03.017.04_V7.3_TEST.rar), [BIN](../analiz/native-ui-candidate/v7.3-tv/package/GM_SWImage_UI_v7.3-tv_OFFLINE_UNVERIFIED.bin). Üreticinin17 dosya /11 dizin düzeni korunur. USB kökündeki beklenen yol `Target_GM/image/GM_SWImage.bin`; sürüm etiketi04 kalır.

Raporlar: [APP](../analiz/native-ui-candidate/v7.3-tv/package/app-build-validation.json), [storage](../analiz/native-ui-candidate/v7.3-tv/package/storage-validation.json), [container](../analiz/native-ui-candidate/v7.3-tv/package/container-validation.json), [bağımsız geri okuma](../analiz/native-ui-candidate/v7.3-tv/package/independent-readback.json), [RAR](../analiz/native-ui-candidate/v7.3-tv/package/vendor-rar-validation.json). Hash'ler [aşama kaydına](../analiz/native-ui-candidate/v7.3-tv/phase-results.json) bağlanır.

V7.3 fiziksel TV'de denenmedi. Gerçek alfa/cache, kumanda, panel sonrası kalıcı gösterge ve ARC kontrolü cihazda bekler. Orijinaller ve çalışan V7 korunur; USB veya TV'ye yazılmadı. `flash_ready=false`, `television_tested=false`. Kullanılan beceri `reverse-engineer-anything`; Ghidra çıktıları doğrudan statik kanıttır.
