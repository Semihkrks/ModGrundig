# V8 gerçek Home/MUF değişikliği

25 Ekim 2026. `scripts/native_ui_v8_home.py` HTML üretmez. V7'nin ayrı native kopyasına357 exact-oldword değişikliği uygular:240 MImg kaynak argümanı,116 yerel metin renk argümanı ve bir görsel flag store. Global Color tablosu, gezinme/donanım/event kodu ve widget geometrisi korunur.

Home'a özel40 yeni PNG:2180..2183 yüzeyler ve2188..2223 ikonlar. Orijinal991/946/947/948 kaynakları başka ekranlarda korunur. MImg::Set/MImg::MImg çağrıları özel kopyalara yönlendirilir; önceki global ikonların diğer tüketicileri etkilenmez. PNG IHDR boyut, bit derinliği ve renk tipi korunur;961 normal DLNA kaynağı LA kalır. Altı mevcut modern ikon ailesinin alfa maskeleri yeniden kullanılır; diğer yerel Home ikonları ince TV piktogramlarıdır. APP/WEB/ağ etkinleştirilmez.

## Beyaz yüzeyde metin kontrastı kanıtı

Önceki96 adayın84'ü doğrudan mixer text-color alanları,12'si üç TextContentConfig kurulumundaki dört renktir. Home LayoutItems0xd29500 içinde SetTextContent çağrıları örneğin0xd2a988/0xd39cd0, config pointer fp+0x1104 kullanır. Konfigürasyon döngüsü160 bayt stride; fp+0x20+0x1118/111c/1120/1124, config+0x34/38/3c/40 eder.

Özgün libmuf `TextImageMixer::SetTextContent0x2e285b38` gerçek MIPS baytları Unicorn'da sınırlandırılmış nesne/servis modeliyle çalıştırıldı.145 benzersiz komut, dört farklı sentinel rengini config+0x34/38/3c/40'tan child+0x7c/80/84/88'e kopyaladı. `UpdateCompositeData0x2e2853c0`74 benzersiz komutla aynı alanları korudu; çağrıları yerleşim güncellemesidir. String/font/geometry/invalidate dış bağımlılıkları açık no-op callback sınırlarıdır; tam UI çalıştırması değildir.

Ek20 Home OnCreate metin argümanı mevcut textbox alanlarına ait store/call bağıyla doğrulandı. Color94/69/56 koyu Color0'a; gri49 odak rengi mevcut mavi Color3'e yerel çağrı argümanında çevrildi. Kaynak Color tablosu değişmedi.

## Testler ve sınırlar

`python -m unittest discover -s scripts -p test_native_ui_v8_home.py -v`:10/10 geçti. Exact byte allowlist, yalnız özel kaynaklar, PNG sözleşmesi, bozuk plan/instruction/ikon reddi, native geometri ve iki özgün MUF fonksiyon yürütmesi kontrol edildi. İlk koşu LA961 formatını desteklemediği için reddetti; LA korunarak düzeltildi, temiz koşu geçti.

[Makine kaydı ve assembly kanıtları](home-evidence.json), [sabit hash'li patch planı](home-plan.json). `scene_spec(num)`60 retained OnCreate widget'ını parent-local koordinat/ID/etiketleriyle verir; son runtime ekran konumu veya font çözümü sayılmaz.

Özgün504/529px root ve nested/dinamik rect'ler korunur; Chrome456px menü yüksekliği native'e aktarılmış gibi sunulmaz. Tam Home OnCreate/LayoutItems/event döngüsü, sonradan EPG/Hotel/focus renk değişimleri ve fiziksel TV/GOP çıkışı doğrulanmadı. Bu sınırlar paket raporunda açık kalmalıdır.

Bağımsız incelemede koyu424/425/426 fallback panelleri üzerinde koyu metin riski bulundu. Dokuz alt widget’a ait27 renk değişikliği plandan çıkarıldı; özgün beyaz/gray talimatları korunur. Regresyon tüm27 adreste özgün Color69 instruction baytlarını ve patch listesinden çıkarılmasını doğrular.

İkinci tam denetimde21 dinamik mixer'ın84 MImg arka plan durumu da özel açık kaynaklara bağlandı: normal40/78/857/461→2181, odak64/79/856/462→2182. Böylece96 koyulaştırılmış outer/config metni eski koyu kartta bırakılmaz. Eski1668/1669/1670 koyu ayırıcıları üzerindeki +1e4/+200 başlıklarının sekiz Color94 argümanı da özgün beyaz olarak korundu.

Tüm36 özel foreground ID'si18 ImageButton'a bağlandı;18×4 arka plan durumu tek tek denetlendi. Yalnız +204 resim kartında dört1485 sentinel argümanı vardı;2181/2182'ye bağlandı. Görsel çizim flag'i için0xd4e660 delay-slot NOP→`sb a1,0x3a(a0)` uygulandı. Önceki0xd4e648 widget a0,0xd4e64c a1=1; çağrılan özgün SetImgExpandProperty0x2e2285f0 yalnız +250/+254/+258'i yazar. Test gerçek patch jalr/delay baytlarını ve hash-sabit özgün16 bayt callee'yi MIPS'te yürütüp3a=1,39=0 ve diğer alanların korunmasını doğrular.

Üst dokuz ImageButton'da OnCreate içinde açık3a=1 görülmez; alt sekizde (resim hariç) vardır. Üst ikonların parent180 yüzeyi açık olduğundan kontrast güvenlidir; tüm üst kart dolgularının runtime çizildiği iddia edilmez. Son kaynaklar/çağrı yolları korunarak üretilmiş native adaydır; bütün native widget kurucuları yürütülmüş değildir.

## Son kullanıcı düzeltmesi: onaylı Chrome ikonları

Önceki alfa maskesi/yeniden çizilen aktif şekiller kullanılmaz.22 aktif kaynak doğrudan güncel `ui-preview/tv-icons.svg` öğelerinden Chrome ile rasterize edildi; normal #203447, odak #056fc2 ve64/48px görünür SVG kutuları mevcut native Expand ölçülerine göre telafi edildi. PNG RGBA baytları onaylı raster çıktısıyla birebir karşılaştırıldı.14 eşdeğeri olmayan pasif ailede özgün OEM alfa şekli korundu ve yerel koyu/mavi renge çevrildi; bunlar Chrome ile birebir eşit diye sunulmaz.

[İkon kaynak/piksel manifesti](approved-icons/manifest.json). Home testleri artık11/11; ELF357 talimat ve geometri aynı kaldı.
