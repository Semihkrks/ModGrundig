# `07_MSLIB/libcurl.so.4.2.0`

SHA-256: `3d130aa1c25c7324d38fe33f34946212a87fc969b101be176a254fcee8bc13cb`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 418768 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 3, "symbol_examples": ["Curl_clone_ssl_config", "Curl_free_ssl_config", "Curl_ssl_config_matches"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `librt.so.1`, `libcares.so.2`, `libssl.so.0.9.8`, `libcrypto.so.0.9.8`, `libz.so.1`, `libpthread.so.0`, `libc.so.6`
- Dynamic import/export: 236 / 386.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 660; semboller: 5557.
- Xref: 16848; analizde call tipli xref: 0.
- Computed-call instruction: 2914 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/3d130aa1c25c7324d38fe33f34946212a87fc969b101be176a254fcee8bc13cb/functions.jsonl) · [Xref](../../../analiz/native/system-modules/3d130aa1c25c7324d38fe33f34946212a87fc969b101be176a254fcee8bc13cb/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/3d130aa1c25c7324d38fe33f34946212a87fc969b101be176a254fcee8bc13cb/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/3d130aa1c25c7324d38fe33f34946212a87fc969b101be176a254fcee8bc13cb/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2e7049fc` | `Curl_speedinit` | [C](../../../analiz/native/system-modules/3d130aa1c25c7324d38fe33f34946212a87fc969b101be176a254fcee8bc13cb/2e7049fc.c) |
| `2e717980` | `Curl_httpchunk_init` | [C](../../../analiz/native/system-modules/3d130aa1c25c7324d38fe33f34946212a87fc969b101be176a254fcee8bc13cb/2e717980.c) |
| `2e6ea970` | `Curl_FormInit` | [C](../../../analiz/native/system-modules/3d130aa1c25c7324d38fe33f34946212a87fc969b101be176a254fcee8bc13cb/2e6ea970.c) |
| `2e6ef5d0` | `Curl_add_buffer_init` | [C](../../../analiz/native/system-modules/3d130aa1c25c7324d38fe33f34946212a87fc969b101be176a254fcee8bc13cb/2e6ef5d0.c) |
| `2e732cb0` | `Curl_HMAC_update` | [C](../../../analiz/native/system-modules/3d130aa1c25c7324d38fe33f34946212a87fc969b101be176a254fcee8bc13cb/2e732cb0.c) |
| `2e726d60` | `Curl_ssl_init` | [C](../../../analiz/native/system-modules/3d130aa1c25c7324d38fe33f34946212a87fc969b101be176a254fcee8bc13cb/2e726d60.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
