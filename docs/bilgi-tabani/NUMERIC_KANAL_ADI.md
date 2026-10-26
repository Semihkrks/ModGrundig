# Sayısal kanal girişinde gerçek kanal adı yolu

26 Ekim güncellemesi: [V7.5'te gerçek helper, metin widget'ı ve event hook'ları kuruldu](../UI_NATIVE_V75_KANAL_ADI.md); aşağıdaki eksikler önceki araştırma durumudur. Yeni kodda baştaki sıfır, route kontrolü ve başarısız sorguda isim temizleme vardır. Fiziksel TV testi henüz yapılmadı.

24 Ekim 2026. Önceki alt ajan araştırmasının adresli devam kaydı. Kaydedilmiş doğrudan Ghidra C ve sınırlanmış MIPS assembly incelemesine dayanır; REA Evidence veya cihaz gözlemi değildir. Yeni helper/event hook kurulmadı.

## Statik çağrı yolu

| Aşama | Adres / bağlantı | Davranış |
|---|---|---|
| Girilen numarayı çözme | `Check_ProgramSelectByNumber0x6371e4`, çağrı `0x6372b0`, GOT `0x10cce20` | Customer `GetProgramSelInfo0x2e16603c` kullanır |
| Numara eşlemesi | `GetProgramSelInfo0x2e16603c` | Favori/filtre gösterim numarası→DB numarası; ATV−1 ve DTV servis türü ayrımı; başarısızlık yolu |
| Adı alma | Manager vtable `+0x4c`, base `GetProgramName0x2d4bf028` | Başarı1 ise string çıktısı; `GetProgramInfo` selector4 |
| Dispatch | `0x2d4bc15c..0x2d4bc214`, tablo `0x2d592fa8`, selector4 hedef `0x2d4bc1c4` | Vtable `+0xec` üzerinden `_GetProgramInfoByNumber0x2d4c0a4c` |
| DB kaydı | `0x2d4c0a4c` | Numara `+4`, servis `+0x13`, string çıktı `+0x18` |

Sanal hedefler statik olarak çözüldü; cihaz nesnesinin runtime vtable değeri gözlenmedi. Decompiler'ın belirsiz prototipi tek başına ABI kanıtı değildir. MIPS o32:

- `GetProgramSelInfo`: a0 manager, a1 typedU16, a2 `&dbNumberU16`, a3 `&serviceU8`, stack+0x10 `&routeU8`.
- `GetProgramName`: a0 manager, a1 DBnumU32, a2 serviceU8, a3 routeU16, stack+0x10 `&std::string`; v0==1 başarı.

Base `GetProgramName` route parametresini kullanmaz. Aktif route ile çözülen route eşleşmeden bu base nesneden ad okumak yanlış sonuç üretebilir. Aktif route `MSrv_Control::GetInstance()` vtable `+0x1b8(this,0)` yolundan alınır. Gelecek köprü route uyuşmazlığını reddetmeli veya route'a uygun manager'ı kanıtlamalıdır.

## Hook adayları ve eksikler

`TenKeyHandle0x89552c` mevcut `SetText(MString&)` çağrıları `0x8957cc/0x895a6c`; öncesindeki yüklemeler `0x8957c8/0x895a68` (`gp−0x1ef8`). A0 frame+0x188 textbox, a1 statik rakam MString `0x10d4d04/0x10d4cf8`. Baştaki sıfırları korumak için mevcut metin kullanılmalı.

`SetMultiline0x2e281b90` ve `MWidget::SetText0x2e250298` tek-font alternatifidir. Ayrı58/26px font için ikinci gerçek widget, ID kaydı ve ömür yönetimi gerekir. `GetWdgInsByID0x2e232338`, app GOT `0x10c6f88` arama yoludur; yeni widget kaydını kanıtlamaz.

Frame alanları boş varsayılmamalı: +0x18c manager getter sonucu, +0x190=1000, +0x194=999, +0x198/+0x19c=1, +0x1a0=4, +0x1a2 typed numara, +0x1a4 digit count ve sonraki alanlar kullanılır. Yeni pointer için kanıtlanmış alan yoktur.

Eksikler: güvenli PIC helper yerleşimi/linking, çağrı dönüş/istisna davranışı, string ömrü/buffer sınırı, widget kaydı, filtre/route dalları ve tam TV testi. Native v6/v7 isimleri örnek veridir; bu DB yolu yürütülmez.

## Kanıt dosyaları

- [Customer numara çözümü](../../analiz/native/system-focused/67b12c70234292c6afeffc489d91ae3101f95c2a4ff7fcc1f726bb4505e6e761/numeric-name-customer-v2/2e16603c.c)
- [GetProgramName](../../analiz/native/system-focused/93fe7286bb7fb9bf3d33ccf75556985f68666fe485241099c20bb7165bc88d97/numeric-name-abi-v1/2d4bf028.c)
- [DB kaydı](../../analiz/native/system-focused/93fe7286bb7fb9bf3d33ccf75556985f68666fe485241099c20bb7165bc88d97/numeric-name-abi-v1/2d4c0a4c.c)
- [Dispatch](../../analiz/native/system-focused/93fe7286bb7fb9bf3d33ccf75556985f68666fe485241099c20bb7165bc88d97/numeric-name-dispatch-bounded-v1/2d4bc15c.json)
- [Mevcut çağıran](../../analiz/native/ui-four/channels/numeric-name-check-v1/006371e4.c)
- [Numeric frame çıktısı](../../analiz/native/ui-four/channels/numeric-name-main-v1/0089722c.c)

[Güncel UI aşaması](../UI_MENU_AYARLAR_V7.md).
