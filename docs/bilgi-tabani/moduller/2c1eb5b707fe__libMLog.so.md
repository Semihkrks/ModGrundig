# `07_MSLIB/libMLog.so`

SHA-256: `2c1eb5b707febd0413be70f84607f658de46ea0dbb26e085a6ac0da731be5770`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 19816 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libstdc++.so.6`, `libc.so.6`
- Dynamic import/export: 50 / 41.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 81; semboller: 411.
- Xref: 893; analizde call tipli xref: 0.
- Computed-call instruction: 178 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 3/3.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/2c1eb5b707febd0413be70f84607f658de46ea0dbb26e085a6ac0da731be5770/functions.jsonl) · [Xref](../../../analiz/native/system-modules/2c1eb5b707febd0413be70f84607f658de46ea0dbb26e085a6ac0da731be5770/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/2c1eb5b707febd0413be70f84607f658de46ea0dbb26e085a6ac0da731be5770/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/2c1eb5b707febd0413be70f84607f658de46ea0dbb26e085a6ac0da731be5770/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f5e12a8` | `_init` | [C](../../../analiz/native/system-modules/2c1eb5b707febd0413be70f84607f658de46ea0dbb26e085a6ac0da731be5770/2f5e12a8.c) |
| `2f5e2c44` | `mlog_write_to_init` | [C](../../../analiz/native/system-modules/2c1eb5b707febd0413be70f84607f658de46ea0dbb26e085a6ac0da731be5770/2f5e2c44.c) |
| `2f5e2a4c` | `__write_to_log_initialize` | [C](../../../analiz/native/system-modules/2c1eb5b707febd0413be70f84607f658de46ea0dbb26e085a6ac0da731be5770/2f5e2a4c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
