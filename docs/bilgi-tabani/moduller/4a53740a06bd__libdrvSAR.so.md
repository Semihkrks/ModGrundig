# `07_MSLIB/utopia/libdrvSAR.so`

SHA-256: `4a53740a06bde9f05f27db1ab7ba504cbf13476bc3e73715af52225ce9f6dd74`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 27700 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 5, "symbol_examples": ["MDrv_SAR_GetKeyCode", "MDrv_SAR_Kpa_GetKeyCode_Alogrithm", "MDrv_SAR_Kpd_GetKeyCode", "MDrv_SAR_Kpd_GetKeyCode_U2K", "MDrv_SAR_Kpd_GetMultiKeyCode"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 5, "symbol_examples": ["HAL_SAR_CfgAtopPowerdown", "HAL_SAR_CfgDigitPowerdown", "HAL_SAR_Wakeup_EN", "MDrv_SAR_CfgPMWakeup", "MDrv_SAR_SetPowerState"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["MDrv_SAR_Adc_Config", "MDrv_SAR_Config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 17 / 82.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 94; semboller: 358.
- Xref: 1089; analizde call tipli xref: 0.
- Computed-call instruction: 149 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/4a53740a06bde9f05f27db1ab7ba504cbf13476bc3e73715af52225ce9f6dd74/functions.jsonl) · [Xref](../../../analiz/native/system-modules/4a53740a06bde9f05f27db1ab7ba504cbf13476bc3e73715af52225ce9f6dd74/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/4a53740a06bde9f05f27db1ab7ba504cbf13476bc3e73715af52225ce9f6dd74/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/4a53740a06bde9f05f27db1ab7ba504cbf13476bc3e73715af52225ce9f6dd74/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f5427c0` | `MDrv_SAR_Kpd_CfgChannelBound` | [C](../../../analiz/native/system-modules/4a53740a06bde9f05f27db1ab7ba504cbf13476bc3e73715af52225ce9f6dd74/2f5427c0.c) |
| `2f543e08` | `HAL_SAR_CfgSingleChannel` | [C](../../../analiz/native/system-modules/4a53740a06bde9f05f27db1ab7ba504cbf13476bc3e73715af52225ce9f6dd74/2f543e08.c) |
| `2f543fb4` | `HAL_SAR_CfgAtopPowerdown` | [C](../../../analiz/native/system-modules/4a53740a06bde9f05f27db1ab7ba504cbf13476bc3e73715af52225ce9f6dd74/2f543fb4.c) |
| `2f543e94` | `HAL_SAR_CfgSingleChannelEn` | [C](../../../analiz/native/system-modules/4a53740a06bde9f05f27db1ab7ba504cbf13476bc3e73715af52225ce9f6dd74/2f543e94.c) |
| `2f543f24` | `HAL_SAR_CfgDigitPowerdown` | [C](../../../analiz/native/system-modules/4a53740a06bde9f05f27db1ab7ba504cbf13476bc3e73715af52225ce9f6dd74/2f543f24.c) |
| `2f544088` | `HAL_SAR_CfgHighChannel` | [C](../../../analiz/native/system-modules/4a53740a06bde9f05f27db1ab7ba504cbf13476bc3e73715af52225ce9f6dd74/2f544088.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
