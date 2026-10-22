# `07_MSLIB/libmsrv_control_customer.so`

SHA-256: `dbb8dc826b7f3bfe3afb768e3427afcd723ae956a8e81807e794deba4a8189ad`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 86116 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 22, "symbol_examples": ["_ZN16MSrv_Control_DVB13GetMuteStatusE27MAPI_SOUND_MUTE_STATUS_TYPE", "_ZN16MSrv_Control_DVB13_SetVideoMuteEht22MAPI_INPUT_SOURCE_TYPE14EN_MUTE_ENGINE", "_ZN16MSrv_Control_DVB14GetSoundVolumeEv", "_ZN16MSrv_Control_DVB14SetSoundVolumeEh", "_ZN19MSrv_Control_common10APVolumeUpEv", "_ZN19MSrv_Control_common10NotifyMuteEv", "_ZN19MSrv_Control_common10ToggleMuteEv", "_ZN19MSrv_Control_common11APSetVolumeEh", "_ZN19MSrv_Control_common11GetMuteFlagEv", "_ZN19MSrv_Control_common11SetMuteFlagEh", "_ZN19MSrv_Control_common12APVolumeDownEv", "_ZN19MSrv_Control_common12NotifyUnmuteEv", "_ZN19MSrv_Control_common12SetAudioMuteEt22MAPI_INPUT_SOURCE_TYPE", "_ZN19MSrv_Control_common14APVolumeChangeEm", "_ZN19MSrv_Control_common14GetMSrvSSSoundEv", "_ZN19MSrv_Control_common24GetEnvPowerOnMusicVolumeEv"], "examples_are_complete": false}, {"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 3, "symbol_examples": ["_ZN11mapi_system15GetIRPowerOnKeyEv", "_ZN21MSrv_Control_Customer15GetIRPowerOnKeyEv", "_ZN21MSrv_Control_Customer26STRWakeUpWithRemoteControlEv"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 50, "symbol_examples": ["GetIRPowerupKey", "_ZN11mapi_system15GetIRPowerOnKeyEv", "_ZN12MSrv_Control17NotifyAfterWakeUpEv", "_ZN12MSrv_Control18ARCpowerUpTimeFlagE", "_ZN12MSrv_Control18FakeStandby2NormalEv", "_ZN12MSrv_Control18Normal2FakeStandbyEv", "_ZN12MSrv_Control26FakeStandby2ScheduledEventEv", "_ZN16MSrv_Control_DVB17SetInputSourceCmdE22MAPI_INPUT_SOURCE_TYPEh15MAPI_SCALER_WIN", "_ZN16MSrv_Control_DVB35setM_enAutoScartRecordPreSourceTypeE22MAPI_INPUT_SOURCE_TYPES0_", "_ZN17ArSrvPowerManager11GetInstanceEv", "_ZN17ArSrvPowerManager13SetPowerStateE11POWER_STATEb", "_ZN17MSrv_CEC_Customer11GetInstanceEv", "_ZN17MSrv_CEC_Customer15DeviceListResetEv", "_ZN17MSrv_CEC_Customer18IsCECInitCompletedEv", "_ZN19MSrv_Control_common13GetSourceListEv", "_ZN19MSrv_Control_common13IsWakeUpByRTCEv"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 5, "symbol_examples": ["_ZN16MSrv_Control_DVB35setM_enAutoScartRecordPreSourceTypeE22MAPI_INPUT_SOURCE_TYPES0_", "_ZN19MSrv_Control_common20WritePowerOnLogoModeEm", "_ZN19MSrv_Control_common21GetEnvPowerOnLogoModeEv", "_ZN19MSrv_Control_common21SetEnvPowerOnLogoModeE12EN_LOGO_MODE", "_ZN20MSrv_System_Database10GetFactOSDEv"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 31, "symbol_examples": ["_ZN15MSrv_Control_TV18GetMSrvAtvDatabaseEv", "_ZN19MSrv_Control_common13GetBootConfigEv", "_ZN19MSrv_Control_common18ResetForOADUpgradeEP22ST_OAD_UPDGRADE_CONFIG", "_ZN19MSrv_Control_common21GetMSrvSystemDatabaseEv", "_ZN20MSrv_System_Database10GetFactOSDEv", "_ZN20MSrv_System_Database12GetFactCecOnEv", "_ZN20MSrv_System_Database12GetLedPWMLowEv", "_ZN20MSrv_System_Database12SetLedPWMLowEt", "_ZN20MSrv_System_Database13GetLedPWMHighEv", "_ZN20MSrv_System_Database13SetESDRestartEh", "_ZN20MSrv_System_Database13SetLedPWMHighEt", "_ZN20MSrv_System_Database16GetFactHotelModeEv", "_ZN20MSrv_System_Database16GetFactorySystemEP26MS_FACTORY_SYSTEM_SETTINGS", "_ZN20MSrv_System_Database16GetLedBrightnessEv", "_ZN20MSrv_System_Database17GetFactWatchdogOnEv", "_ZN20MSrv_System_Database19GetFactBreathingLEDEv"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libutilities.so`, `libdirectfb-1.4.so.0`, `librt.so.1`, `libpthread.so.0`, `libdirect-1.4.so.0`, `libMStarSDK.so`, `libMStarSDK_customer.so`, `libfreetype.so.6`, `libMLog.so`, `libmuf.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 332 / 112.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 407; semboller: 1724.
- Xref: 3599; analizde call tipli xref: 0.
- Computed-call instruction: 991 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/dbb8dc826b7f3bfe3afb768e3427afcd723ae956a8e81807e794deba4a8189ad/functions.jsonl) · [Xref](../../../analiz/native/system-modules/dbb8dc826b7f3bfe3afb768e3427afcd723ae956a8e81807e794deba4a8189ad/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/dbb8dc826b7f3bfe3afb768e3427afcd723ae956a8e81807e794deba4a8189ad/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/dbb8dc826b7f3bfe3afb768e3427afcd723ae956a8e81807e794deba4a8189ad/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f1c8810` | `MSrv_Control_Customer::GetARCpowerUpTime` | [C](../../../analiz/native/system-modules/dbb8dc826b7f3bfe3afb768e3427afcd723ae956a8e81807e794deba4a8189ad/2f1c8810.c) |
| `2f1caef0` | `MSrv_Control_Customer::GetIRPowerOnKey` | [C](../../../analiz/native/system-modules/dbb8dc826b7f3bfe3afb768e3427afcd723ae956a8e81807e794deba4a8189ad/2f1caef0.c) |
| `2f1c8a00` | `MSrv_Control_Customer::IsStandbyUpdateStarted` | [C](../../../analiz/native/system-modules/dbb8dc826b7f3bfe3afb768e3427afcd723ae956a8e81807e794deba4a8189ad/2f1c8a00.c) |
| `2f1ca9dc` | `MSrv_Control_Customer::StartBackRoundUpdate` | [C](../../../analiz/native/system-modules/dbb8dc826b7f3bfe3afb768e3427afcd723ae956a8e81807e794deba4a8189ad/2f1ca9dc.c) |
| `2f1c8320` | `_init` | [C](../../../analiz/native/system-modules/dbb8dc826b7f3bfe3afb768e3427afcd723ae956a8e81807e794deba4a8189ad/2f1c8320.c) |
| `2f1c96fc` | `MSrv_Control_Customer::SetMbootUpgradeComplete` | [C](../../../analiz/native/system-modules/dbb8dc826b7f3bfe3afb768e3427afcd723ae956a8e81807e794deba4a8189ad/2f1c96fc.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
