# `06_RFS/bin/mkdgiff`

SHA-256: `e4ef15bf243acf84e3c8a82b4e003e527f4aa6f3084abed8c55efcf36c1fd700`

Durum: **Ghidra indeks tamam**.

Tür: EXEC (Executable file); ELF32 LE MIPS; 15300 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["direct_config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libfreetype.so.6`, `libdirect-1.2.so.0`, `libz.so.1`, `libdl.so.2`, `libpthread.so.0`, `libc.so.6`
- Dynamic import/export: 27 / 17.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 37; semboller: 181.
- Xref: 312; analizde call tipli xref: 4.
- Computed-call instruction: 24 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/e4ef15bf243acf84e3c8a82b4e003e527f4aa6f3084abed8c55efcf36c1fd700/functions.jsonl) · [Xref](../../../analiz/native/system-modules/e4ef15bf243acf84e3c8a82b4e003e527f4aa6f3084abed8c55efcf36c1fd700/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/e4ef15bf243acf84e3c8a82b4e003e527f4aa6f3084abed8c55efcf36c1fd700/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/e4ef15bf243acf84e3c8a82b4e003e527f4aa6f3084abed8c55efcf36c1fd700/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00400b58` | `_init` | [C](../../../analiz/native/system-modules/e4ef15bf243acf84e3c8a82b4e003e527f4aa6f3084abed8c55efcf36c1fd700/00400b58.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
