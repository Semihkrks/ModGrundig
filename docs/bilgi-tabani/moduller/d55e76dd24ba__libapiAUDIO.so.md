# `07_MSLIB/utopia/libapiAUDIO.so`

SHA-256: `d55e76dd24baea83657739e4424982cb8c4b00d90a9144792c1c6b430fe46651`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 2021612 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 1059, "symbol_examples": ["AUDIOClose", "AUDIOIoctl", "AUDIOOpen", "AUDIORegisterToUtopia", "AudioInitTbl_0", "AudioInitTbl_1", "AudioInputSrcInfo", "AudioPreInitTbl_Clock_0", "AudioPreInitTbl_Clock_1", "Audio_Pcm_Capture1", "Audio_Pcm_Capture2", "Audio_Pcm_HwDma_Reader1", "Audio_Pcm_Mixer_Server", "Audio_Pcm_SwDma_Reader1", "DynamicAvl_active_volume", "HAL_ADVSOUND_ProcessEnable"], "examples_are_complete": false}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 62, "symbol_examples": ["FLAG_HDMI_AC3_IN_SE", "HAL_AUDIO_EnaEarphone_LowPower_Stage", "HAL_AUDIO_HDMIAutoMute", "HAL_AUDIO_HDMI_AC3_PathCFG", "HAL_AUDIO_HDMI_DolbyMonitor", "HAL_AUDIO_HDMI_Get_SYNTH_FREQ", "HAL_AUDIO_HDMI_NonpcmMonitor", "HAL_AUDIO_HDMI_NonpcmMonitor2", "HAL_AUDIO_HDMI_RX_GetHdmiInAudioStatus", "HAL_AUDIO_HDMI_SetNonpcm", "HAL_AUDIO_HDMI_Set_DwonSample", "HAL_AUDIO_HDMI_TX_SetMode", "HAL_AUDIO_HDMI_Tx_GetStatus", "HAL_AUDIO_SetPowerDownWait", "HAL_AUDIO_SetPowerOn", "HAL_SOUND_PowerDown_Wait"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 8, "symbol_examples": ["HAL_AUDIO_SetDataCaptureSource", "MApi_AUDIO_SetDataCaptureSource", "MDrv_AUDIO_SetDataCaptureSource", "UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceRegister", "_MApi_AUDIO_SetDataCaptureSource"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 13, "symbol_examples": ["HAL_AUDIO_GetAnalogConfig", "HAL_AUDIO_PCM_Dump_Setting", "HAL_AUDIO_PCM_HwDma_Reader1_Apply_Setting", "HAL_AUDIO_PCM_SwDma_Reader1_Apply_Setting", "HAL_AUDIO_SetAnalogConfig", "MApi_AUDIO_GetAnalogConfig", "MApi_AUDIO_SetAnalogConfig", "MApi_AUDIO_VoIP_Config", "MDrv_AUDIO_GetAnalogConfig", "MDrv_AUDIO_SetAnalogConfig", "MDrv_AUDIO_VoIP_Config", "_MApi_AUDIO_VoIP_Config", "stCurrentAnalogConfig"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 55 / 1339.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 1270; semboller: 4271.
- Xref: 16472; analizde call tipli xref: 0.
- Computed-call instruction: 4106 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/d55e76dd24baea83657739e4424982cb8c4b00d90a9144792c1c6b430fe46651/functions.jsonl) · [Xref](../../../analiz/native/system-modules/d55e76dd24baea83657739e4424982cb8c4b00d90a9144792c1c6b430fe46651/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/d55e76dd24baea83657739e4424982cb8c4b00d90a9144792c1c6b430fe46651/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/d55e76dd24baea83657739e4424982cb8c4b00d90a9144792c1c6b430fe46651/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2d05cec0` | `HAL_AUDIO_GET_INIT_FLAG` | [C](../../../analiz/native/system-modules/d55e76dd24baea83657739e4424982cb8c4b00d90a9144792c1c6b430fe46651/2d05cec0.c) |
| `2d04fec4` | `MDrv_SOUND_TruVolume_Enable` | [C](../../../analiz/native/system-modules/d55e76dd24baea83657739e4424982cb8c4b00d90a9144792c1c6b430fe46651/2d04fec4.c) |
| `2d053264` | `MDrv_AUDIO_update_DspUsage` | [C](../../../analiz/native/system-modules/d55e76dd24baea83657739e4424982cb8c4b00d90a9144792c1c6b430fe46651/2d053264.c) |
| `2d053368` | `MDrv_AUDIO_PCMCapture_Init` | [C](../../../analiz/native/system-modules/d55e76dd24baea83657739e4424982cb8c4b00d90a9144792c1c6b430fe46651/2d053368.c) |
| `2d05339c` | `MDrv_AUDIO_SetDataCaptureSource` | [C](../../../analiz/native/system-modules/d55e76dd24baea83657739e4424982cb8c4b00d90a9144792c1c6b430fe46651/2d05339c.c) |
| `2d053438` | `MDrv_AUDIO_USBPCM_Enable` | [C](../../../analiz/native/system-modules/d55e76dd24baea83657739e4424982cb8c4b00d90a9144792c1c6b430fe46651/2d053438.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
