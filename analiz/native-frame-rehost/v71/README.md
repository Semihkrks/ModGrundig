# V7 / V7.1 sınırlı çizim karşılaştırması

25 Ekim 2026. Bu kareler fiziksel TV emülasyonu değildir: hash sabitli beş MUF çizim fonksiyonu, sınırlı `RefreshVolumeUI` çalıştırması, sentetik servis dönüşleri ve host Pillow yüzeyi kullanılır. OnCreate alanları statik kanıt ve Num kaynaklarından hazırlanır; OnCreate, DirectFB clipping sürücüsü ve tam firmware süreci çalıştırılmaz. Parent/outer kırpması açık host dikdörtgen kesişimleridir. Progress dolgu geometrisi host varsayımıdır; native font dosyaları Pillow FreeType ile rasterize edilir. Aktif cihaz ölçeklemesi/overscan ölçülmemiştir. Kullanılan beceri: reverse-engineer-anything.

## Kareler

- `v7-tv-volume-27.png`: outer `[0,160,160,725]`, root local `[0,150,68,490]`, ekran paneli `[0,330,68,450]`. Panel image674 kaynağı mevcut olsa da +0x3a image flag sıfır; gerçek DrawBackground `FillRectangle` yoluna girer.
- `v7.1-tv-volume-27.png`: aynı outer, root local `[80,126,68,490]`, ekran paneli `[80,306,68,450]`. Sabitli `0xfbb550=0x24040001`, `0xfbb55c=0xa204003a` panel flag'ini etkinleştirir; gerçek MUF `StretchBlit` yoluna girer. PNG yarıçapı34. Root'un son image1485 kaydı null olduğundan eski image685 gölgesi çizilmez.
- `v7-tv-numeric-12.png`: outer `[0,0,1920,80]` kartın `[1538,64,310,224]` yalnız üst16 pikselini gösterir; `[1566,118,254,78]` rakam alanı tamamen kırpılır.
- `v7.1-tv-numeric-12.png`: `0x89518c` immediate resource id'si0x50 yerine0x98f; outer yüksekliği312 olur. Aynı kart ve rakam alanı görünür. Gerçek kanal adı widget'ı olmadığı için eklenmez; karttaki sabit başlık/açıklama gerçek PNG kaynağının parçasıdır.

Her PNG'nin aynı adlı JSON'u, kaynak hash'leri, native instruction adresleri, callback'ler ve açık kırpma kesişimlerini içerir. `generate_evidence.py` yalnız bu dizine yazar; firmware/overlay/pins değiştirmez. Görseller açılarak ses kapsülü ve rakam kartı gözle kontrol edildi.

## Gerçek doğrulama sonuçları

- `python -m unittest discover -s scripts -p test_native_frame_v71.py -v`:6/6 PASS. Outer origin, image flag/draw yolu, root gölge yokluğu, numeric kırpması, kanal adı yokluğu, tüm çizimlerin clip içinde kalması, native0/100/mute, pin reddi, viewer varsayılanı.
- `python -m unittest discover -s scripts -p test_native_ui_v71_volume.py -v`:8/8 PASS. Paylaşılan NativePainter değişikliği sonrası yeniden çalıştırıldı.
- `python -m unittest discover -s scripts -p test_native_frame_rehost.py -v`:16 PASS,1 SKIP (kullanıcının iptal ettiği V8 deneyi). Önceki V7 TV speaker beklentisi outer origin eklenerek y723 olarak düzeltildi; eski V6 beklentisi y563 korundu.
- `python -m unittest discover -s scripts -p test_native_frame_viewer.py -v`:6/6 PASS.
- `python -m unittest discover -s scripts -p test_native_volume_state_rehost.py -v`:8/8 PASS.
- `node analiz/native-frame-rehost/v71/browser-check.mjs`:Chrome PASS. V7.1 varsayılanı, blob PNG, gerçek klavye ses/mute, hızlı tekrar0/100 sınırı, numeric12, sahne dönüşü; console/HTTP hata yok. Ayrıntı `native-browser-tests.json`, ekran `native-browser.png`.

Toplam44 Python testi geçti,1 tarihsel test atlandı; tarayıcı akışı ayrıca geçti. Loopback4174 yalnız doğrulanmış aynı Python viewer süreci için yeniden başlatıldı. Firmware BIN/RAR, build helper'ları, overlay ve pin dosyaları değiştirilmedi. Cihaz kabulü veya tam TV görsel eşliği bu testlerin sonucu değildir.
