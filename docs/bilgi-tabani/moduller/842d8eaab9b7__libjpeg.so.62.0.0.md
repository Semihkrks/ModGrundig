# `07_MSLIB/libjpeg.so.62.0.0`

SHA-256: `842d8eaab9b70673c9f6d95935cca41b17c07bf2c5d64da473b20215db70e710`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 230008 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 17 / 114.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 354; semboller: 2734.
- Xref: 22758; analizde call tipli xref: 0.
- Computed-call instruction: 1034 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/842d8eaab9b70673c9f6d95935cca41b17c07bf2c5d64da473b20215db70e710/functions.jsonl) · [Xref](../../../analiz/native/system-modules/842d8eaab9b70673c9f6d95935cca41b17c07bf2c5d64da473b20215db70e710/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/842d8eaab9b70673c9f6d95935cca41b17c07bf2c5d64da473b20215db70e710/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/842d8eaab9b70673c9f6d95935cca41b17c07bf2c5d64da473b20215db70e710/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2eb624c0` | `jpeg_mem_init` | [C](../../../analiz/native/system-modules/842d8eaab9b70673c9f6d95935cca41b17c07bf2c5d64da473b20215db70e710/2eb624c0.c) |
| `2eb59cec` | `FUN_2eb59cec` | [C](../../../analiz/native/system-modules/842d8eaab9b70673c9f6d95935cca41b17c07bf2c5d64da473b20215db70e710/2eb59cec.c) |
| `2eb31c74` | `_init` | [C](../../../analiz/native/system-modules/842d8eaab9b70673c9f6d95935cca41b17c07bf2c5d64da473b20215db70e710/2eb31c74.c) |
| `2eb475d8` | `jinit_master_decompress` | [C](../../../analiz/native/system-modules/842d8eaab9b70673c9f6d95935cca41b17c07bf2c5d64da473b20215db70e710/2eb475d8.c) |
| `2eb48454` | `jinit_input_controller` | [C](../../../analiz/native/system-modules/842d8eaab9b70673c9f6d95935cca41b17c07bf2c5d64da473b20215db70e710/2eb48454.c) |
| `2eb41c44` | `jinit_phuff_encoder` | [C](../../../analiz/native/system-modules/842d8eaab9b70673c9f6d95935cca41b17c07bf2c5d64da473b20215db70e710/2eb41c44.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
