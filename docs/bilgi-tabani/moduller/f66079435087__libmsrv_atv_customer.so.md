# `07_MSLIB/libmsrv_atv_customer.so`

SHA-256: `f66079435087d987a918c81f4b9526cdbf03a7b3819a3fc9bc4537518bc879a6`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 71936 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 15, "symbol_examples": ["_ZN11MW_ATV_Scan14SetSoundSystemE19AUDIOSTANDARD_TYPE_", "_ZN11MW_ATV_Scan15VifSetFrequencyEm19AUDIOSTANDARD_TYPE_", "_ZN11MW_ATV_Scan17SetupAutoScanParaE19AUDIOSTANDARD_TYPE_", "_ZN11MW_ATV_Scan19VifSetSoundStandardEh", "_ZN15MSrv_ATV_Player14GetSoundSystemEv", "_ZN15MSrv_ATV_Player19SetForceSoundSystemEN14MSrv_TV_Player23EN_MSRV_UI_SOUND_SYSTEME", "_ZN15MSrv_ATV_Player22CFT_IsChannelAvailableEN14MSrv_TV_Player23EN_MSRV_UI_SOUND_SYSTEMEN17MSrv_ATV_Database6MEDIUMEPt", "_ZN15MSrv_ATV_Player24CheckAudioStandardChangeEv", "_ZN17MSrv_ATV_Database15ATVGetAudioModeEP15AUDIOMODE_TYPE_", "_ZN17MSrv_ATV_Database15ATVSetAudioModeE15AUDIOMODE_TYPE_", "_ZN17MSrv_ATV_Database19ATVGetAudioStandardEh", "_ZN17MSrv_ATV_Database19ATVSetAudioStandardEh26EN_MSRV_AUDIOSTANDARD_TYPE", "_ZN17MSrv_ATV_Database23ATVGetDualAudioSelectedEv", "_ZN17MSrv_ATV_Database31ATVEnableRealtimeAudioDetectionEhh", "_ZN17MSrv_ATV_Database34ATVIsRealtimeAudioDetectionEnabledEh"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 3, "symbol_examples": ["_ZN11MSrv_Player26GetSwitchSourceLockWinFlagEv", "_ZN11MSrv_Player26SetSwitchSourceLockWinFlagEh", "_ZN15MSrv_ATV_Player30IsDiffVideoStandByChannelAndVDEv"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["_ZN11MSrv_Player23SetDisplayWindowForAppsERN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEh", "_ZN15MSrv_ATV_Player13RefreshWindowEv", "_ZN15MSrv_ATV_Player17SetOverscanFromDBEPP25ST_MAPI_VIDEO_WINDOW_INFOh", "_ZN15MSrv_ATV_Player9CalWSSWinEN16mapi_vd_datatype17ASPECT_RATIO_TYPEEPN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEPNS2_22ST_MAPI_VIDEO_ARC_INFOE"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 147, "symbol_examples": ["_ZN15MSrv_ATV_Player16UpdateVIFSettingEv", "_ZN15MSrv_ATV_Player19CFTGetMinMaxChannelEN17MSrv_ATV_Database6MEDIUMEPhS2_", "_ZN15MSrv_ATV_Player19GetChannelFreqTableEPPNS_15ST_CHANNEL_FREQEN17MSrv_ATV_Database6MEDIUMEh", "_ZN15MSrv_ATV_Player21RecoverUserMtsSettingEv", "_ZN15MSrv_ATV_Player22CFT_IsChannelAvailableEN14MSrv_TV_Player23EN_MSRV_UI_SOUND_SYSTEMEN17MSrv_ATV_Database6MEDIUMEPt", "_ZN15MSrv_ATV_Player25MediumChannelSetFrequencyEN17MSrv_ATV_Database6MEDIUMEh", "_ZN15MSrv_ATV_Player26CFTIsValidMediumAndChannelEN17MSrv_ATV_Database6MEDIUMEh", "_ZN15MSrv_ATV_Player26msAPI_CFT_GetMinMaxChannelEN17MSrv_ATV_Database6MEDIUMEPhS2_", "_ZN15MSrv_ATV_Player27msAPI_CFT_GetChannelPLLDataEN17MSrv_ATV_Database6MEDIUMEh", "_ZN15MSrv_ATV_Player28ATVGetMediumAndChannelNumberEhPN17MSrv_ATV_Database6MEDIUMEPh", "_ZN15MSrv_ATV_Player28ATVSetMediumAndChannelNumberEhN17MSrv_ATV_Database6MEDIUMEh", "_ZN15MSrv_ATV_Player49msAPI_Tuner_ConvertMediumAndChannelNumberToStringEN17MSrv_ATV_Database6MEDIUMEhPh", "_ZN15MSrv_Control_TV18GetMSrvAtvDatabaseE14EN_ATV_DB_TYPE", "_ZN15MSrv_Control_TV18GetMSrvAtvDatabaseEv", "_ZN17MSrv_ATV_Database10ATVGetMISCEhPh", "_ZN17MSrv_ATV_Database10ATVNeedAFTEhh"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libmsrv_atv.so`, `libutilities.so`, `libdirectfb-1.4.so.0`, `librt.so.1`, `libpthread.so.0`, `libdirect-1.4.so.0`, `libMStarSDK.so`, `libMStarSDK_customer.so`, `libfreetype.so.6`, `libMLog.so`, `libmuf.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 346 / 89.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 401; semboller: 1496.
- Xref: 2235; analizde call tipli xref: 0.
- Computed-call instruction: 267 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/f66079435087d987a918c81f4b9526cdbf03a7b3819a3fc9bc4537518bc879a6/functions.jsonl) · [Xref](../../../analiz/native/system-modules/f66079435087d987a918c81f4b9526cdbf03a7b3819a3fc9bc4537518bc879a6/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/f66079435087d987a918c81f4b9526cdbf03a7b3819a3fc9bc4537518bc879a6/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/f66079435087d987a918c81f4b9526cdbf03a7b3819a3fc9bc4537518bc879a6/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f198bec` | `_init` | [C](../../../analiz/native/system-modules/f66079435087d987a918c81f4b9526cdbf03a7b3819a3fc9bc4537518bc879a6/2f198bec.c) |
| `2f19a5ec` | `std::vector<MSrv_ATV_Player::ST_MSRV_CHANNEL_INFO,std::allocator<MSrv_ATV_Player::ST_MSRV_CHANNEL_INFO>>::_M_insert_aux` | [C](../../../analiz/native/system-modules/f66079435087d987a918c81f4b9526cdbf03a7b3819a3fc9bc4537518bc879a6/2f19a5ec.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
