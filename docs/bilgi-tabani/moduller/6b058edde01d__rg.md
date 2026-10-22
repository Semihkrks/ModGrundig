# `06_RFS/bin/rg`

SHA-256: `6b058edde01d3291177697454558236522583fe917d93a93f461cb0a3798645c`

Durum: **Ghidra indeks tamam**.

Tür: EXEC (Executable file); ELF32 LE MIPS; 7236 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 14 / 4.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 23; semboller: 96.
- Xref: 158; analizde call tipli xref: 4.
- Computed-call instruction: 22 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/6b058edde01d3291177697454558236522583fe917d93a93f461cb0a3798645c/functions.jsonl) · [Xref](../../../analiz/native/system-modules/6b058edde01d3291177697454558236522583fe917d93a93f461cb0a3798645c/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/6b058edde01d3291177697454558236522583fe917d93a93f461cb0a3798645c/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/6b058edde01d3291177697454558236522583fe917d93a93f461cb0a3798645c/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00400630` | `_init` | [C](../../../analiz/native/system-modules/6b058edde01d3291177697454558236522583fe917d93a93f461cb0a3798645c/00400630.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
