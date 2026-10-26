
/* Analysis fragment only; external jumps/continuation are abstracted as exits. Not original
   standalone code. Original frame/GP context required. */

undefined4
Settings_fragment_fti_initial
          (uint boundary_a0,uint boundary_a1,uint boundary_a2,uint boundary_a3,
          byte *original_frame_context)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined **ppuVar5;
  int iVar6;
  byte *pbStack00000010;
  undefined4 uStack00000014;
  undefined4 uStack00000018;
  
  ppuVar5 = &_gp;
  *(undefined4 *)(original_frame_context + 0x165c) =
       *(undefined4 *)(original_frame_context + 0x16e4);
  if (*(int *)(original_frame_context + 0x165c) == 0) {
    original_frame_context[0x1660] = 0;
    original_frame_context[0x1661] = 0;
    original_frame_context[0x1662] = 0;
    original_frame_context[0x1663] = 0;
  }
  else {
    uVar2 = __dynamic_cast(*(undefined4 *)(original_frame_context + 0x165c),&MMainFrame::typeinfo,
                           &FTI_BasicSetupFrame::typeinfo,0);
    ppuVar5 = *(undefined ***)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x1660) = uVar2;
  }
  *(undefined4 *)(original_frame_context + 0xe8) = *(undefined4 *)(original_frame_context + 0x1660);
  if (*(int *)(original_frame_context + 0xe8) == 0) {
    return 0;
  }
  *(undefined4 *)(original_frame_context + 0x168) =
       *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x194);
  pbStack00000010 = (byte *)0x1f4;
  (*(code *)ppuVar5[-0xac0])(original_frame_context + 0x11e4,0,0x1e,0x780);
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
  iVar3 = *(int *)(*(int *)(original_frame_context + 0xe8) + 0x1b8);
  uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x45f7);
  iVar6 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(iVar3 + 0x9c) = uVar1;
  iVar3 = *(int *)(*(int *)(original_frame_context + 0xe8) + 0x1b8);
  uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45f7);
  iVar6 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(iVar3 + 0x9e) = uVar1;
  *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xe8) + 0x1b8) + 0x128) = 0x11;
  *(undefined4 *)(original_frame_context + 0x15c) =
       *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x1b0);
  pbStack00000010 = (byte *)0x5a;
  (**(code **)(iVar6 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0,0x562);
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
  uVar4 = *(undefined4 *)(original_frame_context + 0x15c);
  uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x13);
  pbStack00000010 = (byte *)0x0;
  uStack00000014 = 2;
  uStack00000018 = 0xffffffff;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))(uVar4,1,uVar2,0xf);
  uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x3215);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x3215);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x3215);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0x128) = 0x21;
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x9e) = 0x46;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45f7);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0xa2) = uVar1;
  uVar2 = (**(code **)(iVar3 + -0x38a4))(*(undefined4 *)(original_frame_context + 0x11ec));
  uVar4 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))
                    (*(undefined4 *)(original_frame_context + 0x11f0));
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3e1c))
            (*(undefined4 *)(original_frame_context + 0x15c),1,uVar2,uVar4);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0xc30,0x4ac);
                    /* try { // try from 0056475c to 00564763 has its CatchHandler @ 00564c18 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0xc1c,0x4ac);
                    /* try { // try from 00564778 to 0056477f has its CatchHandler @ 00564bb8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0xc08,0x4ac);
                    /* try { // try from 00564794 to 0056479b has its CatchHandler @ 00564860 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0xbf4,0x4ac);
  pbStack00000010 = original_frame_context + 0xbf4;
                    /* try { // try from 005647c0 to 005647c7 has its CatchHandler @ 00564804 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1a5c))
            (*(undefined4 *)(original_frame_context + 0x15c),original_frame_context + 0xc30,
             original_frame_context + 0xc1c,original_frame_context + 0xc08);
                    /* try { // try from 005647d8 to 005647df has its CatchHandler @ 00564860 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xbf4);
                    /* try { // try from 005647f0 to 005647f7 has its CatchHandler @ 00564bb8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xc08);
                    /* try { // try from 0056484c to 00564853 has its CatchHandler @ 00564c18 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xc1c);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xc30);
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
  uVar4 = *(undefined4 *)(original_frame_context + 0x15c);
  uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x13);
  pbStack00000010 = (byte *)0x0;
  uStack00000014 = 2;
  uStack00000018 = 0xffffffff;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))(uVar4,1,uVar2,0xf);
  uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x3215);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x3215);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x3215);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0x128) = 0x21;
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x9e) = 0x46;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45f7);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0xa2) = uVar1;
  uVar2 = (**(code **)(iVar3 + -0x38a4))(*(undefined4 *)(original_frame_context + 0x11ec));
  uVar4 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))
                    (*(undefined4 *)(original_frame_context + 0x11f0));
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3e1c))
            (*(undefined4 *)(original_frame_context + 0x15c),1,uVar2,uVar4);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0xbe0,0x4ac);
                    /* try { // try from 00564ba4 to 00564bab has its CatchHandler @ 00565228 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0xbcc,0x4ac);
                    /* try { // try from 00564c04 to 00564c0b has its CatchHandler @ 005651c8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 3000,0x4ac);
                    /* try { // try from 00564c6c to 00564c73 has its CatchHandler @ 00564d38 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0xba4,0x4ac);
  pbStack00000010 = original_frame_context + 0xba4;
                    /* try { // try from 00564c98 to 00564c9f has its CatchHandler @ 00564cdc */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1a5c))
            (*(undefined4 *)(original_frame_context + 0x15c),original_frame_context + 0xbe0,
             original_frame_context + 0xbcc,original_frame_context + 3000);
                    /* try { // try from 00564cb0 to 00564cb7 has its CatchHandler @ 00564d38 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xba4);
                    /* try { // try from 00564cc8 to 00564ccf has its CatchHandler @ 005651c8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 3000);
                    /* try { // try from 00564d24 to 00564d2b has its CatchHandler @ 00565228 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xbcc);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xbe0);
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
  iVar3 = *(int *)(*(int *)(original_frame_context + 0xe8) + 0x1c4);
  uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x45f7);
  iVar6 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(iVar3 + 0x9c) = uVar1;
  iVar3 = *(int *)(*(int *)(original_frame_context + 0xe8) + 0x1c4);
  uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45f7);
  iVar6 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(iVar3 + 0x9e) = uVar1;
  *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0xe8) + 0x1c4) + 0x128) = 0x11;
  *(undefined4 *)(original_frame_context + 0x15c) =
       *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x1bc);
  pbStack00000010 = (byte *)0x5a;
  (**(code **)(iVar6 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0,0x562);
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
  uVar4 = *(undefined4 *)(original_frame_context + 0x15c);
  uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x13);
  pbStack00000010 = (byte *)0x0;
  uStack00000014 = 2;
  uStack00000018 = 0xffffffff;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))(uVar4,1,uVar2,0xf);
  uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x3215);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x3215);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x3215);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0x128) = 0x21;
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x9e) = 0x46;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45f7);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0xa2) = uVar1;
  uVar2 = (**(code **)(iVar3 + -0x38a4))(*(undefined4 *)(original_frame_context + 0x11ec));
  uVar4 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))
                    (*(undefined4 *)(original_frame_context + 0x11f0));
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3e1c))
            (*(undefined4 *)(original_frame_context + 0x15c),1,uVar2,uVar4);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0xb90,0x4ac);
                    /* try { // try from 005651b4 to 005651bb has its CatchHandler @ 00565700 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0xb7c,0x4ac);
                    /* try { // try from 00565214 to 0056521b has its CatchHandler @ 005656a0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0xb68,0x4ac);
                    /* try { // try from 0056527c to 00565283 has its CatchHandler @ 00565348 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0xb54,0x4ac);
  pbStack00000010 = original_frame_context + 0xb54;
                    /* try { // try from 005652a8 to 005652af has its CatchHandler @ 005652ec */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1a5c))
            (*(undefined4 *)(original_frame_context + 0x15c),original_frame_context + 0xb90,
             original_frame_context + 0xb7c,original_frame_context + 0xb68);
                    /* try { // try from 005652c0 to 005652c7 has its CatchHandler @ 00565348 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xb54);
                    /* try { // try from 005652d8 to 005652df has its CatchHandler @ 005656a0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xb68);
                    /* try { // try from 00565334 to 0056533b has its CatchHandler @ 00565700 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xb7c);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xb90);
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
  uVar4 = *(undefined4 *)(original_frame_context + 0x15c);
  uVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x13);
  pbStack00000010 = (byte *)0x0;
  uStack00000014 = 2;
  uStack00000018 = 0xffffffff;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))(uVar4,1,uVar2,0xf);
  uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x3215);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x3215);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x3215);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0x128) = 0x21;
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x9e) = 0x46;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45f7);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x15c) + 0xa2) = uVar1;
  uVar2 = (**(code **)(iVar3 + -0x38a4))(*(undefined4 *)(original_frame_context + 0x11ec));
  uVar4 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))
                    (*(undefined4 *)(original_frame_context + 0x11f0));
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3e1c))
            (*(undefined4 *)(original_frame_context + 0x15c),1,uVar2,uVar4);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0xb40,0x4ac);
                    /* try { // try from 0056568c to 00565693 has its CatchHandler @ 00565dc0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0xb2c,0x4ac);
                    /* try { // try from 005656ec to 005656f3 has its CatchHandler @ 00565d84 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0xb18,0x4ac);
                    /* try { // try from 00565754 to 0056575b has its CatchHandler @ 00565820 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0xb04,0x4ac);
  pbStack00000010 = original_frame_context + 0xb04;
                    /* try { // try from 00565780 to 00565787 has its CatchHandler @ 005657c4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1a5c))
            (*(undefined4 *)(original_frame_context + 0x15c),original_frame_context + 0xb40,
             original_frame_context + 0xb2c,original_frame_context + 0xb18);
                    /* try { // try from 00565798 to 0056579f has its CatchHandler @ 00565820 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xb04);
                    /* try { // try from 005657b0 to 005657b7 has its CatchHandler @ 00565d84 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xb18);
                    /* try { // try from 0056580c to 00565813 has its CatchHandler @ 00565dc0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xb2c);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xb40);
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
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x160) + 0x128) = 0x11;
  *(undefined4 *)(original_frame_context + 0x158) =
       *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x1cc);
  pbStack00000010 = (byte *)0x5a;
  (**(code **)(iVar3 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0x13a,0x562);
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
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x158) + 0x128) = 0x21;
  *(undefined2 *)(*(int *)(original_frame_context + 0x158) + 0x9e) = 0x46;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45f7);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x158) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x158) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x158) + 0xa2) = uVar1;
  uVar4 = *(undefined4 *)(original_frame_context + 0x158);
  uVar2 = (**(code **)(iVar3 + -0x5868))(0x13);
  pbStack00000010 = (byte *)0x0;
  uStack00000014 = 2;
  uStack00000018 = 0xffffffff;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))(uVar4,1,uVar2,0xf);
  pbStack00000010 = (byte *)0x221;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x11e4,0x10f,0x1e,0x562);
  *(undefined4 *)(original_frame_context + 0x164) =
       *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 0x18c);
  uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0xa6) = uVar1;
  (**(code **)(**(int **)(original_frame_context + 0x164) + 0x24))
            (*(undefined4 *)(original_frame_context + 0x164),
             *(undefined4 *)(original_frame_context + 0x11e4),
             *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
  *(undefined4 *)(original_frame_context + 0x164) =
       *(undefined4 *)(*(int *)(original_frame_context + 0xe8) + 400);
  uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  iVar3 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar3 + -0x38a4))(0x45dd);
  *(undefined2 *)(*(int *)(original_frame_context + 0x164) + 0xa6) = uVar1;
  uVar2 = (**(code **)(**(int **)(original_frame_context + 0x164) + 0x24))
                    (*(undefined4 *)(original_frame_context + 0x164),
                     *(undefined4 *)(original_frame_context + 0x11e4),
                     *(undefined4 *)(original_frame_context + 0x11e8),
                     original_frame_context + 0x11e4);
  return uVar2;
}

