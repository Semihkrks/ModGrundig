# V7.9 tabanlı HEVC ses testi

30 Ekim 2026. Gerçek native test yaması `libmsrv_common.so` içinde üretildi. **V7.9 APP ve menü tasarımı aynen korunur; V7.10/SEMIH değişikliği bu adayda yoktur.** Amaç, HEVC görüntüsü hiç frame üretmezken native ses decoder'ı kilit aldıysa kanal değişimi kaynaklı ses mute nedenini güvenli koşullarla kaldırmayı denemektir. Bu yama UHD görüntü decoder'ını açmaz veya ses çıkacağını garanti etmez.

## Gerçek değişiklik

`MW_DTV_AVMonitor::CheckAudioStatus=0x2d9d6124` girişindeki PIC prologue korunur, ardından GP-relative trampoline ile `0x2d957000` yardımcısına gidilir. Orijinal kütüphane `1.504.024` bayttır; boyutu, ELF/program/section header'ları, dynamic/GOT/relocation tabloları ve bağımlılıkları değişmez. Yardımcı, mevcut R-X PT_LOAD içindeki tamamen sıfır ve hiçbir ELF section'ıyla örtüşmeyen boşluğa yazılır (`file+0x47000`). Yeni segment veya loader değişikliği yoktur.

Orijinal akışın **2000 ms'den büyük zaman farkı**, `sync_pending+0x6e==0`, `ready92!=0` yolundaki MAD kilidi ve native `SetMuteFlag(this,0,2)` davranışı korunur. `ready92==0` durumuna eklenen fallback ancak şu şartların tümünde çalışır:

- Saklanan AVInfo video codec'i `monitor+0xa0==7` (HEVC).
- Main DTV monitor kimliği `+0xc==0x1c`, pencere `+0x1c8==0`; Start playback-control flag `+0x1be==0` ve normal demux modu `+0xc6==0`.
- Video ve ses başlatma bayrakları açık; seçilen ses PID/codec'i geçersiz sentinel değerinde değil; decoder nesnesi mevcut.
- Mute nedeni `0x2` mevcut; normal ses maskesindeki **başka hiçbir mute nedeni** etkin değil (`0x1a0cc` ile kontrol).
- Gerçek native `mapi_vdec::GetFrameCnt()==0` ve gerçek native `MW_DTV_AVMonitor::IsMadLock()!=0`.

Koşullar sağlanınca yalnız orijinal `SetMuteFlag(this,0,2)` çağrılır. Video mute `0x1`, video-status nedeni `0x20` ve diğer bütün mask bitleri korunur. `0x1`/`0x20`, mevcut normal ses maskesi `0x1a0ce` içinde değildir; no-frame ses denemesi açısından asıl kaldırılan neden `0x2`'dir. Native başka ses maskesi nedeni varsa fallback hiçbir şey yapmaz. Ses seviyesi/kullanıcı mute ayarı, PCR PID, codec seçimi veya decoder başarı bayrakları yazılmaz. İlk MAD kilidi denemesi başarısızsa ileriki poll denemesi çalışabilir.

Pencere/kimlik değerleri tahmin edilmiş SAT enum'u değildir: constructor `0x2d9d4db4` pencere parametresini `+0x1c8` alanına yazar; pencere0 için `+0xc=0x1c`, pencere1 için `0x25` atar. DoStart'ın son AVInfo kopyası codec'i `+0xa0`, audio PID'yi `+0xb2`, demux modunu `+0xc6` yapar. Start `0x2d9da078`, playback-control girdisini `+0x1be` alanına kaydeder; eski1/yeni0 yolunu `Ignore live pmt change in PVR playback mode` mesajıyla reddeder. DoMonitor ayrıca AVInfo+0x26 sıfır değilse CheckAudioStatus çağrısını atlar. Bu test yalnız normal canlı ana DTV akışını hedefler; dahili kayıt oynatma yolu kapsam dışıdır.

## Kanıt ve test

[Saf byte patch'i](../scripts/native_hevc_audio_test.py), yalnız orijinal/V7.9 MSLIB kütüphanesi SHA-256 `06bc6252713a159d5a41849f476503b0c60b035954f0c82909750223e1077d21` kabul eder. Orijinal entry word'leri ve sıfır RX boşluğu ayrıca kontrol edilir. V7.9 APP pini `861d97c013c4d56e093a69cf779abfa6ea78e6c17233af5d6b2b3ba075b0b4ea`.

[Native sınırlı testler](../scripts/test_native_hevc_audio_test.py), gerçek entry/trampoline/yardımcı MIPS talimatlarını Unicorn'da çalıştırır; bütün dış native servisler mock'tur. Tam firmware, ses/video decoder'ı veya donanım çalıştırılmaz. Testler 2000/2001 ms sınırını, sync kapısını, bütün fallback ret koşullarını, frame0/1 ve MAD0/1'i, MAD kilidi gecikince tekrar denemeyi, mevcut ready92 yolunun orijinalle eşliğini, diğer mute maskelerini ve PCR'a yazılmamasını kapsar. Rebase edilmiş yükleme ile T9/GP, caller-saved register zehirleme ve SP/RA/s0..s7/FP sözleşmeleri denetlenir.

`python -m unittest discover -s scripts -p test_native_hevc_audio_test.py -v` **7 test geçti**. Native `SetMuteFlag` etkisi bu harness'te modellenir; tam ses kontrol zinciri ve fiziksel kumanda mute davranışı bu testlerde çalıştırılmış sayılmaz. [Vaka JSON'u](../analiz/native-4k/audio-test/bounded-native-tests.json), [patch allowlist/hash/ABI kanıtı](../analiz/native-4k/audio-test/patch-proof.json).

**Sınır:** Mevcut unwind/FDE tabloları değişmedi; yeni yardımcı için FDE eklenmedi. Yardımcı içindeki native çağrılarda exception veya asenkron stack unwind desteği yoktur. Normal dönüş ABI'si test edildi; bu sınırlama sıfır risk iddiasına dönüştürülemez. Canlı PID, PCM çıkışı ve fiziksel TV başarısı henüz ölçülmedi. Kullanıcı mute ayarı yazılmasa da kumandadan mute/unmute ve ses0 davranışı cihaz testinde ayrıca kontrol edilmelidir.

## Cihazdaki sınırlı deneme

Paket ana görev tarafından V7.9 tabanında ayrıca bütünlük kontrolünden geçirilir. Testte önce normal SD/HD kanal sesi ve kumanda mute/unmute korunmalı; ardından canlı TRT Ultra HD seçilip birkaç saniye beklenerek iki ses seçeneği ayrı denenmeli. Sonuçlar “ses geldi/gelmedi”, “mute tuşu çalıştı/çalışmadı”, “normal kanala dönüşte ses korundu/bozuldu” olarak ayrılmalı. Dahili kayıt oynatımı veya görüntü açılması bu patch'in başarısı olarak beklenmez. Test başarısızsa aynı V7.9 tabanına geri dönüş imkânı ana pakette korunur; orijinal firmware dosyaları değiştirilmedi.

Beceri: `reverse-engineer-anything`. Çıktılar doğrudan statik ELF/assembly ve sınırlı native test kanıtıdır; REA Evidence veya fiziksel TV doğrulaması değildir.
