# Boot ve format: ek ham bayt kanıtları

22 Ekim 2026. Bu kayıt mevcut çıkarımların açık noktalarını daraltır. Firmware, gömülü programlar, güncelleme scriptleri ve flash komutları çalıştırılmadı; yeniden paketleme veya cihaz erişimi yapılmadı. Bu çalışmada Ghidra projesi açılmadı. Bulgular **ham bayt/ELF çözümü ve mevcut statik indeks sorgusudur; REA Evidence değildir**.

Makine kaydı: [boot-format-ek-kanitlar.json](../../analiz/boot-format-ek-kanitlar.json). Kaynak SHA-256, ham instruction word'leri ve ofsetler oradadır. Kaynak format/CRC kaydı: [bolum-haritasi.json](../../analiz/bolum-haritasi.json).

## Paket tablosunda eksik kaydedilen komut

`GM_SWImage.bin:0x122c`, beş mboot CRC/karşılaştırma grubundan sonra şunu içerir:

```text
ncishash 0x84000000 0x84010000 0x84020000 0x84030000 0x3800 0x84033800 $(filesize) #mboot
```

`scripts/unpack_mstar.py`, bölüm komutlarında yalnız seçilmiş başlangıçları kaydeder; `ncishash` bu filtrede yoktur. Komutun eski JSON'da bulunmaması pakette bulunmadığı anlamına gelmez. Bu dosya parser'ı değiştirmez.

Header `0x208a` paket içindeki bootcmd'yi, `0x20db` RFS parametrelerini, `0x2152` bootargs kalıbını ve `0x21de` `setenv verify n` satırını içerir. Bu env verileri cihazın aktif environment dump'ı değildir. `verify n` tek başına kriptografik imza kontrolünün olmadığı sonucunu vermez.

## Akış sonu baytları

Mevcut decoder'ın 14 akış için kaydettiği iki kullanılmayan trailing baytın tamamı `BE EF`'tir. Her akışın kaynak son-ofseti, iki baytı, açılmış payload hash'i ve önceki CRC eşleşmesi ek JSON'da ayrı kaydedildi. Baytların anlamı ve bootloader tarafından kontrol edilip edilmediği henüz çözülmedi.

`05_KL.bin`: uImage header'ı 64 bayt, beyan edilen payload 1.758.775 bayt; payload sonu dışlayıcı ofseti `0x1ad677`'dir. Dosya 1.758.840 bayttır ve payload'dan sonra tek `FF` bulunur. Önceki header/data CRC eşleşmeleri korunur. Bu tek baytın anlamı bilinmiyor.

## Raw mboot komut kayıtları

`04_mboot.bin` SHA-256: `5c400ef10fccdfbfcd6e3fb2b2249b05150b0d03508c39761bb6284500fcaaa6`.

Altı komut kaydındaki pointer/isim/açıklama ilişkisi, aday `VA − dosya_ofseti = 0x8e1efd80` farkıyla tutarlıdır. Bu, doğrulanmış runtime relocation tabanı değildir. Aşağıdaki dosya ofsetleri bu aday eşlemeden türetilmiştir; ham tablo word'leri ek JSON'dadır.

| Komut | Tablo dosya ofseti | Saklanan handler pointer'ı | Aday handler dosya ofseti |
|---|---|---|---|
| filepartload | `0x1fa20c` | `0x8e213628` | `0x238a8` |
| mscompress7 | `0x1fa3cc` | `0x8e215c80` | `0x25f00` |
| crc32 | `0x1faebc` | `0x8e2465cc` | `0x5684c` |
| ncishash | `0x1fb098` | `0x8e24b22c` | `0x5b4ac` |
| ncisbl | `0x1fb0b4` | `0x8e24a4d0` | `0x5a750` |
| bootm | `0x1facfc` | `0x8e243e68` | `0x540e8` |

`ncishash` adı dosya `0x1b3eb0`, açıklaması `0x1b3ebc`, help metni `0x1b3ee8`'dedir. Açıklama `write cis and hash[0-2] for Secure ROM boot` der. Handler gövdesinde hash yazma/hata metinlerine ve başka alt yordam çağrılarına ham instruction bağlantıları bulundu. **Ad/help metni algoritma, imza doğrulaması veya paket kabul politikası kanıtı değildir.** Yeni raw handler Ghidra incelemesi ayrı kanıt olarak tutulmalıdır.

## CRC32 algoritması ve iki ret dalı

`crc32` handler dosya `0x568d0`'da `0x96260` wrapper'ına `jal` yapar. Wrapper `0x96268`'de `0x96130` core'unu çağırır; çağrı öncesi seed'i ve sonrasında sonucu bit düzeyinde tersler.

Core'un `0x96144/0x96148` instruction'ları aday `0x8e3afe20` tablo adresini kurar; bu dosya `0x1c00a0`'a karşılık gelir. Buradaki 256 uint32'nin tamamı reflected `0xedb88320` polinomu ile üretilen CRC32 tablosuyla eşleşti. Böylece algoritma eşleşmesi yalnız `crc32` adına dayanmaz.

Whole-image CRC metinleriyle bağlantılı iki kod aralığı aynı wrapper'ı çağırır:

| Yol | CRC çağrısı | Eşitlik kontrolü | Eşit hedef | Farklı değerde ret |
|---|---|---|---|---|
| A | dosya `0x24288` | `0x24294`: `beq s2,s5` | `0x2431c` | `0x24314 → 0x23ee8`; `s2=-1`; `0x24378`'de `v0=s2` |
| B | dosya `0x2482c` | `0x24838`: `beq s3,s1` | `0x248c4` | `0x248bc → 0x24468`; `s1=-1`; `0x24940`'ta `v0=s1` |

Beklenen CRC'nin tam kaynağı, encrypted-image dalları, bütün girişlerden bu iki yola ulaşım ve üst çağıranın hata politikasının tamamı henüz çözülmedi. Bunlar kriptografik imza veya imzasız paket kabulü hükmü değildir.

## Kernel wrapper → açılmış kernel

uImage entry `0x84000000` ile wrapper dosya `0x40` eşlemesi kullanıldı. Aşağıdaki kontrol akışı ham instruction'lardan okunur:

1. Wrapper dosya `0x1a8/0x1ac`, `$ra=0x84000180` kurar.
2. `0x1b0/0x1b4`, `$k0=0x84000438` kurar; `0x1b8`'de `jr k0` vardır. Hedef, dosya `0x478`'deki açma yordamı adayıdır.
3. Dönüş adresindeki dosya `0x1c0..0x1cc`, `a0..a3`'ü `s0..s3`'ten geri yükler.
4. Dosya `0x1d0` `lui k0,0x803a`, `0x1d4` `ori k0,k0,0xf190`, `0x1d8` `jr k0`: hedef `0x803af190`.
5. Açılmış kernelin aday `0x80000000` tabanında bu hedef dosya `0x3af190`'dır. Burada CP0 kurulumu ve BSS temizleme kodu vardır. Dosya `0x3af224` doğrudan `0x804e3584`'e atlar.

Açılmış kernel SHA-256: `43e9cf9a68cefafb14beb936cd37f801a69412b69cfc127bd7c866fe431c3426`. `0x804e3584` henüz `start_kernel` olarak adlandırılmadı. Bootloader `bootm` kopyalama/relocation davranışı ve kernelin init seçimi açık kalır.

## ELF entry → main callback

| ELF | e_entry | Callback'i kuran instruction'lar | Startup çağrısı | Relocation kanıtı |
|---|---|---|---|---|
| dvbt_board | `0x4aa570` | `0x4aa57c/0x4aa580`: `a0=0xfd0784` | `0x4aa5b0 → 0x4aa330` PLT stub | `.rel.plt` dosya `0xaa170`, slot `0x10c3e1c`, type 127, dynsym 5 `__libc_start_main` |
| busybox | `0x4059f0` | `0x4059fc/0x405a00`: `a0=0x408020` | `0x405a30 → 0x4048a0` PLT stub | `.rel.plt` dosya `0x3994`, slot `0x4ed1f0`, type 127, dynsym 97 `__libc_start_main` |

Böylece stripped `FUN_00fd0784` ve `FUN_00408020`, yalnız işlev adlarına dayanmayan main callback adayları olarak bağlanır. Gerçek loader bağlaması cihazda gözlenmedi.

## Busybox sh → ash → profile

Busybox dosya `0xd40ce`'deki applet ad dizisi 261 kayıt; `0xc12e0`'daki fonksiyon pointer dizisi 261 kayıttır. `ash` indeks 7 ve `sh` indeks 187 aynı `0x453d70` hedefini taşır. `init` indeks 97 ve `linuxrc` indeks 109 aynı `0x4af9c8` hedefini taşır. Dispatcher `0x407af0..0x407b08`, tablo adresini kurar, indeksi 4 ile çarpar, pointer yükler ve `jalr` yapar.

Ash `0x45437c`'de argv0'ın ilk baytını yükler; `0x454380/0x454384` bunu `'-'` (`0x2d`) ile karşılaştırır. Eşleşen yolda `0x454390` bir flag baytını 1 yapar. `0x454398/0x45439c`, sıfır flag'de profile yolunu atlar; diğer yolda `0x4543a4/0x4543a8` `a0=/etc/profile` kurar ve `0x4543ac → 0x453d28` çağrısı vardır.

`/etc/inittab` string'i `0x4d3088`, default `/etc/init.d/rcS` `0x4d3098`'dedir; `0x4aef50` ve `0x4aef78` bunları kullanır. Init action parser'ının `-/bin/sh`'den argv0 oluşturma ayrıntıları henüz tamamlanmadı. Profile ve autorun symlink zinciri [ana boot kaydında](BOOT_VE_FORMAT.md) korunur.

## Main içindeki UI başlangıç adayları

[Mevcut ham MIPS çağrı indeksinde](../../analiz/ui-kod-cagrilari.json), `0xfd0784` gövdesinde şu GOT-simge bağlantıları vardır:

| Call-site | Simge adayı |
|---|---|
| `0xfd0810` | `MSrv_Control_TV::Build` |
| `0xfd0b70` | `MSystem::Initialize` |
| `0xfd0d7c` | `InitMSrvControl` |
| `0xfd22a0` | `StartMsrv` |
| `0xfd22c8` | `MResourcePkg::ReadResProfile` |
| `0xfd2364` | `RegisterAllHotKey` |
| `0xfd2434` | `MApplet::Run` |
| `0xfd24e8` | `ArTvManager::NotifyBootUpCompleted` |
| `0xfd2b98` | `MSystem::Run` |

Bu liste statik instruction/GOT-simge adaylarıdır; tüm dalların uygulanabilirliği, koşulsuz çağrı sırası veya runtime binding kanıtı değildir. Cihazda gözlem, tam başlangıç koşulları ve sanal dispatch çözümü açık kalır.
