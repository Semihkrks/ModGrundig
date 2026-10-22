# `07_MSLIB/libmuf.so`

SHA-256: `494d4aa45a3c8d8e10760388d8d30111e9127a0357d38cdf97979b9f9bb16d96`

Durum: **Önceki Ghidra + odaklı UI analizi**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 801804 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "ir_key_remote", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 41, "symbol_examples": ["_ZN10MMainFrame5OnKeyEPvS0_S0_", "_ZN10NumberEdit5OnKeyEPvS0_S0_", "_ZN10SpinButton5OnKeyEPvS0_S0_", "_ZN10TextEditor5OnKeyEPvS0_S0_", "_ZN11ComboButton5OnKeyEPvS0_S0_", "_ZN12AbsContainer17DefaultKeyHandlerEmm", "_ZN12TabContainer17DefaultKeyHandlerEmm", "_ZN12ToggleButton5OnKeyEPvS0_S0_", "_ZN13GridContainer17DefaultKeyHandlerEmm", "_ZN13ListContainer17DefaultKeyHandlerEmm", "_ZN13MultiModePage5OnKeyEPvS0_S0_", "_ZN13ScrollTextBox5OnKeyEPvS0_S0_", "_ZN14GridProgEditor17DefaultKeyHandlerEmm", "_ZN14GridProgEditor5OnKeyEPvS0_S0_", "_ZN14MWindowManager13CheckKeyEventEm", "_ZN14MWindowManager14FlushKeyEventsEv"], "examples_are_complete": false}, {"category": "cec_source_power", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 6, "symbol_examples": ["_ZN14MWindowManager29RegisterMSrvActiveStandbyModeEP4MSrv", "_ZN14MWindowManager9WakeUpMUFEv", "_ZN7MApplet6WakeupEm", "_ZN7MSystem20GetActiveStandbyModeEv", "_ZN7MSystem20SetActiveStandbyModeEh", "_ZN7MSystem20m_bStandbyModeActiveE"], "examples_are_complete": true}, {"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 463, "symbol_examples": ["DirectFBCreate", "DirectFBError", "DirectFBInit", "DirectFBSetOption", "_Z13util_get_fontmt", "_Z18util_get_font_pathj", "_Z20_MUF_PlayGifCallbackPv", "_ZN10MMainFrame10MoveWindowEii", "_ZN10MMainFrame11AddWdgInsIDEP7MWidgeti", "_ZN10MMainFrame12GetDFBWindowEv", "_ZN10MMainFrame12MoveWindowToEii", "_ZN10MMainFrame12ResizeWindowEii", "_ZN10MMainFrame13SwitchFocusToEP7MWidget", "_ZN10MMainFrame14RecreateWindowEv", "_ZN10MMainFrame14RemoveWdgInsIDEP7MWidgeti", "_ZN10MMainFrame15CreateDFBWindowEP22_IDirectFBDisplayLayer"], "examples_are_complete": false}, {"category": "settings_database", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 18, "symbol_examples": ["_ZN14GridProgEditor10ConfigItemERSt6vectorI5_RectSaIS1_EES4_P16ImgContentConfigP14TextImageMixer", "_ZN14GridProgEditor10ConfigItemERSt6vectorI5_RectSaIS1_EES4_P17TextContentConfigP14TextImageMixer", "_ZN14GridProgEditor10ConfigItemERSt6vectorI5_RectSaIS1_EES4_P17TextContentConfigP16ImgContentConfigP14TextImageMixer", "_ZN14GridProgEditor15UpdateDataModelERSt6vectorI5_RectSaIS1_EES4_RS0_IP17TextContentConfigSaIS6_EERS0_IP16ImgContentConfigSaISB_EEPm", "_ZN14GridProgEditor9DataModelERSt6vectorI5_RectSaIS1_EES4_RS0_IP17TextContentConfigSaIS6_EERS0_IP16ImgContentConfigSaISB_EEPml", "_ZN14ProgInfoEditor10ConfigItemERSt6vectorI5_RectSaIS1_EES4_P16ImgContentConfigP14TextImageMixer", "_ZN14ProgInfoEditor10ConfigItemERSt6vectorI5_RectSaIS1_EES4_P17TextContentConfigP14TextImageMixer", "_ZN14ProgInfoEditor10ConfigItemERSt6vectorI5_RectSaIS1_EES4_P17TextContentConfigP16ImgContentConfigP14TextImageMixer", "_ZN14ProgInfoEditor15UpdateDataModelERSt6vectorI5_RectSaIS1_EES4_RS0_IP17TextContentConfigSaIS6_EERS0_IP16ImgContentConfigSaISB_EEPm", "_ZN14ProgInfoEditor9DataModelERSt6vectorI5_RectSaIS1_EES4_RS0_IP17TextContentConfigSaIS6_EERS0_IP16ImgContentConfigSaISB_EEPml", "_ZN14TextImageMixer14SetTextContentEPK17TextContentConfig", "_ZN14TextImageMixer15SetImageContentEPK16ImgContentConfig", "_ZN14TextImageMixer15SetImageContentEPK19NewImgContentConfig", "_ZN14TextImageMixer9SetLayOutEPK16TextLayoutConfigPK15ImgLayoutConfig", "_ZN7EPGItem15SetFieldContentEP18FieldContentConfig", "_ZN7EPGItem15SetImageContentEP16ImgContentConfig"], "examples_are_complete": false}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `librt.so.1`, `libpthread.so.0`, `libdirectfb-1.4.so.0`, `libicuuc.so.42`, `libicule.so.42`, `libdfbinfo.so`, `libjpeg.so.62`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 176 / 1909.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Koddan doğrulanan UI davranışları

[UI yapı ve davranış raporu](../../UI_KOD_YAPISI.md) ve [ses/menü ayrıntıları](../../UI_HARITASI.md).

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
