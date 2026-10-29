# Gerçek parser oluşturma yolları — 27 Ekim 2026

Bu dar devam aşamasında **3 modülde 5 fonksiyon incelendi: 3/3 seçilmiş decompile tamamlandı, 5 tam gövdenin orijinal ELF assembly'si saklandı**. Son iki kısa gövde yalnız assembly ile incelendi. Kaynak hash'leri [results.json](results.json), sorgu bağlamları `dvb/` ve `customer/` altındadır. Firmware çalıştırılmadı; Ghidra salt okunur proje sorguları doğrudan statik kanıttır, REA Evidence değildir. Yeni cihaz veya emülasyon testi yoktur.

İncelenen oluşturma yolları eski temel sınıflandırıcıyı seçen koşullu fabrika kullanmıyor. **Customer parser doğrudan oluşturuluyor.** Bunun fiziksel TV'deki nesnenin çalışma anı izi olmadığı ayrımı korunmalıdır.

## Oluşturma ve bağlantılar

- `libmsrv_dvb.so`, `_DoInit_EpgAndCmdbAndSiParser(0x2d4d32e0)`: parser üyesi `player+0xfc` doluysa tekrar oluşturma yapılmaz. Boşsa `0x2d4d34a0` çağrısı `0xd3920` bayt ayırır. `0x2d4d34b4` GOT yükü `0x2d5db52c` üzerinden gerçek CustomerC1 importunu alır; **jalr `0x2d4d34b8`** yeni nesneyi A0 ile verir. Sonuç **`0x2d4d34c8`** adresinde `player+0xfc` alanına yazılır. Başarısız ayırma abort/assert yoluna gider; temel parser'a geri dönüş yoktur. Ardından parser vtable+8 Init ve +0x20 SIMonitorNotify kaydı kullanılır. Kaynak: [C](dvb/2d4d32e0.c), [assembly](dvb-0x2d4d32e0.asm.txt).
- `EnableVideoOut(0x2d4d3990)`: etkinlik/demux/monitor hazırlığı sonrasında `player+0xfc==0` ise aynı boyutta nesne ayırır (**`0x2d4d3f3c`**), aynı CustomerC1 GOT importunu **`0x2d4d3f54`** adresinde çağırır; nesneyi **`0x2d4d3f64`** ile aynı üyeye kaydeder. Doluyken mevcut parser korunur. Burada da base/customer/4K flag seçimi yoktur. Kaynak: [C](dvb/2d4d3990.c), [assembly](dvb-0x2d4d3990.asm.txt).
- `libmsrv_dvb_customer.so`, **CustomerC1 `0x2e1a7c44`**: önce temel C2 yapıcısını `0x2e1a7c78` çağrısında çalıştırır. `0x2e1a7c8c` GOT yükü, `0x2e1e3248` slotundaki vtable sembolü `0x2e1e1418` değerini alır; `0x2e1a7c98` buna 8 ekler; **`0x2e1a7cb8`** doğrudan `*this=0x2e1e1420` vptr'sini yazar. Dolayısıyla yalnız Customer sembolünün bulunması değil, nesnenin Customer sanal tablosunu alması da kanıtlıdır. Sonra ResetInfo/ResetStatus/InitThreads çağrıları vardır; InitThreads başarısızlığı hata bayrağına gider. Kaynak: [C](customer/2e1a7c44.c), [assembly](customer-0x2e1a7c44.asm.txt).

Önceki [vtable relocation kanıtı](../tuner/customer-vtable-bindings.json) ile birleşince bu nesnenin **+0x1c0** slotu Customer `_UpdateServiceType(0x2e192540)` olur; HEVC service_type `0x1f` bu gövdede TV1'e eşlenir. **+0x2bc** slotu Customer `_IsSpecificSupport(0x2e19784c)` olur; [önceki kapı analizi](../tuner/gates/gate-proof.json) satellite mode2'de `0x1f` kabulünü gösterir. Eski base sınıflandırıcının `0x1f` desteklememesi, bu oluşturma yollarında Customer yerine base kullanıldığının kanıtı değildir.

## Uydu taramasına aktarılan nesne aynı mı?

Yalnız oynatma yapıcısından bütün taramalar için sonuç çıkarılmadı; ayrıca gerçek uydu tarama başlatma bağlantısı kontrol edildi:

`libmsrv_dvbs_customer.so` içinde **`MSrv_DTV_Player_DVBS_Customer::DoScanInit(0x2e9623a8)`**, `0x2e96242c` adresinde **aynı player+0xfc parser üyesini** yükler. `0x2e96243c` bunu çağrı stack argümanı **+0x14** alanına yazar. `0x2e96245c` scanner vtable+0x12c'ye çağrı yapar. Gerçek Customer scan vtable kaydı **`0x2e99d3b4` → `0x2e970748`** ile `SetInitData` hedefini verir. Bu fonksiyon stack'i 0x20 küçülttüğü için **`0x2e970764`** adresindeki `lw t0,0x34(sp)` aynı parser argümanını alır; **`0x2e970798`** adresinde **scanner+0x134** alanına saklar. Dolayısıyla bu tarama başlatma yolu, player tarafından sağlanan aynı Customer parser nesnesini kullanmak üzere kurulur; yeni base parser oluşturmaz. [DoScanInit assembly](satellite-0x2e9623a8.asm.txt), [SetInitData assembly](satellite-0x2e970748.asm.txt).

Üç modülün GOT yapıcı envanteri de saklandı: `libmsrv_dvb.so` CustomerC1 importuna; `libmsrv_dvb_customer.so` baseC2 importuna sahiptir; `libmsrv_dvbs_customer.so` parser C1/C2 importu taşımaz. Sonuncusu tek başına başka fabrika olmadığının kanıtı sayılmadı; somut player+fc→scanner+134 aktarımı esas alındı. Bütün tarama modlarının canlı cihazda bu yoldan geçtiği iddia edilmedi.

Dar doğrulama envanteri: **6 seçilmiş çağrı kenarı** adresleriyle `results.json` içindedir (iki ayırıcı, iki CustomerC1, bir baseC2, bir scanner SetInitData). Bunlar tüm çağrı grafiği sayısı değildir. Kod genelinde iki CustomerC1 GOT çağrısı ve `_DoInitBackgroundModules(0x2d4d4294)` içinden iki EPG/SI init GOT yükü bulundu; son ikisi yalnız çağrı adayı olarak tutuldu, yeni gövde/decompile sayısına eklenmedi.

## Sınırlar / takip

1. Önceden dolu `player+0xfc` nesnesinin tüm olası yazıcıları ve canlı TV vptr'si bu dar kapsamda izlenmedi. Kod yollarının seçimi doğrulandı, cihaz çalışma anı seçimi ölçülmedi.
2. Player vtable **+0x710** operatör değişkeni, **+0x8c8** ülke hazırlığı, **+0x840** sonraki başlatma bağlantıları için somut hedefler bu aşamada çözülmedi. Bunlar üç açık takip bağlantısıdır; tüm dolaylı çağrıların eksiksiz sayımı değildir. İncelenen fabrika kodlarında hiçbirinin dönüşü Customer yerine base C1 seçmez.
3. SDT/PMT ve tarama modunun canlı ayarları, RF kilidi, yayın sinyali ve gerçekten alınan service_type/stream_type bilinmiyor. Bu nedenle bulgu "4K kanalı fiziksel TV'de bulur/çözer" sonucu vermez; base-parser-seçilmesi hipotezini incelenen oluşturma yollarında desteklemez.

Yeniden üretme: `python -X utf8 analiz/native-4k/parser-factory/inspect_factory.py`. Bu yalnız yerel dosyaları okur, assembly/JSON kanıtlarını yeniden yazar; gömülü program, init veya update komutu çalıştırmaz.
