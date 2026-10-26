# ModGrundig TV test ortamı

Güncel uygulama ve kanıt sınırları: [UI_TV_SIMULATORU.md](../docs/UI_TV_SIMULATORU.md).

Son devam aşaması ve doğrulamalar: [menü/ayarlar v7](../docs/UI_MENU_AYARLAR_V7.md). Ek kumanda/boş radyo testi: `node ui-preview/tests/remote-focus.mjs`. Tab/Shift+Tab tarayıcı test kumandasına erişir; odağındaki Enter/Space o düğmeyi çalıştırır. Ana/gelişmiş arka ışık değerleri yalnız host önizleme politikası olarak senkrondur.

Orijinal firmware'in iki raflı Home yapısı, satırlı ayar menüleri ve sol kanal listesi/sağ program ayrıntısı esas alınır. Güncel tasarım önizlemesinde ana menü 456px yüksekliğindedir; ayarlar yedi 72px satır gösterir. Ses kapsülü native adayın 68×450px ölçüsünü, 44px PNG ikon alanını ve yerel DINPro fontunu kullanır. Ağ/Web/APP yoktur. Kullanıcının izniyle 12 geçici örnek kanal bulunur; programlar kurmacadır.

Güncel birleşik görüntüleyicide `http://127.0.0.1:4174/preview/?menu=1` doğrudan ana menüyü açar. `?menu=1` olmadan yayın görünümünden başlanır. Bu yüzey **tasarım önizlemesidir**; menülerin tarayıcıda çizilmesi, native menü kodunun çalıştırıldığı veya televizyonda aynı göründüğü anlamına gelmez. Kanal filtrelerindeki “Tüm Kanallar / Favoriler” mevcut test politikasıdır; native filtre sekmelerinin tamamının aktarımı değildir.

```powershell
node ui-preview/server.mjs
node --test ui-preview/tests/tv-model.test.mjs
node ui-preview/tests/browser.mjs
python scripts/native_frame_viewer.py
node ui-preview/tests/new-menu-layout.mjs
```

http://127.0.0.1:4173/ — M menü, yönler/Enter/Esc kumanda, +/- ses, S mute, rakamlar kanal, PageUp/PageDown kanal değişimi, I bilgi, V kaynak, G rehber, R önceki kanal. F1 test kumandası. Kanal düzenleyicide F2 favori/F3 atla/F4 kilit. Demo PIN0000. P bekleme; U test USB bayrağı.

24 menü/156 satır. Kontroller gerçek TV/CEC/RF işlemi yapmaz. Sinyal veya USB dosyası yokken ölçüm/oynatma uydurulmaz. Ayarlar bellektedir; yenileme varsayılanları getirir. Kaynak listesi fiziksel port doğrulaması değildir.

Native kaynak adayları ui-assets/ altında ayrı tutulur. Güncel önizlemedeki `native-assets/` ve `native-fonts/` yolları hash ile sabitlenmiş yerel grafik/font kopyalarını sunar; dış font servisi kullanılmaz. HTML/CSS/JS TV'de çalıştırılmadı veya yüklenmedi. Tarayıcı yumuşatması native MUF animasyon desteği kanıtı değildir.

24 Ekim menü yerleşimi doğrulaması: [Chrome test sonucu](../analiz/ui-modernizasyon/menu-v7/browser-tests.json). 24 menüde 156 satır, kanal filtresi/izleme, sayı kartı boşlukları, 1920×1080 / 1280×720 / 390×844 görünüm ve azaltılmış hareket kontrolü geçti. Cihaz testi yapılmadı.

Genişletilmiş kapsam: [UI_OZELLIK_KAPSAMI.md](../docs/UI_OZELLIK_KAPSAMI.md). A ses dili, B altyazı, T teletekst, C kayıt, Space oynat/duraklat, X durdur, J/L sar. F5/F6/F7/F8 renk tuşları; Medya içinde sarı tuş ayarlar. F1 tüm test tuşlarını gösterir. Video/ses medya kataloğu ve PVR yalnız demo durumlarıdır, codec/RF/disk kaydı değildir.
