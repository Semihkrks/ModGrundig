# Ghidra adresleri ve loader sınırları

Ham ELF adresi ile Ghidra adresi, image-base farkı kontrol edilmeden karşılaştırılmaz. ET_REL nesnelerinde bölüm kimliği gerekir; tek VA üretilmez.

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
