# `07_MSLIB/utopia/libapiDMX.so`

SHA-256: `d2735b9b85837a5efd427a26aae33abbb94f6433e50ef94555fc446c69f659c6`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 418516 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["HAL_TSP_PowerCtrl", "MApi_DMX_SetPowerState", "MDrv_TSP_PowerOff", "_MApi_DMX_SetPowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 11, "symbol_examples": ["MApi_DMX_InitLibResource", "MDrv_MMFI_InitLibResource", "MDrv_TSO_InitLibResource", "MDrv_TSP_InitLibResource", "UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceGetPrivate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 5, "symbol_examples": ["MApi_DMX_FQ_Configure", "MApi_DMX_TSO_Configure", "MDrv_TSO_Configure", "_MApi_DMX_FQ_Configure", "_MApi_DMX_TSO_Configure"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 55 / 1021.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 1072; semboller: 5639.
- Xref: 21558; analizde call tipli xref: 0.
- Computed-call instruction: 4790 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/d2735b9b85837a5efd427a26aae33abbb94f6433e50ef94555fc446c69f659c6/functions.jsonl) · [Xref](../../../analiz/native/system-modules/d2735b9b85837a5efd427a26aae33abbb94f6433e50ef94555fc446c69f659c6/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/d2735b9b85837a5efd427a26aae33abbb94f6433e50ef94555fc446c69f659c6/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/d2735b9b85837a5efd427a26aae33abbb94f6433e50ef94555fc446c69f659c6/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2e619594` | `OSAL_TSP_MutexRelease` | [C](../../../analiz/native/system-modules/d2735b9b85837a5efd427a26aae33abbb94f6433e50ef94555fc446c69f659c6/2e619594.c) |
| `2e6195c8` | `OSAL_TSP_MutexObtain` | [C](../../../analiz/native/system-modules/d2735b9b85837a5efd427a26aae33abbb94f6433e50ef94555fc446c69f659c6/2e6195c8.c) |
| `2e6195fc` | `OSAL_TSP_MutexCreate` | [C](../../../analiz/native/system-modules/d2735b9b85837a5efd427a26aae33abbb94f6433e50ef94555fc446c69f659c6/2e6195fc.c) |
| `2e5f8a98` | `MDrv_TSP_SecFlt_Update` | [C](../../../analiz/native/system-modules/d2735b9b85837a5efd427a26aae33abbb94f6433e50ef94555fc446c69f659c6/2e5f8a98.c) |
| `2e61989c` | `_MApi_DMX_FQ_Init` | [C](../../../analiz/native/system-modules/d2735b9b85837a5efd427a26aae33abbb94f6433e50ef94555fc446c69f659c6/2e61989c.c) |
| `2e614334` | `HAL_TSP_STC_Update_Disable` | [C](../../../analiz/native/system-modules/d2735b9b85837a5efd427a26aae33abbb94f6433e50ef94555fc446c69f659c6/2e614334.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
