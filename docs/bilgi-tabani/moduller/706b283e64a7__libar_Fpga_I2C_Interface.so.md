# `07_MSLIB/libar_Fpga_I2C_Interface.so`

SHA-256: `706b283e64a7c4f9c003e48de546f9cea5371445542ad53c3433bebfdd7c1854`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 7544 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 14 / 21.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 35; semboller: 144.
- Xref: 292; analizde call tipli xref: 0.
- Computed-call instruction: 52 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/706b283e64a7c4f9c003e48de546f9cea5371445542ad53c3433bebfdd7c1854/functions.jsonl) · [Xref](../../../analiz/native/system-modules/706b283e64a7c4f9c003e48de546f9cea5371445542ad53c3433bebfdd7c1854/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/706b283e64a7c4f9c003e48de546f9cea5371445542ad53c3433bebfdd7c1854/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/706b283e64a7c4f9c003e48de546f9cea5371445542ad53c3433bebfdd7c1854/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `000109b0` | `_init` | [C](../../../analiz/native/system-modules/706b283e64a7c4f9c003e48de546f9cea5371445542ad53c3433bebfdd7c1854/000109b0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
