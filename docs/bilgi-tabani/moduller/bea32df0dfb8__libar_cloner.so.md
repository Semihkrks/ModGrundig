# `07_MSLIB/libar_cloner.so`

SHA-256: `bea32df0dfb84e5deb4c9f753c22d958b2efd3e16f9aa75f2ed46df368fad8ca`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 22484 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["_ZN10Clonerplug23Clonerplug_KeepSettingsE22USB_Cloner_Selection_e", "_ZN10Clonerplug26Clonerplug_RestoreSettingsE22USB_Cloner_Selection_e"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 25 / 31.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 47; semboller: 226.
- Xref: 401; analizde call tipli xref: 0.
- Computed-call instruction: 84 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/bea32df0dfb84e5deb4c9f753c22d958b2efd3e16f9aa75f2ed46df368fad8ca/functions.jsonl) · [Xref](../../../analiz/native/system-modules/bea32df0dfb84e5deb4c9f753c22d958b2efd3e16f9aa75f2ed46df368fad8ca/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/bea32df0dfb84e5deb4c9f753c22d958b2efd3e16f9aa75f2ed46df368fad8ca/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/bea32df0dfb84e5deb4c9f753c22d958b2efd3e16f9aa75f2ed46df368fad8ca/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f640f14` | `_init` | [C](../../../analiz/native/system-modules/bea32df0dfb84e5deb4c9f753c22d958b2efd3e16f9aa75f2ed46df368fad8ca/2f640f14.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
