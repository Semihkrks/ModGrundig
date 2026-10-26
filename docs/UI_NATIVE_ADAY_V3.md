# Native UI v3 ve gerçek MIPS laboratuvarı

24 Ekim devamı: [gerçek MUF koduyla kısmi kareler ve font/ikon v4 düzeltmesi](NATIVE_GORUNTU_CALISTIRMA.md) eklendi. Buradaki v3 paket/decoder ölçümleri önceki aşamanın kapsamıdır; v4 ayrı overlay'dir ve yeni firmware paketi üretilmedi. Tam TV açılışı hâlâ doğrulanmadı.

24 Ekim2026 · `codex/ui-soft-preview` · **Çevrimdışı aday; tam UI aktarımı veya TV yükleme onayı değil.** Orijinal dosyalar korunur; TV'ye yazılmadı.

## Gerçekten yapılanlar

- WSL/QEMU MIPSel laboratuvarı kuruldu. Özgün/v2/v3 TV uygulamaları ayrı salt okunur köklerde gerçekten yürütüldü; henüz TV ekranı oluşmuyor. [Çalıştırma ve kanıt](../analiz/emulation-lab/README.md), [üç varyantın sonucu](../analiz/emulation-lab/verification-summary.json), [emülasyon araştırması](TV_EMULASYON_ARASTIRMASI.md).
- Yeni küçük MIPS harness'i, özgün libpng1.2.32/zlib1.2.8/glibc2.8 ile üç PNG'yi çözdü. Şeffaf köşeler gerçek kütüphanede ölçüldü; DirectFB veya TV karesi üretilmedi. [Decoder sonucu](../analiz/native-png-probe/decode-result.json).
- V2'nin20 PNG/14 ses yerleşimi/sıfır ikonu korunarak mevcut numara widget'ları ve ses kapsülü ilerletildi. Yeni widget veya yeni donanım servisi eklenmedi.

## V3 farkları

| Bölüm | Değişiklik | Sınır |
|---|---|---|
| Ses kapsülü bg674 | 69×620 P4/color type3 korunarak tRNS eklendi; beyaz merkez, şeffaf köşeler. Kaynak köşeler76×500 hedefte38px yarıçap tasarımına göre hesaplandı. | Bilinçli alpha yeteneği eklemesi. Eski decoder okuyabiliyor; gerçek GOP çıkışı/TV ölçeklemesi gözlenmedi. |
| Speaker alt çizgisi | Yerel instruction`0xfbd38c`: `a3=8 → 0`. | Yalnız speaker bottom-edge maskesi kaldırıldı; ARC ve diğer border'lar korunur. |
| Numara yerleşimi | 9 Num kaydı: root1920×176, arka plan310×112 `(1538,64)`, rakam254×72 `(1566,84)`. Sağ boşluk72. | İki alt widget aynı root'un çocukları ve sınırlara sığıyor. Yalnız mevcut rakam gösterimi; Chrome310×224 eşleşme/geri sayım kartı değildir. |
| Numara rengi | OnCreate`0x895b84` içinde8 yerel argüman: bgColor18→94, metinColor94→0. | Global Color/Num font tabloları, paylaşımlı48px font ve kanal/event/timeout kodu aynı. |

Toplam **23 Num kaydı** (14+9); yeni **9 görsel instruction** (8 renk argümanı+1 border maskesi). V2'nin20baytlık ses ikon penceresi ayrıca korunur. Trampoline, code cave, yeni import veya bağımlılık yok. Home yüzeyleri, kanal listesi/bilgi bandı ve native animasyon gate'i değiştirilmedi.

[Overlay manifesti](../analiz/native-ui-candidate/v3/manifest.json), [üretici](../scripts/build_native_ui_v3.py), [testler](../scripts/test_native_ui_v3.py). Özgün ELF/Num ve v2 görsel snapshot SHA'ları sabit. APP builder native byte'ları özgünlerden yeniden hesaplayıp22dosyalık allowlist/hash ile karşılaştırır.

## Yeni kanıtlar

Ghidra'da `MWidget::ShowBorder 0x2e250508` ve `DrawBorders 0x2e24d438`: **2/2 C çıktısı**,33+106instruction. [Özet](../analiz/native/ui-targeted/volume-style-v1/summary.json). Setter'da `a3 → widget+0x160`, kalınlık`a1 → +0x161`, renk`a2 → +0x164`; DrawBorders4/8/1/2 bitleriyle üst/alt/sol/sağ dikdörtgenleri çizer. **8 yarıçap değildir, alt kenar bitidir.**

ShowBorder C'si tail-call nedeniyle seçili132bayt dışında invalidate kodu da içerir; dış pcode adresleri JSON'dadır. Parametre yorumu seçili assembly+DrawBorders ile yapıldı; genişleyen C tek başına gövde boyutu sayılmadı. Doğrudan Ghidra çıktısı REA Evidence değildir.

Önceden çözülen DrawBackground`0x2e251be4`, MImg RenderImageToSurface`0x2e23e684`, StretchBlit`0x2de5aac8` bağları kullanıldı. Clrkey674=`0xffffffff` normal görüntü yolunda alpha blit ayarları statik olarak görülür. **Bu yolun v3 ile cihazda yürütüldüğü kanıtlanmadı.**

PNG ölçümleri: özgün köşeler`(10,10,10,255)`, v2 köşeler`(245,245,245,255)`, v3'ün dört köşesi`(245,245,245,0)`, merkezi`(245,245,245,255)`. Eski decoder'ın tRNS desteği çalışan MIPS koduyla doğrulandı.

## Kontroller ve çıktı

| Kontrol | Sonuç |
|---|---|
| V3 testleri | 8/8; yerleşim, kalıtılan patch, hash/byte/output allowlist,9 tek-instruction CPU kontrolü |
| Emülasyon sözleşmesi | 14/14; izolasyon, değiştirilmiş executable/JSON reddi |
| Gerçek MIPS PNG | 3/3;6 özgün kütüphane hash'i sabit |
| APP dosyaları | 2.371/2.371;22değişik/2.349aynı |
| APP metadata | 2.773 mode/uid/gid/type/nlink/mtime;401dizin/1symlink hedefi |
| Committed node CRC | 18.988/18.988; journal replay yok |
| UBIFS | Format4/flags0/min_io2048/LEB126976/maxLEB321, LZO;227LEB |
| Kapsayıcı | 14/14 payload ve iç/dış CRC; diğer13payload/padding/komut aynı |
| Bağımsız diskten okuma | Geçti; eski parser+stdlib LZMA/CRC |
| TV/DirectFB ekranı | **Yok; başarı sayılmadı** |

Bağımsız incelemede bulunan QEMU tekrar kullanım açığı kapatıldı: ilk çalıştırma, kopyalama ve hedef çalıştırma öncesi kod-içi executable SHA sabiti doğrulanır. Editable rapor yetki kaynağı değildir.

APP28.823.552bayt; sıkıştırılmış17.405.841bayt, özgün slotta26.735bayt kaldı. Offsetler taşınmadı; kapasite sınırsız kabul edilmez.

- [GM_SWImage_UI_v3_OFFLINE_UNVERIFIED.bin](../analiz/native-ui-candidate/v3/package/GM_SWImage_UI_v3_OFFLINE_UNVERIFIED.bin)
- [APP doğrulaması](../analiz/native-ui-candidate/v3/package/app-build-validation.json)
- [Paket doğrulaması](../analiz/native-ui-candidate/v3/package/container-validation.json)
- [Bağımsız tekrar okuma](../analiz/native-ui-candidate/v3/package/independent-readback.json)

SWImage SHA: `382750ab36013c489fbe8b34a42241cdfabbc8441e301703153e014b039a1c22`.

APP SHA: `c3f282e9966b3f634442d7574a13ce3cd889c3167ff63baa205ba23d75e0adb2`.

ELF SHA: `c109a782f476dfb8b23136d7dad3a231c57dd4cb605e081da559ed370f76208a`.

Tam kapsayıcı özgün certificate payload'ını opak olarak taşıdığından yerelde kalır; Git ignore korunur. Dış servise firmware/anahtar/kimlik gönderilmedi.

## Gerçek uygulamayı deneme

```powershell
powershell -File tools/emulation-lab-run.ps1 -Variant v3
```

Başlatıcı v3 ile test edildi. `analiz/emulation-lab/run-v3.json`:112 farklı `.so` yolu açıldı; `/sys/class/ubi` yokluğu nedeniyle NAND assert'inde134/SIGABRT. Aynı erken duruş özgün/v2'de de var; UI patch doğruluğu veya GUI başarısı değildir. Gerçek UBI/panel/ses başarısı taklit edilmedi.

## Açık kapsam

[Takip listesi](UI_NATIVE_AKTARIM_TAKIP.md)160yeni kanal/numara/info widget adayını ve21dinamik Home mixer oluşturma noktasını içerir. Beş grup açıktır: Home yüzey/metin/odak; ek numara eşleşme/geri sayım widget'ları; kanal listesi/bilgi bandı; diğer ayar/kaynak/medya/PVR stilleri; native animasyon/event interpolasyonu.

Home'da480renk çağrısı ve gerçek alt metinlere giden TextContentConfig/SetTextContent/UpdateCompositeData yolu var. Beyaz yüzeyde açık metni okunmaz bırakmamak için96aday toplu patch'e çevrilmedi. Numara ekranında3widget var; Chrome'un ek bilgi alanları aktarılmış gibi gösterilmedi.

**Eksiksiz UI aktarımı, native GUI karesi, tam kart emülasyonu, aktif TV profili/kurulum kabulü ve fiziksel test tamamlanmadı.** V3 kurulabilir nihai sürüm değildir. Kullanılan beceriler REA/research; backend/frontend/araştırma ve bağımsız inceleme alt işleri ayrı sahiplikle yürütüldü.
