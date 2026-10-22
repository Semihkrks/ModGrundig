"""Retain manually interpreted service facts with independent raw instruction words."""
from pathlib import Path
import hashlib
import json
from map_mips_calls import Elf32

ROOT=Path(__file__).resolve().parents[1]
FACTS=[
 ('07_MSLIB/libmsrv_network.so',0x2e7ee354,'WAN callback kaydı',
  'a1 callback değerini this+0x1c64 alanına yazar ve 0 döndürür. Callback bu işlev içinde çağrılmaz.'),
 ('07_MSLIB/libmsrv_network.so',0x2e7ee360,'WAN callback kaldırma',
  'this+0x1c64 alanına 0 yazar ve 0 döndürür.'),
 ('07_MSLIB/libmsrv_network.so',0x2e830338,'Route wrapper stub',
  'Struct argüman registerlerini stack’e döküp 0 döndürür; burada syscall veya route değiştirme çağrısı yoktur. Decompiler prototipi bu spill argümanlarını göstermiyor. Diğer ağ yollarına genellenmez.'),
 ('07_MSLIB/libmsrv_control.so',0x2ea9e8f4,'Servisten ses tuşu olayı',
  'PostEvent(this,0,0x14,0xf04d,0) çağrısı üretir. Bu wrapper doğrudan ses seviyesi yazmaz.'),
 ('07_MSLIB/utopia/libdrvIR.so',0x2f461044,'IR yapılandırma ioctl yolu',
  'Girdi işaretçisinden beş 32-bit alan kopyalar, modül içindeki fd ile ioctl request 0x8014750b çağırır. Gerçek cihaz/fd ve ioctl kernel handler bağlantısı henüz doğrulanmadı.'),
 ('07_MSLIB/utopia/libdrvIR.so',0x2f461e74,'IR state geçişi',
  'Girdi 1 durum kaydını 1 yapıp 0 döndürür. Girdi 2 ancak önceki kayıt 1 ise MDrv_IR_Init çağırıp kaydı 2 yapar; diğer yollar 1 döndürür. Sayısal durumlara suspend/resume enum adı henüz atanmadı.'),
 ('07_MSLIB/libar_cec.so',0x2f045304,'CEC başlatma durumu getter',
  'GOT üzerinden erişilen modül globalindeki word değerini döndürür. Bu okuma fiziksel CEC bağlantısının hazır olduğunun gözlemi değildir.'),
 ('07_MSLIB/libmsrv_dvbs.so',0x2ebea490,'LNB virtual yönlendirme',
  'Nesnenin vtable slot +0x9b0 hedefine tail jump yapar. Nihai override ve donanım komutu bu gövdeden tek başına bilinmez.')]

REG=['zero','at','v0','v1','a0','a1','a2','a3','t0','t1','t2','t3','t4','t5','t6','t7','s0','s1','s2','s3','s4','s5','s6','s7','t8','t9','k0','k1','gp','sp','fp','ra']
def instruction(w,va):
    op,rs,rt,rd,fn=w>>26,(w>>21)&31,(w>>16)&31,(w>>11)&31,w&63
    imm=w&65535; signed=imm-65536 if imm&0x8000 else imm
    if w==0:return 'nop'
    if op in (35,43,32,36,40):return f"{ {35:'lw',43:'sw',32:'lb',36:'lbu',40:'sb'}[op]} {REG[rt]},{signed}({REG[rs]})"
    if op==15:return f'lui {REG[rt]},0x{imm:x}'
    if op in (9,12,13):return f"{ {9:'addiu',12:'andi',13:'ori'}[op]} {REG[rt]},{REG[rs]},{signed if op==9 else hex(imm)}"
    if op==0 and fn in (8,9):return f"{'jr' if fn==8 else 'jalr'} {REG[rs]}"
    if op==0 and fn in (0x21,0x25):return f"{'addu' if fn==0x21 else 'or'} {REG[rd]},{REG[rs]},{REG[rt]}"
    if op in (4,5):return f"{'beq' if op==4 else 'bne'} {REG[rs]},{REG[rt]},0x{va+4+signed*4:x}"
    return f'.word 0x{w:08x} (not decoded by this limited verifier)'

def main():
    inv=json.loads((ROOT/'analiz/envanter-v2/elf-envanteri.json').read_text())
    by_path={e['path']:e for e in inv['elfs']}
    records=[];text=['# Servis davranışları: ilk kod kanıtları','',
                     '22 Ekim 2026. Aşağıdaki sonuçlar seçili gövdelerle sınırlıdır; donanımda çalıştırılmadı. '
                     'Diğer servis işlevleri için modül indeksi ve takip listesi esas alınır.','']
    for module,address,title,fact in FACTS:
        e=by_path[module]; elf=Elf32(ROOT/'analiz/dosya-sistemleri-tam'/module)
        if hashlib.sha256(elf.raw).hexdigest()!=e['sha256']:raise ValueError('Changed artifact')
        symbols=[s for s in elf.symbols if s['value']==address and s['type']==2 and not s['imported']]
        if not symbols or not symbols[0]['size']:raise ValueError('No exact positive symbol bound')
        symbol=symbols[0];size=symbol['size']
        if size>16384:raise ValueError('Unexpected large function')
        assembly=[{'va':hex(a),'file_offset':elf.file_offset(a),'u32':f'0x{elf.u32(a):08x}',
                   'decoded_subset':instruction(elf.u32(a),a)} for a in range(address,address+size-3,4)]
        cpath=ROOT/'analiz/native/system-modules'/e['sha256']/(f'{address:08x}.c')
        if not cpath.is_file():raise ValueError('No retained decompiler source')
        row={'module':module,'sha256':e['sha256'],'address':hex(address),'symbol':symbol['name'],
             'declared_bytes':size,'claim':fact,'C_file':cpath.relative_to(ROOT).as_posix(),
             'C_sha256':hashlib.sha256(cpath.read_bytes()).hexdigest(),'instructions':assembly,
             'evidence':'manually_read_C_with_raw_instruction_crosscheck_not_runtime'}
        records.append(row)
        rel='../../'+cpath.relative_to(ROOT).as_posix()
        text += ['## '+title,'',f"`{module}` · `{hex(address)}` · `{symbol['name']}`",'',fact,'',
                 f"[Decompile çıktısı]({rel}); assembly word/ofsetleri [servis kanıt JSON'unda](../../analiz/servis-davranis-kanitlari.json).",'']
    out={'schema_version':1,'functions_with_recorded_behavior':len(records),'records':records,
         'limitations':['Decompiled prototypes are candidates; raw instruction crosschecks constrain the stated facts.',
                        'The small verifier decodes a declared subset and retains other instructions as raw words.',
                        'Callback invocation, final vtable override, hardware side effects and device state remain separate research.']}
    (ROOT/'analiz/servis-davranis-kanitlari.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    (ROOT/'docs/bilgi-tabani/SERVISLER.md').write_text('\n'.join(text),encoding='utf-8')
    print(json.dumps({'functions_with_recorded_behavior':len(records)}))

if __name__=='__main__':main()
