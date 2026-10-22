# `07_MSLIB/utopia/libapihook.so`

SHA-256: `7ae95d8cb6d69a0ddb74045350d833031cce9c5179bbee418d8db3a1dcf7cedb`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 5728 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libpthread.so.0`, `libdl.so.2`, `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 8 / 12.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 14; semboller: 84.
- Xref: 126; analizde call tipli xref: 0.
- Computed-call instruction: 13 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/7ae95d8cb6d69a0ddb74045350d833031cce9c5179bbee418d8db3a1dcf7cedb/functions.jsonl) · [Xref](../../../analiz/native/system-modules/7ae95d8cb6d69a0ddb74045350d833031cce9c5179bbee418d8db3a1dcf7cedb/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/7ae95d8cb6d69a0ddb74045350d833031cce9c5179bbee418d8db3a1dcf7cedb/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/7ae95d8cb6d69a0ddb74045350d833031cce9c5179bbee418d8db3a1dcf7cedb/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f340644` | `_init` | [C](../../../analiz/native/system-modules/7ae95d8cb6d69a0ddb74045350d833031cce9c5179bbee418d8db3a1dcf7cedb/2f340644.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
