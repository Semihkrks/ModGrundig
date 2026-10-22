# `06_RFS/lib/libmemusage.so`

SHA-256: `167bb3bf732665d3ceac9e5708e237ab534271172bb941834250b0fd76841c95`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 18388 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libdl.so.2`, `ld.so.1`, `libc.so.6`
- Dynamic import/export: 26 / 20.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 55; semboller: 372.
- Xref: 572; analizde call tipli xref: 0.
- Computed-call instruction: 57 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/167bb3bf732665d3ceac9e5708e237ab534271172bb941834250b0fd76841c95/functions.jsonl) · [Xref](../../../analiz/native/system-modules/167bb3bf732665d3ceac9e5708e237ab534271172bb941834250b0fd76841c95/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/167bb3bf732665d3ceac9e5708e237ab534271172bb941834250b0fd76841c95/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/167bb3bf732665d3ceac9e5708e237ab534271172bb941834250b0fd76841c95/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010ad0` | `_init` | [C](../../../analiz/native/system-modules/167bb3bf732665d3ceac9e5708e237ab534271172bb941834250b0fd76841c95/00010ad0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
