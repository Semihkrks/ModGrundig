# Gerçek MIPSel uygulama laboratuvarı

24 Ekim 2026. **TV ekranı açılmadı. Tam kart/TV emülatörü değildir.** Gerçek `dvbt_board` ELF ve özgün MIPS kütüphaneleri QEMU linux-user üzerinde çalıştırıldı. Firmware kernel/init/update scriptleri çalıştırılmadı. Orijinal dosyalar ve TV değiştirilmedi.

Güncel v3 de ayrı guest kökünde denendi: ELF SHA `c109a782f476dfb8b23136d7dad3a231c57dd4cb605e081da559ed370f76208a`; kaynak APP ağacındaki tüm v3 manifest kayıtları eşleşti. `run-v3.json` özgün/v2 ile aynı NAND/UBI başlangıç kapısında durur. Eski deneme kayıtları korunur. QEMU executable SHA artık araç ilk çalıştırılmadan (`--version` dahil), hazırlama kopyasından önce ve hedef çalıştırmadan önce kod içindeki sabitle doğrulanır; değiştirilebilir `host-tools.json` çalıştırma yetkisi vermez.

## Çalıştırma

Bu makinede hazırlanan özgün ve v2 kopyaları ayrı Linux dizinlerinde bulunur. PowerShell proje kökünden:

```powershell
powershell -File tools/emulation-lab-run.ps1 -Variant v2
powershell -File tools/emulation-lab-run.ps1 -Variant original
powershell -File tools/emulation-lab-run.ps1 -Variant v3
```

WSL Ubuntu doğrudan:

```bash
python3 scripts/emulation_lab.py fixtures --variant v2
python3 scripts/emulation_lab.py run --variant v2
python3 -m unittest discover -s scripts -p test_emulation_lab.py -v
```

Sonuçlar `run-v2.json`, `run-original.json`, `run-v3.json`. Laboratuvar komutunun başarıyla bitmesi uygulamanın açıldığı anlamına gelmez; hedefin `exit_code` alanı ayrıdır. Üçünde de **134 / SIGABRT** var. Çıktı dosyaları her denemede güncellenir.

Tekrar kurulum için `setup` resmî Ubuntu paketini doğrular ve yalnız özel dizine açar; `prepare --variant original|v2` yeni guest dizini oluşturur ve mevcut dizinin üzerine yazmayı reddeder. `prepare`, bu makinede daha önce çıkarılan canonical dosya ağaçları ve v2 APP tekrar çıkarımına dayanır; bağımsız taşınabilir bir firmware dağıtımı değildir.

## Gerçek sonuç

1. Resmî Ubuntu `qemu-user 1:10.2.1+ds-1ubuntu3.3` paketi apt metadata SHA-256 ile eşleşti. Paket `a00c7fdf34c913b799f8d1cc556d3fdd9f9fd695167a17baf86123a9cfaefb22`; statik QEMU MIPSel executable `7d30ccb62bb20c49fc405636df39362c41f748c0fc053675a8866ffabab13432`. Sistem kurulumu veya maintainer scripti çalıştırılmadı.
2. Bubblewrap 0.11.1 host probu 12 kontrolü geçti: host yolları ve fiziksel cihaz yolları görünmüyor; root salt okunur, geçici alan özel, ağ `ENETUNREACH`, PID namespace ayrıdır. Her hedef denemesinden hemen önce prob tekrar çalışır; başarısızsa hedef başlatılmaz.
3. İlk kütüphane açılımında CONFIG'teki `libdfbinfo.so` gerekiyordu; izinli üç CONFIG ELF kütüphanesi (`libsysteminfo.so`, `libdfbinfo.so`, `libMMAPInfo.so`) eklendi. Rastgele board/provisioning/config dosyaları eklenmedi.
4. İlk uygulama denemesinde `mapi_system::GetBootSource()` assert etti. Fonksiyon `/proc/cmdline` içindeki `ENV=` alanını arar. `getbootsource-static.json` bu **668 bayt / 167 instruction** gövdeyi ve GOT ile çözülen literal adreslerini saklar: VA `0x2cb90064`; `ENV=` file `0x4394bc`; `NAND`, `EMMC`, `SERIAL` literal'leri file `0x439508/0x439510/0x439518`. Eşleşmeyen değer 255, NAND/EMMC 1, SERIAL 0 verir. Kodda zorunlu olan bu alan için yalnız **sentetik `ENV=NAND`** fixture'ı bağlandı. Host veya fiziksel TV boot argümanı son denemelerde kullanılmaz.
5. Fixture ile özgün ve v2, **112 farklı `.so` yolunu başarıyla açtı**; bu, hepsinin fonksiyonlarının çalıştığı veya sembollerinin eksiksiz doğrulandığı anlamına gelmez. Sonraki gerçek engel NAND/UBI oldu: `/sys/class/ubi` açılması `ENOENT`; `mapi_storage_factory_config_nand::Init()` assert + abort. `nand-init-static.json` Init **360 bayt / 90 instruction**, `UBI_Exist()` **204 bayt / 51 instruction**, GOT bağlantısı ve hata kolunu içerir.

Kanıt zinciri: `Init 0x2cb880ac` → `UBI_Exist 0x2cb85f74`; `open 0x2cb85f9c` → `/sys/class/ubi`; başarısızlıkta dönüş0 → `Init 0x2cb880d4` assertion → `0x2cb880e4` abort. Runtime'da yerel binary içindeki sabit `virtual MAPI_BOOL mapi_storage_factory_config_nand::Init()` literal'i eşleşti (file `0x438550`). `/Customer/log_levels.ini` ve `switch_off_test_counter.txt` eksikleri de görülür; doğrudan abort sebebi oldukları ileri sürülmez.

## 24 Ekim devamı: özel UBI topolojisi

Yarım kalan namespace hatası tekrar görülmedi; izolasyon probu yeniden **12/12** geçti. Kaynak yazılım değiştirilmeden, yalnız laboratuvara ait salt okunur `/sys` ağacı ile şu aşamalar yürütüldü:

| Deneme | Sentetik bilgi | Gerçek gözlem |
| --- | --- | --- |
| `run-v3-ubi-directory.json` | Yalnız boş `/sys/class/ubi` dizini | UBI varlık kontrolü geçildi; MPOOL bulunamadı. Bu önceki aşamanın kaydıdır. |
| `run-v3-ubi-mpool-name.json` | `ubi0_0/name=MPOOL` | Ad dosyası okundu; `data_bytes` açılırken `ENOENT`, ardından SIGABRT134. |
| `run-v3-ubi-mpool-empty.json` | Öncekine ek `data_bytes=0`, `usable_eb_size=126976` | İki sayı dosyası da okundu; `/dev/shm/ubi0_0` açılması `ENOENT`, ardından SIGABRT134. |
| `run-original-ubi-mpool-empty.json` | Aynı boş model, özgün ELF | Aynı `/dev/shm/ubi0_0` kapısı; SIGABRT134, 112 farklı `.so` yolu. |

`0` özellikle boş sentetik hacim anlamındadır. `126976` firmware UBIFS LEB geometrisiyle uyumlu bir fixture değeridir; cihazdan okunmuş bilgi değildir. **MPOOL içeriği, cihaz node'u veya başarılı ioctl yanıtı uydurulmadı.** Özgün ve v3 eşit erken duruyor; bu sonuç UI değişikliklerini doğrulamaz. Menü/TV ekranı hâlâ başlamadı.

Statik kanıt: `ubi-model-static.json` içinde ad arama `UBI_VOL_Found_OnVolume 0x2cb86820` ve sayı okuma `UBI_Parameter_Parsing 0x2cb87dc4`; yeni `ubi-memory-boundary-static.json` içinde dört ek fonksiyonun **1584 bayt / 396 instruction** dökümü ve MIPS GOT sembol çözümü var. `UBI_ReadDataOffset 0x2cb86ef4`, `/dev/shm/ubi%d_%d` formatını (VA `0x2ccf7f8c`, file `0x437f8c`) üretir; `open` çağrısı `0x2cb86fa0`, bayrak `0x80002` (MIPS `O_CLOEXEC | O_RDWR`). Başarısız açılışta EBUSY için bekleme/yeniden deneme yolu vardır; diğer errno yolunda `strerror/printf/perror` ardından `raise(6)` çağrısı `0x2cb87094` gelir. Mevcut syscall izi ENOENT → SIGIOT ile uyumludur; bu iz PC düzeyinde instruction trace değildir.

Başarılı açılış kolundaki `lseek 0x2cb870f0` ve `read 0x2cb8713c` henüz yürütülmedi. Hacmin gerçek içeriği ve hazırlayıcı akış anlaşılmadan boş dosya ekleyip bu kolu başarılı gösterme yapılmadı. Sonraki araştırma, `/dev/shm/ubi0_0` dosyasını özgün açılışta hangi bileşenin ve hangi veri düzeniyle hazırladığıdır; rastgele sıfır veri bunun yerini tutmaz.

Yeniden denemek için:

```powershell
powershell -File tools/emulation-lab-run.ps1 -Variant v3 -Topology ubi-mpool-empty
```

Launcher bu seçenekle `run-v3-ubi-mpool-empty.json` üretir. **18/18** laboratuvar sözleşme testi geçti: yeni kontroller topolojinin özel/salt okunur bağını, ek dosya ve symlink reddini, sabit SDK hash zorunluluğunu ve boş hacim değerini kapsar. Her uygulama çalıştırmasından hemen önce izolasyon kontrolü yine zorunludur.

## Koruma ve sınır

- Yalnız SHA sabitli `original`, `v2` veya `v3` uygulaması başlatılabilir; kullanıcıdan rastgele guest komutu alınmaz. Guest içinde shell, init ve update programı yoktur.
- Kaynak RFS/MSLIB/APP/CONFIG yalnız okunur; ayrı guest kökü kopyalanır. Kütüphane symlinkleri host köküne doğru izlenmez. Sertifika/customer bölümleri, özel anahtar dosyaları, kernel modülleri ve scriptler kopyalanmaz.
- Guest root salt okunur; `/tmp`, `/run`, `/USR_DB`, `/BACKUP_DB` geçici ve özeldir. Host `/dev`, ağ, sertifika bölümü veya NAND bağlanmaz. Normal denemede `/sys` boştur; açık topoloji seçeneğinde yalnız yukarıdaki sabit sentetik dosyalar bağlanır. Gerçek cihaz ioctl başarısı taklit edilmez.
- CPU15s, duvar20s, 128 dosya descriptor, 64 process ve 1MiB dosya/log limiti var. 8GiB sanal adres limiti QEMU'nun 32-bit guest rezervasyonu içindir; TV RAM ölçümü değildir. Core dump kapalıdır; QEMU'nun genel hata mesajındaki `core dumped` ifadesi diskte core üretildiğini kanıtlamaz.
- Ham syscall read/write buffer'ları ve uygulama stdout'u kalıcı tutulmaz. Rapor yalnız syscall isimleri, dosya yolları/sonuçları, sinyaller ve binary'de birebir bulunan sabit diagnostik literal'leri saklar. Kaynak ağaç hiçbir dış servise gönderilmedi.
- **Aynı ilk abort, UI patchinin doğruluğunu kanıtlamaz.** Ses paneli, MUF oluşturma/ölçekleme, DirectFB çizimi, IR, ses/CEC, tuner, video ve flash bu laboratuvarda henüz sınanamadı. NAND/UBI kart davranışının doğru modellenmesi veya cihazdan güvenli gözlem gerekir; sahte başarıyla bu engel gizlenmedi.

## Kontroller

`test_emulation_lab.py`: **14/14 geçti**. Provisioning dosya filtresi, guest symlink sınırı, readonly/offline namespace sözleşmesi, sentetik cmdline bağı, raw buffer redaksiyonu, sabit literal diagnostikleri ve başarısız izolasyonda hedefi başlatmama kontrol edildi. Üç yeni substitution testi yanlış executable'ın setup/prepare/run sırasında hiç çalıştırılmadığını kontrol eder; v3 ELF sabiti manifestle karşılaştırılır. Host izolasyon probu geçti. Hedef özgün/v2/v3 denemeleri aynı NAND/UBI kapısında durdu; ekran kontrolü geçmiş sayılmaz.

Dosyalar: `host-tools.json`, `isolation-probe.json`, `guest-{original,v2}.json`, `fixtures-{original,v2}.json`, `run-{original,v2}.json`, `getbootsource-static.json`, `nand-init-static.json`. Önceki adım kayıtları `run-*-before-synthetic-cmdline.json` ve `run-v2-initial-missing-config-library.json` altında tarihsel kapsamlarıyla kalır.
