# `07_MSLIB/utopia/libapiPNL.so`

SHA-256: `f6e412e96afeec7759ef8f59b25f169ffca2f9982c8c6740773f75818d353b72`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 156936 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 10, "symbol_examples": ["MApi_MOD_PVDD_Power_Setting", "MApi_MOD_PVDD_Power_Setting_U2", "MApi_PNL_EX_MOD_PVDD_Power_Setting", "MApi_PNL_EX_TCONMAP_Power_Sequence", "MApi_PNL_SetPowerState", "MApi_PNL_SetPowerState_U2", "MApi_PNL_TCONMAP_Power_Sequence", "MApi_PNL_TCONMAP_Power_Sequence_U2", "MHal_MOD_PVDD_Power_Setting", "MHal_MOD_PowerOn"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 20, "symbol_examples": ["MApi_PNL_SetOSDSSC_En", "MApi_PNL_SetOSDSSC_En_U2", "MApi_PNL_SetOSDSSC_Fmodulation", "MApi_PNL_SetOSDSSC_Fmodulation_U2", "MApi_PNL_SetOSDSSC_Rdeviation_U2", "MDrv_PNL_SetOSDCOutputType", "MDrv_PNL_SetOSDSSC", "MDrv_PNL_SetOSDSSC_En", "MDrv_PNL_SetOSDSSC_Fmodulation", "MDrv_PNL_SetOSDSSC_Rdeviation", "MHal_PNL_SetOSDSSC", "MHal_PNL_SetOSDSSC_En", "UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceGetPrivate"], "examples_are_complete": false}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 12, "symbol_examples": ["LPLLSettingTBL", "MApi_MOD_PVDD_Power_Setting", "MApi_MOD_PVDD_Power_Setting_U2", "MApi_Mod_Calibration_Setting", "MApi_Mod_Calibration_Setting_U2", "MApi_PNL_EX_MOD_OutputConfig_User", "MApi_PNL_EX_MOD_PVDD_Power_Setting", "MApi_PNL_EX_Mod_Calibration_Setting", "MApi_PNL_MOD_OutputConfig_User", "MApi_PNL_MOD_OutputConfig_User_U2", "MHal_MOD_PVDD_Power_Setting", "MHal_Output_LVDS_Pair_Setting"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 39 / 333.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 376; semboller: 1718.
- Xref: 7659; analizde call tipli xref: 0.
- Computed-call instruction: 1396 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/f6e412e96afeec7759ef8f59b25f169ffca2f9982c8c6740773f75818d353b72/functions.jsonl) · [Xref](../../../analiz/native/system-modules/f6e412e96afeec7759ef8f59b25f169ffca2f9982c8c6740773f75818d353b72/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/f6e412e96afeec7759ef8f59b25f169ffca2f9982c8c6740773f75818d353b72/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/f6e412e96afeec7759ef8f59b25f169ffca2f9982c8c6740773f75818d353b72/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2ed49584` | `MHal_PNL_PreInit` | [C](../../../analiz/native/system-modules/f6e412e96afeec7759ef8f59b25f169ffca2f9982c8c6740773f75818d353b72/2ed49584.c) |
| `2ed45b1c` | `MDrv_Mod_Calibration_Init` | [C](../../../analiz/native/system-modules/f6e412e96afeec7759ef8f59b25f169ffca2f9982c8c6740773f75818d353b72/2ed45b1c.c) |
| `2ed46108` | `MDrv_PNL_TCON_Init` | [C](../../../analiz/native/system-modules/f6e412e96afeec7759ef8f59b25f169ffca2f9982c8c6740773f75818d353b72/2ed46108.c) |
| `2ed55b40` | `MApi_PNL_TCON_Init_U2` | [C](../../../analiz/native/system-modules/f6e412e96afeec7759ef8f59b25f169ffca2f9982c8c6740773f75818d353b72/2ed55b40.c) |
| `2ed4cd8c` | `MApi_PNL_TCONMAP_Power_Sequence_U2` | [C](../../../analiz/native/system-modules/f6e412e96afeec7759ef8f59b25f169ffca2f9982c8c6740773f75818d353b72/2ed4cd8c.c) |
| `2ed47d70` | `MDrv_PNL_PreInit` | [C](../../../analiz/native/system-modules/f6e412e96afeec7759ef8f59b25f169ffca2f9982c8c6740773f75818d353b72/2ed47d70.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
