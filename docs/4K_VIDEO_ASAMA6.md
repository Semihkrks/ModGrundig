# HEVC görüntü: başlatma kapıları, ölçekleme ve bellek sınırı

31 Ekim 2026. **Görüntü hedefi sağlanmadı; yeni yüklenebilir firmware üretilmedi.**
İki araştırma alt ajanının bağımsız bulguları ana ajan tarafından yerel kaynaklarla
birleştirildi. `reverse-engineer-anything` kullanıldı. Orijinaller, V7.9 UI,
önceki ses-test paketi ve TV değiştirilmedi. V7.10 bu çalışmaya dahil değildir.

Bu rapor önceki [video sınırları](4K_VIDEO_SINIRLARI.md) ve
[ses testi cihaz sonucu](V79_SES_TEST_REHBERI.md) üzerine eklenir. Bulunan
koşulların cihazda tetiklendiği varsayılmaz. Önceki ses yamasının TRT Ultra HD'de
sonuç vermediği, normal HD sesinin çalıştığı kullanıcı gözlemi korunur.

## Ölçülen kapsam

| İşlem | Gerçek kapsam |
|---|---:|
| Seçilmiş tam assembly gövdesi |13; önceki hedefler de içerir|
| Bu aşamada Ghidra C çıktısı |4/4 tamamlandı|
| Normal MSLIB ELF dynsym import taraması |167; parse hatası0|
| Sınırlı native framebuffer boyut tablosu vakası |20|
| Dış auth sorgusu mock edilmiş native kontrol akışı vakası |5|
| Donanım / gerçek yayın / tam firmware testi |0|
| Yeni firmware yaması veya paketi |0|

13 gövde yeni keşfedilmiş13 fonksiyon veya tam call graph anlamına gelmez.
Özellikle `_VPU_EX_GetFrameBufferDefaultSize`, önceki aşamada da incelenmişti.
25 kontrollü vaka TV'de UHD decode başarısı değildir.

[Yeniden üretici](../scripts/audit_hevc_video_stage6.py),
[hash/adresler ve vaka sonuçları](../analiz/native-4k/video-stage6/results.json),
[Ghidra kapsam kaydı](../analiz/native-4k/video-stage6/ghidra-v1/summary.json).
Kaynak VDEC SHA256:
`215c0a86cdd9fd579655da4752e0a5c7822eb3210e768ca63b86859683c9c02b`.
Ghidra mevcut projede `-noanalysis -readOnly` kullanır; geçici metadata atılır.
Bu sonuçlar doğrudan Ghidra/assembly/Unicorn kanıtıdır, REA Evidence değildir.

## 1. HEVC başlatma kapısı ve DivX bayrakları ayrı

Önceki `MDrv_HVD_EX_Init:0x2d602190` C çıktısı,
`_MDrv_HVD_AUTH_IPCheck(*param_3)` başarısızsa **2** döndüğünü zaten gösteriyordu.
Bu aşamada auth gövdesi **`0x2d6343e0`,572 bayt** olarak çıkarıldı:

- İç decoder türü7 için ana sorgu `MDrv_AUTH_IPCheck(0x4b)` olur.
- Ana sorgu1 ise `0x2d73e804` başlatma baytı1 yapılır.
- Ardından `0x55` ve `0x56` sorguları isteğe bağlı DivX HEVC4K/1080 destek
  bayraklarını ayarlar. İkisi de başarısız olsa bile ana HEVC auth yolu1 döner.
- Ana sorgu başarısızsa0 döner; önceki `_HVD_EX_Init_:0x2d634374` içindeki
  aynı global bayt kapısıyla ilişki böylece açıklanır.

[Yeni C](../analiz/native-4k/video-stage6/ghidra-v1/2d6343e0.c),
[önceki gerçek init çağırıcısı](../analiz/native-4k/video-stage3/ghidra-v1/2d602190.c).
Beş native vakada ana sorgu0; ana sorgu1 ve dört opsiyonel kombinasyon sınandı.
Auth backend sentetik GOT hedefinde durduruldu; cihazın auth verileri/anahtarları
okunmadı veya sorgulanmadı. SP ve kullanılan callee-saved register'lar kontrol edildi.

**Cihazdaki `0x4b` sonucu bilinmiyor.** Bu nedenle bu kapının TRT'deki arızanın
nedeni olduğu veya atlanırsa donanımın UHD çözeceği söylenemez. Auth sonucu
zorlanmadı; lisans/anahtar değişikliği yapılmadı.

## 2. Kare hızı hatası bulundu, canlı DVB'ye etkisi kanıtlanmadı

`MDrv_HVD_EX_GetFrmRateIsSupported:0x2d5f22a0` context `+0x13d` byte'ını okur.
`_MApi_VDEC_EX_V2_GetErrCode:0x2d64b230`, HVD hata sonucu0 ise bu getter'ı
`0x2d64b4dc/0x2d64b4e0` üzerinden çağırır. False ise context hata alanına
**`0x01000003`** yazar (`0x2d64b4f4..0x2d64b504`). Driver hata8 ise
**`0x01000004`** olur. Başarı dönüşü1, ayrı `*out` hata koduyla karıştırılmaz.

[C çıktı](../analiz/native-4k/video-stage6/ghidra-v1/2d64b230.c).
Decompiler `Type propagation algorithm not settling` uyarısı verir; bu sonuç
parametre isimlerinden değil, pinned yükleme/çağrı/yazma talimatlarından alınır.

167 normal `07_MSLIB/**/*.so*` ELF dynsym'inde GetErrCode dış importu yalnız
`libvdplayer.so` içindedir. Bu sınırlı negatif arama dlsym, hesaplanan function
pointer, yerel çağrı veya başka isimli dosyaları kapsamaz.

- Media `msAPI_VDPlayer_CheckFatalError:0x2dad701c`, EX_GetErrCode çağrısı
  `0x2dad7040` ve hata `0x01000003` için özel karar içerir.
- SDK `GetControl:0x2cba4e10` yalnız command8→API0x1005, diğerleri→0x1000
  çevirisini yapar. Genel GetErrCode aktarımı değildir.
- `MW_DTV_AVMonitor::VDEC_EventCb:0x2d9d7364`, argümanları yer değiştirerek
  `DoSetMode:0x2d9d6d58`'e tail-call yapar; hata kodu callback'i değildir.
- DVB `DoMonitor:0x2d4fed30`, SDK GetErrCnt sonucunu `0x2d4ff600` çağrısından
  alır ve seçilmiş blokta printf argümanına taşır (`0x2d4ff6dc`). Bu blokta
  hata koduna göre HEVC reddi veya unmute kararı görülmedi.

Kaynak/gövde hash'leri ve bu dört tam assembly dosyası
[aşama verisinde](../analiz/native-4k/video-stage6/results.json) bulunur.
**Medya oynatıcı hata dalını yamalamanın TRT canlı yayınını düzelteceği kanıtlanmadı.**

## 3. Dynamic scaling çağrısı DPB küçültme çözümü olarak doğrulanmadı

`_MApi_VDEC_EX_V2_SetDynScalingParams:0x2d651ad8` HVD yolunda pointer dönüşümü
ardından `MDrv_HVD_EX_SetDynScalingParam:0x2d5f6114` çağırır. Driver geçerli
stream/pointer/length koşullarından sonra ilk byte'ı
`HAL_HVD_EX_SetCmd(stream,0x2020b,byte)` olarak iletir. Bu gövdede çözünürlük,
SPS veya referans framebuffer boyutu yeniden yazılmaz.

`MDrv_HVD_EX_SetExternalDSBuffer:0x2d5fe380`, en az `0xc00` bayt ister;
SHM `+0xd0c/+0xce4` adres/boyut alanlarını ve context `+0x614` kaydını yazar,
`SetCmd(stream,0x20221,1)` yollar. Referans framebuffer yeniden tahsis edilmez.
`MDrv_HVD_EX_SupportRefNumOverMaxDpbSize:0x2d5f3a80` ise yalnız
`SetCmd(stream,0x2021c,enable)` iletir.

[Driver DS C](../analiz/native-4k/video-stage6/ghidra-v1/2d5f6114.c),
[external DS C](../analiz/native-4k/video-stage6/ghidra-v1/2d5fe380.c).
Mikrokod komutlarının bütün iç davranışı çözülmedi. Bu wrapper'ların isimleri,
UHD referans karelerini FHD'ye indirerek çözme belleğini azalttıklarının kanıtı değildir.
Dolayısıyla bu seçenekleri açan yeni firmware yapılmadı.

## 4. Belleği aynı adreste artırma seçeneği geçersiz

Hash ile sabitlenen paket `09_CONFIG/mmap.ini` değerleri:

| Alan | Bayt / adres |
|---|---:|
| MIU0 toplamı |`0x10000000` =256MiB|
| VDEC framebuffer başlangıcı |`0x0e19a000`|
| Framebuffer boyutu |`0x01e00000` =30MiB|
| Bitiş, exclusive |`0x0ff9a000`|
| Aynı adresten DRAM sonuna kadar kalan ek alan |`0x66000` =408KiB|

Bu nedenle örneğin74–92MiB alanı aynı başlangıç adresine vermek paket haritasında
DRAM sınırını aşar. Bu hesap **aktif TV bellek ölçümü veya kesin UHD kapasite
tespiti değildir**; başka bölümleri taşımak/yeniden kullanmak ayrıca bütün bellek
sahipliklerinin ve donanım adres kısıtlarının kanıtlanmasını gerektirir.

Önceki SPS hesabının bir çağırıcısı bulundu:
`MApi_VDEC_EX_V2_GetControl:0x2d652870`
→ `MDrv_HVD_EX_GetFbMemUsageSize:0x2d5f2754`
→ `_HVD_EX_DemuxTS_ParseHEVCSPS:0x2d633a20`.
**Bu, parser'ın gerçek DTV tahsis kararını verdiğini kanıtlamaz.** Özellikle
30MiB'nin canlı yayın için kesin yetersiz olduğu sonucuna bu bağlantıdan gidilmedi.

`_VPU_EX_GetFrameBufferDefaultSize` gerçek talimatları20 kontrollü enum
girdisiyle sınandı. Sonuçlar örneğin7/8→108MiB,16→160MiB içerir; bunlar bu
fonksiyonun kendi enum alanıdır. DTV codec7 veya API codec16 ile isim/numara
eşitliğinden dolayı eşitlenmez. Native tablo testi cihazın bu RAM'e sahip olduğunu
veya bu profili seçtiğini göstermez.

## Kalan zorunlu ayrım ve mevcut sonuç

| Açık konu | Neden gerekli? |
|---|---|
| Aynı canlı TRT servisi için video/audio/PCR PID ve akış |Liste/EPG bilgisi, gerçek payload geldiğini göstermez.|
| Ana HEVC auth sonucu ve gerçek VDEC init dönüşü |Init öncesi ret ile init sonrası SPS/kare hatasını ayırır.|
| İlk sequence/frame, firmware hata alanları ve seçili bellek |UHD50/Main10/DPB veya downstream display arızasını ayırır.|
| Erişilebilir, sınırlandırılmış tanı çıktısı |Varsayılan başlatıcı stdout/stderr'i `/dev/null`'a yollar; printf eklemek tek başına yetmez.|

Bu dört takip başlığı tüm çözülemeyen dolaylı çağrıların eksiksiz sayımı değildir.
Canlı değerler mevcut olmadığından hangi kapının TRT'de tetiklendiği bilinmiyor.
Bu aşama statik olarak **üç kestirme çözümü desteklemiyor**: medya hata kodunu
yok saymak, DS bayrağını açmak, framebuffer boyutunu tek satır artırmak.
Görüntüyü getiren değişiklik, tam donanım emülasyonu veya yeni TV test paketi yoktur.
