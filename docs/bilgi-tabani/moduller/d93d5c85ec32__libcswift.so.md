# `07_MSLIB/libcswift.so`

SHA-256: `d93d5c85ec32e4fe4d95376d9d00fb762fe0948550723f09ad6283c952d5cc71`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 21937 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libcrypto.so.0.9.8`, `libdl.so.2`, `libc.so.6`
- Dynamic import/export: 52 / 17.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 121; semboller: 391.
- Xref: 918; analizde call tipli xref: 0.
- Computed-call instruction: 256 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 3/3.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/d93d5c85ec32e4fe4d95376d9d00fb762fe0948550723f09ad6283c952d5cc71/functions.jsonl) · [Xref](../../../analiz/native/system-modules/d93d5c85ec32e4fe4d95376d9d00fb762fe0948550723f09ad6283c952d5cc71/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/d93d5c85ec32e4fe4d95376d9d00fb762fe0948550723f09ad6283c952d5cc71/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/d93d5c85ec32e4fe4d95376d9d00fb762fe0948550723f09ad6283c952d5cc71/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010f18` | `_init` | [C](../../../analiz/native/system-modules/d93d5c85ec32e4fe4d95376d9d00fb762fe0948550723f09ad6283c952d5cc71/00010f18.c) |
| `0001316c` | `cswift_init` | [C](../../../analiz/native/system-modules/d93d5c85ec32e4fe4d95376d9d00fb762fe0948550723f09ad6283c952d5cc71/0001316c.c) |
| `00011ad8` | `cswift_dsa_verify` | [C](../../../analiz/native/system-modules/d93d5c85ec32e4fe4d95376d9d00fb762fe0948550723f09ad6283c952d5cc71/00011ad8.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
