# `07_MSLIB/libmsrv_dvb_customer.so`

SHA-256: `67b12c70234292c6afeffc489d91ae3101f95c2a4ff7fcc1f726bb4505e6e761`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 742028 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 24, "symbol_examples": ["_Z14_IsAudioChanget17AUDIO_DSP_SYSTEM_tS_", "_ZN10MSrv_CIMMI17CITurnPCMCIAPowerEh", "_ZN12CIAdaptation12PinEventMuteEhm", "_ZN12CIAdaptation13SetSPDIF_SCMSE22AUDIO_SPDIF_SCMS_MODE_", "_ZN12CIAdaptation18DigitalCopyProtectE22AUDIO_SPDIF_SCMS_MODE_", "_ZN12CIAdaptation18MuteAnalogueOutputEP14mapi_video_outh", "_ZN12CIAdaptation5SPDIFE22AUDIO_SPDIF_SCMS_MODE_", "_ZN12MSrv_SSSound17SetAbsoluteVolumeEv", "_ZN13MW_DTV_CM_DVB27SetCurrentProgAudioUserModeEh", "_ZN13MW_DTV_CM_DVB27SetCurrentProgAudioUserModeEh10AUDIO_MODE", "_ZN13MW_DTV_CM_DVB31SetCurrentProgAudioUserLanguageE15MEMBER_LANGUAGE", "_ZN13mapi_epgdb_ch16AddAudioLanguageE22EN_MAPI_PF_EVENT_INDEX25mapi_ISO639_Language_Code", "_ZN16MW_DTV_AVMonitor11GetMuteFlagERm", "_ZN16MW_DTV_AVMonitor11SetMuteFlagEhm", "_ZN16MW_DTV_AVMonitor9StopAudioEv", "_ZN16mapi_epgdb_event13SetAudioTrackEh"], "examples_are_complete": false}, {"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["_ZN19MSrv_CIMMI_Customer20UploadEncryptionKeysEP7mapi_ci"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 18, "symbol_examples": ["_ZN10MSrv_CIMMI17CITurnPCMCIAPowerEh", "_ZN12CIAdaptation19bIsCICAMPowerActiveE", "_ZN12CIAdaptation24CiEventCommandHcSiWakeUpEv", "_ZN16MSrv_DTV_DVB_OAD16OAD_StandbyCheckEv", "_ZN16MSrv_DTV_DVB_OAD22IsOadActiveStandbyModeEv", "_ZN22MW_DTV_CM_DVB_Customer22ClearStandbyUpdateFlagEh", "_ZN22MW_DTV_CM_DVB_Customer27IsServicesStandbyUpdateFlagEhhh", "_ZN22MW_DTV_CM_DVB_Customer28GetServicesStandbyUpdateFlagERSt6vectorIP16_DVB_PROGRAMINFOSaIS2_EEhhh", "_ZN22MW_DTV_CM_DVB_Customer29SetStandbyUpdateDeleteRequestEhhh", "_ZN22MW_OAD_Parser_Customer22IsSchOADFoundInStandbyEv", "_ZN22MW_OAD_Parser_Customer23SetSchOADFoundInStandbyEh", "_ZN25MSrv_DTV_DVB_OAD_Customer16DoOADStandbyModeEv", "_ZN25MSrv_DTV_DVB_OAD_Customer17_OAD_StandbyCheckEv", "_ZN25MSrv_DTV_DVB_OAD_Customer20OAD_CheckAfterWakeUpEv", "_ZN25MSrv_DTV_DVB_OAD_Customer22IsSchOADFoundInStandbyEv", "_ZN25MSrv_DTV_DVB_OAD_Customer25OAD_AcceptStandbyDownloadEv"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 14, "symbol_examples": ["_ZN16mapi_epgdb_event11SetGuidanceEPht", "_ZN18MW_DTV_Program_DVB26DistinguishNumberDuplicateEP12MW_DTV_CM_DBI16_DVB_PROGRAMINFO12_DVB_MUXINFO16_ST_DVB_SAT_INFO20_ST_DVB_NETWORK_INFOEhhtt", "_ZN18MW_DTV_Program_DVB28DistinguishNumberSameServiceEP12MW_DTV_CM_DBI16_DVB_PROGRAMINFO12_DVB_MUXINFO16_ST_DVB_SAT_INFO20_ST_DVB_NETWORK_INFOEh18MW_DVB_PARSER_TYPE14MEMBER_COUNTRY", "_ZN18MW_DTV_Program_DVB30DistinguishSDAndHDLCNDuplicateEP12MW_DTV_CM_DBI16_DVB_PROGRAMINFO12_DVB_MUXINFO16_ST_DVB_SAT_INFO20_ST_DVB_NETWORK_INFOEh", "_ZN18MW_DTV_Program_DVB32DistinguishNumberPresentOrAbsentEP12MW_DTV_CM_DBI16_DVB_PROGRAMINFO12_DVB_MUXINFO16_ST_DVB_SAT_INFO20_ST_DVB_NETWORK_INFOEh", "_ZN18mapi_si_dvb_parser20SI_CheckGuidanceDescEPK13DESC_GUIDANCEPh15MEMBER_LANGUAGE", "_ZN19MSrv_DTV_Player_DVB23_GetGuidanceDescriptionEP16MW_DTV_EPG_EVENTPtRhh12ST_TRIPLE_ID", "_ZN20MW_DVB_SI_PSI_Parser23_AddGuidanceInfoFromSdtEtttP14_GUIDANCE_INFO", "_ZN20MW_DVB_SI_PSI_Parser26GetGuidanceInfoByTripleIdsE12ST_TRIPLE_IDR14_GUIDANCE_INFO", "_ZN20MW_DVB_SI_PSI_Parser29_ResetGuidanceInfoByTripleIdsE12ST_TRIPLE_IDP14_GUIDANCE_INFO", "_ZN21MW_DTV_EPG_DVB_PARSER12FreeResourceERK16mapi_epgdb_ch_idNS_25EN_EPG_FREE_RESOURCE_MODEE", "_ZN27MW_DTV_SORTING_DVB_Customer14ClearResourcesEv", "_ZN29MW_DVB_SI_PSI_Parser_Customer22_SetTKGSCategoryBitmapEPt", "_ZN8MW_MHEG58IsDrawedEv"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 48, "symbol_examples": ["_ZN10MSrv_CIMMI23CheckCIPlusDebugSettingEv", "_ZN12CIAdaptation16CiTuneSatSettingER24ST_DTV_CI_TUNING_CONTENT", "_ZN12CIAdaptation17CISetDSCMBSettingEv", "_ZN15MSrv_Control_TV18GetMSrvAtvDatabaseE14EN_ATV_DB_TYPE", "_ZN15MSrv_Control_TV18GetMSrvAtvDatabaseEv", "_ZN19MSrv_Control_common21GetMSrvSystemDatabaseEv", "_ZN20MSrv_System_Database11SetFav1NameEPhh", "_ZN20MSrv_System_Database13GetFavNetworkEv", "_ZN20MSrv_System_Database13GetHotelAdminEv", "_ZN20MSrv_System_Database13GetSatLNBTypeEv", "_ZN20MSrv_System_Database14GetOadDownInfoEP15ST_OAD_SETTINGS", "_ZN20MSrv_System_Database14GetSatFilterIDEv", "_ZN20MSrv_System_Database14GetSatOperatorEv", "_ZN20MSrv_System_Database14SetSatFilterIDEh", "_ZN20MSrv_System_Database16GetFactHotelModeEv", "_ZN20MSrv_System_Database17AddChannelHistoryEP23ST_CHANNEL_HISTORY_DATA"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libmsrv_dvb.so`, `libutilities.so`, `libdirectfb-1.4.so.0`, `librt.so.1`, `libpthread.so.0`, `libdirect-1.4.so.0`, `libMStarSDK.so`, `libMStarSDK_customer.so`, `libfreetype.so.6`, `libMLog.so`, `libmuf.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 1129 / 890.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 1888; semboller: 15552.
- Xref: 41747; analizde call tipli xref: 0.
- Computed-call instruction: 7897 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/67b12c70234292c6afeffc489d91ae3101f95c2a4ff7fcc1f726bb4505e6e761/functions.jsonl) · [Xref](../../../analiz/native/system-modules/67b12c70234292c6afeffc489d91ae3101f95c2a4ff7fcc1f726bb4505e6e761/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/67b12c70234292c6afeffc489d91ae3101f95c2a4ff7fcc1f726bb4505e6e761/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/67b12c70234292c6afeffc489d91ae3101f95c2a4ff7fcc1f726bb4505e6e761/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2e180ae0` | `MW_DTV_SORTING_DVB_Customer::HasServiceCollidedLCN` | [C](../../../analiz/native/system-modules/67b12c70234292c6afeffc489d91ae3101f95c2a4ff7fcc1f726bb4505e6e761/2e180ae0.c) |
| `2e18f77c` | `MW_DVB_EPG_UPDATE_CONTROL::ReConnectCM` | [C](../../../analiz/native/system-modules/67b12c70234292c6afeffc489d91ae3101f95c2a4ff7fcc1f726bb4505e6e761/2e18f77c.c) |
| `2e156678` | `MSrv_ChannelManager_DVB_Customer::ProgramCycleTypeReMap` | [C](../../../analiz/native/system-modules/67b12c70234292c6afeffc489d91ae3101f95c2a4ff7fcc1f726bb4505e6e761/2e156678.c) |
| `2e1567b4` | `MSrv_ChannelManager_DVB_Customer::_CompareFav1` | [C](../../../analiz/native/system-modules/67b12c70234292c6afeffc489d91ae3101f95c2a4ff7fcc1f726bb4505e6e761/2e1567b4.c) |
| `2e1567c4` | `MSrv_ChannelManager_DVB_Customer::_CompareFav2` | [C](../../../analiz/native/system-modules/67b12c70234292c6afeffc489d91ae3101f95c2a4ff7fcc1f726bb4505e6e761/2e1567c4.c) |
| `2e1567d4` | `MSrv_ChannelManager_DVB_Customer::_CompareFav3` | [C](../../../analiz/native/system-modules/67b12c70234292c6afeffc489d91ae3101f95c2a4ff7fcc1f726bb4505e6e761/2e1567d4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
