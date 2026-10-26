# V5 Image_res ekleme: native ayrıştırıcı kanıtı

24 Ekim 2026. Sonuç: **2179 numaralı ek kayıt statik native format ve lookup kontrolleriyle uyumlu.** `Clrkey_res.bin` eklemesi gerekmiyor. Ayrıntılı bayt/assembly kaydı [resource-append-evidence.json](resource-append-evidence.json) içinde.

Bu incelemede `reverse-engineer-anything` rehberi kullanıldı. Önceden saklanmış doğrudan Ghidra pseudocode çıktıları ve SHA ile sabitlenen libmuf.so üzerinde Capstone 5.0.6 statik çözümleme kullanıldı. Bunlar REA Evidence veya cihaz gözlemi değildir. `LoadResource` adıyla ayrı native sembol bulunmadı; gerçek kaynak yükleme zinciri aşağıdaki `Prepare`/`BuildData` fonksiyonlarıdır.

## Başlık ve indeks

- Özgün Image_res SHA-256: `d6b1b9fde60c9cc4624f264a8e75da4245e6fb3e9dab7534ddce01706fbcd2f3`, 129.475 bayt, 2.179 kayıt.
- `Prepare=0x2e240cf4`, [saklanmış C:31](../native/libmuf/2e240cf4.c#L31), 56 bayt okur; `_tsm` (`0x6d73745f`) magic ve başlık+8 türünü doğrular. Image türü 5'tir.
- `BuildData=0x2e240ea4` stack üzerinde header tabanını `sp+0x18` olarak hazırlar. `0x2e240f00/04`, başlık+4 toplam boyutu ve başlık+20 veri başlangıcını okur; fark payload boyutudur. `0x2e240f78`, başlık+28 kayıt sayısını okur. Payload ve sayı `<0x1000000` kontrollerinden geçer. Eski [C:24](../native/libmuf/2e240ea4.c#L24) bu farkı gösterir; switch ve t9 belirsizliği ham ELF ile ayrıca çözüldü.
- Ham ELF switch çözümü: `gp=0x2e2bb8e0`, rodata GOT değeri `0x2e291480`, tablo `0x2e28c630`, tür 5 hedefi `0x2e24110c`. Burada `payload -> this+0x44`, `count -> this+0x14`, `payload_length -> this+0x64` atanır. GOT `gp-0x72c4` hedefi `BuildImgPathIndex=0x2e24069c` olup çağrılır. Tam assembly JSON'a alındı.
- [BuildImgPathIndex:9](../native/ui-deep/muf-core35/2e24069c.c#L9), `count*4` indeks belleği ayırır. [BuildIndex:17–27](../native/ui-deep/muf-core35/2e240534.c#L17), uzunluğu uint32 olarak okuyup `offset += 4 + length` ilerler; dolu kaydın indeksi `offset+4` olur. Dosya içinde ayrı, önceden yazılmış indeks tablosu beklemez.
- Başlık+16 bu incelenen `Prepare`/`BuildData`/indeks yolunda tüketilmez. Değerin 8.716'dan 8.720'ye güncellenmesi özgün `count*4` başlık eşitliğini korur; bunu native parser'ın doğrudan okuduğu bir alan diye sunmuyoruz.

V5 eklemesi, toplam boyut+4, indeks baytları+16 ve kayıt sayısı+28 alanlarını günceller. İlk 2.179 kayıt ve onların üretilen indeksleri bayt olarak korunmuştur. Sonuna 49 baytlık `uint32(45) + ../rc/ARimages/Grundig/modern/numeric_bg.png + NUL` eklenir. Aday 129.524 bayttır; SHA-256 `4c7936af201a77418d00e333fe548c32f198785821b8aa9884d40ea3e47ed87b`. Diskteki v5 Image_res aynı baytlara sahiptir.

[GetImgPath:10–12](../native/ui-deep/muf-core35/2e24097c.c#L10), ID'nin `0xffff` altında olmasını; [GetSTR:12–17](../native/ui-deep/muf-core35/2e2408a0.c#L12), ID'nin kayıt sayısından ve indeksin payload uzunluğundan küçük olmasını ister. Yeni ID `2179 < 2180`; indeks `129423 < 129468`. Yolun son NUL'u ve tam EOF bitişi de doğrulandı. Bu kontroller yalnız NUL/son kayıt doğrulayan Python parse sonucu değildir: gerçek native indeks üretimi ve lookup sınırlarıyla eşleştirilmiştir.

## Clrkey davranışı

[RcGetImage:15–16](../native/ui-deep/muf-core35/2e271658.c#L15) aynı ID için `GetImgPath` ve `GetColorKey` çağırır. [GetColorKey:11](../native/ui-deep/muf-core35/2e240464.c#L11), `GetU32`'ye `this+0x48` renk anahtarı verisini, `this+0x18` sayısını ve `0xffffffff` varsayılanını verir. [GetU32:11–14](../native/ui-deep/muf-core35/2e2403a4.c#L11), yalnız veri varsa ve `id<count` ise tabloyu okur; aksi halde varsayılan döner. Özgün Grundig Clrkey sayısı 2.179 olduğundan ID 2.179 için tablo dışı okuma yapılmaz ve sonuç `0xffffffff` olur. Bu nedenle Clrkey tablosunu uzatmak gerekmez.

## Doğrulanan kapsam

Dosya hashleri, header alanları, 2.179 eski kaydın korunması, yeni kaydın sınırları, native switch hedefi ve Clrkey varsayılanı doğrulandı. Kaynak yükleyicisi çalıştırılmadı; TV/DirectFB kabulü bu incelemeyle kanıtlanmaz. Diğer marka profilleri bu eklemenin kapsamı dışındadır. Orijinal firmware ve tablolara yazılmadı; cihaz, güncelleme scripti, firmware prosesi veya flash komutu çalıştırılmadı.
