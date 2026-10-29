# V7.10 — SEMIH menü logosu ve hız ayarları

29 Ekim 2026. Ayrı çalışma dalı: `codex/v710-fast-settings-semih`.
`reverse-engineer-anything` ile üç bağımsız araştırma yürütüldü. Orijinal
firmware ve önceki adaylar korunur; TV'ye veya USB'ye yazılmadı.

## Kullanılabilir hızlı kanal geçişi

Mevcut native seçenek **Ayarlar → Genel → Gelişmiş → Hızlı Kanal Geçişi → Evet**.
Bu yeni eklenen bir özellik değildir. TV'nin canlı kullanıcı veritabanı burada
bulunmadığından mevcut seçimin açık olup olmadığı bilinmez; paket bunu zorlamaz.
BasicMode açıksa Gelişmiş girişinin görünürlüğü farklı olabilir.

`GeneralSettingsFrame` widget49, `0xcf58d8` handler'ından
`ArTvSettingsManager::SetFastZapping=0x53d508` yolunu çağırır. Kullanıcı seçimi
kalıcı DB'ye kaydedilir. `MW_DTV_AVMonitor::Start=0x2d9da078` her AV başlangıcında
aynı canlı ayarı okur. Hayır/Evet için AV senkronizasyon bekleme sınırı sırasıyla
2000/200 ms olur. `DoVideoSync=0x2d9d6270` tüketicisi ve customer vtable bağlantısı
doğrulanmıştır. Bu değerler toplam kanal değiştirme süreleri değildir; tuner,
yayın anahtar kareleri ve çözücü beklemeleri sürer. TV'de hız ölçümü yapılmadı.

[Ayrıntılı kod/DB/menü kanıtı](FAST_CHANNEL_ANALIZ.md).

## Hızlı açılışın sınırı

Mevcut güç yönetiminde gerçek STR/suspend ve ara fake-standby durumları bulunur.
Ancak seçili uygulama yolunda `SuspendSystem=0x532d8c`, `0x532dcc` çağrısında
hızlı açılış ayarını okumadan `SetPowerState(2,0)` ister. Kullanıcı/fabrika hızlı
açılış alanlarının bulunması, bunların bu güç yolunu değiştirdiğini kanıtlamaz.
Eski geçiş stub'ları ayrıca doğrulanmıştır. Bu pakette hızlı açılış yaması veya
güç durumlarını atlatma yoktur. Beklemeden dönüş ile AC sonrası soğuk açılış
ayrıdır; ikisinde de yeni süre veya tüketim ölçümü yapılmadı.

[24 fonksiyonluk inceleme ve bayt kanıtları](FAST_BOOT_ANALIZ.md).

## Gerçek native menü değişikliği

Özgün GRUNDIG başlığı fontlu bir TextBox değildir: kaynak915,
`Grundig/icons/brandLogo/logo_400_120.png` bitmap'idir. Birebir OEM font dosyası
geri kazanılamadı. Yeni **SEMIH**, aynı beyaz ve kalın geometrik stile yaklaştırılan
bağımsız SVG harf çizimidir; özgün fontun aynısı olduğu iddia edilmez.

- Yeni özel kaynak **2184**, `Grundig/modern/semih_menu_brand.png`.
- Doku **400×120 P8+tRNS**, widget **260×78**, parent içi konum **(0,8)**.
- Harf yüksekliği34 piksel ve yatay merkez200 korunur; beş harf daha dar görünür.
- `MenuBackgroundFrame` `this+0x1b8` Image alanının iki yöntemindeki dört görsel
  durumu bağlandı: `SetBreadCrumbs=0xdb5328` normal dalı ve `OnCreate=0xdbb4f8`.
- Sekiz `li a1,915` argümanı2184 oldu; branch, çağrı, register, GP, stack,
  widget geometrisi veya kod boyutu değiştirilmedi.
- Kaynak915, ilk kurulum ve cihaz marka kimliği korunur. Ortak menü arka planını
  kullanan ekranlarda SEMIH görünebilir; yalnız bir ekranla sınırlı değildir.
- V7.9'a göre iki mevcut dosya farklıdır: `dvbt_board` ve `Image_res.bin`.
  Tek yeni dosya özel PNG'dir. Diğer16 overlay dosyası birebir V7.9'dur; ses,
  mute, numara girişi, ARC, transponder ve ayar davranışları korunur.

`ArResourceManager::GetOSDBrandName` menü başlığının tüketicisi çıkmadığından
değiştirilmedi. [Kaynak, adres ve tasarım sınırları](SEMIH_MENU_MARKA.md).

![Native kaynak karşılaştırması](../analiz/native-ui-candidate/v7.10-tv/preview/brand-comparison.png)

Bu karşılaştırma gerçek PNG kaynaklarını widget ölçeğinde gösterir; fiziksel TV
ekran görüntüsü değildir. Gerçek menü yerleşimi kod ve Num kaynaklarıyla korunur.

## Doğrulama ve yeniden üretim

RAR: [GMGRMR.-.-.-.-.V03.017.04_V7.10_SEMIH_TEST.rar](../analiz/native-ui-candidate/v7.10-tv/package/GMGRMR.-.-.-.-.V03.017.04_V7.10_SEMIH_TEST.rar).
SHA-256: `aa73474b557899801030b8a9669bdff96d923ca1ceb4c690ab98758b673851ed`.

APP yeniden çıkarılarak **2377 dosya / 2780 metadata kaydı**, UBIFS committed
index üzerinden **19095 node CRC** doğrulandı. BIN'in14 bölümü kontrol edildi;
diğer13 bölüm birebir özgün kaldı. Vendor RAR düzeni **17 dosya / 11 klasör**
olarak korundu;16 dosya özgün ve yalnız SWImage değişik. 7-Zip ile WinRAR testleri
geçti. Bunlar yükleme kabulü veya fiziksel cihaz uyumluluğu kanıtı değildir.

- Hızlı kanal kanıt testleri: **6/6**.
- Hızlı açılış kanıt testleri: **6/6**.
- Native logo, P8/alpha, kaynak tablosu ve sekiz instruction testi: **7/7**.
- Gerçek V7.10 overlay bütünlüğü, V7.9 delta ve çıktı sınırı testleri: **6/6**.
- Toplam **25/25**. Bunlar statik/bayt ve host kaynak kontrolleridir; donanım testi değildir.
- Bağımsız inceleme: [entegrasyon](../analiz/native-features/v710-review/integration-review.json)
  ve aynı dizindeki native logo incelemesi.
- Chromium'da yerel PNG'ler çözüldü; desktop/mobile öneri ve kompakt karşılaştırma
  doğrulandı. Sunucudaki V7.9 ses/numara önizlemesi bu logo testinin yerine geçmez.

Overlay oluşturucu: `scripts/build_native_ui_v710_tv.py`.
APP oluşturucu ve bağımsız okuyucular `--revision v7.10-tv` seçimini destekler.
Paket hash'leri ve tamamlanan APP/BIN/RAR kontrolleri
`analiz/native-ui-candidate/v7.10-tv/phase-results.json` içinde saklanır.

**Fiziksel V7.10 TV testi yapılmadı.** Sıfır hata, sürüm kabulü veya hızlanma
garantisi verilmez. Vendor sürümü V03.017.04 ve boot dosyası değiştirilmez;
güncelleme sürüm denetimini atlatan yeni işlem yoktur. Yeni4K decoder değişikliği yoktur.
