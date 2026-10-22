# `07_MSLIB/libgmp.so`

SHA-256: `44be03b2af2063f01f49f0a026d67fcb1ea8b45ad83fd02c8e639c9439653bee`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 4620 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libcrypto.so.0.9.8`, `libdl.so.2`, `libc.so.6`
- Dynamic import/export: 3 / 13.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 9; semboller: 66.
- Xref: 91; analizde call tipli xref: 0.
- Computed-call instruction: 7 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/44be03b2af2063f01f49f0a026d67fcb1ea8b45ad83fd02c8e639c9439653bee/functions.jsonl) · [Xref](../../../analiz/native/system-modules/44be03b2af2063f01f49f0a026d67fcb1ea8b45ad83fd02c8e639c9439653bee/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/44be03b2af2063f01f49f0a026d67fcb1ea8b45ad83fd02c8e639c9439653bee/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/44be03b2af2063f01f49f0a026d67fcb1ea8b45ad83fd02c8e639c9439653bee/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `0001049c` | `_init` | [C](../../../analiz/native/system-modules/44be03b2af2063f01f49f0a026d67fcb1ea8b45ad83fd02c8e639c9439653bee/0001049c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
