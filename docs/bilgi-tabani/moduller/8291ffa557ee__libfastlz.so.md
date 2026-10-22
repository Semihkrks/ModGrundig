# `07_MSLIB/libfastlz.so`

SHA-256: `8291ffa557ee5c5bc5f18e2b84d08dd1d35c4e98eb230124cda6b9085b89d45e`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 8192 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 3 / 14.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 12; semboller: 174.
- Xref: 262; analizde call tipli xref: 0.
- Computed-call instruction: 6 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/8291ffa557ee5c5bc5f18e2b84d08dd1d35c4e98eb230124cda6b9085b89d45e/functions.jsonl) · [Xref](../../../analiz/native/system-modules/8291ffa557ee5c5bc5f18e2b84d08dd1d35c4e98eb230124cda6b9085b89d45e/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/8291ffa557ee5c5bc5f18e2b84d08dd1d35c4e98eb230124cda6b9085b89d45e/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/8291ffa557ee5c5bc5f18e2b84d08dd1d35c4e98eb230124cda6b9085b89d45e/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f7004a4` | `_init` | [C](../../../analiz/native/system-modules/8291ffa557ee5c5bc5f18e2b84d08dd1d35c4e98eb230124cda6b9085b89d45e/2f7004a4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
