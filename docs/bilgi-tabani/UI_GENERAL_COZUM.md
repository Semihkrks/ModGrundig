# GeneralSettingsFrame oluşturma gövdesi

23 Ekim 2026. `0x00d01710–0x00d254dc` için **tam işlev C pseudocode'u alındı**. Önceki 90 saniyelik başarısızlık, açık FDE sınırı, standart noreturn varsayımları, 300 saniye ve 256 MB decompiler payload ile aşıldı. Kaynak kod geri kazanıldığı veya tüm çalışma zamanı davranışı gözlendiği iddia edilmez.

Hedef `08_APP/bin/dvbt_board`, SHA-256 `51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916`. İncelenen ELF tekrar hash edildi. Orijinal firmware, TV ve target kodu değiştirilmedi; çıkarılan programlar çalıştırılmadı. Çıktı doğrudan Ghidra statik analizidir, REA Evidence değildir. Kullanılan beceri: `reverse-engineer-anything`.

## Gerçek kapsam ve açık uçlar

| Ölçüm | Sonuç |
|---|---:|
| FDE aralığı / `.eh_frame` ofseti | `[0xd01710,0xd254dc)`, `0x2b6fc` |
| FDE bayt / mevcut instruction | 146.892 / 36.723 |
| Eksik veya sınır dışında instruction | 0 / 0 |
| Tam C çıktısı | 1 / 1, 382.831 bayt |
| Ham çağrı adayı | 3.642 |
| Symbolic GOT / çözülmemiş indirect hedef | 3.573 / 69 |
| Export edilen pcode çağrısı / sınır dışı pcode adresi | 3.197 / 0 |
| Constructor / benzersiz son ulong ID | 66 / 66 (`0–65`) |
| Statik message-map kaydı / ID ile eşleşen widget | 44 / 31 |

3.642 ham çağrı ile 3.197 pcode çağrısı arasındaki **445 fark** kaybedilmiş normal menü çağrısı olarak geçiştirilmedi: `operator delete` 66, `_Unwind_Resume` 129, `MImg::~MImg` 180, `MString::~MString` 18, `__cxa_guard_abort` 18, string destructor 18, allocator destructor 15 ve ostringstream destructor 1. Bunlar exception/cleanup yollarıdır; [tek tek adresleri](../../analiz/native/ui-four/general/raw-pcode-call-gaps.json) korunur. Tam C, her cleanup instruction'ın C'de yeniden gösterildiği anlamına gelmez.

69 indirect çağrının slot erişimi ayrıştırıldı: **66 × vtable `+0x34`**, ayrıca first-time liste yolunda birer `+0x48`, `+0x44`, `+0x40`. İlk grubun argümanları parent ve child nesneleridir; child ekleme bağlantısı adayıdır. Somut dinamik hedefler halen bilinmez; adres uydurulmadı. [Slot ve assembly kayıtları](../../analiz/native/ui-four/general/indirect-call-slots.json).

C'deki 66 `WARNING: Subroutine does not return` işareti abort dallarıdır. Jump-table kurtarılamadı uyarısı yoktur. Bu, prototiplerin doğru olduğu anlamına gelmez: `MWidget::Hide`, `MString::Set`, `SetInitialFocus`, `SwitchFocusTo`, `NewUI_Settings` gibi çağrılarda C argüman listesi eksiktir. Aşağıdaki davranışlarda gerçek `a0/a1/...` register yükleri esas alındı.

## Widget ağacı ve kaynaklar

66 nesnenin türleri: 21 ImageButton, 21 ComboButton, 7 TextBox, 6 ScrollListContainer, 6 AbsContainer, 2 Image, 2 SpinButton, 1 Button. Her nesnenin constructor, `this+alan` store instruction'ı, son ulong argümanındaki ID'si, parent alanı ve kaynak getter noktaları çıkarıldı. **66 alan yazımının tamamı C ve assembly arasında kontrol edildi.**

[66 satırlık tam widget tablosu](../../analiz/native/ui-four/general/widget-table.md), [makine okunur kaynak/renk/Rect/handler kayıtları](../../analiz/native/ui-four/general/widget-resource-groups.json).

| Parent alanı | Doğrudan çocuklar | İşlev / constructor kanıtı |
|---|---|---|
| `+0x38` | ID `0–9` | Başlangıç Button, iki Image, altı liste, bir TextBox; `0xd0180c–0xd06ac8` |
| `+0x18c`, liste ID 3 | ID `10–19` | Dil/Klavye, Erişilebilirlik, Aksesuarlar, Gelişmiş, Hakkında, Hotel, rehber/veri satırları; `0xd06fd4–0xd0adc0` |
| `+0x190`, liste ID 4 | ID `20–23` | Menü/ses/altyazı/klavye dili; `0xd0b250–0xd0c668` |
| `+0x194`, liste ID 5 | ID `24–27` | Sesli anlatım, altyazı modu, anlatım sesi; `0xd0cd48–0xd0e87c` |
| `+0x198`, liste ID 6 | ID `28–42` | Bluetooth/Easy Remote/kamera/USB/VR/gesture satırları; `0xd0f150–0xd14a98` |
| İç AbsContainer alanları | ID `43–47` | Bluetooth, Easy Remote, Kamera, USB Klavye/Fare TextBox'ları; `0xd15178–0xd16440` |
| `+0x19c`, liste ID 7 | ID `48–56` | Kapanma, kanal geçişi, mağaza, LED, güç, timeshift, hava, yardım, hızlı açılma; `0xd168d0–0xd1aed0` |
| `+0x1a0`, liste ID 8 | ID `57–65` | Ürün bilgisi, TV adı, güncelleme, factory reset, geçmiş/imaj/ayar reset, ülke ve lisans; `0xd1b790–0xd1f298` |

Bu etiketler English/Turkish `Str_res.bin` tablo indekslerinden okunmuştur; bazı Türkçe kayıtlar firmware'de İngilizcedir. Etiket, bir özelliğin fiziksel cihazda etkinliğini kanıtlamaz.

Örnek geometri: `0xd01754/6c/84/9c` getter'ları sırasıyla Num ID `13057,13058,13056,13055` alır. `0xd017c4` `_Rect::set` çağrısına `(0,5,1920,5)` gider; `0xd0180c` Button ID 0 oluşturur, `0xd01820` sonucu `this+0x180` alanına yazar. İlk liste `0xd023a4` için başlangıç Rect `(0,100,1920,360)`; ID 1 Image `0xd01c1c` için `(950,476,36,24)` bulunur. Bunlar mantıksal Num tablosu değerleridir. Bazı satırlar sıfır boyutla başlar; `0xd24e6c` sonrasındaki `NewUI_Settings` yeniden düzenini veya aktif TV pikselini temsil ettikleri varsayılmaz.

ImageButton ID 10'un dört background MImg slotu `0xd071e0,0xd07204,0xd07228,0xd0724c` noktalarında `1042,1485,1038,1485` alır. Üç marka Image tablosunda ID 1042 `Common/half/bg/set_rowseperator.png`, 1038 `Common/half/bg/set_activerow_ok.png`, **1485 `---` sentinel metnidir**. Bu son ID bir PNG dosyası gibi yorumlanmaz. Image ID 1'in content slotları `0xd01cdc–0xd01d48` aralığında Image 9 (`Common/icons/navigation/arrowdown-small.png`) alır. Dört slotun normal/focus/pressed/disabled anlam sırası bu işlevden tek başına ispatlanmaz.

ComboButton ID 48'de `0xd1699c` Color 94, `0xd169c0` Color 78 alır: üç palette de sırasıyla `0xfff5f5f5` ve `0xff0a0a0a`. Aynı grubun Color 85 değeri Grundig `0xff373746`, Beko `0xff244d7b`, Arçelik `0xfff32929` olarak değişir. Her renk erişiminin VA/indeks/tablo ofseti kaynak JSON'undadır. `rc_Beko` ve `rc_Arcelik` profilleri Num için açıkça ortak `rc/Num.rc` tablosunu gösterir; profil seçimi çalışma zamanında gözlenmedi.

## Olay ve callback bağlantısı

`GeneralSettingsFrame::GetThisMessageMap` girişi `0x00cf2178`, map `0x010be074`. `0x010be07c` kaydı event 1'i `0xd01710` gövdesine bağlar; OnCreate rolü MUF adlandırılmış event-1 handler'larıyla karşılaştırılmış statik yorumdur. `0x010be0b4`, event `0x14` için adlandırılmış `GeneralSettingsFrame::OnKey=0xcff0b0` hedefini içerir. [44 ham kayıt](../../analiz/native/ui-four/general/message-map.json).

Son constructor ulong argümanı ID `0–65` ile map'in event `0x16` selector aralıkları birleştirildi. 31 widget için eşleşme var; subtype `16/19` değerleri ham olarak korunur. Örnekler:

| Widget / kayıt VA | Selector ham alanları | Handler |
|---|---|---|
| ID 20 Menü Dili / `0x010be178` | `[19,20,20,0]` | `0xcfca08` |
| ID 48 Otomatik Kapanma / `0x010be2c8` | `[16,48,48,0]` | `0xcf59e8` |
| ID 60 Fabrika Ayarları / `0x010be23c` | `[19,60,60,0]` | `0xcf62f4`, adlandırılmış `OnNtyClick_ImageButton_Factory_Reset` |
| ID 63 Ayar Yedekleme / `0x010be4f8` | `[19,63,63,0]` | `0xcf41ec` |

ID 32 için aynı `0xcfbe40` hedefini içeren iki map kaydı vardır (`0x010be338`, `0x010be3fc`); benzersiz handler diye iki kere sayılmadı. Genel subtype 7/9 ve sıfır selector kayıtları belirli ID-0 widget'a otomatik bağlanmadı. Selector eşleşmesi handler gövdesinin çözüldüğü veya runtime dispatch'in gözlendiği anlamına gelmez.

`0xd2486c` çağrısı first-time dışında kendine event `0xc0000020` yollar (`a0=this,a1=this,a2=event,a3=0,stack+0x10=0`). Map kaydı `0x010be0d0`, hedef `0xd01400`. Gövdedeki 18 `__cxa_guard`/`__cxa_atexit` grubu ise statik MString seçenek dizilerinin tek seferlik kurulumu ve destructor kaydıdır; UI handler kaydıyla karıştırılmaz. [Birleşik kayıtlar](../../analiz/native/ui-four/general/callback-bindings.json).

## Koşullar, odak ve gerçek çağrı argümanları

- `0xd24574` ilk odağı ID 0, `this+0x180` nesnesine verir (`a0=this,a1=widget`). App private data `0xb` ise `0xd245d8` odağı TV Rehberi ID 17, `+0x1c4` alanına geçirir ve arka plan çubuğunu seçer. C'deki tek argümanlı görünüm bu ikinci argümanı gizler.
- First-time durumuna göre HelpWidget, FirstTimeFrame `+0x1b4` veya MenuBackgroundFrame `+0x1cc` üzerinden kurulur (`0xd24610–0xd247c8`). First-time değilse `0xd2483c` ana liste `+0x18c`yi gizler ve yukarıdaki deferred eventi yollar. First-time yolunda `0xd24ccc` liste `+0x198` için flag 2'yi 1 yapar; vtable `+0x48/+0x44/+0x40` üzerinden listeyi dolaşıp uygun çocuğa odak geçer (`0xd24cf8/0xd24d40/0xd24d80/0xd24df4`).
- `0xd24890` `LockParental` çağrısı vardır. PermanentTimeshift veya UsbRecording servis getter'larından biri sıfırsa `0xd24924` ID 53 / `+0x254` satırını gizler (`0xd248b4,0xd248e0` koşulları).
- `0xd24e6c`: gerçek çağrı `ArUIManager::NewUI_Settings(a0=manager,a1=this)`; `0xd24e88`: `CommonFrame::EnableShadows(a0=this,a1=1)`. C'deki `NewUI_Settings(pMVar13)` ve `EnableShadows((uchar)param_1)` ifadeleri doğru argüman sözleşmesi olarak kullanılmaz.
- `0xd250e8` current input source tipi **5** dönerse `0xd25124` `SetAudioDescription(a0=audioManager,a1=3)` çağrılır; sesli anlatım ID 26/27 için flag 1 sıfırlanır. Kaynak 5'e burada yeni bir donanım adı atanmadı.
- `ArTvConf_GetCustomScreenSaver()==0` (`0xd25190`) ise ID 62 / `+0x278` gizlenir (`0xd251bc`).
- `Hotel!=0 && HotelAdmin==0` (`0xd251e0,0xd2520c`) ise ID 60 Factory Reset ve ID 59 Software Updates gizlenir (`0xd25250,0xd2526c`). Buna karşılık Hotel satırı ID 15 yalnız `Hotel!=0 && HotelAdmin!=0` iken bu son kapıdan geçer; diğer durumda `0xd25300` onu gizler (`0xd25290,0xd252bc`).
- `SettingsRecovery==0` (`0xd25324`) ise ID 63 gizlenir (`0xd25350`). `ArTvConf_GetBasicMode()==1 && GetBasicMode()==1` (`0xd25374,0xd253a8`) ise ID 12 Aksesuarlar, ID 10 Dil/Klavye, ID 14 Hakkında ve ID 13 Gelişmiş gizlenir (`0xd253f4,0xd25410,0xd2542c,0xd25448`).

Getter ve branch'ler bu sonuçları statik olarak kurar; gerçek cihazdaki ayar değerleri bilinmez. Flag 1/2 için bu işlevden yeni isimler türetilmedi. Gesture, Bluetooth, non-connected, weather, fast-boot ve bubble-help servis kapıları da gövdede yer alır; adresler ve widget alanları C/ham çağrı kayıtlarında tutulur. [Kritik assembly aralıkları](../../analiz/native/ui-four/general/behavior-assembly.json), [tam assembly](../../analiz/native/ui-four/general/assembly.txt).

## Paylaşılan kaynak etkisi ve tekrar üretim

Global ham indeks, Num 17909'u 7.975 çağrı/89 işlevde; Num 17913'ü 4.773/92; Image 1485 sentinel'ini 13.325/109; Image 9'u 37/10 işlevde gösterir. Bunlar statik çağrı adaylarıdır. Böyle bir Num, palette veya Image girdisini değiştirmek tek General satırıyla sınırlı kabul edilemez. [Örnek çapraz işlev kayıtları](../../analiz/native/ui-four/general/shared-resource-check.json).

Tam C: [00d01710.c](../../analiz/native/ui-four/general/bounded300/00d01710.c). Tam native kayıt: [00d01710.json](../../analiz/native/ui-four/general/bounded300/00d01710.json). [Kapsam ölçümleri](../../analiz/native/ui-four/general/scope-edges.json), [hash/alan doğrulamaları](../../analiz/native/ui-four/general/validation.json), [decompiler özeti](../../analiz/native/ui-four/general/bounded300/summary.json).

`python -X utf8 scripts/analyze_general_ui.py` tamamlandı; kaynak hash'i, tüm 66 constructor ID'si, C alanları ve bunların assembly store'ları doğrulandı. `python -m py_compile scripts/analyze_general_ui.py` çalıştırıldı. Firmware ve UI kodu için build/test uygulanmadı; bu görev yalnız çevrimdışı kanıt üretimidir. Fiziksel TV, aktif profil ve dinamik vtable hedefleri halen gözlemsizdir.
