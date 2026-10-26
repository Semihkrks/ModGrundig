# Gerçek firmware üzerinde ilk UI adayı

Güncel devam: [v3 adayı ve gerçek MIPS laboratuvarı](UI_NATIVE_ADAY_V3.md). Bu sayfa23Ekim v2 ölçümlerini korur; v2 dosyaları değiştirilmedi.

23 Ekim 2026 · Dal: `codex/ui-soft-preview` · Durum: **çevrimdışı doğrulanmış, TV'de doğrulanmamış araştırma adayı**.

Kullanıcının firmware değişikliği isteği üzerine gerçek APP dosya sistemi yeniden oluşturuldu ve özgün SWImage'ın ayrı kopyasına yerleştirildi. Orijinal paketler değiştirilmedi. Güncelleme komutları, uygulamanın tamamı ve donanım servisleri çalıştırılmadı; TV'ye yazılmadı. Capstone/Unicorn doğrulaması yalnız küçük instruction penceresini, yapay ABI uyumlu çağrı hedefi ve yapay bellekle sınar.

Bu ilk native aşama bütün tarayıcı tasarımının aktarımı değildir. **Ana menünün tam beyaz yüzeyi/yüksekliği, kanal bilgi kartları, numara kartı ve animasyonlar bu pakete aktarılmadı.** Bunları hazır gibi göstererek kurulabilir paket iddiasında bulunmuyoruz.

## Üretilen dosyalar

| Çıktı | Kapsam |
|---|---|
| [GM_SWImage_UI_v2_OFFLINE_UNVERIFIED.bin](../analiz/native-ui-candidate/v2/package/GM_SWImage_UI_v2_OFFLINE_UNVERIFIED.bin) | Gerçek MStar kapsayıcı; yalnız APP payload'ı değişti, 42.483.736 bayt |
| [08_APP.ubifs](../analiz/native-ui-candidate/v2/package/08_APP.ubifs) | Yeniden oluşturulan APP, 28.823.552 bayt |
| [APP doğrulaması](../analiz/native-ui-candidate/v2/package/app-build-validation.json) | Dosyalar, izinler, sahiplik, zamanlar ve index CRC'leri |
| [Paket doğrulaması](../analiz/native-ui-candidate/v2/package/container-validation.json) | 14 LZMA payload, offsetler, padding, iç/dış CRC'ler |
| [Bağımsız diskten tekrar okuma](../analiz/native-ui-candidate/v2/package/independent-readback.json) | Paketleyici yardımcıları kullanılmadan ayrı kontrol |
| [Görsel manifest](../analiz/native-ui-candidate/v2/package/assets-manifest.json) | Bu APP üretiminde kullanılan 20 PNG'nin sabit kopyası |
| [Kod/yerleşim manifesti](../analiz/native-ui-candidate/v2/package/volume-manifest.json) | 14 Num kaydı ve 20 baytlık MIPS instruction penceresi |

SWImage SHA-256: `1a65ee2df062b8e0040b6fc54d34b0a7e731c974d6f03abb52c66b610dfb6357`.

APP SHA-256: `025b5b38a94a1976dece2aea27c87c7528fb72c599a82622263d3307d9891d6f`.

Tam SWImage, özgün certificate payload'ını da içerdiğinden yerelde tutulur; yeni aday BIN'leri `.gitignore` kapsamındadır. Dış servise yükleme/push yapılmadı. Raporlarda bu bölümün içeriği veya kimlik bilgileri yoktur.

`v1/package/08_APP.ubifs` ilk inceleme çıktısıdır; v2'de kaldırılan fazladan arka plan çizgisini içerir. **Güncel aday v2'dir.** `v1/assets` ve `v1/volume` üretim girdileri olarak kullanıldı; v2 altında manifestlerinin değişmez anlık kopyaları saklandı.

## Gerçekte değişenler

APP'deki 2.371 normal dosyanın **22'si değişti**, **2.349'u aynı kaldı**. Dizin ve symlink hedefi kümesi aynı. ELF/Num uzunlukları değişmedi; fonksiyon taşınmadı, yeni bağımlılık eklenmedi.

| Yer | Değişiklik | Kanıt |
|---|---|---|
| Home ikonları | Altı ayar ailesinin normal/odak için 12 PNG'si onaylı TV simgelerinden üretildi. OEM koyu/mavi yüzey korunarak açık normal ve cyan odak çizgisi kullanıldı. | Resource ID 985/986, 973/974, 975/976, 967/968, 979/982, 983/984; görsel manifestte özgün yol ve hash |
| Ses kaynakları | Beyaz arka plan, mavi speaker/mute simgeleri, üç ARC simgesi. Eski yuvarlak sürgü ve eski mavi dış halo şeffaf PNG oldu. | Image ID 674, 680, 681, 682, 4/5/6, 685; `VolumeControlFrame::OnCreate 0xfb9780` |
| Normal ses yerleşimi | İç panel 100×420 → 76×500; gösterge 10×200 → 6×320; sayı alanı 76 genişlik; speaker/mute 30×30. Üst parent alanı 76×540 ile paneli içerir. | `Num_res.bin`, 14 ID aşağıda; OnCreate ve Refresh'in literal RcGetNum çağrıları |
| Sıfırdaki ikon | Normal ses kolunda `IsMuted || volume==0` ise mute görseli seçilir. **Servise SetMute eklenmedi**, ARC yönlendirmesi değiştirilmedi. | `RefreshVolumeUI 0xfb7d18`, patch VA `0xfb81f8`, dosya ofseti `0xbb81f8` |

20 PNG'nin OEM boyut, bit derinliği, PNG color type ve alpha yeteneği korundu. Arka plana sahte sayı veya gösterge basılmadı; gerçek ilerleme widget'ı korunur. İncelemede yakalanan fazladan gri çizgi v2 öncesi kaldırıldı. [Sentetik ikon temas sayfası](../analiz/native-ui-candidate/v1/assets/native-home-contact.png) TV ekran görüntüsü değildir.

Num değişiklikleri:

| ID | Eski → yeni | Görev |
|---|---|---|
| `0x5a40 / 0x5a3f` | 140×460 → 76×540 | Normal root |
| `0x5a43 / 0x5a3e` | 100×420 → 76×500 | İç panel |
| `0x5a68 / 0x5a69` | 0,320 → 23,444 | Simge x/y |
| `0x5a67 / 0x5a66` | 100×100 → 30×30 | Simge boyutu |
| `0x5a77 / 0x5a79` | 100,20 → 76,18 | Sayı genişliği/y |
| `0x5a6c / 0x5a6d` | 45,88 → 35,92 | Track x/y |
| `0x5a6b / 0x5a6a` | 10×200 → 6×320 | Track boyutu |

Sayı/font ve global Color tabloları değiştirilmedi. `Color25=0xff0082d4` zaten mavi sayı/ilerleme yoludur. `ShowBorder(...Color13,8,0,2,-1)` çağrıları korunur; `8` parametresinin kesin semantiği kanıtlanmadığından köşe yarıçapı veya çizgi kalınlığı diye etiketlenmez.

## MIPS değişikliğinin sınırı

Özgün `dvbt_board` SHA: `51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916`. Aday: `9b64ca24f6f7ff0833284599f8bdec3db1b90c820d4fdfdb9ff26711c1ad41c2`.

20 baytlık pencere, 13 gerçekten değişen bayt:

```text
Özgün: 000000001800dc8f2900c2932700401000000000
Aday:  2900d0932c00c28f0b101000270040141800dc8f
```

Yeni sıra `lbu s0,0x29(fp)` → `lw v0,0x2c(fp)` → `movn v0,zero,s0` → `bne v0,zero,0xfb82a4` → `lw gp,0x18(fp)`. İlk instruction önceki virtual çağrının delay slotudur; son instruction branch delay slotudur. `s0` fonksiyon başında saklanıp sonunda geri yüklenir. Gerçek çağrının ABI'ye uygun callee-saved davranışı statik sözleşme olarak kalır; gerçek widget callee'si emüle edilmedi.

Tüm executable bölümlerde pencereye doğrudan branch/jump girişi ve ELF genelinde adres literal'i bulunmadı. Bu, hesaplanmış dolaylı girişleri bütünüyle dışlamaz. [202 durumlu doğrulama](../analiz/native-ui-candidate/v1/volume/validation.json) ses 0–100 × mute 0/1, iki delay slotu, argümanlar, GP, volatile register clobber, `s0` ve epilogue geri yüklemesini kontrol eder. Ses servisi veya fiziksel sesin gerçekten mute olması bu testin kapsamında değildir.

## ARC bulgusunun düzeltilmesi

Önceki host modelinde CEC reddi yerel sese düşürülüyordu. `VolumeControlFrame::OnKey 0xfb8c7c` assembly'sinde kabul kolu `0xfb9184..0xfb91a4`, ret kolu `0xfb91ac..0xfb91d4` üzerinden aynı çıkışa gider. Yerel ses kolu kapılar false olduğunda `0xfb91e0` sonrasında başlar. **Ret sonucu da yerel sesi değiştirmez.**

`tv-model.js`, eski yardımcı `state.js`, Node ve Chrome kontrolleri bu kanıta göre düzeltildi. Ret halinde yerel seviye ve ARC mute durumu korunur; test etkisi `accepted:false` bildirir. Gerçek firmware'in bu kod yolu değiştirilmedi. Ses ayar menüsünün bütün ayrı native çağrı yolları için ayrıca tam semantik eşlik kanıtı çıkarılmış sayılmaz.

## Dosya sistemi ve kapsayıcı

Host `mkfs.ubifs` 2.3.0, resmî Ubuntu `mtd-utils 1:2.3.0-1ubuntu2` paketinden ayrı araç dizinine açıldı; kurulum scripti çalıştırılmadı. DEB SHA `b0a85919c52c14d500572494e522eae3d16e64f9259e52d0f4184c6c9a250fd6`; executable SHA APP raporundadır.

UBIFS format **4**, flags **0**, min_io **2048**, LEB **126976**, max LEB **321**, LZO, fanout8/log4/orphan1 kullanıldı. Format başlığı elle düşürülmedi; küçük host denemesi ve son superblock kontrolüyle format4 üretimi doğrulandı. Linux3.1'in UBIFS format sabiti4'tür; eski kodun yeni biçimleri desteklemeyeceği kaynakta açıklanır. Bu kontrol hedefte mount edildiği anlamına gelmez. [Linux3.1 birincil kaynak](https://raw.githubusercontent.com/torvalds/linux/v3.1/fs/ubifs/ubifs-media.h).

APP özgün229 → aday227 LEB oldu. Özgün 40MiB volume oluşturma komutu değişmedi. Yeni inode numaraları, UUID, yerleşim ve dosya sistemi iç muhasebesi özgün baytların kopyası değildir. Özgün APP yeniden açılarak canonical ağacın bütün dosya hash'leri doğrulandı; ardından yalnız 22 izinli dosya değişti. Ayrı fakeroot oturumunda orijinal mode/uid/gid/mtime geri kondu ve yeni index'te doğrulandı. 2.773 nlink kaydı bağımsız okumada da eşleşti.

APP'nin LZMA-alone başlığı `5d`, dictionary64MiB ve bilinen açılım boyutunu korur. Host liblzma `LZMA1EXT` ile özgüne uygun end-marker içermeyen akış üretildi; Python encoder'ının bilinmeyen boyut başlığını elle değiştirmek denemede reddedildiği için kullanılmadı. `be ef` trailing baytları korundu.

- APP source offset: `0x16b4000`, slot: 17.432.576 bayt.
- Yeni sıkıştırılmış APP: **17.404.876 bayt**, slotta **27.700 bayt** kaldı. Taşmada paketleyici payload taşımak yerine hata verir.
- `filepartload`, `mscompress7`, APP CRC uzunluğu/değeri ve iki `ubi write` boyutu güncellendi. Diğer bölüm komutları aynı.
- Footer `0x2884000`: header CRC32 `790b05eb`; `0x2884004`: image CRC32 `df0b7d8a`; sonraki16 ASCII bayt aynı.
- Bütün bölüm offsetleri, diğer13 sıkıştırılmış payload/padding'i ve GM_Boot aynı.

## Gerçek kontroller

| Kontrol | Sonuç | Sınır |
|---|---|---|
| PNG decode/format/alpha/chunk CRC, tekrar üretim | 20/20 | TV renderer kontrolü değildir |
| Görsel plan/path olumsuz denemeleri | 7 reddedildi | Kaynak araç girişleri |
| Num/ELF patch regresyonları | 7/7 geçti | Host, hash/allowlist ve deterministik çıktı |
| MIPS instruction senaryoları | 202/202 geçti | Yapay callee; ses/CEC servisi çalışmaz |
| APP builder path/symlink/hardlink/allowlist testleri | 7/7 geçti | Host dosya güvenliği |
| Yeniden çıkarılan APP dosyaları | 2.371/2.371 eşleşti | Staging içeriğiyle tam byte hash kontrolü |
| APP inode/dizin/symlink metadata | 2.773/2.773 | Mode/uid/gid/type/mtime; nlink ayrıca eşleşti |
| Committed UBIFS node CRC | 18.988/18.988 | Index'in eriştiği DATA/INO/DENT/IDX; journal replay yok |
| Paketleyici regresyonları | 21/21 geçti | Bilinen boyutlu LZMA, bozulma, taşma, kaynak/output ve komut kontrolleri |
| Yeni kapsayıcı tekrar açma | 14/14 | İç CRC ve iki dış CRC geçti;13 bölüm değişmedi |
| Bağımsız dosyadan okuma | Geçti | Paketleyici helper'ları yerine eski parser+stdlib LZMA/CRC |
| Node önizleme testleri | 48/48 | 37 aktif model +11 eski yardımcı; firmware testi değildir |
| Gerçek Chrome genel akış | Geçti | 0/100/mute/ARC, yön/OK/Geri, 1920/1280/390 ölçekleri; JS hatası0 |
| Gerçek Chrome özellik taraması | 24 menü/156 satır geçti | Demo USB/PVR/RF, fiziksel servisleri çalıştırmaz |

[Host genel sonuç](../analiz/ui-modernizasyon/browser-tests.json), [özellik taraması](../analiz/ui-modernizasyon/features-browser-tests.json). Kaynak kapsamını artırmak için yeniden 226 ELF taraması/decompile tekrarı yapılmadı; bu aşamada mevcut adresli çıktılar yeniden kullanıldı.

## Devam etmeden kapanması gereken farklar

1. **Görsel eşlik:** beyaz ses arka planı P4 opaktır; yuvarlak transparan köşe ve MUF clipping/stretch davranışı doğrulanmadı. 30px ikonun son ölçeklenmesi, font baseline'ı ve Color13 border görünümü cihazda görülmedi. Beyaz browser kapsülünün eksiksiz aktarıldığı iddia edilemez.
2. **Ana menü ve diğer kartlar:** mevcut native koyu yüzeyler ve menü yüksekliği korunuyor. Kanal listesi, bilgi bandı, numara kartı ve ayar sayfalarının tamamı henüz native modern tasarıma geçirilmedi; bunların eski işlev kodu korunur.
3. **Animasyon:** tarayıcıdaki yumuşak geçişler native paket içinde yok. Önceki C motion yardımcısı MIPS'e bağlanmadı; global animasyon gate'i açılmadı. Mevcut event/timer davranışları kullanılır.
4. **Dolaylı resource tüketicileri:** thumb681 ve halo685 için literal OnCreate bağları var; bütün dinamik ID kullanıcıları çözümlenmiş değil.
5. **Cihaz kabulü:** sağlanan RAR'ın aktif TV firmware dump'ıyla aynı olduğu kanıtlanmadı. CRC eşleşmesi kriptografik imza veya bootloader kabulü değildir. SecureROM/`ncishash` izleri ve gerçek kabul/kurtarma yolu çözülmeden bu aday kurulabilir sürüm sayılmaz. İmza kontrolü kapatılmadı veya atlatılmadı.

Bu yüzden sonraki iş doğrudan yükleme değil; eksik native görsel/kod yollarını kapatıp aynı dosya/paket doğrulamalarını yeni revizyonda tekrarlamaktır. TV testi/yazımı ayrıca açık yetki ve somut cihaz uyumu gerektirir.

## Yeniden üretim kaynakları

`scripts/build_native_tv_assets.py`, `render_native_tv_assets.mjs`, `build_native_volume_patch.py`, `build_native_app.py`, `repack_native_swimage.py`, `verify_native_release.py`.

APP builder WSL'de ubi-reader Python'u ile **tek fakeroot oturumunda** çalışır. `--revision v2` veya `v3` yeni hedef bekler; var olan imajı/staging'i ezmez. Paketleyici de mevcut dosyayı ezmez. Tekrar üretimde yeni revision seçilmelidir. UBIFS UUID ve inode yerleşimi nedeniyle dosya sistemi imajının byte-deterministik olduğu iddia edilmez; PNG ve Num/ELF overlay'lerinin tekrar üretimi hash olarak deterministiktir.

Kullanılan birincil beceri: `reverse-engineer-anything`. Üç alt ajan PNG aktarımı, Num/MIPS patch'i ve kapsayıcı biçimini ayrı sahiplikle yürüttü; bağımsız incelemedeki iki builder açığı (görsel allowlist ve özgün APP'den hash zinciri) kapatıldı.
