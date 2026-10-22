# `09_CONFIG/krl/usb/ehci-hcd.ko`

SHA-256: `5f7a96cfd0d63c69847d05a8c480faafdda24c877904456e72730816ba3ba4ca`

Durum: **Ghidra indeks tamam**.

Tür: REL (Relocatable file); ELF32 LE MIPS; 72552 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["usb_power_saving_enable"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["DPDM_swap_setting_ehc"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: 
- Dynamic import/export: 0 / 0.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 69; semboller: 1283.
- Xref: 2831; analizde call tipli xref: 0.
- Computed-call instruction: 529 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 4/4.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/5f7a96cfd0d63c69847d05a8c480faafdda24c877904456e72730816ba3ba4ca/functions.jsonl) · [Xref](../../../analiz/native/system-modules/5f7a96cfd0d63c69847d05a8c480faafdda24c877904456e72730816ba3ba4ca/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/5f7a96cfd0d63c69847d05a8c480faafdda24c877904456e72730816ba3ba4ca/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/5f7a96cfd0d63c69847d05a8c480faafdda24c877904456e72730816ba3ba4ca/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `0001ae10` | `usb_ehci_mstar_remove` | [C](../../../analiz/native/system-modules/5f7a96cfd0d63c69847d05a8c480faafdda24c877904456e72730816ba3ba4ca/0001ae10.c) |
| `0001b2a4` | `init_module` | [C](../../../analiz/native/system-modules/5f7a96cfd0d63c69847d05a8c480faafdda24c877904456e72730816ba3ba4ca/0001b2a4.c) |
| `0001aea0` | `usb_ehci_mstar_probe` | [C](../../../analiz/native/system-modules/5f7a96cfd0d63c69847d05a8c480faafdda24c877904456e72730816ba3ba4ca/0001aea0.c) |
| `0001a4e4` | `ehci_init` | [C](../../../analiz/native/system-modules/5f7a96cfd0d63c69847d05a8c480faafdda24c877904456e72730816ba3ba4ca/0001a4e4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
