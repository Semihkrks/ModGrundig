# `09_CONFIG/libMMAPInfo.so`

SHA-256: `1c5530208023b5789bc63dc107a3ffcdbace97eac3814554173575c7221917da`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 35384 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["iniparser_freedict", "iniparser_getNumberOfSection", "iniparser_getVal", "iniparser_load"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libiniparser.so`, `libpthread.so.0`, `libstdc++.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 42 / 66.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 97; semboller: 556.
- Xref: 1744; analizde call tipli xref: 0.
- Computed-call instruction: 435 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/1c5530208023b5789bc63dc107a3ffcdbace97eac3814554173575c7221917da/functions.jsonl) · [Xref](../../../analiz/native/system-modules/1c5530208023b5789bc63dc107a3ffcdbace97eac3814554173575c7221917da/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/1c5530208023b5789bc63dc107a3ffcdbace97eac3814554173575c7221917da/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/1c5530208023b5789bc63dc107a3ffcdbace97eac3814554173575c7221917da/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f60196c` | `_init` | [C](../../../analiz/native/system-modules/1c5530208023b5789bc63dc107a3ffcdbace97eac3814554173575c7221917da/2f60196c.c) |
| `2f604508` | `MMAPInfo::Init` | [C](../../../analiz/native/system-modules/1c5530208023b5789bc63dc107a3ffcdbace97eac3814554173575c7221917da/2f604508.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
