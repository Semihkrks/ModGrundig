# `06_RFS/lib/libnss_nisplus-2.8.so`

SHA-256: `ee7275f8085ff98b63702c03b17d946db99e0c77b6ca819c9246e9c8d7a3baaf`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 57548 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libnsl.so.1`, `libc.so.6`
- Dynamic import/export: 49 / 57.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 158; semboller: 819.
- Xref: 2940; analizde call tipli xref: 0.
- Computed-call instruction: 590 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/ee7275f8085ff98b63702c03b17d946db99e0c77b6ca819c9246e9c8d7a3baaf/functions.jsonl) · [Xref](../../../analiz/native/system-modules/ee7275f8085ff98b63702c03b17d946db99e0c77b6ca819c9246e9c8d7a3baaf/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/ee7275f8085ff98b63702c03b17d946db99e0c77b6ca819c9246e9c8d7a3baaf/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/ee7275f8085ff98b63702c03b17d946db99e0c77b6ca819c9246e9c8d7a3baaf/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00011848` | `_DT_INIT` | [C](../../../analiz/native/system-modules/ee7275f8085ff98b63702c03b17d946db99e0c77b6ca819c9246e9c8d7a3baaf/00011848.c) |
| `0001b610` | `_nss_nisplus_initgroups_dyn` | [C](../../../analiz/native/system-modules/ee7275f8085ff98b63702c03b17d946db99e0c77b6ca819c9246e9c8d7a3baaf/0001b610.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
