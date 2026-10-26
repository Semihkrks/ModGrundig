
/* Analysis fragment only; external jumps/continuation are abstracted as exits. Not original
   standalone code. Original frame/GP context required. */

undefined4
Settings_fragment_antenna_initial
          (uint boundary_a0,uint boundary_a1,uint boundary_a2,uint boundary_a3,
          byte *original_frame_context)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uStack00000010;
  
  *(undefined4 *)(original_frame_context + 0x1674) =
       *(undefined4 *)(original_frame_context + 0x16e4);
  if (*(int *)(original_frame_context + 0x1674) == 0) {
    original_frame_context[0x1678] = 0;
    original_frame_context[0x1679] = 0;
    original_frame_context[0x167a] = 0;
    original_frame_context[0x167b] = 0;
  }
  else {
    uVar2 = __dynamic_cast(*(undefined4 *)(original_frame_context + 0x1674),&MMainFrame::typeinfo,
                           &AntennaSettingsFrame::typeinfo,0);
    *(undefined4 *)(original_frame_context + 0x1678) = uVar2;
  }
  *(undefined4 *)(original_frame_context + 0xf8) = *(undefined4 *)(original_frame_context + 0x1678);
  if (*(int *)(original_frame_context + 0xf8) == 0) {
    return 0;
  }
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x180) + 0x3c))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x180),
             *(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1a0));
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x180) + 0x3c))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x180),
             *(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1a4));
  uStack00000010 = 0x31;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1220,0x10f,0x1c,0x545);
  uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x1670) = uVar2;
  uStack00000010 = 100;
                    /* try { // try from 00562fdc to 00562fe3 has its CatchHandler @ 00563004 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x1670),
             *(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x180),
             original_frame_context + 0x1220,0);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0xf4) = *(undefined4 *)(original_frame_context + 0x1670);
  if (*(int *)(original_frame_context + 0xf4) != 0) {
    *(undefined1 *)(*(int *)(original_frame_context + 0xf4) + 0x3a) = 1;
    *(undefined1 *)(*(int *)(original_frame_context + 0xf4) + 0x38) = 0;
    uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45f5);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xf4) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45f5);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xf4) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45f5);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xf4) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45f5);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xf4) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45f9);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xf4) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45f9);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xf4) + 0xa6) = uVar1;
    (**(code **)(iVar3 + -0x910))(*(int *)(original_frame_context + 0xf4) + 0xb8,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0xf4) + 0xcc,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0xf4) + 0xe0,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0xf4) + 0xf4,0x5cd);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x180) + 0x34))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x180),
               *(undefined4 *)(original_frame_context + 0xf4));
    (**(code **)(**(int **)(original_frame_context + 0xf4) + 0x34))
              (*(undefined4 *)(original_frame_context + 0xf4),
               *(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1a0));
    (**(code **)(**(int **)(original_frame_context + 0xf4) + 0x34))
              (*(undefined4 *)(original_frame_context + 0xf4),
               *(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1a4));
    uStack00000010 = 0x31;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1220,0x429,0,0x11e);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x1a0) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1a0),
               *(undefined4 *)(original_frame_context + 0x1220),
               *(undefined4 *)(original_frame_context + 0x1224),original_frame_context + 0x1220);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x1d4) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1d4),0,0,
               original_frame_context + 0x1220);
    uStack00000010 = 0x31;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1220,0,0,0x91);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x1cc) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1cc),
               *(undefined4 *)(original_frame_context + 0x1220),
               *(undefined4 *)(original_frame_context + 0x1224),original_frame_context + 0x1220);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf8) + 0x1cc) + 0x128) = 0x24;
    uStack00000010 = 0x31;
    (**(code **)(iVar3 + -0x2b00))(original_frame_context + 0x1220,0x91,0,0x23);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x1d0) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1d0),
               *(undefined4 *)(original_frame_context + 0x1220),
               *(undefined4 *)(original_frame_context + 0x1224),original_frame_context + 0x1220);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf8) + 0x1d0) + 0x128) = 0x24;
    uStack00000010 = 0x31;
    (**(code **)(iVar3 + -0x2b00))(original_frame_context + 0x1220,0x30d,0,0x11e);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x1a4) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1a4),
               *(undefined4 *)(original_frame_context + 0x1220),
               *(undefined4 *)(original_frame_context + 0x1224),original_frame_context + 0x1220);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x1e0) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1e0),0,0,
               original_frame_context + 0x1220);
    uStack00000010 = 0x31;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1220,0,0,0x91);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x1d8) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1d8),
               *(undefined4 *)(original_frame_context + 0x1220),
               *(undefined4 *)(original_frame_context + 0x1224),original_frame_context + 0x1220);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf8) + 0x1d8) + 0x128) = 0x24;
    uStack00000010 = 0x31;
    (**(code **)(iVar3 + -0x2b00))(original_frame_context + 0x1220,0x91,0,0x23);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x1dc) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1dc),
               *(undefined4 *)(original_frame_context + 0x1220),
               *(undefined4 *)(original_frame_context + 0x1224),original_frame_context + 0x1220);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf8) + 0x1dc) + 0x128) = 0x24;
    (**(code **)(iVar3 + -0x72a8))(*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x194))
    ;
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x72a8))
                      (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x198));
    return uVar2;
  }
  (**(code **)(iVar3 + -0x2400))
            (*(int *)(iVar3 + -0x7fdc) + 0x7b18,*(int *)(iVar3 + -0x7fdc) + 0x7b34,
             *(int *)(iVar3 + -0x7fdc) + 0x7cf8,0x73e);
                    /* WARNING: Subroutine does not return */
  (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
}

