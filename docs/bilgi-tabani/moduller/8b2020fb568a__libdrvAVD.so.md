# `07_MSLIB/utopia/libdrvAVD.so`

SHA-256: `8b2020fb568ac4b3d69a744a6f8e7a9d1f3bdce47d7a76182075f3bf0aaeb5ed`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 124992 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["Drv_AVD_SetPowerState", "MDrv_AVD_SetPowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 13, "symbol_examples": ["Drv_AVD_BackPorchWindowPositon", "Drv_AVD_GetCaptureWindow", "HAL_AVD_AFEC_BackPorchWindowPosition", "MDrv_AVD_BackPorchWindowPositon", "MDrv_AVD_GetCaptureWindow", "UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceGetPrivate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease", "_Drv_AVD_BurstWindowTuning"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 29 / 200.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 209; semboller: 763.
- Xref: 2151; analizde call tipli xref: 0.
- Computed-call instruction: 508 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/8b2020fb568ac4b3d69a744a6f8e7a9d1f3bdce47d7a76182075f3bf0aaeb5ed/functions.jsonl) · [Xref](../../../analiz/native/system-modules/8b2020fb568ac4b3d69a744a6f8e7a9d1f3bdce47d7a76182075f3bf0aaeb5ed/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/8b2020fb568ac4b3d69a744a6f8e7a9d1f3bdce47d7a76182075f3bf0aaeb5ed/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/8b2020fb568ac4b3d69a744a6f8e7a9d1f3bdce47d7a76182075f3bf0aaeb5ed/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2ef89000` | `HAL_AVD_AFEC_GetCoChannelOn` | [C](../../../analiz/native/system-modules/8b2020fb568ac4b3d69a744a6f8e7a9d1f3bdce47d7a76182075f3bf0aaeb5ed/2ef89000.c) |
| `2ef89648` | `HAL_AVD_AFEC_SetChannelChange` | [C](../../../analiz/native/system-modules/8b2020fb568ac4b3d69a744a6f8e7a9d1f3bdce47d7a76182075f3bf0aaeb5ed/2ef89648.c) |
| `2ef88ee4` | `HAL_AVD_RegInitExt` | [C](../../../analiz/native/system-modules/8b2020fb568ac4b3d69a744a6f8e7a9d1f3bdce47d7a76182075f3bf0aaeb5ed/2ef88ee4.c) |
| `2ef8862c` | `MDrv_AVD_SetChannelChange` | [C](../../../analiz/native/system-modules/8b2020fb568ac4b3d69a744a6f8e7a9d1f3bdce47d7a76182075f3bf0aaeb5ed/2ef8862c.c) |
| `2ef87a18` | `MDrv_AVD_SetPowerState` | [C](../../../analiz/native/system-modules/8b2020fb568ac4b3d69a744a6f8e7a9d1f3bdce47d7a76182075f3bf0aaeb5ed/2ef87a18.c) |
| `2ef828d4` | `_init` | [C](../../../analiz/native/system-modules/8b2020fb568ac4b3d69a744a6f8e7a9d1f3bdce47d7a76182075f3bf0aaeb5ed/2ef828d4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
