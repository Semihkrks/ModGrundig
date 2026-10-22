# `07_MSLIB/libatalla.so`

SHA-256: `fcc2c2edfcf8dd7b0ee55f8f3ae1c2b09df45ff48fc14a8d1bceabb667153046`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 15153 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["p_Atalla_GetHardwareConfig"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libcrypto.so.0.9.8`, `libdl.so.2`, `libc.so.6`
- Dynamic import/export: 46 / 13.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 106; semboller: 277.
- Xref: 429; analizde call tipli xref: 0.
- Computed-call instruction: 129 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/fcc2c2edfcf8dd7b0ee55f8f3ae1c2b09df45ff48fc14a8d1bceabb667153046/functions.jsonl) · [Xref](../../../analiz/native/system-modules/fcc2c2edfcf8dd7b0ee55f8f3ae1c2b09df45ff48fc14a8d1bceabb667153046/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/fcc2c2edfcf8dd7b0ee55f8f3ae1c2b09df45ff48fc14a8d1bceabb667153046/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/fcc2c2edfcf8dd7b0ee55f8f3ae1c2b09df45ff48fc14a8d1bceabb667153046/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010cc4` | `_init` | [C](../../../analiz/native/system-modules/fcc2c2edfcf8dd7b0ee55f8f3ae1c2b09df45ff48fc14a8d1bceabb667153046/00010cc4.c) |
| `00011a6c` | `atalla_init` | [C](../../../analiz/native/system-modules/fcc2c2edfcf8dd7b0ee55f8f3ae1c2b09df45ff48fc14a8d1bceabb667153046/00011a6c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
