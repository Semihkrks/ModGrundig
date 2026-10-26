
/* Analysis fragment only; external jumps/continuation are abstracted as exits. Not original
   standalone code. Original frame/GP context required. */

undefined4
Settings_fragment_manualsearch_initial
          (uint boundary_a0,uint boundary_a1,uint boundary_a2,uint boundary_a3,
          byte *original_frame_context)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined **ppuVar5;
  
  ppuVar5 = &_gp;
  *(undefined4 *)(original_frame_context + 0x1680) =
       *(undefined4 *)(original_frame_context + 0x16e4);
  if (*(int *)(original_frame_context + 0x1680) == 0) {
    original_frame_context[0x1684] = 0;
    original_frame_context[0x1685] = 0;
    original_frame_context[0x1686] = 0;
    original_frame_context[0x1687] = 0;
  }
  else {
    uVar3 = __dynamic_cast(*(undefined4 *)(original_frame_context + 0x1680),&MMainFrame::typeinfo,
                           &ManualSearchFrame::typeinfo,0);
    ppuVar5 = *(undefined ***)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x1684) = uVar3;
  }
  *(undefined4 *)(original_frame_context + 0x100) = *(undefined4 *)(original_frame_context + 0x1684)
  ;
  if (*(int *)(original_frame_context + 0x100) != 0) {
    *(undefined4 *)(original_frame_context + 0x168) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x188);
    (*(code *)ppuVar5[-0xac0])(original_frame_context + 0x11e4,0,0,0x780);
    (**(code **)(**(int **)(original_frame_context + 0x168) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x168),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    *(undefined4 *)(original_frame_context + 0x168) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x18c);
    (**(code **)(**(int **)(original_frame_context + 0x168) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x168),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x72a8))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x198));
    iVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1d9c))
                      (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x19c),2);
    original_frame_context[0x16e] = iVar2 != 0;
    iVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1d9c))
                      (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1a0),2);
    original_frame_context[0x16d] = iVar2 != 0;
    iVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1d9c))
                      (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1a4),2);
    original_frame_context[0x16c] = iVar2 != 0;
    *(undefined4 *)(original_frame_context + 0x15c) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x19c);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x11e4,0x10f,0x1e,0x562);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb0) =
         *(undefined4 *)(original_frame_context + 0x15c);
    if (original_frame_context[0x16d] == 0) {
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb4) =
           *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1a4);
    }
    else {
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb4) =
           *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1a0);
    }
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
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x13);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))(uVar4,1,uVar3,0xf);
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))
                      (*(undefined4 *)(original_frame_context + 0x11ec));
    uVar4 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))
                      (*(undefined4 *)(original_frame_context + 0x11f0));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3e1c))
              (*(undefined4 *)(original_frame_context + 0x15c),1,uVar3,uVar4);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xd20,0x125);
                    /* try { // try from 005612d8 to 005612df has its CatchHandler @ 005614e4 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xd0c,0x125);
                    /* try { // try from 005612f4 to 005612fb has its CatchHandler @ 005614a8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xcf8,0x125);
                    /* try { // try from 00561310 to 00561317 has its CatchHandler @ 005613dc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xce4,0x125);
                    /* try { // try from 0056133c to 00561343 has its CatchHandler @ 00561380 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1a5c))
              (*(undefined4 *)(original_frame_context + 0x15c),original_frame_context + 0xd20,
               original_frame_context + 0xd0c,original_frame_context + 0xcf8);
                    /* try { // try from 00561354 to 0056135b has its CatchHandler @ 005613dc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xce4)
    ;
                    /* try { // try from 0056136c to 00561373 has its CatchHandler @ 005614a8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xcf8)
    ;
                    /* try { // try from 005613c8 to 005613cf has its CatchHandler @ 005614e4 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xd0c)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xd20)
    ;
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 0x1a8) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1a8),
               *(int *)(original_frame_context + 0x11e4) + 0x6e,
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x100) + 0x1a8) + 0x128) = 0x21;
    *(undefined4 *)(original_frame_context + 0x15c) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1a0);
    if (original_frame_context[0x16e] == 0) {
      (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0x1e,0x562);
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb0) =
           *(undefined4 *)(original_frame_context + 0x15c);
    }
    else {
      (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0x78,0x562);
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb0) =
           *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x19c);
    }
    if (original_frame_context[0x16c] == 0) {
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb4) =
           *(undefined4 *)(original_frame_context + 0x15c);
    }
    else {
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb4) =
           *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1a4);
    }
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
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x13);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))(uVar4,1,uVar3,0xf);
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))
                      (*(undefined4 *)(original_frame_context + 0x11ec));
    uVar4 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))
                      (*(undefined4 *)(original_frame_context + 0x11f0));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3e1c))
              (*(undefined4 *)(original_frame_context + 0x15c),1,uVar3,uVar4);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xcd0,0x126);
                    /* try { // try from 0056177c to 00561783 has its CatchHandler @ 00561990 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xcbc,0x126);
                    /* try { // try from 00561798 to 0056179f has its CatchHandler @ 00561954 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xca8,0x126);
                    /* try { // try from 005617b4 to 005617bb has its CatchHandler @ 00561880 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xc94,0x126);
                    /* try { // try from 005617e0 to 005617e7 has its CatchHandler @ 00561824 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1a5c))
              (*(undefined4 *)(original_frame_context + 0x15c),original_frame_context + 0xcd0,
               original_frame_context + 0xcbc,original_frame_context + 0xca8);
                    /* try { // try from 005617f8 to 005617ff has its CatchHandler @ 00561880 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xc94)
    ;
                    /* try { // try from 00561810 to 00561817 has its CatchHandler @ 00561954 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xca8)
    ;
                    /* try { // try from 0056186c to 00561873 has its CatchHandler @ 00561990 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xcbc)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xcd0)
    ;
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 0x1ac) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1ac),
               *(int *)(original_frame_context + 0x11e4) + 0x6e,
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x100) + 0x1ac) + 0x128) = 0x21;
    *(undefined4 *)(original_frame_context + 0x15c) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1a4);
    if ((original_frame_context[0x16e] == 1) && (original_frame_context[0x16d] == 1)) {
      (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0xd2,0x562);
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb0) =
           *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1a0);
    }
    else if ((original_frame_context[0x16e] == 0) && (original_frame_context[0x16d] == 1)) {
      (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0x78,0x562);
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb0) =
           *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1a0);
    }
    else if ((original_frame_context[0x16e] != 0) && (original_frame_context[0x16d] != 1)) {
      (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0x78,0x562);
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb0) =
           *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x19c);
    }
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
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x13);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))(uVar4,1,uVar3,0xf);
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))
                      (*(undefined4 *)(original_frame_context + 0x11ec));
    uVar4 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))
                      (*(undefined4 *)(original_frame_context + 0x11f0));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3e1c))
              (*(undefined4 *)(original_frame_context + 0x15c),1,uVar3,uVar4);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xc80,0x12a);
                    /* try { // try from 00561cb4 to 00561cbb has its CatchHandler @ 00562704 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xc6c,0x12a);
                    /* try { // try from 00561cd0 to 00561cd7 has its CatchHandler @ 005626ac */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xc58,0x12a);
                    /* try { // try from 00561cec to 00561cf3 has its CatchHandler @ 00561db8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xc44,0x12a);
                    /* try { // try from 00561d18 to 00561d1f has its CatchHandler @ 00561d5c */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1a5c))
              (*(undefined4 *)(original_frame_context + 0x15c),original_frame_context + 0xc80,
               original_frame_context + 0xc6c,original_frame_context + 0xc58);
                    /* try { // try from 00561d30 to 00561d37 has its CatchHandler @ 00561db8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xc44)
    ;
                    /* try { // try from 00561d48 to 00561d4f has its CatchHandler @ 005626ac */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xc58)
    ;
                    /* try { // try from 00561da4 to 00561dab has its CatchHandler @ 00562704 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xc6c)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xc80)
    ;
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 0x1b0) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1b0),
               *(int *)(original_frame_context + 0x11e4) + 0x6e,
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x100) + 0x1b0) + 0x128) = 0x21;
    (**(code **)(iVar2 + -0x72a8))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1b4));
    *(undefined4 *)(original_frame_context + 0x168) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1b8);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x11e4,0x10f,0x1e,0x562);
    (**(code **)(**(int **)(original_frame_context + 0x168) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x168),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined1 *)(*(int *)(original_frame_context + 0x168) + 0x39) = 1;
    *(undefined1 *)(*(int *)(original_frame_context + 0x168) + 0x3a) = 1;
    uVar4 = *(undefined4 *)(original_frame_context + 0x168);
    uVar3 = (**(code **)(iVar2 + -0x5868))(0x13);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))(uVar4,1,uVar3,0xf);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x168) + 0xb8,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x168) + 0xcc,0x122);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x168) + 0xe0,0x122);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x168) + 0xf4,0x122);
    *(undefined4 *)(original_frame_context + 0x154) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1c8);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x11e4,0,0,0x562);
    (**(code **)(**(int **)(original_frame_context + 0x154) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x154),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x154) + 0x260,0x124);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x154) + 0x274,0x124);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x154) + 0x288,0x124);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x154) + 0x29c,0x124);
    *(undefined4 *)(original_frame_context + 0x160) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1c0);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x11e4,0x17d,0x1e,0x562);
    (**(code **)(**(int **)(original_frame_context + 0x160) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x160),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x160) + 0x13a) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x3215);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x160) + 0x146) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x3215);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x160) + 0x152) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x3215);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x160) + 0x15e) = uVar1;
    *(undefined4 *)(*(int *)(original_frame_context + 0x160) + 0x128) = 0x21;
    *(undefined4 *)(*(int *)(original_frame_context + 0x168) + 0xb0) =
         *(undefined4 *)(original_frame_context + 0x168);
    *(undefined4 *)(*(int *)(original_frame_context + 0x168) + 0xb4) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1bc);
    *(undefined4 *)(*(int *)(original_frame_context + 0x168) + 0xa8) =
         *(undefined4 *)(original_frame_context + 0x168);
    *(undefined4 *)(*(int *)(original_frame_context + 0x168) + 0xac) =
         *(undefined4 *)(original_frame_context + 0x168);
    *(undefined4 *)(original_frame_context + 0x168) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1bc);
    (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0x78,0x562);
    (**(code **)(**(int **)(original_frame_context + 0x168) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x168),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined1 *)(*(int *)(original_frame_context + 0x168) + 0x39) = 1;
    *(undefined1 *)(*(int *)(original_frame_context + 0x168) + 0x3a) = 1;
    uVar4 = *(undefined4 *)(original_frame_context + 0x168);
    uVar3 = (**(code **)(iVar2 + -0x5868))(0x13);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))(uVar4,1,uVar3,0xf);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x168) + 0xb8,0x4ac);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x168) + 0xcc,0x122);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x168) + 0xe0,0x122);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x168) + 0xf4,0x122);
    *(undefined4 *)(original_frame_context + 0x154) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1cc);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x11e4,0,0,0x562);
    (**(code **)(**(int **)(original_frame_context + 0x154) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x154),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x154) + 0x260,0x127);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x154) + 0x274,0x127);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x154) + 0x288,0x127);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x154) + 0x29c,0x127);
    *(undefined4 *)(original_frame_context + 0x160) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1c4);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x11e4,0x17d,0x78,0x562);
    (**(code **)(**(int **)(original_frame_context + 0x160) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x160),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x160) + 0x13a) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x3215);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x160) + 0x146) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x3215);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x160) + 0x152) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x3215);
    *(undefined2 *)(*(int *)(original_frame_context + 0x160) + 0x15e) = uVar1;
    *(undefined4 *)(*(int *)(original_frame_context + 0x160) + 0x128) = 0x21;
    *(undefined4 *)(*(int *)(original_frame_context + 0x168) + 0xb0) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1b8);
    *(undefined4 *)(*(int *)(original_frame_context + 0x168) + 0xb4) =
         *(undefined4 *)(original_frame_context + 0x168);
    *(undefined4 *)(*(int *)(original_frame_context + 0x168) + 0xa8) =
         *(undefined4 *)(original_frame_context + 0x168);
    *(undefined4 *)(*(int *)(original_frame_context + 0x168) + 0xac) =
         *(undefined4 *)(original_frame_context + 0x168);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 400) + 0x3c))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 400),
               *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1d4));
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 400) + 0x3c))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 400),
               *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1d8));
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 400) + 0x3c))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 400),
               *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1dc));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1210,0x10f,0x1c,0x545);
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
    *(undefined4 *)(original_frame_context + 0x167c) = uVar3;
                    /* try { // try from 00562698 to 0056269f has its CatchHandler @ 00562748 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
              (*(undefined4 *)(original_frame_context + 0x167c),
               *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 400),
               original_frame_context + 0x1210,0);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0xfc) =
         *(undefined4 *)(original_frame_context + 0x167c);
    if (*(int *)(original_frame_context + 0xfc) == 0) {
      (**(code **)(iVar2 + -0x2400))
                (*(int *)(iVar2 + -0x7fdc) + 0x7b18,*(int *)(iVar2 + -0x7fdc) + 0x7b34,
                 *(int *)(iVar2 + -0x7fdc) + 0x7cf8,0x670);
                    /* WARNING: Subroutine does not return */
      (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
    }
    *(undefined1 *)(*(int *)(original_frame_context + 0xfc) + 0x3a) = 1;
    *(undefined1 *)(*(int *)(original_frame_context + 0xfc) + 0x38) = 0;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xfc) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xfc) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xfc) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xfc) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xfc) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xfc) + 0xa6) = uVar1;
    (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0xfc) + 0xb8,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0xfc) + 0xcc,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0xfc) + 0xe0,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0xfc) + 0xf4,0x5cd);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 400) + 0x34))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 400),
               *(undefined4 *)(original_frame_context + 0xfc));
    (**(code **)(**(int **)(original_frame_context + 0xfc) + 0x34))
              (*(undefined4 *)(original_frame_context + 0xfc),
               *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1d4));
    (**(code **)(**(int **)(original_frame_context + 0xfc) + 0x34))
              (*(undefined4 *)(original_frame_context + 0xfc),
               *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1d8));
    (**(code **)(**(int **)(original_frame_context + 0xfc) + 0x34))
              (*(undefined4 *)(original_frame_context + 0xfc),
               *(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1dc));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1210,0x429,0,0x11e);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 0x1d4) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1d4),
               *(undefined4 *)(original_frame_context + 0x1210),
               *(undefined4 *)(original_frame_context + 0x1214),original_frame_context + 0x1210);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 0x244) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x244),0,0,
               original_frame_context + 0x1210);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1210,0,0,0x91);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 0x23c) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x23c),
               *(undefined4 *)(original_frame_context + 0x1210),
               *(undefined4 *)(original_frame_context + 0x1214),original_frame_context + 0x1210);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x100) + 0x23c) + 0x128) = 0x24;
    (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x1210,0x91,0,0x23);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 0x240) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x240),
               *(undefined4 *)(original_frame_context + 0x1210),
               *(undefined4 *)(original_frame_context + 0x1214),original_frame_context + 0x1210);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x100) + 0x240) + 0x128) = 0x24;
    (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x1210,0x30d,0,0x11e);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 0x1d8) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1d8),
               *(undefined4 *)(original_frame_context + 0x1210),
               *(undefined4 *)(original_frame_context + 0x1214),original_frame_context + 0x1210);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 0x250) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x250),0,0,
               original_frame_context + 0x1210);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1210,0,0,0x91);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 0x248) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x248),
               *(undefined4 *)(original_frame_context + 0x1210),
               *(undefined4 *)(original_frame_context + 0x1214),original_frame_context + 0x1210);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x100) + 0x248) + 0x128) = 0x24;
    (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x1210,0x91,0,0x23);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 0x24c) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x24c),
               *(undefined4 *)(original_frame_context + 0x1210),
               *(undefined4 *)(original_frame_context + 0x1214),original_frame_context + 0x1210);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x100) + 0x24c) + 0x128) = 0x24;
    (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x1210,0x1ef,0,0x11e);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 0x1dc) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x1dc),
               *(undefined4 *)(original_frame_context + 0x1210),
               *(undefined4 *)(original_frame_context + 0x1214),original_frame_context + 0x1210);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1210,0,0,0x96);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 0x254) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 0x254),
               *(undefined4 *)(original_frame_context + 0x1210),
               *(undefined4 *)(original_frame_context + 0x1214),original_frame_context + 0x1210);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x100) + 0x254) + 0x128) = 0x24;
    (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x1210,0x9c,0,0x82);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x100) + 600) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x100) + 600),
               *(undefined4 *)(original_frame_context + 0x1210),
               *(undefined4 *)(original_frame_context + 0x1214),original_frame_context + 0x1210);
    ppuVar5 = *(undefined ***)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x100) + 600) + 0x128) = 0x21;
  }
  *(undefined4 *)(original_frame_context + 0x1674) =
       *(undefined4 *)(original_frame_context + 0x16e4);
  if (*(int *)(original_frame_context + 0x1674) == 0) {
    original_frame_context[0x1678] = 0;
    original_frame_context[0x1679] = 0;
    original_frame_context[0x167a] = 0;
    original_frame_context[0x167b] = 0;
    return *(undefined4 *)(original_frame_context + 0x16e4);
  }
  uVar3 = (*(code *)ppuVar5[-0x1663])
                    (*(undefined4 *)(original_frame_context + 0x1674),ppuVar5[-0x1511],
                     ppuVar5[-0x16db],0);
  return uVar3;
}

