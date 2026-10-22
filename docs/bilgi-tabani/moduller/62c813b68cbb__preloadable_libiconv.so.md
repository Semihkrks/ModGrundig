# `07_MSLIB/preloadable_libiconv.so`

SHA-256: `62c813b68cbbe2168890a8638647a271144847f0cb6387e1355e8c388a05ac9f`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 1016804 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 26 / 15.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 346; semboller: 3163.
- Xref: 20062; analizde call tipli xref: 0.
- Computed-call instruction: 408 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/62c813b68cbbe2168890a8638647a271144847f0cb6387e1355e8c388a05ac9f/functions.jsonl) · [Xref](../../../analiz/native/system-modules/62c813b68cbbe2168890a8638647a271144847f0cb6387e1355e8c388a05ac9f/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/62c813b68cbbe2168890a8638647a271144847f0cb6387e1355e8c388a05ac9f/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/62c813b68cbbe2168890a8638647a271144847f0cb6387e1355e8c388a05ac9f/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010f74` | `_init` | [C](../../../analiz/native/system-modules/62c813b68cbbe2168890a8638647a271144847f0cb6387e1355e8c388a05ac9f/00010f74.c) |
| `0002dcec` | `FUN_0002dcec` | [C](../../../analiz/native/system-modules/62c813b68cbbe2168890a8638647a271144847f0cb6387e1355e8c388a05ac9f/0002dcec.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
