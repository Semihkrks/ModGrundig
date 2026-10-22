# `06_RFS/lib/libcrypt-2.8.so`

SHA-256: `e8e0a1542e96710880e1a981998c2cb0b091a5f2a10f588bdeb71055c7faa5e4`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 41212 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 19 / 9.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 37; semboller: 472.
- Xref: 1148; analizde call tipli xref: 0.
- Computed-call instruction: 242 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/e8e0a1542e96710880e1a981998c2cb0b091a5f2a10f588bdeb71055c7faa5e4/functions.jsonl) · [Xref](../../../analiz/native/system-modules/e8e0a1542e96710880e1a981998c2cb0b091a5f2a10f588bdeb71055c7faa5e4/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/e8e0a1542e96710880e1a981998c2cb0b091a5f2a10f588bdeb71055c7faa5e4/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/e8e0a1542e96710880e1a981998c2cb0b091a5f2a10f588bdeb71055c7faa5e4/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2eae0798` | `_DT_INIT` | [C](../../../analiz/native/system-modules/e8e0a1542e96710880e1a981998c2cb0b091a5f2a10f588bdeb71055c7faa5e4/2eae0798.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
