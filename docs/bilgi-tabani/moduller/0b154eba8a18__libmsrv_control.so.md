# `07_MSLIB/libmsrv_control.so`

SHA-256: `0b154eba8a18cda242d3a1efafb74ca576bfb35bf0c6b9be38fc13fe16e518ea`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 260032 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 52, "symbol_examples": ["_ZN10mapi_audio15IsAudioInitDoneEv", "_ZN10mapi_audio16SPDIF_UI_SetModeE11SPDIF_TYPE_", "_ZN10mapi_audio18DECODER_SetAC3InfoE19Audio_AC3_infoType_mm", "_ZN10mapi_audio20SND_EnableAutoVolumeEh", "_ZN10mapi_audio9IsMadLockEv", "_ZN12MSrv_Control12_ScaleAudio_Ev", "_ZN12MSrv_Control16TurnOnPanelAudioEv", "_ZN12MSrv_Control25GetZeroBootStatusforAudioEv", "_ZN12MSrv_Control25SetZeroBootStatusforAudioEh", "_ZN12MSrv_SSSound10InitializeEv", "_ZN12MSrv_SSSound13GetMuteStatusE27MAPI_SOUND_MUTE_STATUS_TYPE", "_ZN12MSrv_SSSound13SetMuteStatusE17SSSOUND_MUTE_TYPEh25MSRV_AUDIO_PROCESSOR_TYPE", "_ZN12MSrv_SSSound13SetSPDIFDelayEm", "_ZN12MSrv_SSSound16SetPreScaleTableE22MAPI_INPUT_SOURCE_TYPEh", "_ZN12MSrv_SSSound17SetAbsoluteVolumeEv", "_ZN12MSrv_SSSound18SetSNDSpeakerDelayEm"], "examples_are_complete": false}, {"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 8, "symbol_examples": ["_ZN12MSrv_Control15GetIRPowerOnKeyEv", "_ZN12MSrv_Control26STRWakeUpWithRemoteControlEv", "_ZN14MWindowManager14FlushKeyEventsEv", "_ZN19MSrv_Control_common13SendIRKeyStopEv", "_ZN19MSrv_Control_common14SendIRKeyStartEv", "_ZN19MSrv_Control_common9SendIRKeyEl", "_ZN20MSrv_System_Database13GetKeypadLockEv", "_ZN20MSrv_System_Database24GetFactorySettingRC5TypeEv"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 96, "symbol_examples": ["GetIRPowerupKey", "_ZN11mapi_system13IsWakeUpByRTCEv", "_ZN11mapi_system16QueryPowerOnModeEv", "_ZN11mapi_system17QueryWakeupSourceEv", "_ZN11mapi_system9PowerDownEP8PM_Cfg_th", "_ZN12MSrv_Control10SwitchHDMIEh", "_ZN12MSrv_Control12IsWakeUpByIREv", "_ZN12MSrv_Control15GetIRPowerOnKeyEv", "_ZN12MSrv_Control17GetARCpowerUpTimeEv", "_ZN12MSrv_Control17NotifyAfterWakeUpEv", "_ZN12MSrv_Control18ARCpowerUpTimeFlagE", "_ZN12MSrv_Control18FakeStandby2NormalEv", "_ZN12MSrv_Control18Normal2FakeStandbyEv", "_ZN12MSrv_Control18STRScheduledWakeUpEv", "_ZN12MSrv_Control19m_isFastBootStandbyE", "_ZN12MSrv_Control20isARCDevicePoweredUpE"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 20, "symbol_examples": ["DirectFBGetGOPDst", "DirectFBSetBootLogoPatch", "DirectFBSetGOPDst", "_ZN14MWindowManager14FlushKeyEventsEv", "_ZN16MSrv_Control_DVB35setM_enAutoScartRecordPreSourceTypeE22MAPI_INPUT_SOURCE_TYPES0_", "_ZN19MSrv_Control_common13RefreshWindowE15MAPI_SCALER_WIN", "_ZN19MSrv_Control_common14FinishBootlogoEv", "_ZN19MSrv_Control_common14SurfaceCreatorEPP17_IDirectFBSurfacemm21DFBSurfacePixelFormat", "_ZN19MSrv_Control_common14SurfaceDeletorEPP17_IDirectFBSurface", "_ZN19MSrv_Control_common18CreateJPGThumbnailEPP23_IDirectFBImageProviderPP17_IDirectFBSurface21DFBSurfacePixelFormatPjjiihhhhh", "_ZN19MSrv_Control_common20ImageproviderDeletorEPP23_IDirectFBImageProvider", "_ZN19MSrv_Control_common20IsProgramGuideEnableEv", "_ZN19MSrv_Control_common20SurfaceMirrorProcessEP17_IDirectFBSurface", "_ZN19MSrv_Control_common20WritePowerOnLogoModeEm", "_ZN19MSrv_Control_common21GetEnvPowerOnLogoModeEv", "_ZN19MSrv_Control_common21SetEnvPowerOnLogoModeE12EN_LOGO_MODE"], "examples_are_complete": false}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 37, "symbol_examples": ["_ZN11mapi_system13PM51PWMConfigEP18MAPI_PWM_SimIR_CFG", "_ZN12MSrv_Control19UartSetting_StopBitEh", "_ZN12MSrv_Control20UartSetting_BaudRateE17EN_UART_BAUD_RATE", "_ZN12MSrv_Control23UartSetting_ParityCheckE25EN_UART_PARITY_CHECK_TYPE", "_ZN12MSrv_Control25UartSetting_CharacterSizeE22EN_UART_CHARACTER_SIZE", "_ZN15MSrv_Control_TV18GetMSrvAtvDatabaseE14EN_ATV_DB_TYPE", "_ZN15MSrv_Control_TV18GetMSrvAtvDatabaseEv", "_ZN19MSrv_Control_common13GetBootConfigEv", "_ZN19MSrv_Control_common13PM51PWMConfigEP18MAPI_PWM_SimIR_CFG", "_ZN19MSrv_Control_common18ResetForOADUpgradeEP22ST_OAD_UPDGRADE_CONFIG", "_ZN19MSrv_Control_common21GetMSrvSystemDatabaseEv", "_ZN19MSrv_Control_common30GetMSrvSystemDatabase_CustomerEv", "_ZN20MSrv_System_Database12GetFactCecOnEv", "_ZN20MSrv_System_Database13GetARCSettingEv", "_ZN20MSrv_System_Database13GetESDRestartEv", "_ZN20MSrv_System_Database13GetFactDualCIEv"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libjpeg.so.62`, `libutilities.so`, `libdirectfb-1.4.so.0`, `librt.so.1`, `libpthread.so.0`, `libdirect-1.4.so.0`, `libMStarSDK.so`, `libMStarSDK_customer.so`, `libfreetype.so.6`, `libMLog.so`, `libmuf.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 469 / 494.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 839; semboller: 5382.
- Xref: 13290; analizde call tipli xref: 0.
- Computed-call instruction: 3601 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/0b154eba8a18cda242d3a1efafb74ca576bfb35bf0c6b9be38fc13fe16e518ea/functions.jsonl) · [Xref](../../../analiz/native/system-modules/0b154eba8a18cda242d3a1efafb74ca576bfb35bf0c6b9be38fc13fe16e518ea/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/0b154eba8a18cda242d3a1efafb74ca576bfb35bf0c6b9be38fc13fe16e518ea/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/0b154eba8a18cda242d3a1efafb74ca576bfb35bf0c6b9be38fc13fe16e518ea/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2ea9aba8` | `MSrv_Control_common::GetARCpowerUpTime` | [C](../../../analiz/native/system-modules/0b154eba8a18cda242d3a1efafb74ca576bfb35bf0c6b9be38fc13fe16e518ea/2ea9aba8.c) |
| `2eaa3880` | `MSrv_Control_common::UpdatePQiniFiles` | [C](../../../analiz/native/system-modules/0b154eba8a18cda242d3a1efafb74ca576bfb35bf0c6b9be38fc13fe16e518ea/2eaa3880.c) |
| `2eaa3914` | `MSrv_Control_common::UpdatePQParameterViaUsbKey` | [C](../../../analiz/native/system-modules/0b154eba8a18cda242d3a1efafb74ca576bfb35bf0c6b9be38fc13fe16e518ea/2eaa3914.c) |
| `2eaa646c` | `MSrv_Control_common::QueryPowerOnMode` | [C](../../../analiz/native/system-modules/0b154eba8a18cda242d3a1efafb74ca576bfb35bf0c6b9be38fc13fe16e518ea/2eaa646c.c) |
| `2ea9e8f4` | `MSrv_Control_common::APVolumeDown` | [C](../../../analiz/native/system-modules/0b154eba8a18cda242d3a1efafb74ca576bfb35bf0c6b9be38fc13fe16e518ea/2ea9e8f4.c) |
| `2ea9e934` | `MSrv_Control_common::APVolumeUp` | [C](../../../analiz/native/system-modules/0b154eba8a18cda242d3a1efafb74ca576bfb35bf0c6b9be38fc13fe16e518ea/2ea9e934.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
