# `07_MSLIB/libz.so.1.2.8`

SHA-256: `76610aafecc4078f6c02ed9f29648c78421171b30a4d7790e33ba2930708656a`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 95532 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 18 / 90.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 109; semboller: 1153.
- Xref: 2420; analizde call tipli xref: 0.
- Computed-call instruction: 219 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/76610aafecc4078f6c02ed9f29648c78421171b30a4d7790e33ba2930708656a/functions.jsonl) · [Xref](../../../analiz/native/system-modules/76610aafecc4078f6c02ed9f29648c78421171b30a4d7790e33ba2930708656a/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/76610aafecc4078f6c02ed9f29648c78421171b30a4d7790e33ba2930708656a/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/76610aafecc4078f6c02ed9f29648c78421171b30a4d7790e33ba2930708656a/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f258288` | `inflateInit_` | [C](../../../analiz/native/system-modules/76610aafecc4078f6c02ed9f29648c78421171b30a4d7790e33ba2930708656a/2f258288.c) |
| `2f253bd8` | `deflateInit_` | [C](../../../analiz/native/system-modules/76610aafecc4078f6c02ed9f29648c78421171b30a4d7790e33ba2930708656a/2f253bd8.c) |
| `2f2514fc` | `_DT_INIT` | [C](../../../analiz/native/system-modules/76610aafecc4078f6c02ed9f29648c78421171b30a4d7790e33ba2930708656a/2f2514fc.c) |
| `2f258184` | `inflateInit2_` | [C](../../../analiz/native/system-modules/76610aafecc4078f6c02ed9f29648c78421171b30a4d7790e33ba2930708656a/2f258184.c) |
| `2f256600` | `inflateBackInit_` | [C](../../../analiz/native/system-modules/76610aafecc4078f6c02ed9f29648c78421171b30a4d7790e33ba2930708656a/2f256600.c) |
| `2f2538b0` | `deflateInit2_` | [C](../../../analiz/native/system-modules/76610aafecc4078f6c02ed9f29648c78421171b30a4d7790e33ba2930708656a/2f2538b0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
