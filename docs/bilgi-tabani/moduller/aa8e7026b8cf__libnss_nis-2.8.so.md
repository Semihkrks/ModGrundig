# `06_RFS/lib/libnss_nis-2.8.so`

SHA-256: `aa8e7026b8cffa57d297d1f4dbb581452d26c668d287c0e51d5eed024179f6e0`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 44980 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libnsl.so.1`, `libnss_files.so.2`, `libc.so.6`
- Dynamic import/export: 49 / 58.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 158; semboller: 743.
- Xref: 2777; analizde call tipli xref: 0.
- Computed-call instruction: 497 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/aa8e7026b8cffa57d297d1f4dbb581452d26c668d287c0e51d5eed024179f6e0/functions.jsonl) · [Xref](../../../analiz/native/system-modules/aa8e7026b8cffa57d297d1f4dbb581452d26c668d287c0e51d5eed024179f6e0/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/aa8e7026b8cffa57d297d1f4dbb581452d26c668d287c0e51d5eed024179f6e0/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/aa8e7026b8cffa57d297d1f4dbb581452d26c668d287c0e51d5eed024179f6e0/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00011858` | `_DT_INIT` | [C](../../../analiz/native/system-modules/aa8e7026b8cffa57d297d1f4dbb581452d26c668d287c0e51d5eed024179f6e0/00011858.c) |
| `00019030` | `_nss_nis_initgroups_dyn` | [C](../../../analiz/native/system-modules/aa8e7026b8cffa57d297d1f4dbb581452d26c668d287c0e51d5eed024179f6e0/00019030.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
