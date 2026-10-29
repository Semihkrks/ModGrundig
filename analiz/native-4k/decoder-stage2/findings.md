# Aşama2 — kayıtlı HEVC türünden gerçek decoder'a yol

27 Ekim2026. Önceki decoder incelemesini tekrarlamadan6 yeni fonksiyon gövdesi okundu. **VIDEO_TYPE5→DTV codec7 ad alanı boşluğu kapandı.** Böylece HEVC'nin kayıttan sonra codec dönüşümü sırasında bilinmeyen türe düşürüldüğü yönünde kanıt bulunmadı; aksine doğru decoder koduna aktarıldığı doğrudan gösterildi.

## Kanıtlanan zincir

1. `libmsrv_dvb.so:_GetAvInfoFromProgramInfo 0x2d4d6a08`1056bayt. Program kaydındaki video PID'si`+0x30`, video türü`+0x19` okunur. `0x2d4d6b10` dispatch tablosu`0x2d596d08`'ı kullanır; case5 hedefi`0x2d4d6cf0`'dır. Bu hedef7 yükler ve `0x2d4d6cf8` delay slot'unda çıkış `MW_DTV_AVInfo+0` alanına yazar.
2. `_UpdateAV 0x2d4d6e28`800bayt, `0x2d4d6ed0`'da dönüştürücüyü output S5 ile çağırır. Aynı S5, `0x2d4d7044/704c`'de `MW_DTV_AVMonitor::Start` argümanı a1 olur.
3. `Start 0x2d9da078`792bayt, gelen MW_DTV_AVInfo verisini kopyalar; `0x2d9da27c`'daki adlandırılmış mapi_event Send çağrısına iletir. Codec'e özel elemeye dönüştürülmez. Burada gerçek thread/queue çalıştırılmadı; payload kopyalama ve GOT çağrısı statik olarak çözüldü.
4. `AVMonitorMain 0x2d9d9484`1396bayt, `0x2d9d95e0` event Wait sonrası event1 için `0x2d9d9824/982c`'de DoStart'ı seçer; a1 Wait çıkışındaki info pointer'ıdır.
5. `DoStart 0x2d9d7e40`5700bayt, giriş a1'i S4'te tutar (`0x2d9d7e8c`). `0x2d9d9304` a1'e `*(S4)` codec'ini yükler. `0x2d9d9308` gerçek `mapi_vdec::SetVdecType(DTV CODEC_TYPE,u8)` çağrısıdır. Info+0x26 kontrol bayrağı0 olsa da1 olsa da codec7 aynen aktarılır;0 dalında eski monitor durumu temizlenir.
6. Önceki aşamada çözülen SDK `SetVdecType 0x2cba8604` enum7'yi VDEC16 yapar. Legacy Init ve EX/V2 Init üzerinden mode7/EVD backend2 yoluna gider. Bu noktalar [önceki kayıt](../decoder-findings.md) ve `decoder/codec-init-path.json` içindedir.

Tuner ajanının ayrı bulgusu PMT stream0x24'ün MAPI_SI_VIDEO_INFO tür5 olarak ayrıştırılması ve `_AddCommonProgramInfo`'nun video codec alanını DB+0x19'a taşımasıdır. Bu aşama bu iki bulguyu yeniden üretmez; kendi kanıtı kayıtlı DB+0x19'dan başlar. Birleşik yol PMT0x24 → türe5 → DB5 → AVInfo7 → SDK7 → VDEC16 → EVD'dir. Runtime fiziksel cihaz izi olduğu iddia edilmez.

## Gerçek koşul: eksik video PID'si

Dönüştürücü `PID==0x1fff` ise çıkış video codec'ini0 yapar. Bu HEVC'ye özel değil; geçerli video PID'si bulunmama durumudur. Sentetik geçerli PID101 ile tür5→7; aynı tür5 ve PID8191 ile codec0 sonucu gerçek orijinal talimatlarla doğrulandı. Bu, gerçek kayıtlardaki PID'nin yanlış/eksik olduğuna kanıt değildir; yalnız kontrol edilmesi gereken somut bir veri koşuludur. Etkin olmayan/yanlış transponder veya eksik PMT, salt4K özellik bayrağı değiştirilerek düzeltilmiş sayılmaz.

## Playback durum denetimi liste filtresi değildir

Altıncı gövde `CheckVideoStatus 0x2d9d4c30`388bayt, zaman aralığı, IsImageFreezed ve decoder GetFrameCnt üzerinden durumu denetler; frame sayısı ilerlemezse SetVideoStatus çağırır. Bu gövdede HEVC türüne,3840/2160 boyutuna veya4K capability sonucuna göre kayıt/listeden silme yoktur. Kendi çağrı listesi de DB insert/delete veya kanal listesi işlemi içermez. Bundan tüm firmware'de başka filtre olmadığı sonucu çıkarılmaz.

Bu6 gövdede `MApi_VDEC_CheckCaps/_EX_CheckCaps`, HEVC destek getter'ı veya4K enable getter'ına doğrudan adlandırılmış GOT çağrısı bulunmadı. Dolaylı çağrılar ve kapsam dışı fonksiyonlar açık sınırlardır. Önceki CheckCaps16=false sonucu bu kanıtlanan başlatma yolunda ret kapısı olarak görülmedi; onu zorla true yapan patch bu bulgularla gerekçelendirilemez.

## Kontroller ve sınırlar

**11 bounded vaka geçti:** geçerli PID ile8 giriş video türü, tür5+geçersiz PID ve2 gerçek DoStart aktarım bloğu. Sonuçlar tür0/1/2/3/4→0/1/2/3/4; tür5→7; aralık dışı6/7→0; geçersiz PID ile5→0. İki kontrol bayrağı durumunda SDK'ya codec7 ulaştı.

Tam orijinal6 gövde hash ve disassembly olarak tutuldu; bu aşamada yeni Ghidra decompile çalıştırılmadı. Unicorn yalnız converter'ın video switch bölümünü ve DoStart'ın SDK çağrısına kadar olan kısa bölümünü sentetik bellekle yürüttü. Ses, tuner, grafik, gerçek queue thread'i, decoder Init ve donanım register komutları çalıştırılmadı.

**Kanıtlanmış bir HEVC/4K kanal kilidi açma koşulu bu aşamada bulunmadı.** Kayıt sonrası codec dönüşüm boşluğu artık yoktur; henüz4K fiziksel decode, Main10, gerçek EVD mikrokod sınırı veya kayıtsız kanalın neden hiç listelenmediği kanıtlanmış değildir. Kanal keşfi, factory parser seçimi ve kayıt/listelenebilirlik filtreleri diğer ajanların ayrı kapsamıdır. Üst katman parametre/feature isimlerini değiştirmek bu kanıtların yerine geçmez.

- [Yeniden üretilebilir sınırlı inceleme](inspect_playback.py)
- [11 vaka,6 gövde hash'i ve adlandırılmış çağrı adayları](playback-evidence.json)
- [DB→AVInfo dönüşümü](dvb-0x2d4d6a08.asm.txt)
- [UpdateAV](dvb-0x2d4d6e28.asm.txt)
- [Start](common-0x2d9da078.asm.txt)
- [DoStart](common-0x2d9d7e40.asm.txt)
- [Event tüketimi](common-0x2d9d9484.asm.txt)
- [Playback durum kontrolü](common-0x2d9d4c30.asm.txt)

Orijinal firmware ve V7.7/V7.8 üretim dosyaları değiştirilmedi. İnceleme doğrudan yerel ELF/assembly kanıtıdır, REA Evidence değildir. Beceri `reverse-engineer-anything`.
