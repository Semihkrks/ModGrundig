# `09_CONFIG/krl/usb/usbcore.ko`

SHA-256: `17f50f7dfca38d694b8b55666c03b4a4b5abe3debdeb6cd10b0204a05ed9efa2`

Durum: **Ghidra indeks tamam**.

Tür: REL (Relocatable file); ELF32 LE MIPS; 246370 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 16, "symbol_examples": ["__kstrtab_usb_power_saving_enable", "__kstrtab_usb_root_hub_lost_power", "__ksymtab_usb_power_saving_enable", "__ksymtab_usb_root_hub_lost_power", "dev_attr_bMaxPower", "device_init_wakeup", "device_set_wakeup_capable", "device_set_wakeup_enable", "hub_power_on", "port_power_switch_off", "port_power_switch_on", "power_group_name", "show_bMaxPower", "usb_dev_poweroff", "usb_power_saving_enable", "usb_root_hub_lost_power"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 32, "symbol_examples": ["__kstrtab_usb_altnum_to_altsetting", "__kstrtab_usb_driver_set_configuration", "__kstrtab_usb_find_alt_setting", "__kstrtab_usb_reset_configuration", "__ksymtab_usb_altnum_to_altsetting", "__ksymtab_usb_driver_set_configuration", "__ksymtab_usb_find_alt_setting", "__ksymtab_usb_reset_configuration", "config.c", "dev_attr_bAlternateSetting", "dev_attr_bConfigurationValue", "dev_attr_bNumConfigurations", "dev_attr_configuration", "driver_set_config_work", "format_config", "fs_rh_config_descriptor"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: 
- Dynamic import/export: 0 / 0.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 336; semboller: 3922.
- Xref: 8273; analizde call tipli xref: 4.
- Computed-call instruction: 1773 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/17f50f7dfca38d694b8b55666c03b4a4b5abe3debdeb6cd10b0204a05ed9efa2/functions.jsonl) · [Xref](../../../analiz/native/system-modules/17f50f7dfca38d694b8b55666c03b4a4b5abe3debdeb6cd10b0204a05ed9efa2/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/17f50f7dfca38d694b8b55666c03b4a4b5abe3debdeb6cd10b0204a05ed9efa2/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/17f50f7dfca38d694b8b55666c03b4a4b5abe3debdeb6cd10b0204a05ed9efa2/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `000104a8` | `usb_disabled` | [C](../../../analiz/native/system-modules/17f50f7dfca38d694b8b55666c03b4a4b5abe3debdeb6cd10b0204a05ed9efa2/000104a8.c) |
| `000104b4` | `usb_dev_restore` | [C](../../../analiz/native/system-modules/17f50f7dfca38d694b8b55666c03b4a4b5abe3debdeb6cd10b0204a05ed9efa2/000104b4.c) |
| `000104c4` | `usb_dev_thaw` | [C](../../../analiz/native/system-modules/17f50f7dfca38d694b8b55666c03b4a4b5abe3debdeb6cd10b0204a05ed9efa2/000104c4.c) |
| `000104d4` | `usb_dev_resume` | [C](../../../analiz/native/system-modules/17f50f7dfca38d694b8b55666c03b4a4b5abe3debdeb6cd10b0204a05ed9efa2/000104d4.c) |
| `000104e4` | `usb_dev_complete` | [C](../../../analiz/native/system-modules/17f50f7dfca38d694b8b55666c03b4a4b5abe3debdeb6cd10b0204a05ed9efa2/000104e4.c) |
| `000104f4` | `usb_dev_poweroff` | [C](../../../analiz/native/system-modules/17f50f7dfca38d694b8b55666c03b4a4b5abe3debdeb6cd10b0204a05ed9efa2/000104f4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
