# `07_MSLIB/directfb-1.4-0/systems/libdirectfb_devmem.so`

SHA-256: `67eb99802aa2ce3a114fd674def35879afa11a5b5dea5e92ac42ac2a4303b852`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 43556 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": true, "matching_symbol_count": 4, "symbol_examples": ["dfb_layer_context_windowstack", "dfb_windowstack_lock", "dfb_windowstack_unlock", "dfb_wm_enum_windows"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 2, "symbol_examples": ["dfb_config", "direct_config"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libz.so.1`, `libm.so.6`, `libdirect-1.4.so.0`, `libfusion-1.4.so.0`, `libdirectfb-1.4.so.0`, `libdl.so.2`, `librt.so.1`, `libpthread.so.0`, `libdrvMVOP.so`, `libapiGFX.so`, `libapiGOP.so`, `liblinux.so`, `libdrvVE.so`, `libapiXC.so`, `libapiPNL.so`, `libdrvWDT.so`, `libdrvSAR.so`, `libapiVDEC.so`, `libdrvIPAUTH.so`, `libapiJPEG.so`, `libc.so.6`
- Dynamic import/export: 81 / 11.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 181; semboller: 688.
- Xref: 910; analizde call tipli xref: 0.
- Computed-call instruction: 275 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 1/1.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/67eb99802aa2ce3a114fd674def35879afa11a5b5dea5e92ac42ac2a4303b852/functions.jsonl) · [Xref](../../../analiz/native/system-modules/67eb99802aa2ce3a114fd674def35879afa11a5b5dea5e92ac42ac2a4303b852/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/67eb99802aa2ce3a114fd674def35879afa11a5b5dea5e92ac42ac2a4303b852/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/67eb99802aa2ce3a114fd674def35879afa11a5b5dea5e92ac42ac2a4303b852/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `000116e8` | `_init` | [C](../../../analiz/native/system-modules/67eb99802aa2ce3a114fd674def35879afa11a5b5dea5e92ac42ac2a4303b852/000116e8.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
