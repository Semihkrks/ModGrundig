# `06_RFS/lib/libnsl-2.8.so`

SHA-256: `889fbef7418990e0b148c04369ca87c450623944f7efae14cda5c003226a0a45`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 93916 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 114 / 132.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 364; semboller: 1381.
- Xref: 4837; analizde call tipli xref: 0.
- Computed-call instruction: 1019 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 4/4.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/889fbef7418990e0b148c04369ca87c450623944f7efae14cda5c003226a0a45/functions.jsonl) · [Xref](../../../analiz/native/system-modules/889fbef7418990e0b148c04369ca87c450623944f7efae14cda5c003226a0a45/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/889fbef7418990e0b148c04369ca87c450623944f7efae14cda5c003226a0a45/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/889fbef7418990e0b148c04369ca87c450623944f7efae14cda5c003226a0a45/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00012ca8` | `_DT_INIT` | [C](../../../analiz/native/system-modules/889fbef7418990e0b148c04369ca87c450623944f7efae14cda5c003226a0a45/00012ca8.c) |
| `00015958` | `xdr_ypupdate_args` | [C](../../../analiz/native/system-modules/889fbef7418990e0b148c04369ca87c450623944f7efae14cda5c003226a0a45/00015958.c) |
| `0001d7b0` | `nis_verifygroup` | [C](../../../analiz/native/system-modules/889fbef7418990e0b148c04369ca87c450623944f7efae14cda5c003226a0a45/0001d7b0.c) |
| `00014e78` | `yp_update` | [C](../../../analiz/native/system-modules/889fbef7418990e0b148c04369ca87c450623944f7efae14cda5c003226a0a45/00014e78.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
