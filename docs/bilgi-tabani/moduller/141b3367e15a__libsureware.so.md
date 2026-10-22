# `07_MSLIB/libsureware.so`

SHA-256: `141b3367e15afd3097051ae068d39602b602dae1354e5d905b93ff85009d21dd`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 29392 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libcrypto.so.0.9.8`, `libdl.so.2`, `libc.so.6`
- Dynamic import/export: 68 / 13.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 159; semboller: 482.
- Xref: 1135; analizde call tipli xref: 0.
- Computed-call instruction: 236 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/141b3367e15afd3097051ae068d39602b602dae1354e5d905b93ff85009d21dd/functions.jsonl) · [Xref](../../../analiz/native/system-modules/141b3367e15afd3097051ae068d39602b602dae1354e5d905b93ff85009d21dd/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/141b3367e15afd3097051ae068d39602b602dae1354e5d905b93ff85009d21dd/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/141b3367e15afd3097051ae068d39602b602dae1354e5d905b93ff85009d21dd/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00011160` | `_init` | [C](../../../analiz/native/system-modules/141b3367e15afd3097051ae068d39602b602dae1354e5d905b93ff85009d21dd/00011160.c) |
| `00013bc4` | `surewarehk_init` | [C](../../../analiz/native/system-modules/141b3367e15afd3097051ae068d39602b602dae1354e5d905b93ff85009d21dd/00013bc4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
