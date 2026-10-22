# Servis davranışları: ilk kod kanıtları

22 Ekim 2026. Aşağıdaki sonuçlar seçili gövdelerle sınırlıdır; donanımda çalıştırılmadı. Diğer servis işlevleri için modül indeksi ve takip listesi esas alınır.

Devamı: [CEC dönüşü, standby, anten/LNB, tarama, OAD ve uygulama başlangıcı için sekiz assembly denetimli davranış grubu](SERVIS_DERINLESTIRME.md). Callback sonucunu korumayan CEC wrapper'ına başarı bool'u atfedilmez; OAD/anten wrapper'larının sabit dönüşleri donanım veya kabul sonucu sayılmaz.

## WAN callback kaydı

`07_MSLIB/libmsrv_network.so` · `0x2e7ee354` · `_ZN20MSrv_Network_Control24RegisterWanStatusCheckCbEPFhvE`

a1 callback değerini this+0x1c64 alanına yazar ve 0 döndürür. Callback bu işlev içinde çağrılmaz.

[Decompile çıktısı](../../analiz/native/system-modules/55b8009ddeff377b334d6e116472a837c07e695e86d5ff9ac308d4a2639139bf/2e7ee354.c); assembly word/ofsetleri [servis kanıt JSON'unda](../../analiz/servis-davranis-kanitlari.json).

## WAN callback kaldırma

`07_MSLIB/libmsrv_network.so` · `0x2e7ee360` · `_ZN20MSrv_Network_Control26UnregisterWanStatusCheckCbEv`

this+0x1c64 alanına 0 yazar ve 0 döndürür.

[Decompile çıktısı](../../analiz/native/system-modules/55b8009ddeff377b334d6e116472a837c07e695e86d5ff9ac308d4a2639139bf/2e7ee360.c); assembly word/ofsetleri [servis kanıt JSON'unda](../../analiz/servis-davranis-kanitlari.json).

## Route wrapper stub

`07_MSLIB/libmsrv_network.so` · `0x2e830338` · `_ZN15MSrv_Network_Ip15SetDefaultRouteE17network_if_info_s`

Struct argüman registerlerini stack’e döküp 0 döndürür; burada syscall veya route değiştirme çağrısı yoktur. Decompiler prototipi bu spill argümanlarını göstermiyor. Diğer ağ yollarına genellenmez.

[Decompile çıktısı](../../analiz/native/system-modules/55b8009ddeff377b334d6e116472a837c07e695e86d5ff9ac308d4a2639139bf/2e830338.c); assembly word/ofsetleri [servis kanıt JSON'unda](../../analiz/servis-davranis-kanitlari.json).

## Servisten ses tuşu olayı

`07_MSLIB/libmsrv_control.so` · `0x2ea9e8f4` · `_ZN19MSrv_Control_common12APVolumeDownEv`

PostEvent(this,0,0x14,0xf04d,0) çağrısı üretir. Bu wrapper doğrudan ses seviyesi yazmaz.

[Decompile çıktısı](../../analiz/native/system-modules/0b154eba8a18cda242d3a1efafb74ca576bfb35bf0c6b9be38fc13fe16e518ea/2ea9e8f4.c); assembly word/ofsetleri [servis kanıt JSON'unda](../../analiz/servis-davranis-kanitlari.json).

## IR yapılandırma ioctl yolu

`07_MSLIB/utopia/libdrvIR.so` · `0x2f461044` · `MDrv_IR_InitCfg`

Girdi işaretçisinden beş 32-bit alan kopyalar, modül içindeki fd ile ioctl request 0x8014750b çağırır. Gerçek cihaz/fd ve ioctl kernel handler bağlantısı henüz doğrulanmadı.

[Decompile çıktısı](../../analiz/native/system-modules/ce8942e58ad01c90dee6869aff2673a48ee6267d369597820b6670427e6b4529/2f461044.c); assembly word/ofsetleri [servis kanıt JSON'unda](../../analiz/servis-davranis-kanitlari.json).

## IR state geçişi

`07_MSLIB/utopia/libdrvIR.so` · `0x2f461e74` · `MDrv_IR_SetPowerState`

Girdi 1 durum kaydını 1 yapıp 0 döndürür. Girdi 2 ancak önceki kayıt 1 ise MDrv_IR_Init çağırıp kaydı 2 yapar; diğer yollar 1 döndürür. Sayısal durumlara suspend/resume enum adı henüz atanmadı.

[Decompile çıktısı](../../analiz/native/system-modules/ce8942e58ad01c90dee6869aff2673a48ee6267d369597820b6670427e6b4529/2f461e74.c); assembly word/ofsetleri [servis kanıt JSON'unda](../../analiz/servis-davranis-kanitlari.json).

## CEC başlatma durumu getter

`07_MSLIB/libar_cec.so` · `0x2f045304` · `_ZN14cec_Controller18IsCECInitCompletedEv`

GOT üzerinden erişilen modül globalindeki word değerini döndürür. Bu okuma fiziksel CEC bağlantısının hazır olduğunun gözlemi değildir.

[Decompile çıktısı](../../analiz/native/system-modules/6177c73cfd0cca039e1aacf2fb721f693812b18a9282f2980d5c255bd431bbd7/2f045304.c); assembly word/ofsetleri [servis kanıt JSON'unda](../../analiz/servis-davranis-kanitlari.json).

## LNB virtual yönlendirme

`07_MSLIB/libmsrv_dvbs.so` · `0x2ebea490` · `_ZN20MSrv_DTV_Player_DVBS11SetLNBPowerE18MS_EN_LNBPWR_ONOFF`

Nesnenin vtable slot +0x9b0 hedefine tail jump yapar. Nihai override ve donanım komutu bu gövdeden tek başına bilinmez.

[Decompile çıktısı](../../analiz/native/system-modules/daa8f91f94a64431ec42d3e0681ced5297c28ba7f834991e79353c13990bf08d/2ebea490.c); assembly word/ofsetleri [servis kanıt JSON'unda](../../analiz/servis-davranis-kanitlari.json).
