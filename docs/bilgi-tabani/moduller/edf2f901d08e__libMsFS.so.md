# `07_MSLIB/utopia/libMsFS.so`

SHA-256: `edf2f901d08ec76895f4199acd99e4ef313248f97be9fe2e61919324f5247ecb`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 13480 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 41 / 47.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 82; semboller: 237.
- Xref: 518; analizde call tipli xref: 0.
- Computed-call instruction: 123 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 4/4.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/edf2f901d08ec76895f4199acd99e4ef313248f97be9fe2e61919324f5247ecb/functions.jsonl) · [Xref](../../../analiz/native/system-modules/edf2f901d08ec76895f4199acd99e4ef313248f97be9fe2e61919324f5247ecb/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/edf2f901d08ec76895f4199acd99e4ef313248f97be9fe2e61919324f5247ecb/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/edf2f901d08ec76895f4199acd99e4ef313248f97be9fe2e61919324f5247ecb/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f2e0fa0` | `MsFS_Init` | [C](../../../analiz/native/system-modules/edf2f901d08ec76895f4199acd99e4ef313248f97be9fe2e61919324f5247ecb/2f2e0fa0.c) |
| `2f2e1fdc` | `MsFS_Umount` | [C](../../../analiz/native/system-modules/edf2f901d08ec76895f4199acd99e4ef313248f97be9fe2e61919324f5247ecb/2f2e1fdc.c) |
| `2f2e2010` | `MsFS_Mount` | [C](../../../analiz/native/system-modules/edf2f901d08ec76895f4199acd99e4ef313248f97be9fe2e61919324f5247ecb/2f2e2010.c) |
| `2f2e0e10` | `_init` | [C](../../../analiz/native/system-modules/edf2f901d08ec76895f4199acd99e4ef313248f97be9fe2e61919324f5247ecb/2f2e0e10.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
