# `07_MSLIB/directfb-1.4-0/wm/libdirectfbwm_sawman.so`

SHA-256: `23e32768765a6e2cec808684ae62ac5aed2b89357b85b6a2cdadfde73f2edb13`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 38344 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 8, "symbol_examples": ["dfb_windowstack_cursor_warp", "dfb_windowstack_repaint_all", "sawman_draw_cursor", "sawman_insert_window", "sawman_remove_window", "sawman_update_window", "sawman_window_at_pointer", "sawman_window_border"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 5, "symbol_examples": ["dfb_layer_context_get_configuration", "dfb_surface_reconfig", "direct_config", "sawman_config", "sawman_config_init"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libz.so.1`, `libm.so.6`, `libdirect-1.4.so.0`, `libdirectfb-1.4.so.0`, `libfusion-1.4.so.0`, `libsawman-1.4.so.0`, `libdl.so.2`, `librt.so.1`, `libpthread.so.0`, `libdrvMVOP.so`, `libapiGFX.so`, `libapiGOP.so`, `liblinux.so`, `libdrvVE.so`, `libapiXC.so`, `libapiPNL.so`, `libdrvWDT.so`, `libdrvSAR.so`, `libapiVDEC.so`, `libdrvIPAUTH.so`, `libapiJPEG.so`, `libc.so.6`
- Dynamic import/export: 65 / 11.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 134; semboller: 877.
- Xref: 1608; analizde call tipli xref: 0.
- Computed-call instruction: 351 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/23e32768765a6e2cec808684ae62ac5aed2b89357b85b6a2cdadfde73f2edb13/functions.jsonl) · [Xref](../../../analiz/native/system-modules/23e32768765a6e2cec808684ae62ac5aed2b89357b85b6a2cdadfde73f2edb13/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/23e32768765a6e2cec808684ae62ac5aed2b89357b85b6a2cdadfde73f2edb13/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/23e32768765a6e2cec808684ae62ac5aed2b89357b85b6a2cdadfde73f2edb13/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00011270` | `_init` | [C](../../../analiz/native/system-modules/23e32768765a6e2cec808684ae62ac5aed2b89357b85b6a2cdadfde73f2edb13/00011270.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
