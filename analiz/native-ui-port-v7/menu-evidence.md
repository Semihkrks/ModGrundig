# Menü kaynakları ve önizleme sınırları

24 Ekim 2026. `reverse-engineer-anything` ile mevcut Türkçe UI kaynak tablosu ve kaydedilmiş statik çıktılar karşılaştırıldı. Yeni decompile, firmware çalıştırma veya TV işlemi yapılmadı. Bu kayıt REA Evidence değildir.

## Adresli 10 örnek

| Öğe | String ID | Çağrı noktası | Gövde / widget |
|---|---|---|---|
| Home: Ayarlar | `0xf49` | `0xd2f594` | `0xd29500` |
| Home: Medya Merkezi | `0x114e` | `0xd2f258` | `0xd29500` |
| Home: Plan Listesi | `0xf16` | `0xd31230` | `0xd29500` |
| Home: Kaydedilenler | `0x1196` | `0xd315d4` | `0xd29500` |
| Kanal filtre: Tümü | `0xc0f` | `0x7a9e54` | `0x7995b0` |
| Kanal filtre: Radyo | `0xece` | `0x7aa7bc` | `0x7995b0` |
| TV Ayarları: Dil & Klavye | `0x1147` | `0xd07094` | `0xd01710` / 10 |
| TV Ayarları: Erişilebilirlik Ayarları | `0xbf2` | `0xd07774` | `0xd01710` / 11 |
| TV Ayarları: Aksesuarlar | `0x1071` | `0xd07e54` | `0xd01710` / 12 |
| TV Ayarları: Hakkında | `0x106e` | `0xd08c14` | `0xd01710` / 14 |

## Ana menü ve kategoriler

Önizlemedeki Görüntü Ayarları, Ses Ayarları, Kaynak Ayarları, Ebeveyn Ayarları, Zamanlayıcı ve TV Ayarları metinleri Türkçe tabloda birebir var. `native-profile.js` dört görsel kartı bağlar; son iki kategori ve altı öğelik modern Home sıralaması host tasarımını temsil eder. Kaynak metni, cihaz desteği veya gezinme kenarı kanıtı değildir.

Kaydedilmiş Home LayoutItems `0xd29500` içinde Medya Merkezi, Plan Listesi, Kaydedilenler ve Ayarlar bağlanır. Önizlemedeki Medya Oynatıcı, Kayıt, Zamanlayıcı gibi girişler yararlı tasarım uyarlamalarıdır; birebir native Home kopyası diye sunulmamalı.

## Kanal listesi

Kaydedilmiş `0x7995b0` kurulumunda filtre adayları: Tümü (`0xc0f` @ `0x7a9e54`), Dijital (`0xcdd` @ `0x7aa308`), Radyo (`0xece` @ `0x7aa7bc`), Analog (`0xc17` @ `0x7aac70`), Ücretsiz (`0xd64` @ `0x7ab124`), Şifreli (`0xf1c` @ `0x7ab5d8`), Uydu (`0xf07` @ `0x7aba8c`). Önizlemenin Tüm Kanallar / Favoriler iki sekmesi daha dar host politikasıdır.

İlk okumada doğrudan sekme tıklaması mevcut filtreyi ters çeviriyordu. Tasarım ajanı `app.js` butonlarına istenen index’i ekledi ve aktif sekmeye tıklamayı etkisiz bıraktı; kaynak değişikliği bu alt işte görüldü. Ok tuşu çevrimi korunur. Tarayıcı doğrulamasını tasarım ajanı yürütür.

## Kanıt etiketinde düzeltilecekler

- `program-repeat`: Tekrar etiketi `0xfe9` kaynağıyla eşlenmiş; gerçek metin **Bir kez** (seçenek).
- `recording-list`: Kayıt Listesi etiketi `0x1195` kaynağıyla eşlenmiş; gerçek metin **Kayıt Listesi Boş** (boş durum).
- DIGI LINK Aygıtları / DIGI LINK Ayarları, `0x24` **Digilink** aile metnini genişletir. Bu genişletilmiş etiketler host alt bölümü/uyarlaması diye işaretlenmeli.

Diğer noktalama ve kısaltma farkları JSON’da listelenir; tasarım uyarlaması olarak açıklanınca metin değiştirmek zorunlu değildir.

## Kapsam ve kontrol

Devam düzeltmesi: yukarıdaki program-repeat, recording-list ve iki DIGI LINK etiketinin `labelBasis` kayıtları `ui-preview/extra-menu-data.js` içinde host uyarlaması olarak açıklanmıştır; seçenek/boş durum/aile string'i birebir satır etiketi diye sunulmaz. Doğrudan filtre seçimi modelde de idempotenttir. Son Chrome doğrulaması24 menü/156 satır, boş radyo ve kumanda odağı testleriyle tamamlandı; [güncel rapor](../../docs/UI_MENU_AYARLAR_V7.md).

Aktif katalog 24 menü / 156 satır olarak okundu; çözülemeyen alt menü hedefi 0. Bu statik bağlantı kontrolüdür; bu alt işte tarayıcı veya test paketi çalıştırılmadı.

Ağ/Web/APP kullanıcı cihazı kapsamı gereği kapalı kalmalı. Paylaşılan pakette APP/WEB, Bluetooth, kamera veya diğer ailelerin adı bulunması fiziksel cihaz desteği değildir. RF tarama, medya codec’i, gerçek PVR, CEC aygıt keşfi ve firmware güncellemesi bu host önizlemesinde çalışır diye sunulmamalı. Mevcut donanım bilgi ekranları bu sınırı açıkça bildirir.

Kaynaklar ve bütün etiket karşılaştırmaları: [menu-evidence.json](menu-evidence.json).
