# `07_MSLIB/libiniparser.so`

SHA-256: `16e50b51510af8b477463a0aee1b784a49651d89e16d2638e87298130152912b`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 19616 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 18, "symbol_examples": ["iniparser_dump", "iniparser_dump_ini", "iniparser_find_entry", "iniparser_freedict", "iniparser_getNumberOfSection", "iniparser_getVal", "iniparser_getboolean", "iniparser_getdouble", "iniparser_getint", "iniparser_getnsec", "iniparser_getsecname", "iniparser_getstring", "iniparser_getunsignedint", "iniparser_hex_getstring", "iniparser_hex_setstring", "iniparser_load"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 34 / 43.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 73; semboller: 384.
- Xref: 1096; analizde call tipli xref: 0.
- Computed-call instruction: 229 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/16e50b51510af8b477463a0aee1b784a49651d89e16d2638e87298130152912b/functions.jsonl) · [Xref](../../../analiz/native/system-modules/16e50b51510af8b477463a0aee1b784a49651d89e16d2638e87298130152912b/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/16e50b51510af8b477463a0aee1b784a49651d89e16d2638e87298130152912b/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/16e50b51510af8b477463a0aee1b784a49651d89e16d2638e87298130152912b/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f720dbc` | `_init` | [C](../../../analiz/native/system-modules/16e50b51510af8b477463a0aee1b784a49651d89e16d2638e87298130152912b/2f720dbc.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
