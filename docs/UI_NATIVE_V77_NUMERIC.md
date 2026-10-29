# V7.7 native kanal girişi — mavi sayaç kaldırıldı

Kullanıcının son isteği doğrultusunda V7.6'daki mavi sayaç, ID4 çizgi widget'ı, özel süre alanları ve ID2 kozmetik timer'ı tamamen kaldırıldı. V7.5'teki532 baytlık CREATE helper'ı birebir korunur: yalnız0x250 baytlık standart TextBox ID3 oluşturur. V7.6'nın872 baytlık UPDATE helper'ı gerçek kanal adı ve **Kayıtlı kanal yok** metni için korunur. Başarısız kanal numarası eşleşmesi ile kanal yöneticisi/route/ad servisi hataları ayrı tutulur; servis hatasında eski ad temizlenir.

Sayısal giriş tarafında yalnız6 isim hook sözcüğü vardır. Orijinal3000/2000ms SetTimer çağrıları, OnTimer girişi ve tuning davranışı değiştirilmez. Kanal girişi yardımcıları ek timer çağırmaz, extended allocation/state veya başka child oluşturmaz. UTF-8 fallback, native std::string assignment ve geçici MString ömür yönetimi V7.6 ile aynıdır. Fiziksel TV testi henüz yapılmadı.

**7/7 native isim testi** ve **5/5 ELF/CFI testi** geçti. Testler GP/caller-saved zehirleme, baştaki sıfırlar, Türkçe/uzun kanal adları, eşleşmeyen numara metni, stale label temizleme, tahsis null yolu ve hızlı tekrar girişini kapsar. Ek test CREATE'in V7.5 ile byte byte aynı olduğunu, yalnız ID3 bulunduğunu, tahsisin0x250 kaldığını ve eski sayaç hook'larının bulunmadığını denetler.

Yeni V7.7 ELF yerleştiricisi2 isim yardımcısını ve bağımsız sessiz gösterge düzeltmesi için isteğe bağlı0x1161000/0x1161400 yardımcılarını kabul eder. Her helper için tam FDE gerekir; çakışma, eksik FDE ve64KiB sınır aşımı reddedilir.2 yardımcıda6741 orijinal kayıt korunup6743 olur;3 yardımcı birleşimi sentetik leaf ile6744 olarak ayrıca sınanmıştır. Gerçek sessiz yardımcısının davranış ve birleşim sonuçları ana V7.7 kaydındadır. ELF testi orijinal kanal SetTimer/OnTimer sözcüklerinin değişmediğini ayrıca doğrular.

- [Kanal yardımcıları](../scripts/native_ui_v77_name.py)
- [Native test ve gerçek callback sınırları](../scripts/test_native_ui_v77_name.py)
- [Yeni ELF yerleştirici](../scripts/native_ui_v77_elf.py)
- [ELF testleri](../scripts/test_native_ui_v77_elf.py)
- [Native kanıtlar](../analiz/native-ui-v77/native-name/bounded-tests.json)
- [Byte ve kapsam kaydı](../analiz/native-ui-v77/native-name/helper-proof.json)
- [ELF yerleşim kaydı](../analiz/native-ui-v77/native-name/elf-placement.json)

Bu kontroller sınırlanmış talimat emülasyonu ve statik dosya incelemesidir; fiziksel cihaz başarısı veya tam firmware emülasyonu değildir. Normal yollarda string temizliği vardır; native allocation exception için LSDA cleanup eklenmemiştir. Orijinal firmware, V7.5 ve V7.6 adayları korunur. Beceri: `reverse-engineer-anything`.
