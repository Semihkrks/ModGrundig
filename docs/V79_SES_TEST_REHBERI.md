# V7.9 tabanlı HEVC ses testi

**30 Ekim cihaz geri bildirimi:** Kullanıcı son denemede iki ses seçiminde de
ses gelmediğini bildirdi. Yüklemenin %100 tamamlandığını ve TV'nin yeniden
başladığını da doğruladı. Bu aday ses hedefini sağlamış sayılmaz. Helper'ın
çalışması ve decoder lock/mute değerleri cihazda ölçülmedi.
[Ayrı cihaz gözlemi](../analiz/native-ui-candidate/v7.9-audio-test/device-feedback.json).

Bu deneyin tabanı V7.9'dur. V7.10 ve SEMIH logosu dahil değildir.
Amaç HEVC video karesi oluşmadığında, hazır ses çözücüsünün video kaynaklı
mute nedeninden kurtulup kurtulamayacağını sınamaktır. Görüntü dönüştürme veya
4K decoder desteği ekleme iddiası yoktur.

## Doğrulanan yerel test paketi

[V7.9 HEVC AUDIO TEST RAR](../analiz/native-ui-candidate/v7.9-audio-test/package/GMGRMR.-.-.-.-.V03.017.04_V7.9_HEVC_AUDIO_TEST.rar)
yerel analiz çıktısıdır; GitHub'da firmware indirmesi yayımlanmaz.
SHA-256: `9b7ea14939606bb340437428f8bbc00186a529da29cf69c719fea554c4ed117c`.

7 test / 37 kontrollü MIPS vakası geçti; dış native servisler mock'tur.
MSLIB yeniden çıkarılarak261 dosya ve341 metadata kaydı kontrol edildi;
260 dosya aynı kaldı, yalnız `libmsrv_common.so` içindeki250 bayt değişti.
7.9 APP ve diğer13 payload birebir korunur. MSLIB29.0MB altında olup sabit
RAM sınırını ve compressed slot sınırını aşmaz. 7-Zip ve WinRAR kontrolleri geçti.
[Sonuçlar ve hash'ler](../analiz/native-ui-candidate/v7.9-audio-test/phase-results.json).
Fiziksel TV başarısı henüz bilinmiyor; sıfır hata veya ses çıkışı garantisi yoktur.

Paket yalnız native kod ve paket doğrulaması tamamlandığında deney adayı olarak
sunulur. Testin kesin guard/ABI kapsamı [native ses raporunda](V79_HEVC_SES_TESTI.md),
dosya sistemi ve container sınırları [paketleme raporunda](V79_SES_PAKETLEME.md)
yer alır. Fiziksel TV sonucu bu belgelerin yerine geçmez.

## Kurulum tamamlandıktan sonra

1. Önce normal bir HD kanalda düşük sesle dene. Ses aç/kıs, mute aç/kapat ve
   ses0 davranışını kontrol et. 7.9 ses paneli, kanal girişi ve özgün menü korunmalıdır.
2. Canlı TRT Ultra HD'ye geç. Mute kapalı, ses seviyesi sıfırdan büyük olsun.
   Her ses seçeneğini ayrı seçip en az5 saniye bekle.
3. Ses gelirse mute aç/kapat, ardından HD kanala dönüp yeniden TRT Ultra HD'ye geç.
   Sesin gelme süresini ve hangi ses seçeneğinde geldiğini ayrı kaydet.
4. Ses kesilmesi, gürültü, donma veya menü/kanal geçişinde bozulma varsa hangi
   tuş ve sırada oluştuğunu bildir. Görüntünün gelmemesi bu deneyde beklenen
   açık konudur; bu paket onun düzeltildiğini iddia etmez.

Guard koşulları sağlanmazsa ses açılmayabilir. Sadece sessizlik gözlemi,
ses codec'inin desteklenmediğini veya patch'in hangi kolunun çalıştığını kanıtlamaz.
Canlı ses PID/PCR, decoder lock ve monitor bayrakları henüz cihazda ölçülmemiştir.

## Kayıt hakkındaki mevcut gözlem

Kullanıcı30 Ekim2026'da TV'nin kendi depolamasında kayıt/oynatma başlatabildiğini
ve detayları gösterdiğini, fakat burada da ses/görüntü olmadığını bildirdi.
PC'de incelenmiş bir kayıt yoktur. Bu bilgi dosyada gerçek video/ses paketleri
bulunduğunun veya decoder'ın başarılı olduğunun kanıtı sayılmadı.
Bu ilk deney canlı DTV yoluna yöneliktir; dahili kayıt oynatımının düzeldiği
iddia edilmez.
