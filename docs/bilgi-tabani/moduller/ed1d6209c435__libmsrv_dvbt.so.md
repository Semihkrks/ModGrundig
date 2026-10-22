# `07_MSLIB/libmsrv_dvbt.so`

SHA-256: `ed1d6209c43559a5d6c449aab01a6062f16a30b2ab614605e6d49830f26995cf`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 163876 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 25, "symbol_examples": ["_ZN15MSrv_DTV_Player11ChangeAudioEh", "_ZN15MSrv_DTV_Player11UpdateAudioEv", "_ZN15MSrv_DTV_Player16SwitchAudioTrackEh", "_ZN19MSrv_DTV_Player_DVB12GetAudioInfoER17ST_DTV_AUDIO_INFO", "_ZN19MSrv_DTV_Player_DVB12PinEventMuteEhm", "_ZN19MSrv_DTV_Player_DVB12SetAudioModeE26EN_MSRV_DTV_SET_AUDIO_MODE", "_ZN19MSrv_DTV_Player_DVB12SetDTVAVMuteEh", "_ZN19MSrv_DTV_Player_DVB13GetScreenMuteEv", "_ZN19MSrv_DTV_Player_DVB15GetAdAudioIndexERK16_DVB_PROGRAMINFOhPh", "_ZN19MSrv_DTV_Player_DVB17DoProgChangeAudioEhhh", "_ZN19MSrv_DTV_Player_DVB17DoProgUpdateAudioEh", "_ZN19MSrv_DTV_Player_DVB17GetAudioTrackInfoER17ST_DTV_AUDIO_INFO", "_ZN19MSrv_DTV_Player_DVB19SetCurrentAudioModeEh", "_ZN19MSrv_DTV_Player_DVB19SetCurrentAudioModeEh10AUDIO_MODE", "_ZN19MSrv_DTV_Player_DVB20GetAVMonitorMuteFlagERm", "_ZN19MSrv_DTV_Player_DVB20GetDefaultAudioIndexERK16_DVB_PROGRAMINFO"], "examples_are_complete": false}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 17, "symbol_examples": ["_ZN11MSrv_Player26GetSwitchSourceLockWinFlagEv", "_ZN11MSrv_Player26SetSwitchSourceLockWinFlagEh", "_ZN15MSrv_DTV_Player11StandbyScanEv", "_ZN15MSrv_DTV_Player16StartStandbyScanEv", "_ZN16MW_DTV_Scan_DVBT16StartStandbyScanEv", "_ZN16MW_DTV_Scan_DVBT23HandleEvent_StandbyScanERK16MW_DVBT_ScanInfo", "_ZN16mapi_demodulator23Power_On_InitializationEv", "_ZN19MSrv_DTV_Player_DVB16GetDTVSourceTypeEv", "_ZN19MSrv_DTV_Player_DVB16OAD_StandbyCheckEv", "_ZN19MSrv_DTV_Player_DVB17OADStartInStandbyEv", "_ZN19MSrv_DTV_Player_DVB17_DoOADStandbyModeEv", "_ZN19MSrv_DTV_Player_DVB20OAD_CheckAfterWakeUpEv", "_ZN19MSrv_DTV_Player_DVB22IsOadActiveStandbyModeEv", "_ZN19MSrv_DTV_Player_DVB22IsSchOADFoundInStandbyEv", "_ZN19MSrv_DTV_Player_DVB25OAD_AcceptStandbyDownloadEv", "_ZN19MSrv_DTV_Player_DVB25OAD_RejectStandbyDownloadEv"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 8, "symbol_examples": ["_ZN11MSrv_Player13RefreshWindowEv", "_ZN16mapi_demodulator23DTV_DVB_T2_GetPlpBitMapEPh", "_ZN19MSrv_DTV_Player_DVB16SetDisplayWindowERN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEh", "_ZN19MSrv_DTV_Player_DVB17SetPlaybackWindowEPN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEtt", "_ZN19MSrv_DTV_Player_DVB23SetDisplayWindowForAppsERN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEh", "_ZN19MSrv_DTV_Player_DVB23Set_SetWindow_Mute_FlagEh", "_ZN21MW_DTV_CM_DVB_Factory16CreateSharedCmDbE11EN_DTV_TYPEhmtttPFhRK16_DVB_PROGRAMINFOS3_E22EN_CMDB_MAPPING_WINDOW", "_ZN21MW_DTV_CM_DVB_Factory18CreateSharedOpCmDbE11EN_DTV_TYPEhmtttPFhRK16_DVB_PROGRAMINFOS3_E22EN_CMDB_MAPPING_WINDOW"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 14, "symbol_examples": ["_Z16HookCmDbCallbackR18MW_DTV_Program_DVBRPN12MW_DTV_CM_DBI16_DVB_PROGRAMINFO12_DVB_MUXINFO16_ST_DVB_SAT_INFO20_ST_DVB_NETWORK_INFOE23ProgramSortingMethodSetEPS6_20EN_HOOK_CMDB_SETTING", "_ZN19MSrv_Control_common21GetMSrvSystemDatabaseEv", "_ZN19MSrv_DTV_Player_DVB13ChangeSettingE22EN_SETTING_CHANGE_TYPE", "_ZN19MSrv_DTV_Player_DVB18GetCiOpModeSettingEv", "_ZN19MSrv_DTV_Player_DVB18SetCiOpModeSettingEh", "_ZN19MSrv_DTV_Player_DVB23GetCiOpModeCamIdSettingEv", "_ZN19MSrv_DTV_Player_DVB23SetCiOpModeCamIdSettingEm", "_ZN19MSrv_DTV_Player_DVB29SetDefaultCoutrySystemSettingE14MEMBER_COUNTRY", "_ZN20MSrv_System_Database12GetAirOpModeEv", "_ZN20MSrv_System_Database15GetAirOpCiCamIdEv", "_ZN25MW_DTV_FREQUENCYTABLE_DVB18GetTPSettingByFreqEmP13MW_TP_SETTING", "_ZN26MW_DTV_FREQUENCYTABLE_DVBT16GetTPSettingByRFEhP13MW_TP_SETTING", "_ZTI20MSrv_System_Database", "_ZTI24MSrv_System_Database_DVB"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libutilities.so`, `libdirectfb-1.4.so.0`, `librt.so.1`, `libpthread.so.0`, `libdirect-1.4.so.0`, `libMStarSDK.so`, `libMStarSDK_customer.so`, `libfreetype.so.6`, `libMLog.so`, `libmuf.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 677 / 212.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 830; semboller: 3153.
- Xref: 6299; analizde call tipli xref: 0.
- Computed-call instruction: 1206 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/ed1d6209c43559a5d6c449aab01a6062f16a30b2ab614605e6d49830f26995cf/functions.jsonl) · [Xref](../../../analiz/native/system-modules/ed1d6209c43559a5d6c449aab01a6062f16a30b2ab614605e6d49830f26995cf/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/ed1d6209c43559a5d6c449aab01a6062f16a30b2ab614605e6d49830f26995cf/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/ed1d6209c43559a5d6c449aab01a6062f16a30b2ab614605e6d49830f26995cf/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2ee57b90` | `MW_DTV_Scan_DVBT::HandleEvent_StandbyScan` | [C](../../../analiz/native/system-modules/ed1d6209c43559a5d6c449aab01a6062f16a30b2ab614605e6d49830f26995cf/2ee57b90.c) |
| `2ee533a4` | `MSrv_DTV_Player_DVBT::EnableChannelFrontEnd` | [C](../../../analiz/native/system-modules/ed1d6209c43559a5d6c449aab01a6062f16a30b2ab614605e6d49830f26995cf/2ee533a4.c) |
| `2ee5312c` | `_init` | [C](../../../analiz/native/system-modules/ed1d6209c43559a5d6c449aab01a6062f16a30b2ab614605e6d49830f26995cf/2ee5312c.c) |
| `2ee57cd0` | `MW_DTV_Scan_DVBT::HandleEvent_AutoUpdateScan` | [C](../../../analiz/native/system-modules/ed1d6209c43559a5d6c449aab01a6062f16a30b2ab614605e6d49830f26995cf/2ee57cd0.c) |
| `2ee571c8` | `MW_DTV_Scan_DVBT::_ScanInitFreqTableStatus_AU` | [C](../../../analiz/native/system-modules/ed1d6209c43559a5d6c449aab01a6062f16a30b2ab614605e6d49830f26995cf/2ee571c8.c) |
| `2ee5e3b0` | `MW_DTV_Scan_DVBT::StartStandbyScan` | [C](../../../analiz/native/system-modules/ed1d6209c43559a5d6c449aab01a6062f16a30b2ab614605e6d49830f26995cf/2ee5e3b0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
