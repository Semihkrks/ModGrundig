"""Retain measured status of the four large UI functions, without promoting probes."""
from collections import Counter
from pathlib import Path
import hashlib
import json

ROOT=Path(__file__).resolve().parents[1]
BASE=ROOT/'analiz/native/ui-four'
EXPECTED={'settings':('0055b6c0',0x579360,'NewUI_Settings'),
          'general':('00d01710',0xd254dc,'GeneralFrame create'),
          'home':('00d42150',0xd58d68,'HomePageFrame create'),
          'tools':('00f60a64',0xf86234,'ToolsMenuFrame create')}


def relative(path):
    return path.relative_to(ROOT).as_posix()


def main():
    index=json.loads((ROOT/'analiz/ui-kod-cagrilari.json').read_text(encoding='utf-8'))
    raw={key:[c for c in index['calls'] if int(c['function_address'],16)==int(info[0],16)]
         for key,info in EXPECTED.items()}
    rows=[]
    for key,(entry,end,name) in EXPECTED.items():
        attempts=[]
        for summary_path in sorted((BASE/key).glob('*/summary.json')):
            run=summary_path.parent
            function_path=run/(entry+'.json')
            context_path=run/'selection-and-context.json'
            if not function_path.is_file() or not context_path.is_file():
                continue
            summary=json.loads(summary_path.read_text(encoding='utf-8'))
            function=json.loads(function_path.read_text(encoding='utf-8'))
            context=json.loads(context_path.read_text(encoding='utf-8'))
            request=next((r for r in context.get('requested',[]) if r.get('requested_address')==entry),{})
            bound=request.get('supplied_function_bound',{}).get('end_exclusive','0')
            exact_bound=int(bound,16)==end
            coverage={int(i['address'],16) for i in function.get('instructions',[])}
            missing=sorted(set(range(int(entry,16),end,4))-coverage)
            c_path=run/(entry+'.c')
            full_c=bool(function.get('C_export_complete',function.get('decompile_complete')) and c_path.is_file() and c_path.stat().st_size)
            standard=summary.get('decompiler_simplification_style','decompile')=='decompile'
            groups=summary.get('decompiler_action_group_overrides',{})
            options=summary.get('analysis_option_overrides',{})
            default_inference=not groups and not options
            pcode_available=summary.get('syntax_tree_requested',True) and function.get('pcode_export_complete',False)
            attempt={'run':relative(run),'standard_C_complete':full_c and standard,
                     'standard_C_complete_definition':'C export using decompile printing style; does not imply default inference groups',
                     'inference_profile':'default' if default_inference else 'modified_inference',
                     'analysis_group_overrides':groups,'analysis_option_overrides':options,
                     'default_full_inference_C_complete':full_c and standard and exact_bound and not missing and default_inference,
                     'eligible_full_function_C':full_c and standard and exact_bound and not missing,
                     'error':function.get('decompile_error'),'exact_FDE_bound':exact_bound,
                     'instruction_count':len(coverage),'missing_word_count':len(missing),
                     'missing_word_addresses':[hex(a) for a in missing],
                     'C_file':relative(c_path) if full_c else None,
                     'C_sha256':hashlib.sha256(c_path.read_bytes()).hexdigest() if full_c else None,
                     'function_json':relative(function_path),
                     'function_json_sha256':hashlib.sha256(function_path.read_bytes()).hexdigest(),
                     'summary':relative(summary_path),'pcode_export_available':pcode_available,
                     'pcode_call_count':len(function.get('decompiler_pcode_calls',[])) if pcode_available else None,
                     'pcode_outside_body':function.get('decompiler_pcode_addresses_outside_selected_body') if pcode_available else None,
                     'pcode_bounds_status':'available' if pcode_available else 'unavailable_do_not_use_legacy_empty_outside_list',
                     'time_limit_seconds':summary.get('decompile_timeout_seconds_per_function'),
                     'payload_MB':summary.get('decompiler_max_payload_mbytes')}
            attempts.append(attempt)
        candidates=[a for a in attempts if a['eligible_full_function_C']]
        best=max(candidates,key=lambda a:(a['default_full_inference_C_complete'],a['run'])) if candidates else None
        rows.append({'key':key,'name':name,'entry':'0x'+entry,'end_exclusive':hex(end),
                     'FDE_bytes':end-int(entry,16),'expected_instruction_slots':(end-int(entry,16))//4,
                     'full_function_C_complete':bool(best),'canonical':best,'attempts':attempts,
                     'raw_call_candidates':len(raw[key]),
                     'raw_resolution_counts':dict(Counter(c['resolution'] for c in raw[key]))})
    count=sum(r['full_function_C_complete'] for r in rows)
    default_count=sum(bool(r['canonical'] and r['canonical']['default_full_inference_C_complete']) for r in rows)
    output={'date':'2026-10-23','target_sha256':index['target_sha256'],
            'full_function_C_complete':count,'default_full_inference_C_complete':default_count,
            'modified_inference_C_complete':count-default_count,'requested_functions':4,'records':rows,
            'target_executed':False,'target_modified':False,
            'limitations':['C completion plus full listing is not complete semantic recovery.',
                           'C-only runs omit syntax tree; empty pcode lists are unavailable, not verified zero.',
                           'Static raw call candidates are not runtime bindings; all unresolved targets remain listed.',
                           'Only standard C with exact FDE and complete aligned listing qualifies; partial/diagnostic output does not.']}
    output['limitations'] += ['Settings whole-range C disables protorecovery, protorecovery_b and localrecovery; arguments, types and EH remain incomplete.',
                              'Complete listing and completed C export do not establish that every instruction survives decompiler simplification.',
                              'Settings firstpass pcode and 12 bounded synthetic fragments are separate evidence, not extra original functions.']
    (ROOT/'analiz/ui-dort-buyuk-durum.json').write_text(json.dumps(output,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    doc=['# Dört büyük UI fonksiyonu: kapanış ve tasarıma geçiş', '',
         '23 Ekim 2026. Kullanıcının istediği dört büyük gövde için ölçülen durum. '
         'Orijinal firmware ve UI kaynakları değiştirilmedi; cihazda çalıştırma, yeniden paketleme veya yükleme yapılmadı.', '',
         f'**Bütün FDE aralığından C çıktısı + eksiksiz instruction listesi: {count}/4.** '
         f'Varsayılan çıkarım aşamalarıyla {default_count}/4; sınırlanmış çıkarımla {count-default_count}/4. '
         'C çıktısı özgün kaynak veya bütün davranışların kesin çözümü değildir; tam listing, bütün assembly yollarının C içinde korunduğu anlamına gelmez.', '',
         '| İşlev | FDE baytı | C profili | Ham çağrı adayı / belirsiz hedef | Kanıt |',
         '|---|---:|---|---:|---|']
    for r in rows:
        best=r['canonical']
        link='[C](../../'+best['C_file']+') / [assembly](../../'+best['function_json']+')' if best else 'Devam eden / başarısız denemeler JSON kaydında'
        unknown=r['raw_resolution_counts'].get('unresolved_indirect',0)
        profile=('Varsayılan çıkarım' if best['default_full_inference_C_complete'] else 'Sınırlanmış çıkarım') if best else 'Açık'
        doc.append(f"| `{r['entry']}` {r['name']} | {r['FDE_bytes']} | {profile} | {r['raw_call_candidates']} / {unknown} | {link} |")
    doc += ['', '[Bütün denemeler ve hash kayıtları](../../analiz/ui-dort-buyuk-durum.json) · '
            '[Son doğrulama kaydı](../../analiz/ui-dort-buyuk-dogrulama.json).', '',
            '## Davranış raporları', '',
            '- [Settings: ortak stil, type dispatch, arama ekranı ve switch ikonları](UI_SETTINGS_COZUM.md)',
            '- [General: widget ağacı, event bağlantıları ve koşullar](UI_GENERAL_COZUM.md)',
            '- [Home: widget/kaynak/koşul haritası](UI_HOME_COZUM.md)',
            '- [Tools: widget ağacı, odak ve modlar](UI_TOOLS_COZUM.md)', '',
            '## Bu aşamadaki yeni kanıtlar ve açık işler', '',
            'Dört özgün fonksiyonun tamamı `dvbt_board` içindedir; '
            'araç denemeleri ve Settings fragmentleri özgün fonksiyon sayısına eklenmez. '
            'Dört FDE toplam 128.917 instruction içerir. Ham 12.970 call-site adayının 542 hedefi belirsizdir; '
            'bu statik aday sayısı, 12.970 doğrulanmış runtime çağrısı anlamına gelmez.', '',
            '| Gövde | Yeni anlamlandırma / çapraz kontrol | Kalan konu |',
            '|---|---|---|',
            '| General | 66 widget; 44 event kaydı, 31 widget/event-handler bağı; constructor/parent/rect/color assembly karşılaştırması | 69 dolaylı hedef, aktif Hotel/admin/kaynak koşulları |',
            '| Home | 60 widget; 240 arka plan MImgSet ve 18 ön plan SetImg; Netflix yardım etiketi ve Hotel renk koşulu | 100 dolaylı hedef; aktif profil ve gerçek ekran gözlemi |',
            '| Tools | 85 widget; 125 karşılaştırılabilir sabit nonimport hedefte raw/pcode farkı 0; focus parametreleri assembly ile | 92 dolaylı hedef; medya/3D/DualWatch/CEC koşullarının cihazdaki seçimi |',
            '| Settings | 35 RTTI cast; 336 eksik instruction çözüldü; 10 switch case/40 ikon çağrısı; 13 sonuç etiketi iki arama ekranına bağlandı | 281 dolaylı hedef; eksik tür/argümanlar, 37 ham Unwind çağrısının EH/LSDA semantiği |', '',
            'Kesin statik kontrol ve aday bağlama raporlarda ayrıdır: örneğin Settings focus eşitliği '
            '`0x55f868` ve çağrı `0x55f884`; Tools gerçek SetInitialFocus argümanı `0xf853c0` assembly kaydındadır. '
            'Çıkarılan davranış cihaz gözlemi sayılmaz. Önceki 226/226 modül envanteri bu aşamada tekrar taranmadı.', '',
            '[Settings fragment kapsamı ve sentetik sınırlar](../../analiz/native/ui-four/settings-fragments/README.md) · '
            '[Settings C/assembly çapraz kontrolü](../../analiz/native/ui-four/settings/C-raw-crosscheck.json)', '',
            '## Hangi değişikliklere geçilebilir?', '',
            'Menü, Home ve ses paneli için ortak görsel dilin ve ekran tasarımlarının planlanması bütün 226 modülün semantik çözümünü gerektirmez. '
            'Widget/event bağlarını koruyarak yerleşim, PNG/ikon, tipografi, renk ve focus durumları için ayrı tasarım kapsamı çıkarılabilir. '
            'Paylaşılan Num/Color/Image ID’leri doğrudan global değiştirilmeden önce etki listesi kullanılmalıdır.', '',
            'Ses panelinde normal/mute/ARC modları, 3 saniyelik kapanış ve tuş yönlendirmesi korunmalı; '
            'menülerde Hotel/admin/basic/recovery, kaynak ve medya/3D/DualWatch koşulları hesaba katılmalıdır. '
            'Animation getter bu build’de sabit 0; yeni görünüm ile animasyon davranışı ayrı karar olarak ele alınmalıdır.', '',
            'Bu rapor firmware’e değişiklik uygulama veya TV’ye yükleme yetkisi değildir. '
            'Güncelleme kabul/imza yolu, fiziksel model uyumu ve cihazdaki aktif profil hâlâ açık araştırma konularıdır.', '',
            '## Araç sınırları', '',
            'Önceki 90 saniyelik/50 MB denemeleri aynı biçimde tekrarlanmadı: izole metadata projeleri, '
            '256 MB payload, daha uzun süre, standard C-only çıktı ve gerektiğinde kanıtlı eksik listing/switch metadata’sı kullanıldı. '
            'Metadata müdahaleleri kaydedilmeyen analiz bağlamında kaldı. C-only çıktıda pcode kapsam kontrolü mevcut değildir; '
            'eski boş liste/true alanı böyle bir doğrulama olarak kullanılmaz.', '',
            'Settings için `protorecovery`, `protorecovery_b`, `localrecovery` kapatılarak bütün FDE aralığından C üretildi. '
            'Bu çıktıdaki eksik çağrı argümanları ve `extraout` geçicileri nedeniyle prototipler assembly ile kontrol edilmelidir. '
            'Ham `_Unwind_Resume` yollarının C içinde görünmemesi EH kapsamının ayrıca açık kaldığını gösterir. '
            'Ayrı firstpass pcode 30.504 instruction sınırını doğrular; 12 sınırlı fragment C çıktısı '
            'orijinal gövde üzerinde 30.504 instruction sahipliğini kapsar. Fragment sınırlarında yapay dönüş/bağlam varsayımları vardır; '
            'bunlar eşdeğer kaynak veya 12 ayrı firmware fonksiyonu sayılmaz.', '']
    (ROOT/'docs/bilgi-tabani/UI_DORT_BUYUK_FONKSIYON.md').write_text('\n'.join(doc),encoding='utf-8')
    print(json.dumps({'full_function_C_complete':count,'requested_functions':4,
                      'raw_call_candidates':sum(r['raw_call_candidates'] for r in rows),
                      'raw_unknown_targets':sum(r['raw_resolution_counts'].get('unresolved_indirect',0) for r in rows)}))


if __name__=='__main__':
    main()
