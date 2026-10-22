# `07_MSLIB/utopia/libapiSWI2C.so`

SHA-256: `2346863a6c5d34edace7c0c52a4d59dafa9484bfb4b31b293d75096256ed1936`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 19000 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MApi_SWI2C_SetPowerState"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MApi_SWI2C_Speed_Setting"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 13 / 41.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 53; semboller: 311.
- Xref: 1088; analizde call tipli xref: 0.
- Computed-call instruction: 174 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 5/5.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/2346863a6c5d34edace7c0c52a4d59dafa9484bfb4b31b293d75096256ed1936/functions.jsonl) · [Xref](../../../analiz/native/system-modules/2346863a6c5d34edace7c0c52a4d59dafa9484bfb4b31b293d75096256ed1936/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/2346863a6c5d34edace7c0c52a4d59dafa9484bfb4b31b293d75096256ed1936/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/2346863a6c5d34edace7c0c52a4d59dafa9484bfb4b31b293d75096256ed1936/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f321ef8` | `MApi_SWI2C_MutexUnlock` | [C](../../../analiz/native/system-modules/2346863a6c5d34edace7c0c52a4d59dafa9484bfb4b31b293d75096256ed1936/2f321ef8.c) |
| `2f321e3c` | `MApi_SWI2C_MutexLock` | [C](../../../analiz/native/system-modules/2346863a6c5d34edace7c0c52a4d59dafa9484bfb4b31b293d75096256ed1936/2f321e3c.c) |
| `2f320b74` | `_init` | [C](../../../analiz/native/system-modules/2346863a6c5d34edace7c0c52a4d59dafa9484bfb4b31b293d75096256ed1936/2f320b74.c) |
| `2f323584` | `MApi_SWI2C_SetPowerState` | [C](../../../analiz/native/system-modules/2346863a6c5d34edace7c0c52a4d59dafa9484bfb4b31b293d75096256ed1936/2f323584.c) |
| `2f3232e4` | `MApi_SWI2C_Init` | [C](../../../analiz/native/system-modules/2346863a6c5d34edace7c0c52a4d59dafa9484bfb4b31b293d75096256ed1936/2f3232e4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
