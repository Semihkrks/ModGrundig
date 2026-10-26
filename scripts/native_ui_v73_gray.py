"""Preserve the approved V7.1 mute shape; recolor its existing shared assets."""
import hashlib
import io
from PIL import Image, ImageDraw, ImageOps
from native_ui_v72_tv_pins import RECORDS

ICON = '08_APP/rc/ARimages/Grundig/volume/mute_icon.png'
BADGE = '08_APP/rc/ARimages/Grundig/volume/mute_button_grundig.png'
BACKGROUND = '08_APP/rc/ARimages/Grundig/modern/volume_muted_bg.png'
OLD_ICON_SHA = '703208975d4b1424f003a2998e89c164116968e47e6d05dac6551e3f38698696'
OLD_BADGE_SHA = '9facafe621ba0052c30c67650320d634dc3686ea921f1114a4a9b4055c607bb7'
PANEL_GRAY = 232
GLYPH_GRAY = 137


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def png(image, **options):
    stream = io.BytesIO()
    image.save(stream, format='PNG', compress_level=9, **options)
    return stream.getvalue()


def assets(old_icon, old_badge):
    if sha(old_icon) != OLD_ICON_SHA or sha(old_badge) != OLD_BADGE_SHA:
        raise ValueError('Approved icon or original badge identity differs')
    icon = Image.open(io.BytesIO(old_icon))
    if icon.mode != 'P' or icon.size != (100, 99):
        raise ValueError('Unexpected approved icon format')
    # Keep every palette index and alpha byte: only the RGB palette changes.
    # Blue dominance recovers the existing antialias coverage against the tile.
    palette = icon.getpalette()
    for i in range(0, len(palette), 3):
        r, g, b = palette[i:i + 3]
        coverage = max(0, min(1, (b - r) / 201)) if b > g else 0
        gray = round(PANEL_GRAY + coverage * (GLYPH_GRAY - PANEL_GRAY))
        palette[i:i + 3] = [gray] * 3
    icon.putpalette(palette)
    icon_bytes = png(icon, bits=8, transparency=icon.info['transparency'])
    original_button = Image.open(io.BytesIO(old_badge))
    if original_button.size != (85, 95) or original_button.mode != 'RGB':
        raise ValueError('Unexpected original standalone button format')
    button = Image.new('RGBA', original_button.size, (PANEL_GRAY,) * 3 + (255,))
    glyph = ImageOps.contain(icon.convert('RGBA'), button.size, Image.Resampling.LANCZOS)
    button.alpha_composite(glyph, ((85 - glyph.width) // 2, (95 - glyph.height) // 2))
    scale = 4
    panel = Image.new('RGBA', (68 * scale, 450 * scale), (PANEL_GRAY,) * 3 + (0,))
    ImageDraw.Draw(panel).rounded_rectangle((0, 0, panel.width - 1, panel.height - 1),
                                           radius=34 * scale, fill=(PANEL_GRAY,) * 3 + (255,))
    return {ICON: icon_bytes, BADGE: png(button.convert('RGB')),
            BACKGROUND: png(panel.resize((68, 450), Image.Resampling.LANCZOS))}


def apply(payloads, old_icon, old_badge):
    expected = {p: (digest, size) for p, _, digest, size in RECORDS}
    if payloads.keys() != expected.keys():
        raise ValueError('Expected exact thirteen-file V7.2 overlay')
    for path, raw in payloads.items():
        digest, size = expected[path]
        if len(raw) != size or sha(raw) != digest:
            raise ValueError('Pinned V7.2 input differs: ' + path)
    result = dict(payloads)
    result.update(assets(old_icon, old_badge))
    proof = dict(source='pinned V7.1 approved icon shape and original existing button',
                 changed_paths=[ICON, BADGE, BACKGROUND],
                 shared_normal_image_id=680, standalone_other_states_image_id=401,
                 muted_panel_image_id=2180, panel_gray=PANEL_GRAY, glyph_gray=GLYPH_GRAY,
                 icon_palette_indices_and_alpha_preserved=True,
                 native_bytes_unchanged_from_v72=True,
                 volume_zero_or_mute_selects_gray=True,
                 standalone_show_rule='Existing TimerEventHandler requires real IsMuted; zero alone does not create standalone badge',
                 evidence={'timer': '0xfb7aec', 'standalone_create': '0xdf8630',
                           'normal_image_call': '0xdf932c',
                           'other_image_calls': ['0xdf9350', '0xdf9374', '0xdf9398']},
                 television_tested=False)
    return result, proof
