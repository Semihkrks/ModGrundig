# ModGrundig

Eski nesil Grundig, Beko ve Arçelik televizyonlarının firmware’ini çevrimdışı açmak ve bağlantılarını kanıtlarıyla anlamak için araştırma deposu. UI adayları ayrı kopyalarda üretilir; özgün paketler korunur. Kullanıcı 27 Ekim 2026'da V7.7'nin TV'de sorunsuz çalıştığını bildirdi; bu kapsamlı cihaz testi sayılmaz. V7.3 ses panelinde donma yaptığı için reddedilmişti. Güncel 4K araştırması ayrı tutulur; çalışan V7.7 değiştirilmez ve henüz doğrulanmış bir 4K kilit açma paketi yoktur.

İnceleme [Reverse Engineer Anything](https://github.com/morluto/rea) ile yürür. `rea/` bu depoda sabit commit’e bağlı bir alt depodur. REA’nın kendi kaynağı, README’si ve lisansı [morluto/rea](https://github.com/morluto/rea) üzerindedir.

`analiz/` araştırma notlarını, kanıt JSON’larını, açılmış bölümleri, iki dosya sistemi görünümünü ve firmware imajlarını içerir. Orijinal devir ZIP’i, devir görselleri, sertifika bölümü, PEM ve anahtar dosyaları repoda yoktur.

Lisans: [MIT](LICENSE). REA alt deposu kendi lisansına tabidir.

## Klonlama

```bash
git clone --recurse-submodules https://github.com/Semihkrks/ModGrundig.git
cd ModGrundig
git lfs pull
```

Git LFS, `analiz/ui-kod-cagrilari.json` ve `analiz/dosya-sistemleri-tam.tar` içindir. Alt depo gelmezse `git submodule update --init rea`.

## Nereden başlanır

- [Geliştirme öncelikleri: hızlı kanal, oyun/PC yolu, kırpmasız görüntü ve kullanılabilir özellik adayları](docs/GELISTIRME_ONCELIK_PLANI.md)

- [V7.9 test RAR'ı: seviyeli ses ikonları, yarım kenar boşluğu ve gerçek native kontroller](docs/UI_NATIVE_V79_SEVIYELI_SES.md)
- [V7.10: native SEMIH menü logosu ve hız ayarlarının doğrulanan durumu](docs/UI_NATIVE_V710_SEMIH_VE_HIZ.md)
- [Hızlı kanal geçişinin gerçek ayarı ve AV senkronizasyon yolu](docs/FAST_CHANNEL_ANALIZ.md)
- [Hızlı açılış: mevcut STR yolu ve eksik etkinleştirme bağlantısı](docs/FAST_BOOT_ANALIZ.md)

- [V7.8 veri test RAR'ı: V7.7 korunur, yalnız varsayılan TRT4K transponderi eklenir; decoder kilidi değildir](docs/UI_NATIVE_V78_TRANSPONDER.md)

- [4K kanal araştırması: eksik TRT transponderi, kabul edilen HEVC türü ve decoder sınırları](docs/4K_YAYIN_VE_GIZLI_OZELLIKLER.md)

- [V7.7: panelde mute düzeltmesi, ses0 sağ üst rozeti ve çizgisiz kanal girişi](docs/UI_NATIVE_V77_PAKET.md)

- [V7.6: buyuk sessiz rozeti, gercek kayitsiz kanal mesaji ve native sayac](docs/UI_NATIVE_V76_PAKET.md)

- [V7.5 test adayı: gerçek kanal adı bağlantısı; GP düzeltmesi, gri bar ve beyaz rozet korunur](docs/UI_NATIVE_V75_KANAL_ADI.md)
- [V7.4: V7.3 donma kusuru, V7.1 tabanlı düzeltme, gri bar ve sağ üst beyaz rozet](docs/UI_NATIVE_V74_GP_DUZELTMESI.md)
- [Reddedilen V7.3: cihaz donma geri bildirimi; yüklemeyin](docs/UI_NATIVE_V73_GRI_SESSIZ.md)
- [V7.2 ara revizyon: native sessiz seçim kodu; ikon tasarımı sonradan düzeltildi](docs/UI_NATIVE_V72_SESSIZ_DURUMU.md)
- [V7.1: TV'de görülen köşe, kenar mesafesi ve numara kırpılması düzeltmeleri](docs/UI_NATIVE_V71_TV_DUZELTMELERI.md)
- [Önceki V7 TV adayı: orijinal menüler, yalnız ses ve numara ekranı](docs/UI_NATIVE_V7_TV_ADAYI.md)
- [İptal edilen V8 menü deneyi: tarihsel kanıtlar](docs/UI_NATIVE_ADAY_V8.md)
- [Güncel v7: Chrome menü/ayar önizlemesi, kanal listesi, native sayı boşluğu ve gerçek test sınırları](docs/UI_MENU_AYARLAR_V7.md)
- [Güncel native UI v5: kompakt ses kapsülü, büyük mute ikonu ve kavisli kanal numarası](docs/UI_NATIVE_ADAY_V5.md)
- [Native çizim kodundan görüntü: çalışan test ekranı, font/ikon düzeltmesi ve kalan TV açılış engeli](docs/NATIVE_GORUNTU_CALISTIRMA.md)
- [Güncel native aday v3 ve gerçek MIPS çalıştırma laboratuvarı](docs/UI_NATIVE_ADAY_V3.md)
- [TV emülasyonu: kurulan ortam, gerçek başlangıç engeli ve sınırlar](docs/TV_EMULASYON_ARASTIRMASI.md)
- [Gerçek firmware UI adayı v2: değişiklikler, dosya/paket doğrulamaları ve TV'de doğrulanmayan kapsam](docs/UI_NATIVE_ADAY_V2.md)
- [Güncel modern TV test ortamı:24menü/156satır, kaynak kanıtları ve özellikler](docs/UI_OZELLIK_KAPSAMI.md)

- [UI modernleştirme: çalışan önizleme, native kaynak adayları ve test durumu](docs/UI_UYGULAMA_DURUMU.md)
- [Sistem bilgi tabanı ve modül indeksi](docs/bilgi-tabani/README.md)
- [Dört büyük UI fonksiyonu ve tasarıma geçiş durumu](docs/bilgi-tabani/UI_DORT_BUYUK_FONKSIYON.md)
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
| `analiz/` | Kanıt JSON’ları, açılmış bölümler, dosya sistemi görünümleri, firmware imajları, REA/Ghidra notları |
| `tools/` | Yerel araç sarmalayıcıları |
| `rea/` | Sabitlenmiş [REA](https://github.com/morluto/rea) alt deposu |

Yerel Linux ağacı, Ghidra veritabanı ve araç kurulumları analiz makinesinde kalır. Yollar [kurulum notunda](docs/KURULUM.md).

`analiz/dosya-sistemleri/` ilk NTFS denemesidir ve özel dosyalar yüzünden repoda yoktur. `analiz/firmware-orijinal/` ilk RAR denemesidir; tamamlanmış kaynak diye kullanılmamalıdır. Güncel okuma görünümü `analiz/dosya-sistemleri-tam/`, doğrulanmış imaj `analiz/firmware-dogrulanmis/` altındadır.

## Kanıt kayıtları

`analiz/bolum-haritasi.json`, `dosya-envanteri.json`, `elf-envanteri.json`, `bagimliliklar.json`, `ui-kaynak-haritasi.json`, `sembol-baglantilari.json`, `modul-kategorileri.json` dosya incelemesinden üretilmiştir. Birleşik ilişki grafiği `analiz/baglanti-grafi.json` içindedir.

22 Ekim 2026 düzeltmesi: güncel ELF/sembol/bağımlılık envanteri **`analiz/envanter-v2/`** altındadır. Önceki readelf parser’ı `[MIPS PLT]` alanını section/name’e kaydırıyordu. Eski kök JSON’lar önceki sorguların hash kaydı için durur. UI kod çağrı adayları `analiz/ui-kod-cagrilari.json`, bağımsız Ghidra karşılaştırması `analiz/ui-kod-cagrilari-dogrulama.json` içindedir.

İncelenen paket, kullanıcının sağladığı RAR’dır. Fiziksel televizyonun aktif firmware dump’ı olduğu kanıtlanmamıştır. PC analizi, cihazın aktif tema/kalibrasyonunu veya güvenli yeniden yüklemeyi kanıtlamaz.
