# `07_MSLIB/utopia/libdrvHWI2C.so`

SHA-256: `af1124e26315f823cd306ea82ac109e6e2887e452789f994d20592c7dbc5dd45`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 24152 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MDrv_HWI2C_SetPowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 6, "symbol_examples": ["UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["MDrv_HWI2C_ConfigDelay", "MDrv_HWI2C_ConfigDelay_EX"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 23 / 86.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 106; semboller: 307.
- Xref: 1023; analizde call tipli xref: 0.
- Computed-call instruction: 179 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 5/5.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/af1124e26315f823cd306ea82ac109e6e2887e452789f994d20592c7dbc5dd45/functions.jsonl) · [Xref](../../../analiz/native/system-modules/af1124e26315f823cd306ea82ac109e6e2887e452789f994d20592c7dbc5dd45/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/af1124e26315f823cd306ea82ac109e6e2887e452789f994d20592c7dbc5dd45/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/af1124e26315f823cd306ea82ac109e6e2887e452789f994d20592c7dbc5dd45/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f4230e4` | `MDrv_HWI2C_Init` | [C](../../../analiz/native/system-modules/af1124e26315f823cd306ea82ac109e6e2887e452789f994d20592c7dbc5dd45/2f4230e4.c) |
| `2f4239b8` | `HAL_HWI2C_Init_Chip` | [C](../../../analiz/native/system-modules/af1124e26315f823cd306ea82ac109e6e2887e452789f994d20592c7dbc5dd45/2f4239b8.c) |
| `2f421580` | `_init` | [C](../../../analiz/native/system-modules/af1124e26315f823cd306ea82ac109e6e2887e452789f994d20592c7dbc5dd45/2f421580.c) |
| `2f423118` | `MDrv_HWI2C_SetPowerState` | [C](../../../analiz/native/system-modules/af1124e26315f823cd306ea82ac109e6e2887e452789f994d20592c7dbc5dd45/2f423118.c) |
| `2f422bb0` | `MDrv_HWI2C_Init_U2K` | [C](../../../analiz/native/system-modules/af1124e26315f823cd306ea82ac109e6e2887e452789f994d20592c7dbc5dd45/2f422bb0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
