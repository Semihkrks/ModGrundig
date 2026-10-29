# TRT Ultra HD: ses başlatma ve video kaynaklı mute bağı

30 Ekim 2026. **Video başlatma başarısızlığı DoStart içinde ses başlatma koduna geçişi doğrudan durdurmuyor; fakat video hazır değilken sesin mute durumunda kalabileceği gerçek bir bağ var.** Bu, iki ses seçeneğinin de sessiz olmasını açıklayabilecek statik bir adaydır; canlı TV hatasının nedeni olarak kanıtlanmadı. Yeni yama önerilmedi.

Kaynak gözlem V7.8'de kanalın listelendiği, görüntü olmadığı ve kullanıcının Dolby/HE-AAC olarak tanımladığı iki seçeneğin de sessiz olduğudur. Canlı servis kimliği, seçilen ses indeksi, audio/video/PCR PID, decoder dönüşleri veya monitor bayrakları mevcut değil. Kullanıcı USB kayıt denemedi; kayıt sonucu varmış gibi kullanılmadı.

## Başlatma, başarısız video sonucunu kontrol etmiyor

`libmsrv_common.so:MW_DTV_AVMonitor::DoStart=0x2d9d7e40` yeni C çıktısı ve orijinal assembly ile karşılaştırıldı:

- `0x2d9d9308`: `mapi_vdec::SetVdecType(...)`; `0x2d9d9334`: `mapi_vdec::Play(...)`. Arada/sonrasında bu çağrıların return değeriyle başarı kontrolü yok. `0x2d9d9350`, monitor `+0x110` alanını doğrudan 1 yapıyor. Bu byte fiziksel decoder başarısı değildir.
- Sonraki ortak akış ses bölümüne gider. Ses PID'si `AVInfo+0x12=0x1fff` veya codec `AVInfo+4=0xff` ise normal ses başlatması atlanır; bu, sesin kendi veri koşuludur. Video PID/codec ile karıştırılmamalı.
- Yeni ses başlatmasında `0x2d9d8200–0x2d9d820c`, `SetMuteFlag(this,1,2)` çağırır. Ardından `Get_mapi_audio` nesnesinin sanal `+0x64/+0x5c` status, `+0x38` decoder komutu ve `+0x44` DSP türü yolları çağrılır. `0x2d9d82e0`, `AVInfo+4` codec'ini argüman olarak yükler; `0x2d9d82ec` sanal çağrıyı yapar.
- `this+0x111=1` yazılması da ses decoder'ından gerçekten PCM çıktığına tek başına kanıt değildir; bu gövdedeki başlatma durumu bayrağıdır.

[DoStart C](../analiz/native-4k/audio-stage3/common-v1/2d9d7e40.c), [assembly ve kaynak hash'i](../analiz/native-4k/audio-stage3/results.json). Audio nesnesinin base/customer vtable'larında `+0x44`, `DECODER_SwitchAudioDSPSystem`; `+0x38`, `DECODER_SetCommand` olarak eşleşir. İki tablonun raw pointer/simge karşılaştırması kaydedildi; cihazda hangi somut nesnenin döndüğü ve bu çağrıların başarı durumu doğrulanmadı.

## Video hazır değilken ses neden mute kalabilir?

`DoStart` sonundaki normal mute2 kaldırma koşulu şudur:

```text
audio_active &&
  (!video_active ||
   (old_video_kept && video_active && flag92 && !sync_pending))
```

Burada `video_active=this+0x110`, `audio_active=+0x111`, `flag92=+0x92`, `sync_pending=+0x6e`; `old_video_kept`, aynı DoStart gövdesinde yeni codec başlatıldığında sıfırlanan `s7` koşuludur. `+0x92` için tam bir semantik ad varsayılmadı. Assembly `0x2d9d8a1c–0x2d9d8a64` ve `0x2d9d8d94–0x2d9d8db8` bunu sabitler. Ayrıca açık audio-only istek (`AVInfo+0x24!=0 && +0x25==0`) ayrı bir mute2 kaldırma yoludur.

| Host koşul örneği | DoStart sonunda mute2 kaldırılır mı? |
|---|---|
| Yeni video başlatıldı, ses başlatıldı, `flag92=0` | Hayır |
| Aynı video korunuyor, `flag92=0` | Hayır |
| Aynı video, `flag92=1`, sync hâlâ bekliyor | Hayır |
| Aynı video, `flag92=1`, sync beklemiyor | Evet |
| Video aktif değil, ses aktif | Evet |
| Açık audio-only istek | Evet |

Asenkron `DoVideoSync=0x2d9d6270`, dış koşulunda `this+0x110!=0` ve `mapi_vdec::GetFrameCnt()!=0` ister. Hiç çözülmüş frame yoksa normal sync/mute kaldırma kolu çalışmaz. Sonraki kolda video/ses/PCR koşulları ve `IsSyncDone()`/timeout denetimi vardır; sonunda `SetMuteFlag(this,0,2)` ve `SetMuteFlag(this,0,1)` çağrılır. Bu gövdedeki diğer erken mute kaldırma kolları da aynı dış frame koşulunun içindedir. [Yeniden kullanılan DoVideoSync C](../analiz/native-features/fast-channel/common-sync-v1/2d9d6270.c).

`CheckAudioStatus=0x2d9d6124` alternatif kurtarma yoludur; fakat koşulsuz değildir. **2000 ms'den sonra, `+0x6e==0`, `+0x92!=0` ve `IsMadLock()!=0`** olduğunda mute2'yi kaldırır. `0x2d9d6178–0x2d9d617c` flag92 kapısıdır; `0x2d9d61bc–0x2d9d61d0` kaldırma çağrısıdır. Bu nedenle “ses ayrı, video başlatılamasa da kesin açılır” sonucu çıkarılamaz. [CheckAudioStatus C](../analiz/native-4k/audio-stage3/common-v1/2d9d6124.c).

`SetMuteFlag=0x2d9d3e04`, ortak maskeyi monitor `+0x68` üzerinde tutar. Ses için kullanılan normal `0x1a0ce` ve alternatif `0x15002` maskelerinin ikisinde de bit2 vardır. Maskeye bağlı ses mute/unmute yolu gerçek kontrol sanal çağrılarına ulaşır; bu nedenle bit2 yalnız bir UI göstergesi değildir. `0x80` istisnası ve diğer mute nedenleri de vardır; tek bitin zorla temizlenmesi bütün ses güvenlik koşullarını kanıtlamaz. [SetMuteFlag C](../analiz/native-4k/audio-stage3/common-v1/2d9d3e04.c).

## Ses türü ve PID aktarımı

`_GetAvInfoFromProgramInfo=0x2d4d6a08` için yeni C alındı; primary audio switch'i ayrıca **orijinal jump table ve case word'lerinden**, target çalıştırılmadan çözüldü. Seçilen indeks `SearchAudESIndexForGivenAudioLangList` sonucudur. Ses girişi `program+0x54+14*index` PID, `program+0x56+14*index` türdür. PID `0x1fff` ise çıkış ses codec'i `0xff` olur. Geçerli PID için:

| DB ses türü | AVInfo ana ses codec'i |
|---|---|
| 0 | 0 |
| 1 | 1 |
| 3, 5, 16, 17, 18, 19, 20 | 4 |
| 4 | 6 |
| 21 | 18 |
| 2, 6–15; aralık dışı | 255 / geçersiz |

Bu sayılar farklı enum alanlarıdır; kullanıcının ekranda gördüğü Dolby/HE-AAC yazılarından canlı DB türü çıkarılmadı. Dönüşüm kodunun bir codec'i kabul etmesi DSP/mikrokod/akış profilinin fiziksel olarak çözüldüğünü kanıtlamaz. AD/BMA seçicileri player sanal `+0x82c/+0x758` üzerinden gelir; bütün somut seçim hedefleri çözülmedi. C'deki BMA jump-table uyarısı kapatılmadı ve tam BMA semantiği iddia edilmedi.

Ana ses PID `AVInfo+0x12`, AD PID `+0x14`, BMA PID `+0x16`, PCR PID `+0x1e` olur. PCR doğrudan `program+0x2e` alanından kopyalanır (`0x2d4d6c24–0x2d4d6c30`). DoStart bu PID'leri farklı demux filtre nesneleriyle işler (`monitor+0x158/+0x15c/+0x160`); bazı filtre sanal slotları henüz somut hedefleriyle çözülmedi. Canlı yayında doğru PID'lerin ve veri akışının gerçekten bulunduğu bilinmiyor. [Dönüştürücü C](../analiz/native-4k/audio-stage3/dvb-v1/2d4d6a08.c), [22 case satırı ve PID kaydı](../analiz/native-4k/audio-stage3/results.json).

## Kapsam ve karar

`reverse-engineer-anything` becerisi kullanıldı. Dört orijinal kütüphane SHA-256 ile sabitlendi. **4 yeni C export**, daha önceki DoVideoSync C'sinin yeniden kullanımı, **3 ek küçük raw assembly gövdesi** (DoMonitor, IsMadLock, SetVideoStatus), toplam **8 farklı seçilmiş fonksiyon** incelendi. Bunların **3'ü önceki odaklı gövdeler** (DoStart, converter ve DoVideoSync), **5'i bu odaklı incelemeye eklenen farklı gövdeler**dir. DoStart/converter'ın eski assembly'si yeni fonksiyon keşfi olarak sayılmaz; bu ikisinin C çıktısı yenidir. Yeni C'ler `-noanalysis -readOnly` sorgularıdır; REA Evidence değildir.

[Audit script'i](../scripts/audit_4k_audio_path.py) dört kaynak hash'ini, seçili fonksiyon byte kapsamını, 22 primary audio switch satırını ve **11 host predicate örneğini** doğruladı; `py_compile` geçti. Predicate örnekleri yalnız adresli koşulların host üzerindeki mantık tablosudur. Native MIPS emülasyonu, ses decoder'ı veya donanım testi yapılmadı. USB kayıt, gerçek PID, decode-frame veya PCM ölçümü yok.

**Zorla unmute yaması önerilmiyor.** Video hatasıyla birlikte sesin hazır olduğunu ve PCR/clock koşullarını bağımsız kanıtlayan bir invariant henüz yok; yanlış akışta ses gürültüsü veya senkron kaybı oluşturabilecek kontrol atlanmamalı. Sonuç, sonraki tanıda `video frame count + audio/MAD lock + mute mask + selected PID/PCR` değerlerinin birlikte ayrılmasını gerektirir; yalnız downscale veya codec enum değişikliğiyle çözüm ilan edilemez.
