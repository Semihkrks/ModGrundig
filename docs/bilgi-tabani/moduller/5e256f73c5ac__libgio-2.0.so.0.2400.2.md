# `07_MSLIB/libgio-2.0.so.0.2400.2`

SHA-256: `5e256f73c5ac3920e335bc30d91fa0bd9b19edd83efde32eac272e2dd9ac8129`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 902860 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 33, "symbol_examples": ["IA__g_volume_monitor_get_type", "g_drive_get_volumes", "g_drive_has_volumes", "g_file_mount_enclosing_volume", "g_file_mount_enclosing_volume_finish", "g_mount_get_volume", "g_native_volume_monitor_get_type", "g_volume_can_eject", "g_volume_can_mount", "g_volume_eject", "g_volume_eject_finish", "g_volume_eject_with_operation", "g_volume_eject_with_operation_finish", "g_volume_enumerate_identifiers", "g_volume_get_activation_root", "g_volume_get_drive"], "examples_are_complete": false}, {"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["g_socket_connection_get_remote_address", "g_socket_get_remote_address"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["g_main_context_wakeup"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 7, "symbol_examples": ["g_themed_icon_append_name", "g_themed_icon_get_names", "g_themed_icon_get_type", "g_themed_icon_new", "g_themed_icon_new_from_names", "g_themed_icon_new_with_default_fallbacks", "g_themed_icon_prepend_name"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libgobject-2.0.so.0`, `libgthread-2.0.so.0`, `libpthread.so.0`, `librt.so.1`, `libgmodule-2.0.so.0`, `libdl.so.2`, `libglib-2.0.so.0`, `libresolv.so.2`, `libz.so.1`, `libc.so.6`
- Dynamic import/export: 500 / 876.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 2373; semboller: 10267.
- Xref: 40582; analizde call tipli xref: 0.
- Computed-call instruction: 10275 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/5e256f73c5ac3920e335bc30d91fa0bd9b19edd83efde32eac272e2dd9ac8129/functions.jsonl) · [Xref](../../../analiz/native/system-modules/5e256f73c5ac3920e335bc30d91fa0bd9b19edd83efde32eac272e2dd9ac8129/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/5e256f73c5ac3920e335bc30d91fa0bd9b19edd83efde32eac272e2dd9ac8129/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/5e256f73c5ac3920e335bc30d91fa0bd9b19edd83efde32eac272e2dd9ac8129/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00080260` | `g_socket_client_get_family` | [C](../../../analiz/native/system-modules/5e256f73c5ac3920e335bc30d91fa0bd9b19edd83efde32eac272e2dd9ac8129/00080260.c) |
| `0008026c` | `g_socket_client_get_socket_type` | [C](../../../analiz/native/system-modules/5e256f73c5ac3920e335bc30d91fa0bd9b19edd83efde32eac272e2dd9ac8129/0008026c.c) |
| `00080278` | `g_socket_client_get_protocol` | [C](../../../analiz/native/system-modules/5e256f73c5ac3920e335bc30d91fa0bd9b19edd83efde32eac272e2dd9ac8129/00080278.c) |
| `00080284` | `g_socket_client_get_local_address` | [C](../../../analiz/native/system-modules/5e256f73c5ac3920e335bc30d91fa0bd9b19edd83efde32eac272e2dd9ac8129/00080284.c) |
| `0009ec30` | `g_unix_socket_address_get_path_len` | [C](../../../analiz/native/system-modules/5e256f73c5ac3920e335bc30d91fa0bd9b19edd83efde32eac272e2dd9ac8129/0009ec30.c) |
| `0009ec3c` | `g_unix_socket_address_get_is_abstract` | [C](../../../analiz/native/system-modules/5e256f73c5ac3920e335bc30d91fa0bd9b19edd83efde32eac272e2dd9ac8129/0009ec3c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
