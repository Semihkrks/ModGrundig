# Main DTV ses decoder kimliğinin tahsisi

30 Ekim 2026. Kullanıcı V7.9 HEVC ses testinden sonra TRT Ultra HD'de iki ses
seçiminde de ses gelmediğini, **normal HD kanallara dönünce sesin çalıştığını**
bildirdi. Bu gözlem genel/kalıcı bütün ses tahsislerinin bozulduğu iddiasını
desteklemez. Aşağıdaki başarısızlık koşulları kod bulgusudur; TV'de gerçekleşmiş
TRT hatası sayılmaz. Yeni yama veya paket üretilmedi.

## Başlangıç kimlikleri sabit0/1/2 değildir

`mapi_audio_customer` constructor `0x2dc6ed7c`, main alanı **`this+0x12c=-1`**
(`0x2dc6ee20`) ve secondary **`+0x130=-1`** (`0x2dc6ee10`) atar.
Main status kaydında kaynak `+0x13c=0x1c`, secondary status kaydında
`+0x158=0x25`; ilk DSP alanları `+0x140/+0x15c=0` olur. Bunlar geçerli
decoderID ataması değildir.

Gerçek main tahsisi, `InputSource_ChangeAudioSource(source)=0x2dc6cf38`
üzerinden kaynak değişiminde yapılır:

1. `+0x118==requested_source` ise `0x2dc6cf78` koşulundan erken döner.
2. Vtable `+0x54`, eski `+0x12c` kimliğiyle `CloseAudioDec` çağırır
   (`0x2dc6d028`). Dönüş başarısı test edilmez.
3. Status `+0x134` kaydına processor0 ve istenen kaynak yazılır.
4. Vtable **`+0x50→OpenAudioDec=0x2dc6ae10`** çağrılır (`0x2dc6d04c`).
5. Dönüş V0, **koşulsuz main `+0x12c`** alanına yazılır (`0x2dc6d05c`).
6. Kaynak alanı `+0x118=requested_source` güncellenir (`0x2dc6d06c`).

Dolayısıyla bu katman ID0/1/2 sabiti seçmez; API tahsis çağrısının dönüştürülmüş
sonucunu saklar. Alt `MApi_AUDIO_OpenDecodeSystem` tahsis politikasının sabit bir
ID döndürüp döndürmediği bu kapsamda çözülmedi; canlı main ID halen bilinmiyor.

## Processor ve vtable bağlantıları

| Slot / processor | Çözümlenen yol |
|---|---|
| `+0x50` | `OpenAudioDec=0x2dc6ae10` |
| `+0x54` | `CloseAudioDec=0x2dc6ada4` |
| `+0x58` | Önceki aşamadaki `SetAudioDec=0x2dc6ac08` |
| `+0x6c` | Main kaynak seçimi `0x2dc6cf38` |
| `+0x13c` | Source enum converter `0x2dc62954`; sayısal çıktı bu kapsamda incelenmedi. |

İki argümanlı kaynak seçimi `0x2dc6c98c`, **processor0** için `+0x6c` ile main
yolu çağırır. **Processor1** için status `+0x150`, processor `+0x154` ve kaynak
`+0x158` kullanılır; tahsis dönüşü **`+0x130`** alanına yazılır
(`0x2dc6cca8`). Processor2 yolu legacy DSP işlemini seçer; proc1 tahsisi diye
sunulmaz.

## Open ve Close sözleşmesi

`OpenAudioDec=0x2dc6ae10` null status veya izin verilmeyen kaynakta **-1** döner.
İzin verilen sayısal kaynaklar: **1,0x17,0x18,0x19,0x1a,0x1c,0x1e,0x22,0x25,0x26**.
Örneğin0x27 bu fonksiyonun kabul listesinde yoktur; bu, TRT'nin0x27 kullandığı
veya buranın TRT hatası olduğu anlamına gelmez.

Kabul edilen kaynakta status+0xc DSP enum'u, önceki aşamanın `0x2dc6625c`
mapper'ından; kaynak ise vtable+0x13c mapper'ından geçer. Status+4 değerleri
1/2 ise karşılık1/2, diğer durumda0 konfigürasyonuna dönüşür. Ardından
**`MApi_AUDIO_OpenDecodeSystem`** çağrılır (`0x2dc6af30`), API dönüşü
`0x2dc63550` converter'ından geçirilir ve status+0x18'e de yazılır.
Bu son converter'ın tam sayısal tablosu bu görevde incelenmedi.

`CloseAudioDec=0x2dc6ada4`, -1 veya3 girdisinde0 döner. Diğer girdiler önceki
`0x2dc634d8` mapper'ından sonra `MApi_AUDIO_ReleaseDecodeSystem` çağrısına gider.
Main kaynak değiştirme kodu Close/Open başarısızlığında ayrı bir retry veya
başarısız-kaynak geri alma dalı içermiyor.

## Başarısızlık neden kalabilir, neden TRT teşhisi değildir?

Open sonucu -1 olsa bile main ID ve current-source güncellenir. Sonraki aynı
kaynak çağrısı, ID'nin -1 olup olmadığını kontrol etmeden erken dönebilir.
Bu, **seçilmiş fonksiyonda** allocation başarısızlığının kaynak değişimine kadar
kalabilmesine dair somut koşuldur; başka caller/kurtarma yolları elenmedi.

Önceki DSP switch bulgusu ile birlikte:

- Main ID -1, secondary geçerli ise processor0 DSP switch'i atlanabilir.
- Her iki ID -1 ise legacy DSP switch fallback'i vardır; bu durum otomatik
  sessizlik diye sunulamaz.
- Main ID geçerliyse processor0, saklı ID üzerinden kimlikli SetAudioDec çağırır.

Main DTV source0x1c dalında ayrıca `SwitchAudioDSPSystem(this,0,0)` çağrısı
bulunur; kanal DoStart yolu sonra gerçek ses codec'ini ayarlar. **HEVC/video
codec'ine özel bir tahsis karşılaştırması bu beş gövdede bulunmadı.** Constructor
DSP varsayılanı0 olsa da sonraki kaynak dönüşlerinde `+0x140` yeniden sıfırlanmaz;
önceki DSP değeri tahsis isteğine taşınabilir.

Normal HD sesinin geri geldiği gözlemi nedeniyle, bu kod koşulunu genel kalıcı
tahsis bozukluğu veya TRT'nin gerçek sebebi diye yamak gerekçesizdir. Canlı
`main_ID/secondary_ID`, Open sonucu ve aktif source/processor bilgisi olmadan
ID zorlamak veya tahsis-retry yaması önerilmedi. Diğer ajanın HAL ID→ADEC eşlemesi
ayrı kanıttır; burada legacy MAD getter'ının yanlış decoder okuduğu iddia edilmez.

## Ölçülebilir kapsam

`reverse-engineer-anything` ile **5/5 yeni C çıktısı**, beş orijinal assembly
gövdesi, **18 instruction word**, **5 vtable slotu** ve **4 host mantık örneği**
doğrulandı. Host örnekleri native allocator çalıştırmaz. Main kaynak gövdesinin
geniş geri kalan PQ/çıkış/delay davranışı bu görevin konusu değildir; tahsis ve
ilgili mainDTV bloklarına odaklanıldı. Yeni Ghidra sorgusu mevcut projede
`-noanalysis -readOnly` idi; çıktılar REA Evidence değildir.

[Script](../scripts/audit_hevc_audio_alloc_stage5.py),
[kaynak/gövde hash'leri, instruction/vtable ve koşul kaydı](../analiz/native-4k/audio-stage5-allocation/results.json).
Script ve `py_compile` geçti. Orijinal kütüphane değişmedi; cihaz/donanım veya
çıkarılmış tam TV programı çalıştırılmadı.
