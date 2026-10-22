# `06_RFS/lib/libthread_db-1.0.so`

SHA-256: `4b2462e67965886da38ecc7335f4db9093b311615b6f3e5dee5c144dd9169e01`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 41653 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 18 / 45.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 72; semboller: 655.
- Xref: 1838; analizde call tipli xref: 0.
- Computed-call instruction: 246 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/4b2462e67965886da38ecc7335f4db9093b311615b6f3e5dee5c144dd9169e01/functions.jsonl) · [Xref](../../../analiz/native/system-modules/4b2462e67965886da38ecc7335f4db9093b311615b6f3e5dee5c144dd9169e01/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/4b2462e67965886da38ecc7335f4db9093b311615b6f3e5dee5c144dd9169e01/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/4b2462e67965886da38ecc7335f4db9093b311615b6f3e5dee5c144dd9169e01/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f781330` | `td_init` | [C](../../../analiz/native/system-modules/4b2462e67965886da38ecc7335f4db9093b311615b6f3e5dee5c144dd9169e01/2f781330.c) |
| `2f7811a4` | `_init` | [C](../../../analiz/native/system-modules/4b2462e67965886da38ecc7335f4db9093b311615b6f3e5dee5c144dd9169e01/2f7811a4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
