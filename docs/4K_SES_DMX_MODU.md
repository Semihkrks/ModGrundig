# DTV olayları, DMX yolu ve AVInfo mod alanı

30 Ekim 2026. [A1 ses testinin](V79_HEVC_SES_TESTI.md) `CheckAudioStatus`
koluna erişimi ile kanalın hangi başlatma olayına girdiği ayrıldı.

## Ayrı olan üç kavram

1. `Start=0x2d9da078`, event nesnesindeki komut alanına **1** koyar.
2. `StartWithoutDmx=0x2d9d9da4`, aynı komut alanına **0x100** koyar.
3. AVInfo **+0x26** başka bir bayttır; event komut alanı **+0x20** ile aynı değildir.

Normal event yazımı `0x2d9da284/0x2d9da294`, without-DMX yazımı
`0x2d9d9fb0/0x2d9d9fc0` ile sabitlendi. İki giriş caller AVInfo'sunu kopyalar;
fonksiyon isminden +0x26'nın zorla1 yapıldığı çıkarılmadı.
Önceki `AVMonitorMain=0x2d9d9484` incelemesi event1→DoStart ve
event0x100→DoStartWithoutDmx dispatch'ini içerir.

Seçilmiş `MSrv_DTV_Player_DVB::_UpdateAV=0x2d4d6e28` yolundaki
`0x2d4d7048/0x2d4d704c`, normal **Start** GOT sembolüne gider; WithoutDmx değildir.
Argüman mevcut AVInfo pointer'ıdır. Bütün customer/PVR kaynak yollarının bu
tek caller'dan geçtiği iddia edilmez.

## Varsayılan mod ve çözülmeyen yazıcılar

`MW_DTV_AVInfo` constructor `0x2d98e3f8`, **`0x2d98e440`** adresinde +0x26'ya0
yazar. Yeni104 baytlık raw gövde ve3 bounded native constructor vakası bunu
farklı başlangıç doldurmalarıyla doğrular. Audio/video requested baytları +0x24/+0x25
varsayılan1; PID alanları geçersiz0x1fff ile başlar. Sonradan gelen her caller
yazıcısı kapatılmadı; TV'deki gerçek requested/applied mod ölçülmüş değildir.

Seçilmiş kanal bilgisi converter'ı codec ve PID alanlarını doldurur; bu gövdede
+0x26'ya açık bir store bulunmadı. Bu, bütün caller'ların varsayılanı koruduğu
anlamına gelmez.

`DoSetMode=0x2d9d6d58`, **görüntü/timing** ayarıdır: GetDispInfo/GetLastDispInfo,
mute3, ready92 ve sync_pending6e yollarını içerir. İsmi nedeniyle bu fonksiyonu
AVInfo+0x26 üreticisi saymak yanlıştır. GetDispInfo başarısızlığında normal
görüntü hazır akışı ilerlemeyebilir; gerçekleşen TV hatası olarak ölçülmedi.

## Kapsam ve sonuç

Üç farklı yeni C çıktısı: `StartWithoutDmx`, `DoStartWithoutDmx`, `DoSetMode`.
İlk ve ikinci retained query dizinleri aynı hedefleri içerir; **6 fonksiyon
sayılmaz**. Constructor yeni raw hedeftir. [Audit](../scripts/audit_hevc_audio_mode_stage5.py),
beş source word'ü, DVB GOT sembolünü, C dosyalarının hash'lerini ve **3 native
constructor vakasını** doğrular. Donanım veya tam TV uygulaması çalıştırılmaz.
[Sonuç](../analiz/native-4k/audio-stage5-mode/results.json).

Bu kanıt, sırf kanal HEVC diye WithoutDmx/mode1 yoluna girdiği iddiasını
desteklemez. Önceki yamanın hangi guard'a takıldığını bilmeden mode bayrağını,
event türünü veya bütün ses mute nedenlerini zorlamak için yeni yama çıkarılmadı.
