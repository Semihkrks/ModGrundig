# `07_MSLIB/utopia/libapiGOP.so`

SHA-256: `964c3be660d9bd68299b2125245c023f74910829832c415ff62accc09887151d`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 335440 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 11, "symbol_examples": ["GOP_PowerOff", "GOP_PowerOn", "HAL_GOP_DWIN_SetSourceSel", "HAL_GOP_PowerState", "Ioctl_GOP_PowerState", "MApi_GOP_DWIN_SetSourceSel", "MApi_GOP_PowerOff", "MApi_GOP_PowerOn", "MApi_GOP_SetPowerState", "MDrv_GOP_DWIN_SetSourceSel", "MDrv_GOP_GWIN_PowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 21, "symbol_examples": ["GOP_Enable_VEOSD", "GOP_Set3DOSDMode", "HAL_GOP_GWiN_Set3DOSD_Sub", "MApi_GOP_Enable_VEOSD", "MApi_GOP_GWIN_BeginDraw", "MApi_GOP_GWIN_EndDraw", "MApi_GOP_Initialize_StretchWindow", "MApi_GOP_RegisterXCReduceBWForOSDCB", "MApi_GOP_Set3DOSDMode", "MDrv_GOP_GWIN_BeginDraw", "MDrv_GOP_GWIN_EndDraw", "MDrv_GOP_Set3DOSD_Middle", "MDrv_GOP_Set3DOSD_Mode", "MDrv_GOP_Set3DOSD_Sub", "UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart"], "examples_are_complete": false}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 6, "symbol_examples": ["Ioctl_GOP_GetConfig", "Ioctl_GOP_Palette_Set_Config", "Ioctl_GOP_SetConfig", "MApi_GOP_GetConfigEx", "MApi_GOP_SetConfig", "MApi_GOP_SetConfigEx"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 49 / 739.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 787; semboller: 3198.
- Xref: 17463; analizde call tipli xref: 0.
- Computed-call instruction: 3581 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/964c3be660d9bd68299b2125245c023f74910829832c415ff62accc09887151d/functions.jsonl) · [Xref](../../../analiz/native/system-modules/964c3be660d9bd68299b2125245c023f74910829832c415ff62accc09887151d/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/964c3be660d9bd68299b2125245c023f74910829832c415ff62accc09887151d/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/964c3be660d9bd68299b2125245c023f74910829832c415ff62accc09887151d/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2ea2a668` | `MDrv_GOP_GWIN_ForceWrite_Update` | [C](../../../analiz/native/system-modules/964c3be660d9bd68299b2125245c023f74910829832c415ff62accc09887151d/2ea2a668.c) |
| `2ea301ac` | `MDrv_GOP_InitMux` | [C](../../../analiz/native/system-modules/964c3be660d9bd68299b2125245c023f74910829832c415ff62accc09887151d/2ea301ac.c) |
| `2ea31a6c` | `MDrv_GOP_DeInit` | [C](../../../analiz/native/system-modules/964c3be660d9bd68299b2125245c023f74910829832c415ff62accc09887151d/2ea31a6c.c) |
| `2ea34650` | `MDrv_GOP_GWIN_UpdateReg` | [C](../../../analiz/native/system-modules/964c3be660d9bd68299b2125245c023f74910829832c415ff62accc09887151d/2ea34650.c) |
| `2ea46b00` | `MApi_GOP_GWIN_UpdateRegOnce` | [C](../../../analiz/native/system-modules/964c3be660d9bd68299b2125245c023f74910829832c415ff62accc09887151d/2ea46b00.c) |
| `2ea3a918` | `HAL_GOP_InitMux` | [C](../../../analiz/native/system-modules/964c3be660d9bd68299b2125245c023f74910829832c415ff62accc09887151d/2ea3a918.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
