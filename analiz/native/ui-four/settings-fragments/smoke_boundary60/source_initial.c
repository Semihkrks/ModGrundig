
/* Analysis fragment only; external jumps/continuation are abstracted as exits. Not original
   standalone code. Original frame/GP context required. */

undefined4
Settings_fragment_source_initial
          (uint boundary_a0,uint boundary_a1,uint boundary_a2,uint boundary_a3,
          byte *original_frame_context)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uStack00000010;
  
  *(undefined4 *)(original_frame_context + 0x1668) =
       *(undefined4 *)(original_frame_context + 0x16e4);
  if (*(int *)(original_frame_context + 0x1668) == 0) {
    original_frame_context[0x166c] = 0;
    original_frame_context[0x166d] = 0;
    original_frame_context[0x166e] = 0;
    original_frame_context[0x166f] = 0;
  }
  else {
    uVar2 = __dynamic_cast(*(undefined4 *)(original_frame_context + 0x1668),&MMainFrame::typeinfo,
                           &SourceSetupFrame::typeinfo,0);
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
  uStack00000010 = 0x31;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1230,0x10f,0x1c,0x545);
  uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x1664) = uVar2;
  uStack00000010 = 100;
                    /* try { // try from 005637e4 to 005637eb has its CatchHandler @ 0056380c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x1664),
             *(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 400),
             original_frame_context + 0x1230,0);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0xec) = *(undefined4 *)(original_frame_context + 0x1664);
  if (*(int *)(original_frame_context + 0xec) != 0) {
    *(undefined1 *)(*(int *)(original_frame_context + 0xec) + 0x3a) = 1;
    *(undefined1 *)(*(int *)(original_frame_context + 0xec) + 0x38) = 0;
    uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45f5);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xec) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45f5);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xec) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45f5);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xec) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45f5);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xec) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45f9);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xec) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45f9);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xec) + 0xa6) = uVar1;
    (**(code **)(iVar3 + -0x910))(*(int *)(original_frame_context + 0xec) + 0xb8,0x5cd);
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
    uStack00000010 = 0x31;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1230,0x429,0,0x11e);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x1ec) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x1ec),
               *(undefined4 *)(original_frame_context + 0x1230),
               *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x214) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x214),0,0,
               original_frame_context + 0x1230);
    uStack00000010 = 0x31;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1230,0,0,0x91);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x20c) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x20c),
               *(undefined4 *)(original_frame_context + 0x1230),
               *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x20c) + 0x128) = 0x24;
    uStack00000010 = 0x31;
    (**(code **)(iVar3 + -0x2b00))(original_frame_context + 0x1230,0x91,0,0x23);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x210) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x210),
               *(undefined4 *)(original_frame_context + 0x1230),
               *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x210) + 0x128) = 0x24;
    uStack00000010 = 0x31;
    (**(code **)(iVar3 + -0x2b00))(original_frame_context + 0x1230,0x30d,0,0x11e);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x1e8) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x1e8),
               *(undefined4 *)(original_frame_context + 0x1230),
               *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x208) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x208),0,0,
               original_frame_context + 0x1230);
    uStack00000010 = 0x31;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1230,0,0,0x91);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x200) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x200),
               *(undefined4 *)(original_frame_context + 0x1230),
               *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x200) + 0x128) = 0x24;
    uStack00000010 = 0x31;
    (**(code **)(iVar3 + -0x2b00))(original_frame_context + 0x1230,0x91,0,0x23);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x204) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x204),
               *(undefined4 *)(original_frame_context + 0x1230),
               *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x204) + 0x128) = 0x24;
    uStack00000010 = 0x31;
    (**(code **)(iVar3 + -0x2b00))(original_frame_context + 0x1230,0x1ef,0,0x11e);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x1f0) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x1f0),
               *(undefined4 *)(original_frame_context + 0x1230),
               *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
    uStack00000010 = 0x31;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1230,0,0,0x96);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x218) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x218),
               *(undefined4 *)(original_frame_context + 0x1230),
               *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x218) + 0x128) = 0x24;
    uStack00000010 = 0x31;
    (**(code **)(iVar3 + -0x2b00))(original_frame_context + 0x1230,0x9c,0,0x82);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x21c) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x21c),
               *(undefined4 *)(original_frame_context + 0x1230),
               *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x21c) + 0x128) = 0x21;
    uStack00000010 = 0x31;
    (**(code **)(iVar3 + -0x2b00))(original_frame_context + 0x1230,0xd1,0,0x11e);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 500) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 500),
               *(undefined4 *)(original_frame_context + 0x1230),
               *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
    uStack00000010 = 0x31;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1230,0,0,0x91);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x220) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x220),
               *(undefined4 *)(original_frame_context + 0x1230),
               *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x220) + 0x128) = 0x24;
    uStack00000010 = 0x31;
    (**(code **)(iVar3 + -0x2b00))(original_frame_context + 0x1230,0x91,0,0x23);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x224) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x224),
               *(undefined4 *)(original_frame_context + 0x1230),
               *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x224) + 0x128) = 0x24;
    uStack00000010 = 0x31;
    (**(code **)(iVar3 + -0x2b00))(original_frame_context + 0x1230,0,0,0x1ef);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x1f8) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x1f8),
               *(undefined4 *)(original_frame_context + 0x1230),
               *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
    uStack00000010 = 0x31;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1230,0,0,0x96);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x228) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x228),
               *(undefined4 *)(original_frame_context + 0x1230),
               *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x228) + 0x128) = 0x24;
    uStack00000010 = 0x31;
    (**(code **)(iVar3 + -0x2b00))(original_frame_context + 0x1230,0x9c,0,0x153);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0xf0) + 0x22c) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x22c),
               *(undefined4 *)(original_frame_context + 0x1230),
               *(undefined4 *)(original_frame_context + 0x1234),original_frame_context + 0x1230);
    iVar3 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xf0) + 0x22c) + 0x128) = 0x21;
    (**(code **)(iVar3 + -0x72a8))(*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x188))
    ;
    uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x72a8))
                      (*(undefined4 *)(*(int *)(original_frame_context + 0xf0) + 0x18c));
    return uVar2;
  }
  (**(code **)(iVar3 + -0x2400))
            (*(int *)(iVar3 + -0x7fdc) + 0x7b18,*(int *)(iVar3 + -0x7fdc) + 0x7b34,
             *(int *)(iVar3 + -0x7fdc) + 0x7cf8,0x775);
                    /* WARNING: Subroutine does not return */
  (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
}

