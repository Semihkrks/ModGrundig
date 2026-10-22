# `08_APP/bin/read_piutimer1`

SHA-256: `abcb393d485ea4f5e4932875a43bc8623b353c2c2b8901b31b91c6efa4e51b98`

Durum: **Ghidra indeks tamam**.

Tür: EXEC (Executable file); ELF32 LE MIPS; 6708 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libdrvWDT.so`, `liblinux.so`, `libpthread.so.0`, `librt.so.1`, `libc.so.6`
- Dynamic import/export: 7 / 13.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 16; semboller: 93.
- Xref: 134; analizde call tipli xref: 4.
- Computed-call instruction: 10 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 2/2.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/abcb393d485ea4f5e4932875a43bc8623b353c2c2b8901b31b91c6efa4e51b98/functions.jsonl) · [Xref](../../../analiz/native/system-modules/abcb393d485ea4f5e4932875a43bc8623b353c2c2b8901b31b91c6efa4e51b98/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/abcb393d485ea4f5e4932875a43bc8623b353c2c2b8901b31b91c6efa4e51b98/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/abcb393d485ea4f5e4932875a43bc8623b353c2c2b8901b31b91c6efa4e51b98/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00400694` | `_init` | [C](../../../analiz/native/system-modules/abcb393d485ea4f5e4932875a43bc8623b353c2c2b8901b31b91c6efa4e51b98/00400694.c) |
| `00400928` | `__libc_csu_init` | [C](../../../analiz/native/system-modules/abcb393d485ea4f5e4932875a43bc8623b353c2c2b8901b31b91c6efa4e51b98/00400928.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
