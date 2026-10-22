# Araç kurulumu ve çalışma kayıtları

Tarih: 21 Ekim 2026. Kullanıcının REA'yı global kurma, tam depoyu bu klasöre indirme ve alt ajanlarla araştırma talebi kapsamında yapıldı.

## Windows / Codex

- Global CLI: `rea-agents@6.7.0`, npm ile kuruldu; `rea.cmd --help` çalıştı.
- Codex MCP: `C:/Users/Semih/.codex/config.toml`, yalnız `rea` kaydı eklendi.
- Yedek: `C:/Users/Semih/.codex/config.toml.rea.backup`.
- Önce/sonra TOML karşılaştırmasında REA kaydı dışındaki yapılandırma aynı bulundu.
- Global beceri: `C:/Users/Semih/.agents/skills/reverse-engineer-anything`. Paketle eşleşen beceri sürümü 42, 207 araç.
- `rea.cmd doctor --client codex --skill --json`: `healthy=true`, beceri ve kayıt `aligned`.
- Bağımsız MCP initialize/tools-list testi: sürüm 6.7.0, 207 araç.
- Daha sonra Codex mevcut oturumda bağlantıyı yeniledi; gerçek `mcp__rea.binary_session` çağrısı başarılı oldu. Bu oturum için yeniden başlatma gerekmemiştir.

Kaynak depodaki main becerisi ile npm paketinin beceri sürümleri farklı olabilir; çalışan MCP'nin şemasını/paketini esas al. Geliştiriciye özel REA becerileri ayrıca global kurulmadı; kullanıcıya yönelik paket becerisi ve bütün referansları kuruldu.

## Tam Git kaynağı

Kaynak: https://github.com/morluto/rea

Commit: `6d356b84344659085f2b912857b5e27fe0160c9b`.

| Alt depo | Sabit commit |
|---|---|
| binwalk | `4fdab3d464d97b68e0af9088df3f9e2e1545b21c` |
| ghidra-nativeaot | `effeb734fc570c32650f88b159608979dc7b423e` |
| jadx-headless-mcp | `5844800a486d2248fa949b74c9896285f5b54de2` |
| unblob | `1fcc7a0a584a70a96c31f5a276c20944d199a089` |
| wakaru | `8219bf5016a063d7fb215101a8c45d5959ec733f` |

Unblob test verilerindeki Windows'a uygun olmayan adlar nedeniyle ilk recursive checkout durdu. İstenen commit WSL Git ile checkout edildi. Windows Git uzun/geçersiz adlarda çalışma ağacını farklı gösterebilir; Unblob ağacını WSL'den incele. Kaynakların gelmesi motorların derlendiği anlamına gelmez.

## Linux / Ubuntu WSL

- REA 6.7.0 Linux CLI: `/home/semih/.local/lib/node_modules/rea-agents`.
- Mevcut Linux Node: 22.22.2.
- Unblob 26.6.4: uv tool ortamında kuruldu. Bu ortam `ubi-reader 0.8.16` içerir; kullanılan UBIFS parser budur.
- Ghidra 12.1.4 ve Temurin full JDK 21.0.12.1 resmî release dosyalarından indirildi; yayınlanan SHA-256 ile doğrulandı. Windows MSI kurulumuna ihtiyaç kalmadan taşınabilir Linux araçları kullanıldı.
- `wsl -d Ubuntu --exec sh /mnt/c/Users/Semih/Desktop/grundig/tools/rea-linux.sh doctor --provider ghidra --json`: `healthy=true`; Linux/x64, Ghidra 12.1.4, full JDK ve native decompiler kontrolleri geçti.
- Binwalk çalıştırılabilir motoru kurulmadı. Bu paketin özel güncelleme tablosu `unpack_mstar.py` ile doğrudan çözüldü; UBIFS `ubi-reader` ile açıldı. Bu çıktılar REA firmware Evidence çıktısı diye sunulmaz.

## MIPS kabul sınırı

`dvbt_board` ELF32/LE/o32/MIPS32r2 başlığı bildiriyor. Ancak `.MIPS.abiflags` inceleme kaydı eksik olduğundan REA Ghidra adaptörü `capability_unavailable / architecture_unsupported` döndürdü. Ret çıktısı: `analiz/native/dvbt_board-rea-overview.json`.

ELF'e sahte ABI verisi eklenmedi. Doğrudan resmî Ghidra headless, açık `MIPS:LE:32:default` dili ve `default` compiler spec ile ayrı statik analiz kullanılır. Bu yol floating-point ABI'yi doğrulamaz; decompiler çıktısı kaynak kod değil, pseudocode'dur.

## Tekrar çalıştırma

Önce mevcut çıktıları koru: çoğu çıkarım scripti mevcut hedefe yazmayı reddeder. Envanter/harita scriptlerinin kendi yardımını oku. Güncelleme veya firmware script'lerini shell'e verme.

```powershell
rea.cmd doctor --client codex --skill --json
wsl -d Ubuntu --exec sh /mnt/c/Users/Semih/Desktop/grundig/tools/rea-linux.sh doctor --provider ghidra --json
python -X utf8 scripts/map_ui_resources.py
wsl -d Ubuntu --exec python3 /mnt/c/Users/Semih/Desktop/grundig/scripts/inventory_firmware.py
```

İlk payload çıkarımı `scripts/unpack_mstar.py`; tam Linux FS çıkarımı `extract_linux_tree.py`; Windows okuma görünümü `materialize_tree.py`; kernel/iç arşivler `extract_remaining.py`. `extract_ubifs.py` başarısız ilk NTFS yöntemidir; tam çıkarım için kullanılmaz.

Ghidra ana analiz sarmalayıcısı `tools/analyze-main-linux.sh` ilk import içindir. Mevcut projede yeniden sorgu için `-process dvbt_board -noanalysis` yolu kullanılır; aynı projeyi körlemesine yeniden import etme.
