# Native UI v4: ikon ve tipografi denetimi

24 Ekim 2026. Salt okunur inceleme; bu kayıt kaynak firmware'i veya adayları değiştirmez. İncelenen görüntüler: `analiz/native-frame-rehost/v3-volume-35.png`, `v3-numeric-123.png`. İncelenen üreticiler: `scripts/build_native_tv_assets.py`, `scripts/build_soft_ui_assets.py`, `scripts/render_native_tv_assets.mjs`; hedef çizgi: `ui-preview/styles.css`, `ui-preview/tv-icons.svg`.

## Görsel farkın kanıtlanan nedenleri

- Native ses sayısı `VolumeControlFrame::OnCreate`, giriş `0x00fb9780`, child `frame+0x1ac` için font ID `0x4ae` ve Num `0x3215=36` kullanır. `Image_res.bin` ID1198 bu fontu `../rc/font/DINPro-CondMedium.otf` dosyasına bağlar. Önizleme ise Segoe UI/Arial, 32px ve 600 ağırlık kullanır. Bunlar farklı tipografidir; native karede iki haneli sayı çok dar görünür.
- V3 hoparlör kaynağı 100x100; üretici onaylı 32x32 sembolü yalnız 54x54 alana koyar. Sembolün kendi iç boşluğu da eklenir. PNG'deki mavi piksel sınırı `(28,31)-(76,69)`, yani 48x38'dir. Native 30x30 widget'a indirgendiğinde eşiklenmiş görünür alan yalnız 15x12 olur. Önizlemede 30px SVG doğrudan kullanıldığından aynı ölçek değildir.
- Native rakam `Color0x25=0xff0082d4` mavisidir. Önizleme sayısı `#243c4f` koyudur. Mavi ilerleme çubuğunu koruyarak yalnız rakamı koyulaştırmak okunabilirliği artırır.
- Native numeric kanal girişi mevcut Lucida Sans Bold 48px kullanır. Bu yüzden ses sayısından daha tok görünür. V3 numeric karedeki kutu 310x112'dir; önizlemedeki 310x224, kanal adı ve ipucu içeren kart ile işlevsel/görsel eşliği yoktur. Bu eksikliği yalnız ikon/font düzeltmesi çözmez.

## Dar kapsamlı native düzeltme

Ses sayısında mevcut font ID1199 (`0x4af`) kullanılsın; font dosyası ve `Image_res.bin` değişmesin. Global Num3215 veya global renk tabloları değiştirilmesin. Font36 korunsun. Sadece `frame+0x1ac` için dört durumun font/renk yükleyen talimatı değişsin.

| Amaç | Talimat VA | Eski bayt | Önerilen bayt | Bağlantı |
|---|---|---|---|---|
| Normal font | `0x00fbbe18` | `ae040224` | `af040224` | `addiu v0,zero,0x4af` → child+0x130 |
| İkinci durum font | `0x00fbbe28` | `ae040224` | `af040224` | child+0x13c |
| Üçüncü durum font | `0x00fbbe38` | `ae040224` | `af040224` | child+0x148 |
| Dördüncü durum font | `0x00fbbe48` | `ae040224` | `af040224` | child+0x154 |
| Normal metin rengi | `0x00fbbc30` | `25000424` | `00000424` | `addiu a0,zero,0`; RcGetColor → child+0x7c |
| İkinci durum rengi | `0x00fbbc50` | `25000424` | `00000424` | RcGetColor → child+0x80 |
| Üçüncü durum rengi | `0x00fbbc70` | `25000424` | `00000424` | RcGetColor → child+0x84 |
| Dördüncü durum rengi | `0x00fbbc90` | `25000424` | `00000424` | RcGetColor → child+0x88 |

Font atamalarından sonraki dört RcGetNum çağrısı `0x00fbbe58/7c/a0/c4` halen Num3215 kullanmalı; diğer widget/font tüketicileri etkilenmemeli. ProgressBar iç child+0x254 font atamaları `0x00fbcc50/64/78/8c` bu değişikliğe dahil değildir. Sayı rengi için kullanılan RcGetColor GOT `0x010c6aa8`; metin gövdesi Ghidra C `analiz/native/ui-targeted/dvbt_board/00fb9780.c`, sayı oluşturma bölümü satır 500–562. Yukarıdaki baytlar Capstone ile orijinal ELF üzerinde okundu; talimat çalıştırması bu denetimin kapsamında değildir.

İkon için onaylı speaker/mute geometrisi aynı kalsın; 100px kaynak içindeki sembol 54px yerine merkezlenmiş 80px alana yerleşsin. Beklenen görünür genişlik yaklaşık 22px, yükseklik 17px; çıktı PNG ve native 30px ölçek üzerinde yeniden ölçülmeli. Nihai piksel eşiği rasterizer/quantize aşamasına bağlıdır. Hedef widget 30px kalır; yalıtılmış bu değişiklik koordinatları ve olay davranışını etkilemez. Kaynak beyaz alan kapsülle aynı ton olmalı, mute alfa biçimi korunmalı.

## Ölçüm

Pillow FreeType ile mevcut kaynak fontlar ölçüldü. Bunlar TV'nin DirectFB font metrikleri olarak sunulmaz; mevcut rehost rasterizer sınırının ölçümleridir.

| Font ve boyut | `35` genişlik | `100` genişlik | Sonuç |
|---|---:|---:|---|
| DINPro CondMedium36 | 26px | 39px | Dar ve ince algılanıyor |
| Lucida Sans Bold32 | 40px | 60px | Geniş kenar payı |
| Lucida Sans Bold36 | 46px | 69px | 76px metin widget'ına sığar, her yanda 3.5px |
| Lucida Sans Bold38 | 48px | 72px | Yalnız 2px kenar payı |
| Lucida Sans Bold40 | 52px | 78px | 76px widget'a sığmaz |

Kaynak pinleri:

- Orijinal dvbt_board: `51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916`.
- Image_res.bin: `d6b1b9fde60c9cc4624f264a8e75da4245e6fb3e9dab7534ddce01706fbcd2f3`.
- Lucida Sans Bold.ttf: `347e36d73e5db9b791c4ad385e391bf6fceeb0e17e830634d5fe35ca7da5f0bb`.
- DINPro-CondMedium.otf: `1e00616ed6d74da0eb3105683da02722e697c52f4a7461c1d0bd891ae344aa75`.

## Doğrulama sınırları ve sonraki kontrol

Yeni adayda 0,1,9,35,99,100 ve mute örnekleri üretilmeli; üç haneli sayı kırpılmamalı. Speaker ve mute görünür bbox'ları ölçülmeli, çizgi kalınlıkları aynı tutulmalı. Muhtemel önce/sonra büyütme görselleri yalnız inceleme yardımcısıdır; 1920x1080 tam kare de korunmalı. DirectFB/GetHeight gerçek font backend'i farklı olabileceğinden son cihaz rasterizer eşliği henüz kanıtlanmış değildir. Lucida fontunda Pillow ascent/descent `28,-7` dönüyor; bu mevcut numeric fontla da geçerli bir metrik modelleme sınırıdır, gizlenmemeli.

V4 renderer font/renk bilgisini değiştirilmiş ELF talimatlarından doğrulamalı; sadece Python'da başka font seçerek bunu native değişiklik diye göstermemeli. Mevcut MIPS DrawString/DrawSingleLine çalışması ile host FreeType yüzeyi ayrı belirtilmeli. Ana menü, kanal listesi, bilgi paneli ve canlı yayın yolu bu dar düzeltmeyle tamamlanmış sayılmaz.
