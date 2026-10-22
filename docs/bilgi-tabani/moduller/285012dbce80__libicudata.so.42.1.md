# `07_MSLIB/libicudata.so.42.1`

SHA-256: `285012dbce8074fa72ead919e07a9b28f4f640f722e216df3434a62b291a054a`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 4070768 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: 
- Dynamic import/export: 0 / 9.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 1; semboller: 44.
- Xref: 43; analizde call tipli xref: 0.
- Computed-call instruction: 0 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 0/0.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/285012dbce8074fa72ead919e07a9b28f4f640f722e216df3434a62b291a054a/functions.jsonl) · [Xref](../../../analiz/native/system-modules/285012dbce8074fa72ead919e07a9b28f4f640f722e216df3434a62b291a054a/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/285012dbce8074fa72ead919e07a9b28f4f640f722e216df3434a62b291a054a/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/285012dbce8074fa72ead919e07a9b28f4f640f722e216df3434a62b291a054a/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
