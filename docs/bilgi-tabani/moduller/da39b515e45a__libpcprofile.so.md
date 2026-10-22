# `06_RFS/lib/libpcprofile.so`

SHA-256: `da39b515e45a06c2c7bf459ea8fff7401a685f1fa2581feb4afb82853d5b8481`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 5592 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`, `ld.so.1`
- Dynamic import/export: 8 / 14.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 18; semboller: 75.
- Xref: 99; analizde call tipli xref: 0.
- Computed-call instruction: 12 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/da39b515e45a06c2c7bf459ea8fff7401a685f1fa2581feb4afb82853d5b8481/functions.jsonl) · [Xref](../../../analiz/native/system-modules/da39b515e45a06c2c7bf459ea8fff7401a685f1fa2581feb4afb82853d5b8481/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/da39b515e45a06c2c7bf459ea8fff7401a685f1fa2581feb4afb82853d5b8481/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/da39b515e45a06c2c7bf459ea8fff7401a685f1fa2581feb4afb82853d5b8481/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `000106a0` | `_init` | [C](../../../analiz/native/system-modules/da39b515e45a06c2c7bf459ea8fff7401a685f1fa2581feb4afb82853d5b8481/000106a0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
