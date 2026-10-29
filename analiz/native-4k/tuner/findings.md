# 4K yayın — tuner ve kanal filtreleri

27 Ekim 2026. Dört özgün modülde17 hedef fonksiyon incelendi;17/17 C çıktısı alındı ve kaynak hash'leri doğrulandı. Yalnız statik analiz yapıldı; firmware programı çalıştırılmadı, firmware/paket değiştirilmedi. Merkezi kayıt: [results.json](results.json). Çıktılar doğrudan Ghidra sorgularıdır, REA Evidence olarak sunulmaz.

**Bu yolda açılacak kanıtlanmış bir HEVC/UHD kanal engeli bulunmadı.** Mevcut müşteri uyarlaması HEVC servis türünü TV olarak sınıflandırıyor; PMT ayrıştırıcısı HEVC video PID'sini alıp codec5 olarak sonraki katmana iletiyor. Bu davranış gerçek4K/Main10 çözme veya1080p'ye küçültme desteğini kanıtlamaz.

İkinci aşama ek kanıtları: [müşteri parser'ının oluşturulması ve uydu taramasına aynı pointer'ın aktarılması](../parser-factory/findings.md), [LCN alanının ve görünürlük filtrelerinin çözümü](../visibility/findings.md), [DB5→AVInfo7→SDK/VDEC16 yolu](../decoder-stage2/findings.md). Aşağıdaki ilk aşama sınırları canlı cihaz doğrulaması anlamına gelmez.

| Kod yolu | Kanıtlanan davranış |
|---|---|
| `libmsrv_dvb_customer.so`, `_UpdateServiceType` `0x2e192540` | Servis0x1f, `0x2e192668` case gövdesinde internal TV türü1 / alt tür0 olur. [C](customer/2e192540.c), [case assembly](service-case-assembly.json). |
| Customer vtable `0x2e1e1418`, address point `0x2e1e1420` | Slot+0x1c0, `0x2e1e15e0` dinamik relocation'ıyla müşteri `_UpdateServiceType` fonksiyonuna bağlıdır. Slot+0x1b8 özgün `_UpdateVideo` fonksiyonuna gider. Bu statik sınıf bağlantısıdır; canlı nesne izi yoktur. [Bağlantılar](customer-vtable-bindings.json). |
| `libMStarSDK_customer.so`, PMT `ParseSection` `0x2dca7ed8` | `0x2dca8318` karşılaştırması stream0x24'ü video yolu `0x2dca8508`'e alır; en fazla üç video adayı içinde stream türü ve13 bit PID saklanır. [C](pmt/2dca7ed8.c). |
| `libmsrv_dvb.so`, `_UpdateVideo` `0x2d53bf88` | `0x2d53c01c` stream0x24 dalı, `0x2d53c100` codec5 yazmasına gider; PID korunur. Bu gövdede3840/2160 veya çözünürlük üzerinden reddetme yoktur. Çoklu video adaylarında AVC0x1b tercih edilebilir; bu HEVC'yi AVC'ye dönüştürmez. [C](dvb/2d53bf88.c), [assembly](classifier-assembly.json). |
| Customer `_SatelliteSkipService` `0x2e191a98` | Satellite yolunda internal tür7 ve bazı tür3 servisler atlanır; TV tür1 için bu gövdede UHD ayrımı yoktur. [C](customer/2e191a98.c). |
| Customer `_CheckService` `0x2e191888` | Tür7 reddi, operatör/mode ve program+0x1c alanına ilişkin sınırlar, geçerli video/audio PID'lerine bağlı TV/radio düzeltmeleri vardır. Tür0x1f özel reddi görülmedi. +0x1c alanının LCN olduğu ikinci aşamadaki AddCommon/GetByLcn gövdeleriyle doğrulandı. [C](customer/2e191888.c). |
| `libmsrv_dvbs_customer.so`, `SavePrograms` `0x2e973aa8` | Kullanıcının TV/radio, şifreli/şifresiz seçimleri ve operatör kuralları kayıt kararını etkiler. UHD/HEVC codec'ine bağlı özel ret bulunmadı. [C](satellite/2e973aa8.c). |

Önemli ayrım: temel `_UpdateServiceType` `0x2d53c128` yalnız0x1a altını switch'e alır ve0x1f'yi tür7 yapabilir. Müşteri override'ı0x20 sınırı ve açık0x1f case'i ekler. Temel kodu tek başına görüp “4K engelli” demek veya o sınırı değiştirmek doğru değildir. Switch case assembly'si, ilk analizde kısa görünen fonksiyon sınırının dışındaki gerçek hedef baytlarından ayrıca okundu; yalnız decompiler sembolüne güvenilmedi.

## Kanalın listede bulunmaması için son kontrol

Kullanıcı modlamadan önce de hiçbir UHD kanalını listede görmediğini ve yalnız otomatik arama kullandığını bildirdi; manuel arama denenmedi. Sınıflandırıcıdan önceki sanal +0x2bc kapısı bu yüzden ayrıca çözüldü. Customer vtable relocation `0x2e1e16dc`, `_IsSpecificSupport(0x2e19784c)` fonksiyonuna gider. Case0 `0x8242140e` maskesini kullanır;31. bit açıktır. Gerçek assembly `0x2e1979c8/79d0` maskeyi kurar, `0x2e1979d4` bit kesişimini yapar. Satellite parser mode2 olduğunda `0x2e1979ec` giriş0x1f'yi değiştirmeden yazar ve `0x2e1979f4` true döndürür. Bu yolda4K feature flag'i veya donanım servisi sorgulanmaz. Yalnız parser mode1 + operatör alanı8 için tür1/2 sınırlaması vardır; bu satellite mode2 yolu değildir. [C](gates/2e19784c.c), [relocation, maske ve assembly kanıtı](gates/gate-proof.json).

Customer `_ParserPMT(0x2e192210)` içindeki0x0a..0x0e/0x80 seçimi HEVC video listesini silen genel bir filtre değildir: gövde bu türlerin0x66/0x52 descriptor bildirimlerini işler. HEVC0x24'ü SDK PMT video yolundan kaldıran bir yazma/ret yolu bu gövdede bulunmadı. `_CheckService` video PID'si0x1fff iken audio PID'si geçerliyse bazı modlarda TV'yi radio türüne çevirebilir; dolayısıyla gerçek TS/PMT verisi olmadan kayıp kanalın hangi listede veya aşamada kaldığı kesinleştirilemez.

Ana araştırmadaki bağımsız [Türksat varsayılan transponder kaydı incelemesi](../transponders/turksat-current-tp-audit.json), eski tabloda güncel11767V/15000 kaydının bulunmadığını ortaya koydu. Bu, varsayılan listeyle otomatik arama için somut veri kusurudur. Manuel arama sonucu, demod kilidi ve gerçek yayın PMT'si olmadığı için tablo güncellemesinin4K kanal keşfini veya görüntüyü kesin düzelteceği iddia edilmez.

HEVC video kaydındaki descriptor döngüsü CA0x09, video0x02, AVC0x28 ve stream-id0x52 işlemleri içerir; incelenen video döngüsünde HEVC descriptor0x38 veya EIT component0x50 üzerinden Main/Main10 kapasite kararı kanıtlanmadı. “0x1f kabul ediliyor” tek başına UHD çözme desteği demek değildir. Bunun decoder/SoC katmanında ayrıca kanıtlanması gerekir.

- **Kanal hiç bulunmuyorsa:** RF/transponder/demod kilidi, TV/radio/şifreli tarama filtresi, operatör/LCN ve gerçek SDT/PMT kayıtları incelenmeli. Bu çalışmada mevcut yayın ve cihaz DB'si yok.
- **Kanal bulunup ses varsa, görüntü yoksa:** tarama engelini kaldırmak kanıtlanmış çözüm değildir; demux video PID'si, codec5 aktarımı, VDEC init/sequence ve hata durumları izlenmeli.
- **4K yayını1080p göstermek için:** önce sıkıştırılmış HEVC görüntünün çözülmesi gerekir. Burada gösterilen servis/PMT sınıflandırması bir downscale işlemi yapmaz.

Yama uygulanmadı ve bu filtrelerde önerilecek somut bir UHD kilit açma yaması çıkarılmadı. Canlı müşteri parser seçimi, yayın profili/bit derinliği ve donanım decoder sonucu açık araştırma maddeleridir.
