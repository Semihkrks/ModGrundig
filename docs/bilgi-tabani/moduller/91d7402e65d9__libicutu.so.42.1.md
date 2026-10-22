# `07_MSLIB/libicutu.so.42.1`

SHA-256: `91d7402e65d9bb59217e1c885b007978a6d2bbbdeb9c2390bf7eea6bb647360f`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 145636 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libicui18n.so.42`, `libicuuc.so.42`, `libicudata.so.42`, `libpthread.so.0`, `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 99 / 146.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 373; semboller: 2006.
- Xref: 11613; analizde call tipli xref: 0.
- Computed-call instruction: 1246 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/91d7402e65d9bb59217e1c885b007978a6d2bbbdeb9c2390bf7eea6bb647360f/functions.jsonl) · [Xref](../../../analiz/native/system-modules/91d7402e65d9bb59217e1c885b007978a6d2bbbdeb9c2390bf7eea6bb647360f/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/91d7402e65d9bb59217e1c885b007978a6d2bbbdeb9c2390bf7eea6bb647360f/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/91d7402e65d9bb59217e1c885b007978a6d2bbbdeb9c2390bf7eea6bb647360f/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00012fa0` | `_init` | [C](../../../analiz/native/system-modules/91d7402e65d9bb59217e1c885b007978a6d2bbbdeb9c2390bf7eea6bb647360f/00012fa0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
