# `07_MSLIB/libmsrv_dvbt_customer.so`

SHA-256: `58b171d77de192e33c0f098a1d10f307a75196b7953f1c7d8f5b0d7da574ee69`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 169488 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 24, "symbol_examples": ["_ZN15MSrv_DTV_Player11ChangeAudioEh", "_ZN15MSrv_DTV_Player11UpdateAudioEv", "_ZN15MSrv_DTV_Player16SwitchAudioTrackEh", "_ZN19MSrv_DTV_Player_DVB12GetAudioInfoER17ST_DTV_AUDIO_INFO", "_ZN19MSrv_DTV_Player_DVB12PinEventMuteEhm", "_ZN19MSrv_DTV_Player_DVB12SetAudioModeE26EN_MSRV_DTV_SET_AUDIO_MODE", "_ZN19MSrv_DTV_Player_DVB12SetDTVAVMuteEh", "_ZN19MSrv_DTV_Player_DVB13GetScreenMuteEv", "_ZN19MSrv_DTV_Player_DVB15GetAdAudioIndexERK16_DVB_PROGRAMINFOhPh", "_ZN19MSrv_DTV_Player_DVB17DoProgChangeAudioEhhh", "_ZN19MSrv_DTV_Player_DVB17DoProgUpdateAudioEh", "_ZN19MSrv_DTV_Player_DVB17GetAudioTrackInfoER17ST_DTV_AUDIO_INFO", "_ZN19MSrv_DTV_Player_DVB19SetCurrentAudioModeEh", "_ZN19MSrv_DTV_Player_DVB19SetCurrentAudioModeEh10AUDIO_MODE", "_ZN19MSrv_DTV_Player_DVB20GetAVMonitorMuteFlagERm", "_ZN19MSrv_DTV_Player_DVB20GetDefaultAudioIndexERK16_DVB_PROGRAMINFO"], "examples_are_complete": false}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 18, "symbol_examples": ["_ZN11MSrv_Player26GetSwitchSourceLockWinFlagEv", "_ZN11MSrv_Player26SetSwitchSourceLockWinFlagEh", "_ZN15MSrv_DTV_Player11StandbyScanEv", "_ZN15MSrv_DTV_Player16StartStandbyScanEv", "_ZN16MW_DTV_Scan_DVBT16StartStandbyScanEv", "_ZN19MSrv_DTV_Player_DVB16GetDTVSourceTypeEv", "_ZN19MSrv_DTV_Player_DVB16OAD_StandbyCheckEv", "_ZN19MSrv_DTV_Player_DVB17OADStartInStandbyEv", "_ZN19MSrv_DTV_Player_DVB17_DoOADStandbyModeEv", "_ZN19MSrv_DTV_Player_DVB20OAD_CheckAfterWakeUpEv", "_ZN19MSrv_DTV_Player_DVB22IsOadActiveStandbyModeEv", "_ZN19MSrv_DTV_Player_DVB22IsSchOADFoundInStandbyEv", "_ZN19MSrv_DTV_Player_DVB25OAD_AcceptStandbyDownloadEv", "_ZN19MSrv_DTV_Player_DVB25OAD_RejectStandbyDownloadEv", "_ZN21MSrv_Control_Customer15AdjustAntenna5VE23EN_MENU_5V_AntennaPower", "_ZN25MW_DTV_Scan_DVBT_Customer23HandleEvent_StandbyScanERK16MW_DVBT_ScanInfo"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 5, "symbol_examples": ["_ZN11MSrv_Player13RefreshWindowEv", "_ZN19MSrv_DTV_Player_DVB16SetDisplayWindowERN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEh", "_ZN19MSrv_DTV_Player_DVB17SetPlaybackWindowEPN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEtt", "_ZN19MSrv_DTV_Player_DVB23SetDisplayWindowForAppsERN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEh", "_ZN19MSrv_DTV_Player_DVB23Set_SetWindow_Mute_FlagEh"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 30, "symbol_examples": ["_ZN19MSrv_Control_common21GetMSrvSystemDatabaseEv", "_ZN19MSrv_DTV_Player_DVB13ChangeSettingE22EN_SETTING_CHANGE_TYPE", "_ZN19MSrv_DTV_Player_DVB29SetDefaultCoutrySystemSettingE14MEMBER_COUNTRY", "_ZN20MSrv_System_Database12GetAirOpModeEv", "_ZN20MSrv_System_Database12SetAirOpModeEh", "_ZN20MSrv_System_Database13GetAirFavModeEv", "_ZN20MSrv_System_Database13GetFavNetworkEv", "_ZN20MSrv_System_Database13SetAirFavModeE11EN_FAV_TYPE", "_ZN20MSrv_System_Database13SetFavNetworkEt", "_ZN20MSrv_System_Database14GetOadDownInfoEP15ST_OAD_SETTINGS", "_ZN20MSrv_System_Database14SetOadDownInfoEP15ST_OAD_SETTINGS", "_ZN20MSrv_System_Database15GetAirOpCiCamIdEv", "_ZN20MSrv_System_Database15SetAirOpCiCamIdEm", "_ZN20MSrv_System_Database16GetActiveAntennaEv", "_ZN20MSrv_System_Database16GetAirFilterTypeEv", "_ZN20MSrv_System_Database16SetAirFilterTypeEh"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libmsrv_dvbt.so`, `libutilities.so`, `libdirectfb-1.4.so.0`, `librt.so.1`, `libpthread.so.0`, `libdirect-1.4.so.0`, `libMStarSDK.so`, `libMStarSDK_customer.so`, `libfreetype.so.6`, `libMLog.so`, `libmuf.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 715 / 204.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 846; semboller: 3430.
- Xref: 6607; analizde call tipli xref: 0.
- Computed-call instruction: 1175 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/58b171d77de192e33c0f098a1d10f307a75196b7953f1c7d8f5b0d7da574ee69/functions.jsonl) · [Xref](../../../analiz/native/system-modules/58b171d77de192e33c0f098a1d10f307a75196b7953f1c7d8f5b0d7da574ee69/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/58b171d77de192e33c0f098a1d10f307a75196b7953f1c7d8f5b0d7da574ee69/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/58b171d77de192e33c0f098a1d10f307a75196b7953f1c7d8f5b0d7da574ee69/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2ee9bb1c` | `MW_DTV_Scan_DVBT_Customer::_AutoUpdateStoreCurrentProgInfo` | [C](../../../analiz/native/system-modules/58b171d77de192e33c0f098a1d10f307a75196b7953f1c7d8f5b0d7da574ee69/2ee9bb1c.c) |
| `2ee99958` | `MW_DTV_FREQUENCYTABLE_DVBT_Customer::GetPhysicalChannelInfoTableForFrance` | [C](../../../analiz/native/system-modules/58b171d77de192e33c0f098a1d10f307a75196b7953f1c7d8f5b0d7da574ee69/2ee99958.c) |
| `2ee99974` | `MW_DTV_FREQUENCYTABLE_DVBT_Customer::GetPhysicalChannelInfoTableForItaly_C` | [C](../../../analiz/native/system-modules/58b171d77de192e33c0f098a1d10f307a75196b7953f1c7d8f5b0d7da574ee69/2ee99974.c) |
| `2ee99990` | `MW_DTV_FREQUENCYTABLE_DVBT_Customer::GetPhysicalChannelInfoTableForNordic_SIII` | [C](../../../analiz/native/system-modules/58b171d77de192e33c0f098a1d10f307a75196b7953f1c7d8f5b0d7da574ee69/2ee99990.c) |
| `2ee999f0` | `MW_DTV_FREQUENCYTABLE_DVBT_Customer::GetPhysicalChannelInfoTableForNordic_VHF` | [C](../../../analiz/native/system-modules/58b171d77de192e33c0f098a1d10f307a75196b7953f1c7d8f5b0d7da574ee69/2ee999f0.c) |
| `2ee9bb00` | `MW_DTV_Scan_DVBT_Customer::_AutoUpdateRestoreCurrentProgInfo` | [C](../../../analiz/native/system-modules/58b171d77de192e33c0f098a1d10f307a75196b7953f1c7d8f5b0d7da574ee69/2ee9bb00.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
