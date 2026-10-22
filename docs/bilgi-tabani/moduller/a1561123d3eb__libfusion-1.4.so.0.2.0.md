# `07_MSLIB/libfusion-1.4.so.0.2.0`

SHA-256: `a1561123d3ebfb1695d4263ff1b30c87e68cbb593cf56f74aecf770b8f14e5b7`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 109612 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["FUN___mst_directfb_data_pool_size", "FUN___mst_directfb_main_pool_size"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 11, "symbol_examples": ["CreateFusionConfigHashTable", "FusionConfigTable", "SearchFusionConfigHashTable", "direct_config", "direct_config_destroy", "direct_config_set", "fusion_config", "fusion_config_destroy", "fusion_config_init", "fusion_config_set", "fusion_config_usage"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libz.so.1`, `libm.so.6`, `libdirect-1.4.so.0`, `libdl.so.2`, `librt.so.1`, `libpthread.so.0`, `libdrvMVOP.so`, `libapiGFX.so`, `libapiGOP.so`, `liblinux.so`, `libdrvVE.so`, `libapiXC.so`, `libapiPNL.so`, `libdrvWDT.so`, `libdrvSAR.so`, `libapiVDEC.so`, `libdrvIPAUTH.so`, `libapiJPEG.so`, `libc.so.6`
- Dynamic import/export: 88 / 160.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 237; semboller: 1826.
- Xref: 5964; analizde call tipli xref: 0.
- Computed-call instruction: 1208 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/a1561123d3ebfb1695d4263ff1b30c87e68cbb593cf56f74aecf770b8f14e5b7/functions.jsonl) · [Xref](../../../analiz/native/system-modules/a1561123d3ebfb1695d4263ff1b30c87e68cbb593cf56f74aecf770b8f14e5b7/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/a1561123d3ebfb1695d4263ff1b30c87e68cbb593cf56f74aecf770b8f14e5b7/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/a1561123d3ebfb1695d4263ff1b30c87e68cbb593cf56f74aecf770b8f14e5b7/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f13ff20` | `fusion_vector_init` | [C](../../../analiz/native/system-modules/a1561123d3ebfb1695d4263ff1b30c87e68cbb593cf56f74aecf770b8f14e5b7/2f13ff20.c) |
| `2f132eec` | `_init` | [C](../../../analiz/native/system-modules/a1561123d3ebfb1695d4263ff1b30c87e68cbb593cf56f74aecf770b8f14e5b7/2f132eec.c) |
| `2f135868` | `fusion_config_init` | [C](../../../analiz/native/system-modules/a1561123d3ebfb1695d4263ff1b30c87e68cbb593cf56f74aecf770b8f14e5b7/2f135868.c) |
| `2f13bed4` | `fusion_property_init` | [C](../../../analiz/native/system-modules/a1561123d3ebfb1695d4263ff1b30c87e68cbb593cf56f74aecf770b8f14e5b7/2f13bed4.c) |
| `2f13a420` | `fusion_skirmish_init` | [C](../../../analiz/native/system-modules/a1561123d3ebfb1695d4263ff1b30c87e68cbb593cf56f74aecf770b8f14e5b7/2f13a420.c) |
| `2f134338` | `fusion_call_init` | [C](../../../analiz/native/system-modules/a1561123d3ebfb1695d4263ff1b30c87e68cbb593cf56f74aecf770b8f14e5b7/2f134338.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
