# `07_MSLIB/directfb-1.4-0/interfaces/IDirectFBFont/libidirectfbfont_ft2.so`

SHA-256: `14477cfc672d22acab00108d0e23323e9f5f3146b71e43862a80d192a5a9d615`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 23968 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 4, "symbol_examples": ["IDirectFBFont_Construct", "IDirectFBFont_Destruct", "dfb_font_create", "dfb_font_register_encoding"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["dfb_config", "direct_config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libm.so.6`, `libdirect-1.4.so.0`, `libdirectfb-1.4.so.0`, `libfreetype.so.6`, `libz.so.1`, `libdl.so.2`, `librt.so.1`, `libpthread.so.0`, `libdrvMVOP.so`, `libapiGFX.so`, `libapiGOP.so`, `liblinux.so`, `libdrvVE.so`, `libapiXC.so`, `libapiPNL.so`, `libdrvWDT.so`, `libdrvSAR.so`, `libapiVDEC.so`, `libdrvIPAUTH.so`, `libapiJPEG.so`, `libc.so.6`
- Dynamic import/export: 42 / 11.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 85; semboller: 310.
- Xref: 406; analizde call tipli xref: 0.
- Computed-call instruction: 135 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/14477cfc672d22acab00108d0e23323e9f5f3146b71e43862a80d192a5a9d615/functions.jsonl) · [Xref](../../../analiz/native/system-modules/14477cfc672d22acab00108d0e23323e9f5f3146b71e43862a80d192a5a9d615/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/14477cfc672d22acab00108d0e23323e9f5f3146b71e43862a80d192a5a9d615/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/14477cfc672d22acab00108d0e23323e9f5f3146b71e43862a80d192a5a9d615/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010d28` | `_init` | [C](../../../analiz/native/system-modules/14477cfc672d22acab00108d0e23323e9f5f3146b71e43862a80d192a5a9d615/00010d28.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
