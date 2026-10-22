# Boot zinciri ve paket biçimi

22 Ekim 2026. Buradaki cihaz davranışı çevrimdışı statik kanıttır. Gömülü kod, güncelleme scriptleri ve flash komutları çalıştırılmadı.

## Paket ve filesystem kanıtı

Orijinal kaynak hash'leri ve 14 payload aralığı [ana raporda](../TERSINE_MUHENDISLIK.md), makine kayıtları `analiz/bolum-haritasi.json` içindedir. Güncelleme tablosu `GM_SWImage.bin:0x0` alanında 0x4000 bayt bildirir. `filepartload`, `mscompress7`, CRC ve NAND/UBI ifadeleri veri olarak parse edildi. 14 LZMA akışı ve 14 beyan CRC eşleşir; iki trailing byte korunur. Bu kontrol, kriptografik imza veya cihaz uyumu değildir.

Beş mboot payload'ı GM_Boot içindeki beş aralıkla eşleşir; padding kapsam dışıdır. Kernel uImage header/data CRC'leri doğrulandı. Kernel wrapper içindeki `0x13c0` LZMA açılımı 5.306.304 bayttır. Kernel binary'sinin açılmış olması, tüm kernel fonksiyonlarının decompile edildiği anlamına gelmez.

8 UBIFS superblock kontrolü, orijinal metadata indeksinde 14.191 CRC kontrolü vardır. 4.445 metadata kaydı içinde 380 özel cihaz node'u hostta oluşturulmadı. OAD root-only committed indeks olarak gözlendi; journal replay ve xattr içerik çözümü tamamlanmış sayılmaz. İlk NTFS ve başarısız RAR çıkarım ağaçları kaynak olarak kullanılmaz.

## Boot zinciri: kesin kayıtlar ve çıkarım sınırı

1. Paket, bootloader parçalarını ve KL/RFS/APP/MSLIB/CONFIG hacimlerini tanımlar. Bootloader'ın cihazdaki gerçek env/reset seçimi henüz gözlenmedi.
2. CONFIG `set_env` içinde `root=ubi:RFS`, UBIFS read-only root ve `ttyS0,115200` aday bootargs vardır. Bunlar paket env verisidir; aktif TV env dump'ı değildir.
3. RFS init/inittab/rcS kayıtları mount ve seri login shell yollarını bağlar. `/etc/profile → /Customer/profile → /Customer_Update/profile` symlink zinciri firmware köküyle anlamlandırılır; host köküne doğru takip edilmez.
4. Customer_Update/profile içinde MSLIB, USR_DB, APP ve CONFIG mount ifadeleri; LD_LIBRARY_PATH ve IR modül yükleme yolu bulunur. Komutlar çalıştırılmadı. Login shell'in profile'ı başlatması init/login davranışına dayalı çıkarım olarak ayrı tutulur.
5. Profile içindeki `applications/bin` ve `./autorun signal`; APP `autorun → dvbt_board` bağlantısı ana TV uygulamasına bağlanır. Çalışma zamanı mount başarısı veya seçilen profil henüz gözlenmedi.
6. `dvbt_board` ELF startup → `__libc_start_main` PLT bağı → `0xfd0784` ana callback adayı kuruldu. Bu gövdenin C/assembly incelemesi resource-profile ve factory hata kapılarını, `MApplet::Run` callsite'ını ve console/test event-loop ayrımını bağladı. [Adresli uygulama başlangıcı](SERVIS_DERINLESTIRME.md).

Yeni ham kod kanıtları [boot ek raporunda](BOOT_EK_KANITLAR.md): Busybox applet tablosu `sh/ash` ortak hedefini ve login `'-'` kontrolünden `/etc/profile` yoluna geçişi bağlar. Init'in `-/bin/sh` girdisinden argv0 oluşturduğu gövde hâlâ açıktır. Kernel wrapper, açılmış kernelin `0x803af190` girişine dallanır; `0x804e3584` devamına henüz `start_kernel` adı verilmez. Fiziksel boot/env seçimi gözlenmedi.

Kanıt dosyaları: `analiz/dosya-envanteri.json` (dosya/symlink), `analiz/baglanti-grafi.json` (ilk ilişki grafiği), `analiz/ubifs-orijinal-metadata.json`, `analiz/ui-yapi-haritasi.json`. İlk grafikteki sembol sayımları için güncel `analiz/envanter-v2/` esas alınır.

## İmza ve güncelleme güven zinciri

CRC32 eşleşmesi yalnız bütünlük kontrolü kanıtıdır. Kripto kütüphanesi veya RSA/SHA sembolünün mevcut olması güncelleme kabul yolunda çağrıldığını kanıtlamaz. Güncelleme girişinden doğrulama çağrısına, beklenen header alanlarına ve hata/ret dalına kadar kod yolu kurulmadan “imzalı/imzasız paket kabul eder” sonucu çıkarılmaz. Bu bağlantı açık araştırma işidir.

Header `0x122c` içindeki `ncishash` satırı ilk çıkarıcının modellemediği ek komuttur; ayrı JSON kaydıyla korundu, önceki manifest geriye dönük değiştirilmedi. 14 LZMA tail'inin tamamı `BE EF`; `0x21de` alanındaki `setenv verify n` tek başına imza politikasını kanıtlamaz. CRC çekirdeğinin 256 girişli reflected `0xedb88320` tablosu ve iki kabul/ret dalı ham wordlerle eşleşti; bu dalların bütün güncelleme girişine çağrı zinciri tamamlanmadı.

Beş komut işleyicisi yeni ve izole Ghidra projesinde decompile edildi: `filepartload`, `mscompress7`, `crc32`, `ncishash`, `ncisbl`. [5/5 C, 1.652 instruction ve 170 call xref kapsamı](../../analiz/native/boot-candidate-v1/FINDINGS.md). `ncishash` için yardım metni ve kod CIS/hash bölgelerini programlama yolunu destekler; kriptografik imza doğrulayıcı olduğuna dair kanıt yok. `VA−dosya=0x8e1efd80` komut tablosundan türetilmiş adaydır; cihazın gerçek yükleme adresi değildir.

Sertifika/anahtar bölümü içerikleri, cihaz kimlikleri ve provisioning verileri araştırma raporlarına alınmaz. Repack, imza atlatma veya cihazda yükleme bu kapsamda yapılmaz.
