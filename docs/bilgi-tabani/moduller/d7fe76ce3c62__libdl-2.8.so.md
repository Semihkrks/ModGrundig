# `06_RFS/lib/libdl-2.8.so`

SHA-256: `d7fe76ce3c62688ce52257f66c0d61f71d5c6551093d8879c2a184290bdcdb02`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 12280 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`, `ld.so.1`
- Dynamic import/export: 24 / 17.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 36; semboller: 188.
- Xref: 339; analizde call tipli xref: 0.
- Computed-call instruction: 58 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 5/5.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/d7fe76ce3c62688ce52257f66c0d61f71d5c6551093d8879c2a184290bdcdb02/functions.jsonl) · [Xref](../../../analiz/native/system-modules/d7fe76ce3c62688ce52257f66c0d61f71d5c6551093d8879c2a184290bdcdb02/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/d7fe76ce3c62688ce52257f66c0d61f71d5c6551093d8879c2a184290bdcdb02/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/d7fe76ce3c62688ce52257f66c0d61f71d5c6551093d8879c2a184290bdcdb02/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f6e1aa0` | `_INIT_0` | [C](../../../analiz/native/system-modules/d7fe76ce3c62688ce52257f66c0d61f71d5c6551093d8879c2a184290bdcdb02/2f6e1aa0.c) |
| `2f6e0ac0` | `_DT_INIT` | [C](../../../analiz/native/system-modules/d7fe76ce3c62688ce52257f66c0d61f71d5c6551093d8879c2a184290bdcdb02/2f6e0ac0.c) |
| `2f6e0c50` | `dlopen` | [C](../../../analiz/native/system-modules/d7fe76ce3c62688ce52257f66c0d61f71d5c6551093d8879c2a184290bdcdb02/2f6e0c50.c) |
| `2f6e1b6c` | `dlopen` | [C](../../../analiz/native/system-modules/d7fe76ce3c62688ce52257f66c0d61f71d5c6551093d8879c2a184290bdcdb02/2f6e1b6c.c) |
| `2f6e0e80` | `dlsym` | [C](../../../analiz/native/system-modules/d7fe76ce3c62688ce52257f66c0d61f71d5c6551093d8879c2a184290bdcdb02/2f6e0e80.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
