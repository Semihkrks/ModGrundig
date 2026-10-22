# `07_MSLIB/utopia/libdrvPCMCIA.so`

SHA-256: `f1c885fcd956cc8c67c50a7fef4183682b358d05e681771d84f53cb39b7acbce`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 34752 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 100, "symbol_examples": ["HAL_PCMCIA_ClkCtrl", "HAL_PCMCIA_ClrInt", "HAL_PCMCIA_GetIntStatus", "HAL_PCMCIA_MaskInt", "HAL_PCMCIA_Read_Byte", "HAL_PCMCIA_Set_RIU_base", "HAL_PCMCIA_Write_Byte", "MDrv_PCMCIA_DetectV2", "MDrv_PCMCIA_Enable_Interrupt", "MDrv_PCMCIA_Enable_InterruptV2", "MDrv_PCMCIA_Exit", "MDrv_PCMCIA_GetLibVer", "MDrv_PCMCIA_Get_CD_Interval", "MDrv_PCMCIA_Get_CD_IntervalV2", "MDrv_PCMCIA_Get_InterruptStatus", "MDrv_PCMCIA_Get_InterruptStatusV2"], "examples_are_complete": false}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["MDrv_PCMCIA_SetPowerState", "_MDrv_PCMCIA_SetPowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 8, "symbol_examples": ["UtopiaModuleAddResourceEnd", "UtopiaResourceCreate", "UtopiaResourceGetPrivate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease", "ePcmResourceId", "psResource"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 35 / 114.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 138; semboller: 447.
- Xref: 1331; analizde call tipli xref: 0.
- Computed-call instruction: 312 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/f1c885fcd956cc8c67c50a7fef4183682b358d05e681771d84f53cb39b7acbce/functions.jsonl) · [Xref](../../../analiz/native/system-modules/f1c885fcd956cc8c67c50a7fef4183682b358d05e681771d84f53cb39b7acbce/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/f1c885fcd956cc8c67c50a7fef4183682b358d05e681771d84f53cb39b7acbce/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/f1c885fcd956cc8c67c50a7fef4183682b358d05e681771d84f53cb39b7acbce/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f4a1ef4` | `MDrv_PCMCIA_WaitForStatusBit` | [C](../../../analiz/native/system-modules/f1c885fcd956cc8c67c50a7fef4183682b358d05e681771d84f53cb39b7acbce/2f4a1ef4.c) |
| `2f4a46d8` | `_MDrv_PCMCIA_SetPowerState` | [C](../../../analiz/native/system-modules/f1c885fcd956cc8c67c50a7fef4183682b358d05e681771d84f53cb39b7acbce/2f4a46d8.c) |
| `2f4a4ec4` | `MDrv_PCMCIA_SetPowerState` | [C](../../../analiz/native/system-modules/f1c885fcd956cc8c67c50a7fef4183682b358d05e681771d84f53cb39b7acbce/2f4a4ec4.c) |
| `2f4a1ad4` | `_init` | [C](../../../analiz/native/system-modules/f1c885fcd956cc8c67c50a7fef4183682b358d05e681771d84f53cb39b7acbce/2f4a1ad4.c) |
| `2f4a4f44` | `MDrv_PCMCIA_WaitForStatusBitV2` | [C](../../../analiz/native/system-modules/f1c885fcd956cc8c67c50a7fef4183682b358d05e681771d84f53cb39b7acbce/2f4a4f44.c) |
| `2f4a4190` | `_MDrv_PCMCIA_InitHW` | [C](../../../analiz/native/system-modules/f1c885fcd956cc8c67c50a7fef4183682b358d05e681771d84f53cb39b7acbce/2f4a4190.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
