# `06_RFS/lib/libanl.so.1`

SHA-256: `21db91a4d347ed6ed8c4e61aac3a217e5ca72e8b42044c162909e4f088f3d2d8`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 14420 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`, `libpthread.so.0`
- Dynamic import/export: 26 / 6.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 58; semboller: 244.
- Xref: 377; analizde call tipli xref: 0.
- Computed-call instruction: 92 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/21db91a4d347ed6ed8c4e61aac3a217e5ca72e8b42044c162909e4f088f3d2d8/functions.jsonl) · [Xref](../../../analiz/native/system-modules/21db91a4d347ed6ed8c4e61aac3a217e5ca72e8b42044c162909e4f088f3d2d8/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/21db91a4d347ed6ed8c4e61aac3a217e5ca72e8b42044c162909e4f088f3d2d8/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/21db91a4d347ed6ed8c4e61aac3a217e5ca72e8b42044c162909e4f088f3d2d8/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010974` | `_DT_INIT` | [C](../../../analiz/native/system-modules/21db91a4d347ed6ed8c4e61aac3a217e5ca72e8b42044c162909e4f088f3d2d8/00010974.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
