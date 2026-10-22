# `07_MSLIB/libicule.so.42.1`

SHA-256: `8ee798970a60ac281ec9c4112838927572eeb2e9ea381a43caee0a5c226e022f`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 355120 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 56, "symbol_examples": ["_ZN7icu_4_212LayoutEngine19layoutEngineFactoryEPKNS_14LEFontInstanceEiiR11LEErrorCode", "_ZN7icu_4_212LayoutEngine19layoutEngineFactoryEPKNS_14LEFontInstanceEiiiR11LEErrorCode", "_ZN7icu_4_212LayoutEngineC1EPKNS_14LEFontInstanceEiiiR11LEErrorCode", "_ZN7icu_4_212LayoutEngineC2EPKNS_14LEFontInstanceEiiiR11LEErrorCode", "_ZN7icu_4_214LEFontInstance16getStaticClassIDEv", "_ZN7icu_4_214LEFontInstanceC2Ev", "_ZN7icu_4_214LEFontInstanceD0Ev", "_ZN7icu_4_214LEFontInstanceD1Ev", "_ZN7icu_4_214LEFontInstanceD2Ev", "_ZN7icu_4_220OpenTypeLayoutEngineC1EPKNS_14LEFontInstanceEiiiPKNS_28GlyphSubstitutionTableHeaderER11LEErrorCode", "_ZN7icu_4_220OpenTypeLayoutEngineC1EPKNS_14LEFontInstanceEiiiR11LEErrorCode", "_ZN7icu_4_220OpenTypeLayoutEngineC2EPKNS_14LEFontInstanceEiiiPKNS_28GlyphSubstitutionTableHeaderER11LEErrorCode", "_ZN7icu_4_220OpenTypeLayoutEngineC2EPKNS_14LEFontInstanceEiiiR11LEErrorCode", "_ZN7icu_4_220PortableFontInstanceC1EPKcfR11LEErrorCode", "_ZN7icu_4_220PortableFontInstanceC2EPKcfR11LEErrorCode", "_ZN7icu_4_220PortableFontInstanceD0Ev"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libicuuc.so.42`, `libicudata.so.42`, `libpthread.so.0`, `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 29 / 181.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 781; semboller: 3941.
- Xref: 24704; analizde call tipli xref: 0.
- Computed-call instruction: 2367 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/8ee798970a60ac281ec9c4112838927572eeb2e9ea381a43caee0a5c226e022f/functions.jsonl) · [Xref](../../../analiz/native/system-modules/8ee798970a60ac281ec9c4112838927572eeb2e9ea381a43caee0a5c226e022f/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/8ee798970a60ac281ec9c4112838927572eeb2e9ea381a43caee0a5c226e022f/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/8ee798970a60ac281ec9c4112838927572eeb2e9ea381a43caee0a5c226e022f/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2e8fa96c` | `icu_4_2::LEGlyphStorage::applyInsertion` | [C](../../../analiz/native/system-modules/8ee798970a60ac281ec9c4112838927572eeb2e9ea381a43caee0a5c226e022f/2e8fa96c.c) |
| `2e8fbf18` | `icu_4_2::LEGlyphStorage::~LEGlyphStorage` | [C](../../../analiz/native/system-modules/8ee798970a60ac281ec9c4112838927572eeb2e9ea381a43caee0a5c226e022f/2e8fbf18.c) |
| `2e8fc0ac` | `icu_4_2::LEGlyphStorage::~LEGlyphStorage` | [C](../../../analiz/native/system-modules/8ee798970a60ac281ec9c4112838927572eeb2e9ea381a43caee0a5c226e022f/2e8fc0ac.c) |
| `2e909578` | `icu_4_2::PortableFontInstance::~PortableFontInstance` | [C](../../../analiz/native/system-modules/8ee798970a60ac281ec9c4112838927572eeb2e9ea381a43caee0a5c226e022f/2e909578.c) |
| `2e9097cc` | `icu_4_2::PortableFontInstance::~PortableFontInstance` | [C](../../../analiz/native/system-modules/8ee798970a60ac281ec9c4112838927572eeb2e9ea381a43caee0a5c226e022f/2e9097cc.c) |
| `2e8da0e0` | `icu_4_2::LEGlyphStorage::getGlyphCount` | [C](../../../analiz/native/system-modules/8ee798970a60ac281ec9c4112838927572eeb2e9ea381a43caee0a5c226e022f/2e8da0e0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
