# `07_MSLIB/libatclient.so`

SHA-256: `ff329df4fd238c2f871102702c3048af59ff2a0ca8dd3d4a63f6a7dc35fc8bab`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 25604 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libpthread.so.0`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 46 / 66.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 86; semboller: 480.
- Xref: 1044; analizde call tipli xref: 0.
- Computed-call instruction: 187 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/ff329df4fd238c2f871102702c3048af59ff2a0ca8dd3d4a63f6a7dc35fc8bab/functions.jsonl) · [Xref](../../../analiz/native/system-modules/ff329df4fd238c2f871102702c3048af59ff2a0ca8dd3d4a63f6a7dc35fc8bab/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/ff329df4fd238c2f871102702c3048af59ff2a0ca8dd3d4a63f6a7dc35fc8bab/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/ff329df4fd238c2f871102702c3048af59ff2a0ca8dd3d4a63f6a7dc35fc8bab/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f681c5c` | `_init` | [C](../../../analiz/native/system-modules/ff329df4fd238c2f871102702c3048af59ff2a0ca8dd3d4a63f6a7dc35fc8bab/2f681c5c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
