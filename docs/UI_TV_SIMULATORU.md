> Güncel genişletilmiş kapsam: [24 menü / 156 satır, özellikler ve doğrulama sınırları](UI_OZELLIK_KAPSAMI.md). Bu belgenin önceki12/68 ve31test sayaçları tarihsel aşamadır.

# TV arayüzü: firmware temeli ve çalışan simülatör

23 Ekim 2026 · Dal `codex/ui-soft-preview` · Önizleme `http://127.0.0.1:4173/`.

Bu aşama önceki dört kartlı web önizlemesini, firmware'de bulunan iki yatay Home rafı, satır tabanlı ayarlar ve kanal tarayıcısı düzenine dönüştürür. Tarayıcıya özgü çarpılı pencere, form alanı ve diyalog yoktur. Kullanıcının son talebiyle **12 geçici örnek kanal ve kurmaca program bilgisi** eklenmiştir. Bunlar cihazdan çıkarılmış kanal veritabanı değildir. Ağ/Web/APP eklenmemiştir.

## Kod ve kanıt

| Parça | Statik kaynak | Bu aşamada uygulanan |
|---|---|---|
| İki Home rafı | `HomePageFrame::OnCreate 0xd42150`, `analiz/native/ui-four/home/home-widget-map.json`: 1920×504; üst raf `(57,30,1850,232)`, alt `(57,284,1850,210)` | İki raf, üst eylemler ve Ayarlar bağlamındaki alt kategoriler; beyaz/mavi modern görünüm. Alt kategoriler firmware settings popup'ından uyarlanır; birebir OEM ekran yakalaması değildir. |
| Ayar kategorileri | Aynı ağaç child33/34/35/36/37/39: görüntü, ses, kaynak, kilit, zamanlama, genel; 38 Wi-Fi dışarıda | Altı kategori. Medya oynatıcı, kanal düzenleyici, zamanlayıcı ve kanal listesi üst rafta yer alır. Bu sadeleştirilmiş eylem sırası bir tasarım kararıdır. |
| Ayar satırları | `GeneralSettings 0xd01710`, `SourceSetupFrame 0xf0dd24`, diğer fonksiyon ve string çağrı adresleri `analiz/ui-modernizasyon/menu-schema-evidence.json` | 12 menü / 68 satır. 53 satır native C/widget veya string çağrısı bağlantılı; 15 satır yalnız kaynak metniyle destekli. Değer aralıkları, seçenek grupları ve varsayılanlar simülatör politikasıdır. Cihaz görünürlüğü kanıtı sayılmaz. |
| Kanal listesi | `ChannelListFrame::OnCreate 0x7995b0`, `analiz/native/ui-four/channels/layout-v1/007995b0.c`: sol liste680px; sağ açıklama; alt tuş bandı | Sol kanal satırları / sağ program ayrıntısı, filtre, favori, kanal taşıma, atlama, demo PIN kilidi. |
| Numara girişi | `0x895b84`, `0x89552c`, `0x895b24`, `0x8968d8`, `0x896b88`; `analiz/channel-ui-evidence.json` | Üst orta 200×70 numara alanı, ilk üç basamak3s, dördüncü2s; beşinci basamak/OK ayrımı korunur. |
| Program bilgi bandı | `0x7de53c`, aynı kanıt JSON'u; 250/355 yüksekliğinde native gruplar | Alt bilgi bandı ve Bilgi ile genişletme. Native parent-local koordinatlardan ekrana son yerleşim henüz cihazda doğrulanmadı. |
| Uzun ses paneli | `VolumeControlFrame::OnCreate 0xfb9780`, `RefreshVolumeUI 0xfb7d18`: normal panel420, track200, y88 | Güncel host kapsül76×500px; kesintisiz6px gösterge, sürgü başı yok.0–100, otomatik sıfır sessizliği, mute ve3s kapanma; yerel/ARC simülasyonu ayrı. |

Tam kaynak envanteri ve satır kanıtları [menu-schema-evidence.json](../analiz/ui-modernizasyon/menu-schema-evidence.json) içindedir. [firmware-menu-data.js](../ui-preview/firmware-menu-data.js) bu envanterden üretilir. [tv-model.js](../ui-preview/tv-model.js) saf durum makinesi; [app.js](../ui-preview/app.js) render/klavye katmanıdır. Gerçek cihazla iletişim kurmaz.

## Denenebilir akışlar

- `M`: menü. Yön tuşları, `Enter`: OK, `Esc`: Geri. TV'de OK kanal listesi; `PageUp/PageDown` kanal geçişi; `0–9` ve OK numarayla kanal. `I` bilgi; `G` rehber; `R` önceki kanal; `V` kaynak.
- `+ / −`: ses; `S`: mute. Hızlı tekrarlarda çizilen konumdan yeni hedefe150ms yumuşatma yapılır. Bu modernleştirme host'a aittir; native MUF animasyon gate'inin çalıştığı iddia edilmez.
- Kanal düzenleyicide OK taşıma, yönlerle sıra değiştirme, `F2` favori, `F3` atla, `F4` kilit. Demo PIN başlangıcı0000. PIN değiştirme yalnız geçici simülatör belleğindedir.
- Ayar satırları: sağ/sol değer değiştirir, OK alt menü/eylem açar. Sıfırlama iptal varsayılanlı TV onay ekranıdır. Manuel arama demo kanal numarası alır; arama mevcut demo verileri üzerinde ilerler. RF taraması yapılmaz.
- `P` bekleme/açılma. Zamanlayıcılar yerel sürelerle simüle edilir. `U` yalnız test USB bağlantısı bayrağını değiştirir; host dosyalarına erişmez, medya decode etmez.
- `F1` test kumandası ve ARC/CEC/HDMI koşulları. ARC/CEC/HDMI üç kapısı açıkken CEC kabul veya ret sonucu yerel seviyeyi değiştirmez; bilinmeyen mutlak ARC seviyesi yerine `+ / − / —` gösterilir. Ret halinde mute bayrağı da değişmez. Sonraki [native v2 raporu](UI_NATIVE_ADAY_V2.md) önceki dört kapı varsayımını düzeltir. Fiziksel CEC/ACK yoktur.

Kaynak seçicisindeki HDMI1–4/Scart/AV/USB bir test kataloğudur; gerçek modelin fiziksel port sayısı doğrulanmış değildir. Kurulum değerlerinin tamamının bu cihazda görünür olduğunu varsaymayın. Gerçek medya aygıtı/sinyal bulunmadığında oynatılmış içerik veya ölçülmüş sinyal gösterilmez. Değişiklikler bellekte tutulur; yenileme demo varsayılanlarına döner.

## Firmware entegrasyonunun sınırı

**Çalışan çıktı bilgisayardaki TV simülatörüdür.** HTML/CSS/JS DirectFB/MUF üzerinde çalıştırılmadı. Orijinal BIN/ZIP/ELF/kaynak tabloları değiştirilmedi, kurulabilir paket üretilmedi, TV'ye yazılmadı.

19 PNG adayının boyut/biçim/alpha/CRC ve orijinal hash doğrulaması önceki aşamada tamamlanmıştı; bu aşama bu testleri yeni native uygulama kanıtı diye tekrar saymaz. [Adaylar](../ui-assets/README.md), [doğrulama](../ui-assets/validation.json), [native C hareket çekirdeği](../native-ui/README.md).

Native için kalanlar: kaynak tablolarına güvenli bağlama; tüm parent-local/final layout koordinatları ve odak sırası; opak P4 ses arka planının clipping/colorkey davranışı; MUF50ms timer ve sabit0 animasyon gate'i; MIPS toolchain/header/link sözleşmesi; gerçek kumanda, ses/CEC ve performans kabul testleri. `LayoutItems 0xd29500`, `GetAnimationEnabled 0x555ed4`, `VolumeControlFrame::OnKey 0xfb8c7c` korunacak somut kod yollarıdır. Bu adımlar çözülmeden TV ile önizleme eşliği onaylanmaz.

## Yeniden doğrulama

```powershell
node ui-preview/server.mjs
node --test ui-preview/tests/tv-model.test.mjs
node ui-preview/tests/browser.mjs
```

Güncel gerçek tarayıcı sonuçları ve ekran görüntüleri `analiz/ui-modernizasyon/tv-*` altında tutulur. Eski `state.test.mjs` ve `channel.test.mjs` önceki saf yardımcıların regresyon testleridir; yeni68satırlı aktif uygulamanın kapsamı yerine kullanılmaz. Kullanılan beceriler: `frontend-design`, `reverse-engineer-anything`. Üç alt ajan orijinal yerleşim, görünüm ve menü/model/test sahipliğini ayrı yürüttü; ana ajan denetleyiciyi ve belgeleri birleştirdi.

## Son doğrulama: 23 Ekim 2026

**29/29 Node testi geçti:**18 aktif TV modeli testi +11 önceki yardımcı regresyonu. Aktif modelde10eylem türü, PIN/kilitler, arama, sıfırlama, geçmiş, zamanlayıcılar ve kaynak akışları sınandı. Bağımsız incelemenin dört hatası kapatıldı: ARC ayar satırı yerel sesi değiştirmiyor; rakam silme çalışıyor; kanal taşıma önceki kanal kimliğini koruyor; onay satırına tıklamak doğru seçeneği işletiyor.

**Gerçek Chrome/Playwright geçti:** iki Home rafı, ayar gezintisi/değer değişimi,420px panel,0/100/mute,12+OK kanal girişi, OK listesi/kanal seçimi, bilgi bandı, kaynak seçimi, F1 kumanda/ARC kapıları, onayla/vazgeç tıklamaları.1920×1080,1280×720,390×844 ölçek/taşma kontrolleri geçti. Konsol/pageerror/dialog sayısı0. [Makine sonucu](../analiz/ui-modernizasyon/browser-tests.json).

[Ana menü](../analiz/ui-modernizasyon/tv-home-1920.png) · [Ses](../analiz/ui-modernizasyon/tv-volume-100.png) · [Kanal listesi](../analiz/ui-modernizasyon/tv-channels-1920.png) · [Bilgi bandı](../analiz/ui-modernizasyon/tv-info-1920.png). Bunlar çalışan bilgisayar simülatörünün ekran görüntüleridir. TV ekran yakalaması değildir. Firmware/cihaz testi sayısı0; bu testler donanım işlevlerini veya68satırın fiziksel cihazdaki varlığını doğrulamaz.


## Ses paneli ince ayarı

Kullanıcının sonraki isteğiyle host panel100×420→76×500px oldu (%24 daha dar, %19 daha uzun); mavi ray10×200→6×320px. Sürgü başı DOM/CSS/çizimden kaldırıldı. Büyük opak PNG ikon yerine30px çizgi ikon kullanılır; ikon ve TV/HDMI ARC etiketi ayrı yerleşir. Panel görünürken ikinci bir mute kutusu gösterilmez; panel kapandıktan sonra küçük sessiz işareti kalır.

`audioMuted` yerelde `muted || volume===0` olarak hesaplanır. Sıfır seviyesi manuel mute bayrağını değiştirmez; sesi1'e çıkarmak otomatik sessizliği kaldırır. Sıfırdaki mute tuşu gizli bir manuel kilit oluşturmaz. Önceden elle mute edilmiş durum korunur. ARC için bilinmeyen alıcı seviyesine yerel sıfır değeri uygulanmaz. Ses satırı, hızlı tekrarlı tuşlar ve setter aynı durum hesabını kullanır.

31/31 Node testi geçti (20 aktif model +11 yardımcı regresyonu). Chrome testi sıfırdaki ikon/aria durumu, sürgü yokluğu,76×500 geometri,3s panel kapanışı sonrası sessiz işareti, tekrar ses açma,0/100, manuel mute ve ARC geri dönüşünü geçti; konsol/pageerror0. Önceki menü/kanal ve üç viewport kontrolleri de geçti. Beceri: `redesign-existing-projects`.

[Yeni panel](../analiz/ui-modernizasyon/tv-volume-slim-tv.png) · [Sıfır](../analiz/ui-modernizasyon/tv-volume-slim-zero.png). Bu görünüm ve yeni sıfır davranışı host simülatöründe uygulanmıştır; mevcut native PNG adayları/profil420px kanıt değerlerini korur. Yeni geometri, küçük ikon ve sıfır-mute politikası henüz MUF/MIPS koduna bağlanmadı. Firmware orijinalleri ve TV değişmedi.
