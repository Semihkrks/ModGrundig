# Kanal, numara girişi ve OK listesi

23 Ekim 2026. Kullanıcının son talebi: mevcut TV işlevlerini modernleştir; sunucudaki görünüm ile native hedefi birbirinden bağımsız tasarlama. Ağ/Web/app ekleme. Uzun ses kapsülü korunur.

## Çıktı ve kanıt kapsamı

[Birleşik kanıt](../analiz/channel-ui-evidence.json): **16 özgün giriş / 16 C çıktısı**, 73.574 instruction kaydı, 7.618 ham çağrı adayı. 7.281 GOT sembol adayı, 31 sabit adres adayı, **306 çözülemeyen dolaylı hedef**. Bunlar cihazda gözlenmiş çağrılar değildir.

16 C çıktısı tam kaynak geri kazanımı sayılmaz. Listing'de açık kalanlar: RefreshUI `0x7d4cac` 60 instruction, filter switch `0x774c8c` 52, Idle OnKey `0xd7c7a4` 120, program bilgi OnCreate `0x7de53c` 118. C-only sorgularda pcode scope yoktur. Bu boşluklar ve belirsiz prototipler, native eşdeğerlik hazır kabul edilmeden çözülmelidir. Numara kontrolündeki altı girişin listing'i eksiksizdir.

| İşlev | Kod yolu ve kanıt |
|---|---|
| Normal TV'de rakam | [Idle OnKey `0xd7c7a4`](../analiz/native/ui-four/channels/controls-v1/00d7c7a4.c): `0x30..0x39` ve kaynak kapıları → ChannelControlApp yarat/Run/PostEvent |
| Numara OSD kurulumu | [OnCreate `0x895b84`](../analiz/native/ui-four/channels/numeric-v1/00895b84.c): Num `0x991/992/990/98f` root `(0,0,1920,80)`; TextBox `0x999/99a/998/997` `(860,5,200,70)` |
| Rakam biriktirme | [TenKeyHandle `0x89552c`](../analiz/native/ui-four/channels/number-helpers-v1/0089552c.c): ASCII'den `0x30` çıkarılır; sayı `eski*10+yeni`; ilk üç basamak 3.000ms, dördüncü 2.000ms |
| Timer kanıtı | Ham çağrı VA `0x89580c` args a1=3000/a2=0; `0x895ac0` a1=2000/a2=1; `0x895af4` a1=3000/a2=0. Ayrıntılar birleşik kanıtta |
| OK ile numara onayı | [OnKey `0x896b88`](../analiz/native/ui-four/channels/numeric-v1/00896b88.c): key `0x0d`, sayım 1..4 → OnTimer; beşinci tuş byte sayacını artırır fakat tamponu büyütmez, aynı Enter dalından hemen onaylanmaz |
| Timer sonrası | [OnTimer `0x8968d8`](../analiz/native/ui-four/channels/numeric-v1/008968d8.c): ChangeChannel, alan/flag temizliği, ArProgramInfoApp::Summon(3,1,1), uygulama kapanışı |
| Kanal seçme wrapper | [ChangeChannel `0x895b24`](../analiz/native/ui-four/channels/number-helpers-v1/00895b24.c) → ArChannelManager::SelectChannelByNumber. Decompiler `ushort param_1`/`in_a1` gösterir; bunun özgün C++ parametre prototipi olduğu iddia edilmez |
| Normal TV'de OK | Idle OnKey `0x0d` + kaynak 0/1 kapısı → ArChannelListApp::Run |
| Liste | [OnCreate `0x7995b0`](../analiz/native/ui-four/channels/layout-v1/007995b0.c), [OnKey `0x79464c`](../analiz/native/ui-four/channels/controls-v1/0079464c.c); kayıtlı kanal, filtre, program rehberi, kaynak ve PVR koşulları |
| Kanal bilgi bandı | [ArProgramInfoFrame OnCreate `0x7de53c`](../analiz/native/ui-four/channels/layout-v1/007de53c.c), [RefreshUI `0x7d4cac`](../analiz/native/ui-four/channels/controls-v1/007d4cac.c), [OnKey `0x7dc104`](../analiz/native/ui-four/channels/controls-v1/007dc104.c); kanal/EPG/program verisi canlı yöneticilerden gelir |
| Zapp menüsü | `0xfc03e8`, `0xfc1d18`, SetZappChannel `0xfbf074` farklı akıştır; rakam girişinin kendisi diye etiketlenmez |

Root/child koordinatları kaynak Num değerleridir; parent transform, quarter/half görünüm seçimi, UI manager ve sonraki layout işlemlerinin son ekran konumunu değiştirebildiği açık tutulur. Birleşik kayıttaki 163+ rect dizisi tek başına TV ekran görüntüsü değildir.

## Uygulama

[Host kanal modeli](../ui-preview/channel-model.js), rakam/timer/Enter/cancel yolunu uygular; kullanıcı verisi adapteri doğrulanmamış/eksik kanal isimlerini uydurmaz. Varsayılan [kanal verisi](../ui-preview/channels.json) boştur: sağlanan update paketinde fiziksel cihazın USR_DB kanal dump'ı yoktur. Hiçbir kanal adı veya EPG yayını sahte veriyle doldurulmaz. Test fixture'ları yalnız test dosyalarındadır.

Önizleme menüsü kapalıyken 0–9 numara alanını açar; Enter seçim niyeti üretir. OK liste durumuna girer, ancak son native geometri doğrulanmadığı için farklı tasarımlı bir liste kutusu TV ile eşdeğermiş gibi gösterilmez; durum ekranın dışındaki önizleme bilgisinde bildirilir. Program bandı, gerçek veri ve geometri onayı gelmeden gösterilmez. Tuner/kanal değiştirme komutu gönderilmez. Bu akış tasarımın native bağlanmasına hazırlıktır, TV'de tamamlanmış kanal değiştirme değildir.

## Sunucu/native aynı kaynak ilkesi

- Menü isimleri Türkçe kaynak tablosunun ID/ofset/hash'leriyle üretilir; elle farklı isim verilmez.
- Menü ve ses ikonları [native adaylarla](../ui-assets/manifest.json) aynı PNG byte'larını kullanır; [profil](../analiz/ui-modernizasyon/shared-resource-profile.json) SHA eşliğini tutar.
- Tarayıcı kapsülün köşelerinde CSS clipping kullanır; native opak PNG/alpha/colorkey karşılığı hâlâ doğrulanmalıdır. Görsel olarak düzgün bir PC kapsülü bu engeli çözmüş sayılmaz.
- Uzun ses geometrisi korunur. Menü 444px tasarım adayı hâlâ native layout'a uygulanmadığı için eşdeğerlik **false** kalır.
- Tarayıcıya özgü ses tween'i/menu swipe kapatıldı; C helper native event döngüsüne bağlanmadan efekt sunulmaz.
- Aktif tema/dil/kapılar, MIPS derleme/MUF bağlantısı ve cihazdaki çizim henüz doğrulanmadı. Fiziksel TV karşılaştırması olmadan “sunucuyla TV birebir” sonucu verilemez. Orijinal firmware ve TV değiştirilmedi; yüklenebilir paket üretilmedi.

Sonraki native çalışma: listing boşlukları/switch sınırları → kaynak erişiminin son render yerleşimine kadar izlenmesi → widget/event ve font/alpha sözleşmesi → MIPS entegrasyonu → fiziksel kabul testi. Yeni tarayıcı tasarımının çalışması bu adımların yerine sayılmaz.
