# `07_MSLIB/utopia/libdrvSERFLASH.so`

SHA-256: `4829f2f6c977865cc048ecea46333f4f0ffc4e1d4071a4d4be5be9e094aeec63`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 83048 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MDrv_SERFLASH_SetPowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 6, "symbol_examples": ["UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["HAL_SERFLASH_Config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 33 / 134.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 154; semboller: 983.
- Xref: 3475; analizde call tipli xref: 0.
- Computed-call instruction: 792 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/4829f2f6c977865cc048ecea46333f4f0ffc4e1d4071a4d4be5be9e094aeec63/functions.jsonl) · [Xref](../../../analiz/native/system-modules/4829f2f6c977865cc048ecea46333f4f0ffc4e1d4071a4d4be5be9e094aeec63/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/4829f2f6c977865cc048ecea46333f4f0ffc4e1d4071a4d4be5be9e094aeec63/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/4829f2f6c977865cc048ecea46333f4f0ffc4e1d4071a4d4be5be9e094aeec63/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2efb240c` | `MDrv_SERFLASH_SetMcuCSCallBack` | [C](../../../analiz/native/system-modules/4829f2f6c977865cc048ecea46333f4f0ffc4e1d4071a4d4be5be9e094aeec63/2efb240c.c) |
| `2efb2424` | `MDrv_SERFLASH_SetFlashWPCallBack` | [C](../../../analiz/native/system-modules/4829f2f6c977865cc048ecea46333f4f0ffc4e1d4071a4d4be5be9e094aeec63/2efb2424.c) |
| `2efb23d4` | `MDrv_SERFLASH_SetDbgLevel` | [C](../../../analiz/native/system-modules/4829f2f6c977865cc048ecea46333f4f0ffc4e1d4071a4d4be5be9e094aeec63/2efb23d4.c) |
| `2efb23f0` | `MDrv_SERFLASH_SetWPInfo` | [C](../../../analiz/native/system-modules/4829f2f6c977865cc048ecea46333f4f0ffc4e1d4071a4d4be5be9e094aeec63/2efb23f0.c) |
| `2efb4d24` | `MDrv_SERFLASH_GetStatus` | [C](../../../analiz/native/system-modules/4829f2f6c977865cc048ecea46333f4f0ffc4e1d4071a4d4be5be9e094aeec63/2efb4d24.c) |
| `2efb5c58` | `HAL_SERFLASH_DetectSize` | [C](../../../analiz/native/system-modules/4829f2f6c977865cc048ecea46333f4f0ffc4e1d4071a4d4be5be9e094aeec63/2efb5c58.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
