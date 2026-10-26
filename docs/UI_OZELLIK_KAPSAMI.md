# Orijinal özelliklerin modern test ortamına aktarımı

23 Ekim 2026 · `codex/ui-soft-preview` · `http://127.0.0.1:4173/`

Sonraki native aşama: [gerçek firmware üzerinde ayrı UI adayı v2](UI_NATIVE_ADAY_V2.md). Aşağıdaki test ortamı kapsamı TV desteği anlamına gelmez; artık 20 PNG ile sınırlı yerleşim/ikon patch'i gerçek APP kopyasına aktarılmıştır. Tam menü yüzeyleri, kanal kartları ve animasyonların native aktarımı henüz tamamlanmadı.

Temel amaç, orijinal firmware'in kullanıcıya dönük akışlarını anlamak ve görünümü bu akışlar üzerinde modernleştirmektir. Bu sayfa tarayıcı önizleme aşamasını belgeler; firmware çalıştırıcısı veya TV emülatörü değildir. İlk native devamın gerçek değişiklikleri ve sınırları üstteki ayrı rapordadır. Orijinal firmware, bootloader ve TV değiştirilmedi.

## Ölçülen kapsam

Başlangıç **12 menü / 68 satır**, güncel **24 menü / 156 satır**. Bütün menülerin ve satırların kumandayla erişimi gerçek Chrome'da denendi. Bu sayı firmware'in bütün yeteneklerinin sayısı veya yüzde100 davranış eşliği değildir. Mevcut statik envanterde message-map'i bulunan71 farklı Frame sınıfı vardır; bunlar71 kullanıcı menüsü anlamına gelmez. Envanter karşılaştırmasında12 create gövdesindeki769 MString::Set çağrısı yeniden kullanıldı; yeni decompile yapılmadı.

[Tam satır envanteri, adresler ve kanıtlar](../analiz/ui-modernizasyon/feature-coverage.json):

| Kanıt türü | Satır |
|---|---:|
| C içindeki string ataması |24|
| Statik string çağrısı |80|
| Widget bağlantısı |23|
| Yalnız kaynak metni |17|
| Kanıtlı aile altında simülatör için ayrılan seçenek/eylem |12|

**83 satırın doğrudan callsite adresi, fonksiyon adresi ve string ID'si ham MIPS çağrı indeksiyle eşleşti; uyuşmazlık0.** Diğer satırlar önceki C/widget kanıtlarını veya daha zayıf metin/aile kanıtını taşır. Tekrar kullanılan kanıtlar farklı satırda sayılabilir;83 benzersiz fonksiyon sayısı değildir. Varsayılan değerler, aralıklar, seçenek grupları ve host işleme politikaları cihazdan geri kazanılmış kalibrasyon değildir.

## Aileler ve davranışlar

| Aile | Kod/kanıt | Test ortamındaki davranış ve sınır |
|---|---|---|
| Home | `HomePageFrame 0xd42150`, widget haritası | İki yatay raf, ayar kategorileri, medya, kayıt, kanal düzenleyici, zamanlayıcı ve liste; modern beyaz/mavi yüzeyler. Yerleşim birebir cihaz yakalaması değildir. |
| Görüntü | `PictureSettingsFrame 0xe28b14`; Ton `0xe31168`, Gama `0xe32c14`, Film Modu `0xe35bd8` | Mod, ışık, renk/kontrast, format ve gelişmiş seçenekler. SVG yayın arka planına temel renk/format değişimleri uygulanır. CSS karşılığı gerçek görüntü işlemcisinin algoritması değildir. |
| Ses | `SoundSettingsFrame 0xee9afc`; ARC `0xef2ad4`, çıkış `0xef3408` |0–100, otomatik sıfır sessizliği, manuel mute, EQ, balans, çıkış/ARC/CEC kapıları. Fiziksel ses veya CEC ACK yoktur. İnce76×500 panel ve kesintisiz ray korunur. |
| Genel/erişilebilirlik | `GeneralSettingsFrame 0xd01710`, widget50/53/59/62–65 | Dil, sesli betimleme, altyazı, güç/mağaza/sürekli kayıt, ürün bilgisi. Hızlı ses/altyazı seçenekleri asıl ayarlarla senkron kalır; örnek altyazı gösterilir. |
| DIGI LINK | `CecSettingsFrame 0x885268`; aygıt `0x886644`, kumanda `0x886ee0`, bekleme `0x887540` | Menü ve yönlendirme durumları. Aygıt keşfi ve fiziksel bekleme komutu gönderilmez; bağlı donanım yokluğu açık gösterilir. |
| Anten/kaynak | `SourceSetupFrame 0xf0dd24`, `AntennaSettingsFrame 0x7604f0` | LNB, DiSEqC, kaynak, frekans/sembol/polarizasyon, CA/OAD/TKGS bilgileri. Uydu10700–12750MHz, karasal/kablo45–900MHz host aralıkları ayrı. RF taraması veya motor komutu yapılmaz. |
| Kanal girişi/listesi | `0x89552c`, `0x895b24`, `0x8968d8`, liste `0x7995b0` | Sağ üst numara kartı; kanal adı, eşleşmeyen kayıt durumu ve kalan süre. İlk üç basamak3s, dördüncü2s, sil/OK/Geri ayrımı korunur.12 kanal ve program bilgileri kullanıcının izin verdiği kurmaca verilerdir. |
| Kanal düzenleme/rehber | Kanal UI kanıtları, mevcut native list/detail ağacı | Favori, atla, PIN kilidi, sıra değiştirme, önceki kanala dönüş, örnek program bandı. Gerçek EPG akışı alınmaz. |
| Tarih/zaman/program | `TimerAppsFrame 0xf404b8`; tarih `0xf47168`, saat dilimi `0xf48414` | Uyku/açılma/kapanma, program hatırlatma/kayıt zamanlayıcısı; ekle/liste/ayrıntı/sil/tekrar. Takvim epoch'u, saat dilimi ve yaz saati birlikte hesaplanır. Cihaz RTC'si okunmaz. |
| Kayıt/timeshift | `PVRFrame 0xe703cc`; kayıt `0xe83424`, süre `0xe8a220`, beklemede kayıt `0xe89cf0` | USB/TV kapıları, kayıt göstergesi, başlat/durdur/süre/standby, liste ve oynatma/zaman kaydırma durumları. Yalnız örnek metadata/timeline; yayın kaydedilmez veya disk dosyası yazılmaz. |
| USB medya | `DMPFileSelectorFrame 0x8fcac8`, Movie `0x95b684`, Music `0x9b64d0`, Photo `0x9e1350` | Örnek Film/Müzik/Fotoğraf kataloğu, filtre, taşıma kontrolleri, süre/sar/tekrar/karışık, fotoğraf döndürme. Video/ses codec'i veya fiziksel USB dosya erişimi çalıştırılmaz. Fotoğraf için mevcut yerel örnek SVG gösterilir. |
| Ses/altyazı seçimi | `AudioSubtitleSelectFrame 0x870c88`, QuickSettings `0xea4118` | Ayrı kısa menüler, ana ayarlarla iki yönlü ortak değerler. Yayındaki gerçek ses/altyazı stream seçimi yapılmaz. |
| Teletekst | Kaynak dijital teletext string `0xcdc@0xf19318` ve paket sınıf envanteri |100–899 sayfa, alt sayfa, beklet ve renkli tuşlar. İçerik demo; teletekst yayını decode edilmez. Bu navigasyon politikası native koddan bütünüyle doğrulanmış değildir. |
| Güncelleme/yedek | General widget59/63 ve bağlı handler adayları | Güncelleme bilgisi, örnek USB kapısı, bellek içi ayar yedeği/geri alma onayı. Paket yükleme, dosya yazımı veya kurulmuş gibi başarı mesajı yoktur. |
| Lisans/imaj geri alma | General widget62/65 | Paketteki2 gerçek açık font lisans kaynağı17 sayfa olarak okunabilir. Bu metinler tam ürün sözleşmesi değildir. Özel imaj yoksa sıfırlama yapılmış gibi gösterilmez. |

## Varsayılan menüye alınmayanlar

Ağ/Web/APP kullanıcının cihaz kapsamı gereği dışarıda. Otel/fabrika/servis menüsü eklenmedi. Local Dimming, Microdimming, MEMC ve Mükemmel Netlik için paket kanıtı tutuldu; fiziksel model desteği kanıtlanmadığından normal menüde görünmezler. Bluetooth/kamera/3D/DualWatch/4K varlığı da sırf paketteki isimlerden cihaz özelliği sayılmaz. HDMI port kataloğu gerçek konektör sayısı doğrulaması değildir.

Manuel arama ekranı önceki demo kanal numarası formundan ayrıldı: kullanıcı menüsü artık frekans/sembol/polarizasyon ekranına gider. Eski numarayla demo kanal ekleme yolu yalnız eski testlerin yerel yardımcı davranışı olarak kalır; TV'nin RF arama ekranı gibi sunulmaz.

## Doğrulama

**48/48 Node testi geçti:**37 aktif TV/model özelliği +11 önceki yardımcı regresyonu. Aralıklar, PIN, ARC, takvim/tekrar, yedek/restore, kayıt/USB/standby, medya taşıma ve hızlı ayar senkronu sınandı. [Testler](../ui-preview/tests/features.test.mjs).

İki gerçek Chrome paketi kullanılır: [genel sonuç](../analiz/ui-modernizasyon/browser-tests.json), [24 menü/156 satır ve yeni aileler](../analiz/ui-modernizasyon/features-browser-tests.json). Satır erişimi/odak, footer çakışması, numara kartı eşleşme/silme/süre, medya/recording/timer/altyazı/teletekst, lisans sayfalama ve dar ekranlar kontrol edilir. Bu testler her satırın native algoritmasını veya gerçek donanımı doğrulamaz.

```powershell
python scripts/export_tv_menu_schema.py
python scripts/export_preview_licenses.py
node scripts/audit_preview_coverage.mjs
node --test ui-preview/tests/tv-model.test.mjs ui-preview/tests/features.test.mjs ui-preview/tests/state.test.mjs ui-preview/tests/channel.test.mjs
node ui-preview/tests/browser.mjs
node ui-preview/tests/features-browser.mjs
```

Üretici68satırlık tabanı yeniden yazar, `extendMenus`156satırlık aktif kataloğu ekler. `audit_preview_coverage.mjs` genişletilmiş envanteri ve callsite kontrollerini yeniden üretir. Lisans üreticisi yalnız açıkça beyaz listeye alınmış iki kamuya açık font bildirimini okur; kaynak hash'leri `license-data.js` içinde tutulur. Gizli anahtar/sertifika/cihaz kimliği okunmadı veya aktarılmadı.

## Firmware aşamasına geçiş sınırı

Kullanıcı görsel/akış onayı bu host tasarımının kabulüdür; native eşlik veya güvenli TV kurulumu kanıtı değildir. İlk native aktarımın 20 PNG/14 Num kaydı/ikon seçimi patch'i ve paket kontrol alanları v2 raporunda doğrulanmıştır. Tam MUF/DirectFB tasarım eşliği, animasyon ve cihaz kabul/kurtarma yolu hâlâ açıktır. Kurulabilirliği onaylanmış firmware üretilmedi. Önceki motion adayı MIPS'e bağlanmadı.

Kullanılan beceriler: `reverse-engineer-anything`, `redesign-existing-projects`. Alt ajanlar kaynak envanteri, model ve görünümü paylaştı; kullanım limiti sonrası yeniden denenen model ajanı takvim/RF/alias düzeltmelerini tamamladı. Ana ajan entegrasyonu, kaynak callsite kontrolünü, lisans aktarımını ve gerçek tarayıcı kontrollerini yürüttü.


## TV ikonları ve son görsel düzeltme

Kullanıcının sonraki düzeltmesiyle16simgeli özel `tv-icons.svg` bağlandı. Orijinal video/ses görselleri incelendi; göz/ekran, hoparlör, giriş, kilit/zamanlama kavramları korundu.3D yansıma ve iç içe beyaz web kartları yerine32×32 koordinatlı, tutarlı2px çizgili, şeffaf zeminli TV OSD simgeleri kullanılır. Kayıt kırmızı nokta, kanallar numaralı satırlar, kaynak giriş oku ile ayrılır. Kumanda odağı mavi çerçevedir. Ses/mute ve kaynak seçicisinde de aynı simgeler bağlandı.

[Kaynak ID aday eşlemesi](../analiz/ui-modernizasyon/tv-icon-map.json) mevcut native manifestten üretildi. Sonraki v2 aşamasında 12 Home ve 8 ses kaynağı native PNG olarak doğrulandı; önceki19PNG adayının testlerinden ayrı, yeni manifest ve hash kontrolleri vardır. Eşleşmeyen Home/medya/kanal simgelerinin kaynak ID'si ayrıca bağlanmalıdır.

Bildirim bandı oynatma kontrollerini kapatmayacak şekilde yukarı taşındı. HDMI'dan TV'ye dönünce seçili tuner ile kaynak ayarı tutarlı kalır; bunu doğrulayan ek regresyonla Node toplamı48 oldu.

Son birleştirilmiş sürümde48Node testi ve iki Chrome paketi geçti;24menü/156satır ziyaret edildi, konsol/pageerror0. [Birleşik doğrulama özeti](../analiz/ui-modernizasyon/preview-verification-summary.json).


### İkon geometrisi düzeltmesi

Son kullanıcı incelemesinde asimetrik ayar dişlisi, sıkışık kanal rakamları, kaymış pause çubukları ve saat/kayıt/geri çizimleri düzeltildi. Ayar dişlisi merkez(16,16) etrafında8eşit dişten üretilir. TV/görüntü/medya/kayıt ekranları aynı26×20gövde ve ayak geometrisini paylaşır; kaynak ve ses şekilleri dikeymerkeze oturur. Kanal listesi küçük sıkışık rakamlar yerine TV ekranında üç net satır kullanır. Saat yandaki gereksiz çapraz düğmeden arındırılır. Pause çubukları x9–13/x19–23ile merkez16'ya gelir.

`redesign-existing-projects` ile mevcut sprite üzerinde hedefli düzeltme yapıldı; hiçbir işlev/action veya native kaynak ID'si değiştirilmedi. [Önce/sonra karşılaştırma](../analiz/ui-modernizasyon/icons-before-after.png), [16ikonun sınır/merkez/simetri kontrolleri](../analiz/ui-modernizasyon/icon-geometry-tests.json). Bunlar host SVG geometrisi testleridir. Sonraki native PNG aktarımı v2'nin ayrı kaynak manifestinde belgelenir.
