# `07_MSLIB/utopia/libdrvIR.so`

SHA-256: `ce8942e58ad01c90dee6869aff2673a48ee6267d369597820b6670427e6b4529`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 13112 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 21, "symbol_examples": ["IRClose", "IRIoctl", "IROpen", "IRRegisterToUtopia", "MDrv_IR_Config", "MDrv_IR_Enable", "MDrv_IR_GetCallback", "MDrv_IR_GetInfo", "MDrv_IR_GetKeyCode", "MDrv_IR_GetLibVer", "MDrv_IR_GetPulseShot", "MDrv_IR_GetStatus", "MDrv_IR_Init", "MDrv_IR_InitCfg", "MDrv_IR_OpenDevice", "MDrv_IR_SetCallback"], "examples_are_complete": false}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MDrv_IR_SetPowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceRegister"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MDrv_IR_Config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 22 / 33.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 48; semboller: 205.
- Xref: 603; analizde call tipli xref: 0.
- Computed-call instruction: 80 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 4/4.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/ce8942e58ad01c90dee6869aff2673a48ee6267d369597820b6670427e6b4529/functions.jsonl) · [Xref](../../../analiz/native/system-modules/ce8942e58ad01c90dee6869aff2673a48ee6267d369597820b6670427e6b4529/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/ce8942e58ad01c90dee6869aff2673a48ee6267d369597820b6670427e6b4529/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/ce8942e58ad01c90dee6869aff2673a48ee6267d369597820b6670427e6b4529/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f461044` | `MDrv_IR_InitCfg` | [C](../../../analiz/native/system-modules/ce8942e58ad01c90dee6869aff2673a48ee6267d369597820b6670427e6b4529/2f461044.c) |
| `2f460b1c` | `_init` | [C](../../../analiz/native/system-modules/ce8942e58ad01c90dee6869aff2673a48ee6267d369597820b6670427e6b4529/2f460b1c.c) |
| `2f461e74` | `MDrv_IR_SetPowerState` | [C](../../../analiz/native/system-modules/ce8942e58ad01c90dee6869aff2673a48ee6267d369597820b6670427e6b4529/2f461e74.c) |
| `2f461c88` | `MDrv_IR_Init` | [C](../../../analiz/native/system-modules/ce8942e58ad01c90dee6869aff2673a48ee6267d369597820b6670427e6b4529/2f461c88.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
