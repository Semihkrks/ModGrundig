"""Actual bounded MIPS candidate instructions; all native externals mocked."""
from __future__ import annotations
import json
import struct
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools/native-volume-venv/Lib/site-packages'))
from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_LITTLE_ENDIAN, UC_HOOK_CODE, UC_HOOK_MEM_WRITE
from unicorn import mips_const as m
import native_hevc_audio_test as patch

MON, STACK, STUB, STOP = 0x10000000, 0x12008000, 0x11000000, 0x13000000


class Harness:
    def __init__(self,raw,*,bias=0,now=5001,then=1000,ready92=0,pending=0,codec=7,
                 source=0x1c,window=0,playback=0,demux_mode=0,video=1,audio=1,
                 pid=101,audio_codec=6,mask=3,pcr=100,decoder=0x10004000,
                 frames=0,lock=1):
        self.u=Uc(UC_ARCH_MIPS,UC_MODE_MIPS32|UC_MODE_LITTLE_ENDIAN)
        self.raw,self.bias,self.frames,self.lock,self.now=raw,bias,frames,lock,now
        self.calls=[];self.visited=[];self.writes=[]
        ph,=struct.unpack_from('<I',raw,28);ps,pn=struct.unpack_from('<HH',raw,42)
        for idx in range(pn):
            kind,off,va,_,fs,ms,*_=struct.unpack_from('<8I',raw,ph+ps*idx)
            if kind==1:
                low=(va+bias)&~4095;high=(va+bias+ms+4095)&~4095
                self.u.mem_map(low,high-low);self.u.mem_write(va+bias,raw[off:off+fs])
        for start in [MON,STACK&~0xffff,STUB,STOP]:self.u.mem_map(start,0x10000)
        def w32(off,val):self.u.mem_write(MON+off,struct.pack('<I',val))
        def w16(off,val):self.u.mem_write(MON+off,struct.pack('<H',val))
        for off,val in [(0x84,then),(0xa0,codec),(0xc,source),(0x1c8,window),
                        (0xa4,audio_codec),(0x68,mask),(0x138,decoder)]:w32(off,val)
        for off,val in [(0x92,ready92),(0x6e,pending),(0x1be,playback),
                        (0xc6,demux_mode),(0x110,video),(0x111,audio)]:self.u.mem_write(MON+off,bytes([val]))
        w16(0xb2,pid);w16(0xbe,pcr)
        self.before=bytes(self.u.mem_read(MON,0x200))
        for idx,(name,delta) in enumerate(patch.GOT.items()):
            addr=STUB+idx*0x100
            self.u.mem_write(patch.CANONICAL_GP+bias+delta,struct.pack('<I',addr))
        self.saved={getattr(m,'UC_MIPS_REG_S'+str(i)):0xcafe0000+i for i in range(8)}
        self.saved[m.UC_MIPS_REG_FP]=0xabcd001e
        for reg,val in self.saved.items():self.u.reg_write(reg,val)
        self.u.reg_write(m.UC_MIPS_REG_SP,STACK)
        self.u.reg_write(m.UC_MIPS_REG_GP,0x12345678)
        self.u.reg_write(m.UC_MIPS_REG_RA,STOP)
        self.u.reg_write(m.UC_MIPS_REG_A0,MON)
        self.u.reg_write(m.UC_MIPS_REG_T9,patch.ENTRY+bias)
        self.u.hook_add(UC_HOOK_CODE,self.hook)
        self.u.hook_add(UC_HOOK_MEM_WRITE,self.write_hook)

    def write_hook(self,uc,access,addr,size,value,data):
        self.writes.append((addr,size,value))
        allowed=(STACK-0x20<=addr and addr+size<=STACK) or any(
            MON+off<=addr and addr+size<=MON+off+n for off,n in [(0x84,4),(0x113,1)])
        if not allowed:raise AssertionError(f'Unexpected native write {addr:#x}/{size}')

    def hook(self,uc,address,size,data):
        self.visited.append(address)
        if len(self.visited)>2000:raise AssertionError('Instruction watchdog')
        if STUB<=address<STUB+0x400 and (address-STUB)%0x100==0:
            name=list(patch.GOT)[(address-STUB)//0x100]
            args=[uc.reg_read(getattr(m,'UC_MIPS_REG_A'+str(i))) for i in range(3)]
            self.calls.append((name,args))
            ret=uc.reg_read(m.UC_MIPS_REG_RA)
            result={'time':self.now,'frame_count':self.frames,'mad_lock':self.lock,'set_mute':0}[name]
            if name=='set_mute':
                assert args==[MON,0,2],args
                mask,=struct.unpack('<I',uc.mem_read(MON+0x68,4))
                # Native SetMuteFlag implementation is separately static-pinned;
                # its external effect is modeled here, not claimed executed.
                uc.mem_write(MON+0x68,struct.pack('<I',mask&~2))
            for reg in [m.UC_MIPS_REG_V0,m.UC_MIPS_REG_V1,m.UC_MIPS_REG_A0,
                        m.UC_MIPS_REG_A1,m.UC_MIPS_REG_A2,m.UC_MIPS_REG_A3,
                        m.UC_MIPS_REG_T0,m.UC_MIPS_REG_T1,m.UC_MIPS_REG_T2,
                        m.UC_MIPS_REG_T3,m.UC_MIPS_REG_T4,m.UC_MIPS_REG_T5,
                        m.UC_MIPS_REG_T6,m.UC_MIPS_REG_T7,m.UC_MIPS_REG_T8,
                        m.UC_MIPS_REG_T9,m.UC_MIPS_REG_GP]:uc.reg_write(reg,0xdead1234)
            uc.reg_write(m.UC_MIPS_REG_V0,result)
            uc.reg_write(m.UC_MIPS_REG_PC,ret)
            return
        at=address-self.bias
        allowed=patch.ENTRY<=at<patch.ENTRY+192 or patch.HELPER<=at<patch.HELPER+len(patch.helper_code())
        if not allowed:raise AssertionError(f'Unexpected native execution {address:#x}')

    def run(self):
        self.u.emu_start(patch.ENTRY+self.bias,STOP,count=2000)
        assert self.u.reg_read(m.UC_MIPS_REG_PC)==STOP
        for reg,val in self.saved.items():assert self.u.reg_read(reg)==val,reg
        assert self.u.reg_read(m.UC_MIPS_REG_SP)==STACK
        assert self.u.reg_read(m.UC_MIPS_REG_RA)==STOP
        assert self.u.reg_read(m.UC_MIPS_REG_GP)==patch.CANONICAL_GP+self.bias
        after=bytes(self.u.mem_read(MON,0x200))
        allowed=set(range(0x84,0x88))|set(range(0x68,0x6c))|{0x113}
        assert all(i in allowed for i,(x,y) in enumerate(zip(self.before,after)) if x!=y)
        return dict(mask=struct.unpack_from('<I',after,0x68)[0],timestamp=struct.unpack_from('<I',after,0x84)[0],
                    tried=after[0x113],calls=[x[0] for x in self.calls],abi_preserved=True,
                    executed_addresses=[hex(x) for x in self.visited])


class HEVCAudioTest(unittest.TestCase):
    cases=[]
    @classmethod
    def setUpClass(cls):
        cls.original=(ROOT/'analiz/dosya-sistemleri-tam/07_MSLIB/libmsrv_common.so').read_bytes()
        cls.raw,cls.proof=patch.apply(cls.original)

    def run_case(self,label,**kwargs):
        result=Harness(self.raw,**kwargs).run()
        self.cases.append(dict(label=label,inputs=kwargs,result=result))
        return result

    def test_source_hash_allowlist_and_metadata_preservation(self):
        self.assertEqual(len(self.raw),len(self.original))
        allowed=self.proof['allowlist']
        self.assertTrue(all(any(a['offset']<=i<a['offset']+a['size'] for a in allowed)
                            for i,(x,y) in enumerate(zip(self.original,self.raw)) if x!=y))
        for raw in [b'',self.raw,self.original[:-1],bytes([self.original[0]^1])+self.original[1:]]:
            with self.assertRaises(ValueError):patch.apply(raw)
        sh,=struct.unpack_from('<I',self.original,32);size,count=struct.unpack_from('<HH',self.original,46)
        self.assertEqual(self.original[:52],self.raw[:52])
        self.assertEqual(self.original[sh:sh+size*count],self.raw[sh:sh+size*count])
        self.assertEqual(self.proof['input_sha256'],patch.INPUT_SHA)

    def test_only_native_locked_zero_frame_hevc_recovers(self):
        for bias in [0,0x01000000]:
            result=self.run_case('eligible_HEVC_rebased_'+hex(bias),bias=bias,mask=0x23)
            self.assertEqual(result['calls'],['time','frame_count','mad_lock','set_mute'])
            self.assertEqual(result['mask'],0x21)
            self.assertEqual(result['timestamp'],0)
            self.assertEqual(result['tried'],1)
        self.assertEqual(self.run_case('no_MAD_lock',lock=0)['mask'],3)
        self.assertNotIn('set_mute',self.cases[-1]['result']['calls'])
        self.assertNotIn('mad_lock',self.run_case('has_video_frame',frames=1)['calls'])

    def test_timeout_and_sync_pending_remain_native(self):
        for now,then in [(3000,1000),(2999,1000),(0,0),(1000,3000)]:
            r=self.run_case('timeout_not_elapsed',now=now,then=then)
            self.assertEqual(r['calls'],['time']);self.assertEqual(r['mask'],3)
        self.assertIn('set_mute',self.run_case('timeout_just_elapsed',now=3001,then=1000)['calls'])
        self.assertEqual(self.run_case('sync_pending',pending=1)['calls'],['time'])

    def test_every_fallback_guard_fails_closed(self):
        for key,value in [('codec',2),('codec',0),('source',0x25),('source',5),('window',1),
                          ('playback',1),('demux_mode',1),('video',0),('audio',0),
                          ('pid',0x1fff),('audio_codec',0xff),('mask',1),('decoder',0)]:
            with self.subTest(key=key,value=value):
                r=self.run_case('guard_'+key,**{key:value})
                self.assertEqual(r['calls'],['time'])

    def test_other_audio_mask_reasons_are_preserved(self):
        for bit in [4,8,0x40,0x80,0x2000,0x8000,0x10000]:
            r=self.run_case('other_reason_'+hex(bit),mask=3|bit)
            self.assertEqual(r['mask'],3|bit);self.assertEqual(r['calls'],['time'])
        # PCR is never rewritten, nor arbitrarily used to invent a ready state.
        self.assertIn('set_mute',self.run_case('PCR_null_but_native_MAD_locked',pcr=0x1fff)['calls'])

    def test_initial_mad_lock_failure_does_not_prevent_retry(self):
        h=Harness(self.raw,lock=0)
        first=h.run()
        self.assertEqual(first['tried'],1)
        self.assertNotIn('set_mute',first['calls'])
        h.lock=1
        h.u.reg_write(m.UC_MIPS_REG_A0,MON)
        h.u.reg_write(m.UC_MIPS_REG_T9,patch.ENTRY)
        second=h.run()
        self.assertEqual(second['calls'][-4:],['time','frame_count','mad_lock','set_mute'])
        self.assertEqual(second['mask'],1)
        self.cases.append(dict(label='MAD_false_then_true_retry',inputs=dict(initial_lock=0,later_lock=1),result=second))

    def test_existing_ready_path_matches_original_for_all_sources(self):
        for codec,source,lock,pending in [(2,0x1c,1,0),(7,0x25,1,0),(7,0x1c,0,0),
                                          (7,0x1c,1,1),(0,5,1,0)]:
            kwargs=dict(ready92=1,codec=codec,source=source,lock=lock,pending=pending,mask=0x83)
            before=Harness(self.original,**kwargs).run();after=self.run_case('original_ready_path',**kwargs)
            for key in ['mask','timestamp','tried','calls','abi_preserved']:self.assertEqual(before[key],after[key])

    @classmethod
    def tearDownClass(cls):
        out=ROOT/'analiz/native-4k/audio-test';out.mkdir(parents=True,exist_ok=True)
        (out/'bounded-native-tests.json').write_text(json.dumps(dict(
            kind='Actual entry/trampoline/helper MIPS execution; every external native service mocked',
            candidate_sha256=patch.sha(cls.raw),cases=cls.cases,case_count=len(cls.cases),
            physical_tv_tested=False,full_firmware_executed=False,
            SetMuteFlag_effect_modeled_not_executed=True),ensure_ascii=False,indent=2)+'\n',encoding='utf8')


if __name__=='__main__':unittest.main()
