# 4K video: gerçek init hataları ve açık bellek/DivX bağlantısı

30 Ekim 2026. `reverse-engineer-anything` ile salt okunur devam. **TRT Ultra HD için doğrulanmış bir native çözüm veya uygulanabilir kilit açma yaması bulunmadı.** Sekiz VDEC gövdesi mevcut Ghidra projesinden `-noanalysis -readOnly` ile alındı; 8/8 C çıktısı tamamlandı. Özgün ELF SHA-256: `215c0a86cdd9fd579655da4752e0a5c7822eb3210e768ca63b86859683c9c02b`. Donanım/register komutu veya çıkarılmış program çalıştırılmadı; firmware değiştirilmedi.

[Envanter ve gövde hash'leri](../analiz/native-4k/video-stage3/inventory.json), [sonuçlar](../analiz/native-4k/video-stage3/results.json), [10 seçilmiş adresli çağrı](../analiz/native-4k/video-stage3/selected-call-edges.json), [tam C/JSON sorgusu](../analiz/native-4k/video-stage3/ghidra-v1/summary.json). Çıktılar doğrudan Ghidra statik analizidir, REA Evidence değildir. Yeniden üretim: `python -B scripts/audit_4k_video_limits.py` kaynak kimliğini doğrulayıp sekiz tam gövdenin host disassembly'sini ve dar query selection'ını üretir; hedef kodunu çalıştırmaz.

## Tamamlanan dar kapsam

| Fonksiyon | VA | Bayt | Önceki kapsamla ilişki |
|---|---|---:|---|
| `MApi_VDEC_EX_V2_Init` | `0x2d655304` |8264| Önceki assembly tekrar incelendi; yeni C |
| `MDrv_HVD_EX_Init` | `0x2d602190` |3320| Önceki assembly tekrar incelendi; yeni C |
| `_HVD_EX_DemuxTS_ParseHEVCSPS` | `0x2d633a20` |2388| Önceki toplu decoder disassembly içinde vardı; yeni C |
| `HAL_VPU_EX_LoadCode` | `0x2d630388` |1324| Yeni odaklı gövde |
| `MDrv_HVD_EX_GetErrCode` | `0x2d5fb370` |512| Yeni odaklı gövde |
| `_VPU_EX_GetFrameBufferDefaultSize` | `0x2d62da30` |132| Yeni odaklı gövde; ELF sembol sınırı jump-table kollarını da içerir |
| `HAL_VPU_EX_Init` | `0x2d62ebf0` |276| Yeni odaklı gövde |
| `_HVD_EX_Init_` | `0x2d634374` |108| Yeni odaklı gövde |

Sekiz yeni C çıktısı, sekiz yeni keşfedilmiş fonksiyon olarak sayılmaz. HEVC→SDK→EVD enum aktarımı yeniden çözülmedi. Sınırlar özgün dynsym boyutlarından verildi; önceki Ghidra function inventory'sindeki V2 Init6984 ve framebuffer helper60 baytlık eksik gövdeler kullanılmadı.

## Gerçek init dönüşleri

V2 Init, `0x2d655e60`'ta `MDrv_HVD_EX_Init` çağırır ve yalnız sonuç **1** ise başarılı init yoluna devam eder. MMIO başarısızlığı ve diğer init hata yolları CMA buffer geri verme ve **0** dönüşü içerir. Böylece init sonucu yalnız metadata değildir; üst API'nin gerçek kararına girer.

Driver tarafında `0x2d602c34` BBU kimliğini alır; kimlik **-1** ise gerçek hata yolu `driver init failed due to no valid bbu id` mesajını ve0 dönüşünü içerir. Ardından `0x2d602cf8` `_HVD_EX_Init_` çağrısı **1** dönmeden stream aktif bayrakları yazılmaz. `_HVD_EX_Init_=0x2d634374`, global `0x2d73e804` baytı sıfırsa0 döner ve `STOP and Contact VDEC team` mesajını üretir; aksi halde `0x2d6343c8`'de `_HVD_EX_Rst(stream,0)` sonucunu döndürür. Bu globalin bütün yazıcıları ve hata bayrağının TRT'deki canlı değeri çözülmedi.

`HAL_VPU_EX_LoadCode` gerçek yükleme/kopyalama gövdesidir. Seçilen embedded kaynak `0x2d66c2dc`, boyut `0x9b3e0`; ayrıca dış kaynaklı kopya/decompress yolu bulunur. Yükleme sonrasında destination **byte6='R', byte7='2'** imzası denetlenir. Örneğin `0x2d63066c/0x2d63067c` sabit karşılaştırmaları ve `0x2d63068c` başarı bayrağı yazımı vardır; başarısızlık `0x2d6304e8` yolunda `pVPUHalContext+0xb1=0`, dönüş0 verir. Kaynak türü2 veya eksik dış kaynak/boyut da bu ret yoluna gidebilir. **Bu genel firmware-format kontrolüdür; UHD/Main10'a özgü bir ret değildir.** Bu çalışmada LoadCode→güç/reset→DTV init zincirinin bütün ara çağrıları kapatılmadı; imza kontrolü cihazdaki gerçek başarısızlığın nedeni sayılmaz.

`HAL_VPU_EX_Init` saat değerini normalize eder ve incelenen gövdede her iki saat yolunda1 döndürür. Bunu zorla başarı patch'i adayı yapacak bir hata koşulu bulunmadı.

## SPS'den bellek hesabı: güçlü aday, henüz ret kapısı değil

`_HVD_EX_DemuxTS_ParseHEVCSPS` start-code/NAL33 arar, EBSP→RBSP dönüşümünde1024 bayt sınırı uygular ve profil bölümündeki bitleri atlayarak boyut/sonraki UE alanlarını okur. Bu gövdede Main10 profilini adına/numarasına göre kategorik reddeden bir dal bulunmadı. Bit okuyucu yardımcılarının tamamı ayrıca decompile edilmedi; iki UE alanının bit-depth yorumu SPS sırasına dayanan statik yorumdur.

Boyutlar32'ye hizalanır. Alan ve referans çarpanı üzerinden hesaplanan bellek, iki UE değeri de0 değilse5/4 ile genişletilir; `0x2d634210`'da `HAL_HVD_EX_GetEVDHWBuffer()` sonucu eklenir. Önceki kesin bayt kanıtında bu helper2MiB döndürür. Gerçek C ifadesinin dört **host aritmetiği** örneği:

| Varsayılan SPS boyutu/derinliği | Hizalanmış boyut | Hesaplanan toplam |
|---|---|---:|
|1920×1080 /8bit|1920×1088|19,93MiB|
|1920×1080 /10bit yorumu|1920×1088|24,41MiB|
|3840×2160 /8bit|3840×2176|73,72MiB|
|3840×2160 /10bit yorumu|3840×2176|91,65MiB|

Bunlar seçilmiş MIPS gövdesinin yürütme testi veya TRT SPS ölçümü değildir.30MiB config profiline göre önemli fark vardır; fakat **bu çıktıyı gerçek DTV framebuffer tahsisiyle karşılaştırıp init'i reddeden tüketici henüz bulunmadı**. Parser'ın aktif DVB yolunda çağrıldığı da bu alt görevle kanıtlanmadı. Bu nedenle bellek büyütme patch'i veya “kesin RAM yetmiyor” sonucu çıkarılamaz. `_VPU_EX_GetFrameBufferDefaultSize` farklı format kodlarına göre30/108/160MiB gibi değerler döndürür; onun parametre enum'u burada DTV/VDEC codec enum'uyla eşitlenmedi.

## DivX-HEVC hata koşulu ve eksik tüketici

`MDrv_HVD_EX_GetErrCode=0x2d5fb370` önce stream-active byte'ını denetler; aktif değilse0 döner. Aktifse `HAL_HVD_EX_GetData(stream,0x1205)` ile firmware hata alanını okur. Bazı hata değerleri/normalizasyonlar dışında aşağıdaki koşullu yol bulunur:

- Selector **`0x122c`**, maske **`0x1`**: `bModeSupportDivXPlus` ile koşullu hata8 yolu.
- Aynı selector, maske **`0x2`**: boyut alımı başarılıysa genişlik×yükseklik **`0x1fe001`** eşiğiyle ayrılır; bu1920×1088+1'dir. Büyük boyutta `bModeSupportDivXHEVC_4K==0` ise hata8; küçük boyutta4K veya1080P destek globalinden biri yeterlidir.
- Seçilmiş hata sonuçlarında `0x2d5fb4b8` çağrısı **`HAL_HVD_EX_SetData(stream,0x1102,0)`** yapar; sonuç stream context `+0x138` alanına yazılır.

Bu fonksiyonda doğrudan input-source, DTV/file-mode veya profil karşılaştırması yoktur. DivX kapsamı global sembol isimleri ve firmware selector maskelerinden gelir; **mask0x2'nin sıradan TRT HEVC'de set olduğu kanıtlanmadı**. `0x1102` komutunun anlamı da bu alt görevde kesinleşmediği için kod “sadece yan etkisiz tanılama” olarak sunulmaz.

SDK/API sarmalayıcıları üzerinden bu getter'ın hangi tüketicide çağrıldığı ve AVMonitor'ün bu sonuçla ne yaptığı **açık bağlantıdır**. Bu açık uç, doğrulanmış bir HEVC lisans kilidi ya da güvenli hata8→0 patch'i olarak sunulamaz. Audio çalışmasındaki video/sync hazır olmadan mute2'nin kalabilmesi gözlemiyle birlikte, önce gerçek video başlangıç/sequence hata durumunu ayırmak gerekir.

## Sonraki somut test ve sınır

Mevcut native tanılama erişimi sağlandığında çalışan HD kanal ve TRT kaydı karşılaştırılmalı: aynı stream için SetVdecType/V2 Init dönüşü, BBU kimliği, ilk sequence/frame bilgisi, `GetData(0x1205)` ve `GetData(0x122c)` değerleri kaydedilmeli. Sıfır kare + init başarısızlığı ile başarılı init + SPS/bit-depth/DPB hatası ayrılmalıdır. Bunlar mevcut debug logundan veya kullanıcıca sağlanan gözlemden okunmalı; bu rapor herhangi bir bellek/register yazma komutu önermiyor.

Canlı değerler, TRT SPS'si, firmware kaynak/prefix sonucu ve aktif framebuffer tahsisi yoktur. Kullanıcının V7.8'de kanalı bulup ses/görüntü alamaması korunur; USB kayıt/oynatma testi yapılmış sayılmaz. Ana çalışmadaki host dönüştürme testi native TV decoder desteğinin kanıtı değildir. Yama üretilmedi; firmware build/TV testi yapılmadı.
