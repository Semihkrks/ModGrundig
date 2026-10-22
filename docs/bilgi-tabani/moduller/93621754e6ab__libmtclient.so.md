# `07_MSLIB/libmtclient.so`

SHA-256: `93621754e6ab144ffb8c3d443d6088484312dfd0a1bed7c109416064e9542244`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 32092 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["_ZN13MT_CmdManager19ReadDecimalKeyInputEPKc"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libpthread.so.0`, `libc.so.6`
- Dynamic import/export: 63 / 106.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 193; semboller: 697.
- Xref: 1478; analizde call tipli xref: 0.
- Computed-call instruction: 346 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/93621754e6ab144ffb8c3d443d6088484312dfd0a1bed7c109416064e9542244/functions.jsonl) · [Xref](../../../analiz/native/system-modules/93621754e6ab144ffb8c3d443d6088484312dfd0a1bed7c109416064e9542244/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/93621754e6ab144ffb8c3d443d6088484312dfd0a1bed7c109416064e9542244/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/93621754e6ab144ffb8c3d443d6088484312dfd0a1bed7c109416064e9542244/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `0001258c` | `_init` | [C](../../../analiz/native/system-modules/93621754e6ab144ffb8c3d443d6088484312dfd0a1bed7c109416064e9542244/0001258c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
