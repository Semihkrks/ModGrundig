# `07_MSLIB/utopia/libdrvMBX.so`

SHA-256: `df5b9827cc49d83092dfdd8998c2865655637ed0ef08e35cf588d940364e94cf`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 30748 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MDrv_MBX_SetPowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 6, "symbol_examples": ["UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MHAL_MBX_SetConfig"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 41 / 71.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 144; semboller: 523.
- Xref: 1283; analizde call tipli xref: 0.
- Computed-call instruction: 266 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/df5b9827cc49d83092dfdd8998c2865655637ed0ef08e35cf588d940364e94cf/functions.jsonl) · [Xref](../../../analiz/native/system-modules/df5b9827cc49d83092dfdd8998c2865655637ed0ef08e35cf588d940364e94cf/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/df5b9827cc49d83092dfdd8998c2865655637ed0ef08e35cf588d940364e94cf/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/df5b9827cc49d83092dfdd8998c2865655637ed0ef08e35cf588d940364e94cf/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `000150d0` | `MHAL_MBXINT_CpuInit` | [C](../../../analiz/native/system-modules/df5b9827cc49d83092dfdd8998c2865655637ed0ef08e35cf588d940364e94cf/000150d0.c) |
| `00012fdc` | `MDrv_MBX_Init` | [C](../../../analiz/native/system-modules/df5b9827cc49d83092dfdd8998c2865655637ed0ef08e35cf588d940364e94cf/00012fdc.c) |
| `00014140` | `MApi_MBX_DeInit` | [C](../../../analiz/native/system-modules/df5b9827cc49d83092dfdd8998c2865655637ed0ef08e35cf588d940364e94cf/00014140.c) |
| `00014174` | `MApi_MBX_Init` | [C](../../../analiz/native/system-modules/df5b9827cc49d83092dfdd8998c2865655637ed0ef08e35cf588d940364e94cf/00014174.c) |
| `000146b8` | `MHAL_MBX_Init` | [C](../../../analiz/native/system-modules/df5b9827cc49d83092dfdd8998c2865655637ed0ef08e35cf588d940364e94cf/000146b8.c) |
| `00015248` | `MHAL_MBXINT_Init` | [C](../../../analiz/native/system-modules/df5b9827cc49d83092dfdd8998c2865655637ed0ef08e35cf588d940364e94cf/00015248.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
