# `08_APP/MLog/MLogcat`

SHA-256: `b8a548a2eb1de8b159dd4fc3289d41376faee02abeb01cf060acaad790170852`

Durum: **Ghidra indeks tamam**.

Tür: EXEC (Executable file); ELF32 LE MIPS; 52216 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 46 / 15.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 109; semboller: 452.
- Xref: 811; analizde call tipli xref: 4.
- Computed-call instruction: 171 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/b8a548a2eb1de8b159dd4fc3289d41376faee02abeb01cf060acaad790170852/functions.jsonl) · [Xref](../../../analiz/native/system-modules/b8a548a2eb1de8b159dd4fc3289d41376faee02abeb01cf060acaad790170852/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/b8a548a2eb1de8b159dd4fc3289d41376faee02abeb01cf060acaad790170852/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/b8a548a2eb1de8b159dd4fc3289d41376faee02abeb01cf060acaad790170852/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00400c5c` | `_init` | [C](../../../analiz/native/system-modules/b8a548a2eb1de8b159dd4fc3289d41376faee02abeb01cf060acaad790170852/00400c5c.c) |
| `00403238` | `__libc_csu_init` | [C](../../../analiz/native/system-modules/b8a548a2eb1de8b159dd4fc3289d41376faee02abeb01cf060acaad790170852/00403238.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
