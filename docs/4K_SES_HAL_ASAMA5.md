# Ses HAL: decoder kimliği ve gerçek kilit sözleşmesi

30 Ekim 2026. V7.9 ses denemesi sonrası kullanıcı, yüklemenin %100 tamamlandığını,
yeniden başlama olduğunu, TRT Ultra HD'nin iki ses seçiminin sessiz kaldığını ve
normal HD kanallarda sesin çalıştığını bildirdi. Şifreli kanal veya sinyal yok
uyarısı bildirilmedi; sayısal kalite/TS/PID ölçümü yoktur.

## Eski ve yeni API farklı motora gitmiyor

`libapiAUDIO.so` SHA-256:
`d55e76dd24baea83657739e4424982cb8c4b00d90a9144792c1c6b430fe46651`.

`HAL_MAD_Init=0x2d075e38` içinde `0x2d075ea8/0x2d075eb0/0x2d075eb8`
talimatları, `HAL_MAD_GetAudioInfo2=0x2d072d38` adresini
`g_FuncPrt_Hal_GetAudioInfo2=0x2d2330cc` callback alanına bağlar. Kaynak word'leri,
GP hesabı ve GOT değerleri audit script'inde sabittir; donanım init'i çalıştırılmaz.

HAL girişinde `HAL_AUDIO_Convert_DecId_to_ADECId=0x2d06260c` çağrılır. Bu
derlemede incelenen geçerli API kimlikleri0/1/2 için dönüş **0**'dır. -1/3 için
hata metni vardır; bu çalışma onları kullanılabilir decoder olarak sunmaz.
Bu nedenle seçilmiş per-decoder infoType0 yolu da eski MAD kilit yolu gibi
**`HAL_DEC_R2_Get_SHM_INFO(1,0)`** okur. Eski API'nin yanlış SHM bankını okuduğu
hipotezi bu derlemenin bu yollarında desteklenmedi; bu hipoteze dayanarak A2 yoktur.

## Başarı kodu ile kilit değerini karıştırmamak gerekir

`HAL_MAD_GetAudioInfo2(ID,0,out)`:

- Dönüş register'ında **1**, API isteğinin işlendiğini belirtir.
- `out` adresine **tek bayt**0/1, gerçek SHM sonucunun boolean karşılığıdır.
- Başarı dönüşünün1 olması decoder'ın kilitli olduğunu göstermez.
- Customer `MMA_getAudioInfo2=0x2dc67de4` seçilmiş MM infoType1 yolunu API
  infoType0'a bağlar. Diğer query türlerinin ABI'si bununla aynı sayılmadı.
- HAL case0x14, native metinde `Audio_infoType_UNI_PCM1_Info` olarak geçen
  frame/adres/boyut bilgisidir; genel bir tek bayt kilit sonucu değildir.

## Doğrulama

[Audit ve native sözleşme testi](../scripts/audit_hevc_audio_hal_stage5.py)
üç yeni C çıktısını, kaynak kimliğini ve callback assignment'ını doğrular.
Gerçek HAL query ve converter MIPS talimatları Unicorn'da yürütüldü;
SHM donanım getter'ı tamamen mock'tur, paylaşılan durum önceden hazır varsayılır.
**9 vaka geçti:** ID0/1/2 × mock SHM0/1/2. Hepsinde selector0, API success1,
ayrı tek bayt kilit sonucu ve çıktı canary/stack/callee-saved korunması denetlendi.
Tam firmware, ses DSP'si, gerçek PCM ve RF akışı çalıştırılmadı.

[Kaynak hash'leri ve vakalar](../analiz/native-4k/audio-stage5-hal/results.json).
Çıktılar doğrudan Ghidra ve sınırlı native test kanıtıdır; REA Evidence değildir.

Bu sonuç sesin neden gelmediğini tek başına çözmez. Decoder'ın gerçek kilit
sonucu, seçili audio/PCR PID'leri, DSP codec sonucu ve A1 helper'a erişim hâlâ
ölçülmedi. Çalışan HD sesi genel ses çıkışının bütünüyle bozulduğu iddiasını
desteklemez; UHD ses türü/veri akışının çözüldüğünü de kanıtlamaz.
