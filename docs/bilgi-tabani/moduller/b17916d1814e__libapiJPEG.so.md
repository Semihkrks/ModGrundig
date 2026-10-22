# `07_MSLIB/utopia/libapiJPEG.so`

SHA-256: `b17916d1814ee883c1f1ad7abd716951975245679c8cc49b05d4bd729440dcb9`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 157284 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 8, "symbol_examples": ["HAL_JPD_PowerOff", "HAL_JPD_PowerOn", "MApi_JPEG_PowerOff", "MApi_JPEG_PowerOn", "MDrv_JPD_PowerOff", "MDrv_JPD_PowerOn", "_MApi_JPEG_PowerOff", "_MApi_JPEG_PowerOn"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 7, "symbol_examples": ["UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceGetPrivate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 8, "symbol_examples": ["HAL_JPD_Get_M_Config", "HAL_JPD_Get_S_Config", "HAL_JPD_Set_M_Config", "HAL_JPD_Set_S_Config", "MDrv_JPD_Get_M_Config", "MDrv_JPD_Get_S_Config", "MDrv_JPD_Set_M_Config", "MDrv_JPD_Set_S_Config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 41 / 271.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 306; semboller: 1771.
- Xref: 5846; analizde call tipli xref: 0.
- Computed-call instruction: 1131 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/b17916d1814ee883c1f1ad7abd716951975245679c8cc49b05d4bd729440dcb9/functions.jsonl) · [Xref](../../../analiz/native/system-modules/b17916d1814ee883c1f1ad7abd716951975245679c8cc49b05d4bd729440dcb9/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/b17916d1814ee883c1f1ad7abd716951975245679c8cc49b05d4bd729440dcb9/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/b17916d1814ee883c1f1ad7abd716951975245679c8cc49b05d4bd729440dcb9/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2ed076b8` | `OSAL_JPD_MutexDelete` | [C](../../../analiz/native/system-modules/b17916d1814ee883c1f1ad7abd716951975245679c8cc49b05d4bd729440dcb9/2ed076b8.c) |
| `2ed076ec` | `OSAL_JPD_MutexRelease` | [C](../../../analiz/native/system-modules/b17916d1814ee883c1f1ad7abd716951975245679c8cc49b05d4bd729440dcb9/2ed076ec.c) |
| `2ed07720` | `OSAL_JPD_MutexObtain` | [C](../../../analiz/native/system-modules/b17916d1814ee883c1f1ad7abd716951975245679c8cc49b05d4bd729440dcb9/2ed07720.c) |
| `2ed047d8` | `MDrv_JPD_PowerOff` | [C](../../../analiz/native/system-modules/b17916d1814ee883c1f1ad7abd716951975245679c8cc49b05d4bd729440dcb9/2ed047d8.c) |
| `2ed07754` | `OSAL_JPD_MutexCreate` | [C](../../../analiz/native/system-modules/b17916d1814ee883c1f1ad7abd716951975245679c8cc49b05d4bd729440dcb9/2ed07754.c) |
| `2ed0fad4` | `_MApi_JPEG_Init_UsingOJPD` | [C](../../../analiz/native/system-modules/b17916d1814ee883c1f1ad7abd716951975245679c8cc49b05d4bd729440dcb9/2ed0fad4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
