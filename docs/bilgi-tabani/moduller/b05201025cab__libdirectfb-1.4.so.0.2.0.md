# `07_MSLIB/libdirectfb-1.4.so.0.2.0`

SHA-256: `b05201025cab0dd8734708702a910ff54d24eb723e782c0994a26361194c5bf3`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 996548 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["FUN___mst_ir_max_keycode", "FUN___remote"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["dfb_screen_set_powermode"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 164, "symbol_examples": ["DirectFBCheckVersion", "DirectFBCreate", "DirectFBError", "DirectFBErrorFatal", "DirectFBErrorString", "DirectFBGOPSetForceWrite", "DirectFBGetGOPDst", "DirectFBGetGOPIndex", "DirectFBGetMIUCPUOffset", "DirectFBGetMIUCPUOffset64", "DirectFBGetMIUHALOffset", "DirectFBGetMIUHALOffset64", "DirectFBGetMirrorInfo", "DirectFBInit", "DirectFBPreInitFusion", "DirectFBSafeRelease"], "examples_are_complete": false}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 42, "symbol_examples": ["CreateConfigHashTable", "FUN___mst_gop_miu2_setting_extend", "FUN___mst_gop_miu_setting", "FUN___null_setting", "SearchComboConfigHashTable", "SearchConfigHashTable", "dfb_config", "dfb_config_close_dump_settings_file", "dfb_config_destroy", "dfb_config_init", "dfb_config_parse_pixelformat", "dfb_config_read", "dfb_config_set", "dfb_config_usage", "dfb_layer_context_config_shadowlayer", "dfb_layer_context_get_configuration"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libz.so.1`, `libm.so.6`, `libdirect-1.4.so.0`, `libfusion-1.4.so.0`, `libdl.so.2`, `librt.so.1`, `libpthread.so.0`, `libdrvMVOP.so`, `libapiGFX.so`, `libapiGOP.so`, `liblinux.so`, `libdrvVE.so`, `libapiXC.so`, `libapiPNL.so`, `libdrvWDT.so`, `libdrvSAR.so`, `libapiVDEC.so`, `libdrvIPAUTH.so`, `libapiJPEG.so`, `libc.so.6`
- Dynamic import/export: 219 / 979.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 1275; semboller: 11610.
- Xref: 31617; analizde call tipli xref: 0.
- Computed-call instruction: 4543 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/b05201025cab0dd8734708702a910ff54d24eb723e782c0994a26361194c5bf3/functions.jsonl) · [Xref](../../../analiz/native/system-modules/b05201025cab0dd8734708702a910ff54d24eb723e782c0994a26361194c5bf3/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/b05201025cab0dd8734708702a910ff54d24eb723e782c0994a26361194c5bf3/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/b05201025cab0dd8734708702a910ff54d24eb723e782c0994a26361194c5bf3/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2de81bb8` | `FUN___no_font_premult` | [C](../../../analiz/native/system-modules/b05201025cab0dd8734708702a910ff54d24eb723e782c0994a26361194c5bf3/2de81bb8.c) |
| `2de81c30` | `FUN___no_surface_sentinel` | [C](../../../analiz/native/system-modules/b05201025cab0dd8734708702a910ff54d24eb723e782c0994a26361194c5bf3/2de81c30.c) |
| `2de81e34` | `FUN___no_thrifty_surface_buffers` | [C](../../../analiz/native/system-modules/b05201025cab0dd8734708702a910ff54d24eb723e782c0994a26361194c5bf3/2de81e34.c) |
| `2de81ee8` | `FUN___no_deinit_check` | [C](../../../analiz/native/system-modules/b05201025cab0dd8734708702a910ff54d24eb723e782c0994a26361194c5bf3/2de81ee8.c) |
| `2de81f40` | `FUN___cursor_updates` | [C](../../../analiz/native/system-modules/b05201025cab0dd8734708702a910ff54d24eb723e782c0994a26361194c5bf3/2de81f40.c) |
| `2de96d54` | `dfb_updates_init` | [C](../../../analiz/native/system-modules/b05201025cab0dd8734708702a910ff54d24eb723e782c0994a26361194c5bf3/2de96d54.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
