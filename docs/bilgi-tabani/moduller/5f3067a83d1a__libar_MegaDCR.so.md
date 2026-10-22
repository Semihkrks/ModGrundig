# `07_MSLIB/libar_MegaDCR.so`

SHA-256: `5f3067a83d1a5de6cb5defff042869fa199fce3866ea2fa44e1e2c9406be9512`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 10336 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["_ZN19MSrv_Control_common21GetMSrvSystemDatabaseEv"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 20 / 43.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 36; semboller: 183.
- Xref: 336; analizde call tipli xref: 0.
- Computed-call instruction: 73 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/5f3067a83d1a5de6cb5defff042869fa199fce3866ea2fa44e1e2c9406be9512/functions.jsonl) · [Xref](../../../analiz/native/system-modules/5f3067a83d1a5de6cb5defff042869fa199fce3866ea2fa44e1e2c9406be9512/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/5f3067a83d1a5de6cb5defff042869fa199fce3866ea2fa44e1e2c9406be9512/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/5f3067a83d1a5de6cb5defff042869fa199fce3866ea2fa44e1e2c9406be9512/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f620e6c` | `_init` | [C](../../../analiz/native/system-modules/5f3067a83d1a5de6cb5defff042869fa199fce3866ea2fa44e1e2c9406be9512/2f620e6c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
