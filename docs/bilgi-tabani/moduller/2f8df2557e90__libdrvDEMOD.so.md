# `07_MSLIB/utopia/libdrvDEMOD.so`

SHA-256: `2f8df2557e90355eeb97bc170426d564284bfd4137b18cb4f2de8e2895892393`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 530108 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 35, "symbol_examples": ["INTERN_DVBC_Power_ON_OFF", "INTERN_DVBC_Power_On_Initialization", "INTERN_DVBC_Power_Save", "INTERN_DVBS_PowerSaving", "INTERN_DVBS_Power_ON_OFF", "INTERN_DVBS_Power_On_Initialization", "INTERN_DVBS_Power_Save", "INTERN_DVBS_UnicableAGCCheckPower", "INTERN_DVBT2_Power_ON_OFF", "INTERN_DVBT2_Power_On_Initialization", "INTERN_DVBT2_Power_Save", "INTERN_DVBT_Power_ON_OFF", "INTERN_DVBT_Power_On_Initialization", "INTERN_DVBT_Power_Save", "MDrv_DMD_ATSC_MD_SetPowerState", "MDrv_DMD_ATSC_SetPowerState"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["INTERN_DVBT2_GetPlpBitMap", "MDrv_DMD_DVBT2_GetPlpBitMap"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 23, "symbol_examples": ["INTERN_DVBC_Config", "INTERN_DVBS_BlindScan_Config", "INTERN_DVBS_Config", "INTERN_DVBT2_Config", "INTERN_DVBT2_ConfigAdaptiveTsDivNum", "INTERN_DVBT_Config", "MDrv_DMD_ATSC_MD_SetConfig", "MDrv_DMD_ATSC_SetConfig", "MDrv_DMD_DTMB_MD_SetConfig", "MDrv_DMD_DTMB_SetConfig", "MDrv_DMD_DVBC_SetConfig", "MDrv_DMD_DVBC_SetConfig_symbol_rate_list", "MDrv_DMD_DVBS_SetConfig", "MDrv_DMD_DVBS_SetConfig_symbol_rate_list", "MDrv_DMD_DVBT2_SetConfig", "MDrv_DMD_DVBT_SetConfig"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 40 / 608.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 609; semboller: 2792.
- Xref: 13950; analizde call tipli xref: 0.
- Computed-call instruction: 3336 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/2f8df2557e90355eeb97bc170426d564284bfd4137b18cb4f2de8e2895892393/functions.jsonl) · [Xref](../../../analiz/native/system-modules/2f8df2557e90355eeb97bc170426d564284bfd4137b18cb4f2de8e2895892393/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/2f8df2557e90355eeb97bc170426d564284bfd4137b18cb4f2de8e2895892393/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/2f8df2557e90355eeb97bc170426d564284bfd4137b18cb4f2de8e2895892393/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2e4d2dc4` | `MDrv_DMD_DVBS_BlindScan_GetTunerFreq_EX` | [C](../../../analiz/native/system-modules/2f8df2557e90355eeb97bc170426d564284bfd4137b18cb4f2de8e2895892393/2e4d2dc4.c) |
| `2e4d2e60` | `MDrv_DMD_DVBS_BlindScan_GetChannel` | [C](../../../analiz/native/system-modules/2f8df2557e90355eeb97bc170426d564284bfd4137b18cb4f2de8e2895892393/2e4d2e60.c) |
| `2e4cbc7c` | `MDrv_DMD_ATSC_SetPowerState` | [C](../../../analiz/native/system-modules/2f8df2557e90355eeb97bc170426d564284bfd4137b18cb4f2de8e2895892393/2e4cbc7c.c) |
| `2e4cc0cc` | `MDrv_DMD_SSPI_Init` | [C](../../../analiz/native/system-modules/2f8df2557e90355eeb97bc170426d564284bfd4137b18cb4f2de8e2895892393/2e4cc0cc.c) |
| `2e4cf554` | `MDrv_DMD_DTMB_SetPowerState` | [C](../../../analiz/native/system-modules/2f8df2557e90355eeb97bc170426d564284bfd4137b18cb4f2de8e2895892393/2e4cf554.c) |
| `2e4ddb6c` | `MDrv_DMD_ISDBT_SetPowerState` | [C](../../../analiz/native/system-modules/2f8df2557e90355eeb97bc170426d564284bfd4137b18cb4f2de8e2895892393/2e4ddb6c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
