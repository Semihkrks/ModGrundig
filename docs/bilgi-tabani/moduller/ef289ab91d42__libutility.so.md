# `07_MSLIB/libutility.so`

SHA-256: `ef289ab91d42b60d72fbca21b5be0e4e98bd10d149fd9e2664ff728da822cb36`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 11128 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 8 / 33.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 41; semboller: 180.
- Xref: 732; analizde call tipli xref: 0.
- Computed-call instruction: 58 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 5/5.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/ef289ab91d42b60d72fbca21b5be0e4e98bd10d149fd9e2664ff728da822cb36/functions.jsonl) · [Xref](../../../analiz/native/system-modules/ef289ab91d42b60d72fbca21b5be0e4e98bd10d149fd9e2664ff728da822cb36/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/ef289ab91d42b60d72fbca21b5be0e4e98bd10d149fd9e2664ff728da822cb36/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/ef289ab91d42b60d72fbca21b5be0e4e98bd10d149fd9e2664ff728da822cb36/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00011b68` | `TEE_InitRingBuffer` | [C](../../../analiz/native/system-modules/ef289ab91d42b60d72fbca21b5be0e4e98bd10d149fd9e2664ff728da822cb36/00011b68.c) |
| `000113d4` | `InitBP_Send` | [C](../../../analiz/native/system-modules/ef289ab91d42b60d72fbca21b5be0e4e98bd10d149fd9e2664ff728da822cb36/000113d4.c) |
| `00010850` | `_init` | [C](../../../analiz/native/system-modules/ef289ab91d42b60d72fbca21b5be0e4e98bd10d149fd9e2664ff728da822cb36/00010850.c) |
| `00011450` | `InitBP_Recieve` | [C](../../../analiz/native/system-modules/ef289ab91d42b60d72fbca21b5be0e4e98bd10d149fd9e2664ff728da822cb36/00011450.c) |
| `00011e14` | `TEE_UpdateWriteAddress` | [C](../../../analiz/native/system-modules/ef289ab91d42b60d72fbca21b5be0e4e98bd10d149fd9e2664ff728da822cb36/00011e14.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
