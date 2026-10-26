# NewUI_Settings: tür dalları, ortak görünüm ve iki atlanan switch

23 Ekim 2026. İncelenen hedef `dvbt_board`, SHA-256 `51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916`. İşlev `ArUIManager::NewUI_Settings`, giriş `0x0055b6c0`, FDE sonu `0x00579360` hariç; **122.016 bayt**. Bu belge statik davranış çözümüdür; doğrudan Ghidra ve ham ELF/MIPS çıktıları REA Evidence diye adlandırılmaz. Firmware/TV çalıştırılmadı ve hedef baytları değiştirilmedi.

Güncel sonuç: [tam aralık C kontrol akışı çıktısı](../../analiz/native/ui-four/settings/reduced-recovery180/0055b6c0.c) **345.653 bayt / 7.291 satır** olarak alındı. **C çıktısı 1; azaltılmış tür/prototip çıkarımıyla C 1; varsayılan tam recovery pipeline ile C 0.** `protorecovery`, `protorecovery_b` ve `localrecovery` kapatıldı; yazdırma stili `decompile`, C üretimi açık kaldı. Bu, tamamen tiplenmiş özgün kaynak kod değildir. Çağrı argümanları için ham assembly/kaynak haritası esas alınır.

## İşlevin görevi

Bu gövde, verilen ayar ekranını türüne göre yeniden düzenleyen ortak görünüm uygulayıcısıdır. `__dynamic_cast` argümanlarının GOT/typeinfo adları ekran türünü somut olarak sabitler. İlk aşamada ekranlara özel çocuklar/ölçüler, sonra ortak container/control stilleri, son aşamada **otomatik ve manuel aramanın sonuç/kaynak bilgisi panelleri** kurulur. Bu yorumun adresli ayrıntıları [critical-branches.json](../../analiz/native/ui-four/settings/critical-branches.json), bütün tür denetimleri [type-dispatch.json](../../analiz/native/ui-four/settings/type-dispatch.json) içindedir.

Ghidra'nın eski `undefined NewUI_Settings(MMainFrame *param_1)` prototipi doğru parametre sayısı kanıtı değildir: girişte `a0 → stack+0x16e0`, `a1 → stack+0x16e4` saklanır (`0x55b6e8/0x55b6ec`); `a1`'den gelen nesne ilk `MMainFrame::MoveWindowTo` çağrısına `a0` olarak verilir (`0x55b718–0x55b728`). C++ simgesiyle birlikte bu, `this` ve `MMainFrame*` ayrı girişlerini destekler. İlk konum çağrısı `x=0`, hesaplanan `y` kullanır; aktif cihaz çözünürlüğü buradan belirlenmez.

Metadata preflight bunu gerçek bir kayıt hatası olarak doğruladı: **unknown calling convention, sıfır otomatik parametre, tek `MMainFrame*` input `a0:4`**. Ayrı `settings-abi` proje kopyasında kayıt **`ArUIManager* manager → a0:4`, `MMainFrame* frame → a1:4`**, CUSTOM_STORAGE ve sıfır auto-parametre olarak düzeltildi. Var olan iki yapı tipi kullanıldı; return `/undefined` ve `<UNASSIGNED>` storage aynen korundu. Programın Ghidra MIPS default convention adı `__stdcall`'dır; bu, Windows ABI kullanıldığı iddiası değildir. Önce/sonra kanıtı [settings-abi-before.json](../../analiz/native/ui-four/settings/abi_filled_conly600/settings-abi-before.json), [settings-abi-correction.json](../../analiz/native/ui-four/settings/abi_filled_conly600/settings-abi-correction.json); uygulayan helper [SettingsCorrectAbi.java](../../scripts/ghidra/SettingsCorrectAbi.java). Bu düzeltme yalnız kaydedilmeyen analiz metadata'sındadır.

| RTTI denetimi | Çağrı VA | Statik yol |
|---|---|---|
| AutoSearchFrame | `0x55b768` | Cast null ise `0x560f18` sonraki ekran kontrolüne gider; başarılı dalda `+0x1d4` çocuk Hide ve `+0x1d8/+0x1dc/+0x1e0` flag-2 sorguları vardır (`0x55b80c/82c/854/87c`). |
| ManualSearchFrame | `0x560f4c` | Manuel aramaya özel çocuklar/yerleşim; `0x561034` Hide, `0x561054/7c/a4` flag-2 sorguları. |
| AntennaSettingsFrame | `0x562ed4` | Anten ayarı dalı; `0x5635cc/0x5635e8` iki Hide çağrısı. |
| SourceSetupFrame | `0x563628` | Kaynak ayarı dalı; `0x5642b4/0x5642d0` iki Hide çağrısı. |
| FTI_BasicSetupFrame | `0x564310` | İlk kurulum ekranına özel yerleşim. |

Flag `2` burada örneklenir ve diğer çocuklara aktarılır; bu rapor flag'e doğrulanmamış visible/enabled anlamı yüklemez.

`0x565e60–0x565fa4` aralığı AutoSearch, ManualSearch, AntennaSettings, SourceSetup ve SoundSettings tür denetimlerini OR koşulunda birleştirir. Bu koşuldan geçen yol `frame+0x38` çocuk koleksiyonunu sanal slot `+0x40/+0x44` üzerinden dolaşır (`0x565fb8–0x566150`). `AbsContainer` cast'i (`0x566020`) sonrası `+0x3a` baytı `1` ise vektöre alınır; diğer dalda rect yüksekliği `600` olur (`0x566084`). Sanal slotların bütün sınıflardaki hedefleri çözülmüş sayılmaz.

`AntennaSettingsFrame+0x184/+0x188` çocuk kimliği karşılaştırmaları özel container düzenini seçer (`0x5661ac–0x5662ec`): rect `x=0,y=49,w=1920,h=600` kurulur (`0x5662f4–0x566314`), `+0x39/+0x3a` baytları temizlenir, border gizlenir ve ilk çocuk Hide edilir (`0x566358–0x5663b0`). `0x566474` çağrısı `FindScrollLists` ile scroll/abs container koleksiyonlarını bulur.

Ortak çocuk stil yolunda gerçek türler `ComboButton 0x567710`, `ImageButton 0x567874`, `SpinButton 0x567978`, `NumberEdit 0x567adc`, `TickBox 0x567fe4`, `AbsContainer 0x5680ec` cast'leriyle ayrılır. `ManualSearch+0x200` container kimliği `0x5681c4–0x5681f4` yolunda ayrı başlık düzenini seçer; olağan başlık çocuklarına image `0x6d` verilir (`0x568300`). Dallar `Invalidate` çağrılarında birleşir (`0x568558/0x5685d8`).

## Focus ve giriş/çıkış kapsamı

AutoSearch dalında `frame+0x3c == frame+0x180` ise `SwitchFocusTo` çağrılır (`0x55f858–0x55f884`); hedef, daha önce stack `+0x14c`'ye konulan bileşendir. Bu, görünüm kurulurken focus'u yeni bileşene taşıyan koşullu kenardır; bütün ekranların ilk focus seçimi olduğu ileri sürülmez.

Bu fonksiyonun 3.071 ham çağrı adayı içinde doğrudan `OnKey`, `Run/Kill`, `CloseWithSwipe` veya `GetAnimationEnabled` çağrısı yoktur. Bu sınırlı negatif bulgu, geri tuşunun bu gövdede yorumlanmadığını ve doğrudan animasyon gate'i bulunmadığını gösterir; çağıran ekranların key/event davranışını veya dolaylı 281 çağrıyı dışlamaz. İşlevin 16 gelen çağrı adayı [raw-selected-calls.json](../../analiz/native/ui-four/settings/raw-selected-calls.json) içindedir; isimleri yalnız FUN olan çağıranlar sınıf adı uydurularak tamamlanmadı.

Arama ilerleme çubuğunun görsel/renk kurulumu `ProgressBar::SetBarImg 0x569010` ve `SetBarColor 0x569200` çağrılarına bağlanır. Örnek oluşturma yolu `operator new(0x264) 0x5692c8 → AbsContainer(...frame+0x38...) 0x569300`'dır; nesne null kontrolü `0x569318` üzerinden `printf 0x569380 → abort 0x569390` yoluna ayrılır. Bu hata dalına rağmen akışın devam ettiği decompiler çıktısı doğru sayılmaz. Normal çıkışta geçici vektörler yok edilir (`0x57925c/274/28c`) ve `jr ra 0x5792b0` ile dönülür. FDE'nin sonundaki `0x5792b8–0x579360` exception cleanup kuyruğu `_Unwind_Resume 0x579358` ile biter; ayrı ekran kodu değildir.

## İki gerçek switch ve atlanmış 336 instruction

FDE sınırı uygulandıktan sonra bile mevcut Ghidra listesinde iki aralık tanımsızdı: `0x55e834–0x55ead4` ve `0x55f598–0x55f838`, her biri 672 bayt. **Bunlar inline veri değil, ikişer beş gerçek MIPS case bloğudur.**

`GetID` dönüşünden `0x50` çıkarılır (`0x55e7f4/0x55f558`), unsigned sonuç `<5` değilse default kenarına gider (`0x55e808/0x55f56c`); `jr v0` dispatch adresleri `0x55e82c/0x55f590`'dır. PIC `gp=0x10cc310` varsayımı altında `GOT[gp-0x7fdc]=0xfe0000`; tablolar `0xfe7c80/0xfe7c94` adreslerinde beşer GP-relative word içerir. Her case, aynı image ID'yi dört `MImg::Set` çağrısına verir. Widget ID'leri kumanda tuş kodu değildir.

| Widget ID | Image ID | Profil tablosundaki yol | İlk/ikinci case girişleri |
|---|---|---|---|
| `0x50` | `0x127` | `Settings/icons/digital.png` | `0x55e834 / 0x55f598` |
| `0x51` | `0x129` | `Settings/icons/radio.png` | `0x55e8bc / 0x55f620` |
| `0x52` | `0x124` | `Settings/icons/analog.png` | `0x55e944 / 0x55f6a8` |
| `0x53` | `0x128` | `Settings/icons/free.png` | `0x55e9cc / 0x55f730` |
| `0x54` | `0x12b` | `Settings/icons/scrambled.png` | `0x55ea54 / 0x55f7b8` |

Ham table word'leri, case instruction word'leri, 40 çağrı noktası ve ID'ler [switch-cases.json](../../analiz/native/ui-four/settings/switch-cases.json) içinde korunur. [SettingsFillListingGaps.java](../../scripts/ghidra/SettingsFillListingGaps.java) yalnız bu iki açık aralıkta metadata disassembly ve ham tabloyla doğrulanan ephemeral jumptable override uygular; byte/DB kaydetmez. **Helper çalışması geçti: her aralıkta 0 → 168 instruction, beşer case seed; iki jump table ham word'lerle doğrulandı.** Kanıt [settings-gap-decode.json](../../analiz/native/ui-four/settings/filled_conly600/settings-gap-decode.json). Bu metadata düzeltmesinin ardından standart C-only sorgusu ayrı çalışır.

## Kaynak ve paylaşım

[resource-bindings.json](../../analiz/native/ui-four/settings/resource-bindings.json) **1.564 kaynak çağrı adayı**, **51 tür/ID grubu**, bunların içinde **16 image ID ve 13 string ID** kaydeder; **20 argüman belirsizdir**. Gruplar çağrı VA'larını, tematik adres aralıklarını ve üç marka tablosu adayını içerir. Adres aralığı etiketi, tek başına tam koşul/fizibilite kanıtı değildir.

Son iki büyük ekran dalında **aynı 13 label ID, AutoSearch ve ManualSearch için iki kez** kullanılır. `0xeee → ARAMA SONUÇLARI` (`0x569cf8/0x571b48`), `0xfa3 → KAYNAK BİLGİSİ` (`0x56adfc/0x572c4c`), `0xdcc → SON BULUNAN KANALLAR` (`0x56bf00/0x573d50`). Devamında Toplam Sonuç, Dijital TV Kanalı, Radyo Kanalı, Analog TV Kanalı, Data Kanalı, Kaynak, Konum, Frekans, Polarizasyon ve Sembol Oranı etiketleri bulunur. Yalnız bu 13 olağan UI metninin EN/TR tablo ofset/hash/içeriği ve 26 çağrısı [search-result-labels.json](../../analiz/native/ui-four/settings/search-result-labels.json) içindedir; aktif dil seçimi gözlenmedi.

Örnekler: `0x122` hover arka planı (`0x55b994`), `0x125` antenna (`0x55ba94`), `0x126` cable (`0x55bf38`), `0x12a` satellite (`0x55c470`), `0x242` sinyal görseli (`0x55e4e4`), `0x136` arama satırı (`0x56ce60`), `0x137` ayırıcı (`0x569720`), `0x135` sayı girişi (`0x567e08`). `0x4ac/0x5cd` tablolarda `---` değerindedir; geçerli PNG yolu uydurulmaz. Grundig `0x122`, `Grundig/new/menutree/empty_hover_bg.png`'ye; diğer markalar kendi `Settings/empty_hover_bg.png` yollarına karşılık gelir. Aktif profil cihazda gözlenmedi.

Renk `0x13` üç marka için sırasıyla `0xb60181d4 / 0xb67569eb / 0xb6e04063`; `0x16` için `0xff00b4fe / 0xff9755d0 / 0xffde414c`. Bu aynı kodun tablo üzerinden marka renklerini paylaşması için somut adaydır; çalışma zamanı seçimi değildir. Num ID `0x45f5=3`, `0x45f9=4`, `0x3215=36` gibi ortak ölçüler aynı gövdede çok sayıda kullanılır. ID→tablo indeksi yorumu önceki MUF getter incelemesine dayanır; bu rapor her immediate'ı kaynak diye saymaz.

## Deneme ve doğrulama durumu

| Yöntem | Sonuç |
|---|---|
| Eski 90 s çıktısı | C yok; 25.750 instruction / 103.000 bayt analiz gövdesi. |
| `fde300`: exact FDE + PIC t9 + noreturn + 256 MB, 300 s | **0/1 C; timeout.** 30.168 instruction / 120.672 bayt listelendi; 336 instruction iki switch boşluğunda. Ham indeks aynı 122.016 bayt içinde 3.071 çağrı: 2.790 GOT sembolik aday, 281 çözülemeyen indirect. Ghidra listesinde 3.031 computed call; farkın 40'ı iki switch'te. |
| `conly600`: aynı sınır/varsayımlar, C-only/256 MB/600 s | **0/1 C; timeout.** Eski iki listing boşluğu devam eder. |
| `filled_conly600`: metadata gap-fill + explicit jumptable override, C-only/256 MB/600 s | **0/1 C; timeout.** Helper geçti: 336 instruction tamamlandı, iki switch override doğrulandı. |
| `abi_filled_conly600`: ayrı metadata kopyası, yukarıdakilere ek iki explicit register input | **0/1 C; timeout.** ABI before/after, return koruma ve gap/jump-table denetimleri geçti. **30.504/30.504 instruction = 122.016/122.016 bayt; sıfır listing boşluğu; 3.071 Ghidra computed call = 3.071 ham çağrı adayı.** |
| `normalized90`: normalize stili, 90 s | Timeout; standart C sayılmaz. |
| `firstpass90`: firstpass stili, 90 s, `emit_c_code=false` | **Native diagnostic başarı 1; C dosyası 0.** Tam 30.504 instruction ve 2.739 pcode call kaydı; seçili gövde dışında pcode adresi 0. SSA/tür recovery veya C başarısı değildir. |
| `standard-nopredicate240`: decompile stili, predication/split seçenekleri kapalı, 240 s | Timeout; C 0. |
| `reduced-recovery180`: decompile stili, C açık; prototype/local recovery grupları kapalı, 180 s | **Gerçek C 1, 345.653 bayt / 7.291 satır; varsayılan tam recovery C 0.** 12:37:26–12:40:28 log aralığı 182 s; aktif CPU ölçümü değildir. Tam instruction kapsamı/gap 0 korunur; C-only pcode yoktur. |

`fde300` başarısızken boş pcode/outside-body listesi **scope doğrulaması değildir**. C-only modda kullanılabilir HighFunction/pcode üretilmediğinden bu ölçüm null olmalıdır; boş HighFunction nesnesi bunu değiştirmez. Güncel makine sayımları [scope-edges.json](../../analiz/native/ui-four/settings/scope-edges.json), deneme zamanları [attempts.json](../../analiz/native/ui-four/settings/attempts.json), kontrol transferleri [control-transfers.json](../../analiz/native/ui-four/settings/control-transfers.json) içindedir. `actual_C_count`, native başarı sayacından türetilmez: gerçek ve boş olmayan `.c` dosyası + `decompile` stili + C üretiminin açık olması gerekir. `default_full_recovery_C_count` ve `reduced_inference_C_count` ayrıca tutulur. Fragment C, tam gövde sayımına eklenmez.

Firstpass'in kullanılabilir pcode sonucu [firstpass-flow-scope.json](../../analiz/native/ui-four/settings/firstpass-flow-scope.json), çağrıları [firstpass-pcode-calls.json](../../analiz/native/ui-four/settings/firstpass-pcode-calls.json) içinde ayrı korunur. Bu sorgu tam gövde içinde 2.739 pcode call gösterir; bu sayı 3.071 ham çağrı adayının birebir eşlendiği veya runtime çağrı grafiği olduğu anlamına gelmez. Azaltılmış recovery C sorgusunun pcode kapsamı bu ayrı firstpass sorgusuyla ikame edilmez.

## Üretilen C ile ham kanıtın çapraz kontrolü

[C-raw-crosscheck.json](../../analiz/native/ui-four/settings/C-raw-crosscheck.json) şu kontrolleri kaydeder:

- C başlığı `ArUIManager *manager, MMainFrame *frame` iki input'u gösterir (C satır 4); ham giriş `0x55b6e8/0x55b6ec` ile uyumludur.
- İki manuel switch override'ının **10 case VA'sı** C'de bulunur; her case **dört `MImg::Set` GOT çağrısı** içerir. Selector `GetID()-0x50`, `<5` guard'ı ve GP-relative tablo ifadeleri korunur (C 1892–1927 ve 2063–2098 çevresi). Image ID argümanları C çağrılarında yazdırılmadığı için ikon eşlemesi ham MIPS tablosuna dayanır.
- C'deki kritik GOT kullanım sayıları ham adaylarla eşittir: `__dynamic_cast 35/35`, `SwitchFocusTo 1/1`, `Hide 8/8`, `QueryFlag 8/8`, `MImg::Set 341/341`, `FindScrollLists 1/1`, `abort 78/78`. Slot sayısı eşliği, kayıp çağrı argümanlarını veya RTTI tipi çıkarımını doğrulamaz.
- Focus `frame+0x3c == frame+0x180` koşulu C satır 2100'de ve ardından `SwitchFocusTo` GOT çağrısında korunur; ham `0x55f868/0x55f884` ile uyumludur. Antenna `+0x184/+0x188` kimlik dalları C'de `LAB_00566240/LAB_005662d4` goto/if biçiminde kalır; bunlar aynı ham branch hedefleridir.
- Normal return C satır 6794'te vardır. **Ham 37 `_Unwind_Resume` çağrı adayı normal C metninde yoktur**; implicit EH/LSDA ve exception cleanup semantiği tamamen geri kazanılmış sayılmaz. C printer `void` üretse de ABI helper return metadata'sını `/undefined` olarak korumuştur; özgün return semantiği bundan kanıtlanmaz.

Çok sayıda callee çağrısı argümansız GOT ifadesi ve `extraout` geçici değişkenleri olarak kalır. `WARNING: Switch is manually overridden` beklenen açık varsayımı gösterir; noreturn uyarıları da ham abort/throw varsayımlarıyla birlikte okunmalıdır. Dosya boyutu ve C varlığı, bu sınırlamaları ortadan kaldırmaz.

Son iki iş sırasında host saati 02:52'den 12:17'ye ilerledi. İstenen decompiler timeout'u 600 saniyedir; log başlangıç/bitiş farkı bu nedenle **aktif CPU süresi olarak yorumlanmaz**. Timeout sonucu ve üretilmiş dosyalar gerçek kayıtlardır.

## Mantıksal CFG fazlarına geçiş

Tam gövdeyi aynı 600 saniyelik yöntemle yeniden denemek yerine aşağıdaki **13 doğal faz** ayrıldı. Bunlar orijinal bağımsız C++ fonksiyonları değildir. [phase-plan.json](../../analiz/native/ui-four/settings/phase-plan.json), her faz için tam instruction sayısını, incoming/outgoing branch VA'larını, doğrudan stack okumalarını/yazmalarını, adresi alınan stack nesnelerini ve noreturn uçlarını içerir. Üretici [analyze_settings_phases.py](../../scripts/analyze_settings_phases.py), fazların birleşiminin tam 30.504 instruction/122.016 baytı örtüştürmeden kapladığını doğrular. Aralıkların sonu hariçtir; aşağıdaki stack ofsetleri orijinal `s8` tabanına göredir.

| Faz | Başlangıç → son | Bağlam girdileri / devam |
|---|---|---|
| Giriş/konum | `0x55b6c0 → 0x55b734` | Gerçek `a0=manager`, `a1=frame`, orijinal PIC giriş `t9`; prolog 0x16e0 bayt frame ayırır. |
| AutoSearch ilk görünüm | `0x55b734 → 0x560f18` | `stack+0x16e4=frame`, çocuk nesne durumu; cast pointer `+0x150`; iki ikon switch'i bu fazdadır. |
| ManualSearch ilk görünüm | `0x560f18 → 0x562ea0` | `+0x16e4=frame`; cast pointer `+0x100`. |
| Antenna ilk görünüm | `0x562ea0 → 0x5635f4` | `+0x16e4=frame`; cast pointer `+0xf8`; 469 instruction. |
| Source ilk görünüm | `0x5635f4 → 0x5642dc` | `+0x16e4=frame`; cast pointer `+0xf0`; 826 instruction. |
| İlk kurulum görünümü | `0x5642dc → 0x565e04` | `+0x16e4=frame`; cast pointer `+0xe8`; exception destructor/Unwind uçları içerir. |
| Kök container düzeni | `0x565e04 → 0x56643c` | Frame ve çocuklar; `+0x11f4/+0x1240` AbsContainer vektörleri burada oluşturulur. |
| Scroll koleksiyonu/stili | `0x56643c → 0x5674fc` | `+0x16e0=manager`, `+0x16e4=frame`, önceki container vektörleri; ScrollList vektörü `+0x124c`, iterator `+0x1258`, current scroll `+0xd8`. |
| Çocuk kontroller/scroll kuyruğu | `0x5674fc → 0x568650` | Current scroll `+0xd8`, kullanılabilir ölçü `+0x128c`, frame ve önceki vektör/iterator nesneleri; dış döngüyle bağlantılıdır. |
| AutoSearch sonuç panelleri | `0x568650 → 0x570ab0` | Frame/çocuk durumu; cast pointer `+0xa8`, geçici TextBox vektörü `+0x12b4`; 13 sonuç/kaynak etiketi. |
| ManualSearch sonuç panelleri | `0x570ab0 → 0x579250` | Frame/çocuk durumu; cast pointer `+0x64`, geçici TextBox vektörü `+0x1330`; aynı 13 etiket. |
| Normal cleanup | `0x579250 → 0x5792b8` | `+0x124c/+0x1240/+0x11f4` yaşayan vektörler, kayıtlı ra/s8/s1/s0; caller'a return. |
| Exception cleanup | `0x5792b8 → 0x579360` | EH `a0/a1` girdileri, `+0x16c0/+0x16bc` exception bağlamı, yaşayan vektörler; `_Unwind_Resume`. |

Orta iki faz **aynı dış döngüyü paylaşır**: `0x5664c0 → 0x568608` ilk iterator testi/kuyruğa, `0x568648 → 0x5664c8` bir sonraki scroll'a gider. Bunları sırayla çağrılan bağımsız fonksiyonlar gibi modellemek yanlıştır. Sonuç fazlarının hata yolları `0x5792c4` ortak exception cleanup'ına çıkar. LSDA'dan gelen implicit exception kenarları bu manifestte çözülmedi.

Stack okuma listesi bir bağlam üst kümesidir. `linear_reads_before_first_direct_store_candidates` alanı yalnız doğrusal aday taramasıdır; path-sensitive liveness değildir. `Rect::set`, vektör constructor'ı ve diğer pointer-output çağrılarının yazdığı stack nesneleri ayrıca korunmalıdır. Fragment C, üretildiğinde tam gövde C sayımını değiştirmez.

Kullanılan beceri: reverse-engineer-anything. Statik yorum, doğru C++ prototipi, indirekt vtable hedefleri, aktif marka/dil ve fiziksel TV davranışı ayrı belirsizliklerdir.
