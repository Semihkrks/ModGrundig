# `07_MSLIB/utopia/libdrvWDT.so`

SHA-256: `d2180433180ed3a0794076d5a2602fc2c68f75cdd888b9980d05e5780fa0836f`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 14520 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MDrv_WDT_SetPowerState"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 8 / 57.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 61; semboller: 190.
- Xref: 521; analizde call tipli xref: 0.
- Computed-call instruction: 126 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 4/4.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/d2180433180ed3a0794076d5a2602fc2c68f75cdd888b9980d05e5780fa0836f/functions.jsonl) · [Xref](../../../analiz/native/system-modules/d2180433180ed3a0794076d5a2602fc2c68f75cdd888b9980d05e5780fa0836f/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/d2180433180ed3a0794076d5a2602fc2c68f75cdd888b9980d05e5780fa0836f/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/d2180433180ed3a0794076d5a2602fc2c68f75cdd888b9980d05e5780fa0836f/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f5c0cac` | `_init` | [C](../../../analiz/native/system-modules/d2180433180ed3a0794076d5a2602fc2c68f75cdd888b9980d05e5780fa0836f/2f5c0cac.c) |
| `2f5c1c8c` | `MDrv_WDT_Init` | [C](../../../analiz/native/system-modules/d2180433180ed3a0794076d5a2602fc2c68f75cdd888b9980d05e5780fa0836f/2f5c1c8c.c) |
| `2f5c13fc` | `MDrv_TIMER_Init` | [C](../../../analiz/native/system-modules/d2180433180ed3a0794076d5a2602fc2c68f75cdd888b9980d05e5780fa0836f/2f5c13fc.c) |
| `2f5c1d20` | `MDrv_WDT_SetPowerState` | [C](../../../analiz/native/system-modules/d2180433180ed3a0794076d5a2602fc2c68f75cdd888b9980d05e5780fa0836f/2f5c1d20.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
