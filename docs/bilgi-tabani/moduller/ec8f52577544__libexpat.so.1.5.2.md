# `06_RFS/lib/libexpat.so.1.5.2`

SHA-256: `ec8f52577544d1b7584be0ac7751fba92e609380d69bcc1bd1724217e1e4ba16`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 188128 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 11 / 91.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 222; semboller: 2112.
- Xref: 6337; analizde call tipli xref: 0.
- Computed-call instruction: 384 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/ec8f52577544d1b7584be0ac7751fba92e609380d69bcc1bd1724217e1e4ba16/functions.jsonl) · [Xref](../../../analiz/native/system-modules/ec8f52577544d1b7584be0ac7751fba92e609380d69bcc1bd1724217e1e4ba16/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/ec8f52577544d1b7584be0ac7751fba92e609380d69bcc1bd1724217e1e4ba16/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/ec8f52577544d1b7584be0ac7751fba92e609380d69bcc1bd1724217e1e4ba16/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00031040` | `XmlPrologStateInitExternalEntity` | [C](../../../analiz/native/system-modules/ec8f52577544d1b7584be0ac7751fba92e609380d69bcc1bd1724217e1e4ba16/00031040.c) |
| `00031014` | `XmlPrologStateInit` | [C](../../../analiz/native/system-modules/ec8f52577544d1b7584be0ac7751fba92e609380d69bcc1bd1724217e1e4ba16/00031014.c) |
| `0002bcd0` | `XmlInitUnknownEncodingNS` | [C](../../../analiz/native/system-modules/ec8f52577544d1b7584be0ac7751fba92e609380d69bcc1bd1724217e1e4ba16/0002bcd0.c) |
| `00012470` | `_init` | [C](../../../analiz/native/system-modules/ec8f52577544d1b7584be0ac7751fba92e609380d69bcc1bd1724217e1e4ba16/00012470.c) |
| `0002bd18` | `XmlInitEncodingNS` | [C](../../../analiz/native/system-modules/ec8f52577544d1b7584be0ac7751fba92e609380d69bcc1bd1724217e1e4ba16/0002bd18.c) |
| `0002be2c` | `XmlInitEncoding` | [C](../../../analiz/native/system-modules/ec8f52577544d1b7584be0ac7751fba92e609380d69bcc1bd1724217e1e4ba16/0002be2c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
