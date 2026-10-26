# Orijinal kernel: UBIFS ZLIB desteği

25 Ekim 2026. V8 APP'nin sabit kapsayıcı slotuna sığmaması üzerine yapılan sınırlı, çevrimdışı inceleme. Firmware/kernel/güncelleme script'i çalıştırılmadı; hassas partition veya dosya içerikleri okunmadı. Bu çıktı doğrudan dosya/assembly kanıtıdır, REA Evidence ya da cihaz gözlemi değildir.

**Sonuç:** Orijinal kernel'de UBIFS ZLIB derleme desteği statik olarak vardır. Ayrı bir çevrimdışı APP adayında ZLIB denenmesi için somut kod kanıtı bulunmuştur. Yeni APP'nin gerçek cihazda mount edilmesi veya crypto başlangıcının runtime başarısı bu incelemeyle doğrulanmaz.

## Kaynak ve açma zinciri

- `analiz/bolumler/05_KL.bin`:1.758.840 bayt, SHA256 `d96b0ec70d633751ba8750a1a80aee8cac3a9c5e825744650d749a8862550691`. uImage header/data CRC'leri eşleşti.
- uImage compression alanı0; yük, kendi LZMA açıcı wrapper'ını içeriyor. Wrapper'da `LZMA data is corrupt` sabit metni var. LZMA-alone akışı uImage dosyası `0x13c0` (payload `0x1380`) ofsetinde, properties `5d00000004`.
- Akış EOF'a kadar açıldı;4 trailing bayt kaldı. Sonuç `kernel-linux-flat.bin`:5.306.304 bayt, SHA256 `43e9cf9a68cefafb14beb936cd37f801a69412b69cfc127bd7c866fe431c3426`. IKCONFIG imzası yoktur; CONFIG_* satırları elde edilmiş gibi sunulmaz.
- Düz kernel için0x80000000 adres tabanı çok sayıda string/data pointer eşleşmesiyle ve aşağıdaki callsite adres kurulumuyla tutarlıdır. Dosya ofseti=VA−0x80000000.

## Salt string değil, descriptor ve gerçek kod yolu

1. VA `0x804b91b0` compressor descriptor'ının ilk word'ü **2**. `+0x10` pointer `0x804574b4` → `zlib`; `+0x14` pointer `0x804623f0` → `deflate` ve **NULL değil**. Yalnız adı bulunan fakat derlenmemiş stub durumundan ayrılır.
2. Başlangıç yolu `0x804f0d2c` önce LZO descriptor'ını, ardından `0x804f0d58` çağrısı / `0x804f0d5c` delay slot'u ile tam `0x804b91b0` ZLIB descriptor'ını ortak helper `0x804f0ca4`'e geçirir.
3. Helper `0x804f0cb4` descriptor `+0x14`'ü yükler; sıfır değilse bu CAPI adıyla allocation/lookup çağrı hedefi `0x801cccdc`'ye gider. Başarılı yol `0x804f0d00..0x804f0d14`, descriptor'ın type'ını dörtle çarpıp `0x8056f8e0 + type*4` compressor tablosuna descriptor pointer'ını yazar. Stripped kernel'de helper adları davranıştan yorumlanır; geri kazanılmış ELF sembolleri değildir.
4. Decompression yolu `0x801b7700` type<3 kontrolü yapar, aynı tabloyu indeksler (`0x801b7730..3c`), descriptor `+0x14` desteğini kontrol eder ve `+4` crypto nesnesinden `+8` fonksiyon pointer'ını `0x801b7780`'de çağırır. Desteğin bulunmadığı yol ayrıdır.
5. Ayrı crypto algoritma descriptor'ı `0x804b96a0`, inline `deflate` adı `0x804b96c8` ve gerçek kod fonksiyon pointer'ları içerir. Başlangıç `0x804f11e0..e8` bu descriptor'ı registration hedefi `0x801ce788`'e verir; bu başlangıç pointer'ı initcall bölgesinde dosya `0x50e05c`'de bulunur. Yalnız UBIFS'te kalan bir `zlib` string'ine dayanılmadı.

Bütün ilgili assembly satırları, kaynak/çıktı hash'leri ve descriptor word'leri [kernel-compression.json](kernel-compression.json) içinde tutulur.

## Orijinal dosya sistemi örnekleri

RFS, APP ve CONFIG committed index'leri üzerinden yalnız DATA_NODE metadata `compr_type` alanları sayıldı. DATA payload'ları açılmadı; dosya adları/içerikleri çıkarılmadı; certificate/customer partition'ları incelenmedi.

| İmaj | LZO(type1) | Sıkıştırmasız(type0) | ZLIB(type2) |
|---|---:|---:|---:|
| RFS | 2.071 |83 |0 |
| APP | 7.782 |3.341 |0 |
| CONFIG | 1.005 |6 |0 |

Dolayısıyla **orijinal örnekte ZLIB dosya sistemi zaten kullanılıyor** sonucu yoktur. ZLIB desteği sonucu, kernel'in descriptor/initialization/algorithm/decompression zincirinden gelir. Index CRC'leri, image SHA'ları, sayılar ve örnek metadata ofsetleri [node-counts kaydındadır](kernel-compression.node-counts.json). Yeni ZLIB APP üretimi, yeniden çıkarma ve dosya/metaveri karşılaştırması ayrı kontrol gerektirir.
