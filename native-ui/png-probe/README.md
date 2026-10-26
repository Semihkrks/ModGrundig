# Özgün libpng ile sınırlandırılmış MIPS denemesi

24 Ekim 2026. Bu test televizyon emülatörü veya TV ekran görüntüsü değildir.
Yeni yazılan küçük C harness, firmware'in **gerçek MIPS libpng 1.2.32,
zlib 1.2.8 ve glibc 2.8** kütüphanelerini QEMU kullanıcı modu altında çağırır.
`dvbt_board`, DirectFB, MUF, boot veya güncelleme komutları çalıştırılmaz.

İlk çalıştırma:

```powershell
wsl -d Ubuntu -- python3 /mnt/c/Users/Semih/Desktop/grundig/scripts/build_png_probe.py
```

Araç mevcut guest dizinini değiştirmeyi reddeder. Sabit girdi listesi dışında
program/PNG seçimi veya genel komut çalıştırma parametresi yoktur. Üç Ubuntu
paketi apt SHA-256 doğrulamasıyla ayrı dizine açılır; sistem kurulumu ve paket
scripti çalıştırılmaz. Yeni CRT + C kodu MIPS32r2/o32/little endian/hard-float
olarak derlenir; yalnız özgün loader ve kütüphanelere bağlanır.

`scripts/emulation_lab.py` içindeki bubblewrap izolasyon testi hedef koddan önce
başarılı olmak zorundadır. Guest kökü salt okunur; özel proc/dev/tmp, ayrı PID ve
ağ ad alanı, capabilities yok, CPU/RAM/zaman/dosya sınırları vardır. Anahtar,
sertifika, cihaz kimliği, donanım aygıtları veya host dosyaları guest'e kopyalanmaz.
Kaynakların ve kütüphanelerin sabit SHA değerleri değişirse test durur.

## Ölçülen sonuç

`analiz/native-png-probe/decode-result.json`: **3/3 geçti**, exit 0,
0,067 saniye. Üç kaynak da 69×620, palette color type 3, bit depth 4.

| Kaynak | Dört köşenin RGBA değeri | Merkez RGBA |
|---|---|---|
| Özgün bg674 | 10,10,10,255 | 10,10,10,255 |
| v2 beyaz bg674 | 245,245,245,255 | 245,245,245,255 |
| Yeni deneysel tRNS kapsül | 245,245,245,0 | 245,245,245,255 |

Deneysel PNG:
`analiz/native-png-probe/rounded-bg674-experimental.png`.
SHA-256: `db95b29b413e60c2e7d6a9de3497cecd417c3edf5dc3224820e8da250b32b7f6`.

Kapsülün alfa maskesi hedef 76×500 widget'ta 38 yarıçap için hesaplanır,
kaynak çözünürlüğe örneklenir. P4 ve kaynak boyutu korunur; **tRNS eklenmesi
özgün/v2 alpha kabiliyetinden açık bir değişikliktir**. Görsel v2 paketine
yerleştirilmedi. Eski libpng'nin bu veriyi doğru açması, MUF yüzeyinin alfa ile
çizdiğini veya ölçeklemeyi aynı yaptığını kanıtlamaz. Gerçek bir UI önizlemesi
olarak sunulamaz.

Kanıtlar:

- `analiz/native-png-probe/tools.json`: resmî paket URL, sürüm, SHA ve compiler/linker.
- `analiz/native-png-probe/harness-elf.txt`: MIPS ABI, interpreter, import ve symbol version.
- `analiz/native-png-probe/decode-result.json`: kütüphane/girdi/harness SHA ve piksel ölçümleri.
- `analiz/emulation-lab/isolation-probe.json`: yeniden çalıştırılan izolasyon kontrolleri.

Özgün dosyalar değiştirilmedi; TV'ye yazılmadı. Gizli içerik veya genel runtime
logu rapora alınmadı; yalnız sabit PNG girdi adları, hash ve sayısal piksel
ölçümleri tutuldu.
