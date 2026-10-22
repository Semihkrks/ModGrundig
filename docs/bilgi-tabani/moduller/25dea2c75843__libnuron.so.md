# `07_MSLIB/libnuron.so`

SHA-256: `25dea2c758437c373c8167470a9d92a7874641ef3a22f0e86148e1e609486085`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 12871 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libcrypto.so.0.9.8`, `libdl.so.2`, `libc.so.6`
- Dynamic import/export: 38 / 13.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 90; semboller: 228.
- Xref: 321; analizde call tipli xref: 0.
- Computed-call instruction: 91 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/25dea2c758437c373c8167470a9d92a7874641ef3a22f0e86148e1e609486085/functions.jsonl) · [Xref](../../../analiz/native/system-modules/25dea2c758437c373c8167470a9d92a7874641ef3a22f0e86148e1e609486085/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/25dea2c758437c373c8167470a9d92a7874641ef3a22f0e86148e1e609486085/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/25dea2c758437c373c8167470a9d92a7874641ef3a22f0e86148e1e609486085/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010b9c` | `_init` | [C](../../../analiz/native/system-modules/25dea2c758437c373c8167470a9d92a7874641ef3a22f0e86148e1e609486085/00010b9c.c) |
| `00011548` | `nuron_init` | [C](../../../analiz/native/system-modules/25dea2c758437c373c8167470a9d92a7874641ef3a22f0e86148e1e609486085/00011548.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
