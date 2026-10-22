# `07_MSLIB/directfb-1.4-0/interfaces/IDirectFBImageProvider/libidirectfbimageprovider_gopc.so`

SHA-256: `92a21a681901f54c670363eb4826abaff8447ced484f5e3a9c19d25b0ddc1c38`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 30296 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 6, "symbol_examples": ["MApi_GOP_DWIN_SetSourceSel", "MApi_XC_DIP_SetSourceInfo", "MApi_XC_DIP_SetSourceScanType", "MApi_XC_GetHdmiSyncMode", "MDrv_HDMI_Get_ColorFormat", "MDrv_HDMI_Get_Pixel_Repetition"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 5, "symbol_examples": ["MApi_XC_DIP_GetResource", "MApi_XC_DIP_ReleaseResource", "MApi_XC_DIP_SetWindow", "MApi_XC_GetCaptureWindow", "MApi_XC_GetDEWindow"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["dfb_config", "direct_config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libz.so.1`, `libm.so.6`, `libdirect-1.4.so.0`, `libdirectfb-1.4.so.0`, `libfusion-1.4.so.0`, `libdl.so.2`, `librt.so.1`, `libpthread.so.0`, `libdrvMVOP.so`, `libapiGFX.so`, `libapiGOP.so`, `liblinux.so`, `libdrvVE.so`, `libapiXC.so`, `libapiPNL.so`, `libdrvWDT.so`, `libdrvSAR.so`, `libapiVDEC.so`, `libdrvIPAUTH.so`, `libapiJPEG.so`, `libc.so.6`
- Dynamic import/export: 84 / 11.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 162; semboller: 376.
- Xref: 337; analizde call tipli xref: 0.
- Computed-call instruction: 167 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/92a21a681901f54c670363eb4826abaff8447ced484f5e3a9c19d25b0ddc1c38/functions.jsonl) · [Xref](../../../analiz/native/system-modules/92a21a681901f54c670363eb4826abaff8447ced484f5e3a9c19d25b0ddc1c38/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/92a21a681901f54c670363eb4826abaff8447ced484f5e3a9c19d25b0ddc1c38/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/92a21a681901f54c670363eb4826abaff8447ced484f5e3a9c19d25b0ddc1c38/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `000114d4` | `_init` | [C](../../../analiz/native/system-modules/92a21a681901f54c670363eb4826abaff8447ced484f5e3a9c19d25b0ddc1c38/000114d4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
