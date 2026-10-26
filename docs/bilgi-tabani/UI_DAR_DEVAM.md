# UI dar devam: resim sağlayıcısı ve varsayılan factory

22 Ekim 2026. Kalan kota gözetilerek dört küçük mevcut fonksiyon sorgulandı; 4/4 C tamamlandı. Yeni tüm-modül taraması yapılmadı. Salt okunur Ghidra sorgularının metadata değişiklikleri atıldı; firmware çalıştırılmadı/değiştirilmedi. Beceri: `reverse-engineer-anything`.

## Kaynak ID/MImg → provider oluşturma

- [GetDFBImage(ID) `0x2e23b90c`](../../analiz/native/ui-targeted/provider-entry2/2e23b90c.c): MSystem içindeki DirectFB nesnesi null ise assert/abort. `RcGetImage` callsite `2e23b968` kaynak yolunu ve yardımcı u32 çıktıyı alır; bu u32 çağıranın out alanına yazılır (`2e23b97c`). DirectFB `+0x48` slotu `a0=interface, a1=resource-path, a2=&provider` ile çağrılır (`2e23b984`). Sayısal status 0 ise provider döner, aksi durumda 0.
- [GetDFBImage(MImg) `0x2e23b688`](../../analiz/native/ui-targeted/provider-entry2/2e23b688.c): `QueryFlag(1)` nonzero ise ilk u16 resource ID olarak `RcGetImage` yoluna gider. Diğer dalda `std::string::assign` kaynağı **MImg+4** adresidir: `2e23b714 addiu a1,s3,0x4`, `2e23b718 jalr`, delay-slot `a0=s1`. Decompiler'ın tek argümanlı assign gösterimi eksiktir. Boş string ise provider çağrısı atlanır; diğer durumda `+0x48` callsite `2e23b748`. ID dalına girilmediyse yardımcı out değer `0xffffffff` kalır; bu değerin ürün düzeyindeki adı henüz belirlenmedi.

[ID assembly/pcode](../../analiz/native/ui-targeted/provider-entry2/2e23b90c.json) · [MImg assembly/pcode](../../analiz/native/ui-targeted/provider-entry2/2e23b688.json). İki gövdede toplam 228 instruction vardır. İki `+0x48` çağrı hedefi yerel pcode'da belirsizdir; önceki constructor store `2de4425c` statik hedef adayı `2de47608` verir. O gövde ve provider `+0x10/+0x18/+0xc` implementasyon seçimi henüz çözülmedi. Slotun giriş/çıkışlarını öğrenmek runtime provider sınıfını kanıtlamaz.

## GetDefault seçimi ve IdleAppApp adayı

[MAppFactory::GetDefault `0x00daf324`](../../analiz/native/ui-targeted/default-factory2/00daf324.c) root'tan başlar. Her nesnenin vtable `+0xc` predicate'ini çağırır (`daf36c`); nonzero sonuçta o nesneyi döndürür. Sıfırsa `Next` (`daf398`) ile ilerler. Liste biterse **root'a geri döner**; null return yalnız root da null ise mümkündür. Factory listesinin runtime sırası ve root'un hangi nesne olduğu hâlâ açık.

`MAppFactory_IdleAppApp` vtable `0x010be9b0`, primary address-point `0x010be9b8`:

| Slot | Hedef | Kanıt |
|---|---|---|
| `+8` | `0x00d6401c` | [Creator C](../../analiz/native/ui-targeted/default-factory2/00d6401c.c): `operator new(0x3c)` → `IdleAppApp::IdleAppApp` → nesne dönüşü. Constructor callsite `d64068`. |
| `+0xc` | `0x00d639e8` | [Ham on-word karşılaştırması](../../analiz/default-factory-predicate-stubs.json): `addu v0,zero,zero`, epilog ve `jr ra`; sabit 0 döndürür. |

Bu nedenle **IdleAppApp predicate üzerinden seçilmiş default diye ilan edilemez**. Root/fallback bu factory ise `+8` creator IdleAppApp üretir; aktif root hâlâ kanıtlanmadı. Vtable kayıt kaynağı [UI yapı haritasıdır](../../analiz/ui-yapi-haritasi.json). [GetDefault assembly](../../analiz/native/ui-targeted/default-factory2/00daf324.json), [creator assembly](../../analiz/native/ui-targeted/default-factory2/00d6401c.json).

Öncelikli devam: `MAppFactory::root` yazımları/kayıt sırası, provider oluşturucu `2de47608` ve plugin constructor'ları. Mevcut 226 modül indeksi veya eski büyük UI timeout sorguları bu dar çalışma için tekrar çalıştırılmadı.

23 Ekim devamı: [factory constructor, Next ve static init zinciri](UI_FACTORY_KAYDI.md) beş ek C gövdesiyle bağlandı. Global Idle factory kaydı bulunmuştur; aktif root sırası ve CRT yürüyüşü açık kalır.

Son kontrol: dört yeni C gövdesinin sınır dışı pcode adresi yok; C hash'leri, kaynak ELF hash'i ve predicate'in on ham word'ü kaydedildi. Factory/provider yorumu ayrı ajan tarafından doğrulandı. [Kontrol kaydı](../../analiz/ui-dar-devam-dogrulama.json).
