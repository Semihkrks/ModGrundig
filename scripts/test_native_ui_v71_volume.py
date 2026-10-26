"""Pinned input, real local instruction, draw-path and containment regressions."""
import io
from pathlib import Path
import struct
import sys
import unittest

from PIL import Image

import native_ui_v71_volume as fix

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools/native-volume-venv/Lib/site-packages'))


def base_payloads():
    return {path: (ROOT / 'analiz/native-ui-candidate/v7-tv/overlay' / path).read_bytes()
            for path, *_ in fix.RECORDS}


def constructor_probe(elf):
    """Bounded local UI instructions with synthetic color callback, no process.

    Executes0xfbb548..0xfbb564 only. No real service/library/update/device
    function is invoked. The callback stresses volatile a0 after the delay slot.
    """
    import unicorn as u
    from unicorn import mips_const as m
    uc = u.Uc(u.UC_ARCH_MIPS, u.UC_MODE_MIPS32 | u.UC_MODE_LITTLE_ENDIAN)
    for start, size in ((0xFBB000, 0x1000), (0x10000000, 0x10000),
                        (0x20000000, 0x10000), (0x30000000, 0x1000)):
        uc.mem_map(start, size)
    uc.mem_write(0xFBB000, elf[fix.elf_va_offset(elf, 0xFBB000, 0x1000):][:0x1000])
    uc.mem_write(0x30000000, bytes.fromhex('0800e00300000000'))  # synthetic jr ra/nop
    fp, frame, panel, gp = 0x20000000, 0x20002000, 0x20004000, 0x10008000
    for addr, value in ((fp + 0x130, frame), (frame + 0x1A4, panel),
                        (gp - 0x5868, 0x30000000), (fp + 0x20, gp)):
        uc.mem_write(addr, struct.pack('<I', value))
    uc.mem_write(panel, b'\xA5' * 0x100)
    uc.mem_write(panel + 0x39, b'\x01\x00')
    uc.reg_write(m.UC_MIPS_REG_FP, fp)
    uc.reg_write(m.UC_MIPS_REG_GP, gp)
    calls, visited = [], []

    def hook(machine, address, _size, _data):
        visited.append(address)
        if address == 0x30000000:
            calls.append(dict(argument=machine.reg_read(m.UC_MIPS_REG_A0),
                              flag_at_callback=machine.mem_read(panel + 0x3A, 1)[0]))
            machine.reg_write(m.UC_MIPS_REG_V0, 0xFFF5F5F5)
            machine.reg_write(m.UC_MIPS_REG_A0, 0xDEADBEEF)
        elif address == 0xFBB568:
            machine.emu_stop()
    uc.hook_add(u.UC_HOOK_CODE, hook)
    uc.emu_start(0xFBB548, 0xFBB568, count=32)
    memory = bytes(uc.mem_read(panel, 0x100))
    return dict(flag=memory[0x3A], color=struct.unpack_from('<I', memory, 0x4C)[0],
                calls=calls, visited=[hex(x) for x in visited],
                changed_panel_offsets=[i for i, value in enumerate(memory)
                                       if value != (1 if i == 0x39 else 0 if i == 0x3A else 0xA5)],
                process_or_hardware_executed=False)


def render_probe(payloads):
    """Derive image mode from the patched instructions, then use real MUF draw."""
    from native_frame_rehost import NativePainter
    state = constructor_probe(payloads[fix.ELF])
    painter = NativePainter()
    geometry = fix.layout(payloads[fix.NUM])['panel']
    # MMainFrame stores outer xy then zeros client xy; this canvas models
    # logical screen position by adding the outer window position explicitly.
    geometry = list(geometry)
    geometry[0] += struct.unpack_from('<I', payloads[fix.NUM], 56 + 0x5BF0 * 4)[0]
    geometry[1] += struct.unpack_from('<I', payloads[fix.NUM], 56 + 0x5BF1 * 4)[0]
    image = Image.open(io.BytesIO(payloads[fix.BACKGROUND])).convert('RGBA')
    painter.paint('actual panel flag derived from local OnCreate instructions', geometry,
                  image=image if state['flag'] == 1 else None, color=state['color'])
    return painter.canvas, painter.evidence(), state


class VolumeV71Tests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.base = base_payloads()
        cls.new, cls.proof = fix.apply(cls.base)

    def test_input_is_unchanged_and_only_three_files_change(self):
        self.assertEqual(self.base, base_payloads())
        self.assertEqual(set(k for k in self.base if self.base[k] != self.new[k]),
                         {fix.ELF, fix.NUM, fix.BACKGROUND})
        self.assertIsNot(self.base, self.new)

    def test_every_input_is_pinned_and_unknown_paths_are_rejected(self):
        for path in self.base:
            with self.subTest(path=path):
                modified = dict(self.base)
                raw = bytearray(modified[path]); raw[-1] ^= 1
                modified[path] = bytes(raw)
                with self.assertRaises(ValueError):
                    fix.apply(modified)
        with self.assertRaises(ValueError):
            fix.apply({**self.base, '08_APP/unreviewed': b'x'})
        with self.assertRaises(ValueError):
            fix.apply(self.new)

    def test_only_volume_root_position_resources_change(self):
        a, b = self.base[fix.NUM], self.new[fix.NUM]
        changed = [i for i in range((len(a) - 56) // 4)
                   if a[56 + i * 4:60 + i * 4] != b[56 + i * 4:60 + i * 4]]
        self.assertEqual(changed, [0x5A41, 0x5A42])
        self.assertEqual(a[56 + 0x98F * 4:60 + 0x99A * 4],
                         b[56 + 0x98F * 4:60 + 0x99A * 4])

    def test_elf_patch_is_two_constructor_words_and_all_handlers_stay_identical(self):
        a, b = self.base[fix.ELF], self.new[fix.ELF]
        changed_words = [i for i in range(0, len(a) - 3, 4) if a[i:i + 4] != b[i:i + 4]]
        self.assertEqual(changed_words, [fix.elf_va_offset(a, va, 4) for va, *_ in fix.CODE_PATCHES])
        for va, old, new, _ in fix.CODE_PATCHES:
            off = fix.elf_va_offset(a, va, 4)
            self.assertEqual(struct.unpack_from('<I', a, off)[0], old)
            self.assertEqual(struct.unpack_from('<I', b, off)[0], new)

    def test_real_delay_slot_sets_only_panel_flag_and_preserves_color_store(self):
        before = constructor_probe(self.base[fix.ELF])
        after = constructor_probe(self.new[fix.ELF])
        self.assertEqual(before['flag'], 0)
        self.assertEqual(before['calls'], [dict(argument=94, flag_at_callback=0)])
        self.assertEqual(after['flag'], 1)
        self.assertEqual(after['calls'], [dict(argument=1, flag_at_callback=1)])
        self.assertEqual(before['color'], after['color'])
        self.assertEqual(set(after['changed_panel_offsets']), {0x3A, 0x4C, 0x4D, 0x4E, 0x4F})

    def test_safe_margin_and_child_containment(self):
        before, after = self.proof['before_geometry'], self.proof['after_geometry']
        self.assertEqual(after['root'], [80, 126, 68, 490])
        self.assertEqual(after['panel'], [80, 146, 68, 450])
        for name in ('panel', 'speaker', 'number', 'track'):
            self.assertEqual(after[name][0] - before[name][0], 80)
            self.assertEqual(after[name][1] - before[name][1], -24)
            self.assertEqual(after[name][2:], before[name][2:])
        x, y, w, h = after['panel']
        for name in ('speaker', 'number', 'track'):
            cx, cy, cw, ch = after[name]
            self.assertGreaterEqual(cx, x); self.assertGreaterEqual(cy, y)
            self.assertLessEqual(cx + cw, x + w); self.assertLessEqual(cy + ch, y + h)
        # Logical scaling expectation only, never a claim of active TV mode.
        self.assertEqual(80 * 1280 // 1920, 53)
        outer = [struct.unpack_from('<I', self.new[fix.NUM], 56 + rid * 4)[0]
                 for rid in (0x5BF0, 0x5BF1, 0x5BEF, 0x5BEE)]
        self.assertEqual(outer, [0, 160, 160, 725])
        rx, ry, rw, rh = after['root']
        self.assertLessEqual(rx + rw, outer[2])
        self.assertLessEqual(ry + rh, outer[3])

    def test_exact_size_rgba_capsule_has_transparent_corners_and_opaque_center(self):
        raw = self.new[fix.BACKGROUND]
        self.assertEqual(raw[25], 6)  # PNG IHDR explicit RGBA, no palette/tRNS dependency.
        image = Image.open(io.BytesIO(raw))
        self.assertEqual((image.mode, image.size), ('RGBA', (68, 450)))
        for xy in ((0, 0), (67, 0), (0, 449), (67, 449), (0, 10), (67, 439)):
            self.assertEqual(image.getpixel(xy)[3], 0)
        for xy in ((34, 0), (34, 449), (0, 225), (67, 225), (34, 225)):
            self.assertEqual(image.getpixel(xy)[3], 255)
        self.assertTrue(any(image.getchannel('A').histogram()[1:255]))

    def test_real_muf_draw_selects_fill_before_and_image_after(self):
        _old, before, oldstate = render_probe(self.base)
        canvas, after, state = render_probe(self.new)
        oldcalls = [r['boundary'] for r in before['callbacks']]
        calls = [r['boundary'] for r in after['callbacks']]
        self.assertIn('FillRectangle', oldcalls)
        self.assertNotIn('StretchBlit', oldcalls)
        self.assertIn('StretchBlit', calls)
        self.assertNotIn('FillRectangle', calls)
        self.assertEqual((oldstate['flag'], state['flag']), (0, 1))
        x, y, w, h = fix.layout(self.new[fix.NUM])['panel']
        y += 160  # outer window origin, proven by MMainFrame constructor.
        # NativePainter canvas has opaque test-video background. Compare to a
        # distant pixel instead of treating this host canvas as raw OSD alpha.
        background = canvas.getpixel((0, 0))
        self.assertEqual(canvas.getpixel((x, y)), background)
        self.assertNotEqual(canvas.getpixel((x + w // 2, y + h // 2)), background)


if __name__ == '__main__':
    unittest.main()
