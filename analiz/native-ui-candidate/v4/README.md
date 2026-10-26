# Native ses paneli görsel düzeltmesi v4

24 Ekim 2026. Ayrı çevrimdışı kaynak kopyasıdır; firmware yeniden paketlenmedi, TV'ye yazılmadı.

V3'ün 22 dosyası korunarak yalnız `dvbt_board` ve ses ikonları 680/682 değiştirildi. Num, global renk/font/image tabloları ve font dosyaları v3 ile aynıdır.

- Sayı fontu: `VolumeControlFrame::OnCreate 0xfb9780` içinde `0xfbbe18/28/38/48` adreslerindeki dört `addiu v0,zero,0x4ae` komutu `0x4af` olur. Bu mevcut Image_res girdisi `../rc/font/Lucida Sans Bold.ttf` dosyasına bağlıdır. Boyut36 kalır; `100` yaklaşık69px olup76px widget'a sığar. Ölçüm host FreeType ölçümüdür; hedef DirectFB font metrikleri henüz cihazda gözlenmedi.
- Sayı rengi: `0xfbbc30/50/70/90` adreslerindeki dört yerel `RcGetColor` argümanı `0x25` yerine `0` olur; sayı `#212121` görünür. Diğer widget renkleri değiştirilmez.
- Hoparlör ve mute ikonları: aynı onaylı SVG sembolleri, kaynak içinde54px yerine80px alana çizilir.30px native widget'ta hoparlörün yaklaşık15px olan görünür genişliği21px'i aşar.100×100/100×99 boyut, P8 PNG türü ve özgün alfa yeteneği korunur.

Yeni ELF SHA256: `62fd931e69eabae725d7b1938c91cf2ae52e46444a0e23794ef9bcd737c6eaf4`.

Manifest düzenlenerek çıktı doğrulanamaz: `verified_records()` ELF/Num'u hash sabitli özgün dosyalardan yeniden hesaplar, diğer dosyaları doğrulanmış v3 ile karşılaştırır ve iki yeni ikon için kod içindeki SHA sabitlerini kullanır. `verified_records(rebuild_icons=True)` ikonları da yerel Chrome ile tekrar rasterize eder. Orijinal font ve onaylı SVG girdileri ayrıca sabittir.

```powershell
python scripts/build_native_ui_v4.py
python -m unittest discover -s scripts -p test_native_ui_v4.py -v
```

İlk yarım kalan çalışmanın25 çıktı dosyası tamamen NUL içeriyordu. Yalnız tam olarak bilinen, tamamen sıfır içerikli v4 çıktıları güvenlik kontrollerinden sonra yeniden üretildi. Önceki boyut/hash kayıtları `interruption-recovery.json` içindedir. Orijinal veya v3 dosyası onarılmadı/değiştirilmedi. Yeni yazımlar flush/fsync ve diskten geri okuma ile denetlenir; geçerli veya bilinmeyen dosyalar kurtarma işlemiyle üzerine yazılmaz.

Bu kapsam menünün diğer fontlarını/ikonlarını, tam uygulama açılışını, animasyonu veya TV piksel eşliğini doğrulamaz. Gerçek MIPS çiziminden üretilen kareler ayrı native frame rehost raporundadır.
