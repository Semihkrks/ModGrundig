# Grundig firmware araştırması

- Kullanıcının son önceliği, sağlanan firmware'i çevrimdışı açmak ve bağlantıları anlamaktır. Yeni arayüz/özellik uygulaması ancak sonraki görevle başlar.
- Önce README.md ve docs/TERSINE_MUHENDISLIK.md içindeki kanıt ve kapsam durumunu oku. Devir notundaki eski iddiaları yeni kanıtlarla karıştırma.
- Orijinal ZIP/RAR/BIN dosyalarını değiştirme. Analiz scriptleri scripts/, çıktılar analiz/ altında tutulur.
- Güncelleme scriptlerini, çıkarılan MIPS programlarını, devmem/flash/NAND komutlarını çalıştırma. TV'ye yazma ayrı ve açık kullanıcı yetkisi gerektirir.
- Yerleşik beceri keşfini kullan. Binary/firmware araştırmasında reverse-engineer-anything uygundur; her mesajda bütün becerileri veya setup/doctor komutlarını yükleme.
- Windows REA MCP bağlıdır. Linux araç sarmalayıcısı tools/rea-linux.sh; eski MIPS ELF ABI sınırları için kaydedilmiş REA ret sonucunu dikkate al. Doğrudan Ghidra çıktısını REA Evidence diye sunma.
- Tam Linux dosya ağacı ve Windows okuma görünümü README'de belirtilir. analiz/dosya-sistemleri ilk, kısmi denemedir; tamamlanmış ağaç diye kullanma.
- Sembolik bağlantıları host dosyalarına doğru izleme. Firmware kökü ve mount tablosuna göre anlamlandır. Anahtar, sertifika ve benzersiz cihaz kimliği içeriklerini raporlara/dış servislere taşıma.
- İsim/string eşleşmesi, dosya hash eşleşmesi, statik xref ve cihazda gözlem farklı kanıt düzeyleridir. Bilinmeyen bağlantıları açıkça belirt.
- Bağımsız büyük alt işlerde kullanıcı tarafından istenen alt ajan desteğini kullan; dosya sahipliğini belirt ve başkalarının değişikliklerini geri alma.
