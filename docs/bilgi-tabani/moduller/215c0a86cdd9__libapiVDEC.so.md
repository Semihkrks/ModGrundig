# `07_MSLIB/utopia/libapiVDEC.so`

SHA-256: `215c0a86cdd9fd579655da4752e0a5c7822eb3210e768ca63b86859683c9c02b`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 1420616 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 8, "symbol_examples": ["HAL_MVD_SetAutoMute", "HAL_VPU_EX_DRAMDispCMDQueueIsEmpty", "HAL_VPU_EX_DRAMDispCMDQueueIsFull", "HAL_VPU_EX_DRAMStreamDispCMDQueueSend", "MApi_MJPEG_EnableDispCmdQ", "MApi_MJPEG_GetDispCmdQVacancy", "MApi_MJPEG_PushDispCmdQ", "MDrv_MVD_SetAutoMute"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 7, "symbol_examples": ["HAL_HVD_EX_MVD_PowerCtrl", "HAL_HVD_EX_PowerCtrl", "HAL_HVD_EX_PowerSaving", "HAL_MVD_PowerCtrl", "HAL_VPU_EX_IsPowered", "HAL_VPU_EX_PowerCtrl", "_MApi_VDEC_EX_V2_SetPowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 9, "symbol_examples": ["MDrv_HVD_EX_AVCResizeDosDispPendBuf", "ResourceGroup", "UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceGetPrivate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["HAL_VPU_EX_CPUSetting", "MDrv_HVD_EX_RVU_Setting_Mode", "MDrv_HVD_EX_SetSettings_Pro", "_HVD_EX_RecoverySettings"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 83 / 1414.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 1506; semboller: 8483.
- Xref: 32838; analizde call tipli xref: 0.
- Computed-call instruction: 6128 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/215c0a86cdd9fd579655da4752e0a5c7822eb3210e768ca63b86859683c9c02b/functions.jsonl) · [Xref](../../../analiz/native/system-modules/215c0a86cdd9fd579655da4752e0a5c7822eb3210e768ca63b86859683c9c02b/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/215c0a86cdd9fd579655da4752e0a5c7822eb3210e768ca63b86859683c9c02b/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/215c0a86cdd9fd579655da4752e0a5c7822eb3210e768ca63b86859683c9c02b/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2d62d040` | `HAL_VPU_EX_InitRegBase` | [C](../../../analiz/native/system-modules/215c0a86cdd9fd579655da4752e0a5c7822eb3210e768ca63b86859683c9c02b/2d62d040.c) |
| `2d62d5a8` | `HAL_VPU_EX_IsPowered` | [C](../../../analiz/native/system-modules/215c0a86cdd9fd579655da4752e0a5c7822eb3210e768ca63b86859683c9c02b/2d62d5a8.c) |
| `2d6348e0` | `MDrv_CC_Init` | [C](../../../analiz/native/system-modules/215c0a86cdd9fd579655da4752e0a5c7822eb3210e768ca63b86859683c9c02b/2d6348e0.c) |
| `2d604edc` | `MDrv_MJPEG_InitRegBase` | [C](../../../analiz/native/system-modules/215c0a86cdd9fd579655da4752e0a5c7822eb3210e768ca63b86859683c9c02b/2d604edc.c) |
| `2d635850` | `OSAL_HVD_MutexDelete` | [C](../../../analiz/native/system-modules/215c0a86cdd9fd579655da4752e0a5c7822eb3210e768ca63b86859683c9c02b/2d635850.c) |
| `2d635884` | `OSAL_HVD_MutexRelease` | [C](../../../analiz/native/system-modules/215c0a86cdd9fd579655da4752e0a5c7822eb3210e768ca63b86859683c9c02b/2d635884.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
