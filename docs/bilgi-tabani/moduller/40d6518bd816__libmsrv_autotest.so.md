# `07_MSLIB/libmsrv_autotest.so`

SHA-256: `40d6518bd8162d5a1e20e5e7cd18fb503c5f4009c37ee285c4859231b7720c80`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 412500 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 54, "symbol_examples": ["_ZN10mapi_audio13SPDIF_GetSCMSEv", "_ZN10mapi_audio16SetCommAudioInfoE20Audio_COMM_infoType_mm", "_ZN10mapi_audio16SetDebugMsgLevelE22MAPI_AUDIO_DEBUG_LEVEL", "_ZN10mapi_audio17SND_ProcessEnableE18Sound_ENABLE_Type_h", "_ZN10mapi_audio18SIF_GetAudioStatusEv", "_ZN10mapi_audio31SIF_ConvertToBasicAudioStandardE19AUDIOSTANDARD_TYPE_", "_ZN12MSrv_SSSound13GetMuteStatusE27MAPI_SOUND_MUTE_STATUS_TYPE", "_ZN12MSrv_SSSound16SetDebugMsgLevelE24MSRV_SSSOUND_DEBUG_LEVEL", "_ZN12MSrv_SSSound9GetVolumeEv", "_ZN12MSrv_SSSound9SetVolumeEh", "_ZN16TestSuite_SI_Cmd19GetVolumeMuteStatusEv", "_ZN16TestSuite_SI_Cmd9GetVolumeEv", "_ZN16TestSuite_SI_Cmd9SetVolumeEj", "_ZN17MSrv_MediaBrowser16ChangeAudioTrackE27EN_MEDIA_BROWSER_MEDIA_TYPEm", "_ZN17MSrv_MediaBrowser18GetAudioTrackIndexE27EN_MEDIA_BROWSER_MEDIA_TYPE", "_ZN19MSrv_Control_common14GetMSrvSSSoundEv"], "examples_are_complete": false}, {"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 14, "symbol_examples": ["_ZN23TestSuite_IRKey_Handler10m_instanceE", "_ZN23TestSuite_IRKey_Handler11GetInstanceEv", "_ZN23TestSuite_IRKey_Handler12IRKeyMappingEt", "_ZN23TestSuite_IRKey_Handler8Hex2LongEPKc", "_ZN23TestSuite_IRKey_Handler9SendIRKeyEth", "_ZN23TestSuite_IRKey_HandlerC1Ev", "_ZN23TestSuite_IRKey_HandlerC2Ev", "_ZN23TestSuite_IRKey_HandlerD0Ev", "_ZN23TestSuite_IRKey_HandlerD1Ev", "_ZN23TestSuite_IRKey_HandlerD2Ev", "_ZN6MW_TTX10KeyHandlerE19EN_TELETEXT_COMMAND", "_ZTI23TestSuite_IRKey_Handler", "_ZTS23TestSuite_IRKey_Handler", "_ZTV23TestSuite_IRKey_Handler"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["_ZN15MSrv_Control_TV11GetMSrvHdmiEv", "_ZN16MSrv_HDMI_Player10ISHDMIModeEv", "_ZN20TestSuite_Direct_Cmd14GetInputSourceEP23EN_AT_INPUT_SOURCE_TYPE", "_ZN20TestSuite_Direct_Cmd14SetInputSourceE23EN_AT_INPUT_SOURCE_TYPE"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 14, "symbol_examples": ["_ZN14MWindowManager10IsOSDExistEv", "_ZN16TestSuite_SI_Cmd13GetOsdCountryEv", "_ZN16TestSuite_SI_Cmd14GetOsdLanguageEv", "_ZN22TestSuite_OSD_Dump_Cmd16ProcessATCommandE6AT_CMD", "_ZN22TestSuite_OSD_Dump_Cmd8IntToStrEl", "_ZN22TestSuite_OSD_Dump_CmdC1Ev", "_ZN22TestSuite_OSD_Dump_CmdC2Ev", "_ZN22TestSuite_OSD_Dump_CmdD0Ev", "_ZN22TestSuite_OSD_Dump_CmdD1Ev", "_ZN22TestSuite_OSD_Dump_CmdD2Ev", "_ZN7MSystem17GetMWindowManagerEv", "_ZTI22TestSuite_OSD_Dump_Cmd", "_ZTS22TestSuite_OSD_Dump_Cmd", "_ZTV22TestSuite_OSD_Dump_Cmd"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 10, "symbol_examples": ["_ZN15MSrv_Control_TV18GetMSrvAtvDatabaseEv", "_ZN17TestSuite_Utility25HardwareConfig_ShowConfigEv", "_ZN17TestSuite_Utility28SoftwareConfig_ShowAppConfigEv", "_ZN17TestSuite_Utility30SoftwareConfig_ShowAdvTVConfigEv", "_ZN17TestSuite_Utility32SoftwareConfig_ShowBasicTVConfigEv", "_ZN19MSrv_Control_common21GetMSrvSystemDatabaseEv", "_ZN20MSrv_Network_Control28EnableEthIpStaticWithSettingE24msrv_network_ipv4_addr_sS0_S0_h", "_ZN21TestSuite_Network_Cmd14SettingNetworkEv", "_ZTI20MSrv_System_Database", "_ZTI24MSrv_System_Database_DVB"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libatclient.so`, `libmsrv_atv.so`, `libmsrv_dvb_customer.so`, `libmsrv_dvbc_customer.so`, `libmsrv_dvbs_customer.so`, `libmsrv_dvbt_customer.so`, `libmsrv_mmbrowser.so`, `libmsrv_network.so`, `libutilities.so`, `libdirectfb-1.4.so.0`, `librt.so.1`, `libpthread.so.0`, `libdirect-1.4.so.0`, `libMStarSDK.so`, `libMStarSDK_customer.so`, `libfreetype.so.6`, `libMLog.so`, `libmuf.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 371 / 476.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 723; semboller: 9854.
- Xref: 19418; analizde call tipli xref: 0.
- Computed-call instruction: 5092 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/40d6518bd8162d5a1e20e5e7cd18fb503c5f4009c37ee285c4859231b7720c80/functions.jsonl) · [Xref](../../../analiz/native/system-modules/40d6518bd8162d5a1e20e5e7cd18fb503c5f4009c37ee285c4859231b7720c80/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/40d6518bd8162d5a1e20e5e7cd18fb503c5f4009c37ee285c4859231b7720c80/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/40d6518bd8162d5a1e20e5e7cd18fb503c5f4009c37ee285c4859231b7720c80/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2e771568` | `MW_AutoTest_DVB_SI::Init` | [C](../../../analiz/native/system-modules/40d6518bd8162d5a1e20e5e7cd18fb503c5f4009c37ee285c4859231b7720c80/2e771568.c) |
| `2e7a3890` | `TestSuite_Network_Cmd::~TestSuite_Network_Cmd` | [C](../../../analiz/native/system-modules/40d6518bd8162d5a1e20e5e7cd18fb503c5f4009c37ee285c4859231b7720c80/2e7a3890.c) |
| `2e7a38b0` | `TestSuite_Network_Cmd::~TestSuite_Network_Cmd` | [C](../../../analiz/native/system-modules/40d6518bd8162d5a1e20e5e7cd18fb503c5f4009c37ee285c4859231b7720c80/2e7a38b0.c) |
| `2e7a3920` | `TestSuite_Network_Cmd::TestSuite_Network_Cmd` | [C](../../../analiz/native/system-modules/40d6518bd8162d5a1e20e5e7cd18fb503c5f4009c37ee285c4859231b7720c80/2e7a3920.c) |
| `2e7a3968` | `TestSuite_Network_Cmd::TestSuite_Network_Cmd` | [C](../../../analiz/native/system-modules/40d6518bd8162d5a1e20e5e7cd18fb503c5f4009c37ee285c4859231b7720c80/2e7a3968.c) |
| `2e7a38d0` | `TestSuite_Network_Cmd::~TestSuite_Network_Cmd` | [C](../../../analiz/native/system-modules/40d6518bd8162d5a1e20e5e7cd18fb503c5f4009c37ee285c4859231b7720c80/2e7a38d0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
