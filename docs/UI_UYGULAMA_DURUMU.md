> **Tarihsel aşama kaydı. Güncel uygulama: [TV simülatörü ve firmware sınırları](UI_TV_SIMULATORU.md). Aşağıdaki dört kart, 320px panel ve eski test kapsamı güncel önizlemeyi tanımlamaz.**

# Soft UI: ilk uygulama ve doğrulama

**Son düzeltme — 23 Ekim:** Kullanıcı uzun kapsülü tercih etti; önizlemede ses yüksekliği yeniden **420px**, bar **200px**, sayı **36px** oldu. Kısaltılmış 320px artık güncel hedef değildir. Menü adları doğrudan Türkçe `Str_res.bin` tablosundan alınır: Görüntü Ayarları `0xea3`, Ses Ayarları `0xf9d`, Kaynak Ayarları `0xffb`, TV Ayarları `0x8d`. [Ortak profil](../analiz/ui-modernizasyon/shared-resource-profile.json), önizlemedeki 12 PNG'nin native adaylarla SHA eşliğini kaydeder. Bu, renderer/piksel eşdeğerliği kanıtı değildir. Native hook hazır olmadığı için tarayıcıya özgü ses yumuşatma ve menü fade/slide kapatıldı. [Kanal çalışması ve açık işler](UI_KANAL_AKISLARI.md). Aşağıdaki 320px ve animasyon satırları ilk uygulama aşamasının tarihsel kaydıdır; güncel durum bu paragraftır.

23 Ekim 2026. Dal: `codex/ui-soft-preview`. Kullanıcının son kapsam düzeltmesi uygulanmıştır: TV'de bulunmayan Ağ, Web, uygulama mağazası veya yeni uygulama ekranı eklenmez. Önizleme yalnız Görüntü, Ses, Kaynaklar ve Genel içerir. [Özellik politikası](../ui-assets/feature-policy.json).

Devir kaydı cihazı **Dortmund 40 CLE 5745 AN**, görünen sürümü **GMGRMR V03.017.04** olarak tanımlar. Bu bilgi yeniden kullanıcıdan istenmez. Aynı devir kaydı sağlanan arşivin A32L 5745 4B ile ilişkilendirildiğini ve fiziksel ürün uyumunun doğrulanmadığını söyler. Model kaydı ile dosya analizinin hedef cihazda test edilmesi ayrı kanıtlardır. Paket kaynak olarak kullanılmış; orijinal BIN/ELF/PNG/Num/Color dosyaları değiştirilmemiştir.

## Gerçekleştirilen değişiklikler

| Parça | Uygulama | Doğrulama sınırı |
|---|---|---|
| Etkileşimli önizleme | [Vanilla JS/HTML/CSS](../ui-preview/index.html), bağımlılıksız yerel sunucu; beyaz kapsül ve mavi odak korundu | Tarayıcıda çalışan model; TV render motoru değildir |
| Daha kısa yerleşim | Menü 504→444 mantıksal px (%11,9); kapsül 420→320 (%23,8); yeni ikonlar, 150 ms ses hedefleme, kısa açılış/kapanış | Bu ölçüler önizlemede uygulanmıştır; native geometri henüz uygulanmadı |
| Native kaynak adayları | [19 değişen PNG](../ui-assets/manifest.json): 6 mevcut ağsız Home ikon çiftine ek 4 ses ve 3 ARC görseli | Gerçek dosya yolu/ID/PNG biçimi eşleşir; yükleme veya TV testi yok |
| Native animasyon çekirdeği | [Heap/float kullanmayan C99](../native-ui/motion.c); sürekli konumdan son hedefe yeniden yönelir, tuş kuyruğu biriktirmez | x86_64 host üzerinde derlendi/test edildi; MIPS/MUF'a bağlanmadı |
| Cihazın bulunmayan özellikleri | Ağ kartı, APP/WEB sekmeleri ve Wi-Fi adayları çıkarıldı | Paylaşılan firmware kataloğu cihaz özelliği sayılmadı |

Orijinal firmware Home kurulumunda yedi settings widget'ı vardır. Yeni native ikon adayları yalnız mevcut kaynakları yeniden çizer; orijinal widget/event listesini silmez veya görünmeyen özelliği etkinleştirmez. Kilit/zamanlama kaynakları eski kodda vardır; aday çizimleri, bu ekranların fiziksel cihazda görünür olduğunun kanıtı değildir. Önizlemedeki dört kategori native ağacın dört karta dönüştürüldüğü anlamına gelmez.

Native dosyalardaki boyut, PNG renk türü, bit derinliği ve alpha yeteneği korunmuştur. Kaynakların tahmini toplam decoded RGBA boyutu **2.154.764 bayt** olarak aynı kalır; bu, gerçek TV bellek kullanımı ölçümü değildir. PNG toplam boyutu 292.898→54.412 bayt; küçük dosya boyutu daha yüksek FPS kanıtı değildir. Global Color `0x25` ve font Num `0x3215` değiştirilmedi. Arka plan için canlı blur eklenmedi.

## Gerçek etkileşim testleri

- [State testleri](../ui-preview/tests/state.test.mjs): sınırlar 0/100, 1.000 hızlı zıt ses tuşu, mute, 3.000 ms kapanış, bütün ARC/CEC/HDMI kapıları, CEC reddinde yerel sesin korunması, menü/OK/Geri, desteklenmeyen kategorilere erişim engeli ve animasyon sürekliliği. ARC yorumu sonraki [native v2 kanıtıyla](UI_NATIVE_ADAY_V2.md) düzeltildi.
- [Gerçek Chromium testleri](../analiz/ui-modernizasyon/browser-tests.json): yön tuşları/OK/Geri, aç/kapa, mute ikonu ve kapanış sonrası mute işareti, ARC simülasyonunda yerel sesin korunması, bilinmeyen ARC seviyesinin uydurulmaması, 100 hızlı zıt tuş, reduced-motion, 1920/1280/390 genişlikleri. Sayfa JS hatası yok.
- [Native C host testleri](../native-ui/test-result.json): **42.897 kontrol**, strict C99 GCC ve ayrıca ASan+UBSan. Fiziksel ses/CEC komutu gönderilmez.
- [Native PNG doğrulaması](../ui-assets/validation.json): 19/19 decode, boyut/biçim/alpha eşliği, bütün PNG chunk CRC'leri ve özgün dosya hash'leri doğrulandı.

[İyileştirilmiş önizleme](../analiz/ui-modernizasyon/after-desktop.png) · [Önceki konsept ölçüleri](../analiz/ui-modernizasyon/before-concept-desktop.png) · [Mute](../analiz/ui-modernizasyon/mute-desktop.png) · [ARC](../analiz/ui-modernizasyon/arc-desktop.png). “Önce” görüntüsü eski konseptin ölçülerinin yeniden kurulmasıdır; orijinal TV'den alınmış ekran görüntüsü değildir. Arka plan dekoratif SVG'dir, TV yakalaması değildir.

## Native entegrasyonda kalan somut işler

1. **Geometri ve çizim:** `VolumeControlFrame::OnCreate 0xfb9780` / `RefreshVolumeUI 0xfb7d18` Num sözleşmesine birlikte uygulanmalı. `0x5a3e=420`, track `0x5a6a=200`, y `0x5a6d=88`; ellipse `h+y−floor(h*volume/100)−10`. 320px adayındaki ikon ölçeklemesi/kırpılması ve kenar alpha/colorkey davranışı doğrulanmalı. [Geometri adayı](../ui-assets/geometry-proposal.json) henüz Num tablosuna yazılmadı. OEM arka plan **69×620 opak P4**; aynı biçimdeki PNG tek başına şeffaf dış köşe oluşturamaz.
2. **Menü yerleşimi:** `HomePageFrame 0xd42150` dış H için Num `0x3473=504`; `LayoutItems 0xd29500` sonraki yerleşimi değiştirebilir. Tek yüksekliği küçültüp alt widget'ları kırpmak yerine tam ağacın layout sözleşmesi korunmalı.
3. **Animasyon bağlantısı:** C çekirdeği mevcut event yaşam döngüsüne bağlanmalı. MUF timer nominal **50 ms**, `SetDuration` 50 ms katına aşağı yuvarlanır; `GetAnimationEnabled 0x555ed4` sabit 0. Global gate açılmadı. Browser rAF ile native 20 Hz tick aynı performans değildir. `keyCount/isAnimationDone` kapısı ve event `0x16` tamamlanması korunmadan native akıcılık iddia edilmez.
4. **Ses davranışı:** `VolumeControlFrame::OnKey 0xfb8c7c` ARC/CEC/HDMI kapıları korunur. Sonraki assembly incelemesi, CEC reddinin de yerel sese düşmeden çıktığını gösterdi (`0xfb91ac..0xfb91d4`); önceki yerel dönüş yorumu yanlıştı ve host model/testleri düzeltildi. Native v2 yalnız normal koldaki sıfır ikon seçimini değiştirir; gerçek ARC yolu korunur. Hotel/headphone, DMP, bekleme/açılış ve yönlendirme koşulları native testte ayrıca kontrol edilmeli.
5. **Derleme/dağıtım ve cihaz kabulü:** MIPS SDK/cross-compiler, MUF header/link sözleşmesi ve güvenli yükleme/kurtarma yolu doğrulanmadı. İmzalı/CRC'li kurulabilir paket üretilmedi. Fiziksel kumanda, mute/ARC, gerçek görüntü ölçeği, tekrarlı tuşlar ve render performansı cihazda sınanmadan **“TV'de eksiksiz çalışıyor” denmez**.

Kanıt temeli: [UI bağlantıları](UI_HARITASI.md), [MUF timer/çizim](UI_KOD_YAPISI.md), [Home widget haritası](bilgi-tabani/UI_HOME_COZUM.md), [native aday üretimi](../ui-assets/README.md). REA becerisiyle önceki doğrudan Ghidra/statik bulguları kullanıldı; bu yeni host testleri REA Evidence değildir. Etki kontrolü için `ecc:change-impact`, görünüm için `frontend-design` uygulandı.

## Tekrar çalıştırma

```powershell
node ui-preview/server.mjs
# http://127.0.0.1:4173 — yalnız yerel bilgisayar
node --test ui-preview/tests/state.test.mjs
node ui-preview/tests/browser.mjs
python scripts/test_soft_ui_assets.py
```

Native C ve kaynak üretme komutları kendi README dosyalarındadır. `ui-assets/candidate/` kurulabilir firmware değildir. Önizleme bilgisayarın sesini, ağa bağlı cihazları veya TV'yi kontrol etmez. Dalı değiştirmek/dosyaları kullanmamak tüm bu değişiklikleri geri alınabilir tutar; hedef dosyalara kopyalama yapılmadı.

