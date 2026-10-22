# `07_MSLIB/utopia/libapiMHL.so`

SHA-256: `e8c64eb569d4da902fa0dc5b039199295d5a9e5a51bc7e167d55f32babbd64f2`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 81476 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 6, "symbol_examples": ["_mapi_mhl_SendAudioDataTunnelSupport", "mapi_mhl_SendRAPCmd", "mapi_mhl_SendRCPCmd", "mapi_mhl_SendUCPCmd", "mdrv_mhl_GetAudioDataTunnel", "tMHL_AUDIO_TUNNEL_TABLE"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 20, "symbol_examples": ["_mapi_mhl_SetPowerOnTimer", "_mhal_mhl_CbusForceToStandby", "_mhal_mhl_HdmiBypassModeSetting", "mapi_mhl_CbusWakeupIntFlag", "mapi_mhl_CbusWakeupIntSetting", "mapi_mhl_PowerCtrl", "mapi_mhl_SetPowerState", "mapi_mhl_WakeupDetect", "mdrv_mhl_CbusWakeupIntFlag", "mdrv_mhl_CbusWakeupIntSetting", "mdrv_mhl_PowerDown", "mdrv_mhl_PowerOn", "mdrv_mhl_PowerResume", "mdrv_mhl_PowerStandby", "mhal_mhl_CbusWakeupIntFlag", "mhal_mhl_CbusWakeupIntSetting"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["mhal_mhl_CheckPIPWindow"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 22, "symbol_examples": ["_mhal_mhl_HdmiBypassModeSetting", "_mhal_mhl_Mhl24bitsModeSetting", "_mhal_mhl_MhlPackedPixelModeSetting", "_mhal_mhl_PhyInitialSetting", "mapi_mhl_AdjustImpedanceSetting", "mapi_mhl_AdjustSettingIControl", "mapi_mhl_CableDetectPadSetting", "mapi_mhl_CbusWakeupIntSetting", "mapi_mhl_VbusConfigSetting", "mdrv_mhl_AdjustImpedanceSetting", "mdrv_mhl_AdjustSettingIControl", "mdrv_mhl_CableDetectPadSetting", "mdrv_mhl_CbusConfigControl", "mdrv_mhl_CbusPadConfigSwitch", "mdrv_mhl_CbusWakeupIntSetting", "mdrv_mhl_VbusConfigSetting"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 13 / 317.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 304; semboller: 1039.
- Xref: 3065; analizde call tipli xref: 0.
- Computed-call instruction: 527 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/e8c64eb569d4da902fa0dc5b039199295d5a9e5a51bc7e167d55f32babbd64f2/functions.jsonl) · [Xref](../../../analiz/native/system-modules/e8c64eb569d4da902fa0dc5b039199295d5a9e5a51bc7e167d55f32babbd64f2/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/e8c64eb569d4da902fa0dc5b039199295d5a9e5a51bc7e167d55f32babbd64f2/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/e8c64eb569d4da902fa0dc5b039199295d5a9e5a51bc7e167d55f32babbd64f2/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00018390` | `_mhal_mhl_IsCbusBusy` | [C](../../../analiz/native/system-modules/e8c64eb569d4da902fa0dc5b039199295d5a9e5a51bc7e167d55f32babbd64f2/00018390.c) |
| `000157cc` | `mdrv_mhl_PowerDown` | [C](../../../analiz/native/system-modules/e8c64eb569d4da902fa0dc5b039199295d5a9e5a51bc7e167d55f32babbd64f2/000157cc.c) |
| `00015800` | `mdrv_mhl_PowerStandby` | [C](../../../analiz/native/system-modules/e8c64eb569d4da902fa0dc5b039199295d5a9e5a51bc7e167d55f32babbd64f2/00015800.c) |
| `00015834` | `mdrv_mhl_PowerOn` | [C](../../../analiz/native/system-modules/e8c64eb569d4da902fa0dc5b039199295d5a9e5a51bc7e167d55f32babbd64f2/00015834.c) |
| `00017dec` | `mdrv_mhl_LoadDeviceCapability` | [C](../../../analiz/native/system-modules/e8c64eb569d4da902fa0dc5b039199295d5a9e5a51bc7e167d55f32babbd64f2/00017dec.c) |
| `0001b688` | `mapi_mhl_LoadDeviceCapability` | [C](../../../analiz/native/system-modules/e8c64eb569d4da902fa0dc5b039199295d5a9e5a51bc7e167d55f32babbd64f2/0001b688.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
