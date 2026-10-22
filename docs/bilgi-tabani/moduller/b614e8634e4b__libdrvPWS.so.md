# `07_MSLIB/utopia/libdrvPWS.so`

SHA-256: `b614e8634e4bb78823645ae2c9060b5c825a93e51a5cbb5b44743a839d8ed06d`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 20352 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 7, "symbol_examples": ["HAL_PWS_GetSourceInfo", "HAL_PWS_IpPowerControl", "MDrv_PWS_GetSourceInfo", "MDrv_PWS_IpPowerControl", "MDrv_PWS_PHYPower", "MDrv_PWS_ScenePowerControl", "MDrv_PWS_SetPowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 6, "symbol_examples": ["UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 28 / 58.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 73; semboller: 256.
- Xref: 656; analizde call tipli xref: 0.
- Computed-call instruction: 129 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/b614e8634e4bb78823645ae2c9060b5c825a93e51a5cbb5b44743a839d8ed06d/functions.jsonl) · [Xref](../../../analiz/native/system-modules/b614e8634e4bb78823645ae2c9060b5c825a93e51a5cbb5b44743a839d8ed06d/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/b614e8634e4bb78823645ae2c9060b5c825a93e51a5cbb5b44743a839d8ed06d/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/b614e8634e4bb78823645ae2c9060b5c825a93e51a5cbb5b44743a839d8ed06d/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f501e3c` | `MDrv_PWS_IpPowerControl` | [C](../../../analiz/native/system-modules/b614e8634e4bb78823645ae2c9060b5c825a93e51a5cbb5b44743a839d8ed06d/2f501e3c.c) |
| `2f50107c` | `_init` | [C](../../../analiz/native/system-modules/b614e8634e4bb78823645ae2c9060b5c825a93e51a5cbb5b44743a839d8ed06d/2f50107c.c) |
| `2f501c88` | `MDrv_PWS_Init` | [C](../../../analiz/native/system-modules/b614e8634e4bb78823645ae2c9060b5c825a93e51a5cbb5b44743a839d8ed06d/2f501c88.c) |
| `2f501d30` | `MDrv_PWS_SetPowerState` | [C](../../../analiz/native/system-modules/b614e8634e4bb78823645ae2c9060b5c825a93e51a5cbb5b44743a839d8ed06d/2f501d30.c) |
| `2f5018e0` | `MDrv_PWS_PHYPower` | [C](../../../analiz/native/system-modules/b614e8634e4bb78823645ae2c9060b5c825a93e51a5cbb5b44743a839d8ed06d/2f5018e0.c) |
| `2f502228` | `HAL_PWS_Init` | [C](../../../analiz/native/system-modules/b614e8634e4bb78823645ae2c9060b5c825a93e51a5cbb5b44743a839d8ed06d/2f502228.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
