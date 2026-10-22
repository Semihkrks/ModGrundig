# `06_RFS/bin/ntpdate`

SHA-256: `74553edaf3dede83047f2f1bdc44ecf7b11b42a775622c6b358a7be49e3afc51`

Durum: **Ghidra indeks tamam**.

Tür: EXEC (Executable file); ELF32 LE MIPS; 104662 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 71 / 7.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 236; semboller: 1429.
- Xref: 6087; analizde call tipli xref: 57.
- Computed-call instruction: 553 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/74553edaf3dede83047f2f1bdc44ecf7b11b42a775622c6b358a7be49e3afc51/functions.jsonl) · [Xref](../../../analiz/native/system-modules/74553edaf3dede83047f2f1bdc44ecf7b11b42a775622c6b358a7be49e3afc51/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/74553edaf3dede83047f2f1bdc44ecf7b11b42a775622c6b358a7be49e3afc51/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/74553edaf3dede83047f2f1bdc44ecf7b11b42a775622c6b358a7be49e3afc51/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `0040b6e0` | `init_lock` | [C](../../../analiz/native/system-modules/74553edaf3dede83047f2f1bdc44ecf7b11b42a775622c6b358a7be49e3afc51/0040b6e0.c) |
| `00408be0` | `init_lib` | [C](../../../analiz/native/system-modules/74553edaf3dede83047f2f1bdc44ecf7b11b42a775622c6b358a7be49e3afc51/00408be0.c) |
| `0040afa8` | `initialize_action` | [C](../../../analiz/native/system-modules/74553edaf3dede83047f2f1bdc44ecf7b11b42a775622c6b358a7be49e3afc51/0040afa8.c) |
| `00406e30` | `init_auth` | [C](../../../analiz/native/system-modules/74553edaf3dede83047f2f1bdc44ecf7b11b42a775622c6b358a7be49e3afc51/00406e30.c) |
| `0040a400` | `initialise_buffer` | [C](../../../analiz/native/system-modules/74553edaf3dede83047f2f1bdc44ecf7b11b42a775622c6b358a7be49e3afc51/0040a400.c) |
| `0040afe8` | `initialize` | [C](../../../analiz/native/system-modules/74553edaf3dede83047f2f1bdc44ecf7b11b42a775622c6b358a7be49e3afc51/0040afe8.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
