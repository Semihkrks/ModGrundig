# `07_MSLIB/utopia/libapiACE.so`

SHA-256: `11d63f18d7c7ac81ce94d5561c46f587da1e041abd20a9302db0ca0e5016e906`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 127976 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 3, "symbol_examples": ["ACEClose", "MApi_XC_ACE_SetPowerState", "MApi_XC_ACE_SetPowerState_U2"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 7, "symbol_examples": ["UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceGetPrivate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 34 / 385.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 403; semboller: 1204.
- Xref: 5308; analizde call tipli xref: 0.
- Computed-call instruction: 978 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/11d63f18d7c7ac81ce94d5561c46f587da1e041abd20a9302db0ca0e5016e906/functions.jsonl) · [Xref](../../../analiz/native/system-modules/11d63f18d7c7ac81ce94d5561c46f587da1e041abd20a9302db0ca0e5016e906/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/11d63f18d7c7ac81ce94d5561c46f587da1e041abd20a9302db0ca0e5016e906/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/11d63f18d7c7ac81ce94d5561c46f587da1e041abd20a9302db0ca0e5016e906/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2eec79b8` | `Hal_ACE_init_riu_base` | [C](../../../analiz/native/system-modules/11d63f18d7c7ac81ce94d5561c46f587da1e041abd20a9302db0ca0e5016e906/2eec79b8.c) |
| `2eec6c2c` | `MDrv_ACE_init_riu_base` | [C](../../../analiz/native/system-modules/11d63f18d7c7ac81ce94d5561c46f587da1e041abd20a9302db0ca0e5016e906/2eec6c2c.c) |
| `2eed9ad0` | `ACEClose` | [C](../../../analiz/native/system-modules/11d63f18d7c7ac81ce94d5561c46f587da1e041abd20a9302db0ca0e5016e906/2eed9ad0.c) |
| `2eed72fc` | `MApi_XC_ACE_EX_DNR_Init_Noise` | [C](../../../analiz/native/system-modules/11d63f18d7c7ac81ce94d5561c46f587da1e041abd20a9302db0ca0e5016e906/2eed72fc.c) |
| `2eed7368` | `MApi_XC_ACE_EX_DNR_Init_Luma` | [C](../../../analiz/native/system-modules/11d63f18d7c7ac81ce94d5561c46f587da1e041abd20a9302db0ca0e5016e906/2eed7368.c) |
| `2eed73d4` | `MApi_XC_ACE_EX_DNR_Init_Motion` | [C](../../../analiz/native/system-modules/11d63f18d7c7ac81ce94d5561c46f587da1e041abd20a9302db0ca0e5016e906/2eed73d4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
