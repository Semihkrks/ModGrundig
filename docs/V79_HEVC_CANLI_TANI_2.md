# V7.9 HEVC tanı2 — kurtarılan cihaz kaydı ve sonraki ölçüm

1 Kasım2026. **4K görüntü/ses henüz çözülmedi.** Bu aşamada ilk gerçek SDK
başlatma kayıtları USB'nin kayıp FAT32 zincirinden kurtarıldı. Ardından kare,
ses kilidi ve sync durumunu ölçmek için ayrı tanı2 adayı hazırlandı. V7.9 APP/UI
aynen korunur; decode/mute kararları zorlanmaz. `reverse-engineer-anything`
akışı, iki alt ajan, sınırlı native test ve ana ajan incelemesi kullanıldı.

## Gerçek cihazdan kurtarılan veri

Kullanıcı `MODGRUNDIG_DIAG.txt` dosyasını kendisinin oluşturmadığını belirtti.
Görünür dosya0 bayttı. Salt okunur CHKDSK, FAT32 hatası ve16KiB tek kayıp zincir
bildirdi. D: sadece `rb` olarak açıldı; iki FAT kopyası aynıydı. Referanssız
cluster149780'den şu sayısal kayıtlar çıkarıldı:

```text
MGDIAG_META 1 3 0 0 3
MGDIAG 1 1 2 0 4300 4500 4300 0 3
MGDIAG 1 1 7 6 4855 4955 4855 0 3
MGDIAG 1 1 2 0 4300 4500 4300 0 3
```

| Olay | SDK sonucu | Video / ses codec | Video / ses / PCR PID | Mod | Mute maskesi |
|---|---:|---|---|---:|---:|
| Önceki HD geçişiyle uyumlu |1|2 /0|4300 /4500 /4300|0|3|
| HEVC geçişi, TRT denemesiyle uyumlu |1|7 /6|4855 /4955 /4855|0|3|
| HD'ye dönüşle uyumlu |1|2 /0|4300 /4500 /4300|0|3|

Kayıtlarda servis adı/ID'si tutulmaz; kanal adını bu sayılardan kanıtlamıyoruz.
Metadata3 kabul/0 ret/0 overlong ve3 saklanan kaydı bildirir; çıkarılan üç
olayla tutarlıdır. Ham cluster dışarı yayımlanmadı; yalnız bu sayılar ve hash
rapora alındı. Kaynak16KiB SHA256:
`2967e84f24b867c6620f8f76bfcec6186abc3a7bae6ac8a6289e51c34c56a343`.
[Cihaz gözlemi](../analiz/native-ui-candidate/v7.9-hevc-diag/recovered-device-feedback-2026-11-01.json).

**Artık bilinen:** tanı kancası/toplayıcı TV'de çalışmış; codec7 için
`mapi_vdec::SetVdecType`1 dönmüş. Kaynak çağrı bloğu
`Common:0x2d9d92fc..0x2d9d930c`, sonuç alınan SDK fonksiyonu
`libMStarSDK:0x2cba8604`'tür. Bu ölçüm `Play:0x2d9d9334` ve sonraki
kare/senkron davranışından öncedir. Başarılı init, UHD/Main10 karelerinin
çözüldüğünü, gerçek PID payload'ının geldiğini veya PCM çıktığını göstermez.

**Mute3 tek başına arıza değildir:** bu başlangıç anında çalışan HD kaydında da
aynı3 görülür. Kalıcı mute veya hangi bitin takıldığı buradan çıkarılamaz.
Bu yüzden maskeyi temizleyen veya init başarısını zorlayan yama yapılmadı.

## USB onarımı ve veri koruma

Önce20 kullanıcı/paket dosyası bilgisayara yedeklenip hash ile doğrulandı.
Kullanıcı onayından sonra yalnız D: için `CHKDSK /F` uygulandı; kayıp zincir
dosyaya dönüştürülerek korundu. Oluşan CHK dosyasının hash'i salt okunur
kurtarılan cluster ile birebir eşleşti. Yedeklenen20 dosya onarım sonrasında
değişmemişti; ikinci CHKDSK sorun bulmadı ve bağımsız FAT yürüyüşü0 orphan buldu.
Format yapılmadı, TV'ye yazılmadı.
[Onarım kaydı](../analiz/native-ui-candidate/v7.9-hevc-diag/usb-repair-2026-11-01.json).
Okunabilir kurtarılmış kopya D: kökünde `MODGRUNDIG_DIAG_RECOVERED.txt`'dir.
Ham veri/yedekler yerel, Git tarafından dışlanan `tools/` altındadır.

FAT hasarının nedeninin sürekli rename, ani çıkarma, cihaz sürücüsü veya başka
bir etken olduğu kanıtlanmadı. CHKDSK ile kurtarılan zincirin tanı kaydı olduğu
kanıtlandı; bunu4K arızasının nedeni olarak sunmuyoruz.
[Salt okunur kurtarıcı](../scripts/recover_fat32_diag.py) için7 sentetik test
geçti; komşu satırları atlamama ve canlı dosya zincirine girmeme de sınanır.

## Yeni pakette ne ölçülüyor?

Önceki init kancası byte byte korunur. Yeni kaynak
[`native_hevc_diag_stage2.py`](../scripts/native_hevc_diag_stage2.py), mevcut
DoMonitor içindeki **DoVideoSync** çağrı bloğunu `0x2d9d6cec` noktasında sarar.
Özgün sync çağrısı ve hemen sonraki ready92 dalı korunur. Yeni helper
`0x2d957800`,1184 bayttır. Tarihsel `diag-hooks/stage2/` alternatif checkpoint'i
bu pakete dahil değildir; **yalnız `stage2-sync/` finali kullanılır**.

Ana canlı monitor/window0/non-PVR için nesne+codec+video/audio PID anahtarı
değiştiğinde ölçüm sayacı sıfırlanır. İlk eşleşen monitor çağrısından sonra
≥2/4/6 saniyede en fazla üç deneme yapılır. Bu tam kanal geçiş timestamp'i
değildir; geç çalışan monitor gerçek elapsed değerini kaydeder.

```text
MGDIAG 4 elapsed_ms video_codec video_pid audio_pid frames mad_lock ready92 sync_pending mute_mask video_started audio_started
```

`frames=0` gerçek getter sonucudur. `frames=4294967295`, video başlamadığı veya
decoder pointer'ı olmadığı için sorgu yapılmadığını gösterir. `mad_lock=255`
sorgu yapılmadı anlamındadır;0 ile eşit değildir. Pozitif frame/MAD sonucu da
tek başına ekranda doğru UHD görüntü veya duyulur PCM garantisi değildir.

Ölçüm state'i iki bağımsız RW padding alanında tutulur:
`0x2da89f94..0x2da89fa0` dosya tabanlı sıfır alan;
`0x2da8d0b4..0x2da8d0c0` PT_LOAD örtük sıfır kuyruğu. Section/symbol/relocation
örtüşmesi reddedilir; GNU_RELRO program header sayısı0'dır. Monitorün kendi
alanları değiştirilmez. GP/stack/HI/LO/errno ve özgün dal korunması testlidir.
Yeni helper'ın FDE'si yoktur; exception/asenkron unwind doğrulanmaz. Ana canlı
monitorün seri çağrıldığı varsayımı korunur; yeni mutex eklenmez.
[Kanca kanıtı](../analiz/native-4k/diag-hooks/stage2-sync/patch-proof.json).

## USB yazma yolu da güçlendirildi

Toplayıcı artık boş/yanlış formatter başlığını kabul etmez. TEMP için dosya
türü/inode/boyut ve tam byte readback doğrulanmadan rename yapmaz. Başarılı
snapshot sayaçları ve USB/marker kimliği IPC üzerinden parent'a bildirilir;
aynı veri2 saniyede bir tekrar yazılmaz. Marker kontrolü sürer; yeni olay veya
yeniden opt-in yeni snapshot üretir, başarısız export yeniden denenir.
Bu, kesin FAT kök neden çözümü veya güç kesintisi garantisi değildir.

## Gerçek test kapsamı

| Kontrol | Sonuç |
|---|---|
| Yeni native sampler |9 test /50 senaryo /162 kanca çağrısı;4 özgün kontrol bloğu karşılaştırması|
| Toplayıcı Linux host |18/18; bozuk header, yalancı write, readback, idle ve retry dahil|
| Kendi MIPS toplayıcımız + stock glibc2.8/loader, QEMU `-r 3.1.10` |12 geçti;6 host-only fault shim açıkça SKIP|
| Paket pozitif/tamper |6/6|
| Salt okunur FAT kurtarıcı |7/7 sentetik fixture|
| UBIFS / SWImage |Metaveri/indexCRC/readback;14 payload,12 değişmeyen slot, V7.9 APP aynı|
| RAR |17 dosya/11 dizin;16 dosya aynı;7-Zip ve WinRAR PASS|
| Yeni tanı2 fiziksel TV /4K görüntü |Henüz test edilmedi / çözülmedi|

QEMU'da yalnız kendi toplayıcımız çalıştırıldı; TV uygulaması/güncelleyicisi
çalıştırılmadı, tuner/VDEC/DSP veya gerçek3.1 kernel emüle edilmedi. `-r` yalnız
emüle sürecin uname sürümünü ayarlar. İlk tanı adayının cihaz kaydı yeni
sampler'ın donanım başarısı diye sayılmaz. Ana ajan kaynak/ABI/paket incelemesi
yaptı; yeni pakette bitmiş ikinci bağımsız release incelemesi iddia edilmez.

BIN SHA256: `7247e876541261d745dd4d3ff7920c0c964af46aab20be846b95d25bba458a61`.
RAR SHA256: `76980d3bf635be86b0668fa7de7aa46bc53602b6736f0b3dc35917886d4c4601`.

## D: hazırlandıktan sonra tek cihaz denemesi

Yeni tanı2 RAR'ı yerel `analiz/native-ui-candidate/v7.9-hevc-diag2/package/`
altındadır. Açılmış güncelleme düzeni ve marker D:'ye eşitlenir; TV'ye otomatik
yazma yapılmaz. Eski firmware ve kurtarılan loglar korunur.

1. D:'deki **yeni firmware'i** önceki USB güncelleme yöntemiyle yükle; gerçekten
   %100 ve yeniden başlatma mı, yoksa güncel uyarısı mı olduğunu ayır.
2. USB takılı kalsın. Açılıştan20 saniye sonra HD'de10 saniye → TRT Ultra HD'de
   15 saniye → HD'de15 saniye bekle. İlk10 dakika içinde dene; son beklemede
   kumandada başka tuşa basma, yeni kayıt gelmeyince USB yazımı duracaktır.
3. PC'ye geri geldiğinde `MODGRUNDIG_DIAG.txt` kontrol edilecek. Ek dosya
   oluşturmana gerek yok; `MODGRUNDIG_DIAG_RECOVERED.txt` önceki kurtarılmış
   kayıttır ve yeni ölçüm diye kullanılmaz. Windows'tan USB'yi güvenle kaldır.

Yeni kare/MAD/sync kayıtları gelmeden sahte decoder success, koşulsuz unmute
veya gelişigüzel bellek büyütme paketi hazırlanmaz.
