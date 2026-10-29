# V7.6 — sessiz rozeti ve sayısal kanal geri bildirimi

26 Ekim 2026. V7.1 tabanlı ses GP düzeltmesi ve V7.5 gerçek kanal adı bağlantısı korunur. Ana menü ve ayarlar orijinaldir. **V7.6 çevrimdışı test adayıdır; henüz fiziksel TV'de denenmedi.**

- Sağ üst beyaz sessiz rozeti52×52→64×64, ikon26×26→32×32; ekran alanı `[1772,74,64,64]`, sağ/üst boşluk84/74. Legacy Image401 dosyası da modern görselle eşleştirilir. Cihazda eski simgenin neden göründüğü runtime izi olmadan kesinleştirilmedi.
- Sayı gerçekten eşleşmiyorsa **Kayıtlı kanal yok** yazılır. Kanal yöneticisi/route hatasında yanlış bir kayıt yok iddiası yerine ad temizlenir. Baştaki sıfırlar ve gerçek kanal adı sorgusu korunur.
- Altında254×4 mavi çizgi, ayrı50ms ID2 native timer ile azalır. Orijinal ID0/1 ve2000/3000ms kanal seçim süreleri aynen çağrılır; kozmetik çizim tuning'i geciktirmez. Her rakamda çizgi sıfırlanır. Orijinal timeout/OK/teardown ile iptal edilir; gecikmiş görsel olaylar fiziksel TV'de ölçülmedi.

Native helper7, ELF/CFI4, pakete yerleşen gerçek hook6, mute kaynak6, V7.6 önizleme9 ve ortak APP builder8 test geçti. Bağımsız inceleme GP/RA/SP/t9, string ömrü, timer ayrımı ve FDE kayıtlarında yeni uygulanabilir hata bulmadı. YeniRX alan62520 bayt;6741 eski unwind kaydı korunup4 eklenir. Cihazın grafik sürücüsü, gerçek DB, timer akışı ve Türkçe glif rasterizasyonu henüz cihazda doğrulanmadı. Native allocation istisnalarında helper yerel LSDA temizliği yoktur.

APP yeniden çıkarılarak2374 dosya/2777 metaveri kaydı doğrulandı;2359 orijinal normal dosya aynıdır. UBIFS codec0/1 ve19083 committed node CRC kontrolü geçti. BIN'de14 payload açıldı,13'ü birebir orijinal kaldı. RAR orijinal17 dosya/11 dizin düzeninde; yalnızGM_SWImage.bin farklı, diğer16 dosya ve sıkıştırılmış blokları aynıdır. 7-Zip veWinRAR bütünlük testleri geçti.

- [RAR test adayı](../analiz/native-ui-candidate/v7.6-tv/package/GMGRMR.-.-.-.-.V03.017.04_V7.6_TEST.rar)
- [Hash, kapsam ve test kaydı](../analiz/native-ui-candidate/v7.6-tv/phase-results.json)
- [Kanal mesajı ve sayaç kanıtları](UI_NATIVE_V76_NUMERIC.md)
- [Sessiz rozetinin kaynakları ve sınırları](UI_NATIVE_V76_SESSIZ.md)
- [Kurulu hook test kaydı](../analiz/native-ui-v76/installed-hooks.json)
- [Kayıtlı olmayan numara önizlemesi](../analiz/native-frame-rehost/v76/numeric0000.png)
- [Yeni rozet önizlemesi](../analiz/native-frame-rehost/v76/badge.png)

Önizleme `http://127.0.0.1:4174/` varsayılanV7.6 ile gerçek yerleştirilmiş yardımcı byte'larını kontrollü callback'lerle çalıştırır. PC'nin demo kanal listesi firmware'e eklenmez. TamTV emülatörü değildir. Dosyalar ayrı `codex/v76-native-mute-numeric` dalındadır; orijinaller, önceki paketler, USB ve TV değiştirilmedi. Kullanılan beceri `reverse-engineer-anything`; doğrudan Ghidra/Unicorn kanıtları REA Evidence diye sunulmaz.
