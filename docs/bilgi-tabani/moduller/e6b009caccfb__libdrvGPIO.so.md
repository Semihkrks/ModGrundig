# `07_MSLIB/utopia/libdrvGPIO.so`

SHA-256: `e6b009caccfb602fdb7bc4a608d7f60aeb88f9ac494980d16c4b2c1f001356af`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 18456 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MDrv_GPIO_SetPowerState"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 5 / 42.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 39; semboller: 138.
- Xref: 277; analizde call tipli xref: 0.
- Computed-call instruction: 37 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 3/3.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/e6b009caccfb602fdb7bc4a608d7f60aeb88f9ac494980d16c4b2c1f001356af/functions.jsonl) · [Xref](../../../analiz/native/system-modules/e6b009caccfb602fdb7bc4a608d7f60aeb88f9ac494980d16c4b2c1f001356af/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/e6b009caccfb602fdb7bc4a608d7f60aeb88f9ac494980d16c4b2c1f001356af/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/e6b009caccfb602fdb7bc4a608d7f60aeb88f9ac494980d16c4b2c1f001356af/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f4012e8` | `mdrv_gpio_init` | [C](../../../analiz/native/system-modules/e6b009caccfb602fdb7bc4a608d7f60aeb88f9ac494980d16c4b2c1f001356af/2f4012e8.c) |
| `2f400aa0` | `_init` | [C](../../../analiz/native/system-modules/e6b009caccfb602fdb7bc4a608d7f60aeb88f9ac494980d16c4b2c1f001356af/2f400aa0.c) |
| `2f401340` | `MDrv_GPIO_SetPowerState` | [C](../../../analiz/native/system-modules/e6b009caccfb602fdb7bc4a608d7f60aeb88f9ac494980d16c4b2c1f001356af/2f401340.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
