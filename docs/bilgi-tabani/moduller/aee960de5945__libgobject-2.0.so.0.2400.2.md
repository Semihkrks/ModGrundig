# `07_MSLIB/libgobject-2.0.so.0.2400.2`

SHA-256: `aee960de5945f026a516eeb472544c44cd7119eca4af125a0c95c0b3685189bc`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 339160 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libgthread-2.0.so.0`, `libpthread.so.0`, `librt.so.1`, `libglib-2.0.so.0`, `libc.so.6`
- Dynamic import/export: 133 / 347.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 716; semboller: 4825.
- Xref: 16707; analizde call tipli xref: 0.
- Computed-call instruction: 3359 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/aee960de5945f026a516eeb472544c44cd7119eca4af125a0c95c0b3685189bc/functions.jsonl) · [Xref](../../../analiz/native/system-modules/aee960de5945f026a516eeb472544c44cd7119eca4af125a0c95c0b3685189bc/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/aee960de5945f026a516eeb472544c44cd7119eca4af125a0c95c0b3685189bc/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/aee960de5945f026a516eeb472544c44cd7119eca4af125a0c95c0b3685189bc/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `000421d0` | `g_type_init` | [C](../../../analiz/native/system-modules/aee960de5945f026a516eeb472544c44cd7119eca4af125a0c95c0b3685189bc/000421d0.c) |
| `0002acec` | `FUN_0002acec` | [C](../../../analiz/native/system-modules/aee960de5945f026a516eeb472544c44cd7119eca4af125a0c95c0b3685189bc/0002acec.c) |
| `0003ce38` | `g_io_channel_get_type` | [C](../../../analiz/native/system-modules/aee960de5945f026a516eeb472544c44cd7119eca4af125a0c95c0b3685189bc/0003ce38.c) |
| `000161b4` | `_DT_INIT` | [C](../../../analiz/native/system-modules/aee960de5945f026a516eeb472544c44cd7119eca4af125a0c95c0b3685189bc/000161b4.c) |
| `0001b8d8` | `g_initially_unowned_get_type` | [C](../../../analiz/native/system-modules/aee960de5945f026a516eeb472544c44cd7119eca4af125a0c95c0b3685189bc/0001b8d8.c) |
| `0004e0c0` | `g_value_init` | [C](../../../analiz/native/system-modules/aee960de5945f026a516eeb472544c44cd7119eca4af125a0c95c0b3685189bc/0004e0c0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
