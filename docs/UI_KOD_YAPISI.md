# UI kod yapısı ve davranış kanıtları

22 Ekim 2026. Bu belge UI araştırmasının genişletilmiş aşamasıdır. Kaynak firmware değiştirilmedi. Statik kod, kaynak tablosu ve çalışma zamanı gözlemi farklı kanıt türleridir; cihaz gözlemi yoktur.

## Ölçülen kapsam

| İnceleme | Kapsam | Kanıt |
|---|---:|---|
| Ham ELF sembol karşılaştırması | 226 ELF / 125.246 satır / 0 uyuşmazlık | `analiz/elf-envanter-v2-dogrulama.json` |
| UI sınıf adı adayları | 285 | `analiz/ui-yapi-haritasi.json` |
| Tanımlı RTTI / vtable kayıtları | 187 / 244 | aynı dosya; raw ELF adresleri |
| Sabit message-map adayları | 236; APP içinde 158 | aynı dosya |
| Event kaydı / benzersiz handler adayı | 1.250 / 1.126 | aynı dosya |
| Ana uygulama instruction çağrı noktaları | 279.689 | `analiz/ui-kod-cagrilari.json` |
| MUF instruction çağrı noktaları | 8.070 | `analiz/ui-muf-kod-cagrilari.json` |
| Odaklı native giriş / tamamlanmış C | 136 / 132 | `analiz/native/ui-targeted/`, `analiz/native/ui-deep/` |
| UI normal dosyaları / profil / font | 2.357 / 31 / 16 | `analiz/ui-asset-bagimliliklari.json` |
| Tam çözülen resource tablosu | 70; ayrıca 1 Bool belirsiz | aynı dosya |
| Instruction üzerinden resource çağrısı adayı | 114.342; 241 argüman belirsiz | aynı dosya |

285 aday sınıf, 285 ekran demek değildir. RTTI, vtable ve event tabloları modül/VA ile kaydedilir. İsim sınıflandırması ile somut metadata ayrı tutulur. Ana uygulama `.text` aralıklarının 11.730.068 / 11.730.704 baytı, MUF'un 466.604 / 467.440 baytı indeks kapsamında tarandı. Bu byte kapsamı, bütün davranışların anlamlandırıldığı anlamına gelmez.

## Oluşturma ve olay sistemi

`MApplet` vtable adresi `0x2e2b23a8`; address-point slot `+0x10`, tabanda `MApplet::InitResource (0x2e22cc20)` işlevine bağlanır. Uygulama override'larının Frame constructor çağırdığı 70 statik zincir bulundu. Örnekler:

| Uygulama override'ı | Constructor çağrı noktası | Ekran |
|---|---|---|
| HomePageApp `0xd25a30` | `0xd25afc` | HomePageFrame |
| ToolsMenuApp `0xf87494` | `0xf87560` | ToolsMenuFrame |
| SoundSettingsApp `0xee3ba4` | `0xee3c80` | SoundSettingsFrame |

Diğer ana override girişleri: General `0xcf1f24`, Picture `0xe21430`, Quick `0xea11d4`, InputSource `0xd96b54`, SourceSetup `0xefdcfc`, Volume `0xfb601c`. Bunlar vtable + instruction çağrı adaylarıdır; allocation/ownership ve dinamik override seçimi ayrıca incelenmelidir.

MUF `MMainFrame` map `0x2e2b2524` callback isimleri olayları sabitler: `1 → OnCreate (0x2e23704c)`, `2 → OnDestroy (0x2e232380)`, `0x14 → OnKey (0x2e232c9c)`, `0x13 → OnPaint (0x2e235b00)`. Böylece önceki UI raporundaki event-1 kurulum yorumu framework kaydıyla desteklenir. `0x1d/0x1f` mouseDown/wheel yollarıdır; lifecycle diye adlandırılmaz.

Başlangıç envanterinde 78 çözülemeyen getter vardır; hepsinin aynı sınıfta sabit `GetThisMessageMap` adayı bulundu. Bunlar 78 ilave eksik ekran değildir. Navigation/constructor adayları ve Run/Kill/Hide/Focus çağrı noktaları yapı JSON'unda adresleriyle bulunur. Run argümanları yalnız sabit oldukları için “uygulama kimliği” olarak adlandırılmaz.

## Kaynak ID ve çizim

Temiz MUF sorguları public `RcGetNum`, `RcGetImage`, `RcGetColor`, `RcGetString` ID'lerinin paket getter'ına değiştirilmeden geçtiğini gösterir. `GetU32 (0x2e2403a4)` sınır kontrolünden sonra `table[id]`; `GetImgPath (0x2e24097c)` aynı ID'yi index tablosunda kullanır ve `id < 0xffff` koşulu arar. Böylece incelenen flat paketlerde ID→indeks ilişkisi kodla desteklenmiştir. Aktif profil seçimi cihazda gözlenmedi.

71 resource tablosundan 70'i tam tüketildi: 170.389 kayıt. Binary `ResProfile.bin` ayrı biçimde tam parse edildi. `Bool_res.bin` 56 bayt header-only iken header count alanı 2: iki bool değeri çıkarılmış sayılmaz. Kod `GetBool (0x2e240370)` ile byte-indexing gösterir; bitpacking varsayılmadı. `BuildBoolData (0x2e243820)` tip-0 yükleme yoludur. Font tabloları count-0/header-only; `GetFontPath (0x2e2409e0)` index/string yolunu kullanır. Font dosyalarının varlığı, bu boş tabloda seçili olduklarını kanıtlamaz.

`QueryVisualState (0x2e24d5e0)`: flag-1 kapalıysa slot 1; açık ve flag-4 varsa slot 2; aksi halde flag-8 varsa slot 3, yoksa slot 0. `SetFocus (0x2e232fa4)` flag-4'ü kurar, `UnsetFocus (0x2e232f20)` temizler: **slot 2 focus** kanıtlıdır. Flag-1/8 için enabled/pressed adları kesinleştirilmedi. `DrawBackground (0x2e251be4)` ayrıca flag-1 kapalıyken seçimi yeniden düzenlediğinden bütün widget'lara tek koşulsuz state sırası uygulanamaz. Image adresi `widget + 0xb8 + state*0x14` ile seçilir.

`DrawBackground` packed renkten R=`>>16`, G=`>>8`, B=`&255`, A=`>>24` bileşenlerini DirectFB yüzeyine verir. Bu çizim yolunda ARGB yorumu kodla desteklenir. Source ölçekleri ile aktif panel/DirectFB yüzeyi aynı varsayılmaz; kaynak config'leri asset raporundadır.

## Zamanlayıcı ve animasyon

- `MTimerManager::AddTimer (0x2e24c034)` süreyi `/1000` ve `%1000 × 1000000` ile timespec'e ayırır: timer birimi **ms**. Ses panelindeki 3000, **3 saniye kapanış zamanlayıcısıdır**.
- `MWidget::StartAnimation (0x2e259b4c)` async dalında 50 ms timer kurar. `OnAnimationTimer (0x2e25a1c8)` sayacı ve `counter*50` karşılaştırmasını kullanır. Nominal 20 Hz tick, cihazın ölçülmüş frame rate'i değildir.
- `MAnimation::SetDuration (0x2e22bae8)` süreyi 50 ms katına aşağı yuvarlar.
- `GetAnimationEnabled (0x555ed4)` bu build'de sabit 0 döndürür. General `0xd01400` ve Sound `0xee97b4` callback'leri `ShowWithSwipe(...,500,100)` + `StartAnimation` çağrılarını bu getter'ın nonzero dalına koyar; doğrudan Show dışarıda devam eder.
- Source callback `0xd9e11c`, `CloseWithSwipe(...,2,250,100)` çağrısını aynı getter ile koşullandırır. Bu incelenen yollar için build'deki gate davranışı desteklenir; bütün UI animasyonlarına genellenmez.

Normal ses ellipse konumu doğrudan rect güncellemesidir. Bir tamamlanma flag'i bulunması tek başına aktif yumuşak ses tween'i kanıtlamaz. Sesin dört modu, ARC yönlendirme ve kaynak ölçüleri [ayrıntı raporundadır](UI_HARITASI.md).

## Doğrulama ve açık noktalar

Raw MIPS indeksi, ana uygulamanın 54 Ghidra çıktısındaki 91 hedef ve 5.844 ortak sabit argümanla; MUF'un temiz 35 çıktısındaki 191 hedef ve 116 argümanla karşılaştırıldı: uyuşmazlık yok. Bilinmeyen değerler karşılaştırmaya alınmadı. MIPS GOT→symbol eşlemesi ayrıca GNU readelf ile main 8.796, MUF 1.371 global slotta eşleşti. Bunlar runtime binding doğrulaması değildir.

Bağımsız incelemenin bulduğu ROTR/SRL ayrımı düzeltildi; RDHWR register invalidation ve COP branch sınırları da koruyucu olarak genişletildi. Regression fixture'ları geçti. İndekste GP/PIC ABI varsayımları açıkça işaretlidir; vtable/memory yükleri ve cross-block değerler çözülemediğinde hedef uydurulmaz. Ana uygulamada 7.914, MUF'ta 1.933 call hedefi belirsizdir. Nonlink tail/switch jump adayları ayrı kaydedilir.

Yeni sorgular abort/throw sonrası sahte decompiler taşmalarını noreturn ve GOT-callsite override varsayımlarıyla kesti; her değişiklik read-only analiz bağlamında kaldı. SourceSetup `0xf0dd24` payload limiti artırılarak, Home LayoutItems `0xd29500` daha uzun süreyle tamamlandı. Dört C boşluğu: `NewUI_Settings 0x55b6c0`, General create `0xd01710`, Home create `0xd42150`, Tools create `0xf60a64`. Exact range/instruction ve çağrı kayıtları korunur; C başarısı diye sayılmaz.

Decompile tamamlandı işareti doğru prototype veya tam semantik demek değildir. İncelenen davranışlar yukarıdaki adreslerle sınırlıdır. Kalıcı ayarlar, aktif marka/dil, donanımın yanıtları ve fiziksel model uyumu açık kalır.

## Uygulama başlangıcı ve servis devamı

ELF startup/PLT bağı `0xfd0784` adresini ana callback adayı olarak bağladı. FDE ile sınırlanmış 9.352 bayt gövde ayrıca decompile edildi. `ReadResProfile` sıfır dönerse UI kurulmadan return yoluna gider; factory veya oluşturulan app null ise `-1`. Başarılı dalda `0xfd2434` callsite'ı `MApplet::Run` için `a0=DefaultApp, a1=0xfe, a2=0` geçirir. Default factory'nin `+8` callback hedefi henüz çözülmedi. Ardından boot-complete bildirimi gelir; console/test koşulları ana event-loop yolunu değiştirir.

Ghidra'nın bu gövdeye verdiği `float,float,int,char**` prototipi güvenilir değildir: girişte gerçek `a0/a1` değerleri stacke saklanıp ilk option-init çağrısına aktarılır. CEC customer wrapper'ında da callback sonucu destructor/delete üzerinden korunmadığı için “processed bool” yorumu geri çekildi. Bunlar [sekiz yeni davranış grubunda ve adresli assembly kayıtlarında](bilgi-tabani/SERVIS_DERINLESTIRME.md) açıklanır.

MUF render çekirdeği için beş ek C gövdesi, DirectFB constructor'ları için üç ek C gövdesi alındı. Constructor'a yazılan callback adresleri, aynı nesne türünün MUF slot kullanımlarıyla karşılaştırılır; provider, surface ve ana DirectFB nesnesinin aynı offsetleri birbirine karıştırılmaz. Hedef gövde çözümü [DirectFB callback çıktılarında](../analiz/native/directfb-callbacks-v1/) ayrı kapsamdır.
