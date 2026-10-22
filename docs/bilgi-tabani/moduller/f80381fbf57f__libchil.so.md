# `07_MSLIB/libchil.so`

SHA-256: `f80381fbf57f4ec256731b5652c7d5b2125cd0a3d1d4f0a8e01d1f50940631c4`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 27131 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libcrypto.so.0.9.8`, `libdl.so.2`, `libc.so.6`
- Dynamic import/export: 69 / 13.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 163; semboller: 486.
- Xref: 993; analizde call tipli xref: 0.
- Computed-call instruction: 230 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/f80381fbf57f4ec256731b5652c7d5b2125cd0a3d1d4f0a8e01d1f50940631c4/functions.jsonl) · [Xref](../../../analiz/native/system-modules/f80381fbf57f4ec256731b5652c7d5b2125cd0a3d1d4f0a8e01d1f50940631c4/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/f80381fbf57f4ec256731b5652c7d5b2125cd0a3d1d4f0a8e01d1f50940631c4/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/f80381fbf57f4ec256731b5652c7d5b2125cd0a3d1d4f0a8e01d1f50940631c4/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00013c90` | `hwcrhk_mutex_destroy` | [C](../../../analiz/native/system-modules/f80381fbf57f4ec256731b5652c7d5b2125cd0a3d1d4f0a8e01d1f50940631c4/00013c90.c) |
| `00012450` | `hwcrhk_mutex_unlock` | [C](../../../analiz/native/system-modules/f80381fbf57f4ec256731b5652c7d5b2125cd0a3d1d4f0a8e01d1f50940631c4/00012450.c) |
| `00013ca8` | `hwcrhk_mutex_init` | [C](../../../analiz/native/system-modules/f80381fbf57f4ec256731b5652c7d5b2125cd0a3d1d4f0a8e01d1f50940631c4/00013ca8.c) |
| `00012478` | `hwcrhk_mutex_lock` | [C](../../../analiz/native/system-modules/f80381fbf57f4ec256731b5652c7d5b2125cd0a3d1d4f0a8e01d1f50940631c4/00012478.c) |
| `00011218` | `_init` | [C](../../../analiz/native/system-modules/f80381fbf57f4ec256731b5652c7d5b2125cd0a3d1d4f0a8e01d1f50940631c4/00011218.c) |
| `00013870` | `hwcrhk_init` | [C](../../../analiz/native/system-modules/f80381fbf57f4ec256731b5652c7d5b2125cd0a3d1d4f0a8e01d1f50940631c4/00013870.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
