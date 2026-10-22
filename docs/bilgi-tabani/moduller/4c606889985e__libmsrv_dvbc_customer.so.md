# `07_MSLIB/libmsrv_dvbc_customer.so`

SHA-256: `4c606889985e070d66c41cda9237c796b453c37ce8384d15ab7be3e719f56bf7`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 163912 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 24, "symbol_examples": ["_ZN15MSrv_DTV_Player11ChangeAudioEh", "_ZN15MSrv_DTV_Player11UpdateAudioEv", "_ZN15MSrv_DTV_Player16SwitchAudioTrackEh", "_ZN19MSrv_DTV_Player_DVB12GetAudioInfoER17ST_DTV_AUDIO_INFO", "_ZN19MSrv_DTV_Player_DVB12PinEventMuteEhm", "_ZN19MSrv_DTV_Player_DVB12SetAudioModeE26EN_MSRV_DTV_SET_AUDIO_MODE", "_ZN19MSrv_DTV_Player_DVB12SetDTVAVMuteEh", "_ZN19MSrv_DTV_Player_DVB13GetScreenMuteEv", "_ZN19MSrv_DTV_Player_DVB15GetAdAudioIndexERK16_DVB_PROGRAMINFOhPh", "_ZN19MSrv_DTV_Player_DVB17DoProgChangeAudioEhhh", "_ZN19MSrv_DTV_Player_DVB17DoProgUpdateAudioEh", "_ZN19MSrv_DTV_Player_DVB17GetAudioTrackInfoER17ST_DTV_AUDIO_INFO", "_ZN19MSrv_DTV_Player_DVB19SetCurrentAudioModeEh", "_ZN19MSrv_DTV_Player_DVB19SetCurrentAudioModeEh10AUDIO_MODE", "_ZN19MSrv_DTV_Player_DVB20GetAVMonitorMuteFlagERm", "_ZN19MSrv_DTV_Player_DVB20GetDefaultAudioIndexERK16_DVB_PROGRAMINFO"], "examples_are_complete": false}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 20, "symbol_examples": ["_ZN11MSrv_Player26GetSwitchSourceLockWinFlagEv", "_ZN11MSrv_Player26SetSwitchSourceLockWinFlagEh", "_ZN15MSrv_DTV_Player11StandbyScanEv", "_ZN15MSrv_DTV_Player16StartStandbyScanEv", "_ZN16MW_DTV_Scan_DVBC23StartStandbyNetworkScanEtN25mapi_demodulator_datatype19EN_CAB_CONSTEL_TYPEEmmt", "_ZN19MSrv_DTV_Player_DVB16GetDTVSourceTypeEv", "_ZN19MSrv_DTV_Player_DVB16OAD_StandbyCheckEv", "_ZN19MSrv_DTV_Player_DVB17OADStartInStandbyEv", "_ZN19MSrv_DTV_Player_DVB17_DoOADStandbyModeEv", "_ZN19MSrv_DTV_Player_DVB20OAD_CheckAfterWakeUpEv", "_ZN19MSrv_DTV_Player_DVB22IsOadActiveStandbyModeEv", "_ZN19MSrv_DTV_Player_DVB22IsSchOADFoundInStandbyEv", "_ZN19MSrv_DTV_Player_DVB25OAD_AcceptStandbyDownloadEv", "_ZN19MSrv_DTV_Player_DVB25OAD_RejectStandbyDownloadEv", "_ZN25MW_DTV_Scan_DVBC_Customer21StartStandbyQuickScanEtN25mapi_demodulator_datatype19EN_CAB_CONSTEL_TYPEEmmt", "_ZN25MW_DTV_Scan_DVBC_Customer23HandleEvent_StandbyScanERK16MW_DVBC_ScanInfo"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 5, "symbol_examples": ["_ZN11MSrv_Player13RefreshWindowEv", "_ZN19MSrv_DTV_Player_DVB16SetDisplayWindowERN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEh", "_ZN19MSrv_DTV_Player_DVB17SetPlaybackWindowEPN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEtt", "_ZN19MSrv_DTV_Player_DVB23SetDisplayWindowForAppsERN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEh", "_ZN19MSrv_DTV_Player_DVB23Set_SetWindow_Mute_FlagEh"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 32, "symbol_examples": ["_ZN19MSrv_Control_common21GetMSrvSystemDatabaseEv", "_ZN19MSrv_DTV_Player_DVB13ChangeSettingE22EN_SETTING_CHANGE_TYPE", "_ZN19MSrv_DTV_Player_DVB29SetDefaultCoutrySystemSettingE14MEMBER_COUNTRY", "_ZN20MSrv_System_Database14GetCableOpModeEv", "_ZN20MSrv_System_Database14GetOadDownInfoEP15ST_OAD_SETTINGS", "_ZN20MSrv_System_Database14SetCableOpModeEh", "_ZN20MSrv_System_Database14SetOadDownInfoEP15ST_OAD_SETTINGS", "_ZN20MSrv_System_Database15GetCableFavModeEv", "_ZN20MSrv_System_Database15SetCableFavModeE11EN_FAV_TYPE", "_ZN20MSrv_System_Database17GetCableOpCiCamIdEv", "_ZN20MSrv_System_Database17SetCableOpCiCamIdEm", "_ZN20MSrv_System_Database18GetCableFilterTypeEv", "_ZN20MSrv_System_Database18SetCableFilterTypeEh", "_ZN20MSrv_System_Database20SetAutoServiceUpdateEh", "_ZN20MSrv_System_Database21GetCableOpModeUserOffEv", "_ZN20MSrv_System_Database21GetFactMultiSourceFavEv"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libmsrv_dvbc.so`, `libutilities.so`, `libdirectfb-1.4.so.0`, `librt.so.1`, `libpthread.so.0`, `libdirect-1.4.so.0`, `libMStarSDK.so`, `libMStarSDK_customer.so`, `libfreetype.so.6`, `libMLog.so`, `libmuf.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 696 / 201.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 835; semboller: 3160.
- Xref: 6343; analizde call tipli xref: 0.
- Computed-call instruction: 1072 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/4c606889985e070d66c41cda9237c796b453c37ce8384d15ab7be3e719f56bf7/functions.jsonl) · [Xref](../../../analiz/native/system-modules/4c606889985e070d66c41cda9237c796b453c37ce8384d15ab7be3e719f56bf7/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/4c606889985e070d66c41cda9237c796b453c37ce8384d15ab7be3e719f56bf7/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/4c606889985e070d66c41cda9237c796b453c37ce8384d15ab7be3e719f56bf7/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2ee166dc` | `MW_DTV_Scan_DVBC_Customer::SetOPVariableInit` | [C](../../../analiz/native/system-modules/4c606889985e070d66c41cda9237c796b453c37ce8384d15ab7be3e719f56bf7/2ee166dc.c) |
| `2ee13d34` | `MSrv_DTV_Player_DVBC_Customer::SetCableNetworkID` | [C](../../../analiz/native/system-modules/4c606889985e070d66c41cda9237c796b453c37ce8384d15ab7be3e719f56bf7/2ee13d34.c) |
| `2ee13ac0` | `_init` | [C](../../../analiz/native/system-modules/4c606889985e070d66c41cda9237c796b453c37ce8384d15ab7be3e719f56bf7/2ee13ac0.c) |
| `2ee1659c` | `MW_DTV_Scan_DVBC_Customer::ResetChannelDBScanParameters` | [C](../../../analiz/native/system-modules/4c606889985e070d66c41cda9237c796b453c37ce8384d15ab7be3e719f56bf7/2ee1659c.c) |
| `2ee169d0` | `MW_DTV_Scan_DVBC_Customer::HandleEvent_StandbyScan` | [C](../../../analiz/native/system-modules/4c606889985e070d66c41cda9237c796b453c37ce8384d15ab7be3e719f56bf7/2ee169d0.c) |
| `2ee14d24` | `MSrv_DTV_Player_DVBC_Customer::GetDefaultNetworkID` | [C](../../../analiz/native/system-modules/4c606889985e070d66c41cda9237c796b453c37ce8384d15ab7be3e719f56bf7/2ee14d24.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
