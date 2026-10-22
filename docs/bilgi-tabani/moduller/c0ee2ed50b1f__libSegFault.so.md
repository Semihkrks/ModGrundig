# `06_RFS/lib/libSegFault.so`

SHA-256: `c0ee2ed50b1f845b6e991e7409112866b91b3f7891e3df7e8eee00badbe04e7f`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 9756 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`, `ld.so.1`
- Dynamic import/export: 25 / 12.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 48; semboller: 155.
- Xref: 211; analizde call tipli xref: 0.
- Computed-call instruction: 65 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/c0ee2ed50b1f845b6e991e7409112866b91b3f7891e3df7e8eee00badbe04e7f/functions.jsonl) · [Xref](../../../analiz/native/system-modules/c0ee2ed50b1f845b6e991e7409112866b91b3f7891e3df7e8eee00badbe04e7f/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/c0ee2ed50b1f845b6e991e7409112866b91b3f7891e3df7e8eee00badbe04e7f/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/c0ee2ed50b1f845b6e991e7409112866b91b3f7891e3df7e8eee00badbe04e7f/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `0001094c` | `_init` | [C](../../../analiz/native/system-modules/c0ee2ed50b1f845b6e991e7409112866b91b3f7891e3df7e8eee00badbe04e7f/0001094c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
