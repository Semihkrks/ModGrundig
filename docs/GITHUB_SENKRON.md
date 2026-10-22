# GitHub senkronu

Repo: https://github.com/Semihkrks/ModGrundig

Kök `README.md` herkese açık giriş sayfasıdır. GitHub About açıklaması ve konuları aynı kapsamı söyler: araştırma notları ve REA alt deposu. Lisans MIT’tir.

Araştırma belgeleri, scriptler ve `analiz/` çıktıları main dalındadır. Büyük çağrı indeksi ve `analiz/dosya-sistemleri-tam.tar` Git LFS kullanır. REA sabit commitli alt depodur (`git clone --recurse-submodules` ve `git lfs pull`).

Orijinal devir ZIP’i, devir görselleri, sertifika bölümü (`12_certificate`), PEM ve anahtar dosyaları yalnız yereldedir. `analiz/bolumler/07_MSLIB.bin` de yereldedir: paket içindeki bir C++ tür adı GitHub’ın token filtresine takılır. Açılmış MSLIB dosyaları `analiz/dosya-sistemleri-tam/07_MSLIB/` altındadır. `analiz/dosya-sistemleri/` ilk NTFS denemesidir; özel dosyalar yüzünden indekslenmez. Okunabilir ağaç `analiz/dosya-sistemleri-tam/`, symlink arşivi `analiz/dosya-sistemleri-tam.tar` altındadır. Araç kurulumları da yerel bağımlılıktır. Bu dosyalar silinmedi.

Kullanıcının tercihi: bundan sonraki yetkili proje çalışmaları tamamlandıkça hassas veri kontrolü, commit ve push ile senkron ilerle. Gözetimsiz otomatik görev kurulmadı.
