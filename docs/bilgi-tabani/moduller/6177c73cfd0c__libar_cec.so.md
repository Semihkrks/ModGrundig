# `07_MSLIB/libar_cec.so`

SHA-256: `6177c73cfd0cca039e1aacf2fb721f693812b18a9282f2980d5c255bd431bbd7`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 83204 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["_Z19cec_Api_IsARCMuteOnv", "_ZN16cec_StateMachine11IsARCMuteOnEv", "_ZN18MW_CEC_MainWrapper17SendARCAudioEventEh7BBOOL_e", "_ZN18MW_CEC_MainWrapper26ReportShortAudioDescriptorEPK23CecShortAudioDescriptor"], "examples_are_complete": true}, {"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["_ZN16MW_CEC_IrWrapper11PowerUpInitEPFv17Cec_Ir_Key_Pair_sE", "_ZN6cec_Ir6GetKeyEP17Cec_Ir_Key_Pair_s"], "examples_are_complete": true}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 133, "symbol_examples": ["_Z16IsExpectedPhyAdrPKhP20CecPhysicalAddress_s", "_Z19cec_Api_IsARCMuteOnv", "_Z19cec_Api_PowerUpInitv", "_Z19cec_Api_UserCommand17Cec_UserCommand_ePKv", "_Z19cec_Api_isARCActivev", "_Z21cec_Api_KillOperationv", "_Z25cec_Api_ScheduledBySystemv", "_Z26cec_Api_IsCECInitCompletedv", "_Z31cec_Api_DeviceDiscover_DevCountv", "_Z36cec_Api_getSelectedDevicePowerStatush", "_Z45cec_Api_GetSourceIdCorrespondingToGivenPhyAdrPK20CecPhysicalAddress_s", "_ZN14cec_Controller11PowerUpInitEv", "_ZN14cec_Controller18IsCECInitCompletedEv", "_ZN16MW_CEC_IrWrapper11PowerUpInitEPFv17Cec_Ir_Key_Pair_sE", "_ZN16MW_CEC_IrWrapper20SetSelectedDevLogAdrE19CecLogicalAddress_e", "_ZN16MW_CEC_IrWrapper26ForwardIncomingKeyToSystemEj"], "examples_are_complete": false}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["_ZN18MW_CEC_MainWrapper14IsARCsettingONEv"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 106 / 113.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 247; semboller: 1884.
- Xref: 4677; analizde call tipli xref: 0.
- Computed-call instruction: 1265 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/6177c73cfd0cca039e1aacf2fb721f693812b18a9282f2980d5c255bd431bbd7/functions.jsonl) · [Xref](../../../analiz/native/system-modules/6177c73cfd0cca039e1aacf2fb721f693812b18a9282f2980d5c255bd431bbd7/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/6177c73cfd0cca039e1aacf2fb721f693812b18a9282f2980d5c255bd431bbd7/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/6177c73cfd0cca039e1aacf2fb721f693812b18a9282f2980d5c255bd431bbd7/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f04509c` | `cec_CommonDataStorage::SetOwnLogicalAddress` | [C](../../../analiz/native/system-modules/6177c73cfd0cca039e1aacf2fb721f693812b18a9282f2980d5c255bd431bbd7/2f04509c.c) |
| `2f0450b4` | `cec_CommonDataStorage::SetNrOfAvailableHdmiInputs` | [C](../../../analiz/native/system-modules/6177c73cfd0cca039e1aacf2fb721f693812b18a9282f2980d5c255bd431bbd7/2f0450b4.c) |
| `2f045120` | `cec_CommonDataStorage::GetOwnLogicalAddress` | [C](../../../analiz/native/system-modules/6177c73cfd0cca039e1aacf2fb721f693812b18a9282f2980d5c255bd431bbd7/2f045120.c) |
| `2f045138` | `cec_CommonDataStorage::GetNrOfAvailableHdmiInputs` | [C](../../../analiz/native/system-modules/6177c73cfd0cca039e1aacf2fb721f693812b18a9282f2980d5c255bd431bbd7/2f045138.c) |
| `2f045304` | `cec_Controller::IsCECInitCompleted` | [C](../../../analiz/native/system-modules/6177c73cfd0cca039e1aacf2fb721f693812b18a9282f2980d5c255bd431bbd7/2f045304.c) |
| `2f046588` | `cec_DeviceDiscover::DevCount` | [C](../../../analiz/native/system-modules/6177c73cfd0cca039e1aacf2fb721f693812b18a9282f2980d5c255bd431bbd7/2f046588.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
