# V7.9 HEVC ses testi: erişim ve gözlemlenebilirlik

30 Ekim 2026. Kullanıcı güncellemenin yüzde100 tamamlandığını ve TV'nin yeniden
başladığını, buna rağmen iki ses seçiminde de ses gelmediğini bildirdi. Bu geri
bildirim korunur; güncellemenin atlandığı varsayılmaz. Ancak yardımcıya girildiği,
hangi ret koşulunun oluştuğu, mute2'nin gerçekten kaldırıldığı veya PCM çıktığı
henüz cihazda gözlenmedi. Bu çalışma yeni unmute yaması üretmez.

## Yardımcıya ulaşmadan önceki kapılar

`MW_DTV_AVMonitor::DoMonitor=0x2d9d6c44`, önce `GetAVInfo`, ardından
`DoVideoSync` çağırır. Normal demux modu, video-started ve audio-started koşulları
uygunsa `0x2d9d6d34` adresinde `CheckAudioStatus` çağrılır.

| Koşul | Sonuç / kanıt |
|---|---|
| Requested AVInfo+0x26 sıfır değil | `0x2d9d6d04–0x2d9d6d0c`: ses kontrolü atlanır. |
| Monitor+0x110 sıfır | `0x2d9d6d10–0x2d9d6d18`: ses kontrolü atlanır. |
| Monitor+0x111 sıfır | `0x2d9d6d24–0x2d9d6d2c`: ses kontrolü atlanır. |
| Monitor+0x113 bir | Bu caller'da tekrar kontrolünü engellemez; +0x113 okunmaz. |

Yeni, küçük raw inceleme `GetAVInfo=0x2d9d1b18` (200 bayt) içindir. Bu fonksiyon
normal dönüşte **koşulsuz1** döndürür (`0x2d9d1bc8`); false sonucu bu gövdede
kanıtlanmış bir engel değildir. Kopyalanan kaynak **monitor+0xd8 requested info**
alanıdır. Buna karşılık yama **monitor+0xa0 applied info** alanını okur.
Dolayısıyla caller'ın mod kontrolü requested+0xfe, yardımcının mod kontrolü
applied+0xc6 alanından gelir. İkisi güncelleme sırasında farklı olabilir;
cihazda farklı oldukları iddia edilmez.

[DoMonitor assembly](../analiz/native-4k/audio-stage3/libmsrv_common.so-0x2d9d6c44.asm.txt),
[yeni GetAVInfo gövdesi](../analiz/native-4k/audio-stage4-reachability/GetAVInfo.asm.txt).

## CheckVideoStatus sesi ayrıca kapatıyor mu?

`CheckVideoStatus=0x2d9d4c30`, ilerlemeyen frame sayacıyla status2 isteyebilir
(`0x2d9d4d44`). `SetVideoStatus=0x2d9d4a90`, status2 için
`SetMuteFlag(this,1,0x20)` çağırır (`0x2d9d4b88`); diğer durumlarda aynı0x20
nedenini kaldırır (`0x2d9d4af8`).

**0x20, normal ses maskesi0x1a0ce içinde değildir.** Yardımcı zaten video
mute1/status0x20 bitlerini koruyarak çalışır. Bu nedenle sırf frame yok diye
0x20'nin görülmesi, sesin bu nedenle kapalı kaldığının kanıtı değildir.
0x20'yi kaldıran yeni bir yama bu bulguyla gerekçelendirilemez.

## Yardımcıya girilse bile neden ses gelmeyebilir?

- DoStart, video/ses aktifse `0x2d9d9028` adresinde zaman damgasını yeniden
  yazar. Tekrarlayan start olayları, 2000ms eşiğinin dolmasını önleyebilir;
  cihazda böyle bir olay dizisi gözlenmedi.
- `sync_pending+0x6e!=0` en başta ret verir. DoVideoSync'in frame0 yolunda yerel
  başarı koşulu false kalır; bu durumda aşağıdaki pending temizleme yolu
  çalışmaz. Yeni video başlangıcı normalde +0x6e'yi sıfırlar, fakat bütün
  çalışma anı yazıcıları tamamlanmış sayılmaz.
- `ready92!=0` ise değiştirilmemiş native kurtarma yoluna gidilir. Ek fallback
  koşulları yalnız ready92==0 içindir.
- HEVC/source/window/playback/demux/başlatma/PID/codec koşullarından biri,
  başka ses mute nedeni, boş decoder pointer'ı veya sıfır olmayan frame sayısı
  fallback'i reddeder. Siyah ekran, frame sayacının kesinlikle0 olduğu anlamına gelmez.
- `IsMadLock()==0` hiçbir ses mute bitini kaldırmaz. Legacy MAD getter'ının
  seçili gerçek ses decoder'ını temsil etmesi ayrıca incelenmelidir.
- Native `SetMuteFlag(0,2)` çalışmış olsa bile bu, sıkıştırılmış sesin geldiği,
  DSP/codec/PCR koşullarının sağlandığı veya PCM üretildiği anlamına gelmez.
  Başka SDK/kullanıcı/çıkış mute nedenleri de ses çıkışını etkileyebilir.

## En küçük geri alınabilir tanılama önerisi

**Uygulanmadı; yeni paket veya cihaz yazımı yoktur.** Mevcut local
`fprintf/printf` kanalından tek ayarlama/ret değişimi başına sınırlı bir kayıt
yeterli olabilir: yardımcı giriş kimliği, ilk ret nedeni, requested/applied
codec+mod+audioPID, mevcut çağrılardan alınan frame/MAD değeri ve mute maskesinin
çağrı öncesi/sonrası değeri. Ek decoder çağrısı veya mute değişikliği gerekmez.

`SetMuteFlag=0x2d9d3e04`, `_DAT_2c67c868` üzerinden `fprintf` çağrılarına;
`DoVideoSync=0x2d9d6270`, AT/PIU/SYS ve sync-done loglarına zaten sahiptir.
Ancak bu stream'in kullanıcıca erişilebilir kalıcı dosyaya veya USB'ye aktarıldığı
kanıtlanmadı. Log okunamıyorsa bu yöntem cihaz tanısı olarak hazır sayılmaz.
UI'ye tanılama yazısı eklemek için güvenilir event/widget yaşam döngüsü yolu
bu incelemede kurulmadığından UI injection önerilmedi.

## Kapsam

Yedi mevcut fonksiyon gövdesi yeniden kullanıldı; bir yeni200 bayt raw fonksiyon
incelendi. Yeni decompile, native emülasyon veya donanım testi yapılmadı.
Kaynak `libmsrv_common.so` SHA-256 ve gövde hash'leri
[results.json](../analiz/native-4k/audio-stage4-reachability/results.json) içindedir.
Beceri `reverse-engineer-anything`; bu doğrudan statik analizdir, REA Evidence
veya fiziksel erişim ölçümü değildir.

## Ek doğrulama: mevcut loglar kullanıcıya aktarılıyor mu?

**Bu sınırlı incelemede kullanıcı tarafından okunabilir bir DTV log aktarım yolu
kanıtlanmadı.** Daha güçlü bir engel, sağlanan uygulama başlatıcısında bulunur:
`11_customer_update/profile:110`, `UART_ENABLE=FALSE` atar; `:115` satırındaki dal
uygulamayı `./autorun signal >/dev/null 2>&1` komutuyla başlatır. Böylece varsayılan
başlatmada uygulamanın devraldığı stdout ve stderr `/dev/null`'a yönlenir.
Yalnız printf eklemek, kullanıcıya okunabilir tanı vermeyecektir.

`06_RFS/etc/inittab` ve `rcS` içinde kullanıcı için bir dosya/USB log yönlendirmesi
bulunmadı. Burada başlatıcı veya UART ayarı değiştirilmedi; bu inceleme böyle bir
değişiklik önermiyor. Statik profil, canlı TV ortamının ölçümü değildir; uygulama
içi bütün FILE pointer'larının veya olası sonraki redirection'ların çözülmüş olduğu
da iddia edilmez.

`09_CONFIG/MM/mm_cfg.ini:84`, `ms_mm_log_to_file=0`; `:86`, `ms_mm_log_dir=usb/sda1`;
`:100`, `ms_mm_disable_all_log=1` içerir. Bunlar MM yapılandırma kayıtlarıdır.
Bu seçeneklerin canlı DTV AVMonitor printf/fprintf akışını USB'ye taşıdığına dair
tüketici bağlantısı bulunmadı. USB dizini string'inin varlığı mevcut log dışa
aktarma işlevi sayılmaz. İncelenen APP/MSRV string'lerinde seçilmiş log-file
adayları da kullanıcıca uygulanabilir bir DTV export yöntemi kurmadı.

Bu nedenle yukarıdaki log önerisi **yalnız kanal erişimi önceden kanıtlanırsa**
değerlendirilebilir; hazır bir cihaz tanı yöntemi değildir. Dar, erişilebilir bir
çıktı kanalı kurulmadan yeni genel printf enstrümantasyonu veya geniş log yakalama
önerilmez. Profil/hash/satır kanıtları
[observability.json](../analiz/native-4k/audio-stage4-reachability/observability.json)
içindedir. Yeni Ghidra sorgusu, setter/target yürütmesi veya firmware paketi yoktur.
