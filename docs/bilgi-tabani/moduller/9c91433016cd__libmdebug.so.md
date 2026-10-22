# `07_MSLIB/libmdebug.so`

SHA-256: `9c91433016cdcdc977779918e215dfdec7f0703653bc5c82799188895859216f`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 79416 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["_Z19ReadDecimalKeyInputPKc"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 3, "symbol_examples": ["_Z22Mdebug_UtopiaACEConfigv", "_Z22Mdebug_UtopiaCECConfigv", "_Z25Mdebug_UtopiaHDMITXConfigv"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 34, "symbol_examples": ["_Z21Mdebug_HardwareConfigv", "_Z21Mdebug_SoftwareConfigv", "_Z21Mdebug_UtopiaPMConfigv", "_Z21Mdebug_UtopiaSCConfigv", "_Z21Mdebug_UtopiaVEConfigv", "_Z21Mdebug_UtopiaXCConfigv", "_Z22Mdebug_UtopiaACEConfigv", "_Z22Mdebug_UtopiaAVDConfigv", "_Z22Mdebug_UtopiaCECConfigv", "_Z22Mdebug_UtopiaCPUConfigv", "_Z22Mdebug_UtopiaDACConfigv", "_Z22Mdebug_UtopiaDLCConfigv", "_Z22Mdebug_UtopiaDMXConfigv", "_Z22Mdebug_UtopiaGFXConfigv", "_Z22Mdebug_UtopiaGOPConfigv", "_Z22Mdebug_UtopiaMBXConfigv"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libpthread.so.0`, `libc.so.6`
- Dynamic import/export: 53 / 64.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 146; semboller: 2287.
- Xref: 4916; analizde call tipli xref: 0.
- Computed-call instruction: 897 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 4/4.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/9c91433016cdcdc977779918e215dfdec7f0703653bc5c82799188895859216f/functions.jsonl) · [Xref](../../../analiz/native/system-modules/9c91433016cdcdc977779918e215dfdec7f0703653bc5c82799188895859216f/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/9c91433016cdcdc977779918e215dfdec7f0703653bc5c82799188895859216f/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/9c91433016cdcdc977779918e215dfdec7f0703653bc5c82799188895859216f/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00011840` | `_init` | [C](../../../analiz/native/system-modules/9c91433016cdcdc977779918e215dfdec7f0703653bc5c82799188895859216f/00011840.c) |
| `00012ca4` | `Mdebug_UtopiaACEConfig` | [C](../../../analiz/native/system-modules/9c91433016cdcdc977779918e215dfdec7f0703653bc5c82799188895859216f/00012ca4.c) |
| `00013d84` | `Mdebug_UtopiaCECConfig` | [C](../../../analiz/native/system-modules/9c91433016cdcdc977779918e215dfdec7f0703653bc5c82799188895859216f/00013d84.c) |
| `00015ac4` | `Mdebug_UtopiaFLASHConfig` | [C](../../../analiz/native/system-modules/9c91433016cdcdc977779918e215dfdec7f0703653bc5c82799188895859216f/00015ac4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
