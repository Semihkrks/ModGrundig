# `07_MSLIB/utopia/libapiGFX.so`

SHA-256: `e9dff8d4db95cb4050d72ac36acc8188c3ada89a7cd2a949250c29c5bc9d9279`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 129204 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 5, "symbol_examples": ["MApi_GFX_PowerOff", "MApi_GFX_PowerOn", "MApi_GFX_SetPowerState", "MDrv_GE_PowerOff", "MDrv_GE_SetPowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 22, "symbol_examples": ["GE_Free_Resource", "GE_Get_Resource", "MApi_GFX_BeginDraw", "MApi_GFX_BeginDraw_U02", "MApi_GFX_DrawBitmap", "MApi_GFX_DrawBitmap_U02", "MApi_GFX_DrawLine", "MApi_GFX_DrawLine_U02", "MApi_GFX_DrawOval", "MApi_GFX_DrawOval_U02", "MApi_GFX_EndDraw", "MApi_GFX_EndDraw_U02", "MApi_GFX_RegisterGetFontCB", "MDrv_GE_DrawLine", "MDrv_GE_DrawOval", "MDrv_GE_GetClipWindow"], "examples_are_complete": false}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MApi_GFX_SetConfig"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 35 / 316.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 351; semboller: 1410.
- Xref: 6436; analizde call tipli xref: 0.
- Computed-call instruction: 1237 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/e9dff8d4db95cb4050d72ac36acc8188c3ada89a7cd2a949250c29c5bc9d9279/functions.jsonl) · [Xref](../../../analiz/native/system-modules/e9dff8d4db95cb4050d72ac36acc8188c3ada89a7cd2a949250c29c5bc9d9279/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/e9dff8d4db95cb4050d72ac36acc8188c3ada89a7cd2a949250c29c5bc9d9279/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/e9dff8d4db95cb4050d72ac36acc8188c3ada89a7cd2a949250c29c5bc9d9279/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2ef2b210` | `GE_Chip_Proprity_Init` | [C](../../../analiz/native/system-modules/e9dff8d4db95cb4050d72ac36acc8188c3ada89a7cd2a949250c29c5bc9d9279/2ef2b210.c) |
| `2ef248fc` | `MDrv_GE_PowerOff` | [C](../../../analiz/native/system-modules/e9dff8d4db95cb4050d72ac36acc8188c3ada89a7cd2a949250c29c5bc9d9279/2ef248fc.c) |
| `2ef2b998` | `GE_Init_HAL_Context` | [C](../../../analiz/native/system-modules/e9dff8d4db95cb4050d72ac36acc8188c3ada89a7cd2a949250c29c5bc9d9279/2ef2b998.c) |
| `2ef23e60` | `_init` | [C](../../../analiz/native/system-modules/e9dff8d4db95cb4050d72ac36acc8188c3ada89a7cd2a949250c29c5bc9d9279/2ef23e60.c) |
| `2ef26d84` | `MDrv_GE_Chip_Proprity_Init` | [C](../../../analiz/native/system-modules/e9dff8d4db95cb4050d72ac36acc8188c3ada89a7cd2a949250c29c5bc9d9279/2ef26d84.c) |
| `2ef2edc8` | `MApi_GFX_SetPowerState` | [C](../../../analiz/native/system-modules/e9dff8d4db95cb4050d72ac36acc8188c3ada89a7cd2a949250c29c5bc9d9279/2ef2edc8.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
