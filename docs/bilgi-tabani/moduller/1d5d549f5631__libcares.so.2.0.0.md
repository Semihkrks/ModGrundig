# `07_MSLIB/libcares.so.2.0.0`

SHA-256: `1d5d549f56319630c9d444827b55137e179965713dbc38c88efa91a1d2b149b2`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 79172 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `librt.so.1`, `libc.so.6`
- Dynamic import/export: 48 / 52.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 106; semboller: 1473.
- Xref: 3842; analizde call tipli xref: 0.
- Computed-call instruction: 636 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 5/5.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/1d5d549f56319630c9d444827b55137e179965713dbc38c88efa91a1d2b149b2/functions.jsonl) · [Xref](../../../analiz/native/system-modules/1d5d549f56319630c9d444827b55137e179965713dbc38c88efa91a1d2b149b2/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/1d5d549f56319630c9d444827b55137e179965713dbc38c88efa91a1d2b149b2/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/1d5d549f56319630c9d444827b55137e179965713dbc38c88efa91a1d2b149b2/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f0d64d0` | `ares_set_socket_callback` | [C](../../../analiz/native/system-modules/1d5d549f56319630c9d444827b55137e179965713dbc38c88efa91a1d2b149b2/2f0d64d0.c) |
| `2f0d9648` | `ares_init` | [C](../../../analiz/native/system-modules/1d5d549f56319630c9d444827b55137e179965713dbc38c88efa91a1d2b149b2/2f0d9648.c) |
| `2f0d9670` | `ares_library_init` | [C](../../../analiz/native/system-modules/1d5d549f56319630c9d444827b55137e179965713dbc38c88efa91a1d2b149b2/2f0d9670.c) |
| `2f0d124c` | `_init` | [C](../../../analiz/native/system-modules/1d5d549f56319630c9d444827b55137e179965713dbc38c88efa91a1d2b149b2/2f0d124c.c) |
| `2f0d7800` | `ares_init_options` | [C](../../../analiz/native/system-modules/1d5d549f56319630c9d444827b55137e179965713dbc38c88efa91a1d2b149b2/2f0d7800.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
