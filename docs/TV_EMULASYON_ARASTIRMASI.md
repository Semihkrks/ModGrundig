# Gerçek firmware çalıştırma araştırması

24 Ekim devamı: **seçilmiş gerçek MUF çizim kodundan ses ve rakam kareleri üretildi**; [native test ekranı ve ölçülen kapsam](NATIVE_GORUNTU_CALISTIRMA.md). Tam uygulama açılışı ise özel UBI topolojisiyle `/dev/shm/ubi0_0` okuma kapısına ilerledi ve burada durdu. Aşağıdaki ilk `/sys/class/ubi` engeli önceki aşamanın kaydıdır; kısmi native kare ile tam TV açılışı birbirine karıştırılmamalıdır.

24 Ekim 2026. `reverse-engineer-anything` ve araştırma alt ajanı kullanıldı. Güncel kullanıcı isteği kapsamında yalnız izole bilgisayar ortamında hedef yürütme yetkisiyle çalışıldı; TV'ye, gerçek NAND'a veya güncelleme komutlarına erişilmedi.

## Kurulan ve gözlenen

**WSL üzerinde gerçek MIPS uygulama laboratuvarı kuruldu. TV ekranı henüz açılmıyor.** Bu, mevcut tarayıcı önizlemesinden farklıdır: özgün firmware'in `dvbt_board` ELF'i ve MIPS kütüphaneleri QEMU linux-user ile gerçekten yürütüldü.

- Başlatıcı: [tools/emulation-lab-run.ps1](../tools/emulation-lab-run.ps1).
- Kullanım ve gerçek sonuç: [laboratuvar README](../analiz/emulation-lab/README.md).
- [İzolasyon kontrolü](../analiz/emulation-lab/isolation-probe.json), [ölçülen durum](../analiz/emulation-lab/verification-summary.json).

```powershell
powershell -File tools/emulation-lab-run.ps1 -Variant v3
```

Komutun tamamlanması, hedef uygulamanın başarıyla açıldığı anlamına gelmez. JSON'daki `exit_code`, `screen_rendered` ve `full_board_emulator` alanları değerlendirilmelidir. Araç kendi kopyalarıyla çalışır; TV güncellemesini veya kernel/init'i başlatmaz.

Resmî Ubuntu paketinden SHA doğrulanmış QEMU MIPSel10.2.1 ayrı araç dizinine açıldı. Sistem kurulum scripti çalıştırılmadı. Bubblewrap host dosyalarını, gerçek `/dev/mem`, NAND/block/framebuffer cihazlarını ve ağı kapatır; guest salt okunur, çalışma alanları özel/geçicidir. Guest içinde shell/init/update programı veya certificate/customer provisioning bölümleri yoktur. Hedef çalıştırmadan önce izolasyon probu tekrar geçmelidir. Ham uygulama çıktısı/read buffer'ları dışarı aktarılmadan sınırlı syscall/yol/kanıtlanmış sabit diagnostikler saklanır.

Özgün/v2 başlangıçlarında 112 farklı `.so` yolu açıldı. İlk engel `mapi_system::GetBootSource 0x2cb90064` içinde `/proc/cmdline` alanında aranan `ENV=` idi. 668bayt/167instruction ve yerel diagnostik literal eşleşmesiyle sebep doğrulandı. Yalnız bu parser için açıkça sentetik `ENV=NAND` fixture'ı sağlandı; gerçek cihaz veya host kimliği kopyalanmadı.

Sonraki gerçek engel **NAND/UBI başlangıcı**:

```text
Init: 0x2cb880ac → UBI_Exist: 0x2cb85f74
open('/sys/class/ubi') → ENOENT
Init assertion: 0x2cb880d4 → abort: 0x2cb880e4
```

[Statik boot-source kanıtı](../analiz/emulation-lab/getbootsource-static.json), [NAND/UBI kanıtı](../analiz/emulation-lab/nand-init-static.json). Başarılı cihaz sonucu uydurulmadı. İki uygulamanın aynı erken kapıda durması UI patch'inin doğru çizildiğini kanıtlamaz; grafik/event yollarına henüz ulaşılmadı.

## Linux neden tek başına yetmiyor?

WSL Linux çalışma ortamıdır; TV'nin MStar kartını sağlamaz. QEMU user-mode MIPS kodu ve Linux syscall dönüşümü sağlar; özel TV çevrebirimlerinin uygulanmış olduğu sonucu buradan çıkmaz. [Resmî QEMU user-mode belgesi](https://www.qemu.org/docs/master/user/main.html).

İncelenen upstream QEMU MIPS belgeleri ve kaynak listesinde Malta/Boston/Jazz/Fuloong/Loongson modelleri var, **MStar/Grundig kart modeli bulunmadı**. Bu, bütün özel veya ticari simülatörlerin yokluğu iddiası değildir. [QEMU MIPS](https://www.qemu.org/docs/master/system/target-mips.html), [makine kaynak listesi](https://raw.githubusercontent.com/qemu/qemu/master/hw/mips/meson.build). Erişim24 Ekim2026.

FirmAE `get_qemu_machine()` içinde MIPS için Malta seçer; çalışma şablonu `-display none` kullanır. Bu kaynaklarda MStar panel/GOP desteği bulunmadı. Router/kamera yeniden barındırma sonuçları bu TV'ye başarı garantisi olarak taşınamaz. [FirmAE makine seçimi](https://raw.githubusercontent.com/pr0v3rbs/FirmAE/master/firmae.config), [çalıştırma şablonu](https://github.com/pr0v3rbs/FirmAE/blob/master/scripts/makeNetwork.py). Bu yüzden FirmAE/Firmadyne kurulumu grafik engelini çözmüş gibi sunulmadı.

## Firmware'de bulunan grafik bağımlılıkları

- `09_CONFIG/dfbrc.ini`: `DFBRC_SYSTEM="devmem"`, `ARGB4444`, MIU1 CPU offset`0x60000000`, GOP/layer eşlemeleri.
- `09_CONFIG/directfbrc`: `/mslib/directfb-1.4-0`, varsayılan1280×720 yüzey ve `mst_*` vendor seçenekleri.
- İncelenen sistem backend'i `libdirectfb_devmem.so`, grafik sürücüsü `libdirectfb_mstar_g2.so`. Hazır SDL/X11 backend'i bu ağaçta bulunmadı.
- Bu modüller `libapiGFX/GOP/XC/PNL/VDEC`, `liblinux` ve MStar servislerine bağımlılık bildirir. İsim/DT_NEEDED bağı gerçek yürütülmüş çağrıyla karıştırılmaz.
- `startup-main1/00fd0784.c`: ProductKey/Control/PNL hazırlığı, `SetGopForceWrite → MSystem::Initialize → InitializeDFBLayer → InitMSrvControl`; `StartMsrv` kaynak profili okunmadan önce gelir.

Dolayısıyla uygulama genel bir DirectFB demosu gibi yalnız SDL seçilerek açılamaz. Upstream başka DirectFB sürümünün vendor ABI'siyle eş olduğu da varsayılamaz. [Yerel callback kanıtları](bilgi-tabani/DIRECTFB_CALLBACK.md).

## Dar ama gerçek native test

Sadece firmware'in **libpng1.2.32/zlib1.2.8/glibc2.8** kütüphanelerini kullanan yeni küçük MIPS harness'i derlendi ve aynı izolasyonla çalıştırıldı. Özgün/v2/yeni kapsül PNG'lerinin üçü de çözüldü; deneysel P4+tRNS kapsülün dört köşesinde alfa0, merkezinde alfa255 ölçüldü. [Gerçek decoder sonucu](../analiz/native-png-probe/decode-result.json), [harness kaynağı](../native-ui/png-probe/README.md).

Bu test, yeni PNG'yi eski decoder'ın okuyabildiğini kanıtlar. DirectFB/GOP çıkışı, MUF ölçeklemesi, ses/CEC, tuner veya TV'deki piksel görünümü değildir.

## Kalan teknik işler

1. NAND/UBI ve servis başlangıcını doğru modellemek veya UI'yi bunlardan bağımsız bir girişten yeniden barındırmak.
2. Vendor ABI'ye uygun yazılım yüzeyi ve gerekli dar callback'leri uygulamak; önce gerçek MUF ile tek bir kareyi çizmek.
3. Ses, kanal listesi, numara ve menü event'lerini bu ortamda tek tek çalıştırmak; gerçek/emüle/taklit/çözülmemiş davranışları ayrı kaydetmek.
4. Tam kart hedeflenirse kesmeler, zamanlayıcılar, MIU/MMIO, GOP/GFX ve gereken çevrebirimleri ayrıca modellemek.

Doğrulanmış indirilebilir üretici GMGRMR/MIPS PC simülatörü kamuya açık resmî kaynak taramasında bulunmadı. Özel SDK erişimi hakkında veri yok. **Şu an kurulan ortam tam televizyon emülatörü değildir; nihai firmware ve TV uyumu tamamlandı denemez.**
