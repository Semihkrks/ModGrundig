
/* Analysis fragment only; external jumps/continuation are abstracted as exits. Not original
   standalone code. Original frame/GP context required. */

undefined4
Settings_fragment_manualsearch_results
          (uint boundary_a0,uint boundary_a1,uint boundary_a2,uint boundary_a3,
          byte *original_frame_context)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined **ppuVar4;
  int iVar5;
  int iVar6;
  byte *pbStack00000010;
  
  ppuVar4 = &_gp;
  *(undefined4 *)(original_frame_context + 0x1468) =
       *(undefined4 *)(original_frame_context + 0x16e4);
  if (*(int *)(original_frame_context + 0x1468) == 0) {
    original_frame_context[0x146c] = 0;
    original_frame_context[0x146d] = 0;
    original_frame_context[0x146e] = 0;
    original_frame_context[0x146f] = 0;
  }
  else {
    uVar3 = __dynamic_cast(*(undefined4 *)(original_frame_context + 0x1468),&MMainFrame::typeinfo,
                           &ManualSearchFrame::typeinfo,0);
    ppuVar4 = *(undefined ***)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x146c) = uVar3;
  }
  *(undefined4 *)(original_frame_context + 100) = *(undefined4 *)(original_frame_context + 0x146c);
  if (*(int *)(original_frame_context + 100) == 0) {
    return 0;
  }
  (*(code *)ppuVar4[-0x141b])(original_frame_context + 0x1330);
  *(undefined4 *)(original_frame_context + 0x60) =
       *(undefined4 *)(*(int *)(original_frame_context + 100) + 0x194);
  *(undefined4 *)(original_frame_context + 0x133c) =
       *(undefined4 *)(*(int *)(original_frame_context + 100) + 0x26c);
                    /* try { // try from 00570b58 to 00571243 has its CatchHandler @ 00579214 */
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
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x373c))(original_frame_context + 0x135c);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x6be0))
            (original_frame_context + 0x13c0,original_frame_context + 0x1330);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x135c) =
       *(undefined4 *)(original_frame_context + 0x13c0);
  while( true ) {
    (**(code **)(iVar5 + -0x11cc))(original_frame_context + 0x544,original_frame_context + 0x1330);
    iVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + 0xed0))
                      (original_frame_context + 0x135c,original_frame_context + 0x544);
    iVar6 = *(int *)(original_frame_context + 0x20);
    if (iVar5 == 0) break;
    puVar2 = (undefined4 *)(**(code **)(iVar6 + -0x55d4))(original_frame_context + 0x135c);
    *(undefined4 *)(original_frame_context + 0x28) = *puVar2;
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x7c) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x80) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x84) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x88) = uVar3;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0xa6) = uVar1;
    (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x28) + 0xb8,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x28) + 0xcc,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x28) + 0xe0,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x28) + 0xf4,0x5cd);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x130) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x13c) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x148) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x154) = 0x4ae;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0x13a) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0x146) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0x152) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x28) + 0x15e) = uVar1;
    *(undefined4 *)(*(int *)(original_frame_context + 0x28) + 0x128) = 0x24;
    (**(code **)(iVar5 + -0x75c4))(original_frame_context + 0x540,original_frame_context + 0x135c,0)
    ;
    iVar5 = *(int *)(original_frame_context + 0x20);
  }
  *(undefined4 *)(*(int *)(original_frame_context + 0x1348) + 0x128) = 0x21;
  *(undefined4 *)(original_frame_context + 0x1464) =
       *(undefined4 *)(original_frame_context + 0x1348);
  uVar1 = (**(code **)(iVar6 + -0x38a4))(0x3213);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x1464) + 0x13a) = uVar1;
  *(undefined4 *)(original_frame_context + 0x1460) =
       *(undefined4 *)(original_frame_context + 0x1348);
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3213);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x1460) + 0x146) = uVar1;
  *(undefined4 *)(original_frame_context + 0x145c) =
       *(undefined4 *)(original_frame_context + 0x1348);
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3213);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x145c) + 0x152) = uVar1;
  *(undefined4 *)(original_frame_context + 0x1458) =
       *(undefined4 *)(original_frame_context + 0x1348);
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3213);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x1458) + 0x15e) = uVar1;
  pbStack00000010 = (byte *)0x226;
  (**(code **)(iVar5 + -0x2b00))(original_frame_context + 0x1360,0,0x1e,0x780);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x1454) = uVar3;
  pbStack00000010 = (byte *)0x4b;
                    /* try { // try from 00571274 to 0057127b has its CatchHandler @ 0057129c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x1454),
             *(undefined4 *)(*(int *)(original_frame_context + 0x16e4) + 0x38),
             original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x5c) = *(undefined4 *)(original_frame_context + 0x1454);
  if (*(int *)(original_frame_context + 0x5c) == 0) {
                    /* try { // try from 005712f4 to 005714eb has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xd26);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x11d4))(*(undefined4 *)(original_frame_context + 0x5c),2,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x5c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x5c) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x5c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x5c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x5c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x5c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x5c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x5c) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x5c) + 0xb8,0x5cd);
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
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x1450) = uVar3;
  pbStack00000010 = (byte *)0x4c;
                    /* try { // try from 00571514 to 0057151b has its CatchHandler @ 0057153c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x1450),
             *(undefined4 *)(original_frame_context + 0x5c),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x58) = *(undefined4 *)(original_frame_context + 0x1450);
  if (*(int *)(original_frame_context + 0x58) == 0) {
                    /* try { // try from 00571594 to 005717fb has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xd38);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x58) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x58) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x58) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x58) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x58) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x58) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x58) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x58) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x58) + 0xb8,0x137);
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
             *(undefined4 *)(original_frame_context + 0x1364),original_frame_context + 0x1360);
  pbStack00000010 = (byte *)0x16c;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1360,0x10f,0x72,0x1b7);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x144c) = uVar3;
  pbStack00000010 = (byte *)0x4d;
                    /* try { // try from 00571824 to 0057182b has its CatchHandler @ 0057184c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x144c),
             *(undefined4 *)(original_frame_context + 0x5c),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x54) = *(undefined4 *)(original_frame_context + 0x144c);
  if (*(int *)(original_frame_context + 0x54) == 0) {
                    /* try { // try from 005718a4 to 00571a73 has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xd52);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x54) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x54) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x54) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x54) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x54) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x54) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x54) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x54) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x54) + 0xb8,0x5cd);
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
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x1448) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 00571a9c to 00571aa3 has its CatchHandler @ 00571ac4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x1448),
             *(undefined4 *)(original_frame_context + 0x54),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x50) = *(undefined4 *)(original_frame_context + 0x1448);
  if (*(int *)(original_frame_context + 0x50) == 0) {
                    /* try { // try from 00571b1c to 00571e0f has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xd63);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x50) + 0x170,0xeee);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x50) + 0x39) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x50) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x1a);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x1a);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x1a);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x1a);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  *(undefined2 *)(*(int *)(original_frame_context + 0x50) + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x50) + 0x128) = 0x21;
  (**(code **)(**(int **)(original_frame_context + 0x54) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x54),
             *(undefined4 *)(original_frame_context + 0x50));
  pbStack00000010 = (byte *)0x12c;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1360,0,0x40,0x1b7);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0xbf8);
  *(undefined4 *)(original_frame_context + 0x1444) = uVar3;
  pbStack00000010 = (byte *)0x4e;
                    /* try { // try from 00571e38 to 00571e3f has its CatchHandler @ 00571e60 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x605c))
            (*(undefined4 *)(original_frame_context + 0x1444),
             *(undefined4 *)(original_frame_context + 0x54),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x4c) = *(undefined4 *)(original_frame_context + 0x1444);
  if (*(int *)(original_frame_context + 0x4c) == 0) {
                    /* try { // try from 00571eb8 to 0057205f has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xd81);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x4c) + 0x39) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x4c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x4c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x4c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x4c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x4c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x4c) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x4c) + 0xb8,0x5cd);
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
                    /* try { // try from 00572074 to 0057207b has its CatchHandler @ 00572234 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x518,0x5cd);
                    /* try { // try from 00572090 to 00572097 has its CatchHandler @ 005721d4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x504,0x5cd);
                    /* try { // try from 005720ac to 005720b3 has its CatchHandler @ 00572178 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x4f0,0x5cd);
  pbStack00000010 = original_frame_context + 0x4f0;
                    /* try { // try from 005720d8 to 005720df has its CatchHandler @ 0057211c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x77c8))
            (*(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x52c,
             original_frame_context + 0x518,original_frame_context + 0x504);
                    /* try { // try from 005720f0 to 005720f7 has its CatchHandler @ 00572178 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x4f0);
                    /* try { // try from 00572108 to 0057210f has its CatchHandler @ 005721d4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x504);
                    /* try { // try from 00572164 to 0057216b has its CatchHandler @ 00572234 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x518);
                    /* try { // try from 005721c0 to 005721c7 has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x52c);
                    /* try { // try from 00572220 to 00572227 has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x4dc,0x5cd);
                    /* try { // try from 00572280 to 00572287 has its CatchHandler @ 00572440 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x4c8,0x5cd);
                    /* try { // try from 0057229c to 005722a3 has its CatchHandler @ 005723e0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x4b4,0x5cd);
                    /* try { // try from 005722b8 to 005722bf has its CatchHandler @ 00572384 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x4a0,0x5cd);
  pbStack00000010 = original_frame_context + 0x4a0;
                    /* try { // try from 005722e4 to 005722eb has its CatchHandler @ 00572328 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x447c))
            (*(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x4dc,
             original_frame_context + 0x4c8,original_frame_context + 0x4b4);
                    /* try { // try from 005722fc to 00572303 has its CatchHandler @ 00572384 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x4a0);
                    /* try { // try from 00572314 to 0057231b has its CatchHandler @ 005723e0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x4b4);
                    /* try { // try from 00572370 to 00572377 has its CatchHandler @ 00572440 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x4c8);
                    /* try { // try from 005723cc to 005723d3 has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x4dc);
                    /* try { // try from 0057242c to 00572433 has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x48c,0x5cd);
                    /* try { // try from 0057248c to 00572493 has its CatchHandler @ 0057264c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x478,0x5cd);
                    /* try { // try from 005724a8 to 005724af has its CatchHandler @ 005725ec */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x464,0x5cd);
                    /* try { // try from 005724c4 to 005724cb has its CatchHandler @ 00572590 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x450,0x5cd);
  pbStack00000010 = original_frame_context + 0x450;
                    /* try { // try from 005724f0 to 005724f7 has its CatchHandler @ 00572534 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x17d4))
            (*(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x48c,
             original_frame_context + 0x478,original_frame_context + 0x464);
                    /* try { // try from 00572508 to 0057250f has its CatchHandler @ 00572590 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x450);
                    /* try { // try from 00572520 to 00572527 has its CatchHandler @ 005725ec */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x464);
                    /* try { // try from 0057257c to 00572583 has its CatchHandler @ 0057264c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x478);
                    /* try { // try from 005725d8 to 005725df has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x48c);
                    /* try { // try from 00572638 to 0057263f has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x43c,0x5cd);
                    /* try { // try from 00572698 to 0057269f has its CatchHandler @ 0057285c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x428,0x5cd);
                    /* try { // try from 005726b4 to 005726bb has its CatchHandler @ 005727f8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x414,0x5cd);
                    /* try { // try from 005726d0 to 005726d7 has its CatchHandler @ 0057279c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x400,0x5cd);
  pbStack00000010 = original_frame_context + 0x400;
                    /* try { // try from 005726fc to 00572703 has its CatchHandler @ 00572740 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4bb4))
            (*(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x43c,
             original_frame_context + 0x428,original_frame_context + 0x414);
                    /* try { // try from 00572714 to 0057271b has its CatchHandler @ 0057279c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x400);
                    /* try { // try from 0057272c to 00572733 has its CatchHandler @ 005727f8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x414);
                    /* try { // try from 00572788 to 0057278f has its CatchHandler @ 0057285c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x428);
                    /* try { // try from 005727e4 to 005727eb has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x43c);
                    /* try { // try from 00572848 to 0057284f has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x11d4))
            (*(undefined4 *)(original_frame_context + 0x4c),2,1);
                    /* try { // try from 005728b8 to 005728ff has its CatchHandler @ 00579214 */
  (**(code **)(**(int **)(original_frame_context + 0x54) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x54),
             *(undefined4 *)(original_frame_context + 0x4c));
  pbStack00000010 = (byte *)0x16c;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1360,0x2e5,0x72,0x1b7);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x1440) = uVar3;
  pbStack00000010 = (byte *)0x4f;
                    /* try { // try from 00572928 to 0057292f has its CatchHandler @ 00572950 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x1440),
             *(undefined4 *)(original_frame_context + 0x5c),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x48) = *(undefined4 *)(original_frame_context + 0x1440);
  if (*(int *)(original_frame_context + 0x48) == 0) {
                    /* try { // try from 005729a8 to 00572b77 has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xd98);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x48) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x48) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x48) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x48) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x48) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x48) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x48) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x48) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x48) + 0xb8,0x5cd);
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
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x143c) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 00572ba0 to 00572ba7 has its CatchHandler @ 00572bc8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x143c),
             *(undefined4 *)(original_frame_context + 0x48),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x44) = *(undefined4 *)(original_frame_context + 0x143c);
  if (*(int *)(original_frame_context + 0x44) == 0) {
                    /* try { // try from 00572c20 to 00572f13 has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xda9);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x44) + 0x170,0xfa3);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x44) + 0x39) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x44) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x18);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x18);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x18);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x18);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  *(undefined2 *)(*(int *)(original_frame_context + 0x44) + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x44) + 0x128) = 0x21;
  (**(code **)(**(int **)(original_frame_context + 0x48) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x48),
             *(undefined4 *)(original_frame_context + 0x44));
  pbStack00000010 = (byte *)0x12c;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1360,0,0x40,0x1b7);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0xbf8);
  *(undefined4 *)(original_frame_context + 0x1438) = uVar3;
  pbStack00000010 = (byte *)0x50;
                    /* try { // try from 00572f3c to 00572f43 has its CatchHandler @ 00572f64 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x605c))
            (*(undefined4 *)(original_frame_context + 0x1438),
             *(undefined4 *)(original_frame_context + 0x48),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x40) = *(undefined4 *)(original_frame_context + 0x1438);
  if (*(int *)(original_frame_context + 0x40) == 0) {
                    /* try { // try from 00572fbc to 00573163 has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xdc7);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x40) + 0x39) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x40) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x40) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x40) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x40) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x40) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x40) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x40) + 0xb8,0x5cd);
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
                    /* try { // try from 00573178 to 0057317f has its CatchHandler @ 00573338 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x3d8,0x5cd);
                    /* try { // try from 00573194 to 0057319b has its CatchHandler @ 005732d8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x3c4,0x5cd);
                    /* try { // try from 005731b0 to 005731b7 has its CatchHandler @ 0057327c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x3b0,0x5cd);
  pbStack00000010 = original_frame_context + 0x3b0;
                    /* try { // try from 005731dc to 005731e3 has its CatchHandler @ 00573220 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x77c8))
            (*(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x3ec,
             original_frame_context + 0x3d8,original_frame_context + 0x3c4);
                    /* try { // try from 005731f4 to 005731fb has its CatchHandler @ 0057327c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x3b0);
                    /* try { // try from 0057320c to 00573213 has its CatchHandler @ 005732d8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x3c4);
                    /* try { // try from 00573268 to 0057326f has its CatchHandler @ 00573338 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x3d8);
                    /* try { // try from 005732c4 to 005732cb has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x3ec);
                    /* try { // try from 00573324 to 0057332b has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x39c,0x5cd);
                    /* try { // try from 00573384 to 0057338b has its CatchHandler @ 00573544 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x388,0x5cd);
                    /* try { // try from 005733a0 to 005733a7 has its CatchHandler @ 005734e4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x374,0x5cd);
                    /* try { // try from 005733bc to 005733c3 has its CatchHandler @ 00573488 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x360,0x5cd);
  pbStack00000010 = original_frame_context + 0x360;
                    /* try { // try from 005733e8 to 005733ef has its CatchHandler @ 0057342c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x447c))
            (*(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x39c,
             original_frame_context + 0x388,original_frame_context + 0x374);
                    /* try { // try from 00573400 to 00573407 has its CatchHandler @ 00573488 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x360);
                    /* try { // try from 00573418 to 0057341f has its CatchHandler @ 005734e4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x374);
                    /* try { // try from 00573474 to 0057347b has its CatchHandler @ 00573544 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x388);
                    /* try { // try from 005734d0 to 005734d7 has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x39c);
                    /* try { // try from 00573530 to 00573537 has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x34c,0x5cd);
                    /* try { // try from 00573590 to 00573597 has its CatchHandler @ 00573750 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x338,0x5cd);
                    /* try { // try from 005735ac to 005735b3 has its CatchHandler @ 005736f0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x324,0x5cd);
                    /* try { // try from 005735c8 to 005735cf has its CatchHandler @ 00573694 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x310,0x5cd);
  pbStack00000010 = original_frame_context + 0x310;
                    /* try { // try from 005735f4 to 005735fb has its CatchHandler @ 00573638 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x17d4))
            (*(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x34c,
             original_frame_context + 0x338,original_frame_context + 0x324);
                    /* try { // try from 0057360c to 00573613 has its CatchHandler @ 00573694 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x310);
                    /* try { // try from 00573624 to 0057362b has its CatchHandler @ 005736f0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x324);
                    /* try { // try from 00573680 to 00573687 has its CatchHandler @ 00573750 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x338);
                    /* try { // try from 005736dc to 005736e3 has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x34c);
                    /* try { // try from 0057373c to 00573743 has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x2fc,0x5cd);
                    /* try { // try from 0057379c to 005737a3 has its CatchHandler @ 00573960 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x2e8,0x5cd);
                    /* try { // try from 005737b8 to 005737bf has its CatchHandler @ 005738fc */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x2d4,0x5cd);
                    /* try { // try from 005737d4 to 005737db has its CatchHandler @ 005738a0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x2c0,0x5cd);
  pbStack00000010 = original_frame_context + 0x2c0;
                    /* try { // try from 00573800 to 00573807 has its CatchHandler @ 00573844 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4bb4))
            (*(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x2fc,
             original_frame_context + 0x2e8,original_frame_context + 0x2d4);
                    /* try { // try from 00573818 to 0057381f has its CatchHandler @ 005738a0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x2c0);
                    /* try { // try from 00573830 to 00573837 has its CatchHandler @ 005738fc */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x2d4);
                    /* try { // try from 0057388c to 00573893 has its CatchHandler @ 00573960 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x2e8);
                    /* try { // try from 005738e8 to 005738ef has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x2fc);
                    /* try { // try from 0057394c to 00573953 has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x11d4))
            (*(undefined4 *)(original_frame_context + 0x40),2,1);
                    /* try { // try from 005739bc to 00573a03 has its CatchHandler @ 00579214 */
  (**(code **)(**(int **)(original_frame_context + 0x48) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x48),
             *(undefined4 *)(original_frame_context + 0x40));
  pbStack00000010 = (byte *)0x16c;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1360,0x4bb,0x72,0x1b7);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x1434) = uVar3;
  pbStack00000010 = (byte *)0x51;
                    /* try { // try from 00573a2c to 00573a33 has its CatchHandler @ 00573a54 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x1434),
             *(undefined4 *)(original_frame_context + 0x5c),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x3c) = *(undefined4 *)(original_frame_context + 0x1434);
  if (*(int *)(original_frame_context + 0x3c) == 0) {
                    /* try { // try from 00573aac to 00573c7b has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xdde);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x3c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x3c) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x3c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x3c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x3c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x3c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x3c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x3c) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x3c) + 0xb8,0x5cd);
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
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x1430) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 00573ca4 to 00573cab has its CatchHandler @ 00573ccc */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x1430),
             *(undefined4 *)(original_frame_context + 0x3c),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x38) = *(undefined4 *)(original_frame_context + 0x1430);
  if (*(int *)(original_frame_context + 0x38) == 0) {
                    /* try { // try from 00573d24 to 00574017 has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xdef);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x38) + 0x170,0xdcc);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x38) + 0x39) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x38) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x19);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x19);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x19);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x19);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  *(undefined2 *)(*(int *)(original_frame_context + 0x38) + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x38) + 0x128) = 0x21;
  (**(code **)(**(int **)(original_frame_context + 0x3c) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x3c),
             *(undefined4 *)(original_frame_context + 0x38));
  pbStack00000010 = (byte *)0x12c;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1360,0,0x40,0x1b7);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0xbf8);
  *(undefined4 *)(original_frame_context + 0x142c) = uVar3;
  pbStack00000010 = (byte *)0x52;
                    /* try { // try from 00574040 to 00574047 has its CatchHandler @ 00574068 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x605c))
            (*(undefined4 *)(original_frame_context + 0x142c),
             *(undefined4 *)(original_frame_context + 0x3c),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x34) = *(undefined4 *)(original_frame_context + 0x142c);
  if (*(int *)(original_frame_context + 0x34) == 0) {
                    /* try { // try from 005740c0 to 00574267 has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xe0d);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x34) + 0x39) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x34) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x34) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x34) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x34) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x34) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x34) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x34) + 0xb8,0x5cd);
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
                    /* try { // try from 0057427c to 00574283 has its CatchHandler @ 0057443c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x298,0x5cd);
                    /* try { // try from 00574298 to 0057429f has its CatchHandler @ 005743dc */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x284,0x5cd);
                    /* try { // try from 005742b4 to 005742bb has its CatchHandler @ 00574380 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x270,0x5cd);
  pbStack00000010 = original_frame_context + 0x270;
                    /* try { // try from 005742e0 to 005742e7 has its CatchHandler @ 00574324 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x77c8))
            (*(undefined4 *)(original_frame_context + 0x34),original_frame_context + 0x2ac,
             original_frame_context + 0x298,original_frame_context + 0x284);
                    /* try { // try from 005742f8 to 005742ff has its CatchHandler @ 00574380 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x270);
                    /* try { // try from 00574310 to 00574317 has its CatchHandler @ 005743dc */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x284);
                    /* try { // try from 0057436c to 00574373 has its CatchHandler @ 0057443c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x298);
                    /* try { // try from 005743c8 to 005743cf has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x2ac);
                    /* try { // try from 00574428 to 0057442f has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x25c,0x5cd);
                    /* try { // try from 00574488 to 0057448f has its CatchHandler @ 00574648 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x248,0x5cd);
                    /* try { // try from 005744a4 to 005744ab has its CatchHandler @ 005745e8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x234,0x5cd);
                    /* try { // try from 005744c0 to 005744c7 has its CatchHandler @ 0057458c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x220,0x5cd);
  pbStack00000010 = original_frame_context + 0x220;
                    /* try { // try from 005744ec to 005744f3 has its CatchHandler @ 00574530 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x447c))
            (*(undefined4 *)(original_frame_context + 0x34),original_frame_context + 0x25c,
             original_frame_context + 0x248,original_frame_context + 0x234);
                    /* try { // try from 00574504 to 0057450b has its CatchHandler @ 0057458c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x220);
                    /* try { // try from 0057451c to 00574523 has its CatchHandler @ 005745e8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x234);
                    /* try { // try from 00574578 to 0057457f has its CatchHandler @ 00574648 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x248);
                    /* try { // try from 005745d4 to 005745db has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x25c);
                    /* try { // try from 00574634 to 0057463b has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x20c,0x5cd);
                    /* try { // try from 00574694 to 0057469b has its CatchHandler @ 00574854 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x1f8,0x5cd);
                    /* try { // try from 005746b0 to 005746b7 has its CatchHandler @ 005747f4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x1e4,0x5cd);
                    /* try { // try from 005746cc to 005746d3 has its CatchHandler @ 00574798 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x1d0,0x5cd);
  pbStack00000010 = original_frame_context + 0x1d0;
                    /* try { // try from 005746f8 to 005746ff has its CatchHandler @ 0057473c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x17d4))
            (*(undefined4 *)(original_frame_context + 0x34),original_frame_context + 0x20c,
             original_frame_context + 0x1f8,original_frame_context + 0x1e4);
                    /* try { // try from 00574710 to 00574717 has its CatchHandler @ 00574798 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x1d0);
                    /* try { // try from 00574728 to 0057472f has its CatchHandler @ 005747f4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x1e4);
                    /* try { // try from 00574784 to 0057478b has its CatchHandler @ 00574854 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x1f8);
                    /* try { // try from 005747e0 to 005747e7 has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x20c);
                    /* try { // try from 00574840 to 00574847 has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x1bc,0x5cd);
                    /* try { // try from 005748a0 to 005748a7 has its CatchHandler @ 00574a64 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x1a8,0x5cd);
                    /* try { // try from 005748bc to 005748c3 has its CatchHandler @ 00574a00 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x194,0x5cd);
                    /* try { // try from 005748d8 to 005748df has its CatchHandler @ 005749a4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x180,0x5cd);
  pbStack00000010 = original_frame_context + 0x180;
                    /* try { // try from 00574904 to 0057490b has its CatchHandler @ 00574948 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4bb4))
            (*(undefined4 *)(original_frame_context + 0x34),original_frame_context + 0x1bc,
             original_frame_context + 0x1a8,original_frame_context + 0x194);
                    /* try { // try from 0057491c to 00574923 has its CatchHandler @ 005749a4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x180);
                    /* try { // try from 00574934 to 0057493b has its CatchHandler @ 00574a00 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x194);
                    /* try { // try from 00574990 to 00574997 has its CatchHandler @ 00574a64 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x1a8);
                    /* try { // try from 005749ec to 005749f3 has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x1bc);
                    /* try { // try from 00574a50 to 00574a57 has its CatchHandler @ 00579214 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x11d4))
            (*(undefined4 *)(original_frame_context + 0x34),2,1);
                    /* try { // try from 00574ac0 to 00574b07 has its CatchHandler @ 00579214 */
  (**(code **)(**(int **)(original_frame_context + 0x3c) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x3c),
             *(undefined4 *)(original_frame_context + 0x34));
  pbStack00000010 = (byte *)0x3c;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x1360,0,0,0x1b7);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x1428) = uVar3;
  pbStack00000010 = (byte *)0x53;
                    /* try { // try from 00574b30 to 00574b37 has its CatchHandler @ 00574b58 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x1428),
             *(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x30) = *(undefined4 *)(original_frame_context + 0x1428);
  if (*(int *)(original_frame_context + 0x30) == 0) {
                    /* try { // try from 00574bb0 to 00574daf has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xe24);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
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
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x1424) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 00574dd8 to 00574ddf has its CatchHandler @ 00574e00 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x1424),
             *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x2c) = *(undefined4 *)(original_frame_context + 0x1424);
  if (*(int *)(original_frame_context + 0x2c) == 0) {
                    /* try { // try from 00574e58 to 00575183 has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xe38);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0x11db);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
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
             *(undefined4 *)(original_frame_context + 0x1374),original_frame_context + 0x1370);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x1420) = uVar3;
  pbStack00000010 = (byte *)0x54;
                    /* try { // try from 005751ac to 005751b3 has its CatchHandler @ 005751d4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x1420),
             *(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x30) = *(undefined4 *)(original_frame_context + 0x1420);
  if (*(int *)(original_frame_context + 0x30) == 0) {
                    /* try { // try from 0057522c to 005753d3 has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xe57);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
  (**(code **)(**(int **)(original_frame_context + 0x4c) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x4c),
             *(undefined4 *)(original_frame_context + 0x30));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x141c) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 005753fc to 00575403 has its CatchHandler @ 00575424 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x141c),
             *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x2c) = *(undefined4 *)(original_frame_context + 0x141c);
  if (*(int *)(original_frame_context + 0x2c) == 0) {
                    /* try { // try from 0057547c to 005757a7 has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xe67);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0xcda);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
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
             *(undefined4 *)(original_frame_context + 0x1374),original_frame_context + 0x1370);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x1418) = uVar3;
  pbStack00000010 = (byte *)0x55;
                    /* try { // try from 005757d0 to 005757d7 has its CatchHandler @ 005757f8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x1418),
             *(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x30) = *(undefined4 *)(original_frame_context + 0x1418);
  if (*(int *)(original_frame_context + 0x30) == 0) {
                    /* try { // try from 00575850 to 005759f7 has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xe86);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
  (**(code **)(**(int **)(original_frame_context + 0x4c) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x4c),
             *(undefined4 *)(original_frame_context + 0x30));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x1414) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 00575a20 to 00575a27 has its CatchHandler @ 00575a48 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x1414),
             *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x2c) = *(undefined4 *)(original_frame_context + 0x1414);
  if (*(int *)(original_frame_context + 0x2c) == 0) {
                    /* try { // try from 00575aa0 to 00575dcb has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xe96);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0xed0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
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
             *(undefined4 *)(original_frame_context + 0x1374),original_frame_context + 0x1370);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x1410) = uVar3;
  pbStack00000010 = (byte *)0x56;
                    /* try { // try from 00575df4 to 00575dfb has its CatchHandler @ 00575e1c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x1410),
             *(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x30) = *(undefined4 *)(original_frame_context + 0x1410);
  if (*(int *)(original_frame_context + 0x30) == 0) {
                    /* try { // try from 00575e74 to 0057601b has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xeb5);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
  (**(code **)(**(int **)(original_frame_context + 0x4c) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x4c),
             *(undefined4 *)(original_frame_context + 0x30));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x140c) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 00576044 to 0057604b has its CatchHandler @ 0057606c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x140c),
             *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x2c) = *(undefined4 *)(original_frame_context + 0x140c);
  if (*(int *)(original_frame_context + 0x2c) == 0) {
                    /* try { // try from 005760c4 to 005763ef has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xec5);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0xc15);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
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
             *(undefined4 *)(original_frame_context + 0x1374),original_frame_context + 0x1370);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x1408) = uVar3;
  pbStack00000010 = (byte *)0x57;
                    /* try { // try from 00576418 to 0057641f has its CatchHandler @ 00576440 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x1408),
             *(undefined4 *)(original_frame_context + 0x4c),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x30) = *(undefined4 *)(original_frame_context + 0x1408);
  if (*(int *)(original_frame_context + 0x30) == 0) {
                    /* try { // try from 00576498 to 0057663f has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xee4);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
  (**(code **)(**(int **)(original_frame_context + 0x4c) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x4c),
             *(undefined4 *)(original_frame_context + 0x30));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x1404) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 00576668 to 0057666f has its CatchHandler @ 00576690 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x1404),
             *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x2c) = *(undefined4 *)(original_frame_context + 0x1404);
  if (*(int *)(original_frame_context + 0x2c) == 0) {
                    /* try { // try from 005766e8 to 00576a13 has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xef4);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0xcbd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
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
             *(undefined4 *)(original_frame_context + 0x1374),original_frame_context + 0x1370);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x1400) = uVar3;
  pbStack00000010 = (byte *)0x58;
                    /* try { // try from 00576a3c to 00576a43 has its CatchHandler @ 00576a64 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x1400),
             *(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x30) = *(undefined4 *)(original_frame_context + 0x1400);
  if (*(int *)(original_frame_context + 0x30) == 0) {
                    /* try { // try from 00576abc to 00576c63 has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xf13);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
  (**(code **)(**(int **)(original_frame_context + 0x40) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x40),
             *(undefined4 *)(original_frame_context + 0x30));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x13fc) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 00576c8c to 00576c93 has its CatchHandler @ 00576cb4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x13fc),
             *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x2c) = *(undefined4 *)(original_frame_context + 0x13fc);
  if (*(int *)(original_frame_context + 0x2c) == 0) {
                    /* try { // try from 00576d0c to 0057706b has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xf23);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0xfa1);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
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
            (original_frame_context + 0x1390,*(int *)(original_frame_context + 0x1370) + -0x5a,
             *(undefined4 *)(original_frame_context + 0x1374),
             *(int *)(original_frame_context + 0x1378) + 0x5a);
  (**(code **)(**(int **)(original_frame_context + 0x1344) + 0x24))
            (*(undefined4 *)(original_frame_context + 0x1344),
             *(undefined4 *)(original_frame_context + 0x1390),
             *(undefined4 *)(original_frame_context + 0x1394),original_frame_context + 0x1390);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x13f8) = uVar3;
  pbStack00000010 = (byte *)0x59;
                    /* try { // try from 00577094 to 0057709b has its CatchHandler @ 005770bc */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x13f8),
             *(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x30) = *(undefined4 *)(original_frame_context + 0x13f8);
  if (*(int *)(original_frame_context + 0x30) == 0) {
                    /* try { // try from 00577114 to 005772db has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xf44);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x11d4))(*(undefined4 *)(original_frame_context + 0x30),2,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
  (**(code **)(**(int **)(original_frame_context + 0x40) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x40),
             *(undefined4 *)(original_frame_context + 0x30));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x13f4) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 00577304 to 0057730b has its CatchHandler @ 0057732c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x13f4),
             *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x2c) = *(undefined4 *)(original_frame_context + 0x13f4);
  if (*(int *)(original_frame_context + 0x2c) == 0) {
                    /* try { // try from 00577384 to 00577647 has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xf55);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0xeb4);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x128) = 0x21;
  (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x30),
             *(undefined4 *)(original_frame_context + 0x2c));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x13f0) = uVar3;
  pbStack00000010 = (byte *)0x5a;
                    /* try { // try from 00577670 to 00577677 has its CatchHandler @ 00577698 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x13f0),
             *(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x30) = *(undefined4 *)(original_frame_context + 0x13f0);
  if (*(int *)(original_frame_context + 0x30) == 0) {
                    /* try { // try from 005776f0 to 005778b7 has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xf72);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x11d4))(*(undefined4 *)(original_frame_context + 0x5c),2,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
  (**(code **)(**(int **)(original_frame_context + 0x40) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x40),
             *(undefined4 *)(original_frame_context + 0x30));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x13ec) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 005778e0 to 005778e7 has its CatchHandler @ 00577908 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x13ec),
             *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x2c) = *(undefined4 *)(original_frame_context + 0x13ec);
  if (*(int *)(original_frame_context + 0x2c) == 0) {
                    /* try { // try from 00577960 to 00577c8b has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xf83);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0x1115);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
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
             *(undefined4 *)(original_frame_context + 0x1394),original_frame_context + 0x1390);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x13e8) = uVar3;
  pbStack00000010 = (byte *)0x5b;
                    /* try { // try from 00577cb4 to 00577cbb has its CatchHandler @ 00577cdc */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x13e8),
             *(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x1360,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x30) = *(undefined4 *)(original_frame_context + 0x13e8);
  if (*(int *)(original_frame_context + 0x30) == 0) {
                    /* try { // try from 00577d34 to 00577efb has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xfa2);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x11d4))(*(undefined4 *)(original_frame_context + 0x5c),2,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
  (**(code **)(**(int **)(original_frame_context + 0x40) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x40),
             *(undefined4 *)(original_frame_context + 0x30));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x13e4) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 00577f24 to 00577f2b has its CatchHandler @ 00577f4c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x13e4),
             *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x2c) = *(undefined4 *)(original_frame_context + 0x13e4);
  if (*(int *)(original_frame_context + 0x2c) != 0) {
    (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0xeb1);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
    *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar3;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x15e) = uVar1;
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x128) = 0x21;
    (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
              (*(undefined4 *)(original_frame_context + 0x30),
               *(undefined4 *)(original_frame_context + 0x2c));
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
    *(undefined4 *)(original_frame_context + 0x13e0) = uVar3;
    pbStack00000010 = (byte *)0x5d;
                    /* try { // try from 00578290 to 00578297 has its CatchHandler @ 005782b8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
              (*(undefined4 *)(original_frame_context + 0x13e0),
               *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x2c) =
         *(undefined4 *)(original_frame_context + 0x13e0);
    if (*(int *)(original_frame_context + 0x2c) == 0) {
                    /* try { // try from 00578310 to 00578317 has its CatchHandler @ 00579214 */
      (**(code **)(iVar5 + -0x2400))
                (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
                 *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xfd2);
                    /* WARNING: Subroutine does not return */
      (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
    }
    *(int *)(original_frame_context + 0x13dc) = *(int *)(original_frame_context + 0x2c) + 0x170;
    (**(code **)(iVar5 + -0x59f0))(original_frame_context + 0x178);
                    /* try { // try from 00578368 to 0057836f has its CatchHandler @ 00578454 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x7374))
              (original_frame_context + 0x17c,
               *(int *)(*(int *)(original_frame_context + 0x20) + -0x7fdc) + 0x7b94,
               original_frame_context + 0x178);
                    /* try { // try from 00578384 to 0057838b has its CatchHandler @ 005783f0 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0xf74))
              (*(undefined4 *)(original_frame_context + 0x13dc),original_frame_context + 0x17c);
    *(byte **)(original_frame_context + 0x13d8) = original_frame_context + 0x17c;
                    /* try { // try from 005783a0 to 005783a7 has its CatchHandler @ 00578454 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x72a0))
              (*(undefined4 *)(original_frame_context + 0x13d8));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x79c8))(original_frame_context + 0x178)
    ;
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
    *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
                    /* try { // try from 005783dc to 005783e3 has its CatchHandler @ 00579214 */
    uVar3 = (**(code **)(iVar5 + -0x5868))(0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar3;
                    /* try { // try from 00578440 to 00578747 has its CatchHandler @ 00579214 */
    uVar3 = (**(code **)(iVar5 + -0x5868))(0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar3;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x15e) = uVar1;
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x128) = 0x24;
    (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
              (*(undefined4 *)(original_frame_context + 0x30),
               *(undefined4 *)(original_frame_context + 0x2c));
    pbStack00000010 = *(byte **)(original_frame_context + 0x137c);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x13a0,*(int *)(original_frame_context + 0x1370) + -0x5a,
               *(undefined4 *)(original_frame_context + 0x1374),
               *(int *)(original_frame_context + 0x1378) + 0x5a);
    (**(code **)(**(int **)(original_frame_context + 0x2c) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x2c),
               *(undefined4 *)(original_frame_context + 0x13a0),
               *(undefined4 *)(original_frame_context + 0x13a4),original_frame_context + 0x13a0);
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
    *(undefined4 *)(original_frame_context + 0x13d4) = uVar3;
    pbStack00000010 = (byte *)0x5c;
                    /* try { // try from 00578770 to 00578777 has its CatchHandler @ 00578798 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
              (*(undefined4 *)(original_frame_context + 0x13d4),
               *(undefined4 *)(original_frame_context + 0x40),original_frame_context + 0x1360,0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x30) =
         *(undefined4 *)(original_frame_context + 0x13d4);
    if (*(int *)(original_frame_context + 0x30) == 0) {
                    /* try { // try from 005787f0 to 005789b7 has its CatchHandler @ 00579214 */
      (**(code **)(iVar5 + -0x2400))
                (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
                 *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xff2);
                    /* WARNING: Subroutine does not return */
      (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
    }
    (**(code **)(iVar5 + -0x11d4))(*(undefined4 *)(original_frame_context + 0x5c),2,0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x3a) = 1;
    *(undefined1 *)(*(int *)(original_frame_context + 0x30) + 0x38) = 0;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x30) + 0xa6) = uVar1;
    (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x30) + 0xb8,0x136);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x30) + 0xcc,0x136);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x30) + 0xe0,0x136);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x30) + 0xf4,0x136);
    (**(code **)(**(int **)(original_frame_context + 0x40) + 0x34))
              (*(undefined4 *)(original_frame_context + 0x40),
               *(undefined4 *)(original_frame_context + 0x30));
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
    *(undefined4 *)(original_frame_context + 0x13d0) = uVar3;
    pbStack00000010 = (byte *)0x0;
                    /* try { // try from 005789e0 to 005789e7 has its CatchHandler @ 00578a08 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
              (*(undefined4 *)(original_frame_context + 0x13d0),
               *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x2c) =
         *(undefined4 *)(original_frame_context + 0x13d0);
    if (*(int *)(original_frame_context + 0x2c) == 0) {
                    /* try { // try from 00578a60 to 00578d23 has its CatchHandler @ 00579214 */
      (**(code **)(iVar5 + -0x2400))
                (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
                 *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0x1003);
                    /* WARNING: Subroutine does not return */
      (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
    }
    (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x2c) + 0x170,0x11d1);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
    *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar3;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x15e) = uVar1;
    *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x128) = 0x21;
    (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
              (*(undefined4 *)(original_frame_context + 0x30),
               *(undefined4 *)(original_frame_context + 0x2c));
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
    *(undefined4 *)(original_frame_context + 0x13cc) = uVar3;
    pbStack00000010 = (byte *)0x5e;
                    /* try { // try from 00578d4c to 00578d53 has its CatchHandler @ 00578d74 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
              (*(undefined4 *)(original_frame_context + 0x13cc),
               *(undefined4 *)(original_frame_context + 0x30),original_frame_context + 0x1380,0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x2c) =
         *(undefined4 *)(original_frame_context + 0x13cc);
    if (*(int *)(original_frame_context + 0x2c) != 0) {
      *(int *)(original_frame_context + 0x13c8) = *(int *)(original_frame_context + 0x2c) + 0x170;
      (**(code **)(iVar5 + -0x59f0))(original_frame_context + 0x170);
                    /* try { // try from 00578e24 to 00578e2b has its CatchHandler @ 00578f10 */
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x7374))
                (original_frame_context + 0x174,
                 *(int *)(*(int *)(original_frame_context + 0x20) + -0x7fdc) + 0x7b98,
                 original_frame_context + 0x170);
                    /* try { // try from 00578e40 to 00578e47 has its CatchHandler @ 00578eac */
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0xf74))
                (*(undefined4 *)(original_frame_context + 0x13c8),original_frame_context + 0x174);
      *(byte **)(original_frame_context + 0x13c4) = original_frame_context + 0x174;
                    /* try { // try from 00578e5c to 00578e63 has its CatchHandler @ 00578f10 */
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x72a0))
                (*(undefined4 *)(original_frame_context + 0x13c4));
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x79c8))
                (original_frame_context + 0x170);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x39) = 0;
      *(undefined1 *)(*(int *)(original_frame_context + 0x2c) + 0x38) = 0;
                    /* try { // try from 00578e98 to 00578e9f has its CatchHandler @ 00579214 */
      uVar3 = (**(code **)(iVar5 + -0x5868))(0);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x4c) = uVar3;
                    /* try { // try from 00578efc to 005791ef has its CatchHandler @ 00579214 */
      uVar3 = (**(code **)(iVar5 + -0x5868))(0);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x50) = uVar3;
      uVar3 = (**(code **)(iVar5 + -0x5868))(0);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x54) = uVar3;
      uVar3 = (**(code **)(iVar5 + -0x5868))(0);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x58) = uVar3;
      uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x7c) = uVar3;
      uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x80) = uVar3;
      uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x84) = uVar3;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9c) = uVar1;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x9e) = uVar1;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa0) = uVar1;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa2) = uVar1;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa4) = uVar1;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0xa6) = uVar1;
      *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x130) = 0x4ae;
      *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x13c) = 0x4ae;
      *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x148) = 0x4ae;
      *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x154) = 0x4ae;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x13a) = uVar1;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x146) = uVar1;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x152) = uVar1;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
      *(undefined2 *)(*(int *)(original_frame_context + 0x2c) + 0x15e) = uVar1;
      *(undefined4 *)(*(int *)(original_frame_context + 0x2c) + 0x128) = 0x24;
      (**(code **)(**(int **)(original_frame_context + 0x30) + 0x34))
                (*(undefined4 *)(original_frame_context + 0x30),
                 *(undefined4 *)(original_frame_context + 0x2c));
      pbStack00000010 = *(byte **)(original_frame_context + 0x137c);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
                (original_frame_context + 0x13b0,*(int *)(original_frame_context + 0x1370) + -0x5a,
                 *(undefined4 *)(original_frame_context + 0x1374),
                 *(int *)(original_frame_context + 0x1378) + 0x5a);
      (**(code **)(**(int **)(original_frame_context + 0x2c) + 0x24))
                (*(undefined4 *)(original_frame_context + 0x2c),
                 *(undefined4 *)(original_frame_context + 0x13b0),
                 *(undefined4 *)(original_frame_context + 0x13b4),original_frame_context + 0x13b0);
      uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + 0x958))
                        (original_frame_context + 0x1330);
      return uVar3;
    }
                    /* try { // try from 00578dcc to 00578dd3 has its CatchHandler @ 00579214 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0x1022);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
                    /* try { // try from 00577fa4 to 00578267 has its CatchHandler @ 00579214 */
  (**(code **)(iVar5 + -0x2400))
            (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
             *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xfb3);
                    /* WARNING: Subroutine does not return */
  (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
}

