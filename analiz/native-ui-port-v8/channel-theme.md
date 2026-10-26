# Native v8 kanal listesi ve bilgi bandı alt işi

25 Ekim 2026. Mevcut gerçek `dvbt_board` yerel görsel argümanları değiştirilir. HTML/CSS veya yeni kanal durum modeli kullanılmaz. Kaynaklar orijinal firmware'den elde edilmiş Ghidra/assembly kayıtlarıdır; REA Evidence ve TV gözlemi değildir. Bu alt iş orijinallere yazmaz; ana v8 üreticisi dönüşümü ayrı kopyaya birleştirir.

## Somut değişiklikler

- `ArChannelListFrame::OnCreate0x7995b0`, ana panel `this+0x184`: Color75→94 dört durumda; MImg normal66 ve diğer39→özel2184 dört durumda. Panelin orijinal `(100,160,1720,770)` rect'i korunur. Yeni texture353×138RGBA, hafif kavisli beyaz yüzeydir; orijinal normal66texture ölçüsü korunur.
- Aynı fonksiyonda sağ ayrıntı alanları `this+0x1b8/+1bc/+1c0/+1c4/+1c8` normal metin Color69→0: beyaz yerine koyu. Kesin instruction VA'ları `0x79d164/0x79d5c8/0x79da38/0x79de98/0x79e2f8`.
- `ArProgramInfoFrame::OnCreate0x7de53c`: üç yerel alt yüzeyin on iki MImg423 argümanı özel2185'e bağlanır. Mevcut beyaz metin ve ikonların kontrastını koruyan yumuşak koyu mavi-gri band2×250RGBA'dır. Yerleşim/kapanma/görünürlük veya servis akışı değiştirilmez.

Yeni ID'ler `../rc/ARimages/Grundig/modern/v8_channel_panel.png` ve `v8_program_band.png` yoluna bağlanır. Eski Image kayıtları ve ortak PNG'ler değiştirilmez. İki kaynağın açılmış toplam texture belleği197kB'nin altındadır; DirectFB cache/yüzey kopyası ve gerçek SoC bellek tüketimi bu hesabın kapsamında değildir.

## Bilinçli kapsam

Kanal listesinin sol dinamik satırları, seçim/focus mantığı ve yedi özgün filtre korunur. Bu sol bölge mevcut koyu native stilindedir; sağ panel açık yüzeydir. Bütün kanal ekranı Chrome ile aynı beyaz tasarıma dönüştürüldü denmez. Sol satırları tamamen beyaza çevirmek, dinamik oluşturulan satırların metin/config/ikon durumlarının ayrıca çözülmesini gerektirir.

Program bandı özgün beyaz metin/ikonlar için koyu tutulur. Kısmi beyaz dönüşümle ikonları okunmaz yapmak yerine bu yerel, tutarlı alt küme uygulanır. RF/kanal DB/EPG/CEC/event handler ve global Color tablosu değişmez. Sahte kanal veya program adı firmware'e eklenmez.

## Kod ve doğrulama

[Dönüşüm modülü](../../../scripts/native_ui_v8_channels.py): `transform(num,elf,assets)` → yeniNum, yeniELF, yeniAssets, değişiklikler. Num baytları aynen döner. Her MIPS instruction eski kelime eşleşmesiyle değiştirilir; bütün ELF farkları25instruction allowlist'iyle sınırlanır. Yeni Image kayıtlarını ana üretici merkezi tabloda eklemelidir.

[Testler](../../../scripts/test_native_ui_v8_channels.py): **5/5**. Yerel argüman değişimi/ELF uzunluğu; yanlış eski bayt reddi; kaynak çakışması reddi; PNG boyut/alfa/bellek; constructor geometri kayıtları ve25eski+25yeni tek komutun Unicorn MIPS üzerinde yürütülmesi. Tek komut testi tam OnCreate/ekran/TV testi değildir.

[Ayrıntılı kanıt](channel-theme-evidence.json):25VA/eski-yeniword, çağrı noktası, kayıtlı kaynak hash'i, yeni PNG hash'leri ve scene spec. Yeni decompile0; tamframe yürütmesi ve cihaz testi0. Sahne tanımı parent-local ilk rect'leri gösterir; sonraki layout/event hareketleri gözlenmiş kabul edilmez.

Kaynaklar: `analiz/native-ui-port-v3/channel-list/{widget-bindings,raw-calls}.json`, `program-info/{widget-bindings,raw-calls}.json`, `analiz/native/ui-four/channels/layout-v1/{007995b0,007de53c}.c`. Metin başlangıç kaydı3439 “Hazır Değil”dir; native rehost bunu çizerse gerçek yayın/EPG varlığı iddiası taşımaz.
