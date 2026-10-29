# V7.8 varsayılan transponder veri adayı

Yalnız firmware'in ilk kurulum için kullandığı varsayılan Türksat listesine11767V/15000 DVB-S2 ekler. Mevcut V7.7 overlay dosyaları ve kodu byte byte aynıdır.6 veri testi geçti.

Geçerli cihaz SAT veritabanı Init yolunda yeniden yüklendiği için bu arşiv değişikliği mevcut kanal/TP listesine otomatik birleşmez. Fabrika sıfırlaması yaptırılmaz; SAT/kanal veritabanı değiştirilmedi. Kullanıcının sonraki açık paketleme isteğiyle ayrı test BIN/RAR'ı üretildi;4K decoder kilidi açıldığı iddia edilmez. Sonraki kullanıcı V7.8 denemesinde TRT Ultra HD adlı kanal listede, görüntü yok ve Dolby/HE-AAC olarak bildirilen iki ses seçeneğinde de ses yok. Ayrıntı `device-feedback.json`; bağımsız cihaz izi veya UHD oynatım başarısı değildir.

RAR: `package/GMGRMR.-.-.-.-.V03.017.04_V7.8_TRT4K_TP_TEST.rar`

SHA256: `3cf43a024ead701a5f72d20825a2258d41acb0592053bdcf48c8476dd4482ad6`

6 veri testi, APP yeniden çıkarma/metadata/CRC, bağımsız14 bölüm kontrolü, V7.7 ile2374 dosyanın karşılaştırması ve7-Zip/WinRAR testleri geçti. Yalnız frekans tablosu farklıdır;2373 APP dosyası V7.7 ile aynı kaldı. Üretici sürümü V03.017.04 ve boot dosyası değiştirilmedi; V7.8 yalnız aday etiketi. Ayrıntılar: `docs/UI_NATIVE_V78_TRANSPONDER.md` ve `phase-results.json`.
