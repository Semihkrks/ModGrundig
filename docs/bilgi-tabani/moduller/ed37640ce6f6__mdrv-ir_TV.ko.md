# `09_CONFIG/krl/ir/mdrv-ir_TV.ko`

SHA-256: `ed37640ce6f6373230dc7a01244daf96986f1d7ec9bcee0bf904e739c26be555`

Durum: **Ghidra indeks tamam**.

Tür: REL (Relocatable file); ELF32 LE MIPS; 26657 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 57, "symbol_examples": ["IRDev", "IR_PROTOCOL_Common.c", "IR_PROTOCOL_INSTALL.c", "MDrv_IR_EnableIR", "MDrv_IR_GetCode", "MDrv_IR_GetKey", "MDrv_IR_GetLastKeyTime", "MDrv_IR_GetMasterPid", "MDrv_IR_Init", "MDrv_IR_InitCfg", "MDrv_IR_IsFantasyProtocolSupported", "MDrv_IR_ParseKey", "MDrv_IR_Poll", "MDrv_IR_Read", "MDrv_IR_ReadShotBuffer", "MDrv_IR_SendKey"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: 
- Dynamic import/export: 0 / 0.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 39; semboller: 570.
- Xref: 807; analizde call tipli xref: 2.
- Computed-call instruction: 70 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 3/3.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/ed37640ce6f6373230dc7a01244daf96986f1d7ec9bcee0bf904e739c26be555/functions.jsonl) · [Xref](../../../analiz/native/system-modules/ed37640ce6f6373230dc7a01244daf96986f1d7ec9bcee0bf904e739c26be555/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/ed37640ce6f6373230dc7a01244daf96986f1d7ec9bcee0bf904e739c26be555/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/ed37640ce6f6373230dc7a01244daf96986f1d7ec9bcee0bf904e739c26be555/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `00011cbc` | `init_module` | [C](../../../analiz/native/system-modules/ed37640ce6f6373230dc7a01244daf96986f1d7ec9bcee0bf904e739c26be555/00011cbc.c) |
| `00010174` | `MDrv_IR_InitCfg` | [C](../../../analiz/native/system-modules/ed37640ce6f6373230dc7a01244daf96986f1d7ec9bcee0bf904e739c26be555/00010174.c) |
| `00010a74` | `MDrv_IR_Init` | [C](../../../analiz/native/system-modules/ed37640ce6f6373230dc7a01244daf96986f1d7ec9bcee0bf904e739c26be555/00010a74.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
