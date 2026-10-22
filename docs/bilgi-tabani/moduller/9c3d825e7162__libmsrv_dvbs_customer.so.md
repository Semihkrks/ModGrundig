# `07_MSLIB/libmsrv_dvbs_customer.so`

SHA-256: `9c3d825e7162bb36495c9e74ddc345d151e4b8e51e3190f822d25e607b7cd9ed`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 327428 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 25, "symbol_examples": ["_ZN15MSrv_DTV_Player11ChangeAudioEh", "_ZN15MSrv_DTV_Player11UpdateAudioEv", "_ZN15MSrv_DTV_Player16SwitchAudioTrackEh", "_ZN19MSrv_DTV_Player_DVB12GetAudioInfoER17ST_DTV_AUDIO_INFO", "_ZN19MSrv_DTV_Player_DVB12PinEventMuteEhm", "_ZN19MSrv_DTV_Player_DVB12SetAudioModeE26EN_MSRV_DTV_SET_AUDIO_MODE", "_ZN19MSrv_DTV_Player_DVB12SetDTVAVMuteEh", "_ZN19MSrv_DTV_Player_DVB13GetScreenMuteEv", "_ZN19MSrv_DTV_Player_DVB15GetAdAudioIndexERK16_DVB_PROGRAMINFOhPh", "_ZN19MSrv_DTV_Player_DVB17DoProgChangeAudioEhhh", "_ZN19MSrv_DTV_Player_DVB17DoProgUpdateAudioEh", "_ZN19MSrv_DTV_Player_DVB17GetAudioTrackInfoER17ST_DTV_AUDIO_INFO", "_ZN19MSrv_DTV_Player_DVB19SetCurrentAudioModeEh", "_ZN19MSrv_DTV_Player_DVB19SetCurrentAudioModeEh10AUDIO_MODE", "_ZN19MSrv_DTV_Player_DVB20GetAVMonitorMuteFlagERm", "_ZN19MSrv_DTV_Player_DVB20GetDefaultAudioIndexERK16_DVB_PROGRAMINFO"], "examples_are_complete": false}, {"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["_ZN29MSrv_DTV_Player_DVBS_Customer15ProcessKeyInputEh", "_ZN29MSrv_DTV_Player_DVBS_Customer29TuneToCAMKeyUpdateTransponderEv"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 33, "symbol_examples": ["_ZN11MSrv_Player26GetSwitchSourceLockWinFlagEv", "_ZN11MSrv_Player26SetSwitchSourceLockWinFlagEh", "_ZN15MSrv_DTV_Player11StandbyScanEv", "_ZN15MSrv_DTV_Player16StartStandbyScanEv", "_ZN19MSrv_DTV_Player_DVB16GetDTVSourceTypeEv", "_ZN19MSrv_DTV_Player_DVB16OAD_StandbyCheckEv", "_ZN19MSrv_DTV_Player_DVB17OADStartInStandbyEv", "_ZN19MSrv_DTV_Player_DVB17_DoOADStandbyModeEv", "_ZN19MSrv_DTV_Player_DVB20OAD_CheckAfterWakeUpEv", "_ZN19MSrv_DTV_Player_DVB22IsOadActiveStandbyModeEv", "_ZN19MSrv_DTV_Player_DVB22IsSchOADFoundInStandbyEv", "_ZN19MSrv_DTV_Player_DVB25OAD_AcceptStandbyDownloadEv", "_ZN19MSrv_DTV_Player_DVB25OAD_RejectStandbyDownloadEv", "_ZN20MSrv_DTV_Player_DVBS11SetLNBPowerE18MS_EN_LNBPWR_ONOFF", "_ZN25MSrv_DTV_DVB_OAD_Customer32OAD_ResetStandbyDownloadSettingsEv", "_ZN25MW_DTV_Scan_DVBS_Customer19StartSGTStandbyScanEv"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 9, "symbol_examples": ["_ZN11MSrv_Player13RefreshWindowEv", "_ZN19MSrv_DTV_Player_DVB16SetDisplayWindowERN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEh", "_ZN19MSrv_DTV_Player_DVB17SetPlaybackWindowEPN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEtt", "_ZN19MSrv_DTV_Player_DVB23SetDisplayWindowForAppsERN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEh", "_ZN19MSrv_DTV_Player_DVB23Set_SetWindow_Mute_FlagEh", "_ZN25MW_DTV_Scan_DVBS_Customer28ManualTuningUIGetTpTempValueEP19MS_TRASPONDER_PARAM", "_ZN25MW_DTV_Scan_DVBS_Customer28ManualTuningUISetTpTempValueEP19MS_TRASPONDER_PARAM", "_ZN35MW_DTV_FREQUENCYTABLE_DVBS_Customer10LoadBitmapE8BMP_TYPE", "_ZN35MW_DTV_FREQUENCYTABLE_DVBS_Customer10SaveBitmapE8BMP_TYPE"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 42, "symbol_examples": ["_ZN19MSrv_Control_common21GetMSrvSystemDatabaseEv", "_ZN19MSrv_DTV_Player_DVB13ChangeSettingE22EN_SETTING_CHANGE_TYPE", "_ZN19MSrv_DTV_Player_DVB29SetDefaultCoutrySystemSettingE14MEMBER_COUNTRY", "_ZN20MSrv_DTV_Player_DVBS11GetSCIFInfoER17MS_SCIF_CONFIG_DB", "_ZN20MSrv_DTV_Player_DVBS14UpdateSCIFInfoER17MS_SCIF_CONFIG_DB", "_ZN20MSrv_DTV_Player_DVBS16CiTuneSatSettingER24ST_DTV_CI_TUNING_CONTENT", "_ZN20MSrv_System_Database12GetSatOpModeEv", "_ZN20MSrv_System_Database12SetSatOpModeEh", "_ZN20MSrv_System_Database13GetSatFavModeEv", "_ZN20MSrv_System_Database13SetSatFavModeE11EN_FAV_TYPE", "_ZN20MSrv_System_Database14GetOadDownInfoEP15ST_OAD_SETTINGS", "_ZN20MSrv_System_Database14GetSatOperatorEv", "_ZN20MSrv_System_Database14GetSatUnicableEP26ST_SETTING_UNICABLE_SYSTEM", "_ZN20MSrv_System_Database14SetOadDownInfoEP15ST_OAD_SETTINGS", "_ZN20MSrv_System_Database14SetSatOperatorE21EN_SATELLITE_PLATFORM", "_ZN20MSrv_System_Database15GetSatOpCiCamIdEv"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libmsrv_dvbs.so`, `libutilities.so`, `libdirectfb-1.4.so.0`, `librt.so.1`, `libpthread.so.0`, `libdirect-1.4.so.0`, `libMStarSDK.so`, `libMStarSDK_customer.so`, `libfreetype.so.6`, `libMLog.so`, `libmuf.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 823 / 489.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 1178; semboller: 5892.
- Xref: 14093; analizde call tipli xref: 0.
- Computed-call instruction: 2564 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/9c3d825e7162bb36495c9e74ddc345d151e4b8e51e3190f822d25e607b7cd9ed/functions.jsonl) · [Xref](../../../analiz/native/system-modules/9c3d825e7162bb36495c9e74ddc345d151e4b8e51e3190f822d25e607b7cd9ed/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/9c3d825e7162bb36495c9e74ddc345d151e4b8e51e3190f822d25e607b7cd9ed/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/9c3d825e7162bb36495c9e74ddc345d151e4b8e51e3190f822d25e607b7cd9ed/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2e96eb14` | `MW_DTV_Scan_DVBS_Customer::SetOPVariableInit` | [C](../../../analiz/native/system-modules/9c3d825e7162bb36495c9e74ddc345d151e4b8e51e3190f822d25e607b7cd9ed/2e96eb14.c) |
| `2e96a110` | `MW_DTV_FrontEnd_DVBS_Customer::UpdateSingleCablePassword` | [C](../../../analiz/native/system-modules/9c3d825e7162bb36495c9e74ddc345d151e4b8e51e3190f822d25e607b7cd9ed/2e96a110.c) |
| `2e95e164` | `MSrv_DTV_Player_DVBS_Customer::DoesChannelBelongToSat` | [C](../../../analiz/native/system-modules/9c3d825e7162bb36495c9e74ddc345d151e4b8e51e3190f822d25e607b7cd9ed/2e95e164.c) |
| `2e969cf8` | `MW_DTV_FrontEnd_DVBS_Customer::FE_LNBPower_Text` | [C](../../../analiz/native/system-modules/9c3d825e7162bb36495c9e74ddc345d151e4b8e51e3190f822d25e607b7cd9ed/2e969cf8.c) |
| `2e96a128` | `MW_DTV_FrontEnd_DVBS_Customer::ODU_PowerOff` | [C](../../../analiz/native/system-modules/9c3d825e7162bb36495c9e74ddc345d151e4b8e51e3190f822d25e607b7cd9ed/2e96a128.c) |
| `2e96a3c4` | `MW_DTV_FrontEnd_DVBS_Customer::Channel_scan_extend_indicator` | [C](../../../analiz/native/system-modules/9c3d825e7162bb36495c9e74ddc345d151e4b8e51e3190f822d25e607b7cd9ed/2e96a3c4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
