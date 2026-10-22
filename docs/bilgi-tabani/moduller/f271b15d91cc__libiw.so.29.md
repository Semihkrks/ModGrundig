# `06_RFS/lib/libiw.so.29`

SHA-256: `f271b15d91ccabdd212ce02ba4ecbf0de242bdde8a4ccf6d59b2d2ffc652df2c`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 77976 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["__fpcmp_parts_d"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["iw_print_txpower"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 3, "symbol_examples": ["/scratch/clm/2008q3-src/src/gcc-4.3/libgcc/../gcc/config/fp-bit.h", "iw_get_basic_config", "iw_set_basic_config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libm.so.6`, `libc.so.6`
- Dynamic import/export: 44 / 56.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 104; semboller: 761.
- Xref: 2151; analizde call tipli xref: 0.
- Computed-call instruction: 409 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/f271b15d91ccabdd212ce02ba4ecbf0de242bdde8a4ccf6d59b2d2ffc652df2c/functions.jsonl) · [Xref](../../../analiz/native/system-modules/f271b15d91ccabdd212ce02ba4ecbf0de242bdde8a4ccf6d59b2d2ffc652df2c/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/f271b15d91ccabdd212ce02ba4ecbf0de242bdde8a4ccf6d59b2d2ffc652df2c/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/f271b15d91ccabdd212ce02ba4ecbf0de242bdde8a4ccf6d59b2d2ffc652df2c/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2c8a1754` | `iw_init_event_stream` | [C](../../../analiz/native/system-modules/f271b15d91ccabdd212ce02ba4ecbf0de242bdde8a4ccf6d59b2d2ffc652df2c/2c8a1754.c) |
| `2c8a1248` | `_init` | [C](../../../analiz/native/system-modules/f271b15d91ccabdd212ce02ba4ecbf0de242bdde8a4ccf6d59b2d2ffc652df2c/2c8a1248.c) |
| `2c8a5610` | `iw_sockets_open` | [C](../../../analiz/native/system-modules/f271b15d91ccabdd212ce02ba4ecbf0de242bdde8a4ccf6d59b2d2ffc652df2c/2c8a5610.c) |
| `2c8a4060` | `iw_print_txpower` | [C](../../../analiz/native/system-modules/f271b15d91ccabdd212ce02ba4ecbf0de242bdde8a4ccf6d59b2d2ffc652df2c/2c8a4060.c) |
| `2c8a47bc` | `iw_channel_to_freq` | [C](../../../analiz/native/system-modules/f271b15d91ccabdd212ce02ba4ecbf0de242bdde8a4ccf6d59b2d2ffc652df2c/2c8a47bc.c) |
| `2c8a4898` | `iw_freq_to_channel` | [C](../../../analiz/native/system-modules/f271b15d91ccabdd212ce02ba4ecbf0de242bdde8a4ccf6d59b2d2ffc652df2c/2c8a4898.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
