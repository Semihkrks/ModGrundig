# `07_MSLIB/libTEEClient.so`

SHA-256: `322e0da0e28fde2b0bcf7f01a6c79c06fbbb487c7fc603cc624990c29ad964cb`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 167996 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `liblinux.so`, `libpthread.so.0`, `librt.so.1`, `libstdc++.so.6`, `libSema.so`, `libdl.so.2`, `libc.so.6`
- Dynamic import/export: 62 / 124.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 176; semboller: 1528.
- Xref: 8780; analizde call tipli xref: 0.
- Computed-call instruction: 3458 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/322e0da0e28fde2b0bcf7f01a6c79c06fbbb487c7fc603cc624990c29ad964cb/functions.jsonl) · [Xref](../../../analiz/native/system-modules/322e0da0e28fde2b0bcf7f01a6c79c06fbbb487c7fc603cc624990c29ad964cb/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/322e0da0e28fde2b0bcf7f01a6c79c06fbbb487c7fc603cc624990c29ad964cb/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/322e0da0e28fde2b0bcf7f01a6c79c06fbbb487c7fc603cc624990c29ad964cb/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2ecd58d0` | `teec_msg_init` | [C](../../../analiz/native/system-modules/322e0da0e28fde2b0bcf7f01a6c79c06fbbb487c7fc603cc624990c29ad964cb/2ecd58d0.c) |
| `2ecd5918` | `teec_msg_deinit` | [C](../../../analiz/native/system-modules/322e0da0e28fde2b0bcf7f01a6c79c06fbbb487c7fc603cc624990c29ad964cb/2ecd5918.c) |
| `2ece0e60` | `ca_mbx_deinit` | [C](../../../analiz/native/system-modules/322e0da0e28fde2b0bcf7f01a6c79c06fbbb487c7fc603cc624990c29ad964cb/2ece0e60.c) |
| `2ece0ea8` | `ca_mbx_init` | [C](../../../analiz/native/system-modules/322e0da0e28fde2b0bcf7f01a6c79c06fbbb487c7fc603cc624990c29ad964cb/2ece0ea8.c) |
| `2ece3c50` | `TEE_LogIsInitOk` | [C](../../../analiz/native/system-modules/322e0da0e28fde2b0bcf7f01a6c79c06fbbb487c7fc603cc624990c29ad964cb/2ece3c50.c) |
| `2ecc1e58` | `_init` | [C](../../../analiz/native/system-modules/322e0da0e28fde2b0bcf7f01a6c79c06fbbb487c7fc603cc624990c29ad964cb/2ecc1e58.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
