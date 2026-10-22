# `06_RFS/lib/libdbus-1.so.3.4.0`

SHA-256: `d788e9d3d05b8b5ac941ad0e52feabe51735c4c096cd0ecf387ffc69a6ef6e4e`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 365432 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["dbus_connection_set_wakeup_main_function"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["dbus_connection_get_windows_user", "dbus_connection_set_windows_user_function"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 91 / 216.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 1209; semboller: 4260.
- Xref: 30845; analizde call tipli xref: 0.
- Computed-call instruction: 4032 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/d788e9d3d05b8b5ac941ad0e52feabe51735c4c096cd0ecf387ffc69a6ef6e4e/functions.jsonl) · [Xref](../../../analiz/native/system-modules/d788e9d3d05b8b5ac941ad0e52feabe51735c4c096cd0ecf387ffc69a6ef6e4e/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/d788e9d3d05b8b5ac941ad0e52feabe51735c4c096cd0ecf387ffc69a6ef6e4e/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/d788e9d3d05b8b5ac941ad0e52feabe51735c4c096cd0ecf387ffc69a6ef6e4e/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `0004799c` | `dbus_watch_get_socket` | [C](../../../analiz/native/system-modules/d788e9d3d05b8b5ac941ad0e52feabe51735c4c096cd0ecf387ffc69a6ef6e4e/0004799c.c) |
| `00041d70` | `dbus_threads_init_default` | [C](../../../analiz/native/system-modules/d788e9d3d05b8b5ac941ad0e52feabe51735c4c096cd0ecf387ffc69a6ef6e4e/00041d70.c) |
| `000262a0` | `dbus_error_init` | [C](../../../analiz/native/system-modules/d788e9d3d05b8b5ac941ad0e52feabe51735c4c096cd0ecf387ffc69a6ef6e4e/000262a0.c) |
| `0003f9a0` | `dbus_signature_iter_init` | [C](../../../analiz/native/system-modules/d788e9d3d05b8b5ac941ad0e52feabe51735c4c096cd0ecf387ffc69a6ef6e4e/0003f9a0.c) |
| `0003fa00` | `dbus_signature_iter_get_current_type` | [C](../../../analiz/native/system-modules/d788e9d3d05b8b5ac941ad0e52feabe51735c4c096cd0ecf387ffc69a6ef6e4e/0003fa00.c) |
| `0003fb88` | `dbus_signature_iter_get_element_type` | [C](../../../analiz/native/system-modules/d788e9d3d05b8b5ac941ad0e52feabe51735c4c096cd0ecf387ffc69a6ef6e4e/0003fb88.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
