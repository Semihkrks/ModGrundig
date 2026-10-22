# `07_MSLIB/libmmsdk_porting.so`

SHA-256: `3097e030b2ef57031c71791336ef9a9900793746afb1f52a66eaa7a01135a4b7`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 117376 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 39, "symbol_examples": ["PT_Audio_AllocateDecoder", "PT_Audio_CheckInputRequest", "PT_Audio_CheckPlayDone", "PT_Audio_FileEndDataHandle", "PT_Audio_Finalize", "PT_Audio_GetPlayTick", "PT_Audio_Initialize", "PT_Audio_Mute", "PT_Audio_PauseDecode", "PT_Audio_ReleaseDecoder", "PT_Audio_SetInput", "PT_Audio_SetParam", "PT_Audio_StartDecode", "PT_Audio_StopDecode", "_ZN10mapi_audio13SPDIF_SetModeE11SPDIF_TYPE_", "_ZN10mapi_audio18DECODER_SetDTSInfoE19Audio_DTS_infoType_19Audio_DTS_CtrlType_"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 27, "symbol_examples": ["DirectFBGetGOPDst", "DirectFBSetGOPDst", "PT_Display_CloseWindow", "PT_Display_SetXCWindow", "_ZN10mapi_video14DS_ViewZoomingEmPN19mapi_video_datatype25ST_MAPI_VIDEO_WINDOW_TYPEES2_mmm", "_ZN10mapi_video17CaptureMVopOutputEN19mapi_video_datatype25EN_MAPI_GOP_DWIN_DATA_FMTEhmmPNS0_25ST_MAPI_VIDEO_WINDOW_TYPEE", "_ZN14MWindowManager16CreateMSrvWindowE10EN_MSRV_IDP5_Rect", "_ZN14MWindowManager17DestroyMSrvWindowE10EN_MSRV_ID", "_ZN30porting_InternalSubtitleRender10RenderFontEPhthS0_ttt", "_ZN30porting_InternalSubtitleRender10pDFBWindowE", "_ZN30porting_InternalSubtitleRender12CreateWindowEhP8SBT_RecthPv", "_ZN30porting_InternalSubtitleRender12pDFBWindowIPE", "_ZN30porting_InternalSubtitleRender13DestroyWindowEhPv", "_ZN30porting_InternalSubtitleRender13GetWindowInfoEhP8GWinInfoPv", "_ZN30porting_InternalSubtitleRender14RenderFontTextEPhth", "_ZN30porting_InternalSubtitleRender14RenderFont_TTFEPhthS0_ttt"], "examples_are_complete": false}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 15, "symbol_examples": ["PT_GetDivXDRMSetting", "PT_MISC_Demux_GetSettingInfo", "PT_SetDivXDRMSetting", "PT_iniparser_freedict", "PT_iniparser_getstring", "PT_iniparser_load", "_ZN13MSrv_DivX_DRM17GetDivXDRMSettingEP15ST_DIVXDRM_INFO", "_ZN13MSrv_DivX_DRM17SetDivXDRMSettingEP15ST_DIVXDRM_INFO", "_ZN19MSrv_Control_common21GetMSrvSystemDatabaseEv", "_ZN20MSrv_System_Database13GetARCSettingEv", "_ZN9mapi_mvop9SetConfigEN18mapi_mvop_datatype18MAPI_MVOP_InputSelEPNS0_17MAPI_MVOP_VidStatEPNS0_18MAPI_MVOP_InputCfgE", "_ZNK10mapi_demux14GetSettingInfoERmS0_RhS1_", "iniparser_freedict", "iniparser_getstring", "iniparser_load"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libutilities.so`, `libdirectfb-1.4.so.0`, `librt.so.1`, `libpthread.so.0`, `libdirect-1.4.so.0`, `libMStarSDK.so`, `libMStarSDK_customer.so`, `libfreetype.so.6`, `libMLog.so`, `libmuf.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 199 / 212.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 386; semboller: 2356.
- Xref: 5873; analizde call tipli xref: 0.
- Computed-call instruction: 1180 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/3097e030b2ef57031c71791336ef9a9900793746afb1f52a66eaa7a01135a4b7/functions.jsonl) · [Xref](../../../analiz/native/system-modules/3097e030b2ef57031c71791336ef9a9900793746afb1f52a66eaa7a01135a4b7/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/3097e030b2ef57031c71791336ef9a9900793746afb1f52a66eaa7a01135a4b7/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/3097e030b2ef57031c71791336ef9a9900793746afb1f52a66eaa7a01135a4b7/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f1669ac` | `porting_InternalSubtitleRender::SetSubtitleType` | [C](../../../analiz/native/system-modules/3097e030b2ef57031c71791336ef9a9900793746afb1f52a66eaa7a01135a4b7/2f1669ac.c) |
| `2f1669c4` | `porting_InternalSubtitleRender::SetTtfFontPath` | [C](../../../analiz/native/system-modules/3097e030b2ef57031c71791336ef9a9900793746afb1f52a66eaa7a01135a4b7/2f1669c4.c) |
| `2f1669dc` | `porting_InternalSubtitleRender::SetFTFace` | [C](../../../analiz/native/system-modules/3097e030b2ef57031c71791336ef9a9900793746afb1f52a66eaa7a01135a4b7/2f1669dc.c) |
| `2f1669f4` | `porting_InternalSubtitleRender::SetVideoSize` | [C](../../../analiz/native/system-modules/3097e030b2ef57031c71791336ef9a9900793746afb1f52a66eaa7a01135a4b7/2f1669f4.c) |
| `2f175318` | `PT_Thread_MutexUnlock` | [C](../../../analiz/native/system-modules/3097e030b2ef57031c71791336ef9a9900793746afb1f52a66eaa7a01135a4b7/2f175318.c) |
| `2f17533c` | `PT_Thread_MutexLock` | [C](../../../analiz/native/system-modules/3097e030b2ef57031c71791336ef9a9900793746afb1f52a66eaa7a01135a4b7/2f17533c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
