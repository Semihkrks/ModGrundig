# `07_MSLIB/libmsrv_network.so`

SHA-256: `55b8009ddeff377b334d6e116472a837c07e695e86d5ff9ac308d4a2639139bf`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 423636 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 18, "symbol_examples": ["_ZN20MSrv_Network_Control14ClearIpSettingE17network_if_info_s", "_ZN20MSrv_Network_Control16ResetEthDataBaseEv", "_ZN20MSrv_Network_Control17ResetWifiDataBaseEv", "_ZN20MSrv_Network_Control19ResetCommonDataBaseEv", "_ZN20MSrv_Network_Control27CloneNetworkSettingFromFileEPhlll", "_ZN20MSrv_Network_Control28EnableEthIpStaticWithSettingE24msrv_network_ipv4_addr_sS0_S0_h", "_ZN20MSrv_Network_Control29EnableWifiIpStaticWithSettingE24msrv_network_ipv4_addr_sS0_S0_h", "_ZN20MSrv_Network_Control29GetWifiAccessPointSettingSSIDEPhm", "_ZN20MSrv_Network_Control31GetWifiAccessPointSettingPasswdEPhm", "iniparser_dump_ini", "iniparser_freedict", "iniparser_getboolean", "iniparser_getnsec", "iniparser_getsecname", "iniparser_getstring", "iniparser_getunsignedint"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `librt.so.1`, `libpthread.so.0`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 148 / 465.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 567; semboller: 7737.
- Xref: 26978; analizde call tipli xref: 0.
- Computed-call instruction: 10452 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/55b8009ddeff377b334d6e116472a837c07e695e86d5ff9ac308d4a2639139bf/functions.jsonl) · [Xref](../../../analiz/native/system-modules/55b8009ddeff377b334d6e116472a837c07e695e86d5ff9ac308d4a2639139bf/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/55b8009ddeff377b334d6e116472a837c07e695e86d5ff9ac308d4a2639139bf/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/55b8009ddeff377b334d6e116472a837c07e695e86d5ff9ac308d4a2639139bf/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2e7ee310` | `MSrv_Network_Control::IsNetworkInit` | [C](../../../analiz/native/system-modules/55b8009ddeff377b334d6e116472a837c07e695e86d5ff9ac308d4a2639139bf/2e7ee310.c) |
| `2e7ee354` | `MSrv_Network_Control::RegisterWanStatusCheckCb` | [C](../../../analiz/native/system-modules/55b8009ddeff377b334d6e116472a837c07e695e86d5ff9ac308d4a2639139bf/2e7ee354.c) |
| `2e7ee360` | `MSrv_Network_Control::UnregisterWanStatusCheckCb` | [C](../../../analiz/native/system-modules/55b8009ddeff377b334d6e116472a837c07e695e86d5ff9ac308d4a2639139bf/2e7ee360.c) |
| `2e830338` | `MSrv_Network_Ip::SetDefaultRoute` | [C](../../../analiz/native/system-modules/55b8009ddeff377b334d6e116472a837c07e695e86d5ff9ac308d4a2639139bf/2e830338.c) |
| `2e81ebf8` | `MSrv_Network_Data_Mgr::~MSrv_Network_Data_Mgr` | [C](../../../analiz/native/system-modules/55b8009ddeff377b334d6e116472a837c07e695e86d5ff9ac308d4a2639139bf/2e81ebf8.c) |
| `2e81ec10` | `MSrv_Network_Data_Mgr::~MSrv_Network_Data_Mgr` | [C](../../../analiz/native/system-modules/55b8009ddeff377b334d6e116472a837c07e695e86d5ff9ac308d4a2639139bf/2e81ec10.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
