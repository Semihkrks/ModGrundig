# V7.5 — gerçek kanal adı bağlantısı

26 Ekim 2026. V7.4'ün V7.1 tabanlı GP düzeltmesi, gri ses dolgusu ve sağ üst beyaz sessiz rozeti korunur. Yeni paket, sayısal girişe gerçek kanal adı köprüsünü ekler. V7.3 cihazda donma bildirdiği için kullanılmamalıdır; cihazda çalışan doğrulanmış temel kullanıcıya göre V7.1'dir. **V7.5 henüz TV'de denenmedi.**

`01` yazısı mevcut `SetText` çağrısıyla aynen korunur. `frame+0x1a2` numarası `GetProgramSelInfo` ile DB numarası/servis/route değerlerine çözülür. Aktif route eşleşiyorsa kanal yöneticisinin `GetProgramName` sanal çağrısı ad okur. Başarısızlıkta önceki ad temizlenir; o anda izlenen başka kanalın adı gösterilmez. Kanal seçimi, OK ve zamanlayıcı kodları değiştirilmez.

Yeni TextBox ID3, mevcut kök `frame+0x180` altında `[1566,206,254,38]` alanındadır; DejaVu Sans26 ve `#527185` kullanır. Kurucu ID kaydını yapar; container çocuk sahipliğini alır; yıkıcı kaydı kaldırır. Yeni frame pointer alanı kullanılmaz. Normal string yollarında geçici MString oluşturulur, widget'a sahipli kopyalanır ve yıkılır.

Kurulum hook'u `0x8968ac/0x8968b0`; digit hook'ları `0x8957c8/0x8957cc` ve `0x895a68/0x895a6c`. CREATE `0x1160100`532 bayt; UPDATE `0x1160800`768 bayt. GP her çağrıda korunur; CREATE'in kayıtlı unwind GP'si de APP_GP olarak düzeltilmiştir.

Yeni RX segmenti `0x1160000`, dosya offseti `0xd60000`'dır. PHDR tablosu8 kayıtla taşınır; eski LOAD içerikleri yalnız ELF başlığı ve6 hook sözcüğü dışında aynıdır. Eski6741 unwind arama kaydı korunarak2 FDE eklenir. Üretilmiş küçük MIPS probe, firmware'in eski yükleyicisiyle çalıştı. Ayrı C++ probe yeni RX helper üzerinden istisnayı çağıranda yakaladı; FDE'siz negatif kontrol abort verdi. TV uygulaması veya güncelleme programı yürütülmedi.

Doğrulama: native yardımcı6 test; ELF yerleşim/unwind4 test; **pakete yerleştirilen gerçek hook talimatlarıyla4 bütünleşme testi** geçti. Son CREATE revizyonuyla5 önizleme testi ve HTTP `01→0000→01`, rozet/sınır kontrolleri geçti. Önizleme PC'de açıkça işaretlenmiş demo kanal servisi kullanır; firmware'e örnek kanal listesi eklenmez. Gerçek TV kodu kendi kanal yöneticisini çağırır.

Bilinen sınırlar: fiziksel TV çekirdeği, gerçek kanal veritabanı, grafik sürücüsü ve kumanda akışı cihazda doğrulanmadı. Route uyuşmazlığında ad boş bırakılır. İstisna taşınması için FDE vardır; yardımcı içindeki geçici nesneler için LSDA cleanup yoktur, sonraki native allocation istisnasında kaynak sızıntısı mümkündür. İlk widget tahsisi nothrow ve null kontrollüdür. Tam OOM koruması iddia edilmez.

- [Native yardımcı](../scripts/native_ui_v75_name.py), [ELF yerleştirici](../scripts/native_ui_v75_elf.py), [üretici ve hook kontrolleri](../scripts/build_native_ui_v75_tv.py).
- [Kurulu hook testleri](../analiz/native-ui-v75/installed-hooks.json), [yardımcı ABI testleri](../analiz/native-ui-v75/native-name/bounded-tests.json), [eski yükleyici/C++ testi](../analiz/native-ui-v75/elf-loader/cpp-results.json).
- [Son önizleme kanıtı](../analiz/native-frame-rehost/v75/verification.json), [01 ve kanal adı](../analiz/native-frame-rehost/v75/numeric01.png), [eşleşmeyen0000](../analiz/native-frame-rehost/v75/numeric0000.png).
- [RAR test adayı](../analiz/native-ui-candidate/v7.5-tv/package/GMGRMR.-.-.-.-.V03.017.04_V7.5_TEST.rar), [aşama/hash kaydı](../analiz/native-ui-candidate/v7.5-tv/phase-results.json).

Orijinaller ve V7.1 korundu. Bu çalışmada USB veya TV'ye yazılmadı. Kullanılan beceri `reverse-engineer-anything`; doğrudan statik Ghidra çıktıları REA Evidence olarak sunulmaz.
