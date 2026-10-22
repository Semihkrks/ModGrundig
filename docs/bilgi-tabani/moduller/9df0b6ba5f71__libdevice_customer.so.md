# `07_MSLIB/libdevice_customer.so`

SHA-256: `9df0b6ba5f712280cf60f84363d908fc6b61e8d31ed5ffa61c5cee3d9480f52f`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 441572 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 43, "symbol_examples": ["_ZN10device_pcb11GetAudioAmpEh", "_ZN11device_ursa11SetUrsaMuteEPhS0_", "_ZN11device_ursa16SetVideoMuteDataEPh", "_ZN11device_ursa17transferMuteColorEPhS0_", "_ZN14mapi_audio_amp19AMP_Api_Init_DeviceEv", "_ZN14mapi_audio_amp20AmpSwapOutputChannelEh", "_ZN14mapi_audio_amp21AMP_Api_AmpAutoDetectEv", "_ZN14mapi_audio_amp21AmpSetSubWooferVolumeEhh", "_ZN14mapi_audio_amp22AMP_Api_AmpSetEQByModeE24ENUM_SET_EQ_BY_MODE_TYPE", "_ZN14mapi_audio_amp23AMP_Api_AmpGetSenceModeEv", "_ZN14mapi_audio_amp23AMP_Api_AmpSetSenceModeEh", "_ZN14mapi_audio_amp23AMP_Api_Init_ResetOnOffEh", "_ZN14mapi_audio_amp24AMP_Api_AmpGetOutputModeEv", "_ZN14mapi_audio_amp24AMP_Api_AmpSetOutputModeEh", "_ZN14mapi_audio_amp24AMP_Api_AmpSetSampleRateEh", "_ZN14mapi_audio_amp24AMP_Api_AmpSoftMuteOnOffEh"], "examples_are_complete": false}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 33, "symbol_examples": ["MDrv_DMD_DVBC_GetLockWithRFPower", "MDrv_DMD_DVBC_GetSignalQualityWithRFPower", "MDrv_DMD_DVBC_GetSignalStrengthWithRFPower", "MDrv_DMD_DVBS_GetSignalQualityWithRFPower", "MDrv_DMD_DVBT2_GetSignalQualityWithRFPower", "MDrv_DMD_DVBT2_GetSignalStrengthWithRFPower", "MDrv_DMD_DVBT_GetSignalQualityWithRFPower", "MDrv_DMD_DVBT_GetSignalStrengthWithRFPower", "UnicablePowerOFF", "_Z14Si2151_StandbyP17L1_Si2151_Context", "_Z16Si2151_PowerdownP17L1_Si2151_Context", "_Z17Si2151_L1_STANDBYP17L1_Si2151_Contexth", "_Z18Si2151_L1_POWER_UPP17L1_Si2151_Contexthhhhhhhhhh", "_Z23Si2151_L1_POWER_DOWN_HWP17L1_Si2151_Contexthhhhhhhhhhhh", "_Z23Si2151_PowerUpWithPatchP17L1_Si2151_Context", "_Z31Si2151_PowerUpUsingBroadcastI2CPP17L1_Si2151_Contexti"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 13, "symbol_examples": ["L0_ReadRawBytes", "MDrv_DMD_DVBT2_GetPlpBitMap", "_ZN11device_ursa10setOSDSizeEv", "_ZN11device_ursa13DisableOsdWinE14EN_MFC_OSD_WIN", "_ZN11device_ursa14SetOSDWinHDataEPh", "_ZN11device_ursa14SetOSDWinVDataEPh", "_ZN11device_ursa14setRxOsdEnableEPhS0_", "_ZN11device_ursa16DisableAllOsdWinEv", "_ZN11device_ursa16SetOsdResolutionEtt", "_ZN11device_ursa16SetUrsaOSDEnableEh", "_ZN11device_ursa26SetOSDVideoChannelExchangeEPhS0_", "_ZN11device_ursa9SetOsdWinE14EN_MFC_OSD_WINtttt", "_ZN18device_demodulator16DTV_GetPlpBitMapEPh"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 26, "symbol_examples": ["MDrv_DMD_DVBC_SetConfig", "MDrv_DMD_DVBS_SetConfig", "MDrv_DMD_DVBT2_SetConfig", "MDrv_DMD_DVBT_SetConfigHPLPSetIF", "TunerInitialSetting", "UnicableConfig", "UnicableGetConfigNumber", "_Z16Si2151_ConfigureP17L1_Si2151_Context", "_Z20Si2151_L1_CONFIG_I2CP17L1_Si2151_Contexthh", "_Z21Si2151_L1_CONFIG_PINSP17L1_Si2151_Contexthhhhhhhhh", "_Z23Si2151_L1_CONFIG_CLOCKSP17L1_Si2151_Contexthhh", "_ZN10SystemInfo14GetDemodConfigEhPPhS1_", "_ZN10mapi_demux17SetPreConfigInputE19MAPI_DMX_FLOW_INPUT", "_ZN10mapi_tuner13ConfigAGCModeE13EN_TUNER_MODE", "_ZN18device_demodulator10DTV_ConfigE20RF_CHANNEL_BANDWIDTHhh", "_ZN18device_demodulator17Tuner_TOP_SettingE"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libMStarSDK.so`, `libutilities.so`, `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 258 / 691.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 864; semboller: 4921.
- Xref: 22675; analizde call tipli xref: 0.
- Computed-call instruction: 2970 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/9df0b6ba5f712280cf60f84363d908fc6b61e8d31ed5ffa61c5cee3d9480f52f/functions.jsonl) · [Xref](../../../analiz/native/system-modules/9df0b6ba5f712280cf60f84363d908fc6b61e8d31ed5ffa61c5cee3d9480f52f/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/9df0b6ba5f712280cf60f84363d908fc6b61e8d31ed5ffa61c5cee3d9480f52f/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/9df0b6ba5f712280cf60f84363d908fc6b61e8d31ed5ffa61c5cee3d9480f52f/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2e2e149c` | `device_demodulator_extend2::SuspendDeInit` | [C](../../../analiz/native/system-modules/9df0b6ba5f712280cf60f84363d908fc6b61e8d31ed5ffa61c5cee3d9480f52f/2e2e149c.c) |
| `2e2e14c0` | `device_demodulator_extend2::ResumeInit` | [C](../../../analiz/native/system-modules/9df0b6ba5f712280cf60f84363d908fc6b61e8d31ed5ffa61c5cee3d9480f52f/2e2e14c0.c) |
| `2e2e1530` | `device_demodulator_extend2::Power_On_Initialization` | [C](../../../analiz/native/system-modules/9df0b6ba5f712280cf60f84363d908fc6b61e8d31ed5ffa61c5cee3d9480f52f/2e2e1530.c) |
| `2e2e1554` | `device_demodulator_extend2::Set_PowerOn` | [C](../../../analiz/native/system-modules/9df0b6ba5f712280cf60f84363d908fc6b61e8d31ed5ffa61c5cee3d9480f52f/2e2e1554.c) |
| `2e2e1578` | `device_demodulator_extend2::Set_PowerOff` | [C](../../../analiz/native/system-modules/9df0b6ba5f712280cf60f84363d908fc6b61e8d31ed5ffa61c5cee3d9480f52f/2e2e1578.c) |
| `2e2e1ad8` | `device_demodulator::SuspendDeInit` | [C](../../../analiz/native/system-modules/9df0b6ba5f712280cf60f84363d908fc6b61e8d31ed5ffa61c5cee3d9480f52f/2e2e1ad8.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
