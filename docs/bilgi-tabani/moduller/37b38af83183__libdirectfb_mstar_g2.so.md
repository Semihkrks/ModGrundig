# `07_MSLIB/directfb-1.4-0/gfxdrivers/libdirectfb_mstar_g2.so`

SHA-256: `37b38af83183ebc3c5f0bbfa005e108578a3d3940df7a70842940fb1a640172e`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 160720 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 8, "symbol_examples": ["MApi_GFX_BeginDraw", "MApi_GFX_DrawLine", "MApi_GFX_DrawOval", "MApi_GFX_EndDraw", "MApi_GOP_RegisterXCReduceBWForOSDCB", "MApi_GOP_Set3DOSDMode", "MApi_XC_OSDC_GetDstInfo", "MApi_XC_SetOSDBlendingFormula"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 5, "symbol_examples": ["MApi_GOP_SetConfig", "MApi_GOP_SetConfigEx", "dfb_config", "dfb_surface_reconfig", "direct_config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libz.so.1`, `libm.so.6`, `libdirect-1.4.so.0`, `libdirectfb-1.4.so.0`, `libfusion-1.4.so.0`, `libdl.so.2`, `librt.so.1`, `libpthread.so.0`, `libdrvMVOP.so`, `libapiGFX.so`, `libapiGOP.so`, `liblinux.so`, `libdrvVE.so`, `libapiXC.so`, `libapiPNL.so`, `libdrvWDT.so`, `libdrvSAR.so`, `libapiVDEC.so`, `libdrvIPAUTH.so`, `libapiJPEG.so`, `libc.so.6`
- Dynamic import/export: 192 / 11.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 393; semboller: 2096.
- Xref: 2703; analizde call tipli xref: 0.
- Computed-call instruction: 1134 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/37b38af83183ebc3c5f0bbfa005e108578a3d3940df7a70842940fb1a640172e/functions.jsonl) · [Xref](../../../analiz/native/system-modules/37b38af83183ebc3c5f0bbfa005e108578a3d3940df7a70842940fb1a640172e/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/37b38af83183ebc3c5f0bbfa005e108578a3d3940df7a70842940fb1a640172e/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/37b38af83183ebc3c5f0bbfa005e108578a3d3940df7a70842940fb1a640172e/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00012d20` | `_init` | [C](../../../analiz/native/system-modules/37b38af83183ebc3c5f0bbfa005e108578a3d3940df7a70842940fb1a640172e/00012d20.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
