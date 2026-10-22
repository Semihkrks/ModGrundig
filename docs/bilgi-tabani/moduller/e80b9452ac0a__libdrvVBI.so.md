# `07_MSLIB/utopia/libdrvVBI.so`

SHA-256: `e80b9452ac0a0b708899aa51410b0cfad2d659c88ce265a5c81f378c5a20b56c`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 42592 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["MDrv_DMX_TTX_SetPowerState", "MDrv_VBI_SetPowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 10, "symbol_examples": ["MDrv_VBI_CC_SetSCWindowLen", "UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease", "VBI_CC_SetSCWindowLen", "_MDrv_VBI_CC_SetSCWindowLen", "eVbiResourceId"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 35 / 150.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 176; semboller: 487.
- Xref: 1697; analizde call tipli xref: 0.
- Computed-call instruction: 461 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/e80b9452ac0a0b708899aa51410b0cfad2d659c88ce265a5c81f378c5a20b56c/functions.jsonl) · [Xref](../../../analiz/native/system-modules/e80b9452ac0a0b708899aa51410b0cfad2d659c88ce265a5c81f378c5a20b56c/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/e80b9452ac0a0b708899aa51410b0cfad2d659c88ce265a5c81f378c5a20b56c/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/e80b9452ac0a0b708899aa51410b0cfad2d659c88ce265a5c81f378c5a20b56c/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f584658` | `_MDrv_VBI_CC_InitYPbYr` | [C](../../../analiz/native/system-modules/e80b9452ac0a0b708899aa51410b0cfad2d659c88ce265a5c81f378c5a20b56c/2f584658.c) |
| `2f585110` | `_MDrv_VBI_InitializeTTXSlicer` | [C](../../../analiz/native/system-modules/e80b9452ac0a0b708899aa51410b0cfad2d659c88ce265a5c81f378c5a20b56c/2f585110.c) |
| `2f582e9c` | `MDrv_DMX_TTX_SetPowerState` | [C](../../../analiz/native/system-modules/e80b9452ac0a0b708899aa51410b0cfad2d659c88ce265a5c81f378c5a20b56c/2f582e9c.c) |
| `2f583504` | `MDrv_VBI_CC_InitYPbYr` | [C](../../../analiz/native/system-modules/e80b9452ac0a0b708899aa51410b0cfad2d659c88ce265a5c81f378c5a20b56c/2f583504.c) |
| `2f5855c4` | `MDrv_VBI_SetPowerState` | [C](../../../analiz/native/system-modules/e80b9452ac0a0b708899aa51410b0cfad2d659c88ce265a5c81f378c5a20b56c/2f5855c4.c) |
| `2f581f00` | `_init` | [C](../../../analiz/native/system-modules/e80b9452ac0a0b708899aa51410b0cfad2d659c88ce265a5c81f378c5a20b56c/2f581f00.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
