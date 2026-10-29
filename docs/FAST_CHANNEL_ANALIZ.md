# Hızlı kanal geçişi: mevcut gerçek açma/kapatma yolu

29 Ekim 2026. **Bu build'de Hızlı Kanal Geçişi gerçek bir kullanıcı ayarıdır.** Normal menü yolu `Ayarlar → Genel → Gelişmiş → Hızlı Kanal Geçişi → Evet` olarak kurulur. `Hayır=0`, `Evet=1`. Açıkken AV senkronizasyon timeout'u 200 ms, kapalıyken 2000 ms seçilir. Bu değerler kanal geçiş süresi ölçümü veya 1800 ms hızlanma garantisi değildir. Aktif TV veritabanının mevcut değeri bilinmiyor.

V7.9 ELF'i `861d97c013c4d56e093a69cf779abfa6ea78e6c17233af5d6b2b3ba075b0b4ea` ile orijinal `51f6bd24…` aynı açma/kapatma yolunu içeriyor. Özelliği açılmış gibi gösteren getter, varsayılan DB değişikliği veya BasicMode bypass yaması üretilmedi. Mevcut kullanıcı seçimi korunur; Evet seçimi gerçek kalıcı DB setter'ını ve runtime setter'ını çalıştırır.

## Etiket → olay → DB → runtime

| Katman | Adres / kanıt | Davranış |
|---|---|---|
| General OnCreate | `0xd17190`, `this+0x244` | ComboButton ID49; parent liste `this+0x19c`, ID7. |
| Etiket | `0xd1748c`, Str `0xd50` | English `Fast Zapping`, Turkish `Hızlı Kanal Geçişi`. |
| Seçenekler | `0xd2354c`, `0xd23568` | Sırasıyla Str `0xe39=Hayır`, `0x106c=Evet`; dizi iki elemanlı. |
| UI başlangıç seçimi | `0xd235bc–0xd235cc` | `ArTvSettingsManager::GetFastZapping()` sonucunu widget `+0x264` alanına koyar. |
| Message map | kayıt `0x010be354` | Event `0x16`, selector `[16,49,49,0]`, handler `0xcf58d8`. |
| UI handler | `0xcf58d8` | Widget `+0x264` seçimini uchar olarak settings setter'ına gönderir. |
| Settings setter | `0x53d508` | Aynı değeri DB setter'ına ve DTV player bulunursa player setter'ına verir. C çıktısındaki eksik argümanlar yerine MIPS `a0/a1` kullanıldı. |
| DB getter / setter | `0x2e5787e8` / `0x2e5843e8` | Mutex altında DB nesnesi `+0x37c8` okunur/yazılır; setter `SaveUserGeneralSettings()` çağırır. |
| Player setter | `0x2d4ccaa8` | Monitor varsa değere göre `SetAVSyncDelay(200/2000)` çağırır; null monitor için hata mesajı vardır. |
| Customer setter | `0x2dfd34bc` | `jr ra; sh a1,0x1d6(a0)`. İkinci instruction delay slot'ta gerçek alan yazımıdır; sekiz bayt olması boş stub olduğunu göstermez. |
| Her AV start | `0x2d9da078` | Canlı DB `GetFastZapping()` yeniden okunur; `0x2d9da2dc` 200, `0x2d9da330` 2000 seçer; monitor `+0x1d6` alanına yazar. |
| Timeout getter | `0x2d9cfeac` | `jr ra; lhu v0,0x1d6(a0)`. |

Kaynaklar: [General oluşturma C](../analiz/native/ui-four/general/bounded300/00d01710.c), [widget/etiket haritası](../analiz/native/ui-four/general/widget-resource-groups.json), [UI handler](../analiz/native-features/fast-channel/ui-v1/00cf58d8.c), [settings setter assembly](../analiz/native-features/fast-channel/ui-v1/0053d508.json), [DB setter](../analiz/native-features/fast-channel/db-v1/2e5843e8.c), [player setter](../analiz/native-features/fast-channel/dvb-v1/2d4ccaa8.c), [monitor Start](../analiz/native-features/fast-channel/common-v1/2d9da078.c).

## Hangi beklemeyi etkiler?

`MW_DTV_AVMonitor::DoVideoSync=0x2d9d6270` içinde decode frame, ses/PCR ve kaynak algılama koşullarından sonra şu yol vardır: monitor `+0x6e !=0` ve üst kontroller uygunken geçen zaman hesaplanır; `IsSyncDone()` sıfırsa sanal slot `+8` çağrılır. Base vtable relocation `0x2da87ee8`, bu slotu `GetAvSyncTimeout()` ile bağlar. [Customer constructor](../analiz/native-features/fast-channel/customer-v2/2dfd3554.c), vptr'ı `0x2e028250` olarak kurar; customer vtable relocation `0x2e028258` de aynı getter'ı içerir. `0x2d9d6798–0x2d9d67a8` çağrı/karşılaştırması, **`elapsed <= timeout` iken return ederek beklemeyi sürdürür**. Sync daha erken tamamlanırsa timeout dolması beklenmez. Sonraki yolda mute bayrakları kaldırılır.

Bu nedenle ayar sadece metin/flag değildir; AV-sync bekleme eşiğine ulaşır. Tuner kilidi, program/PID seçimi, ilk decode frame, PCR/ses düzeltmeleri ve file-in koşulundaki ilave frame beklemesi ayrı kalır. Bunları atlayan bir yama uygulanmadı. Aynı/farklı transponder veya şifreli/şifresiz geçişte toplam etkinin ne olduğu TV üzerinde ölçülmedi. [DoVideoSync C ve assembly](../analiz/native-features/fast-channel/common-sync-v1/2d9d6270.json).

`MSrv_DTV_Player_DVB::IsFastZappingEnable=0x2d4c7574` ayrı bir public capability getter'ında gerçekten sabit 0 döndürür. Bu isimden hareketle onu 1'e çevirmek doğru değildir: yukarıda kanıtlanan normal UI/DB/AV-start yolu bu getter'ı kullanmadan gerçek timeout seçer. Yalnız global GOT-load taramasında çağrı bulunmaması sanal/indirect çağrıların yokluğunu kanıtlamaz; capability getter'ının bütün tüketicileri çözülmüş sayılmaz.

## Gizlenme ve erişim koşulları

General OnCreate içinde ID49 için ayrı service-enable veya Hide çağrısı bulunmadı. ID49 normal Advanced listesine eklenir. `OnKey=0xcff0b0` içinde Enter key `0xd`, odaklı ana satıra göre alt menüyü seçer; Gelişmiş yolu `HideAllShowSubmenu(this,7,this+0x240)` ile liste7'yi ve ilk satır ID48'i açar, başlığı Str `0x80=Gelişmiş` yapar. Key `0xd`, widget13 selector'ı değildir. [OnKey C](../analiz/native-features/fast-channel/ui-nav-v1/00cff0b0.c).

İki BasicMode getter'ı da 1 olduğunda General OnCreate, ana Gelişmiş satırını (`ID13`, `this+0x1b4`) `0xd25448` üzerinden gizler; Dil/Klavye, Aksesuarlar ve Hakkında satırları da bu koşuldadır. Özelliğin tekil gizlilik kapısı olarak sunulamaz. BasicMode, otel veya diğer menü erişim kısıtları bu görevde kaldırılmadı. Aktif TV'de bu koşullar gözlenmedi. [Önceki General koşul incelemesi](bilgi-tabani/UI_GENERAL_COZUM.md).

## Doğrulama ve sınırlar

`reverse-engineer-anything` becerisi uygulandı. Bilinen eski MIPS ABI REA sınırı yeniden denenmedi. Yeni çıktılar mevcut Ghidra projelerinden `-noanalysis -readOnly` ile alınmış doğrudan statik Ghidra çıktısıdır; REA Evidence değildir. Firmware programları ve donanım komutları çalıştırılmadı.

Customer sorgusunun ilk denemesi yanlış lane1 projesinde program bulunamadığı için reddedildi (`customer-v1/ghidra.log`); manifestteki lane0 ile yinelenen `customer-v2` sorgusu iki fonksiyonu başarıyla çıkardı. Başarısız deneme C çıktısı veya hedef analizi olarak sayılmadı.

[Kaynak koruma aracı](../scripts/native_fast_channel.py), orijinal/V7.9 app kimliğini, dört kütüphane hash'ini ve ilgili MIPS word'lerini kontrol eder. [Kanıt JSON'u](../analiz/native-features/fast-channel/proof.json) gerçek girişlerden yeniden üretildi. Altı test, orijinal/V7.9 sözleşme eşitliğini, bozulmuş word ve bilinmeyen ELF reddini, ELF file-backed sınırlarını ve bu analizin mutator sunmadığını kontrol eder. Bu testler MIPS çalıştırma, TV testi veya zaman ölçümü değildir.

Çalıştırılanlar: `python -X utf8 scripts/native_fast_channel.py` geçti; `python -m unittest discover -s scripts -p test_native_fast_channel.py -v` **6/6 geçti**; `python -m py_compile scripts/native_fast_channel.py scripts/test_native_fast_channel.py` geçti.
