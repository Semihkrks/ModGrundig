# `07_MSLIB/libicuuc.so.42.1`

SHA-256: `d9de405ba4f18f8576aa16909450a53010de6786a2146a126f2cb5717c9deca0`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 1896892 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["_ZN7icu_4_217CanonicalIterator7permuteERNS_13UnicodeStringEaPNS_9HashtableER10UErrorCode"], "examples_are_complete": true}, {"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 5, "symbol_examples": ["_ZNK7icu_4_214ResourceBundle6getKeyEv", "_ZNK7icu_4_26Locale15getKeywordValueEPKcPciR10UErrorCode", "uloc_getKeywordValue_4_2", "ures_getKey_4_2", "ures_getKeywordValues_4_2"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["_ZN7icu_4_217CanonicalIterator9getSourceEv", "_ZN7icu_4_217CanonicalIterator9setSourceERKNS_13UnicodeStringER10UErrorCode"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 49, "symbol_examples": ["_ZN7icu_4_214ResourceBundle13getNextStringEPPKcR10UErrorCode", "_ZN7icu_4_214ResourceBundle13getNextStringER10UErrorCode", "_ZN7icu_4_214ResourceBundle13resetIteratorEv", "_ZN7icu_4_214ResourceBundle15getWithFallbackEPKcR10UErrorCode", "_ZN7icu_4_214ResourceBundle16getStaticClassIDEv", "_ZN7icu_4_214ResourceBundle18constructForLocaleERKNS_13UnicodeStringERKNS_6LocaleER10UErrorCode", "_ZN7icu_4_214ResourceBundle7getNextER10UErrorCode", "_ZN7icu_4_214ResourceBundleC1EP15UResourceBundleR10UErrorCode", "_ZN7icu_4_214ResourceBundleC1EPKcRKNS_6LocaleER10UErrorCode", "_ZN7icu_4_214ResourceBundleC1ER10UErrorCode", "_ZN7icu_4_214ResourceBundleC1ERKNS_13UnicodeStringER10UErrorCode", "_ZN7icu_4_214ResourceBundleC1ERKNS_13UnicodeStringERKNS_6LocaleER10UErrorCode", "_ZN7icu_4_214ResourceBundleC1ERKS0_", "_ZN7icu_4_214ResourceBundleC2EP15UResourceBundleR10UErrorCode", "_ZN7icu_4_214ResourceBundleC2EPKcRKNS_6LocaleER10UErrorCode", "_ZN7icu_4_214ResourceBundleC2ER10UErrorCode"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libicudata.so.42`, `libpthread.so.0`, `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 72 / 1759.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 2989; semboller: 26955.
- Xref: 159195; analizde call tipli xref: 0.
- Computed-call instruction: 10775 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/d9de405ba4f18f8576aa16909450a53010de6786a2146a126f2cb5717c9deca0/functions.jsonl) · [Xref](../../../analiz/native/system-modules/d9de405ba4f18f8576aa16909450a53010de6786a2146a126f2cb5717c9deca0/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/d9de405ba4f18f8576aa16909450a53010de6786a2146a126f2cb5717c9deca0/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/d9de405ba4f18f8576aa16909450a53010de6786a2146a126f2cb5717c9deca0/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2d2dfcec` | `FUN_2d2dfcec` | [C](../../../analiz/native/system-modules/d9de405ba4f18f8576aa16909450a53010de6786a2146a126f2cb5717c9deca0/2d2dfcec.c) |
| `2d269d4c` | `uprv_getInfinity_4_2` | [C](../../../analiz/native/system-modules/d9de405ba4f18f8576aa16909450a53010de6786a2146a126f2cb5717c9deca0/2d269d4c.c) |
| `2d2cb8ac` | `icu_4_2::ResourceBundle::getStaticClassID` | [C](../../../analiz/native/system-modules/d9de405ba4f18f8576aa16909450a53010de6786a2146a126f2cb5717c9deca0/2d2cb8ac.c) |
| `2d2cb8e0` | `icu_4_2::ResourceBundle::getDynamicClassID` | [C](../../../analiz/native/system-modules/d9de405ba4f18f8576aa16909450a53010de6786a2146a126f2cb5717c9deca0/2d2cb8e0.c) |
| `2d2cbc50` | `icu_4_2::ResourceBundle::getVersionNumber` | [C](../../../analiz/native/system-modules/d9de405ba4f18f8576aa16909450a53010de6786a2146a126f2cb5717c9deca0/2d2cbc50.c) |
| `2d2cbf74` | `icu_4_2::ResourceBundle::resetIterator` | [C](../../../analiz/native/system-modules/d9de405ba4f18f8576aa16909450a53010de6786a2146a126f2cb5717c9deca0/2d2cbf74.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
