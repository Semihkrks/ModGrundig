# CONFIG özellik incelemesi — 27 Ekim 2026

Kapsam: 23 paket dosyası, 287 build makrosu (282 değerli/5 yalın tanım), 235 seçilmiş INI kaydı, 15 medya dynscaling profili; önceki UI analizinden 14 adresli özellik kaydı yeniden kullanıldı. Dört temel parse/doğrulama kontrolü geçti. Yeni binary decompile veya cihaz çalıştırması yapılmadı. Kaynaklar, hashler ve sayaçlar `manifest.json`; tekrar üretici `scripts/audit_4k_config.py`.

## 4K yayın → 1080p için bulunanlar

- Paket build kaydı `09_CONFIG/buildsetting:1`: `build_Marlon_120B_ROM_NAND_DVB.sh`. `09_CONFIG/Flags:1` içindeki `ENABLE_4K2K`, tüm 4K2K platform/demo varyantları, `ENABLE_PHOTO_4K2K`, `UHD_TEST_ENABLE`, `VP9_ENABLE`, `ENABLE_BACKEND`, `FRC_INSIDE_ENABLE`, `LOCAL_DIMMING` **0**. Bu, paketlenmiş build metadata'sıdır; dosyayı değiştirmenin derlenmiş kodu değiştirdiği kanıtlanmadı. Flag adı/durumu tek başına silikon codec limitini de ispatlamaz.
- Modelin başvurduğu `module/Customer_Module.ini:17–21` ile `MStar_Default_Module.ini:17–21`, `F_BACKEND_ENABLE_4K2K` ve ilgili backend seçeneklerini ayrıca **0** tanımlar. CONFIG'te doğrulanmış, kapalı bir UHD→FHD yayın dönüştürme anahtarı bulunmadı. Decode edilemeyen akışın panel ölçekleyicisine ulaşacağı varsayılamaz; decoder/tuner araştırması ayrı yürütülüyor.
- `Flags:1` içinde `ENABLE_DYNSCALING=1` olmasına rağmen `DYNAMIC_SCALING_ENABLE=0`, `H_LINEAR_SCALING_ENABLE=0`, `H_PRESCALING_FOR_BW=0`. Bunlar farklı adlandırılmış mekanizmalardır; biri diğerinin veya UHD decode'un eş anlamlısı sayılmadı. `MM/mm_cfg.ini:159` app3/HbbTV için dynscaling1 içerirken build kaydında `HBBTV_ENABLE=0`; app5:198 ve app8:239 ise0. Toplam15 profil, medya ailesi genel seçeneklerinin pakette kalabildiğini gösterir; aktif uygulama kanıtı değildir.

## Varsayılan seçim ve aktif cihaz ayrımı

- `sys.ini:2` → `/config/model/Customer_1.ini`; `sys.ini:14` SPI project-ID seçimini FALSE tanımlar. `Customer_1.ini:15` → FullHD_CMO216_H1L01; o panel dosyası:57/58 **1920×1080**, :136/137 OSD1920×1080. `panel/Beko_Panel.ini:14/15` de1920×1080. Bunlar paket varsayılanlarıdır; fiziksel cihazın canlı panel/factory parametreleri okunmadı. `BEKO_MULTIPANEL_TYPE=1` bulunduğu için varsayılan panel adından gerçek panel modeli çıkarılmadı.
- `Customer_1.ini:89/100/111/122` dört HDMI2.0/4K EDID aile dosyasına başvurur. Bu, RF HEVC decode veya aktif HDMI4K alımı kanıtı değildir. `DBPath/DBPath.ini:9–13` ve `DBPath_CSOT_4K540.ini` 4K router isimleri içerir; başvurulan `/config/3D/3D_convert_rule.ini` materyalize CONFIG ağacında yoktur. DACOUT_4K2KP_24.ini de aile tablosudur; seçildiği gösterilmedi. Kaynak isimleri aktif özellik listesi yapılmadı.
- `Customer_Module.ini:26` ARC port parametresi23, varsayılan modül:26 ise24. Bunlar port enum/config değerleridir; cihazın23/24 HDMI soketi olduğu anlamına gelmez. Modelin iki modül dosyasını göstermesi, olası default/customer ayrımını ortaya koyar; canlı yükleme önceliği doğrulanmadı.

## Bellek ve görüntü işleme sınırları

`mmap.ini:32` MIU0 toplamını256MiB; :446 VDEC framebuffer'ı30MiB; :302 XC ana framebuffer'ı18MiB; :383 DFB alanını60MiB tanımlar. Bu paket haritasıdır, canlı bellek ölçümü değildir. Bit derinliği, referans kare sayısı ve codec blokları bilinmeden bunlardan maksimum çözünürlük türetilmedi. :518 `TEST_4K_ALIGN`, :37 `CPU_ALIGN=0x1000` ile bellek haritası bağlamında hizalama ile ilgili görünür (statik yorum); 4K video desteği kanıtı değildir. PQConfig.ini DBC/DNR gibi resim işleme tabloları taşır; tek başına bunlar decode kapasitesi eklemez.

## İncelenmeye değer mevcut özellikler

- Build metadata: `PVR_ENABLE=1`, `CIPLUS_PVR_ENABLE=1`, `EPG_ENABLE=1`, `EPG_EED_ENABLE=1`, `CEC_ENABLE=1`, `ARC_ENABLE=1`, `SUBTITLE_ENABLE=1`, `TTX_ENABLE=1`, `ENABLE_DIVX=1`, `FLAC_ENABLE=1`, `OGG_ENABLE=1`. PVR/timeshift/EPG/CEC/medya zaten araştırılmış ailelerdir; bunlar yeni gizli açılım ilan edilmedi. USB, servis/akış ve lisans koşulları fiziksel olarak doğrulanmadı.
- Mevcut adresli örnekler: sürekli kayıt `GeneralSettingsFrame0xd01710`, callsite `0xd1978c`; kayıt `PVRFrame0xe703cc`, callsite `0xe83424`; ARC `SoundSettingsFrame0xee9afc`, callsite `0xef2ad4`; resim formatı `PictureSettingsFrame0xe28b14`. Bunlar önceki kanıtlardır, yeni davranış testleri değildir.
- `PIP_ENABLE=0`, `DUAL_TUNER=0`, `TWIN_TUNER=0`, `DUAL_XC_ENABLE=0`; Customer1:292–294 No_DualDecode tablo adlarını gösterir ve bu tablolar materyalize ağaçta yoktur. Sadece menü açmanın ikinci tuner/decode yaratacağı söylenemez.
- `NETWORK_CONFIG_ENABLE`, `WIFI_ENABLE`, `BLUETOOTH_ENABLE`, `HBBTV_ENABLE`, `NETFLIX_ENABLE`, `INTEL_WIDI_ENABLE`0: kullanıcının ağsız cihaz kapsamıyla uyumlu metadata. Oyun/low-latency için güvenilir bir CONFIG anahtarı bu sınırlı incelemede saptanmadı. `LOCAL_DIMMING=0`, MEMC kaynağı/başlığı ve `6m30_mode.ini:2 MEMC_ENABLE=DISABLE` donanım özelliğini açılabilir ilan etmek için yeterli değildir.

Çıktılar: `flags.json`, `selected-ini.json`, `model-resolution.json`, `dynscaling-profiles.json`, `memory-map.json`, `reused-feature-evidence.json`. Orijinal dosyalara/pakete/TV'ye yazılmadı; gömülü script/program çalıştırılmadı; anahtar, sertifika veya cihaz kimliği dosyaları açılmadı ve dış servise içerik gönderilmedi.
