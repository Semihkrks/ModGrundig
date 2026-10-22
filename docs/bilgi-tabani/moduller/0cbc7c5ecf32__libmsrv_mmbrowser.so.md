# `07_MSLIB/libmsrv_mmbrowser.so`

SHA-256: `0cbc7c5ecf32731a9ab97b08c0e58f3468711c0128f98929a1c7ca2724f619cc`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 596492 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 20, "symbol_examples": ["_ZN17MSrv_MediaBrowser16ChangeAudioTrackE27EN_MEDIA_BROWSER_MEDIA_TYPEm", "_ZN17MSrv_MediaBrowser18GetAudioTrackIndexE27EN_MEDIA_BROWSER_MEDIA_TYPE", "_ZN17MSrv_MediaBrowser21GetAudioTrackLanguageE27EN_MEDIA_BROWSER_MEDIA_TYPEmPm", "_ZN17MSrv_MediaBrowser22GetAudioTrackCodecInfoE27EN_MEDIA_BROWSER_MEDIA_TYPEm", "_ZN17MSrv_MediaBrowser29MM_Interface_ChangeAudioTrackE26EN_MM_INTERFACE_MEDIA_TYPEm", "_ZN17MSrv_MediaBrowser31MM_Interface_GetAudioTrackIndexE26EN_MM_INTERFACE_MEDIA_TYPE", "_ZN20MSrv_MediaFilePlayer15SetAudioTrackIDEm", "_ZN20MSrv_MediaFilePlayer18GetAudioTrackIndexEv", "_ZN20MSrv_MediaFilePlayer21GetAudioTrackLanguageEmPm", "_ZN20MSrv_MediaFilePlayer22GetAudioTrackCodecInfoEPmm", "_ZN23MSrv_MM_PlayerInterface18MM_GetAudioTrackIDEmPh", "_ZN23MSrv_MM_PlayerInterface18MM_SetAudioTrackIDEmh", "_ZN23MSrv_MM_PlayerInterface20MM_GetAudioTrackInfoEmPmm", "_ZN23MSrv_MM_PlayerInterface24MM_GetAudioTrackLanguageEmmPm", "_ZN25MSrv_MediaFilePlayerCombo15SetAudioTrackIDEm", "_ZN25MSrv_MediaFilePlayerCombo18GetAudioTrackIndexEv"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 16, "symbol_examples": ["_ZN17MSrv_MediaBrowser11CaptureLogoEPc", "_ZN17MSrv_MediaBrowser16SetDisplayWindowE27EN_MEDIA_BROWSER_MEDIA_TYPEmmmmh", "_ZN17MSrv_MediaBrowser16SetPreviewWindowE27EN_MEDIA_BROWSER_MEDIA_TYPEmmmmh", "_ZN17MSrv_MediaBrowser29MM_Interface_SetPreviewWindowE26EN_MM_INTERFACE_MEDIA_TYPEmmmmh", "_ZN20MSrv_MediaFilePlayer11CaptureLogoEPc", "_ZN20MSrv_MediaFilePlayer24SetDisplayWindowPositionEmmmmh", "_ZN20MSrv_MediaFilePlayer24SetPreviewWindowPositionEmmmmh", "_ZN23MSrv_MM_PlayerInterface14MM_CaptureLogoEPc", "_ZN23MSrv_MM_PlayerInterface17MM_MoveViewWindowEm22EN_VIEW_MOVE_DIRECTIONt", "_ZN25MSrv_MediaFilePlayerCombo24SetDisplayWindowPositionEmmmmh", "_ZN25MSrv_MediaFilePlayerCombo24SetPreviewWindowPositionEmmmmh", "_ZN25MSrv_MediaFilePlayerMovie24SetDisplayWindowPositionEmmmmh", "_ZN25MSrv_MediaFilePlayerMovie24SetPreviewWindowPositionEmmmmh", "_ZN25MSrv_MediaFilePlayerPhoto11CaptureLogoEPc", "_ZN25MSrv_MediaFilePlayerPhoto24SetDisplayWindowPositionEmmmmh", "_ZN25MSrv_MediaFilePlayerPhoto24SetPreviewWindowPositionEmmmmh"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 29, "symbol_examples": ["_ZN17MSrv_MediaBrowser14UpdateFolderDBEP18MSrv_MediaDatabase", "_ZN17MSrv_MediaBrowser14UpdateFolderDBEP18MSrv_MediaDatabaseP15MSrv_MediaDrive", "_ZN17MSrv_MediaBrowser27SystemSettingAssistantMovieERKSs", "_ZN17MSrv_MediaBrowser31StopSystemSettingAssistantMovieEv", "_ZN17MSrv_MediaBrowser32PauseSystemSettingAssistantMovieEv", "_ZN18MSrv_MediaDatabase10GetFileNumEv", "_ZN18MSrv_MediaDatabase10HideFolderEh", "_ZN18MSrv_MediaDatabase10IsSelectedEm", "_ZN18MSrv_MediaDatabase10RemoveFileEm", "_ZN18MSrv_MediaDatabase11SetSelectedEm", "_ZN18MSrv_MediaDatabase12GetFolderNumEv", "_ZN18MSrv_MediaDatabase12SetOrderTypeE28EN_MEDIA_DATABASE_ORDER_MODE", "_ZN18MSrv_MediaDatabase13SetUnselectedEm", "_ZN18MSrv_MediaDatabase4InitEPK22ST_MEDIA_DATABASE_INIT", "_ZN18MSrv_MediaDatabase5ClearEv", "_ZN18MSrv_MediaDatabase6DeinitEv"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libmsrv_mmplayer.so`, `libutilities.so`, `libdirectfb-1.4.so.0`, `librt.so.1`, `libpthread.so.0`, `libdirect-1.4.so.0`, `libMStarSDK.so`, `libMStarSDK_customer.so`, `libfreetype.so.6`, `libMLog.so`, `libmuf.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 262 / 1153.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 1314; semboller: 13650.
- Xref: 35559; analizde call tipli xref: 0.
- Computed-call instruction: 5993 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/0cbc7c5ecf32731a9ab97b08c0e58f3468711c0128f98929a1c7ca2724f619cc/functions.jsonl) · [Xref](../../../analiz/native/system-modules/0cbc7c5ecf32731a9ab97b08c0e58f3468711c0128f98929a1c7ca2724f619cc/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/0cbc7c5ecf32731a9ab97b08c0e58f3468711c0128f98929a1c7ca2724f619cc/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/0cbc7c5ecf32731a9ab97b08c0e58f3468711c0128f98929a1c7ca2724f619cc/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2e3ba16c` | `MSrv_MediaFilePlayerCombo::ChangeChannel` | [C](../../../analiz/native/system-modules/0cbc7c5ecf32731a9ab97b08c0e58f3468711c0128f98929a1c7ca2724f619cc/2e3ba16c.c) |
| `2e3ba1a8` | `MSrv_MediaFilePlayerCombo::GetChannelIndex` | [C](../../../analiz/native/system-modules/0cbc7c5ecf32731a9ab97b08c0e58f3468711c0128f98929a1c7ca2724f619cc/2e3ba1a8.c) |
| `2e3ae4b8` | `MSrv_MediaDatabase::Deinit` | [C](../../../analiz/native/system-modules/0cbc7c5ecf32731a9ab97b08c0e58f3468711c0128f98929a1c7ca2724f619cc/2e3ae4b8.c) |
| `2e3c8a98` | `MSrv_MediaPlayList::Deinit` | [C](../../../analiz/native/system-modules/0cbc7c5ecf32731a9ab97b08c0e58f3468711c0128f98929a1c7ca2724f619cc/2e3c8a98.c) |
| `2e3a827c` | `MSrv_MediaBrowser::UpdateFolderDB` | [C](../../../analiz/native/system-modules/0cbc7c5ecf32731a9ab97b08c0e58f3468711c0128f98929a1c7ca2724f619cc/2e3a827c.c) |
| `2e3a639c` | `MSrv_MediaBrowser::MM_Interface_Init` | [C](../../../analiz/native/system-modules/0cbc7c5ecf32731a9ab97b08c0e58f3468711c0128f98929a1c7ca2724f619cc/2e3a639c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
