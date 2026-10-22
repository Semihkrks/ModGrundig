# Grundig firmware inceleme çalışma alanı

22 Ekim 2026. Öncelik: mevcut firmware'i açmak, özellikle UI bağlantılarını kanıtlarıyla öğrenmek. Menü ve ses animasyonları değiştirilmedi; TV'ye değişiklik yüklenmedi.

## Başlangıç dosyaları

- [Sistem tersine mühendislik bilgi tabanı ve 226 modül indeksi](docs/bilgi-tabani/README.md)
- [Genişletilmiş UI kod yapısı ve davranış kanıtları](docs/UI_KOD_YAPISI.md)
- [UI, menü ve ses paneli bağlantı haritası](docs/UI_HARITASI.md)
- [Tersine mühendislik bulguları ve kapsamı](docs/TERSINE_MUHENDISLIK.md)
- [Araç kurulumu ve tekrar çalıştırma](docs/KURULUM.md)
- [Kullanıcının proje devir notu](devir-paketi/Grundig_Firmware_Modlama_Proje_Ozeti.md)

## Dizinler

| Yol | İçerik |
|---|---|
| `Grundig_Tum_Proje_Devir_Paketi.zip` | Kullanıcının değiştirilmemiş orijinal paketi |
| `devir-paketi/` | Devir Markdown'ı, kaynak RAR/ZIP'ler, görseller |
| `rea/` | Tam Git klonu ve beş sabitlenmiş alt depo; çalışan global npm paketinden ayrı |
| `analiz/firmware-dogrulanmis/` | RAR bütünlük testi sonrası açılan BIN'ler ve paket dosyaları |
| `analiz/bolumler/` | 14 açılmış payload; CRC/hash/ofsetler `bolum-haritasi.json` içinde |
| `analiz/dosya-sistemleri-tam/` | Windows'ta okunabilir normal dosyalar; symlink/özel dosyalar burada uygulanmaz |
| `analiz/dosya-sistemleri-tam.tar` | Çıkarılmış Linux ağacının dosya ve symlink arşivi |
| `analiz/dosya-sistemleri-tam-metadata.json` | Windows görünümünde uygulanmayan link kayıtları dahil tar metaverisi |
| `analiz/ubifs-orijinal-metadata.json` | Orijinal inode metaverisi ve 380 özel cihaz node'u dahil 4.445 kayıt |
| `analiz/ic-arsivler/` | Dört fabrika verisi arşivinin açılımları |
| `analiz/kernel-mips-unpacked.bin` | MIPS kernel wrapper'ından açılan ham kernel verisi |
| `analiz/native/` | REA kabul/ret sonucu ve doğrudan Ghidra analizleri |
| `analiz/loglar/` | Başarılı/başarısız çıkarım ve analiz günlükleri |
| `scripts/` | Yalnız çevrimdışı veri işleyen yeniden çalıştırılabilir araştırma araçları |
| `tools/` | Yerel araç sarmalayıcıları, resmî hash'i doğrulanmış indirmeler |

Canonical Linux ağaç: `/home/semih/.local/share/grundig-analysis/full-v1/files` (Ubuntu WSL). Ghidra veritabanı: `/home/semih/grundig-analysis/ghidra-projects`. Ghidra/JDK Linux kurulumları: `/home/semih/.local/share/grundig-tools`.

`analiz/dosya-sistemleri/` ilk NTFS denemesidir; APP sırasında zaman aşımı oldu. `analiz/firmware-orijinal/` Windows tar'ın BIN'leri açamadığı ilk RAR denemesidir. Bu iki ağaç tamamlanmış kaynak diye kullanılmamalıdır.

## Kanıt kayıtları

`analiz/bolum-haritasi.json`, `dosya-envanteri.json`, `elf-envanteri.json`, `bagimliliklar.json`, `ui-kaynak-haritasi.json`, `sembol-baglantilari.json`, `modul-kategorileri.json` gerçek dosya incelemesinden üretilmiştir. Birleşik ilişki grafiği `analiz/baglanti-grafi.json` içindedir. Büyük ELF JSON'u tüm sembol/relocation kayıtlarını içerir; özet soruları için bütün dosyayı terminale basmak yerine filtrele.

22 Ekim düzeltmesi: ELF/sembol/bağımlılık envanterlerinin güncel sürümü **`analiz/envanter-v2/`** altındadır. Önceki readelf parser'ı `[MIPS PLT]` alanını section/name'e kaydırıyordu; parser ve MIPS örnekli self-test düzeltildi. Eski kök JSON'lar önceki sorguların hash/provenance kaydı için tutulur; güncel import/export sayıları için kullanılmamalıdır. UI kod çağrı adayları `analiz/ui-kod-cagrilari.json`, bağımsız Ghidra karşılaştırması `analiz/ui-kod-cagrilari-dogrulama.json` içindedir.

Mevcut RAR'ın Grundig 40 CLE 5745 AN ile yükleme uyumu kanıtlanmış değildir. PC analizi, cihazın aktif tema/kalibrasyonunu veya güvenli yeniden yüklemeyi kanıtlamaz. Konsept görselinde cihaz kimliği görülebilir; görselleri dışarı yayımlamadan önce incele.
