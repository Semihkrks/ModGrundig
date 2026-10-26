# Dört büyük UI fonksiyonu: kapanış ve tasarıma geçiş

23 Ekim 2026. Kullanıcının istediği dört büyük gövde için ölçülen durum. Orijinal firmware ve UI kaynakları değiştirilmedi; cihazda çalıştırma, yeniden paketleme veya yükleme yapılmadı.

**Bütün FDE aralığından C çıktısı + eksiksiz instruction listesi: 4/4.** Varsayılan çıkarım aşamalarıyla 3/4; sınırlanmış çıkarımla 1/4. C çıktısı özgün kaynak veya bütün davranışların kesin çözümü değildir; tam listing, bütün assembly yollarının C içinde korunduğu anlamına gelmez.

| İşlev | FDE baytı | C profili | Ham çağrı adayı / belirsiz hedef | Kanıt |
|---|---:|---|---:|---|
| `0x0055b6c0` NewUI_Settings | 122016 | Sınırlanmış çıkarım | 3071 / 281 | [C](../../analiz/native/ui-four/settings/reduced-recovery180/0055b6c0.c) / [assembly](../../analiz/native/ui-four/settings/reduced-recovery180/0055b6c0.json) |
| `0x00d01710` GeneralFrame create | 146892 | Varsayılan çıkarım | 3642 / 69 | [C](../../analiz/native/ui-four/general/bounded300/00d01710.c) / [assembly](../../analiz/native/ui-four/general/bounded300/00d01710.json) |
| `0x00d42150` HomePageFrame create | 93208 | Varsayılan çıkarım | 2202 / 100 | [C](../../analiz/native/ui-four/home/conly600/00d42150.c) / [assembly](../../analiz/native/ui-four/home/conly600/00d42150.json) |
| `0x00f60a64` ToolsMenuFrame create | 153552 | Varsayılan çıkarım | 4055 / 92 | [C](../../analiz/native/ui-four/tools/full256-360s/00f60a64.c) / [assembly](../../analiz/native/ui-four/tools/full256-360s/00f60a64.json) |

[Bütün denemeler ve hash kayıtları](../../analiz/ui-dort-buyuk-durum.json) · [Son doğrulama kaydı](../../analiz/ui-dort-buyuk-dogrulama.json).

## Davranış raporları

- [Settings: ortak stil, type dispatch, arama ekranı ve switch ikonları](UI_SETTINGS_COZUM.md)
- [General: widget ağacı, event bağlantıları ve koşullar](UI_GENERAL_COZUM.md)
- [Home: widget/kaynak/koşul haritası](UI_HOME_COZUM.md)
- [Tools: widget ağacı, odak ve modlar](UI_TOOLS_COZUM.md)

## Bu aşamadaki yeni kanıtlar ve açık işler

Dört özgün fonksiyonun tamamı `dvbt_board` içindedir; araç denemeleri ve Settings fragmentleri özgün fonksiyon sayısına eklenmez. Dört FDE toplam 128.917 instruction içerir. Ham 12.970 call-site adayının 542 hedefi belirsizdir; bu statik aday sayısı, 12.970 doğrulanmış runtime çağrısı anlamına gelmez.

| Gövde | Yeni anlamlandırma / çapraz kontrol | Kalan konu |
|---|---|---|
| General | 66 widget; 44 event kaydı, 31 widget/event-handler bağı; constructor/parent/rect/color assembly karşılaştırması | 69 dolaylı hedef, aktif Hotel/admin/kaynak koşulları |
| Home | 60 widget; 240 arka plan MImgSet ve 18 ön plan SetImg; Netflix yardım etiketi ve Hotel renk koşulu | 100 dolaylı hedef; aktif profil ve gerçek ekran gözlemi |
| Tools | 85 widget; 125 karşılaştırılabilir sabit nonimport hedefte raw/pcode farkı 0; focus parametreleri assembly ile | 92 dolaylı hedef; medya/3D/DualWatch/CEC koşullarının cihazdaki seçimi |
| Settings | 35 RTTI cast; 336 eksik instruction çözüldü; 10 switch case/40 ikon çağrısı; 13 sonuç etiketi iki arama ekranına bağlandı | 281 dolaylı hedef; eksik tür/argümanlar, 37 ham Unwind çağrısının EH/LSDA semantiği |

Kesin statik kontrol ve aday bağlama raporlarda ayrıdır: örneğin Settings focus eşitliği `0x55f868` ve çağrı `0x55f884`; Tools gerçek SetInitialFocus argümanı `0xf853c0` assembly kaydındadır. Çıkarılan davranış cihaz gözlemi sayılmaz. Önceki 226/226 modül envanteri bu aşamada tekrar taranmadı.

[Settings fragment kapsamı ve sentetik sınırlar](../../analiz/native/ui-four/settings-fragments/README.md) · [Settings C/assembly çapraz kontrolü](../../analiz/native/ui-four/settings/C-raw-crosscheck.json)

## Hangi değişikliklere geçilebilir?

Menü, Home ve ses paneli için ortak görsel dilin ve ekran tasarımlarının planlanması bütün 226 modülün semantik çözümünü gerektirmez. Widget/event bağlarını koruyarak yerleşim, PNG/ikon, tipografi, renk ve focus durumları için ayrı tasarım kapsamı çıkarılabilir. Paylaşılan Num/Color/Image ID’leri doğrudan global değiştirilmeden önce etki listesi kullanılmalıdır.

Ses panelinde normal/mute/ARC modları, 3 saniyelik kapanış ve tuş yönlendirmesi korunmalı; menülerde Hotel/admin/basic/recovery, kaynak ve medya/3D/DualWatch koşulları hesaba katılmalıdır. Animation getter bu build’de sabit 0; yeni görünüm ile animasyon davranışı ayrı karar olarak ele alınmalıdır.

Bu rapor firmware’e değişiklik uygulama veya TV’ye yükleme yetkisi değildir. Güncelleme kabul/imza yolu, fiziksel model uyumu ve cihazdaki aktif profil hâlâ açık araştırma konularıdır.

## Araç sınırları

Önceki 90 saniyelik/50 MB denemeleri aynı biçimde tekrarlanmadı: izole metadata projeleri, 256 MB payload, daha uzun süre, standard C-only çıktı ve gerektiğinde kanıtlı eksik listing/switch metadata’sı kullanıldı. Metadata müdahaleleri kaydedilmeyen analiz bağlamında kaldı. C-only çıktıda pcode kapsam kontrolü mevcut değildir; eski boş liste/true alanı böyle bir doğrulama olarak kullanılmaz.

Settings için `protorecovery`, `protorecovery_b`, `localrecovery` kapatılarak bütün FDE aralığından C üretildi. Bu çıktıdaki eksik çağrı argümanları ve `extraout` geçicileri nedeniyle prototipler assembly ile kontrol edilmelidir. Ham `_Unwind_Resume` yollarının C içinde görünmemesi EH kapsamının ayrıca açık kaldığını gösterir. Ayrı firstpass pcode 30.504 instruction sınırını doğrular; 12 sınırlı fragment C çıktısı orijinal gövde üzerinde 30.504 instruction sahipliğini kapsar. Fragment sınırlarında yapay dönüş/bağlam varsayımları vardır; bunlar eşdeğer kaynak veya 12 ayrı firmware fonksiyonu sayılmaz.
