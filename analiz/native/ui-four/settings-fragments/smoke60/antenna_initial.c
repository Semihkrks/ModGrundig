
/* Analysis fragment only; external jumps/continuation are abstracted as exits. Not original
   standalone code. Original frame/GP context required. */

undefined4
Settings_fragment_antenna_initial
          (uint boundary_a0,uint boundary_a1,uint boundary_a2,uint boundary_a3,
          byte *original_frame_context)

{
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  byte *pbStack00000010;
  
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
  pbStack00000010 = (byte *)0x31;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1220,0x10f,0x1c,0x545);
  uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x1670) = uVar2;
  pbStack00000010 = (byte *)0x64;
                    /* try { // try from 00562fdc to 00562fe3 has its CatchHandler @ 00563004 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x1670),
             *(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x180),
             original_frame_context + 0x1220,0);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0xf4) = *(undefined4 *)(original_frame_context + 0x1670);
  if (*(int *)(original_frame_context + 0xf4) == 0) {
    (**(code **)(iVar7 + -0x2400))
              (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
               *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0x73e);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0xf4) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0xf4) + 0x38) = 0;
  uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0xf4) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0xf4) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0xf4) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0xf4) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0xf4) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0xf4) + 0xa6) = uVar1;
  (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0xf4) + 0xb8,0x5cd);
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
  pbStack00000010 = (byte *)0x31;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1220,0x429,0,0x11e);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x1a0) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1a0),
             *(undefined4 *)(original_frame_context + 0x1220),
             *(undefined4 *)(original_frame_context + 0x1224),original_frame_context + 0x1220);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x1d4) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1d4),0,0,
             original_frame_context + 0x1220);
  pbStack00000010 = (byte *)0x31;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1220,0,0,0x91);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x1cc) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1cc),
             *(undefined4 *)(original_frame_context + 0x1220),
             *(undefined4 *)(original_frame_context + 0x1224),original_frame_context + 0x1220);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf8) + 0x1cc) + 0x128) = 0x24;
  pbStack00000010 = (byte *)0x31;
  (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x1220,0x91,0,0x23);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x1d0) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1d0),
             *(undefined4 *)(original_frame_context + 0x1220),
             *(undefined4 *)(original_frame_context + 0x1224),original_frame_context + 0x1220);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf8) + 0x1d0) + 0x128) = 0x24;
  pbStack00000010 = (byte *)0x31;
  (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x1220,0x30d,0,0x11e);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x1a4) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1a4),
             *(undefined4 *)(original_frame_context + 0x1220),
             *(undefined4 *)(original_frame_context + 0x1224),original_frame_context + 0x1220);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x1e0) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1e0),0,0,
             original_frame_context + 0x1220);
  pbStack00000010 = (byte *)0x31;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1220,0,0,0x91);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x1d8) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1d8),
             *(undefined4 *)(original_frame_context + 0x1220),
             *(undefined4 *)(original_frame_context + 0x1224),original_frame_context + 0x1220);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf8) + 0x1d8) + 0x128) = 0x24;
  pbStack00000010 = (byte *)0x31;
  (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x1220,0x91,0,0x23);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf8) + 0x1dc) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x1dc),
             *(undefined4 *)(original_frame_context + 0x1220),
             *(undefined4 *)(original_frame_context + 0x1224),original_frame_context + 0x1220);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf8) + 0x1dc) + 0x128) = 0x24;
  (**(code **)(iVar7 + -0x72a8))(*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x194));
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x72a8))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf8) + 0x198));
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x1668) =
       *(undefined4 *)(original_frame_context + 0x16e4);
  if (*(int *)(original_frame_context + 0x1668) == 0) {
    original_frame_context[0x166c] = 0;
    original_frame_context[0x166d] = 0;
    original_frame_context[0x166e] = 0;
    original_frame_context[0x166f] = 0;
  }
  else {
    uVar2 = (**(code **)(iVar7 + -0x598c))
                      (*(undefined4 *)(original_frame_context + 0x1668),
                       *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x6228),0);
    *(undefined4 *)(original_frame_context + 0x166c) = uVar2;
  }
  *(undefined4 *)(original_frame_context + 0xf0) = *(undefined4 *)(original_frame_context + 0x166c);
  if (*(int *)(original_frame_context + 0xf0) == 0) {
    return 0;
  }
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 400) + 0x3c))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 400),
             *(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x1ec));
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 400) + 0x3c))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 400),
             *(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x1e8));
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 400) + 0x3c))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 400),
             *(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x1f0));
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 400) + 0x3c))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 400),
             *(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 500));
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 400) + 0x3c))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 400),
             *(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x1f8));
  pbStack00000010 = (byte *)0x31;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1230,0x10f,0x1c,0x545);
  uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x1664) = uVar2;
  pbStack00000010 = (byte *)0x64;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x1664),
             *(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 400),
             original_frame_context + 0x1230,0);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0xec) = *(undefined4 *)(original_frame_context + 0x1664);
  if (*(int *)(original_frame_context + 0xec) == 0) {
    (**(code **)(iVar7 + -0x2400))
              (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
               *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0x775);
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
    return uVar2;
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0xec) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0xec) + 0x38) = 0;
  uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0xec) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0xec) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0xec) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0xec) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0xec) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0xec) + 0xa6) = uVar1;
  (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0xec) + 0xb8,0x5cd);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0xec) + 0xcc,0x5cd);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0xec) + 0xe0,0x5cd);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0xec) + 0xf4,0x5cd);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 400) + 0x34))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 400),
             *(undefined4 *)(original_frame_context + 0xec));
  (**(code **)(**(int **)(original_frame_context + 0xec) + 0x34))
            (*(undefined4 *)(original_frame_context + 0xec),
             *(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x1ec));
  (**(code **)(**(int **)(original_frame_context + 0xec) + 0x34))
            (*(undefined4 *)(original_frame_context + 0xec),
             *(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x1e8));
  (**(code **)(**(int **)(original_frame_context + 0xec) + 0x34))
            (*(undefined4 *)(original_frame_context + 0xec),
             *(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x1f0));
  (**(code **)(**(int **)(original_frame_context + 0xec) + 0x34))
            (*(undefined4 *)(original_frame_context + 0xec),
             *(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 500));
  (**(code **)(**(int **)(original_frame_context + 0xec) + 0x34))
            (*(undefined4 *)(original_frame_context + 0xec),
             *(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x1f8));
  pbStack00000010 = (byte *)0x31;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1230,0x429,0,0x11e);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x1ec) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x1ec),
             *(undefined4 *)(original_frame_context + 0x1230),
             *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x214) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x214),0,0,
             original_frame_context + 0x1230);
  pbStack00000010 = (byte *)0x31;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1230,0,0,0x91);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x20c) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x20c),
             *(undefined4 *)(original_frame_context + 0x1230),
             *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x20c) + 0x128) = 0x24;
  pbStack00000010 = (byte *)0x31;
  (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x1230,0x91,0,0x23);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x210) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x210),
             *(undefined4 *)(original_frame_context + 0x1230),
             *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x210) + 0x128) = 0x24;
  pbStack00000010 = (byte *)0x31;
  (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x1230,0x30d,0,0x11e);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x1e8) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x1e8),
             *(undefined4 *)(original_frame_context + 0x1230),
             *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x208) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x208),0,0,
             original_frame_context + 0x1230);
  pbStack00000010 = (byte *)0x31;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1230,0,0,0x91);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x200) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x200),
             *(undefined4 *)(original_frame_context + 0x1230),
             *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x200) + 0x128) = 0x24;
  pbStack00000010 = (byte *)0x31;
  (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x1230,0x91,0,0x23);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x204) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x204),
             *(undefined4 *)(original_frame_context + 0x1230),
             *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x204) + 0x128) = 0x24;
  pbStack00000010 = (byte *)0x31;
  (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x1230,0x1ef,0,0x11e);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x1f0) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x1f0),
             *(undefined4 *)(original_frame_context + 0x1230),
             *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
  pbStack00000010 = (byte *)0x31;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1230,0,0,0x96);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x218) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x218),
             *(undefined4 *)(original_frame_context + 0x1230),
             *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x218) + 0x128) = 0x24;
  pbStack00000010 = (byte *)0x31;
  (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x1230,0x9c,0,0x82);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x21c) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x21c),
             *(undefined4 *)(original_frame_context + 0x1230),
             *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x21c) + 0x128) = 0x21;
  pbStack00000010 = (byte *)0x31;
  (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x1230,0xd1,0,0x11e);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 500) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 500),
             *(undefined4 *)(original_frame_context + 0x1230),
             *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
  pbStack00000010 = (byte *)0x31;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1230,0,0,0x91);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x220) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x220),
             *(undefined4 *)(original_frame_context + 0x1230),
             *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x220) + 0x128) = 0x24;
  pbStack00000010 = (byte *)0x31;
  (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x1230,0x91,0,0x23);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x224) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x224),
             *(undefined4 *)(original_frame_context + 0x1230),
             *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x224) + 0x128) = 0x24;
  pbStack00000010 = (byte *)0x31;
  (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x1230,0,0,0x1ef);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x1f8) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x1f8),
             *(undefined4 *)(original_frame_context + 0x1230),
             *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
  pbStack00000010 = (byte *)0x31;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1230,0,0,0x96);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x228) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x228),
             *(undefined4 *)(original_frame_context + 0x1230),
             *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x228) + 0x128) = 0x24;
  pbStack00000010 = (byte *)0x31;
  (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x1230,0x9c,0,0x153);
  (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x22c) + 0x24))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x22c),
             *(undefined4 *)(original_frame_context + 0x1230),
             *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x22c) + 0x128) = 0x21;
  (**(code **)(iVar7 + -0x72a8))(*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x188));
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x72a8))
            (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x18c));
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x165c) =
       *(undefined4 *)(original_frame_context + 0x16e4);
  if (*(int *)(original_frame_context + 0x165c) == 0) {
    original_frame_context[0x1660] = 0;
    original_frame_context[0x1661] = 0;
    original_frame_context[0x1662] = 0;
    original_frame_context[0x1663] = 0;
  }
  else {
    uVar2 = (**(code **)(iVar7 + -0x598c))
                      (*(undefined4 *)(original_frame_context + 0x165c),
                       *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x3adc),0);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x1660) = uVar2;
  }
  *(undefined4 *)(original_frame_context + 0xe8) = *(undefined4 *)(original_frame_context + 0x1660);
  if (*(int *)(original_frame_context + 0xe8) != 0) {
    *(undefined4 *)(original_frame_context + 0x168) =
         *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x194);
    pbStack00000010 = (byte *)0x1f4;
    (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x11e4,0,0x1e,0x780);
    (**(code **)(**(int **)(original_frame_context + 0x168) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x168),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    pbStack00000010 = (byte *)0x78;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x11e4,0x10f,0xd2,0x562);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xe8) + 0x1b8) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x1b8),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    iVar7 = *(int *)(*(int *)(original_frame_context + 0xe8) + 0x1b8);
    uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x45f7);
    iVar8 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(iVar7 + 0x9c) = uVar1;
    iVar7 = *(int *)(*(int *)(original_frame_context + 0xe8) + 0x1b8);
    uVar1 = (**(code **)(iVar8 + -0x38a4))(0x45f7);
    iVar8 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(iVar7 + 0x9e) = uVar1;
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xe8) + 0x1b8) + 0x128) = 0x11;
    *(undefined4 *)(original_frame_context + 0x15c) =
         *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x1b0);
    pbStack00000010 = (byte *)0x5a;
    (**(code **)(iVar8 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0,0x562);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb0) =
         *(undefined4 *)(original_frame_context + 0x15c);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb4) =
         *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x1b4);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xa8) =
         *(undefined4 *)(original_frame_context + 0x15c);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xac) =
         *(undefined4 *)(original_frame_context + 0x15c);
    (**(code **)(**(int **)(original_frame_context + 0x15c) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x15c),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x15c) + 0xb8,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x15c) + 0xcc,0x122);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x15c) + 0xe0,0x122);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x15c) + 0xf4,0x122);
    uVar6 = *(undefined4 *)(original_frame_context + 0x15c);
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x13);
    pbStack00000010 = (byte *)0x0;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))(uVar6,1,uVar2,0xf);
    uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x13a) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x146) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x152) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x15e) = uVar1;
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0x128) = 0x21;
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x9e) = 0x46;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f7);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0xa2) = uVar1;
    uVar2 = (**(code **)(iVar7 + -0x38a4))(*(undefined4 *)(original_frame_context + 0x11ec));
    uVar6 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))
                      (*(undefined4 *)(original_frame_context + 0x11f0));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3e1c))
              (*(undefined4 *)(original_frame_context + 0x15c),1,uVar2,uVar6);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xc30,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xc1c,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xc08,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xbf4,0x4ac);
    pbStack00000010 = original_frame_context + 0xbf4;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1a5c))
              (*(undefined4 *)(original_frame_context + 0x15c),original_frame_context + 0xc30,
               original_frame_context + 0xc1c,original_frame_context + 0xc08);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xbf4)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xc08)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xc1c)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xc30)
    ;
    *(undefined4 *)(original_frame_context + 0x15c) =
         *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x1b4);
    pbStack00000010 = (byte *)0x5a;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x11e4,0x10f,0x5a,0x562);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb0) =
         *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x1b0);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb4) =
         *(undefined4 *)(original_frame_context + 0x15c);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xa8) =
         *(undefined4 *)(original_frame_context + 0x15c);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xac) =
         *(undefined4 *)(original_frame_context + 0x15c);
    (**(code **)(**(int **)(original_frame_context + 0x15c) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x15c),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x15c) + 0xb8,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x15c) + 0xcc,0x122);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x15c) + 0xe0,0x122);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x15c) + 0xf4,0x122);
    uVar6 = *(undefined4 *)(original_frame_context + 0x15c);
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x13);
    pbStack00000010 = (byte *)0x0;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))(uVar6,1,uVar2,0xf);
    uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x13a) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x146) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x152) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x15e) = uVar1;
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0x128) = 0x21;
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x9e) = 0x46;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f7);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0xa2) = uVar1;
    uVar2 = (**(code **)(iVar7 + -0x38a4))(*(undefined4 *)(original_frame_context + 0x11ec));
    uVar6 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))
                      (*(undefined4 *)(original_frame_context + 0x11f0));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3e1c))
              (*(undefined4 *)(original_frame_context + 0x15c),1,uVar2,uVar6);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xbe0,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xbcc,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 3000,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xba4,0x4ac);
    pbStack00000010 = original_frame_context + 0xba4;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1a5c))
              (*(undefined4 *)(original_frame_context + 0x15c),original_frame_context + 0xbe0,
               original_frame_context + 0xbcc,original_frame_context + 3000);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xba4)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 3000);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xbcc)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xbe0)
    ;
    *(undefined4 *)(original_frame_context + 0x168) =
         *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x198);
    pbStack00000010 = (byte *)0x1f4;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x11e4,0,0x1e,0x780);
    (**(code **)(**(int **)(original_frame_context + 0x168) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x168),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    pbStack00000010 = (byte *)0x78;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x11e4,0x10f,0xd2,0x562);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xe8) + 0x1c4) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x1c4),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    iVar7 = *(int *)(*(int *)(original_frame_context + 0xe8) + 0x1c4);
    uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x45f7);
    iVar8 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(iVar7 + 0x9c) = uVar1;
    iVar7 = *(int *)(*(int *)(original_frame_context + 0xe8) + 0x1c4);
    uVar1 = (**(code **)(iVar8 + -0x38a4))(0x45f7);
    iVar8 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(iVar7 + 0x9e) = uVar1;
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xe8) + 0x1c4) + 0x128) = 0x11;
    *(undefined4 *)(original_frame_context + 0x15c) =
         *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x1bc);
    pbStack00000010 = (byte *)0x5a;
    (**(code **)(iVar8 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0,0x562);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb0) =
         *(undefined4 *)(original_frame_context + 0x15c);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb4) =
         *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x1c0);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xa8) =
         *(undefined4 *)(original_frame_context + 0x15c);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xac) =
         *(undefined4 *)(original_frame_context + 0x15c);
    (**(code **)(**(int **)(original_frame_context + 0x15c) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x15c),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x15c) + 0xb8,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x15c) + 0xcc,0x122);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x15c) + 0xe0,0x122);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x15c) + 0xf4,0x122);
    uVar6 = *(undefined4 *)(original_frame_context + 0x15c);
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x13);
    pbStack00000010 = (byte *)0x0;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))(uVar6,1,uVar2,0xf);
    uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x13a) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x146) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x152) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x15e) = uVar1;
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0x128) = 0x21;
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x9e) = 0x46;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f7);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0xa2) = uVar1;
    uVar2 = (**(code **)(iVar7 + -0x38a4))(*(undefined4 *)(original_frame_context + 0x11ec));
    uVar6 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))
                      (*(undefined4 *)(original_frame_context + 0x11f0));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3e1c))
              (*(undefined4 *)(original_frame_context + 0x15c),1,uVar2,uVar6);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xb90,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xb7c,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xb68,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xb54,0x4ac);
    pbStack00000010 = original_frame_context + 0xb54;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1a5c))
              (*(undefined4 *)(original_frame_context + 0x15c),original_frame_context + 0xb90,
               original_frame_context + 0xb7c,original_frame_context + 0xb68);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xb54)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xb68)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xb7c)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xb90)
    ;
    *(undefined4 *)(original_frame_context + 0x15c) =
         *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x1c0);
    pbStack00000010 = (byte *)0x5a;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x11e4,0x10f,0x5a,0x562);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb0) =
         *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x1bc);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb4) =
         *(undefined4 *)(original_frame_context + 0x15c);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xa8) =
         *(undefined4 *)(original_frame_context + 0x15c);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xac) =
         *(undefined4 *)(original_frame_context + 0x15c);
    (**(code **)(**(int **)(original_frame_context + 0x15c) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x15c),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x15c) + 0xb8,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x15c) + 0xcc,0x122);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x15c) + 0xe0,0x122);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x15c) + 0xf4,0x122);
    uVar6 = *(undefined4 *)(original_frame_context + 0x15c);
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x13);
    pbStack00000010 = (byte *)0x0;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))(uVar6,1,uVar2,0xf);
    uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x13a) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x146) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x152) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x15e) = uVar1;
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0x128) = 0x21;
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x9e) = 0x46;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f7);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0xa2) = uVar1;
    uVar2 = (**(code **)(iVar7 + -0x38a4))(*(undefined4 *)(original_frame_context + 0x11ec));
    uVar6 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))
                      (*(undefined4 *)(original_frame_context + 0x11f0));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3e1c))
              (*(undefined4 *)(original_frame_context + 0x15c),1,uVar2,uVar6);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xb40,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xb2c,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xb18,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xb04,0x4ac);
    pbStack00000010 = original_frame_context + 0xb04;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1a5c))
              (*(undefined4 *)(original_frame_context + 0x15c),original_frame_context + 0xb40,
               original_frame_context + 0xb2c,original_frame_context + 0xb18);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xb04)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xb18)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xb2c)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xb40)
    ;
    *(undefined4 *)(original_frame_context + 0x168) =
         *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x19c);
    pbStack00000010 = (byte *)0x1f4;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x11e4,0,0x1e,0x780);
    (**(code **)(**(int **)(original_frame_context + 0x168) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x168),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    pbStack00000010 = (byte *)0x130;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x11e4,0x10f,0,0x562);
    *(undefined4 *)(original_frame_context + 0x160) =
         *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x1c8);
    (**(code **)(**(int **)(original_frame_context + 0x160) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x160),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x160) + 0x128) = 0x11;
    *(undefined4 *)(original_frame_context + 0x158) =
         *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x1cc);
    pbStack00000010 = (byte *)0x5a;
    (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0x13a,0x562);
    *(undefined4 *)(*(int *)(original_frame_context + 0x158) + 0xb0) =
         *(undefined4 *)(original_frame_context + 0x15c);
    *(undefined4 *)(*(int *)(original_frame_context + 0x158) + 0xb4) =
         *(undefined4 *)(original_frame_context + 0x15c);
    *(undefined4 *)(*(int *)(original_frame_context + 0x158) + 0xa8) =
         *(undefined4 *)(original_frame_context + 0x15c);
    *(undefined4 *)(*(int *)(original_frame_context + 0x158) + 0xac) =
         *(undefined4 *)(original_frame_context + 0x15c);
    (**(code **)(**(int **)(original_frame_context + 0x158) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x158),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x158) + 0xb8,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x158) + 0xcc,0x122);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x158) + 0xe0,0x122);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x158) + 0xf4,0x122);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x158) + 0x128) = 0x21;
    *(undefined2 *)(*(int *)(original_frame_context + 0x158) + 0x9e) = 0x46;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f7);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x158) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x158) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x158) + 0xa2) = uVar1;
    uVar6 = *(undefined4 *)(original_frame_context + 0x158);
    uVar2 = (**(code **)(iVar7 + -0x5868))(0x13);
    pbStack00000010 = (byte *)0x0;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))(uVar6,1,uVar2,0xf);
    pbStack00000010 = (byte *)0x221;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x11e4,0x10f,0x1e,0x562);
    *(undefined4 *)(original_frame_context + 0x164) =
         *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x18c);
    uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0xa6) = uVar1;
    (**(code **)(**(int **)(original_frame_context + 0x164) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x164),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    *(undefined4 *)(original_frame_context + 0x164) =
         *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 400);
    uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
    *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0xa6) = uVar1;
    (**(code **)(**(int **)(original_frame_context + 0x164) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x164),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    iVar7 = *(int *)(original_frame_context + 0x20);
  }
  pbStack00000010 = (byte *)0x5a;
  (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0,0x562);
  (**(code **)(*(int *)(original_frame_context + 0x20) + 0x948))(original_frame_context + 0x11f4);
  (**(code **)(*(int *)(original_frame_context + 0x20) + 0x948))(original_frame_context + 0x1240);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x1654) =
       *(undefined4 *)(original_frame_context + 0x16e4);
  if (*(int *)(original_frame_context + 0x1654) == 0) {
LAB_00565e9c:
    *(undefined4 *)(original_frame_context + 0x1650) =
         *(undefined4 *)(original_frame_context + 0x16e4);
    if (*(int *)(original_frame_context + 0x1650) != 0) {
      iVar8 = (**(code **)(iVar7 + -0x598c))
                        (*(undefined4 *)(original_frame_context + 0x1650),
                         *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x7420),0);
      iVar7 = *(int *)(original_frame_context + 0x20);
      if (iVar8 != 0) goto LAB_00565f8c;
    }
    *(undefined4 *)(original_frame_context + 0x164c) =
         *(undefined4 *)(original_frame_context + 0x16e4);
    if (*(int *)(original_frame_context + 0x164c) != 0) {
      iVar8 = (**(code **)(iVar7 + -0x598c))
                        (*(undefined4 *)(original_frame_context + 0x164c),
                         *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x5b6c),0);
      iVar7 = *(int *)(original_frame_context + 0x20);
      if (iVar8 != 0) goto LAB_00565f8c;
    }
    *(undefined4 *)(original_frame_context + 0x1648) =
         *(undefined4 *)(original_frame_context + 0x16e4);
    if (*(int *)(original_frame_context + 0x1648) != 0) {
      iVar8 = (**(code **)(iVar7 + -0x598c))
                        (*(undefined4 *)(original_frame_context + 0x1648),
                         *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x6228),0);
      iVar7 = *(int *)(original_frame_context + 0x20);
      if (iVar8 != 0) goto LAB_00565f8c;
    }
    *(undefined4 *)(original_frame_context + 0x1644) =
         *(undefined4 *)(original_frame_context + 0x16e4);
    if (*(int *)(original_frame_context + 0x1644) != 0) {
      iVar8 = (**(code **)(iVar7 + -0x598c))
                        (*(undefined4 *)(original_frame_context + 0x1644),
                         *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x4a68),0);
      iVar7 = *(int *)(original_frame_context + 0x20);
      if (iVar8 != 0) goto LAB_00565f8c;
    }
    original_frame_context[0x1658] = 0;
    original_frame_context[0x1659] = 0;
    original_frame_context[0x165a] = 0;
    original_frame_context[0x165b] = 0;
  }
  else {
    iVar8 = (**(code **)(iVar7 + -0x598c))
                      (*(undefined4 *)(original_frame_context + 0x1654),
                       *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x38e0),0);
    iVar7 = *(int *)(original_frame_context + 0x20);
    if (iVar8 == 0) goto LAB_00565e9c;
LAB_00565f8c:
    original_frame_context[0x1658] = 1;
    original_frame_context[0x1659] = 0;
    original_frame_context[0x165a] = 0;
    original_frame_context[0x165b] = 0;
  }
  if (*(int *)(original_frame_context + 0x1658) != 0) {
    original_frame_context[0xe4] = 0;
    original_frame_context[0xe5] = 0;
    original_frame_context[0xe6] = 0;
    original_frame_context[0xe7] = 0;
    while( true ) {
      uVar3 = (**(code **)(**(int **)(*(int *)(original_frame_context + 0x16e4) + 0x38) + 0x44))
                        (*(undefined4 *)(*(int *)(original_frame_context + 0x16e4) + 0x38));
      iVar7 = *(int *)(original_frame_context + 0x20);
      if (uVar3 <= *(uint *)(original_frame_context + 0xe4)) break;
      uVar2 = (**(code **)(**(int **)(*(int *)(original_frame_context + 0x16e4) + 0x38) + 0x40))
                        (*(undefined4 *)(*(int *)(original_frame_context + 0x16e4) + 0x38),
                         *(undefined4 *)(original_frame_context + 0xe4));
      iVar7 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(original_frame_context + 0xe0) = uVar2;
      *(undefined4 *)(original_frame_context + 0x163c) =
           *(undefined4 *)(original_frame_context + 0xe0);
      if (*(int *)(original_frame_context + 0x163c) == 0) {
        original_frame_context[0x1640] = 0;
        original_frame_context[0x1641] = 0;
        original_frame_context[0x1642] = 0;
        original_frame_context[0x1643] = 0;
      }
      else {
        uVar2 = (**(code **)(iVar7 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x163c),
                           *(undefined4 *)(iVar7 + -0x2dd4),*(undefined4 *)(iVar7 + -0x6e84),0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x1640) = uVar2;
      }
      *(undefined4 *)(original_frame_context + 0x126c) =
           *(undefined4 *)(original_frame_context + 0x1640);
      if (*(int *)(original_frame_context + 0x126c) != 0) {
        if (*(char *)(*(int *)(original_frame_context + 0x126c) + 0x3a) == '\x01') {
          (**(code **)(iVar7 + -0x7790))
                    (original_frame_context + 0x11f4,original_frame_context + 0x126c);
        }
        else {
          (**(code **)(iVar7 + -0x6b0c))
                    (*(undefined4 *)(original_frame_context + 0x126c),
                     original_frame_context + 0x125c);
          pbStack00000010 = (byte *)0x258;
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                    (original_frame_context + 0x125c,
                     *(undefined4 *)(original_frame_context + 0x125c),0,
                     *(undefined4 *)(original_frame_context + 0x1264));
          (**(code **)(**(int **)(original_frame_context + 0x126c) + 0x24))
                    (*(undefined4 *)(original_frame_context + 0x126c),
                     *(undefined4 *)(original_frame_context + 0x125c),
                     *(undefined4 *)(original_frame_context + 0x1260),
                     original_frame_context + 0x125c);
        }
      }
      *(int *)(original_frame_context + 0xe4) = *(int *)(original_frame_context + 0xe4) + 1;
    }
  }
  iVar7 = (**(code **)(iVar7 + 0x8e4))(original_frame_context + 0x11f4);
  iVar8 = *(int *)(original_frame_context + 0x20);
  *(int *)(original_frame_context + 0x1270) = iVar7 + -1;
  while (-1 < *(int *)(original_frame_context + 0x1270)) {
    puVar5 = (undefined4 *)
             (**(code **)(iVar8 + -0x76a0))
                       (original_frame_context + 0x11f4,
                        *(undefined4 *)(original_frame_context + 0x1270));
    iVar8 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0xdc) = *puVar5;
    *(undefined4 *)(original_frame_context + 0x1634) =
         *(undefined4 *)(original_frame_context + 0x16e4);
    if (*(int *)(original_frame_context + 0x1634) == 0) {
LAB_00566240:
      *(undefined4 *)(original_frame_context + 0x1628) =
           *(undefined4 *)(original_frame_context + 0x16e4);
      if (*(int *)(original_frame_context + 0x1628) != 0) {
        iVar7 = (**(code **)(iVar8 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x1628),
                           *(undefined4 *)(iVar8 + -0x5444),*(undefined4 *)(iVar8 + -0x5b6c),0);
        iVar8 = *(int *)(original_frame_context + 0x20);
        if (iVar7 != 0) {
          *(undefined4 *)(original_frame_context + 0x1620) =
               *(undefined4 *)(original_frame_context + 0x16e4);
          if (*(int *)(original_frame_context + 0x1620) == 0) {
            original_frame_context[0x1624] = 0;
            original_frame_context[0x1625] = 0;
            original_frame_context[0x1626] = 0;
            original_frame_context[0x1627] = 0;
          }
          else {
            uVar2 = (**(code **)(iVar8 + -0x598c))
                              (*(undefined4 *)(original_frame_context + 0x1620),
                               *(undefined4 *)(iVar8 + -0x5444),*(undefined4 *)(iVar8 + -0x5b6c),0);
            iVar8 = *(int *)(original_frame_context + 0x20);
            *(undefined4 *)(original_frame_context + 0x1624) = uVar2;
          }
          if (*(int *)(*(int *)(original_frame_context + 0x1624) + 0x188) ==
              *(int *)(original_frame_context + 0xdc)) goto LAB_005662d4;
        }
      }
      original_frame_context[0x1638] = 0;
      original_frame_context[0x1639] = 0;
      original_frame_context[0x163a] = 0;
      original_frame_context[0x163b] = 0;
    }
    else {
      iVar7 = (**(code **)(iVar8 + -0x598c))
                        (*(undefined4 *)(original_frame_context + 0x1634),
                         *(undefined4 *)(iVar8 + -0x5444),*(undefined4 *)(iVar8 + -0x5b6c),0);
      iVar8 = *(int *)(original_frame_context + 0x20);
      if (iVar7 == 0) goto LAB_00566240;
      *(undefined4 *)(original_frame_context + 0x162c) =
           *(undefined4 *)(original_frame_context + 0x16e4);
      if (*(int *)(original_frame_context + 0x162c) == 0) {
        original_frame_context[0x1630] = 0;
        original_frame_context[0x1631] = 0;
        original_frame_context[0x1632] = 0;
        original_frame_context[0x1633] = 0;
      }
      else {
        uVar2 = (**(code **)(iVar8 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x162c),
                           *(undefined4 *)(iVar8 + -0x5444),*(undefined4 *)(iVar8 + -0x5b6c),0);
        iVar8 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x1630) = uVar2;
      }
      if (*(int *)(*(int *)(original_frame_context + 0x1630) + 0x184) !=
          *(int *)(original_frame_context + 0xdc)) goto LAB_00566240;
LAB_005662d4:
      original_frame_context[0x1638] = 1;
      original_frame_context[0x1639] = 0;
      original_frame_context[0x163a] = 0;
      original_frame_context[0x163b] = 0;
    }
    if (*(int *)(original_frame_context + 0x1638) != 0) {
      pbStack00000010 = (byte *)0x258;
      (**(code **)(iVar8 + -0x2b00))(original_frame_context + 0x1274,0,0x31,0x780);
      (**(code **)(**(int **)(original_frame_context + 0xdc) + 0x24))
                (*(undefined4 *)(original_frame_context + 0xdc),
                 *(undefined4 *)(original_frame_context + 0x1274),
                 *(undefined4 *)(original_frame_context + 0x1278),original_frame_context + 0x1274);
      iVar7 = *(int *)(original_frame_context + 0x20);
      *(undefined1 *)(*(int *)(original_frame_context + 0xdc) + 0x39) = 0;
      *(undefined1 *)(*(int *)(original_frame_context + 0xdc) + 0x3a) = 0;
      (**(code **)(iVar7 + -0x464))(*(undefined4 *)(original_frame_context + 0xdc));
      uVar2 = (**(code **)(**(int **)(original_frame_context + 0xdc) + 0x40))
                        (*(undefined4 *)(original_frame_context + 0xdc),0);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x72a8))(uVar2);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x30a8))
                (original_frame_context + 0xaf8,original_frame_context + 0x11f4);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x467c))
                (original_frame_context + 0xafc,original_frame_context + 0xaf8,
                 original_frame_context + 0x1270);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x6168))
                (original_frame_context + 0xb00,original_frame_context + 0x11f4,
                 *(undefined4 *)(original_frame_context + 0xafc));
      iVar8 = *(int *)(original_frame_context + 0x20);
    }
    *(int *)(original_frame_context + 0x1270) = *(int *)(original_frame_context + 0x1270) + -1;
  }
  (**(code **)(iVar8 + -0x7b0))(original_frame_context + 0x124c);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5260))
            (*(undefined4 *)(original_frame_context + 0x16e0),
             *(undefined4 *)(*(int *)(original_frame_context + 0x16e4) + 0x38),
             original_frame_context + 0x124c,original_frame_context + 0x11f4);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1194))(original_frame_context + 0x1258);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x6f50))
            (original_frame_context + 0x13c0,original_frame_context + 0x124c);
  iVar7 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x1258) =
       *(undefined4 *)(original_frame_context + 0x13c0);
  do {
    (**(code **)(iVar7 + -0x2774))(original_frame_context + 0xaf4,original_frame_context + 0x124c);
    iVar7 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x6ca8))
                      (original_frame_context + 0x1258,original_frame_context + 0xaf4);
    iVar8 = *(int *)(original_frame_context + 0x20);
    if (iVar7 == 0) {
      *(undefined4 *)(original_frame_context + 0x1518) =
           *(undefined4 *)(original_frame_context + 0x16e4);
      if (*(int *)(original_frame_context + 0x1518) == 0) {
        original_frame_context[0x151c] = 0;
        original_frame_context[0x151d] = 0;
        original_frame_context[0x151e] = 0;
        original_frame_context[0x151f] = 0;
      }
      else {
        uVar2 = (**(code **)(iVar8 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x1518),
                           *(undefined4 *)(iVar8 + -0x5444),*(undefined4 *)(iVar8 + -0x38e0),0);
        iVar8 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x151c) = uVar2;
      }
      *(undefined4 *)(original_frame_context + 0xa8) =
           *(undefined4 *)(original_frame_context + 0x151c);
      if (*(int *)(original_frame_context + 0xa8) != 0) {
        (**(code **)(iVar8 + -0x506c))(original_frame_context + 0x12b4);
        *(undefined4 *)(original_frame_context + 0xa4) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x1a0);
        *(undefined4 *)(original_frame_context + 0xa0) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x264);
        (**(code **)(**(int **)(original_frame_context + 0xa4) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0xa4),
                   *(undefined4 *)(original_frame_context + 0xa0));
        *(undefined4 *)(original_frame_context + 0x12c0) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x274);
        (**(code **)(**(int **)(original_frame_context + 0xa4) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0xa4),
                   *(undefined4 *)(original_frame_context + 0x12c0));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x12b4,original_frame_context + 0x12c0);
        *(undefined4 *)(original_frame_context + 0x12c4) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x278);
        (**(code **)(**(int **)(original_frame_context + 0xa4) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0xa4),
                   *(undefined4 *)(original_frame_context + 0x12c4));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x12b4,original_frame_context + 0x12c4);
        *(undefined4 *)(original_frame_context + 0x12c8) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x27c);
        (**(code **)(**(int **)(original_frame_context + 0xa4) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0xa4),
                   *(undefined4 *)(original_frame_context + 0x12c8));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x12b4,original_frame_context + 0x12c8);
        *(undefined4 *)(original_frame_context + 0x12cc) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x280);
        (**(code **)(**(int **)(original_frame_context + 0xa4) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0xa4),
                   *(undefined4 *)(original_frame_context + 0x12cc));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x12b4,original_frame_context + 0x12cc);
        *(undefined4 *)(original_frame_context + 0x12d0) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x288);
        (**(code **)(**(int **)(original_frame_context + 0xa4) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0xa4),
                   *(undefined4 *)(original_frame_context + 0x12d0));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x12b4,original_frame_context + 0x12d0);
        *(undefined4 *)(original_frame_context + 0x12d4) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x29c);
        (**(code **)(**(int **)(original_frame_context + 0xa4) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0xa4),
                   *(undefined4 *)(original_frame_context + 0x12d4));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x12b4,original_frame_context + 0x12d4);
        *(undefined4 *)(original_frame_context + 0x12d8) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x268);
        (**(code **)(**(int **)(original_frame_context + 0xa4) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0xa4),
                   *(undefined4 *)(original_frame_context + 0x12d8));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x12b4,original_frame_context + 0x12d8);
        *(undefined4 *)(original_frame_context + 0xa4) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x28c);
        *(undefined4 *)(original_frame_context + 0x12dc) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x2a4);
        (**(code **)(**(int **)(original_frame_context + 0xa4) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0xa4),
                   *(undefined4 *)(original_frame_context + 0x12dc));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x12b4,original_frame_context + 0x12dc);
        *(undefined4 *)(original_frame_context + 0xa4) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x290);
        *(undefined4 *)(original_frame_context + 0x12e0) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x2ac);
        (**(code **)(**(int **)(original_frame_context + 0xa4) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0xa4),
                   *(undefined4 *)(original_frame_context + 0x12e0));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x12b4,original_frame_context + 0x12e0);
        *(undefined4 *)(original_frame_context + 0xa4) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x294);
        *(undefined4 *)(original_frame_context + 0x12e4) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x2b4);
        (**(code **)(**(int **)(original_frame_context + 0xa4) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0xa4),
                   *(undefined4 *)(original_frame_context + 0x12e4));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x12b4,original_frame_context + 0x12e4);
        *(undefined4 *)(original_frame_context + 0xa4) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x298);
        *(undefined4 *)(original_frame_context + 0x12e8) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 700);
        (**(code **)(**(int **)(original_frame_context + 0xa4) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0xa4),
                   *(undefined4 *)(original_frame_context + 0x12e8));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x12b4,original_frame_context + 0x12e8);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x373c))
                  (original_frame_context + 0x12ec);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x6be0))
                  (original_frame_context + 0x13c0,original_frame_context + 0x12b4);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x12ec) =
             *(undefined4 *)(original_frame_context + 0x13c0);
        while( true ) {
          (**(code **)(iVar7 + -0x11cc))
                    (original_frame_context + 0x95c,original_frame_context + 0x12b4);
          iVar7 = (**(code **)(*(int *)(original_frame_context + 0x20) + 0xed0))
                            (original_frame_context + 0x12ec,original_frame_context + 0x95c);
          iVar8 = *(int *)(original_frame_context + 0x20);
          if (iVar7 == 0) break;
          puVar5 = (undefined4 *)(**(code **)(iVar8 + -0x55d4))(original_frame_context + 0x12ec);
          *(undefined4 *)(original_frame_context + 0x68) = *puVar5;
          uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x45);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x7c) = uVar2;
          uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x80) = uVar2;
          uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x84) = uVar2;
          uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x88) = uVar2;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0x9c) = uVar1;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0x9e) = uVar1;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0xa0) = uVar1;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0xa2) = uVar1;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0xa4) = uVar1;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0xa6) = uVar1;
          (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x68) + 0xb8,0x5cd);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x68) + 0xcc,0x5cd);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x68) + 0xe0,0x5cd);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x68) + 0xf4,0x5cd);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x130) = 0x4ae;
          *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x13c) = 0x4ae;
          *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x148) = 0x4ae;
          *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x154) = 0x4ae;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0x13a) = uVar1;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0x146) = uVar1;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0x152) = uVar1;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0x15e) = uVar1;
          *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x128) = 0x24;
          (**(code **)(iVar7 + -0x75c4))
                    (original_frame_context + 0x958,original_frame_context + 0x12ec,0);
          iVar7 = *(int *)(original_frame_context + 0x20);
        }
        *(undefined4 *)(*(int *)(original_frame_context + 0x12d8) + 0x128) = 0x21;
        *(undefined4 *)(original_frame_context + 0x1514) =
             *(undefined4 *)(original_frame_context + 0x12d8);
        uVar1 = (**(code **)(iVar8 + -0x38a4))(0x3213);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x1514) + 0x13a) = uVar1;
        *(undefined4 *)(original_frame_context + 0x1510) =
             *(undefined4 *)(original_frame_context + 0x12d8);
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3213);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x1510) + 0x146) = uVar1;
        *(undefined4 *)(original_frame_context + 0x150c) =
             *(undefined4 *)(original_frame_context + 0x12d8);
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3213);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x150c) + 0x152) = uVar1;
        *(undefined4 *)(original_frame_context + 0x1508) =
             *(undefined4 *)(original_frame_context + 0x12d8);
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3213);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x1508) + 0x15e) = uVar1;
        *(undefined4 *)(original_frame_context + 0x1504) =
             *(undefined4 *)(original_frame_context + 0x12c0);
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x16);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1504) + 0x7c) = uVar2;
        *(undefined4 *)(original_frame_context + 0x1500) =
             *(undefined4 *)(original_frame_context + 0x12c0);
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x16);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1500) + 0x80) = uVar2;
        *(undefined4 *)(original_frame_context + 0x14fc) =
             *(undefined4 *)(original_frame_context + 0x12c0);
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x16);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x14fc) + 0x84) = uVar2;
        *(undefined4 *)(original_frame_context + 0x14f8) =
             *(undefined4 *)(original_frame_context + 0x12c0);
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x16);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x14f8) + 0x88) = uVar2;
        (**(code **)(iVar7 + -0x45a8))(original_frame_context + 0x944,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x930,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x91c,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x908,0x5cd);
        pbStack00000010 = original_frame_context + 0x91c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x78c8))
                  (*(undefined4 *)(original_frame_context + 0xa0),0,original_frame_context + 0x944,
                   original_frame_context + 0x930);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x908);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x91c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x930);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x944);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x16);
        *(undefined4 *)(original_frame_context + 0x14f4) = uVar2;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x16);
        *(undefined4 *)(original_frame_context + 0x14f0) = uVar2;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x16);
        *(undefined4 *)(original_frame_context + 0x14ec) = uVar2;
        pbStack00000010 =
             (byte *)(**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x16);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x228))
                  (*(undefined4 *)(original_frame_context + 0xa0),
                   *(undefined4 *)(original_frame_context + 0x14f4),
                   *(undefined4 *)(original_frame_context + 0x14f0),
                   *(undefined4 *)(original_frame_context + 0x14ec));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x15);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0xa0) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x15);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0xa0) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x15);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0xa0) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x15);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0xa0) + 0x58) = uVar2;
        *(undefined1 *)(*(int *)(original_frame_context + 0xa0) + 0x3a) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0xa0) + 0x39) = 1;
        pbStack00000010 = (byte *)0x226;
        (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x12f0,0,0x1e,0x780);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x14e8) = uVar2;
        pbStack00000010 = (byte *)0x67;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x14e8),
                   *(undefined4 *)(*(int *)(original_frame_context + 0x16e4) + 0x38),
                   original_frame_context + 0x12f0,0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x9c) =
             *(undefined4 *)(original_frame_context + 0x14e8);
        if (*(int *)(original_frame_context + 0x9c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0x9e5);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x11d4))(*(undefined4 *)(original_frame_context + 0x9c),2,0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x9c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x9c) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x9c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x9c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x9c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x9c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x9c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x9c) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x9c) + 0xb8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x9c) + 0xcc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x9c) + 0xe0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x9c) + 0xf4,0x5cd);
        (**(code **)(**(int **)(*(int *)(original_frame_context + 0x16e4) + 0x38) + 0x34))
                  (*(undefined4 *)(*(int *)(original_frame_context + 0x16e4) + 0x38),
                   *(undefined4 *)(original_frame_context + 0x9c));
        pbStack00000010 = (byte *)0x52;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x12f0,0x10f,0,0x562);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x14e4) = uVar2;
        pbStack00000010 = (byte *)0x68;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x14e4),
                   *(undefined4 *)(original_frame_context + 0x9c),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x98) =
             *(undefined4 *)(original_frame_context + 0x14e4);
        if (*(int *)(original_frame_context + 0x98) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0x9f7);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x98) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x98) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x98) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x98) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x98) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x98) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x98) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x98) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x98) + 0xb8,0x137);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x98) + 0xcc,0x137);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x98) + 0xe0,0x137);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x98) + 0xf4,0x137);
        (**(code **)(**(int **)(original_frame_context + 0x9c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x9c),
                   *(undefined4 *)(original_frame_context + 0x98));
        (**(code **)(**(int **)(original_frame_context + 0x98) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x98),
                   *(undefined4 *)(original_frame_context + 0xa0));
        (**(code **)(**(int **)(original_frame_context + 0x98) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x98),
                   *(undefined4 *)(original_frame_context + 0x12d8));
        (**(code **)(**(int **)(original_frame_context + 0x98) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x98),
                   *(undefined4 *)(original_frame_context + 0x12c0));
        pbStack00000010 = (byte *)0xa;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x12f0,0xe6,0x27,0x435);
        (**(code **)(**(int **)(original_frame_context + 0xa0) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0xa0),
                   *(undefined4 *)(original_frame_context + 0x12f0),
                   *(undefined4 *)(original_frame_context + 0x12f4),original_frame_context + 0x12f0)
        ;
        pbStack00000010 = (byte *)0x52;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x12f0,0,0,0x14a);
        (**(code **)(**(int **)(original_frame_context + 0x12d8) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x12d8),
                   *(undefined4 *)(original_frame_context + 0x12f0),
                   *(undefined4 *)(original_frame_context + 0x12f4),original_frame_context + 0x12f0)
        ;
        pbStack00000010 = (byte *)0x52;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x12f0,0x508,0,0x5a);
        (**(code **)(**(int **)(original_frame_context + 0x12c0) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x12c0),
                   *(undefined4 *)(original_frame_context + 0x12f0),
                   *(undefined4 *)(original_frame_context + 0x12f4),original_frame_context + 0x12f0)
        ;
        pbStack00000010 = (byte *)0x16c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x12f0,0x10f,0x72,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x14e0) = uVar2;
        pbStack00000010 = (byte *)0x69;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x14e0),
                   *(undefined4 *)(original_frame_context + 0x9c),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x94) =
             *(undefined4 *)(original_frame_context + 0x14e0);
        if (*(int *)(original_frame_context + 0x94) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xa11);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x94) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x94) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x94) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x94) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x94) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x94) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x94) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x94) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x94) + 0xb8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x94) + 0xcc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x94) + 0xe0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x94) + 0xf4,0x5cd);
        (**(code **)(**(int **)(original_frame_context + 0x9c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x9c),
                   *(undefined4 *)(original_frame_context + 0x94));
        pbStack00000010 = (byte *)0x40;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x12f0,0,0,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x14dc) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x14dc),
                   *(undefined4 *)(original_frame_context + 0x94),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x90) =
             *(undefined4 *)(original_frame_context + 0x14dc);
        if (*(int *)(original_frame_context + 0x90) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xa22);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x90) + 0x170,0xeee);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x90) + 0x39) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x90) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x1a);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x1a);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x1a);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x1a);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x94) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x94),
                   *(undefined4 *)(original_frame_context + 0x90));
        pbStack00000010 = (byte *)0x12c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x12f0,0,0x40,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0xbf8);
        *(undefined4 *)(original_frame_context + 0x14d8) = uVar2;
        pbStack00000010 = (byte *)0x6c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x605c))
                  (*(undefined4 *)(original_frame_context + 0x14d8),
                   *(undefined4 *)(original_frame_context + 0x94),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x8c) =
             *(undefined4 *)(original_frame_context + 0x14d8);
        if (*(int *)(original_frame_context + 0x8c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xa40);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x8c) + 0x39) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x8c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x8c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x8c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x8c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x8c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x8c) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x8c) + 0xb8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x8c) + 0xcc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x8c) + 0xe0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x8c) + 0xf4,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5b08))
                  (*(undefined4 *)(original_frame_context + 0x8c),0);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2820))
                  (*(undefined4 *)(original_frame_context + 0x8c),5);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x8f4,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x8e0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x8cc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x8b8,0x5cd);
        pbStack00000010 = original_frame_context + 0x8b8;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x77c8))
                  (*(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x8f4,
                   original_frame_context + 0x8e0,original_frame_context + 0x8cc);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x8b8);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x8cc);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x8e0);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x8f4);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x8a4,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x890,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x87c,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x868,0x5cd);
        pbStack00000010 = original_frame_context + 0x868;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x447c))
                  (*(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x8a4,
                   original_frame_context + 0x890,original_frame_context + 0x87c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x868);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x87c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x890);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x8a4);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x854,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x840,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x82c,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x818,0x5cd);
        pbStack00000010 = original_frame_context + 0x818;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x17d4))
                  (*(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x854,
                   original_frame_context + 0x840,original_frame_context + 0x82c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x818);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x82c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x840);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x854);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x804,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x7f0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x7dc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x7c8,0x5cd);
        pbStack00000010 = original_frame_context + 0x7c8;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4bb4))
                  (*(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x804,
                   original_frame_context + 0x7f0,original_frame_context + 0x7dc);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x7c8);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x7dc);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x7f0);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x804);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x11d4))
                  (*(undefined4 *)(original_frame_context + 0x8c),2,1);
        (**(code **)(**(int **)(original_frame_context + 0x94) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x94),
                   *(undefined4 *)(original_frame_context + 0x8c));
        pbStack00000010 = (byte *)0x16c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x12f0,0x2e5,0x72,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x14d4) = uVar2;
        pbStack00000010 = (byte *)0x6a;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x14d4),
                   *(undefined4 *)(original_frame_context + 0x9c),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x88) =
             *(undefined4 *)(original_frame_context + 0x14d4);
        if (*(int *)(original_frame_context + 0x88) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xa57);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x88) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x88) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x88) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x88) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x88) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x88) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x88) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x88) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x88) + 0xb8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x88) + 0xcc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x88) + 0xe0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x88) + 0xf4,0x5cd);
        (**(code **)(**(int **)(original_frame_context + 0x9c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x9c),
                   *(undefined4 *)(original_frame_context + 0x88));
        pbStack00000010 = (byte *)0x40;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x12f0,0,0,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x14d0) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x14d0),
                   *(undefined4 *)(original_frame_context + 0x88),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x84) =
             *(undefined4 *)(original_frame_context + 0x14d0);
        if (*(int *)(original_frame_context + 0x84) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xa68);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x84) + 0x170,0xfa3);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x84) + 0x39) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x84) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x18);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x18);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x18);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x18);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x88) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x88),
                   *(undefined4 *)(original_frame_context + 0x84));
        pbStack00000010 = (byte *)0x12c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x12f0,0,0x40,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0xbf8);
        *(undefined4 *)(original_frame_context + 0x14cc) = uVar2;
        pbStack00000010 = (byte *)0x6d;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x605c))
                  (*(undefined4 *)(original_frame_context + 0x14cc),
                   *(undefined4 *)(original_frame_context + 0x88),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x80) =
             *(undefined4 *)(original_frame_context + 0x14cc);
        if (*(int *)(original_frame_context + 0x80) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xa86);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x80) + 0x39) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x80) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x80) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x80) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x80) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x80) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x80) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x80) + 0xb8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x80) + 0xcc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x80) + 0xe0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x80) + 0xf4,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5b08))
                  (*(undefined4 *)(original_frame_context + 0x80),0);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2820))
                  (*(undefined4 *)(original_frame_context + 0x80),5);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x7b4,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x7a0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x78c,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x778,0x5cd);
        pbStack00000010 = original_frame_context + 0x778;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x77c8))
                  (*(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x7b4,
                   original_frame_context + 0x7a0,original_frame_context + 0x78c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x778);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x78c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x7a0);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x7b4);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x764,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x750,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x73c,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x728,0x5cd);
        pbStack00000010 = original_frame_context + 0x728;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x447c))
                  (*(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x764,
                   original_frame_context + 0x750,original_frame_context + 0x73c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x728);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x73c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x750);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x764);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x714,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x700,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x6ec,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x6d8,0x5cd);
        pbStack00000010 = original_frame_context + 0x6d8;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x17d4))
                  (*(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x714,
                   original_frame_context + 0x700,original_frame_context + 0x6ec);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x6d8);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x6ec);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x700);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x714);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x6c4,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x6b0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x69c,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x688,0x5cd);
        pbStack00000010 = original_frame_context + 0x688;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4bb4))
                  (*(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x6c4,
                   original_frame_context + 0x6b0,original_frame_context + 0x69c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x688);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x69c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x6b0);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x6c4);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x11d4))
                  (*(undefined4 *)(original_frame_context + 0x80),2,1);
        (**(code **)(**(int **)(original_frame_context + 0x88) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x88),
                   *(undefined4 *)(original_frame_context + 0x80));
        pbStack00000010 = (byte *)0x16c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x12f0,0x4bb,0x72,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x14c8) = uVar2;
        pbStack00000010 = (byte *)0x6b;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x14c8),
                   *(undefined4 *)(original_frame_context + 0x9c),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x7c) =
             *(undefined4 *)(original_frame_context + 0x14c8);
        if (*(int *)(original_frame_context + 0x7c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xa9d);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x7c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x7c) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x7c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x7c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x7c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x7c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x7c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x7c) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x7c) + 0xb8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x7c) + 0xcc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x7c) + 0xe0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x7c) + 0xf4,0x5cd);
        (**(code **)(**(int **)(original_frame_context + 0x9c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x9c),
                   *(undefined4 *)(original_frame_context + 0x7c));
        pbStack00000010 = (byte *)0x40;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x12f0,0,0,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x14c4) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x14c4),
                   *(undefined4 *)(original_frame_context + 0x7c),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x78) =
             *(undefined4 *)(original_frame_context + 0x14c4);
        if (*(int *)(original_frame_context + 0x78) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xaae);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x78) + 0x170,0xdcc);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x78) + 0x39) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x78) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x19);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x19);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x19);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x19);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x7c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x7c),
                   *(undefined4 *)(original_frame_context + 0x78));
        pbStack00000010 = (byte *)0x12c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x12f0,0,0x40,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0xbf8);
        *(undefined4 *)(original_frame_context + 0x14c0) = uVar2;
        pbStack00000010 = (byte *)0x6e;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x605c))
                  (*(undefined4 *)(original_frame_context + 0x14c0),
                   *(undefined4 *)(original_frame_context + 0x7c),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x74) =
             *(undefined4 *)(original_frame_context + 0x14c0);
        if (*(int *)(original_frame_context + 0x74) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xacc);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x74) + 0x39) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x74) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x74) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x74) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x74) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x74) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x74) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x74) + 0xb8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x74) + 0xcc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x74) + 0xe0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x74) + 0xf4,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5b08))
                  (*(undefined4 *)(original_frame_context + 0x74),0);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2820))
                  (*(undefined4 *)(original_frame_context + 0x74),5);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x674,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x660,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x64c,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x638,0x5cd);
        pbStack00000010 = original_frame_context + 0x638;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x77c8))
                  (*(undefined4 *)(original_frame_context + 0x74),original_frame_context + 0x674,
                   original_frame_context + 0x660,original_frame_context + 0x64c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x638);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x64c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x660);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x674);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x624,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x610,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x5fc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x5e8,0x5cd);
        pbStack00000010 = original_frame_context + 0x5e8;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x447c))
                  (*(undefined4 *)(original_frame_context + 0x74),original_frame_context + 0x624,
                   original_frame_context + 0x610,original_frame_context + 0x5fc);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x5e8);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x5fc);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x610);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x624);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x5d4,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x5c0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x5ac,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x598,0x5cd);
        pbStack00000010 = original_frame_context + 0x598;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x17d4))
                  (*(undefined4 *)(original_frame_context + 0x74),original_frame_context + 0x5d4,
                   original_frame_context + 0x5c0,original_frame_context + 0x5ac);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x598);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x5ac);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x5c0);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x5d4);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x584,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x570,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x55c,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x548,0x5cd);
        pbStack00000010 = original_frame_context + 0x548;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4bb4))
                  (*(undefined4 *)(original_frame_context + 0x74),original_frame_context + 0x584,
                   original_frame_context + 0x570,original_frame_context + 0x55c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x548);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x55c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x570);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x584);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x11d4))
                  (*(undefined4 *)(original_frame_context + 0x74),2,1);
        (**(code **)(**(int **)(original_frame_context + 0x7c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x7c),
                   *(undefined4 *)(original_frame_context + 0x74));
        pbStack00000010 = (byte *)0x3c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x12f0,0,0,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x14bc) = uVar2;
        pbStack00000010 = (byte *)0x6f;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x14bc),
                   *(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x70) =
             *(undefined4 *)(original_frame_context + 0x14bc);
        if (*(int *)(original_frame_context + 0x70) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xae3);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x8c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x8c),
                   *(undefined4 *)(original_frame_context + 0x70));
        pbStack00000010 = (byte *)0x3a;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1300,0x117,0,0xa0);
        pbStack00000010 = (byte *)0x3a;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1310,0,0,0x117);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x14b8) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x14b8),
                   *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x6c) =
             *(undefined4 *)(original_frame_context + 0x14b8);
        if (*(int *)(original_frame_context + 0x6c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xaf7);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0x11db);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x6c));
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x12d0));
        (**(code **)(**(int **)(original_frame_context + 0x12d0) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x12d0),
                   *(undefined4 *)(original_frame_context + 0x1300),
                   *(undefined4 *)(original_frame_context + 0x1304),original_frame_context + 0x1300)
        ;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x14b4) = uVar2;
        pbStack00000010 = (byte *)0x70;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x14b4),
                   *(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x70) =
             *(undefined4 *)(original_frame_context + 0x14b4);
        if (*(int *)(original_frame_context + 0x70) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xb16);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x8c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x8c),
                   *(undefined4 *)(original_frame_context + 0x70));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x14b0) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x14b0),
                   *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x6c) =
             *(undefined4 *)(original_frame_context + 0x14b0);
        if (*(int *)(original_frame_context + 0x6c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xb26);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0xcda);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x6c));
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x12dc));
        (**(code **)(**(int **)(original_frame_context + 0x12dc) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x12dc),
                   *(undefined4 *)(original_frame_context + 0x1300),
                   *(undefined4 *)(original_frame_context + 0x1304),original_frame_context + 0x1300)
        ;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x14ac) = uVar2;
        pbStack00000010 = (byte *)0x71;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x14ac),
                   *(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x70) =
             *(undefined4 *)(original_frame_context + 0x14ac);
        if (*(int *)(original_frame_context + 0x70) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xb45);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x8c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x8c),
                   *(undefined4 *)(original_frame_context + 0x70));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x14a8) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x14a8),
                   *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x6c) =
             *(undefined4 *)(original_frame_context + 0x14a8);
        if (*(int *)(original_frame_context + 0x6c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xb55);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0xed0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x6c));
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x12e0));
        (**(code **)(**(int **)(original_frame_context + 0x12e0) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x12e0),
                   *(undefined4 *)(original_frame_context + 0x1300),
                   *(undefined4 *)(original_frame_context + 0x1304),original_frame_context + 0x1300)
        ;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x14a4) = uVar2;
        pbStack00000010 = (byte *)0x72;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x14a4),
                   *(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x70) =
             *(undefined4 *)(original_frame_context + 0x14a4);
        if (*(int *)(original_frame_context + 0x70) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xb74);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x8c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x8c),
                   *(undefined4 *)(original_frame_context + 0x70));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x14a0) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x14a0),
                   *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x6c) =
             *(undefined4 *)(original_frame_context + 0x14a0);
        if (*(int *)(original_frame_context + 0x6c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xb84);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0xc15);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x6c));
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x12e8));
        (**(code **)(**(int **)(original_frame_context + 0x12e8) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x12e8),
                   *(undefined4 *)(original_frame_context + 0x1300),
                   *(undefined4 *)(original_frame_context + 0x1304),original_frame_context + 0x1300)
        ;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x149c) = uVar2;
        pbStack00000010 = (byte *)0x73;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x149c),
                   *(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x70) =
             *(undefined4 *)(original_frame_context + 0x149c);
        if (*(int *)(original_frame_context + 0x70) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xba3);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x8c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x8c),
                   *(undefined4 *)(original_frame_context + 0x70));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x1498) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x1498),
                   *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x6c) =
             *(undefined4 *)(original_frame_context + 0x1498);
        if (*(int *)(original_frame_context + 0x6c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xbb3);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0xcbd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x6c));
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x12e4));
        (**(code **)(**(int **)(original_frame_context + 0x12e4) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x12e4),
                   *(undefined4 *)(original_frame_context + 0x1300),
                   *(undefined4 *)(original_frame_context + 0x1304),original_frame_context + 0x1300)
        ;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x1494) = uVar2;
        pbStack00000010 = (byte *)0x74;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x1494),
                   *(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x70) =
             *(undefined4 *)(original_frame_context + 0x1494);
        if (*(int *)(original_frame_context + 0x70) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xbd2);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x80) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x80),
                   *(undefined4 *)(original_frame_context + 0x70));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x1490) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x1490),
                   *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x6c) =
             *(undefined4 *)(original_frame_context + 0x1490);
        if (*(int *)(original_frame_context + 0x6c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xbe2);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0xfa1);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x6c));
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x12d4));
        pbStack00000010 = *(byte **)(original_frame_context + 0x130c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1320,*(int *)(original_frame_context + 0x1300) + -0x78
                   ,*(undefined4 *)(original_frame_context + 0x1304),
                   *(int *)(original_frame_context + 0x1308) + 0x78);
        (**(code **)(**(int **)(original_frame_context + 0x12d4) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x12d4),
                   *(undefined4 *)(original_frame_context + 0x1320),
                   *(undefined4 *)(original_frame_context + 0x1324),original_frame_context + 0x1320)
        ;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x148c) = uVar2;
        pbStack00000010 = (byte *)0x75;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x148c),
                   *(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x70) =
             *(undefined4 *)(original_frame_context + 0x148c);
        if (*(int *)(original_frame_context + 0x70) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xc03);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x11d4))(*(undefined4 *)(original_frame_context + 0x70),2,0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x80) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x80),
                   *(undefined4 *)(original_frame_context + 0x70));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x1488) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x1488),
                   *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x6c) =
             *(undefined4 *)(original_frame_context + 0x1488);
        if (*(int *)(original_frame_context + 0x6c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xc14);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0xeb4);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x6c));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x1484) = uVar2;
        pbStack00000010 = (byte *)0x76;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x1484),
                   *(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x70) =
             *(undefined4 *)(original_frame_context + 0x1484);
        if (*(int *)(original_frame_context + 0x70) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xc31);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x80) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x80),
                   *(undefined4 *)(original_frame_context + 0x70));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x1480) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x1480),
                   *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x6c) =
             *(undefined4 *)(original_frame_context + 0x1480);
        if (*(int *)(original_frame_context + 0x6c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xc41);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0x1115);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x6c));
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x12c4));
        (**(code **)(**(int **)(original_frame_context + 0x12c4) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x12c4),
                   *(undefined4 *)(original_frame_context + 0x1320),
                   *(undefined4 *)(original_frame_context + 0x1324),original_frame_context + 0x1320)
        ;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x147c) = uVar2;
        pbStack00000010 = (byte *)0x77;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x147c),
                   *(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x70) =
             *(undefined4 *)(original_frame_context + 0x147c);
        if (*(int *)(original_frame_context + 0x70) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xc60);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x80) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x80),
                   *(undefined4 *)(original_frame_context + 0x70));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x1478) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x1478),
                   *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x6c) =
             *(undefined4 *)(original_frame_context + 0x1478);
        if (*(int *)(original_frame_context + 0x6c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xc70);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0xeb1);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x6c));
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x12c8));
        (**(code **)(**(int **)(original_frame_context + 0x12c8) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x12c8),
                   *(undefined4 *)(original_frame_context + 0x1300),
                   *(undefined4 *)(original_frame_context + 0x1304),original_frame_context + 0x1300)
        ;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x1474) = uVar2;
        pbStack00000010 = (byte *)0x78;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x1474),
                   *(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x12f0,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x70) =
             *(undefined4 *)(original_frame_context + 0x1474);
        if (*(int *)(original_frame_context + 0x70) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xc8f);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x80) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x80),
                   *(undefined4 *)(original_frame_context + 0x70));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x1470) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x1470),
                   *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x6c) =
             *(undefined4 *)(original_frame_context + 0x1470);
        if (*(int *)(original_frame_context + 0x6c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xc9f);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0x11d1);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x6c));
        (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x70),
                   *(undefined4 *)(original_frame_context + 0x12cc));
        (**(code **)(**(int **)(original_frame_context + 0x12cc) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x12cc),
                   *(undefined4 *)(original_frame_context + 0x1320),
                   *(undefined4 *)(original_frame_context + 0x1324),original_frame_context + 0x1320)
        ;
        (**(code **)(*(int *)(original_frame_context + 0x20) + 0x958))
                  (original_frame_context + 0x12b4);
        iVar8 = *(int *)(original_frame_context + 0x20);
      }
      *(undefined4 *)(original_frame_context + 0x1468) =
           *(undefined4 *)(original_frame_context + 0x16e4);
      if (*(int *)(original_frame_context + 0x1468) == 0) {
        original_frame_context[0x146c] = 0;
        original_frame_context[0x146d] = 0;
        original_frame_context[0x146e] = 0;
        original_frame_context[0x146f] = 0;
      }
      else {
        uVar2 = (**(code **)(iVar8 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x1468),
                           *(undefined4 *)(iVar8 + -0x5444),*(undefined4 *)(iVar8 + -0x7420),0);
        iVar8 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x146c) = uVar2;
      }
      *(undefined4 *)(original_frame_context + 100) =
           *(undefined4 *)(original_frame_context + 0x146c);
      if (*(int *)(original_frame_context + 100) != 0) {
        (**(code **)(iVar8 + -0x506c))(original_frame_context + 0x1330);
        *(undefined4 *)(original_frame_context + 0x60) =
             *(undefined4 *)(*(int *)(original_frame_context + 100) + 0x194);
        *(undefined4 *)(original_frame_context + 0x133c) =
             *(undefined4 *)(*(int *)(original_frame_context + 100) + 0x26c);
        (**(code **)(**(int **)(original_frame_context + 0x60) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0x60),
                   *(undefined4 *)(original_frame_context + 0x133c));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x1330,original_frame_context + 0x133c);
        *(undefined4 *)(original_frame_context + 0x1340) =
             *(undefined4 *)(*(int *)(original_frame_context + 100) + 0x278);
        (**(code **)(**(int **)(original_frame_context + 0x60) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0x60),
                   *(undefined4 *)(original_frame_context + 0x1340));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x1330,original_frame_context + 0x1340);
        *(undefined4 *)(original_frame_context + 0x1344) =
             *(undefined4 *)(*(int *)(original_frame_context + 100) + 0x25c);
        (**(code **)(**(int **)(original_frame_context + 0x60) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0x60),
                   *(undefined4 *)(original_frame_context + 0x1344));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x1330,original_frame_context + 0x1344);
        *(undefined4 *)(original_frame_context + 0x1348) =
             *(undefined4 *)(*(int *)(original_frame_context + 100) + 0x268);
        (**(code **)(**(int **)(original_frame_context + 0x60) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0x60),
                   *(undefined4 *)(original_frame_context + 0x1348));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x1330,original_frame_context + 0x1348);
        *(undefined4 *)(original_frame_context + 0x60) =
             *(undefined4 *)(*(int *)(original_frame_context + 100) + 0x27c);
        *(undefined4 *)(original_frame_context + 0x134c) =
             *(undefined4 *)(*(int *)(original_frame_context + 100) + 0x290);
        (**(code **)(**(int **)(original_frame_context + 0x60) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0x60),
                   *(undefined4 *)(original_frame_context + 0x134c));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x1330,original_frame_context + 0x134c);
        *(undefined4 *)(original_frame_context + 0x60) =
             *(undefined4 *)(*(int *)(original_frame_context + 100) + 0x280);
        *(undefined4 *)(original_frame_context + 0x1350) =
             *(undefined4 *)(*(int *)(original_frame_context + 100) + 0x298);
        (**(code **)(**(int **)(original_frame_context + 0x60) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0x60),
                   *(undefined4 *)(original_frame_context + 0x1350));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x1330,original_frame_context + 0x1350);
        *(undefined4 *)(original_frame_context + 0x60) =
             *(undefined4 *)(*(int *)(original_frame_context + 100) + 0x288);
        *(undefined4 *)(original_frame_context + 0x1354) =
             *(undefined4 *)(*(int *)(original_frame_context + 100) + 0x2a8);
        (**(code **)(**(int **)(original_frame_context + 0x60) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0x60),
                   *(undefined4 *)(original_frame_context + 0x1354));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x1330,original_frame_context + 0x1354);
        *(undefined4 *)(original_frame_context + 0x60) =
             *(undefined4 *)(*(int *)(original_frame_context + 100) + 0x284);
        *(undefined4 *)(original_frame_context + 0x1358) =
             *(undefined4 *)(*(int *)(original_frame_context + 100) + 0x29c);
        (**(code **)(**(int **)(original_frame_context + 0x60) + 0x3c))
                  (*(undefined4 *)(original_frame_context + 0x60),
                   *(undefined4 *)(original_frame_context + 0x1358));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x29a8))
                  (original_frame_context + 0x1330,original_frame_context + 0x1358);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x373c))
                  (original_frame_context + 0x135c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x6be0))
                  (original_frame_context + 0x13c0,original_frame_context + 0x1330);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x135c) =
             *(undefined4 *)(original_frame_context + 0x13c0);
        while( true ) {
          (**(code **)(iVar7 + -0x11cc))
                    (original_frame_context + 0x544,original_frame_context + 0x1330);
          iVar7 = (**(code **)(*(int *)(original_frame_context + 0x20) + 0xed0))
                            (original_frame_context + 0x135c,original_frame_context + 0x544);
          iVar8 = *(int *)(original_frame_context + 0x20);
          if (iVar7 == 0) break;
          puVar5 = (undefined4 *)(**(code **)(iVar8 + -0x55d4))(original_frame_context + 0x135c);
          *(undefined4 *)(original_frame_context + 0x28) = *puVar5;
          uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x45);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x7c) = uVar2;
          uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x80) = uVar2;
          uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x84) = uVar2;
          uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x88) = uVar2;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0x9c) = uVar1;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0x9e) = uVar1;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0xa0) = uVar1;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0xa2) = uVar1;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0xa4) = uVar1;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0xa6) = uVar1;
          (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x28) + 0xb8,0x5cd);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x28) + 0xcc,0x5cd);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x28) + 0xe0,0x5cd);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x28) + 0xf4,0x5cd);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x130) = 0x4ae;
          *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x13c) = 0x4ae;
          *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x148) = 0x4ae;
          *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x154) = 0x4ae;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0x13a) = uVar1;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0x146) = uVar1;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0x152) = uVar1;
          uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0x15e) = uVar1;
          *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x128) = 0x24;
          (**(code **)(iVar7 + -0x75c4))
                    (original_frame_context + 0x540,original_frame_context + 0x135c,0);
          iVar7 = *(int *)(original_frame_context + 0x20);
        }
        *(undefined4 *)(*(int *)(original_frame_context + 0x1348) + 0x128) = 0x21;
        *(undefined4 *)(original_frame_context + 0x1464) =
             *(undefined4 *)(original_frame_context + 0x1348);
        uVar1 = (**(code **)(iVar8 + -0x38a4))(0x3213);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x1464) + 0x13a) = uVar1;
        *(undefined4 *)(original_frame_context + 0x1460) =
             *(undefined4 *)(original_frame_context + 0x1348);
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3213);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x1460) + 0x146) = uVar1;
        *(undefined4 *)(original_frame_context + 0x145c) =
             *(undefined4 *)(original_frame_context + 0x1348);
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3213);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x145c) + 0x152) = uVar1;
        *(undefined4 *)(original_frame_context + 0x1458) =
             *(undefined4 *)(original_frame_context + 0x1348);
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3213);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x1458) + 0x15e) = uVar1;
        pbStack00000010 = (byte *)0x226;
        (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x1360,0,0x1e,0x780);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x1454) = uVar2;
        pbStack00000010 = (byte *)0x4b;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x1454),
                   *(undefined4 *)(*(int *)(original_frame_context + 0x16e4) + 0x38),
                   original_frame_context + 0x1360,0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x5c) =
             *(undefined4 *)(original_frame_context + 0x1454);
        if (*(int *)(original_frame_context + 0x5c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xd26);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x11d4))(*(undefined4 *)(original_frame_context + 0x5c),2,0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x5c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x5c) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x5c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x5c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x5c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x5c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x5c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x5c) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x5c) + 0xb8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x5c) + 0xcc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x5c) + 0xe0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x5c) + 0xf4,0x5cd);
        (**(code **)(**(int **)(*(int *)(original_frame_context + 0x16e4) + 0x38) + 0x34))
                  (*(undefined4 *)(*(int *)(original_frame_context + 0x16e4) + 0x38),
                   *(undefined4 *)(original_frame_context + 0x5c));
        pbStack00000010 = (byte *)0x52;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1360,0x10f,0,0x562);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x1450) = uVar2;
        pbStack00000010 = (byte *)0x4c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x1450),
                   *(undefined4 *)(original_frame_context + 0x5c),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x58) =
             *(undefined4 *)(original_frame_context + 0x1450);
        if (*(int *)(original_frame_context + 0x58) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xd38);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x58) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x58) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x58) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x58) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x58) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x58) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x58) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x58) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x58) + 0xb8,0x137);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x58) + 0xcc,0x137);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x58) + 0xe0,0x137);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x58) + 0xf4,0x137);
        (**(code **)(**(int **)(original_frame_context + 0x5c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x5c),
                   *(undefined4 *)(original_frame_context + 0x58));
        (**(code **)(**(int **)(original_frame_context + 0x58) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x58),
                   *(undefined4 *)(original_frame_context + 0x1348));
        pbStack00000010 = (byte *)0x52;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1360,0,0,0xe6);
        (**(code **)(**(int **)(original_frame_context + 0x1348) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x1348),
                   *(undefined4 *)(original_frame_context + 0x1360),
                   *(undefined4 *)(original_frame_context + 0x1364),original_frame_context + 0x1360)
        ;
        pbStack00000010 = (byte *)0x16c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1360,0x10f,0x72,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x144c) = uVar2;
        pbStack00000010 = (byte *)0x4d;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x144c),
                   *(undefined4 *)(original_frame_context + 0x5c),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x54) =
             *(undefined4 *)(original_frame_context + 0x144c);
        if (*(int *)(original_frame_context + 0x54) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xd52);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x54) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x54) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x54) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x54) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x54) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x54) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x54) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x54) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x54) + 0xb8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x54) + 0xcc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x54) + 0xe0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x54) + 0xf4,0x5cd);
        (**(code **)(**(int **)(original_frame_context + 0x5c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x5c),
                   *(undefined4 *)(original_frame_context + 0x54));
        pbStack00000010 = (byte *)0x40;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1360,0,0,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x1448) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x1448),
                   *(undefined4 *)(original_frame_context + 0x54),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x50) =
             *(undefined4 *)(original_frame_context + 0x1448);
        if (*(int *)(original_frame_context + 0x50) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xd63);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x50) + 0x170,0xeee);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x50) + 0x39) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x50) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x1a);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x1a);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x1a);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x1a);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x54) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x54),
                   *(undefined4 *)(original_frame_context + 0x50));
        pbStack00000010 = (byte *)0x12c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1360,0,0x40,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0xbf8);
        *(undefined4 *)(original_frame_context + 0x1444) = uVar2;
        pbStack00000010 = (byte *)0x4e;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x605c))
                  (*(undefined4 *)(original_frame_context + 0x1444),
                   *(undefined4 *)(original_frame_context + 0x54),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x4c) =
             *(undefined4 *)(original_frame_context + 0x1444);
        if (*(int *)(original_frame_context + 0x4c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xd81);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x4c) + 0x39) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x4c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x4c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x4c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x4c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x4c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x4c) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x4c) + 0xb8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x4c) + 0xcc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x4c) + 0xe0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x4c) + 0xf4,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5b08))
                  (*(undefined4 *)(original_frame_context + 0x4c),0);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2820))
                  (*(undefined4 *)(original_frame_context + 0x4c),5);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x52c,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x518,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x504,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x4f0,0x5cd);
        pbStack00000010 = original_frame_context + 0x4f0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x77c8))
                  (*(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x52c,
                   original_frame_context + 0x518,original_frame_context + 0x504);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x4f0);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x504);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x518);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x52c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x4dc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x4c8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x4b4,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x4a0,0x5cd);
        pbStack00000010 = original_frame_context + 0x4a0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x447c))
                  (*(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x4dc,
                   original_frame_context + 0x4c8,original_frame_context + 0x4b4);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x4a0);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x4b4);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x4c8);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x4dc);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x48c,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x478,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x464,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x450,0x5cd);
        pbStack00000010 = original_frame_context + 0x450;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x17d4))
                  (*(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x48c,
                   original_frame_context + 0x478,original_frame_context + 0x464);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x450);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x464);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x478);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x48c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x43c,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x428,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x414,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x400,0x5cd);
        pbStack00000010 = original_frame_context + 0x400;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4bb4))
                  (*(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x43c,
                   original_frame_context + 0x428,original_frame_context + 0x414);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x400);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x414);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x428);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x43c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x11d4))
                  (*(undefined4 *)(original_frame_context + 0x4c),2,1);
        (**(code **)(**(int **)(original_frame_context + 0x54) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x54),
                   *(undefined4 *)(original_frame_context + 0x4c));
        pbStack00000010 = (byte *)0x16c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1360,0x2e5,0x72,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x1440) = uVar2;
        pbStack00000010 = (byte *)0x4f;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x1440),
                   *(undefined4 *)(original_frame_context + 0x5c),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x48) =
             *(undefined4 *)(original_frame_context + 0x1440);
        if (*(int *)(original_frame_context + 0x48) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xd98);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x48) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x48) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x48) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x48) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x48) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x48) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x48) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x48) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x48) + 0xb8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x48) + 0xcc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x48) + 0xe0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x48) + 0xf4,0x5cd);
        (**(code **)(**(int **)(original_frame_context + 0x5c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x5c),
                   *(undefined4 *)(original_frame_context + 0x48));
        pbStack00000010 = (byte *)0x40;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1360,0,0,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x143c) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x143c),
                   *(undefined4 *)(original_frame_context + 0x48),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x44) =
             *(undefined4 *)(original_frame_context + 0x143c);
        if (*(int *)(original_frame_context + 0x44) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xda9);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x44) + 0x170,0xfa3);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x44) + 0x39) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x44) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x18);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x18);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x18);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x18);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x48) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x48),
                   *(undefined4 *)(original_frame_context + 0x44));
        pbStack00000010 = (byte *)0x12c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1360,0,0x40,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0xbf8);
        *(undefined4 *)(original_frame_context + 0x1438) = uVar2;
        pbStack00000010 = (byte *)0x50;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x605c))
                  (*(undefined4 *)(original_frame_context + 0x1438),
                   *(undefined4 *)(original_frame_context + 0x48),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x40) =
             *(undefined4 *)(original_frame_context + 0x1438);
        if (*(int *)(original_frame_context + 0x40) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xdc7);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x40) + 0x39) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x40) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x40) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x40) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x40) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x40) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x40) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x40) + 0xb8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x40) + 0xcc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x40) + 0xe0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x40) + 0xf4,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5b08))
                  (*(undefined4 *)(original_frame_context + 0x40),0);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2820))
                  (*(undefined4 *)(original_frame_context + 0x40),5);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x3ec,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x3d8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x3c4,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x3b0,0x5cd);
        pbStack00000010 = original_frame_context + 0x3b0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x77c8))
                  (*(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x3ec,
                   original_frame_context + 0x3d8,original_frame_context + 0x3c4);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x3b0);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x3c4);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x3d8);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x3ec);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x39c,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x388,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x374,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x360,0x5cd);
        pbStack00000010 = original_frame_context + 0x360;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x447c))
                  (*(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x39c,
                   original_frame_context + 0x388,original_frame_context + 0x374);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x360);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x374);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x388);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x39c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x34c,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x338,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x324,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x310,0x5cd);
        pbStack00000010 = original_frame_context + 0x310;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x17d4))
                  (*(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x34c,
                   original_frame_context + 0x338,original_frame_context + 0x324);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x310);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x324);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x338);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x34c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x2fc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x2e8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x2d4,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x2c0,0x5cd);
        pbStack00000010 = original_frame_context + 0x2c0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4bb4))
                  (*(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x2fc,
                   original_frame_context + 0x2e8,original_frame_context + 0x2d4);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x2c0);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x2d4);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x2e8);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x2fc);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x11d4))
                  (*(undefined4 *)(original_frame_context + 0x40),2,1);
        (**(code **)(**(int **)(original_frame_context + 0x48) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x48),
                   *(undefined4 *)(original_frame_context + 0x40));
        pbStack00000010 = (byte *)0x16c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1360,0x4bb,0x72,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x1434) = uVar2;
        pbStack00000010 = (byte *)0x51;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x1434),
                   *(undefined4 *)(original_frame_context + 0x5c),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x3c) =
             *(undefined4 *)(original_frame_context + 0x1434);
        if (*(int *)(original_frame_context + 0x3c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xdde);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x3c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x3c) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x3c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x3c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x3c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x3c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x3c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x3c) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x3c) + 0xb8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x3c) + 0xcc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x3c) + 0xe0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x3c) + 0xf4,0x5cd);
        (**(code **)(**(int **)(original_frame_context + 0x5c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x5c),
                   *(undefined4 *)(original_frame_context + 0x3c));
        pbStack00000010 = (byte *)0x40;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1360,0,0,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x1430) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x1430),
                   *(undefined4 *)(original_frame_context + 0x3c),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x38) =
             *(undefined4 *)(original_frame_context + 0x1430);
        if (*(int *)(original_frame_context + 0x38) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xdef);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x38) + 0x170,0xdcc);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x38) + 0x39) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x38) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x19);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x19);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x19);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x19);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x3c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x3c),
                   *(undefined4 *)(original_frame_context + 0x38));
        pbStack00000010 = (byte *)0x12c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1360,0,0x40,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0xbf8);
        *(undefined4 *)(original_frame_context + 0x142c) = uVar2;
        pbStack00000010 = (byte *)0x52;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x605c))
                  (*(undefined4 *)(original_frame_context + 0x142c),
                   *(undefined4 *)(original_frame_context + 0x3c),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x34) =
             *(undefined4 *)(original_frame_context + 0x142c);
        if (*(int *)(original_frame_context + 0x34) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xe0d);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x34) + 0x39) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x34) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x34) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x34) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x34) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x34) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x34) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x34) + 0xb8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x34) + 0xcc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x34) + 0xe0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x34) + 0xf4,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5b08))
                  (*(undefined4 *)(original_frame_context + 0x34),0);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2820))
                  (*(undefined4 *)(original_frame_context + 0x34),5);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x2ac,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x298,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x284,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x270,0x5cd);
        pbStack00000010 = original_frame_context + 0x270;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x77c8))
                  (*(undefined4 *)(original_frame_context + 0x34),original_frame_context + 0x2ac,
                   original_frame_context + 0x298,original_frame_context + 0x284);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x270);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x284);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x298);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x2ac);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x25c,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x248,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x234,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x220,0x5cd);
        pbStack00000010 = original_frame_context + 0x220;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x447c))
                  (*(undefined4 *)(original_frame_context + 0x34),original_frame_context + 0x25c,
                   original_frame_context + 0x248,original_frame_context + 0x234);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x220);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x234);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x248);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x25c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x20c,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x1f8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x1e4,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x1d0,0x5cd);
        pbStack00000010 = original_frame_context + 0x1d0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x17d4))
                  (*(undefined4 *)(original_frame_context + 0x34),original_frame_context + 0x20c,
                   original_frame_context + 0x1f8,original_frame_context + 0x1e4);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x1d0);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x1e4);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x1f8);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x20c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x1bc,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x1a8,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x194,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x180,0x5cd);
        pbStack00000010 = original_frame_context + 0x180;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4bb4))
                  (*(undefined4 *)(original_frame_context + 0x34),original_frame_context + 0x1bc,
                   original_frame_context + 0x1a8,original_frame_context + 0x194);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x180);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x194);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x1a8);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x1bc);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x11d4))
                  (*(undefined4 *)(original_frame_context + 0x34),2,1);
        (**(code **)(**(int **)(original_frame_context + 0x3c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x3c),
                   *(undefined4 *)(original_frame_context + 0x34));
        pbStack00000010 = (byte *)0x3c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1360,0,0,0x1b7);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x1428) = uVar2;
        pbStack00000010 = (byte *)0x53;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x1428),
                   *(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x30) =
             *(undefined4 *)(original_frame_context + 0x1428);
        if (*(int *)(original_frame_context + 0x30) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xe24);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x4c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x4c),
                   *(undefined4 *)(original_frame_context + 0x30));
        pbStack00000010 = (byte *)0x3a;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1370,0x117,0,0xa0);
        pbStack00000010 = (byte *)0x3a;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1380,0,0,0x117);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x1424) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x1424),
                   *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x2c) =
             *(undefined4 *)(original_frame_context + 0x1424);
        if (*(int *)(original_frame_context + 0x2c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xe38);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0x11db);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x2c));
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x1340));
        (**(code **)(**(int **)(original_frame_context + 0x1340) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x1340),
                   *(undefined4 *)(original_frame_context + 0x1370),
                   *(undefined4 *)(original_frame_context + 0x1374),original_frame_context + 0x1370)
        ;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x1420) = uVar2;
        pbStack00000010 = (byte *)0x54;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x1420),
                   *(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x30) =
             *(undefined4 *)(original_frame_context + 0x1420);
        if (*(int *)(original_frame_context + 0x30) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xe57);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x4c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x4c),
                   *(undefined4 *)(original_frame_context + 0x30));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x141c) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x141c),
                   *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x2c) =
             *(undefined4 *)(original_frame_context + 0x141c);
        if (*(int *)(original_frame_context + 0x2c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xe67);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0xcda);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x2c));
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x134c));
        (**(code **)(**(int **)(original_frame_context + 0x134c) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x134c),
                   *(undefined4 *)(original_frame_context + 0x1370),
                   *(undefined4 *)(original_frame_context + 0x1374),original_frame_context + 0x1370)
        ;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x1418) = uVar2;
        pbStack00000010 = (byte *)0x55;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x1418),
                   *(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x30) =
             *(undefined4 *)(original_frame_context + 0x1418);
        if (*(int *)(original_frame_context + 0x30) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xe86);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x4c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x4c),
                   *(undefined4 *)(original_frame_context + 0x30));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x1414) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x1414),
                   *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x2c) =
             *(undefined4 *)(original_frame_context + 0x1414);
        if (*(int *)(original_frame_context + 0x2c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xe96);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0xed0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x2c));
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x1350));
        (**(code **)(**(int **)(original_frame_context + 0x1350) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x1350),
                   *(undefined4 *)(original_frame_context + 0x1370),
                   *(undefined4 *)(original_frame_context + 0x1374),original_frame_context + 0x1370)
        ;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x1410) = uVar2;
        pbStack00000010 = (byte *)0x56;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x1410),
                   *(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x30) =
             *(undefined4 *)(original_frame_context + 0x1410);
        if (*(int *)(original_frame_context + 0x30) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xeb5);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x4c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x4c),
                   *(undefined4 *)(original_frame_context + 0x30));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x140c) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x140c),
                   *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x2c) =
             *(undefined4 *)(original_frame_context + 0x140c);
        if (*(int *)(original_frame_context + 0x2c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xec5);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0xc15);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x2c));
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x1358));
        (**(code **)(**(int **)(original_frame_context + 0x1358) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x1358),
                   *(undefined4 *)(original_frame_context + 0x1370),
                   *(undefined4 *)(original_frame_context + 0x1374),original_frame_context + 0x1370)
        ;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x1408) = uVar2;
        pbStack00000010 = (byte *)0x57;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x1408),
                   *(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x30) =
             *(undefined4 *)(original_frame_context + 0x1408);
        if (*(int *)(original_frame_context + 0x30) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xee4);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x4c) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x4c),
                   *(undefined4 *)(original_frame_context + 0x30));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x1404) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x1404),
                   *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x2c) =
             *(undefined4 *)(original_frame_context + 0x1404);
        if (*(int *)(original_frame_context + 0x2c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xef4);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0xcbd);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x2c));
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x1354));
        (**(code **)(**(int **)(original_frame_context + 0x1354) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x1354),
                   *(undefined4 *)(original_frame_context + 0x1370),
                   *(undefined4 *)(original_frame_context + 0x1374),original_frame_context + 0x1370)
        ;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x1400) = uVar2;
        pbStack00000010 = (byte *)0x58;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x1400),
                   *(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x30) =
             *(undefined4 *)(original_frame_context + 0x1400);
        if (*(int *)(original_frame_context + 0x30) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xf13);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x40) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x40),
                   *(undefined4 *)(original_frame_context + 0x30));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x13fc) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x13fc),
                   *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x2c) =
             *(undefined4 *)(original_frame_context + 0x13fc);
        if (*(int *)(original_frame_context + 0x2c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xf23);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0xfa1);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x2c));
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x1344));
        pbStack00000010 = *(byte **)(original_frame_context + 0x137c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x1390,*(int *)(original_frame_context + 0x1370) + -0x5a
                   ,*(undefined4 *)(original_frame_context + 0x1374),
                   *(int *)(original_frame_context + 0x1378) + 0x5a);
        (**(code **)(**(int **)(original_frame_context + 0x1344) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x1344),
                   *(undefined4 *)(original_frame_context + 0x1390),
                   *(undefined4 *)(original_frame_context + 0x1394),original_frame_context + 0x1390)
        ;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x13f8) = uVar2;
        pbStack00000010 = (byte *)0x59;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x13f8),
                   *(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x30) =
             *(undefined4 *)(original_frame_context + 0x13f8);
        if (*(int *)(original_frame_context + 0x30) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xf44);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x11d4))(*(undefined4 *)(original_frame_context + 0x30),2,0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x40) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x40),
                   *(undefined4 *)(original_frame_context + 0x30));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x13f4) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x13f4),
                   *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x2c) =
             *(undefined4 *)(original_frame_context + 0x13f4);
        if (*(int *)(original_frame_context + 0x2c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xf55);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0xeb4);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x2c));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x13f0) = uVar2;
        pbStack00000010 = (byte *)0x5a;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x13f0),
                   *(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x30) =
             *(undefined4 *)(original_frame_context + 0x13f0);
        if (*(int *)(original_frame_context + 0x30) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xf72);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x11d4))(*(undefined4 *)(original_frame_context + 0x5c),2,0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x40) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x40),
                   *(undefined4 *)(original_frame_context + 0x30));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x13ec) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x13ec),
                   *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x2c) =
             *(undefined4 *)(original_frame_context + 0x13ec);
        if (*(int *)(original_frame_context + 0x2c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xf83);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0x1115);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x2c));
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x133c));
        (**(code **)(**(int **)(original_frame_context + 0x133c) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x133c),
                   *(undefined4 *)(original_frame_context + 0x1390),
                   *(undefined4 *)(original_frame_context + 0x1394),original_frame_context + 0x1390)
        ;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x13e8) = uVar2;
        pbStack00000010 = (byte *)0x5b;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x13e8),
                   *(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x30) =
             *(undefined4 *)(original_frame_context + 0x13e8);
        if (*(int *)(original_frame_context + 0x30) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xfa2);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x11d4))(*(undefined4 *)(original_frame_context + 0x5c),2,0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x40) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x40),
                   *(undefined4 *)(original_frame_context + 0x30));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x13e4) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x13e4),
                   *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x2c) =
             *(undefined4 *)(original_frame_context + 0x13e4);
        if (*(int *)(original_frame_context + 0x2c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xfb3);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0xeb1);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x2c));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x13e0) = uVar2;
        pbStack00000010 = (byte *)0x5d;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x13e0),
                   *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x2c) =
             *(undefined4 *)(original_frame_context + 0x13e0);
        if (*(int *)(original_frame_context + 0x2c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xfd2);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(int *)(original_frame_context + 0x13dc) = *(int *)(original_frame_context + 0x2c) + 0x170;
        (**(code **)(iVar7 + -0x59f0))(original_frame_context + 0x178);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x7374))
                  (original_frame_context + 0x17c,
                   *(int *)(*(int *)(original_frame_context + 0x20) + -0x7fdc) + 0x7b94,
                   original_frame_context + 0x178);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0xf74))
                  (*(undefined4 *)(original_frame_context + 0x13dc),original_frame_context + 0x17c);
        *(byte **)(original_frame_context + 0x13d8) = original_frame_context + 0x17c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x72a0))
                  (*(undefined4 *)(original_frame_context + 0x13d8));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x79c8))
                  (original_frame_context + 0x178);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x128) = 0x24;
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x2c));
        pbStack00000010 = *(byte **)(original_frame_context + 0x137c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x13a0,*(int *)(original_frame_context + 0x1370) + -0x5a
                   ,*(undefined4 *)(original_frame_context + 0x1374),
                   *(int *)(original_frame_context + 0x1378) + 0x5a);
        (**(code **)(**(int **)(original_frame_context + 0x2c) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x2c),
                   *(undefined4 *)(original_frame_context + 0x13a0),
                   *(undefined4 *)(original_frame_context + 0x13a4),original_frame_context + 0x13a0)
        ;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
        *(undefined4 *)(original_frame_context + 0x13d4) = uVar2;
        pbStack00000010 = (byte *)0x5c;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
                  (*(undefined4 *)(original_frame_context + 0x13d4),
                   *(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x1360,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x30) =
             *(undefined4 *)(original_frame_context + 0x13d4);
        if (*(int *)(original_frame_context + 0x30) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0xff2);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x11d4))(*(undefined4 *)(original_frame_context + 0x5c),2,0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
        *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
        (**(code **)(**(int **)(original_frame_context + 0x40) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x40),
                   *(undefined4 *)(original_frame_context + 0x30));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x13d0) = uVar2;
        pbStack00000010 = (byte *)0x0;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x13d0),
                   *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x2c) =
             *(undefined4 *)(original_frame_context + 0x13d0);
        if (*(int *)(original_frame_context + 0x2c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0x1003);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        (**(code **)(iVar7 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0x11d1);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x128) = 0x21;
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x2c));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
        *(undefined4 *)(original_frame_context + 0x13cc) = uVar2;
        pbStack00000010 = (byte *)0x5e;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
                  (*(undefined4 *)(original_frame_context + 0x13cc),
                   *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x2c) =
             *(undefined4 *)(original_frame_context + 0x13cc);
        if (*(int *)(original_frame_context + 0x2c) == 0) {
          (**(code **)(iVar7 + -0x2400))
                    (*(int *)(iVar7 + -0x7fdc) + 0x7b18,*(int *)(iVar7 + -0x7fdc) + 0x7b34,
                     *(int *)(iVar7 + -0x7fdc) + 0x7cf8,0x1022);
          iVar7 = *(int *)(original_frame_context + 0x20);
          (**(code **)(iVar7 + 0x3b0))();
        }
        *(int *)(original_frame_context + 0x13c8) = *(int *)(original_frame_context + 0x2c) + 0x170;
        (**(code **)(iVar7 + -0x59f0))(original_frame_context + 0x170);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x7374))
                  (original_frame_context + 0x174,
                   *(int *)(*(int *)(original_frame_context + 0x20) + -0x7fdc) + 0x7b98,
                   original_frame_context + 0x170);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0xf74))
                  (*(undefined4 *)(original_frame_context + 0x13c8),original_frame_context + 0x174);
        *(byte **)(original_frame_context + 0x13c4) = original_frame_context + 0x174;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x72a0))
                  (*(undefined4 *)(original_frame_context + 0x13c4));
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x79c8))
                  (original_frame_context + 0x170);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
        *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar2;
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar2;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45de);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f5);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f9);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x15e) = uVar1;
        *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x128) = 0x24;
        (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                  (*(undefined4 *)(original_frame_context + 0x30),
                   *(undefined4 *)(original_frame_context + 0x2c));
        pbStack00000010 = *(byte **)(original_frame_context + 0x137c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                  (original_frame_context + 0x13b0,*(int *)(original_frame_context + 0x1370) + -0x5a
                   ,*(undefined4 *)(original_frame_context + 0x1374),
                   *(int *)(original_frame_context + 0x1378) + 0x5a);
        (**(code **)(**(int **)(original_frame_context + 0x2c) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0x2c),
                   *(undefined4 *)(original_frame_context + 0x13b0),
                   *(undefined4 *)(original_frame_context + 0x13b4),original_frame_context + 0x13b0)
        ;
        (**(code **)(*(int *)(original_frame_context + 0x20) + 0x958))
                  (original_frame_context + 0x1330);
        iVar8 = *(int *)(original_frame_context + 0x20);
      }
      (**(code **)(iVar8 + -0x2dec))(original_frame_context + 0x124c);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x6a30))
                (original_frame_context + 0x1240);
      uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x6a30))
                        (original_frame_context + 0x11f4);
      return uVar2;
    }
    puVar5 = (undefined4 *)(**(code **)(iVar8 + 0x81c))(original_frame_context + 0x1258);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0xd8) = *puVar5;
    *(undefined4 *)(original_frame_context + 0x1618) =
         *(undefined4 *)(original_frame_context + 0x16e4);
    if (*(int *)(original_frame_context + 0x1618) == 0) {
LAB_0056657c:
      *(undefined4 *)(original_frame_context + 0x160c) =
           *(undefined4 *)(original_frame_context + 0x16e4);
      if (*(int *)(original_frame_context + 0x160c) != 0) {
        iVar8 = (**(code **)(iVar7 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x160c),
                           *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x5b6c),0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        if (iVar8 != 0) {
          *(undefined4 *)(original_frame_context + 0x1604) =
               *(undefined4 *)(original_frame_context + 0x16e4);
          if (*(int *)(original_frame_context + 0x1604) == 0) {
            original_frame_context[0x1608] = 0;
            original_frame_context[0x1609] = 0;
            original_frame_context[0x160a] = 0;
            original_frame_context[0x160b] = 0;
          }
          else {
            uVar2 = (**(code **)(iVar7 + -0x598c))
                              (*(undefined4 *)(original_frame_context + 0x1604),
                               *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x5b6c),0);
            iVar7 = *(int *)(original_frame_context + 0x20);
            *(undefined4 *)(original_frame_context + 0x1608) = uVar2;
          }
          if (*(int *)(*(int *)(original_frame_context + 0x1608) + 0x19c) ==
              *(int *)(original_frame_context + 0xd8)) goto LAB_005666a4;
        }
      }
      *(undefined4 *)(original_frame_context + 0x1600) =
           *(undefined4 *)(original_frame_context + 0x16e4);
      if (*(int *)(original_frame_context + 0x1600) != 0) {
        iVar8 = (**(code **)(iVar7 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x1600),
                           *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x6228),0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        if (iVar8 != 0) {
          *(undefined4 *)(original_frame_context + 0x15f8) =
               *(undefined4 *)(original_frame_context + 0x16e4);
          if (*(int *)(original_frame_context + 0x15f8) == 0) {
            original_frame_context[0x15fc] = 0;
            original_frame_context[0x15fd] = 0;
            original_frame_context[0x15fe] = 0;
            original_frame_context[0x15ff] = 0;
          }
          else {
            uVar2 = (**(code **)(iVar7 + -0x598c))
                              (*(undefined4 *)(original_frame_context + 0x15f8),
                               *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x6228),0);
            iVar7 = *(int *)(original_frame_context + 0x20);
            *(undefined4 *)(original_frame_context + 0x15fc) = uVar2;
          }
          if (*(int *)(*(int *)(original_frame_context + 0x15fc) + 0x1fc) ==
              *(int *)(original_frame_context + 0xd8)) goto LAB_005666a4;
        }
      }
      original_frame_context[0x161c] = 0;
      original_frame_context[0x161d] = 0;
      original_frame_context[0x161e] = 0;
      original_frame_context[0x161f] = 0;
    }
    else {
      iVar8 = (**(code **)(iVar7 + -0x598c))
                        (*(undefined4 *)(original_frame_context + 0x1618),
                         *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x7420),0);
      iVar7 = *(int *)(original_frame_context + 0x20);
      if (iVar8 == 0) goto LAB_0056657c;
      *(undefined4 *)(original_frame_context + 0x1610) =
           *(undefined4 *)(original_frame_context + 0x16e4);
      if (*(int *)(original_frame_context + 0x1610) == 0) {
        original_frame_context[0x1614] = 0;
        original_frame_context[0x1615] = 0;
        original_frame_context[0x1616] = 0;
        original_frame_context[0x1617] = 0;
      }
      else {
        uVar2 = (**(code **)(iVar7 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x1610),
                           *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x7420),0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x1614) = uVar2;
      }
      if (*(int *)(*(int *)(original_frame_context + 0x1614) + 0x1d0) !=
          *(int *)(original_frame_context + 0xd8)) goto LAB_0056657c;
LAB_005666a4:
      original_frame_context[0x161c] = 1;
      original_frame_context[0x161d] = 0;
      original_frame_context[0x161e] = 0;
      original_frame_context[0x161f] = 0;
    }
    if (*(int *)(original_frame_context + 0x161c) == 0) {
      *(undefined4 *)(original_frame_context + 0x15e0) =
           *(undefined4 *)(original_frame_context + 0x16e4);
      if (*(int *)(original_frame_context + 0x15e0) == 0) {
LAB_005669e8:
        original_frame_context[0x15e4] = 0;
        original_frame_context[0x15e5] = 0;
        original_frame_context[0x15e6] = 0;
        original_frame_context[0x15e7] = 0;
      }
      else {
        iVar8 = (**(code **)(iVar7 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x15e0),
                           *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x38e0),0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        if (iVar8 == 0) goto LAB_005669e8;
        *(undefined4 *)(original_frame_context + 0x15d8) =
             *(undefined4 *)(original_frame_context + 0x16e4);
        if (*(int *)(original_frame_context + 0x15d8) == 0) {
          original_frame_context[0x15dc] = 0;
          original_frame_context[0x15dd] = 0;
          original_frame_context[0x15de] = 0;
          original_frame_context[0x15df] = 0;
        }
        else {
          uVar2 = (**(code **)(iVar7 + -0x598c))
                            (*(undefined4 *)(original_frame_context + 0x15d8),
                             *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x38e0),0);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined4 *)(original_frame_context + 0x15dc) = uVar2;
        }
        if (*(int *)(*(int *)(original_frame_context + 0x15dc) + 0x1f8) !=
            *(int *)(original_frame_context + 0xd8)) goto LAB_005669e8;
        original_frame_context[0x15e4] = 1;
        original_frame_context[0x15e5] = 0;
        original_frame_context[0x15e6] = 0;
        original_frame_context[0x15e7] = 0;
      }
      if (((*(uint *)(original_frame_context + 0x15e4) ^ 1) & 0xff) != 0) {
        pbStack00000010 = (byte *)0x1fe;
        (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x1284,0x10f,0x1e,0x562);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2820))
                  (*(undefined4 *)(original_frame_context + 0xd8),6);
        (**(code **)(**(int **)(original_frame_context + 0xd8) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0xd8),
                   *(undefined4 *)(original_frame_context + 0x1284),
                   *(undefined4 *)(original_frame_context + 0x1288),original_frame_context + 0x1284)
        ;
        iVar7 = *(int *)(original_frame_context + 0x20);
      }
    }
    else {
      uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
      iVar7 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xd8) + 0x9c) = uVar1;
      uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
      iVar7 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xd8) + 0x9e) = uVar1;
      uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
      iVar7 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xd8) + 0xa0) = uVar1;
      uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
      iVar7 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xd8) + 0xa2) = uVar1;
      uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
      iVar7 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xd8) + 0xa4) = uVar1;
      uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
      iVar7 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xd8) + 0xa6) = uVar1;
      pbStack00000010 = (byte *)0x1fe;
      (**(code **)(iVar7 + -0x2b00))(original_frame_context + 0x1284,0x10f,0x4f,0x562);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2820))
                (*(undefined4 *)(original_frame_context + 0xd8),6);
      (**(code **)(**(int **)(original_frame_context + 0xd8) + 0x24))
                (*(undefined4 *)(original_frame_context + 0xd8),
                 *(undefined4 *)(original_frame_context + 0x1284),
                 *(undefined4 *)(original_frame_context + 0x1288),original_frame_context + 0x1284);
      iVar7 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(original_frame_context + 0x15f0) =
           *(undefined4 *)(original_frame_context + 0x16e4);
      if (*(int *)(original_frame_context + 0x15f0) == 0) {
LAB_005668a4:
        original_frame_context[0x15f4] = 0;
        original_frame_context[0x15f5] = 0;
        original_frame_context[0x15f6] = 0;
        original_frame_context[0x15f7] = 0;
      }
      else {
        iVar8 = (**(code **)(iVar7 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x15f0),
                           *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x6228),0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        if (iVar8 == 0) goto LAB_005668a4;
        *(undefined4 *)(original_frame_context + 0x15e8) =
             *(undefined4 *)(original_frame_context + 0x16e4);
        if (*(int *)(original_frame_context + 0x15e8) == 0) {
          original_frame_context[0x15ec] = 0;
          original_frame_context[0x15ed] = 0;
          original_frame_context[0x15ee] = 0;
          original_frame_context[0x15ef] = 0;
        }
        else {
          uVar2 = (**(code **)(iVar7 + -0x598c))
                            (*(undefined4 *)(original_frame_context + 0x15e8),
                             *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x6228),0);
          iVar7 = *(int *)(original_frame_context + 0x20);
          *(undefined4 *)(original_frame_context + 0x15ec) = uVar2;
        }
        if (*(int *)(*(int *)(original_frame_context + 0x15ec) + 0x1fc) !=
            *(int *)(original_frame_context + 0xd8)) goto LAB_005668a4;
        original_frame_context[0x15f4] = 1;
        original_frame_context[0x15f5] = 0;
        original_frame_context[0x15f6] = 0;
        original_frame_context[0x15f7] = 0;
      }
      if (*(int *)(original_frame_context + 0x15f4) != 0) {
        original_frame_context[0xd4] = 0;
        original_frame_context[0xd5] = 0;
        original_frame_context[0xd6] = 0;
        original_frame_context[0xd7] = 0;
        while( true ) {
          uVar3 = (**(code **)(**(int **)(original_frame_context + 0xd8) + 0x44))
                            (*(undefined4 *)(original_frame_context + 0xd8));
          iVar7 = *(int *)(original_frame_context + 0x20);
          if (uVar3 <= *(uint *)(original_frame_context + 0xd4)) break;
          iVar7 = (**(code **)(**(int **)(original_frame_context + 0xd8) + 0x40))
                            (*(undefined4 *)(original_frame_context + 0xd8),
                             *(undefined4 *)(original_frame_context + 0xd4));
          *(undefined1 *)(iVar7 + 0x38) = 1;
          *(int *)(original_frame_context + 0xd4) = *(int *)(original_frame_context + 0xd4) + 1;
        }
      }
    }
    uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45ea);
    iVar7 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xd8) + 0x9e) = uVar1;
    (**(code **)(iVar7 + -0x5b08))(*(undefined4 *)(original_frame_context + 0xd8),8);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xae0,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xacc,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xab8,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xaa4,0x5cd);
    pbStack00000010 = original_frame_context + 0xaa4;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x77c8))
              (*(undefined4 *)(original_frame_context + 0xd8),original_frame_context + 0xae0,
               original_frame_context + 0xacc,original_frame_context + 0xab8);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xaa4)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xab8)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xacc)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xae0)
    ;
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(1);
    *(undefined4 *)(original_frame_context + 0x15d4) = uVar2;
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(1);
    *(undefined4 *)(original_frame_context + 0x15d0) = uVar2;
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(1);
    *(undefined4 *)(original_frame_context + 0x15cc) = uVar2;
    pbStack00000010 = (byte *)(**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(1);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x769c))
              (*(undefined4 *)(original_frame_context + 0xd8),
               *(undefined4 *)(original_frame_context + 0x15d4),
               *(undefined4 *)(original_frame_context + 0x15d0),
               *(undefined4 *)(original_frame_context + 0x15cc));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xa90,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xa7c,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xa68,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xa54,0x5cd);
    pbStack00000010 = original_frame_context + 0xa54;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x447c))
              (*(undefined4 *)(original_frame_context + 0xd8),original_frame_context + 0xa90,
               original_frame_context + 0xa7c,original_frame_context + 0xa68);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xa54)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xa68)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xa7c)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xa90)
    ;
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x51);
    *(undefined4 *)(original_frame_context + 0x15c8) = uVar2;
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x51);
    *(undefined4 *)(original_frame_context + 0x15c4) = uVar2;
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x51);
    *(undefined4 *)(original_frame_context + 0x15c0) = uVar2;
    pbStack00000010 = (byte *)(**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x51)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4e28))
              (*(undefined4 *)(original_frame_context + 0xd8),
               *(undefined4 *)(original_frame_context + 0x15c8),
               *(undefined4 *)(original_frame_context + 0x15c4),
               *(undefined4 *)(original_frame_context + 0x15c0));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xa40,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xa2c,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xa18,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xa04,0x5cd);
    pbStack00000010 = original_frame_context + 0xa04;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x17d4))
              (*(undefined4 *)(original_frame_context + 0xd8),original_frame_context + 0xa40,
               original_frame_context + 0xa2c,original_frame_context + 0xa18);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xa04)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xa18)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xa2c)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xa40)
    ;
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x46);
    *(undefined4 *)(original_frame_context + 0x15bc) = uVar2;
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x46);
    *(undefined4 *)(original_frame_context + 0x15b8) = uVar2;
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x46);
    *(undefined4 *)(original_frame_context + 0x15b4) = uVar2;
    pbStack00000010 = (byte *)(**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x46)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5334))
              (*(undefined4 *)(original_frame_context + 0xd8),
               *(undefined4 *)(original_frame_context + 0x15bc),
               *(undefined4 *)(original_frame_context + 0x15b8),
               *(undefined4 *)(original_frame_context + 0x15b4));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x9f0,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x9dc,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x9c8,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x9b4,0x5cd);
    pbStack00000010 = original_frame_context + 0x9b4;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4bb4))
              (*(undefined4 *)(original_frame_context + 0xd8),original_frame_context + 0x9f0,
               original_frame_context + 0x9dc,original_frame_context + 0x9c8);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x9b4)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x9c8)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x9dc)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x9f0)
    ;
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x51);
    *(undefined4 *)(original_frame_context + 0x15b0) = uVar2;
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x51);
    *(undefined4 *)(original_frame_context + 0x15ac) = uVar2;
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x51);
    *(undefined4 *)(original_frame_context + 0x15a8) = uVar2;
    pbStack00000010 = (byte *)(**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x51)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3018))
              (*(undefined4 *)(original_frame_context + 0xd8),
               *(undefined4 *)(original_frame_context + 0x15b0),
               *(undefined4 *)(original_frame_context + 0x15ac),
               *(undefined4 *)(original_frame_context + 0x15a8));
    *(undefined1 *)(*(int *)(original_frame_context + 0xd8) + 0x51d) = 0;
    *(undefined1 *)(*(int *)(original_frame_context + 0xd8) + 0x76d) = 0;
    *(undefined1 *)(*(int *)(original_frame_context + 0xd8) + 0xb27) = 0;
    original_frame_context[0xd0] = 0;
    original_frame_context[0xd1] = 0;
    original_frame_context[0xd2] = 0;
    original_frame_context[0xd3] = 0;
    while (uVar3 = (**(code **)(**(int **)(original_frame_context + 0xd8) + 0x44))
                             (*(undefined4 *)(original_frame_context + 0xd8)),
          *(uint *)(original_frame_context + 0xd0) < uVar3) {
      uVar2 = (**(code **)(**(int **)(original_frame_context + 0xd8) + 0x40))
                        (*(undefined4 *)(original_frame_context + 0xd8),
                         *(undefined4 *)(original_frame_context + 0xd0));
      *(undefined4 *)(original_frame_context + 0xcc) = uVar2;
      uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x45f7);
      iVar7 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0x9c) = uVar1;
      uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f7);
      iVar7 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0x9e) = uVar1;
      uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
      iVar7 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0xa0) = uVar1;
      uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
      iVar7 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0xa2) = uVar1;
      uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
      iVar7 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0xa4) = uVar1;
      uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45dd);
      iVar7 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0xa6) = uVar1;
      (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0xcc) + 0xb8,0x4ac);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0xcc) + 0xcc,0x122);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0xcc) + 0xe0,0x122);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0xcc) + 0xf4,0x122);
      uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x5e);
      iVar7 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(*(int *)(original_frame_context + 0xcc) + 0x84) = uVar2;
      uVar2 = (**(code **)(iVar7 + -0x5868))(0x13);
      pbStack00000010 = (byte *)0x0;
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))
                (*(undefined4 *)(original_frame_context + 0xcc),1,uVar2,0xf);
      iVar7 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(original_frame_context + 0x15a0) =
           *(undefined4 *)(original_frame_context + 0xcc);
      if (*(int *)(original_frame_context + 0x15a0) == 0) {
        original_frame_context[0x15a4] = 0;
        original_frame_context[0x15a5] = 0;
        original_frame_context[0x15a6] = 0;
        original_frame_context[0x15a7] = 0;
      }
      else {
        uVar2 = (**(code **)(iVar7 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x15a0),
                           *(undefined4 *)(iVar7 + -0x2dd4),*(undefined4 *)(iVar7 + -0x7558),0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x15a4) = uVar2;
      }
      *(undefined4 *)(original_frame_context + 200) =
           *(undefined4 *)(original_frame_context + 0x15a4);
      if (*(int *)(original_frame_context + 200) != 0) {
        *(undefined2 *)(*(int *)(*(int *)(original_frame_context + 200) + 0x260) + 0x9e) = 0x46;
        *(undefined4 *)(original_frame_context + 0x159c) =
             *(undefined4 *)(*(int *)(original_frame_context + 200) + 0x25c);
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f7);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x159c) + 0x9c) = uVar1;
        *(undefined4 *)(original_frame_context + 0x1598) =
             *(undefined4 *)(*(int *)(original_frame_context + 200) + 0x25c);
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x5e);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1598) + 0x84) = uVar2;
        *(undefined4 *)(original_frame_context + 0x1594) =
             *(undefined4 *)(*(int *)(original_frame_context + 200) + 0x260);
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x5e);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1594) + 0x84) = uVar2;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 200) + 0xb8,0x4ac);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 200) + 0xcc,0x122);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 200) + 0xe0,0x122);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 200) + 0xf4,0x122);
        iVar7 = *(int *)(original_frame_context + 0x20);
      }
      *(undefined4 *)(original_frame_context + 0x158c) =
           *(undefined4 *)(original_frame_context + 0xcc);
      if (*(int *)(original_frame_context + 0x158c) == 0) {
        original_frame_context[0x1590] = 0;
        original_frame_context[0x1591] = 0;
        original_frame_context[0x1592] = 0;
        original_frame_context[0x1593] = 0;
      }
      else {
        uVar2 = (**(code **)(iVar7 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x158c),
                           *(undefined4 *)(iVar7 + -0x2dd4),*(undefined4 *)(iVar7 + -0x71d0),0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x1590) = uVar2;
      }
      *(undefined4 *)(original_frame_context + 0xc4) =
           *(undefined4 *)(original_frame_context + 0x1590);
      if (*(int *)(original_frame_context + 0xc4) != 0) {
        *(undefined2 *)(*(int *)(original_frame_context + 0xc4) + 0x9e) = 0x46;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f7);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0xc4) + 0x9c) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0xc4) + 0xb8,0x4ac);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xc4) + 0xcc,0x122);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xc4) + 0xe0,0x122);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xc4) + 0xf4,0x122);
        iVar7 = *(int *)(original_frame_context + 0x20);
      }
      *(undefined4 *)(original_frame_context + 0x1584) =
           *(undefined4 *)(original_frame_context + 0xcc);
      if (*(int *)(original_frame_context + 0x1584) == 0) {
        original_frame_context[0x1588] = 0;
        original_frame_context[0x1589] = 0;
        original_frame_context[0x158a] = 0;
        original_frame_context[0x158b] = 0;
      }
      else {
        uVar2 = (**(code **)(iVar7 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x1584),
                           *(undefined4 *)(iVar7 + -0x2dd4),*(undefined4 *)(iVar7 + -0x7878),0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x1588) = uVar2;
      }
      *(undefined4 *)(original_frame_context + 0xc0) =
           *(undefined4 *)(original_frame_context + 0x1588);
      if (*(int *)(original_frame_context + 0xc0) != 0) {
        *(undefined2 *)(*(int *)(*(int *)(original_frame_context + 0xc0) + 0x264) + 0x9e) = 0x46;
        *(undefined4 *)(original_frame_context + 0x1580) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xc0) + 0x260);
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f7);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x1580) + 0x9c) = uVar1;
        *(undefined4 *)(original_frame_context + 0x157c) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xc0) + 0x260);
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x5e);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x157c) + 0x84) = uVar2;
        *(undefined4 *)(original_frame_context + 0x1578) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xc0) + 0x264);
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x5e);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1578) + 0x84) = uVar2;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0xc0) + 0xb8,0x4ac);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xc0) + 0xcc,0x122);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xc0) + 0xe0,0x122);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xc0) + 0xf4,0x122);
        iVar7 = *(int *)(original_frame_context + 0x20);
      }
      *(undefined4 *)(original_frame_context + 0x1570) =
           *(undefined4 *)(original_frame_context + 0xcc);
      if (*(int *)(original_frame_context + 0x1570) == 0) {
        original_frame_context[0x1574] = 0;
        original_frame_context[0x1575] = 0;
        original_frame_context[0x1576] = 0;
        original_frame_context[0x1577] = 0;
      }
      else {
        uVar2 = (**(code **)(iVar7 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x1570),
                           *(undefined4 *)(iVar7 + -0x2dd4),*(undefined4 *)(iVar7 + -0x16c),0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x1574) = uVar2;
      }
      *(undefined4 *)(original_frame_context + 0xbc) =
           *(undefined4 *)(original_frame_context + 0x1574);
      if (*(int *)(original_frame_context + 0xbc) != 0) {
        *(undefined2 *)(*(int *)(original_frame_context + 0xbc) + 0x9e) = 0x46;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x45f7);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0xbc) + 0x9c) = uVar1;
        (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0xbc) + 0xb8,0x4ac);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xbc) + 0xcc,0x122);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xbc) + 0xe0,0x122);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xbc) + 0xf4,0x122);
        uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0xbc) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0xbc) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0xbc) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0xbc) + 0x15e) = uVar1;
        uVar3 = (**(code **)(iVar7 + -0x38a4))(0x3215);
        *(uint *)(original_frame_context + 0x156c) = uVar3 & 0xffff;
        uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
        *(uint *)(original_frame_context + 0x1568) = uVar3 & 0xffff;
        uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
        *(uint *)(original_frame_context + 0x1564) = uVar3 & 0xffff;
        uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
        pbStack00000010 = (byte *)(uVar3 & 0xffff);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x78fc))
                  (*(undefined4 *)(original_frame_context + 0xbc),
                   *(undefined4 *)(original_frame_context + 0x156c),
                   *(undefined4 *)(original_frame_context + 0x1568),
                   *(undefined4 *)(original_frame_context + 0x1564));
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x5e);
        *(undefined4 *)(original_frame_context + 0x1560) = uVar2;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x54);
        *(undefined4 *)(original_frame_context + 0x155c) = uVar2;
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x5e);
        *(undefined4 *)(original_frame_context + 0x1558) = uVar2;
        pbStack00000010 =
             (byte *)(**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x5e);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x7160))
                  (*(undefined4 *)(original_frame_context + 0xbc),
                   *(undefined4 *)(original_frame_context + 0x1560),
                   *(undefined4 *)(original_frame_context + 0x155c),
                   *(undefined4 *)(original_frame_context + 0x1558));
        *(undefined4 *)(original_frame_context + 0x1554) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xbc) + 0x250);
        uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x5e);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1554) + 0x84) = uVar2;
        *(undefined4 *)(original_frame_context + 0x1550) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xbc) + 0x254);
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x5e);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1550) + 0x84) = uVar2;
        (**(code **)(iVar7 + -0x22f8))(*(undefined4 *)(original_frame_context + 0xbc),1);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x9a0,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x98c,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x978,0x5cd);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x964,0x135);
        pbStack00000010 = original_frame_context + 0x964;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x47f0))
                  (*(undefined4 *)(original_frame_context + 0xbc),original_frame_context + 0x9a0,
                   original_frame_context + 0x98c,original_frame_context + 0x978);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x964);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x978);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x98c);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x9a0);
        iVar7 = *(int *)(original_frame_context + 0x20);
      }
      *(undefined4 *)(original_frame_context + 0x1548) =
           *(undefined4 *)(original_frame_context + 0xcc);
      if (*(int *)(original_frame_context + 0x1548) == 0) {
        original_frame_context[0x154c] = 0;
        original_frame_context[0x154d] = 0;
        original_frame_context[0x154e] = 0;
        original_frame_context[0x154f] = 0;
      }
      else {
        uVar2 = (**(code **)(iVar7 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x1548),
                           *(undefined4 *)(iVar7 + -0x2dd4),*(undefined4 *)(iVar7 + -0x4d04),0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x154c) = uVar2;
      }
      *(undefined4 *)(original_frame_context + 0xb8) =
           *(undefined4 *)(original_frame_context + 0x154c);
      if (*(int *)(original_frame_context + 0xb8) != 0) {
        *(undefined2 *)(*(int *)(*(int *)(original_frame_context + 0xb8) + 0x268) + 0x9c) = 0x5a;
        *(undefined4 *)(original_frame_context + 0x1544) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xb8) + 0x268);
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1544) + 0x7c) = uVar2;
        *(undefined4 *)(original_frame_context + 0x1540) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xb8) + 0x268);
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x54);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1540) + 0x80) = uVar2;
        *(undefined4 *)(original_frame_context + 0x153c) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xb8) + 0x268);
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x153c) + 0x84) = uVar2;
        *(undefined4 *)(original_frame_context + 0x1538) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xb8) + 0x268);
        uVar2 = (**(code **)(iVar7 + -0x5868))(0x45);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1538) + 0x88) = uVar2;
      }
      *(undefined4 *)(original_frame_context + 0x1530) =
           *(undefined4 *)(original_frame_context + 0xcc);
      if (*(int *)(original_frame_context + 0x1530) == 0) {
        original_frame_context[0x1534] = 0;
        original_frame_context[0x1535] = 0;
        original_frame_context[0x1536] = 0;
        original_frame_context[0x1537] = 0;
      }
      else {
        uVar2 = (**(code **)(iVar7 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x1530),
                           *(undefined4 *)(iVar7 + -0x2dd4),*(undefined4 *)(iVar7 + -0x6e84),0);
        iVar7 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x1534) = uVar2;
      }
      *(undefined4 *)(original_frame_context + 0xb4) =
           *(undefined4 *)(original_frame_context + 0x1534);
      if ((*(int *)(original_frame_context + 0xb4) != 0) &&
         (*(int *)(original_frame_context + 0xb8) == 0)) {
        original_frame_context[0xb0] = 0;
        *(undefined4 *)(original_frame_context + 0x1528) =
             *(undefined4 *)(original_frame_context + 0x16e4);
        if (*(int *)(original_frame_context + 0x1528) == 0) {
LAB_0056816c:
          original_frame_context[0x152c] = 0;
          original_frame_context[0x152d] = 0;
          original_frame_context[0x152e] = 0;
          original_frame_context[0x152f] = 0;
        }
        else {
          iVar8 = (**(code **)(iVar7 + -0x598c))
                            (*(undefined4 *)(original_frame_context + 0x1528),
                             *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x7420),0);
          iVar7 = *(int *)(original_frame_context + 0x20);
          if (iVar8 == 0) goto LAB_0056816c;
          original_frame_context[0x152c] = 1;
          original_frame_context[0x152d] = 0;
          original_frame_context[0x152e] = 0;
          original_frame_context[0x152f] = 0;
        }
        if (*(int *)(original_frame_context + 0x152c) != 0) {
          *(undefined4 *)(original_frame_context + 0x1520) =
               *(undefined4 *)(original_frame_context + 0x16e4);
          if (*(int *)(original_frame_context + 0x1520) == 0) {
            original_frame_context[0x1524] = 0;
            original_frame_context[0x1525] = 0;
            original_frame_context[0x1526] = 0;
            original_frame_context[0x1527] = 0;
          }
          else {
            uVar2 = (**(code **)(iVar7 + -0x598c))
                              (*(undefined4 *)(original_frame_context + 0x1520),
                               *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x7420),0);
            iVar7 = *(int *)(original_frame_context + 0x20);
            *(undefined4 *)(original_frame_context + 0x1524) = uVar2;
          }
          if (*(int *)(*(int *)(original_frame_context + 0x1524) + 0x200) ==
              *(int *)(original_frame_context + 0xb4)) {
            original_frame_context[0xb0] = 1;
          }
        }
        if (original_frame_context[0xb0] == 1) {
          (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0xb4) + 0xb8,0x4ac);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0xb4) + 0xcc,0x4ac);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x464))
                    (*(undefined4 *)(original_frame_context + 0xb4));
          original_frame_context[0x12a4] = 0;
          original_frame_context[0x12a5] = 0;
          original_frame_context[0x12a6] = 0;
          original_frame_context[0x12a7] = 0;
          original_frame_context[0x12a8] = 10;
          original_frame_context[0x12a9] = 0;
          original_frame_context[0x12aa] = 0;
          original_frame_context[0x12ab] = 0;
          original_frame_context[0x12b0] = 0x14;
          original_frame_context[0x12b1] = 0;
          original_frame_context[0x12b2] = 0;
          original_frame_context[0x12b3] = 0;
          *(int *)(original_frame_context + 0x12ac) =
               *(int *)(original_frame_context + 0x128c) + -0x1e;
          piVar4 = (int *)(**(code **)(**(int **)(original_frame_context + 0xb4) + 0x40))
                                    (*(undefined4 *)(original_frame_context + 0xb4),1);
          (**(code **)(*piVar4 + 0x24))
                    (piVar4,*(undefined4 *)(original_frame_context + 0x12a4),
                     *(undefined4 *)(original_frame_context + 0x12a8),
                     original_frame_context + 0x12a4);
          original_frame_context[0x12a4] = 0x11;
          original_frame_context[0x12a5] = 2;
          original_frame_context[0x12a6] = 0;
          original_frame_context[0x12a7] = 0;
          original_frame_context[0x12a8] = 0x1e;
          original_frame_context[0x12a9] = 0;
          original_frame_context[0x12aa] = 0;
          original_frame_context[0x12ab] = 0;
          original_frame_context[0x12b0] = 0x28;
          original_frame_context[0x12b1] = 0;
          original_frame_context[0x12b2] = 0;
          original_frame_context[0x12b3] = 0;
          original_frame_context[0x12ac] = 0x40;
          original_frame_context[0x12ad] = 1;
          original_frame_context[0x12ae] = 0;
          original_frame_context[0x12af] = 0;
          piVar4 = (int *)(**(code **)(**(int **)(original_frame_context + 0xb4) + 0x40))
                                    (*(undefined4 *)(original_frame_context + 0xb4),0);
          (**(code **)(*piVar4 + 0x24))
                    (piVar4,*(undefined4 *)(original_frame_context + 0x12a4),
                     *(undefined4 *)(original_frame_context + 0x12a8),
                     original_frame_context + 0x12a4);
          iVar7 = *(int *)(original_frame_context + 0x20);
        }
        else {
          (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0xb4) + 0xb8,0x4ac);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0xb4) + 0xcc,0x4ac);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x464))
                    (*(undefined4 *)(original_frame_context + 0xb4));
          original_frame_context[0x1294] = 0;
          original_frame_context[0x1295] = 0;
          original_frame_context[0x1296] = 0;
          original_frame_context[0x1297] = 0;
          original_frame_context[0x1298] = 0x1e;
          original_frame_context[0x1299] = 0;
          original_frame_context[0x129a] = 0;
          original_frame_context[0x129b] = 0;
          original_frame_context[0x12a0] = 0x31;
          original_frame_context[0x12a1] = 0;
          original_frame_context[0x12a2] = 0;
          original_frame_context[0x12a3] = 0;
          *(undefined4 *)(original_frame_context + 0x129c) =
               *(undefined4 *)(original_frame_context + 0x128c);
          original_frame_context[0xac] = 0;
          original_frame_context[0xad] = 0;
          original_frame_context[0xae] = 0;
          original_frame_context[0xaf] = 0;
          while( true ) {
            uVar3 = (**(code **)(**(int **)(original_frame_context + 0xb4) + 0x44))
                              (*(undefined4 *)(original_frame_context + 0xb4));
            iVar7 = *(int *)(original_frame_context + 0x20);
            if (uVar3 <= *(uint *)(original_frame_context + 0xac)) break;
            uVar2 = (**(code **)(**(int **)(original_frame_context + 0xb4) + 0x40))
                              (*(undefined4 *)(original_frame_context + 0xb4),
                               *(undefined4 *)(original_frame_context + 0xac));
            *(undefined4 *)(original_frame_context + 0xcc) = uVar2;
            (**(code **)(**(int **)(original_frame_context + 0xcc) + 0x24))
                      (*(undefined4 *)(original_frame_context + 0xcc),
                       *(undefined4 *)(original_frame_context + 0x1294),
                       *(undefined4 *)(original_frame_context + 0x1298),
                       original_frame_context + 0x1294);
            iVar7 = *(int *)(original_frame_context + 0x20);
            *(undefined1 *)(*(int *)(original_frame_context + 0xcc) + 0x3a) = 1;
            (**(code **)(iVar7 + -0x910))(*(int *)(original_frame_context + 0xcc) + 0xb8,0x6d);
            uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x45f7);
            iVar7 = *(int *)(original_frame_context + 0x20);
            *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0x9c) = uVar1;
            uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3214);
            iVar7 = *(int *)(original_frame_context + 0x20);
            *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0x13a) = uVar1;
            uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3214);
            iVar7 = *(int *)(original_frame_context + 0x20);
            *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0x146) = uVar1;
            uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3214);
            iVar7 = *(int *)(original_frame_context + 0x20);
            *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0x152) = uVar1;
            uVar1 = (**(code **)(iVar7 + -0x38a4))(0x3214);
            *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0x15e) = uVar1;
            *(int *)(original_frame_context + 0xac) = *(int *)(original_frame_context + 0xac) + 1;
          }
        }
        (**(code **)(iVar7 + -0x74e8))(*(undefined4 *)(original_frame_context + 0xb4));
      }
      *(int *)(original_frame_context + 0xd0) = *(int *)(original_frame_context + 0xd0) + 1;
    }
    (**(code **)(**(int **)(original_frame_context + 0xd8) + 0x48))
              (*(undefined4 *)(original_frame_context + 0xd8));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x74e8))
              (*(undefined4 *)(original_frame_context + 0xd8));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x20cc))
              (original_frame_context + 0x960,original_frame_context + 0x1258,0);
    iVar7 = *(int *)(original_frame_context + 0x20);
  } while( true );
}

