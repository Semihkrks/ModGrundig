# `07_MSLIB/utopia/libapiCEC.so`

SHA-256: `900f66ee625a0a2c4db8fca424f76d0076fbbbcc01721cb46d0314e3c2a5ad99`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 65960 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["MApi_CEC_Msg_GiveAudioStatus", "MDrv_CEC_Msg_GiveAudioStatus", "MDrv_CecMsg_AudioModeReq", "MsAPI_CecMsg_AudioModeReq"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 170, "symbol_examples": ["CECClose", "CECIoctl", "CECOpen", "CECRegisterToUtopia", "CECSTR", "CEC_RIU_BASE", "MApi_CEC_AttachDriverISR", "MApi_CEC_CheckDeviceIsTx", "MApi_CEC_CheckExistDevices", "MApi_CEC_CheckFrame", "MApi_CEC_ChkRxBuf", "MApi_CEC_ConfigWakeUp", "MApi_CEC_ConfigWakeupInfoVendorID", "MApi_CEC_Ctrl", "MApi_CEC_Enabled", "MApi_CEC_Exit"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 7, "symbol_examples": ["UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceGetPrivate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 7, "symbol_examples": ["MApi_CEC_ConfigWakeUp", "MApi_CEC_ConfigWakeupInfoVendorID", "MDrv_CEC_ConfigWakeUp", "MDrv_CEC_ConfigWakeupInfoVendorID", "MDrv_CEC_GetConfiguration", "mapi_CEC_GetConfig", "mhal_CEC_ConfigWakeUp"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 30 / 188.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 209; semboller: 753.
- Xref: 3549; analizde call tipli xref: 0.
- Computed-call instruction: 836 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/900f66ee625a0a2c4db8fca424f76d0076fbbbcc01721cb46d0314e3c2a5ad99/functions.jsonl) · [Xref](../../../analiz/native/system-modules/900f66ee625a0a2c4db8fca424f76d0076fbbbcc01721cb46d0314e3c2a5ad99/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/900f66ee625a0a2c4db8fca424f76d0076fbbbcc01721cb46d0314e3c2a5ad99/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/900f66ee625a0a2c4db8fca424f76d0076fbbbcc01721cb46d0314e3c2a5ad99/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f308b18` | `mhal_CEC_init_riu_base` | [C](../../../analiz/native/system-modules/900f66ee625a0a2c4db8fca424f76d0076fbbbcc01721cb46d0314e3c2a5ad99/2f308b18.c) |
| `2f308b30` | `mhal_CEC_HeaderSwap` | [C](../../../analiz/native/system-modules/900f66ee625a0a2c4db8fca424f76d0076fbbbcc01721cb46d0314e3c2a5ad99/2f308b30.c) |
| `2f308ce0` | `mhal_CEC_IsMessageReceived` | [C](../../../analiz/native/system-modules/900f66ee625a0a2c4db8fca424f76d0076fbbbcc01721cb46d0314e3c2a5ad99/2f308ce0.c) |
| `2f308fbc` | `mhal_CEC_TxStatus` | [C](../../../analiz/native/system-modules/900f66ee625a0a2c4db8fca424f76d0076fbbbcc01721cb46d0314e3c2a5ad99/2f308fbc.c) |
| `2f308d00` | `mhal_CEC_ReceivedMessageLen` | [C](../../../analiz/native/system-modules/900f66ee625a0a2c4db8fca424f76d0076fbbbcc01721cb46d0314e3c2a5ad99/2f308d00.c) |
| `2f308fe4` | `mhal_CEC_SetRetryCount` | [C](../../../analiz/native/system-modules/900f66ee625a0a2c4db8fca424f76d0076fbbbcc01721cb46d0314e3c2a5ad99/2f308fe4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
