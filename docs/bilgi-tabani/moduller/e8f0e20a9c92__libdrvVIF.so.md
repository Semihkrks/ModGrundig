# `07_MSLIB/utopia/libdrvVIF.so`

SHA-256: `e8f0e20a9c92afc725aee61a5690b5973db041fdca4accfabbcadf22fda4c951`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 61284 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 8, "symbol_examples": ["DRV_VIF_BypassDBBAudioFilter", "DRV_VIF_SetSoundSystem", "HAL_VIF_BypassDBBAudioFilter", "VIF_PAL_DK_Audio_SingleSAW", "VIF_PAL_GH_Audio_SingleSAW", "VIF_PAL_I_Audio_SingleSAW", "g_ucVifSoundSystemType", "msVifSetSoundSystem"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MDrv_VIF_SetPowerState"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 10 / 157.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 66; semboller: 372.
- Xref: 1444; analizde call tipli xref: 0.
- Computed-call instruction: 612 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/e8f0e20a9c92afc725aee61a5690b5973db041fdca4accfabbcadf22fda4c951/functions.jsonl) · [Xref](../../../analiz/native/system-modules/e8f0e20a9c92afc725aee61a5690b5973db041fdca4accfabbcadf22fda4c951/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/e8f0e20a9c92afc725aee61a5690b5973db041fdca4accfabbcadf22fda4c951/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/e8f0e20a9c92afc725aee61a5690b5973db041fdca4accfabbcadf22fda4c951/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f5a370c` | `MDrv_VIF_SetPowerState` | [C](../../../analiz/native/system-modules/e8f0e20a9c92afc725aee61a5690b5973db041fdca4accfabbcadf22fda4c951/2f5a370c.c) |
| `2f5a1e14` | `_init` | [C](../../../analiz/native/system-modules/e8f0e20a9c92afc725aee61a5690b5973db041fdca4accfabbcadf22fda4c951/2f5a1e14.c) |
| `2f5aae3c` | `HAL_VIF_RegInit` | [C](../../../analiz/native/system-modules/e8f0e20a9c92afc725aee61a5690b5973db041fdca4accfabbcadf22fda4c951/2f5aae3c.c) |
| `2f5aa538` | `msVifAdcInitial` | [C](../../../analiz/native/system-modules/e8f0e20a9c92afc725aee61a5690b5973db041fdca4accfabbcadf22fda4c951/2f5aa538.c) |
| `2f5a2718` | `DRV_VIF_Init` | [C](../../../analiz/native/system-modules/e8f0e20a9c92afc725aee61a5690b5973db041fdca4accfabbcadf22fda4c951/2f5a2718.c) |
| `2f5a7a94` | `msVifInitial` | [C](../../../analiz/native/system-modules/e8f0e20a9c92afc725aee61a5690b5973db041fdca4accfabbcadf22fda4c951/2f5a7a94.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
