# `07_MSLIB/libgthread-2.0.so.0.2400.2`

SHA-256: `d4f00f3438a9f29f1bd17b2daa9f4693d89506dfd16762335f15855fbb37adcc`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 16488 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libpthread.so.0`, `librt.so.1`, `libglib-2.0.so.0`, `libc.so.6`
- Dynamic import/export: 47 / 13.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 92; semboller: 276.
- Xref: 367; analizde call tipli xref: 0.
- Computed-call instruction: 127 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 3/3.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/d4f00f3438a9f29f1bd17b2daa9f4693d89506dfd16762335f15855fbb37adcc/functions.jsonl) · [Xref](../../../analiz/native/system-modules/d4f00f3438a9f29f1bd17b2daa9f4693d89506dfd16762335f15855fbb37adcc/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/d4f00f3438a9f29f1bd17b2daa9f4693d89506dfd16762335f15855fbb37adcc/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/d4f00f3438a9f29f1bd17b2daa9f4693d89506dfd16762335f15855fbb37adcc/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00010dcc` | `_init` | [C](../../../analiz/native/system-modules/d4f00f3438a9f29f1bd17b2daa9f4693d89506dfd16762335f15855fbb37adcc/00010dcc.c) |
| `000128cc` | `g_thread_init_with_errorcheck_mutexes` | [C](../../../analiz/native/system-modules/d4f00f3438a9f29f1bd17b2daa9f4693d89506dfd16762335f15855fbb37adcc/000128cc.c) |
| `0001260c` | `g_thread_init` | [C](../../../analiz/native/system-modules/d4f00f3438a9f29f1bd17b2daa9f4693d89506dfd16762335f15855fbb37adcc/0001260c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
