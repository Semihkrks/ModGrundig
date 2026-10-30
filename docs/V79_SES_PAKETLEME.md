# V7.9 ses test adayı: MSLIB paketleme sınırları

30 Ekim 2026. Bu araçlar `v7.9-audio-test` için çevrimdışı paketleme sağlar. V7.10 kullanılmaz. Native ses yaması ayrı inceleme/test sorumluluğundadır; paketleme sonucu sesin TV'de düzeldiği anlamına gelmez. Kullanılan beceri `reverse-engineer-anything`. Gömülü firmware, update script'i veya donanım komutu çalıştırılmaz.

## Sabit kaynaklar

| Kaynak | SHA-256 |
|---|---|
| Özgün MSLIB UBIFS | `7d92780368b178854a46a8f2e2ee8b625d06c7292695929800e5ecbc56fb827b` |
| Özgün `libmsrv_common.so` | `06bc6252713a159d5a41849f476503b0c60b035954f0c82909750223e1077d21` |
| Korunan V7.9 APP UBIFS | `438caad4b1fed4a908d018e154da7939f21a20c4440eab5bc9c6238f104ee4c1` |
| V7.9 SWImage tabanı | `ae6a322861e3b288294b0e4a5f5faf33cb41864439508b2fcee4f6d89ddba496` |

MSLIB26 dizin,261 normal dosya,54 symlink; toplam341 girdi taşır. En küçük I/O2048, LEB126976, özgün kullanılan LEB229, **max LEB480**. APP'nin321 sınırı buraya kopyalanmadı. Aynı isimli özgün symlink'ler host dosyalarına doğru izlenmez; hedef metinleri korunur.

`build_native_mslib.py` özgün MSLIB'i host ubi-reader ile yeniden çıkarır ve canonical Linux ağacını dosya hash'leriyle karşılaştırır. Yalnız `/libmsrv_common.so` değiştirilir. Tüm özgün mode/uid/gid/nlink/mtime ve symlink hedefleri korunur; tüm normal dosya içerikleri ikinci çıkarımda kontrol edilir. Yeni inode/path eklenmez. Orijinal inode numaraları, UBIFS node yerleşimi ve UUID'nin bayt eşliği iddia edilmez.

ELF denetimi ET_DYN/ELF32 little-endian MIPS ve aynı dosya boyutunu ister. ELF header/ABI, program ve section tabloları aynıdır. Değişiklikler yalnız mevcut file-backed executable segmentteki executable section'larda veya bütün section'ların dışındaki özgün sıfır boşluklarda kabul edilir. Sonuncusu yalnız native yamanın ayrı cave/ABI kanıtıyla kullanılabilir; paketleyici semantik doğruluk yerine geçmez. Yeni segment, loader yönlendirmesi veya DT_NEEDED değişikliği kabul edilmez.

## Çevrimdışı komut sözleşmesi

Yalnız native yama testleri ve bağımsız inceleme tamamlandıktan sonra, onaylanan dosya ve SHA ile Linux ubi-reader Python'u aynı fakeroot oturumunda çalıştırılır:

```text
fakeroot <ubi-reader-python> scripts/build_native_mslib.py --library <onaylanan-libmsrv_common.so> --library-sha256 <onaylanan-sha256>
<linux-python> scripts/repack_native_audio_test.py --preset 9e
<ubi-reader-python> scripts/verify_native_audio_test.py --library <onaylanan-libmsrv_common.so> --library-sha256 <onaylanan-sha256>
```

İlk araç sabit Linux work dizini kullanır ve mevcut çalışma/çıktıyı yeniden kullanmayı reddeder. Ana çıktı `analiz/native-ui-candidate/v7.9-audio-test/package/07_MSLIB.ubifs`; içerik/metadata kanıtı `mslib-build-validation.json` ve `mslib-index.json` içindedir. Önceki sürümler ve özgün dosyalar yazma hedefi değildir.

MSLIB dosyaları UBIFS içinde mevcut **LZO** codec'iyle tutulur.261 dosyanın özgün toplam boyutu55.714.175 bayttır; raw-all yaklaşımı kullanılmaz. Güncelleme metni sıkıştırılmış girdiyi`0x81e00000`, açılmış çıktıyı`0x80200000` adresine koyar; CRC scratch de girdi adresindedir. Bu nedenle volume480 LEB kabul etse bile **açılmış MSLIB en fazla`0x1c00000`=29.360.128 bayt** olabilir. Özgün imaj29.077.504 bayttır. Builder, repacker ve bağımsız okuyucu bu RAM sınırını ayrı denetler; girdi/çıktı adresleri değiştirilmez.

Yeni UBIFS hem480 LEB volume sınırına hem bu daha dar RAM aralığına, dıştaki sıkıştırılmış stream de özgün MSLIB slotuna sığmalıdır. Sığmazsa araç durur; payload taşınmaz ve kernel codec desteği değiştirilmez. Raw-all önerisi bağımsız incelemede bu RAM çakışması nedeniyle elendi; hiçbir raw-all test imajı üretilmedi.

## Container ve bağımsız okuma

`repack_native_audio_test.py` V7.9 SWImage'ın yalnız7 numaralı MSLIB slotunu değiştirir. APP dahil diğer13 sıkıştırılmış slot padding'leriyle birebir korunur. MSLIB bölümünde yalnız filepartload/mscompress7 uzunluğu, CRC span/değeri ve iki ubi-write uzunluğu güncellenir. **`ubi part UBI #mslib` satırı değişmez.** Bütün offset'ler ve container toplam boyutu korunur; iki dış CRC yeniden hesaplanır. Gömülü komutlar sadece inert veri olarak parse edilir.

`verify_native_audio_test.py` repacker helper'ı import etmez. Stdlib LZMA/CRC ve özgün header parser'ıyla14 payload'ı bağımsız açar; V7.9 APP hash'ini ve değişmeyen13 slotu doğrular. Ardından özgün/aday MSLIB inode metadata'sını okur, ikisini ayrı host extractor dizinlerinde yeniden çıkarır; yalnız onaylı library hash'inin değiştiğini kontrol eder. Boot dosya hash'i ayrıca korunur. Son rapor `independent-readback.json`: başarılı durumda `status=PASS_OFFLINE_ONLY` ve `container_sha256` içerir; RAR hazırlama aracı bu kanıttan sonra çalıştırılır.

## Gerçek doğrulama durumu

İlk uygulama kontrolünde üç Python dosyası bellekte derlendi ve `python -B -S` ile stdlib import'ları geçti. Bağımsız okuyucu, sabit V7.9 tabanında14 payload'ı geçti; corruption olumsuz kontrolü reddedildi. Özgün MSLIB sayılarıyla header yeniden yazımı taban header'ının aynısını verdi. No-op library girişi reddedildi. RAM sınırından bir bayt büyük girdi repacker ve bağımsız okuyucu tarafından reddedildi; builder aynı üst sınırı çıktı yayımlamadan denetler.

Bu belge yazıldığında native yama doğrulaması bekleniyordu; yeni MSLIB/container/RAR build veya cihaz testi **geçmiş sayılmadı**. Nihai paket varsa gerçek hash/test sonucu `package/mslib-build-validation.json`, `repack-validation.json` ve `independent-readback.json` üzerinden okunmalıdır. Slot/volume taşması veya metadata/içerik farkı varsa dağıtım bloke edilir.
