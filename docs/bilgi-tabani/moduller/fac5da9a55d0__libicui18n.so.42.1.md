# `07_MSLIB/libicui18n.so.42.1`

SHA-256: `fac5da9a55d0a9c521da6d3e012e86c027a6b145a3dbb65040442ed17e2c86b4`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 604108 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 35, "symbol_examples": ["_ZN7icu_4_212CollationKey10setToBogusEv", "_ZN7icu_4_212CollationKey14ensureCapacityEi", "_ZN7icu_4_212CollationKey16getStaticClassIDEv", "_ZN7icu_4_212CollationKey5adoptEPhi", "_ZN7icu_4_212CollationKey5resetEv", "_ZN7icu_4_212CollationKeyC1EPKhi", "_ZN7icu_4_212CollationKeyC1ERKS0_", "_ZN7icu_4_212CollationKeyC1Ev", "_ZN7icu_4_212CollationKeyC2EPKhi", "_ZN7icu_4_212CollationKeyC2ERKS0_", "_ZN7icu_4_212CollationKeyC2Ev", "_ZN7icu_4_212CollationKeyD0Ev", "_ZN7icu_4_212CollationKeyD1Ev", "_ZN7icu_4_212CollationKeyD2Ev", "_ZN7icu_4_212CollationKeyaSERKS0_", "_ZN7icu_4_28Collator11getKeywordsER10UErrorCode"], "examples_are_complete": false}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["_ZN7icu_4_217CanonicalIterator9setSourceERKNS_13UnicodeStringER10UErrorCode"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["ures_getNextResource_4_2"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libicuuc.so.42`, `libicudata.so.42`, `libpthread.so.0`, `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 246 / 485.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 1706; semboller: 9418.
- Xref: 51692; analizde call tipli xref: 0.
- Computed-call instruction: 4557 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/fac5da9a55d0a9c521da6d3e012e86c027a6b145a3dbb65040442ed17e2c86b4/functions.jsonl) · [Xref](../../../analiz/native/system-modules/fac5da9a55d0a9c521da6d3e012e86c027a6b145a3dbb65040442ed17e2c86b4/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/fac5da9a55d0a9c521da6d3e012e86c027a6b145a3dbb65040442ed17e2c86b4/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/fac5da9a55d0a9c521da6d3e012e86c027a6b145a3dbb65040442ed17e2c86b4/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `0002d2cc` | `uprv_init_collIterate_4_2` | [C](../../../analiz/native/system-modules/fac5da9a55d0a9c521da6d3e012e86c027a6b145a3dbb65040442ed17e2c86b4/0002d2cc.c) |
| `0002bac0` | `uprv_init_pce_4_2` | [C](../../../analiz/native/system-modules/fac5da9a55d0a9c521da6d3e012e86c027a6b145a3dbb65040442ed17e2c86b4/0002bac0.c) |
| `0002e6fc` | `uprv_uca_initImplicitConstants_4_2` | [C](../../../analiz/native/system-modules/fac5da9a55d0a9c521da6d3e012e86c027a6b145a3dbb65040442ed17e2c86b4/0002e6fc.c) |
| `0001ec08` | `_init` | [C](../../../analiz/native/system-modules/fac5da9a55d0a9c521da6d3e012e86c027a6b145a3dbb65040442ed17e2c86b4/0001ec08.c) |
| `0004f7a8` | `ucol_normalizeShortDefinitionString_4_2` | [C](../../../analiz/native/system-modules/fac5da9a55d0a9c521da6d3e012e86c027a6b145a3dbb65040442ed17e2c86b4/0004f7a8.c) |
| `00049310` | `ucol_initInverseUCA_4_2` | [C](../../../analiz/native/system-modules/fac5da9a55d0a9c521da6d3e012e86c027a6b145a3dbb65040442ed17e2c86b4/00049310.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
