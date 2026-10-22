# `06_RFS/bin/busybox`

SHA-256: `8cff67625e6003a82128cecf17749a792309395c4e05b90625107318bcb3aae2`

Durum: **Ghidra indeks tamam**.

Tür: EXEC (Executable file); ELF32 LE MIPS; 914036 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libcrypt.so.1`, `libm.so.6`, `libc.so.6`
- Dynamic import/export: 377 / 11.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 2159; semboller: 19713.
- Xref: 54037; analizde call tipli xref: 4149.
- Computed-call instruction: 9845 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 3/3.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/8cff67625e6003a82128cecf17749a792309395c4e05b90625107318bcb3aae2/functions.jsonl) · [Xref](../../../analiz/native/system-modules/8cff67625e6003a82128cecf17749a792309395c4e05b90625107318bcb3aae2/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/8cff67625e6003a82128cecf17749a792309395c4e05b90625107318bcb3aae2/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/8cff67625e6003a82128cecf17749a792309395c4e05b90625107318bcb3aae2/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00404234` | `_init` | [C](../../../analiz/native/system-modules/8cff67625e6003a82128cecf17749a792309395c4e05b90625107318bcb3aae2/00404234.c) |
| `0047dcec` | `FUN_0047dcec` | [C](../../../analiz/native/system-modules/8cff67625e6003a82128cecf17749a792309395c4e05b90625107318bcb3aae2/0047dcec.c) |
| `0040fcec` | `FUN_0040fcec` | [C](../../../analiz/native/system-modules/8cff67625e6003a82128cecf17749a792309395c4e05b90625107318bcb3aae2/0040fcec.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
