# HomePageFrame oluşturma gövdesi

23 Ekim 2026. İncelenen `dvbt_board` SHA-256: `51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916`. Firmware ve TV değiştirilmedi; hedef program çalıştırılmadı. Bulgular doğrudan Ghidra ve ham ELF/MIPS statik incelemesidir; REA Evidence kaydı değildir.

## Kapsam ve çıktı durumu

Giriş `0x00d42150`, FDE sonu exclusive `0x00d58d68`, aralık **93.208 bayt**. Önceki analiz gövdesi 81.640 bayttı. FDE ile sınırlanan yeni sorgu **23.302/23.302 instruction slotunu** içeriyor; **eksik instruction baytı 0**. 2.202 computed callsite, ham indekste 2.102 isimli hedef adayı ve **100 belirsiz hedef** var. Bunlar runtime çağrı bağlanmaları değildir.

**Standart decompile C çıktısı tamamlandı: 1/1.** [C-only/600 saniye sorgusu](../../analiz/native/ui-four/home/conly600/summary.json), yaklaşık 492 saniyede 257.616 bayt / 5.671 satır [tam C gövdesi](../../analiz/native/ui-four/home/conly600/00d42150.c) üretti. C SHA-256 `17029677e68bc0203902a4bee9d6aee60bf9b22acd632e0b36ddcc6925d35971`.

Öncesindeki `bounded300` denemesi, açık FDE sınırı + t9=entry + standart abort/throw noreturn varsayımları + 256 MB payload ile **300 saniyede timeout** oldu; C sayısı 0/1 idi. İki denemenin instruction adres/metin envanteri aynıdır. `HomePageFrame::LayoutItems 0xd29500` yeniden çalıştırılmadı.

C-only sorguda syntax tree istenmediğinden **pcode containment kontrolü kullanılamıyor**. Orijinal sorgu JSON'unda `high_function_present:true` ve `decompiler_pcode_within_selected_body:true` yazması boş/prototype HighFunction nesnesinin yan etkisidir; `syntax_tree_requested:false` ve `pcode_export_complete:false` esas alınır. Orijinal JSON geriye dönük değiştirilmedi; [ayrı doğrulama kaydı](../../analiz/native/ui-four/home/home-validation.json) bu sınırı açıkça kaydeder. Kontrol edilen 1.103 C label/try-range adresi FDE içinde kaldı; bu pcode kontrolünün yerine geçmez.

Ana kanıt dosyaları:

- [Tam C sorgusunun instruction kaydı](../../analiz/native/ui-four/home/conly600/00d42150.json), [bağlam ve noreturn değişiklikleri](../../analiz/native/ui-four/home/conly600/selection-and-context.json). Önceki timeout için [300 saniye sorgusu](../../analiz/native/ui-four/home/bounded300/summary.json) ayrı korunur.
- [Ölçüm ve bütün kaynak çağrıları](../../analiz/native/ui-four/home/home-create-analysis.json): 784 Num, 61 Color, 240 `MImg::Set`, 136 `MImg` constructor = **1.221 kaynak çağrısı; belirsiz ID 0**. Ayrı 39 `MString::Set` vardır. Benzersiz ID sayıları: Num 273, Color 5, Image 49.
- [60 widget'ın parent, alan, rect, görüntü, renk ve metin haritası](../../analiz/native/ui-four/home/home-widget-map.json), [tekrarlanabilir assembly aday izi](../../analiz/native/ui-four/home/home-widget-trace.json), [görünürlük/yardım son bölüm assembly'si](../../analiz/native/ui-four/home/home-tail.asm).

## Widget ağacı ve kaynaklar

60 oluşturma noktası: **19 AbsContainer, 18 ImageButton, 16 TextBox, 4 ScrollListContainer, 3 Button**. Her biri ayrı `this+0x180 … this+0x26c` pointer alanına bağlanır. Tam C'deki **60/60 constructor sınıfı, beş argüman varlığı, son iki argüman ve alan yazımı** assembly aday iziyle eşleşti; uyuşmazlık 0. JSON'daki ayrıntılı parent/rect izleri basit register ve stack transferleriyle çıkarılan, adresli assembly ile denetlenebilir adaylardır; CFG birleştirmelerini modelleyen bir yürütme değildir.

İlk örnek assembly ile ayrıca kontrol edildi: `0xd42198/1b0/1c8/1e0` çağrıları Num ID `13429,13430,13428,13427` getirir; `0xd42208` bunları `_Rect::set(x,y,w,h)` argümanları olarak alır. `0xd42250` AbsContainer constructor'ına parent=`*(this+0x38)` geçirir; `0xd42264` nesneyi `this+0x180` alanına yazar. `this+0x38` için ilave framework alan adı varsayılmadı.

Başlıca ağaç, ilk yerel koordinatlarla:

| Alan / son constructor argümanı | Tür ve parent | rc profilindeki ilk rect / içerik | Constructor VA |
|---|---|---|---|
| `+0x180 / 0` | AbsContainer, `*(this+0x38)` | `(0,0,1920,504)`; image 991 `Grundig/half/bg/bg.homescreen.bg.png` | `0xd42250` |
| `+0x184 / 1` | AbsContainer, `*(this+0x38)` | `(0,0,1920,529)` | `0xd425dc` |
| `+0x190 / 4` | ScrollListContainer, `+0x180` | `(57,284,1850,210)`; ImageButton 12–20 | `0xd42fb0` |
| `+0x194 / 5` | AbsContainer, `+0x180` | `(1161,260,600,230)`; Ekran Paylaşımı alt ağacı | `0xd43bc4` |
| `+0x198 / 6` | AbsContainer, `+0x180` | `(210,260,1500,230)`; Ayarlar alt ağacı | `0xd43f08` |
| `+0x1a0 / 8` | TextBox, `+0x180` | `(70,10,128,36)`; string 2826 “TV” | `0xd44710` |
| `+0x1a4 / 9` | TextBox, `+0x180` | `(1445,10,128,36)`; string 2942 “APP” | `0xd44bb8` |
| `+0x1a8 / 10` | TextBox, `+0x180` | `(1670,10,128,36)`; string 3010 “WEB” | `0xd45060` |
| `+0x1ac / 11` | ScrollListContainer, `+0x180` | `(57,30,1850,232)` | `0xd45508` |
| `+0x1e0 / 24` | ScrollListContainer, `+0x194` | `(20,32,580,200)`; ImageButton 26–27 | `0xd4a87c` |
| `+0x1fc / 31` | ScrollListContainer, `+0x198` | `(20,32,1414,200)`; ImageButton 33–39 | `0xd4d194` |
| `+0x220 / 40` | AbsContainer, `+0x184` | Kişiselleştir başlığı; `(1436,254,420,50)` | `0xd512d8` |
| `+0x224 / 41` | AbsContainer, `+0x184` | İzle & Dinle başlığı; `(64,254,1316,50)` | `0xd51620` |
| `+0x228 / 42` | AbsContainer, `+0x184` | Bağlan / son izlenen başlığı; `(988,0,868,50)` | `0xd51968` |
| `+0x22c / 43` | AbsContainer, `+0x184` | Son izlenen & favoriler başlığı; `(64,0,868,50)` | `0xd51cb0` |
| `+0x230 / 44` | AbsContainer, `+0x184` | Kanal ayarı yok paneli; `(64,65,868,146)` | `0xd51ff8` |
| `+0x234 / 45` | AbsContainer, `+0x184` | Bağlantı ayarı yok paneli; `(988,65,868,146)` | `0xd52364` |
| `+0x260 / 56` | AbsContainer, `+0x184` | İkinci kanal arama paneli; `(988,65,868,146)` | `0xd55828` |

Son constructor argümanının ID rolü AbsContainer → Container → MWidget zincirinde ayrıca ham ELF ile doğrulandı: `0x2e21791c/92c` ve `0x2e21a728/738` son stack argümanını aktarır; `MWidget` `0x2e258914` ile argümanı alıp `0x2e258acc` ile `this+0x1a8` alanına yazar. `MWidget::GetID 0x2e24d420/424` aynı alanı döndürür. Destek instruction word'leri ve `libmuf.so` hash'i widget-map JSON'undadır. Diğer alt sınıfların forwarding zincirleri burada tek tek doğrulanmadığı için JSON alanı `id_candidate_last_argument` adıyla korunur. Oluşturma argümanları 0–57,59,60; **58 atlanır**. Daha sonraki yardım kayıtlarının 61+ değerleri bu 60 oluşturmayla karıştırılmamalıdır.

18 ImageButton foreground setter'ı, settings/mediaPlayer/recording/dlna/channelEditor/timer/screen-share/browser/interactive, Miracast/WiDi ve video/sound/source-setup/lock/schedule/WiFi/settings ikonlarına bağlanır. Örneğin `+0x1b0` ID adayı 12, constructor `0xd4610c`, `ImageButton::SetImg 0xd46564` dört argümanıyla `[972,972,971,971]` kullanır; 972/971 tablo yolları `l2.icon.settings.focus.png` / `l2.icon.settings.png`'dir. Parametre sırası doğrudan assembly stack adreslerinden çıkarılır; dosyadaki “focus” adı tek başına API slotunun semantiği olarak sunulmaz.

240 background ataması widget başına `+0xb8,+0xcc,+0xe0,+0xf4` dört `MImg` alanındadır. Bütün profile bağlı path ve renk değerleri JSON'da saklıdır; `---` tablo sentinel'ı gerçek dosya sayılmaz. Color ID'leri 49=`0xff9e9e9e`, 56=`0xffc6c6c6`, 69=`0xffffffff`, 84=`0xff909090`, 94=`0xfff5f5f5` (rc tablosu). Argb yorumu önceki MUF DrawBackground incelemesiyle sınırlıdır. İlk rect'ler sonraki `LayoutItems` ve diğer rect güncellemeleriyle değişebilir; cihazın aktif yüzeyi/piksel ölçüsü değillerdir.

## Olay, görünürlük, focus ve yardım kararları

Mevcut Home message-map kaydı `0x010be5e4`: event `1`, handler `0x00d42150`, member adjustment 0; getter `0xd25bf0` map `0x10be5dc` döndürür. Event-1 OnCreate yorumu MUF'taki isimli lifecycle map'i ile desteklidir. Bu gövde içinde ayrıca yeni isimli callback kaydı bulunmadı; 100 dolaylı hedef açık olduğu için “hiç callback yok” sonucu çıkarılmaz. [Mevcut map'in dar kopyası](../../analiz/native/ui-four/home/home-message-map-existing.json) yeniden analiz yapılmadan korunur.

- **USB:** getter `0xd56a1c` sonucu sıfırsa `0xd56a30` dalı fall-through olur; `+0x1b4` (mediaPlayer), `+0x1bc` (dlna), `+0x1b8` (recording) için flag 1/2 sıfırlanır ve Hide çağrılır (`0xd56a90`, `0xd56af4`, `0xd56b58`). Sonra `ArTvConf_GetUsbRecording 0xd56b7c` sıfırsa recording yine gizlenir (`0xd56bf0`). Flag'lere burada ilave enabled/visible adları verilmez.
- **Başlangıç focus:** `0xd579a8` LayoutItems; `0xd579c8` `HandleFocus(this,0xf002,1,0x3d)`; `0xd579e4` başlangıçta `this+0x270 = *(this+0x1b0)` yazar. Bu kurulum verisidir; cihazda gözlenen focus/tuş olayı değildir.
- **Kayıt kontrolü:** `ControlAllRecordProcess 0xd57a10` sonucu **1 ise**, `0xd57a28` fall-through dalı `this+0x20c` widget'ını Hide eder (`0xd57a40`). Getter adından boolean semantik uydurulmadı.
- **NonConnected/Basic Mode:** `ArTvConf_GetNonConnectedEnabled 0xd57aac` sonucu **1 ise** `+0x228` Show (`0xd57adc`) yoluna girer. `ArTvConf_GetBasicMode 0xd57b00` ve `GetBasicMode 0xd57b34` sonuçlarının ikisinin de **1** olması ayrı dal oluşturur. Sonraki rect/başlık değişiklikleri ilgili assembly'de korunur; bütün cihaz ayarlarının aktif değerleri bilinmiyor.
- **Netflix:** `ArNetworkConf_GetNetFlixVisible 0xd58670` sonucu **1 ise** `this+0x10c` yardım vektörüne `(0x44,0x109f)` (`0xd586b8`); diğer değerlerde `(0x44,0x10a1)` (`0xd586f4`) eklenir. Bu doğrudan Netflix widget'ına Hide/Show çağrısı değildir.
- **Hotel:** `ArSystemConf_GetHotel 0xd58954 != 0` ve `GetHotelAdmin 0xd58980 == 0` birlikteyse `0xd589ac` sonrası `+0x26c` ve `+0x250` text alanlarına Color ID 84 yazıp invalidate eder. Basic Mode / NonConnected sonrası `0xd58bbc` ayrıca Hotel==0 koşulunda `(61,4263),(62,4263),(63,4263)` yardım kayıtlarını ekler.
- **Yardım:** 19 statik `vector<bubblehelppair>::push_back` çağrı noktası vardır; koşullu alternatifleri içerir, runtime'da 19 kayıt garantisi değildir. Pair alanları ve ikinci alanın Turkish/English string-ID adayları widget-map JSON'undadır. HelpWidget HideAllButtons/ShowButton/Refresh çağrıları da ham çağrı kaydındadır.
- **Animasyon:** Bu gövdede isimle çözülen çağrılar arasında `StartAnimation`, `ShowWithSwipe`, `CloseWithSwipe` ve AddTimer yoktur. Dolaylı çağrılar yüzünden bu sınırlı negatif bulgu tüm Home davranışına genellenmez.

## Tekrar üretme ve sınırlar

`scripts/analyze_home_create.py` tam instruction kapsamını ve kaynak ID adaylarını ölçer. `scripts/analyze_home_widget_trace.py` register/stack transferlerini dar biçimde izler. `scripts/analyze_home_widget_map.py` mevcut profil tabloları ve ham `libmuf` instruction word'leriyle birleştirir. `scripts/analyze_home_validation.py` hedef hash'ini, iki sorgunun instruction eşitliğini, 60 constructor/alan/argüman eşleşmesini ve C kontrol-akışı adreslerini doğruladı; tüm kontroller geçti. Dört script için `py_compile` geçti. Çıktılar yalnız `analiz/native/ui-four/home/` altına yazılır.

Girişte `a0` `0xd42178` ile saklanıp nesne alanlarında kullanılır. `a1/a2/a3` saklanır; ilk instruction envanterinde bu üç stack alanından yeniden yükleme görülmez. C girişi `undefined4 FUN_00d42150(HomePageFrame *param_1)` oldu; bu a0 nesne kullanımı ve normal çıkıştaki `0xd58d10` v0=0 ile uyumludur. Event framework'ünün bütün parametreleri yeniden kurulmuş sayılmaz. Ghidra'nın ham function metadata'sındaki eski `undefined(void)` imzası güvenilir API sözleşmesi değildir.

**C çağrı prototipleri kusursuz değildir:** `MImg::Set` ve `MString::Set` bazı satırlarda numeric resource argümanını düşürür. `ImageButton::SetImg` C'si yanlış this çıkarımıyla yalnız üç görüntü referansı gösterir; assembly gerçek `a0=widget`, `a1/a2/a3` ve `stack+0x10` üzerinden **dört** görüntü referansı geçirir (`0xd46544–0xd46564` örneği). Kaynak ID'leri ve kritik argüman sayıları C metninden değil, yukarıdaki O32 assembly kaydından alınır. FDE exception kuyruğunu da kapsar; orijinal kaynak kodu veya bütün dinamik davranışlar geri kazanılmış sayılmaz.

Aktif profil, dil, Hotel/Basic Mode, kaynak ve servis yanıtları, render sonucu ve fiziksel TV uyumu bilinmiyor. Tam C başarı durumu, instruction kapsamı ve semantik haritanın kapsamı ayrı sayılmalıdır.
