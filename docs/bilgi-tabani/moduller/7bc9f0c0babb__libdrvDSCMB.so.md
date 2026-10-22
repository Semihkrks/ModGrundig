# `07_MSLIB/utopia/libdrvDSCMB.so`

SHA-256: `7bc9f0c0babb1f466a5c823d6e2b1fdd97d696840916a1d2c9267e3e68558b6c`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 41268 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["MApi_DSCMB_SetPowerState", "MDrv_DSCMB2_SetPowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 7, "symbol_examples": ["UtopiaModuleAddResourceEnd", "UtopiaResourceCreate", "UtopiaResourceGetPrivate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease", "eDscmbResourceId"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 5, "symbol_examples": ["HAL_DSCMB_OptConfig", "MDrv_DSCMB2_OptConfig", "MDrv_DSCMB_KLadder_GetConfig", "MDrv_DSCMB_KLadder_SetConfig", "_MDrv_DSCMB2_OptConfig"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 27 / 148.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 165; semboller: 535.
- Xref: 1612; analizde call tipli xref: 0.
- Computed-call instruction: 258 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/7bc9f0c0babb1f466a5c823d6e2b1fdd97d696840916a1d2c9267e3e68558b6c/functions.jsonl) · [Xref](../../../analiz/native/system-modules/7bc9f0c0babb1f466a5c823d6e2b1fdd97d696840916a1d2c9267e3e68558b6c/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/7bc9f0c0babb1f466a5c823d6e2b1fdd97d696840916a1d2c9267e3e68558b6c/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/7bc9f0c0babb1f466a5c823d6e2b1fdd97d696840916a1d2c9267e3e68558b6c/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f3e5610` | `MDrv_DSCMB_Init` | [C](../../../analiz/native/system-modules/7bc9f0c0babb1f466a5c823d6e2b1fdd97d696840916a1d2c9267e3e68558b6c/2f3e5610.c) |
| `2f3e56cc` | `MApi_DSCMB_SetPowerState` | [C](../../../analiz/native/system-modules/7bc9f0c0babb1f466a5c823d6e2b1fdd97d696840916a1d2c9267e3e68558b6c/2f3e56cc.c) |
| `2f3e5644` | `MDrv_DSCMB2_SetPowerState` | [C](../../../analiz/native/system-modules/7bc9f0c0babb1f466a5c823d6e2b1fdd97d696840916a1d2c9267e3e68558b6c/2f3e5644.c) |
| `2f3e20e0` | `_init` | [C](../../../analiz/native/system-modules/7bc9f0c0babb1f466a5c823d6e2b1fdd97d696840916a1d2c9267e3e68558b6c/2f3e20e0.c) |
| `2f3e5534` | `MDrv_DSCMB2_Init` | [C](../../../analiz/native/system-modules/7bc9f0c0babb1f466a5c823d6e2b1fdd97d696840916a1d2c9267e3e68558b6c/2f3e5534.c) |
| `2f3e75c4` | `HAL_DSCMB_Init` | [C](../../../analiz/native/system-modules/7bc9f0c0babb1f466a5c823d6e2b1fdd97d696840916a1d2c9267e3e68558b6c/2f3e75c4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
