# `07_MSLIB/libcharset.so.1.0.0`

SHA-256: `c57c9e5a2acf36e5136718a5355d03e9f420eadfa12cb6133bc623f2f6dd16b4`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 9332 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 19 / 13.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 47; semboller: 179.
- Xref: 618; analizde call tipli xref: 0.
- Computed-call instruction: 90 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/c57c9e5a2acf36e5136718a5355d03e9f420eadfa12cb6133bc623f2f6dd16b4/functions.jsonl) · [Xref](../../../analiz/native/system-modules/c57c9e5a2acf36e5136718a5355d03e9f420eadfa12cb6133bc623f2f6dd16b4/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/c57c9e5a2acf36e5136718a5355d03e9f420eadfa12cb6133bc623f2f6dd16b4/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/c57c9e5a2acf36e5136718a5355d03e9f420eadfa12cb6133bc623f2f6dd16b4/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `000106b0` | `_init` | [C](../../../analiz/native/system-modules/c57c9e5a2acf36e5136718a5355d03e9f420eadfa12cb6133bc623f2f6dd16b4/000106b0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
