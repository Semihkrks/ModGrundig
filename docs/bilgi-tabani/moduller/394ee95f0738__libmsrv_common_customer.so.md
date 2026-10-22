# `07_MSLIB/libmsrv_common_customer.so`

SHA-256: `394ee95f07383231c9cc1019d9d1fb8eb3c8309ae68fe2d3186ddf19c51dae39`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 969280 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 268, "symbol_examples": ["MApi_AUDIO_SetMute", "_Z19cec_Api_IsARCMuteOnv", "_ZN10MSrv_Video11setUrsaMuteE14URSA_MUTE_TYPEt", "_ZN10mapi_audio11GetInstanceEv", "_ZN10mapi_audio12SND_SetParamE21Sound_SET_PARAM_Type_ss", "_ZN10mapi_audio17SND_ProcessEnableE18Sound_ENABLE_Type_h", "_ZN10mapi_audio18SND_EnableSurroundEh", "_ZN10mapi_audio19DECODER_SetMpegInfoE20Audio_MPEG_infoType_mm", "_ZN10mapi_audio19GetOutputSourceInfoEP31MSAPI_AUDIO_OUTPORT_SOURCE_INFO", "_ZN10mapi_audio19HDMI_ARC_PINControlE22MAPI_INPUT_SOURCE_TYPEhh", "_ZN10mapi_audio19SetOutputSourceInfoEP31MSAPI_AUDIO_OUTPORT_SOURCE_INFO", "_ZN10mapi_audio21DECODER_SetOutputModeE21En_DVB_soundModeType_", "_ZN10mapi_audio31DIGITAL_OUT_SetDeviceCapabilityE19AudioSDK_CODEC_TYPEP22Digital_Out_Capability", "_ZN12MSrv_SSSound11SetHPVolumeEh", "_ZN12MSrv_SSSound12SND_GetParamE21Sound_GET_PARAM_Type_s", "_ZN12MSrv_SSSound12SetSPDIFmodeE11SPDIF_TYPE_"], "examples_are_complete": false}, {"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["_ZN14MWindowManager14FlushKeyEventsEv", "_ZN16MW_CEC_IrWrapper11PowerUpInitEPFv17Cec_Ir_Key_Pair_sE", "_ZN22MSrv_ProductKeyManager10GetKeySizeE8keyNames", "_ZN27MSrv_MountNotifier_Customer16GetKeyboardCountEv"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 385, "symbol_examples": ["MApi_CEC_TxSendMsg", "POWER_MANAGER_TAG", "_Z19cec_Api_IsARCMuteOnv", "_Z19cec_Api_PowerUpInitv", "_Z19cec_Api_UserCommand17Cec_UserCommand_ePKv", "_Z19cec_Api_isARCActivev", "_Z25cec_Api_ScheduledBySystemv", "_Z26cec_Api_IsCECInitCompletedv", "_Z31cec_Api_DeviceDiscover_DevCountv", "_Z45cec_Api_GetSourceIdCorrespondingToGivenPhyAdrPK20CecPhysicalAddress_s", "_ZN10MSrv_Timer19SetTVPowerDoneTimerEm", "_ZN10SystemInfo23SetHDMIEDIDInfoSettingsEv", "_ZN10SystemInfo31SetHDMIEDIDInfoSet_ForSADUpdateEv", "_ZN10mapi_audio19HDMI_ARC_PINControlE22MAPI_INPUT_SOURCE_TYPEhh", "_ZN11MSrv_Player26GetSwitchSourceLockWinFlagEv", "_ZN11MSrv_Player26SetSwitchSourceLockWinFlagEh"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 40, "symbol_examples": ["DirectFBErrorFatal", "HOTEL_LOGO_PATH", "_ZN10mapi_audio31DIGITAL_OUT_SetDeviceCapabilityE19AudioSDK_CODEC_TYPEP22Digital_Out_Capability", "_ZN11MSrv_Player23SetDisplayWindowForAppsERN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEh", "_ZN14MSrv_AV_Player13RefreshWindowEv", "_ZN14MSrv_PC_Player13RefreshWindowEv", "_ZN14MSrv_SV_Player9CalWSSWinEN16mapi_vd_datatype17ASPECT_RATIO_TYPEEPN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEPNS2_22ST_MAPI_VIDEO_ARC_INFOE", "_ZN14MWindowManager14FlushKeyEventsEv", "_ZN14MWindowManager16CheckInputEventsEv", "_ZN16MSrv_COMP_Player13RefreshWindowEv", "_ZN16MSrv_HDMI_Player17SetOverscanFromDBEPP25ST_MAPI_VIDEO_WINDOW_INFOh", "_ZN17ArSrvPowerManager19ShowHotelTVBootLogoEv", "_ZN17MSrv_SCART_Player17SetOverscanFromDBEPP25ST_MAPI_VIDEO_WINDOW_INFOh", "_ZN19MSrv_Control_common24GetWindowInputSourceTypeE15MAPI_SCALER_WIN", "_ZN19mapi_audio_customer17GetAudioDECStatusEP17AudioSDKDecStatusS1_", "_ZN20MSrv_System_Database10GetFactOSDEv"], "examples_are_complete": false}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 154, "symbol_examples": ["_ZN10Clonerplug23Clonerplug_KeepSettingsE22USB_Cloner_Selection_e", "_ZN10Clonerplug26Clonerplug_RestoreSettingsE22USB_Cloner_Selection_e", "_ZN10MSrv_Timer22IsEPGTimerSettingValidERK23ST_EPG_EVENT_TIMER_INFO", "_ZN10SystemInfo23SetHDMIEDIDInfoSettingsEv", "_ZN14MSrv_PC_Player18reorderModeSettingEv", "_ZN15MSrv_Control_TV18GetMSrvAtvDatabaseE14EN_ATV_DB_TYPE", "_ZN15MSrv_Control_TV18GetMSrvAtvDatabaseEv", "_ZN17MSrv_CEC_Customer14IsARCsettingONEv", "_ZN18MW_CEC_MainWrapper14IsARCsettingONEv", "_ZN19MSrv_Control_common21GetMSrvSystemDatabaseEv", "_ZN19MSrv_DTV_Player_DVB20GetDefaultAudioIndexEP9_AUD_INFO12_AUD_SETTINGh", "_ZN19MSrv_Timer_Customer21ReconfigTimerFromListEmh", "_ZN19mapi_audio_customer20SetScalingParametersE22MAPI_INPUT_SOURCE_TYPEP25MS_SOUND_SCALING_SETTINGS", "_ZN19mapi_audio_customer23SetATVScalingParametersEP25MS_SOUND_SCALING_SETTINGS", "_ZN19mapi_audio_customer23SetDTVScalingParametersEP25MS_SOUND_SCALING_SETTINGS", "_ZN19mapi_audio_customer23SetUSBScalingParametersEP25MS_SOUND_SCALING_SETTINGS13MM_AUDIO_TYPE"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libar_cec.so`, `libar_MegaDCR.so`, `libar_cloner.so`, `libutilities.so`, `libdirectfb-1.4.so.0`, `librt.so.1`, `libpthread.so.0`, `libdirect-1.4.so.0`, `libMStarSDK.so`, `libMStarSDK_customer.so`, `libfreetype.so.6`, `libMLog.so`, `libmuf.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 1341 / 1683.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 2724; semboller: 20342.
- Xref: 53462; analizde call tipli xref: 0.
- Computed-call instruction: 13247 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/394ee95f07383231c9cc1019d9d1fb8eb3c8309ae68fe2d3186ddf19c51dae39/functions.jsonl) · [Xref](../../../analiz/native/system-modules/394ee95f07383231c9cc1019d9d1fb8eb3c8309ae68fe2d3186ddf19c51dae39/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/394ee95f07383231c9cc1019d9d1fb8eb3c8309ae68fe2d3186ddf19c51dae39/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/394ee95f07383231c9cc1019d9d1fb8eb3c8309ae68fe2d3186ddf19c51dae39/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2df7ab1c` | `MSrv_CEC_Customer::PreventARCPopUp` | [C](../../../analiz/native/system-modules/394ee95f07383231c9cc1019d9d1fb8eb3c8309ae68fe2d3186ddf19c51dae39/2df7ab1c.c) |
| `2dfbcd58` | `MW_Channel_DB_XML_Builder::ConvertTVPolarityToXML` | [C](../../../analiz/native/system-modules/394ee95f07383231c9cc1019d9d1fb8eb3c8309ae68fe2d3186ddf19c51dae39/2dfbcd58.c) |
| `2df76434` | `ArSrvPowerManager::ArSrvPowerManager` | [C](../../../analiz/native/system-modules/394ee95f07383231c9cc1019d9d1fb8eb3c8309ae68fe2d3186ddf19c51dae39/2df76434.c) |
| `2df76448` | `ArSrvPowerManager::ArSrvPowerManager` | [C](../../../analiz/native/system-modules/394ee95f07383231c9cc1019d9d1fb8eb3c8309ae68fe2d3186ddf19c51dae39/2df76448.c) |
| `2dfe28f0` | `UsbDeviceManager::getUsbDeviceCount` | [C](../../../analiz/native/system-modules/394ee95f07383231c9cc1019d9d1fb8eb3c8309ae68fe2d3186ddf19c51dae39/2dfe28f0.c) |
| `2dfe2950` | `UsbDevice::getDiskPartitionCount` | [C](../../../analiz/native/system-modules/394ee95f07383231c9cc1019d9d1fb8eb3c8309ae68fe2d3186ddf19c51dae39/2dfe2950.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
