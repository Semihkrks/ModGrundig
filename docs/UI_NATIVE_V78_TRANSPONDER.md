# V7.8 — varsayılan TRT4K transponderi test paketi

27 Ekim 2026. Kullanıcı manuel uydu aramasını daha sonra yapacağını belirterek mevcut veri değişikliğini ayrı RAR olarak istedi. Paketleme çevrimdışı yapıldı; USB/TV'ye yazılmadı. Orijinal firmware ve kullanıcının TV'de çalıştığını bildirdiği V7.7 paketi korundu. Kullanılan beceri `reverse-engineer-anything`; yerel araç çıktıları REA Evidence değildir.

Sonraki kullanıcı denemesi: V7.8'de TRT Ultra HD adlı kanal listede; görüntü ve ayrı ayrı seçilen iki ses seçeneğinde ses yok. [Cihaz geri bildirimi](../analiz/native-ui-candidate/v7.8-tv/device-feedback.json). Bu kayıt paketleme sırasındaki çevrimdışı testlerle karıştırılmaz;4K oynatım başarısı veya keşfin yamadan kaynaklandığı kanıtı değildir.

## Tam olarak değişen

V7.7'deki native kod, menüler, ses/mute paneli, sağ üst sessiz simgesi ve kanal numarası/adı kaynakları aynen korunur. Tek ek değişiklik `/defaults/frequency_tables.tar.gz` içindeki Türksat42°E varsayılan tablosuna11767MHz / VERTICAL /15000 /DVB-S2 /8PSK /FEC3/4 satırının eklenmesidir. Türksat79→80 transponder olur; diğer bütün eski transponderler korunur. Frekans kaynağı ve gerçek tüketici kodu [4K araştırmasında](4K_YAYIN_VE_GIZLI_OZELLIKLER.md).

**Bu bir HEVC/4K kilit açma yaması değildir.** İncelenen tüketici Init, geçerli mevcut SAT DB'yi yükler; yeni default XML'i otomatik birleştirmez. Dolayısıyla bu paketin mevcut cihazda4K kanal bulmayı değiştirmemesi mümkündür. Kanal veritabanı migration'ı, reset veya tuner/decoder/panel flag değişikliği uygulanmadı. Gerçek UHD50/Main10 çözme ve1080p ölçekleme doğrulanmadı. Fabrika sıfırlaması önerilmez.

V7.8 yalnız bu adayın adıdır. `ProjectReleaseVersion.txt` üretici sürümü V03.017.04, boot ve diğer arşiv üyeleri aynı kaldı. Sürüm kontrolünü atlatan veya sürümü yükselten ek değişiklik yoktur; daha güncel paket kurulu uyarısının kalkacağı iddia edilmez.

## Paket ve doğrulamalar

- [V7.8 test RAR'ı](../analiz/native-ui-candidate/v7.8-tv/package/GMGRMR.-.-.-.-.V03.017.04_V7.8_TRT4K_TP_TEST.rar)
- [Birleşik paket kaydı](../analiz/native-ui-candidate/v7.8-tv/phase-results.json)
- [V7.7→V7.8 yeniden çıkarılmış dosya karşılaştırması](../analiz/native-ui-candidate/v7.8-tv/package/v77-v78-delta-validation.json)
- [Bağımsız BIN okuması](../analiz/native-ui-candidate/v7.8-tv/package/independent-readback.json)
- [RAR iki okuyucu ve tüm üye hash sonuçları](../analiz/native-ui-candidate/v7.8-tv/package/vendor-rar-validation.json)

| Kontrol | Gerçek sonuç |
|---|---|
| Varsayılan transponder dönüşümü |6/6 test geçti; eski veriler ve TAR metadata'sı korunur.|
| APP yeniden çıkarma |2374 normal dosya /2777 metadata kaydı doğrulandı.|
| V7.7 ile APP byte karşılaştırması |2373 normal dosya aynı; yalnız frekans arşivi farklı; bir symlink aynı.|
| Özgün APP metadata'sı |2773 kayıt korunur; yalnız önceki UI'nin ilan edilmiş dört yeni inode'u bulunur.|
| UBIFS |19083 committed node CRC geçti; codec0/1; native ELF raw, yeni kernel codec gerekmiyor.|
| BIN |14 bölüm açılıp CRC doğrulandı;13 bölüm özgün kaldı; dış CRC'ler geçti.|
| RAR |17 dosya /11 dizin; yalnız GM_SWImage.bin farklı; diğer16 dosya ve arşiv blokları korundu.|
| Bağımsız arşiv okuyucuları |7-Zip ve WinRAR bütünlük testleri geçti.|
| Fiziksel V7.8 TV geri bildirimi |Kullanıcı kanalı ve iki ses seçeneğini görüyor; görüntü ve iki seçenekte de ses yok. Bağımsız cihaz izi yok; UHD oynatım başarılı değil.|

RAR:43.141.176 bayt, SHA256 `3cf43a024ead701a5f72d20825a2258d41acb0592053bdcf48c8476dd4482ad6`.

BIN SHA256 `25c7296e6dfe73a1c00a2368204038716958999a225968d7f8cb1bd487975787`.

APP SHA256 `0ee9cdf256ebf92f1d76df7252a2a1aca8386bbe64958d690cdc23e7e1b4d61e`.

Yeniden üretme araçları: `scripts/build_native_ui_v78_tv.py`, `test_native_ui_v78_transponder.py`, `build_native_app.py --revision v7.8-tv --fs-compressor lzo-raw-elf`, `repack_native_swimage.py`, `verify_native_storage.py`, `verify_native_release.py`, `verify_native_ui_v78_delta.py`, `prepare_v78_vendor_rar.py`. APP derleyicisi özgün sahiplikleri izole staging ağacında korumak için WSL/Linux tek fakeroot oturumunda çalışır. Üretilen dosyalar orijinallerin üzerine yazılmaz. Arşivde ek rapor/README veya araştırma dosyası bulunmaz.
