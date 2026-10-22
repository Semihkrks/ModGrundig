# `07_MSLIB/utopia/libdrvPWM.so`

SHA-256: `32a4abe1d652c026090e8dc92a540bb60980af14294ea1f9541a1f17acae7001`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 29836 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MDrv_PWM_SetPowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 6, "symbol_examples": ["UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 23 / 93.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 108; semboller: 250.
- Xref: 884; analizde call tipli xref: 0.
- Computed-call instruction: 197 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 4/4.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/32a4abe1d652c026090e8dc92a540bb60980af14294ea1f9541a1f17acae7001/functions.jsonl) · [Xref](../../../analiz/native/system-modules/32a4abe1d652c026090e8dc92a540bb60980af14294ea1f9541a1f17acae7001/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/32a4abe1d652c026090e8dc92a540bb60980af14294ea1f9541a1f17acae7001/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/32a4abe1d652c026090e8dc92a540bb60980af14294ea1f9541a1f17acae7001/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f4e1580` | `_init` | [C](../../../analiz/native/system-modules/32a4abe1d652c026090e8dc92a540bb60980af14294ea1f9541a1f17acae7001/2f4e1580.c) |
| `2f4e291c` | `MDrv_PWM_SetPowerState` | [C](../../../analiz/native/system-modules/32a4abe1d652c026090e8dc92a540bb60980af14294ea1f9541a1f17acae7001/2f4e291c.c) |
| `2f4e46a0` | `HAL_PWM_Init` | [C](../../../analiz/native/system-modules/32a4abe1d652c026090e8dc92a540bb60980af14294ea1f9541a1f17acae7001/2f4e46a0.c) |
| `2f4e27f0` | `MDrv_PWM_Init` | [C](../../../analiz/native/system-modules/32a4abe1d652c026090e8dc92a540bb60980af14294ea1f9541a1f17acae7001/2f4e27f0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
