# `07_MSLIB/utopia/libdrvVE.so`

SHA-256: `f81aab978a51ffb53737553c7089ba83cc8951948393f7a6041d1feef707c035`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 71028 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 3, "symbol_examples": ["Hal_VE_DCS_SetActivationKey", "MDrv_VE_DCS_SetActivationKey", "_MDrv_VE_DCS_SetActivationKey"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 7, "symbol_examples": ["Hal_VE_set_inputsource", "MDrv_TVE_SetPowerState", "MDrv_VE_SetInputSource", "MDrv_VE_SwitchInputSource", "_MDrv_TVE_SetPowerState", "_MDrv_VE_SetInputSource", "_MDrv_VE_SwitchInputSource"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 27, "symbol_examples": ["Hal_VE_Get_OSDLayer", "Hal_VE_Set_Crop_OSD_Offset", "Hal_VE_Set_OSD", "Hal_VE_Set_OSDLayer", "Hal_VE_Set_VbiTtxActiveLinesBitmap", "Hal_VE_set_capture_window", "MDrv_VE_Get_OSDLayer", "MDrv_VE_SetOSD", "MDrv_VE_SetVbiTtxActiveLinesBitmap", "MDrv_VE_SetWindow", "MDrv_VE_Set_OSDLayer", "MDrv_VE_set_be_display_window", "MDrv_VE_set_capture_window", "MDrv_VE_set_crop_window", "MDrv_VE_set_display_window", "UtopiaModuleAddResourceEnd"], "examples_are_complete": false}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["Hal_VE_ISRConfig"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 30 / 236.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 239; semboller: 980.
- Xref: 2816; analizde call tipli xref: 0.
- Computed-call instruction: 541 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/f81aab978a51ffb53737553c7089ba83cc8951948393f7a6041d1feef707c035/functions.jsonl) · [Xref](../../../analiz/native/system-modules/f81aab978a51ffb53737553c7089ba83cc8951948393f7a6041d1feef707c035/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/f81aab978a51ffb53737553c7089ba83cc8951948393f7a6041d1feef707c035/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/f81aab978a51ffb53737553c7089ba83cc8951948393f7a6041d1feef707c035/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2efea390` | `Hal_VE_init_riu_base` | [C](../../../analiz/native/system-modules/f81aab978a51ffb53737553c7089ba83cc8951948393f7a6041d1feef707c035/2efea390.c) |
| `2efe95e8` | `MDrv_VEC_GFLIPInit` | [C](../../../analiz/native/system-modules/f81aab978a51ffb53737553c7089ba83cc8951948393f7a6041d1feef707c035/2efe95e8.c) |
| `2efe3014` | `_init` | [C](../../../analiz/native/system-modules/f81aab978a51ffb53737553c7089ba83cc8951948393f7a6041d1feef707c035/2efe3014.c) |
| `2efe3524` | `MDrv_VE_InitVECapture` | [C](../../../analiz/native/system-modules/f81aab978a51ffb53737553c7089ba83cc8951948393f7a6041d1feef707c035/2efe3524.c) |
| `2efeb888` | `Hal_VE_set_v_initfactor` | [C](../../../analiz/native/system-modules/f81aab978a51ffb53737553c7089ba83cc8951948393f7a6041d1feef707c035/2efeb888.c) |
| `2efe334c` | `MDrv_TVE_SetPowerState` | [C](../../../analiz/native/system-modules/f81aab978a51ffb53737553c7089ba83cc8951948393f7a6041d1feef707c035/2efe334c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
