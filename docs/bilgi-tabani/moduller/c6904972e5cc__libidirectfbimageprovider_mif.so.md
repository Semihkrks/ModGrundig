# `07_MSLIB/directfb-1.4-0/interfaces/IDirectFBImageProvider/libidirectfbimageprovider_mif.so`

SHA-256: `c6904972e5cc834a20859dcd92d2c19d21954791ab36a8f2d64db2c98ee18646`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 11312 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 1, "symbol_examples": ["idirectfb_singleton"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["direct_config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libz.so.1`, `libm.so.6`, `libdirect-1.4.so.0`, `libdirectfb-1.4.so.0`, `libdl.so.2`, `librt.so.1`, `libpthread.so.0`, `libdrvMVOP.so`, `libapiGFX.so`, `libapiGOP.so`, `liblinux.so`, `libdrvVE.so`, `libapiXC.so`, `libapiPNL.so`, `libdrvWDT.so`, `libdrvSAR.so`, `libapiVDEC.so`, `libdrvIPAUTH.so`, `libapiJPEG.so`, `libc.so.6`
- Dynamic import/export: 26 / 11.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 49; semboller: 137.
- Xref: 179; analizde call tipli xref: 0.
- Computed-call instruction: 44 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/c6904972e5cc834a20859dcd92d2c19d21954791ab36a8f2d64db2c98ee18646/functions.jsonl) · [Xref](../../../analiz/native/system-modules/c6904972e5cc834a20859dcd92d2c19d21954791ab36a8f2d64db2c98ee18646/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/c6904972e5cc834a20859dcd92d2c19d21954791ab36a8f2d64db2c98ee18646/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/c6904972e5cc834a20859dcd92d2c19d21954791ab36a8f2d64db2c98ee18646/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010a2c` | `_init` | [C](../../../analiz/native/system-modules/c6904972e5cc834a20859dcd92d2c19d21954791ab36a8f2d64db2c98ee18646/00010a2c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
