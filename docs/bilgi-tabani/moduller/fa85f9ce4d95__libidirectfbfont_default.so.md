# `07_MSLIB/directfb-1.4-0/interfaces/IDirectFBFont/libidirectfbfont_default.so`

SHA-256: `fa85f9ce4d95e75256531c6807dba42cb1a9d3527c8f7c10ce2453c668bf799e`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 27404 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 3, "symbol_examples": ["IDirectFBFont_Construct", "dfb_font_create", "dfb_font_destroy"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["direct_config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libz.so.1`, `libm.so.6`, `libdirect-1.4.so.0`, `libdirectfb-1.4.so.0`, `libdl.so.2`, `librt.so.1`, `libpthread.so.0`, `libdrvMVOP.so`, `libapiGFX.so`, `libapiGOP.so`, `liblinux.so`, `libdrvVE.so`, `libapiXC.so`, `libapiPNL.so`, `libdrvWDT.so`, `libdrvSAR.so`, `libapiVDEC.so`, `libdrvIPAUTH.so`, `libapiJPEG.so`, `libc.so.6`
- Dynamic import/export: 21 / 11.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 42; semboller: 184.
- Xref: 388; analizde call tipli xref: 0.
- Computed-call instruction: 51 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/fa85f9ce4d95e75256531c6807dba42cb1a9d3527c8f7c10ce2453c668bf799e/functions.jsonl) · [Xref](../../../analiz/native/system-modules/fa85f9ce4d95e75256531c6807dba42cb1a9d3527c8f7c10ce2453c668bf799e/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/fa85f9ce4d95e75256531c6807dba42cb1a9d3527c8f7c10ce2453c668bf799e/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/fa85f9ce4d95e75256531c6807dba42cb1a9d3527c8f7c10ce2453c668bf799e/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010948` | `_init` | [C](../../../analiz/native/system-modules/fa85f9ce4d95e75256531c6807dba42cb1a9d3527c8f7c10ce2453c668bf799e/00010948.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
