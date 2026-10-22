# `07_MSLIB/libPQ_cus.so`

SHA-256: `f6787274fb200fc59dd48acdc8e1cd5ff652cb3d78f67121dda693c46dd10106`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 395804 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 34, "symbol_examples": ["MDrv_PQ_GetInputSourceType", "PQ_IPTAB_DHD_HDMI_6R_3_Text_Main", "PQ_IPTAB_DHD_HDMI_6R_6_Text_Main", "PQ_IPTAB_DHD_HDMI_6R_HD_3_Text_Main", "PQ_IPTAB_DHD_HDMI_6R_HD_6_Text_Main", "PQ_IPTAB_DHD_HDMI_8R_3_Text_Main", "PQ_IPTAB_DHD_HDMI_8R_6_Text_Main", "PQ_IPTAB_DHD_HDMI_8R_HD_3_Text_Main", "PQ_IPTAB_DHD_HDMI_8R_HD_6_Text_Main", "PQ_IPTAB_PostCCS_HDMI_6R_3_Text_Main", "PQ_IPTAB_PostCCS_HDMI_6R_6_Text_Main", "PQ_IPTAB_PostCCS_HDMI_8R_3_Text_Main", "PQ_IPTAB_PostCCS_HDMI_8R_6_Text_Main", "PQ_IPTAB_PostCCS_HDMI_8R_7_Text_Main", "PQ_IPTAB_VIP_ICC_SETTING_HDMI_1080_Text_Main", "PQ_IPTAB_VIP_ICC_SETTING_HDMI_1080i_Text_Main"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 9, "symbol_examples": ["MDrv_PQ_GetMADiFromOSDBWGrule", "MDrv_PQ_LoadOSD_BWTable", "MDrv_PQ_ReduceBW_ForOSD", "MST_GRule_1366_OSD_BW_Main", "MST_GRule_1920_OSD_BW_Main", "MST_GRule_OSD_BW_IP_Index_Main", "MST_GRule_OSD_BW_Main", "PQ_IPTAB_Film_AUTOSD_50_Text_Main", "_bOSD_On"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 88, "symbol_examples": ["MDrv_PQ_ChangeMemConfigFor3D", "MST_3DSettingForLBL_no_comm_COM_Main", "MST_3DSettingForLBL_no_comm_Main", "MST_SettingFor2LineMode_no_comm_COM_Main", "MST_SettingFor2LineMode_no_comm_Main", "MST_VIP_IBC_SETTING_COM_Main", "MST_VIP_IBC_SETTING_Main", "MST_VIP_ICC_SETTING_COM_Main", "MST_VIP_ICC_SETTING_Main", "MST_VIP_IHC_SETTING_COM_Main", "MST_VIP_IHC_SETTING_Main", "MST_VIP_LDE_setting_COM_Main", "MST_VIP_LDE_setting_Main", "MST_VIP_Ymode_Yvalue_SETTING_COM_Main", "MST_VIP_Ymode_Yvalue_SETTING_Main", "PQ_IPTAB_3DSettingForLBL_no_comm_ON_Text_Main"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 94 / 1932.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 211; semboller: 2917.
- Xref: 4761; analizde call tipli xref: 0.
- Computed-call instruction: 624 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 4/4.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/f6787274fb200fc59dd48acdc8e1cd5ff652cb3d78f67121dda693c46dd10106/functions.jsonl) · [Xref](../../../analiz/native/system-modules/f6787274fb200fc59dd48acdc8e1cd5ff652cb3d78f67121dda693c46dd10106/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/f6787274fb200fc59dd48acdc8e1cd5ff652cb3d78f67121dda693c46dd10106/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/f6787274fb200fc59dd48acdc8e1cd5ff652cb3d78f67121dda693c46dd10106/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2e68136c` | `MDrv_PQ_SetNetworkMM_OnOff` | [C](../../../analiz/native/system-modules/f6787274fb200fc59dd48acdc8e1cd5ff652cb3d78f67121dda693c46dd10106/2e68136c.c) |
| `2e67f840` | `_init` | [C](../../../analiz/native/system-modules/f6787274fb200fc59dd48acdc8e1cd5ff652cb3d78f67121dda693c46dd10106/2e67f840.c) |
| `2e68553c` | `MDrv_BW_LoadInitTable` | [C](../../../analiz/native/system-modules/f6787274fb200fc59dd48acdc8e1cd5ff652cb3d78f67121dda693c46dd10106/2e68553c.c) |
| `2e681f88` | `MDrv_PQ_Init_DisplayType` | [C](../../../analiz/native/system-modules/f6787274fb200fc59dd48acdc8e1cd5ff652cb3d78f67121dda693c46dd10106/2e681f88.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
