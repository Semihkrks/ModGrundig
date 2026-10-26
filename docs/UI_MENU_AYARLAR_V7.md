# Menü, ayarlar ve kanal önizlemesi — v7

Sonraki gerçek firmware çalışması: [native MUF v8](UI_NATIVE_ADAY_V8.md). Aşağıdaki belge Chrome tasarım aşamasını korur; native port kapsamı v8 raporunda ayrıca açıklanır.

24 Ekim 2026. Mevcut Chrome tasarımı ve Vanilla JS uygulaması korunarak devam edildi. Orijinal firmware değiştirilmedi; TV'ye yazılmadı ve yeni BIN üretilmedi. Çalışma dalı `codex/ui-soft-preview`.

## Çalışan ekran

`python scripts/native_frame_viewer.py --port 4174`

- [Menü ve ayarlar tasarım önizlemesi](http://127.0.0.1:4174/preview/?menu=1): HTML/CSS/JS; mevcut durum modeli ve açıkça etiketlenmiş 12 örnek kanal.
- [Kısmi native MUF çizim laboratuvarı](http://127.0.0.1:4174/): ayrı yüzey; seçilmiş özgün MIPS çizim fonksiyonları ve host yüzey/servis sınırları. Varsayılan v7.

Menüde yönler/Enter/Esc gezinir; M menüyü açar/kapatır. TV ekranında Enter kanal listesini, rakamlar kanal girişini açar. F1 test kumandasını gösterir. Tab/Shift+Tab tarayıcı kumandasına erişim içindir. Ayarlar bellektedir; sayfayı yenilemek varsayılanları getirir.

## Uygulanan düzen

| Alan | Güncel durum |
|---|---|
| Ana menü | 456px yüksekliğinde iki raf; altı ana eylem, altı ayar kategorisi; beyaz yüzey ve açık mavi odak korunur |
| Ayarlar | 24 menü / 156 satır; aynı anda yedi 72px satır; odak çevresinde kayan pencere, taşmayan alt tuş ipuçları |
| Kanal listesi/düzenleyici | Sekiz görünür kanal; solda liste, sağda örnek program ayrıntısı; izleme, favori, atlama ve PIN akışları mevcut modelde |
| Sayısal kanal kartı | 310×224px; 58px rakam; başlık/rakam arasında en az16px; eşleşen örnek kanal adı |
| Ses | 68×450px kapsül, 44×44px gerçek PNG ikon alanı, önceki DINPro fontu; sıfırda mute ikonu; ARC ayrı durum |

Hafif açılış/odak geçişleri ve azaltılmış hareket tercihi desteklenir. TV görüntüsü yerine mevcut örnek sahne vardır; gerçek RF/codec/video düzlemi çalıştırılmaz. Ağ/Web/APP eklenmedi.

Son kontrol düzeltmeleri: doğrudan kanal sekmesi seçimi artık filtreyi yanlış ters çevirmiyor; boş radyo listesi favori talimatıyla karışmıyor; test kumandasının Tab/Enter/Space odağı TV komutlarıyla çakışmıyor. Ana ve gelişmiş arka ışık satırları ortak test görüntüsünü değiştirir; bu eşleme **host önizleme politikasıdır**, özgün firmware'in sensör/arka ışık algoritması değildir.

PNG ve fontlar dış servisten alınmaz. Beş kaynak kopyası `ui-preview/native-assets/`, `native-fonts/` ve [hash manifestinde](../ui-preview/native-assets/source-manifest.json) tutulur. `scripts/export_native_preview_assets.py` bunları doğrulanmış yerel dosyalardan çıkarır. Aynı içerik ayrı `node ui-preview/server.mjs` sunucusunda4173 üzerinden de açılabilir.

## Firmware ile bağlantısı ve aktarım sınırı

[Adresli kaynak denetimi](../analiz/native-ui-port-v7/menu-evidence.md) Türkçe metin tablosunu ve10 çağrı noktasını kaydeder. Örnekler: Home Ayarlar `Str0xf49 @0xd2f594`, General Dil & Klavye `Str0x1147 @0xd07094`, kanal filtresi Tümü `Str0xc0f @0x7a9e54`. Önizleme menü isimleri bu kaynaklara dayanır; modern sıralama ve etkileşim politikası birebir native widget yürütmesi değildir.

Özgün kanal kurulumunda Tümü/Dijital/Radyo/Analog/Ücretsiz/Şifreli/Uydu filtreleri görülür. Önizlemedeki Tüm Kanallar/Favoriler daha dar bir test politikasıdır. İsim veya string bulunması cihazda ilgili donanımın bulunduğunu kanıtlamaz. Kayıt, tarama, zamanlayıcı, medya ve CEC akışları donanım yerine yerel model kullanır.

Native v6 overlay mevcut sayısal widget'ı büyütür; dört yerel font argümanını58 yapar (`0x896784/7a8/7cc/7f0`) ve hizalamayı `0x896800` noktasında `0x11` yapar. Ses ikonunu42→44px büyütür. V7 yalnız `Num0x99a` rakam y değerini106→118 değiştirir. V7 toplam24 dosyadır; v6 ELF baytları korunur. [Üretici](../scripts/build_native_ui_v7.py), [manifest](../analiz/native-ui-candidate/v7/manifest.json).

V7 Num SHA256: `d293c1c7aeec39c4384915a66aa42be0c37b1fd52b726e74022551707d122cfa`. V6/v7 ELF SHA256: `9ededb627b8548d0b12f6495d66bac4a0943fb3d92e83a2f3547a86b1ec33dc3`.

Native laboratuvardaki kanal adı **önerilen ek widget + örnek kanal verisi** kullanır. Gerçek OnCreate/handler/kanal veritabanı köprüsü overlay'e kurulmadı. V7'de rakam y118, önerilen ad y206 olup kutular arasında10px vardır. Tam menü/ayar tasarımının native portu tamamlanmadı; Chrome ekranı ile TV'de piksel eşliği veya eksiksiz çalışma iddia edilmez.

## Gerçek doğrulama kayıtları

| Kontrol | Sonuç / kanıt |
|---|---|
| Etkileşim modeli | `node --test ui-preview/tests/*.test.mjs`: 50/50; arka ışık çift yön, geri yükleme ve sıfırlama dahil |
| Gerçek Chrome menü testi | [menu-v7/browser-tests.json](../analiz/ui-modernizasyon/menu-v7/browser-tests.json):24 menü/156 satır; kanal seçimi/favori; gerçek tuşlarla görüntü filtresi değişimi; sayı boşluğu/font; üç viewport ve azaltılmış hareket |
| Chrome kumanda ve boş durum | [remote-focus-tests.json](../analiz/ui-modernizasyon/menu-v7/remote-focus-tests.json): Tab/Shift+Tab, Enter/Space, F1 ve boş radyo ayrımı |
| Geniş tarayıcı regresyonu | [browser-tests.json](../analiz/ui-modernizasyon/browser-tests.json):10 kontrol geçti; ses0/100, mute/ARC, hızlı girdiler ve menü akışları; bu aşamada yeniden çalıştırıldı |
| Native çizim | `test_native_frame_rehost.py`:15/15; v7 geometrisi, kaynak baytları ve sınırlı özgün MIPS yürütmesi |
| HTTP sınırları | `test_native_frame_viewer.py`:5/5; parametre/host/origin, statik önizleme ve sabit grafik kaynakları |
| Native görüntüleyici JS | `test_native_frame_viewer.mjs`:9/9; hızlı girdiler, eski istekler, sayı onayı ve hata durumları |
| V7 overlay | Üretici `verified_existing_v7`,24 dosya; önceki orijinal hash metaverisi ve hesaplanan çıktıyla eşleşme |

Bu sayılar farklı test kapsamlarıdır; toplamları TV doğrulaması olarak kullanılmaz. Chrome raporları `deviceTested=false`, `firmwareExecuted=false` taşır. Native rehost seçilmiş fonksiyon yürütür; tam firmware açılışı değildir. V6 overlay'in önceki7/7 sonucu tarihsel kayıttır; bu aşamada ağır v6 üretim paketi yeniden çalıştırılmadı.

Bağımsız incelemede bulunan arka ışık ve boş radyo sorunları kapatıldı; dar yeniden incelemede açık P1/P2 bulunmadı. İlk menü testi, dosyalar düzenlenirken sayfa hazır olma zaman aşımına uğradı; düzenlemeler bittikten sonraki tam tekrar geçti. Bu geçici hata başarı olarak sayılmadı.

## Sonraki teknik engeller

1. Gerçek kanal adı için [adresli ABI ve çağrı yolu](bilgi-tabani/NUMERIC_KANAL_ADI.md) mevcut; widget kaydı/ömür yönetimi, güvenli PIC helper yerleşimi ve event köprüsü henüz uygulanmadı.
2. Menü/ayar font, ikon, kaynak ID ve event yollarını native modüle taşımak ayrı port çalışmasıdır. Tarayıcı animasyonu MUF/DirectFB performansı kanıtı değildir.
3. Tam uygulama başlangıcı kayıtlı `UBI_ReadDataOffset0x2cb86ef4` / `/dev/shm/ubi0_0` sınırında durur. Gerçek tuner, ses, HDMI ve SoC görüntü düzlemi doğrulaması yoktur; ayrıntılar [emülasyon raporunda](TV_EMULASYON_ARASTIRMASI.md).

Örnek ekranlar: [ana menü](../analiz/ui-modernizasyon/menu-v7/01-main-menu.png), [görüntü ayarları](../analiz/ui-modernizasyon/menu-v7/03-picture-settings.png), [kanal listesi](../analiz/ui-modernizasyon/menu-v7/04-channel-list.png).
