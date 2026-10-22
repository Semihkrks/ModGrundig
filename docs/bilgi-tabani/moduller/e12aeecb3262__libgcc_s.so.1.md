# `06_RFS/lib/libgcc_s.so.1`

SHA-256: `e12aeecb32628a1e5e11b51fc03945c91d5b9a573114425208dafad070d50f29`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 203308 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 19 / 1106.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 1163; semboller: 3329.
- Xref: 5269; analizde call tipli xref: 0.
- Computed-call instruction: 386 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/e12aeecb32628a1e5e11b51fc03945c91d5b9a573114425208dafad070d50f29/functions.jsonl) · [Xref](../../../analiz/native/system-modules/e12aeecb32628a1e5e11b51fc03945c91d5b9a573114425208dafad070d50f29/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/e12aeecb32628a1e5e11b51fc03945c91d5b9a573114425208dafad070d50f29/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/e12aeecb32628a1e5e11b51fc03945c91d5b9a573114425208dafad070d50f29/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2c83b330` | `_DT_INIT` | [C](../../../analiz/native/system-modules/e12aeecb32628a1e5e11b51fc03945c91d5b9a573114425208dafad070d50f29/2c83b330.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
