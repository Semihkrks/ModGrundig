# `07_MSLIB/libar_mmrgLibrary.so`

SHA-256: `7bd6342bb20f507c91ef42e13ac3ae1c69e639857afa0f4bef0d57db71401681`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 110020 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "audio_volume_sound", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 3, "symbol_examples": ["_ZN14mmrgImageCodec22m_pcMemoryInstance_DFBE", "_ZN14mmrgImageCodec25m_pcMemoryInstance_OpencvE", "_ZN14mmrgImageCodec28m_pcMemoryInstance_SupernovaE"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 47, "symbol_examples": ["DirectFBCreate", "_ZN11mmrgFactory22createDrawTextInstanceEv", "_ZN12mmrgDrawText11getInstanceEv", "_ZN12mmrgDrawTextD0Ev", "_ZN12mmrgDrawTextD1Ev", "_ZN12mmrgDrawTextD2Ev", "_ZN16mmrgDrawText_DFB10imDrawTextER9mmrgImageiiSs", "_ZN16mmrgDrawText_DFB11SetFontPathESs", "_ZN16mmrgDrawText_DFB11getInstanceEv", "_ZN16mmrgDrawText_DFB13SetTextHeightEi", "_ZN16mmrgDrawText_DFBC1Ev", "_ZN16mmrgDrawText_DFBC2Ev", "_ZN16mmrgDrawText_DFBD0Ev", "_ZN16mmrgDrawText_DFBD1Ev", "_ZN16mmrgDrawText_DFBD2Ev", "_ZN25mmrgDrawText_LookUp_Table10String2IntERSs"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libstdc++.so.6`, `libm.so.6`, `libgcc_s.so.1`, `libc.so.6`
- Dynamic import/export: 97 / 263.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 293; semboller: 2203.
- Xref: 6204; analizde call tipli xref: 0.
- Computed-call instruction: 1823 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 5/5.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/7bd6342bb20f507c91ef42e13ac3ae1c69e639857afa0f4bef0d57db71401681/functions.jsonl) · [Xref](../../../analiz/native/system-modules/7bd6342bb20f507c91ef42e13ac3ae1c69e639857afa0f4bef0d57db71401681/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/7bd6342bb20f507c91ef42e13ac3ae1c69e639857afa0f4bef0d57db71401681/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/7bd6342bb20f507c91ef42e13ac3ae1c69e639857afa0f4bef0d57db71401681/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f07a398` | `mmrgDrawText_DFB::SetFontPath` | [C](../../../analiz/native/system-modules/7bd6342bb20f507c91ef42e13ac3ae1c69e639857afa0f4bef0d57db71401681/2f07a398.c) |
| `2f07a354` | `mmrgDrawText_DFB::GetFontPath` | [C](../../../analiz/native/system-modules/7bd6342bb20f507c91ef42e13ac3ae1c69e639857afa0f4bef0d57db71401681/2f07a354.c) |
| `2f076370` | `_init` | [C](../../../analiz/native/system-modules/7bd6342bb20f507c91ef42e13ac3ae1c69e639857afa0f4bef0d57db71401681/2f076370.c) |
| `2f080cf0` | `mmrgDrawText_LookUp_Table::SetFontPath` | [C](../../../analiz/native/system-modules/7bd6342bb20f507c91ef42e13ac3ae1c69e639857afa0f4bef0d57db71401681/2f080cf0.c) |
| `2f08071c` | `mmrgDrawText_LookUp_Table::GetFontPath` | [C](../../../analiz/native/system-modules/7bd6342bb20f507c91ef42e13ac3ae1c69e639857afa0f4bef0d57db71401681/2f08071c.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
