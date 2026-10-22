# `07_MSLIB/directfb-1.4-0/wm/libdirectfbwm_default.so`

SHA-256: `5e01cb95e5a9fd43aac1e67b2c3815cc3c91da6233a8614ed1182537f69c9d1e`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 57760 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 11, "symbol_examples": ["dfb_window_destroy", "dfb_window_move", "dfb_window_post_event", "dfb_window_raisetotop", "dfb_window_resize", "dfb_window_set_opacity", "dfb_window_set_rotation", "dfb_windowstack_cursor_enable", "dfb_windowstack_cursor_set_opacity", "dfb_windowstack_cursor_warp", "dfb_windowstack_repaint_all"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 5, "symbol_examples": ["dfb_config", "dfb_layer_region_get_configuration", "dfb_layer_region_set_configuration", "dfb_surface_reconfig", "direct_config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libz.so.1`, `libm.so.6`, `libdirect-1.4.so.0`, `libfusion-1.4.so.0`, `libdirectfb-1.4.so.0`, `libdl.so.2`, `librt.so.1`, `libpthread.so.0`, `libdrvMVOP.so`, `libapiGFX.so`, `libapiGOP.so`, `liblinux.so`, `libdrvVE.so`, `libapiXC.so`, `libapiPNL.so`, `libdrvWDT.so`, `libdrvSAR.so`, `libapiVDEC.so`, `libdrvIPAUTH.so`, `libapiJPEG.so`, `libc.so.6`
- Dynamic import/export: 75 / 11.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 156; semboller: 825.
- Xref: 1621; analizde call tipli xref: 0.
- Computed-call instruction: 273 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/5e01cb95e5a9fd43aac1e67b2c3815cc3c91da6233a8614ed1182537f69c9d1e/functions.jsonl) · [Xref](../../../analiz/native/system-modules/5e01cb95e5a9fd43aac1e67b2c3815cc3c91da6233a8614ed1182537f69c9d1e/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/5e01cb95e5a9fd43aac1e67b2c3815cc3c91da6233a8614ed1182537f69c9d1e/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/5e01cb95e5a9fd43aac1e67b2c3815cc3c91da6233a8614ed1182537f69c9d1e/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00011470` | `_init` | [C](../../../analiz/native/system-modules/5e01cb95e5a9fd43aac1e67b2c3815cc3c91da6233a8614ed1182537f69c9d1e/00011470.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
