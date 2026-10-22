# `07_MSLIB/utopia/libdrvIPAUTH.so`

SHA-256: `00e160cb4f4efc1b715cec16f7c9b3bcfb019b70996db5b0d4194f69d13d8e74`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 32496 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 15 / 47.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 31; semboller: 297.
- Xref: 680; analizde call tipli xref: 0.
- Computed-call instruction: 60 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/00e160cb4f4efc1b715cec16f7c9b3bcfb019b70996db5b0d4194f69d13d8e74/functions.jsonl) · [Xref](../../../analiz/native/system-modules/00e160cb4f4efc1b715cec16f7c9b3bcfb019b70996db5b0d4194f69d13d8e74/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/00e160cb4f4efc1b715cec16f7c9b3bcfb019b70996db5b0d4194f69d13d8e74/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/00e160cb4f4efc1b715cec16f7c9b3bcfb019b70996db5b0d4194f69d13d8e74/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f4454b0` | `MDrv_AUTH_InitialVars` | [C](../../../analiz/native/system-modules/00e160cb4f4efc1b715cec16f7c9b3bcfb019b70996db5b0d4194f69d13d8e74/2f4454b0.c) |
| `2f440b10` | `_init` | [C](../../../analiz/native/system-modules/00e160cb4f4efc1b715cec16f7c9b3bcfb019b70996db5b0d4194f69d13d8e74/2f440b10.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
