# `06_RFS/lib/libcidn-2.8.so`

SHA-256: `4c4c7a4170bd6c4dcf19903c03dc5984733ad3ca8b875cf67c2c3f86453e8791`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 187164 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 20 / 4.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 55; semboller: 332.
- Xref: 726; analizde call tipli xref: 0.
- Computed-call instruction: 140 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/4c4c7a4170bd6c4dcf19903c03dc5984733ad3ca8b875cf67c2c3f86453e8791/functions.jsonl) · [Xref](../../../analiz/native/system-modules/4c4c7a4170bd6c4dcf19903c03dc5984733ad3ca8b875cf67c2c3f86453e8791/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/4c4c7a4170bd6c4dcf19903c03dc5984733ad3ca8b875cf67c2c3f86453e8791/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/4c4c7a4170bd6c4dcf19903c03dc5984733ad3ca8b875cf67c2c3f86453e8791/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010b4c` | `_DT_INIT` | [C](../../../analiz/native/system-modules/4c4c7a4170bd6c4dcf19903c03dc5984733ad3ca8b875cf67c2c3f86453e8791/00010b4c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
