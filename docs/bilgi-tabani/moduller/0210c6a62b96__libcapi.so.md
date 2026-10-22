# `07_MSLIB/libcapi.so`

SHA-256: `0210c6a62b96b1a79256743637e7ccf37b8db48c68c3e14d7ae7029a14fa48c2`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 4621 bayt.

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

[Fonksiyonlar](../../../analiz/native/system-modules/0210c6a62b96b1a79256743637e7ccf37b8db48c68c3e14d7ae7029a14fa48c2/functions.jsonl) · [Xref](../../../analiz/native/system-modules/0210c6a62b96b1a79256743637e7ccf37b8db48c68c3e14d7ae7029a14fa48c2/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/0210c6a62b96b1a79256743637e7ccf37b8db48c68c3e14d7ae7029a14fa48c2/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/0210c6a62b96b1a79256743637e7ccf37b8db48c68c3e14d7ae7029a14fa48c2/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `0001049c` | `_init` | [C](../../../analiz/native/system-modules/0210c6a62b96b1a79256743637e7ccf37b8db48c68c3e14d7ae7029a14fa48c2/0001049c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
