# `07_MSLIB/utopia/libdrvAUDSP.so`

SHA-256: `b50f623ef506fb145a82a951a236b4da2a9e3cedad923c2ad4d1c6f87f0c7583`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 4468 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 3 / 11.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 7; semboller: 63.
- Xref: 97; analizde call tipli xref: 0.
- Computed-call instruction: 7 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/b50f623ef506fb145a82a951a236b4da2a9e3cedad923c2ad4d1c6f87f0c7583/functions.jsonl) · [Xref](../../../analiz/native/system-modules/b50f623ef506fb145a82a951a236b4da2a9e3cedad923c2ad4d1c6f87f0c7583/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/b50f623ef506fb145a82a951a236b4da2a9e3cedad923c2ad4d1c6f87f0c7583/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/b50f623ef506fb145a82a951a236b4da2a9e3cedad923c2ad4d1c6f87f0c7583/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f380414` | `_init` | [C](../../../analiz/native/system-modules/b50f623ef506fb145a82a951a236b4da2a9e3cedad923c2ad4d1c6f87f0c7583/2f380414.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
