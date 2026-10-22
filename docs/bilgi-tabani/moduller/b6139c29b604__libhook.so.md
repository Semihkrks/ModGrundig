# `07_MSLIB/utopia/libhook.so`

SHA-256: `b6139c29b60438fd33c8fee9a9836fb286aa609500e8b43291796798a2833366`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 75144 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libpthread.so.0`, `libdl.so.2`, `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 59 / 139.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 200; semboller: 1448.
- Xref: 4981; analizde call tipli xref: 0.
- Computed-call instruction: 703 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 3/3.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/b6139c29b60438fd33c8fee9a9836fb286aa609500e8b43291796798a2833366/functions.jsonl) · [Xref](../../../analiz/native/system-modules/b6139c29b60438fd33c8fee9a9836fb286aa609500e8b43291796798a2833366/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/b6139c29b60438fd33c8fee9a9836fb286aa609500e8b43291796798a2833366/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/b6139c29b60438fd33c8fee9a9836fb286aa609500e8b43291796798a2833366/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00019638` | `initList` | [C](../../../analiz/native/system-modules/b6139c29b60438fd33c8fee9a9836fb286aa609500e8b43291796798a2833366/00019638.c) |
| `00012a48` | `_init` | [C](../../../analiz/native/system-modules/b6139c29b60438fd33c8fee9a9836fb286aa609500e8b43291796798a2833366/00012a48.c) |
| `0001a86c` | `MSystem_Init` | [C](../../../analiz/native/system-modules/b6139c29b60438fd33c8fee9a9836fb286aa609500e8b43291796798a2833366/0001a86c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
