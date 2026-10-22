"""Retain reviewed C/assembly findings; reads analysis exports, never target code."""
from pathlib import Path
import hashlib
import json

ROOT = Path(__file__).resolve().parents[1]
MAIN = 'analiz/native/ui-targeted/system-critical14/'
CEC = 'analiz/native/system-focused/394ee95f07383231c9cc1019d9d1fb8eb3c8309ae68fe2d3186ddf19c51dae39/cec-return1/'
DVB = 'analiz/native/system-focused/93fe7286bb7fb9bf3d33ccf75556985f68666fe485241099c20bb7165bc88d97/oad-path2/'

RECORDS = [
    ('CEC dönüş değeri ve kaybolan parametre', [MAIN+'00555350', CEC+'2df7d2f8'],
     ['0055538c','00555390','00555398','2df7d348','2df7d35c','2df7d37c'],
     'Ana wrapper a0=servis nesnesi, a1=özgün RC kodu geçirir; decompiler ikinci argümanı düşürebilir. Customer wrapper callback ardından destructor ve operator_delete çağırır. Callback v0 değeri bunların üzerinden korunmaz. Önceki processed-bool yorumu desteklenmez.',
     'MW_CEC_IrWrapper::UnmappedIrEventReceivedCallbackFunc 0x2dfb95c8 (980 bayt) ve gerçek çağıran koşulları incelenmeli.'),
    ('Standby ve iptal koşulları', [MAIN+'00532f24', MAIN+'00532df4'], ['005330f8','00533104','00533110','00533118','005331cc'],
     'StartStandby aktif taramayı durdurabilir; SetPowerState(this,3,0), CEC standby, ses +0x1a0 ve DTV +0x724 sanal çağrılarını içerir. ASU nesnesi varsa StopExistingASUUpdate sonucu 1 olduğunda StartASU çağırmadan 0 döner; stop sonucu 1 değilse StartASU sonucu 1 için yine 0 döner. Diğer yollar 1. CancelStandby power-state=3 ve ASU-started=1 kapısından geçer; LED olayları ve ASU stop içerir.',
     'Cancel wrapper içinde POWER_ON yazımı yok. Ses +0x1a0 hedefinin taban implementasyonu 8 baytlık jr ra/nop stub olabilir; bundan mute veya güç kesme sonucu çıkarılmaz. Aktif override bilinmiyor.'),
    ('Aktif anten girdi dönüşümü', [MAIN+'0061d2a4'], ['0061d2ec','0061d304','0061d360','0061d390'],
     'Özgün enum globalde saklanır; DB setter için değer input==1 olarak dönüştürülür. DB getter sonucu AdjustAntenna5V yoluna gider. Wrapper sabit 1 döndürür; bu donanım başarı durumu değildir.',
     'Decompiler this/prototype ve düşen argümanları assembly ile yorumlanmalıdır; SDK/driver hata dönüşü henüz bağlanmadı.'),
    ('LNB güç eşlemesi', [MAIN+'00620940'], ['00620974','00620ae4','00620af0','00620b08'],
     'Girdi 1→1, 2→4, diğer→0. SatInfo+0x0f ve arSatTuningParams+0x16 byte alanlarına yazılır; +0x9b0 sanal çağrı, SatelliteUserInteraction(2), +0xa34 retune ve changed flag yolu vardır. Başarı wrapperı 1; cast failure assert/abort.',
     'DVBS customer runtime override ve fiziksel voltaj etkisi doğrulanmadı.'),
    ('Tarama durumu ve ATV indeks dönüşümü', [MAIN+'004f1c3c', MAIN+'004f1a20', MAIN+'004f86bc'], ['004f87c4','004f87dc'],
     'Pause/resume this+0x6c durumuna göre DTV +0x128/+0x12c veya ATV +0xe4/+0xe8 dispatch yapar; state=0 için +0x95 seçimi, geçersiz durumda assert vardır. ATV moveMode=0 kaydında ((input&255)-1)&255 geçirilir: 0 girdisi 255 olur; diğer mod SaveProgramToBack yoludur.',
     '0→255 dönüşümünün ürün düzeyinde hata mı sentinel mı olduğu, çağıran sözleşmesi çözülmeden söylenemez.'),
    ('OAD kabul wrapperlarının dönüşleri', [MAIN+'00642a50', DVB+'2d4e2b44', DVB+'2d4e2a78'], ['00642ae8'],
     'StartOADUpgrade sanal +0x610 çağrısından sonra sabit 1 döndürür. DVB taban vtable adayı +0x610→0x2d4e2b44; bu fonksiyon this+0x2b8 ve customer cast koşulunda customer kabul çağrısı ardından 1, diğer durumda 0 döndürür. Customer sonucu forward edilmez. CheckAfterWakeUp ise customer dönüşünü tail-forward eder.',
     'Vtable eşlemesi statik primary-address-point adayıdır. Customer kabul 0x2e16aad0 ve wake-up check 0x2e1695fc koşulları henüz çözülmedi; firmware kabul/imza kanıtı değildir.'),
    ('Manuel OAD ve standby update parametreleri', [MAIN+'006430b4', MAIN+'00640ecc'], ['0064108c','006410d8','006412f4','0064142c','00641564'],
     'GetOadDownInfo stack üzerinde çıktı yapısı doldurur; TV mode 1/32/128 için yapı+0x11 byte→OadScanRF, diğer modlarda yapı+8 word→OadScanFreq; wrapper sabit 1. Standby update timer/on-timer/OAD schedule sorgularına a1=1200 verir; standby-scan flag OR 1, auto-OAD flag OR 4 yolları vardır.',
     '1200 parametresinin zaman birimi ve GetOadDownInfo tam yapı prototipi açık. Decompiler sözde başlatılmamış stack değerlerini gerçek C hatası diye sunma.'),
    ('Uygulama main callback ve UI başlangıcı', ['analiz/native/ui-targeted/startup-main1/00fd0784'],
     ['00fd07a8','00fd07ac','00fd0810','00fd0b70','00fd0d7c','00fd22a0','00fd22c8','00fd22dc','00fd2374','00fd2388','00fd23cc','00fd23ec','00fd2434','00fd24e8','00fd2b98'],
     'ELF startup main callback adayı 0xfd0784, FDE [0xfd0784,0xfd2c0c). a0/a1 girişte stacke saklanır; C çıktısının float,float,int,char** prototipi güvenilir değildir. Build→MSystem Initialize→InitMSrvControl→StartMsrv→ReadResProfile sırası kodda bulunur. Profile sonucu 0 ise UI kurulmadan ortak return yoluna gider. Factory/GetDefault ve oluşturulan app null ise -1; başarılı dalda MApplet::Run(DefaultApp,0xfe,0), ardından NotifyBootUpCompleted. Console/test dalları MSystem::Run yolunu değiştirir.',
     'Factory +8 callback hedefi ve aktif DefaultApp sınıfı henüz kanıtlanmadı. MApplet Run C prototipi a2=0 argümanını düşürür. Fonksiyon main callback olarak startup/PLT bağından güçlü adaydır; ISO C main prototipi iddia edilmez.'),
]


def main():
    records = []
    doc = ['# Servis ve uygulama başlangıcı: assembly ile derinleştirme', '',
           '22 Ekim 2026. Sekiz davranış grubu; statik kod bulgularıdır. TV üzerinde gözlem yapılmadı. '
           'C çıktısının parametre ve dönüş tipleri assembly karşısında denetlendi.', '']
    for title, stems, sites, finding, unknown in RECORDS:
        artifacts = []; instructions = {}
        for stem in stems:
            path = ROOT / (stem+'.json')
            data = json.loads(path.read_text(encoding='utf-8'))
            for ins in data['instructions']:
                instructions[ins['address']] = ins['instruction']
            cpath = ROOT / (stem+'.c')
            artifacts.append({'json': stem+'.json', 'json_sha256': hashlib.sha256(path.read_bytes()).hexdigest(),
                              'c': stem+'.c', 'c_sha256': hashlib.sha256(cpath.read_bytes()).hexdigest(),
                              'function_address': data['address'], 'name': data['name']})
        missing = sorted(set(sites)-set(instructions))
        if missing:
            raise ValueError((title, 'missing instruction addresses', missing))
        records.append({'title': title, 'evidence_kind': 'reviewed_static_C_and_assembly',
                        'finding': finding, 'open_questions': unknown, 'artifacts': artifacts,
                        'instruction_evidence': [{'address': a, 'instruction': instructions[a]} for a in sites]})
        doc += ['## '+title, '', finding, '', 'Açık nokta: '+unknown, '',
                ' · '.join('[`'+a['function_address']+' C`](../../'+a['c']+') / '
                           '[assembly JSON](../../'+a['json']+')' for a in artifacts), '']
        if sites:
            doc += ['Kontrol adresleri: '+', '.join('`0x'+a+'`' for a in sites)+'.', '']
    out = ROOT/'analiz/servis-derinlestirme.json'
    out.write_text(json.dumps({'schema_version': 1, 'target_executed': False, 'target_bytes_written': False,
                               'behavior_groups': len(records), 'records': records}, ensure_ascii=False, indent=2)+'\n', encoding='utf-8')
    (ROOT/'docs/bilgi-tabani/SERVIS_DERINLESTIRME.md').write_text('\n'.join(doc), encoding='utf-8')
    print(json.dumps({'behavior_groups':len(records), 'instruction_addresses_checked':sum(len(r['instruction_evidence']) for r in records)}))


if __name__ == '__main__':
    main()
