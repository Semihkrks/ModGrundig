# V7.6 — sessiz rozeti

26 Ekim 2026. Kullanıcı önceki sessiz simgesinin hâlâ göründüğünü bildirdi. Hangi imajın cihazda kurulu olduğuna veya gerçek çalışma izine sahip olmadığımız için bu bildirimin kök nedeni doğrulanmış değildir. V7.5'in dört normal standalone görsel ataması zaten Image2181 kullanır (`0xdf9324/9348/936c/9390`); bunlar tekrar doğrulandı. HDMI ARC kökü seçimini yapan `SetMuteInDeviceMode` (`0xdf8454`) ve ses/panel zamanlayıcısı değiştirilmedi.

Yeni dönüşüm `scripts/native_ui_v76_mute.py` içinde `apply(payloads)` ile uygulanır. Beyaz rozet52×52'den64×64'e, çizgi ikon26×26'dan32×32'ye çıkar. `Num_res.bin` içindeki `0x4219` x56→44, `0x4218/0x4217` genişlik/yükseklik52→64 olur. Ekran alanı `[1772,74,64,64]`, sağ boşluk84 ve üst boşluk74 mantıksal pikseldir. Dış pencere `[1728,19,160,230]`, panel ve kök sınırları içinde kalır.

Orijinal Image401 yolunun `../rc/ARimages/Grundig/volume/mute_button_grundig.png` olduğu resource tablosunun401. kaydı parse edilerek doğrulandı. Eski dosyanın85×95 boyutu korunur; eski görsel yerine aynı modern64×64 beyaz rozet ortalanır. Bu, legacy401 yolunun kullanılması hâlinde eski simgeye dönüşü önler; cihazın gerçekten bu yolu seçtiği iddia edilmez. Yeni2181 dosyası `/rc/ARimages/Grundig/modern/mute_badge.png` olarak kalır. Panelle ortak Image680 kaynağı değiştirilmez.

Orijinal401 SHA256: `9facafe621ba0052c30c67650320d634dc3686ea921f1114a4a9b4055c607bb7`. Dönüşüm ELF veya Image tablosuna dokunmaz; tüm2181 durumlarını,20 null gölge atamasını ve `0xfb8200` adresindeki `lw gp,0x18(fp)` düzeltmesini zorunlu tutar. Yalnız üç geometri kaydı ve iki PNG değişir. Orijinaller ve V7.5 korunur.

`python scripts/test_native_ui_v76_mute.py`: **6/6 geçti**. Dosya kapsamı, şeffaf köşeler, yeni/legacy PNG boyutları, ebeveyn sınırları, dört eski simge durumunun reddi, eksik GP düzeltmesinin reddi ve mute alanı dışındaki yeni numeric verilerin korunması sınandı. Kanıt `analiz/native-ui-v76/mute/bounded-tests.json`; örnek varlıklar aynı klasördedir. Bu kontroller fiziksel TV çizimini, geçerli sürümün cihazda kurulu olduğunu veya tam runtime yaşam döngüsünü doğrulamaz.
