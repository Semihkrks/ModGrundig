# Marlon120B decoder araştırması — UHD yayını1080p gösterme

27 Ekim2026 devamı: [Aşama2 kayıtlı VIDEO_TYPE5→AVInfo7→SDK/VDEC/EVD yolunu kapattı](decoder-stage2/findings.md). Aşağıdaki VIDEO_TYPE dönüşüm boşluğu önceki aşamanın tarihsel durumudur; fiziksel UHD/Main10 sınırları hâlâ açıktır.

27 Ekim2026. Salt okunur yerel firmware incelemesi. Orijinaller/aday UI kodları değiştirilmedi; TV'ye yazılmadı. Çıkarılmış TV uygulaması, update script'i veya donanım komutu çalıştırılmadı. Yalnız belirtilen küçük, yan etkisiz MIPS fonksiyonları/codec switch blokları sentetik bellekle sınırlanmış Unicorn incelemesinde yürütüldü. Bu çıktı doğrudan statik assembly incelemesidir; REA Evidence veya cihaz gözlemi değildir.

**Sonuç:** Paket gerçek HEVC/EVD başlatma ve decode yolları içeriyor. Bunları yalnız ikon/string veya boş API olarak nitelemek doğru değil. Buna karşılık bu bulgular3840×2160/50Hz, HEVC Main10, bitrate ve gerçek yayın çözümünü kanıtlamaz. `ENABLE_4K2K=0`, bir capability API'sinin false sonucu veya30MiB bellek havuzu tek başına “ASIC4K çözemez” ya da “tek baytla açılır” hükmü için yeterli değil. Kanalın listede bulunmaması ayrı tarama/servis keşfi sorunudur; decoder incelemesi listeye ekleme başarısının yerine geçmez.

## Platform kanıtı

`09_CONFIG/buildsetting:1` hedefi `build_Marlon_120B_ROM_NAND_DVB.sh` olarak adlandırıyor. `libapiVDEC.so` içindeki derleme yolu `UTPA2-300.0.x/.../hal/marlon/hvd_v3/halHVD_EX.c` ve `mvd_v3/halMVD_EX.c` ailelerini gösteriyor. Bu **SDK/build hedefi** kanıtıdır; fiziksel SoC'nin tam pazarlama kodu veya silikon revizyonu okunmuş değildir. Bunlara dayanarak bir MSD parça numarası uydurulmadı.

Flags verisi `EVD_ENABLE=1`, `ENABLE_4K2K=0`, `ENABLE_PHOTO_4K2K=0`, `VP9_ENABLE=0` içeriyor. Paket çok modelli4K EDID/rota tabloları ve HEVC görselleri de içeriyor; bunların varlığı tek başına cihaz özelliği sayılmadı.

## Gerçek HEVC/EVD yolu

| Dosya / fonksiyon | Adres ve davranış | Kanıt düzeyi |
|---|---|---|
| libvdplayer `msAPI_VDPlayer_HWInit_HEVC` | `0x2db668ec`,1420bayt; `0x2db669a4/0x2db669b0` codec16'yı init parametresine yazar. `0x2db669cc` gerçek EX_GetFreeStream, `0x2db66bec` EX_Init çağrısı yapar. | Statik tam gövde, GOT sembol eşlemesi |
| libvdplayer `DecodeFrame_HEVC` | `0x2db66844`,168bayt; StepDisp/StepDecode ve hata dönüşleri vardır. | Statik tam gövde; boş return stub değil |
| VDEC `MApi_VDEC_EX_V2_Init` | `0x2d655304`,8264bayt; codec16 sınıflandırılır. `0x2d655cd4→0x2d6572b4` HVD mode alt bitlerini7 yapar. `0x2d655e60` gerçek MDrv_HVD_EX_Init çağrısıdır. | Statik gövde + codec16→7 switch'inin18 talimatlık sınanmış yolu |
| `MDrv_HVD_EX_Init` | `0x2d602190`,3320bayt; kind7 `0x2d602434→0x2d602ab8` ile backend2 yoluna gider. | Statik tam gövde |
| `HAL_HVD_EX_InitHW` | `0x2d618e0c`,1820bayt; kind7 için EVDInUsed yolunu seçer. `0x2d619008..0x2d61906c` gerçek RIU+C1604/C1700 register işlemleri içerir. | Statik tam gövde; register işlemleri **çalıştırılmadı** |
| `HAL_VPU_EX_EVDInUsed` | `0x2d62e624`,204bayt; backend kayıtlarını yürür, doluluk sonucu üretir. | Statik tam gövde |

`HAL_VPU_EX_IsEVDR2 0x2d62d5e0` bu build'de iki talimatla0 döndürür. Bu yalnız ilgili fonksiyonun döndürdüğü sabiti kanıtlar; tüm EVD'nin olmadığı anlamına gelmez. `HAL_HVD_EX_GetEVDHWBuffer 0x2d60fcf0` sabit0x200000 döndürür; bu adlandırılmış yardımcı değeri toplam UHD decoder belleğiyle karıştırılmadı.

## Capability ve piksel oranı tuzakları

`_MApi_VDEC_EX_V2_CheckCaps 0x2d648428` codec16 için destek output byte'ını0 bırakıyor. Driver pointer'ı0 ise dönüş0; mevcut kabul edilirse dönüş1 ve output yine0. İki sınanmış durumda da destek false. **Aynı binary'nin Init gövdesi codec16'yı açıkça EVD yoluna yönlendirdiği için**, bu capability sonucunu HEVC donanımı yok hükmüne çevirmek yanlış olur.

`HAL_HVD_EX_GetFrmRateIsSupported 0x2d60feb0`,16bit genişlik×yükseklik×32bit rate değerini64bit çarpar; `0x1dab370000 =127426560000` eşiğini uygular. Saf yardımcı testinde1920×1080×60000 ve1920×1088×60000 kabul,3840×2160×30000/50000/60000 ret,3840×2160×15000 kabul verdi. Sayısal rate argümanı burada ham değerdir; fps×1000 yorumunun aktif HEVC çağıranında ayrıca doğrulanması gerekir.

İlgili çağıran **`MDrv_HVD_EX_GetDispInfo 0x2d5ffd54`**: başarılı info yolunda `0x2d5ffe80` yardımcıyı çağırır, sonucu stream durumuna+0x13d yazıp **önceki s3 başarı sonucunu değiştirmeden döndürür**. Dolayısıyla eşik bu noktada bir destek/durum raporudur; doğrudan Init reddi değildir. Üst katmanın bu bayrağı hangi codec/akış koşullarında kullandığı henüz çözülmedi. Donanım üst çözünürlüğü/HEVC Main10 sınırı olarak sunulamaz.

## DVB wrapper ve bellek

`libMStarSDK.so:mapi_vdec::SetVdecType(DTV CODEC_TYPE,u8) 0x2cba8604`,1/2/3/7 parametrelerini ayırır. Enum7 `0x2cba869c→0x2cba8944` ile VDEC codec16 olur. Diğer5 değerini buraya doğrudan vererek HEVC açıldığı iddia edilmedi: PMT parser'ının VIDEO_TYPE5 ad alanından DTV enum7 veya genel init-param codec ad alanına geçiş **bu alt görevde henüz kanıtlanmadı**.

Bu wrapper CPU/framebuffer/bitstream alanlarını aynı MMAPInfo mekanizmasından alır. Adlar sırasıyla VA`0x2ccd02f8`, `0x2ccd030c`, `0x2ccd0348`'dedir. Framebuffer araması `0x2cba8778/0x2cba878c`; ilk wrapper gövdesinde çözünürlüğe göre yeni4K havuz seçimi görünmez. Legacy `MApi_VDEC_Init 0x2d662224` codec tablosu`0x2d72c688[16]` değerini16 tutar; `0x2d6622f4` EX_GetFreeStream ve `0x2d6623d0` EX_Init çağrılarıyla yukarıdaki EX/V2 yoluna bağlanır.

`09_CONFIG/mmap.ini` yapılandırması VDEC_CPU2MiB, VDEC_BITSTREAM4MiB, VDEC_FRAMEBUFFER30MiB ayırıyor. Bu bir derleme/config profili, cihazda gözlenmiş çalışma anı tahsisi değildir. UHD çözümleme için gereken referans kareler ve bit derinliği, ekrana küçültülmüş1080p görüntüden önce decoder belleğinde yer ister. Framebuffer sıkıştırması/DPB yerleşimi/mikrokod sınırları çözülmeden30MiB üzerinden kesin sonuç verilmedi; yalnız havuzu büyütmek de4K desteği kanıtı değildir.

## Ölçülebilir tamamlanan kapsam ve kalanlar

İki kaynak grubunda **21 seçilmiş fonksiyon gövdesi** adres ve gövde hash'iyle tutuldu; ek legacy Init ve yerel wrapper tablosu ayrı kayıtlandı. Yeni Ghidra decompile çalıştırılmadı. Bounded yürütme:2 capability vakası,6 saf piksel-oranı vakası ve1 codec16→7 switch vakası; toplam9 vaka geçti. Bunlar tam decoder/TV emülasyonu değildir.

Kalanlar: gerçek DVB VIDEO_TYPE5 dönüşümü, aktif UHD HEVC SPS/profile/Main10/bit-depth sınırları, VDEC mikrokodu ve DPB bellek düzeni, destek bayrağının üst katmanda etkisi, hedef yayınla gerçek EVD decoder hataları. Bunlar çözülmeden güvenilir bir HEVC4K “unlock patch”i tanımlanmış değildir. Root tarafından yürütülen kanal keşfi/frekans araştırması bundan ayrıdır; manuel doğru transponder denemesi listelenmeme ile sonradan decoder hatasını ayırabilir.

- [Yeniden üretilebilir salt okunur inceleme](decoder/inspect_decoder.py)
- [Capability ve aritmetik kanıtları](decoder/decoder-evidence.json)
- [HEVC init/EVD gövde zinciri ve switch kanıtı](decoder/codec-init-path.json)
- [DVB wrapper ve MMAP adları](decoder/dtv-wrapper-memory.json)
- [Decoder disassembly](decoder/decoder-disassembly.txt)

Beceri: `reverse-engineer-anything`; eski MIPS REA ABI sınırı korunur. Anahtar/sertifika/cihaz kimliği incelenmedi veya dış servise gönderilmedi. Web kaynağı kullanılmadı; yukarıdaki iddialar yalnız sağlanan yerel firmware dosyalarına dayanır.
