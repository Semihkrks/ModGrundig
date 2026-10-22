# `07_MSLIB/utopia/libdrvRTC.so`

SHA-256: `9f78459f3eb4df6036edcd4a7bf48d33a9ab21f66ba3738b992cf7bc38ae21aa`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 15980 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MDrv_RTC_SetPowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceRegister"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 21 / 46.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 60; semboller: 243.
- Xref: 492; analizde call tipli xref: 0.
- Computed-call instruction: 92 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 4/4.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/9f78459f3eb4df6036edcd4a7bf48d33a9ab21f66ba3738b992cf7bc38ae21aa/functions.jsonl) · [Xref](../../../analiz/native/system-modules/9f78459f3eb4df6036edcd4a7bf48d33a9ab21f66ba3738b992cf7bc38ae21aa/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/9f78459f3eb4df6036edcd4a7bf48d33a9ab21f66ba3738b992cf7bc38ae21aa/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/9f78459f3eb4df6036edcd4a7bf48d33a9ab21f66ba3738b992cf7bc38ae21aa/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f5210f0` | `MDrv_RTC_DeInit` | [C](../../../analiz/native/system-modules/9f78459f3eb4df6036edcd4a7bf48d33a9ab21f66ba3738b992cf7bc38ae21aa/2f5210f0.c) |
| `2f520dcc` | `_init` | [C](../../../analiz/native/system-modules/9f78459f3eb4df6036edcd4a7bf48d33a9ab21f66ba3738b992cf7bc38ae21aa/2f520dcc.c) |
| `2f521854` | `MDrv_RTC_SetPowerState` | [C](../../../analiz/native/system-modules/9f78459f3eb4df6036edcd4a7bf48d33a9ab21f66ba3738b992cf7bc38ae21aa/2f521854.c) |
| `2f521614` | `MDrv_RTC_Init` | [C](../../../analiz/native/system-modules/9f78459f3eb4df6036edcd4a7bf48d33a9ab21f66ba3738b992cf7bc38ae21aa/2f521614.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
