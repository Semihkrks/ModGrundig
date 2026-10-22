# `07_MSLIB/utopia/libapiHSL.so`

SHA-256: `f4ba969be1c697963ba667ff76b546b45ac6142efdea08043e407438c966de3e`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 38396 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 45 / 112.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 138; semboller: 550.
- Xref: 2189; analizde call tipli xref: 0.
- Computed-call instruction: 326 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/f4ba969be1c697963ba667ff76b546b45ac6142efdea08043e407438c966de3e/functions.jsonl) · [Xref](../../../analiz/native/system-modules/f4ba969be1c697963ba667ff76b546b45ac6142efdea08043e407438c966de3e/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/f4ba969be1c697963ba667ff76b546b45ac6142efdea08043e407438c966de3e/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/f4ba969be1c697963ba667ff76b546b45ac6142efdea08043e407438c966de3e/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2ef51ec0` | `FrHslV2InitialiseGroupIdFiltering` | [C](../../../analiz/native/system-modules/f4ba969be1c697963ba667ff76b546b45ac6142efdea08043e407438c966de3e/2ef51ec0.c) |
| `2ef55e20` | `initCondition` | [C](../../../analiz/native/system-modules/f4ba969be1c697963ba667ff76b546b45ac6142efdea08043e407438c966de3e/2ef55e20.c) |
| `2ef55e58` | `deleteMutex` | [C](../../../analiz/native/system-modules/f4ba969be1c697963ba667ff76b546b45ac6142efdea08043e407438c966de3e/2ef55e58.c) |
| `2ef55e90` | `initMutex` | [C](../../../analiz/native/system-modules/f4ba969be1c697963ba667ff76b546b45ac6142efdea08043e407438c966de3e/2ef55e90.c) |
| `2ef55ec8` | `initThread` | [C](../../../analiz/native/system-modules/f4ba969be1c697963ba667ff76b546b45ac6142efdea08043e407438c966de3e/2ef55ec8.c) |
| `2ef53468` | `FrHslInitialise` | [C](../../../analiz/native/system-modules/f4ba969be1c697963ba667ff76b546b45ac6142efdea08043e407438c966de3e/2ef53468.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
