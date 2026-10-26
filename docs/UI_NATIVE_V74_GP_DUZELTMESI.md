# V7.4 — V7.1 tabanlı GP düzeltmesi ve görünüm adayı

26 Ekim 2026. Kullanıcı V7.3'te ses panelinin görünmediğini ve TV'nin donduğunu, V7.1'in sorunsuz çalıştığını bildirdi. **V7.2/V7.3 dağıtım için reddedildi. Cihazda çalışan temel V7.1'dir.** Yeni V7.4, doğrudan V7.1'in sabitlenmiş12 dosyalı overlay'inden üretilir; V7.3 ELF'ini girdi olarak kullanmaz. V7.4 henüz cihazda denenmedi.

## Hata ve testte yeniden üretim

V7.1'de `RefreshVolumeUI` içindeki sanal konumlandırma çağrısı `0xfb81f4` adresindedir. PIC çağrısı GP kaydını değiştirebilir. Derlenmiş mevcut kod, `0xfb8204` dalının delay slot'unda `0xfb8208: lw gp,0x18(fp)` ile çağıranın GP'sini geri yüklüyordu.

V7.2/V7.3 seçici yeniden düzenlenirken bu yükleme kaldırılıp yerine `nop` konmuştu. Sonraki `lw t9,-0x910(gp)` yanlış GP üzerinden fonksiyon adresi okuyabilir. Önceki host callback'i `VirtualMoveRect` çağrısında GP'yi değiştirmediğinden yüzlerce durum testi bu ABI kusurunu gizledi. Sonradan yalnız yeni blok içindeki çağrılara uygulanan stres testi de bloktan önceki sanal çağrıyı kapsamıyordu.

Yeni test, sanal callback'in GP'yi değiştirmesine izin verir:

| Kod | Sonuç |
|---|---|
| V7.1 | Normal döner |
| V7.3 | `Invalid memory read (UC_ERR_READ_UNMAPPED)` |
| V7.4 | Normal döner |

V7.4, **`0xfb8200: 0x8fdc0018` (`lw gp,0x18(fp)`)** ile bloğun başında GP'yi geri yükler; bütün GOT okumaları bundan sonradır. Aynı86 sözcüklük alan85 talimat ve1 padding sözcüğüyle kullanılır. Yeni code cave, segment veya import eklenmez. Bu, gerçek bir kod kusurunun kontrollü yeniden üretimidir; cihaz crash dump'ı olmadığından TV'deki tek neden olduğu kanıtlanmış değildir.

Kanıt: [regresyon testi](../scripts/test_native_ui_v74_safe.py), [6 testin son sonucu ve202 durum](../analiz/native-ui-v74/safe-gp-regression.json), [V7.1 tabanlı üretici](../scripts/build_native_ui_v74_tv.py), [sınırlandırılmış düzeltme](../scripts/native_ui_v74_safe.py), [manifest](../analiz/native-ui-candidate/v7.4-tv/manifest.json).

## Gri bar ve sağ üst beyaz rozet

Mute veya ses0 durumunda ProgressBar'ın dört dolgu rengi `0xff898989`; normal durumda özgün Color25 `0xff0082d4` olur. Yalnız önizlemede CSS rengi değiştirilmez: gerçek Refresh kodu `ProgressBar+0x2a4/+0x2a8/+0x2ac/+0x2b0` alanlarını yazar ve progress widget'ını invalidate eder. Bu alanlar `SetBarColor` (`libmuf 0x2e26ff00`) ile doğrulandı. Önizleme dönen native bellek değerini çizer.

Kalıcı rozet, önceki ModGrundig `ui-preview/styles.css #mute-badge` tasarımından alınır:52×52 beyaz yüzey,16px köşe,26×26 hoparlör+X, ikon rengi `#527185`. Yeni özel Image2181 `/rc/ARimages/Grundig/modern/mute_badge.png` kaynağına bağlanır. Panelin gri Image680 kaynağı ayrı kalır.

`MuteControlFrame::OnCreate` (`0xdf8630`) içindeki dört ikon ataması (`0xdf9324/9348/936c/9390`)2181'e döner. Beş eski gölge widget'ının20 ataması, aynı OnCreate'ın zaten kullandığı null Image1485'e çekilir. Sıfır boyutlu widget oluşturulmaz. [Kaynak/patch tablosu](../scripts/native_ui_v74_badge.py).

| Alan | Mantıksal1920×1080 sınırı |
|---|---|
| Dış pencere | `[1728,19,160,230]`; sağ1888, alt249 |
| Normal kök | `[0,0,160,230]` |
| Alt panel | `[0,25,158,165]` |
| İkon (alt panelde) | `[56,30,52,52]`; sağ108≤158 |
| Ekrandaki rozet | `[1784,74,52,52]`; sağ boşluk84, üst74 |

Normal kökün önceki165 genişliği160'a indirilir; böylece kök de dış pencere içinde kalır. ARC158×90 ağacı pencereye sığar; ortak dış pencere taşındığı için ARC göstergesinin konumu da taşınır. Ses yönlendirme kodu değişmez. Fiziksel ölçekleme/overscan gözlenmedi. Eski CSS'nin numara kartı açıkken rozeti aşağı taşıma kuralı firmware'e henüz kurulmadı; eşzamanlı popup çakışması cihaz kontrolü gerektirir.

Mevcut timer/lifecycle korunur: ayrı rozet yalnız gerçek `IsMuted` açıkken panel kapanışından sonra gösterilir; ses0 tek başına bu uygulamayı açmaz. Önizlemedeki ayrı sahne statik kaynak/parent çizimidir, gerçek timer yürütmesi değildir.

## Son doğrulama

- Altı regresyon testi geçti: V7.3 kusurunu tekrar üretme;202 ses/mute kombinasyonu;10 bütün callback'leri bozan ABI senaryosu;12 ARC karşılaştırması; parent/screen sınırları; manifest/pin eşliği.
- Sanal callback, ortak harness'te artık varsayılan olarak GP'yi bozar. Böylece eski V7.3'ün sahte başarılı önizlemesi sürmez. V7.2/V7.3 viewer seçeneklerinden ve API'den çıkarıldı.
- Dört native renk/piksel durumu, rozetin iki yatay sınırı ve altı HTTP rotası geçti. [Önizleme raporu](../analiz/native-frame-rehost/v74/preview-checks.json). Bu tur GUI/Chrome klavye testi yapılmadı.
- APP2.374 dosya /2.777 metaveriyle geri çıkarıldı;2.360 özgün dosya aynı. Container14 payload açıldı, diğer13 aynı;19.067 committed UBIFS node CRC doğrulandı.
- RAR4,17 dosya /11 dizinle geri açılıp 7-Zip ve WinRAR'dan geçti; yalnız SWImage farklıdır. Bölüm offsetleri ve BIN boyutu korunur.

[Mute35 — gri dolgu](../analiz/native-frame-rehost/v74/mute35.png), [beyaz sağ üst rozet](../analiz/native-frame-rehost/v74/badge.png), [normal35](../analiz/native-frame-rehost/v74/normal35.png), [ses0](../analiz/native-frame-rehost/v74/zero0.png). Sınırlı MUF + Pillow kareleridir; gerçek TV görüntüsü değildir. Ana ajan son mute ve rozet karelerini gözle inceledi.

## Paket ve durum

[V7.4 inceleme/test RAR'ı](../analiz/native-ui-candidate/v7.4-tv/package/GMGRMR.-.-.-.-.V03.017.04_V7.4_TEST.rar), [BIN](../analiz/native-ui-candidate/v7.4-tv/package/GM_SWImage_UI_v7.4-tv_OFFLINE_UNVERIFIED.bin). Normal kullanım için cihazda doğrulanmış temel V7.1 kalır; V7.4'e sorunsuz cihaz sürümü denmez. Bu aşamada USB/TV'ye yazılmadı.

Raporlar: [APP](../analiz/native-ui-candidate/v7.4-tv/package/app-build-validation.json), [storage](../analiz/native-ui-candidate/v7.4-tv/package/storage-validation.json), [container](../analiz/native-ui-candidate/v7.4-tv/package/container-validation.json), [bağımsız geri okuma](../analiz/native-ui-candidate/v7.4-tv/package/independent-readback.json), [RAR](../analiz/native-ui-candidate/v7.4-tv/package/vendor-rar-validation.json), [aşama ve kimlikler](../analiz/native-ui-candidate/v7.4-tv/phase-results.json).

İlk alt ajanlar günlük limite ulaştı; son GP teşhisi, V7.1 üzerinden entegrasyon, regresyonlar ve paketleme ana ajan tarafından tamamlandı. Kullanılan beceri `reverse-engineer-anything`; orijinaller ve çalışan V7.1 korundu.

## Yeni kanal adı isteği

Kullanıcı `01` girildiğinde numaranın altında gerçek kanal adı istiyor. Önceki web örneğinde adlar `channels.json` demonstrasyon verisiydi; native pakette isim widget'ı/DB köprüsü yoktu. [Adresli çağrı yolu](bilgi-tabani/NUMERIC_KANAL_ADI.md) hazırdır: typedU16 → `GetProgramSelInfo` → eşleşen DBnum/service/route → `GetProgramName`.

V7.4 numara event'lerini bu yeni özellik için değiştirmez. Hedef kanal yerine o anda izlenen kanalın adı veya sabit örnek isim gösterilmez. Farklı fontlu ikinci widget'ın kaydı/ömrü, string ABI'si, doğru route ve yeni event helper yerleşimi birlikte doğrulanmadan kurulmuş sayılmaz. Bu iş devam konusudur; mevcut pakette tamamlandığı iddia edilmez.
