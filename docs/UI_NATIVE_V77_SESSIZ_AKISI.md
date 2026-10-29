# V7.7 — ses panelinden sessiz durumuna geçiş

27 Ekim 2026. Bu düzeltme gerçek native olay yolunu değiştirir. Özgün firmware ve önceki paketler korunur; fiziksel TV testi yapılmadı.

## Eski sol simgenin nedeni

`VolumeControlFrame::OnKey` (`0xfb8c7c`) yerel mute tuşu `0xf04e` için `0xfb93d4` adresinde mode1 yükleyip `0xfb93d8` adresinde `frame+0x214` alanına yazıyordu. Sonra özgün ses yöneticisinin `IsMuted` / `SetMute` çağrılarıyla sesi değiştirip `RefreshVolumeUI` çağırıyordu. Refresh'in mode1 dalı eski bağımsız sol mute kökünü seçiyordu. Yalnız PNG değiştirmek bu seçim yolunu değiştirmiyordu.

Yeni tek sözcük değişikliği `0xfb93d4: 0x24020001 → 0x24020000` yerel mute olayını normal dikey panelin mode0 yoluna yönlendirir. Gerçek `SetMute` çağrısı ve sonrasındaki Refresh korunur. Panel açık kalır; alt ikon Image680 ve dolgu gri olur. Tekrar mute tuşunda gerçek sessiz durumu kapanır ve mavi dolgu geri gelir. ARC/CEC'nin işlediği mute olayındaki mode3 ataması `0xfb93a4` değişmez; o yolda yerel ses yöneticisine ek mute komutu gönderilmez.

Bağımsız ses servisi incelemesi, `SetMute(0x4c8208) → SetMuteStatus(0x2d9aa7c8) → müşteri vtable+0x2c` yolunun geri dönmeden önce sessiz cache byte'ını yazdığını doğruladı. Setter `0x2ea9a5a4`, getter `0x2ea9a59c` aynı `this+0x11c` byte'ını kullanır. Dört özgün iki talimatlık leaf testi geçti. Bu yüzden olay testindeki eşzamanlı bool güncellemesi yalnız bir zamanlama varsayımına dayanmıyor. Kanıt `analiz/native-ui-v77/mute-review/synchronous-cache.json`; fiziksel ses çıkışı bu incelemenin kapsamında değildir.

## Panel kapandıktan sonraki sağ üst gösterge

Özgün `TimerEventHandler` (`0xfb7aec`) panel uygulamasını kapatıp yalnız `IsMuted` doğruysa mevcut MuteControlApp'i açıyordu. Yeni224 baytlık yardımcı `0x1161000` şu görsel koşulu döndürür:

```text
IsMuted || (panel kapanmadan önceki mode == 0 && GetMainVolume == 0)
```

Gerçek `IsMuted` davranışı bütün modlarda korunur. Yerel ses seviyesinin sıfır olması yalnız mode0 için ek gösterge açar; harici ARC cihazı kullanılırken TV'nin yerel ses değerinin sıfır olması bu cihazın sessiz olduğu şeklinde gösterilmez. Bu görsel kural sıfır seste ses yöneticisine `SetMute` göndermez.

Mode değeri panel uygulaması kapatılmadan önce yakalanır. `0xfb7b38` özgün frame'i a0'a, `0xfb7b3c` mode değerini v0'a yükler. `0xfb7b4c` KillTimer çağrısının delay slotunda değeri `FP+0x1c` alanına kaydeder. Bu alanın eski dispatch kimliği son kez `0xfb7b2c` adresinde okunur ve `0xfb7b30` adresinde dallanır; kalan özgün timer talimatlarında bu alana erişim olmadığı üretici tarafından doğrulanır. KillTimer'ın özgün `a0=frame`, `a1=0` argümanları korunur. `0xfb7b98` yeni JAL'ın delay slotunda bu kaydedilmiş tamsayıyı a1'e verir. Böylece `MApplet::Kill` sonrasında eski frame'in mode alanını okumaya gerek kalmaz.

`0xfb7b94/0xfb7b98` yalnız IsMuted çağrısının yerini alır. Özgün panel kapatma, MuteControlApp oluşturma/Run (`0xfb7ca4`) ve mevcut uygulamayı Show (`0xfb7ce8`) yolları korunur. Yardımcı GP ve callee-saved register'ları korur; özgün `0xfb7ba0` GP yüklemesi de kalır. Üçüncü helper için FDE eklenir; orijinal ses panelindeki `0xfb8200` GP düzeltmesine dokunulmaz.

MuteControlFrame'in küçük olay gövdesi `0xdf8330` doğrudan1 döner; sessiz durumunu yeniden sorgulayıp sıfır ses göstergesini hemen kapatmaz. Ses paneli tekrar açıldığında `RefreshVolumeUI` başlangıcı mevcut MuteControlFrame'in parent uygulamasını kapatır ve ardından normal paneli gösterir. Bu işlem iki göstergeyi üst üste bırakmaz.

## Görsel sınırlar ve doğrulama

V7.6'nın64×64 modern beyaz rozeti korunur: `[1772,74,64,64]`, sağ boşluk84 ve üst boşluk74 mantıksal piksel. Image2181'in dört durumu ve legacy401 alternatifi modern tasarımı taşır. Bu değişiklik varlıklara veya menülere yeniden dokunmaz.

`python scripts/test_native_ui_v77_mute.py`: **8/8 geçti.** Testler pakete yerleştirilmiş gerçek `OnKey → Refresh` talimatlarını aynı Unicorn örneğinde yürütür. Gerçek timeout gövdesi ve yeni yardımcı da yürütülür. Ses servisi, uygulama yöneticisi ve çizim yüzeyi açıkça modellenmiş dış bağımlılıklardır; tam uygulama veya olay dağıtıcısı çalıştırılmaz.

- Mute → gri panel/alt ikon → tekrar mute ile mavi panel.
- Mute rozeti açıkken tuşa basılması ve gösterge temizliği.
- Ses0 ve gerçek mute için panel kapanınca rozet; pozitif normal seste rozet yok.
- Mode0/1/2/3 × ses0/35 × mute kapalı/açık matrisi; gerçek mute bütün modlarda korunur.
- Parent Kill sonrasında frame mode alanını bozarak, sıfır kuralının yalnız önceden yakalanmış değeri kullandığının doğrulanması.
- Özgün KillTimer argümanları, ARC mode3 yolu, callee-saved register'lar ve çağrılar arasında GP/caller-saved register bozulması.
- Sağ üst rozetin ekran ve ebeveyn sınırları.

Kanıt: `analiz/native-ui-v77/mute/native-transitions.json`. Üretici: `scripts/native_ui_v77_mute.py`; bounded yürütücü/test: `scripts/test_native_ui_v77_mute.py`. Yardımcı SHA256: `8ee4cf80c5054d9f1c652e8c7f78cd2484be2f542bcfd79d8ef9a28aba33c1cd`.

Bağımsız inceleme aynı8 testi tekrar çalıştırdı;224 baytlık yardımcı, altı hook, ölü stack alanının yeniden kullanımı ve FDE için yeni uygulanabilir kusur bulmadı. İnceleme kaydı `analiz/native-ui-v77/mute-review/final-review.json`.

Gerçek cihazın grafik sürücüsü, kumanda dağıtıcısı, harici ARC cihazı ve heap davranışı bu testlerle doğrulanmaz. Güncelleme komutları veya TV'ye yazma işlemleri yürütülmedi.
