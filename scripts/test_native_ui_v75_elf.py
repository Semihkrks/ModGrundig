import struct
import unittest
from native_ui_v75_elf import append_payload, FILE_OFFSET, SEGMENT_VA, PH


def fixture():
    data = bytearray(0xD40000)
    data[:7] = b'\x7fELF\x01\x01\x01'
    struct.pack_into('<HHI', data, 16, 2, 8, 1)
    struct.pack_into('<I', data, 28, 52)
    struct.pack_into('<I', data, 32, 0xD30000)
    struct.pack_into('<HH', data, 42, 32, 7)
    ph = [(6,52,0x400034,0x400034,224,224,4,4),
          (3,276,0x400114,0x400114,13,13,4,1),
          (1,0,0x400000,0x400000,0xC1D800,0xC1D800,5,0x10000),
          (1,0xCBD3D4,0x10ED3D4,0x10ED3D4,0x720E2,0x720E2,6,0x10000),
          (2,0x200,0x400200,0x400200,128,128,6,4),
          (0x70000000,0,0,0,0,0,4,4),(0x70000001,0,0,0,0,0,4,4)]
    for i,p in enumerate(ph): PH.pack_into(data,52+i*32,*p)
    return bytes(data)


class ExtensionTests(unittest.TestCase):
    def test_mapping_preserves_original_bytes_and_linux_auxv(self):
        old = fixture()
        new, proof = append_payload(old, b'\x11'*32, b'\x22'*40)
        changes = [i for i,(a,b) in enumerate(zip(old,new)) if a != b]
        self.assertTrue(all(i in range(28,32) or i in range(44,46) for i in changes))
        self.assertEqual(new[52:276],old[52:276])
        self.assertEqual(struct.unpack_from('<I',new,28)[0],FILE_OFFSET)
        ph = [PH.unpack_from(new,FILE_OFFSET+i*32) for i in range(8)]
        self.assertEqual(ph[0][2],0x400000+FILE_OFFSET)
        self.assertEqual(ph[7][2],SEGMENT_VA)
        self.assertEqual(ph[7][6],5)
        self.assertEqual(new[FILE_OFFSET+0x100:FILE_OFFSET+0x120],b'\x11'*32)
        self.assertEqual(new[FILE_OFFSET+0x800:],b'\x22'*40)
        self.assertTrue(proof['section_table_unchanged'])

    def test_reject_slot_overflow_and_empty_helper(self):
        for create, update in [(b'',b'1234'),(b'123',b'1234'),(b'1'*0x704,b'1234'),(b'1234',b'1'*0x1804)]:
            with self.assertRaises(ValueError): append_payload(fixture(),create,update)

    def test_reject_profile_drift(self):
        for address, value in [(16,3),(44,8),(28,100),(52+2*32+16,1)]:
            data=bytearray(fixture());struct.pack_into('<H' if address in (16,44) else '<I',data,address,value)
            with self.assertRaises(ValueError): append_payload(data,b'1234',b'5678')

    def test_unwind_merge_preserves_old_search_target(self):
        data=bytearray(fixture())
        PH.pack_into(data,52+6*32,0x6474E550,0x1000,0x401000,0x401000,20,20,4,4)
        data[0x1000:0x1004]=bytes([1,0x1b,3,0x3b])
        struct.pack_into('<iIii',data,0x1004,0x1000,1,0x100,0x200)
        frames=[{'start':SEGMENT_VA+x,'size':8,'events':[{'pc':4,'cfa_offset':160},{'pc':8,'offsets':{31:-4}}]} for x in (0x100,0x800)]
        new,proof=append_payload(bytes(data),b'1'*8,b'2'*8,unwind_frames=frames)
        self.assertEqual(proof['unwind']['merged_entries'],3)
        self.assertTrue(proof['unwind']['old_entries_preserved'])
        eh=next(PH.unpack_from(new,FILE_OFFSET+i*32) for i in range(8) if PH.unpack_from(new,FILE_OFFSET+i*32)[0]==0x6474E550)
        pairs=[tuple(eh[2]+v for v in struct.unpack_from('<ii',new,eh[1]+12+i*8)) for i in range(3)]
        self.assertEqual(pairs[0],(0x401100,0x401200))
        self.assertEqual([p[0] for p in pairs[1:]],[SEGMENT_VA+0x100,SEGMENT_VA+0x800])
        self.assertEqual(new[0x1000:0x1014],data[0x1000:0x1014])


if __name__ == '__main__': unittest.main()
