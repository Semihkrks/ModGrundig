# Ghidra adresleri ve loader sınırları

Ham ELF adresi ile Ghidra adresi, image-base farkı kontrol edilmeden karşılaştırılmaz. ET_REL nesnelerinde bölüm kimliği gerekir; tek VA üretilmez.

## 23 Ekim: C, C-only ve diagnostic çıktılar

Decompiler'ın bir native isteği tamamlaması, C dosyası üretmesi veya prototipleri doğru çözmesi ayrı ölçümlerdir. Settings `firstpass90` tam aralıktaki ham pcode isteğini tamamladı; **C istenmedi ve üretilmedi**. Bu başarı standart C sayısına katılmaz. `normalize` da tip kurtarma/final sadeleştirmeyi değiştiren ayrı tanısal yöntemdir. Ayrım [Ghidra 12.1.4 DecompInterface dokümantasyonuna](https://github.com/NationalSecurityAgency/ghidra/blob/Ghidra_12.1.4_build/Ghidra/Features/Decompiler/src/main/java/ghidra/app/decompiler/DecompInterface.java) dayanır.

Syntax-tree kapalı C-only modunda boş/prototip HighFunction nesnesi yine dönebilir. `getHighFunction()!=null` veya boş outside-body listesi pcode doğrulaması değildir. Exporter bu durumda `pcode_export_complete=false`, `decompiler_pcode_within_selected_body=null` yazar. Küçük GetID denemesiyle gerçek C çıktısı ve bu unavailable/null davranışı kontrol edildi. İlk probe'daki yanıltıcı true alanı kaynak kaydı olarak tutuldu; v2 düzeltmesi esas alınır.

Settings için ayrıca predication/split seçenekleri ve açık analysis-group kontrolleri denenir. Grup seçenekleri [sürüme sabitlenmiş DecompileOptions encoding API'si](https://github.com/NationalSecurityAgency/ghidra/blob/Ghidra_12.1.4_build/Ghidra/Features/Decompiler/src/main/java/ghidra/app/decompiler/DecompileOptions.java) üzerinden native seçenek akışına eklenir. Çıkarım grubu kapatılan C'de parametre/tür kurtarma daha sınırlı olabilir; bu seçenekler raporda saklanır ve C/assembly kontrolünün yerini tutmaz. Bunlar analiz işlemleridir; firmware byte'larını değiştirmez.

Settings'in doğal blokları üzerinde üretilen fragment C'leri ayrıca soyutlamadır. Kesilen gerçek CFG kenarları, eklenen tail-return metadata'sı ve atlanan GP-restore gibi instruction'lar ayrı tutulur. Fragment C veya tam raw listing, standart bütün-fonksiyon C başarısı diye sayılmaz.

```json
{
  "artifacts": 222,
  "address_normalized_artifacts": 213,
  "declared_FUNC_entries_compared": 61961,
  "declared_FUNC_entries_missing": 0,
  "rebased_artifacts": 83,
  "section_relative_artifacts": 9
}
```

| Durum | Relocation tipi | Adet |
|---|---|---:|
| PARTIAL | `5` | 10242 |
| UNSUPPORTED | `R_MIPS_GLOB_DAT` | 2454 |
| FAILURE | `R_MIPS_REL32` | 342 |
| UNSUPPORTED | `R_MIPS_COPY` | 29 |
| UNSUPPORTED | `R_MIPS_TLS_TPREL32` | 12 |
| UNSUPPORTED | `R_MIPS_TLS_DTPMOD32` | 4 |
| UNSUPPORTED | `R_MIPS_TLS_DTPREL32` | 1 |

[Tüm adres normalizasyonları, eksik declared girişler ve relocation kayıtları](../../analiz/loader-durum.json).
[Bağımsız çıktı/bütünlük denetimi](../../analiz/sistem-taramasi-dogrulama.json).

Bu durumlar TV loader hatası diye sunulmaz. Ghidra programları external library binding yapılandırmadan açıldı. Dolaylı hedefler ve data pointer değerleri, relocation durumu kontrol edilmeden kesin sayılmaz. Decompile örneklerinin tamamlanması, prototype veya çalışma zamanı etkisinin doğru anlaşıldığı anlamına gelmez.
