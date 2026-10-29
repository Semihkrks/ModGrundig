# V7.9 — seviyeli ses ikonları ve yarım kenar boşluğu

27 Ekim 2026. Kullanıcının ikon onayı ve “7.9'a yaz” isteği uygulandı. [V7.9 RAR test paketi](../analiz/native-ui-candidate/v7.9-tv/package/GMGRMR.-.-.-.-.V03.017.04_V7.9_VOLUME_TEST.rar). Ayrı dal `codex/v79-volume-levels`; orijinal firmware, çalışan V7.7 ve V7.8 paketleri korunur. USB veya TV'ye yazılmadı. Beceriler: `reverse-engineer-anything`, mevcut SVG ikon sistemini koruyan `redesign-existing-projects` ve bağımsız ECC incelemesi. Doğrudan native/Capstone/Unicorn çıktıları REA Evidence değildir.

## Gerçek native davranış

| Durum | Normal ses paneli ikonu |
|---|---|
| Ses0 veya mute |Mevcut gri sessiz simgesi680; gri panel/bar korunur.|
|1–20|Yeni tek dalga, image2182.|
|21–60|Mevcut iki dalgalı ikon682 byte byte korunur.|
|61–100|Yeni üç dalga, image2183.|

Mevcut hoparlör gövdesi, mavi renk ve çizgi kalınlığı korunur. Onay SVG'leri Chromium8× rasterizasyon / LANCZOS / OEM P8 hattında100×100 PNG kaynaklarına dönüştürüldü; native widget44×44 kalır. `Image_res.bin` eski0..2181 kayıtları korunarak iki kaynakla2184 kayda çıkar. Yeni dosyalar yalnız `Grundig/modern/volume_low.png` ve `volume_high.png`.

Gerçek `RefreshVolumeUI` içindeki0xfb820c/0xfb8210 iki sözcük,0x1161400 adresindeki72 bayt saf leaf yordamı çağırır. Yordam mevcut RX segmentinin doğrulanmış sıfır boşluğundadır; ELF boyutu, segment başlıkları, GOT, eski CFI/EH ve önceden yerleştirilmiş isim/mute yordamları değişmez. Etkin ses ve audibility değerinden yalnız V1 ikon ID'si üretilir; bellek/stack/GP/S-register değişikliği ve dış çağrı yoktur. Sonuç eski0xfb8214 store'una döner; dört özgün MImgSet çağrısı korunur. Özgün mode kontrolü nedeniyle yalnız yerel mode0 bu yola girer; ARC/nonlocal1/2/3 kodu korunur. Saf leaf içinde senkron exception/cleanup yolu yoktur; bu72 bayt aralığında asenkron unwind doğrulanmış sayılmaz.

Sol boşluk `Num_res.bin` ID0x5a41 offset92476'da80→40 mantıksal piksel olur. Panel ve çocukları40 piksel sola taşınır; panel68×450 ve ikon44×44 kalır.1920×1080 kaynak koordinatıdır; cihaz overscan ölçümü değildir. Native dış pencere ve bütün çocuk sınırları doğrulandı.

Sağ üst kalıcı sessiz rozeti, mute tuşu akışı, ses0 davranışı, kanal numarası/adı, kayıtlı kanal yok mesajı ve orijinal kanal seçim süreleri korunur. Menü/ayar tasarımı değişmez. V7.8'in varsayılan TRT4K frekans tablosu korunur; yeni4K decoder, downscale veya ses codec değişikliği eklenmez. Üretici sürümü V03.017.04 ve boot dosyası değiştirilmedi. V7.9 kullanıcı arayüzü adayının adıdır; sürüm kontrolünü atlatma değildir.

## Doğrulananlar

- **31 test metodu geçti:**8 asset,7 native wave,6 yeni frame/lifecycle/default,10 önceki V7.7 regresyonu. Yeni varsayılanın V7.9 olması ayrı test edildi; V7.7 HTTP regresyonu artık açık sürüm seçer.
- **85 kayıtlı native senaryo:**20/21 ve60/61 sınırları,0/1/100, özgün101/255 clamp, mute/unmute, tuşla eşik geçişleri, ARC/nonlocal önce/sonra eşitliği ve GP/SP/register koruması. Gerçek yerleştirilmiş talimatlar çalışır; audio/widget servisleri sınırlı modeldir.
- Chromium'da varsayılan V7.9, ses+, gerçek mute/unmute sahneleri ve12 kanal girişi çalıştı; sayfa hatası yok. Altı aktif4174 HTTP karesi güncel yerel native render ile byte byte eşleşti. Önizleme yalnız PNG framebuffer gösterir; tam TV emülasyonu değildir.
- Bağımsız ajan incelemesi: **APPROVE**, uygulanabilir hata bulgusu yok.18 overlay kaydı doğrulandı; V7.8'e göre yalnız ELF/NUM/Image tablosu ve iki yeni PNG farklıdır. Yeni native yordam hataları mock başarı dönüşüyle gizlenmez.
- APP yeniden çıkarılarak2376 normal dosya ve2779 metadata kaydı doğrulandı. Özgün2773 metadata kaydı ve ilan edilmiş altı yeni inode korunur.19090 committed UBIFS node CRC geçti; native ELF raw, diğer kaynaklarda codec0/1; yeni kernel codec gerekmez.
- BIN14 bölüm olarak açıldı;13 bölüm özgün kaldı ve dış CRC'ler geçti. RAR17 dosya/11 dizin; yalnızGM_SWImage.bin değişir, diğer16 üye/blok aynı kalır. **7-Zip ve WinRAR testleri geçti.**

## Kanıtlar ve dosyalar

- [Birleşik paket/test/hash kaydı](../analiz/native-ui-candidate/v7.9-tv/phase-results.json)
- [Son31 test sonucu](../analiz/native-ui-v79/final-tests.json)
- [85 native senaryo](../analiz/native-ui-v79/wave/bounded-tests.json)
- [Bağımsız inceleme](../analiz/native-ui-v79/review/final-review.json)
- [BIN bağımsız okuma](../analiz/native-ui-candidate/v7.9-tv/package/independent-readback.json)
- [RAR iki okuyucu ve üye hash kontrolü](../analiz/native-ui-candidate/v7.9-tv/package/vendor-rar-validation.json)
- [Chromium etkileşim kaydı](../analiz/native-ui-v79/preview/browser-verification.json)
- [Aktif4174 eşleşmesi](../analiz/native-ui-v79/preview/active-server-verification.json)
- [Tek dalga20](../analiz/native-ui-v79/preview/volume20.png), [üç dalga61](../analiz/native-ui-v79/preview/volume61.png), [gri ses0](../analiz/native-ui-v79/preview/volume0.png)

RAR43.141.176 bayt; SHA256 `ee8cd53d0815cf9a2637ddd052e723b7eab76eeccde132e1bf8b9261194defb9`.

BIN SHA256 `ae6a322861e3b288294b0e4a5f5faf33cb41864439508b2fcee4f6d89ddba496`.

APP SHA256 `438caad4b1fed4a908d018e154da7939f21a20c4440eab5bc9c6238f104ee4c1`.

Sunucu: `http://127.0.0.1:4174/`, varsayılan V7.9. V7.9 fiziksel TV testi henüz yapılmadı; gerçek ses/ARC/DirectFB zamanlaması ve overscan sonucu bu çevrimdışı testlerden garanti edilmez. V7.8'de bildirilen TRT Ultra HD ses/görüntü yokluğu ayrı A/V araştırmasıdır.
