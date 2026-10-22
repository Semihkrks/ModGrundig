# MUF → DirectFB callback gövdeleri

22 Ekim 2026. Kaynak `07_MSLIB/libdirectfb-1.4.so.0.2.0`, SHA-256 `b05201025cab0dd8734708702a910ff54d24eb723e782c0994a26361194c5bf3`. Adlar harici sürüm tablosundan alınmadı: bu firmware'in gövdelerindeki log argümanları, constructor pointer yazımları ve kod davranışı birlikte kullanıldı.

[Makine bulguları](../../analiz/native/directfb-callbacks-v1/findings.json) ve [çalışma kaydı](../../analiz/native/directfb-callbacks-v1/README.md). Canonical çalışma **attempt1**; ilk kök log başarısız derleme denemesidir.

| Surface slotu | Hedef ve C kanıtı | Gövdeden doğrulanan davranış |
|---|---|---|
| `+0x5c` | [SetSrcBlendFunction `2de506d0`](../../analiz/native/directfb-callbacks-v1/attempt1/2de506d0.c) | 1..12 normal değer; özel `0x100` bitli yol ayrı. State ve dirty mask günceller; geçersiz değer sayısal 9. |
| `+0x60` | [SetDstBlendFunction `2de504e4`](../../analiz/native/directfb-callbacks-v1/attempt1/2de504e4.c) | 1..11 aralığı; state `+0x108`, dirty OR `0x20`; geçersiz değer 9. |
| `+0x68` | [SetSrcColorKey `2de5c164`](../../analiz/native/directfb-callbacks-v1/attempt1/2de5c164.c) | RGB'yi byte'a indirger; palette araması veya pixel-from-color dönüşümü; sonucu `+0x2a0` alanına saklar. |
| `+0x78` | [SetBlittingFlags `2de4f450`](../../analiz/native/directfb-callbacks-v1/attempt1/2de4f450.c) | Flag değiştiğinde `+0xe0` yazımı ve dirty OR 2. |
| `+0x88` | [StretchBlit `2de5aac8`](../../analiz/native/directfb-callbacks-v1/attempt1/2de5aac8.c) | Surface/rect kontrolleri, offset ve kaynak kırpması; hedef rect'i orantılar. `dfb_gfxcard_stretchblit` çağrısı ve dönüşü. |
| `+0xd8` | [ReleaseSource `2de56064`](../../analiz/native/directfb-callbacks-v1/attempt1/2de56064.c) | State source ve source-mask alanlarını null yapar. |
| `+0x100` | [SetAlphaCmpMode `2de50308`](../../analiz/native/directfb-callbacks-v1/attempt1/2de50308.c) | Değer `+0x110`, dirty OR `0x100000`; bu gövdede sayısal aralık kontrolü görülmedi. |
| `+0xc` | [Release `2de5dde0`](../../analiz/native/directfb-callbacks-v1/attempt1/2de5dde0.c) | Refcount `+0xc` azaltılır; sıfıra indiğinde surface destructor. |

Constructor kanıtı: [IDirectFBSurface_Construct](../../analiz/native/system-focused/b05201025cab0dd8734708702a910ff54d24eb723e782c0994a26361194c5bf3/interface-abi3/2de4d8e8.c), instruction store adresleri sırasıyla `2de4dc3c`, `2de4dc68`, `2de4dca4`, `2de4dce8`, `2de4dd18`, `2de4de2c`, `2de4dc54`, `2de4db38`.

MUF kullanım kanıtları: [RenderImageToSurface](../../analiz/native/ui-targeted/render-core5/2e23cf84.c), [DoRender](../../analiz/native/ui-targeted/render-core5/2e23ba7c.c), [MImg overload](../../analiz/native/ui-targeted/render-core5/2e23e684.c). Örneğin `2e23d168` surface `+0x5c`, `2e23d178` `+0x60`, `2e23d0a8` `+0x88`, `2e23d0b4` `+0xd8`, `2e23bbcc` `+0xc` çağrılarıdır. Ana IDirectFB nesnesinin `+0x20` slotu constructor store `2de441e4` ile `2de4948c` hedefine bağlanır; gövdesi bu sekizli kapsamda değildir.

Provider nesnesinin **`+0x10/+0x18/+0xc` hedefleri çözülmedi**. Surface ile aynı sayısal offset, aynı callback anlamına gelmez. Provider çağrı noktaları `2e23bafc/2e23bb40/2e23bb54`.

## Kapsam ve sınırlar

8/8 decompile; 1.218 instruction, 88 decompiler callsite. Sekiz giriş MIPS `.pdr` kayıtlarına birebir eşleşir; sonraki procedure girişleri exclusive üst sınır sağlar. Eksik instruction ve gövde dışı pcode yok. Bu 88 kayıtta çözülemeyen sabit hedef yok; firmware'in bütün dolaylı çağrılarının çözüldüğü anlamına gelmez.

Ghidra'da eksik fonksiyonlar yalnız kaydedilmeyen analiz bağlamında oluşturuldu. Hedef hash'i önce/sonra eşit; metadata değişiklikleri atıldı. Doğrudan Ghidra çıktısıdır, REA Evidence değildir. Numeric enum adları, gerçek typedef/struct/prototipler, fiziksel runtime seçimi ve alt callee gövdeleri açık kalır. Kaydedilmiş varsayılan `void` imzalar yerine C ve assembly argümanları birlikte incelenmelidir.
