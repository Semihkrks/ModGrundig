"""V7.1-based visual candidate with explicit post-virtual-call GP recovery."""
import hashlib
import struct
from native_ui_v71_tv_pins import RECORDS
from build_native_volume_patch import elf_va_offset, verify_allowlist
from native_ui_v72_mute import START, END, BLOCK_SHA
from native_ui_v74_native import block, NORMAL_COLOR, MUTED_COLOR, FIELDS
from native_ui_v73_gray import assets, ICON, BADGE as OLD_BUTTON, BACKGROUND
from native_ui_v74_badge import (badge_png, BADGE, BADGE_ID, ICON_PATCHES,
                                 SHADOW_PATCHES, NUM_PATCHES)

ELF = '08_APP/bin/dvbt_board'
NUM = '08_APP/rc/rc/bin/Num_res.bin'
IMAGE = '08_APP/rc/rc/bin/Image_res.bin'


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def apply(payloads, original_button):
    expected = {p: (digest, size) for p, _, digest, size in RECORDS}
    if payloads.keys() != expected.keys():
        raise ValueError('Expected exact twelve-file device-tested V7.1 overlay')
    for path, raw in payloads.items():
        digest, size = expected[path]
        if not isinstance(raw, bytes) or len(raw) != size or sha(raw) != digest:
            raise ValueError('V7.1 pin mismatch: ' + path)
    result = dict(payloads)
    gray_assets = assets(payloads[ICON], original_button)
    for path in (ICON, BACKGROUND):
        result[path] = gray_assets[path]
    result[BADGE] = badge_png()
    original = payloads[ELF]
    off = elf_va_offset(original, START, END - START)
    if sha(original[off:off + END - START]) != BLOCK_SHA:
        raise ValueError('V7.1 original selection block differs')
    native = block()
    if len(native) != END - START or struct.unpack_from('<I', native)[0] != 0x8fdc0018:
        raise ValueError('Required post-MoveRect GP restore missing')
    patched = bytearray(original)
    patched[off:off + END - START] = native
    allowed = set(range(off, off + END - START))
    targets = [(va, old, BADGE_ID) for va, old in ICON_PATCHES]
    targets += [(va, rid, 1485) for rid, addresses in SHADOW_PATCHES for va in addresses]
    code = []
    for va, old_id, new_id in targets:
        at = elf_va_offset(original, va, 4)
        old_word, new_word = 0x24050000 | old_id, 0x24050000 | new_id
        if struct.unpack_from('<I', original, at)[0] != old_word:
            raise ValueError('Original standalone image instruction differs')
        if struct.unpack_from('<I', original, at + 8)[0] != 0x0320f809:
            raise ValueError('Original MImgSet call differs')
        struct.pack_into('<I', patched, at, new_word)
        allowed.update(range(at, at + 4))
        code.append(dict(va=hex(va), old=hex(old_word), new=hex(new_word)))
    result[ELF] = bytes(patched)
    verify_allowlist(original, result[ELF], allowed)
    nums = bytearray(payloads[NUM])
    for rid, old, new in NUM_PATCHES:
        at = 56 + rid * 4
        if struct.unpack_from('<I', nums, at)[0] != old:
            raise ValueError('Original standalone geometry differs')
        struct.pack_into('<I', nums, at, new)
    result[NUM] = bytes(nums)
    table = payloads[IMAGE]
    header = struct.unpack_from('<14I', table)
    if header[1] != len(table) or header[7] != 2180 or header[4] != 2180 * 4:
        raise ValueError('Unexpected V7.1 image table')
    table = bytearray(table)
    for path in (b'../rc/ARimages/Grundig/modern/volume_muted_bg.png\0',
                 b'../rc/ARimages/Grundig/modern/mute_badge.png\0'):
        table += struct.pack('<I', len(path)) + path
    for at, value in ((4, len(table)), (16, 2182 * 4), (28, 2182)):
        struct.pack_into('<I', table, at, value)
    result[IMAGE] = bytes(table)
    proof = dict(source_revision='v7.1-tv', source_user_reports_working=True,
        prior_v73_user_reports_freeze=True,
        defect='V72/V73 removed GP restore following virtual MoveRect before GOT loads',
        required_gp_restore_va=hex(START), required_gp_word='0x8fdc0018',
        native_span=[hex(START), hex(END)], native_block_sha256=sha(native),
        normal_fill=hex(NORMAL_COLOR), muted_fill=hex(MUTED_COLOR),
        fill_fields=[hex(f) for f in FIELDS],
        standalone_code=code,
        standalone_num=[dict(id=hex(i), old=a, new=b) for i, a, b in NUM_PATCHES],
        standalone_outer=[1728, 19, 160, 230], standalone_icon=[1784, 74, 52, 52],
        right_margin=84, top_margin=74, white_badge_id=2181,
        legacy_shadows_null_id=1485, base_overlay_files=12, output_overlay_files=14,
        original_button_not_overlaid=True,
        limits=['Static and bounded instruction tests do not prove physical TV behavior',
                'No device crash dump; GP defect reproduces invalid access and fits reported symptom',
                'CSS numeric-popup badge relocation is not installed',
                'Existing real IsMuted predicate still governs standalone lifecycle'],
        television_tested=False, flash_ready=False)
    return result, proof
