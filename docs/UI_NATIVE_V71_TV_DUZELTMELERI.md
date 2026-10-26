# V7.1 — fiziksel TV gözlemlerinden ses ve numara düzeltmeleri

25 Ekim 2026. Kullanıcı V7'yi USB üzerinden yüklediğini, TV'nin açıldığını ve yayın/ses panelinin çalıştığını bildirdi. İki fotoğraf, ses panelinin düz köşeli ve kenara yakın olduğunu; kanal numarasının ise yalnız ince beyaz şerit olarak göründüğünü gösterdi. Bu, V7'nin tüm işlevlerinin hatasız olduğunu kanıtlamaz. **Aşağıdaki V7.1 revizyonu henüz fiziksel TV'de denenmedi.**

## Son dosyalar

- [V7.1 RAR test paketi](../analiz/native-ui-candidate/v7.1-tv/package/GMGRMR.-.-.-.-.V03.017.04_V7.1_TEST.rar): 43.141.176 bayt; SHA256 `859147abccd343f2be336145e751a360b9f522aa0c7d473dad940ac0efb80166`.
- [V7.1 BIN](../analiz/native-ui-candidate/v7.1-tv/package/GM_SWImage_UI_v7.1-tv_OFFLINE_UNVERIFIED.bin): 42.483.736 bayt; SHA256 `32b3d7fd706c3d5b24795e664a2a6a4538f98cd7a27b7ad9487a9573ad0ec647`.
- [Arşivden geri çıkarılmış Target_GM](../analiz/native-ui-candidate/v7.1-tv/vendor-rar-readback/Target_GM): üreticinin 17 dosya / 11 dizin düzeni korunur. Yazılımın aradığı yol USB kökündeki `Target_GM/image/GM_SWImage.bin` yoludur; RAR dosyasını doğrudan okuduğu gösterilmedi.

Yalnız SWImage arşiv üyesi değiştirildi; diğer 16 dosya ve sıkıştırılmış arşiv blokları aynıdır. Sürüm etiketi `V03.017.04` korunur; 05 yapılmadı. Önceki “daha yeni sürüm yok” mesajının dosya bulma yoluyla ilişkisi [ayrı belgede](USB_GUNCELLEME_DOSYA_BULMA.md) kanıtlanmıştır. Bu çalışmada USB'ye veya TV'ye yazılmadı.

## Ses panelinin nedeni ve düzeltmesi

`VolumeControlFrame::OnCreate` (`0x00fb9780`) panelin Image ID674 kaynağını ayarlıyor, ancak panel nesnesinin `+0x3a` görüntü bayrağını açmıyordu. `MWidget::DrawBackground` (`0x2e251be4`) bu bayrak kapalıyken düz renk doldurma yoluna giriyor. Eski host önizlemesi bayrağı kaynak kodundan çıkarmadan doğrudan PNG çiziyordu; böylece TV'deki köşe sorunu önizlemede gizlenmişti.

V7.1'de iki yerel MIPS sözcüğü değiştirilir:

| Adres | Önce → sonra | Etki |
|---|---|---|
| `0x00fbb550` | `0x2404005e` → `0x24040001` | Yerel argümanı 1 yapar |
| `0x00fbb55c` | `0x00000000` → `0xa204003a` | `RcGetColor` çağrısının delay slot'unda panel `+0x3a` bayrağını açar |

Renk callback'i, GP geri yüklemesi ve renk yazımı korunur. Normal durum rengi94 yerine1 olur; açık görüntü modunda kullanılmaz. Sınırlı instruction testinde callback `a0` kaydını bozsa bile bayrağın çağrıdan önce yazıldığı doğrulandı. Gerçek MUF çizim fonksiyonunda önce `FillRectangle`, sonra `StretchBlit` yolu gözlendi. Bu, tüm OnCreate veya gerçek DirectFB sürücüsünün çalıştırılması değildir.

Mevcut Image ID674 yolu korunarak `bg.png`, açık RGBA alfa kanallı **68×450, yarıçap34** kapsülle değiştirilir. Yazı fontu, ikon boyutu44×44 ve iç yerleşim V7 ile aynıdır. Kullanıcının son isteğiyle panel ayrıca **24 mantıksal piksel yukarı** alınır.

| Geometri (1920×1080 mantıksal koordinat) | Son değer |
|---|---|
| Dış pencere | `[0,160,160,725]` |
| Client içindeki kök | `[80,126,68,490]` |
| Client içindeki panel | `[80,146,68,450]` |
| Ekrandaki panel | `[80,306,68,450]` |
| Num ID değişikliği | `0x5a41: 0→80`, `0x5a42: 150→126` |

Kökün sağ sınırı148, dış pencere genişliği160 içinde kalır. İlk x96 denemesinde sağ sınır164 olacağından bu taslak TV'ye sunulmadan reddedildi; `v7.1-tv-rejected-margin96` yalnız tarihsel kayıttır. Gerçek cihazın ölçekleme/overscan oranı ölçülmedi.

Kanıt: [final manifest](../analiz/native-ui-candidate/v7.1-tv/manifest.json), [yerel yama](../scripts/native_ui_v71_volume.py), [dış pencere assembly kanıtı](../analiz/native-ui-v71/volume/outer-frame-base-window-disassembly.txt), [regresyon testleri](../scripts/test_native_ui_v71_volume.py). Factory `0x00fb601c` → MMainFrame constructor → `MWnd::SetRect` (`0x2e261b74`) dış koordinatları saklar, client XY sıfırlanır; `CreateDFBWindow` içindeki `0x2e2335e8` çağrısı saklanan dış sınırları tüketir. Önceki volume-proof/görsellerindeki y150 değerleri son yukarı taşıma öncesine aittir; final geometri manifestteki y126'dır.

## Numara ekranının nedeni ve düzeltmesi

`ChannelControlApp::CreateMainFrame` (`0x00895108`) dış pencerenin yüksekliğini global Num ID`0x50` üzerinden80 alıyordu. V7'de içerideki kök312 yüksekliğe büyütülmüş, dış pencere80'de kalmıştı. Kart y64'te başladığından yalnız16 pikseli görünür; y118'deki rakamlar tamamen dışarıda kalır. Bu sınırlar fotoğraftaki beyaz şeritle örtüşür.

Tek sözcük değişir: **`0x0089518c: 0x24040050 → 0x2404098f`**. Dış pencere mevcut yerel Num ID`0x98f` değerini, yani312'yi kullanır. Global Num80 değiştirilmez. Son dış pencere `[0,0,1920,312]`, kart `[1538,64,310,224]`, rakam alanı `[1566,118,254,78]` olur; ikisi de bütün üst sınırların içinde kalır.

Kart PNG'si, Image ID2179, DejaVu Sans58, dört metin durumu, rakam/timeout/kanal seçimi handler'ları korunur. Yeni kanal adı widget'ı eklenmedi; eski tarayıcı örneklerindeki sahte kanal adı bu firmware'in özelliği değildir.

Kanıt: [fonksiyonun doğrudan Ghidra çıktısı](../analiz/native/ui-targeted/v71-numeric-frame/00895108.c), [numeric proof](../analiz/native-ui-v71/numeric/proof.json), [numeric yama](../scripts/native_ui_v71_numeric.py), [12 testin kaydı](../analiz/native-ui-v71/numeric/tests.json).

## Değişiklik kapsamı ve doğrulama

V7'ye göre yalnız üç dosya değişir: `/bin/dvbt_board`, `/rc/rc/bin/Num_res.bin`, ses `bg.png`. ELF'te üç sözcük, Num tablosunda iki pozisyon kaydı farkı vardır. Özgün firmware'e göre V7'den taşınan değişikliklerle toplam12 overlay dosyası (11 değişiklik, 1 yeni PNG) bulunur. Ana menü, ayarlar, menü ikonları, kanal listesi ve bilgi bandı orijinaldir. ARC yönlendirmesi, güncelleme işleyicileri ve boot bölümleri değiştirilmedi.

| Kontrol | Sonuç |
|---|---|
| Numeric / volume / bütünleşme testleri | 12 + 8 + 4 = 24 geçti |
| Bağımsız alt ajan incelemesi | Final geometri, üç instruction, 12 pin ve paket/hash bağlantısında actionable kusur bulunmadı |
| APP yeniden çıkarma | 2.372 dosya, 2.775 metaveri; 2.360 özgün dosya aynı |
| Bağımsız metaveri okuması | 2.773 özgün kayıt + 1 yeni dosya + 1 yeni dizin kontrol edildi |
| Container | 14/14 payload açıldı; diğer13 bayt/hash eşit, tüm CRC'ler geçti |
| UBIFS | Format4, min_io2048, LEB126976, 308/321 LEB; 19.060 committed node CRC geçti |
| Sıkıştırma | Yalnız özgünde de kullanılan codec0/1; ELF'in 3.307 DATA node'u raw |
| RAR4 | 7-Zip ve WinRAR doğrulaması geçti; 17 dosya / 11 dizin geri okundu |

APP SHA256 `6353008a5cdb9669bdabe33fc0dbe2ab8ba27c4e31d721bd20813ac642d0a756`. APP39.108.608 bayt; dış sıkıştırılmış boyut16.755.823 bayt, özgün slotta676.753 bayt boşluk. Bölüm offsetleri ve BIN boyutu korunur.

Raporlar: [APP](../analiz/native-ui-candidate/v7.1-tv/package/app-build-validation.json), [storage](../analiz/native-ui-candidate/v7.1-tv/package/storage-validation.json), [container](../analiz/native-ui-candidate/v7.1-tv/package/container-validation.json), [bağımsız diskten okuma](../analiz/native-ui-candidate/v7.1-tv/package/independent-readback.json), [RAR](../analiz/native-ui-candidate/v7.1-tv/package/vendor-rar-validation.json).

## Son önizleme kontrolü

Kullanıcının model tercihi üzerine kalan önizleme işi açıkça GPT-6.1-Sol alt ajanıyla tamamlandı. [Yerel test ekranı](http://127.0.0.1:4174/) V7.1'i varsayılan kullanır. V7/V7.1 karşılaştırması gerçek dış pencere yüksekliğini, ekran Y ofsetini ve panel görüntü bayrağını uygular; eski önizlemenin görünmez kök gölgesi kaldırılmıştır. Rakam girişi örnek girdidir; tam TV/kanal değiştirme emülatörü değildir.

- V7.1 odaklı önizleme: **6/6** geçti.
- Ortak çizim kodu değiştiğinden volume regresyonu tekrar çalıştırıldı: **8/8** geçti; yukarıdaki24 testin içindeki aynı8 testtir, ayrıca eklenmez.
- Genel native frame: **16 geçti, iptal edilmiş V8 menü testi1 atlandı**; atlanan geçmiş sayılmaz.
- Viewer API: **6/6** geçti.
- Sınırlı native ses durumu: **8/8** geçti. Önizleme turunda toplam44 test geçti,1 tarihsel test atlandı. [Tam komut ve yöntem kaydı](../analiz/native-frame-rehost/v71/README.md).
- Chrome: ses0/100, mute, hızlı tekrar, numara12 ve geri dönüş akışları geçti; konsol/HTTP hatası gözlenmedi. [Tarayıcı raporu](../analiz/native-frame-rehost/v71/native-browser-tests.json).

[V7.1 ses27](../analiz/native-frame-rehost/v71/v7.1-tv-volume-27.png), [V7.1 numara12](../analiz/native-frame-rehost/v71/v7.1-tv-numeric-12.png), [V7 kırpılmış numara karşılığı](../analiz/native-frame-rehost/v71/v7-tv-numeric-12.png). Bunlar sınırlı gerçek MUF talimatları + host Pillow yüzeyiyle üretilir; TV fotoğrafı veya fiziksel alfa/overscan kanıtı değildir. Son görseller ana ajan tarafından da gözle incelendi.

Orijinal kaynaklar, kullanıcının değiştirdiği çalışma RAR'ı ve çalışan V7 korunur. Gerçek firmware/boot/update programı yürütülmedi. Testlerde yalnız sınırlandırılmış MUF/yerel MIPS talimatları host callback'leriyle kullanıldı; fiziksel görüntü, ses donanımı ve SoC doğrulanmış sayılmaz. Kullanılan beceri `reverse-engineer-anything`; tutulan Ghidra çıktıları REA Evidence olarak adlandırılmaz.

## Kalan cihaz kontrolü

V7.1 için yuvarlak köşelerin video üstünde doğru alfa göstermesi, kenar/yükseklik konumu, 1–4 rakam görünürlüğü ve gerçek kanala geçiş, 0/100 ses sınırları, mute, ARC, hızlı tuş basma ve otomatik kapanma henüz cihaz üzerinde gözlenmedi. Bunlar çevrimdışı testlerin yerine geçtiği iddia edilmeyen takip maddeleridir. `flash_ready=false` ve `television_tested=false` bu sınırı korur; sıfır hata garantisi verilmez.
