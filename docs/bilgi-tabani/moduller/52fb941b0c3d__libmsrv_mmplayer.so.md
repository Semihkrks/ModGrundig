# `07_MSLIB/libmsrv_mmplayer.so`

SHA-256: `52fb941b0c3df02b135d22d1da548a64fcecef1d1ec2a41e75ae3e57fbf5badb`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 82828 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 14, "symbol_examples": ["MMSDK_ES_SwitchAudioTrack", "MMSDK_GetAudioTrackID", "MMSDK_GetAudioTrackPID", "MMSDK_SetAudioTrackID", "MMSDK_SetAudioTrackPID", "_ZN23MSrv_MM_PlayerInterface14m_u32AudioItemE", "_ZN23MSrv_MM_PlayerInterface15m_u32AudioItem2E", "_ZN23MSrv_MM_PlayerInterface18MM_GetAudioTrackIDEmPh", "_ZN23MSrv_MM_PlayerInterface18MM_SetAudioTrackIDEmh", "_ZN23MSrv_MM_PlayerInterface19MM_GetAudioTrackPIDEmP17ST_PLAYER_TS_INFO", "_ZN23MSrv_MM_PlayerInterface19MM_SetAudioTrackPIDEmPK17ST_PLAYER_TS_INFO", "_ZN23MSrv_MM_PlayerInterface19MM_SwitchAudioTrackEmRK21ST_PLAYER_AUDIO_PARAM", "_ZN23MSrv_MM_PlayerInterface20MM_GetAudioTrackInfoEmPmm", "_ZN23MSrv_MM_PlayerInterface24MM_GetAudioTrackLanguageEmmPm"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["MMSDK_CaptureLogo", "MMSDK_MoveViewWindow", "_ZN23MSrv_MM_PlayerInterface14MM_CaptureLogoEPc", "_ZN23MSrv_MM_PlayerInterface17MM_MoveViewWindowEm22EN_VIEW_MOVE_DIRECTIONt"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["_ZN23MSrv_MM_PlayerInterface15MM_BeginPreviewEmRK18ST_PREVIEW_SETTING"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libmmsdk.so`, `libutilities.so`, `libdirectfb-1.4.so.0`, `librt.so.1`, `libpthread.so.0`, `libdirect-1.4.so.0`, `libMStarSDK.so`, `libMStarSDK_customer.so`, `libfreetype.so.6`, `libMLog.so`, `libmuf.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 113 / 148.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 243; semboller: 1535.
- Xref: 4051; analizde call tipli xref: 0.
- Computed-call instruction: 556 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 3/3.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/52fb941b0c3df02b135d22d1da548a64fcecef1d1ec2a41e75ae3e57fbf5badb/functions.jsonl) · [Xref](../../../analiz/native/system-modules/52fb941b0c3df02b135d22d1da548a64fcecef1d1ec2a41e75ae3e57fbf5badb/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/52fb941b0c3df02b135d22d1da548a64fcecef1d1ec2a41e75ae3e57fbf5badb/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/52fb941b0c3df02b135d22d1da548a64fcecef1d1ec2a41e75ae3e57fbf5badb/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f1fd9c4` | `MSrv_MM_PlayerInterface::MM_Initialize_APSelect` | [C](../../../analiz/native/system-modules/52fb941b0c3df02b135d22d1da548a64fcecef1d1ec2a41e75ae3e57fbf5badb/2f1fd9c4.c) |
| `2f1f4be8` | `_init` | [C](../../../analiz/native/system-modules/52fb941b0c3df02b135d22d1da548a64fcecef1d1ec2a41e75ae3e57fbf5badb/2f1f4be8.c) |
| `2f1fd7e8` | `MSrv_MM_PlayerInterface::MM_Initialize` | [C](../../../analiz/native/system-modules/52fb941b0c3df02b135d22d1da548a64fcecef1d1ec2a41e75ae3e57fbf5badb/2f1fd7e8.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
