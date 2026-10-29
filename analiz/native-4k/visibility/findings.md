# Tarama sonrası görünürlük ve LCN — ikinci aşama

27 Ekim 2026. İki özgün modülde **12 yeni Ghidra C çıktısı** ve **3 ek tam assembly gövdesi** tutuldu. Assembly gövdelerinden `_UpdateProgInfoByServiceType` önceki aşamada decompile edilmişti; yalnız diğer ikisi yeni fonksiyondur. Dolayısıyla bu aşama **14 yeni farklı fonksiyon** kapsar. Önceki aşamanın `_CheckService` gövdesi de test için yeniden kullanıldı ve yeni fonksiyon sayılmadı. [13 sınırlı metadata testi](lcn-evidence.json) geçti. Tam TV programı, güncelleyici veya donanım kodu çalıştırılmadı; kaynak ELF'ler değiştirilmedi. Doğrudan Ghidra/Capstone/Unicorn sonuçları REA Evidence veya cihaz testi değildir. [Makine kaydı](results.json).

## Kanal listesi, codec değerine göre filtrelemiyor

- `_AddCommonProgramInfo`, `libmsrv_dvb.so:0x2d53eda4`: geçici programın `+0x1c` alanını DB `+0x32/+0x34` alanlarına, video türünü `MW+0x14 → DB+0x19`, sınıfı `MW+0xe → DB+0x1d` olarak kopyalar. Görünürlük `MW+3/+4 → DB+0x10/+0xf` aktarılır. [C](dvb/2d53eda4.c).
- `GetByLcn`, `0x2d50c488`: DB `+0x34` değerini istenen numarayla karşılaştırır. Böylece önceki aşamada adı belirsiz bırakılan **MW+0x1c alanının LCN olduğu** iki gövde üzerinden doğrulandı. [C](small-dvb/2d50c488.c).
- `_IsProgramListable`, `0x2d50280c`: `DB[0x15]!=1 && DB[0x11]!=1 && DB[0xf]==1 && DB[0x10]==1` ister. Codec `+0x19`, çözünürlük veya raw servis0x1f okunmaz. Bayrakların bütün kullanıcı/operatör anlamları henüz çözümlenmedi; sayıların kendisi kanıttır. [C](small-dvb/2d50280c.c), [assembly](small-gates-assembly.json).
- `_GetNextProgramInfo`, `0x2d507238`: sanal `+0x9c` listelenebilirlik ve `+0xb8` tür filtrelerini çağırır. Müşteri vtable adres noktası `0x2e1e10f0` relocation'larında `+0x9c → base_IsProgramListable`, `+0xb8 → Customer_IsMatchedProgramTypeByFilterLoopType` çözülür. Temel/müşteri sınıfları için dört relocation kaydı tutuldu; bu iki çağrı hedefidir, canlı nesne izi değildir. [C](dvb/2d507238.c), [bağlantılar](list-vtable-bindings.json).
- Müşteri tür filtresi, `0x2e172f44`: query2/3/5 için DB sınıf1/2/3, query6/7 için DB `+0x14` şifreli durumuna bakar; query0xc ayrı sanal `+0xd0` çağrısıdır. Codec okunmaz. Ghidra parametre adı/sırası kusurlu görünse de ham A1 kayıt adresi/A2 query kullanımı [assembly](small-gates-assembly.json) ile kontrol edilmiştir. [C](small-customer/2e172f44.c).
- Müşteri `GetProgramInfoByIndex`, `0x2e1778dc`: indeksi ve DB kaydının `+0x11/+0xf` bayraklarını kontrol eder; codec'e özgü görünürlük filtresi yoktur. `_CheckFilterListProgram`, `0x2e1651bc`, favori/route eşleştirmesidir. [C](customer/2e1778dc.c), [favori gövdesi](customer/2e1651bc.c).
- `SaveProgram`, `0x2d50eda8`: kayıt serileştirme `GetSaveData` sonucu ve sanal yazma `+0x144` dönüşüyle başarı/başarısızlık verir. Bu gövdede HEVC kıyası bulunmadı; serileştiricinin ve fiziksel yazma arka ucunun bütün alt yolları bu incelemenin kapsamı değildir. [C](dvb/2d50eda8.c).

## LCN0 ret koşulu var; HEVC'ye özgü olduğu kanıtlanmadı

Önceki aşamanın müşteri `_CheckService`, `0x2e191888`, gerçek bir LCN kapısı içerir:

1. İç servis tür7 reddedilir; TV1 bu ilk kapıyı geçer.
2. `this+0xd2d6c` operatör alanı4 veya7 **ve `this+0x170` mode1** ise LCN sırasıyla `<1024` / `<1000` olmalıdır. Uydu parser mode2 bu sınırlama dalına girmez.
3. LCN0 genel olarak reddedilir. İstisnalar: `this+0x168==8 && mode==2 && this+0x1d8==12`, veya `this+0x168==12 && mode==0`. Bunlar ham kod değerleridir; ülke/operatör adları uydurulmadı.
4. Video PID0x1fff ve geçerli ses PID'si bazı koşullarda TV'yi radyoya çevirir. Gerçek yayın PMT'si olmadığı için bu koşulun cihazda oluştuğu söylenemez.

[Önceki C](../tuner/customer/2e191888.c); sekiz yeni CheckService sınır/istisna vakası [13 testlik kayıtta](lcn-evidence.json). Testler tam bu528 baytlık metadata gövdesini, sanal çağrıya girmeyen TV sınıfıyla çalıştırır; eksik çağrılar başarı diye taklit edilmez.

**Ancak “LCN bulunmazsa0 olur, bu yüzden bütün4K kanallar elenir” varsayımı desteklenmiyor:**

- Base `_ResetServiceInfo`, `0x2d53d010`, `0x2d53d028` komutunda `MW+0x1c=0xffff` yazar; aynı gövdede görünürlük `+3/+4=1` olur. Bu120 baytlık yan etkisiz gövde sınırlı testte doğrulandı. [Assembly](base-0x2d53d010.asm.txt).
- Customer reset `0x2e19c210`, GOT yüklemesi `0x2e19c22c` / çağrı `0x2e19c230` ile base reset'e gider; dönüşte yalnız `+0x16c/+0x167/+0x16a` alanlarını sıfırlar. LCN'i0 yapmaz. [Assembly](customer-0x2e19c210.asm.txt), [GOT kanıtı](lcn-evidence.json).
- `_GetNitLCN`, `0x2e191b98`: etkinse en fazla120 servis-ID kaydını arar, eşleşmede NIT LCN ve görünürlük alanlarını kopyalar. Eşleşmeyince program LCN alanını değiştirmez; örnek reset değeri0xffff kalır. Eşleşen LCN gerçekten0 ise bazı konfigürasyonlarda NIT görünürlük alanlarını da sıfırlar. Servis0x1f veya video5 karşılaştırması yoktur. Dört ayrı disabled/missing/valid/zero vakası geçti. [C](lcn-customer/2e191b98.c).
- `_GetBatLCN`, `0x2e191c48`: yine servis-ID eşleştirmesi üzerinden BAT LCN/flag kopyalar. Mode ve operatör koşulları BAT üyeliği ve dönüş değerini etkiler; HEVC video türünü okumaz. [C](lcn-customer/2e191c48.c).
- `_UpdateProgInfoByServiceType`, `0x2d53db70`, LCN'e yazmaz. İç sınıf7'de görünürlük alanlarını temizler; raw tür0x0c/0x10 için sanal specific-support kapısı vardır. Raw0x1f, zaten TV1 sınıflanmışsa bu gövdede görünürlük kaybetmez. [Assembly](base-0x2d53db70.asm.txt).

Bu sonuç başlangıç değerini ve ilgili kopyalama gövdelerini kanıtlar. Bütün tarama sırasının tek gerçek cihaz izi, bütün LCN yazıcılarının eksiksiz envanteri veya canlı TRT4K LCN'i değildir. Çalışan uydu yolunda bu fonksiyonların çağrı sırası ve kullanılan operatör seçimi ayrıca doğrulanmalıdır.

## Kalan somut araştırma

- Gerçek manuel RF aramasında demod kilidi/SDT/PMT ve bulunan servis sonucu: yalnız otomatik arama denendi, yayın verisi alınmadı.
- TKGS/operatör/bouquet LCN dallarının cihazdaki etkin seçimi ve kanal ekleme öncesi son değerler.
- `query0xc` sanal filtre hedefi, alttaki DB provider/serileştirme/yazma ve favori route nesnesinin canlı tipi. Bu dolaylı alanlar HEVC ret kapısı diye ilan edilmedi.
- Eksik RF tablosunun mevcut geçerli cihaz DB'sine güvenli artımlı taşınması; fabrika reseti veya DB silme yapılmadı.
- Kanal keşfedildikten sonra gerçek UHD50/Main10 çözme ve1080p ölçekleme ölçümü. Liste filtresinden geçmek decoder başarısı değildir.

Bu aşamada uygulanabilecek kanıtlanmış HEVC'ye özgü ret yaması çıkarılmadı; orijinal dosyalara veya çalışan V7.7 paketine yama uygulanmadı.
