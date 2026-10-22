# ModGrundig

Eski nesil Grundig, Beko ve Arçelik televizyonlarının firmware’ini çevrimdışı açmak ve bağlantılarını kanıtlarıyla anlamak için araştırma deposu. Menü ve ses animasyonları değiştirilmedi. Televizyona yazılmadı.

İnceleme [Reverse Engineer Anything](https://github.com/morluto/rea) ile yürür. `rea/` bu depoda sabit commit’e bağlı bir alt depodur. REA’nın kendi kaynağı, README’si ve lisansı [morluto/rea](https://github.com/morluto/rea) üzerindedir.

Ham firmware, orijinal ZIP/RAR/BIN paketleri, çıkarılmış dosya sistemleri ve cihaz kimliği içerebilen görseller bu repoda yoktur. Onlar yerel analiz kaynağıdır. Burada araştırma notları, scriptler ve kanıt kayıtları durur.

Lisans: [MIT](LICENSE). REA alt deposu kendi lisansına tabidir.

## Klonlama

```bash
git clone --recurse-submodules https://github.com/Semihkrks/ModGrundig.git
cd ModGrundig
git lfs pull
```

Git LFS, büyük çağrı indeksi `analiz/ui-kod-cagrilari.json` içindir. Alt depo gelmezse `git submodule update --init rea`.

## Nereden başlanır

- [Sistem bilgi tabanı ve modül indeksi](docs/bilgi-tabani/README.md)
- [UI kod yapısı ve davranış kanıtları](docs/UI_KOD_YAPISI.md)
- [UI, menü ve ses paneli bağlantı haritası](docs/UI_HARITASI.md)
- [Tersine mühendislik bulguları ve kapsamı](docs/TERSINE_MUHENDISLIK.md)
- [Araç kurulumu ve tekrar çalıştırma](docs/KURULUM.md)
- [GitHub’da olan ve yerelde kalan ayrımı](docs/GITHUB_SENKRON.md)

## Dizinler

| Yol | İçerik |
|---|---|
| `docs/` | Bulgular, UI haritası, modül notları |
| `scripts/` | Yalnız çevrimdışı veri işleyen araştırma araçları |
| `analiz/` | Kanıt JSON’ları, envanterler, REA/Ghidra notları. Ham BIN ve dosya sistemi ağacı yok |
| `tools/` | Yerel araç sarmalayıcıları |
| `rea/` | Sabitlenmiş [REA](https://github.com/morluto/rea) alt deposu |

Yerel Linux ağacı, Ghidra veritabanı ve araç kurulumları analiz makinesinde kalır. Yollar [kurulum notunda](docs/KURULUM.md).

`analiz/dosya-sistemleri/` ilk NTFS denemesidir. `analiz/firmware-orijinal/` ilk RAR denemesidir. Bu iki ağaç tamamlanmış kaynak diye kullanılmamalıdır; ikisi de GitHub’da yoktur.

## Kanıt kayıtları

`analiz/bolum-haritasi.json`, `dosya-envanteri.json`, `elf-envanteri.json`, `bagimliliklar.json`, `ui-kaynak-haritasi.json`, `sembol-baglantilari.json`, `modul-kategorileri.json` dosya incelemesinden üretilmiştir. Birleşik ilişki grafiği `analiz/baglanti-grafi.json` içindedir.

22 Ekim 2026 düzeltmesi: güncel ELF/sembol/bağımlılık envanteri **`analiz/envanter-v2/`** altındadır. Önceki readelf parser’ı `[MIPS PLT]` alanını section/name’e kaydırıyordu. Eski kök JSON’lar önceki sorguların hash kaydı için durur. UI kod çağrı adayları `analiz/ui-kod-cagrilari.json`, bağımsız Ghidra karşılaştırması `analiz/ui-kod-cagrilari-dogrulama.json` içindedir.

İncelenen paket, kullanıcının sağladığı RAR’dır. Fiziksel televizyonun aktif firmware dump’ı olduğu kanıtlanmamıştır. PC analizi, cihazın aktif tema/kalibrasyonunu veya güvenli yeniden yüklemeyi kanıtlamaz.
