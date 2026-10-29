# Menüde SEMIH marka yazısı — 29 Ekim 2026

Gerçek menüdeki marka, font ve string kaynağı kullanan bir `TextBox` değildir. `MenuBackgroundFrame` içindeki `Image` widget'ı, kaynak 915 olan `Grundig/icons/brandLogo/logo_400_120.png` dosyasını gösterir. Bağımsız SVG harflerle beyaz, kalın geometrik **SEMIH** yazısı üretildi. Bu, özgün bitmap yazı stiline yaklaştırılmış yeni çizimdir; birebir özgün fontun bulunduğu veya kurtarıldığı iddia edilmez.

[Beyaz/lacivert karşılaştırma](../analiz/native-features/semih-brand/proposal.html) ve [önizleme PNG'si](../analiz/native-features/semih-brand/proposal.png) özgün kaynakla yeni çizimi hem 400×120 kaynak boyutunda hem 260×78 native widget boyutunda gösterir. Bunlar TV ekran görüntüsü değildir.

## Native bağlantı ve kapsam

Doğrudan Ghidra statik sorgusu, özgün APP SHA-256 `51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916` üzerindedir. `-process -noanalysis -readOnly` kullanıldı. Kaynak kod çıktısı REA Evidence diye sunulmaz; eski MIPS ABI için kaydedilmiş REA engeli korunur. Hedef program, güncelleme veya TV komutu çalıştırılmadı.

- `MenuBackgroundFrame::OnCreate` aday gövdesi `0xdbb4f8`: `Image::Image` çağrısı `0xdbeb1c`, nesne alanı `this+0x1b8`, ebeveyn `this+0x18c`. Num kaynakları `0x4015/0x4016/0x4014/0x4013`, sırasıyla `(x,y,w,h)=(0,8,260,78)` verir.
- Bu nesnenin dört `MImg::Set` durumu `0xdbebd4/0xdbebf8/0xdbec1c/0xdbec40` adreslerinde `a1=915` yükler.
- `MenuBackgroundFrame::SetBreadCrumbs` (`0xdb5328`) normal marka dalı aynı nesneye `0xdb56e4/0xdb5708/0xdb572c/0xdb5750` adreslerinde dört kez 915 yükler. Yalnız bu sekiz argüman yeni özel kaynak **2184** olacak şekilde değişir. Diğer marka seçim dalları ve ekmek kırıntısı/metin davranışı korunur.
- Native geometri, `Num_res.bin`, widget sınıfı, parent, fonksiyon çağrısı, register, branch, delay slot, navigation ve zamanlayıcılar değişmez. Yardımcı kod veya yeni executable segment eklenmez.
- Kaynak 915 ve tüm eski kaynak kayıtları byte düzeyinde korunur. Yeni yol `08_APP/rc/ARimages/Grundig/modern/semih_menu_brand.png` olur. `Image_res.bin` 2184 kayıttan 2185 kayda yalnız eklemeyle büyür.

`GetOSDBrandName`, cihaz marka kimliği, boot logosu, ilk kurulumdaki logo ve başka ekranların 915 kullanımları değiştirilmez. Ortak `MenuBackgroundFrame` marka widget'ını kullanan menü başlıkları yeni yazıyı paylaşabilir; yalnız ana ekranın bir runtime örneğini ayıran koşul eklenmez. Statik analiz fiziksel TV'nin seçili tema dalını veya son ölçeklemesini kanıtlamaz.

## Görsel kaynak ve yerleşim

Özgün logo 400×120 P8 PNG'dir, beyaz RGB ve alfa içerir. Özgün alfa kutusu `(54,43)-(346,77)`, yeni kutu `(98,43)-(302,77)` olur. Merkez x=200 ve 34 piksel harf yüksekliği aynıdır; daha az harf nedeniyle yazı genişliği azalır. 260×78 native kutu ve konumu aynen kaldığından yeni yazı aynı merkez ve düşey hizada kalır.

Yeni SVG, raster kopyalama veya font tahmini olmadan bağımsız düzenlenebilir path'lerden oluşur. Chromium 156.0.8078.48 ile 8× render, LANCZOS küçültme, 16 kademeli alfa coverage ve beyaz P8+tRNS kullanıldı. Çok zayıf yeniden örnekleme halkaları alfa<24 için kaldırılır. Orijinal PNG yaratıcı biçimde düzenlenmez. PNG boyutu/renk türü, alfa, palet ve her chunk CRC'si doğrulanır. Render sırasında ağ isteği yoktur.

## API ve doğrulama

`scripts/native_semih_brand.py`:

- `apply(v79_elf_bytes) → (patched_elf, proof)`: tam V7.9 SHA guard'ı ile sekiz native immediate değiştirir. Diğer özellik dönüşümlerinden önce uygulanır.
- `expected_payloads(v79_image_table) → (images_dict, appended_table, proof)`: tam V7.9 tablo guard'ı ve sabit SVG/PNG hash'i ile yeni özel kaynak ekler.
- `--render`: yalnız ayrılmış analiz klasöründeki yeni SVG/PNG kaynaklarını mevcut yerel Chromium/Pillow akışıyla tekrar üretir; firmware çalıştırmaz.

V7.9 girdi ELF SHA-256 `861d97c013c4d56e093a69cf779abfa6ea78e6c17233af5d6b2b3ba075b0b4ea`; Image_res SHA-256 `3319b2a33d2950396bb181a558214d901575c82ca2ab8df2a91f52316dfce467`.

`python -m unittest discover -s scripts -p test_native_semih_brand.py -v`: **7/7 geçti**. Testler tüm ELF farkını izinli sekiz word'e sınırlar; bozuk girdi ve CRC'yi reddeder; eski tablo kayıtları/kaynak915'i, yeni özel ID/yolu, şeffaf beyaz PNG'yi, merkez ve harf yüksekliğini denetler. Önizleme Chromium'da 1080×900 ve 390×844 boyutlarında açıldı: bütün görseller yüklendi, yatay taşma yok. Bunlar native firmware runtime testi değildir. Fiziksel TV testi yapılmadı.

Adresli instruction kesitleri, girdi/çıktı hash'leri, görsel sınırları, kaynak kapsamı ve sorgu hash'leri [proof.json](../analiz/native-features/semih-brand/proof.json) içindedir. Kullanılan beceri: `reverse-engineer-anything`.
