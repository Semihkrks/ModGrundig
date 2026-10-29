# ModGrundig — faydalı özellikler için öncelik planı

29 Ekim 2026. Kullanıcı, arayüz düzenlemelerinin ardından TV'yi gerçekten iyileştirecek mevcut/gizli yetenekler için plan istedi. Bu aşama yalnız araştırma ve planlamadır: firmware, paketler, cihaz ayarları veya TV değiştirilmedi. Kullanılan beceri `reverse-engineer-anything`; önceki kanıtlar yeniden kullanıldı. Yeni olarak üç modülde beş küçük fonksiyonun orijinal assembly gövdesi okundu; yeni decompile, benchmark veya cihaz testi yapılmadı.

“Kodda adı var”, “çağrı yolu var” ve “bu cihazda çalışıyor” ayrı durumlardır. Bir ayar dosyasındaki build makrosunu değiştirmek derlenmiş özelliği etkinleştirdiğimizi göstermez. Mevcut özelliğin cihazda zaten kullanılabildiği anlaşılırsa yeniden geliştirme yerine o iş tamamlanmış kabul edilir.

## Öncelikler

29 Ekim devamı: [hızlı kanal geçişinin gerçek native ayarı](FAST_CHANNEL_ANALIZ.md)
doğrulandı: Genel → Gelişmiş → Hızlı Kanal Geçişi → Evet. DB seçimi AV-sync
bekleme sınırına ulaşır; toplam kanal süresi henüz ölçülmedi. [Hızlı açılış
incelemesi](FAST_BOOT_ANALIZ.md), seçili güç yolunun ayardan bağımsız STR isteğini
gösterdi; güvenilir ek hızlandırma yaması çıkarılmadı. Bu iki araştırmada firmware
değişmedi. Ayrı [V7.10 adayında](UI_NATIVE_V710_SEMIH_VE_HIZ.md) yalnız native menü
logosu SEMIH yapıldı; bu, yukarıdaki ilk plan aşamasından sonraki uygulamadır.

| Sıra | İş | Beklenen pratik fayda | Mevcut kanıt / durum | Sonraki geçiş koşulu |
|---|---|---|---|---|
|1|Hızlı kanal geçişinin etkinliğini çözmek|Kanal değiştirirken bekleme ve siyah ekran süresini azaltma potansiyeli.|Native ayar→kalıcı DB→AV monitor→200/2000ms sync bekleme sınırı doğrulandı. Toplam hızlanma ve canlı cihaz ayarı ölçülmedi.|Mevcut ayarı Evet seç; aynı/farklı transponder ve şifreli/şifresiz geçişleri ayrı ölç.|
|2|HDMI oyun/PC modu adayını çözmek|Konsol/PC girişinde gecikmeyi azaltma potansiyeli.|Servis ve müşteri PQ wrapper'ları var; temel PQ wrapper yalnız printf+return0. Sanal hedefler ve gerçek cihaz davranışı henüz çözülmedi.|Customer nesne/vtable ve son sürücü çağrısı doğrulansın; gerçek gecikme farkı ve geri dönüş test edilsin.|
|3|Kaynak başına kırpmasız/1:1 görüntü seçimi|HDMI/PC'de kesilen kenarlar ve gereksiz ölçeklemeden kaynaklanan yazı bulanıklığını azaltma potansiyeli.|Resim formatı UI'si, kullanıcı overscan alanı ve scaler yolları mevcut. Her kaynakta mevcut kırpma durumu ölçülmedi.|1080p test deseniyle kenar/kare eşleşmesini doğrula; SD/AFD/altyazı davranışını koru.|
|4|Ses dengesi ve kaynak bazlı ses profili|Reklam/kanal geçişlerindeki ses farklarını azaltmak; gerekirse ses gecikmesini ayarlamak.|AVL, dijital çıkış ve ses gecikmesi UI kanıtı var; audio AVC importları var. Yeni algoritma/başarılı fiziksel işleme kanıtı değil.|AVL/AVC setter→backend bağını doğrula; aynı ses içeriğiyle etki/bozulma ve ARC davranışını karşılaştır.|
|5|USB sürekli kayıt/timeshift ve programlı kayıt kontrolü|Canlı yayını durdurma/geri sarma ve zamanlı kayıt.|PVR/CI+PVR/EPG build kayıtları1; gerçek PVR/sürekli kayıt menü bağlantıları var. Cihaz, USB ve yayın koşullarıyla çalışması ölçülmedi.|Önce mevcut işlevi USB ile doğrula; eksik menü/feature kapısı varsa kök nedeni çöz. Kayıt ve standby dönüşünü ayrı test et.|
|6|Kanal sırasını koruyan ek tarama ve transponder güncelleme|Frekans değişince favori/sıra kaybetmeden yeni servis bulmak.|TKGS build1 ve UI bağlantısı var. V7.8 araştırmasında geçerli SAT DB'nin yeni default XML'i birleştirmediği kanıtlandı.|Mevcut DB'ye artımlı merge/duplicate politikası ve hata halinde geri alma tasarlanıp test edilsin; reset kullanılmasın.|
|7|Doğrulanabilir USB ayar/kanal yedeği|Denemelerden sonra ayarları ve kanal sırasını geri getirebilmek.|Ayar yedekleme ailesine UI/string bağlantısı var; kanal DB'sini de kapsayan tam güvenli restore yolu henüz kanıtlanmadı.|Nelerin yedeklendiğini çöz; kanal ve kullanıcı ayarlarını sürümlü/checksum'lı tut; önce kopyada geri yükleme doğrula.|
|8|Hızlı açılma/standby araştırması|Beklemeden TV'ye dönüşü hızlandırma potansiyeli.|24 fonksiyon incelendi; seçili SuspendSystem yolu ayarı okumadan STR ister. Eski hızlı açılış geçişleri stub; gerçek STR desteği mevcut. Güvenilir ek hızlandırma yaması çıkarılmadı.|Güç yolunu atlatmadan yeni somut bağlantı veya cihaz ölçümü gerekir. Açılma süresi, standby tüketimi ve USB/CEC/tuner geri dönüşü ölçülmeli.|

İlk öneri **hızlı kanal geçişi → oyun/PC yolu → kırpmasız görüntü** incelemesidir. USB kayıt zaten kullanılabiliyorsa5. iş geliştirme kuyruğundan çıkar. Hızlı açılma, kapalı build kaydı ve güç/uyanma kapsamı nedeniyle son sıradadır. Kesin hızlanma yüzdesi, açılış süresi veya input-lag değeri verilmez; ölçüm yapılmadı.

## Kanıt dizini

- [Önceki özellik/CONFIG araştırması](../analiz/native-4k/config/findings.md): PVR/CEC/ARC/TKGS mevcut altyapısı; build/çalışma anı ayrımı; hızlı açılma ve donanım seçenekleri.
- [Menü/event kanıtları](../analiz/ui-modernizasyon/feature-coverage.json):
  - Hızlı kanal geçişi: `GeneralSettingsFrame0xd01710`, widget49, label callsite`0xd1748c`, event handler`0x00cf58d8`.
  - Hızlı açılma: aynı frame, widget56, label callsite`0xd1b1cc`, event handler`0x00cf576c`.
  - AVL: `SoundSettingsFrame0xee9afc`, label callsite`0xef02dc`. Ses gecikmesi label`0xef0c28`.
  - Resim formatı: `PictureSettingsFrame0xe28b14`, label callsite`0xe2b970`.
  - Sürekli kayıt: `GeneralSettingsFrame0xd01710`, label callsite`0xd1978c`; kayıt frame`0xe703cc`, kayıt label`0xe83424`.
  - TKGS: `SourceSetupFrame0xf0dd24`, label callsite`0xf12640`.
  - Ayar yedekleme: GeneralSettings label callsite`0xd1e394`. Bu isim bütün kanal DB'sinin başarıyla yedeklendiği anlamına gelmez.
- [Yeni beş gövdenin hash/adres/GOT kaydı](../analiz/feature-roadmap/selected-game-overscan-functions.json):
  - `libmsrv_common.so:MSrv_Picture::SetGameModeOnOff0x2d99c314`,92 bayt: pencere/PQ nesnesini alır; `0x2d99c358`'de vtable`+0x154` hedefini yükler ve tail-call yapar. Hedef somut nesne/vtable ile ayrıca çözülmeli.
  - `libMStarSDK.so:mapi_pql::SetGameModeOnOff0x2cb60824`,68 bayt: printf ve return0. Bu temel fonksiyonun adı donanım oyun modu kanıtı yapılmaz.
  - `libMStarSDK_customer.so:mapi_pql_customer::SetGameModeOnOff0x2dc76928`,112 bayt: pencere enum dönüşümünü yapar; `0x2dc7695c`'de sanal`+0x1dc` hedefini alıp`0x2dc76974`'te çağırır. Müşteri override yolu, sürücü hedefi ve cihaz seçimi henüz doğrulanmadı.
  - `libmsrv_common.so:MSrv_Player::SetUserOverScanMode0x2d99f748`,8 bayt: kullanıcı alanını yazan küçük setter; gerçek kırpma uygulaması ayrı yoldur.
  - `libMStarSDK.so:mapi_video_base::EnableOverScan0x2cbaef48`,56 bayt: statik overscan byte'ını boolean yapar. Tek başına1:1 görüntü veya kaynak başına kayıt kanıtı değildir.
- [Gerçek SAT DB tüketici analizi](../analiz/native-4k/transponders/consumer-findings.md): geçerli DB yolunda default XML merge yok; ResetSatDB ana/yedek depolarını temizler. Planlanan artımlı güncellemenin bunun yerine geçmesi gerekir.

## Üretici kaynakları nasıl kullanıldı

29 Ekim 2026'da kontrol edildi. [Beko'nun USB kayıt açıklaması](https://documents.beko.com/TV/BK2T00/tr-TR/192499723.html), kayıt ve timeshift için harici veri ortamı gerektiğini anlatır. Bu sayfa GMGRMR modeline ait bir uyumluluk belgesi olarak kullanılmadı.

[Beko DZ8T00 kılavuzu](https://docs.beko.com/DZ8T00/DZ8T00_MDM2_USER_MANUAL_FILE_tr_TR.pdf) oyun/PC modu ve HDMI RGB aralığının amacını açıklayan başka bir modelin kaynağıdır. Bu modeldeki gecikme rakamı veya destek listesi bizim TV'ye taşınmadı. Bizim adayımızın dayanağı yerel native wrapper'lar ve çözülmesi gereken sanal çağrılardır.

## Şimdilik plana alınmayanlar

PIP/ikinci tuner, MEMC, Local Dimming, Bluetooth/ağ, HDR veya paneli120Hz yapma gibi başlıklar için cihazın gerekli donanımı ve aktif sürücü yolu kanıtlanmadı. Kapalı macro veya ortak aile kaynağı tek başına açılabilirlik değildir. Fiziksel panel tipi, timing, akım ve fabrika kalibrasyonu rastgele değiştirilmez.

4K ayrı A/V araştırmasıdır: V7.8 kullanıcı gözleminde TRT Ultra HD listelenir, iki ses seçeneğinde ses ve görüntü yoktur. Kanal keşfi, decoder ve1080p ölçekleme birbirinden ayrılmalıdır; kesin çözüm taahhüdü verilmez. Bu plan4K decoder desteği eklemez.

Her uygulama adımı ayrı adayda tutulacak; önce gerçekten çalışan ayar/servis yolu, ardından cihazda gözlenebilir fayda doğrulanacaktır. Mevcut orijinal menü tasarımı korunacaktır.
