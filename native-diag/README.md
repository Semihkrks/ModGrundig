# Native tanı taşıması — FIFO / sınırlı USB çıktısı

**1 Kasım güncellemesi:** İlk toplayıcının gerçek kaydı FAT32 kayıp zincirinden
kurtarıldı. Güncel kaynak event4 örneklerini de kabul eder, TEMP readback'i
doğrular ve değişmeyen snapshot'ı tekrar yazmaz.18 host testi ve12 MIPS/QEMU
yaşam döngüsü testi geçti;6 host-only fault shim hedefte açıkça atlandı.
[Güncel kanıtlar ve tanı2 sınırları](../docs/V79_HEVC_CANLI_TANI_2.md).

Bu klasör tanı verisini taşır; HEVC çözücü veya 4K düzeltmesi içermez. Firmware
kodunun gerçek olaylara ekleyeceği sayısal kayıtlar ayrı kancalar gerektirir.
Güncel kaynak Linux host ve kendi MIPS toplayıcımızın stock glibc2.8/QEMU
testlerinden geçmiştir. Yeni sampler/toplayıcı revizyonunun fiziksel TV testi
ayrıca gerekir; önceki cihaz kaydı bu yeni kodun başarısı sayılmaz.

## Opt-in ve dosyalar

USB bölümünün kökünde tam **8 bayt** `MGDIAG1\n` içeren
`MODGRUNDIG_DIAG_ENABLE` adlı normal dosya bulunmalıdır. BOM, ek uzantı veya
başka içerik kabul edilmez. Marker bir symlink/FIFO/cihaz dosyası olamaz.
Örnek içerik üretimi: Python `Path(...).write_bytes(b"MGDIAG1\n")`.

Bu marker, aynı USB kökünde aşağıdaki **ayrılmış tanı adlarının** kullanılmasını
kabul eder:

- `MODGRUNDIG_DIAG.txt`: atomik olarak yenilenen, en fazla16KiB tanı snapshot'ı.
  Bu adla önceden bulunan dosya veya symlink, tanı çıktısıyla değiştirilebilir.
- `.MODGRUNDIG_DIAG.tmp`: geçici yazı. Önceki kesilmiş yazıdan kalan, aynı
  kullanıcıya ait, tek hardlink'li normal ve en fazla16KiB dosya temizlenebilir.
  Symlink veya daha büyük dosya silinmez; bu durumda export gerçekleşmez.

Başka USB dosyası değiştirilmez. Anahtar, sertifika, kanal adı, seri numarası,
bellek dump'ı veya genel stdout/stderr kaydı alınmaz. Yalnız aşağıdaki dar sayısal
şemalar tutulur. Kod dış servise veri göndermez.

Collector `/proc/mounts` içindeki `/dev/sd…` USB block cihazlarını ve rw
vfat/exfat/ntfs/fuseblk/ext2/ext3/ext4 mount'larını inceler. Mount dizini string'i
sabit varsayılmaz; boşluk içeren kernel octal-escape alanı çözümlenir. Başka
cihaz adlandırması kullanan TV için bu keşif ayrıca uyarlanmalıdır. Birden fazla
marker varsa ilk uygun bölüm seçilir.

## Producer sözleşmesi

Marker ilk kez worker tarafından doğrulanınca collector RAM'de
`/tmp/modgrundig-diag.fifo` oluşturur. İzin0600; başka mevcut nesne, symlink veya
eşzamanlı ikinci collector kabul edilmez. Normal marker-yok durumunda FIFO yoktur.
Collector FIFO'yu önce aynı dizinde `.pending` sonekiyle oluşturur ve read FD'yi
açar; ancak sonra `link(pending,final)` ile final adı atomik olarak görünür
yapar. `link` mevcut final nesnesini ezmez ve Linux3.1'de bulunur. Böylece final
adını görür görmez yazıp kapatan producer'ın ilk kaydı, collector henüz open
etmediği için kaybolmaz. Ardından pending hardlink'i kaldırılır.
Marker kaldırılınca FIFO kapatılır ve collector'ın oluşturduğu inode silinir.
Çöken collector'dan kalan FIFO veya `.pending` yeniden kullanılmaz; RAM temizliği/yeniden başlatma
gerektirir. Normal çıkışta yalnız aynı inode temizlenir.

Firmware helper her kayıtta şu sırayı uygular:

1. Önce path `__lxstat64` kontrolünü yapar, sonra FIFO'yu
   `O_RDWR | O_NONBLOCK | O_NOFOLLOW` ile açar; `O_CREAT` kullanmaz.
2. Açılan FD için proc-fd `__xstat`
   üzerinden FIFO tipi, root owner0 ve special bit içermeyen tam0600 iznini
   iki aşamada doğrular. Tarihsel v2 yalnız FIFO tipini kontrol ediyordu;
   owner/mode güvencesi v2 için geçerli değildir. Collector da oluşturduğu
   FIFO'da0600 ve owner/inode doğrulaması yapar.
3. En fazla192 baytlık newline ile biten kaydı **tek write** ile yollar.
4. FD'yi kapatır; cache tutmaz. ENOENT/EAGAIN/EINTR/hata durumunda kayıt düşer.

`O_RDWR` kritiktir: collector ölür veya marker kaldırılırsa producer'ın kendi
okuma ucu açık kalır; `SIGPIPE` oluşmaz. `O_NONBLOCK` dolu FIFO'da beklemeyi
engeller.192 bayt Linux'un en az4096 bayt `PIPE_BUF` sınırının altındadır;
başarılı write atomiktir. Üretici hook'u sayısal formatı stack üzerinde, sınırlı
uzunlukta üretmeli; TV'nin stdout/stderr yönlendirmesini değiştirmemelidir.

## İzin verilen şemalar

Tüm alanlar unsigned32 **ondalık** sayıdır. Negatif, hex, ek alan, key/value,
metin veya tanınmayan event reddedilir. Her satır `\n` ile biter.

```text
MGDIAG 1 rc video_codec audio_codec video_pid audio_pid pcr_pid mode mute_mask
MGDIAG 2 query ret
MGDIAG 3 ret kind framebuffer_bytes
MGDIAG 4 elapsed_ms video_codec video_pid audio_pid frames mad_lock ready92 sync_pending mute_mask video_started audio_started
```

Event1'de codec/mode<=255, PID'ler<=8191; event2 query<=255; event3 kind<=31.
Event4 tam12 unsigned sayı taşır; codec/MAD/byte bayrakları<=255 vePID'ler<=8191.
`MGDIAG_META 1 accepted rejected overlong retained` snapshot başlığıdır.
Yalnız son64 geçerli satır RAM ring'inde kalır; dosya uzayıp gitmez.

## Bloklamayı ayırma ve sınırlar

Ana collector yalnız RAM FIFO okuma, poll, child durum takibi yapar. USB marker
okuma, mount dizinini açma ve dosya yazma **ayrı child worker** içindedir.
Varsayılan marker kontrol aralığı2000ms, worker deadline1500ms'dir. Snapshot
yalnız yeni veri veya yeniden opt-in/USB kimliği olduğunda yazılır; başarılı
snapshot parent IPC'sinde cache'lenir, başarısız yazı yeniden denenir. Aşan child'a
SIGKILL gönderilir; önceki reaped olmadan yeni child açılmaz. Böylece takılmış
USB yazısı producer'ın TV thread'ine bağlanmaz ve sınırsız child oluşmaz.
Kernel'de kesilemeyen D-state I/O child'ı SIGKILL ile hemen durmayabilir; bu
durumda yeni export bekler, ana RAM okuyucusu çalışmayı sürdürür.

USB mount kökü açık directory FD ile tutulur; unmount sonrası path'in altındaki
dahili dosya sistemine yanlışlıkla yazılmaz. Symlink takip edilmez; scratch
oluşturma `O_EXCL` kullanır. FAT/NTFS mount-wide izinlerini0600 sanan bir kontrol
yoktur. Worker dosyayı close etmeden önce `fsync(fd)`, rename sonrasında
`fsync(dirfd)` çağırır. Dosya fsync hatasında snapshot yayımlanmaz; directory
fsync için desteklenmeyen VFAT/benzeri dosya sistemlerinin `EINVAL` sonucu
tolere edilir. Bu durumda rename'in güç kesintisine dayanıklılığı kanıtlanmaz.
Bütün sync işlemleri worker içindedir ve parent timeout sınırı korunur.
USB kaldırılınca son snapshot'ın kalıcı yazılmış olması garanti edilmez;
bu bir firmware/veritabanı işlemi değildir.

Boot sırasında marker/USB henüz mount edilmemişse ilk hook kayıtları düşebilir.
Gerçek testte USB algılanıp FIFO etkinleşince çalışan HD kanaldan TRT kanalına
geçmek, başlatma kayıtlarını yeniden üretir. Native hook ve gerçek USB mount
zinciri doğrulanmadan bu yönerge hazır bir TV tanı paketi sayılmaz.

## Gerçekleştirilen host doğrulaması

```sh
wsl -d Ubuntu --exec python3 /mnt/c/Users/Semih/Desktop/grundig/scripts/test_modgrundig_diag_sink.py
```

18 sentetik test geçti: marker-yok, strict numeric filtre,64 satır sınırı,
partial/overlong input, marker kaldırma/yeniden etkinleştirme, kapanmış sink'e
RDWR producer/EAGAIN, FIFO/marker symlink reddi, output symlink hedefini koruma,
FAT-benzeri0777 stale temp ve takılmış child sırasında1000 kayıt okuma/iyileşme.
İki host-only linker fault shim'i dosya `fsync=EIO` durumunda önceki snapshot'ın
korunmasını ve directory `fsync=EINVAL` durumunda export yapılmasını sınar.
Üçüncü host-only shim, mkfifo sonrasında150ms gecikme ekleyerek eski
publish-before-open yarışını zorlar; final görünür olur olmaz write+close yapılan
ilk kaydın korunmasını sınar.
Diğer fault kontrolleri sıfır/bozuk formatter başlığı, yalancı write ve bozuk
readback'i reddeder; başarılı IPC cache sonrası idle inode/mtime korunmasını,
başarısız export retry'sini ve event4 sayısal şemasını sınar.
Kontrol deneyi aynı gecikmeyle eski doğrudan-final `create_fifo` gövdesinde ilk
kaydın kaybolduğunu yeniden üretti; atomik-publish sürümünde bu test geçti.
Host derleme `gcc -std=c99 -Wall -Wextra -Werror -O2` ile yapılır. Bütün mount'lar
ve çıkarılabilir medya yalnız host temporary directory içinde taklit edilir;
firmware/MIPS programı, updater veya donanım komutu çalıştırılmaz.

Test runner ayrıca `MGDIAG_TEST_COMMAND` ortam değişkeninde shell komutu değil,
JSON string listesi kabul eder. Örneğin `["qemu-mipsel","-L","/absolute/runtime",
"/absolute/newly-built-collector"]` verilirse host derlemesi atlanır ve aynı
12 lifecycle testi sağlanan komut prefix'iyle çalışır. Altı host-only fault
shim testi bu modda açıkça SKIP olur. Bu destek, belirtilen emülasyon testlerinin
çalıştırıldığı veya fiziksel TV'de doğrulandığı anlamına gelmez; koşum kaydı ayrı
raporlanmalıdır. Ortam override'ı yalnız yeni collector binary'sini hedeflemeli,
orijinal firmware uygulamalarını çalıştırmak için kullanılmamalıdır.
