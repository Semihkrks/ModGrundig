# `07_MSLIB/libvdplayer.so`

SHA-256: `76fedf3a2226d3e7939a5f6e83362caa0bacacd28cb0849a5f330fe60f3ddfad`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 1077472 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 68, "symbol_examples": ["MApi_AUDIO_CheckInputRequest", "MApi_AUDIO_GetCommAudioInfo", "MApi_AUDIO_GetDDRInfo", "MApi_AUDIO_MM2_checkAesInfo", "MApi_AUDIO_MM2_initAesInfo", "MApi_AUDIO_MM2_inputAesFinished", "MApi_AUDIO_MM_CheckPlayDone", "MApi_AUDIO_SPDIF_GetMode", "MApi_AUDIO_SetAC3PInfo", "MApi_AUDIO_SetCommAudioInfo", "MApi_AUDIO_SetCommand", "MApi_AUDIO_SetInput", "MFP_WAVEFORMATEX_AUDIO_TAGS", "g_bAudioProbe", "g_u8AudioCryptoSize", "g_u8AudioDSPID"], "examples_are_complete": false}, {"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 8, "symbol_examples": ["g_sessionKeyInstance", "msAPI_VDPlayer_Demuxer_GetKeyFramePosition", "msAPI_VDPlayer_Demuxer_SaveEditionKeyIdx", "msAPI_VDPlayer_GetKeyIdx", "msAPI_VDPlayer_GetKeyIdx2", "msAPI_VDPlayer_GetKeyIdxPTS", "msAPI_VDPlayer_GetKeyIdxPTS2", "msAPI_VDPlayer_GetKeyIdxPos"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MApp_StillImage_PowerOnInit"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["mm_png_release_resource"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 12, "symbol_examples": ["msAPI_IO_VDPlayer_ScreenDisplaySetting", "msAPI_StillImage_BMBuffer_Configuration", "msAPI_VDPlayer_BMBuffer_Configuration", "msAPI_VDPlayer_BMBuffer_ReConfiguration", "msAPI_VDPlayer_BMExtBuffer_Reconfiguration", "msAPI_VDPlayer_BMQueue_Configuration", "msAPI_VDPlayer_BufferConfiguration", "msAPI_VDPlayer_Demuxer_BufferConfiguration", "msAPI_VDPlayer_Demuxer_Read_AACConfiguration", "msAPI_VDPlayer_Demuxer_Read_AVCConfiguration", "msAPI_VDPlayer_Demuxer_Read_HEVCConfiguration", "msAPI_VDPlayer_ScreenDisplaySetting"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libtee_mm.so`, `libc.so.6`
- Dynamic import/export: 196 / 1089.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 1229; semboller: 13658.
- Xref: 40382; analizde call tipli xref: 0.
- Computed-call instruction: 7834 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/76fedf3a2226d3e7939a5f6e83362caa0bacacd28cb0849a5f330fe60f3ddfad/functions.jsonl) · [Xref](../../../analiz/native/system-modules/76fedf3a2226d3e7939a5f6e83362caa0bacacd28cb0849a5f330fe60f3ddfad/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/76fedf3a2226d3e7939a5f6e83362caa0bacacd28cb0849a5f330fe60f3ddfad/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/76fedf3a2226d3e7939a5f6e83362caa0bacacd28cb0849a5f330fe60f3ddfad/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2db3a4c0` | `msAPI_StillImage_UpdateDisplayedFrameIndex` | [C](../../../analiz/native/system-modules/76fedf3a2226d3e7939a5f6e83362caa0bacacd28cb0849a5f330fe60f3ddfad/2db3a4c0.c) |
| `2db798d0` | `mm_png_init_read_mem_state` | [C](../../../analiz/native/system-modules/76fedf3a2226d3e7939a5f6e83362caa0bacacd28cb0849a5f330fe60f3ddfad/2db798d0.c) |
| `2db38e9c` | `msAPI_StillImage_BMBuffer_UpdateBase` | [C](../../../analiz/native/system-modules/76fedf3a2226d3e7939a5f6e83362caa0bacacd28cb0849a5f330fe60f3ddfad/2db38e9c.c) |
| `2daf7d50` | `msAPI_VDPlayer_DemuxFLV_InitTmpIdxBuf` | [C](../../../analiz/native/system-modules/76fedf3a2226d3e7939a5f6e83362caa0bacacd28cb0849a5f330fe60f3ddfad/2daf7d50.c) |
| `2db1f410` | `msAPI_VDPlayer_DemuxSWF_InitCompressBuf` | [C](../../../analiz/native/system-modules/76fedf3a2226d3e7939a5f6e83362caa0bacacd28cb0849a5f330fe60f3ddfad/2db1f410.c) |
| `2daca580` | `msAPI_VDPlayer_BMUpdateDemuxBase` | [C](../../../analiz/native/system-modules/76fedf3a2226d3e7939a5f6e83362caa0bacacd28cb0849a5f330fe60f3ddfad/2daca580.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
