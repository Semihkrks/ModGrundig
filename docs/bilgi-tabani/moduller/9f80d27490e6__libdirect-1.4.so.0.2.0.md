# `07_MSLIB/libdirect-1.4.so.0.2.0`

SHA-256: `9f80d27490e6b3fc33438047f211a009b619d4bb4881da611591000128c699c2`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 119516 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["direct_stream_remote"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 8, "symbol_examples": ["CreateDirectConfigHashTable", "DirectConfigTable", "SearchDirectConfigHashTable", "direct_config", "direct_config_destroy", "direct_config_set", "direct_config_usage", "direct_debug_config_domain"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libz.so.1`, `libm.so.6`, `libdl.so.2`, `librt.so.1`, `libpthread.so.0`, `libdrvMVOP.so`, `libapiGFX.so`, `libapiGOP.so`, `liblinux.so`, `libdrvVE.so`, `libapiXC.so`, `libapiPNL.so`, `libdrvWDT.so`, `libdrvSAR.so`, `libapiVDEC.so`, `libdrvIPAUTH.so`, `libapiJPEG.so`, `libc.so.6`
- Dynamic import/export: 114 / 179.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 290; semboller: 1624.
- Xref: 4209; analizde call tipli xref: 0.
- Computed-call instruction: 901 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/9f80d27490e6b3fc33438047f211a009b619d4bb4881da611591000128c699c2/functions.jsonl) · [Xref](../../../analiz/native/system-modules/9f80d27490e6b3fc33438047f211a009b619d4bb4881da611591000128c699c2/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/9f80d27490e6b3fc33438047f211a009b619d4bb4881da611591000128c699c2/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/9f80d27490e6b3fc33438047f211a009b619d4bb4881da611591000128c699c2/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f10cbf8` | `direct_stream_remote` | [C](../../../analiz/native/system-modules/9f80d27490e6b3fc33438047f211a009b619d4bb4881da611591000128c699c2/2f10cbf8.c) |
| `2f108648` | `dfb_MPool_Init` | [C](../../../analiz/native/system-modules/9f80d27490e6b3fc33438047f211a009b619d4bb4881da611591000128c699c2/2f108648.c) |
| `2f108774` | `dfb_MMA_Init` | [C](../../../analiz/native/system-modules/9f80d27490e6b3fc33438047f211a009b619d4bb4881da611591000128c699c2/2f108774.c) |
| `2f10375c` | `_init` | [C](../../../analiz/native/system-modules/9f80d27490e6b3fc33438047f211a009b619d4bb4881da611591000128c699c2/2f10375c.c) |
| `2f105fc8` | `direct_initialize` | [C](../../../analiz/native/system-modules/9f80d27490e6b3fc33438047f211a009b619d4bb4881da611591000128c699c2/2f105fc8.c) |
| `2f113d2c` | `direct_thread_remove_init_handler` | [C](../../../analiz/native/system-modules/9f80d27490e6b3fc33438047f211a009b619d4bb4881da611591000128c699c2/2f113d2c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
