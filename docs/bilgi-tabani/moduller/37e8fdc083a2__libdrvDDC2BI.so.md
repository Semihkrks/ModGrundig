# `07_MSLIB/utopia/libdrvDDC2BI.so`

SHA-256: `37e8fdc083a2232a5e70753cb6f93714bba479e74e8cae262cdeaa844ce033f9`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 10264 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 10 / 44.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 34; semboller: 139.
- Xref: 242; analizde call tipli xref: 0.
- Computed-call instruction: 40 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 5/5.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/37e8fdc083a2232a5e70753cb6f93714bba479e74e8cae262cdeaa844ce033f9/functions.jsonl) · [Xref](../../../analiz/native/system-modules/37e8fdc083a2232a5e70753cb6f93714bba479e74e8cae262cdeaa844ce033f9/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/37e8fdc083a2232a5e70753cb6f93714bba479e74e8cae262cdeaa844ce033f9/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/37e8fdc083a2232a5e70753cb6f93714bba479e74e8cae262cdeaa844ce033f9/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f3c16d0` | `mhal_DDC2BI_init_riu_base` | [C](../../../analiz/native/system-modules/37e8fdc083a2232a5e70753cb6f93714bba479e74e8cae262cdeaa844ce033f9/2f3c16d0.c) |
| `2f3c0d00` | `MDrv_DDC2BI_InitRx` | [C](../../../analiz/native/system-modules/37e8fdc083a2232a5e70753cb6f93714bba479e74e8cae262cdeaa844ce033f9/2f3c0d00.c) |
| `2f3c1504` | `_MDrv_DDC2BI_init_riu_base` | [C](../../../analiz/native/system-modules/37e8fdc083a2232a5e70753cb6f93714bba479e74e8cae262cdeaa844ce033f9/2f3c1504.c) |
| `2f3c0b18` | `_init` | [C](../../../analiz/native/system-modules/37e8fdc083a2232a5e70753cb6f93714bba479e74e8cae262cdeaa844ce033f9/2f3c0b18.c) |
| `2f3c1584` | `MDrv_DDC2BI_Init` | [C](../../../analiz/native/system-modules/37e8fdc083a2232a5e70753cb6f93714bba479e74e8cae262cdeaa844ce033f9/2f3c1584.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
