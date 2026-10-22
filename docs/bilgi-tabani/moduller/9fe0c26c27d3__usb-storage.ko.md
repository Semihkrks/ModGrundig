# `09_CONFIG/krl/usb/usb-storage.ko`

SHA-256: `9fe0c26c27d3d202c1688d3fc6e8c60558f7f45c72b3d419234536a46e78271e`

Durum: **Ghidra indeks tamam**.

Tür: REL (Relocatable file); ELF32 LE MIPS; 93745 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["slave_configure"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: 
- Dynamic import/export: 0 / 0.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 60; semboller: 1157.
- Xref: 1441; analizde call tipli xref: 1.
- Computed-call instruction: 296 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/9fe0c26c27d3d202c1688d3fc6e8c60558f7f45c72b3d419234536a46e78271e/functions.jsonl) · [Xref](../../../analiz/native/system-modules/9fe0c26c27d3d202c1688d3fc6e8c60558f7f45c72b3d419234536a46e78271e/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/9fe0c26c27d3d202c1688d3fc6e8c60558f7f45c72b3d419234536a46e78271e/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/9fe0c26c27d3d202c1688d3fc6e8c60558f7f45c72b3d419234536a46e78271e/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `0001195c` | `usb_stor_blocking_completion` | [C](../../../analiz/native/system-modules/9fe0c26c27d3d202c1688d3fc6e8c60558f7f45c72b3d419234536a46e78271e/0001195c.c) |
| `00012328` | `usb_stor_Bulk_reset` | [C](../../../analiz/native/system-modules/9fe0c26c27d3d202c1688d3fc6e8c60558f7f45c72b3d419234536a46e78271e/00012328.c) |
| `00013118` | `usb_stor_pre_reset` | [C](../../../analiz/native/system-modules/9fe0c26c27d3d202c1688d3fc6e8c60558f7f45c72b3d419234536a46e78271e/00013118.c) |
| `0001450c` | `usb_stor_reset_resume` | [C](../../../analiz/native/system-modules/9fe0c26c27d3d202c1688d3fc6e8c60558f7f45c72b3d419234536a46e78271e/0001450c.c) |
| `000113a4` | `usb_stor_pad12_command` | [C](../../../analiz/native/system-modules/9fe0c26c27d3d202c1688d3fc6e8c60558f7f45c72b3d419234536a46e78271e/000113a4.c) |
| `00014550` | `usb_stor_huawei_e220_init` | [C](../../../analiz/native/system-modules/9fe0c26c27d3d202c1688d3fc6e8c60558f7f45c72b3d419234536a46e78271e/00014550.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
