# V7.2 — sıfır ses ve mute görünümü

**Ara revizyon; dağıtılmayacak.** Kullanıcı bu aşamada eski ikonun şeklinin korunmasını, renginin gri olmasını ve mevcut ayrı sessiz göstergesinin güncellenmesini açıkladı. Güncel sonuç [V7.3 belgesindedir](UI_NATIVE_V73_GRI_SESSIZ.md). Aşağıdaki V7.2 kod/test bulguları tarihsel kanıttır; slash ikon tasarımı son pakette kullanılmaz.

25 Ekim 2026. V7.1'de sessiz ikonunun seçimi mevcuttu, panel arka planı ise sürekli beyazdı. Kullanıcının isteğiyle sıfır ses ve mute durumları gerçek `VolumeControlFrame::RefreshVolumeUI` yolunda aynı görsel duruma bağlandı.

| Durum | Panel | İkon |
|---|---|---|
| Ses1–100, mute kapalı | Mevcut beyaz kapsül, Image674 | Mevcut mavi hoparlör, Image682 |
| Ses0 veya mute açık | Soft mavi-gri kapsül `#DEE9F1`, Image2180 | Çapraz çizgili yeni sessiz hoparlör, Image680 |
| Mute kapanır, ses0'dan yükselir | Normal kaynaklara geri döner | Normal hoparlöre geri döner |

Mute açıkken mevcut ses değeri saklanır/gösterilir; örneğin35'te mute yapıldığında sayı35 kalır. Yalnız görsel kaynak seçimi değişti; ses servisine yeni mute komutu eklenmedi. Ses0 zaten sayısal sıfır seviyesidir. ARC modlarının ayrı servis davranışı korunur.

## Gerçek kod bağlantısı

`dvbt_board` içindeki `RefreshVolumeUI` (`0x00fb7d18`) normal ses modundaki mevcut `0x00fb8200..0x00fb8358` aralığında yeniden düzenlendi. 86 sözcüklük mevcut alana83 talimat ve3 padding sözcüğü sığar; ELF boyutu, segmentler, stack frame, import tablosu ve epilog adresi değişmez. Yeni code cave/trampoline kullanılmaz.

Önceki yerel seçim kuralı `volume == 0 || IsMuted` korunur. Her yenilemede dört `MImg` alanı (`+0xb8/+0xcc/+0xe0/+0xf4`) hem hoparlör (`frame+0x1a8`) hem panel (`frame+0x1a4`) için atanır; ardından ikisi de invalidate edilir. Kaynak seçimi tarayıcıda koşullu renklendirme ile taklit edilmez: önizleme de gerçek değiştirilmiş MIPS kodunun ürettiği image ID'lerini çizer.

Seçilen kaynak ID'leri, son tüketimi `0x00fb81f4` öncesinde tamamlanan yerel geometri alanları `fp+0x40/0x44` içinde tutulur; callback'ler arasında caller-saved register değeri taşınmaz. Her çağrıdan sonra GP geri yüklenir. Var olan `0x00fb8b0c` epiloguna dönülür. Bağımsız inceleme branch/delay slot'ları, dış giriş bulunmamasını, stack alanı ömrünü ve exception cleanup aralıklarının korunmasını kontrol etti.

MUF `MImg::Set(unsigned short)` (`0x2e231944`) yeni ID'yi kaydeder ve dahili string durumunu sıfırlar. `FindCachedSurface` (`0x2e23c358`) bu ID'yi okuyup `RcGetImage` üzerinden kaynak bulur; filename/length karşılaştırmaları `0x2e23c2d0..0x2e23c2fc` içinde bulunur. Statik incelemede eski görüntüde kalmaya yol açacak bir bağ bulunmadı; fiziksel renderer/cache testi yapılmadı.

## Kaynaklar ve korunan yerleşim

Yeni panel `/rc/ARimages/Grundig/modern/volume_muted_bg.png`, RGBA68×450, yarıçap34'tür. Mevcut Image kayıtlarının gövdeleri aynı kalır; yalnız sona ID2180 eklenir. Image680'in mevcut yolu RGBA44×44 sessiz ikonuyla yenilenir. Menü/sayı/font/Num tabloları V7.1 ile aynıdır. Panel ekran konumu `[80,306,68,450]` korunur.

V7.1'e göre yalnız ELF, Image tablosu, mute PNG'si ve yeni muted panel PNG'si farklıdır. Overlay13 dosyadır; orijinal firmware'e göre11 mevcut dosya değişir ve2 özel PNG eklenir. V7.1 ve daha önce kullanıcı tarafından cihazda denenmiş V7 ayrı tutulur.

Kod/kanıt: [yerel yama](../scripts/native_ui_v72_mute.py), [86 sözcüğün assembly dökümü](../analiz/native-ui-v72/mute-block-disassembly.txt), [220 vakanın kaydı](../analiz/native-ui-v72/mute-native-evidence.json), [compositor ve manifest üreticisi](../scripts/build_native_ui_v72_tv.py), [sabit dosya kimlikleri](../scripts/native_ui_v72_tv_pins.py), [manifest](../analiz/native-ui-candidate/v7.2-tv/manifest.json).

## Doğrulama

- Native seçim testleri3/3 geçti: ses0–100 ve mute kombinasyonları ile tekrarlı geçiş girdileri208 kayıt; ARC modları1/2/3 için12 kayıt önceki durumla eşleşti. Toplam220 sınırlı MIPS vaka kaydedildi. Her vaka sentetik frame ile başlar; gerçek cihazda ardışık tuş basma testi değildir.
- Bağımsız incelemede5 ek ABI testi geçti: callback'ler caller-saved register'ları, GP'yi ve stack argüman alanını bozduğunda8 görüntü ataması ve2 invalidate doğru kaldı.
- Kapsam/paket pin testleri4/4 geçti; seçilen blok dışındaki bütün ELF baytları V7.1 ile eşit. Önceki2180 Image kaydı gövdesi korunur.
- APP yardımcı testleri8/8, bağımsız metaveri politikası6/6 geçti.
- V7.2/V7.1 odaklı çizim testleri11/11 geçti. Normal35 ve numara ekranı V7.1 ile piksel eşit; sessiz panel rengi ve alfa sınırları kontrol edildi. [Önizleme raporu](../analiz/native-frame-rehost/v72/verification.json).
- Yerel HTTP'de0→100→mute35→normal35→mute→normal geçişleri doğru kaynak ve PNG hash'lerini döndürdü. [Test yüzeyi](http://127.0.0.1:4174/) V7.2 varsayılanını kullanır.

Bu tur gerçek Chrome tuş testi tamamlanmadı: Chrome DevTools profil kilidi bildirdi; Computer Use, Windows'ta mevcut URL'yi politika uygulamak için yeterli güvenle belirleyemediğinden `cua.getApp({windowId:2491964})` işlemini durdurdu. Daha sonra bilgisayar UI işlemi denenmedi. Önceki V7.1 tarayıcı sonuçları bu revizyon için geçmiş sayılmaz.

[Normal35](../analiz/native-frame-rehost/v72/normal35.png), [mute35](../analiz/native-frame-rehost/v72/mute35.png), [ses0](../analiz/native-frame-rehost/v72/zero0.png). Görseller gerçek sınırlı MUF çizim talimatları ve host Pillow yüzeyiyle oluşturuldu; fiziksel TV veya tam SoC emülasyonu değildir. Ana ajan da mute/zero görsellerini gözle inceledi.

## Son paket

[V7.2 ara BIN](../analiz/native-ui-candidate/v7.2-tv/package/GM_SWImage_UI_v7.2-tv_OFFLINE_UNVERIFIED.bin) yalnız tarihsel kayıt olarak tutulur; `NOT_FOR_TV.txt` ile işaretlendi. Kullanıcı düzeltmesi üzerine bu aşamanın RAR'ı ve son sürüm onayı hazırlanmadı. [V7.3](UI_NATIVE_V73_GRI_SESSIZ.md) kullanılır.

Tamamlanan ara raporlar: [APP](../analiz/native-ui-candidate/v7.2-tv/package/app-build-validation.json), [storage](../analiz/native-ui-candidate/v7.2-tv/package/storage-validation.json), [container](../analiz/native-ui-candidate/v7.2-tv/package/container-validation.json). Son revizyonun bağımsız geri okuma ve RAR raporları V7.3 altında tutulur.

V7.2 fiziksel TV'de denenmedi. Yeni panel alfa/cache davranışı, gerçek kumanda geçişleri ve ARC üzerinde cihaz kontrolü bekler. Orijinal arşiv/BIN değiştirilmedi; USB veya TV'ye yazılmadı; gömülü update/boot programları yürütülmedi. `flash_ready=false` ve `television_tested=false` korunur. Kullanılan beceri `reverse-engineer-anything`; doğrudan Ghidra çıktıları REA Evidence olarak sunulmaz.
