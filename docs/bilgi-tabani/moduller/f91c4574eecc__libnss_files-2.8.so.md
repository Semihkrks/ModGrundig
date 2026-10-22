# `06_RFS/lib/libnss_files-2.8.so`

SHA-256: `f91c4574eecc703526bec5513f7387394dbf8c0958051cd1357f964fc0de2cbb`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 49364 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 46 / 62.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 158; semboller: 858.
- Xref: 2635; analizde call tipli xref: 0.
- Computed-call instruction: 488 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/f91c4574eecc703526bec5513f7387394dbf8c0958051cd1357f964fc0de2cbb/functions.jsonl) · [Xref](../../../analiz/native/system-modules/f91c4574eecc703526bec5513f7387394dbf8c0958051cd1357f964fc0de2cbb/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/f91c4574eecc703526bec5513f7387394dbf8c0958051cd1357f964fc0de2cbb/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/f91c4574eecc703526bec5513f7387394dbf8c0958051cd1357f964fc0de2cbb/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `000117f8` | `_DT_INIT` | [C](../../../analiz/native/system-modules/f91c4574eecc703526bec5513f7387394dbf8c0958051cd1357f964fc0de2cbb/000117f8.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
