# `07_MSLIB/libxml2.so.2.7.7`

SHA-256: `13c39733bf7d7d34ee29e109765bf59d1b5653b995f672faefb10f748f6fa381`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 2261644 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["xmlNormalizeWindowsPath@@LIBXML2_2.4.30", "xmlUCSIsBoxDrawing@@LIBXML2_2.4.30"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libdl.so.2`, `libm.so.6`, `libc.so.6`
- Dynamic import/export: 88 / 1751.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 3035; semboller: 28989.
- Xref: 189895; analizde call tipli xref: 0.
- Computed-call instruction: 17866 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/13c39733bf7d7d34ee29e109765bf59d1b5653b995f672faefb10f748f6fa381/functions.jsonl) · [Xref](../../../analiz/native/system-modules/13c39733bf7d7d34ee29e109765bf59d1b5653b995f672faefb10f748f6fa381/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/13c39733bf7d7d34ee29e109765bf59d1b5653b995f672faefb10f748f6fa381/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/13c39733bf7d7d34ee29e109765bf59d1b5653b995f672faefb10f748f6fa381/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2cf24278` | `__xmlGlobalInitMutexDestroy` | [C](../../../analiz/native/system-modules/13c39733bf7d7d34ee29e109765bf59d1b5653b995f672faefb10f748f6fa381/2cf24278.c) |
| `2cfe0864` | `xmlInitializePredefinedEntities` | [C](../../../analiz/native/system-modules/13c39733bf7d7d34ee29e109765bf59d1b5653b995f672faefb10f748f6fa381/2cfe0864.c) |
| `2cec82b8` | `FUN_2cec82b8` | [C](../../../analiz/native/system-modules/13c39733bf7d7d34ee29e109765bf59d1b5653b995f672faefb10f748f6fa381/2cec82b8.c) |
| `2ce3cc44` | `xmlInitNodeInfoSeq` | [C](../../../analiz/native/system-modules/13c39733bf7d7d34ee29e109765bf59d1b5653b995f672faefb10f748f6fa381/2ce3cc44.c) |
| `2cf241d8` | `__xmlGlobalInitMutexLock` | [C](../../../analiz/native/system-modules/13c39733bf7d7d34ee29e109765bf59d1b5653b995f672faefb10f748f6fa381/2cf241d8.c) |
| `2cf24228` | `__xmlGlobalInitMutexUnlock` | [C](../../../analiz/native/system-modules/13c39733bf7d7d34ee29e109765bf59d1b5653b995f672faefb10f748f6fa381/2cf24228.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
