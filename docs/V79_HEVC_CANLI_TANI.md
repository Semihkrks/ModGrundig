# V7.9 HEVC canlı tanı paketi

**1 Kasım güncel devamı:** [FAT32 zincirinden kurtarılan gerçek SDK kayıtları,
USB onarımı ve ayrı tanı2 paketi](V79_HEVC_CANLI_TANI_2.md). Aşağıdaki ilk
paketin metni tarihsel kapsamıyla korunur; yeni paketle karıştırılmamalıdır.

1 Kasım USB hazırlığı: kullanıcı dosya oluşmadığını ve yalnız firmware'i
yüklediğini bildirdi. D: FAT32 çıkarılabilir sürücüde17 paket dosyasının tamamı
son adayla hash olarak eşleşti; etkinleştirme dosyası yoktu. USB köküne tam8
bayt marker eklendi ve yeniden okundu. Firmware tekrar kopyalanmadı; cihazda
hangi sürümün aktif olduğu ve tanı çıktısı henüz ölçülmedi.
[USB hazırlık kaydı](../analiz/native-ui-candidate/v7.9-hevc-diag/usb-preparation-2026-11-01.json).

31 Ekim 2026. **Bu paket 4K görüntüyü açan bir düzeltme değildir.** Önceki
pakette ses gelmemesi tek başına hangi decoder kapısına takıldığımızı göstermedi.
Bu aday, gerçek TV'de video başlangıcının sonucunu sayısal bir USB kaydına alır.
Arayüzün çalıştığı bilgisayar önizlemesi bu ölçüm yerine kullanılmaz.

## TV'de yapılacak kısa deneme

Dosyalar yereldir, GitHub'a tam firmware yüklenmemiştir:

- RAR: `analiz/native-ui-candidate/v7.9-hevc-diag/package/GMGRMR.-.-.-.-.V03.017.04_V7.9_HEVC_DIAG.rar`
- Hazır etkinleştirme dosyası: `analiz/native-ui-candidate/v7.9-hevc-diag/package/MODGRUNDIG_DIAG_ENABLE`
- TV'nin oluşturacağı çıktı: USB kökünde `MODGRUNDIG_DIAG.txt`.

1. RAR'ı açıp içeriğini önceki çalışan paketlerle aynı USB yerleşiminde kullan.
   RAR'ın orijinal17 dosya/11 dizin düzeni korunur. TV'ye doğrudan RAR okuyacağı
   varsayılmaz; paket önce açılır.
2. Hazır `MODGRUNDIG_DIAG_ENABLE` dosyasını USB'nin **en üstüne** ayrıca kopyala.
   `Target_GM` içine koyma. Dosyanın tam içeriği8 bayt `MGDIAG1` ve LF'dir;
   uzantı/BOM ekleme. Bu dosya RAR'ın içine eklenmedi.
3. TV'de daha önce kullandığın USB güncelleme yoluyla bu ayrı adayı dene.
   Güncellemenin gerçekten tamamlandığını ayır: %100 ve yeniden başlatma ile
   “zaten güncel” bildirimi aynı sonuç değildir. Kabul edilmezse sürüm/boot
   numaralarını değiştirerek tekrar deneme; mesajı aynen kaydet.
4. Yeniden başladıktan sonra USB takılı kalsın. Yaklaşık20 saniye bekle; sesi
   çalışan bir HD kanala geçip5 saniye, TRT Ultra HD'ye geçip15 saniye, sonra
   tekrar HD kanala geçip10 saniye bekle. Bu geçişler ilk otomatik açılıştan
   sonra, tanı kanalı hazırken yeni kayıt üretmek içindir.
5. USB'yi PC'de açıp **`MODGRUNDIG_DIAG.txt` dosyasını paylaş**. Gerekli veri
   budur; tüm USB içeriği, cihaz kimliği veya sertifika istemiyoruz.

Toplayıcı açılıştan itibaren600 saniye çalışır. Bu süre geçtiyse TV'yi yeniden
başlatıp denemeyi ilk10 dakika içinde yap. Etkinleştirme dosyası kaldırılınca
toplama kapanır. `MODGRUNDIG_DIAG.txt` ve `.MODGRUNDIG_DIAG.tmp` adları bu
opt-in tanıya ayrılmıştır; bu adlarda kişisel dosya bulundurma.

**Dosya oluşmazsa veya yalnız `MGDIAG_META` varsa bunu da sonuç olarak bildir.**
Bu, “HEVC düzeltmesi çalışmadı” demek değildir; tanı çıktısının erişimi veya
kanca yolunun çalışması ayrıca çözülmelidir. Fiziksel TV entegrasyonu henüz
doğrulanmadı. Buradan TV'ye/USB'ye yazma veya gömülü güncelleme scripti çalıştırma
yapılmadı; cihaz denemesi kullanıcının kontrolündedir.

## Gerçekte değişen parçalar

| Parça | Değişiklik |
|---|---|
| V7.9 APP/UI |Byte byte korunur; menü/ikon/volume tasarımı değişmez.|
| MSLIB / Common |Tek SDK video başlangıç çağrısına sayısal kayıt kancası.|
| customer_update / profile |TV başlatma satırına dokunmadan, ayrı toplayıcıyı arka planda başlatma.|
| customer_update / yeni dosya |15.208 baytlık kendi MIPS tanı toplayıcımız.|
| Diğer12 sıkıştırılmış payload |Byte byte aynı; offset/boot/kerneli değiştirme yok.|

Taban V7.9'dur. V7.10/SEMIH deneyi ve sonuç vermeyen A1 ses-mute yardımcı kodu
bu adaya dahil edilmedi. Kanca codec/PID/mute/decoder kararını değiştirmez.
Orijinal `SetVdecType` çağrısının argümanları, dönüşü ve gecikme slotundaki
`s7=0` davranışı korunur.

## Kayıt sözleşmesi ve kod kanıtı

`libmsrv_common.so:0x2d9d92fc..0x2d9d930c` SDK çağrı bloğu, mevcut boş RX
alanı `0x2d957000` içindeki728 baytlık yardımcıya yönlendirilir. Orijinal ELF
header/segment/section/GOT/dependency listesi ve dosya boyutu korunur.
[Üretici](../scripts/native_hevc_diag.py),
[son kanca kanıtı](../analiz/native-4k/diag-hooks/fifo-v3/patch-proof.json).
**Eski kök/fifo-v2 adayları tarihsel çıktıdır; paket yalnız fifo-v3'ü kullanır.**

Üretilen kayıt şeması:

```text
MGDIAG 1 rc video_codec audio_codec video_pid audio_pid pcr_pid mode mute_mask
```

Tüm alanlar unsigned decimal sayılardır; isim, string pointer, bellek dökümü,
anahtar, sertifika veya cihaz kimliği kaydedilmez. Bu ölçüm SDK başlangıç
sonucudur; ilk çözülmüş kare, ses PCM çıktısı veya bütün alt donanım hatası değildir.
Toplayıcının2/3 numaralı şemaları gelecekteki ölçümler için doğrulanır; bu
paketin kancası yalnız event1 üretir.

Yardımcı her olayda `/tmp/modgrundig-diag.fifo` yolunu önce `__lxstat64(3,...)`
ile doğrular: FIFO, root sahibi ve tam0600 gerekir. `O_NOFOLLOW|O_NONBLOCK|O_RDWR`
ile açtıktan sonra `/proc/self/fd/N` üzerinden `__xstat(3,...)` aynı koşulları
yeniden doğrular. Tek, en fazla191 baytlık write yapıp kapatır. FIFO yok, dolu,
izin/format/stat hatalıysa kayıt bırakılır; retry yoktur. Errno, GP, volatile
register'lar, HI/LO ve stack korunur. Yeni FDE yoktur; yardımcı içindeki
exception/asenkron unwind bu aşamada desteklenmez.

Toplayıcı sadece RAM'de son64 sayısal kaydı tutar; USB snapshot16KiB ile
sınırlıdır. USB keşfi/yazısı ayrı, deadline ile sonlandırılabilen tek worker'dadır.
FIFO okuyucusu USB I/O yapmaz. Gerçek USB sürücüsünde D-state'e takılan bir
worker derhal öldürülemeyebilir; bu durumda ikinci worker üretilmez. Disk
dayanıklılığı/hardware davranışı host testinden garanti edilmez.
[Toplayıcı sözleşmesi](../native-diag/README.md).

FIFO, okuyucu açılıp doğrulandıktan sonra hard-link ile atomik yayımlanır.
İlk QEMU turundaki partial-input testi bir kez zaman aşımına uğradı; tekil tekrar
geçti. Bundan ayrı, eski create-before-open kodunda ilk kaydın kaybolduğu
gecikme enjekte edilen host deneyiyle üretildi. Atomik yayın aynı regresyon
testini geçti. İlk QEMU hatasının tek kesin sebebi olduğu iddia edilmez.

## Gerçek doğrulamalar

| Kontrol | Sonuç / sınır |
|---|---|
| Native kanca |8 unittest,47 sınırlı MIPS vaka; dış çağrılar mock.|
| Toplayıcı host entegrasyonu |13/13 geçti; hata enjeksiyonu dahil.|
| Kendi MIPS toplayıcımız + gerçek glibc2.8/loader, QEMU |10 yaşam döngüsü testi geçti;3 host-only shim açıkça atlandı.|
| Paket pozitif/tamper testleri |6/6 geçti; CRC yeniden hesaplanmış header/boot/UBI sapmaları da reddedilir.|
| Dosya sistemi |MSLIB261 dosya ve54 link; customer profile +1 yeni collector, metaveri/CRC/readback kontrolü.|
| SWImage |14/14 payload doğrulandı;12 sıkıştırılmış slot tam aynı; V7.9 APP aynı.|
| RAR |17 dosya/11 dizin;16 dosya tam aynı; WinRAR ve7-Zip testi geçti.|
| Gerçek TV / 4K görüntü ve ses |Henüz doğrulanmadı; çalışan çözüm iddiası yok.|

QEMU'da TV uygulaması veya güncelleyicisi çalıştırılmadı. Yalnız kendi yeni
toplayıcımız, sentetik USB/mount fixture'ları ve ayrı kopyalanmış eski
loader/libc ile çalıştırıldı. Kernel/tuner/VDEC/DSP emüle edilmedi.

Çapraz derleme Clang/binutils ile yapıldı; yalnız `libc.so.6` bağımlılığı ve
GLIBC2.0/2.2/2.4 sembolleri bulunur. Yeni host libc'sine link yapılmadı.
`clock_gettime` için eski O32 Linux syscall, plain stat fonksiyonları için
glibc2.8 `__xstat` ailesi uyarlaması kullanılır.
[Derleme kanıtı](../analiz/native-4k/diag-sink/build-v2/build-proof.json).
Başlıklar [Debian bookworm mipsel çapraz geliştirme paketinden](https://packages.debian.org/bookworm/all/libc6-dev-mipsel-cross/download)
alındı; MIPS open/stat sabitleri
[Linux3.1 MIPS başlıklarıyla](https://github.com/torvalds/linux/tree/v3.1/arch/mips/include/asm)
karşılaştırıldı. Başlık sürümü hedef runtime sürümü olarak sunulmaz.

RAR SHA256: `26e7ea897cdd003b0973862f3e47908c7ced4fe23d5c970c4dc444e2bada177d`.
BIN SHA256: `71c0f7b40ceceb53e9ce3d12496951f0d7a3551f3bd246a6683212cb0d30e15a`.
[Aşama kaydı](../analiz/native-ui-candidate/v7.9-hevc-diag/phase-results.json).

İlk kanca/toplayıcı bağımsız incelendi. Son paket incelemesi alt ajan kota
sınırında kesildi; final revizyonları ve paket ana ajan tarafından kontrol
edildi. Tamamlanmış ikinci bağımsız release incelemesi iddia edilmez.

## Bu kayıtla ayrılacak sonraki karar

Çalışan HD ve TRT olayları yan yana karşılaştırılacak. TRT'de çağrı yoksa
başlatma yoluna ulaşma; başlangıç sonucu başarısızsa init/auth/tahsis; başarı
varsa TS/PCR, sequence/frame ve çıkış yolu araştırması ayrılacak. Başarılı SDK
başlangıcı tek başına UHD/Main10 çözüldüğü anlamına gelmez. Canlı kayıt gelmeden
rastgele başarı zorlama, framebuffer büyütme veya ölçekleme bayrağı paketi üretilmez.
