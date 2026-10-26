
/* Analysis fragment only; external jumps/continuation are abstracted as exits. Not original
   standalone code. Original frame/GP context required. */

undefined4
Settings_fragment_exception_cleanup
          (uint boundary_a0,uint boundary_a1,uint boundary_a2,uint boundary_a3,
          byte *original_frame_context)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
                    /* catch() { ... } // from try @ 00566474 with catch @ 005792b8
                       catch() { ... } // from try @ 00566c2c with catch @ 005792b8
                       catch() { ... } // from try @ 00566c84 with catch @ 005792b8
                       catch() { ... } // from try @ 00566ce0 with catch @ 005792b8
                       catch() { ... } // from try @ 00566eb8 with catch @ 005792b8
                       catch() { ... } // from try @ 00566f10 with catch @ 005792b8
                       catch() { ... } // from try @ 00566f6c with catch @ 005792b8
                       catch() { ... } // from try @ 00567144 with catch @ 005792b8
                       catch() { ... } // from try @ 0056719c with catch @ 005792b8
                       catch() { ... } // from try @ 005671f8 with catch @ 005792b8
                       catch() { ... } // from try @ 005673d0 with catch @ 005792b8
                       catch() { ... } // from try @ 00567428 with catch @ 005792b8
                       catch() { ... } // from try @ 00567484 with catch @ 005792b8
                       catch() { ... } // from try @ 00567f1c with catch @ 005792b8
                       catch() { ... } // from try @ 0056802c with catch @ 005792b8 */
  *(uint *)(original_frame_context + 0x16c0) = boundary_a0;
  *(uint *)(original_frame_context + 0x16bc) = boundary_a1;
  uVar1 = *(undefined4 *)(original_frame_context + 0x16bc);
  uVar2 = *(undefined4 *)(original_frame_context + 0x16c0);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2dec))(original_frame_context + 0x124c);
  *(undefined4 *)(original_frame_context + 0x16c0) = uVar2;
  *(undefined4 *)(original_frame_context + 0x16bc) = uVar1;
  uVar1 = *(undefined4 *)(original_frame_context + 0x16bc);
  uVar2 = *(undefined4 *)(original_frame_context + 0x16c0);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x6a30))(original_frame_context + 0x1240);
  *(undefined4 *)(original_frame_context + 0x16c0) = uVar2;
  *(undefined4 *)(original_frame_context + 0x16bc) = uVar1;
  uVar1 = *(undefined4 *)(original_frame_context + 0x16bc);
  uVar2 = *(undefined4 *)(original_frame_context + 0x16c0);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x6a30))(original_frame_context + 0x11f4);
  *(undefined4 *)(original_frame_context + 0x16c0) = uVar2;
  *(undefined4 *)(original_frame_context + 0x16bc) = uVar1;
                    /* WARNING: Subroutine does not return */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3184))();
}

