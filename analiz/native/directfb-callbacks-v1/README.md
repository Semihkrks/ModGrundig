# DirectFB callback recovery

22 Ekim 2026. Başarılı kanıt kümesi **`attempt1/`**; gövde bulguları `findings.json` içindedir. Üst dizindeki ilk `ghidra.log` Java iterator tipi derleme hatası olan başarısız denemedir; başarılı analiz diye kullanılmaz.

`ExportDirectFbCallbacks.java`, sekiz callback'i kendi ELF `.pdr` girişleriyle sınırlar, yalnız `-readOnly -noanalysis` oturumunda disassemble/createFunction uygular ve mevcut `ExportUiSelection.java` ile C/JSON üretir. Her fonksiyonda `.asm`, `-transfers.json` ve ayrıntılı `.json` bulunur. `callback-recovery.json` eksik instruction ve önceki function çakışmalarını kaydeder. `.pdr` sınırları ve her aralığın ham dosya SHA-256 değeri `elf-boundaries.json` içindedir.

8/8 decompile tamamlandı; 0 eksik word, 0 sınır dışı pcode. MIPS PIC `t9=entry` analiz varsayımıdır. Hedefin önce/sonra SHA-256 değeri aynıdır; Ghidra log'u metadata değişikliklerinin atıldığını bildirir. Target çalıştırılmadı, TV bağlantısı kurulmadı, repack yapılmadı. Bunlar doğrudan Ghidra statik çıktılarıdır; REA Evidence kaydı değildir.

Yeni boş çalışma ağacında `wsl -d Ubuntu -- sh tools/query-directfb-callbacks-linux.sh`; bu çıktı mevcutsa `... query-directfb-callbacks-linux.sh fresh-run-name` ile aynı kök altında yeni alt dizin seçilebilir. Sarmalayıcı hedef ELF'i içeri almaz veya kaydetmez; mevcut lane1 analiz veritabanını salt okunur açar.

Yöntem adları bu firmware'in callback gövdelerindeki `_IDirectFBSurface_*` log argümanlarından gelir ve gerçek durum değişiklikleri/çağrılarla desteklenir. Dış DirectFB sürümünden ABI/ad/enum kopyalanmadı. Detailed JSON içindeki `signature`, decompile öncesi yeni function kaydının varsayılanıdır; gerçek argüman yorumu için C ve assembly birlikte kullanılmalıdır.
