# `07_MSLIB/libneon.so.27.2.3`

SHA-256: `3206c1d1095d656da384f5754dd6ba168f794bd86d9d0f61424330e05c250324`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 185976 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["ne_lock_using_resource"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libz.so.1`, `libssl.so.0.9.8`, `libcrypto.so.0.9.8`, `libxml2.so.2`, `libdl.so.2`, `libm.so.6`, `libc.so.6`
- Dynamic import/export: 196 / 310.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 727; semboller: 2661.
- Xref: 7539; analizde call tipli xref: 0.
- Computed-call instruction: 1880 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/3206c1d1095d656da384f5754dd6ba168f794bd86d9d0f61424330e05c250324/functions.jsonl) · [Xref](../../../analiz/native/system-modules/3206c1d1095d656da384f5754dd6ba168f794bd86d9d0f61424330e05c250324/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/3206c1d1095d656da384f5754dd6ba168f794bd86d9d0f61424330e05c250324/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/3206c1d1095d656da384f5754dd6ba168f794bd86d9d0f61424330e05c250324/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00019b90` | `ne_ssl_set_verify` | [C](../../../analiz/native/system-modules/3206c1d1095d656da384f5754dd6ba168f794bd86d9d0f61424330e05c250324/00019b90.c) |
| `000234ec` | `ne_sock_doCRCVerify` | [C](../../../analiz/native/system-modules/3206c1d1095d656da384f5754dd6ba168f794bd86d9d0f61424330e05c250324/000234ec.c) |
| `00023074` | `ne_debug_init` | [C](../../../analiz/native/system-modules/3206c1d1095d656da384f5754dd6ba168f794bd86d9d0f61424330e05c250324/00023074.c) |
| `00029f40` | `ne_i18n_init` | [C](../../../analiz/native/system-modules/3206c1d1095d656da384f5754dd6ba168f794bd86d9d0f61424330e05c250324/00029f40.c) |
| `000155f8` | `_init` | [C](../../../analiz/native/system-modules/3206c1d1095d656da384f5754dd6ba168f794bd86d9d0f61424330e05c250324/000155f8.c) |
| `00033854` | `ne_ssl_context_set_verify` | [C](../../../analiz/native/system-modules/3206c1d1095d656da384f5754dd6ba168f794bd86d9d0f61424330e05c250324/00033854.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
