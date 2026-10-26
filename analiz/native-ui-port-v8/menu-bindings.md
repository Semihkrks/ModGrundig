# Native menü bağlantıları — v8

25 Ekim 2026. Tarayıcıdaki24 menü modeli bağlantı otoritesi değildir. Gerçek ELF message tabloları ve eski native çağrı noktaları tekrar okundu. Yeni veya sahte servis eklenmedi; bu statik koruma denetimidir.

| Ölçüm | Sonuç |
|---|---|
| classes | 81 |
| message_bindings | 1181 |
| distinct_handlers | 1059 |
| handler_extents_verified | 1059 |
| handler_bodies_unchanged_since_v7 | 1056 |
| changed_visual_handler_bodies | ['0x7995b0', '0x7de53c', '0xd42150'] |
| application_frame_factories | 70 |
| navigation_call_instructions | 1854 |
| unresolved_static_byte_ranges | 0 |

Gerçek fonksiyon/map/callsite adresleri ve çözülemeyen kapsam [JSON](menu-bindings.json) içindedir. OnCreate görsel gövdelerindeki değişiklikler normaldir; statik tablo korunması bütün menülerin TV’de çalıştırıldığı anlamına gelmez.

## Çekirdek ekranlar

| Sınıf | Map VA | Kayıt |
|---|---|
| ArChannelListFrame | 0x010b9954 | 13 |
| ArProgramInfoFrame | 0x010b9cf4 | 16 |
| ChannelControlFrame | 0x010bad04 | 5 |
| DMPFileSelectorFrame | 0x010bb1ac | 36 |
| DMPMoviePlayerFrame | 0x010bb634 | 69 |
| DMPMusicPlayerFrame | 0x010bbe5c | 27 |
| DMPPhotoPlayerFrame | 0x010bc1ec | 32 |
| DMPTextPlayerFrame | 0x010bc604 | 18 |
| DMPlayerFrame | 0x010bc894 | 18 |
| EpgTimerCountDownFrame | 0x010bcb24 | 4 |
| GeneralSettingsFrame | 0x010be074 | 44 |
| HomePageFrame | 0x010be5dc | 8 |
| ParentalControlFrame | 0x010c0604 | 16 |
| PC_SourceSetupFrame | 0x010c085c | 17 |
| PictureSettingsFrame | 0x010c0d3c | 16 |
| PVRFrame | 0x010c1334 | 39 |
| SoundSettingsFrame | 0x010c253c | 32 |
| SourceSetupFrame | 0x010c2954 | 46 |
| TimerAppsFrame | 0x010c2fe4 | 28 |
| TimeSleepTimerStartMessageFrame | 0x010c338c | 8 |
