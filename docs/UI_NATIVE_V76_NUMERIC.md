# V7.6 native kanal girişi: eşleşmeyen numara ve mavi sayaç

26 Ekim 2026. Bu kayıt yalnız yeni sayısal kanal girişi yardımcılarını kapsar; paket ve sessiz rozetinin birleşik durumu ana V7.6 raporundadır. Kaynak/orijinal firmware ve önceki V7.5 dosyaları değişmez. Fiziksel TV testi yapılmadı.

`GetProgramSelInfo` başarı1 döndürmediğinde mevcut numaranın altında **Kayıtlı kanal yok** gösterilir. Yönetici bulunamaması, route uyuşmazlığı veya ad servisindeki hata aynı şey değildir: bu durumlarda önceki ad temizlenir. `01` gibi baştaki sıfırlar ve gerçek hedef kanal adı V7.5 yoluyla korunur. Yazı UTF-8 sabitinin yerel `std::string::operator=(const char*)` çağrısıyla atanmasıdır; yeni MString oluşturulur, widget metni sahipli kopyalar, geçici nesne yıkılır. Stack literal tamponu24 baytla sınırlıdır. DejaVu Sans26 yerel font ölçümünde metin211px olup254px alanına sığar; host font ölçümü fiziksel DirectFB metin çiziminin kanıtı değildir.

Yeni mavi çizgi `AbsContainer` ID4, kök `frame+0x180` altında `[1566,266,254,4]` alanındadır. Mevcut kart `[1538,64,310,224]` içinde kalır; metin `[1566,206,254,38]` sonundan22px boşluk vardır. Çizgi rengi `0xff0082d4`. Ad etiketi ID3'ün tahsisi0x250→0x258 olur; yalnız yeni ayrılan kuyruğundaki+0x250/+0x254 alanları kalan/toplam kozmetik süreyi tutar. Eski frame alanlarına yeni pointer yazılmaz. Native constructor/parent AddChild sahipliği korunur.

Orijinal kanal değiştirme zamanlayıcıları **aynen ilk çağrı olarak** çalışır:1–3 rakam için3000ms/ID0/mode0,4 rakam için2000ms/ID1/mode0. Bunların periyodu veya tuning handler'ı değiştirilmez. Ardından ayrı ID2/mode0 zamanlayıcısı50ms aralıkla yalnız çizgiyi günceller. Yeni rakam önceki ID2'yi iptal eder, çizgiyi tam genişliğe ve süreyi ilgili2/3s değerine döndürür. Kalan her kozmetik tick50 azalır; genişlik `remaining*254/total`,0..254. Grafik olayları gecikirse çizgi görsel olarak geriden gelebilir; orijinal kanal değişme süresi bundan etkilenmez.

`OnTimer` girişindeki GP kuran ilk12 bayt yeni dispatch helper'a atlar. Timer ID'si gerçek assembly'deki a2'den okunur. ID2 çizim dalına gider; ID0/1 önce kozmetik ID2'yi iptal edip a0..a3/RA/SP/callee-saved register'ları geri yükleyerek orijinal `OnTimer+12` noktasına döner. T9 orijinal entry0x8968d8, GP0x10cc310 olarak kurulur. Bilinmeyen ID'ler orijinal handler'a aynen iletilir. MEvtHandle yıkıcısının ilk KillTimer() çağrısı tüm handle timer'larını temizler.

Çizgi küçülmeden önce eski dikdörtgen invalidate edilir. Native sanal+0x24 MoveRect, SetRect ve MoveXY üzerinden eski yüzeyi temizler/bırakır; ardından yalnız310×224 kanal kartı invalidate edilir.1920×312 kökün tamamı her tick redraw edilmez. Fiziksel MIPS performansı henüz ölçülmedi.

| Yardımcı | Adres | Bayt |
|---|---|---:|
| CREATE | 0x01160100 | 884 |
| UPDATE | 0x01160800 | 872 |
| START_TIMER | 0x01161000 | 500 |
| TICK_TIMER | 0x01161400 | 612 |

15 hook sözcüğü eski beklenen değerleriyle kontrol edilir. Yeni ELF RX segmentindeki4 yardımcıya4 FDE eklenir; önceki6741 indeks kaydı korunur, toplam6745 olur. Yerleşim64KiB sınırı altında kalır. CFI, harici çağrı noktalarında CFA160 ve saved GP/RA/callee-saved konumlarıyla statik olarak sınanır. LSDA cleanup eklenmez; sonraki native allocation istisnasında geçici kaynak sızıntısı sınırı V7.5'teki gibi sürer.

Doğrulama: **7 native yardımcı testi** ve **4 ELF/CFI testi** geçti. Tam2s ve3s çizgi tick'leri, hızlı yeniden giriş, orijinal tuning timer'ının bağımsız kalması, gerçek UTF-8 literal byte'ları, eşleşmeme/servis hata ayrımı, isim ömürleri, GP/argüman register zehirleme, eksik widget ve nothrow null yolları sınandı. Callback'ler kontrollü modeldir; tüm firmware uygulaması, tuner veya TV timer manager süreci çalıştırılmadı. Pakete kurulu hook ve önizleme kontrolleri ana raporda ayrıca sayılır, bu testlerle birleştirilerek şişirilmez.

Kanıtlar:

- [Native kod ve tam hook listesi](../scripts/native_ui_v76_name.py)
- [4 yardımcı/FDE yerleştiricisi](../scripts/native_ui_v76_elf.py)
- [Yardımcı testleri](../analiz/native-ui-v76/native-name/bounded-tests.json)
- [ELF yerleşimi](../analiz/native-ui-v76/native-name/elf-placement.json)
- [Adresli kaynak/ABI/font ölçüm kaydı](../analiz/native-ui-v76/native-name/helper-proof.json)
- [Üretilmiş MIPS disassembly](../analiz/native-ui-v76/native-name/helper-disassembly.txt)
- [Orijinal TenKeyHandle](../analiz/native/ui-four/channels/number-helpers-v1/0089552c.c)
- [Orijinal OnTimer](../analiz/native/ui-four/channels/numeric-v1/008968d8.json)
- [Orijinal AddTimer](../analiz/native/ui-deep/muf-core35/2e24c034.c)
- [Native50ms periyodik animasyon örneği](../analiz/native/ui-deep/muf-core35/2e259b4c.c)

Doğrudan statik MIPS/Ghidra ve sınırlı Unicorn incelemesidir; REA Evidence veya fiziksel TV başarısı olarak sunulmaz. Kullanılan beceri `reverse-engineer-anything`.
