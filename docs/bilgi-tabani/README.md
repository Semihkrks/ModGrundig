# Grundig firmware bilgi tabanı

Öncelik: özgün firmware’i değiştirmeden mimariyi ve davranışları kanıtlarıyla çözmek. Cihazda çalıştırma, repack veya yükleme yapılmadı.

[Genel bulgular](../TERSINE_MUHENDISLIK.md) · [UI kod yapısı](../UI_KOD_YAPISI.md) · [UI ayrıntıları](../UI_HARITASI.md) · [Boot ve format](BOOT_VE_FORMAT.md) · [Servis davranışları](SERVISLER.md) · [Bağımlılık araştırması](BAGIMLILIKLAR.md) · [Servis derinleştirme](SERVIS_DERINLESTIRME.md) · [DirectFB callback çözümü](DIRECTFB_CALLBACK.md) · [Dar UI devamı](UI_DAR_DEVAM.md) · [Araç sınırları](ARAC_SINIRLARI.md) · [Aşama raporu](ASAMA_2026-10-22.md) · [Araştırma takibi](TAKIP.md) · [Ölçülebilir durum](../../analiz/asama-durum.json)

## Kapsam

- ELF: 226 dosya yolu / 224 benzersiz hash; tümünün statik sembol/bağımlılık envanteri mevcut.
- Ghidra indeksi mevcut dosya yolu: 226/226.
- Bu sistem taramasında 222 yeni artifact, 106930 fonksiyon kaydı, 2376133 xref.
- İlk örnek decompile: 837/837; analiz timeout: 4.
- Güncel odaklı sorgular: 174 benzersiz giriş / 170 tamamlanmış C; dört büyük UI gövdesi ayrıca takipte.
- Ham bootloader komutları ayrı kapsam: 5/5 decompile; [bulgular](../../analiz/native/boot-candidate-v1/FINDINGS.md).
- Decompile tamamlanması doğruluk veya semantik inceleme tamamlanması değildir. Fonksiyon sayıları external/thunk kayıtları içerebilir. Dolaylı hedefler açıkça adaydır.

## Modüller

| Modül | Aşama durumu | Fonksiyon | İlk örnek C |
|---|---|---:|---:|
| [`06_RFS/bin/busybox`](moduller/8cff67625e60__busybox.md) | Ghidra indeks tamam | 2159 | 3/3 |
| [`06_RFS/bin/dbus-daemon`](moduller/7d9440364674__dbus-daemon.md) | Ghidra indeks tamam | 1787 | 6/6 |
| [`06_RFS/bin/gdbserver`](moduller/3a21983cdedb__gdbserver.md) | Ghidra indeks tamam | 289 | 6/6 |
| [`06_RFS/bin/mkdfiff`](moduller/4170fa1fd9f3__mkdfiff.md) | Ghidra indeks tamam | 51 | 1/1 |
| [`06_RFS/bin/mkdgiff`](moduller/e4ef15bf243a__mkdgiff.md) | Ghidra indeks tamam | 37 | 1/1 |
| [`06_RFS/bin/ntpdate`](moduller/74553edaf3de__ntpdate.md) | Ghidra indeks tamam | 236 | 6/6 |
| [`06_RFS/bin/rg`](moduller/6b058edde01d__rg.md) | Ghidra indeks tamam | 23 | 1/1 |
| [`06_RFS/bin/sed-v4.2.1`](moduller/459394fa3756__sed-v4.2.1.md) | Ghidra indeks tamam | 440 | 6/6 |
| [`06_RFS/bin/targetbot_server`](moduller/ad4dd9b79313__targetbot_server.md) | Ghidra indeks tamam | 48 | 2/2 |
| [`06_RFS/etc/init.d/nscd`](moduller/a1f8bda87e2f__nscd.md) | Ghidra indeks tamam | 135 | 3/3 |
| [`06_RFS/lib/ld-2.8.so`](moduller/fe601ae62268__ld-2.8.so.md) | Ghidra indeks tamam | 73 | 1/1 |
| [`06_RFS/lib/libBrokenLocale-2.8.so`](moduller/b477879c43fc__libBrokenLocale-2.8.so.md) | Ghidra indeks tamam | 10 | 1/1 |
| [`06_RFS/lib/libSegFault.so`](moduller/c0ee2ed50b1f__libSegFault.so.md) | Ghidra indeks tamam | 48 | 1/1 |
| [`06_RFS/lib/libanl-2.8.so`](moduller/21db91a4d347__libanl-2.8.so.md) | Ghidra indeks tamam | 58 | 1/1 |
| [`06_RFS/lib/libanl.so.1`](moduller/21db91a4d347__libanl.so.1.md) | Ghidra indeks tamam | 58 | 1/1 |
| [`06_RFS/lib/libc-2.8.so`](moduller/7c0e5900f24a__libc-2.8.so.md) | Ghidra indeks tamam | 2305 | 6/6 |
| [`06_RFS/lib/libcidn-2.8.so`](moduller/4c4c7a4170bd__libcidn-2.8.so.md) | Ghidra indeks tamam | 55 | 1/1 |
| [`06_RFS/lib/libcrypt-2.8.so`](moduller/e8e0a1542e96__libcrypt-2.8.so.md) | Ghidra indeks tamam | 37 | 1/1 |
| [`06_RFS/lib/libdbus-1.so.3.4.0`](moduller/d788e9d3d05b__libdbus-1.so.3.4.0.md) | Ghidra indeks tamam | 1209 | 6/6 |
| [`06_RFS/lib/libdl-2.8.so`](moduller/d7fe76ce3c62__libdl-2.8.so.md) | Ghidra indeks tamam | 36 | 5/5 |
| [`06_RFS/lib/libexpat.so.1.5.2`](moduller/ec8f52577544__libexpat.so.1.5.2.md) | Ghidra indeks tamam | 222 | 6/6 |
| [`06_RFS/lib/libgcc_s.so.1`](moduller/e12aeecb3262__libgcc_s.so.1.md) | Ghidra indeks tamam | 1163 | 1/1 |
| [`06_RFS/lib/libiw.so.29`](moduller/f271b15d91cc__libiw.so.29.md) | Ghidra indeks tamam | 104 | 6/6 |
| [`06_RFS/lib/libm-2.8.so`](moduller/8254aa2fc566__libm-2.8.so.md) | Ghidra indeks tamam | 255 | 4/4 |
| [`06_RFS/lib/libmemusage.so`](moduller/167bb3bf7326__libmemusage.so.md) | Ghidra indeks tamam | 55 | 1/1 |
| [`06_RFS/lib/libnsl-2.8.so`](moduller/889fbef74189__libnsl-2.8.so.md) | Ghidra indeks tamam | 364 | 4/4 |
| [`06_RFS/lib/libnss_compat-2.8.so`](moduller/96c88bb38c39__libnss_compat-2.8.so.md) | Ghidra indeks tamam | 103 | 2/2 |
| [`06_RFS/lib/libnss_dns-2.8.so`](moduller/48e6049167e9__libnss_dns-2.8.so.md) | Ghidra indeks tamam | 74 | 1/1 |
| [`06_RFS/lib/libnss_files-2.8.so`](moduller/f91c4574eecc__libnss_files-2.8.so.md) | Ghidra indeks tamam | 158 | 1/1 |
| [`06_RFS/lib/libnss_hesiod-2.8.so`](moduller/fc000efdf471__libnss_hesiod-2.8.so.md) | Ghidra indeks tamam | 94 | 2/2 |
| [`06_RFS/lib/libnss_nis-2.8.so`](moduller/aa8e7026b8cf__libnss_nis-2.8.so.md) | Ghidra indeks tamam | 158 | 2/2 |
| [`06_RFS/lib/libnss_nisplus-2.8.so`](moduller/ee7275f8085f__libnss_nisplus-2.8.so.md) | Ghidra indeks tamam | 158 | 2/2 |
| [`06_RFS/lib/libpcprofile.so`](moduller/da39b515e45a__libpcprofile.so.md) | Ghidra indeks tamam | 18 | 1/1 |
| [`06_RFS/lib/libpthread-2.8.so`](moduller/664a35efa581__libpthread-2.8.so.md) | Ghidra indeks tamam | 355 | 6/6 |
| [`06_RFS/lib/libresolv-2.8.so`](moduller/8e2719734540__libresolv-2.8.so.md) | Ghidra indeks tamam | 199 | 1/1 |
| [`06_RFS/lib/librt-2.8.so`](moduller/409c4a5c206f__librt-2.8.so.md) | Ghidra indeks tamam | 141 | 4/4 |
| [`06_RFS/lib/libstdc++.so.6.0.10`](moduller/11427a71b958__libstdc++.so.6.0.10.md) | Ghidra indeks tamam | 2614 | 6/6 |
| [`06_RFS/lib/libthread_db-1.0.so`](moduller/4b2462e67965__libthread_db-1.0.so.md) | Ghidra indeks tamam | 72 | 2/2 |
| [`06_RFS/lib/libutil-2.8.so`](moduller/92509d87645a__libutil-2.8.so.md) | Ghidra indeks tamam | 75 | 1/1 |
| [`06_RFS/sbin/iwconfig`](moduller/f129be34b2bc__iwconfig.md) | Ghidra indeks tamam | 81 | 4/4 |
| [`06_RFS/sbin/iwlist`](moduller/e475db7905e1__iwlist.md) | Ghidra indeks tamam | 75 | 3/3 |
| [`06_RFS/sbin/mkfs.ext3`](moduller/4d77d361b7b5__mkfs.ext3.md) | Ghidra indeks tamam | 427 | 2/2 |
| [`07_MSLIB/directfb-1.4-0/gfxdrivers/libdirectfb_mstar_g2.so`](moduller/37b38af83183__libdirectfb_mstar_g2.so.md) | Ghidra indeks tamam | 393 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/inputdrivers/libdirectfb_mstar_linux_input.so`](moduller/4101c4ea5387__libdirectfb_mstar_linux_input.so.md) | Ghidra indeks tamam | 129 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/inputdrivers/libdirectfb_mstar_loopback_input.so`](moduller/b70164856699__libdirectfb_mstar_loopback_input.so.md) | Ghidra indeks tamam | 31 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/inputdrivers/libdirectfb_mstar_networkir.so`](moduller/3b58e1881303__libdirectfb_mstar_networkir.so.md) | Ghidra indeks tamam | 79 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/inputdrivers/libdirectfb_mstarir.so`](moduller/5c081fe8e975__libdirectfb_mstarir.so.md) | Ghidra indeks tamam | 67 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/inputdrivers/libdirectfb_mstarkeypad.so`](moduller/b5b4843f1f0c__libdirectfb_mstarkeypad.so.md) | Ghidra indeks tamam | 78 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/interfaces/IDirectFBFont/libidirectfbfont_default.so`](moduller/fa85f9ce4d95__libidirectfbfont_default.so.md) | Ghidra indeks tamam | 42 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/interfaces/IDirectFBFont/libidirectfbfont_dgiff.so`](moduller/46ba59dea652__libidirectfbfont_dgiff.so.md) | Ghidra indeks tamam | 61 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/interfaces/IDirectFBFont/libidirectfbfont_ft2.so`](moduller/14477cfc672d__libidirectfbfont_ft2.so.md) | Ghidra indeks tamam | 85 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/interfaces/IDirectFBFont/libidirectfbfont_mstarbmp.so`](moduller/735c2c7f4e8a__libidirectfbfont_mstarbmp.so.md) | Ghidra indeks tamam | 70 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/interfaces/IDirectFBImageProvider/libidirectfbimageprovider_bmp.so`](moduller/d55305920b1e__libidirectfbimageprovider_bmp.so.md) | Ghidra indeks tamam | 37 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/interfaces/IDirectFBImageProvider/libidirectfbimageprovider_dfiff.so`](moduller/a9de833be7b4__libidirectfbimageprovider_dfiff.so.md) | Ghidra indeks tamam | 49 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/interfaces/IDirectFBImageProvider/libidirectfbimageprovider_gif.so`](moduller/5715344b2ec0__libidirectfbimageprovider_gif.so.md) | Ghidra indeks tamam | 57 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/interfaces/IDirectFBImageProvider/libidirectfbimageprovider_gopc.so`](moduller/92a21a681901__libidirectfbimageprovider_gopc.so.md) | Ghidra indeks tamam | 162 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/interfaces/IDirectFBImageProvider/libidirectfbimageprovider_jpeg.so`](moduller/b6e9f424b9fb__libidirectfbimageprovider_jpeg.so.md) | Ghidra indeks tamam | 144 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/interfaces/IDirectFBImageProvider/libidirectfbimageprovider_mif.so`](moduller/c6904972e5cc__libidirectfbimageprovider_mif.so.md) | Ghidra indeks tamam | 49 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/interfaces/IDirectFBImageProvider/libidirectfbimageprovider_png.so`](moduller/09e101bb7fe8__libidirectfbimageprovider_png.so.md) | Ghidra indeks tamam | 136 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/interfaces/IDirectFBImageProvider/libidirectfbimageprovider_pnm.so`](moduller/b182fa2f6d78__libidirectfbimageprovider_pnm.so.md) | Ghidra indeks tamam | 44 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/interfaces/IDirectFBImageProvider/libidirectfbimageprovider_vec.so`](moduller/c706efe9a6e0__libidirectfbimageprovider_vec.so.md) | Ghidra indeks tamam | 87 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/interfaces/IDirectFBVideoProvider/libidirectfbvideoprovider_gif.so`](moduller/d901a0975922__libidirectfbvideoprovider_gif.so.md) | Ghidra indeks tamam | 71 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/interfaces/IDirectFBVideoProvider/libidirectfbvideoprovider_gopc.so`](moduller/3103879263ee__libidirectfbvideoprovider_gopc.so.md) | Ghidra indeks tamam | 136 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/interfaces/IDirectFBVideoProvider/libidirectfbvideoprovider_v4l.so`](moduller/cb41d30f63e6__libidirectfbvideoprovider_v4l.so.md) | Ghidra indeks tamam | 94 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/interfaces/IDirectFBVideoProvider/libidirectfbvideoprovider_vec.so`](moduller/05ce58375f0e__libidirectfbvideoprovider_vec.so.md) | Ghidra indeks tamam | 106 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/systems/libdirectfb_devmem.so`](moduller/67eb99802aa2__libdirectfb_devmem.so.md) | Ghidra indeks tamam | 181 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/wm/libdirectfbwm_default.so`](moduller/5e01cb95e5a9__libdirectfbwm_default.so.md) | Ghidra indeks tamam | 156 | 1/1 |
| [`07_MSLIB/directfb-1.4-0/wm/libdirectfbwm_sawman.so`](moduller/23e32768765a__libdirectfbwm_sawman.so.md) | Ghidra indeks tamam | 134 | 1/1 |
| [`07_MSLIB/lib4758cca.so`](moduller/4e17b7b2d6b6__lib4758cca.so.md) | Ghidra indeks tamam | 114 | 3/3 |
| [`07_MSLIB/libMBacktrace.so`](moduller/aa635dd7153f__libMBacktrace.so.md) | Ghidra indeks tamam | 37 | 1/1 |
| [`07_MSLIB/libMLog.so`](moduller/2c1eb5b707fe__libMLog.so.md) | Ghidra indeks tamam | 81 | 3/3 |
| [`07_MSLIB/libMStarSDK.so`](moduller/00d147f752f9__libMStarSDK.so.md) | Ghidra indeks tamam; analiz süre sınırlı | 10730 | 6/6 |
| [`07_MSLIB/libMStarSDK_customer.so`](moduller/4ebd5fc038a8__libMStarSDK_customer.so.md) | Ghidra indeks tamam | 2523 | 6/6 |
| [`07_MSLIB/libPQ.so`](moduller/2510703171ed__libPQ.so.md) | Ghidra indeks tamam | 304 | 5/5 |
| [`07_MSLIB/libPQ_cus.so`](moduller/f6787274fb20__libPQ_cus.so.md) | Ghidra indeks tamam | 211 | 4/4 |
| [`07_MSLIB/libSema.so`](moduller/17cd307d7a35__libSema.so.md) | Ghidra indeks tamam | 28 | 1/1 |
| [`07_MSLIB/libTEEClient.so`](moduller/322e0da0e28f__libTEEClient.so.md) | Ghidra indeks tamam | 176 | 6/6 |
| [`07_MSLIB/libaep.so`](moduller/8910b256b1fe__libaep.so.md) | Ghidra indeks tamam | 108 | 2/2 |
| [`07_MSLIB/libar_Fpga_I2C_Interface.so`](moduller/706b283e64a7__libar_Fpga_I2C_Interface.so.md) | Ghidra indeks tamam | 35 | 1/1 |
| [`07_MSLIB/libar_MegaDCR.so`](moduller/5f3067a83d1a__libar_MegaDCR.so.md) | Ghidra indeks tamam | 36 | 1/1 |
| [`07_MSLIB/libar_cec.so`](moduller/6177c73cfd0c__libar_cec.so.md) | Ghidra indeks tamam | 247 | 6/6 |
| [`07_MSLIB/libar_cloner.so`](moduller/bea32df0dfb8__libar_cloner.so.md) | Ghidra indeks tamam | 47 | 1/1 |
| [`07_MSLIB/libar_factory_automation_code.so`](moduller/3aafa840b793__libar_factory_automation_code.so.md) | Ghidra indeks tamam | 180 | 3/3 |
| [`07_MSLIB/libar_mmrgLibrary.so`](moduller/7bd6342bb20f__libar_mmrgLibrary.so.md) | Ghidra indeks tamam | 293 | 5/5 |
| [`07_MSLIB/libar_qrcode.so`](moduller/eed6c0cf75cf__libar_qrcode.so.md) | Ghidra indeks tamam | 157 | 3/3 |
| [`07_MSLIB/libar_unicable.so`](moduller/16c9d8f23f71__libar_unicable.so.md) | Ghidra indeks tamam | 22 | 3/3 |
| [`07_MSLIB/libatalla.so`](moduller/fcc2c2edfcf8__libatalla.so.md) | Ghidra indeks tamam | 106 | 2/2 |
| [`07_MSLIB/libatclient.so`](moduller/ff329df4fd23__libatclient.so.md) | Ghidra indeks tamam | 86 | 1/1 |
| [`07_MSLIB/libbrick_terminator_info.so`](moduller/dbb3e5d650d0__libbrick_terminator_info.so.md) | Ghidra indeks tamam | 43 | 2/2 |
| [`07_MSLIB/libcapi.so`](moduller/0210c6a62b96__libcapi.so.md) | Ghidra indeks tamam | 9 | 1/1 |
| [`07_MSLIB/libcares.so.2.0.0`](moduller/1d5d549f5631__libcares.so.2.0.0.md) | Ghidra indeks tamam | 106 | 5/5 |
| [`07_MSLIB/libcharset.so.1.0.0`](moduller/c57c9e5a2acf__libcharset.so.1.0.0.md) | Ghidra indeks tamam | 47 | 1/1 |
| [`07_MSLIB/libchil.so`](moduller/f80381fbf57f__libchil.so.md) | Ghidra indeks tamam | 163 | 6/6 |
| [`07_MSLIB/libcrypto.so.0.9.8`](moduller/1684e17c5322__libcrypto.so.0.9.8.md) | Ghidra indeks tamam; analiz süre sınırlı | 3820 | 6/6 |
| [`07_MSLIB/libcswift.so`](moduller/d93d5c85ec32__libcswift.so.md) | Ghidra indeks tamam | 121 | 3/3 |
| [`07_MSLIB/libcurl.so.4.2.0`](moduller/3d130aa1c25c__libcurl.so.4.2.0.md) | Ghidra indeks tamam | 660 | 6/6 |
| [`07_MSLIB/libcusinfo.so`](moduller/81276e9fb372__libcusinfo.so.md) | Ghidra indeks tamam | 21 | 2/2 |
| [`07_MSLIB/libdevice_customer.so`](moduller/9df0b6ba5f71__libdevice_customer.so.md) | Ghidra indeks tamam | 864 | 6/6 |
| [`07_MSLIB/libdirect-1.4.so.0.2.0`](moduller/9f80d27490e6__libdirect-1.4.so.0.2.0.md) | Ghidra indeks tamam | 290 | 6/6 |
| [`07_MSLIB/libdirectfb-1.4.so.0.2.0`](moduller/b05201025cab__libdirectfb-1.4.so.0.2.0.md) | Ghidra indeks tamam | 1275 | 6/6 |
| [`07_MSLIB/libdlmalloc.so`](moduller/0e10ffb2265e__libdlmalloc.so.md) | Ghidra indeks tamam | 59 | 1/1 |
| [`07_MSLIB/libfastlz.so`](moduller/8291ffa557ee__libfastlz.so.md) | Ghidra indeks tamam | 12 | 1/1 |
| [`07_MSLIB/libfreetype.so.6.11.2`](moduller/9bb5e5dd922a__libfreetype.so.6.11.2.md) | Ghidra indeks tamam | 1547 | 6/6 |
| [`07_MSLIB/libfusion-1.4.so.0.2.0`](moduller/a1561123d3eb__libfusion-1.4.so.0.2.0.md) | Ghidra indeks tamam | 237 | 6/6 |
| [`07_MSLIB/libgio-2.0.so.0.2400.2`](moduller/5e256f73c5ac__libgio-2.0.so.0.2400.2.md) | Ghidra indeks tamam | 2373 | 6/6 |
| [`07_MSLIB/libglib-2.0.so.0.2400.2`](moduller/a587ce9e0778__libglib-2.0.so.0.2400.2.md) | Ghidra indeks tamam | 1784 | 6/6 |
| [`07_MSLIB/libgmodule-2.0.so.0.2400.2`](moduller/af256e415875__libgmodule-2.0.so.0.2400.2.md) | Ghidra indeks tamam | 79 | 1/1 |
| [`07_MSLIB/libgmp.so`](moduller/44be03b2af20__libgmp.so.md) | Ghidra indeks tamam | 9 | 1/1 |
| [`07_MSLIB/libgobject-2.0.so.0.2400.2`](moduller/aee960de5945__libgobject-2.0.so.0.2400.2.md) | Ghidra indeks tamam | 716 | 6/6 |
| [`07_MSLIB/libgthread-2.0.so.0.2400.2`](moduller/d4f00f3438a9__libgthread-2.0.so.0.2400.2.md) | Ghidra indeks tamam | 92 | 3/3 |
| [`07_MSLIB/libiconv.so.2.5.0`](moduller/ab79c529549b__libiconv.so.2.5.0.md) | Ghidra indeks tamam | 358 | 1/1 |
| [`07_MSLIB/libicudata.so.42.1`](moduller/285012dbce80__libicudata.so.42.1.md) | Ghidra indeks tamam | 1 | 0/0 |
| [`07_MSLIB/libicui18n.so.42.1`](moduller/fac5da9a55d0__libicui18n.so.42.1.md) | Ghidra indeks tamam | 1706 | 6/6 |
| [`07_MSLIB/libicule.so.42.1`](moduller/8ee798970a60__libicule.so.42.1.md) | Ghidra indeks tamam | 781 | 6/6 |
| [`07_MSLIB/libiculx.so.42.1`](moduller/6f70a89c8166__libiculx.so.42.1.md) | Ghidra indeks tamam | 266 | 6/6 |
| [`07_MSLIB/libicutu.so.42.1`](moduller/91d7402e65d9__libicutu.so.42.1.md) | Ghidra indeks tamam | 373 | 1/1 |
| [`07_MSLIB/libicuuc.so.42.1`](moduller/d9de405ba4f1__libicuuc.so.42.1.md) | Ghidra indeks tamam | 2989 | 6/6 |
| [`07_MSLIB/libiniparser.so`](moduller/16e50b51510a__libiniparser.so.md) | Ghidra indeks tamam | 73 | 1/1 |
| [`07_MSLIB/libjpeg.so.62.0.0`](moduller/842d8eaab9b7__libjpeg.so.62.0.0.md) | Ghidra indeks tamam | 354 | 6/6 |
| [`07_MSLIB/libmdebug.so`](moduller/9c91433016cd__libmdebug.so.md) | Ghidra indeks tamam | 146 | 4/4 |
| [`07_MSLIB/libmdmpplayer.so`](moduller/fc1b512c862f__libmdmpplayer.so.md) | Ghidra indeks tamam | 344 | 6/6 |
| [`07_MSLIB/libmmsdk.so`](moduller/d0a66142dfa6__libmmsdk.so.md) | Ghidra indeks tamam | 537 | 2/2 |
| [`07_MSLIB/libmmsdk_porting.so`](moduller/3097e030b2ef__libmmsdk_porting.so.md) | Ghidra indeks tamam | 386 | 6/6 |
| [`07_MSLIB/libmsrv_atv.so`](moduller/ff35f7ad1def__libmsrv_atv.so.md) | Ghidra indeks tamam | 531 | 6/6 |
| [`07_MSLIB/libmsrv_atv_customer.so`](moduller/f66079435087__libmsrv_atv_customer.so.md) | Ghidra indeks tamam | 401 | 2/2 |
| [`07_MSLIB/libmsrv_autotest.so`](moduller/40d6518bd816__libmsrv_autotest.so.md) | Ghidra indeks tamam | 723 | 6/6 |
| [`07_MSLIB/libmsrv_common.so`](moduller/06bc6252713a__libmsrv_common.so.md) | Ghidra indeks tamam; analiz süre sınırlı | 3617 | 6/6 |
| [`07_MSLIB/libmsrv_common_customer.so`](moduller/394ee95f0738__libmsrv_common_customer.so.md) | Ghidra indeks tamam | 2724 | 6/6 |
| [`07_MSLIB/libmsrv_control.so`](moduller/0b154eba8a18__libmsrv_control.so.md) | Ghidra indeks tamam | 839 | 6/6 |
| [`07_MSLIB/libmsrv_control_customer.so`](moduller/dbb8dc826b7f__libmsrv_control_customer.so.md) | Ghidra indeks tamam | 407 | 6/6 |
| [`07_MSLIB/libmsrv_dvb.so`](moduller/93fe7286bb7f__libmsrv_dvb.so.md) | Ghidra indeks tamam; analiz süre sınırlı | 4048 | 6/6 |
| [`07_MSLIB/libmsrv_dvb_customer.so`](moduller/67b12c702342__libmsrv_dvb_customer.so.md) | Ghidra indeks tamam | 1888 | 6/6 |
| [`07_MSLIB/libmsrv_dvbc.so`](moduller/5896e9f66231__libmsrv_dvbc.so.md) | Ghidra indeks tamam | 820 | 6/6 |
| [`07_MSLIB/libmsrv_dvbc_customer.so`](moduller/4c606889985e__libmsrv_dvbc_customer.so.md) | Ghidra indeks tamam | 835 | 6/6 |
| [`07_MSLIB/libmsrv_dvbs.so`](moduller/daa8f91f94a6__libmsrv_dvbs.so.md) | Ghidra indeks tamam | 1040 | 6/6 |
| [`07_MSLIB/libmsrv_dvbs_customer.so`](moduller/9c3d825e7162__libmsrv_dvbs_customer.so.md) | Ghidra indeks tamam | 1178 | 6/6 |
| [`07_MSLIB/libmsrv_dvbt.so`](moduller/ed1d6209c435__libmsrv_dvbt.so.md) | Ghidra indeks tamam | 830 | 6/6 |
| [`07_MSLIB/libmsrv_dvbt_customer.so`](moduller/58b171d77de1__libmsrv_dvbt_customer.so.md) | Ghidra indeks tamam | 846 | 6/6 |
| [`07_MSLIB/libmsrv_mmbrowser.so`](moduller/0cbc7c5ecf32__libmsrv_mmbrowser.so.md) | Ghidra indeks tamam | 1314 | 6/6 |
| [`07_MSLIB/libmsrv_mmplayer.so`](moduller/52fb941b0c3d__libmsrv_mmplayer.so.md) | Ghidra indeks tamam | 243 | 3/3 |
| [`07_MSLIB/libmsrv_network.so`](moduller/55b8009ddeff__libmsrv_network.so.md) | Ghidra indeks tamam | 567 | 6/6 |
| [`07_MSLIB/libmsrv_network_sn.so`](moduller/60a935b26f09__libmsrv_network_sn.so.md) | Ghidra indeks tamam | 160 | 6/6 |
| [`07_MSLIB/libmsrv_system_database.so`](moduller/dbdef96fed7b__libmsrv_system_database.so.md) | Ghidra indeks tamam | 1297 | 6/6 |
| [`07_MSLIB/libmsrv_system_database_customer.so`](moduller/420859c1e0af__libmsrv_system_database_customer.so.md) | Ghidra indeks tamam | 553 | 3/3 |
| [`07_MSLIB/libmtclient.so`](moduller/93621754e6ab__libmtclient.so.md) | Ghidra indeks tamam | 193 | 1/1 |
| [`07_MSLIB/libmuf.so`](moduller/494d4aa45a3c__libmuf.so.md) | Önceki Ghidra + odaklı UI analizi | önceki UI indeksi | odaklı UI |
| [`07_MSLIB/libneon.so.27.2.3`](moduller/3206c1d1095d__libneon.so.27.2.3.md) | Ghidra indeks tamam | 727 | 6/6 |
| [`07_MSLIB/libnuron.so`](moduller/25dea2c75843__libnuron.so.md) | Ghidra indeks tamam | 90 | 2/2 |
| [`07_MSLIB/libpng.so.3.32.0`](moduller/65abc793e96b__libpng.so.3.32.0.md) | Ghidra indeks tamam | 366 | 6/6 |
| [`07_MSLIB/libpng12.so.0.32.0`](moduller/8e4e63d5e772__libpng12.so.0.32.0.md) | Ghidra indeks tamam | 392 | 6/6 |
| [`07_MSLIB/libsawman-1.4.so.0.2.0`](moduller/dc59e1229c9c__libsawman-1.4.so.0.2.0.md) | Ghidra indeks tamam | 212 | 6/6 |
| [`07_MSLIB/libssl.so.0.9.8`](moduller/a922be14f2d5__libssl.so.0.9.8.md) | Ghidra indeks tamam | 835 | 6/6 |
| [`07_MSLIB/libsureware.so`](moduller/141b3367e15a__libsureware.so.md) | Ghidra indeks tamam | 159 | 2/2 |
| [`07_MSLIB/libtee_mm.so`](moduller/d7247183165c__libtee_mm.so.md) | Ghidra indeks tamam | 17 | 1/1 |
| [`07_MSLIB/libubsec.so`](moduller/bb469406c0a9__libubsec.so.md) | Ghidra indeks tamam | 106 | 3/3 |
| [`07_MSLIB/libutilities.so`](moduller/c4596d82c0e1__libutilities.so.md) | Ghidra indeks tamam | 78 | 3/3 |
| [`07_MSLIB/libutility.so`](moduller/ef289ab91d42__libutility.so.md) | Ghidra indeks tamam | 41 | 5/5 |
| [`07_MSLIB/libvdplayer.so`](moduller/76fedf3a2226__libvdplayer.so.md) | Ghidra indeks tamam | 1229 | 6/6 |
| [`07_MSLIB/libxml2.so.2.7.7`](moduller/13c39733bf7d__libxml2.so.2.7.7.md) | Ghidra indeks tamam | 3035 | 6/6 |
| [`07_MSLIB/libz.so.1.2.8`](moduller/76610aafecc4__libz.so.1.2.8.md) | Ghidra indeks tamam | 109 | 6/6 |
| [`07_MSLIB/libzmplayer.so`](moduller/22a27083ca0d__libzmplayer.so.md) | Ghidra indeks tamam | 230 | 2/2 |
| [`07_MSLIB/preloadable_libiconv.so`](moduller/62c813b68cbb__preloadable_libiconv.so.md) | Ghidra indeks tamam | 346 | 2/2 |
| [`07_MSLIB/utopia/libMsFS.so`](moduller/edf2f901d08e__libMsFS.so.md) | Ghidra indeks tamam | 82 | 4/4 |
| [`07_MSLIB/utopia/libapiACE.so`](moduller/11d63f18d7c7__libapiACE.so.md) | Ghidra indeks tamam | 403 | 6/6 |
| [`07_MSLIB/utopia/libapiAUDIO.so`](moduller/d55e76dd24ba__libapiAUDIO.so.md) | Ghidra indeks tamam | 1270 | 6/6 |
| [`07_MSLIB/utopia/libapiCEC.so`](moduller/900f66ee625a__libapiCEC.so.md) | Ghidra indeks tamam | 209 | 6/6 |
| [`07_MSLIB/utopia/libapiDLC.so`](moduller/b784d7a8bea6__libapiDLC.so.md) | Ghidra indeks tamam | 223 | 6/6 |
| [`07_MSLIB/utopia/libapiDMX.so`](moduller/d2735b9b8583__libapiDMX.so.md) | Ghidra indeks tamam | 1072 | 6/6 |
| [`07_MSLIB/utopia/libapiGFX.so`](moduller/e9dff8d4db95__libapiGFX.so.md) | Ghidra indeks tamam | 351 | 6/6 |
| [`07_MSLIB/utopia/libapiGOP.so`](moduller/964c3be660d9__libapiGOP.so.md) | Ghidra indeks tamam | 787 | 6/6 |
| [`07_MSLIB/utopia/libapiHSL.so`](moduller/f4ba969be1c6__libapiHSL.so.md) | Ghidra indeks tamam | 138 | 6/6 |
| [`07_MSLIB/utopia/libapiJPEG.so`](moduller/b17916d1814e__libapiJPEG.so.md) | Ghidra indeks tamam | 306 | 6/6 |
| [`07_MSLIB/utopia/libapiMHL.so`](moduller/e8c64eb569d4__libapiMHL.so.md) | Ghidra indeks tamam | 304 | 6/6 |
| [`07_MSLIB/utopia/libapiPNL.so`](moduller/f6e412e96afe__libapiPNL.so.md) | Ghidra indeks tamam | 376 | 6/6 |
| [`07_MSLIB/utopia/libapiSWI2C.so`](moduller/2346863a6c5d__libapiSWI2C.so.md) | Ghidra indeks tamam | 53 | 5/5 |
| [`07_MSLIB/utopia/libapiVDEC.so`](moduller/215c0a86cdd9__libapiVDEC.so.md) | Ghidra indeks tamam | 1506 | 6/6 |
| [`07_MSLIB/utopia/libapiXC.so`](moduller/3706a8f87384__libapiXC.so.md) | Ghidra indeks tamam | 2721 | 6/6 |
| [`07_MSLIB/utopia/libapihook.so`](moduller/7ae95d8cb6d6__libapihook.so.md) | Ghidra indeks tamam | 14 | 1/1 |
| [`07_MSLIB/utopia/libdrvAESDMA.so`](moduller/24bddd93e7b1__libdrvAESDMA.so.md) | Ghidra indeks tamam | 187 | 6/6 |
| [`07_MSLIB/utopia/libdrvAUDIO.so`](moduller/7b50590ff5ab__libdrvAUDIO.so.md) | Ghidra indeks tamam | 823 | 6/6 |
| [`07_MSLIB/utopia/libdrvAUDSP.so`](moduller/b50f623ef506__libdrvAUDSP.so.md) | Ghidra indeks tamam | 7 | 1/1 |
| [`07_MSLIB/utopia/libdrvAVD.so`](moduller/8b2020fb568a__libdrvAVD.so.md) | Ghidra indeks tamam | 209 | 6/6 |
| [`07_MSLIB/utopia/libdrvCPU.so`](moduller/e7616d5f9361__libdrvCPU.so.md) | Ghidra indeks tamam | 72 | 6/6 |
| [`07_MSLIB/utopia/libdrvDDC2BI.so`](moduller/37e8fdc083a2__libdrvDDC2BI.so.md) | Ghidra indeks tamam | 34 | 5/5 |
| [`07_MSLIB/utopia/libdrvDEMOD.so`](moduller/2f8df2557e90__libdrvDEMOD.so.md) | Ghidra indeks tamam | 609 | 6/6 |
| [`07_MSLIB/utopia/libdrvDSCMB.so`](moduller/7bc9f0c0babb__libdrvDSCMB.so.md) | Ghidra indeks tamam | 165 | 6/6 |
| [`07_MSLIB/utopia/libdrvGPIO.so`](moduller/e6b009caccfb__libdrvGPIO.so.md) | Ghidra indeks tamam | 39 | 3/3 |
| [`07_MSLIB/utopia/libdrvHWI2C.so`](moduller/af1124e26315__libdrvHWI2C.so.md) | Ghidra indeks tamam | 106 | 5/5 |
| [`07_MSLIB/utopia/libdrvIPAUTH.so`](moduller/00e160cb4f4e__libdrvIPAUTH.so.md) | Ghidra indeks tamam | 31 | 2/2 |
| [`07_MSLIB/utopia/libdrvIR.so`](moduller/ce8942e58ad0__libdrvIR.so.md) | Ghidra indeks tamam | 48 | 4/4 |
| [`07_MSLIB/utopia/libdrvJPD.so`](moduller/201d3dcc2c1a__libdrvJPD.so.md) | Ghidra indeks tamam | 132 | 6/6 |
| [`07_MSLIB/utopia/libdrvMBX.so`](moduller/df5b9827cc49__libdrvMBX.so.md) | Ghidra indeks tamam | 144 | 6/6 |
| [`07_MSLIB/utopia/libdrvMSPI.so`](moduller/88b1538204b4__libdrvMSPI.so.md) | Ghidra indeks tamam | 76 | 6/6 |
| [`07_MSLIB/utopia/libdrvMVOP.so`](moduller/81e3185d9217__libdrvMVOP.so.md) | Ghidra indeks tamam | 390 | 6/6 |
| [`07_MSLIB/utopia/libdrvPCMCIA.so`](moduller/f1c885fcd956__libdrvPCMCIA.so.md) | Ghidra indeks tamam | 138 | 6/6 |
| [`07_MSLIB/utopia/libdrvPM.so`](moduller/7585898428bb__libdrvPM.so.md) | Ghidra indeks tamam | 132 | 6/6 |
| [`07_MSLIB/utopia/libdrvPWM.so`](moduller/32a4abe1d652__libdrvPWM.so.md) | Ghidra indeks tamam | 108 | 4/4 |
| [`07_MSLIB/utopia/libdrvPWS.so`](moduller/b614e8634e4b__libdrvPWS.so.md) | Ghidra indeks tamam | 73 | 6/6 |
| [`07_MSLIB/utopia/libdrvRTC.so`](moduller/9f78459f3eb4__libdrvRTC.so.md) | Ghidra indeks tamam | 60 | 4/4 |
| [`07_MSLIB/utopia/libdrvSAR.so`](moduller/4a53740a06bd__libdrvSAR.so.md) | Ghidra indeks tamam | 94 | 6/6 |
| [`07_MSLIB/utopia/libdrvSC.so`](moduller/081af8cf34c3__libdrvSC.so.md) | Ghidra indeks tamam | 98 | 6/6 |
| [`07_MSLIB/utopia/libdrvSERFLASH.so`](moduller/4829f2f6c977__libdrvSERFLASH.so.md) | Ghidra indeks tamam | 154 | 6/6 |
| [`07_MSLIB/utopia/libdrvURDMA.so`](moduller/87c8b04112b7__libdrvURDMA.so.md) | Ghidra indeks tamam | 26 | 4/4 |
| [`07_MSLIB/utopia/libdrvVBI.so`](moduller/e80b9452ac0a__libdrvVBI.so.md) | Ghidra indeks tamam | 176 | 6/6 |
| [`07_MSLIB/utopia/libdrvVE.so`](moduller/f81aab978a51__libdrvVE.so.md) | Ghidra indeks tamam | 239 | 6/6 |
| [`07_MSLIB/utopia/libdrvVIF.so`](moduller/e8f0e20a9c92__libdrvVIF.so.md) | Ghidra indeks tamam | 66 | 6/6 |
| [`07_MSLIB/utopia/libdrvWDT.so`](moduller/d2180433180e__libdrvWDT.so.md) | Ghidra indeks tamam | 61 | 4/4 |
| [`07_MSLIB/utopia/libhook.so`](moduller/b6139c29b604__libhook.so.md) | Ghidra indeks tamam | 200 | 3/3 |
| [`07_MSLIB/utopia/liblinux.so`](moduller/832d421017c2__liblinux.so.md) | Ghidra indeks tamam | 833 | 6/6 |
| [`08_APP/MLog/MLogcat`](moduller/b8a548a2eb1d__MLogcat.md) | Ghidra indeks tamam | 109 | 2/2 |
| [`08_APP/bin/dvbt_board`](moduller/51f6bd24ea6f__dvbt_board.md) | Önceki Ghidra + odaklı UI analizi | önceki UI indeksi | odaklı UI |
| [`08_APP/bin/read_piutimer1`](moduller/abcb393d485e__read_piutimer1.md) | Ghidra indeks tamam | 16 | 2/2 |
| [`09_CONFIG/krl/ir/mdrv-ir.ko`](moduller/ed37640ce6f6__mdrv-ir.ko.md) | Ghidra indeks tamam | 39 | 3/3 |
| [`09_CONFIG/krl/ir/mdrv-ir_BK.ko`](moduller/5332c7912d96__mdrv-ir_BK.ko.md) | Ghidra indeks tamam | 39 | 3/3 |
| [`09_CONFIG/krl/ir/mdrv-ir_TV.ko`](moduller/ed37640ce6f6__mdrv-ir_TV.ko.md) | Ghidra indeks tamam | 39 | 3/3 |
| [`09_CONFIG/krl/usb/ehci-hcd.ko`](moduller/5f7a96cfd0d6__ehci-hcd.ko.md) | Ghidra indeks tamam | 69 | 4/4 |
| [`09_CONFIG/krl/usb/hid.ko`](moduller/c1b757fba1b4__hid.ko.md) | Ghidra indeks tamam | 60 | 2/2 |
| [`09_CONFIG/krl/usb/usb-storage.ko`](moduller/9fe0c26c27d3__usb-storage.ko.md) | Ghidra indeks tamam | 60 | 6/6 |
| [`09_CONFIG/krl/usb/usbcore.ko`](moduller/17f50f7dfca3__usbcore.ko.md) | Ghidra indeks tamam | 336 | 6/6 |
| [`09_CONFIG/krl/usb/usbhid.ko`](moduller/91a7701524f5__usbhid.ko.md) | Ghidra indeks tamam | 41 | 6/6 |
| [`09_CONFIG/krl/usb/usbserial.ko`](moduller/f59ed384e5cb__usbserial.ko.md) | Ghidra indeks tamam | 67 | 6/6 |
| [`09_CONFIG/krl/usb/x.ko`](moduller/c7902e105402__x.ko.md) | Ghidra indeks tamam | 268 | 6/6 |
| [`09_CONFIG/libMMAPInfo.so`](moduller/1c5530208023__libMMAPInfo.so.md) | Ghidra indeks tamam | 97 | 2/2 |
| [`09_CONFIG/libdfbinfo.so`](moduller/1ff1dbcc1ed1__libdfbinfo.so.md) | Ghidra indeks tamam | 72 | 2/2 |
| [`09_CONFIG/libsysteminfo.so`](moduller/c19ce43d3926__libsysteminfo.so.md) | Ghidra indeks tamam | 418 | 6/6 |
| [`09_CONFIG/rmmod`](moduller/2b9fdbebb62f__rmmod.md) | Ghidra indeks tamam | 27 | 2/2 |
