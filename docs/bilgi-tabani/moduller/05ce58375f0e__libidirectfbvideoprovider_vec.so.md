# `07_MSLIB/directfb-1.4-0/interfaces/IDirectFBVideoProvider/libidirectfbvideoprovider_vec.so`

SHA-256: `05ce58375f0e7a41ef6108524ef2ae7a47dbd0663b966652f67d6383dbebcf69`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 23312 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MDrv_VE_SwitchInputSource"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 0, "symbol_examples": [], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["direct_config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libz.so.1`, `libm.so.6`, `libdirect-1.4.so.0`, `libfusion-1.4.so.0`, `libdirectfb-1.4.so.0`, `libdl.so.2`, `librt.so.1`, `libpthread.so.0`, `libdrvMVOP.so`, `libapiGFX.so`, `libapiGOP.so`, `liblinux.so`, `libdrvVE.so`, `libapiXC.so`, `libapiPNL.so`, `libdrvWDT.so`, `libdrvSAR.so`, `libapiVDEC.so`, `libdrvIPAUTH.so`, `libapiJPEG.so`, `libc.so.6`
- Dynamic import/export: 58 / 11.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 106; semboller: 270.
- Xref: 345; analizde call tipli xref: 0.
- Computed-call instruction: 96 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/05ce58375f0e7a41ef6108524ef2ae7a47dbd0663b966652f67d6383dbebcf69/functions.jsonl) · [Xref](../../../analiz/native/system-modules/05ce58375f0e7a41ef6108524ef2ae7a47dbd0663b966652f67d6383dbebcf69/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/05ce58375f0e7a41ef6108524ef2ae7a47dbd0663b966652f67d6383dbebcf69/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/05ce58375f0e7a41ef6108524ef2ae7a47dbd0663b966652f67d6383dbebcf69/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010ff0` | `_init` | [C](../../../analiz/native/system-modules/05ce58375f0e7a41ef6108524ef2ae7a47dbd0663b966652f67d6383dbebcf69/00010ff0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
