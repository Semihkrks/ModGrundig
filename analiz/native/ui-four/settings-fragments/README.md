# Settings: doğal fazlardan sınırlı C parçaları

23 Ekim 2026. Hedef: `dvbt_board`, SHA-256 `51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916`.

**12/12 sınırlı analiz parçası C üretti.** Bunlar `NewUI_Settings 0x55b6c0–0x579360` için **tam fonksiyon C veya eşdeğer kaynak kod değildir**. Parça sınırlarında açık `RETURN` / `CALL_RETURN` metaveri soyutlamaları vardır. Orijinal koşullu dal instruction'ları ve manifestteki CFG kenarları davranış için esas kayıttır. Kaynak byte'ları değiştirilmedi; firmware programı çalıştırılmadı; Ghidra veritabanı kaydedilmedi.

[Doğrulama](fragment-validation.json) ve [ham çağrı adayları](fragment-raw-call-candidates.json):

- Orijinal doğal aralıklar toplamı: **30.504 instruction / 122.016 bayt**, eksik 0, aralık örtüşmesi 0.
- C toplamı: **617.681 bayt**. Her parçada pcode adreslerinin seçilen analiz gövdesi dışına çıkma sayısı 0.
- Parça başına pcode callsite toplamı 2.747; adapter prefix'leri nedeniyle benzersiz kaynak adresi 2.743. Bunlar whole-function çağrı sayıları değildir.
- Ham indekste 3.071 orijinal callsite vardır; 328'i hiçbir parça pcode listesinde görünmez. Çıktılar ham eksik siteleri açıkça tutar. Ulaşılamayan EH yolları, prototype çıkarımı ve optimizasyonlar nedeniyle pcode listesi bütün ham instruction davranışlarının eşdeğeri sayılmaz.
- `whole_function_C_complete_count` bu yöntem için **0** kalır.

Ayrı whole-function yönteminin güncel durumu [Settings faz manifestinin `whole_C_status` alanındadır](../settings/phase-plan.json). Buradaki 0, yalnız fragment yönteminin whole-function çıktısı üretmediğini belirtir; bağımsız reduced-inference whole-C sonucunu geçersiz saymaz.

| Doğal parça | Orijinal instruction | C bayt | Pcode callsite | Ek sonraki-faz prefix'i |
|---|---:|---:|---:|---:|
| entry_position | 29 | 374 | 1 | 0 |
| autosearch_initial | 5.625 | 100.566 | 478 | 60 bayt |
| manualsearch_initial | 2.018 | 37.906 | 158 | 60 bayt |
| antenna_initial | 469 | 9.322 | 37 | 0 |
| source_initial | 826 | 15.621 | 61 | 0 |
| fti_initial | 1.738 | 33.833 | 151 | 0 |
| root_containers | 398 | 12.153 | 30 | 20 bayt |
| scroll_collection_and_children | 2.181 | 56.085 | 190 | 60 bayt |
| autosearch_results | 8.472 | 171.309 | 806 | 0 |
| manualsearch_results | 8.680 | 176.796 | 828 | 0 |
| normal_cleanup | 26 | 808 | 3 | 0 |
| exception_cleanup | 42 | 2.908 | 4 | 0 |

İlk üç geçerli çıktı [smoke_boundary60](smoke_boundary60/) altındadır. Diğerleri `all_<id>_120/` altındadır. Her dizinde `.c`, `.json`, `fragment-metadata-assumptions.json`, sabitlenmiş `phase-plan.json`, sorgu-script hash'leri ve Ghidra log'u bulunur. Bir parçanın C dosyası bağımsız çalıştırılabilir kaynak veya tam yeniden oluşturulmuş API sözleşmesi değildir.

## Metaveri soyutlamaları ve bağlam

- GP=**0x10cc310**, orijinal MIPS PIC invariant varsayımıdır. Yalnız orijinal giriş parçası `t9=0x55b6c0` alır; ortadan başlayan fazlara yanlış `t9=fragment entry` atanmaz. Orta fazlar `s8` register'ında açık `original_frame_context` parametresi alır. Gerçek stack/nesne içeriği bilinmiyor; manifestteki okuma listeleri bağlamın koruyucu üst kümesidir.
- Giriş/anten/kaynak son çağrıları `0x55b728`, `0x5635e8`, `0x5642d0` analiz parçasının sonu olarak `CALL_RETURN` yapılır. **Son GP restore instruction'ları** `0x55b730`, `0x5635f0`, `0x5642d8` ham doğal instruction kaydında bulunur; parça C'sinde temsil edilmez. Döndürülen C değeri bu sınır soyutlamasının ürünüdür, orijinal fonksiyonun sözleşmesi değildir.
- Son instruction'ı kritik store veya loop koşulu olan dört fazda önceki call'da kesmek yerine sonraki fazın ilk call'una kadarki gerçek byte'lar analiz gövdesine eklenir; o call `CALL_RETURN` yapılır. Böylece son store/loop korunur. Ek **200 bayt prefix** doğal faz sahipliği sayılmaz. `natural_end_exclusive` ile `analysis_end_exclusive` ayrı tutulur; C parçaları birleştirilip eşdeğer whole-function kaynak gibi sunulamaz.
- Doğal faz dışına giden koşullu dallar, inceleme gövdesi dışındaki devamı temsil etmek için `RETURN` olarak soyutlanabilir. Her değişiklik orijinal instruction/target/koşul metniyle ayrı JSON kaydındadır. Bilinmeyen computed jump'lar da açık sınır varsayımı gerektirir.
- **Scroll outer loop korundu:** `scroll_collection_and_style` ve `child_controls_and_scroll_tail`, `0x56643c–0x568650` aralığında birleştirildi. `0x568648→0x5664c8` geri kenarı ve `0x5664c0→0x568608` kenarı parçanın içindedir; bu iki instruction'a sınır override'ı uygulanmadığı doğrulandı. C'de döngü yapıları korunur; bu bulgu bütün veri bağımlılıklarının eşdeğerliği iddiası değildir.
- AutoSearch başlangıcındaki iki MIPS switch dispatch'i `0x55e82c`, `0x55f590`, ham tabloyla doğrulanmış beşer internal case hedefiyle yeniden ilişkilendirildi. Bu iki computed jump, çıkış diye kesilmedi.
- `_Unwind_Resume` / `abort` callsite'ları standart noreturn varsayımıyla işaretlenir. Bu isimler statik GOT/ham-call adaylarıdır; runtime binding gözlenmedi.
- Ghidra'da orta fazlarda GP'nin frame-relative yüklemelerinden sonra C bazı GOT çağrılarını pointer ifadesiyle gösterebilir. MIPS O32 prototype hataları C argümanlarını eksiltebilir; ham çağrı JSON'undaki a0–a3 adayları korunur. Örneğin giriş C'sinin `MoveWindowTo` argüman sayısı orijinal assembly sözleşmesi sayılmaz.
- AutoSearch başlangıcında iki decompiler uyarısı (`ram:000016c8`, `ram:000016c4` okunamadı) oluştu. Uyarılar doğrulama JSON'unda saklıdır; bilinmeyen frame değerleri gerçek runtime adresleri gibi yorumlanmaz.

## Başarısız ilk yöntem

[smoke60](smoke60/) salt `setFallThrough(null)` yönteminin başarısız kaydıdır: giriş timeout oldu; antenna/source için araç C-complete döndürse de pcode sırasıyla **12.367 / 11.867 adresle** doğal aralık dışına taştı. Bu iki C çıktısı diagnostic'tir ve **geçerli parça sayısına katılmaz**. Sonraki metaveri sınır yöntemi aynı kaynak byte'larıyla bu taşmayı giderdi. İlk çıktıların provenance kaydı geriye dönük değiştirilmedi.

## Tekrar üretme

Yardımcılar: `scripts/ghidra/SettingsFragmentExport.java` ve `scripts/run_settings_fragments.sh`. Wrapper, pristine `GrundigBounded` metaverisini yalnız ilk kullanımda ayrı `/home/semih/grundig-analysis/ui-four/settings-fragments/` dizinine kopyalar; programı `-noanalysis -readOnly` ile işler. `SettingsFillListingGaps` yalnız doğrulanmış iki switch-case boşluğunu decode eder. Asıl program ve diğer analiz DB'leri kaydedilmez/değiştirilmez.

```sh
sh scripts/run_settings_fragments.sh --compile
sh -n scripts/run_settings_fragments.sh
sh scripts/run_settings_fragments.sh /absolute/linux/path/logical-plan.json scroll_collection_and_children fresh_run 120
sh scripts/run_settings_fragments.sh --validate
```

Java JDK 21 / Ghidra 12.1.4 derleme, shell syntax, 12 gerçek fragment sorgusu ve bütün kapsam/pcode/hash doğrulamaları geçti. Prefix adapter gerektiren faz tek başına seçilir; aynı çalışma içindeki overlapping function metadata'sı reddedilir. Timeout 1–120 saniyedir; büyük whole-function yeniden denemesi bu yardımcıdan başlatılmaz. [logical-plan.json](logical-plan.json), orijinal 13 fazı 12 mantıksal aralığa indirger; eski kenar etiketleri `phase_aliases` ile açıklanır.
