# 4K görüntü ve ses → FHD: host üzerinde kontrollü deney

30 Ekim 2026. Bu deney bilgisayarda çalışır; televizyonun kendi uydu akışını
dönüştürebildiğinin veya yeni firmware'in çalıştığının kanıtı değildir.

Mevcut host FFmpeg 8.1.1 ile bağımsız sentetik kaynak üretildi:
3840×2160/50 fps, HEVC Main10, 10-bit SDR BT.709 ve AC-3 ses. Ardından
1920×1080/25 fps, 8-bit H.264 Main Level4.0 ve stereo AAC-LC/48kHz MP4'e
dönüştürüldü. Çıktı tekrar çözüldü; hata çıkmadı ve sesin sessiz olmadığı
`volumedetect` ile doğrulandı.

**Sonuç: PASS_HOST_ONLY.** Gerçek TRT yayını, HE-AAC, HDR ton eşleme, gerçek zaman
performansı ve TV USB oynatımı bu deneyde sınanmadı. Klip yalnız0,4 saniyedir;
uzun süreli görsel/işitsel cihaz testi için tasarlanmamıştır. 50→25 fps dönüşümü
hareket örneklerinin yarısını bırakır; aynı akıcılığı koruma iddiası yoktur.

- [Script](../scripts/verify_4k_fhd_host_conversion.py)
- [Komutlar, girdi/çıktı akış bilgileri ve SHA-256 kayıtları](../analiz/native-4k/host-conversion/results.json)
- Yerel medya: `analiz/native-4k/host-conversion/`. Sentetik videolar GitHub'a eklenmez.

Yeniden üretim için FFmpeg/ffprobe PATH üzerinde olmalıdır. Script mevcut deney
dizinini değiştirmeyi reddeder; orijinal firmware, TV uygulaması, USB veya ağ
akışını çalıştırmaz. Araçları otomatik kurmaz ve dış servise dosya göndermez.

```powershell
python -X utf8 scripts/verify_4k_fhd_host_conversion.py
```

Yöntem: [FFmpeg transcoding ve stream seçimi](https://ffmpeg.org/ffmpeg.html),
[scale filtresi](https://ffmpeg.org/ffmpeg-filters.html#scale-1).

Bu deney, genel dönüşüm işleminin mümkün olduğunu gösterir. Aynı işlemi TV'ye
taşımak için yerleşik decoder/mikrokod/bellek desteği veya ölçülmüş bir yazılımsal
çözücü gerekir. Bilgisayardaki FFmpeg'in varlığı MIPS CPU'nun gerçek zamanlı
UHD çözebileceğini göstermez. Native araştırma [ana 4K raporunda](4K_YAYIN_VE_GIZLI_OZELLIKLER.md)
ayrı takip edilir; bu çalışmada yeni yüklenebilir paket üretilmedi.
