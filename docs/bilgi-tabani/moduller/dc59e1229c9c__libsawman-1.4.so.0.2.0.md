# `07_MSLIB/libsawman-1.4.so.0.2.0`

SHA-256: `dc59e1229c9cd61dd260efbdbbce10ecd8cdc9eb9553d90a325103400095704d`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 53420 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 12, "symbol_examples": ["dfb_gfxcard_drawrectangle", "dfb_window_post_event", "sawman_draw_background", "sawman_draw_cursor", "sawman_draw_window", "sawman_insert_window", "sawman_remove_window", "sawman_showing_window", "sawman_update_window", "sawman_window_at_pointer", "sawman_window_border", "sawman_withdraw_window"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 11, "symbol_examples": ["dfb_config", "dfb_config_parse_pixelformat", "dfb_layer_context_set_configuration", "dfb_layer_context_test_configuration", "dfb_surface_reconfig", "direct_config", "fusion_config", "sawman_config", "sawman_config_init", "sawman_config_set", "sawman_config_usage"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libz.so.1`, `libm.so.6`, `libdirect-1.4.so.0`, `libdirectfb-1.4.so.0`, `libfusion-1.4.so.0`, `libdl.so.2`, `librt.so.1`, `libpthread.so.0`, `libdrvMVOP.so`, `libapiGFX.so`, `libapiGOP.so`, `liblinux.so`, `libdrvVE.so`, `libapiXC.so`, `libapiPNL.so`, `libdrvWDT.so`, `libdrvSAR.so`, `libapiVDEC.so`, `libdrvIPAUTH.so`, `libapiJPEG.so`, `libc.so.6`
- Dynamic import/export: 88 / 39.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 212; semboller: 995.
- Xref: 2473; analizde call tipli xref: 0.
- Computed-call instruction: 320 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/dc59e1229c9cd61dd260efbdbbce10ecd8cdc9eb9553d90a325103400095704d/functions.jsonl) · [Xref](../../../analiz/native/system-modules/dc59e1229c9cd61dd260efbdbbce10ecd8cdc9eb9553d90a325103400095704d/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/dc59e1229c9cd61dd260efbdbbce10ecd8cdc9eb9553d90a325103400095704d/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/dc59e1229c9cd61dd260efbdbbce10ecd8cdc9eb9553d90a325103400095704d/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `0001898c` | `SaWManInit` | [C](../../../analiz/native/system-modules/dc59e1229c9cd61dd260efbdbbce10ecd8cdc9eb9553d90a325103400095704d/0001898c.c) |
| `00011988` | `_init` | [C](../../../analiz/native/system-modules/dc59e1229c9cd61dd260efbdbbce10ecd8cdc9eb9553d90a325103400095704d/00011988.c) |
| `00016f38` | `sawman_update_focus` | [C](../../../analiz/native/system-modules/dc59e1229c9cd61dd260efbdbbce10ecd8cdc9eb9553d90a325103400095704d/00016f38.c) |
| `000151d4` | `sawman_update_window` | [C](../../../analiz/native/system-modules/dc59e1229c9cd61dd260efbdbbce10ecd8cdc9eb9553d90a325103400095704d/000151d4.c) |
| `00018120` | `sawman_initialize` | [C](../../../analiz/native/system-modules/dc59e1229c9cd61dd260efbdbbce10ecd8cdc9eb9553d90a325103400095704d/00018120.c) |
| `0001a810` | `sawman_config_init` | [C](../../../analiz/native/system-modules/dc59e1229c9cd61dd260efbdbbce10ecd8cdc9eb9553d90a325103400095704d/0001a810.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
