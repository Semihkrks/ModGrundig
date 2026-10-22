# `07_MSLIB/libubsec.so`

SHA-256: `bb469406c0a9695f10ef9fd0ada5814bee08e6103fcc76bdb70a4e6bb9c6f69a`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 20967 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libcrypto.so.0.9.8`, `libdl.so.2`, `libc.so.6`
- Dynamic import/export: 45 / 13.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 106; semboller: 349.
- Xref: 925; analizde call tipli xref: 0.
- Computed-call instruction: 222 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 3/3.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/bb469406c0a9695f10ef9fd0ada5814bee08e6103fcc76bdb70a4e6bb9c6f69a/functions.jsonl) · [Xref](../../../analiz/native/system-modules/bb469406c0a9695f10ef9fd0ada5814bee08e6103fcc76bdb70a4e6bb9c6f69a/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/bb469406c0a9695f10ef9fd0ada5814bee08e6103fcc76bdb70a4e6bb9c6f69a/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/bb469406c0a9695f10ef9fd0ada5814bee08e6103fcc76bdb70a4e6bb9c6f69a/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010d50` | `_init` | [C](../../../analiz/native/system-modules/bb469406c0a9695f10ef9fd0ada5814bee08e6103fcc76bdb70a4e6bb9c6f69a/00010d50.c) |
| `00011cc8` | `ubsec_dsa_verify` | [C](../../../analiz/native/system-modules/bb469406c0a9695f10ef9fd0ada5814bee08e6103fcc76bdb70a4e6bb9c6f69a/00011cc8.c) |
| `00012940` | `ubsec_init` | [C](../../../analiz/native/system-modules/bb469406c0a9695f10ef9fd0ada5814bee08e6103fcc76bdb70a4e6bb9c6f69a/00012940.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
