# `07_MSLIB/libar_qrcode.so`

SHA-256: `eed6c0cf75cfcaac87985861c384b3c58c2e127804f94e0e7aaf1260429f28a8`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 72008 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 47 / 110.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 157; semboller: 1142.
- Xref: 3337; analizde call tipli xref: 0.
- Computed-call instruction: 528 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 3/3.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/eed6c0cf75cfcaac87985861c384b3c58c2e127804f94e0e7aaf1260429f28a8/functions.jsonl) · [Xref](../../../analiz/native/system-modules/eed6c0cf75cfcaac87985861c384b3c58c2e127804f94e0e7aaf1260429f28a8/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/eed6c0cf75cfcaac87985861c384b3c58c2e127804f94e0e7aaf1260429f28a8/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/eed6c0cf75cfcaac87985861c384b3c58c2e127804f94e0e7aaf1260429f28a8/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f0a2434` | `_init` | [C](../../../analiz/native/system-modules/eed6c0cf75cfcaac87985861c384b3c58c2e127804f94e0e7aaf1260429f28a8/2f0a2434.c) |
| `2f0aa3b4` | `QRinput_setVersionAndErrorCorrectionLevel` | [C](../../../analiz/native/system-modules/eed6c0cf75cfcaac87985861c384b3c58c2e127804f94e0e7aaf1260429f28a8/2f0aa3b4.c) |
| `2f0ab950` | `init_rs` | [C](../../../analiz/native/system-modules/eed6c0cf75cfcaac87985861c384b3c58c2e127804f94e0e7aaf1260429f28a8/2f0ab950.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
