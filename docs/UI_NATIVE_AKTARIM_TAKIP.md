# Native UI aktarımının kalan kod yolları

Sonraki kök uygulama: [v3 adayı](UI_NATIVE_ADAY_V3.md) bu rapordaki9Num/8yerel renk önerisini uyguladı; ayrıca PNG decoder testiyle kapsül ilerletildi. Aşağıdaki “uygulanmadı/çalıştırılmadı” ifadeleri bu statik alt ajan incelemesinin kapsamıdır; güncel emülasyon sonucu ayrı v3 raporundadır.

24 Ekim 2026. Bu çalışma yeni firmware üretimi değil, v2 adayından sonraki aktarım için adresli statik incelemedir. Özgün dosya, v2 adayı, uygulama ve TV değiştirilmedi/çalıştırılmadı. Birincil beceri `reverse-engineer-anything`; önceki Ghidra C/assembly ve ham MIPS indeksleri yeniden kullanıldı, büyük fonksiyonlar tekrar decompile edilmedi. Bu çıktılar REA Evidence veya TV gözlemi değildir.

Hedef `08_APP/bin/dvbt_board`, SHA-256 `51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916`. Girdi dosyalarının SHA kayıtları ve sayaçlar [audit-summary.json](../analiz/native-ui-port-v3/audit-summary.json) içindedir.

## Ölçülen kapsam

| İncelenen parça | Bu aşamanın gerçek çıktısı | Sınır |
|---|---|---|
| Home OnCreate `0xd42150` | Mevcut 60 widget haritası tekrar kullanıldı; yüzey/Image/Num/Color bağı ayrıldı | İlk yerel rect, son ekran rect'i değildir |
| Home LayoutItems `0xd29500` | 2.107 çağrı adayı, 480 Color çağrısı; 21 dinamik TextImageMixer oluşturma noktası, 420 doğrudan renk alanı yazımı | Döngüde bir oluşturma noktası birden çok runtime nesne oluşturabilir |
| ChannelControl OnCreate `0x895b84` | 91 çağrı adayı, 3/3 widget; 12 geometri ID'sinin literal tüketicileri | Gerçek ekran, cihaz profili ve hesaplanmış ID tüketicileri bilinmiyor |
| ArChannelList OnCreate `0x7995b0` | 2.564 çağrı adayı; 77 rect'li widget adayı | HelpWidget farklı constructor ABI'si nedeniyle rect izine eklenmedi |
| ArProgramInfo OnCreate `0x7de53c` | 2.422 çağrı adayı; 80 rect'li widget adayı | HelpWidget/TimeWidget farklı ABI; yenileme yolları ilk geometriyi değiştirebilir |
| Yeni decompile / TV veya firmware uygulama testi | **0 / 0** | Statik izleme çalıştırma değildir |

Kanal ve numara yollarında yeni **160 widget adayı**, Home'da yeniden kullanılan 60 widget ve LayoutItems'da 21 oluşturma noktası ayrı sayılır. İzleyici basit register/stack transferlerini takip eder; CFG birleşimlerini veya koşul uygulanabilirliğini modellemez. Bu nedenle ilişki dosyaları koşulsuz çalışma garantisi değildir.

## 1. Home: beyaz yüzey için ikon değiştirmek yetmez

Ana arka plan Image **991**, dosya `rc/ARimages/Grundig/half/bg/bg.homescreen.bg.png`, **1×501 RGBA** dikey şerittir. 1920×504 tam ekran resim değildir. OnCreate içinde `this+0x180`, `+0x194`, `+0x198` aynı dosyayı kullanır. Alt menü/ekran paylaşımı yüzeyleri de değişiklikten etkilenir. İlgili MImg çağrıları ve dosya hash'leri [home-surfaces.json](../analiz/native-ui-port-v3/home-surfaces.json) içindedir.

Üst kartların background Image 946/947'si 110×110 paletli PNG; alt kartlardaki Image 948 ise 102×102 RGBA'dır. **1485/0x5cd = `---`** sentinel'ıdır; PNG oluşturulmaz. V2'deki açık normal ikonlar koyu yüzeye göre üretildi; beyaz Home'a geçerken aynı ikonların normal rengi tekrar koyulaştırılmalıdır.

| İlk widget | Num ID (h/w/x/y) | Özgün değer | Giriş/rect kanıtı |
|---|---|---|---|
| Home root `+0x180` | 13427 /13428 /13429 /13430 | 1920×504, x0/y0 | constructor `0xd42250`, rect `0xd42208` |
| İkinci root `+0x184` | 13367 /13368 /13369 /13370 | 1920×529, x0/y0 | constructor `0xd425dc` |
| Üst raf `+0x1ac` | 13575 /13576 /13577 /13578 | `(57,30,1850,232)` | constructor `0xd45508` |
| Alt raf `+0x190` | 13579 /13580 /13581 /13582 | `(57,284,1850,210)` | constructor `0xd42fb0` |

Bu dört yükseklik ID'sinin ana ELF indeksinde birer literal tüketicisi var. Buna rağmen tek başına root 504'ü azaltmak tutarlı küçültme değildir: ikinci root529, alt raf sonu494 ve LayoutItems'ın doğrudan sayısal rect'leri de hesaba katılmalıdır. Güncel Chrome CSS de 504px kullanıyor; eski yüzde10–15 talebini tekrar sayısal küçültme olarak rastgele uygulamak mevcut onaylı görünümle eşlik sağlamaz.

### Yerel renk değişikliği için bulunan sınır

LayoutItems'ın 21 TextImageMixer oluşturma noktasında her nesneye 20 renk alanı yazılıyor. **84** beyaz `Color94=0xfff5f5f5` çağrısı, bu nesnelerin `+0x7c/+0x80/+0x84/+0x88` alanlarına bağlandı. Aynı fonksiyonda üç TextContentConfig şablon grubuna yazılan **12** ilave beyaz renk çağrısı var. [96 adayın instruction VA/old word ve önerilen yerel değişiklikleri](../analiz/native-ui-port-v3/home-layout/local-text-color-review.json) yalnız inceleme içindir; uygulanmadı. Global Color tablosuna değişiklik önerilmez.

**84 dış widget rengi tek başına bütün metni düzeltmez.** Her TextImageMixer'a ayrıca `SetTextAmount`, `SetTextContent(TextContentConfig const*)`, `SetImageContent`, `SetLayOut` ile içerik veriliyor. Örneğin `0xd39bf8` constructor'ı sonrası `auStack_9cc` içerik konfigürasyonu aktarılır. Gerçek alt metin renkleri bu konfigürasyondan gelebilir. Asgari kalan inceleme: MUF `TextImageMixer::SetTextContent 0x2e285b38`, `UpdateCompositeData 0x2e2853c0`, konfigürasyonun alan kopyaları ve daha sonraki EPG/kanal içerik yenilemeleri. Focus/Hotel/BasicMode/NonConnected yolları da korunmalı. Bu yollar kapanmadan beyaz Home'u tutarlı tamamlanmış aktarım saymak doğru değildir.

## 2. Numara girişi: küçük ve somut aktarım fırsatı

Sınıf gerçek sembollerde **ChannelControlFrame** olarak geçer; `NumericEntryFrame` bu raporda sembol gibi kullanılmaz. Oluşturma `0x895b84` yalnız üç widget üretir:

| Alan | Tür | Num ID (x/y/w/h) | Gerçek ilk rect |
|---|---|---|---|
| `this+0x180` | Root AbsContainer | `991/992/990/98f` hex | `(0,0,1920,80)` |
| `this+0x184` | Background AbsContainer | `995/996/994/993` hex | `(0,0,1920,80)` |
| `this+0x188` | TextBox | `999/99a/998/997` hex | `(860,5,200,70)` |

Önceki özetlerdeki 200×70 bütün root değil, **yalnız numara metninin alanıdır**. Background tüm1920px genişlikte80px yüksekliktedir. Her ID'nin dosya ofseti `56+4*ID`; özgün Num SHA `e20c03cd212f548eb8154e8e49d6cf4daafc5fd5842887c51590bf76cfe613ff`. On iki ID'nin her biri ana ELF indeksinde yalnız `0x895b84` içinde birer literal tüketiciye bağlanır. Dolaylı ID kullanımı bundan çıkarılarak reddedilemez.

**Sınırlandırılmış uygulanabilir alt küme:** [9 Num değişiklik önerisi](../analiz/native-ui-port-v3/numeric/compact-layout-proposal.json) root'u `(0,0,1920,176)`, background'u `(1538,64,310,112)`, metni `(1566,84,254,72)` yapar. Sağ boşluk72px; metin ve panel root içinde kalır. Bu kompakt, yalnız numaralı yerleşimdir; onaylı tarayıcıdaki310×224 eşleşme kartının tamamı diye sunulmaz.

Renkler global tabloyu değiştirmeden **8 sabit çağrı argümanı** ile yerelleştirilebilir:

- Background Color18 `0xe5161528` → Color94 `0xfff5f5f5`: instruction `0x896100/120/140/160`, `0x24040012 → 0x2404005e`.
- Dört metin durumu Color94 → Color0 `0xff212121`: instruction `0x896548/568/588/5a8`, `0x2404005e → 0x24040000`.

[Tam eski/yeni bayt ve çağrı adresleri](../analiz/native-ui-port-v3/numeric/local-color-proposal.json). Bu denetim bunları uygulamadı; ana entegrasyon exact bytes/hash/allowlist kontrolüyle ayrı aday üretebilir. Font Num `0x321e=48` **55 çağrı/12 fonksiyonda** kullanılır; fontu büyütmek için global ID değiştirilmez.

Tarayıcı kartındaki kanal adı, eşleşme/açıklama ve görsel geri sayım için burada widget yok. Bunları Num veya PNG'ye basmak canlı işlev oluşturmaz. Yeni native widget/kanal sorgusu/timer repaint entegrasyonu gerekir. `TenKeyHandle 0x89552c` ilk üç basamakta3000ms, dördüncüde2000ms timer kurar; `ChangeChannel 0x895b24` `ArChannelManager::SelectChannelByNumber(...,1)` çağrısını kullanır. Yeni görünüm bu davranış yollarını korumalıdır.

## 3. Kanal listesi ve bilgi bandı

[Kanal listesi 77 widget/parent/Num/Color adayı](../analiz/native-ui-port-v3/channel-list/widget-bindings.json), [bilgi bandı 80 aday](../analiz/native-ui-port-v3/program-info/widget-bindings.json). Her kayıtta constructor/rect/alan-yazım VA'sı bulunur; ham çağrılar aynı dizinlerdedir.

Kanal listesi `0x7995b0` ilk alanları: `+0x180=(0,0,1920,80)`, `+0x184=(100,160,1720,770)`, `+0x188=(0,640,1920,360)`; alt yardım grupları `+0x198=(0,920,1920,80)` ve `+0x19c=(0,921,1920,80)`. Bunlar tek bir680px liste rectangle'ı değildir; liste/sağ detay/widget alt ağacı ayrıca dikkate alınmalıdır. OnCreate'ı tek panel gibi boyamak seçim satırı ve detay kontrastını garanti etmez. `ArChannelListFrame::FilterTypeToStringID 0x774c8c` ve kontrol `0x79464c` yolları işlev açısından korunmalıdır.

Program bilgi `0x7de53c`: root `+0x180=(0,0,1920,1080)`; `+0x188=(0,0,1920,250)`; geniş bilgi `+0x18c=(0,250,1920,355)`; `+0x190=(0,550,1920,40)`, `+0x194=(0,600,1920,60)`. Bunlar parent-local ilk koordinatlardır; root'u alt bant yüksekliğine düşürmek kalan çocukları kırpabilir. `ArProgramInfoFrame::RefreshUI 0x7d4cac` dinamik içerik ve `0x7dc104` olay yolu ile birlikte incelenmelidir. Tarayıcıdaki alt250px kartın gerçek native konumu bu değerlerden tek başına kanıtlanamaz.

## 4. Animasyon ve diğer sayfalar

`GetAnimationEnabled 0x555ed4` sabit0'dır. General callback `0xd01400`, Sound `0xee97b4` ve Source `0xd9e11c` seçilmiş geçişleri bu kapıdan geçirir. MUF `StartAnimation 0x2e259b4c` 50ms timer kullanır; `SetDuration 0x2e22bae8` 50ms katına yuvarlar. Tarayıcı100/150ms geçişlerini global gate'i1yaparak birebir aktarmak kanıtlanmış çözüm değildir. Diğer ekranlar ve tekrarlı kumanda olayları etkilenebilir. Yeni native easing/timer yardımcı kodu olay ve yaşam döngüsü sözleşmesine bağlanmadan aktif sayılmaz.

Ayarlar/kaynak/medya/PVR/arama/lisans gibi ekranların işlevleri özgün native uygulamada zaten var; Chrome durum makinesini firmware'e taşımak yerine mevcut native servis bağlarını korumak gerekir. Bu ekranların bütün modern yüzeyleri v2'ye aktarılmış değildir. Beş kritik grup açık: Home; numara/eşleşme kartı; kanal listesi+bilgi; diğer ekranların stilleri; animasyon/event entegrasyonu. Bunların tamamı kapanmadan “Chrome ile eksiksiz aynı” veya “nihai sorunsuz firmware” durumu verilmez.

Ses panelinin clipping/stretch ve özgün MImg çizim yollarını ana ajan ayrı inceler; bu denetim o çalışmayı tekrar etmedi.

## Doğrulama ve tekrar kullanım

Yeni JSON'lar parse edilerek sayılar kontrol edildi: numara3, kanal listesi77, bilgi80; 12 Num tüketicisi tek fonksiyonda; paylaşılan font55/12; HomeLayout96 beyaz çağrı=84 doğrudan alan+12 konfigürasyon adayı. Sekiz numara renk önerisinin kaynak instruction word'leri doğrudan özgün ELF'ten kontrol edildi. Yerleşim önerisinin parent sınırları aritmetik olarak kontrol edildi; çizim/TV testi değildir.

Kalanlar yalnız rapor üretilmiş diye kapanmış sayılmaz. Ana entegrasyonun uygulayacağı her değişiklik yeni immutable manifest, ELF/dosya allowlist ve yeniden açılmış APP/paket doğrulaması gerektirir. Kullanıcı emulator istiyor diye WSL'nin MStar donanımını veya tuner/CEC/video hattını emüle ettiği varsayılmaz.
