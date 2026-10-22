# `09_CONFIG/rmmod`

SHA-256: `2b9fdbebb62fdc34e08cc7a705ab20df41dabe6e2ec5177fcdefdf875e669f3e`

Durum: **Ghidra indeks tamam**.

Tür: EXEC (Executable file); ELF32 LE MIPS; 12183 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 8 / 5.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 27; semboller: 129.
- Xref: 194; analizde call tipli xref: 21.
- Computed-call instruction: 13 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/2b9fdbebb62fdc34e08cc7a705ab20df41dabe6e2ec5177fcdefdf875e669f3e/functions.jsonl) · [Xref](../../../analiz/native/system-modules/2b9fdbebb62fdc34e08cc7a705ab20df41dabe6e2ec5177fcdefdf875e669f3e/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/2b9fdbebb62fdc34e08cc7a705ab20df41dabe6e2ec5177fcdefdf875e669f3e/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/2b9fdbebb62fdc34e08cc7a705ab20df41dabe6e2ec5177fcdefdf875e669f3e/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `004004e8` | `_init` | [C](../../../analiz/native/system-modules/2b9fdbebb62fdc34e08cc7a705ab20df41dabe6e2ec5177fcdefdf875e669f3e/004004e8.c) |
| `00400870` | `__libc_csu_init` | [C](../../../analiz/native/system-modules/2b9fdbebb62fdc34e08cc7a705ab20df41dabe6e2ec5177fcdefdf875e669f3e/00400870.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
