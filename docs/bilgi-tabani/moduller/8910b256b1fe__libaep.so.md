# `07_MSLIB/libaep.so`

SHA-256: `8910b256b1fe619656976ed8210e54ec765be5ef2af9448b0e6609c5c5936ec6`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 19541 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libcrypto.so.0.9.8`, `libdl.so.2`, `libc.so.6`
- Dynamic import/export: 44 / 13.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 108; semboller: 340.
- Xref: 639; analizde call tipli xref: 0.
- Computed-call instruction: 147 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/8910b256b1fe619656976ed8210e54ec765be5ef2af9448b0e6609c5c5936ec6/functions.jsonl) · [Xref](../../../analiz/native/system-modules/8910b256b1fe619656976ed8210e54ec765be5ef2af9448b0e6609c5c5936ec6/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/8910b256b1fe619656976ed8210e54ec765be5ef2af9448b0e6609c5c5936ec6/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/8910b256b1fe619656976ed8210e54ec765be5ef2af9448b0e6609c5c5936ec6/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010d0c` | `_init` | [C](../../../analiz/native/system-modules/8910b256b1fe619656976ed8210e54ec765be5ef2af9448b0e6609c5c5936ec6/00010d0c.c) |
| `000128a8` | `aep_init` | [C](../../../analiz/native/system-modules/8910b256b1fe619656976ed8210e54ec765be5ef2af9448b0e6609c5c5936ec6/000128a8.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
