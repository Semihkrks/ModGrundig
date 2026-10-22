# `07_MSLIB/libSema.so`

SHA-256: `17cd307d7a35c1f13ca1f443d5a65b058ddddc0f92b809be6030112f8b6b2c87`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 8364 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 14 / 21.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 28; semboller: 132.
- Xref: 376; analizde call tipli xref: 0.
- Computed-call instruction: 50 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/17cd307d7a35c1f13ca1f443d5a65b058ddddc0f92b809be6030112f8b6b2c87/functions.jsonl) · [Xref](../../../analiz/native/system-modules/17cd307d7a35c1f13ca1f443d5a65b058ddddc0f92b809be6030112f8b6b2c87/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/17cd307d7a35c1f13ca1f443d5a65b058ddddc0f92b809be6030112f8b6b2c87/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/17cd307d7a35c1f13ca1f443d5a65b058ddddc0f92b809be6030112f8b6b2c87/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f280738` | `_init` | [C](../../../analiz/native/system-modules/17cd307d7a35c1f13ca1f443d5a65b058ddddc0f92b809be6030112f8b6b2c87/2f280738.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
