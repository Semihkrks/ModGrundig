# `07_MSLIB/libfreetype.so.6.11.2`

SHA-256: `9bb5e5dd922a4f2b758d3a9ec7242bf8ccd979c72b2b811082820ad9ce115aaf`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 939648 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[{"category": "resource_brand_osd_directfb_muf", "classification": "inferred", "confidence": "name_based_only", "filename_match": false, "matching_symbol_count": 16, "symbol_examples": ["FT_Bitmap_Convert", "FT_Bitmap_Copy", "FT_Bitmap_Done", "FT_Bitmap_Embolden", "FT_Bitmap_New", "FT_Get_PS_Font_Info", "FT_Get_PS_Font_Private", "FT_Get_PS_Font_Value", "FT_Get_X11_Font_Format", "FT_GlyphSlot_Own_Bitmap", "FT_Glyph_To_Bitmap", "FT_Outline_Get_Bitmap", "ft_bitmap_glyph_class", "ft_glyphslot_alloc_bitmap", "ft_glyphslot_free_bitmap", "ft_glyphslot_set_bitmap"], "examples_are_complete": true}]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libz.so.1`, `libc.so.6`
- Dynamic import/export: 32 / 441.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 1547; semboller: 10293.
- Xref: 85817; analizde call tipli xref: 0.
- Computed-call instruction: 4521 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/9bb5e5dd922a4f2b758d3a9ec7242bf8ccd979c72b2b811082820ad9ce115aaf/functions.jsonl) · [Xref](../../../analiz/native/system-modules/9bb5e5dd922a4f2b758d3a9ec7242bf8ccd979c72b2b811082820ad9ce115aaf/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/9bb5e5dd922a4f2b758d3a9ec7242bf8ccd979c72b2b811082820ad9ce115aaf/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/9bb5e5dd922a4f2b758d3a9ec7242bf8ccd979c72b2b811082820ad9ce115aaf/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2e037720` | `ft_debug_init` | [C](../../../analiz/native/system-modules/9bb5e5dd922a4f2b758d3a9ec7242bf8ccd979c72b2b811082820ad9ce115aaf/2e037720.c) |
| `2e03a4dc` | `ft_validator_init` | [C](../../../analiz/native/system-modules/9bb5e5dd922a4f2b758d3a9ec7242bf8ccd979c72b2b811082820ad9ce115aaf/2e03a4dc.c) |
| `2e04242c` | `FT_Get_Renderer` | [C](../../../analiz/native/system-modules/9bb5e5dd922a4f2b758d3a9ec7242bf8ccd979c72b2b811082820ad9ce115aaf/2e04242c.c) |
| `2e0370b0` | `_init` | [C](../../../analiz/native/system-modules/9bb5e5dd922a4f2b758d3a9ec7242bf8ccd979c72b2b811082820ad9ce115aaf/2e0370b0.c) |
| `2e0427cc` | `FT_Render_Glyph` | [C](../../../analiz/native/system-modules/9bb5e5dd922a4f2b758d3a9ec7242bf8ccd979c72b2b811082820ad9ce115aaf/2e0427cc.c) |
| `2e056e20` | `FT_Get_X11_Font_Format` | [C](../../../analiz/native/system-modules/9bb5e5dd922a4f2b758d3a9ec7242bf8ccd979c72b2b811082820ad9ce115aaf/2e056e20.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
