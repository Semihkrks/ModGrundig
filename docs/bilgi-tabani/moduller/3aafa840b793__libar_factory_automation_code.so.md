# `07_MSLIB/libar_factory_automation_code.so`

SHA-256: `3aafa840b793c4136fa97ad57fcb7023404cd0621bfa5847885490338dd830d8`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 71768 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 6, "symbol_examples": ["_Z21checkIfValidAudio_Sysh", "_Z21checkIfValidSoundModeh", "_Z21checkIfValidSoundTypeh", "_Z31factoryplug_checkValidAudio_Sysh", "_Z31factoryplug_checkValidSoundModeh", "_Z31factoryplug_checkValidSoundTypeh"], "examples_are_complete": true}, {"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 4, "symbol_examples": ["_Z31factoryplug_getRC5CAResultReadyv", "_Z31factoryplug_setRC5CAResultReadyh", "_Z33factoryplug_setRC5CAResultRequesth", "_Z36factoryplug_isColorAnalyzerSourceRC5v"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["_Z25factoryplug_setOSDPatternh"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 114 / 90.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 180; semboller: 997.
- Xref: 2964; analizde call tipli xref: 0.
- Computed-call instruction: 706 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 3/3.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/3aafa840b793c4136fa97ad57fcb7023404cd0621bfa5847885490338dd830d8/functions.jsonl) · [Xref](../../../analiz/native/system-modules/3aafa840b793c4136fa97ad57fcb7023404cd0621bfa5847885490338dd830d8/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/3aafa840b793c4136fa97ad57fcb7023404cd0621bfa5847885490338dd830d8/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/3aafa840b793c4136fa97ad57fcb7023404cd0621bfa5847885490338dd830d8/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f66ae74` | `factoryuart_initMessageTable` | [C](../../../analiz/native/system-modules/3aafa840b793c4136fa97ad57fcb7023404cd0621bfa5847885490338dd830d8/2f66ae74.c) |
| `2f663768` | `_init` | [C](../../../analiz/native/system-modules/3aafa840b793c4136fa97ad57fcb7023404cd0621bfa5847885490338dd830d8/2f663768.c) |
| `2f663b24` | `ArWhiteBalance::UpdateLowLimits` | [C](../../../analiz/native/system-modules/3aafa840b793c4136fa97ad57fcb7023404cd0621bfa5847885490338dd830d8/2f663b24.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
