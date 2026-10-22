# `07_MSLIB/libzmplayer.so`

SHA-256: `22a27083ca0dae21f7cd9e30992edc1e8a2863cca2e754e630fee9869dd20172`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 125716 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 3, "symbol_examples": ["_Z15RtspAType2ACdec15rtsp_audio_type", "_ZN23MSrv_MM_PlayerInterface18MM_GetAudioTrackIDEmPh", "_ZN23MSrv_MM_PlayerInterface18MM_SetAudioTrackIDEmh"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["_ZN23MSrv_MM_PlayerInterface17MM_MoveViewWindowEm22EN_VIEW_MOVE_DIRECTIONt"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["_ZN23MSrv_MM_PlayerInterface15MM_BeginPreviewEmRK18ST_PREVIEW_SETTING"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libmsrv_mmplayer.so`, `libutilities.so`, `libdirectfb-1.4.so.0`, `librt.so.1`, `libpthread.so.0`, `libdirect-1.4.so.0`, `libMStarSDK.so`, `libMStarSDK_customer.so`, `libfreetype.so.6`, `libMLog.so`, `libmuf.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 90 / 61.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 230; semboller: 1520.
- Xref: 3450; analizde call tipli xref: 20.
- Computed-call instruction: 762 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/22a27083ca0dae21f7cd9e30992edc1e8a2863cca2e754e630fee9869dd20172/functions.jsonl) · [Xref](../../../analiz/native/system-modules/22a27083ca0dae21f7cd9e30992edc1e8a2863cca2e754e630fee9869dd20172/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/22a27083ca0dae21f7cd9e30992edc1e8a2863cca2e754e630fee9869dd20172/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/22a27083ca0dae21f7cd9e30992edc1e8a2863cca2e754e630fee9869dd20172/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00012818` | `_init` | [C](../../../analiz/native/system-modules/22a27083ca0dae21f7cd9e30992edc1e8a2863cca2e754e630fee9869dd20172/00012818.c) |
| `0001f6cc` | `MApi_MPlayer_Initialize` | [C](../../../analiz/native/system-modules/22a27083ca0dae21f7cd9e30992edc1e8a2863cca2e754e630fee9869dd20172/0001f6cc.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
