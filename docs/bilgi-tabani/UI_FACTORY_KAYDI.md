# UI factory kaydı ve açılışa bağlantı

23 Ekim 2026. Önceki [dar UI devamından](UI_DAR_DEVAM.md) ilerlenmiştir. Beş mevcut fonksiyon için 5/5 C, 134 instruction; sınır dışı pcode yok. Doğrudan Ghidra sorguları salt okunurdur; kaynak firmware çalıştırılmadı/değiştirilmedi. Kullanılan beceri `reverse-engineer-anything`.

| Giriş | Koddan doğrulanan görev | Kanıt |
|---|---|---|
| `0xd6398c` MAppFactory ctor | Base vtable yazar; `this+4=eski root`, ardından `root=this`. Yeni kayıt listenin başına eklenir. | [C](../../analiz/native/ui-targeted/factory-registration3/00d6398c.c) / [assembly](../../analiz/native/ui-targeted/factory-registration3/00d6398c.json) |
| `0xd63ab8` Idle factory ctor | Base ctor çağrısından sonra vtable address-point `0x10be9b8` yazar. | [C](../../analiz/native/ui-targeted/factory-registration3/00d63ab8.c) / [assembly](../../analiz/native/ui-targeted/factory-registration3/00d63ab8.json) |
| `0xdaf2f8` Next | `this+4` word değerini döndürür. | [C](../../analiz/native/ui-targeted/factory-registration3/00daf2f8.c) / [assembly](../../analiz/native/ui-targeted/factory-registration3/00daf2f8.json) |
| `0xd63e8c` static init helper | Yalnız `(1,0xffff)` koşulunda global `0x10d7abc` nesnesi için Idle factory ctor çağırır; destructor'ı `__cxa_atexit` ile kaydeder. | [C](../../analiz/native/ui-targeted/factory-static-init2/00d63e8c.c) / [assembly](../../analiz/native/ui-targeted/factory-static-init2/00d63e8c.json) |
| `0xd63f64` static init wrapper | Helper'ı `(1,0xffff)` ile çağırır. | [C](../../analiz/native/ui-targeted/factory-static-init2/00d63f64.c) / [assembly](../../analiz/native/ui-targeted/factory-static-init2/00d63f64.json) |

Ana ELF `.ctors` tablosunda **VA `0x10b8110` → `0xd63f64`** kaydı vardır. Tabloda 157 word bulunur; bunun tamamı 157 constructor demek değildir, sentinel kayıtları ayrı yorumlanmalıdır. `MAppFactory::root` sembolü `0x10d7d58`, boyut 4'tür.

Bu kayıtlar şu statik zinciri kurar: `.ctors` kaydı → wrapper → koşullu helper → global Idle factory ctor → base ctor → root/list kaydı. Önceki creator `0xd6401c` (`new(0x3c)` → IdleAppApp) ve GetDefault `0xdaf324` bulgularıyla birlikte değerlendirilir. Idle factory predicate'i hâlâ sabit 0'dır; listede predicate-nonzero bulunmazsa GetDefault root'a döner.

**Sınır:** CRT'nin `.ctors` dolaşım gövdesi ve bütün olası root yazımları/dinamik kayıtlar henüz bu aşamada incelenmedi. Dolayısıyla aktif cihazın varsayılan app'inin kesin IdleAppApp olduğu ilan edilmez. Kayıt yapısının push-front olması, son kayıt sırasını tek başına belirlemez.

## Değişikliğe geçiş için durum

| Değişiklik alanı | Hazır bilgi | Kalan eşik |
|---|---|---|
| Ses panelinin görselleri/renkleri | Dosya/ID, rect, tema ve dört ses modu adresli | Seçilen kaynağın ortak kullanım etkisini sınırla; hedef tasarımı belirle. |
| Ses paneli geometri/davranış | Volume Init/Refresh/OnKey/Timer ve 3 s kapanış yolu | Değiştirilecek davranışın normal/mute/ARC dallarını birlikte kontrol et. |
| Menü geçişleri/animasyon | 50 ms tick, süre yuvarlaması, belirli çağıran gate'leri | Sabit 0 animation getter'ının kapsamı ve seçilen ekranın çağıranları. |
| Bütün menüler | Event/resource haritaları ve çok sayıda callback | Dört büyük UI gövdesinin kalan CFG blokları; focus/back/error yolları. |
| TV'ye uygulanabilir paket | Çıkarım, CRC ve bölüm haritası | Güncelleme kabul/imza yolu, model uyumu ve ayrı cihazda yazma yetkisi. |

Çalışma tahmini: tek bir ekranın, özellikle ses panelinin değişiklik planına **1–2 odaklı oturum** sonra geçilebilir. Bu bir planlama tahminidir; bütün UI'nin bitiş veya TV'ye yükleme tarihi değildir. Bütün 226 modülün semantik incelemesi, seçilen ekranın tasarımını planlamak için ön koşul yapılmaz. Şu anki analiz yetkisiyle arayüz veya firmware değişikliği uygulanmadı.

Sonraki dar işler: root pointer'a başka yazımlar; CRT constructor yürüyüşü; provider `2de47608` gövdesi; seçilecek ekranın ortak kaynak kullanımının sınırlandırılması.

Doğrulama: kaynak SHA-256 ve ham `.ctors` pointer'ı eşleşti; beş C/assembly çıktısının hash'leri kaydedildi, sınır dışı pcode ve kırık yerel belge bağlantısı bulunmadı. [Makine kaydı](../../analiz/ui-factory-kaydi-dogrulama.json). Güncel odaklı kapsam **179 giriş / 175 tamamlanmış C**; dört eski büyük UI boşluğu korunur.
