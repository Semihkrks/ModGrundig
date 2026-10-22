# `09_CONFIG/krl/usb/usbserial.ko`

SHA-256: `f59ed384e5cb49fb3addc9bf9e02097b1a716903e65a434e08629440fc9ca447`

Durum: **Ghidra indeks tamam**.

Tür: REL (Relocatable file); ELF32 LE MIPS; 57529 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["tty_wakeup"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: 
- Dynamic import/export: 0 / 0.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 67; semboller: 820.
- Xref: 1503; analizde call tipli xref: 0.
- Computed-call instruction: 381 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/f59ed384e5cb49fb3addc9bf9e02097b1a716903e65a434e08629440fc9ca447/functions.jsonl) · [Xref](../../../analiz/native/system-modules/f59ed384e5cb49fb3addc9bf9e02097b1a716903e65a434e08629440fc9ca447/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/f59ed384e5cb49fb3addc9bf9e02097b1a716903e65a434e08629440fc9ca447/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/f59ed384e5cb49fb3addc9bf9e02097b1a716903e65a434e08629440fc9ca447/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00011814` | `usb_serial_port_softint` | [C](../../../analiz/native/system-modules/f59ed384e5cb49fb3addc9bf9e02097b1a716903e65a434e08629440fc9ca447/00011814.c) |
| `000134d0` | `usb_serial_generic_register` | [C](../../../analiz/native/system-modules/f59ed384e5cb49fb3addc9bf9e02097b1a716903e65a434e08629440fc9ca447/000134d0.c) |
| `00011824` | `usb_serial_put` | [C](../../../analiz/native/system-modules/f59ed384e5cb49fb3addc9bf9e02097b1a716903e65a434e08629440fc9ca447/00011824.c) |
| `00015180` | `usb_serial_device_match` | [C](../../../analiz/native/system-modules/f59ed384e5cb49fb3addc9bf9e02097b1a716903e65a434e08629440fc9ca447/00015180.c) |
| `00015558` | `usb_serial_bus_register` | [C](../../../analiz/native/system-modules/f59ed384e5cb49fb3addc9bf9e02097b1a716903e65a434e08629440fc9ca447/00015558.c) |
| `000134f0` | `usb_serial_handle_break` | [C](../../../analiz/native/system-modules/f59ed384e5cb49fb3addc9bf9e02097b1a716903e65a434e08629440fc9ca447/000134f0.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
