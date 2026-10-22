# `06_RFS/lib/libnss_compat-2.8.so`

SHA-256: `96c88bb38c395b6fa8430c81be4e35a05a809dab551d3e2dcceaf69a6d681e72`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 36368 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["__nss_database_lookup@GLIBC_2.0 (3)"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libnsl.so.1`, `libc.so.6`
- Dynamic import/export: 37 / 17.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 103; semboller: 431.
- Xref: 1348; analizde call tipli xref: 0.
- Computed-call instruction: 275 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/96c88bb38c395b6fa8430c81be4e35a05a809dab551d3e2dcceaf69a6d681e72/functions.jsonl) · [Xref](../../../analiz/native/system-modules/96c88bb38c395b6fa8430c81be4e35a05a809dab551d3e2dcceaf69a6d681e72/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/96c88bb38c395b6fa8430c81be4e35a05a809dab551d3e2dcceaf69a6d681e72/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/96c88bb38c395b6fa8430c81be4e35a05a809dab551d3e2dcceaf69a6d681e72/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010d54` | `_DT_INIT` | [C](../../../analiz/native/system-modules/96c88bb38c395b6fa8430c81be4e35a05a809dab551d3e2dcceaf69a6d681e72/00010d54.c) |
| `00016a6c` | `_nss_compat_initgroups_dyn` | [C](../../../analiz/native/system-modules/96c88bb38c395b6fa8430c81be4e35a05a809dab551d3e2dcceaf69a6d681e72/00016a6c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
