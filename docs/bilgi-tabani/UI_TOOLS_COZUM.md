# Tools menüsü: büyük create gövdesi

23 Ekim 2026. `dvbt_board` SHA-256 `51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916`; fonksiyon `0xf60a64`, FDE sonu `0xf86234`.

Önceki response-buffer hatası 256 MB payload ile aşıldı. [Tam C](../../analiz/native/ui-four/tools/full256-360s/00f60a64.c), [instruction/pcode](../../analiz/native/ui-four/tools/full256-360s/00f60a64.json), [kapsam ve ilişkiler](../../analiz/native/ui-four/tools/tools-create-analysis.json). Metadata izole Ghidra kopyasında salt okunur sorgulandı; orijinal firmware çalıştırılmadı/değiştirilmedi. Bu doğrudan Ghidra çıktısıdır, REA Evidence değildir.

## Kapsam

- 1/1 tamamlanmış C, 374.378 bayt. FDE **153.552 bayt / 38.388 instruction**: eksik aligned word yok.
- 3.425 decompiler callsite; pcode export tamam, gövde dışı pcode adresi yok.
- Bağımsız ham indekste 4.055 callsite adayı: 3.963 symbolic GOT, 92 çözülemeyen dolaylı hedef. Pcode ve raw sayıları aynı kapsam metriği değildir; exception/destructor dalları farklılaşabilir.
- İçe aktarılmayan ve iki kayıtta da sabit hedefi olan **125 callsite adresi** karşılaştırıldı: uyuşmazlık yok. Runtime import bağlaması doğrulanmadı.
- 85 widget constructor / 85 C-derived field bağlantısı: 3 AbsContainer, 18 Image, 10 ScrollListContainer, 5 TextBox, 48 ImageButton, 1 HelpWidget.

## Widget ağacı ve geometri

`this+0x180` kök AbsContainer, parent `this+0x38`; `this+0x184` ve `this+0x1a8` onun alt container'larıdır. `0xf60b64` ilk constructor çağrısıdır. İlk root rect kaynakları Num `0x5692/0x5693/0x5691/0x5690`: mevcut tabloda **(0,0,1922,332)**. Bunlar mantıksal koordinatlardır; fiziksel panel ölçüsü veya düzeltilmesi gereken hata diye yorumlanmadı.

`this+0x1e4` ScrollListContainer'ın ctor son argümanı `0x19`; `this+0x1ec` Image bu container altında, son argüman `0x1b`; `this+0x200` Image son argümanı `0x20`. `this+0x294` ImageButton, `this+0x1a8` parent'ında, son argüman `0x45`. Field/constructor argümanları [JSON listesinde](../../analiz/native/ui-four/tools/tools-create-analysis.json); tüm mantıksal kontrol adları henüz atanmış değildir. C'deki pointer/prototip gösterimleri assembly karşısında kontrol edilmelidir.

## İlk odak ve menü modları

Create sonunda `MApplet::GetPrivateData` sonucu `this+0x2e0` alanına alınır. İlk değer 4 ise yerel bir bool saklanır ve alan 0 yapılır. Açık DMP player nesneleri, 3D modu ve diğer kaynak koşulları menü durumunu değiştirebilir; bu modların tamamına ürün adı verilmedi.

`0xf853c0` SetInitialFocus çağrısının gerçek **a1** girdisi `this+0x1e4`'tür. C bu argümanı düşürür. Özel bool dalında `0xf853f0` SwitchFocusTo gerçek **a1=this+0x200**; diğer dalda `0xf85500` **a1=this+0x1ec**. Assembly `0xf853dc–0xf853e8` ve `0xf854ec–0xf854f8` bunu kanıtlar. Mevcut seçim alanları `+0x2d4/+0x2d8` buna göre yazılır. Bu nedenle layout değişirken yalnız PNG konumlarını takip etmek yeterli değildir.

3D, DualWatch, CEC konfigürasyonu, geçerli kaynak ve panel parametresi yolları bazı widget'larda flag 2 veya flag 1 temizleyip invalidate yapar. Sayısal flag'lere bu gövdeden tek başına disabled/visible adı verilmedi. Kontrol noktaları `GetDualWatchStatus` callsite'ları `f84994/f84b94/f84d70/f84e10/f8500c`; `IsTvIn4kMode` `f85038`; `Get3DDisplayMode` `f85064`. SleepTimer sorgusu `f85544` ve scroll-container sanal `+0x40` kullanımı korunmalıdır.

HelpWidget `this+0x2d0` alanına yazılır. ShowButton çiftleri `(0xe,0xd41)`, `(6,0x10c6)`, `(7,0xf37)` callsite'ları `f8608c/f860b0/f860d4`; gerçek kumanda tuşu adı ek kanıt olmadan atanmadı. Create normal dönüşü sayısal 0'dır; null widget durumları assert/abort yolundadır.

## Event ve açık noktalar

ToolsMenuFrame message map `0x10c34cc`, **18 kayıt**: event 1 → `f60a64` create, event `0x14` → `f86234` key handler; event `0x16` selector aralıkları ayrı callback'lere gider. Raw selector alanları JSON'da korunur; hepsine click veya aynı kontrol adı verilmez.

92 ham dolaylı hedef, gerçek runtime profil, tüm selector/flag adları ve varsayılan widget typedef'leri açık kalır. Tam C olması bu noktaları çözülmüş yapmaz. Tasarımda bu create ağacı ve mevcut callback sınırları korunarak menü görselleri, renkleri ve geometri için değişiklik planı hazırlanabilir; firmware paketine uygulama ayrı aşamadır.

Ek MUF sözleşme kontrolü: [SetFlag enum gövdesi `2e24dd98`](../../analiz/native/ui-targeted/ui-four-widget-flags2/2e24dd98.c) yalnız `1,2,4,8,16,32` maskelerini kabul eder; diğer girdiler assert/abort. Bool sıfırsa `widget+0x1a4` byte alanında maskeyi temizler, diğer durumda ekler. [QueryFlag `2e24d3d4`](../../analiz/native/ui-targeted/ui-four-widget-flags2/2e24d3d4.c) `(flags & mask)==mask` karşılaştırmasıdır. Dolayısıyla Tools içindeki `2` bir bit sıra numarası değildir; bit maskesidir. Focus için `4` önceki SetFocus koduyla doğrulanmıştır; `1/2/8` için ürün adı tahmin edilmez.
