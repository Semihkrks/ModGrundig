# `07_MSLIB/libiculx.so.42.1`

SHA-256: `6f70a89c8166957096ab9c0158eae8aea7d38001214b848f60120fbd18ac177a`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 83308 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 33, "symbol_examples": ["_ZN7icu_4_212LayoutEngine19layoutEngineFactoryEPKNS_14LEFontInstanceEiiR11LEErrorCode", "_ZN7icu_4_215ParagraphLayout15computeSubFontsEPKNS_8FontRunsER11LEErrorCode", "_ZN7icu_4_215ParagraphLayout4Line6appendEPKNS_14LEFontInstanceE14UBiDiDirectioniPKjPKfPKi", "_ZN7icu_4_215ParagraphLayout9VisualRunC1EPKNS_14LEFontInstanceE14UBiDiDirectioniPKjPKfPKi", "_ZN7icu_4_215ParagraphLayoutC1EPKtiPKNS_8FontRunsEPKNS_9ValueRunsES8_PKNS_10LocaleRunsEhaR11LEErrorCode", "_ZN7icu_4_215ParagraphLayoutC2EPKtiPKNS_8FontRunsEPKNS_9ValueRunsES8_PKNS_10LocaleRunsEhaR11LEErrorCode", "_ZN7icu_4_28FontRuns16getStaticClassIDEv", "_ZN7icu_4_28FontRuns3addEPKNS_14LEFontInstanceEi", "_ZN7icu_4_28FontRuns4growEi", "_ZN7icu_4_28FontRuns4initEi", "_ZN7icu_4_28FontRuns9fgClassIDE", "_ZN7icu_4_28FontRunsC1EPPKNS_14LEFontInstanceEPKii", "_ZN7icu_4_28FontRunsC1Ei", "_ZN7icu_4_28FontRunsC2Ei", "_ZN7icu_4_28FontRunsD0Ev", "_ZN7icu_4_28FontRunsD1Ev"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libicuuc.so.42`, `libicudata.so.42`, `libicule.so.42`, `libpthread.so.0`, `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 43 / 199.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 266; semboller: 1233.
- Xref: 6178; analizde call tipli xref: 0.
- Computed-call instruction: 518 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/6f70a89c8166957096ab9c0158eae8aea7d38001214b848f60120fbd18ac177a/functions.jsonl) · [Xref](../../../analiz/native/system-modules/6f70a89c8166957096ab9c0158eae8aea7d38001214b848f60120fbd18ac177a/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/6f70a89c8166957096ab9c0158eae8aea7d38001214b848f60120fbd18ac177a/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/6f70a89c8166957096ab9c0158eae8aea7d38001214b848f60120fbd18ac177a/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `0001f1b8` | `icu_4_2::ParagraphLayout::VisualRun::getFont` | [C](../../../analiz/native/system-modules/6f70a89c8166957096ab9c0158eae8aea7d38001214b848f60120fbd18ac177a/0001f1b8.c) |
| `0001df5c` | `icu_4_2::FontRuns::getStaticClassID` | [C](../../../analiz/native/system-modules/6f70a89c8166957096ab9c0158eae8aea7d38001214b848f60120fbd18ac177a/0001df5c.c) |
| `0001df8c` | `icu_4_2::FontRuns::getDynamicClassID` | [C](../../../analiz/native/system-modules/6f70a89c8166957096ab9c0158eae8aea7d38001214b848f60120fbd18ac177a/0001df8c.c) |
| `0001f320` | `pl_closeFontRuns_4_2` | [C](../../../analiz/native/system-modules/6f70a89c8166957096ab9c0158eae8aea7d38001214b848f60120fbd18ac177a/0001f320.c) |
| `0001c708` | `icu_4_2::RunArray::init` | [C](../../../analiz/native/system-modules/6f70a89c8166957096ab9c0158eae8aea7d38001214b848f60120fbd18ac177a/0001c708.c) |
| `0001f404` | `pl_resetFontRuns_4_2` | [C](../../../analiz/native/system-modules/6f70a89c8166957096ab9c0158eae8aea7d38001214b848f60120fbd18ac177a/0001f404.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
