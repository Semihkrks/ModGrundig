# `09_CONFIG/libdfbinfo.so`

SHA-256: `1ff1dbcc1ed129311807f062b5670245e58df51271dd513f15713de67e00ae0e`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 25468 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 3, "symbol_examples": ["GetKeypadChInfo", "KeycodeMappingTable", "_Z28GetDFBKeycodeByUtopiaKeycodei"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["GetIRPowerupKey", "_Z16SetIRPowerupKeysv"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["DirectFBSetOption", "_Z14ExtendBootlogov"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 6, "symbol_examples": ["iniparser_freedict", "iniparser_getboolean", "iniparser_getint", "iniparser_getstring", "iniparser_getunsignedint", "iniparser_load"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libdirectfb-1.4.so.0`, `libdrvSAR.so`, `liblinux.so`, `libdrvSERFLASH.so`, `libMMAPInfo.so`, `libiniparser.so`, `libstdc++.so.6`, `libc.so.6`
- Dynamic import/export: 46 / 35.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 72; semboller: 340.
- Xref: 895; analizde call tipli xref: 0.
- Computed-call instruction: 335 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/1ff1dbcc1ed129311807f062b5670245e58df51271dd513f15713de67e00ae0e/functions.jsonl) · [Xref](../../../analiz/native/system-modules/1ff1dbcc1ed129311807f062b5670245e58df51271dd513f15713de67e00ae0e/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/1ff1dbcc1ed129311807f062b5670245e58df51271dd513f15713de67e00ae0e/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/1ff1dbcc1ed129311807f062b5670245e58df51271dd513f15713de67e00ae0e/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f6c136c` | `GetIRPowerupKey` | [C](../../../analiz/native/system-modules/1ff1dbcc1ed129311807f062b5670245e58df51271dd513f15713de67e00ae0e/2f6c136c.c) |
| `2f6c1144` | `_init` | [C](../../../analiz/native/system-modules/1ff1dbcc1ed129311807f062b5670245e58df51271dd513f15713de67e00ae0e/2f6c1144.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
