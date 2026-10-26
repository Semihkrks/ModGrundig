# GeneralSettingsFrame: 66 widget / kaynak / handler bağı

Kaynak: `bounded300/00d01710.c`, ham MIPS çağrıları ve `message-map.json`. Geometri `rc/Num` tablosunun mantıksal başlangıç değerleridir; sonraki NewUI_Settings çağrısı ve runtime düzeni bunları değiştirebilir. Son constructor ulong argümanı ile map selector ID eşleşmesi statik adaydır.

| ID | Alan / parent alanı | Tür / ilk etiket | Constructor VA | rc başlangıç Rect (x,y,w,h) | 0x16 selector → handler |
|---:|---|---|---|---|---|
| 0 | 0x180 / 0x38 | Button   | 0xd0180c | 0,5,1920,5 |  |
| 1 | 0x184 / 0x38 | Image  | 0xd01c1c | 950,476,36,24 |  |
| 2 | 0x188 / 0x38 | Image  | 0xd01fe0 | 950,80,36,24 |  |
| 3 | 0x18c / 0x38 | ScrollListContainer  | 0xd023a4 | 0,100,1920,360 |  |
| 4 | 0x190 / 0x38 | ScrollListContainer  | 0xd02ef0 | 0,100,1920,360 |  |
| 5 | 0x194 / 0x38 | ScrollListContainer  | 0xd03ae8 | 0,100,1920,360 |  |
| 6 | 0x198 / 0x38 | ScrollListContainer  | 0xd046e0 | 0,100,1920,360 |  |
| 7 | 0x19c / 0x38 | ScrollListContainer  | 0xd052d8 | 0,100,1920,360 |  |
| 8 | 0x1a0 / 0x38 | ScrollListContainer  | 0xd05ed0 | 0,100,1920,360 |  |
| 9 | 0x1a4 / 0x38 | TextBox Default | 0xd06ac8 | 1044,420,774,44 |  |
| 10 | 0x1a8 / 0x18c | ImageButton Dil & Klavye | 0xd06fd4 | 0,0,1918,58 |  |
| 11 | 0x1ac / 0x18c | ImageButton Erişilebilirlik Ayarları | 0xd0762c | 0,58,1918,58 |  |
| 12 | 0x1b0 / 0x18c | ImageButton Aksesuarlar | 0xd07d0c | 182,91,182,91 |  |
| 13 | 0x1b4 / 0x18c | ImageButton Gelişmiş | 0xd083ec | 0,234,1918,58 |  |
| 14 | 0x1b8 / 0x18c | ImageButton Hakkında | 0xd08acc | 0,292,1918,58 |  |
| 15 | 0x1bc / 0x18c | ImageButton OTEL TV AYARLARI | 0xd091ac | 0,0,0,0 | 19:0x00cf3f90 @0x010be4dc |
| 16 | 0x1c0 / 0x18c | AbsContainer  | 0xd0988c | 0,300,1920,60 |  |
| 17 | 0x1c4 / 0x18c | ComboButton TV Rehberi | 0xd09c40 | 0,0,0,0 |  |
| 18 | 0x1c8 / 0x18c | ComboButton Çevrimiçi Program Bilgisi | 0xd0a500 | 0,0,0,0 |  |
| 19 | 0x1cc / 0x1c0 | TextBox Çevrimiçi Program Verisi | 0xd0adc0 | 580,25,790,30 |  |
| 20 | 0x1d0 / 0x190 | ImageButton Menü Dili | 0xd0b250 | 0,292,1918,58 | 19:0x00cfca08 @0x010be178 |
| 21 | 0x1d4 / 0x190 | ImageButton Ses Dili | 0xd0b8a8 | 0,175,1918,58 | 19:0x00cfc514 @0x010be194 |
| 22 | 0x1d8 / 0x190 | ImageButton Altyazı Dili | 0xd0bf88 | 0,175,1918,58 | 19:0x00cfaf24 @0x010be1b0 |
| 23 | 0x1dc / 0x190 | ImageButton Klavye Dili | 0xd0c668 | 0,0,1918,58 | 19:0x00cf70d8 @0x010be1cc |
| 24 | 0x1e0 / 0x194 | ComboButton Sesli Anlatım | 0xd0cd48 | 0,180,1920,60 |  |
| 25 | 0x1e4 / 0x194 | ComboButton Altyazı Modu | 0xd0d6d8 | 0,0,1920,60 | 16:0x00cfc194 @0x010be2e4 |
| 26 | 0x1e8 / 0x194 | ComboButton Sesli Anlatım | 0xd0df98 | 0,117,1918,58 | 16:0x00cfbfa8 @0x010be300 |
| 27 | 0x1ec / 0x194 | SpinButton Sesli Anlatım Sesi | 0xd0e87c | 0,175,1918,58 | 16:0x00cfbef4 @0x010be31c |
| 28 | 0x1f0 / 0x198 | AbsContainer  | 0xd0f150 | 0,0,1920,60 |  |
| 29 | 0x1f4 / 0x198 | ImageButton Ayarlar | 0xd0f47c | 0,60,1920,60 | 19:0x00cfed24 @0x010be15c |
| 30 | 0x1f8 / 0x198 | AbsContainer  | 0xd0fad4 | 0,0,1920,60 |  |
| 31 | 0x1fc / 0x198 | ComboButton Durum | 0xd0fe88 | 0,300,1920,60 | 16:0x00cf21f8 @0x010be3e0 |
| 32 | 0x200 / 0x198 | SpinButton Kulaklık | 0xd1076c | 182,91,182,91 | 16:0x00cfbe40 @0x010be338; 16:0x00cfbe40 @0x010be3fc |
| 33 | 0x204 / 0x198 | AbsContainer  | 0xd1104c | 0,180,1920,60 |  |
| 34 | 0x208 / 0x198 | ComboButton Durum | 0xd11378 | 0,0,0,0 | 16:0x00cf222c @0x010be434 |
| 35 | 0x20c / 0x198 | ComboButton Hareketle Kontrol | 0xd11c5c | 0,0,0,0 | 16:0x00cfc404 @0x010be418 |
| 36 | 0x210 / 0x198 | AbsContainer  | 0xd12540 | 0,0,0,0 |  |
| 37 | 0x214 / 0x198 | ComboButton Dil | 0xd1286c | 0,0,0,0 | 16:0x00cfc360 @0x010be450 |
| 38 | 0x218 / 0x198 | AbsContainer  | 0xd13150 | 0,0,0,0 |  |
| 39 | 0x21c / 0x198 | ComboButton Hassasiyet | 0xd1347c | 0,0,0,0 | 16:0x00cf2260 @0x010be46c |
| 40 | 0x220 / 0x198 | ImageButton VR Settings | 0xd13d60 | 0,60,1920,60 |  |
| 41 | 0x224 / 0x198 | ImageButton Air Mouse/Gesture conrol Settings | 0xd143b8 | 182,91,182,91 |  |
| 42 | 0x228 / 0x198 | ImageButton Skype Cam/Baby Cam Settings | 0xd14a98 | 182,91,182,91 |  |
| 43 | 0x22c / 0x1f0 | TextBox Bluetooth | 0xd15178 | 580,25,790,30 |  |
| 44 | 0x230 / 0x1f8 | TextBox Easy Remote | 0xd15690 | 580,25,790,30 |  |
| 45 | 0x234 / 0x204 | TextBox Kamera | 0xd15b20 | 580,25,790,30 |  |
| 46 | 0x238 / 0x210 | TextBox USB Klavye | 0xd15fb0 | 580,25,790,30 |  |
| 47 | 0x23c / 0x218 | TextBox USB Fare | 0xd16440 | 580,25,790,30 |  |
| 48 | 0x240 / 0x19c | ComboButton Otomatik Kapanma | 0xd168d0 | 0,0,0,0 | 16:0x00cf59e8 @0x010be2c8 |
| 49 | 0x244 / 0x19c | ComboButton Hızlı Kanal Geçişi | 0xd17190 | 182,180,1920,60 | 16:0x00cf58d8 @0x010be354 |
| 50 | 0x248 / 0x19c | ComboButton Mağaza Logosu Görünümü | 0xd17a50 | 182,91,182,91 | 16:0x00cfc29c @0x010be488 |
| 51 | 0x24c / 0x19c | ComboButton Güç LED'i Parlaklığı | 0xd18310 | 182,91,182,91 | 16:0x00cf67c4 @0x010be220 |
| 52 | 0x250 / 0x19c | ComboButton Güç Koruma Modu | 0xd18bd0 | 0,180,1920,60 | 16:0x00cfc48c @0x010be2ac |
| 53 | 0x254 / 0x19c | ComboButton Sürekli Kayıt | 0xd19490 | 182,180,1920,60 | 16:0x00cf5960 @0x010be370 |
| 54 | 0x258 / 0x19c | ComboButton Hava Durumu Gösterimi | 0xd19d50 | 0,0,0,0 | 16:0x00cf2294 @0x010be38c |
| 55 | 0x25c / 0x19c | ComboButton Yardım | 0xd1a610 | 0,0,0,0 | 16:0x00cf56e4 @0x010be3a8 |
| 56 | 0x260 / 0x19c | ComboButton Hızlı Açılma | 0xd1aed0 | 182,180,1920,60 | 16:0x00cf576c @0x010be3c4 |
| 57 | 0x264 / 0x1a0 | ImageButton Ürün Bilgisi | 0xd1b790 | 0,234,1918,58 | 19:0x00cf4a38 @0x010be204 |
| 58 | 0x268 / 0x1a0 | ComboButton TV Adı | 0xd1bde8 | 0,117,1918,58 | 19:0x00cf3b3c @0x010be1e8 |
| 59 | 0x26c / 0x1a0 | ImageButton Yazılım Güncellemeleri | 0xd1c754 | 0,0,1918,58 | 19:0x00cf5e08 @0x010be290 |
| 60 | 0x270 / 0x1a0 | ImageButton Fabrika Ayarlarına Dönüş | 0xd1cdac | 0,117,1918,58 | 19:0x00cf62f4 @0x010be23c |
| 61 | 0x274 / 0x1a0 | ImageButton Kanal Geçmişini Temizle | 0xd1d48c | 0,117,1918,58 | 19:0x00cf3c70 @0x010be258 |
| 62 | 0x278 / 0x1a0 | ImageButton Seçili İmajları Eski Haline Döndür | 0xd1db6c | 0,117,1918,58 | 19:0x00cf3e00 @0x010be274 |
| 63 | 0x27c / 0x1a0 | ImageButton Ayar Yedekleme | 0xd1e24c | 0,117,1918,58 | 19:0x00cf41ec @0x010be4f8 |
| 64 | 0x280 / 0x1a0 | ComboButton Ülke | 0xd1e92c | 0,117,1918,58 |  |
| 65 | 0x284 / 0x1a0 | ImageButton Lisans Anlaşması | 0xd1f298 | 0,234,1918,58 |  |
