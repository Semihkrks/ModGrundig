# `07_MSLIB/directfb-1.4-0/inputdrivers/libdirectfb_mstar_loopback_input.so`

SHA-256: `b7016485669935fff623d0228fb3d510b2171cca0c25f3957e2605e3d668a6c6`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 7604 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 0, "symbol_examples": [], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["dfb_config", "direct_config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libz.so.1`, `libm.so.6`, `libdirect-1.4.so.0`, `libdirectfb-1.4.so.0`, `libdl.so.2`, `librt.so.1`, `libpthread.so.0`, `libdrvMVOP.so`, `libapiGFX.so`, `libapiGOP.so`, `liblinux.so`, `libdrvVE.so`, `libapiXC.so`, `libapiPNL.so`, `libdrvWDT.so`, `libdrvSAR.so`, `libapiVDEC.so`, `libdrvIPAUTH.so`, `libapiJPEG.so`, `libc.so.6`
- Dynamic import/export: 17 / 11.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 31; semboller: 139.
- Xref: 160; analizde call tipli xref: 0.
- Computed-call instruction: 40 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/b7016485669935fff623d0228fb3d510b2171cca0c25f3957e2605e3d668a6c6/functions.jsonl) · [Xref](../../../analiz/native/system-modules/b7016485669935fff623d0228fb3d510b2171cca0c25f3957e2605e3d668a6c6/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/b7016485669935fff623d0228fb3d510b2171cca0c25f3957e2605e3d668a6c6/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/b7016485669935fff623d0228fb3d510b2171cca0c25f3957e2605e3d668a6c6/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `000108a8` | `_init` | [C](../../../analiz/native/system-modules/b7016485669935fff623d0228fb3d510b2171cca0c25f3957e2605e3d668a6c6/000108a8.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
