"""Build measured local research index from retained evidence; no firmware writes."""
from pathlib import Path
from collections import Counter
from datetime import datetime, timezone
import json

ROOT=Path(__file__).resolve().parents[1]
A=ROOT/'analiz'
DOC=ROOT/'docs/bilgi-tabani'

def read(path):
    return json.loads(path.read_text(encoding='utf-8'))

def main():
    inventory=read(A/'envanter-v2/elf-envanteri.json')
    manifest=read(A/'native/system-modules/manifest.json')
    categories={e['module']:e for e in read(A/'envanter-v2/modul-kategorileri.json')['modules']}
    modules=DOC/'moduller'
    modules.mkdir(parents=True,exist_ok=True)
    by_sha={r['sha256']:r for r in manifest['records']}
    totals=Counter(); rows=[]; pending=[]
    for e in inventory['elfs']:
        sha=e['sha256']; record=by_sha[sha]
        summary_file=A/'native/system-modules'/sha/'summary.json'
        s=read(summary_file) if summary_file.is_file() else None
        existing=record['status']=='existing_UI_analysis'
        if s:
            status='Ghidra indeks tamam; analiz süre sınırlı' if s['analysis_timeout'] else 'Ghidra indeks tamam'
            totals['module_paths_with_Ghidra_index']+=1
        elif existing:
            status='Önceki Ghidra + odaklı UI analizi'
            totals['module_paths_with_Ghidra_index']+=1
        else:
            status='Sırada / analiz sürüyor'
            pending.append(e['path'])
        role=categories[e['path']].get('categories',[])
        module_name=sha[:12]+'__'+Path(e['path']).name+'.md'
        body=[f"# `{e['path']}`",'',f"SHA-256: `{sha}`",'',f"Durum: **{status}**.",'',
              f"Tür: {e['header'].get('Type','?')}; ELF32 LE MIPS; {e['size']} bayt.",'',
              f"İşlev alanı **isim/bağımlılık çıkarımıdır**: `{json.dumps(role,ensure_ascii=False)}`.",
              'Davranışın koddan anlamlandırılması bu sınıflandırmadan ayrı değerlendirilir.','',
              '## Bağımlılık ve API beyanları','',
              '- DT_NEEDED: '+', '.join('`'+n+'`' for n in e.get('needed',[])),
              f"- Dynamic import/export: {e['counts']['dynamic_imports']} / {e['counts']['dynamic_exports']}.",
              '- Sembol adresleri ve relocation kayıtları: [güncel ELF envanteri](../../../analiz/envanter-v2/elf-envanteri.json).',
              '- Bağlama adayları: [sembol ilişkileri](../../../analiz/envanter-v2/sembol-baglantilari.json).','']
        if s:
            rel='../../../analiz/native/system-modules/'+sha+'/'
            body += ['## Ghidra kapsamı','',f"- Fonksiyon kayıtları: {s['functions']}; semboller: {s['symbols']}.",
                     f"- Xref: {s['xrefs']}; analizde call tipli xref: {s['analyzed_call_xrefs']}.",
                     f"- Computed-call instruction: {s['computed_call_instructions']} (runtime hedefi doğrulanmadı).",
                     f"- İlk örnek decompile: {s['sample_decompile_complete']}/{s['sample_decompile_attempted']}.",
                     f"- Analiz timeout: {s['analysis_timeout']}.",'',
                     f"[Fonksiyonlar]({rel}functions.jsonl) · [Xref]({rel}xrefs.jsonl) · [Semboller]({rel}symbols.jsonl) · [Dolaylı çağrı noktaları]({rel}computed-calls.jsonl)",'',
                     '### İlk decompile örnekleri','',
                     '| Adres | Fonksiyon | Çıktı |','|---|---|---|']
            for d in s['samples']:
                label=f"[C]({rel}{d['address']}.c)" if d['complete'] else 'Başarısız: '+str(d.get('error',''))
                body.append(f"| `{d['address']}` | `{d['name']}` | {label} |")
        elif existing:
            body += ['## Koddan doğrulanan UI davranışları','',
                     '[UI yapı ve davranış raporu](../../UI_KOD_YAPISI.md) ve [ses/menü ayrıntıları](../../UI_HARITASI.md).']
        body += ['', '## Giriş/çıkış ve açık işler','',
                 'Import/export beyanı, API çağrısının gerçekleştiği veya parametrelerinin doğru çözüldüğü anlamına gelmez. '
                 'Girdi/çıktı türleri, sınır kontrolleri, hata yolları ve servis yan etkileri kritik fonksiyon bazında assembly ile doğrulanmalıdır. '
                 'İlk örnekler isim ve boyutla seçilir; tamamlanmış semantik inceleme sayılmaz.',
                 'Dinamik loader kapsamı, sanal fonksiyon hedefleri, callback kaydı ve cihazın aktif koşulları açık kalabilir.','']
        (modules/module_name).write_text('\n'.join(body),encoding='utf-8',newline='\n')
        rows.append(f"| [`{e['path']}`](moduller/{module_name}) | {status} | {s['functions'] if s else 'önceki UI indeksi' if existing else '—'} | {str(s['sample_decompile_complete'])+'/'+str(s['sample_decompile_attempted']) if s else 'odaklı UI' if existing else '—'} |")
    summaries=[read(p) for p in (A/'native/system-modules').glob('*/summary.json')]
    totals.update(module_paths=len(inventory['elfs']),unique_artifacts=len(by_sha),
                  new_Ghidra_artifacts=len(summaries),new_Ghidra_functions=sum(s['functions'] for s in summaries),
                  new_Ghidra_xrefs=sum(s['xrefs'] for s in summaries),
                  new_Ghidra_call_xrefs=sum(s['analyzed_call_xrefs'] for s in summaries),
                  new_Ghidra_computed_call_instructions=sum(s['computed_call_instructions'] for s in summaries),
                  new_sample_decompile_attempted=sum(s['sample_decompile_attempted'] for s in summaries),
                  new_sample_decompile_complete=sum(s['sample_decompile_complete'] for s in summaries),
                  new_analysis_timeouts=sum(s['analysis_timeout'] for s in summaries))
    status={'updated_at_UTC':datetime.now(timezone.utc).isoformat(),'counts':dict(totals),
            'pending_modules':pending,'source_files_modified':False,
            'limitations':['Counts measure retained outputs, not percentage of source recovered or behavior understood.',
                           'Aliases share SHA-level Ghidra outputs; unique artifact counts avoid double-counting.',
                           'Ghidra call xrefs and raw PIC/GOT call candidates are different metrics and must not be added as independent calls.']}
    focused_file=A/'odakli-analiz-durum.json'
    if focused_file.is_file():
        focused=read(focused_file)
        status['focused_analysis']={k:focused[k] for k in ['unique_selected_entries','unique_complete_entries','records']}
    four_file=A/'ui-dort-buyuk-durum.json'
    if four_file.is_file():
        four=read(four_file)
        status['four_large_UI']={k:four[k] for k in ['full_function_C_complete','default_full_inference_C_complete','modified_inference_C_complete','requested_functions']}
    partition_file=A/'native/analysis-partitions/manifest.json'
    if partition_file.is_file():
        partition=read(partition_file)
        status['timeout_followup_queue']={'modules':len(partition['modules']),
            'chunks':sum(len(m['chunks']) for m in partition['modules']),
            'internal_functions':sum(m['internal_non_thunk_records'] for m in partition['modules']),
            'queue_executed':False}
    (A/'asama-durum.json').write_text(json.dumps(status,ensure_ascii=False,indent=2)+'\n',encoding='utf-8',newline='\n')
    overview=['# Grundig firmware bilgi tabanı','',
              'Öncelik: özgün firmware’i değiştirmeden mimariyi ve davranışları kanıtlarıyla çözmek. '
              'Cihazda çalıştırma, repack veya yükleme yapılmadı.','',
              '[Genel bulgular](../TERSINE_MUHENDISLIK.md) · [UI kod yapısı](../UI_KOD_YAPISI.md) · '
              '[UI ayrıntıları](../UI_HARITASI.md) · [Boot ve format](BOOT_VE_FORMAT.md) · '
              '[Servis davranışları](SERVISLER.md) · [Bağımlılık araştırması](BAGIMLILIKLAR.md) · '
              '[Servis derinleştirme](SERVIS_DERINLESTIRME.md) · [DirectFB callback çözümü](DIRECTFB_CALLBACK.md) · '
              '[Dar UI devamı](UI_DAR_DEVAM.md) · '
              '[Factory kaydı ve UI hazırlığı](UI_FACTORY_KAYDI.md) · '
              '[Dört büyük UI gövdesi ve tasarıma geçiş](UI_DORT_BUYUK_FONKSIYON.md) · '
              '[Araç sınırları](ARAC_SINIRLARI.md) · [Aşama raporu](ASAMA_2026-10-22.md) · '
              '[Araştırma takibi](TAKIP.md) · [Ölçülebilir durum](../../analiz/asama-durum.json)','',
              '## Kapsam','',
              f"- ELF: {len(inventory['elfs'])} dosya yolu / {len(by_sha)} benzersiz hash; tümünün statik sembol/bağımlılık envanteri mevcut.",
              f"- Ghidra indeksi mevcut dosya yolu: {totals['module_paths_with_Ghidra_index']}/{len(inventory['elfs'])}.",
              f"- Bu sistem taramasında {len(summaries)} yeni artifact, {totals['new_Ghidra_functions']} fonksiyon kaydı, {totals['new_Ghidra_xrefs']} xref.",
              f"- İlk örnek decompile: {totals['new_sample_decompile_complete']}/{totals['new_sample_decompile_attempted']}; analiz timeout: {totals['new_analysis_timeouts']}.",
              f"- Güncel odaklı sorgular: {focused['unique_selected_entries']} benzersiz giriş / {focused['unique_complete_entries']} tamamlanmış C; Settings sınırlanmış çıkarım profiliyle bu sayıya dahildir." if focused_file.is_file() else '- Önceki UI aşaması: 136 odaklı giriş / 132 tamamlanmış C.',
              '- Ham bootloader komutları ayrı kapsam: 5/5 decompile; [bulgular](../../analiz/native/boot-candidate-v1/FINDINGS.md).',
              '- Decompile tamamlanması doğruluk veya semantik inceleme tamamlanması değildir. '
              'Fonksiyon sayıları external/thunk kayıtları içerebilir. Dolaylı hedefler açıkça adaydır.','',
              '## Modüller','', '| Modül | Aşama durumu | Fonksiyon | İlk örnek C |','|---|---|---:|---:|']+rows+['']
    (DOC/'README.md').write_text('\n'.join(overview),encoding='utf-8',newline='\n')
    print(json.dumps(dict(totals)))

if __name__=='__main__':main()
