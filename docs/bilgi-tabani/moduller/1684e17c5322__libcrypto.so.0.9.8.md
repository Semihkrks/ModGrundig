# `07_MSLIB/libcrypto.so.0.9.8`

SHA-256: `1684e17c532291d547f5ab47ec76be30911fdde1f352e6903c66b2693e3ae8f4`

Durum: **Ghidra indeks tamam; analiz süre sınırlı**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 1859609 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 5, "symbol_examples": ["i2s_ASN1_ENUMERATED", "i2s_ASN1_ENUMERATED_TABLE", "i2s_ASN1_IA5STRING", "i2s_ASN1_INTEGER", "i2s_ASN1_OCTET_STRING"], "examples_are_complete": true}, {"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["e_rc5.c"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["CONF_get1_default_config_file", "OPENSSL_config", "OPENSSL_no_config", "openssl_configured"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libdl.so.2`, `libc.so.6`
- Dynamic import/export: 101 / 3311.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 3820; semboller: 21802.
- Xref: 83062; analizde call tipli xref: 0.
- Computed-call instruction: 14259 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: True.

[Fonksiyonlar](../../../analiz/native/system-modules/1684e17c532291d547f5ab47ec76be30911fdde1f352e6903c66b2693e3ae8f4/functions.jsonl) · [Xref](../../../analiz/native/system-modules/1684e17c532291d547f5ab47ec76be30911fdde1f352e6903c66b2693e3ae8f4/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/1684e17c532291d547f5ab47ec76be30911fdde1f352e6903c66b2693e3ae8f4/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/1684e17c532291d547f5ab47ec76be30911fdde1f352e6903c66b2693e3ae8f4/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2d80afa8` | `ec_GFp_simple_is_at_infinity` | [C](../../../analiz/native/system-modules/1684e17c532291d547f5ab47ec76be30911fdde1f352e6903c66b2693e3ae8f4/2d80afa8.c) |
| `2d817a18` | `ec_GF2m_simple_is_at_infinity` | [C](../../../analiz/native/system-modules/1684e17c532291d547f5ab47ec76be30911fdde1f352e6903c66b2693e3ae8f4/2d817a18.c) |
| `2d82bd14` | `ENGINE_set_init_function` | [C](../../../analiz/native/system-modules/1684e17c532291d547f5ab47ec76be30911fdde1f352e6903c66b2693e3ae8f4/2d82bd14.c) |
| `2d8bfb60` | `STORE_method_set_initialise_function` | [C](../../../analiz/native/system-modules/1684e17c532291d547f5ab47ec76be30911fdde1f352e6903c66b2693e3ae8f4/2d8bfb60.c) |
| `2d8bfbe4` | `STORE_method_set_update_store_function` | [C](../../../analiz/native/system-modules/1684e17c532291d547f5ab47ec76be30911fdde1f352e6903c66b2693e3ae8f4/2d8bfbe4.c) |
| `2d825960` | `DSA_do_verify` | [C](../../../analiz/native/system-modules/1684e17c532291d547f5ab47ec76be30911fdde1f352e6903c66b2693e3ae8f4/2d825960.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
