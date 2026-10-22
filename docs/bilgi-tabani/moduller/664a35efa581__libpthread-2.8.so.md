# `06_RFS/lib/libpthread-2.8.so`

SHA-256: `664a35efa58130b22e17989c418c64ba27ea359ace6f22ada682f03ea421db23`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 148544 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`, `ld.so.1`
- Dynamic import/export: 72 / 249.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 355; semboller: 2902.
- Xref: 5027; analizde call tipli xref: 0.
- Computed-call instruction: 419 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/664a35efa58130b22e17989c418c64ba27ea359ace6f22ada682f03ea421db23/functions.jsonl) · [Xref](../../../analiz/native/system-modules/664a35efa58130b22e17989c418c64ba27ea359ace6f22ada682f03ea421db23/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/664a35efa58130b22e17989c418c64ba27ea359ace6f22ada682f03ea421db23/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/664a35efa58130b22e17989c418c64ba27ea359ace6f22ada682f03ea421db23/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2c87a720` | `pthread_mutexattr_init` | [C](../../../analiz/native/system-modules/664a35efa58130b22e17989c418c64ba27ea359ace6f22ada682f03ea421db23/2c87a720.c) |
| `2c87cef0` | `pthread_condattr_init` | [C](../../../analiz/native/system-modules/664a35efa58130b22e17989c418c64ba27ea359ace6f22ada682f03ea421db23/2c87cef0.c) |
| `2c87cfd0` | `pthread_spin_init` | [C](../../../analiz/native/system-modules/664a35efa58130b22e17989c418c64ba27ea359ace6f22ada682f03ea421db23/2c87cfd0.c) |
| `2c87d3f0` | `pthread_barrierattr_init` | [C](../../../analiz/native/system-modules/664a35efa58130b22e17989c418c64ba27ea359ace6f22ada682f03ea421db23/2c87d3f0.c) |
| `2c87b7b0` | `pthread_rwlockattr_init` | [C](../../../analiz/native/system-modules/664a35efa58130b22e17989c418c64ba27ea359ace6f22ada682f03ea421db23/2c87b7b0.c) |
| `2c87a740` | `pthread_mutexattr_getpshared` | [C](../../../analiz/native/system-modules/664a35efa58130b22e17989c418c64ba27ea359ace6f22ada682f03ea421db23/2c87a740.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
