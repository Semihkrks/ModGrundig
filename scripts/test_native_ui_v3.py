"""Guarded numeric/style patch checks, no whole firmware execution."""
import struct
import unittest
from pathlib import Path
from unittest.mock import patch
import build_native_ui_v3 as p
import build_native_volume_patch as volume


class V3Tests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.num=(volume.SOURCE/volume.NUM_REL).read_bytes()
        cls.elf=(volume.SOURCE/volume.ELF_REL).read_bytes()
        cls.new_num,cls.new_elf,cls.proof=p.construct(cls.num,cls.elf)

    def test_exact_original_hashes_and_file_lengths(self):
        self.assertEqual(volume.sha(self.num),volume.NUM_SHA)
        self.assertEqual(volume.sha(self.elf),volume.ELF_SHA)
        self.assertEqual(len(self.num),len(self.new_num))
        self.assertEqual(len(self.elf),len(self.new_elf))

    def test_previous_volume_patch_is_preserved(self):
        self.assertEqual(self.new_elf[volume.PATCH_OFF:volume.PATCH_OFF+len(volume.NEW)],volume.NEW)
        for rid,_,new,*_ in volume.NUM_PATCHES:
            self.assertEqual(struct.unpack_from('<I',self.new_num,56+4*rid)[0],new)

    def test_number_rects_fit_and_leave_video_uncovered(self):
        value=lambda rid:struct.unpack_from('<I',self.new_num,56+4*rid)[0]
        self.assertEqual(value(0x990),1920)
        self.assertEqual(value(0x995)+value(0x994),1848)
        self.assertLessEqual(value(0x996)+value(0x993),value(0x98f))
        self.assertGreaterEqual(value(0x999),value(0x995))
        self.assertGreaterEqual(value(0x99a),value(0x996))
        self.assertLessEqual(value(0x999)+value(0x998),value(0x995)+value(0x994))
        self.assertLessEqual(value(0x99a)+value(0x997),value(0x996)+value(0x993))
        self.assertEqual(value(0x321e),48)

    def test_no_instruction_outside_selected_windows_changed(self):
        allowed=set(range(volume.PATCH_OFF,volume.PATCH_OFF+len(volume.NEW)))
        for row in self.proof['code_records']:allowed.update(range(row['file_offset'],row['file_offset']+4))
        self.assertTrue(set(volume.changed_offsets(self.elf,self.new_elf))<=allowed)
        scalar_allowed=set()
        for rid,*_ in volume.NUM_PATCHES+p.NUM_PATCHES:scalar_allowed.update(range(56+4*rid,60+4*rid))
        self.assertTrue(set(volume.changed_offsets(self.num,self.new_num))<=scalar_allowed)

    def test_local_argument_instructions_with_cpu(self):
        from unicorn import Uc,UC_ARCH_MIPS,UC_MODE_MIPS32,UC_MODE_LITTLE_ENDIAN
        from unicorn.mips_const import UC_MIPS_REG_A0,UC_MIPS_REG_A1,UC_MIPS_REG_A2,UC_MIPS_REG_A3,UC_MIPS_REG_GP
        for row in self.proof['code_records']:
            mu=Uc(UC_ARCH_MIPS,UC_MODE_MIPS32|UC_MODE_LITTLE_ENDIAN)
            mu.mem_map(0x1000,0x1000)
            code=self.new_elf[row['file_offset']:row['file_offset']+4]
            mu.mem_write(0x1000,code)
            registers=(UC_MIPS_REG_A0,UC_MIPS_REG_A1,UC_MIPS_REG_A2,UC_MIPS_REG_A3,UC_MIPS_REG_GP)
            for reg in registers:mu.reg_write(reg,0x123456)
            mu.emu_start(0x1000,0x1004,count=1)
            changed=UC_MIPS_REG_A3 if row['role'].startswith('speaker') else UC_MIPS_REG_A0
            self.assertEqual(mu.reg_read(changed),int(row['new_word'],16)&0xffff)
            for reg in registers:
                if reg!=changed:self.assertEqual(mu.reg_read(reg),0x123456)

    def test_bad_source_is_rejected(self):
        bad=bytearray(self.elf);bad[-1]^=1
        with self.assertRaises(ValueError):p.construct(self.num,bytes(bad))

    def test_full_overlay_paths_and_hashes(self):
        rows=p.verified_records()
        self.assertEqual(len(rows),22)
        self.assertEqual(len({r['path'] for r in rows}),22)
        self.assertTrue(any(r['candidate_sha256']==p.CAPSULE_SHA for r in rows))

    def test_output_boundary_is_not_redefined_by_out_variable(self):
        with patch.object(p,'OUT',p.ROOT/'analiz/outside-v3'):
            with self.assertRaises(ValueError):p.output_guard(p.OUT/'manifest.json')
        with self.assertRaises(ValueError):p.output_guard(p.ROOT/'README.md')


if __name__=='__main__':unittest.main()
