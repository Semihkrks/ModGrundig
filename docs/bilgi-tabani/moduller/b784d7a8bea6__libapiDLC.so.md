# `07_MSLIB/utopia/libapiDLC.so`

SHA-256: `b784d7a8bea6747746365f54e012a4247ce0d0cc4ff3d61de908c47ee622b1d9`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 84168 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["MApi_XC_DLC_SetPowerState", "MApi_XC_DLC_SetPowerState_U2"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 6, "symbol_examples": ["UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["MApi_XC_DLC_SetSetting", "MApi_XC_DLC_SetSetting_Ex", "MApi_XC_DLC_SetSetting_Ex_U2", "MApi_XC_DLC_SetSetting_U2"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 28 / 260.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 223; semboller: 1013.
- Xref: 3390; analizde call tipli xref: 0.
- Computed-call instruction: 501 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/b784d7a8bea6747746365f54e012a4247ce0d0cc4ff3d61de908c47ee622b1d9/functions.jsonl) · [Xref](../../../analiz/native/system-modules/b784d7a8bea6747746365f54e012a4247ce0d0cc4ff3d61de908c47ee622b1d9/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/b784d7a8bea6747746365f54e012a4247ce0d0cc4ff3d61de908c47ee622b1d9/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/b784d7a8bea6747746365f54e012a4247ce0d0cc4ff3d61de908c47ee622b1d9/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2eef39d4` | `MDrv_DLC_DBC_UpdatePWM` | [C](../../../analiz/native/system-modules/b784d7a8bea6747746365f54e012a4247ce0d0cc4ff3d61de908c47ee622b1d9/2eef39d4.c) |
| `2eef4878` | `Hal_DLC_init_riu_base` | [C](../../../analiz/native/system-modules/b784d7a8bea6747746365f54e012a4247ce0d0cc4ff3d61de908c47ee622b1d9/2eef4878.c) |
| `2eef3f54` | `MDrv_DLC_init_riu_base` | [C](../../../analiz/native/system-modules/b784d7a8bea6747746365f54e012a4247ce0d0cc4ff3d61de908c47ee622b1d9/2eef3f54.c) |
| `2eef435c` | `MDrv_DLC_CGC_ReInit` | [C](../../../analiz/native/system-modules/b784d7a8bea6747746365f54e012a4247ce0d0cc4ff3d61de908c47ee622b1d9/2eef435c.c) |
| `2eef4390` | `MDrv_DLC_CGC_Init` | [C](../../../analiz/native/system-modules/b784d7a8bea6747746365f54e012a4247ce0d0cc4ff3d61de908c47ee622b1d9/2eef4390.c) |
| `2eefddf0` | `MApi_XC_DLC_DBC_UpdatePWM_U2` | [C](../../../analiz/native/system-modules/b784d7a8bea6747746365f54e012a4247ce0d0cc4ff3d61de908c47ee622b1d9/2eefddf0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
