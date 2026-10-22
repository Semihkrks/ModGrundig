# `06_RFS/etc/init.d/nscd`

SHA-256: `a1f8bda87e2fc667420a47965d87c9ad114c6586c3ec77b0e7593992ddec1973`

Durum: **Ghidra indeks tamam**.

Tür: EXEC (Executable file); ELF32 LE MIPS; 38017 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 79 / 9.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 135; semboller: 623.
- Xref: 1231; analizde call tipli xref: 152.
- Computed-call instruction: 204 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 3/3.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/a1f8bda87e2fc667420a47965d87c9ad114c6586c3ec77b0e7593992ddec1973/functions.jsonl) · [Xref](../../../analiz/native/system-modules/a1f8bda87e2fc667420a47965d87c9ad114c6586c3ec77b0e7593992ddec1973/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/a1f8bda87e2fc667420a47965d87c9ad114c6586c3ec77b0e7593992ddec1973/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/a1f8bda87e2fc667420a47965d87c9ad114c6586c3ec77b0e7593992ddec1973/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00401188` | `_init` | [C](../../../analiz/native/system-modules/a1f8bda87e2fc667420a47965d87c9ad114c6586c3ec77b0e7593992ddec1973/00401188.c) |
| `004057d8` | `__libc_csu_init` | [C](../../../analiz/native/system-modules/a1f8bda87e2fc667420a47965d87c9ad114c6586c3ec77b0e7593992ddec1973/004057d8.c) |
| `004037c0` | `open_socket` | [C](../../../analiz/native/system-modules/a1f8bda87e2fc667420a47965d87c9ad114c6586c3ec77b0e7593992ddec1973/004037c0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
