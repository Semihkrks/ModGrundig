# `07_MSLIB/libbrick_terminator_info.so`

SHA-256: `dbb3e5d650d0d1207e814a5f8f41b22b507f5f47b6313566632b44c014206ed4`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 5880 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libdrvSERFLASH.so`, `libdrvGPIO.so`, `liblinux.so`, `librt.so.1`, `libc.so.6`
- Dynamic import/export: 17 / 18.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 43; semboller: 117.
- Xref: 228; analizde call tipli xref: 0.
- Computed-call instruction: 40 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/dbb3e5d650d0d1207e814a5f8f41b22b507f5f47b6313566632b44c014206ed4/functions.jsonl) · [Xref](../../../analiz/native/system-modules/dbb3e5d650d0d1207e814a5f8f41b22b507f5f47b6313566632b44c014206ed4/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/dbb3e5d650d0d1207e814a5f8f41b22b507f5f47b6313566632b44c014206ed4/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/dbb3e5d650d0d1207e814a5f8f41b22b507f5f47b6313566632b44c014206ed4/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `000107fc` | `_init` | [C](../../../analiz/native/system-modules/dbb3e5d650d0d1207e814a5f8f41b22b507f5f47b6313566632b44c014206ed4/000107fc.c) |
| `00010b80` | `BrickTerminatorInfo_init` | [C](../../../analiz/native/system-modules/dbb3e5d650d0d1207e814a5f8f41b22b507f5f47b6313566632b44c014206ed4/00010b80.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
