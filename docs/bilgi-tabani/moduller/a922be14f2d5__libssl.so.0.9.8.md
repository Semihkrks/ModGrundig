# `07_MSLIB/libssl.so.0.9.8`

SHA-256: `a922be14f2d5c0c28ab95d7bc7a287798d524075309233a058b3b033a4f873d4`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 375683 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libcrypto.so.0.9.8`, `libdl.so.2`, `libc.so.6`
- Dynamic import/export: 308 / 483.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 835; semboller: 5934.
- Xref: 17936; analizde call tipli xref: 0.
- Computed-call instruction: 3838 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/a922be14f2d5c0c28ab95d7bc7a287798d524075309233a058b3b033a4f873d4/functions.jsonl) · [Xref](../../../analiz/native/system-modules/a922be14f2d5c0c28ab95d7bc7a287798d524075309233a058b3b033a4f873d4/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/a922be14f2d5c0c28ab95d7bc7a287798d524075309233a058b3b033a4f873d4/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/a922be14f2d5c0c28ab95d7bc7a287798d524075309233a058b3b033a4f873d4/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2e9e2d3c` | `SSL_CTX_set_cert_verify_callback` | [C](../../../analiz/native/system-modules/a922be14f2d5c0c28ab95d7bc7a287798d524075309233a058b3b033a4f873d4/2e9e2d3c.c) |
| `2e9e2d48` | `SSL_CTX_set_verify` | [C](../../../analiz/native/system-modules/a922be14f2d5c0c28ab95d7bc7a287798d524075309233a058b3b033a4f873d4/2e9e2d48.c) |
| `2e9e2970` | `SSL_set_verify` | [C](../../../analiz/native/system-modules/a922be14f2d5c0c28ab95d7bc7a287798d524075309233a058b3b033a4f873d4/2e9e2970.c) |
| `2e9e31d8` | `SSL_CTX_load_verify_locations` | [C](../../../analiz/native/system-modules/a922be14f2d5c0c28ab95d7bc7a287798d524075309233a058b3b033a4f873d4/2e9e31d8.c) |
| `2e9e31f0` | `SSL_CTX_set_default_verify_paths` | [C](../../../analiz/native/system-modules/a922be14f2d5c0c28ab95d7bc7a287798d524075309233a058b3b033a4f873d4/2e9e31f0.c) |
| `2e9e47d0` | `SSL_CTX_set_verify_depth` | [C](../../../analiz/native/system-modules/a922be14f2d5c0c28ab95d7bc7a287798d524075309233a058b3b033a4f873d4/2e9e47d0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
