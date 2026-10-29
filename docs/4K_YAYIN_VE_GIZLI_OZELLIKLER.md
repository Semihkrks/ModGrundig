# 4K yayın →1080p ve kayıp kanal araştırması

## 30 Ekim: görüntü hatası, ses mute koşulları ve dönüşüm deneyi

Yeni odak tarama/listelenme değildir: kullanıcı kanalın V7.8'de bulunduğunu,
ancak iki ses seçiminde de görüntü/ses olmadığını bildirmiştir. USB kayıt henüz
denenmemiştir; canlı servis/PID/decoder hata ölçümleri bulunmaz.

- [Ses yolu](4K_SES_YOLU.md): video init dönüşü kontrol edilmeden ses başlatma
  sürer. Fakat mute2'nin kaldırılması video/readiness/sync koşullarına bağlanır.
  Başarısız video ile sesin sessiz kalması, iki ses codec'inin de desteklenmediği
  sonucunu tek başına vermez. Beş yeni odaklı gövde, dört yeni C çıktısı,
  22 codec dönüşüm satırı ve11 host mantık vakası belgelendi.
- [Görüntü sınırları](4K_VIDEO_SINIRLARI.md): sekiz C çıktısı, beş yeni odaklı
  gövde ve üç önceki assembly hedefinin yeniden incelemesi. Gerçek init dönüş
  kapıları, R2 mikrokod başlık kontrolü ve SPS bellek hesabı çözüldü.
  Örnek UHD girdide yaklaşık74–92MiB hesabı çıkar; **aktif DTV tahsisi ve bu
  hesabın gerçek çağrı yolu henüz bağlanmadı**. Paket varsayılanındaki30MiB'den
  doğrudan kesin yetersizlik veya güvenli yeni MMAP boyutu çıkarılmaz.
- DivX koşullu hata8 yolu bulundu; TRT UHD'de bayrak değeri, tetiklenme ve hata
  tüketicisi doğrulanmadı. Genel bir HEVC/4K kilidi diye patch edilmedi.
- [Host dönüşüm deneyi](4K_FHD_DONUSUM_DENEYI.md): sentetik4K Main10+AC-3,
  FHD H.264+AAC'ye çevrildi ve hata/sessizlik kontrolleri geçti. Bu, bilgisayar
  üzerinde bir deneydir; TV'nin canlı uydu akışını dönüştürmesi değildir.

Bu aşamada **yüklenebilir yeni 4K firmware yaması çıkarılmadı**. Kaynaklar ve
önceki paketler korunur; zorla success/unmute veya bellek haritası değişikliği yoktur.
[Aşama3 kapsam kaydı](../analiz/native-4k/stage3-results.json).

**27 Ekim son cihaz geri bildirimi:** kullanıcı V7.8'de **TRT Ultra HD** adlı kanalı bulduğunu, görüntü olmadığını ve Dolby/HE-AAC olarak belirttiği iki ses seçeneğini ayrı ayrı seçtiğinde ikisinde de ses çıkmadığını bildirdi. [Ayrı cihaz gözlem kaydı](../analiz/native-ui-candidate/v7.8-tv/device-feedback.json). Böylece önceki “hiç listelenmiyor” gözlemi bu deneme için aşıldı; keşfin default transponder yamasından kaynaklandığı, doğru/güncel servisin alındığı veya canlı PID/codec değerleri henüz kanıtlanmadı. Aşağıdaki ilk tarama aşaması tarihsel kapsamıyla korunur.

Yeni öncelik yalnız ölçekleme değildir: geçerli video/ses/PCR PID'lerinin gerçek akışa bağlanması, A/V başlatma ve mute durumları, ardından HEVC profil/bit derinliği/UHD50 ve ses decoder çıktıları ayrılmalıdır. EPG/akış bilgisi veya ses menüsünde iki seçeneğin görünmesi metadata okunmasını gösterebilir; sıkıştırılmış görüntü/sesin çözüldüğünü göstermez.1080p ölçekleme çözülmüş kareden sonra gelir. Mevcut firmware incelemesinde `_GetAvInfoFromProgramInfo0x2d4d6a08` video ve seçilen ses PID/codec alanlarını ayrı okur (`0x2d4d6a38`, `0x2d4d6a9c`, `0x2d4d6aac`); `AVMonitor::DoStart0x2d9d7e40` demux PID filtreleri ve SetMuteFlag/Get_mapi_audio yollarını içerir. Bunlar gerçek cihaz dönüşleri olmadan hatanın nedeni olarak ilan edilmez. [Kaynak assembly ve GOT adları](../analiz/native-4k/decoder-stage2/playback-evidence.json). Bu devamda yeni decompile veya firmware değişikliği yapılmadı; mevcut iki gövde yeni gözlemle yeniden değerlendirildi.

27 Ekim 2026. Kullanıcı modlamadan önce de hiçbir4K kanalın listede bulunmadığını, yalnız otomatik arama yaptığını ve V7.7'nin TV'de sorunsuz çalıştığını bildirdi. Bu gözlemler4K'nın yazılımla engellendiğini veya donanımca çözülebildiğini kanıtlamaz. İnceleme `reverse-engineer-anything` becerisiyle yerel firmware üzerinde yürütüldü. Gömülü program/update komutu veya donanıma yazma çalıştırılmadı; orijinal imajlar ve çalışan V7.7 paketi değişmedi. Küçük decoder/service gate parçaları kontrollü bellekle sınandı. Doğrudan Ghidra/assembly/Unicorn kanıtı REA Evidence veya fiziksel4K TV başarısı değildir.

## En somut bulgu: eksik güncel RF transponder

`08_APP/defaults/frequency_tables.tar.gz` içindeki tek dosya `satellite_list.xml`, Türksat42°E için79 transponder taşır. Eski10980V/12500 satırı bulunur;11767MHz hiçbir polarizasyonda yoktur. TRT'nin27 Ekim2026'da kontrol edilen [resmî SSS kaynağı](https://www.trt.net.tr/corporate/faq/2), TRT4K için **Türksat4A,11767MHz,V/Dikey,15000,FEC3/4,DVB-S2** bildirir;50p HEVC çözme gereğini de belirtir. Eski üretici yardım sayfalarında farklı tarihli frekanslar bulunduğu için yayıncının güncel kaynağı esas alındı. [Arşiv ve RF tuple kanıtı](../analiz/native-4k/transponders/turksat-current-tp-audit.json).

Bu eksiklik otomatik taramanın kanalı kaçırabilmesi için somut bir adaydır; fiziksel sinyal ve cihazdaki mevcut SAT veritabanı görülmeden tek kesin neden ilan edilmedi. Güncel transponderle manuel uydu araması eski varsayılan listeyi kullanma ihtimalini ayırır. Aktif LNB/DiSEqC ayarı değiştirilmeden uygulanmalı; mevcut kanal listesi silinmez.

## Güncellenen veri ve neden yeni firmware dağıtılmadı

**Sonraki kullanıcı isteğiyle paketleme:** kullanıcı manuel aramayı henüz yapamayacağını belirterek mevcut değişikliği RAR olarak istedi. Bu açık istek üzerine [V7.8 varsayılan transponder test RAR'ı](UI_NATIVE_V78_TRANSPONDER.md) üretildi ve çevrimdışı doğrulandı. Bu, aşağıdaki canlı DB sınırlamasını çözmez; decoder kilidi açılmaz, üretici sürümü yükseltilmez. Aşağıdaki paket üretilmeme gerekçesi ilk analiz kararının kaydıdır; yeni paketleme durumu [V7.8 faz kaydındadır](../analiz/native-ui-candidate/v7.8-tv/phase-results.json).

`native_ui_v78_transponder.py`, orijinal hash sabitlenmiş arşivde yalnız11767V/15000/DVB-S2/8PSK/FEC3/4 transponderini ekler; Türksat sayısı79→80 olur. Diğer tüm transponderler/uydular, tar dosya sahibi/izin/zamanı, header/trailer düzeni ve gzip header korunur.6 test geçti. `v7.8-tv/overlay` ayrı veri adayıdır; V7.7'nin15 overlay dosyası ve tüm UI/native kodları byte byte aynıdır. [Aday kapsamı](../analiz/native-ui-candidate/v7.8-tv/STATUS.md).

Dört gerçek tüketici fonksiyonu incelendi: libmsrv_dvbs_customer `LoadSatelliteListfromXML0x2e9665a8`, `ResetSatDB0x2e9666dc`, `ReloadSatList0x2e967260`, `Init0x2e9674d4`. Geçerli SAT DB bulunduğunda Init mevcut SAT/TP kayıtlarını okuyup döner; yeni tar/XML birleştirmez. ResetSatDB ise ana/yedek SAT depolarını temizleyip yeniden kurar. Bu nedenle sırf varsayılan arşivi değiştiren yeni firmware mevcut listeyi otomatik düzeltir diye sunulmadı, fabrika sıfırlaması yapılmadı veya önerilmedi; ilk analiz aşamasında BIN/RAR üretilmedi. Koruyucu, artımlı canlı DB migration'ı henüz uygulanmadı. [Tüketici gövdeleri](../analiz/native-4k/transponders/consumer-query/summary.json).

## Tarama ve decoder birbirinden ayrıldı

17 tuner/servis fonksiyonu decompile edildi. Customer_UpdateServiceType0x2e192540, HEVC service_type0x1f'yi TV1'e eşler. Gerçek vtable+0x2bc kapısı `_IsSpecificSupport0x2e19784c` satellite mode2 için maske0x8242140e içindeki bit31 üzerinden0x1f'yi kabul eder; bu yolda4K enable flag'i sorgulanmaz. PMT stream_type0x24, `_UpdateVideo0x2d53bf88` içinde video PID ve iç VIDEO_TYPE5 olarak kaydedilir. Sınırlı incelenen filtrelerde güvenilir bir4K yasaklama yaması bulunmadı; bazı genel alan/LCN/operator anlamları çözümsüz bırakıldı. [Tuner raporu](../analiz/native-4k/tuner/findings.md), [17/17 sonuç](../analiz/native-4k/tuner/results.json).

Decoder tarafında ilk aşamada21 gövde ve9 kontrollü switch/capability/pixel-rate testi incelendi. HEVC HWInit→VDEC16→kind7→EVD backend yolu gerçek kod içerir; API yalnız isim değildir. CheckCaps16=false sonucu ve piksel oranı bayrağı tek başına donanımın HEVC/UHD çözmediğini kanıtlamaz; Init16'yı kabul eder. Fiziksel3840×2160/50p, Main10, referans kare/DPB ve firmware microcode kapasitesi doğrulanmadı. [İlk decoder raporu](../analiz/native-4k/decoder-findings.md).

## İkinci aşama: kayıtlı HEVC'den oynatıma kapanan bağlantı

Altı yeni playback gövdesinin orijinal assembly'si incelendi; bu alt görevde yeni decompile yapılmadı. `_GetAvInfoFromProgramInfo0x2d4d6a08`, DB video codec alanı`+0x19` değeri5'i case`0x2d4d6cf0` üzerinden AVInfo7'ye çevirir. `_UpdateAV0x2d4d6e28` aynı info'yu `AVMonitor::Start0x2d9da078`'e verir. `AVMonitorMain0x2d9d9484` event1'i `DoStart0x2d9d7e40`'a iletir; SDK SetVdecType çağrı noktası`0x2d9d9308` info codec'ini7 olarak alır. Önceki aşamadaki SDK7→VDEC16→EVD yolu ile birleşir. Arada farklı codec numaraları bulunması ret değildir; farklı enum alanlarıdır.

**11 kontrollü vaka geçti:** sekiz giriş video türü, geçersiz video PID ve iki DoStart kontrol bayrağı. Tür5 geçerli PID ile7 olur; PID0x1fff olduğunda0 olur. Bu son koşul tüm codec'lere uygulanan geçerli video PID'si koşuludur; gerçek TRT kaydında bu hatanın oluştuğu henüz gözlenmedi. `CheckVideoStatus0x2d9d4c30` frame/freeze denetler; incelenen gövdede kanal DB'sinden4K kayıt silme yoktur. [Adresli playback raporu](../analiz/native-4k/decoder-stage2/findings.md), [11 vaka ve kaynak hash'leri](../analiz/native-4k/decoder-stage2/playback-evidence.json).

## Orijinal servis ve liste kapılarının kontrollü sınaması

`scripts/test_4k_native_service_gates.py`, gerçek müşteri classifier ve `_IsSpecificSupport` talimatlarını tek çözümlenmiş vtable slotu üzerinden sentetik nesnede yürütür. Satellite mode2 ve operatör alanı0/8 için servis1,0x19,0x1f kabul edilir;0x1f TV1/alt tür0 olur. Mode1+operatör8'de0x1f gerçekten reddedilir; bu farklı koşul negatif kontrol olarak korunur. Parametre alanlarının canlı TV'deki değerleri sentetik testten çıkarılmaz.

`_IsProgramListable0x2d50280c`, DB`+0x15/+0x11/+0x0f/+0x10` bayraklarına bakar. Aynı bayraklarla codec0/1/5 aynı sonucu verir. **Toplam23 sınırlı vaka / iki test metodu geçti.** Bu fonksiyonda HEVC ayrımı yoktur; bayrakların başka yollarla değiştirilemeyeceği iddia edilmez. Kaynak ELF hash'leri sabitlenir; beklenmeyen kod/dış çağrı başarısız sayılır. Tam uygulama, parser yaşam döngüsü, tuner, yayın TS'si ve donanım çalıştırılmaz. [Vaka sonuçları](../analiz/native-4k/service-gate-tests.json).

## İkinci aşama: kanal numarası ve kayıt sonrası görünürlük

İki modülde12/12 yeni C çıktısı ve üç tam assembly gövdesi incelendi. Assembly gövdelerinin ikisi yeni hedef, `0x2d53db70` ise ilk tuner aşamasında decompile edilmiş gövdenin yeniden kontrolüdür: **14 yeni farklı fonksiyon**. `_AddCommonProgramInfo0x2d53eda4`, MW`+0x1c` alanını DB`+0x34`'e taşır; `GetByLcn0x2d50c488` bunu LCN olarak karşılaştırır. Böylece önceki alan belirsizliği kapandı. `_GetNextProgramInfo0x2d507238` için iki somut sanal hedef çözüldü: slot`+0x9c→_IsProgramListable0x2d50280c`, slot`+0xb8→Customer_IsMatchedProgramTypeByFilterLoopType0x2e172f44`. Tür/şifreli/şifresiz sorguları bulundu; bu hedeflerde HEVC codec ayrımı yoktur.

Gerçek `_CheckService0x2e191888` LCN0'ı bazı istisnalar dışında reddeder; mode1 ve operatör alanı4/7 için1024/1000 sınırları vardır. **Ancak eksik LCN başlangıçta0 olmaz:** `_ResetServiceInfo0x2d53d010`, `0x2d53d028`'de0xffff yazar. Customer reset0x2e19c210 bu temel reset'i çağırır, LCN'i0'a çevirmez. NIT/BAT eşleştirmeleri servis-ID'ye bakar; bulunamayan NIT eşleşmesi mevcut LCN'i korur. HEVC türüne özel LCN reddi bu gövdelerde bulunmadı.

**13 yeni kontrollü vaka geçti:** reset başlangıcı, dört NIT LCN durumu ve sekiz CheckService sınır/istisna durumu. Canlı TRT yayınının LCN'i, etkin ülke/operatör alanları ve bütün yazıcıların çağrı sırası bu testlerle ölçülmüş sayılmaz. [Görünürlük/LCN raporu](../analiz/native-4k/visibility/findings.md), [12 decompile +3 assembly kapsamı](../analiz/native-4k/visibility/results.json), [13 vaka](../analiz/native-4k/visibility/lcn-evidence.json).

## Parser nesnesinin gerçek oluşturulması

Üç modülde beş yeni hedef incelendi:3/3 decompile ve iki ek assembly gövdesi. Player `_DoInit_EpgAndCmdbAndSiParser0x2d4d32e0` ve `EnableVideoOut0x2d4d3990`, `player+0xfc` boşsa doğrudan CustomerC1'i çağırır; temel/customer seçen4K flag dalı yoktur. CustomerC1`0x2e1a7c44`, temel yapıcıdan sonra`0x2e1a7cb8`'de müşteri vptr'si`0x2e1e1420`'ı yazar. Bu vptr önceki0x1f destekli classifier/gate relocation'larıyla eşleşir.

**Tarama bağlantısı da kanıtlandı:** `libmsrv_dvbs_customer.so:DoScanInit0x2e9623a8`, `0x2e96242c`'de aynı`player+0xfc` parser'ını okur, `0x2e96243c`'de stack argümanı olarak iletir. Sanal`+0x12c` çağrısı`0x2e96245c`, vtable kaydı`0x2e99d3b4` üzerinden `SetInitData0x2e970748`'e gider. Alıcı`0x2e970764`'de argümanı okur ve`0x2e970798`'de `scanner+0x134`'e yazar. Dolayısıyla yalnız oynatma tarafında müşteri sınıfı varlığına dayanılmadı; incelenen uydu başlangıcı aynı nesneyi kullanır. Dolu player üyesinin bütün olası yazıcıları ve cihazdaki canlı nesne/mod izi henüz tamamlanmadı. [Factory/tarama raporu](../analiz/native-4k/parser-factory/findings.md), [Adresli bağlantılar](../analiz/native-4k/parser-factory/results.json).

## İkinci aşamanın test ve kapsam ayrımı

| Alt görev | Yeni farklı fonksiyon | Yeni decompile | Yeni yalnız assembly |
|---|---:|---:|---:|
| Parser oluşturma ve uydu tarama köprüsü |5|3|2|
| Kayıt/listelenebilirlik ve LCN |14|12|2|
| DB codec→AVInfo→SDK oynatım aktarımı |6|0|6|
| **Toplam, dört özgün modül** |**25**|**15**|**10**|

Buna ek eski`0x2d53db70` assembly üzerinden yeniden kontrol edildi; yeni hedef olarak sayılmadı. Factory alt raporu altı seçilmiş statik çağrı noktasını; görünürlük alt raporu bir reset GOT çağrısı ve iki liste sanal hedefini kaydeder: **dokuz seçilmiş çözümlenmiş çağrı/dispatch bağlantısı**. Bu sayı bütün grafiğin çağrı sayısı değildir; playback veri/event zinciri ayrıca adresli olarak belgelenmiştir. Player`+0x710/+0x8c8/+0x840`, query0xc`+0xd0`, DB provider alt yolları ve favori nesnesi gibi açık bağlantılar alt raporların takip listelerindedir; çözülemeyen bütün dolaylı çağrıların eksiksiz sayıldığı iddia edilmez.

Playback11 + servis/liste23 + LCN13 = **47 kontrollü vaka geçti**. Bunlar fiziksel yayın/TV testleri değildir. Aynı eski fonksiyonun yeni bir vaka ile sınanması yeni decompile sayılmadı. İlk aşamanın decoder9 ve transponder6 vakaları bu47'ye dahil değildir. Bu aşamada gerçek TV'ye yazılmadı, orijinal ELF/BIN/RAR dosyaları değiştirilmedi. Çalışan V7.7 RAR SHA256 yeniden kontrolünde`725b6e1b39d8bf593bce50034d02a4fe83b2fcc7a5d9b72893cc7bd99ce593b7` olarak korundu.

[Tekilleştirilmiş ikinci aşama fonksiyon envanteri, kaynak hash'leri ve açık bağlantılar](../analiz/native-4k/stage2-results.json). Tekrar incelenen gövde ilk tuner C çıktısıyla adres/modül üzerinden karşılaştırıldı; yeni fonksiyon sayısından çıkarıldı.

Ölçekleyicide `mapi_video_base::SetWindow0x2cbb4c94` SetXCWindow'a gider; AVMonitor_SetWindow0x2d9d10f8 çözülmüş görüntü bilgisini GetDispInfo üzerinden alır.8 ilgili fonksiyonun assembly'si ve doğrudan GOT çağrıları kaydedildi. `Enable4K2KMode0x2caf831c` ise PNL_SkipTimingChange, PNL_ChangePanelType ve XC_ChangePanelType çağırır: bu panel/çıktı seçimi yoludur; HEVC çözme kilidi olarak değiştirilmedi. Prescaling getter/setter0x2cbaecf8/0x2cbaecf0 yalnız obje+0x2e byte'ını okur/yazar; UHD desteği kanıtı değildir. [Scaler assembly](../analiz/native-4k/scaler/static-functions.json), [GOT kanıtı](../analiz/native-4k/scaler/enable4k-got-calls.json).

## Diğer özellikler

23 yapılandırma dosyası,287 makro ve235 INI kaydı incelendi;4 ayrıştırma kontrolü geçti,23 orijinal hash korundu. Derleme kaydında PVR/kayıt, EPG, altyazı, CEC/ARC ve bazı medya codec seçenekleri var. Bunlar cihazda yeni açılmış özellikler sayılmadı. PIP/çift tuner/ağ/Bluetooth ve4K backend seçenekleri kapalı metadata içerir; yalnız menü/flag değiştirerek eksik donanım yaratılmaz. HDMI4K EDID ve çok modelli panel dosyaları RF çözme kanıtı değildir. [Yapılandırma/özellik raporu](../analiz/native-4k/config/findings.md).

## Sonraki doğrulama

Önce mevcut listeyi koruyan manuel RF/kanal ekleme aramasıyla11767V/15000/DVB-S2/FEC3/4 ölçülmeli. Aktif LNB/DiSEqC düzeni korunmalı; fabrika sıfırlaması gerekmez. Sinyal kalitesi/kilit, bulunan kanal sayısı, TRT4K kaydı ve varsa hata/ses-görüntü sonucu ayrı kaydedilmeli:

| Gerçek sonuç | Bir sonraki kanıt ihtiyacı |
|---|---|
| Kilit yok / kalite0 | Anten güzergâhı, tuner/demod ve RF parametreleri; servis filtresi henüz test edilmiş olmaz. |
| Kilit var, TRT4K listede yok | Gerçek SDT/PMT/service-ID ile etkin tarama/operatör/LCN değerleri; yayının hangi koşulda elendiği. |
| Kanal ve iki ses seçeneği listede, ikisinde de ses/görüntü yok — son kullanıcı gözlemi | Canlı servis kimliği/PID/PCR ve demux akışı; A/V başlatma ve mute durumları; ses/video decoder sonuçları. Yalnız downscale sorunu denemez. |
| TRT4K kaydoldu, ses var/görüntü yok | Geçerli video PID, VDEC init/sequence hata durumu, Main10/UHD50/DPB kapasitesi. |
| Kanal ve görüntü var | Gerçek çözülmüş boyut/fps ve1080p ölçekleme; kararlılık testi. |

İncelenen gövdelerde güvenilir bir HEVC kilit açma koşulu bulunmadığı için rastgele flag/switch patch'i üretilmedi. Açık dolaylı bağlantılar ilgili alt raporlarda adres/slot ile izlenir. Bu aşama gerçek4K→1080p oynatımını garanti etmez. [Merkezi ölçülebilir kapsam](../analiz/native-4k/phase-results.json).
