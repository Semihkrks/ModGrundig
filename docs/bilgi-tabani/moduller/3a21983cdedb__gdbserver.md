# `06_RFS/bin/gdbserver`

SHA-256: `3a21983cdedba4933f513becd0e89c037cec05cb33078a556c5a870a161c9ec7`

Durum: **Ghidra indeks tamam**.

Tür: EXEC (Executable file); ELF32 LE MIPS; 132764 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 8, "symbol_examples": ["/scratch/clm/2008q3-src/src/gdb-mips/gdb/gdbserver/remote-utils.c", "check_remote_input_interrupt_request", "remote_close", "remote_debug", "remote_desc", "remote_escape_output", "remote_open", "remote_unescape_input"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libthread_db.so.1`, `libc.so.6`
- Dynamic import/export: 84 / 189.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 289; semboller: 2071.
- Xref: 4935; analizde call tipli xref: 173.
- Computed-call instruction: 850 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/3a21983cdedba4933f513becd0e89c037cec05cb33078a556c5a870a161c9ec7/functions.jsonl) · [Xref](../../../analiz/native/system-modules/3a21983cdedba4933f513becd0e89c037cec05cb33078a556c5a870a161c9ec7/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/3a21983cdedba4933f513becd0e89c037cec05cb33078a556c5a870a161c9ec7/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/3a21983cdedba4933f513becd0e89c037cec05cb33078a556c5a870a161c9ec7/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00406488` | `remote_close` | [C](../../../analiz/native/system-modules/3a21983cdedba4933f513becd0e89c037cec05cb33078a556c5a870a161c9ec7/00406488.c) |
| `00406464` | `check_remote_input_interrupt_request` | [C](../../../analiz/native/system-modules/3a21983cdedba4933f513becd0e89c037cec05cb33078a556c5a870a161c9ec7/00406464.c) |
| `0040c130` | `init_registers_mips_linux` | [C](../../../analiz/native/system-modules/3a21983cdedba4933f513becd0e89c037cec05cb33078a556c5a870a161c9ec7/0040c130.c) |
| `0040c180` | `init_registers_mips64_linux` | [C](../../../analiz/native/system-modules/3a21983cdedba4933f513becd0e89c037cec05cb33078a556c5a870a161c9ec7/0040c180.c) |
| `00403028` | `_init` | [C](../../../analiz/native/system-modules/3a21983cdedba4933f513becd0e89c037cec05cb33078a556c5a870a161c9ec7/00403028.c) |
| `00406280` | `initialize_async_io` | [C](../../../analiz/native/system-modules/3a21983cdedba4933f513becd0e89c037cec05cb33078a556c5a870a161c9ec7/00406280.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
