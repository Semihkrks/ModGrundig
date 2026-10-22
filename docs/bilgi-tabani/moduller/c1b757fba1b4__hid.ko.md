# `09_CONFIG/krl/usb/hid.ko`

SHA-256: `c1b757fba1b419566831044ba021a5e9ce8171934af14153f4e48caeffbfe344`

Durum: **Ghidra indeks tamam**.

Tür: REL (Relocatable file); ELF32 LE MIPS; 111512 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["sounds"], "examples_are_complete": true}, {"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 3, "symbol_examples": ["hidinput_getkeycode", "hidinput_setkeycode", "match_keycode"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: 
- Dynamic import/export: 0 / 0.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 60; semboller: 2136.
- Xref: 3939; analizde call tipli xref: 0.
- Computed-call instruction: 294 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/c1b757fba1b419566831044ba021a5e9ce8171934af14153f4e48caeffbfe344/functions.jsonl) · [Xref](../../../analiz/native/system-modules/c1b757fba1b419566831044ba021a5e9ce8171934af14153f4e48caeffbfe344/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/c1b757fba1b419566831044ba021a5e9ce8171934af14153f4e48caeffbfe344/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/c1b757fba1b419566831044ba021a5e9ce8171934af14153f4e48caeffbfe344/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010200` | `hid_debug_init` | [C](../../../analiz/native/system-modules/c1b757fba1b419566831044ba021a5e9ce8171934af14153f4e48caeffbfe344/00010200.c) |
| `00019c74` | `init_module` | [C](../../../analiz/native/system-modules/c1b757fba1b419566831044ba021a5e9ce8171934af14153f4e48caeffbfe344/00019c74.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
