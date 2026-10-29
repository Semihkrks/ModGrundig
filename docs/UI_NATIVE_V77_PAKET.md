# V7.7 — panel açıkken mute düzeltmesi, ses0 rozeti ve sayaç kaldırma

27 Ekim 2026. Kullanıcının son isteği uygulandı. **27 Ekim kullanıcı geri bildirimi: V7.7 gerçek TV'de sorunsuz çalışıyor.** Bu, kullanıcının genel kullanım gözlemidir; fiziksel4K/ARC sınırlarının bağımsız doğrulaması değildir. [Cihaz geri bildirimi](../analiz/native-ui-candidate/v7.7-tv/device-feedback.json). Orijinaller, V7.1 ve önceki paketler korunur; menü ve ayarlar değiştirilmez.

Panel açıkken Mute tuşu özgün OnKey kodunda mode1 seçip eski sol simgeyi gösteriyordu. `0xfb93d4` adresindeki mode seçimi0 yapıldı. Gerçek `SetMute(!IsMuted)` ve Refresh korunur: panel kapanmaz, alt sessiz ikon Image680 ve dolgu gri olur; mute kapatılınca pozitif seste maviye döner. Ses yöneticisinin mute cache'ini Refresh öncesinde senkron güncellediği adresli inceleme ve dört özgün leaf testiyle doğrulandı.

Panel zaman aşımı sonrasında mevcut sağ üst64×64 beyaz rozet, gerçek mute veya **yerel mode0'da ses0** durumunda gösterilir. ARC modunda yerel ses0 harici cihazın sessiz olduğu anlamına getirilmez.224 baytlık yardımcı `0x1161000` yalnız görsel koşulu hesaplar. Mode, uygulama kapanmadan önce FP+1c ölü dispatch alanına alınır; kapanmış frame okunmaz. Sonraki ses açma/panel yenilemesi rozeti önce kaldırır. Detaylı kanıt ve hook adresleri [sessiz akışı belgesindedir](UI_NATIVE_V77_SESSIZ_AKISI.md).

Kanal girişindeki mavi sayaç, çizgi widget'ı ve kozmetik timer tamamen kaldırıldı. Orijinal2/3 saniyelik kanal seçim süreleri ve OnTimer byte'ları korunur. Gerçek kanal adı ve **Kayıtlı kanal yok** mesajı kalır. Yeni ad alanı dışında ek numeric child/state yoktur. [Kanal kodu ve kapsamı](UI_NATIVE_V77_NUMERIC.md).

Doğrulamalar ayrı kapsamlarıyla:7 native kanal testi,4 kurulu isim kancası testi,8 gerçek kurulu OnKey/Refresh/timeout testi,5 ELF/CFI testi ve10 V7.7 önizleme testi geçti. Tarihsel14 önizleme testiyle birleşik24 test,12 HTTP kontrolü ve JS sözdizimi kontrolü geçti. Gerçek Chrome'da Mute→gri panel→3000ms timeout→sağ üst rozet ve sayaçsız01 girişi doğrulandı. Ses/heap/timer teslimi/app görünürlüğü ve çizim servisleri kontrollü modeldir; bu sonuç tamTV emülasyonu veya cihaz başarısı değildir. Bağımsız inceleme uygulanabilir yeni hata bulmadı.

APP yeniden çıkarılarak2374 dosya/2777 metaveri kaydı karşılaştırıldı;2359 özgün normal dosya aynı kaldı. UBIFS codec0/1,19083 committed node CRC ve volume sınırları doğrulandı. Yeni ELF segmenti62428 bayt;6741 eski unwind kaydı korunup3 yeni FDE ile6744 oldu. BIN14 payload olarak açıldı,13'ü özgün kaldı. RAR17 dosya/11 dizin içerir; yalnızGM_SWImage.bin farklıdır, diğer16 dosya/sıkıştırılmış blok korunur.7-Zip veWinRAR testleri geçti.

- [V7.7 RAR test adayı](../analiz/native-ui-candidate/v7.7-tv/package/GMGRMR.-.-.-.-.V03.017.04_V7.7_TEST.rar)
- [Hash/kapsam/test kaydı](../analiz/native-ui-candidate/v7.7-tv/phase-results.json)
- [Native olay geçişleri](../analiz/native-ui-v77/mute/native-transitions.json)
- [Bağımsız inceleme](../analiz/native-ui-v77/mute-review/final-review.json)
- [Önizleme/HTTP/Chrome kanıtları](../analiz/native-frame-rehost/v77/verification.json)
- [Mute sonrası gri panel](../analiz/native-frame-rehost/v77/mute_key35.png)
- [Ses0 sonrası sağ üst rozet](../analiz/native-frame-rehost/v77/timeout_zero0.png)
- [Çizgisiz numara ekranı](../analiz/native-frame-rehost/v77/numeric0000.png)

RAR SHA256: `725b6e1b39d8bf593bce50034d02a4fe83b2fcc7a5d9b72893cc7bd99ce593b7`.

Sunucu `http://127.0.0.1:4174/` varsayılanV7.7'dir. PC demo kanal verisi firmware'e paketlenmez. Kaynaklar `codex/v77-mute-flow-no-countdown` dalında; USB ve TV'ye yazılmadı. Önceki kapsamı ARC için daraltılmamış ara çıktı `v7.7-tv-draft-unscoped-zero` altında NOT_FOR_TV işaretiyle saklandı. Kalan sınırlar gerçek TV grafik/ses/ARC zamanlaması, DB davranışı, glif rasterizasyonu ve native allocation istisnasında yerel LSDA temizliğidir. Kullanılan beceri `reverse-engineer-anything`; doğrudan Ghidra/Unicorn kanıtları REA Evidence değildir.
