# `07_MSLIB/libiconv.so.2.5.0`

SHA-256: `ab79c529549b940a776a6f33c2168dc106a5261639f39b1ca4ff999a2481d2a7`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 1025380 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 27 / 20.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 358; semboller: 3278.
- Xref: 20909; analizde call tipli xref: 0.
- Computed-call instruction: 454 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/ab79c529549b940a776a6f33c2168dc106a5261639f39b1ca4ff999a2481d2a7/functions.jsonl) · [Xref](../../../analiz/native/system-modules/ab79c529549b940a776a6f33c2168dc106a5261639f39b1ca4ff999a2481d2a7/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/ab79c529549b940a776a6f33c2168dc106a5261639f39b1ca4ff999a2481d2a7/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/ab79c529549b940a776a6f33c2168dc106a5261639f39b1ca4ff999a2481d2a7/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00011058` | `_init` | [C](../../../analiz/native/system-modules/ab79c529549b940a776a6f33c2168dc106a5261639f39b1ca4ff999a2481d2a7/00011058.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
