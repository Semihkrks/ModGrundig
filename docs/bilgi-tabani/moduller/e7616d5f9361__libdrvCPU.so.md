# `07_MSLIB/utopia/libdrvCPU.so`

SHA-256: `e7616d5f9361e7de5f1a271c95084e0a8909ffd1ea05e6aad76d7caf22f3888d`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 16060 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MDrv_CPU_SetPowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 6, "symbol_examples": ["UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 26 / 68.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 72; semboller: 212.
- Xref: 480; analizde call tipli xref: 0.
- Computed-call instruction: 115 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/e7616d5f9361e7de5f1a271c95084e0a8909ffd1ea05e6aad76d7caf22f3888d/functions.jsonl) · [Xref](../../../analiz/native/system-modules/e7616d5f9361e7de5f1a271c95084e0a8909ffd1ea05e6aad76d7caf22f3888d/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/e7616d5f9361e7de5f1a271c95084e0a8909ffd1ea05e6aad76d7caf22f3888d/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/e7616d5f9361e7de5f1a271c95084e0a8909ffd1ea05e6aad76d7caf22f3888d/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f3a2634` | `HAL_COPRO_Init_End` | [C](../../../analiz/native/system-modules/e7616d5f9361e7de5f1a271c95084e0a8909ffd1ea05e6aad76d7caf22f3888d/2f3a2634.c) |
| `2f3a1910` | `_MDrv_CPU_InitEnd` | [C](../../../analiz/native/system-modules/e7616d5f9361e7de5f1a271c95084e0a8909ffd1ea05e6aad76d7caf22f3888d/2f3a1910.c) |
| `2f3a1a14` | `_MDrv_CPU_InitFront` | [C](../../../analiz/native/system-modules/e7616d5f9361e7de5f1a271c95084e0a8909ffd1ea05e6aad76d7caf22f3888d/2f3a1a14.c) |
| `2f3a1a6c` | `MDrv_COPRO_Init_Front` | [C](../../../analiz/native/system-modules/e7616d5f9361e7de5f1a271c95084e0a8909ffd1ea05e6aad76d7caf22f3888d/2f3a1a6c.c) |
| `2f3a26ec` | `HAL_COPRO_Init_Front` | [C](../../../analiz/native/system-modules/e7616d5f9361e7de5f1a271c95084e0a8909ffd1ea05e6aad76d7caf22f3888d/2f3a26ec.c) |
| `2f3a1174` | `_init` | [C](../../../analiz/native/system-modules/e7616d5f9361e7de5f1a271c95084e0a8909ffd1ea05e6aad76d7caf22f3888d/2f3a1174.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
