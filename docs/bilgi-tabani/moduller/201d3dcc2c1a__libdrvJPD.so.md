# `07_MSLIB/utopia/libdrvJPD.so`

SHA-256: `201d3dcc2c1a81a4f33b345439da7d00456c5903d5e6b4101bb5165661e9a4ed`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 32976 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["HAL_JPD_PowerOff", "HAL_JPD_PowerOn", "MDrv_JPD_PowerOff", "MDrv_JPD_PowerOn"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 8, "symbol_examples": ["HAL_JPD_Get_M_Config", "HAL_JPD_Get_S_Config", "HAL_JPD_Set_M_Config", "HAL_JPD_Set_S_Config", "MDrv_JPD_Get_M_Config", "MDrv_JPD_Get_S_Config", "MDrv_JPD_Set_M_Config", "MDrv_JPD_Set_S_Config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 17 / 109.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 132; semboller: 386.
- Xref: 1437; analizde call tipli xref: 0.
- Computed-call instruction: 297 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/201d3dcc2c1a81a4f33b345439da7d00456c5903d5e6b4101bb5165661e9a4ed/functions.jsonl) · [Xref](../../../analiz/native/system-modules/201d3dcc2c1a81a4f33b345439da7d00456c5903d5e6b4101bb5165661e9a4ed/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/201d3dcc2c1a81a4f33b345439da7d00456c5903d5e6b4101bb5165661e9a4ed/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/201d3dcc2c1a81a4f33b345439da7d00456c5903d5e6b4101bb5165661e9a4ed/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00013318` | `OSAL_JPD_MutexDelete` | [C](../../../analiz/native/system-modules/201d3dcc2c1a81a4f33b345439da7d00456c5903d5e6b4101bb5165661e9a4ed/00013318.c) |
| `0001334c` | `OSAL_JPD_MutexRelease` | [C](../../../analiz/native/system-modules/201d3dcc2c1a81a4f33b345439da7d00456c5903d5e6b4101bb5165661e9a4ed/0001334c.c) |
| `00013380` | `OSAL_JPD_MutexObtain` | [C](../../../analiz/native/system-modules/201d3dcc2c1a81a4f33b345439da7d00456c5903d5e6b4101bb5165661e9a4ed/00013380.c) |
| `00012b08` | `MDrv_JPD_PowerOff` | [C](../../../analiz/native/system-modules/201d3dcc2c1a81a4f33b345439da7d00456c5903d5e6b4101bb5165661e9a4ed/00012b08.c) |
| `000133b4` | `OSAL_JPD_MutexCreate` | [C](../../../analiz/native/system-modules/201d3dcc2c1a81a4f33b345439da7d00456c5903d5e6b4101bb5165661e9a4ed/000133b4.c) |
| `00012b44` | `MDrv_JPD_PowerOn` | [C](../../../analiz/native/system-modules/201d3dcc2c1a81a4f33b345439da7d00456c5903d5e6b4101bb5165661e9a4ed/00012b44.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
