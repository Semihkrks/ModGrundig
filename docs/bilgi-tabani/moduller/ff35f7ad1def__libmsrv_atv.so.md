# `07_MSLIB/libmsrv_atv.so`

SHA-256: `ff35f7ad1defc88a945723d5b209d934d2dd219fa7c3f40eae77c44d68301bcc`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 193892 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 30, "symbol_examples": ["_ZN10mapi_audio30SIF_StartAutoStandardDetectionEv", "_ZN10mapi_audio31SIF_ConvertToBasicAudioStandardE19AUDIOSTANDARD_TYPE_", "_ZN10mapi_audio36SIF_GetResultOfAutoStandardDetectionEv", "_ZN11MW_ATV_Scan14SetSoundSystemE19AUDIOSTANDARD_TYPE_", "_ZN11MW_ATV_Scan15VifSetFrequencyEm19AUDIOSTANDARD_TYPE_", "_ZN11MW_ATV_Scan17SetupAutoScanParaE19AUDIOSTANDARD_TYPE_", "_ZN11MW_ATV_Scan19VifSetSoundStandardEh", "_ZN12MSrv_SSSound10GetMtsModeEv", "_ZN12MSrv_SSSound10SetMtsModeEh", "_ZN12MSrv_SSSound12GetSoundModeEv", "_ZN15MSrv_ATV_Player14GetSoundSystemEv", "_ZN15MSrv_ATV_Player19SetForceSoundSystemEN14MSrv_TV_Player23EN_MSRV_UI_SOUND_SYSTEME", "_ZN15MSrv_ATV_Player22CFT_IsChannelAvailableEN14MSrv_TV_Player23EN_MSRV_UI_SOUND_SYSTEMEN17MSrv_ATV_Database6MEDIUMEPt", "_ZN15MSrv_ATV_Player24CheckAudioStandardChangeEv", "_ZN16mapi_demodulator22ATV_SetVIF_SoundSystemEN25mapi_demodulator_datatype25DEMOD_AUDIOSTANDARD_TYPE_E", "_ZN17MSrv_ATV_Database15ATVGetAudioModeEP15AUDIOMODE_TYPE_"], "examples_are_complete": false}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 5, "symbol_examples": ["_ZN11MSrv_Player26GetSwitchSourceLockWinFlagEv", "_ZN11MSrv_Player26SetSwitchSourceLockWinFlagEh", "_ZN15MSrv_ATV_Player30IsDiffVideoStandByChannelAndVDEv", "_ZN16mapi_demodulator23Power_On_InitializationEv", "_ZN7mapi_vd14SetVideoSourceE24MAPI_AVD_InputSourceType"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["_ZN11MSrv_Player23SetDisplayWindowForAppsERN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEh", "_ZN15MSrv_ATV_Player13RefreshWindowEv", "_ZN15MSrv_ATV_Player17SetOverscanFromDBEPP25ST_MAPI_VIDEO_WINDOW_INFOh", "_ZN15MSrv_ATV_Player9CalWSSWinEN16mapi_vd_datatype17ASPECT_RATIO_TYPEEPN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEEPNS2_22ST_MAPI_VIDEO_ARC_INFOE"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 147, "symbol_examples": ["_ZN15MSrv_ATV_Player16UpdateVIFSettingEv", "_ZN15MSrv_ATV_Player19CFTGetMinMaxChannelEN17MSrv_ATV_Database6MEDIUMEPhS2_", "_ZN15MSrv_ATV_Player19GetChannelFreqTableEPPNS_15ST_CHANNEL_FREQEN17MSrv_ATV_Database6MEDIUMEh", "_ZN15MSrv_ATV_Player21RecoverUserMtsSettingEv", "_ZN15MSrv_ATV_Player22CFT_IsChannelAvailableEN14MSrv_TV_Player23EN_MSRV_UI_SOUND_SYSTEMEN17MSrv_ATV_Database6MEDIUMEPt", "_ZN15MSrv_ATV_Player25MediumChannelSetFrequencyEN17MSrv_ATV_Database6MEDIUMEh", "_ZN15MSrv_ATV_Player26CFTIsValidMediumAndChannelEN17MSrv_ATV_Database6MEDIUMEh", "_ZN15MSrv_ATV_Player26msAPI_CFT_GetMinMaxChannelEN17MSrv_ATV_Database6MEDIUMEPhS2_", "_ZN15MSrv_ATV_Player27msAPI_CFT_GetChannelPLLDataEN17MSrv_ATV_Database6MEDIUMEh", "_ZN15MSrv_ATV_Player28ATVGetMediumAndChannelNumberEhPN17MSrv_ATV_Database6MEDIUMEPh", "_ZN15MSrv_ATV_Player28ATVSetMediumAndChannelNumberEhN17MSrv_ATV_Database6MEDIUMEh", "_ZN15MSrv_ATV_Player49msAPI_Tuner_ConvertMediumAndChannelNumberToStringEN17MSrv_ATV_Database6MEDIUMEhPh", "_ZN15MSrv_Control_TV18GetMSrvAtvDatabaseEv", "_ZN17MSrv_ATV_Database10ATVGetMISCEhPh", "_ZN17MSrv_ATV_Database10ATVNeedAFTEhh", "_ZN17MSrv_ATV_Database10ATVSetMISCEhPKh"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libutilities.so`, `libdirectfb-1.4.so.0`, `librt.so.1`, `libpthread.so.0`, `libdirect-1.4.so.0`, `libMStarSDK.so`, `libMStarSDK_customer.so`, `libfreetype.so.6`, `libMLog.so`, `libmuf.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 212 / 382.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 531; semboller: 3001.
- Xref: 8609; analizde call tipli xref: 0.
- Computed-call instruction: 2211 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/ff35f7ad1defc88a945723d5b209d934d2dd219fa7c3f40eae77c44d68301bcc/functions.jsonl) · [Xref](../../../analiz/native/system-modules/ff35f7ad1defc88a945723d5b209d934d2dd219fa7c3f40eae77c44d68301bcc/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/ff35f7ad1defc88a945723d5b209d934d2dd219fa7c3f40eae77c44d68301bcc/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/ff35f7ad1defc88a945723d5b209d934d2dd219fa7c3f40eae77c44d68301bcc/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2eb93190` | `MSrv_ATV_Player::SetChannelSearchType` | [C](../../../analiz/native/system-modules/ff35f7ad1defc88a945723d5b209d934d2dd219fa7c3f40eae77c44d68301bcc/2eb93190.c) |
| `2eb93524` | `MSrv_ATV_Player::TunerSetMedium` | [C](../../../analiz/native/system-modules/ff35f7ad1defc88a945723d5b209d934d2dd219fa7c3f40eae77c44d68301bcc/2eb93524.c) |
| `2eb93178` | `MSrv_ATV_Player::CFTGetMinMaxChannel` | [C](../../../analiz/native/system-modules/ff35f7ad1defc88a945723d5b209d934d2dd219fa7c3f40eae77c44d68301bcc/2eb93178.c) |
| `2eb9d4a8` | `MW_ATV_Scan::Init` | [C](../../../analiz/native/system-modules/ff35f7ad1defc88a945723d5b209d934d2dd219fa7c3f40eae77c44d68301bcc/2eb9d4a8.c) |
| `2eb96574` | `MSrv_ATV_Player::UpdateVIFSetting` | [C](../../../analiz/native/system-modules/ff35f7ad1defc88a945723d5b209d934d2dd219fa7c3f40eae77c44d68301bcc/2eb96574.c) |
| `2eb9658c` | `MSrv_ATV_Player::InitATVVIF` | [C](../../../analiz/native/system-modules/ff35f7ad1defc88a945723d5b209d934d2dd219fa7c3f40eae77c44d68301bcc/2eb9658c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
