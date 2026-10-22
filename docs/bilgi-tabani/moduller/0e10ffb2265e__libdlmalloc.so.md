# `07_MSLIB/libdlmalloc.so`

SHA-256: `0e10ffb2265eeb22fd2f5a49e7540e7975137d204d96ce6dcd7d1e6364efb059`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 27316 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `librt.so.1`, `libm.so.6`, `libpthread.so.0`, `libc.so.6`
- Dynamic import/export: 21 / 45.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 59; semboller: 457.
- Xref: 847; analizde call tipli xref: 0.
- Computed-call instruction: 80 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/0e10ffb2265eeb22fd2f5a49e7540e7975137d204d96ce6dcd7d1e6364efb059/functions.jsonl) · [Xref](../../../analiz/native/system-modules/0e10ffb2265eeb22fd2f5a49e7540e7975137d204d96ce6dcd7d1e6364efb059/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/0e10ffb2265eeb22fd2f5a49e7540e7975137d204d96ce6dcd7d1e6364efb059/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/0e10ffb2265eeb22fd2f5a49e7540e7975137d204d96ce6dcd7d1e6364efb059/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f2a0c90` | `_init` | [C](../../../analiz/native/system-modules/0e10ffb2265eeb22fd2f5a49e7540e7975137d204d96ce6dcd7d1e6364efb059/2f2a0c90.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
