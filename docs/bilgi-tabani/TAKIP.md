# Araştırma takibi ve kanıt kuralları

22 Ekim 2026. Güncel sayaçlar [asama-durum.json](../../analiz/asama-durum.json) ve [modül indeksinde](README.md). Aşağıdaki işlerin tamamlanması yalnız çıktı üretimine göre değil, belirtilen doğrulamaya göre değerlendirilir.

| Öncelik | İş | Tamamlanma ölçütü / gerekçe |
|---|---|---|
| 1 | 226 modülün Ghidra temel indeksi | Her hash için fonksiyon/xref/symbol/computed-call çıktısı; aliaslar ayrı yol, tek artifact sayılır. Timeout ve loader uyarıları açık tutulur. |
| 2 | UI incelemesini birleştirme | Dört büyük gövdenin C çıktısı mevcut; Settings sınırlanmış çıkarımla tamamlandı. Prototip, EH ve dolaylı hedeflerin kalan belirsizlikleri takipte. [Güncel rapor](UI_DORT_BUYUK_FONKSIYON.md). |
| 3 | Servis yolları | Audio, CEC/IR, görüntü/tuner/kanal, ağ/depolama/güç için giriş→servis→SDK/driver code yolu ve yan etki/hata dalları. İsim benzerliği yeterli değildir. |
| 4 | 7.583 eşleşmeyen import | Weak hook, closure-dışı sağlayıcı, version/loader ve gerçek eksik aday ayrı sınıflandırılır; runtime eksikliği diye ilan edilmez. |
| 5 | Sanal/dinamik bağlantılar | Vtable address-point, override seçimi, callback kaydı, dlopen/dlsym argümanları ve koşullar. |
| 6 | Tam boot zinciri | Bootloader entry/bootargs/jump, kernel init seçimi, init/profile ve uygulama başlangıcının adresli devamı. |
| 7 | Güncelleme kabul/doğrulama | Header parser→CRC/hash/signature→ret/başarı dalı; kripto sembolü varlığı tek başına sonuç değildir. |

## Bilinen UI boşlukları

23 Ekim güncellemesi: önceki dört C boşluğu için bütün FDE aralığından çıktı alındı: General `0xd01710`, Home `0xd42150`, Tools `0xf60a64` varsayılan çıkarımla; Settings `0x55b6c0` protorecovery/protorecovery_b/localrecovery kapatılarak. Settings'in varsayılan çıkarımla tamamlanması, eksik argüman/türler, EH landing-pad/LSDA yolları ve 281 ham dolaylı hedef açık kalır. Ayrıca 12 sınırlı fragment C çıktısı ve ayrı firstpass pcode tutulur; eşdeğer kaynak sayılmaz. [Dört gövde ve kanıtları](UI_DORT_BUYUK_FONKSIYON.md). SourceSetup `0xf0dd24` ve LayoutItems `0xd29500` önceki aşamada tamamlandı.

Bool resource header count/payload uyumsuzluğu ve flag-1/8 adlandırması açık. Focus flag-4 kodla doğrulandı. Aktif fiziksel cihaz profili/dil ve dinamik dispatch seçimi gözlenmedi.

## Kanıt seviyeleri

- Dosya hash/CRC/ofset: doğrudan veri karşılaştırması.
- ELF import/export/DT_NEEDED: statik beyan.
- RTTI/vtable/message-map: somut kayıt, adres ve yapısal yorum.
- Instruction call-site ve GOT eşlemesi: statik hedef adayı; ABI varsayımı ve runtime rebinding açık.
- Decompiled davranış: assembly/prototype kontrolü yapılan adreslerle sınırlı kod sonucu.
- Cihaz gözlemi: bu projede henüz yok.

Tamamlanmış decompile, kritik davranışın anlamlandırıldığı anlamına gelmez. Ghidra xref, raw PIC/GOT call adayı ve sembol eşleşmesi aynı metriğe toplanmaz. Yüzde kaynak geri kazanımı iddia edilmez.

## Araç ve erişim durumu

REA kuruludur; eski MIPS ELF ABI ret kaydı korunur. Doğrudan Ghidra çıktıları REA Evidence diye etiketlenmez. MIPS Constant Reference Analyzer patolojik çalışma nedeniyle kapalıdır; bu, dolaylı xref eksikliği yaratabilir. Bazı ELF loader relocation türleri ayrıca uyarı verir; program günlükleri kontrol edilmeden relocation başarısı varsayılmaz.

Önceki ajanların kota hataları korunur; sonrasında yeni uzman ajanlarla boot/format, raw boot handler, servis, DirectFB ve bağımsız kanıt kontrolü tamamlandı. Kullanıcının kalan limit uyarısı üzerine yeni geniş tarama açılmadan bu aşama kaydedildi. [Aşama raporu ve somut devam kuyruğu](ASAMA_2026-10-22.md) güncel başlangıç noktasıdır.

Dört süre sınırlı büyük modül için [154 parçalık kuyruk](../../analiz/native/analysis-partitions/manifest.json) oluşturuldu. Kuyruk plan durumundadır; çalıştırılmış analiz veya tamamlanmış decompile diye sayılmaz. Baseline Ghidra indeksi 226/226 yollar için mevcuttur.
