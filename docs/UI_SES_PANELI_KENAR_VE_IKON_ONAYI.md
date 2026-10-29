# Ses paneli — kenar boşluğu ve seviyeli ikon önizlemesi

Sonraki aşama: kullanıcı ikonları onaylayıp7.9'a uygulanmasını istedi. [Gerçek native seçim ve V7.9 test RAR'ı](UI_NATIVE_V79_SEVIYELI_SES.md) tamamlandı. Aşağıdaki onay taslağı kendi aşamasının tarihsel kaydıdır.

27 Ekim 2026. Kullanıcı panelin sol kenara mesafesinin yarıya indirilmesini, mevcut hoparlör şeklinin korunmasını ve ses seviyesine göre1/2/3 dalga ikonlarının uygulamadan önce gösterilmesini istedi. `reverse-engineer-anything` ile önceki native kaynak/çizim kanıtları kullanıldı; yeni Ghidra sorgusu, TV'ye yazma veya paketleme yapılmadı.

## Uygulanan kaynak adayı

Tam hash'i sabitlenmiş V7.8 `Num_res.bin` üzerinde normal ses paneli kök X resource ID`0x5a41`, dosya offset92476:80→40. Fiziksel ölçüm değil,1920×1080 mantıksal koordinattır. Kök/panel/numara/ikon/çubuk birlikte40 piksel sola taşınır; yükseklik, genişlik ve dikey konum değişmez. Dış native pencere`[0,160,160,725]` korunur; kök ve çocukların sınır içinde kaldığı doğrulanır. ARC'nin ayrı geometrisine müdahale edilmez.

- [Tek resource farkı ve geometri kanıtı](../analiz/native-ui-candidate/v7.9-margin-review/margin-proof.json)
- [İzole NUM adayı](../analiz/native-ui-candidate/v7.9-margin-review/overlay/08_APP/rc/rc/bin/Num_res.bin)
- [Yeni kenar mesafesinin native çizim önizlemesi](../analiz/native-ui-candidate/v7.9-margin-review/margin-after-native.png)
- [Önceki mesafe](../analiz/native-ui-candidate/v7.9-margin-review/margin-before-native.png)
- [Üç durumun native çizim doğrulaması](../analiz/native-ui-candidate/v7.9-margin-review/native-render-verification.json)

`scripts/build_native_ui_v79_margin_review.py` yalnız bu aday NUM'u ve kanıtını üretir. Beklenmeyen girdiyi reddeder; kaynak/yayın dosyalarının üzerine yazmaz. `native_frame_rehost.render(..., half_margin_review=True)` önce V7.7 gerçek kod/asset pinlerini doğrular, sonra yalnız türetilmiş NUM adayını okur. V7.7 ve V7.8 UI/native dosyaları aynıdır; V7.8'in ek değişikliği varsayılan RF tablosudur. Native ses state'inin NUM başlangıç modeli değişmediğinden yalnız kök konumu farklıdır; gerçek TV ölçekleyicisi/overscan ve DirectFB servisleri hâlâ modellenmiş sınırlardır.

## İkon kararı bekleniyor

Önerilen eşikler:1–20 tek dalga,21–60 mevcut iki dalga,61–100 üç dalga.0 veya mute mevcut gri sessiz simgesidir. Mevcut hoparlör gövdesi ve çizgi dili korunarak yeni SVG önizlemeleri hazırlanır. Bunlar onay görselleridir; gerçek RefreshVolumeUI içinde dinamik ikon seçimi veya yeni image ID bağlantısı bu aşamada uygulanmadı. Sağ üst kalıcı sessiz rozeti değiştirilmedi.

[İkon onay görseli](../analiz/ui-volume-review/v79-icons/icon-approval-board.png), [8 kontrolün sonucu](../analiz/ui-volume-review/v79-icons/verification.json). `redesign-existing-projects` becerisiyle mevcut SVG ikon sistemi genişletildi; orta seviyedeki iki dalgalı şekil mevcut kaynakla aynıdır. Büyük karşılaştırmanın altında44×44 widget ölçüsündeki görüntüler bulunur. Gövde/kalınlık/renk,1/2/3 dalga,100px kaynak canvas sınırları, masaüstü/mobil taşma ve tarayıcı hataları kontrol edildi. Bunlar firmware'e yüklenmiş PNG kaynakları veya gerçek TV testi değildir.

## Gerçek kontroller

V7.7'nin10 mevcut native önizleme testi geçti. Yeni NUM ile35normal/0normal/35mute olmak üzere üç çizim karşılaştırmasında panel ve tüm çocukları tam40 piksel sola taşındı; orijinal native state ve bar rengi aynı kaldı. Kaynak dönüşümünde tek değişen bayt92476'dır. Orijinal firmware, V7.7/V7.8 RAR'ları ve ELF dosyaları değiştirilmedi. Henüz bu değişikliği içeren yeni RAR yoktur.
