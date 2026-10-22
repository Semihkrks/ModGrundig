# `06_RFS/lib/libBrokenLocale-2.8.so`

SHA-256: `b477879c43fcdace9e87660f287643751453bfb684848a7744edfbc6553daec4`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 5516 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 4 / 3.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 10; semboller: 55.
- Xref: 108; analizde call tipli xref: 0.
- Computed-call instruction: 9 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/b477879c43fcdace9e87660f287643751453bfb684848a7744edfbc6553daec4/functions.jsonl) · [Xref](../../../analiz/native/system-modules/b477879c43fcdace9e87660f287643751453bfb684848a7744edfbc6553daec4/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/b477879c43fcdace9e87660f287643751453bfb684848a7744edfbc6553daec4/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/b477879c43fcdace9e87660f287643751453bfb684848a7744edfbc6553daec4/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010474` | `_DT_INIT` | [C](../../../analiz/native/system-modules/b477879c43fcdace9e87660f287643751453bfb684848a7744edfbc6553daec4/00010474.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
