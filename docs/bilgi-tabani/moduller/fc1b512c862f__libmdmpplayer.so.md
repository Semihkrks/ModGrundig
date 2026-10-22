# `07_MSLIB/libmdmpplayer.so`

SHA-256: `fc1b512c862f110e86051e5fcbdbb4b9760eeb70e7a733f082e5598f1e39cefd`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 80208 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 30, "symbol_examples": ["_Z18MDMPPlayer_SetMuteb", "_Z19MDMPPlayer_VolumeUpv", "_Z20MDMPPlayer_GetVolumev", "_Z20MDMPPlayer_SetVolumei", "_Z21MDMPPlayer_ToggleMutev", "_Z21MDMPPlayer_VolumeDownv", "_Z22MDMPPlayer_GetMuteFlagv", "_Z23MDMPPlayer_SetVideoMuteb", "_Z26MDMPESPlayer_SetAudioCodec21EN_MDMPESPLAYER_AUDIO", "_Z26MDMPPlayer_GetAudioChanneljPj", "_Z26MDMPPlayer_SetAudioTrackIDj", "_Z27MDMPESPlayer_SetAudioConfigP13ST_AUDIO_INFO", "_Z27MDMPPlayer_GetAudioTrackPIDP21ST_MDMPPLAYER_TS_INFO", "_Z27MDMPPlayer_SetAudioTrackPIDPK21ST_MDMPPLAYER_TS_INFO", "_Z28MDMPPlayer_GetAudioTrackInfoPjj", "_Z29MDMPESPlayer_SetAudioChannelsi"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 19, "symbol_examples": ["_Z28MDMPPlayer_Subtitle_DrawTextPKci", "_Z29MDMPPlayer_Subtitle_DrawImagePKcii", "_Z31MDMPPlayer_Subtitle_SetFontFilePKc", "_Z31MDMPPlayer_Subtitle_SetFontSizej", "_Z33MDMPPlayer_Subtitle_ConfigureFontv", "_ZN16MResourceManager10GetDFBFontEmtm", "_ZN23MSrv_MM_PlayerInterface17MM_MoveViewWindowEm22EN_VIEW_MOVE_DIRECTIONt", "_ZN24MSrv_Mdmpplayer_Subtitle11SetFontFileEPKc", "_ZN24MSrv_Mdmpplayer_Subtitle12CreateWindowEhPK8SBT_RecthPKv", "_ZN24MSrv_Mdmpplayer_Subtitle13ConfigureFontEv", "_ZN24MSrv_Mdmpplayer_Subtitle13DestroyWindowEhPKv", "_ZN24MSrv_Mdmpplayer_Subtitle13GetWindowInfoEhP8GWinInfoPKv", "_ZN24MSrv_Mdmpplayer_Subtitle18ClearWindowByColorEhPK8SBT_RectPK15RGBPaletteColorPKv", "_ZN24MSrv_Mdmpplayer_Subtitle18ClearWindowByIndexEhPK8SBT_RecthPKv", "_ZN24MSrv_Mdmpplayer_Subtitle20CreateOnScreenWindowEv", "_ZN24MSrv_Mdmpplayer_Subtitle21CreateOffScreenWindowEv"], "examples_are_complete": false}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["_Z27MDMPESPlayer_SetAudioConfigP13ST_AUDIO_INFO", "_Z33MDMPPlayer_Subtitle_ConfigureFontv", "_ZN23MSrv_MM_PlayerInterface15MM_BeginPreviewEmRK18ST_PREVIEW_SETTING", "_ZN24MSrv_Mdmpplayer_Subtitle13ConfigureFontEv"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libmsrv_mmplayer.so`, `libdirectfb-1.4.so.0`, `librt.so.1`, `libpthread.so.0`, `libdirect-1.4.so.0`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 116 / 133.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 344; semboller: 1097.
- Xref: 3145; analizde call tipli xref: 0.
- Computed-call instruction: 625 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/fc1b512c862f110e86051e5fcbdbb4b9760eeb70e7a733f082e5598f1e39cefd/functions.jsonl) · [Xref](../../../analiz/native/system-modules/fc1b512c862f110e86051e5fcbdbb4b9760eeb70e7a733f082e5598f1e39cefd/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/fc1b512c862f110e86051e5fcbdbb4b9760eeb70e7a733f082e5598f1e39cefd/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/fc1b512c862f110e86051e5fcbdbb4b9760eeb70e7a733f082e5598f1e39cefd/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `000170c8` | `MDMPPlayer_VolumeDown` | [C](../../../analiz/native/system-modules/fc1b512c862f110e86051e5fcbdbb4b9760eeb70e7a733f082e5598f1e39cefd/000170c8.c) |
| `00017108` | `MDMPPlayer_VolumeUp` | [C](../../../analiz/native/system-modules/fc1b512c862f110e86051e5fcbdbb4b9760eeb70e7a733f082e5598f1e39cefd/00017108.c) |
| `00017148` | `MDMPPlayer_ToggleMute` | [C](../../../analiz/native/system-modules/fc1b512c862f110e86051e5fcbdbb4b9760eeb70e7a733f082e5598f1e39cefd/00017148.c) |
| `00017084` | `MDMPPlayer_GetMuteFlag` | [C](../../../analiz/native/system-modules/fc1b512c862f110e86051e5fcbdbb4b9760eeb70e7a733f082e5598f1e39cefd/00017084.c) |
| `000171e4` | `MDMPPlayer_GetVolume` | [C](../../../analiz/native/system-modules/fc1b512c862f110e86051e5fcbdbb4b9760eeb70e7a733f082e5598f1e39cefd/000171e4.c) |
| `00017228` | `MDMPPlayer_SetVolume` | [C](../../../analiz/native/system-modules/fc1b512c862f110e86051e5fcbdbb4b9760eeb70e7a733f082e5598f1e39cefd/00017228.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
