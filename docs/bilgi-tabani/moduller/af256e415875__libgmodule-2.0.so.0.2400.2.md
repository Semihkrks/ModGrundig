# `07_MSLIB/libgmodule-2.0.so.0.2400.2`

SHA-256: `af256e415875244829acf9ace53e6c21b348082f56ecd890c5506bc289354f92`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 11548 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libdl.so.2`, `libglib-2.0.so.0`, `libc.so.6`
- Dynamic import/export: 35 / 19.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 79; semboller: 239.
- Xref: 494; analizde call tipli xref: 0.
- Computed-call instruction: 175 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/af256e415875244829acf9ace53e6c21b348082f56ecd890c5506bc289354f92/functions.jsonl) · [Xref](../../../analiz/native/system-modules/af256e415875244829acf9ace53e6c21b348082f56ecd890c5506bc289354f92/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/af256e415875244829acf9ace53e6c21b348082f56ecd890c5506bc289354f92/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/af256e415875244829acf9ace53e6c21b348082f56ecd890c5506bc289354f92/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010b00` | `_init` | [C](../../../analiz/native/system-modules/af256e415875244829acf9ace53e6c21b348082f56ecd890c5506bc289354f92/00010b00.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
