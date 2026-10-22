# `07_MSLIB/libMStarSDK_customer.so`

SHA-256: `4ebd5fc038a843b26c03b6cb6b44b5e9052820bea388c5d4fc1913b840e83949`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 1061044 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 351, "symbol_examples": ["MApi_AUDIO_EnableBalance", "MApi_AUDIO_EnableDACSwap", "MApi_AUDIO_EnableEQ", "MApi_AUDIO_EnablePEQ", "MApi_AUDIO_EnableTone", "MApi_AUDIO_GetAC3PInfo", "MApi_AUDIO_GetAnalogConfig", "MApi_AUDIO_GetAudioInfo2", "MApi_AUDIO_GetCommAudioInfo", "MApi_AUDIO_GetCommand", "MApi_AUDIO_GetDecodeSystem", "MApi_AUDIO_HDMI_GetNonpcmFlag", "MApi_AUDIO_HDMI_RX_GetNonPCM", "MApi_AUDIO_HDMI_RX_SetNonpcm", "MApi_AUDIO_HDMI_Tx_SetMute", "MApi_AUDIO_I2S_SetMode"], "examples_are_complete": false}, {"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 5, "symbol_examples": ["MDrv_HDCP_initproductionkey", "_ZN18ArPanelManager_ini14GetRC5WaitTimeEv", "_ZN18ArPanelManager_ini14SetRC5WaitTimeEt", "_ZN18ArPanelManager_ini25GetColorAnalyzerSourceRC5Ev", "_ZN18ArPanelManager_ini25SetColorAnalyzerSourceRC5Eh"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 93, "symbol_examples": ["HDMIBekoOverscanOffset", "MApi_AUDIO_HDMI_GetNonpcmFlag", "MApi_AUDIO_HDMI_RX_GetNonPCM", "MApi_AUDIO_HDMI_RX_SetNonpcm", "MApi_AUDIO_HDMI_Tx_SetMute", "MApi_AUDIO_SetSourceInfo", "MApi_XC_DisableInputSource", "MApi_XC_SetHdmiSyncMode", "MDrv_AUDIO_SetPowerDownWait", "MDrv_HDMI_Get_AVIInfoFrameVer", "MDrv_HDMI_Get_ColorRange", "MDrv_HDMI_Get_Content_Type", "MDrv_HDMI_Get_ExtColorimetry", "MDrv_HDMI_Packet_Received", "MDrv_PQ_GetHDMI_PC_Status", "MDrv_PQ_SetHDMIInfo"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 43, "symbol_examples": ["MApi_AUDIO_SetDataCaptureSource", "MApi_XC_EnableMainWindow", "MApi_XC_EnableSubWindow", "MApi_XC_SetDispWindowColor", "MDrv_PQ_MWE_CloneWindow", "ScartBekoCaptureWindow", "ScartBekoCropWindow", "_Z25drvTAS5753_SetPWMCh1ToSDG22enumTAS5753_PWMCHTOSDG", "_Z25drvTAS5753_SetPWMCh2ToSDG22enumTAS5753_PWMCHTOSDG", "_Z25drvTAS5753_SetPWMCh3ToSDG22enumTAS5753_PWMCHTOSDG", "_Z25drvTAS5753_SetPWMCh4ToSDG22enumTAS5753_PWMCHTOSDG", "_ZN17mapi_pql_customer12SetMWEStatusENS_17MAPI_PQL_MWE_TYPEERKN17mapi_pql_datatype16MAPI_WINDOW_TYPEE", "_ZN18ArPanelManager_ini16GetLogoBacklightEv", "_ZN18ArPanelManager_ini16SetLogoBacklightEh", "_ZN18mapi_si_CDT_parser11GetLogoDataEPtPPh", "_ZN18mapi_si_dvb_parser20SI_CheckGuidanceDescEPK13DESC_GUIDANCEPh15MEMBER_LANGUAGE"], "examples_are_complete": false}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 37, "symbol_examples": ["MApi_AUDIO_GetAnalogConfig", "MApi_AUDIO_SetAnalogConfig", "MApi_PNL_MOD_OutputConfig_User", "MApi_XC_DLC_SetSetting_Ex", "MDrv_PQ_LoadCustomerSettings", "MDrv_PQ_LoadSettings", "MDrv_PQ_SkipDuplicatedSetting", "_ZN17mapi_pql_customer10LoadConfigEv", "_ZN18mapi_config_helper10Get2DArrayEPKcPPhii", "_ZN18mapi_config_helper5GetU8EPKcPh", "_ZN18mapi_config_helperC1EPKc", "_ZN18mapi_config_helperD1Ev", "_ZN19mapi_audio_customer16DoAfterSettingEQE16AMPLIFIER_DEVICE", "_ZN19mapi_audio_customer17DoAfterSettingDRCE16AMPLIFIER_DEVICE", "_ZN19mapi_audio_customer17DoBeforeSettingEQE16AMPLIFIER_DEVICE", "_ZN19mapi_audio_customer18DoBeforeSettingDRCE16AMPLIFIER_DEVICE"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `librt.so.1`, `libpthread.so.0`, `libMMAPInfo.so`, `libMStarSDK.so`, `libPQ.so`, `libPQ_cus.so`, `libutilities.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 671 / 2214.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 2523; semboller: 17423.
- Xref: 48672; analizde call tipli xref: 0.
- Computed-call instruction: 10463 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/4ebd5fc038a843b26c03b6cb6b44b5e9052820bea388c5d4fc1913b840e83949/functions.jsonl) · [Xref](../../../analiz/native/system-modules/4ebd5fc038a843b26c03b6cb6b44b5e9052820bea388c5d4fc1913b840e83949/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/4ebd5fc038a843b26c03b6cb6b44b5e9052820bea388c5d4fc1913b840e83949/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/4ebd5fc038a843b26c03b6cb6b44b5e9052820bea388c5d4fc1913b840e83949/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2dc61c94` | `mapi_audio_customer::GetAudioUSBDECStatus` | [C](../../../analiz/native/system-modules/4ebd5fc038a843b26c03b6cb6b44b5e9052820bea388c5d4fc1913b840e83949/2dc61c94.c) |
| `2dc42da0` | `ArPanelManager_ini::InitPanelWBAParameter` | [C](../../../analiz/native/system-modules/4ebd5fc038a843b26c03b6cb6b44b5e9052820bea388c5d4fc1913b840e83949/2dc42da0.c) |
| `2dc761a8` | `mapi_pql_customer::SetNetworkMMOnOff` | [C](../../../analiz/native/system-modules/4ebd5fc038a843b26c03b6cb6b44b5e9052820bea388c5d4fc1913b840e83949/2dc761a8.c) |
| `2dc761dc` | `mapi_pql_customer::UpdateMemformat` | [C](../../../analiz/native/system-modules/4ebd5fc038a843b26c03b6cb6b44b5e9052820bea388c5d4fc1913b840e83949/2dc761dc.c) |
| `2dc62a3c` | `mapi_audio_customer::GetDeviceCount` | [C](../../../analiz/native/system-modules/4ebd5fc038a843b26c03b6cb6b44b5e9052820bea388c5d4fc1913b840e83949/2dc62a3c.c) |
| `2dc5dd24` | `drvTAS5753_SetVolumeSlewRate` | [C](../../../analiz/native/system-modules/4ebd5fc038a843b26c03b6cb6b44b5e9052820bea388c5d4fc1913b840e83949/2dc5dd24.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
