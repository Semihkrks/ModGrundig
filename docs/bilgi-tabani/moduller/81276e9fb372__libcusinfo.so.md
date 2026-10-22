# `07_MSLIB/libcusinfo.so`

SHA-256: `81276e9fb3728c4d40111d679bf24ec8b2b851c4312c9b5896c555516e152dd4`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 7564 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 12 / 20.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 21; semboller: 125.
- Xref: 190; analizde call tipli xref: 0.
- Computed-call instruction: 29 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/81276e9fb3728c4d40111d679bf24ec8b2b851c4312c9b5896c555516e152dd4/functions.jsonl) · [Xref](../../../analiz/native/system-modules/81276e9fb3728c4d40111d679bf24ec8b2b851c4312c9b5896c555516e152dd4/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/81276e9fb3728c4d40111d679bf24ec8b2b851c4312c9b5896c555516e152dd4/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/81276e9fb3728c4d40111d679bf24ec8b2b851c4312c9b5896c555516e152dd4/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f6a07c4` | `_init` | [C](../../../analiz/native/system-modules/81276e9fb3728c4d40111d679bf24ec8b2b851c4312c9b5896c555516e152dd4/2f6a07c4.c) |
| `2f6a0b54` | `CusInfo::initCustomerInfo` | [C](../../../analiz/native/system-modules/81276e9fb3728c4d40111d679bf24ec8b2b851c4312c9b5896c555516e152dd4/2f6a0b54.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
