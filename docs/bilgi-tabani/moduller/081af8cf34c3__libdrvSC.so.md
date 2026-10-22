# `07_MSLIB/utopia/libdrvSC.so`

SHA-256: `081af8cf34c3a339a79091a8722b31c887d0852b9f462a63449aa5b2d4c1f2ca`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 39820 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 3, "symbol_examples": ["HAL_SC_PowerCtrl", "MDrv_SC_PowerOff", "MDrv_SC_SetPowerState"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 3, "symbol_examples": ["HAL_SC_CardVoltage_Config", "MDrv_SC_CardVoltage_Config", "MDrv_SC_Config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 31 / 76.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 98; semboller: 583.
- Xref: 2003; analizde call tipli xref: 0.
- Computed-call instruction: 326 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/081af8cf34c3a339a79091a8722b31c887d0852b9f462a63449aa5b2d4c1f2ca/functions.jsonl) · [Xref](../../../analiz/native/system-modules/081af8cf34c3a339a79091a8722b31c887d0852b9f462a63449aa5b2d4c1f2ca/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/081af8cf34c3a339a79091a8722b31c887d0852b9f462a63449aa5b2d4c1f2ca/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/081af8cf34c3a339a79091a8722b31c887d0852b9f462a63449aa5b2d4c1f2ca/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f561ad4` | `MDrv_SC_PowerOff` | [C](../../../analiz/native/system-modules/081af8cf34c3a339a79091a8722b31c887d0852b9f462a63449aa5b2d4c1f2ca/2f561ad4.c) |
| `2f561348` | `_init` | [C](../../../analiz/native/system-modules/081af8cf34c3a339a79091a8722b31c887d0852b9f462a63449aa5b2d4c1f2ca/2f561348.c) |
| `2f5673bc` | `HAL_SC_PowerCtrl` | [C](../../../analiz/native/system-modules/081af8cf34c3a339a79091a8722b31c887d0852b9f462a63449aa5b2d4c1f2ca/2f5673bc.c) |
| `2f5675c8` | `HAL_SC_Init` | [C](../../../analiz/native/system-modules/081af8cf34c3a339a79091a8722b31c887d0852b9f462a63449aa5b2d4c1f2ca/2f5675c8.c) |
| `2f566e90` | `OS_SC_Init` | [C](../../../analiz/native/system-modules/081af8cf34c3a339a79091a8722b31c887d0852b9f462a63449aa5b2d4c1f2ca/2f566e90.c) |
| `2f566778` | `MDrv_SC_SetPowerState` | [C](../../../analiz/native/system-modules/081af8cf34c3a339a79091a8722b31c887d0852b9f462a63449aa5b2d4c1f2ca/2f566778.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
