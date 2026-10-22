# `07_MSLIB/libmsrv_network_sn.so`

SHA-256: `60a935b26f0915965ba81fa023dd42bb138a5502428cb2fb3ce707765d6dc1ea`

Durum: **Ghidra indeks tamam**.

Tür: DYN (Shared object file); ELF32 LE MIPS; 51180 bayt.

İşlev alanı **isim/bağımlılık çıkarımıdır**: `[]`.
Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.

## Bağımlılık ve API beyanları

- DT_NEEDED: `libmsrv_system_database.so`, `libmsrv_system_database_customer.so`, `libcusinfo.so`, `libsysteminfo.so`, `libcurl.so.4`, `libxml2.so.2`, `libz.so.1`, `libcares.so.2`, `libssl.so.0.9.8`, `libcrypto.so.0.9.8`, `libmsrv_atv_customer.so`, `libmsrv_dvb_customer.so`, `libmsrv_dvbc_customer.so`, `libmsrv_dvbs_customer.so`, `libmsrv_dvbt_customer.so`, `libmsrv_mmbrowser.so`, `libmsrv_autotest.so`, `libmsrv_common_customer.so`, `libmsrv_control.so`, `libmsrv_control_customer.so`, `libdevice_customer.so`, `libmsrv_network.so`, `libutilities.so`, `libdirectfb-1.4.so.0`, `librt.so.1`, `libpthread.so.0`, `libdirect-1.4.so.0`, `libMStarSDK.so`, `libMStarSDK_customer.so`, `libfreetype.so.6`, `libMLog.so`, `libmuf.so`, `libstdc++.so.6`, `libm.so.6`, `libc.so.6`, `libgcc_s.so.1`
- Dynamic import/export: 90 / 97.
- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).
- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).

## Ghidra kapsamı

- Fonksiyon kayıtları: 160; semboller: 844.
- Xref: 2031; analizde call tipli xref: 0.
- Computed-call instruction: 578 (runtime hedefi doğrulanmadı).
- İlk örnek decompile: 6/6.
- Analiz timeout: False.

[Fonksiyonlar](../../../analiz/native/system-modules/60a935b26f0915965ba81fa023dd42bb138a5502428cb2fb3ce707765d6dc1ea/functions.jsonl) · [Xref](../../../analiz/native/system-modules/60a935b26f0915965ba81fa023dd42bb138a5502428cb2fb3ce707765d6dc1ea/xrefs.jsonl) · [Semboller](../../../analiz/native/system-modules/60a935b26f0915965ba81fa023dd42bb138a5502428cb2fb3ce707765d6dc1ea/symbols.jsonl) · [Dolaylı çağrı noktaları](../../../analiz/native/system-modules/60a935b26f0915965ba81fa023dd42bb138a5502428cb2fb3ce707765d6dc1ea/computed-calls.jsonl)

### İlk decompile örnekleri

| Adres | Fonksiyon | Çıktı |
|---|---|---|
| `2f7434c0` | `MSrv_NetworkUpgrade::reset_http_progress_stats` | [C](../../../analiz/native/system-modules/60a935b26f0915965ba81fa023dd42bb138a5502428cb2fb3ce707765d6dc1ea/2f7434c0.c) |
| `2f746158` | `MSrv_Network_Smb::Network_SetScanAvailableIp` | [C](../../../analiz/native/system-modules/60a935b26f0915965ba81fa023dd42bb138a5502428cb2fb3ce707765d6dc1ea/2f746158.c) |
| `2f743490` | `MSrv_NetworkUpgrade::GetThisMessageMap` | [C](../../../analiz/native/system-modules/60a935b26f0915965ba81fa023dd42bb138a5502428cb2fb3ce707765d6dc1ea/2f743490.c) |
| `2f7434a8` | `MSrv_NetworkUpgrade::GetMessageMap` | [C](../../../analiz/native/system-modules/60a935b26f0915965ba81fa023dd42bb138a5502428cb2fb3ce707765d6dc1ea/2f7434a8.c) |
| `2f743598` | `MSrv_NetworkUpgrade::IsHTTPDownloadSucceed` | [C](../../../analiz/native/system-modules/60a935b26f0915965ba81fa023dd42bb138a5502428cb2fb3ce707765d6dc1ea/2f743598.c) |
| `2f7442e4` | `MSrv_NetworkUpgrade::WriteExcludeVersionString` | [C](../../../analiz/native/system-modules/60a935b26f0915965ba81fa023dd42bb138a5502428cb2fb3ce707765d6dc1ea/2f7442e4.c) |

## Giriş/çıkış ve açık işler

Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.
Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.
