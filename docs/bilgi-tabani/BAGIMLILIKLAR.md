# Bağımlılık ve dinamik bağlama araştırması

Güncel v2 envanterde 7583 eşleşmeyen import beyanı sınıflandırıldı. Bunlar çalışma zamanında eksik sembol hükmü değildir.

| Sınıf | Adet |
|---|---:|
| `nonweak_provider_outside_candidate_closure` | 7005 |
| `weak_no_global_export_candidate` | 529 |
| `weak_provider_outside_candidate_closure` | 49 |

dlopen/dlsym/dlclose/dlerror import eden modül: 11. İki UI instruction indeksinde loader çağrı adayı: 0.

Ana uygulama köklü DT_NEEDED aday birleşimi 114 modül içerir. Bu kapsamdaki önceki eşleşmesiz importlar: `{"no_provider_in_rooted_candidate_union": 325, "provider_in_rooted_candidate_union": 6891}`.
Bu genişletme yalnız statik aday kapsamını değiştirir; runtime arama sırası veya fiilî sağlayıcı seçimi kanıtı değildir.

[Tam kayıt, import indeksleri ve adaylar](../../analiz/cozulemeyen-semboller.json).
[Güncel sembol bağlama adayları](../../analiz/envanter-v2/sembol-baglantilari.json).

Weak import için çağıranın sıfır kontrolü ayrıca incelenmelidir. Closure-dışı sağlayıcılar process-global veya plugin kapsamına ancak loader/callback kaydı ve çağıran bağlamıyla bağlanabilir. Loader import beyanı, belirli bir dosyanın gerçekten yüklendiğini kanıtlamaz. Ghidra sistem taraması external library binding yapılandırmadan yapıldığından onun unresolved external uyarıları bu kayıtlarla karıştırılmaz.

## Öncelikli modüller

| Modül | Eşleşmeyen import |
|---|---:|
| `07_MSLIB/libmsrv_common_customer.so` | 798 |
| `07_MSLIB/libmsrv_dvbs_customer.so` | 610 |
| `07_MSLIB/libmsrv_dvbt.so` | 604 |
| `07_MSLIB/libmsrv_dvbs.so` | 601 |
| `07_MSLIB/libmsrv_dvbc.so` | 598 |
| `07_MSLIB/libmsrv_dvbt_customer.so` | 589 |
| `07_MSLIB/libmsrv_dvbc_customer.so` | 581 |
| `07_MSLIB/libmsrv_dvb.so` | 313 |
| `07_MSLIB/libmsrv_control_customer.so` | 205 |
| `07_MSLIB/libmsrv_control.so` | 199 |
| `07_MSLIB/libvdplayer.so` | 152 |
| `07_MSLIB/libar_cec.so` | 96 |
| `07_MSLIB/utopia/libdrvMVOP.so` | 90 |
| `07_MSLIB/libmsrv_atv.so` | 86 |
| `07_MSLIB/libPQ.so` | 76 |
| `07_MSLIB/libmsrv_dvb_customer.so` | 76 |
| `07_MSLIB/utopia/libapiVDEC.so` | 76 |
| `07_MSLIB/libPQ_cus.so` | 75 |
| `07_MSLIB/libMStarSDK.so` | 63 |
| `07_MSLIB/libmsrv_autotest.so` | 61 |
