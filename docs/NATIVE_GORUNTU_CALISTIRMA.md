# Native MUF görüntüsü ve yazı/ikon düzeltmesi

Güncel kapsam: [V7 TV ses/numara adayı](UI_NATIVE_V7_TV_ADAYI.md). Menüler ve menü ikonları orijinaldir; V8 menü deneyi kullanıcı kararıyla iptal edildi. Test yüzeyi V7 TV ses paneliyle açılır. Aşağıdaki diğer sürüm notları tarihseldir.

25 Ekim güncel sürüm: [gerçek native MUF v8](UI_NATIVE_ADAY_V8.md). Görüntüleyici v8 kaynak karşılaştırmasını açar; gerçek aday resimler özgün MUF MIPS çizim fonksiyonlarıyla çizilir. Bu levha tam native menü/event yürütmesi değildir. Aşağıdaki v7/v4/v5 kayıtları önceki aşamalardır.

Güncel durum: [menü/ayarlar ve native v7](UI_MENU_AYARLAR_V7.md). Native laboratuvar varsayılanı v7: kapsül68×450, DINPro fontu ve44×44 ikon; genişletilmiş sayısal kartta rakam boşluğu düzeltildi. Kanal adı önerilen test widget'ıdır; gerçek DB/event köprüsü kurulmadı. [Tam menü önizlemesi](http://127.0.0.1:4174/preview/?menu=1) ayrı HTML/CSS/JS yüzeyidir. Aşağıdaki v4/v5 ölçümleri önceki aşamanın kaydıdır.

24 Ekim 2026. Kullanıcının izole bilgisayar üzerinde çalıştırma ve görsel iyileştirme isteğiyle devam edildi. `reverse-engineer-anything`, bağımsız analiz/uygulama alt ajanları ve kod incelemesi kullanıldı. Orijinal firmware ve önceki v3 adayı korunur. TV'ye yazılmaz.

## Ekranı açma

Depo kökünden:

```powershell
python scripts/native_frame_viewer.py --port 4174
```

Ardından [yerel native kare görüntüleyicisini](http://127.0.0.1:4174) aç. Sağ/sol tuşları test ses değerini, M açık mute girdisini değiştirir. Rakamlar sayısal paneli gösterir; Esc ses paneline döner. Sürüm seçimi orijinal/v3/v4 kaynaklarını karşılaştırır.

Tarayıcı, sunucuda üretilen 1920×1080 PNG'yi gösterir. Televizyon widget'ları HTML/CSS ile çizilmez. Tuşlar test durumunu emüle servis sınırlarına verir; özgün kumanda sürücüsü, kanal değiştirme veya gerçek ses çıkışı çalışmaz. Görüntüleyici yalnız loopback adresine bağlanır, dosya sunucusu değildir.

## Çalıştırılan ve modellenen parçalar

Gerçek ELF baytları Unicorn MIPS CPU üzerinde yürütülür:

| Modül / fonksiyon | Adres | Kapsam |
|---|---|---|
| dvbt_board / VolumeControlFrame::RefreshVolumeUI | `0xfb7d18` | Ses metni, progress değeri, dört durumun ikon ID'leri, thumb koordinatı, timer ve ARC dalları |
| libmuf / MWidget::DrawBackground | `0x2e251be4` | Arka plan rengi, kaynak resmi ve kenarlık çizim akışı |
| libmuf / MResourceManager::RenderImageToSurface | `0x2e23e684` | Kaynak yüzey boyutu, alfa ayarları ve StretchBlit parametreleri |
| libmuf / MWidget::DrawBorders | `0x2e24d438` | Kenar maskesi ve dikdörtgenler |
| libmuf / MWidget::DrawString | `0x2e24de4c` | Seçilmiş ASCII rakam yolu, buffer ve yüzeye metin aktarımı |
| libmuf / MWidget::CalculateTextDrawFlags | `0x2e24fe3c` | Metin hizalaması, koordinat ve çizim flag'leri |

`RefreshVolumeUI` servisleri açık callback'lerdir. Ses/CEC donanımı taklit edilerek başarılı cihaz testi sonucu verilmez. Widget alanları retained OnCreate C/assembly ve kaynak tablolarından kurulur; asıl OnCreate/kurucu/event döngüsü henüz yürütülmez. DirectFB yüzeyi, PNG açma, font rasterizer/ölçüleri, alfa birleştirme ve ölçekleme Pillow/FreeType tarafından sağlanır. ProgressBar dolgusu native seçilmiş değerden host geometrisiyle hesaplanır; özgün ProgressBar Update çalıştırılmaz.

Bu nedenle çıkan kareler gerçek firmware kodunun **kısmi yeniden barındırılmasıdır**. Tam TV açılışı, video-plane birleştirmesi, gerçek yayın veya cihazla piksel eşliği değildir. Koyu arka plan nötr test yüzeyidir.

Adresli callback ve çalıştırılan komut listeleri her PNG'nin yanındaki JSON'da bulunur: [kareler ve yürütme kanıtları](../analiz/native-frame-rehost/README.md), [durum senaryoları](../analiz/native-volume-state/states.json), [metin ABI/font kanıtları](../analiz/native-text-render/text-path-evidence.md).

## Neden önceki karede font ve ikon zayıftı?

v3, ses sayısında özgün DINPro-CondMedium fontunu kullanıyordu. 36px istek yüksekliğine rağmen dar fontun `35` rakamları yaklaşık 26px genişliğindedir. 100px kaynak ikon içindeki 54px SVG ve şeklin kendi boşluğu, 30px widget'a küçülünce hoparlörü yaklaşık 15×12px yapıyordu. Tarayıcı taslağının sistem fontuyla eşleştiği varsayılmamalıydı.

Yeni v4, ayrı kaynak kopyasında yalnız ses sayısının dört font durumunu mevcut firmware fontu **Lucida Sans Bold, ID0x4af** olarak değiştirir. 36px boyut korunur; `100` yaklaşık 69px genişlikle 76px alana sığar. Dört yerel metin renk argümanı Color0x25'ten Color0'a değiştirilerek koyu ve okunaklı sayı elde edilir. Global font dosyaları, font/color tabloları veya paylaşılan Num0x3215 değiştirilmez.

Font instruction adresleri `0xfbbe18/28/38/48`, renk argümanları `0xfbbc30/50/70/90`; her biri eski instruction doğrulanarak değiştirilir. Hoparlör/mute kaynaklarında aynı onaylı TV sembollerinin iç yerleşimi büyütülür; PNG boyut/bit derinliği ve alfa yeteneği korunur. Diğer menü font ve ikonları bu v4 düzeltmesinin kapsamına girmez.

[V4 üretici](../scripts/build_native_ui_v4.py), [ayrı overlay manifesti](../analiz/native-ui-candidate/v4/manifest.json), [görsel ölçüm ve adresler](../analiz/native-ui-port-v4/visual-audit.md). V4, v3'e göre üç dosya farkıdır: ELF'te sekiz yerel instruction ve iki PNG. V4 için firmware paketi üretilmez.

[V4 gerçek kare](../analiz/native-frame-rehost/v4-volume-35.png), [aynı koordinatların önce/sonra karşılaştırması](../analiz/native-ui-port-v4/volume-before-after.png), [v4 ses100](../analiz/native-frame-rehost/v4-volume-100.png), [mute](../analiz/native-frame-rehost/v4-volume-35-mute.png), [rakam123](../analiz/native-frame-rehost/v4-numeric-123.png).

## Bu aşamanın doğrulaması

| Kontrol | Ölçülen sonuç |
|---|---|
| Native RefreshVolumeUI senaryoları | Orijinal/v3/v4 toplam57/57 döndü; 0/1/35/100/150, mute, ARC modları ve tuş girdileri |
| Native durum testleri | 6/6; v4 tipografi değişikliği ses/ARC durumlarını değiştirmedi |
| Native çizim/metin testleri | 10/10; değişmeyen MUF komutları, kaynak pikselleri, yerleşim, font, 100 sınırı ve hash ret kontrolleri |
| V4 overlay testleri | 7/7; 22 dosya, v3'e göre3 fark, sekiz instruction allowlist, font/ikon format ve bozulma reddi |
| Yerel HTTP görüntüleyici | 3/3; gerçek PNG, parametre/host/origin/dosya sınırları |
| Gerçek görüntüleyici JavaScript'i | 3/3; hızlı tuşlar,0/100 sınırları ve eski istek hatası sırasında son girdinin korunması |
| Tarayıcı yürütmesi | v4 varsayılan; ses35→36, mute aç/kapa,130 artışla100 ve130 azalışla0, rakam123; her birinde1920px görüntü ve boş hata alanı |
| Bağımsız inceleme | İlk aşamadaki orijinal1px border ve eski istek hatası bulguları kapatıldı; v4 incelemesinde açık P1/P2 bulgu yok |

Toplam29 ilgili otomatik test geçti. Bu sayıya önceki18 laboratuvar sözleşme testi eklenerek UI cihaz testi yapılmış gibi sunulmaz. V3 ses35 karesinde639 benzersiz MUF komutu (212+187+17+157+66) ve311 Refresh komutu yürütüldü; v4 aynı seçilmiş kod yollarını kullanır. Bu, fonksiyonların bütün dallarının çözüldüğü anlamına gelmez.

Kesintiden sonra v4 çıktıları ve renderer kaynağındaki tamamen sıfırlanmış dosyalar doğrulamada reddedildi; v4 doğrulanmış orijinallerden yeniden üretildi, renderer kendi başarılı yerel patch kayıtlarından kurtarıldı. Kurtarma raporları: [v4 kaynakları](../analiz/native-ui-candidate/v4/interruption-recovery.json), [renderer](../analiz/native-frame-rehost/source-recovery.json). Orijinal ve v3 kaynak hashleri korunur.

## Tam uygulamanın kalan açılış engeli

İzole QEMU başlangıcında `/sys/class/ubi` kapısı özel sentetik topolojiyle geçildi. MPOOL adı ve boyut bilgileri okunduktan sonra native kod `/dev/shm/ubi0_0` açmaya ulaştı. Bu dosya bulunmadığı için `UBI_ReadDataOffset 0x2cb86ef4` içinde `open 0x2cb86fa0 → ENOENT → raise(6) 0x2cb87094` yoluyla durdu. Özgün ve v3 ELF aynı erken kapıda durur; 112 `.so` yolu açılır, ioctl sayısı sıfır, UI başlamaz.

Burada ek dört fonksiyonun 1584 bayt/396 komut statik analizi yapıldı. [Aşama sonuçları](../analiz/emulation-lab/topology-phase-results.json), [adresli depolama sınırı](../analiz/emulation-lab/ubi-memory-boundary-static.json), [tekrar çalıştırma](../analiz/emulation-lab/README.md). Laboratuvar sözleşme testleri 18/18, izolasyon kontrolleri 12/12 geçti.

## Kalan araştırma

- `/dev/shm/ubi0_0` hacmini özgün açılışta hazırlayan kod ve beklenen veri düzeni: tam uygulama depolama başlangıcını doğru modellemek için.
- Widget kurucuları, ProgressBar Update, görünürlük ve event döngüsü: elle hazırlanan test nesnelerinin yerine native yaşam döngüsünü çalıştırmak için.
- DirectFB font metrikleri/rasterizer ve grafik arka ucu: mevcut yazılım yüzeyi ile cihazın gerçek çizim farkını ölçmek için.
- Menü/kanal listesi/bilgi bandı ve kumanda handler'ları: bu aşamada yalnız ses ve rakam yüzeyleri çizilir.
- Tuner, VDEC ve video-plane/GOP: canlı TV görüntüsü için ayrıca gerekir; yalnız Linux veya MIPS CPU emülasyonu bunları sağlamaz.

Analiz envanterinin 226 modülü yeniden tamamlanmış sayılmaz. Bu aşama iki UI modülünde altı seçilmiş yürütme girişini, ayrı depolama modülündeki dört odaklı statik fonksiyonu derinleştirir; çözülemeyen servis/surface sınırları callback listelerinde açıkça durur.
