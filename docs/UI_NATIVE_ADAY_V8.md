# Native MUF UI v8

**İptal edilen menü deneyi:** kullanıcı menüleri ve ikonları orijinal bırakmayı seçti. Güncel paket [V7 ses/numara adayıdır](UI_NATIVE_V7_TV_ADAYI.md). Aşağıdaki metin araştırma geçmişidir; V8 yükleme önerisi değildir. V8 çıktıları `v8-menu-experiment-cancelled/` altında saklanır.

25 Ekim 2026 · `codex/ui-soft-preview`. Bu sürüm gerçek `dvbt_board` ELF'i ve native MUF kaynaklarını ayrı kopyada değiştirir. Chrome arayüzü firmware'e gömülmedi. Orijinaller ve önceki adaylar korunur; TV'ye yazılmadı.

## Native değişiklikler

V7'ye göre **395 yerel MIPS talimatı**, **44 yeni PNG** ve46 ek Image kaydı vardır. Overlay68 dosyadır: orijinale göre23 değiştirilmiş dosya ve45 yeni PNG (önceki sayısal kart dahil). Image_res'de önceki2180 kayıt gövdesi aynıdır; yeni tablo2226 kayıt taşır. ID2186/2187 ayrılmış ama kullanılmayan açık alias'lardır; ek widget oluşturmazlar.

| Native yol | Değişiklik ve kanıt |
|---|---|
| Home `OnCreate0xd42150` / `LayoutItems0xd29500` | 357 talimat:240 Image argümanı,116 yerel yazı rengi,1 görsel bool store.40 özel PNG; açık yüzey, koyu normal/mavi odak ikonları. [Adresli plan](../analiz/native-ui-port-v8/home-plan.json), [kanıt](../analiz/native-ui-port-v8/home-evidence.md) |
| Dinamik Home kartları | 21 mixer ×4 arka plan=84 çağrı özel2181/2182'ye bağlanır. TextContentConfig ve dış widget renkleri birlikte değişir. Koyu fallback/bölüm başlıklarındaki35 beyaz argüman korunur |
| Picture kartı | Dört sentinel arka plan özel açık kaynaklara bağlanır. `0xd4e660` jalr delay slot'unda `sb a1,0x3a(a0)`; a0 gerçek picture widget, a1=1. Özgün `SetImgExpandProperty0x2e2285f0` ile MIPS yürütmesinde doğrulandı |
| Ayar ortak stili `NewUI_Settings0x55b6c0` | 13 yerel MImg argümanı: Combo/Image/Spin/NumberEdit odak yüzeyleri özel2224; olağan başlık2225. Beyaz metinle okunur yumuşak mavi odak/koyu başlık. [Adresler](../analiz/native-ui-port-v8/settings-theme-evidence.json) |
| Kanal listesi `OnCreate0x7995b0` | Özel2184 açık ana panel ve sağ ayrıntıda koyu normal metin. Sol dinamik liste/odak stili korunur. Gerçek yedi filtre, DB ve kanal seçimi işleyicileri aynı |
| Program bilgisi `OnCreate0x7de53c` | On iki yerel MImg argümanı özel2185 koyu mavi-gri banda bağlanır; mevcut beyaz metin/ikonların kontrastı korunur. [Kanal kanıtı](../analiz/native-ui-port-v8/channel-theme.md) |
| Ses / numara | V7'nin68×450 kapsülü,44px ikonu, DINPro fontu, sıfırda mute ikonu ve58px sayı yerleşimi korunur. V8 test karesine sahte eşleşen kanal adı eklenmez |

Global Color/font tabloları, native geometri, event/kanal/ayar servisleri ve animasyon kapısı değiştirilmedi. Home504/529 yüksekliği korunur; Chrome456px düzeni native'e uygulanmış değildir. Ağ/Web/APP etkinleştirilmedi. Ek resim kaynakları olay veya donanım özelliği eklemez.

## Üretim ve kimlik

[Üretici](../scripts/build_native_ui_v8.py) özgün/v7 baytlarından dönüşümü yeniden hesaplar, eski instruction word'lerini ve değişiklik allowlist'ini denetler. [Manifest](../analiz/native-ui-candidate/v8-menu-experiment-cancelled/manifest.json) ve [kodda sabitlenmiş paket kimlikleri](../scripts/native_ui_v8_pins.py) aynı68 dosyayı tanımlar. Manifest tek başına kendi doğrulama otoritesi değildir.

- ELF SHA256: `3eea9fc3ecea42edfbaefc25d5c88867a7f756bc8a06959095cb2e7a36354045`.
- Num SHA256: `d293c1c7aeec39c4384915a66aa42be0c37b1fd52b726e74022551707d122cfa` (v7 ile aynı).
- Home plan SHA256: `24df71e8ce0bfcaa9d14bc879ab4d72a6714b09c571e2b629a20cca76b3256e4`.

Windows tam PNG/font yeniden üretimi yapar. Windows/Linux FreeType/zlib çıktıları aynı olmadığı için Linux paketleme aynı çıktıyı yeniden çizmez; önceden tam doğrulanıp kodda sabitlenen dosya hash'lerini denetler. WSL Pillow12.2 yalnız yerel araç hedef dizinindedir; global ortam değiştirilmedi.

## Çalıştırılan kontroller

| Kontrol | Gerçek sonuç |
|---|---|
| Home | 11/11;18 ImageButton/36 foreground/72 arka plan bağı,21 mixer/84 arka plan durumu,35 korunmuş koyu panel rengi ve picture bool store |
| Özgün MUF çalışma kanıtı | `SetTextContent0x2e285b38`:145 benzersiz MIPS komutu; config renkleri child+0x7c/80/84/88'e kopyalandı. `UpdateCompositeData0x2e2853c0`:74 komut, renkler korunuyor. Servis/string/yerleşim bağımlılıkları açık callback modelidir |
| Kanal dönüşümü | 5/5;25 talimat,50 eski/yeni tek komut MIPS deneyi, resim/yerleşim ve yanlış girdi reddi |
| Ayar dönüşümü | 3/3;13 tam yerel argüman, resim ölçüsü/kontrast, bozuk instruction ve kaynak çakışması reddi |
| V8 birleşim/kod pinleri | 4/4; yeniden üretim ile paket pinleri aynı, eski Image kayıtları ve allowlist dışı ELF baytları değişmiyor, ID boşluğu/path kaçışı/tahrif edilmiş pin reddi |
| Native çizim | 17/17; v8 ses/sayı ve özel menü kaynakları dahil özgün MUF fonksiyonları |
| HTTP / görüntüleyici JS | 6/6 +9/9; v8 kaynak sahnesi, sınırlar, hızlı girdiler ve hata durumları |
| Gerçek Chrome native-kare testi | [4 kontrol geçti](../analiz/native-ui-port-v8/native-browser-tests.json); tarayıcı TV widget'ı çizmez, üretilen1920×1080 PNG'yi gösterir. Mute, hızlı tuşlar,0/100 ve örnek kanal adı eklenmemesi kontrol edildi |

İncelemenin üç ara overlay'i kontrast/kart flag'i düzeltmeleri öncesinde ayrı `v8-rejected-*` dizinlerine alınmıştır; bu adaylardan BIN yayımlanmadı. Son bağımsız dar incelemede açık P1/P2 yoktur. Yeni sürümün TV'de güvenli kabulünü veya tam görünüm eşliğini bu incelemeden çıkarmayız.

## MUF görüntüsü ve açık sınırlar

Başlatma: `python scripts/native_frame_viewer.py --port 4174`. [Native MUF kaynak testi](http://127.0.0.1:4174/) gerçek v8 dosyalarını, özgün MIPS DrawBackground/RenderImageToSurface/DrawString yollarıyla çizer. [PNG](../analiz/native-frame-rehost/v8-native-resources.png) ve [komut/callback kanıtı](../analiz/native-frame-rehost/v8-native-resources.json).

Bu kaynak karşılaştırma levhasının yerleşimi host tarafından hazırlanır; tam menü OnCreate/event döngüsü yürütülmüş değildir. DirectFB yüzeyleri ve font rasterizer Pillow/FreeType ile modellenir. V8 sayı ekranı yalnız gerçekten mevcut native sayı widget'ını gösterir; gerçek kanal adı [köprüsü](bilgi-tabani/NUMERIC_KANAL_ADI.md) kurulmadı.

Üst dokuz Home kartının image-enable varsayılanı/runtime dolgu görünümü gözlenmedi. Açık parent üzerinde ikon kontrastı statik olarak güvenlidir; bütün odak/kart dolguları cihazda doğrulandı denmez. Kanal listesi tamamen beyaza çevrilmedi; ayarların yalnız ortak stil yolundan geçen odak/başlık yüzeyleri değişti. Dinamik içerik yenilemelerinin bütün renk dalları, gerçek TV/GOP, tuner/video/HDMI ve tam UI piksel eşliği açıktır.

45 ek PNG'nin sıkıştırılmış dosya toplamı150.153 bayttır. Hepsini32bit texture sayan basit üst sınır6.570.964 bayt (~6,27MiB); DirectFB yüzey/cache kopyaları ve eski kaynakların birlikte yaşaması buna dahil değildir. TV bellek/FPS ölçümü yapılmadı. Yeni blur, ek widget veya global animasyon açılmadı.

Kullanılan beceriler: `reverse-engineer-anything`; bağımsız incelemede `verification-loop`. Alt işler Home, kanal ve paketleme sahipliklerine ayrılmıştır.

## Son devam: ikonlar ve gerçek bağlantılar

22 aktif ikon güncel onaylı Chrome SVG’siyle birebir RGBA eşleşir;64/48px görünür ölçüler gerçek native Expand kutularına göre telafi edilir.14 pasif aile özgün OEM şekillerini korur. [İkon manifesti](../analiz/native-ui-port-v8/approved-icons/manifest.json). ELF/Num ve395 talimatlık değişiklik kümesi bu düzeltmede aynı kaldı.

[Native bağlantı denetimi](../analiz/native-ui-port-v8/menu-bindings.md):81 sınıf,1.181 message kaydı,1.059 tam FDE handler gövdesi,70 uygulama→frame factory ve1.854 gezinme çağrı noktası gerçek ELF baytlarından kontrol edildi. V7’ye göre yalnız üç görsel OnCreate handler gövdesi değişti; kalan1.056 gövde aynı. Bu, yeni/sahte tarayıcı rotası kurulması değildir; var olan native bağlantılar korunur. Runtime fonksiyon pointer çözümü ve bütün menülerin TV’de yürütülmesi henüz doğrulanmadı.
