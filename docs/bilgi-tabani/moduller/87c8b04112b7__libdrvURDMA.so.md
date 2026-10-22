# `07_MSLIB/utopia/libdrvURDMA.so`

SHA-256: `87c8b04112b7aa61df59dc0b1e0e788b0e2d0766ddd77a08e8403e00517c532f`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 6656 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 8 / 20.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 26; semboller: 109.
- Xref: 217; analizde call tipli xref: 0.
- Computed-call instruction: 30 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 4/4.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/87c8b04112b7aa61df59dc0b1e0e788b0e2d0766ddd77a08e8403e00517c532f/functions.jsonl) · [Xref](../../../analiz/native/system-modules/87c8b04112b7aa61df59dc0b1e0e788b0e2d0766ddd77a08e8403e00517c532f/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/87c8b04112b7aa61df59dc0b1e0e788b0e2d0766ddd77a08e8403e00517c532f/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/87c8b04112b7aa61df59dc0b1e0e788b0e2d0766ddd77a08e8403e00517c532f/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010690` | `_init` | [C](../../../analiz/native/system-modules/87c8b04112b7aa61df59dc0b1e0e788b0e2d0766ddd77a08e8403e00517c532f/00010690.c) |
| `00010d08` | `MDrv_UrDMA_RxInit` | [C](../../../analiz/native/system-modules/87c8b04112b7aa61df59dc0b1e0e788b0e2d0766ddd77a08e8403e00517c532f/00010d08.c) |
| `00010ee0` | `MDrv_UrDMA_TxInit` | [C](../../../analiz/native/system-modules/87c8b04112b7aa61df59dc0b1e0e788b0e2d0766ddd77a08e8403e00517c532f/00010ee0.c) |
| `00010ad4` | `MDrv_UrDMA_Init` | [C](../../../analiz/native/system-modules/87c8b04112b7aa61df59dc0b1e0e788b0e2d0766ddd77a08e8403e00517c532f/00010ad4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
