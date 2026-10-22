# `07_MSLIB/libmmsdk.so`

SHA-256: `d0a66142dfa6be88c16f074c416080bf51262d34bb906053906c095811e649b8`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 544492 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 25, "symbol_examples": ["MMSDK_ES_SwitchAudioTrack", "MMSDK_GetAudioTrackID", "MMSDK_GetAudioTrackPID", "MMSDK_SetAudioTrackID", "MMSDK_SetAudioTrackPID", "PT_Audio_AllocateDecoder", "PT_Audio_AllocateDecoderEx", "PT_Audio_CheckInputRequest", "PT_Audio_CheckPlayDone", "PT_Audio_FileEndDataHandle", "PT_Audio_Finalize", "PT_Audio_GetAudioCodecType", "PT_Audio_GetAudioUnsupport", "PT_Audio_GetPlayTick", "PT_Audio_GetUnsupportAudioCodec", "PT_Audio_Initialize"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["MMSDK_CaptureLogo", "MMSDK_MoveViewWindow", "PT_Display_CloseWindow", "PT_Display_SetXCWindow"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 6, "symbol_examples": ["PT_GetDivXDRMSetting", "PT_MISC_Demux_GetSettingInfo", "PT_SetDivXDRMSetting", "PT_iniparser_freedict", "PT_iniparser_getstring", "PT_iniparser_load"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libmmsdk_porting.so`, `libvdplayer.so`, `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 222 / 99.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 537; semboller: 9672.
- Xref: 19630; analizde call tipli xref: 0.
- Computed-call instruction: 5160 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/d0a66142dfa6be88c16f074c416080bf51262d34bb906053906c095811e649b8/functions.jsonl) · [Xref](../../../analiz/native/system-modules/d0a66142dfa6be88c16f074c416080bf51262d34bb906053906c095811e649b8/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/d0a66142dfa6be88c16f074c416080bf51262d34bb906053906c095811e649b8/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/d0a66142dfa6be88c16f074c416080bf51262d34bb906053906c095811e649b8/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2e424e34` | `_init` | [C](../../../analiz/native/system-modules/d0a66142dfa6be88c16f074c416080bf51262d34bb906053906c095811e649b8/2e424e34.c) |
| `2e44c0c8` | `MMSDK_Initialize` | [C](../../../analiz/native/system-modules/d0a66142dfa6be88c16f074c416080bf51262d34bb906053906c095811e649b8/2e44c0c8.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
