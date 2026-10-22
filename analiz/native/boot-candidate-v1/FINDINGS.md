# 04_mboot: beş ham boot komutunun sınırlı statik analizi

22 Ekim 2026. Kullanılan beceri: `reverse-engineer-anything`. Doğrudan Ghidra 12.1.4 çıktısıdır; REA Evidence kaydı değildir. Firmware kodu, güncelleme komutları veya çıkarılan programlar çalıştırılmadı. Kaynak baytları değiştirilmedi.

Kaynak `analiz/bolumler/04_mboot.bin`, 2.078.028 bayt; SHA-256 `5c400ef10fccdfbfcd6e3fb2b2249b05150b0d03508c39761bb6284500fcaaa6`. Komut kayıtlarından türetilen **aday** VA−dosya farkı `0x8e1efd80` kullanıldı. Bu, cihazın gerçek yükleme adresi kanıtı değildir. Ghidra raw bloğu `0x8e1efd80..0x8e3eb2cb`; program image-base metaverisi `0` kaldı. Ayrı yeni proje `/home/semih/grundig-analysis/ghidra-projects/GrundigBootCandidateV1`.

| Komut | Kayıt dosya ofseti | Handler dosya ofseti | Aday VA | Listing body baytı |
|---|---:|---:|---:|---:|
| filepartload | 0x1fa20c | 0x238a8 | 0x8e213628 | 284 |
| mscompress7 | 0x1fa3cc | 0x25f00 | 0x8e215c80 | 260 |
| crc32 | 0x1faebc | 0x5684c | 0x8e2465cc | 240 |
| ncishash | 0x1fb098 | 0x5b4ac | 0x8e24b22c | 2404 |
| ncisbl | 0x1fb0b4 | 0x5a750 | 0x8e24a4d0 | 3420 |

Her kayıt için ad/handler pointer eşleşmesi, hizalama, ham blok içinde bulunma ve kaynak hash'i doğrulandı. Ham bloğun çalıştırılabilir işareti yalnız bu yeni analiz veritabanındaki varsayımdır. İşleyici başına 8 KiB akış penceresi, bütün program analizi kapalı, decompile başına 30 saniye ve headless için 240 saniye sınırı uygulandı. `gp`/`t9` değeri zorlanmadı. 5/5 decompile tamamlandı; listing içinde 1.652 instruction, 317 xref ve 170 call xref sayıldı. Bunlar bütün bootloader kapsamı değildir. Özellikle switch dolaylı akışları nedeniyle listing function-body kapsamı ile decompiler'ın çıkardığı akış kapsamı aynı sayılmaz.

## ncishash ve ncisbl

`summary.json` içindeki kayıt pointer'larıyla okunan `ncishash` usage metni `write cis and hash[0-2] for Secure ROM boot` der. Help alanı CIS/PPM/PNI, Hash0 adres/boyutu, Mboot adres/boyutu ve opsiyonel Hash1 boyutunu listeler. Bu metin bir yazma komutunu tarif eder; kriptografik doğrulama çağrısı kanıtı değildir.

Kod bağımsız olarak bu yorumu destekler: `candidate_cmd_ncishash.c:76` parametreleri `0x8e375d0c` alt işlevine gönderir (callsite `0x8e24b3c0`, hedef dosya `0x185f8c`). `:136` sonrasında ek adres/boyut argümanları ayrıştırılır ve üç bölgelik döngü kurulurken kaynak+boyut çiftleri hazırlanır. Döngüdeki `0x8e376378` çağrıları `0x8e24b8c8` ve `0x8e24ba04` adreslerindedir; hedef dosya `0x1865f8`. Bunların çevresindeki sabit mesajlar `write hash%d @ block %X`, `error: write hash%d @ block %X`, `write hash%d backup @ block %X` der. Bölge sınırı başarısızlığında `not enough block for hash2` dalı vardır. Sonrasında `0x8e375648` çağrısı `0x8e24baa0` adresindedir (hedef dosya `0x1858c8`); başarısızlık mesajı `Update CIS for ROM fail` olur. Alt işlevlerin gövdeleri bu aşamada incelenmediğinden NAND yazma ayrıntıları, hash nesnesinin biçimi ve ROM'un bunu nasıl kabul ettiği açık kalır.

Her iki işleyicide önceki ve mevcut partition kayıtlarının alan karşılaştırmaları da vardır. `ncishash` callsite `0x8e24b6d4` ve `ncisbl` callsite `0x8e24a978`, sabit `nand erase.force` metnini aynı `0x8e25f5d0` hedefine verir. Bu **çalıştırılmış işlem değildir**; ham kodun olası komut-dispatch davranışına dair statik çağrı kanıtıdır. Alt işlevin gerçek dispatch semantiği ayrıca çözülmelidir.

`ncisbl` usage metni CIS, bootloader ve uboot yazma yolunu tarif eder; kod `ncishash` ile `0x8e375d0c`, `0x8e376378`, `0x8e375648` hedeflerini paylaşır. Bu ortak kod bağlantısı ve yukarıdaki mesajlar, iki komutu provisioning/programlama araştırma hattına yerleştirmeyi destekler. Komut isimlerinden güvenli boot'un etkinliği, imza algoritması, zorunlu kabul kontrolü veya bunun atlatılabilirliği çıkarılmaz.

## Diğer üç işleyici

- `crc32`: en az üç argüman kontrolü, hex adres/boyut ayrıştırması, seed `0` ile `0x8e285fe0` çağrısı (`0x8e246650`, hedef dosya `0x96260`), sonuç yazdırma ve opsiyonel adrese sonuç saklama kodu görüldü. Bu işleyici kendi içinde beklenen imzayı karşılaştırmıyor. CRC çekirdeğinin algoritma doğrulaması ayrı boot-format araştırmacısının kanıtına aittir.
- `mscompress7`: ilk mod karakteri `d`, index değeri `0` kontrol edilir; kaynak/uzunluk/hedef argümanları ayrıştırılıp `0x8e215b5c` çağrılır (`0x8e215da0`, hedef dosya `0x25ddc`). Yardım metni LZMA der; gerçek alt decompressor gövdesi bu aşamada incelenmedi.
- `filepartload`: argüman sayısı kontrolü ve bir alt işlev sonucuna göre yollar vardır. Bazı yollar komut metni üretip `0x8e25f5d0` hedefine, başka yollar `0x8e21743c` hedefine gider. Kaynağın seçimi, tüm switch hedefleri ve alt dosya yükleyici gövdeleri tamamlanmadı.

## Yeniden çalıştırma ve doğrulama

Yeni ortamda `sh tools/analyze-boot-candidate-linux.sh` yalnız kaynak payload'ı import eder. Bu görevde oluşturulmuş projeyi yeniden sorgulamak için `--resume-own-project` kullanılabilir; kayıtlı kaynak hash'i, veritabanı kaynak hash'i ve güncel manifest bağı kontrol edilir. Mevcut başka projeler açılmaz. Ghidra/JDK kurulumu yenilenmez.

Host shell sözdizimi kontrolü geçti. Ghidra Java script'i derlendi ve gerçek analiz 5/5 sonuç üretti. Son yeniden çalıştırma çıkış kodu `0`; `source-hash-verification.json` kaynak hash'inin değişmediğini doğrular. İlk girişimde program image-base metaverisini ham blok başlangıcı sanan kontrol durdu; bunun hata günlüğü ve o girişimin manifesti `initial-import-*` dosyalarında saklanır. Son kontrol ham blok başlangıcına düzeltildi.

Kaynak/script kimliği `source-hash-manifest.json`, kapsam/varsayımlar/komut pointer ve help alanları `summary.json`, adresli assembly `handler-instructions.jsonl`, adresli çağrılar `handler-xrefs.jsonl`, sınırlı tanılama metinleri `referenced-diagnostics.json`, pseudocode beş `candidate_cmd_*.c` dosyasındadır. C çıktıları özgün kaynak kod değildir. Sertifika, anahtar veya benzersiz cihaz kimliği içerikleri bu araştırmada okunmadı veya rapora taşınmadı. Boot girişinden paket kabul/ret kararına kadar çağrı zinciri hâlâ çözülmemiştir.
