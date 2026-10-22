# Servis ve uygulama başlangıcı: assembly ile derinleştirme

22 Ekim 2026. Sekiz davranış grubu; statik kod bulgularıdır. TV üzerinde gözlem yapılmadı. C çıktısının parametre ve dönüş tipleri assembly karşısında denetlendi.

## CEC dönüş değeri ve kaybolan parametre

Ana wrapper a0=servis nesnesi, a1=özgün RC kodu geçirir; decompiler ikinci argümanı düşürebilir. Customer wrapper callback ardından destructor ve operator_delete çağırır. Callback v0 değeri bunların üzerinden korunmaz. Önceki processed-bool yorumu desteklenmez.

Açık nokta: MW_CEC_IrWrapper::UnmappedIrEventReceivedCallbackFunc 0x2dfb95c8 (980 bayt) ve gerçek çağıran koşulları incelenmeli.

[`00555350 C`](../../analiz/native/ui-targeted/system-critical14/00555350.c) / [assembly JSON](../../analiz/native/ui-targeted/system-critical14/00555350.json) · [`2df7d2f8 C`](../../analiz/native/system-focused/394ee95f07383231c9cc1019d9d1fb8eb3c8309ae68fe2d3186ddf19c51dae39/cec-return1/2df7d2f8.c) / [assembly JSON](../../analiz/native/system-focused/394ee95f07383231c9cc1019d9d1fb8eb3c8309ae68fe2d3186ddf19c51dae39/cec-return1/2df7d2f8.json)

Kontrol adresleri: `0x0055538c`, `0x00555390`, `0x00555398`, `0x2df7d348`, `0x2df7d35c`, `0x2df7d37c`.

## Standby ve iptal koşulları

StartStandby aktif taramayı durdurabilir; SetPowerState(this,3,0), CEC standby, ses +0x1a0 ve DTV +0x724 sanal çağrılarını içerir. ASU nesnesi varsa StopExistingASUUpdate sonucu 1 olduğunda StartASU çağırmadan 0 döner; stop sonucu 1 değilse StartASU sonucu 1 için yine 0 döner. Diğer yollar 1. CancelStandby power-state=3 ve ASU-started=1 kapısından geçer; LED olayları ve ASU stop içerir.

Açık nokta: Cancel wrapper içinde POWER_ON yazımı yok. Ses +0x1a0 hedefinin taban implementasyonu 8 baytlık jr ra/nop stub olabilir; bundan mute veya güç kesme sonucu çıkarılmaz. Aktif override bilinmiyor.

[`00532f24 C`](../../analiz/native/ui-targeted/system-critical14/00532f24.c) / [assembly JSON](../../analiz/native/ui-targeted/system-critical14/00532f24.json) · [`00532df4 C`](../../analiz/native/ui-targeted/system-critical14/00532df4.c) / [assembly JSON](../../analiz/native/ui-targeted/system-critical14/00532df4.json)

Kontrol adresleri: `0x005330f8`, `0x00533104`, `0x00533110`, `0x00533118`, `0x005331cc`.

## Aktif anten girdi dönüşümü

Özgün enum globalde saklanır; DB setter için değer input==1 olarak dönüştürülür. DB getter sonucu AdjustAntenna5V yoluna gider. Wrapper sabit 1 döndürür; bu donanım başarı durumu değildir.

Açık nokta: Decompiler this/prototype ve düşen argümanları assembly ile yorumlanmalıdır; SDK/driver hata dönüşü henüz bağlanmadı.

[`0061d2a4 C`](../../analiz/native/ui-targeted/system-critical14/0061d2a4.c) / [assembly JSON](../../analiz/native/ui-targeted/system-critical14/0061d2a4.json)

Kontrol adresleri: `0x0061d2ec`, `0x0061d304`, `0x0061d360`, `0x0061d390`.

## LNB güç eşlemesi

Girdi 1→1, 2→4, diğer→0. SatInfo+0x0f ve arSatTuningParams+0x16 byte alanlarına yazılır; +0x9b0 sanal çağrı, SatelliteUserInteraction(2), +0xa34 retune ve changed flag yolu vardır. Başarı wrapperı 1; cast failure assert/abort.

Açık nokta: DVBS customer runtime override ve fiziksel voltaj etkisi doğrulanmadı.

[`00620940 C`](../../analiz/native/ui-targeted/system-critical14/00620940.c) / [assembly JSON](../../analiz/native/ui-targeted/system-critical14/00620940.json)

Kontrol adresleri: `0x00620974`, `0x00620ae4`, `0x00620af0`, `0x00620b08`.

## Tarama durumu ve ATV indeks dönüşümü

Pause/resume this+0x6c durumuna göre DTV +0x128/+0x12c veya ATV +0xe4/+0xe8 dispatch yapar; state=0 için +0x95 seçimi, geçersiz durumda assert vardır. ATV moveMode=0 kaydında ((input&255)-1)&255 geçirilir: 0 girdisi 255 olur; diğer mod SaveProgramToBack yoludur.

Açık nokta: 0→255 dönüşümünün ürün düzeyinde hata mı sentinel mı olduğu, çağıran sözleşmesi çözülmeden söylenemez.

[`004f1c3c C`](../../analiz/native/ui-targeted/system-critical14/004f1c3c.c) / [assembly JSON](../../analiz/native/ui-targeted/system-critical14/004f1c3c.json) · [`004f1a20 C`](../../analiz/native/ui-targeted/system-critical14/004f1a20.c) / [assembly JSON](../../analiz/native/ui-targeted/system-critical14/004f1a20.json) · [`004f86bc C`](../../analiz/native/ui-targeted/system-critical14/004f86bc.c) / [assembly JSON](../../analiz/native/ui-targeted/system-critical14/004f86bc.json)

Kontrol adresleri: `0x004f87c4`, `0x004f87dc`.

## OAD kabul wrapperlarının dönüşleri

StartOADUpgrade sanal +0x610 çağrısından sonra sabit 1 döndürür. DVB taban vtable adayı +0x610→0x2d4e2b44; bu fonksiyon this+0x2b8 ve customer cast koşulunda customer kabul çağrısı ardından 1, diğer durumda 0 döndürür. Customer sonucu forward edilmez. CheckAfterWakeUp ise customer dönüşünü tail-forward eder.

Açık nokta: Vtable eşlemesi statik primary-address-point adayıdır. Customer kabul 0x2e16aad0 ve wake-up check 0x2e1695fc koşulları henüz çözülmedi; firmware kabul/imza kanıtı değildir.

[`00642a50 C`](../../analiz/native/ui-targeted/system-critical14/00642a50.c) / [assembly JSON](../../analiz/native/ui-targeted/system-critical14/00642a50.json) · [`2d4e2b44 C`](../../analiz/native/system-focused/93fe7286bb7fb9bf3d33ccf75556985f68666fe485241099c20bb7165bc88d97/oad-path2/2d4e2b44.c) / [assembly JSON](../../analiz/native/system-focused/93fe7286bb7fb9bf3d33ccf75556985f68666fe485241099c20bb7165bc88d97/oad-path2/2d4e2b44.json) · [`2d4e2a78 C`](../../analiz/native/system-focused/93fe7286bb7fb9bf3d33ccf75556985f68666fe485241099c20bb7165bc88d97/oad-path2/2d4e2a78.c) / [assembly JSON](../../analiz/native/system-focused/93fe7286bb7fb9bf3d33ccf75556985f68666fe485241099c20bb7165bc88d97/oad-path2/2d4e2a78.json)

Kontrol adresleri: `0x00642ae8`.

## Manuel OAD ve standby update parametreleri

GetOadDownInfo stack üzerinde çıktı yapısı doldurur; TV mode 1/32/128 için yapı+0x11 byte→OadScanRF, diğer modlarda yapı+8 word→OadScanFreq; wrapper sabit 1. Standby update timer/on-timer/OAD schedule sorgularına a1=1200 verir; standby-scan flag OR 1, auto-OAD flag OR 4 yolları vardır.

Açık nokta: 1200 parametresinin zaman birimi ve GetOadDownInfo tam yapı prototipi açık. Decompiler sözde başlatılmamış stack değerlerini gerçek C hatası diye sunma.

[`006430b4 C`](../../analiz/native/ui-targeted/system-critical14/006430b4.c) / [assembly JSON](../../analiz/native/ui-targeted/system-critical14/006430b4.json) · [`00640ecc C`](../../analiz/native/ui-targeted/system-critical14/00640ecc.c) / [assembly JSON](../../analiz/native/ui-targeted/system-critical14/00640ecc.json)

Kontrol adresleri: `0x0064108c`, `0x006410d8`, `0x006412f4`, `0x0064142c`, `0x00641564`.

## Uygulama main callback ve UI başlangıcı

ELF startup main callback adayı 0xfd0784, FDE [0xfd0784,0xfd2c0c). a0/a1 girişte stacke saklanır; C çıktısının float,float,int,char** prototipi güvenilir değildir. Build→MSystem Initialize→InitMSrvControl→StartMsrv→ReadResProfile sırası kodda bulunur. Profile sonucu 0 ise UI kurulmadan ortak return yoluna gider. Factory/GetDefault ve oluşturulan app null ise -1; başarılı dalda MApplet::Run(DefaultApp,0xfe,0), ardından NotifyBootUpCompleted. Console/test dalları MSystem::Run yolunu değiştirir.

Açık nokta: Factory +8 callback hedefi ve aktif DefaultApp sınıfı henüz kanıtlanmadı. MApplet Run C prototipi a2=0 argümanını düşürür. Fonksiyon main callback olarak startup/PLT bağından güçlü adaydır; ISO C main prototipi iddia edilmez.

[`00fd0784 C`](../../analiz/native/ui-targeted/startup-main1/00fd0784.c) / [assembly JSON](../../analiz/native/ui-targeted/startup-main1/00fd0784.json)

Kontrol adresleri: `0x00fd07a8`, `0x00fd07ac`, `0x00fd0810`, `0x00fd0b70`, `0x00fd0d7c`, `0x00fd22a0`, `0x00fd22c8`, `0x00fd22dc`, `0x00fd2374`, `0x00fd2388`, `0x00fd23cc`, `0x00fd23ec`, `0x00fd2434`, `0x00fd24e8`, `0x00fd2b98`.
