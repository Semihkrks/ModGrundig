# Native UI v5 — kompakt ses paneli ve kavisli kanal numarası

Bu belge v5 aşamasının kaydıdır. Görüntüleyicinin güncel varsayılanı ve sonraki menü çalışması: [v7](UI_MENU_AYARLAR_V7.md).

24 Ekim 2026. Kullanıcının son düzeltmeleri uygulanmıştır. Ayrı çevrimdışı kaynak kopyasıdır; firmware paketlenmedi, orijinal/v3/v4 dosyaları değiştirilmedi, TV'ye yazılmadı.

[Yerel native test ekranı](http://127.0.0.1:4174) varsayılan v5'i açar. Başlatma: `python scripts/native_frame_viewer.py --port 4174`. [Kontrol kareleri](../analiz/native-ui-port-v5/native-review.png), [ses35](../analiz/native-frame-rehost/v5-volume-35.png), [ses0](../analiz/native-frame-rehost/v5-volume-0.png), [mute](../analiz/native-frame-rehost/v5-volume-35-mute.png), [ses100](../analiz/native-frame-rehost/v5-volume-100.png), [kanal123](../analiz/native-frame-rehost/v5-numeric-123.png), [beş haneli giriş](../analiz/native-frame-rehost/v5-numeric-10000.png).

## Görsel değişiklikler

| Öğe | V4 | V5 |
|---|---|---|
| Ses kapsülü | 76×500 | **68×450**; genişlik yaklaşık%10.5, yükseklik%10 azaldı |
| Ses sayısı | Lucida Sans Bold36 | Önceki **DINPro-CondMedium36** geri geldi; koyu renk korundu |
| Hoparlör/mute widget'ı | 30×30 | **42×42**, panel içinde x13/y394; gerçek mavi şekil genişliği yaklaşık30px |
| Ses çubuğu | x35/y92,6×320 | x31/y86,**6×276**; yeni kapsüle ortalı |
| Kanal numarası | Lucida Bold48, düz dikdörtgen | **DejaVu Sans48**, gerçek310×112 PNG üzerinde20px kavisli köşeler |
| Ses0 | Sessiz ikon dalı mevcut | Native Refresh ile yeniden doğrulandı; dört görsel durumun tamamı ID680 |

Ses0'da gerçek `RefreshVolumeUI 0xfb7d18` yürütmesi `MImg::Set` için ID680'i seçer; ses35'te ID682 seçilir. Bu, donanım mute servisine yeni bir komut eklendiği anlamına gelmez. Mevcut ses/ARC yönlendirme ve timer davranışı korunur. Büyük ikonlar v4'ün aynı onaylı PNG'leridir; yeni boyutlar Num kaynaklarında uygulanır.

## Gerçek kaynak bağlantısı

[Üretici](../scripts/build_native_ui_v5.py), [manifest](../analiz/native-ui-candidate/v5/manifest.json), [testler](../scripts/test_native_ui_v5.py). Toplam24 overlay dosyası vardır. V4'e göre yalnız ELF, Num tablosu, Image tablosu ve yeni sayısal kart PNG'si değişir.

- Ses fontu dört yerel OnCreate argümanında0x4af→0x4ae geri alınır; global font dosyası veya font tablosu değiştirilmez.
- Numeric OnCreate `0x895b84` içinde dört font argümanı `0x896730/40/50/60` adreslerinde mevcut ID0x4b0'a bağlanır: `08_APP/rc/rc/DejaVuSans.ttf`.
- Dört numeric arka plan MImg argümanı `0x896260/284/2a8/2cc` adreslerinde yeni ID2179'u kullanır.
- `0x896100` argümanı1 ve `0x89610c` jalr delay slot'u `sb a0,0x3a(s0)` yapılır. Delay slot servis çağrısından önce çalışırken s0 numeric arka planı, a0=1'dir. Böylece `DrawBackground 0x2e251be4` gerçek resim çizim dalını seçer. Bu dal normal arka plan renk dolgusunu kullanmaz.
- Image_res sonuna bir kayıt eklenir; önceki2179 kaydın ID ve baytları korunur. Yeni kaynak `../rc/ARimages/Grundig/modern/numeric_bg.png` olur.
- Native `BuildData 0x2e240ea4` type5 dalı, `BuildImgPathIndex 0x2e24069c`, `BuildIndex 0x2e240534` ve `GetImgPath/GetSTR` sınırları üzerinden kayıt eklemesi statik olarak doğrulandı. Mevcut Clrkey tablosunda ID2179 yokken `GetU32 0x2e2403a4` varsayılan `0xffffffff` döndürür. [Adresli parser/flag kanıtı](../analiz/native-ui-port-v5/resource-append-evidence.md).

Yeni ELF SHA256: `f48239c5b3ac82405edd42417518f4f22098a8771218ae87460bee8464f0c5a2`. Num SHA256: `81228423a23fde8bd54855d47d613b0cd61db381ebb332388d9e013d2a637a43`.

## Doğrulama ve sınırlar

- V5 overlay testleri **8/8**, içindeki202 sınırlı MIPS ses/mute dalı denemesi geçti.
- Native çizim/metin testleri **12/12**; kompakt yerleşim, büyüyen gerçek ikon, geri alınan font, ses0 ikonu, kavisli PNG pikselleri ve native StretchBlit çağrısı kontrol edildi.
- Native durum testleri **7/7**; ses0/1/35/100, yeni geometri ve korunmuş ARC davranışı kontrol edildi.
- Yerel HTTP testleri **3/3**, gerçek görüntüleyici JavaScript testleri **3/3** geçti.
- Orijinal/v3/v4/v5 toplam **76/76** Refresh senaryosu döndü. Bu sayıya callback servislerinin gerçek donanımda çalışması dahil değildir.
- Gerçek tarayıcıda v5,1920px PNG, ses35→0 ve rakam123 kontrol edildi; hata alanı boş kaldı. V5 ses35/0/mute/100 ve rakam123/10000 kareleri tek tek incelendi.

Bu aşamada33 ilgili otomatik test geçti. Gerçek `libmuf` çizim/hizalama/metin komutları çalışır; yüzey ve font rasterizer/ölçüleri yazılım katmanıdır. OnCreate kurucuları, tam event döngüsü, kanal ayarlama, tam uygulama açılışı ve TV piksel eşliği doğrulanmış değildir. [Kalan çalışma ve emülasyon sınırları](NATIVE_GORUNTU_CALISTIRMA.md).
