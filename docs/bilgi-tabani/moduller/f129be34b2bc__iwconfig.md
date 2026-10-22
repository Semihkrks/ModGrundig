# `06_RFS/sbin/iwconfig`

SHA-256: `f129be34b2bc05e17571310b4abee549bfc54e4fb8ce1824a76b8560a1977908`

Durum: **Ghidra indeks tamam**.

Tür: EXEC (Executable file); ELF32 LE MIPS; 36032 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["__fpcmp_parts_d"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["iw_print_txpower", "iwmod_power", "set_power_info", "set_txpower_info"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 4, "symbol_examples": ["/scratch/clm/2008q3-src/src/gcc-4.3/libgcc/../gcc/config/fp-bit.h", "iw_get_basic_config", "iwconfig.c", "iwconfig_cmds"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libiw.so.29`, `libm.so.6`, `libc.so.6`
- Dynamic import/export: 49 / 13.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 81; semboller: 610.
- Xref: 1655; analizde call tipli xref: 4.
- Computed-call instruction: 321 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 4/4.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/f129be34b2bc05e17571310b4abee549bfc54e4fb8ce1824a76b8560a1977908/functions.jsonl) · [Xref](../../../analiz/native/system-modules/f129be34b2bc05e17571310b4abee549bfc54e4fb8ce1824a76b8560a1977908/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/f129be34b2bc05e17571310b4abee549bfc54e4fb8ce1824a76b8560a1977908/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/f129be34b2bc05e17571310b4abee549bfc54e4fb8ce1824a76b8560a1977908/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00400dc4` | `_init` | [C](../../../analiz/native/system-modules/f129be34b2bc05e17571310b4abee549bfc54e4fb8ce1824a76b8560a1977908/00400dc4.c) |
| `004051d8` | `__libc_csu_init` | [C](../../../analiz/native/system-modules/f129be34b2bc05e17571310b4abee549bfc54e4fb8ce1824a76b8560a1977908/004051d8.c) |
| `00401e40` | `set_txpower_info` | [C](../../../analiz/native/system-modules/f129be34b2bc05e17571310b4abee549bfc54e4fb8ce1824a76b8560a1977908/00401e40.c) |
| `004023e0` | `set_power_info` | [C](../../../analiz/native/system-modules/f129be34b2bc05e17571310b4abee549bfc54e4fb8ce1824a76b8560a1977908/004023e0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
