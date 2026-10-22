# `09_CONFIG/libsysteminfo.so`

SHA-256: `c19ce43d39263bb0d765de7077d7901d3d2497808aaab09353b45e0573ef4426`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 249684 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 33, "symbol_examples": ["_ZN10SystemInfo13m_VolumeCurveE", "_ZN10SystemInfo14GetVolumeCurveEv", "_ZN10SystemInfo14SetVolumeCurveEv", "_ZN10SystemInfo15m_pAudioMuxInfoE", "_ZN10SystemInfo16GetAudioPathInfoEv", "_ZN10SystemInfo16m_pAudioPathInfoE", "_ZN10SystemInfo17GetAudioAmpSelectEv", "_ZN10SystemInfo17SetAudioAmpSelectEv", "_ZN10SystemInfo18m_AudioDefaultInitE", "_ZN10SystemInfo18m_bEnableVolumeComE", "_ZN10SystemInfo18m_u8AudioAmpSelectE", "_ZN10SystemInfo19GetAudioDefaultInitEv", "_ZN10SystemInfo19SetAudioInputMuxCfgEv", "_ZN10SystemInfo19get_AUDIOSystemTypeEv", "_ZN10SystemInfo20GetAudioInputMuxInfoEv", "_ZN10SystemInfo20GetPcModeTimingTableEv"], "examples_are_complete": false}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 23, "symbol_examples": ["BOARD_pstHDMIEDIDInfos", "_ZN10SystemInfo16CheckHDMIEDIDBinEh", "_ZN10SystemInfo16GetCECPortSelectEv", "_ZN10SystemInfo16LoadHDMIEDIDInfoEP16HDMI_EDID_Info_tPvi", "_ZN10SystemInfo16m_stHdmiZoomInfoE", "_ZN10SystemInfo17m_HdmiEdidInfoSetE", "_ZN10SystemInfo18GetHDMIEDIDInfoSetEv", "_ZN10SystemInfo18GetHdmiDetectCountEv", "_ZN10SystemInfo18SetHDMIEDIDInfoSetEv", "_ZN10SystemInfo19GetHdmi5vGpioSelectEv", "_ZN10SystemInfo19SetHDMITxAnalogInfoEv", "_ZN10SystemInfo20GetPowerOnNetflixKeyEv", "_ZN10SystemInfo20SetPowerOnNetflixKeyEh", "_ZN10SystemInfo21m_u8PowerOnNetflixKeyE", "_ZN10SystemInfo21stHDMIDetectCountInfoE", "_ZN10SystemInfo22SetHDMIDetectModeCountEPK19stSignalDetectCount"], "examples_are_complete": false}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 7, "symbol_examples": ["_ZN10SystemInfo11GetOSDCInfoEP13MAPI_OSDCType", "_ZN10SystemInfo12LoadOSDCInfoEv", "_ZN10SystemInfo14getOSDLpllTypeEv", "_ZN10SystemInfo14setOSDLpllTypeEm", "_ZN10SystemInfo15SetVideoInfoCfgE11VideoInfo_shPK25ST_MAPI_VIDEO_WINDOW_INFOmhm", "_ZN10SystemInfo17updateOSDLpllTypeEiii", "_ZN10SystemInfo19SetVDCaptureWinModeE25EN_VD_CAPTURE_WINDOW_MODE"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 25, "symbol_examples": ["_Z20iniparser_getU8arrayP12_dictionary_PKctPh", "_ZN10SystemInfo10SetMSPICfgEP12MSPIConfig_shh", "_ZN10SystemInfo11m_i2cconfigE", "_ZN10SystemInfo12GetI2CConfigEv", "_ZN10SystemInfo12m_gpioconfigE", "_ZN10SystemInfo12m_mspiconfigE", "_ZN10SystemInfo13GetGPIOConfigEv", "_ZN10SystemInfo13GetMSPIConfigEv", "_ZN10SystemInfo14GetDemodConfigEhPPhS1_", "_ZN10SystemInfo14GetEpgDBConfigEv", "_ZN10SystemInfo14SetDemodConfigEv", "_ZN10SystemInfo14SetEpgDBConfigER17MAPI_EPGDB_CONFIG", "_ZN10SystemInfo17iniparser_CheckCSEPKc", "_ZN10SystemInfo18iniparser_UpdateCSEPKc", "_ZN10SystemInfo23SetHDMIEDIDInfoSettingsEv", "_ZN10SystemInfo25GetTspSectionFilterConfigEv"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libiniparser.so`, `libMStarSDK.so`, `libstdc++.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 103 / 458.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 418; semboller: 3374.
- Xref: 8828; analizde call tipli xref: 0.
- Computed-call instruction: 2275 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/c19ce43d39263bb0d765de7077d7901d3d2497808aaab09353b45e0573ef4426/functions.jsonl) · [Xref](../../../analiz/native/system-modules/c19ce43d39263bb0d765de7077d7901d3d2497808aaab09353b45e0573ef4426/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/c19ce43d39263bb0d765de7077d7901d3d2497808aaab09353b45e0573ef4426/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/c19ce43d39263bb0d765de7077d7901d3d2497808aaab09353b45e0573ef4426/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2ec7a904` | `SystemInfo::GetAudioDefaultInit` | [C](../../../analiz/native/system-modules/c19ce43d39263bb0d765de7077d7901d3d2497808aaab09353b45e0573ef4426/2ec7a904.c) |
| `2ec7a918` | `SystemInfo::GetVolumeCurve` | [C](../../../analiz/native/system-modules/c19ce43d39263bb0d765de7077d7901d3d2497808aaab09353b45e0573ef4426/2ec7a918.c) |
| `2ec7a9f0` | `SystemInfo::GetPanelModPvddPowerInfo` | [C](../../../analiz/native/system-modules/c19ce43d39263bb0d765de7077d7901d3d2497808aaab09353b45e0573ef4426/2ec7a9f0.c) |
| `2ec7b328` | `SystemInfo::GetTunerPWMInfo` | [C](../../../analiz/native/system-modules/c19ce43d39263bb0d765de7077d7901d3d2497808aaab09353b45e0573ef4426/2ec7b328.c) |
| `2ec79fcc` | `SystemInfo::GetSARChannel` | [C](../../../analiz/native/system-modules/c19ce43d39263bb0d765de7077d7901d3d2497808aaab09353b45e0573ef4426/2ec79fcc.c) |
| `2ec7a0e8` | `SystemInfo::SetVolumeCompensationFlag` | [C](../../../analiz/native/system-modules/c19ce43d39263bb0d765de7077d7901d3d2497808aaab09353b45e0573ef4426/2ec7a0e8.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
