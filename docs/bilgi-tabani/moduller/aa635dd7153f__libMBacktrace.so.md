# `07_MSLIB/libMBacktrace.so`

SHA-256: `aa635dd7153fd87fa4f5d0c7b763c59c64c7e7a914e6b5dc7d1b0461d699aaf1`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 7900 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libstdc++.so.6`, `libpthread.so.0`, `libc.so.6`
- Dynamic import/export: 15 / 19.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 37; semboller: 135.
- Xref: 298; analizde call tipli xref: 0.
- Computed-call instruction: 59 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/aa635dd7153fd87fa4f5d0c7b763c59c64c7e7a914e6b5dc7d1b0461d699aaf1/functions.jsonl) · [Xref](../../../analiz/native/system-modules/aa635dd7153fd87fa4f5d0c7b763c59c64c7e7a914e6b5dc7d1b0461d699aaf1/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/aa635dd7153fd87fa4f5d0c7b763c59c64c7e7a914e6b5dc7d1b0461d699aaf1/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/aa635dd7153fd87fa4f5d0c7b763c59c64c7e7a914e6b5dc7d1b0461d699aaf1/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010898` | `_init` | [C](../../../analiz/native/system-modules/aa635dd7153fd87fa4f5d0c7b763c59c64c7e7a914e6b5dc7d1b0461d699aaf1/00010898.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
