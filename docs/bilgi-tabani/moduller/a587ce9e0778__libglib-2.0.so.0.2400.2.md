# `07_MSLIB/libglib-2.0.so.0.2400.2`

SHA-256: `a587ce9e0778b51e41bef75c29f58824548f28e2c9f9db014b0930f873e0b1c9`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 1287184 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["g_main_context_wakeup"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 6, "symbol_examples": ["g_get_system_config_dirs", "g_get_user_config_dir", "g_slice_get_config", "g_slice_get_config_state", "g_slice_set_config", "g_test_config_vars"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 149 / 1338.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 1784; semboller: 13368.
- Xref: 45105; analizde call tipli xref: 0.
- Computed-call instruction: 7767 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/a587ce9e0778b51e41bef75c29f58824548f28e2c9f9db014b0930f873e0b1c9/functions.jsonl) · [Xref](../../../analiz/native/system-modules/a587ce9e0778b51e41bef75c29f58824548f28e2c9f9db014b0930f873e0b1c9/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/a587ce9e0778b51e41bef75c29f58824548f28e2c9f9db014b0930f873e0b1c9/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/a587ce9e0778b51e41bef75c29f58824548f28e2c9f9db014b0930f873e0b1c9/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00094240` | `g_thread_get_initialized` | [C](../../../analiz/native/system-modules/a587ce9e0778b51e41bef75c29f58824548f28e2c9f9db014b0930f873e0b1c9/00094240.c) |
| `00049dcc` | `g_io_channel_error_quark` | [C](../../../analiz/native/system-modules/a587ce9e0778b51e41bef75c29f58824548f28e2c9f9db014b0930f873e0b1c9/00049dcc.c) |
| `000a92b0` | `g_bit_storage` | [C](../../../analiz/native/system-modules/a587ce9e0778b51e41bef75c29f58824548f28e2c9f9db014b0930f873e0b1c9/000a92b0.c) |
| `00039c78` | `g_datalist_init` | [C](../../../analiz/native/system-modules/a587ce9e0778b51e41bef75c29f58824548f28e2c9f9db014b0930f873e0b1c9/00039c78.c) |
| `00094674` | `g_static_rec_mutex_free` | [C](../../../analiz/native/system-modules/a587ce9e0778b51e41bef75c29f58824548f28e2c9f9db014b0930f873e0b1c9/00094674.c) |
| `000946b0` | `g_static_mutex_init` | [C](../../../analiz/native/system-modules/a587ce9e0778b51e41bef75c29f58824548f28e2c9f9db014b0930f873e0b1c9/000946b0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
