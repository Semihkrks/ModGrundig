# `07_MSLIB/utopia/libdrvMSPI.so`

SHA-256: `88b1538204b40f55b47dea0de092629e32f55c5985f526b7c4af9b2c08e70118`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 25004 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 1, "symbol_examples": ["MDrv_MSPI_SetPowerState"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 6, "symbol_examples": ["UtopiaModuleAddResourceEnd", "UtopiaModuleAddResourceStart", "UtopiaResourceCreate", "UtopiaResourceObtain", "UtopiaResourceRegister", "UtopiaResourceRelease"], "examples_are_complete": true}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 18, "symbol_examples": ["HAL_MSPI_CLKConfigMax", "HAL_MSPI_CLOCK_Config", "HAL_MSPI_DCConfigMax", "HAL_MSPI_FrameConfigMax", "HAL_MSPI_MMIOConfig", "HAL_MSPI_Reset_CLKConfig", "HAL_MSPI_Reset_DCConfig", "HAL_MSPI_Reset_FrameConfig", "MDrv_MSPI_CLKConfig", "MDrv_MSPI_DCConfig", "MDrv_MSPI_FRAMEConfig", "MDrv_MasterSPI_CLKConfig", "MDrv_MasterSPI_CsPadConfig", "MDrv_MasterSPI_DCConfig", "MDrv_MasterSPI_FRAMEConfig", "MDrv_MasterSPI_MaxClkConfig"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libc.so.6`
- Dynamic import/export: 25 / 61.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 76; semboller: 361.
- Xref: 988; analizde call tipli xref: 0.
- Computed-call instruction: 193 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/88b1538204b40f55b47dea0de092629e32f55c5985f526b7c4af9b2c08e70118/functions.jsonl) · [Xref](../../../analiz/native/system-modules/88b1538204b40f55b47dea0de092629e32f55c5985f526b7c4af9b2c08e70118/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/88b1538204b40f55b47dea0de092629e32f55c5985f526b7c4af9b2c08e70118/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/88b1538204b40f55b47dea0de092629e32f55c5985f526b7c4af9b2c08e70118/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f483e5c` | `HAL_MSPI_Init` | [C](../../../analiz/native/system-modules/88b1538204b40f55b47dea0de092629e32f55c5985f526b7c4af9b2c08e70118/2f483e5c.c) |
| `2f4810f4` | `_init` | [C](../../../analiz/native/system-modules/88b1538204b40f55b47dea0de092629e32f55c5985f526b7c4af9b2c08e70118/2f4810f4.c) |
| `2f482e30` | `MDrv_MSPI_SetPowerState` | [C](../../../analiz/native/system-modules/88b1538204b40f55b47dea0de092629e32f55c5985f526b7c4af9b2c08e70118/2f482e30.c) |
| `2f4826fc` | `MDrv_MasterSPI_Init` | [C](../../../analiz/native/system-modules/88b1538204b40f55b47dea0de092629e32f55c5985f526b7c4af9b2c08e70118/2f4826fc.c) |
| `2f4828f8` | `MDrv_MSPI_Init` | [C](../../../analiz/native/system-modules/88b1538204b40f55b47dea0de092629e32f55c5985f526b7c4af9b2c08e70118/2f4828f8.c) |
| `2f482af4` | `MDrv_MSPI_Init_Ext` | [C](../../../analiz/native/system-modules/88b1538204b40f55b47dea0de092629e32f55c5985f526b7c4af9b2c08e70118/2f482af4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
