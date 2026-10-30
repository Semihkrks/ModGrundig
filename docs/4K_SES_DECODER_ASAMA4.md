# Ses decoder yolu — V7.9 testinden sonraki dar inceleme

**Aşama5 güncellemesi:** Aşağıdaki decoderID→SHM belirsizliği artık
[HAL ve native testleriyle](4K_SES_HAL_ASAMA5.md) kapandı: incelenen ID0/1/2 aynı
selector0'a gider. Yanlış kilit bankı hipotezi desteklenmedi. Aşağıdaki metin
aşama4'ün tarihsel sınır kaydıdır.

30 Ekim 2026. Kullanıcı V7.9 HEVC ses testinin yüklenmesinin %100 tamamlandığını, TV'nin yeniden başladığını ve iki ses seçeneğinde de belirgin değişiklik/ses olmadığını bildirdi. **Bu sonuç, fallback'in çalıştığını veya MAD kilidinin false olduğunu kanıtlamaz.** Canlı helper çağrı sayısı, seçilen PID/codec, mute maskesi ve PCM verisi yoktur.

Somut yeni sonuç: **Normal ses başlatması, decoder kimliği atanmışsa kimlikli AudioSDK API'sini kullanıyor; testte korunan IsMadLock zinciri ise SHM selector0'ı okuyor.** Decoder kimliği ile bu selector arasındaki ilişki çözülmediği için “yanlış decoder kilidi okunuyor” sonucu henüz çıkarılamaz. Yeni A2 yaması üretilmedi.

## Main/proc0 hangi kimliği kullanır?

`mapi_audio_customer::DECODER_SwitchAudioDSPSystem(AUDIO_DSP_SYSTEM_,processor)=0x2dc65c6c`:

| Koşul | Gerçek yol |
|---|---|
| Hem `audio+0x12c` hem `+0x130` -1 | Sanal `+0x40` üzerinden legacy tek argümanlı DSP switch'i. |
| processor0 ve `audio+0x12c!=-1` | DSP türünü `+0x140` alanına koyar; sanal `+0x58(this,ID, audio+0x134)` çağrısı. |
| processor1 ve `audio+0x130!=-1` | DSP türünü `+0x15c` alanına koyar; `+0x58(this,ID,audio+0x150)`. |
| Seçilen ID -1, diğer ID geçerli | O processor için DSP switch çağrılmaz; SPDIF ayarı ayrı devam eder. |

Main DTV'nin önceki DoStart yolu processor0 gönderir. Bu, **API decoderID0 sabitini gönderdiği anlamına gelmez**: gerçek ID `audio+0x12c` alanından yüklenir (`0x2dc65cd4`). Canlı cihazdaki ID tahmin edilmedi. Aynı switch'in parametrelerinde HEVC/video codec'i bulunmaz; bu seçilmiş gövdede HEVC'ye özel ayrı ses pipeline'ı saptanmadı.

Sanal `+0x58` customer vtable'ında `SetAudioDec=0x2dc6ac08`'dir. `AudioSDKDecStatus*` null veya ID -1/3 olduğunda 0 döner. Normal yolda ID, `0x2dc634d8` enum converter'ından geçer: 0→0, 1→1, 2→2; -1 korunur, diğer değerler hata/-1 olur. Ardından `MApi_AUDIO_GetDecodeSystem(id,status)` ve `MApi_AUDIO_SetDecodeSystem(id,status)` çağrılır. Bu gövdede SetDecodeSystem başarısı kontrol edilmeden outward1 dönülür; 1 dönüşü fiziksel ses/DSP başarısı değildir.

[Processor switch C](../analiz/native-4k/audio-stage4/customer-v1/2dc65c6c.c), [SetAudioDec C](../analiz/native-4k/audio-stage4/customer-v1/2dc6ac08.c), [kaynak hash'leri ve raw enum helper](../analiz/native-4k/audio-stage4/results.json).

## Seçilen codec'in DSP enum dönüşümü

Önceki aşamadaki DB→AVInfo dönüşümü değiştirilmedi ve yeniden HEVC/tarama araştırması yapılmadı. Yeni kimlikli yol, `AudioSDKDecStatus+0xc` alanını `0x2dc6625c` mapper'ına gönderir. Orijinal 20 satırlık jump table `0x2dccb5c8` ve case word'leri statik olarak çözüldü:

| DoStart'tan gelen DSP enum'u | Kimlikli SetDecodeSystem config enum'u | Legacy SetSystem argümanı |
|---|---:|---:|
| 0 | 1 | 1 |
| 1 | 3 | 2 |
| 4 | 4 | 4 |
| 6 | 3 | 3 |
| 18 (`0x12`) | 20 (`0x14`) | 20 (`0x14`) |

DSP3 analog SIF konfigürasyonuna bağlıdır; sabit değere indirgenmedi. Enum alanları/API'ler farklıdır; farklı sayının görülmesi codec dönüşüm hatası sayılmaz. Özellikle 1 ve 6'nın kimlikli yolda aynı 3 değerine gitmesi **orijinal kodun gerçek eşlemesidir**, doğru/yanlış DSP seçimi veya ses desteği kanıtı değildir. Ekranda bildirilen Dolby/HE-AAC adlarının canlı kayıtta hangi DB/DSP enum'uyla eşleştiği bilinmiyor. Bu yüzden sayısal eşleme “Dolby bozuk, 3'ü2 yapalım” yamasına dönüştürülmedi.

[Legacy switch C](../analiz/native-4k/audio-stage4/customer-v1/2dc65de0.c), [20 sayısal case kaydı](../analiz/native-4k/audio-stage4/results.json).

## IsMadLock IOCTL yolu kapatıldı

Yalnız public wrapper'a bakılarak API farkı ilan edilmedi; aşağıdaki dar driver kenarı orijinal word'lerle izlendi:

1. `mapi_audio::IsMadLock=0x2caaa93c`, `MApi_AUDIO_IsMadLock=0x2d08ab00` çağırır. Public API, sıfırlanmış 8 baytlık request ile `UtopiaIoctl(instance,0x3d,&request)` yapar ve `request+4` alt baytını döndürür; seçilen ses türü/decoderID parametresi almaz.
2. `AUDIOIoctl` tablosu `0x2d09ff6c`, cmd`0x3d`yi case`0x2d08cbe8`'e bağlar. Case, instance-private `+0xfc` callback'ini çağırıp sonucu request+4'e yazar. Bütün 7648 baytlık dispatcher decompile edilmedi.
3. `AUDIOOpen:0x2d08e7a0–0x2d08e7a8`, bu callback'e `_MApi_AUDIO_IsMadLock=0x2d080820` atar. Callback hedefi böylece tahmin edilmedi.
4. `_MApi_AUDIO_IsMadLock`, `_MApi_AUDIO_GetCommAudioInfo(infoType0)` çağırır (`0x2d080840: a0=0`). Wrapper→`MDrv_AUDIO_GetCommAudioInfo`→`HAL_MAD_GetCommInfo` zinciri kapandı.
5. HAL'de infoType0 yolu `0x2d074dc4→0x2d075144→0x2d074bd4` üzerinden **`HAL_DEC_R2_Get_SHM_INFO(infoType1, selector0)`** çağırır. `0x2d074dc8` a0=1, `0x2d075148` a1=0 yükler.

Bu, sabit SHM selector0 okunduğuna dair somut kanıttır. **Main API decoderID1/2'nin hangi SHM selector'a karşılık geldiği henüz çözülmedi.** Örneğin API ID1'in normal olarak SHM0'a bağlanması mümkündür; burada ne doğrulandı ne elendi. Sabit selector ile kimlikli config API'sinin birlikte bulunması tek başına yanlış kilit kontrolü değildir.

[Public API C](../analiz/native-4k/audio-stage4/api-v1/2d08ab00.c), [seçilmiş IOCTL/HAL blokları ve hash'leri](../analiz/native-4k/audio-stage4/results.json).

## Sonraki değişiklik için kalan kesin sınır

Mevcut `mapi_audio` sanal `+0x64` prototipi `GetAudioDecStatus(processor,AudioSDKDecStatus*)`; önceki DoStart bunu config/status taşıma amacıyla kullanır. **Bu scope içinde güvenilir bir donanım kilidi alanı/enum'u veya IsMadLock yerine koyulabilecek dönüş sözleşmesi kanıtlanmadı.** `MApi_AUDIO_GetAudioInfo2` gibi per-decoder API isimleri de doğru lock-info enum'u ve çağrı ABI'si çözülmeden yama değildir.

A2 için önce main decoderID'nin atanması ve ID→SHM selector eşleşmesi; gerekiyorsa bu ID'ye ait gerçek lock/PCM-ready bilgi türü çözülmeli. ID -1 durumunda DSP switch'in atlanması somut bir koşuldur, fakat gerçek cihazda gerçekleştiğine dair veri yoktur. False kilidi true yapmak, decoderID'yi zorlamak veya bütün kaynakların mute'unu kaldırmak gerekçelendirilmedi.

## Doğrulama kapsamı

`reverse-engineer-anything` kullanıldı. Üç kütüphane SHA-256 ile sabitlendi. **5 yeni C çıktısı**, iki küçük enum helper'ının raw incelemesi, **20 DSP tablo satırı**, **7 host processor/ID koşul vakası** ve **11 seçilmiş driver dispatch/forwarder bloğu** kaydedildi. Blok sayısı yeni decompile/fonksiyon sayısı değildir. Ghidra `-noanalysis -readOnly` kullanıldı; çıktılar REA Evidence değildir.

`python -X utf8 scripts/audit_hevc_audio_decoder_stage4.py` ve `python -m py_compile scripts/audit_hevc_audio_decoder_stage4.py` geçti. [Script](../scripts/audit_hevc_audio_decoder_stage4.py) kaynak hash'lerini, beş gerçek C çıktısını, callback/table word'lerini ve sayısal eşlemeleri doğrular. Host koşul vakaları native decoder çalıştırmaz. Firmware programı, donanım veya bütün TV süreci çalıştırılmadı; orijinal dosyalara ve önceki test paketine yazılmadı.

## Son dar kapanış: decoder kimliği nerede HAL'a geçiyor?

İki küçük raw gövde ve ayrıca onaylanan 108 baytlık driver forwarder okundu; **yeni C/decompile yoktur**:

- `_MApi_AUDIO_GetDecodeSystem=0x2d082f00` (468 bayt), decoderID için `g_AudioVars2+0x98+36*ID` tablosuna ve `+0x9d+36*ID` baytına bakar; etkin kayıt varsa config'i kopyalar. Bu fonksiyon ID'yi SHM bankına çevirmiyor; cached config okumasıdır.
- `_MApi_AUDIO_GetAudioInfo2=0x2d07f534` (376 bayt), ID/infoType/output girdilerini değiştirmeden `MDrv_AUDIO_GetAudioInfo2`'ye iletir (`0x2d07f594–0x2d07f5a0`). Burada da ID1→SHM0 benzeri eşleme yoktur.
- `MDrv_AUDIO_GetAudioInfo2=0x2d05735c` (108 bayt), BSS `g_FuncPrt_Hal_GetAudioInfo2=0x2d2330cc` pointer'ını yükler ve doluysa **a0=ID, a1=infoType, a2=output** girdilerini değiştirmeden çağırır (`0x2d057374–0x2d057388`). Pointer null ise 0 döner.

Artık kalan sınır yapay bir wrapper değildir: **runtime HAL callback'inin atanması ve onun ID→SHM selector eşlemesi**dir. `HAL_MAD_GetAudioInfo2=0x2d072d38`, 2264 baytlık bir export olarak mevcut; bu son görevde geniş gövdesi açılmadı ve runtime pointer'ın kesin hedefi diye ilan edilmedi. API ID0/1/2'nin hangi SHM bankını okuduğu hâlâ kanıtlanmış değildir; dolayısıyla legacy kilit uyumsuzluğu ne doğrulandı ne elendi.

Main audio ID'nin `audio+0x12c` alanından okunduğu kesin. **ID tahsisinin sabit bir değer mi yoksa açılışta allocation sonucuna göre mi olduğu**, bu alanın tahsis yazıcısı incelenmediği için ayrıştırılamadı. “Mutlaka ID1 kullanıyor” veya “cihazdan cihaza değişiyor” sonucu çıkarılmadı. Son script bu üç ilave raw gövdeyi ayrı sayar; beş C çıktısı sayısı değişmez. Yeni firmware veya A2 yaması yoktur.
