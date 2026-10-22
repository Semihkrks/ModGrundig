# `06_RFS/sbin/iwlist`

SHA-256: `e475db7905e1a75068267dd4aee811a3c8fbfccd4c730e2bb411c5b38ba8dd30`

Durum: **Ghidra indeks tamam**.

Tür: EXEC (Executable file); ELF32 LE MIPS; 36610 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["print_txpower_info"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["iw_auth_settings"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libiw.so.29`, `libm.so.6`, `libc.so.6`
- Dynamic import/export: 49 / 13.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 75; semboller: 563.
- Xref: 1600; analizde call tipli xref: 4.
- Computed-call instruction: 370 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 3/3.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/e475db7905e1a75068267dd4aee811a3c8fbfccd4c730e2bb411c5b38ba8dd30/functions.jsonl) · [Xref](../../../analiz/native/system-modules/e475db7905e1a75068267dd4aee811a3c8fbfccd4c730e2bb411c5b38ba8dd30/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/e475db7905e1a75068267dd4aee811a3c8fbfccd4c730e2bb411c5b38ba8dd30/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/e475db7905e1a75068267dd4aee811a3c8fbfccd4c730e2bb411c5b38ba8dd30/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00400c20` | `_init` | [C](../../../analiz/native/system-modules/e475db7905e1a75068267dd4aee811a3c8fbfccd4c730e2bb411c5b38ba8dd30/00400c20.c) |
| `00404af8` | `__libc_csu_init` | [C](../../../analiz/native/system-modules/e475db7905e1a75068267dd4aee811a3c8fbfccd4c730e2bb411c5b38ba8dd30/00404af8.c) |
| `00402b40` | `print_txpower_info` | [C](../../../analiz/native/system-modules/e475db7905e1a75068267dd4aee811a3c8fbfccd4c730e2bb411c5b38ba8dd30/00402b40.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
