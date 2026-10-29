# Hızlı açılış: ayar var, doğrulanan güç yolunda etkin arka uç yok

29 Ekim 2026. **Hızlı açılış açılmadı ve bu özellik için firmware yaması üretilmedi.** Genel ayarlardaki satır ve kalıcı kullanıcı alanı gerçek; fakat incelenen çalışan güç yolu bu ayarı okumadan STR durumuna geçiyor. Menüde “açık” göstermek bu bağlantıyı kurmaz. Mevcut STR/suspend desteği ve ara fake-standby durum makinesi bulunur; bunlar kaldırılmış veya bozuk sayılmadı.

Kullanılan beceri `reverse-engineer-anything`. Bulgular doğrudan Ghidra statik sorgusu ve hash sabitli ELF bayt karşılaştırmasıdır; REA Evidence veya TV gözlemi değildir. REA'nın bilinen eski MIPS ABI sınırı nedeniyle yeniden kurulum denenmedi. Firmware, donanım komutu veya çıkarılan MIPS programı çalıştırılmadı.

## Kaynak ve yeniden üretim

| Kaynak | SHA-256 |
|---|---|
| Orijinal `dvbt_board` | `51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916` |
| V7.9 `dvbt_board` | `861d97c013c4d56e093a69cf779abfa6ea78e6c17233af5d6b2b3ba075b0b4ea` |
| `libmsrv_control.so` | `0b154eba8a18cda242d3a1efafb74ca576bfb35bf0c6b9be38fc13fe16e518ea` |
| `libmsrv_system_database.so` | `dbdef96fed7bd96d18b44c641203491649a04909d50aa8ecf8d7af4cf6fd4882` |
| `libmsrv_common_customer.so` | `394ee95f07383231c9cc1019d9d1fb8eb3c8309ae68fe2d3186ddf19c51dae39` |

[Bayt doğrulayıcı](../scripts/native_fast_boot.py) altı kritik APP aralığının V7.9'da orijinaliyle aynı olduğunu kontrol eder. Yanlış hash, eksik sembol ve dosya dışına taşan ELF aralığı kabul edilmez. Sonuç [byte-proof.json](../analiz/native-features/fast-boot/byte-proof.json), seçilmiş çağrı ve register bağlamları [static-edges.json](../analiz/native-features/fast-boot/static-edges.json) içindedir. Sorgular mevcut Ghidra projelerinde `-process -noanalysis -readOnly` ile yapıldı; her çalışmanın selection, C, JSON ve log dosyaları aynı kanıt dizininde saklandı.

## Menü → kullanıcı/fabrika veritabanı

`GeneralSettingsFrame` widget **56**, `this+0x260`, etiket getter noktası `0xd1b1cc`; olay handler'ı **`0xcf576c`**. [Önceki tam constructor kanıtı](bilgi-tabani/UI_GENERAL_COZUM.md) korunur.

| Nokta | Statik davranış |
|---|---|
| `0xd23a7c` | `GetFastBootMode()` sonucu combo nesnesinin `+0x264` seçim alanına yazılır. |
| `0xd23f68` | `ArTvConf_GetFastBoot()` sonucuyla widget flag **2** sıfır/bir yapılır. Bu işlev tek başına flag'e yeni bir anlam adı vermez. |
| `0xcf576c` | Seçimi `SetFastBootMode()` ile kaydeder. Getter sıfır değilse `0x1106` metinli bilgi popup'ı kurar; güç geçişini kendisi değiştirmez. |
| `0x53bf20 / 0x53bf80` | `GetFastBootEnabled / SetFastBootEnabled` DB sarmalayıcıları. |
| `0x523460 / 0x521d70` | `GetFactFastBoot / SetFactFastBoot` fabrika sarmalayıcıları. |
| DB `0x2e57865c / 0x2e584288` | `this+0x37de` kullanıcı baytını okur/yazar; setter `SaveUserGeneralSettings()` çağırır. |
| DB `0x2e573d64 / 0x2e57d0b4` | `this+0x110d0` alanının bit15'ini okur/yazar; setter `SaveFactoryTvConfigurationSetting()` çağırır. |
| DB `0x2e5786d8` | `IsFastBootInUse()` kullanıcı baytı sıfır değilse fabrika bit15'ini döndürür; aksi halde sıfır. |

C pseudocode'daki bazı sarmalayıcı prototipleri eksiktir; parametre aktarımı JSON'daki instruction/register bağlamıyla değerlendirilir. DB alanları kalıcılık kanıtıdır, cihazın güncel ayar değeri değildir. Orijinal **226 ELF** dinamik import envanterinde `IsFastBootInUse` import'u yok; `GetFastBootEnabled` import'u yalnız APP'dedir. Bu sayım vtable/dolaylı çağrıları veya bütün dahili kullanımları dışlayan tam çağrı grafiği değildir.

## Gerçek standby ve açılma yolu

`PowerOnOffFrame::PowerOff=0xea019c`, durum **4** ve uyanma tamamlanmamışsa tuşu yok sayar. Durum **3** ise `CancelStandby()` yoluna gider. Diğer uygun yolda `StartStandby()` çağrılır; başarılı sonuçta ekran temizliğinden sonra `SuspendSystem()` çağrılır. Tarama, ASU/OAD ve PVR gibi mevcut koşullar bu kodda kalır.

`StartStandby=0x532f24`, `SetPowerState(instance,3,0)` çağrısını **`0x532fc0`** adresinde koşulsuz yapar. Bu önce AV'yi kapatan ara fake-standby durumudur. `SuspendSystem=0x532d8c`, **`0x532dcc`** çağrısında `SetPowerState(instance,2,0)` ister: `0x532dc4` instruction'ı `a1=2`, `0x532dc8` `a2=0` yükler. Bu kısa fonksiyonda hızlı açılış ayarına göre bir getter/branch yoktur.

`ArSrvPowerManager::SetPowerState=0x2df77fdc` gerçek bir durum makinesidir: durum **3** fake standby, **4** on, **2** STR. Durum2 isteği mevcut duruma göre `TaskFakeStandbyToSTR`, `TaskOnToSTR` veya `TaskBootingToSTR`, ardından `Suspend()` yoluna gider. Dolayısıyla yalnız “FakeStandby” adının bulunması hızlı açılışın etkin olduğunu göstermez.

Başlangıç tarafında `TaskBootingToOn=0x2df7703c` panel/hotel başlangıç koşullarını ve `EnableAV()` çağrısını içerir; incelenen gövdede fast-boot kullanıcı alanı kontrolü yoktur. `TaskFakeStandbyToOn=0x2df77720` ise DTV/ATV kanal geri dönüşü, panel/hotel ve `EnableAV()` işlemlerini içerir. Bu gerçek geçiş kodları, aşağıdaki legacy stub'lardan ayrı tutulur. `GetInstance=0x2df78254` yalnız singleton nesnesini kurar. Soğuk açılışın tüm bootloader/kernel/APP başlangıç sırası yeniden çözülmüş sayılmaz.

## Derleme sınırının kesin bayt kanıtı

| Fonksiyon | VA | 8 baytın anlamı |
|---|---|---|
| `MSrv_Control::Normal2FakeStandby` | `0x2ea92410` | `jr ra; nop` — geçiş yapmaz. |
| `MSrv_Control::FakeStandby2Normal` | `0x2ea92418` | `jr ra; nop` — geçiş yapmaz. |
| `MSrv_Control::FakeStandby2ScheduledEvent` | `0x2ea92428` | `jr ra; nop` — geçiş yapmaz. |
| `ArSrvPowerManager::FakeStandby` | `0x2df76494` | `jr ra; li v0,1` — yalnız başarı döndürür. |

İlk üçü `0800e00300000000`, sonuncusu `0800e00301000224` hex baytlarıyla doğrulandı. CONFIG/Flags içindeki `FAST_BOOT_ENABLE=0` ve `ACTIVE_STANDBY_MODE_ENABLE=0` bu bulgularla uyumlu **derleme metaverisidir**; bunları metin olarak değiştirmek kayıp derlenmiş davranışı geri getirmez.

Bu nedenle kullanıcı/fabrika baytını zorla açma, satırı etkin gösterme, `SuspendSystem` atlama veya güç durumunu değiştirme yaması yapılmadı. Seçilen derlenmiş yolda menü ayarını çalışan hızlı açılışa bağlayan semantik yol doğrulanmadı. STR'yi atlamak güç yönetimi, ses/panel, zamanlanmış işlemler ve bekleme tüketimini değiştirebilir; böyle bir değişiklik bu çalışmanın güvenli leaf yaması değildir.

## Doğrulama ve sınır

`python -X utf8 scripts/native_fast_boot.py` tamamlandı; dört özgün ELF ve V7.9 kimliği, üç return-only stub, başarı-only stub ve altı APP aralığı doğrulandı. Yedi dar Ghidra sorgusunda **24/24 fonksiyon** tamamlandı. `python -m unittest discover -s scripts -p test_native_fast_boot.py -v`: **6/6 geçti**; gerçek kaynak, yanlış kimlik, bozuk ELF tablo sınırı, BSS/dosya aralığı ve eksik sembol denetlendi. Python derleme kontrolü de geçti.

Firmware build/TV testi yapılmadı; yeni hızlı açılış patch'i yoktur. Beklemeden dönüş ile AC kesildikten sonraki soğuk açılış farklı yollardır. Hiçbir açılma süresi, hız artışı veya bekleme tüketimi ölçülmedi; bu araştırma bunlara dair performans sonucu vermez.
