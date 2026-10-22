# `07_MSLIB/utopia/libdrvMVOP.so`

SHA-256: `81e3185d921776a26caaad6bb7356a92e5b8f9187111fe6f9869cd0ef64c41a9`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 138572 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 3, "symbol_examples": ["HAL_MVOP_PowerStateSuspend", "MDrv_MVOP_SetPowerState", "MDrv_MVOP_SetPowerState_V2"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 8, "symbol_examples": ["HAL_MVOP_EX_SetCropWindow", "HAL_MVOP_SetCropWindow", "UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 94 / 304.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 390; semboller: 1868.
- Xref: 5289; analizde call tipli xref: 0.
- Computed-call instruction: 942 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/81e3185d921776a26caaad6bb7356a92e5b8f9187111fe6f9869cd0ef64c41a9/functions.jsonl) · [Xref](../../../analiz/native/system-modules/81e3185d921776a26caaad6bb7356a92e5b8f9187111fe6f9869cd0ef64c41a9/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/81e3185d921776a26caaad6bb7356a92e5b8f9187111fe6f9869cd0ef64c41a9/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/81e3185d921776a26caaad6bb7356a92e5b8f9187111fe6f9869cd0ef64c41a9/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2ed98c40` | `OSAL_MVOP_MutexDelete` | [C](../../../analiz/native/system-modules/81e3185d921776a26caaad6bb7356a92e5b8f9187111fe6f9869cd0ef64c41a9/2ed98c40.c) |
| `2ed98c74` | `OSAL_MVOP_MutexRelease` | [C](../../../analiz/native/system-modules/81e3185d921776a26caaad6bb7356a92e5b8f9187111fe6f9869cd0ef64c41a9/2ed98c74.c) |
| `2ed98ca8` | `OSAL_MVOP_MutexObtain` | [C](../../../analiz/native/system-modules/81e3185d921776a26caaad6bb7356a92e5b8f9187111fe6f9869cd0ef64c41a9/2ed98ca8.c) |
| `2ed98cdc` | `OSAL_MVOP_MutexCreate` | [C](../../../analiz/native/system-modules/81e3185d921776a26caaad6bb7356a92e5b8f9187111fe6f9869cd0ef64c41a9/2ed98cdc.c) |
| `2ed86278` | `MDrv_MVOP_SubInit_V2` | [C](../../../analiz/native/system-modules/81e3185d921776a26caaad6bb7356a92e5b8f9187111fe6f9869cd0ef64c41a9/2ed86278.c) |
| `2ed98d38` | `HAL_MVOP_InitMirrorMode` | [C](../../../analiz/native/system-modules/81e3185d921776a26caaad6bb7356a92e5b8f9187111fe6f9869cd0ef64c41a9/2ed98d38.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
