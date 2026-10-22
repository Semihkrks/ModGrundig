# `07_MSLIB/directfb-1.4-0/interfaces/IDirectFBFont/libidirectfbfont_dgiff.so`

SHA-256: `46ba59dea652780c04484dabbb834e61c02f1f3455166323de67ae8bac1baa91`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 8908 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 4, "symbol_examples": ["IDirectFBFont_Construct", "IDirectFBFont_Destruct", "dfb_font_create", "dfb_font_destroy"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["direct_config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libz.so.1`, `libm.so.6`, `libdirect-1.4.so.0`, `libfusion-1.4.so.0`, `libdirectfb-1.4.so.0`, `libdl.so.2`, `librt.so.1`, `libpthread.so.0`, `libdrvMVOP.so`, `libapiGFX.so`, `libapiGOP.so`, `liblinux.so`, `libdrvVE.so`, `libapiXC.so`, `libapiPNL.so`, `libdrvWDT.so`, `libdrvSAR.so`, `libapiVDEC.so`, `libdrvIPAUTH.so`, `libapiJPEG.so`, `libc.so.6`
- Dynamic import/export: 29 / 11.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 61; semboller: 179.
- Xref: 303; analizde call tipli xref: 0.
- Computed-call instruction: 78 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/46ba59dea652780c04484dabbb834e61c02f1f3455166323de67ae8bac1baa91/functions.jsonl) · [Xref](../../../analiz/native/system-modules/46ba59dea652780c04484dabbb834e61c02f1f3455166323de67ae8bac1baa91/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/46ba59dea652780c04484dabbb834e61c02f1f3455166323de67ae8bac1baa91/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/46ba59dea652780c04484dabbb834e61c02f1f3455166323de67ae8bac1baa91/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010ac0` | `_init` | [C](../../../analiz/native/system-modules/46ba59dea652780c04484dabbb834e61c02f1f3455166323de67ae8bac1baa91/00010ac0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
