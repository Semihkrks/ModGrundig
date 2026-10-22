# `07_MSLIB/libMStarSDK.so`

SHA-256: `00d147f752f92c9706e6496d0cda21de528e81f0c73cac54426b2618c17fe5fb`

Durum: **Ghidra indeks tamam; analiz süre sınırlı**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 5009264 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 469, "symbol_examples": ["DRV_VIF_BypassDBBAudioFilter", "DRV_VIF_SetSoundSystem", "MApi_AUDIO_ADSetMute", "MApi_AUDIO_ADVSND_SetParam", "MApi_AUDIO_ADVSOUND_ProcessEnable", "MApi_AUDIO_ADVSOUND_SubProcessEnable", "MApi_AUDIO_CheckInputRequest", "MApi_AUDIO_CheckPlayDone", "MApi_AUDIO_DigitalOut_SetDeviceCapability", "MApi_AUDIO_DmaReader_AllInput_Init", "MApi_AUDIO_DmaReader_Init", "MApi_AUDIO_DmaReader_WritePCM", "MApi_AUDIO_EnableAutoVolume", "MApi_AUDIO_EnableEQ", "MApi_AUDIO_EnableSurround", "MApi_AUDIO_FileEndDataHandle"], "examples_are_complete": false}, {"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 27, "symbol_examples": ["MDrv_IR_Config", "MDrv_IR_Init", "MDrv_PM_GetIRPowerOnKey", "MDrv_PM_PWM_IRRecord_Init", "MDrv_PM_PWM_IRRecord_Receive_Exit", "MDrv_PM_PWM_IRRecord_Receive_Require", "MDrv_PM_PWM_IRRecord_SetCallBackFunction", "MDrv_PM_PWM_IRRecord_Transmit", "_ZN11mapi_secure16secure_processor16_CmdSMbxToGetKeyEmht", "_ZN11mapi_secure16secure_processor6GetKeyEPK11ST_KEY_INFOm", "_ZN11mapi_secure6GetKeyEmPK11ST_KEY_INFO", "_ZN11mapi_system15GetIRPowerOnKeyEv", "_ZN11mapi_system20Load51_IR_InitializeEPK13PM_IrRegCfg_th", "_ZN11mapi_system20PM_PWM_IRRecord_InitEv", "_ZN11mapi_system24PM_PWM_IRRecord_TransmitEmt", "_ZN11mapi_system28PM_PWM_IRRecord_Receive_ExitEv"], "examples_are_complete": false}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 301, "symbol_examples": ["MApi_AUDIO_HDMI_GetNonpcmFlag", "MApi_AUDIO_HDMI_GetSynthFreq", "MApi_AUDIO_HDMI_RX_GetNonPCM", "MApi_AUDIO_HDMI_SetDownSample", "MApi_AUDIO_HDMI_TX_SetMode", "MApi_AUDIO_SetPowerOn", "MApi_CEC_CheckFrame", "MApi_CEC_ChkRxBuf", "MApi_CEC_ConfigWakeUp", "MApi_CEC_Enabled", "MApi_CEC_Exit", "MApi_CEC_GetCmdLen", "MApi_CEC_GetFifoIdx", "MApi_CEC_GetMsgCnt", "MApi_CEC_GetRxData", "MApi_CEC_Get_Header"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 171, "symbol_examples": ["DirectFBCreate", "DirectFBError", "DirectFBInit", "MApi_GFX_BeginDraw", "MApi_GFX_DrawLine", "MApi_GFX_DrawOval", "MApi_GFX_EndDraw", "MApi_XC_EnableWindow", "MApi_XC_FRC_SetWindow", "MApi_XC_GetCaptureWindow", "MApi_XC_OSDC_Control", "MApi_XC_OSDC_InitSetting", "MApi_XC_OSDC_SetOutVfreqx10", "MApi_XC_SetCaptureWindowHstart", "MApi_XC_SetCaptureWindowVstart", "MApi_XC_SetDispWindowColor"], "examples_are_complete": false}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 253, "symbol_examples": ["MApi_CEC_ConfigWakeUp", "MApi_GOP_SetConfig", "MApi_MOD_PVDD_Power_Setting", "MApi_PNL_MOD_OutputConfig_User", "MApi_SWI2C_Speed_Setting", "MApi_XC_OSDC_InitSetting", "MDrv_DSCMB_KLadder_SetConfig", "MDrv_IR_Config", "MDrv_MSPI_CLKConfig", "MDrv_MSPI_DCConfig", "MDrv_MasterSPI_CsPadConfig", "MDrv_MasterSPI_MaxClkConfig", "MDrv_PM_PWM_Config", "MDrv_SAR_Adc_Config", "MDrv_SAR_Config", "TT_CustomBehaviorConfig_GetCancelModeConfig"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `librt.so.1`, `libpthread.so.0`, `libapiACE.so`, `libapiAUDIO.so`, `libapiCEC.so`, `libapiDLC.so`, `libapiDMX.so`, `libapiGFX.so`, `libapiGOP.so`, `libapiJPEG.so`, `libapiPNL.so`, `libapiSWI2C.so`, `libapiVDEC.so`, `libapiXC.so`, `libdrvMSPI.so`, `libdrvAUDSP.so`, `libdrvAESDMA.so`, `libdrvCPU.so`, `libdrvDDC2BI.so`, `libdrvGPIO.so`, `libdrvHWI2C.so`, `libdrvIPAUTH.so`, `libdrvMVOP.so`, `libdrvPCMCIA.so`, `libdrvPM.so`, `libdrvPWM.so`, `libdrvPWS.so`, `libdrvRTC.so`, `libdrvSAR.so`, `libdrvSERFLASH.so`, `libdrvVBI.so`, `libdrvVE.so`, `libdrvWDT.so`, `liblinux.so`, `libdrvIR.so`, `libdrvSC.so`, `libdrvDEMOD.so`, `libMsFS.so`, `libdrvDSCMB.so`, `libdrvVIF.so`, `libdrvAVD.so`, `libapiHSL.so`, `libfastlz.so`, `libMLog.so`, `libfreetype.so.6`, `libpng.so.3`, `libz.so.1`, `libdlmalloc.so`, `libvdplayer.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 1338 / 9548.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 10730; semboller: 77670.
- Xref: 99391; analizde call tipli xref: 0.
- Computed-call instruction: 47375 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: True.

[Fonksiyonlar](../../../analiz/native/system-modules/00d147f752f92c9706e6496d0cda21de528e81f0c73cac54426b2618c17fe5fb/functions.jsonl) · [Xref](../../../analiz/native/system-modules/00d147f752f92c9706e6496d0cda21de528e81f0c73cac54426b2618c17fe5fb/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/00d147f752f92c9706e6496d0cda21de528e81f0c73cac54426b2618c17fe5fb/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/00d147f752f92c9706e6496d0cda21de528e81f0c73cac54426b2618c17fe5fb/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2caea1f8` | `mapi_demux_filter_common::SetChangeSourceCB` | [C](../../../analiz/native/system-modules/00d147f752f92c9706e6496d0cda21de528e81f0c73cac54426b2618c17fe5fb/2caea1f8.c) |
| `2cafd298` | `mapi_epgdb_ch::SetEventUpdated` | [C](../../../analiz/native/system-modules/00d147f752f92c9706e6496d0cda21de528e81f0c73cac54426b2618c17fe5fb/2cafd298.c) |
| `2cb5e34c` | `mapi_panel::setMuteColor` | [C](../../../analiz/native/system-modules/00d147f752f92c9706e6496d0cda21de528e81f0c73cac54426b2618c17fe5fb/2cb5e34c.c) |
| `2cb891b4` | `mapi_storage_spiflash::Finalize` | [C](../../../analiz/native/system-modules/00d147f752f92c9706e6496d0cda21de528e81f0c73cac54426b2618c17fe5fb/2cb891b4.c) |
| `2cb951e8` | `mapi_tuner::GetCableStatus` | [C](../../../analiz/native/system-modules/00d147f752f92c9706e6496d0cda21de528e81f0c73cac54426b2618c17fe5fb/2cb951e8.c) |
| `2cb99684` | `mapi_ursa::setMuteColor` | [C](../../../analiz/native/system-modules/00d147f752f92c9706e6496d0cda21de528e81f0c73cac54426b2618c17fe5fb/2cb99684.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
