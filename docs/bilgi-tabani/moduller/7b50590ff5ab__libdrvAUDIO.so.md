# `07_MSLIB/utopia/libdrvAUDIO.so`

SHA-256: `7b50590ff5ab9c371a733ec81ce89d19e1d567bec2a6de13fc68fb60fdf6fa4e`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 1908280 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 596, "symbol_examples": ["AudioInitTbl_0", "AudioInitTbl_1", "AudioInputSrcInfo", "AudioPreInitTbl_Clock_0", "AudioPreInitTbl_Clock_1", "Audio_Pcm_Capture1", "Audio_Pcm_Capture2", "Audio_Pcm_HwDma_Reader1", "Audio_Pcm_Mixer_Server", "Audio_Pcm_SwDma_Reader1", "HAL_ADVSOUND_ProcessEnable", "HAL_ADVSOUND_SetParam", "HAL_ADVSOUND_SubProcessEnable", "HAL_AUDIO_ADCInit", "HAL_AUDIO_ALSA_Check", "HAL_AUDIO_ALSA_Enable"], "examples_are_complete": false}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 32, "symbol_examples": ["FLAG_HDMI_AC3_IN_SE", "HAL_AUDIO_EnaEarphone_LowPower_Stage", "HAL_AUDIO_HDMIAutoMute", "HAL_AUDIO_HDMI_AC3_PathCFG", "HAL_AUDIO_HDMI_DolbyMonitor", "HAL_AUDIO_HDMI_Get_SYNTH_FREQ", "HAL_AUDIO_HDMI_NonpcmMonitor", "HAL_AUDIO_HDMI_NonpcmMonitor2", "HAL_AUDIO_HDMI_RX_GetHdmiInAudioStatus", "HAL_AUDIO_HDMI_SetNonpcm", "HAL_AUDIO_HDMI_Set_DwonSample", "HAL_AUDIO_HDMI_TX_SetMode", "HAL_AUDIO_HDMI_Tx_GetStatus", "HAL_AUDIO_SetPowerDownWait", "HAL_AUDIO_SetPowerOn", "HAL_SOUND_PowerDown_Wait"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["HAL_AUDIO_SetDataCaptureSource", "MDrv_AUDIO_SetDataCaptureSource"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 9, "symbol_examples": ["HAL_AUDIO_GetAnalogConfig", "HAL_AUDIO_PCM_Dump_Setting", "HAL_AUDIO_PCM_HwDma_Reader1_Apply_Setting", "HAL_AUDIO_PCM_SwDma_Reader1_Apply_Setting", "HAL_AUDIO_SetAnalogConfig", "MDrv_AUDIO_GetAnalogConfig", "MDrv_AUDIO_SetAnalogConfig", "MDrv_AUDIO_VoIP_Config", "stCurrentAnalogConfig"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 43 / 861.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 823; semboller: 3210.
- Xref: 11582; analizde call tipli xref: 0.
- Computed-call instruction: 3052 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/7b50590ff5ab9c371a733ec81ce89d19e1d567bec2a6de13fc68fb60fdf6fa4e/functions.jsonl) · [Xref](../../../analiz/native/system-modules/7b50590ff5ab9c371a733ec81ce89d19e1d567bec2a6de13fc68fb60fdf6fa4e/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/7b50590ff5ab9c371a733ec81ce89d19e1d567bec2a6de13fc68fb60fdf6fa4e/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/7b50590ff5ab9c371a733ec81ce89d19e1d567bec2a6de13fc68fb60fdf6fa4e/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00028060` | `HAL_AUDIO_GET_INIT_FLAG` | [C](../../../analiz/native/system-modules/7b50590ff5ab9c371a733ec81ce89d19e1d567bec2a6de13fc68fb60fdf6fa4e/00028060.c) |
| `0001b064` | `MDrv_SOUND_TruVolume_Enable` | [C](../../../analiz/native/system-modules/7b50590ff5ab9c371a733ec81ce89d19e1d567bec2a6de13fc68fb60fdf6fa4e/0001b064.c) |
| `0001b8a4` | `MDrv_AUDIO_update_DspUsage` | [C](../../../analiz/native/system-modules/7b50590ff5ab9c371a733ec81ce89d19e1d567bec2a6de13fc68fb60fdf6fa4e/0001b8a4.c) |
| `0001b9a8` | `MDrv_AUDIO_PCMCapture_Init` | [C](../../../analiz/native/system-modules/7b50590ff5ab9c371a733ec81ce89d19e1d567bec2a6de13fc68fb60fdf6fa4e/0001b9a8.c) |
| `0001b9dc` | `MDrv_AUDIO_SetDataCaptureSource` | [C](../../../analiz/native/system-modules/7b50590ff5ab9c371a733ec81ce89d19e1d567bec2a6de13fc68fb60fdf6fa4e/0001b9dc.c) |
| `0001ba78` | `MDrv_AUDIO_USBPCM_Enable` | [C](../../../analiz/native/system-modules/7b50590ff5ab9c371a733ec81ce89d19e1d567bec2a6de13fc68fb60fdf6fa4e/0001ba78.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
