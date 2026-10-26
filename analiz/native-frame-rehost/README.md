# Yerel MUF çizim kodundan kare — 24 Ekim 2026

Güncel: [V7 TV ses/numara adayı](../../docs/UI_NATIVE_V7_TV_ADAYI.md). Menüler orijinaldir; V8 menü deneyi iptal edildi. [Ses0](v7-tv-volume-0.png), [numara12](v7-tv-numeric-12.png). Aşağıdaki diğer sürümler tarihsel kayıttır.

25 Ekim güncel native sürüm [v8](../../docs/UI_NATIVE_ADAY_V8.md): [MUF kaynak testi](v8-native-resources.png), [ses0](v8-volume-0.png), [sayı12](v8-numeric-12.png). Kaynak levhası gerçek v8 kaynaklarını özgün MUF üzerinden host test düzeninde çizer; tam menü/event döngüsü değildir. V8 sayı görüntüsüne örnek kanal adı eklenmez. Native çizim17/17, HTTP6/6; önceki sayaçlar tarihsel kayıttır.

Güncel aşama [v7](../../docs/UI_MENU_AYARLAR_V7.md): [ses35](v7-volume-35.png), [kanal12](v7-numeric-12.png). Ses ikonu44px, kapsül68×450; rakam y118 ve önerilen ad y206 ile aralarında10px bulunur. Ad örnek veriden oluşturulmuş test widget'ıdır; gerçek firmware kanal köprüsü kurulmadı. Güncel native çizim testleri15/15. Aşağıdaki v5/v4 sonuçları tarihsel kayıttır. Tam menüler ayrı [HTML önizlemesindedir](http://127.0.0.1:4174/preview/?menu=1).

Güncel çıktı [v5](../../docs/UI_NATIVE_ADAY_V5.md): [ses35](v5-volume-35.png), [ses0](v5-volume-0.png), [mute](v5-volume-35-mute.png), [ses100](v5-volume-100.png), [rakam123](v5-numeric-123.png), [rakam10000](v5-numeric-10000.png). Kompakt68×450 kapsül,42×42 ikon, geri alınmış DINPro ses fontu ve gerçek kavisli kanal kartı bağlandı. Güncel çizim testleri12/12; aşağıdaki8/8 ve v3/v4 ayrıntıları önceki aşamaların kaydıdır.

Güncel görsel varyant **v4**: [ses35](v4-volume-35.png), [ses0](v4-volume-0.png), [mute](v4-volume-35-mute.png), [ses100](v4-volume-100.png), [numara123](v4-numeric-123.png). Ses sayısı artık özgün firmware'de zaten bulunan Lucida Sans Bold36 ile ve koyu Color0 ile çizilir; büyütülmüş hoparlör/mute PNG'leri gerçek v4 overlay'den okunur. Font/renk tercihi yalnız varyant adına bakılarak uydurulmaz: seçilen sabit hash'li ELF'in `0xfbbe18/28/38/48` ve `0xfbbc30/50/70/90` adreslerindeki sekiz yerel OnCreate argümanı okunup doğrulanır. OnCreate gövdesi yine yürütülmez. Global font/renk/Num tabloları değiştirilmez.

Lucida36 için Pillow `getmetrics()` `(28,-7)` döndürür; mevcut model `GetHeight=21` kabul eder. Bu açık bir host font metriği sınırıdır, gerçek DirectFB `GetHeight` sonucu değildir. Daha güzel görünmesi için metin koordinatı veya font yüksekliği kanıtsız biçimde değiştirilmedi. Gerçek TV piksel eşitliği henüz doğrulanmadı.

Bu görüntüler HTML önizlemesi değildir. Orijinal `libmuf.so` içindeki seçilmiş MIPS komutları Unicorn üzerinde yürütülür; DirectFB yüzey çağrılarını açıkça tanımlanmış Pillow yazılım yüzeyi karşılar. Tam TV uygulaması, tuner, görüntü çözücüsü veya SoC emülasyonu çalışmış değildir. Koyu arka plan nötr test yüzeyidir; yayın görüntüsü değildir.

Görseller:

- [Orijinal ses35](original-volume-35.png), [v3 ses35](v3-volume-35.png)
- [Orijinal ses0](original-volume-0.png), [v3 ses0](v3-volume-0.png)
- [v3 sessiz](v3-volume-35-mute.png), [v3 ses100](v3-volume-100.png)
- [Orijinal rakam123](original-numeric-123.png), [v3 rakam123](v3-numeric-123.png)

Her PNG'nin yanında adresleri, callback sınırlarını, kaynak hashlerini ve model varsayımlarını içeren aynı adlı JSON bulunur. Kaynak dosyalar değiştirilmez; yalnız `analiz/native-frame-rehost/` çıktıları yazılır. Emülatöre syscall, ağ veya donanım erişimi verilmez. Bilinmeyen çağrı, eşlenmemiş bellek ve komut bütçesi aşımı işlemi durdurur.

## Gerçekte yürütülen kod

`libmuf.so` SHA256: `494d4aa45a3c8d8e10760388d8d30111e9127a0357d38cdf97979b9f9bb16d96`.

| Fonksiyon | Giriş | v3 ses35 benzersiz yürütülen komut |
|---|---|---:|
| MWidget::DrawBackground | `0x2e251be4` | 212 |
| MResourceManager::RenderImageToSurface(MImg...) | `0x2e23e684` | 187 |
| MWidget::DrawBorders | `0x2e24d438` | 17 |
| MWidget::DrawString | `0x2e24de4c` | 157 |
| MWidget::CalculateTextDrawFlags | `0x2e24fe3c` | 66 |

Ses metni, ilerleme değeri, dört durumun ikon seçimi ve başparmak dikdörtgeni ayrıca gerçek `dvbt_board::RefreshVolumeUI` (`0xfb7d18`) yürütmesinden alınır. Bunun servis bağımlılıkları da simüledir; ayrıntılar [`../native-volume-state/states.json`](../native-volume-state/states.json) ve kare JSON'undadır. Ses0'da sessiz ikonun seçilmesi gerçek ses donanımının mute edildiğini kanıtlamaz.

Native çizim fonksiyonları değiştirilmez. Test, izin verilen bütün fonksiyon komutlarının emülatörde özgün ELF baytlarıyla aynı kaldığını denetler. Callback hedefleri çağrı noktalarında `$t9` değiştirilerek tanımlanır; yalnız harici boş-string bağımlılığı için bir GOT hücresi modele bağlanır.

## Kaynak ve yerleşim

- Ses: `OnCreate0xfb9780`, Num `0x5a3e..0x5a79`, renk `0x24/0x25`, resim674/680/681/682/685. Alt öğeler normal kökün değil, panel `+0x1a4` nesnesinin çocuklarıdır; panelin y20 ofseti uygulanır.
- v3 hoparlör alt çizgisi kaldırıldığı için `DrawBorders` maskesi0; orijinalde mask8 ve 1px kalınlık korunur. `ShowBorder0x2e250508`, `OnCreate0xfb9780` çağrısındaki ilk parametre1'i yazar; kalınlığı2 yapan alternatif yalnız OSD'nin hem genişliği1920'den hem yüksekliği1080'den farklıysa geçerlidir. Buradaki yüzey1920×1080'dir.
- Ses fontu: gerçek `DINPro-CondMedium.otf`, Num `0x3215=36`, metin rengi `0x25`, hizalama `0x22`, padding0.
- Sayısal kanal girişi: `OnCreate0x895b84`, Num `0x98f..0x99a`, gerçek `Lucida Sans Bold.ttf`, Num `0x321e=48`, hizalama `0x42`, padding3. Rakamlar test girdisidir; kanal ayarlama/event handler çalıştırılmaz.
- Native sayısal hizalama, Ghidra JSON'unda eksik olan `0x2e24ffa0..0x2e24ffd4` (14 komut) bloğuna gider. Orijinal hash sabitli ELF üzerinde ayrıca disassemble edilerek yalnız bu blok izin listesine eklenir. Komutlar değiştirilmez. `C` çıktısı bu bottom-center dalını zaten gösterir.

## Henüz eşdeğerliği doğrulanmayan kısımlar

`OnCreate`/widget kurucuları yürütülmez; alanları belgelenmiş kaynaklardan hazırlanır. `QueryVisualState` normal durum0, font yönü5, başarılı resim cache'i ve DirectFB alt yüzeyleri model sınırlarıdır. PNG verisini Pillow açar; özgün libpng'nin ayrı decoder deneyi bu kare üretiminin parçası değildir.

Metin bayt döngüsü ve hizalama native koddan gelir. Font rasterizer, `GetHeight` metrikleri, alfa birleştirme ve bilinear ölçekleme host FreeType/Pillow ile sağlanır; gerçek TV piksel eşitliği iddia edilmez. ProgressBar dolgusunun dikdörtgeni native seçilmiş değerden host formülüyle hesaplanır; ProgressBar `Update` gövdesi yürütülmemiştir. Menü, animasyon, donanım ses yönlendirme, yayın ve tam açılış doğrulanmamıştır.

## Tekrar çalıştırma ve test

Depo kökünde, Unicorn+Pillow bulunan Python ile:

```powershell
python scripts/native_frame_rehost.py --variant both --volume 35 --numeric 123
python scripts/native_frame_rehost.py --variant both --volume 0
python scripts/native_frame_rehost.py --variant v3 --volume 35 --mute
python scripts/native_frame_rehost.py --variant v3 --volume 100
python scripts/native_frame_rehost.py --variant v4 --volume 35 --numeric 123
python -m unittest discover -s scripts -p test_native_frame_rehost.py -v
```

Son kontrol: **10/10 geçti**. Native kod/gerçek çizim çağrıları, değişmeyen komut baytları, panel ebeveynliği ve v3 border değişikliği, gerçek Refresh ikon seçimi, beklenen kaynak pikselleri, sayısal native hizalama, watchdog ve hash ret davranışı kontrol edildi. Ek v4 kontrolleri sekiz gerçek yerel font/renk argümanını, koyu metin piksellerini, büyüyen native ikon çizimini, `100` metninin76px alana sığmasını ve değiştirilmiş ikon hash'inin reddini kapsar. Bunlar cihaz kabul testi değildir.

## Kesinti sonrası kaynak kurtarma

Devam başında `scripts/native_frame_rehost.py` dosyasının23838baytının tamamı sıfırdı. Dosya, bu renderer'ı oluşturan iki yerel ajan oturumundaki başarılı `apply_patch` girdileri yeniden uygulanarak kurtarıldı; başarısız71numaralı patch uygulanmadı. Önce mevcut8test geçti, ardından v4 desteği eklendi. [Kurtarma kaydı](source-recovery.json) yalnız patch kimlikleri/hashleri ve kurtarılan kaynak hash'ini içerir; oturumların tamamı kopyalanmadı. Orijinal firmware dosyaları bu işlemde okunmadı veya değiştirilmedi.
