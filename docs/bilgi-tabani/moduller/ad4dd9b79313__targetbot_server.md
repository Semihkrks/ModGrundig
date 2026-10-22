# `06_RFS/bin/targetbot_server`

SHA-256: `ad4dd9b793131583e8fb608361f673b8eb05640df20d45252071ac6a686c058b`

Durum: **Ghidra indeks tamam**.

Tür: EXEC (Executable file); ELF32 LE MIPS; 18364 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 37 / 6.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 48; semboller: 204.
- Xref: 339; analizde call tipli xref: 10.
- Computed-call instruction: 159 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/ad4dd9b793131583e8fb608361f673b8eb05640df20d45252071ac6a686c058b/functions.jsonl) · [Xref](../../../analiz/native/system-modules/ad4dd9b793131583e8fb608361f673b8eb05640df20d45252071ac6a686c058b/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/ad4dd9b793131583e8fb608361f673b8eb05640df20d45252071ac6a686c058b/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/ad4dd9b793131583e8fb608361f673b8eb05640df20d45252071ac6a686c058b/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `004009ec` | `_init` | [C](../../../analiz/native/system-modules/ad4dd9b793131583e8fb608361f673b8eb05640df20d45252071ac6a686c058b/004009ec.c) |
| `00401eb8` | `__libc_csu_init` | [C](../../../analiz/native/system-modules/ad4dd9b793131583e8fb608361f673b8eb05640df20d45252071ac6a686c058b/00401eb8.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
