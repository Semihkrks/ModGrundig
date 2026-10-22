# `06_RFS/bin/mkdfiff`

SHA-256: `4170fa1fd9f32dc9aa4c9ffc9e7ee098ab2118e440bb8699a1a256d44321c393`

Durum: **Ghidra indeks tamam**.

Tür: EXEC (Executable file); ELF32 LE MIPS; 12756 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libpng12.so.0`, `libm.so.6`, `libdirect-1.2.so.0`, `libz.so.1`, `libdl.so.2`, `libpthread.so.0`, `libc.so.6`
- Dynamic import/export: 35 / 15.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 51; semboller: 218.
- Xref: 390; analizde call tipli xref: 10.
- Computed-call instruction: 56 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/4170fa1fd9f32dc9aa4c9ffc9e7ee098ab2118e440bb8699a1a256d44321c393/functions.jsonl) · [Xref](../../../analiz/native/system-modules/4170fa1fd9f32dc9aa4c9ffc9e7ee098ab2118e440bb8699a1a256d44321c393/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/4170fa1fd9f32dc9aa4c9ffc9e7ee098ab2118e440bb8699a1a256d44321c393/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/4170fa1fd9f32dc9aa4c9ffc9e7ee098ab2118e440bb8699a1a256d44321c393/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00400cb8` | `_init` | [C](../../../analiz/native/system-modules/4170fa1fd9f32dc9aa4c9ffc9e7ee098ab2118e440bb8699a1a256d44321c393/00400cb8.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
