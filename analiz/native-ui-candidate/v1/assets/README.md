# Native PNG kaynak adayı v1

Bu klasördeki `candidate/08_APP/rc/ARimages/` ağacı, orijinal firmware'in gerçek resource yollarına karşılık gelen **20 değiştirilmiş PNG** içerir. Firmware imajı veya TV'ye kurulabilir güncelleme paketi değildir.

- Kaynak çizimler: `ui-preview/tv-icons.svg`, manifestte SHA-256 ile sabitlenir. Önceki kutulu web çizimleri kullanılmaz.
- 12 Home kaynağı: video 985/986, sound 973/974, source 975/976, lock 967/968, schedule 979/982, settings 983/984. Son onaylanan sembol geometrisi 190×190 RGBA yerlerine rasterize edilir. OEM mavi/koyu yüzeylerde açık gri normal ve cyan odak rengi kullanılır; ayrı beyaz kart eklenmez.
- 4 ses kaynağı: arka plan 674, sessiz 680, hoparlör 682 ve sürgü 681. Onaylanan beyaz tasarıma göre arka plan ve hoparlör yüzeyi `#f5f5f5`, simgeler mavidir. Sessiz göstergesi alpha destekleyen beyaz yuvarlatılmış rozet kullanır. **681 tamamen şeffaf P8/tRNS adayıdır**: `VolumeControlFrame::OnCreate 0xfb9780`, `analiz/native/ui-targeted/dvbt_board/00fb9780.c:650–653` içinde aynı thumb'ın dört durum görseline literal bağlandığı görüldükten sonra bu değişiklik istendi. Bu, bütün dinamik resource kullanıcılarının yokluğunu kanıtlamaz; genel resource değişiminin bu belirsizliği manifestte korunur.
- ARC kaynakları 4/5/6: 158×89 LA8 ve monokrom alpha biçimi korunur.
- Ses arka planı düz beyazdır; seviye veya kanal/sayı verisi raster görsele gömülmez. Eski adayda bulunmuş gri çizgi kaldırılmıştır: gerçek track/progress native widget tarafından kendi Num koordinatlarında çizilir. Böylece arka plan esnetildiğinde sayı ve hoparlör arkasına taşan sahte çizgi oluşmaz.
- Eski mavi halo 685 (`volume_shadow.png`, 104×690 RGBA) şeffaflaştırılır: aynı OnCreate C118–121 dört durum bağlamasını gösterir. Widget tahsisi/ölçüsü korunur; boyutu değişen panelin yanında eski mavi kontur çizilmez. Dinamik kullanım dışlanmış sayılmaz.

`manifest.json` dosyasında orijinal/güncel çizim/aday SHA-256 kayıtları, gerçek dosya yolları, resource ID, boyutlar, PNG tipi/bit derinliği, alpha yeteneği ve chunk CRC sonuçları bulunur. `validation.json` kaydı, 20/20 decode ve deterministik yeniden üretimi, 7 olumsuz path/plan denemesinin reddini ve orijinallerin korunmasını gösterir.

`native-home-contact.png` yalnız sentetik koyu zemin üzerinde aday ikon temas sayfasıdır; TV ekran görüntüsü değildir. `original-contact.png` orijinal ikonların sentetik koyu zemin üzerinde temas sayfasıdır.

P4 arka plan opak olduğundan, önizlemedeki beyaz yüzen kapsülün transparan köşeleri burada taklit edilmez. `MResourceManager::RenderImageToSurface 0x2e23e684` C çıktısında hedef dikdörtgenin genişlik/yüksekliği ve dolaylı yüzey çizim çağrıları görülür; nihai stretch/clip yöntemi ve köşe kırpması cihazda doğrulanmamıştır. Var olan arka plan PNG boyutu ve opaklık biçimi korunur; yeni alpha modu uydurulmaz. Native konumlar, menü yüzeyi, sayı yazımı, widget ölçüleri, event handler ve animasyon kodu bu dosyalarla değişmez. Color13 border ve Color25 progress/number yollarına dokunulmaz. Dolayısıyla görsel kaynak uyumluluğu TV'de tam tasarım eşitliğini kanıtlamaz. Native Num/ELF değişikliği ve fiziksel cihaz doğrulaması ayrıca gereklidir.

Yeniden üretim:

```powershell
python scripts/build_native_tv_assets.py prepare
node scripts/render_native_tv_assets.mjs
python scripts/build_native_tv_assets.py finalize
```

Orijinal `Image_res.bin` tablosunun SHA-256 değeri `d6b1b9fde60c9cc4624f264a8e75da4245e6fb3e9dab7534ddce01706fbcd2f3` olarak sabitlenir. Tablo/resource yolları, girdi hash'i ve bütün çıktı yolları yazmadan önce denetlenir. Kaynak PNG'ler, Num/Color tabloları, ELF programları ve orijinal paketler değiştirilmez.
