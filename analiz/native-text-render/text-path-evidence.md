# Native text path: actionable rehosting evidence

Date: 2026-10-24. Source is the original `07_MSLIB/libmuf.so`, SHA256 `494d4aa45a3c8d8e10760388d8d30111e9127a0357d38cdf97979b9f9bb16d96`.

This report is **static evidence** derived from retained direct Ghidra C, assembly and resource bytes. It is not REA Evidence and does not itself claim execution. Six functions in `ui-targeted/text-render6` and three in `text-small3` decompiled completely. Renderer execution is tracked separately by `native_frame_rehost.py`.

## Smallest usable native text loop

`MWidget::DrawString` at **0x2e24de4c**, 2,400 bytes / 600 selected instructions, implements the overload with a control map. See `analiz/native/ui-targeted/text-small3/2e24de4c.{c,json}`. Its empty-map path is substantially smaller to rehost than `DrawSingleLine` at 0x2e255bd4, which also performs preprocessing, iconv and language-dependent ICU layout.

MIPS o32 entry arguments, checked against loads after the `sp -= 0x118` prologue:

| Location | Meaning |
|---|---|
| a0 | Widget object |
| a1 | DirectFB surface interface |
| a2 | DirectFB font interface |
| a3 | NUL-terminated UTF-8 input |
| incoming sp+16 | Byte length, excluding final NUL |
| incoming sp+20 | Pointer to mutable x |
| incoming sp+24 | Pointer to mutable y |
| incoming sp+28 | Surface text flags |
| incoming sp+32 | Starting control offset, u16 |
| incoming sp+36 | Control map object, whose +8 root pointer is zero when empty |

For ASCII digits, an empty map, visual state zero and font orientation `u16(widget+0x138)=5`, the routine copies input bytes into its own allocated buffer and forwards them to the DirectFB DrawString callback. It restores the original x on return. No ICU/iconv or STL tree traversal is required on this selected path.

| Callsite | External boundary |
|---|---|
| 0x2e24dec0 | QueryVisualState |
| 0x2e24df10 | nothrow operator new[], length+2 |
| 0x2e24e448 | QueryVisualState before final draw |
| 0x2e24e610 | Surface DrawString, interface+0xbc |
| 0x2e24e0e0 | operator delete[] |

Other branches have additional callbacks and must fail closed if reached without a model. The orientation value 5 is a **selected rehost state**, not independently observed constructor output in this investigation. Non-5 orientation selects the transformed surface callback at +0xfc.

## Actual alignment arithmetic

`MWidget::CalculateTextDrawFlags`, **0x2e24fe3c**, retained C/assembly in `text-render6/2e24fe3c.{c,json}`:

Arguments are a0=widget, a1=rectangle, a2=alignment, a3=font height, incoming sp+16=x output pointer, +20=y output pointer, +24=flags output pointer. The only computed callsite is QueryVisualState at **0x2e24fedc**.

The retained Ghidra JSON enumerates only 69 instructions and omits the reachable bottom-center block **0x2e24ffa0–0x2e24ffd4 inclusive, 14 instructions**, although its decompiled C describes that case. The render implementation checks these instructions against the pinned original ELF and explicitly adds the bounded block to its execution allowlist. This is an analysis-enumeration gap, not a firmware instruction patch.

For volume alignment 0x22: x=rect.x+width/2, y=rect.y+(height-fontHeight)/2, flags=5 (center/top). For numeric alignment 0x42: x=rect.x+width/2, y=rect.y+height, flags=9 (center/bottom). Division is signed MIPS arithmetic rounding toward zero. Orientation other than 5 adds flag 0x20.

`DrawSingleLine` **0x2e255bd4**, retained C around lines 310–340, obtains the font through GetDFBFont, calls font interface **+0x18 GetHeight**, calculates alignment, calls surface **+0xb4 SetFont** and **+0x54 SetColor**. Therefore the requested font size must not automatically be called the measured font height. A Pillow/FreeType replacement of font metrics/rasterization remains a host dependency boundary.

## Real resources and widget placement

Image resource table entries, rather than the unused font resource table, resolve the fonts. `MResourceManager::GetDFBFont` **0x2e23a030** explicitly calls `GetRcEngine::RcGetImage`. Resource table SHA256 is `d6b1b9fde60c9cc4624f264a8e75da4245e6fb3e9dab7534ddce01706fbcd2f3`.

| Widget | Font resource and file | Requested height | Alignment | Padding |
|---|---|---|---|---|
| Volume number, frame+0x1ac | ID 0x4ae, `08_APP/rc/font/DINPro-CondMedium.otf` | Num 0x3215 = 36 | 0x22 | Num0x45dd=0 |
| Numeric channel entry, frame+0x188 | ID 0x4af, `08_APP/rc/font/Lucida Sans Bold.ttf` | Num0x321e=48 | 0x42 | Num0x45f5=3 on each edge |

Font hashes:

- DINPro-CondMedium.otf: `1e00616ed6d74da0eb3105683da02722e697c52f4a7461c1d0bd891ae344aa75`.
- Lucida Sans Bold.ttf: `347e36d73e5db9b791c4ad385e391bf6fceeb0e17e830634d5fe35ca7da5f0bb`.

Volume constructor body retained at `analiz/native/ui-targeted/dvbt_board/00fb9780.c`, lines 490–565, gives the actual number parent as **frame+0x1a4, the panel**, both in TextBox construction and AddChild. Speaker frame+0x1a8 and track frame+0x1b0 are also panel children. Their absolute position therefore includes the panel offset; adding only the frame+0x184 root offset misses the panel y=20 offset. Volume number background drawing is disabled with byte+0x39=0, its color is Color0x25, its font slots are +0x130/+0x13c/+0x148/+0x154 and requested height slots +0x13a/+0x146/+0x152/+0x15e. Its stored alignment is +0x128.

Numeric constructor **0x00895b84**, `analiz/native/ui-four/channels/numeric-v1/00895b84.c`, lines 174–198, sets font0x4af, height48 and alignment0x42. `DrawSingleLine` applies 3px padding before calculating text placement, producing center x=w/2 and bottom y=h-3 in local widget coordinates. Numeric background and text are sibling children of the root frame+0x180. V3 patches change numeric background Color0x12→0x5e and text Color0x5e→0, tracked separately in the v3 manifest.

## Remaining limits

- TextBox::Update **0x2e281f14** chooses DrawSingleLine or DrawMultipleLines using widget byte+0x17e; it also checks visible flag2 and nonzero dimensions. Calling the selected DrawString directly does not validate the complete event/update lifecycle.
- The retained TextBox constructor **0x2e282068** calls the MWidget base constructor and assigns its vtable; this report does not establish all base defaults.
- Arabic/Thai shaping, multiline text, marquee, clipping, rasterizer pixel equivalence, television scaling and video-plane composition remain unvalidated.
- The full application startup and actual tuner/decoder pipeline are separate from these text routines.
