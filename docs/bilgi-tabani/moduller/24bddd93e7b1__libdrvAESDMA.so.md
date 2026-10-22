# `07_MSLIB/utopia/libdrvAESDMA.so`

SHA-256: `24bddd93e7b1a0bfbfc6f2e42302d252d23fe8dfb4a80a6a8b8868f6d2531370`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 46140 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 3, "symbol_examples": ["AESDMA_POWER_RESUME", "AESDMA_POWER_SUSPEND", "MDrv_AESDMA_SetPowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 6, "symbol_examples": ["UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 36 / 158.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 187; semboller: 466.
- Xref: 1739; analizde call tipli xref: 0.
- Computed-call instruction: 425 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/24bddd93e7b1a0bfbfc6f2e42302d252d23fe8dfb4a80a6a8b8868f6d2531370/functions.jsonl) · [Xref](../../../analiz/native/system-modules/24bddd93e7b1a0bfbfc6f2e42302d252d23fe8dfb4a80a6a8b8868f6d2531370/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/24bddd93e7b1a0bfbfc6f2e42302d252d23fe8dfb4a80a6a8b8868f6d2531370/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/24bddd93e7b1a0bfbfc6f2e42302d252d23fe8dfb4a80a6a8b8868f6d2531370/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f368794` | `AESDMA_Set_EvenInitVector` | [C](../../../analiz/native/system-modules/24bddd93e7b1a0bfbfc6f2e42302d252d23fe8dfb4a80a6a8b8868f6d2531370/2f368794.c) |
| `2f368880` | `AESDMA_POWER_RESUME` | [C](../../../analiz/native/system-modules/24bddd93e7b1a0bfbfc6f2e42302d252d23fe8dfb4a80a6a8b8868f6d2531370/2f368880.c) |
| `2f36883c` | `AESDMA_POWER_SUSPEND` | [C](../../../analiz/native/system-modules/24bddd93e7b1a0bfbfc6f2e42302d252d23fe8dfb4a80a6a8b8868f6d2531370/2f36883c.c) |
| `2f36647c` | `AESDMA_Set_InitVector` | [C](../../../analiz/native/system-modules/24bddd93e7b1a0bfbfc6f2e42302d252d23fe8dfb4a80a6a8b8868f6d2531370/2f36647c.c) |
| `2f368704` | `AESDMA_Set_OddInitVector` | [C](../../../analiz/native/system-modules/24bddd93e7b1a0bfbfc6f2e42302d252d23fe8dfb4a80a6a8b8868f6d2531370/2f368704.c) |
| `2f3622d0` | `_init` | [C](../../../analiz/native/system-modules/24bddd93e7b1a0bfbfc6f2e42302d252d23fe8dfb4a80a6a8b8868f6d2531370/2f3622d0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
