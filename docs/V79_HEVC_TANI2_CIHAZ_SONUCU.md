# V7.9 tanı2: görüntü hazır durumu ve USB kaydı

1 Kasım 2026. Kullanıcı yeniden ses/görüntü gelmediğini bildirdi. **4K hedefi
sağlanmadı; bu kontrolde yeni firmware üretilmedi veya TV'ye yazılmadı.**
`reverse-engineer-anything` akışı ve iki ayrı alt ajanla kayıt, monitor yolu ve
USB taşıması incelendi.

## Yeni gerçek cihaz ölçümü

D: çıkarılabilir FAT32 sürücüdür. Güncelleme düzenindeki **17 dosyanın tamamı**
tanı2 manifestindeki hash'lerle eşleşir; etkinleştirme dosyası tam olarak
`MGDIAG1\n` içerir. Görünür `MODGRUNDIG_DIAG.txt` yine **0 bayttır**.
Salt okunur CHKDSK tekrar 16 KiB kayıp zincir bildirdi. Bağımsız FAT yürüyüşü
iki FAT kopyasının aynı olduğunu ve tek orphan cluster **175** bulunduğunu
doğruladı. Sürücü yalnız `rb` açıldı; bu aşamada onarım yapılmadı.

Yerelde korunan cluster SHA256:
`5cbc7fe0e861192254a18922ebefc26a79a7e7ec43104add379580ee754a0a64`.
Önceki tanı1 kurtarma dosyası kullanılmadı. Yeni kayıtta metadata
`MGDIAG_META 1 18 0 0 18`: **7 init + 11 durum olayı**, 0 ret / 0 overlong.
[Sayısal kayıt ve doğrulamalar](../analiz/native-ui-candidate/v7.9-hevc-diag2/recovered-device-feedback-2026-11-01.json).

| Geçiş / örnek | Süre, ms | GetFrameCnt sonucu | MAD kilidi | ready92 | pending | Mute |
|---|---|---|---|---|---|---|
| Codec7, PID4855/4955 |2009 / 4011 / 6018|5 / 9 / 13|1 / 1 / 1|0 / 0 / 0|0 / 0 / 0|3 / 3 / 3|
| Önceki uzun codec2, PID4300/4500 |2029 / 4002 / 6044|25 / 74 / 125|1 / 1 / 1|1 / 1 / 1|0 / 0 / 0|0 / 0 / 0|
| Sonraki codec2, PID4300/4500 |2003 / 4042 / 6010|13 / 61 / 111|1 / 1 / 1|1 / 1 / 1|0 / 0 / 0|0 / 0 / 0|

Bu üç grupta video/audio_started baytları 1/1'dir. İki daha erken, kısa codec2
örneğinde de ready92=0 / mute3 görülür; sorun örüntüsünün yalnız HEVC'ye özgü
olduğu iddia edilmez. Aynı HEVC PID çifti için codec7 öncesinde codec1 init
olayı vardır; sebebi ve geçici codec bildirisinin etkisi ölçülmedi.
Servis adı, çözünürlük, bit derinliği, PCM ve gerçek görüntü çıktısı kaydedilmez.

## Ölçümün doğru yorumu

Yeni event4 kayıtları sampler'ın fiziksel cihazda çalıştığına kanıttır. D:'deki
paket doğrulandı; aktif flash içeriğinin ayrıca dump/hash kontrolü yapılmadı.
Codec7 init sonucu1, MAD kilidi1 ve started1/1, sesin duyulduğu veya UHD
görüntünün başarıyla çözüldüğü anlamına gelmez.

**GetFrameCnt, ekrana basılmış kare sayacı değildir.** SDK `0x2cba739c` →
legacy API `0x2d6604bc` → EX `0x2d63f994` → V2 `0x2d64ae28` zincirinde,
HVD kolu `0x2d64af98..0x2d64afc0` **DecodeCnt + SkipCnt** döndürür.
Decode HAL selector'ı `0x1202`, skip selector'ı `0x1400`'dür; ayrı display
sayacı `0x1402` kullanır. Skip API'sinin `0x2d64adf4..0x2d64ae08` çağrısı
aynı `GetData(stream,1)` yolunu kanıtlar. Artışın tamamı atlanan karelerden
gelebilir; log bunu ayrıştırmaz. SDK wrapper'ı nesne argümanını kullanmadan
legacy global API'ye gider. Artışı gerçek görüntü veya FPS ölçümü diye
sunmuyoruz. [Hash ve adresli statik inceleme](../analiz/native-ui-candidate/v7.9-hevc-diag2/static-feedback-review.json).
Kaynak sampler, mevcut monitorün
`DoVideoSync` çağrısı sonrasında örnek alır:
[kanca ve alan adresleri](../scripts/native_hevc_diag_stage2.py).

Önceki yalnız init kaydından farklı olarak, **yaklaşık 2–6 saniye boyunca
ready92=0 / mute3 kalması** artık ölçülmüştür. Uzun HD örnekleriyle karşılaştırma,
incelemeyi görüntü bilgisi/hazır olma ve buna bağlı mute temizleme koşullarına
daraltır. Hangi alt çağrının başarısız olduğu henüz kayıtta yoktur; hazır
bayrağını zorlamak bu eksik koşulları gerçekleştirmez.

`DoSetMode:0x2d9d6d58` içinde started denetimini, `GetDispInfo` çağrısı
`0x2d9d6df8` ve `GetActiveVdecType` çağrısı `0x2d9d6e98` izler. Bunlardan
önce/sonra çıkış olabilir; video/timing sanal çağrılarından sonra
`0x2d9d6fbc` ready92'ye1 yazar. Bu, display kurulumunun bu noktaya ulaştığı
anlamındadır; nihai çıktı başarısı değildir. İncelenen SDK GetDispInfo gövdesi
HEVC16'yı kabul eder, açık bir1920/1080 üst sınır reddi içermez. Alt API
başarısızlığı veya sıfır boyut yine başarısız dönebilir. Aktif codec dönüşümü
de VDEC16→DTV7 destekler. **Log, hangi ön kapıda kalındığını ölçmüyor.**

`CheckVideoStatus:0x2d9d4c30` yaklaşık1 saniye arayla toplam sayacın ilerlemesini
denetler; sadece skip artarken de bu denetim ilerleme görebilir. `DoMonitor`
ready1/AFD kolu `0x2d9d6d50` üzerinden bu kontrol yoluna geri döner; ready1
olduğunda bütün durum kontrolünün atlandığı varsayılmaz.

## USB sorunu ayrı bir bulgudur

Önceki onarım ve temiz kontrolden sonra kayıp zincir tekrar oluştu. RAM/snapshot
doğrulamaları, verinin fiziksel USB üzerinde kalıcı ve metadata ile tutarlı
olduğunu garanti etmemiştir. TV'nin FAT sürücüsü, çıkarma zamanı ve USB donanımı
arasındaki kesin neden ayrıştırılmadı. Ham cluster ve önceki yedekler yalnız
yerel `tools/` altında tutulur; dışarı yalnız sayısal olaylar yayımlanır.

Toplayıcıda somut bir kalıcılık açığı düzeltildi: önceki kod TEMP dosyasını
eşitleyip kapatıyor, rename sonrasında yalnız dizini eşitliyordu. Linux3.1
[`vfat_rename`](https://github.com/torvalds/linux/blob/v3.1/fs/fat/namei_vfat.c)
dosya inode'unu yeni directory entry'ye bağladıktan sonra tekrar dirty eder;
[`generic_file_fsync`](https://github.com/torvalds/linux/blob/v3.1/fs/libfs.c)
çağrılan inode'un metadata'sını eşitler. FAT'ın
[`fsync` yolu](https://github.com/torvalds/linux/blob/v3.1/fs/fat/file.c)
bu mekanizmayı kullanır. Bu nedenle yalnız directory fsync'in child-file inode
yerine geçtiği varsayımı desteklenmez. Bu gözlem, TV'deki vendor FAT kodunun
birebir aynı olduğunu veya tek kök nedenin bu olduğunu kanıtlamaz.

[Kaynak düzeltmesi](../native-diag/modgrundig_diag_sink.c) aynı FD'yi açık tutar:
file fsync → rename → **aynı file FD'ye yeniden fsync** → FD/path inode-boyut
kontrolü ve tam readback → directory fsync → close. Yayın sonrası hata çıkarsa
çıktı silinmez/truncate edilmez; başarısızlık olarak yeniden denenir. Önceki
snapshot'a geri dönülmüş gibi davranılmaz. Deadline/USB güç kaybı ve gerçek
vendor FAT kalıcılığı hâlâ cihaz testi gerektirir.

**20/20 host testi geçti**; iki yeni test sıralamayı ve rename sonrası
fsync/stat/path/read hatalarını sınar. Yeni kendi MIPS toplayıcımız stock
glibc2.8 ile derlendi: **12 QEMU testi geçti, 8 host-only test SKIP**.
QEMU TV donanımını veya gerçek3.1 kernelini emüle etmez.
[Doğrulama](../analiz/native-ui-candidate/v7.9-hevc-diag2/postrename-source-validation.json).
Bu kaynak düzeltmesi henüz firmware paketine alınmadı; **D:'deki tanı2
paketi değiştirilmedi**. Çalıştırılan yalnız kendi toplayıcımızdır.

## Bu aşamanın kapsamı

- 18 gerçek olay çözümlendi: 7 init, 11 monitor örneği; yeni decompile sayısı0.
- USB'deki 17 paket dosyası ve marker doğrulandı.
- Salt okunur kurtarıcının 7 sentetik testi geçti; firmware programı çalıştırılmadı.
- Mevcut sampler'ın fonksiyon bağlantıları yeniden anlamlandırılıyor; dolaylı
  görüntü callback'inin runtime dönüşü ve decoder hata/display bilgisi hâlâ yok.
- Decode/mute zorlaması, bellek genişletme veya yeni test paketi yapılmadı.

Sonraki dar hedef, `DoSetMode` giriş sayısı, mevcut `GetDispInfo` dönüşü ve
width/height/fps, mevcut `GetActiveVdecType` dönüşü ile ayrı
decode/skip/display/error sayaçlarını ayırmaktır. USB aktarımı da tekrar
veri kaybetmeden ölçüm alınabilmesi için incelenir. Eski paket tekrar tekrar
yüklenerek farklı sonuç beklenmez.
