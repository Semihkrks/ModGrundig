# `07_MSLIB/libpng.so.3.32.0`

SHA-256: `65abc793e96bd86315066749180e14e5bf87c16655ca6e8c2fb476da1025d24a`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 242964 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["png_set_compression_window_bits"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libz.so.1`, `libm.so.6`, `libpthread.so.0`, `libc.so.6`
- Dynamic import/export: 30 / 368.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 366; semboller: 2976.
- Xref: 21663; analizde call tipli xref: 0.
- Computed-call instruction: 1347 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/65abc793e96bd86315066749180e14e5bf87c16655ca6e8c2fb476da1025d24a/functions.jsonl) · [Xref](../../../analiz/native/system-modules/65abc793e96bd86315066749180e14e5bf87c16655ca6e8c2fb476da1025d24a/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/65abc793e96bd86315066749180e14e5bf87c16655ca6e8c2fb476da1025d24a/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/65abc793e96bd86315066749180e14e5bf87c16655ca6e8c2fb476da1025d24a/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2ec2574c` | `png_init_io` | [C](../../../analiz/native/system-modules/65abc793e96bd86315066749180e14e5bf87c16655ca6e8c2fb476da1025d24a/2ec2574c.c) |
| `2ec24b88` | `png_info_init` | [C](../../../analiz/native/system-modules/65abc793e96bd86315066749180e14e5bf87c16655ca6e8c2fb476da1025d24a/2ec24b88.c) |
| `2ec29fe0` | `png_get_channels` | [C](../../../analiz/native/system-modules/65abc793e96bd86315066749180e14e5bf87c16655ca6e8c2fb476da1025d24a/2ec29fe0.c) |
| `2ec2a040` | `png_get_signature` | [C](../../../analiz/native/system-modules/65abc793e96bd86315066749180e14e5bf87c16655ca6e8c2fb476da1025d24a/2ec2a040.c) |
| `2ec3a528` | `png_read_init` | [C](../../../analiz/native/system-modules/65abc793e96bd86315066749180e14e5bf87c16655ca6e8c2fb476da1025d24a/2ec3a528.c) |
| `2ec3ec4c` | `png_write_init` | [C](../../../analiz/native/system-modules/65abc793e96bd86315066749180e14e5bf87c16655ca6e8c2fb476da1025d24a/2ec3ec4c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
