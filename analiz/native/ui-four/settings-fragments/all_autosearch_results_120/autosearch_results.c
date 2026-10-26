
/* Analysis fragment only; external jumps/continuation are abstracted as exits. Not original
   standalone code. Original frame/GP context required. */

undefined4
Settings_fragment_autosearch_results
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
  byte *pbStack00000014;
  
  ppuVar4 = &_gp;
  *(undefined4 *)(original_frame_context + 0x1518) =
       *(undefined4 *)(original_frame_context + 0x16e4);
  if (*(int *)(original_frame_context + 0x1518) == 0) {
    original_frame_context[0x151c] = 0;
    original_frame_context[0x151d] = 0;
    original_frame_context[0x151e] = 0;
    original_frame_context[0x151f] = 0;
  }
  else {
    uVar3 = __dynamic_cast(*(undefined4 *)(original_frame_context + 0x1518),&MMainFrame::typeinfo,
                           &AutoSearchFrame::typeinfo,0);
    ppuVar4 = *(undefined ***)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x151c) = uVar3;
  }
  *(undefined4 *)(original_frame_context + 0xa8) = *(undefined4 *)(original_frame_context + 0x151c);
  if (*(int *)(original_frame_context + 0xa8) == 0) {
    return 0;
  }
  (*(code *)ppuVar4[-0x141b])(original_frame_context + 0x12b4);
  *(undefined4 *)(original_frame_context + 0xa4) =
       *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x1a0);
  *(undefined4 *)(original_frame_context + 0xa0) =
       *(undefined4 *)(*(int *)(original_frame_context + 0xa8) + 0x264);
                    /* try { // try from 005686f8 to 00568f8f has its CatchHandler @ 00570a74 */
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
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x373c))(original_frame_context + 0x12ec);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x6be0))
            (original_frame_context + 0x13c0,original_frame_context + 0x12b4);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x12ec) =
       *(undefined4 *)(original_frame_context + 0x13c0);
  while( true ) {
    (**(code **)(iVar5 + -0x11cc))(original_frame_context + 0x95c,original_frame_context + 0x12b4);
    iVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + 0xed0))
                      (original_frame_context + 0x12ec,original_frame_context + 0x95c);
    iVar6 = *(int *)(original_frame_context + 0x20);
    if (iVar5 == 0) break;
    puVar2 = (undefined4 *)(**(code **)(iVar6 + -0x55d4))(original_frame_context + 0x12ec);
    *(undefined4 *)(original_frame_context + 0x68) = *puVar2;
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x7c) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x80) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x84) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x88) = uVar3;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0xa6) = uVar1;
    (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x68) + 0xb8,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x68) + 0xcc,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x68) + 0xe0,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x68) + 0xf4,0x5cd);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x130) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x13c) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x148) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x154) = 0x4ae;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0x13a) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0x146) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0x152) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x68) + 0x15e) = uVar1;
    *(undefined4 *)(*(int *)(original_frame_context + 0x68) + 0x128) = 0x24;
    (**(code **)(iVar5 + -0x75c4))(original_frame_context + 0x958,original_frame_context + 0x12ec,0)
    ;
    iVar5 = *(int *)(original_frame_context + 0x20);
  }
  *(undefined4 *)(*(int *)(original_frame_context + 0x12d8) + 0x128) = 0x21;
  *(undefined4 *)(original_frame_context + 0x1514) =
       *(undefined4 *)(original_frame_context + 0x12d8);
  uVar1 = (**(code **)(iVar6 + -0x38a4))(0x3213);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x1514) + 0x13a) = uVar1;
  *(undefined4 *)(original_frame_context + 0x1510) =
       *(undefined4 *)(original_frame_context + 0x12d8);
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3213);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x1510) + 0x146) = uVar1;
  *(undefined4 *)(original_frame_context + 0x150c) =
       *(undefined4 *)(original_frame_context + 0x12d8);
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3213);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x150c) + 0x152) = uVar1;
  *(undefined4 *)(original_frame_context + 0x1508) =
       *(undefined4 *)(original_frame_context + 0x12d8);
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3213);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x1508) + 0x15e) = uVar1;
  *(undefined4 *)(original_frame_context + 0x1504) =
       *(undefined4 *)(original_frame_context + 0x12c0);
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x16);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x1504) + 0x7c) = uVar3;
  *(undefined4 *)(original_frame_context + 0x1500) =
       *(undefined4 *)(original_frame_context + 0x12c0);
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x16);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x1500) + 0x80) = uVar3;
  *(undefined4 *)(original_frame_context + 0x14fc) =
       *(undefined4 *)(original_frame_context + 0x12c0);
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x16);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x14fc) + 0x84) = uVar3;
  *(undefined4 *)(original_frame_context + 0x14f8) =
       *(undefined4 *)(original_frame_context + 0x12c0);
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x16);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x14f8) + 0x88) = uVar3;
  (**(code **)(iVar5 + -0x45a8))(original_frame_context + 0x944,0x5cd);
                    /* try { // try from 00568fa4 to 00568fab has its CatchHandler @ 00569164 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x930,0x5cd);
                    /* try { // try from 00568fc0 to 00568fc7 has its CatchHandler @ 0056910c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x91c,0x5cd);
                    /* try { // try from 00568fdc to 00568fe3 has its CatchHandler @ 005690b0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x908,0x5cd);
  pbStack00000010 = original_frame_context + 0x91c;
  pbStack00000014 = original_frame_context + 0x908;
                    /* try { // try from 00569010 to 00569017 has its CatchHandler @ 00569054 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x78c8))
            (*(undefined4 *)(original_frame_context + 0xa0),0,original_frame_context + 0x944,
             original_frame_context + 0x930);
                    /* try { // try from 00569028 to 0056902f has its CatchHandler @ 005690b0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x908);
                    /* try { // try from 00569040 to 00569047 has its CatchHandler @ 0056910c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x91c);
                    /* try { // try from 0056909c to 005690a3 has its CatchHandler @ 00569164 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x930);
                    /* try { // try from 005690f8 to 005690ff has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x944);
                    /* try { // try from 00569150 to 00569157 has its CatchHandler @ 00570a74 */
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x16);
  *(undefined4 *)(original_frame_context + 0x14f4) = uVar3;
                    /* try { // try from 005691ac to 005692cf has its CatchHandler @ 00570a74 */
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x16);
  *(undefined4 *)(original_frame_context + 0x14f0) = uVar3;
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x16);
  *(undefined4 *)(original_frame_context + 0x14ec) = uVar3;
  pbStack00000010 = (byte *)(**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x16);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x228))
            (*(undefined4 *)(original_frame_context + 0xa0),
             *(undefined4 *)(original_frame_context + 0x14f4),
             *(undefined4 *)(original_frame_context + 0x14f0),
             *(undefined4 *)(original_frame_context + 0x14ec));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x15);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0xa0) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x15);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0xa0) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x15);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0xa0) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x15);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0xa0) + 0x58) = uVar3;
  *(undefined1 *)(*(int *)(original_frame_context + 0xa0) + 0x3a) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0xa0) + 0x39) = 1;
  pbStack00000010 = (byte *)0x226;
  (**(code **)(iVar5 + -0x2b00))(original_frame_context + 0x12f0,0,0x1e,0x780);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x14e8) = uVar3;
  pbStack00000010 = (byte *)0x67;
                    /* try { // try from 00569300 to 00569307 has its CatchHandler @ 00569328 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x14e8),
             *(undefined4 *)(*(int *)(original_frame_context + 0x16e4) + 0x38),
             original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x9c) = *(undefined4 *)(original_frame_context + 0x14e8);
  if (*(int *)(original_frame_context + 0x9c) == 0) {
                    /* try { // try from 00569380 to 00569577 has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0x9e5);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x11d4))(*(undefined4 *)(original_frame_context + 0x9c),2,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x9c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x9c) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x9c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x9c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x9c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x9c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x9c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x9c) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x9c) + 0xb8,0x5cd);
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
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x14e4) = uVar3;
  pbStack00000010 = (byte *)0x68;
                    /* try { // try from 005695a0 to 005695a7 has its CatchHandler @ 005695c8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x14e4),
             *(undefined4 *)(original_frame_context + 0x9c),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x98) = *(undefined4 *)(original_frame_context + 0x14e4);
  if (*(int *)(original_frame_context + 0x98) == 0) {
                    /* try { // try from 00569620 to 005699ab has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0x9f7);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x98) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x98) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x98) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x98) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x98) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x98) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x98) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x98) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x98) + 0xb8,0x137);
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
             *(undefined4 *)(original_frame_context + 0x12f4),original_frame_context + 0x12f0);
  pbStack00000010 = (byte *)0x52;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x12f0,0,0,0x14a);
  (**(code **)(**(int **)(original_frame_context + 0x12d8) + 0x24))
            (*(undefined4 *)(original_frame_context + 0x12d8),
             *(undefined4 *)(original_frame_context + 0x12f0),
             *(undefined4 *)(original_frame_context + 0x12f4),original_frame_context + 0x12f0);
  pbStack00000010 = (byte *)0x52;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x12f0,0x508,0,0x5a);
  (**(code **)(**(int **)(original_frame_context + 0x12c0) + 0x24))
            (*(undefined4 *)(original_frame_context + 0x12c0),
             *(undefined4 *)(original_frame_context + 0x12f0),
             *(undefined4 *)(original_frame_context + 0x12f4),original_frame_context + 0x12f0);
  pbStack00000010 = (byte *)0x16c;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x12f0,0x10f,0x72,0x1b7);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x14e0) = uVar3;
  pbStack00000010 = (byte *)0x69;
                    /* try { // try from 005699d4 to 005699db has its CatchHandler @ 005699fc */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x14e0),
             *(undefined4 *)(original_frame_context + 0x9c),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x94) = *(undefined4 *)(original_frame_context + 0x14e0);
  if (*(int *)(original_frame_context + 0x94) == 0) {
                    /* try { // try from 00569a54 to 00569c23 has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xa11);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x94) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x94) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x94) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x94) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x94) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x94) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x94) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x94) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x94) + 0xb8,0x5cd);
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
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x14dc) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 00569c4c to 00569c53 has its CatchHandler @ 00569c74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x14dc),
             *(undefined4 *)(original_frame_context + 0x94),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x90) = *(undefined4 *)(original_frame_context + 0x14dc);
  if (*(int *)(original_frame_context + 0x90) == 0) {
                    /* try { // try from 00569ccc to 00569fbf has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xa22);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x90) + 0x170,0xeee);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x90) + 0x39) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x90) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x1a);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x1a);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x1a);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x1a);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  *(undefined2 *)(*(int *)(original_frame_context + 0x90) + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x90) + 0x128) = 0x21;
  (**(code **)(**(int **)(original_frame_context + 0x94) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x94),
             *(undefined4 *)(original_frame_context + 0x90));
  pbStack00000010 = (byte *)0x12c;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x12f0,0,0x40,0x1b7);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0xbf8);
  *(undefined4 *)(original_frame_context + 0x14d8) = uVar3;
  pbStack00000010 = (byte *)0x6c;
                    /* try { // try from 00569fe8 to 00569fef has its CatchHandler @ 0056a010 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x605c))
            (*(undefined4 *)(original_frame_context + 0x14d8),
             *(undefined4 *)(original_frame_context + 0x94),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x8c) = *(undefined4 *)(original_frame_context + 0x14d8);
  if (*(int *)(original_frame_context + 0x8c) == 0) {
                    /* try { // try from 0056a068 to 0056a20f has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xa40);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x8c) + 0x39) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x8c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x8c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x8c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x8c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x8c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x8c) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x8c) + 0xb8,0x5cd);
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
                    /* try { // try from 0056a224 to 0056a22b has its CatchHandler @ 0056a3e4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x8e0,0x5cd);
                    /* try { // try from 0056a240 to 0056a247 has its CatchHandler @ 0056a384 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x8cc,0x5cd);
                    /* try { // try from 0056a25c to 0056a263 has its CatchHandler @ 0056a328 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x8b8,0x5cd);
  pbStack00000010 = original_frame_context + 0x8b8;
                    /* try { // try from 0056a288 to 0056a28f has its CatchHandler @ 0056a2cc */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x77c8))
            (*(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x8f4,
             original_frame_context + 0x8e0,original_frame_context + 0x8cc);
                    /* try { // try from 0056a2a0 to 0056a2a7 has its CatchHandler @ 0056a328 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x8b8);
                    /* try { // try from 0056a2b8 to 0056a2bf has its CatchHandler @ 0056a384 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x8cc);
                    /* try { // try from 0056a314 to 0056a31b has its CatchHandler @ 0056a3e4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x8e0);
                    /* try { // try from 0056a370 to 0056a377 has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x8f4);
                    /* try { // try from 0056a3d0 to 0056a3d7 has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x8a4,0x5cd);
                    /* try { // try from 0056a430 to 0056a437 has its CatchHandler @ 0056a5f0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x890,0x5cd);
                    /* try { // try from 0056a44c to 0056a453 has its CatchHandler @ 0056a590 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x87c,0x5cd);
                    /* try { // try from 0056a468 to 0056a46f has its CatchHandler @ 0056a534 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x868,0x5cd);
  pbStack00000010 = original_frame_context + 0x868;
                    /* try { // try from 0056a494 to 0056a49b has its CatchHandler @ 0056a4d8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x447c))
            (*(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x8a4,
             original_frame_context + 0x890,original_frame_context + 0x87c);
                    /* try { // try from 0056a4ac to 0056a4b3 has its CatchHandler @ 0056a534 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x868);
                    /* try { // try from 0056a4c4 to 0056a4cb has its CatchHandler @ 0056a590 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x87c);
                    /* try { // try from 0056a520 to 0056a527 has its CatchHandler @ 0056a5f0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x890);
                    /* try { // try from 0056a57c to 0056a583 has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x8a4);
                    /* try { // try from 0056a5dc to 0056a5e3 has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x854,0x5cd);
                    /* try { // try from 0056a63c to 0056a643 has its CatchHandler @ 0056a7fc */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x840,0x5cd);
                    /* try { // try from 0056a658 to 0056a65f has its CatchHandler @ 0056a79c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x82c,0x5cd);
                    /* try { // try from 0056a674 to 0056a67b has its CatchHandler @ 0056a740 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x818,0x5cd);
  pbStack00000010 = original_frame_context + 0x818;
                    /* try { // try from 0056a6a0 to 0056a6a7 has its CatchHandler @ 0056a6e4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x17d4))
            (*(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x854,
             original_frame_context + 0x840,original_frame_context + 0x82c);
                    /* try { // try from 0056a6b8 to 0056a6bf has its CatchHandler @ 0056a740 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x818);
                    /* try { // try from 0056a6d0 to 0056a6d7 has its CatchHandler @ 0056a79c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x82c);
                    /* try { // try from 0056a72c to 0056a733 has its CatchHandler @ 0056a7fc */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x840);
                    /* try { // try from 0056a788 to 0056a78f has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x854);
                    /* try { // try from 0056a7e8 to 0056a7ef has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x804,0x5cd);
                    /* try { // try from 0056a848 to 0056a84f has its CatchHandler @ 0056aa0c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x7f0,0x5cd);
                    /* try { // try from 0056a864 to 0056a86b has its CatchHandler @ 0056a9a8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x7dc,0x5cd);
                    /* try { // try from 0056a880 to 0056a887 has its CatchHandler @ 0056a94c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x7c8,0x5cd);
  pbStack00000010 = original_frame_context + 0x7c8;
                    /* try { // try from 0056a8ac to 0056a8b3 has its CatchHandler @ 0056a8f0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4bb4))
            (*(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x804,
             original_frame_context + 0x7f0,original_frame_context + 0x7dc);
                    /* try { // try from 0056a8c4 to 0056a8cb has its CatchHandler @ 0056a94c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x7c8);
                    /* try { // try from 0056a8dc to 0056a8e3 has its CatchHandler @ 0056a9a8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x7dc);
                    /* try { // try from 0056a938 to 0056a93f has its CatchHandler @ 0056aa0c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x7f0);
                    /* try { // try from 0056a994 to 0056a99b has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x804);
                    /* try { // try from 0056a9f8 to 0056a9ff has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x11d4))
            (*(undefined4 *)(original_frame_context + 0x8c),2,1);
                    /* try { // try from 0056aa68 to 0056aaaf has its CatchHandler @ 00570a74 */
  (**(code **)(**(int **)(original_frame_context + 0x94) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x94),
             *(undefined4 *)(original_frame_context + 0x8c));
  pbStack00000010 = (byte *)0x16c;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x12f0,0x2e5,0x72,0x1b7);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x14d4) = uVar3;
  pbStack00000010 = (byte *)0x6a;
                    /* try { // try from 0056aad8 to 0056aadf has its CatchHandler @ 0056ab00 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x14d4),
             *(undefined4 *)(original_frame_context + 0x9c),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x88) = *(undefined4 *)(original_frame_context + 0x14d4);
  if (*(int *)(original_frame_context + 0x88) == 0) {
                    /* try { // try from 0056ab58 to 0056ad27 has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xa57);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x88) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x88) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x88) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x88) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x88) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x88) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x88) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x88) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x88) + 0xb8,0x5cd);
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
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x14d0) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 0056ad50 to 0056ad57 has its CatchHandler @ 0056ad78 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x14d0),
             *(undefined4 *)(original_frame_context + 0x88),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x84) = *(undefined4 *)(original_frame_context + 0x14d0);
  if (*(int *)(original_frame_context + 0x84) == 0) {
                    /* try { // try from 0056add0 to 0056b0c3 has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xa68);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x84) + 0x170,0xfa3);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x84) + 0x39) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x84) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x18);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x18);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x18);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x18);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  *(undefined2 *)(*(int *)(original_frame_context + 0x84) + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x84) + 0x128) = 0x21;
  (**(code **)(**(int **)(original_frame_context + 0x88) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x88),
             *(undefined4 *)(original_frame_context + 0x84));
  pbStack00000010 = (byte *)0x12c;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x12f0,0,0x40,0x1b7);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0xbf8);
  *(undefined4 *)(original_frame_context + 0x14cc) = uVar3;
  pbStack00000010 = (byte *)0x6d;
                    /* try { // try from 0056b0ec to 0056b0f3 has its CatchHandler @ 0056b114 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x605c))
            (*(undefined4 *)(original_frame_context + 0x14cc),
             *(undefined4 *)(original_frame_context + 0x88),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x80) = *(undefined4 *)(original_frame_context + 0x14cc);
  if (*(int *)(original_frame_context + 0x80) == 0) {
                    /* try { // try from 0056b16c to 0056b313 has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xa86);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x80) + 0x39) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x80) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x80) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x80) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x80) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x80) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x80) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x80) + 0xb8,0x5cd);
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
                    /* try { // try from 0056b328 to 0056b32f has its CatchHandler @ 0056b4e8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x7a0,0x5cd);
                    /* try { // try from 0056b344 to 0056b34b has its CatchHandler @ 0056b488 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x78c,0x5cd);
                    /* try { // try from 0056b360 to 0056b367 has its CatchHandler @ 0056b42c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x778,0x5cd);
  pbStack00000010 = original_frame_context + 0x778;
                    /* try { // try from 0056b38c to 0056b393 has its CatchHandler @ 0056b3d0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x77c8))
            (*(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x7b4,
             original_frame_context + 0x7a0,original_frame_context + 0x78c);
                    /* try { // try from 0056b3a4 to 0056b3ab has its CatchHandler @ 0056b42c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x778);
                    /* try { // try from 0056b3bc to 0056b3c3 has its CatchHandler @ 0056b488 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x78c);
                    /* try { // try from 0056b418 to 0056b41f has its CatchHandler @ 0056b4e8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x7a0);
                    /* try { // try from 0056b474 to 0056b47b has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x7b4);
                    /* try { // try from 0056b4d4 to 0056b4db has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x764,0x5cd);
                    /* try { // try from 0056b534 to 0056b53b has its CatchHandler @ 0056b6f4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x750,0x5cd);
                    /* try { // try from 0056b550 to 0056b557 has its CatchHandler @ 0056b694 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x73c,0x5cd);
                    /* try { // try from 0056b56c to 0056b573 has its CatchHandler @ 0056b638 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x728,0x5cd);
  pbStack00000010 = original_frame_context + 0x728;
                    /* try { // try from 0056b598 to 0056b59f has its CatchHandler @ 0056b5dc */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x447c))
            (*(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x764,
             original_frame_context + 0x750,original_frame_context + 0x73c);
                    /* try { // try from 0056b5b0 to 0056b5b7 has its CatchHandler @ 0056b638 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x728);
                    /* try { // try from 0056b5c8 to 0056b5cf has its CatchHandler @ 0056b694 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x73c);
                    /* try { // try from 0056b624 to 0056b62b has its CatchHandler @ 0056b6f4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x750);
                    /* try { // try from 0056b680 to 0056b687 has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x764);
                    /* try { // try from 0056b6e0 to 0056b6e7 has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x714,0x5cd);
                    /* try { // try from 0056b740 to 0056b747 has its CatchHandler @ 0056b900 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x700,0x5cd);
                    /* try { // try from 0056b75c to 0056b763 has its CatchHandler @ 0056b8a0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x6ec,0x5cd);
                    /* try { // try from 0056b778 to 0056b77f has its CatchHandler @ 0056b844 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x6d8,0x5cd);
  pbStack00000010 = original_frame_context + 0x6d8;
                    /* try { // try from 0056b7a4 to 0056b7ab has its CatchHandler @ 0056b7e8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x17d4))
            (*(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x714,
             original_frame_context + 0x700,original_frame_context + 0x6ec);
                    /* try { // try from 0056b7bc to 0056b7c3 has its CatchHandler @ 0056b844 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x6d8);
                    /* try { // try from 0056b7d4 to 0056b7db has its CatchHandler @ 0056b8a0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x6ec);
                    /* try { // try from 0056b830 to 0056b837 has its CatchHandler @ 0056b900 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x700);
                    /* try { // try from 0056b88c to 0056b893 has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x714);
                    /* try { // try from 0056b8ec to 0056b8f3 has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x6c4,0x5cd);
                    /* try { // try from 0056b94c to 0056b953 has its CatchHandler @ 0056bb10 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x6b0,0x5cd);
                    /* try { // try from 0056b968 to 0056b96f has its CatchHandler @ 0056baac */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x69c,0x5cd);
                    /* try { // try from 0056b984 to 0056b98b has its CatchHandler @ 0056ba50 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x688,0x5cd);
  pbStack00000010 = original_frame_context + 0x688;
                    /* try { // try from 0056b9b0 to 0056b9b7 has its CatchHandler @ 0056b9f4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4bb4))
            (*(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x6c4,
             original_frame_context + 0x6b0,original_frame_context + 0x69c);
                    /* try { // try from 0056b9c8 to 0056b9cf has its CatchHandler @ 0056ba50 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x688);
                    /* try { // try from 0056b9e0 to 0056b9e7 has its CatchHandler @ 0056baac */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x69c);
                    /* try { // try from 0056ba3c to 0056ba43 has its CatchHandler @ 0056bb10 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x6b0);
                    /* try { // try from 0056ba98 to 0056ba9f has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x6c4);
                    /* try { // try from 0056bafc to 0056bb03 has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x11d4))
            (*(undefined4 *)(original_frame_context + 0x80),2,1);
                    /* try { // try from 0056bb6c to 0056bbb3 has its CatchHandler @ 00570a74 */
  (**(code **)(**(int **)(original_frame_context + 0x88) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x88),
             *(undefined4 *)(original_frame_context + 0x80));
  pbStack00000010 = (byte *)0x16c;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x12f0,0x4bb,0x72,0x1b7);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x14c8) = uVar3;
  pbStack00000010 = (byte *)0x6b;
                    /* try { // try from 0056bbdc to 0056bbe3 has its CatchHandler @ 0056bc04 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x14c8),
             *(undefined4 *)(original_frame_context + 0x9c),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x7c) = *(undefined4 *)(original_frame_context + 0x14c8);
  if (*(int *)(original_frame_context + 0x7c) == 0) {
                    /* try { // try from 0056bc5c to 0056be2b has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xa9d);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x7c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x7c) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x7c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x7c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x7c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x7c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x7c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x7c) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x7c) + 0xb8,0x5cd);
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
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x14c4) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 0056be54 to 0056be5b has its CatchHandler @ 0056be7c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x14c4),
             *(undefined4 *)(original_frame_context + 0x7c),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x78) = *(undefined4 *)(original_frame_context + 0x14c4);
  if (*(int *)(original_frame_context + 0x78) == 0) {
                    /* try { // try from 0056bed4 to 0056c1c7 has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xaae);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x78) + 0x170,0xdcc);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x78) + 0x39) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x78) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x19);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x19);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x19);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x19);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  *(undefined2 *)(*(int *)(original_frame_context + 0x78) + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x78) + 0x128) = 0x21;
  (**(code **)(**(int **)(original_frame_context + 0x7c) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x7c),
             *(undefined4 *)(original_frame_context + 0x78));
  pbStack00000010 = (byte *)0x12c;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x12f0,0,0x40,0x1b7);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0xbf8);
  *(undefined4 *)(original_frame_context + 0x14c0) = uVar3;
  pbStack00000010 = (byte *)0x6e;
                    /* try { // try from 0056c1f0 to 0056c1f7 has its CatchHandler @ 0056c218 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x605c))
            (*(undefined4 *)(original_frame_context + 0x14c0),
             *(undefined4 *)(original_frame_context + 0x7c),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x74) = *(undefined4 *)(original_frame_context + 0x14c0);
  if (*(int *)(original_frame_context + 0x74) == 0) {
                    /* try { // try from 0056c270 to 0056c417 has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xacc);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x74) + 0x39) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x74) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x74) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x74) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x74) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x74) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45dd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x74) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x74) + 0xb8,0x5cd);
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
                    /* try { // try from 0056c42c to 0056c433 has its CatchHandler @ 0056c5ec */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x660,0x5cd);
                    /* try { // try from 0056c448 to 0056c44f has its CatchHandler @ 0056c58c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x64c,0x5cd);
                    /* try { // try from 0056c464 to 0056c46b has its CatchHandler @ 0056c530 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x638,0x5cd);
  pbStack00000010 = original_frame_context + 0x638;
                    /* try { // try from 0056c490 to 0056c497 has its CatchHandler @ 0056c4d4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x77c8))
            (*(undefined4 *)(original_frame_context + 0x74),original_frame_context + 0x674,
             original_frame_context + 0x660,original_frame_context + 0x64c);
                    /* try { // try from 0056c4a8 to 0056c4af has its CatchHandler @ 0056c530 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x638);
                    /* try { // try from 0056c4c0 to 0056c4c7 has its CatchHandler @ 0056c58c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x64c);
                    /* try { // try from 0056c51c to 0056c523 has its CatchHandler @ 0056c5ec */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x660);
                    /* try { // try from 0056c578 to 0056c57f has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x674);
                    /* try { // try from 0056c5d8 to 0056c5df has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x624,0x5cd);
                    /* try { // try from 0056c638 to 0056c63f has its CatchHandler @ 0056c7f8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x610,0x5cd);
                    /* try { // try from 0056c654 to 0056c65b has its CatchHandler @ 0056c798 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x5fc,0x5cd);
                    /* try { // try from 0056c670 to 0056c677 has its CatchHandler @ 0056c73c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x5e8,0x5cd);
  pbStack00000010 = original_frame_context + 0x5e8;
                    /* try { // try from 0056c69c to 0056c6a3 has its CatchHandler @ 0056c6e0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x447c))
            (*(undefined4 *)(original_frame_context + 0x74),original_frame_context + 0x624,
             original_frame_context + 0x610,original_frame_context + 0x5fc);
                    /* try { // try from 0056c6b4 to 0056c6bb has its CatchHandler @ 0056c73c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x5e8);
                    /* try { // try from 0056c6cc to 0056c6d3 has its CatchHandler @ 0056c798 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x5fc);
                    /* try { // try from 0056c728 to 0056c72f has its CatchHandler @ 0056c7f8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x610);
                    /* try { // try from 0056c784 to 0056c78b has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x624);
                    /* try { // try from 0056c7e4 to 0056c7eb has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x5d4,0x5cd);
                    /* try { // try from 0056c844 to 0056c84b has its CatchHandler @ 0056ca04 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x5c0,0x5cd);
                    /* try { // try from 0056c860 to 0056c867 has its CatchHandler @ 0056c9a4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x5ac,0x5cd);
                    /* try { // try from 0056c87c to 0056c883 has its CatchHandler @ 0056c948 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x598,0x5cd);
  pbStack00000010 = original_frame_context + 0x598;
                    /* try { // try from 0056c8a8 to 0056c8af has its CatchHandler @ 0056c8ec */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x17d4))
            (*(undefined4 *)(original_frame_context + 0x74),original_frame_context + 0x5d4,
             original_frame_context + 0x5c0,original_frame_context + 0x5ac);
                    /* try { // try from 0056c8c0 to 0056c8c7 has its CatchHandler @ 0056c948 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x598);
                    /* try { // try from 0056c8d8 to 0056c8df has its CatchHandler @ 0056c9a4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x5ac);
                    /* try { // try from 0056c934 to 0056c93b has its CatchHandler @ 0056ca04 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x5c0);
                    /* try { // try from 0056c990 to 0056c997 has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x5d4);
                    /* try { // try from 0056c9f0 to 0056c9f7 has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x584,0x5cd);
                    /* try { // try from 0056ca50 to 0056ca57 has its CatchHandler @ 0056cc14 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x570,0x5cd);
                    /* try { // try from 0056ca6c to 0056ca73 has its CatchHandler @ 0056cbb0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x55c,0x5cd);
                    /* try { // try from 0056ca88 to 0056ca8f has its CatchHandler @ 0056cb54 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
            (original_frame_context + 0x548,0x5cd);
  pbStack00000010 = original_frame_context + 0x548;
                    /* try { // try from 0056cab4 to 0056cabb has its CatchHandler @ 0056caf8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4bb4))
            (*(undefined4 *)(original_frame_context + 0x74),original_frame_context + 0x584,
             original_frame_context + 0x570,original_frame_context + 0x55c);
                    /* try { // try from 0056cacc to 0056cad3 has its CatchHandler @ 0056cb54 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x548);
                    /* try { // try from 0056cae4 to 0056caeb has its CatchHandler @ 0056cbb0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x55c);
                    /* try { // try from 0056cb40 to 0056cb47 has its CatchHandler @ 0056cc14 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x570);
                    /* try { // try from 0056cb9c to 0056cba3 has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x584);
                    /* try { // try from 0056cc00 to 0056cc07 has its CatchHandler @ 00570a74 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x11d4))
            (*(undefined4 *)(original_frame_context + 0x74),2,1);
                    /* try { // try from 0056cc70 to 0056ccb7 has its CatchHandler @ 00570a74 */
  (**(code **)(**(int **)(original_frame_context + 0x7c) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x7c),
             *(undefined4 *)(original_frame_context + 0x74));
  pbStack00000010 = (byte *)0x3c;
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
            (original_frame_context + 0x12f0,0,0,0x1b7);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x14bc) = uVar3;
  pbStack00000010 = (byte *)0x6f;
                    /* try { // try from 0056cce0 to 0056cce7 has its CatchHandler @ 0056cd08 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x14bc),
             *(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x70) = *(undefined4 *)(original_frame_context + 0x14bc);
  if (*(int *)(original_frame_context + 0x70) == 0) {
                    /* try { // try from 0056cd60 to 0056cf5f has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xae3);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
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
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x14b8) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 0056cf88 to 0056cf8f has its CatchHandler @ 0056cfb0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x14b8),
             *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x6c) = *(undefined4 *)(original_frame_context + 0x14b8);
  if (*(int *)(original_frame_context + 0x6c) == 0) {
                    /* try { // try from 0056d008 to 0056d333 has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xaf7);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0x11db);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
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
             *(undefined4 *)(original_frame_context + 0x1304),original_frame_context + 0x1300);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x14b4) = uVar3;
  pbStack00000010 = (byte *)0x70;
                    /* try { // try from 0056d35c to 0056d363 has its CatchHandler @ 0056d384 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x14b4),
             *(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x70) = *(undefined4 *)(original_frame_context + 0x14b4);
  if (*(int *)(original_frame_context + 0x70) == 0) {
                    /* try { // try from 0056d3dc to 0056d583 has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xb16);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
  (**(code **)(**(int **)(original_frame_context + 0x8c) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x8c),
             *(undefined4 *)(original_frame_context + 0x70));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x14b0) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 0056d5ac to 0056d5b3 has its CatchHandler @ 0056d5d4 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x14b0),
             *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x6c) = *(undefined4 *)(original_frame_context + 0x14b0);
  if (*(int *)(original_frame_context + 0x6c) == 0) {
                    /* try { // try from 0056d62c to 0056d957 has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xb26);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0xcda);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
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
             *(undefined4 *)(original_frame_context + 0x1304),original_frame_context + 0x1300);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x14ac) = uVar3;
  pbStack00000010 = (byte *)0x71;
                    /* try { // try from 0056d980 to 0056d987 has its CatchHandler @ 0056d9a8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x14ac),
             *(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x70) = *(undefined4 *)(original_frame_context + 0x14ac);
  if (*(int *)(original_frame_context + 0x70) == 0) {
                    /* try { // try from 0056da00 to 0056dba7 has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xb45);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
  (**(code **)(**(int **)(original_frame_context + 0x8c) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x8c),
             *(undefined4 *)(original_frame_context + 0x70));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x14a8) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 0056dbd0 to 0056dbd7 has its CatchHandler @ 0056dbf8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x14a8),
             *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x6c) = *(undefined4 *)(original_frame_context + 0x14a8);
  if (*(int *)(original_frame_context + 0x6c) == 0) {
                    /* try { // try from 0056dc50 to 0056df7b has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xb55);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0xed0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
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
             *(undefined4 *)(original_frame_context + 0x1304),original_frame_context + 0x1300);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x14a4) = uVar3;
  pbStack00000010 = (byte *)0x72;
                    /* try { // try from 0056dfa4 to 0056dfab has its CatchHandler @ 0056dfcc */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x14a4),
             *(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x70) = *(undefined4 *)(original_frame_context + 0x14a4);
  if (*(int *)(original_frame_context + 0x70) == 0) {
                    /* try { // try from 0056e024 to 0056e1cb has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xb74);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
  (**(code **)(**(int **)(original_frame_context + 0x8c) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x8c),
             *(undefined4 *)(original_frame_context + 0x70));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x14a0) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 0056e1f4 to 0056e1fb has its CatchHandler @ 0056e21c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x14a0),
             *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x6c) = *(undefined4 *)(original_frame_context + 0x14a0);
  if (*(int *)(original_frame_context + 0x6c) == 0) {
                    /* try { // try from 0056e274 to 0056e59f has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xb84);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0xc15);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
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
             *(undefined4 *)(original_frame_context + 0x1304),original_frame_context + 0x1300);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x149c) = uVar3;
  pbStack00000010 = (byte *)0x73;
                    /* try { // try from 0056e5c8 to 0056e5cf has its CatchHandler @ 0056e5f0 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x149c),
             *(undefined4 *)(original_frame_context + 0x8c),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x70) = *(undefined4 *)(original_frame_context + 0x149c);
  if (*(int *)(original_frame_context + 0x70) == 0) {
                    /* try { // try from 0056e648 to 0056e7ef has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xba3);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
  (**(code **)(**(int **)(original_frame_context + 0x8c) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x8c),
             *(undefined4 *)(original_frame_context + 0x70));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x1498) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 0056e818 to 0056e81f has its CatchHandler @ 0056e840 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x1498),
             *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x6c) = *(undefined4 *)(original_frame_context + 0x1498);
  if (*(int *)(original_frame_context + 0x6c) == 0) {
                    /* try { // try from 0056e898 to 0056ebc3 has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xbb3);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0xcbd);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
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
             *(undefined4 *)(original_frame_context + 0x1304),original_frame_context + 0x1300);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x1494) = uVar3;
  pbStack00000010 = (byte *)0x74;
                    /* try { // try from 0056ebec to 0056ebf3 has its CatchHandler @ 0056ec14 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x1494),
             *(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x70) = *(undefined4 *)(original_frame_context + 0x1494);
  if (*(int *)(original_frame_context + 0x70) == 0) {
                    /* try { // try from 0056ec6c to 0056ee13 has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xbd2);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
  (**(code **)(**(int **)(original_frame_context + 0x80) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x80),
             *(undefined4 *)(original_frame_context + 0x70));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x1490) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 0056ee3c to 0056ee43 has its CatchHandler @ 0056ee64 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x1490),
             *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x6c) = *(undefined4 *)(original_frame_context + 0x1490);
  if (*(int *)(original_frame_context + 0x6c) == 0) {
                    /* try { // try from 0056eebc to 0056f21b has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xbe2);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0xfa1);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
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
            (original_frame_context + 0x1320,*(int *)(original_frame_context + 0x1300) + -0x78,
             *(undefined4 *)(original_frame_context + 0x1304),
             *(int *)(original_frame_context + 0x1308) + 0x78);
  (**(code **)(**(int **)(original_frame_context + 0x12d4) + 0x24))
            (*(undefined4 *)(original_frame_context + 0x12d4),
             *(undefined4 *)(original_frame_context + 0x1320),
             *(undefined4 *)(original_frame_context + 0x1324),original_frame_context + 0x1320);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x148c) = uVar3;
  pbStack00000010 = (byte *)0x75;
                    /* try { // try from 0056f244 to 0056f24b has its CatchHandler @ 0056f26c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x148c),
             *(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x70) = *(undefined4 *)(original_frame_context + 0x148c);
  if (*(int *)(original_frame_context + 0x70) == 0) {
                    /* try { // try from 0056f2c4 to 0056f48b has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xc03);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x11d4))(*(undefined4 *)(original_frame_context + 0x70),2,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
  (**(code **)(**(int **)(original_frame_context + 0x80) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x80),
             *(undefined4 *)(original_frame_context + 0x70));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x1488) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 0056f4b4 to 0056f4bb has its CatchHandler @ 0056f4dc */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x1488),
             *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x6c) = *(undefined4 *)(original_frame_context + 0x1488);
  if (*(int *)(original_frame_context + 0x6c) == 0) {
                    /* try { // try from 0056f534 to 0056f7f7 has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xc14);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0xeb4);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x15e) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x128) = 0x21;
  (**(code **)(**(int **)(original_frame_context + 0x70) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x70),
             *(undefined4 *)(original_frame_context + 0x6c));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x1484) = uVar3;
  pbStack00000010 = (byte *)0x76;
                    /* try { // try from 0056f820 to 0056f827 has its CatchHandler @ 0056f848 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x1484),
             *(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x70) = *(undefined4 *)(original_frame_context + 0x1484);
  if (*(int *)(original_frame_context + 0x70) == 0) {
                    /* try { // try from 0056f8a0 to 0056fa47 has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xc31);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
  (**(code **)(**(int **)(original_frame_context + 0x80) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x80),
             *(undefined4 *)(original_frame_context + 0x70));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x1480) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 0056fa70 to 0056fa77 has its CatchHandler @ 0056fa98 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x1480),
             *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x6c) = *(undefined4 *)(original_frame_context + 0x1480);
  if (*(int *)(original_frame_context + 0x6c) == 0) {
                    /* try { // try from 0056faf0 to 0056fe1b has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xc41);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0x1115);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
  *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar3;
  uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar3;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
  *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
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
             *(undefined4 *)(original_frame_context + 0x1324),original_frame_context + 0x1320);
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
  *(undefined4 *)(original_frame_context + 0x147c) = uVar3;
  pbStack00000010 = (byte *)0x77;
                    /* try { // try from 0056fe44 to 0056fe4b has its CatchHandler @ 0056fe6c */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
            (*(undefined4 *)(original_frame_context + 0x147c),
             *(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x12f0,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x70) = *(undefined4 *)(original_frame_context + 0x147c);
  if (*(int *)(original_frame_context + 0x70) == 0) {
                    /* try { // try from 0056fec4 to 0057006b has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xc60);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
  *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
  uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
  (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
            (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
  (**(code **)(**(int **)(original_frame_context + 0x80) + 0x34))
            (*(undefined4 *)(original_frame_context + 0x80),
             *(undefined4 *)(original_frame_context + 0x70));
  uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
  *(undefined4 *)(original_frame_context + 0x1478) = uVar3;
  pbStack00000010 = (byte *)0x0;
                    /* try { // try from 00570094 to 0057009b has its CatchHandler @ 005700bc */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
            (*(undefined4 *)(original_frame_context + 0x1478),
             *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x6c) = *(undefined4 *)(original_frame_context + 0x1478);
  if (*(int *)(original_frame_context + 0x6c) != 0) {
    (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0xeb1);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
    *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar3;
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar3;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
    *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
    *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
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
               *(undefined4 *)(original_frame_context + 0x1304),original_frame_context + 0x1300);
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
    *(undefined4 *)(original_frame_context + 0x1474) = uVar3;
    pbStack00000010 = (byte *)0x78;
                    /* try { // try from 00570468 to 0057046f has its CatchHandler @ 00570490 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
              (*(undefined4 *)(original_frame_context + 0x1474),
               *(undefined4 *)(original_frame_context + 0x80),original_frame_context + 0x12f0,0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x70) =
         *(undefined4 *)(original_frame_context + 0x1474);
    if (*(int *)(original_frame_context + 0x70) == 0) {
                    /* try { // try from 005704e8 to 0057068f has its CatchHandler @ 00570a74 */
      (**(code **)(iVar5 + -0x2400))
                (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
                 *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xc8f);
                    /* WARNING: Subroutine does not return */
      (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
    }
    *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x3a) = 1;
    *(undefined1 *)(*(int *)(original_frame_context + 0x70) + 0x38) = 0;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x70) + 0xa6) = uVar1;
    (**(code **)(iVar5 + -0x910))(*(int *)(original_frame_context + 0x70) + 0xb8,0x136);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x70) + 0xcc,0x136);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x70) + 0xe0,0x136);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x70) + 0xf4,0x136);
    (**(code **)(**(int **)(original_frame_context + 0x80) + 0x34))
              (*(undefined4 *)(original_frame_context + 0x80),
               *(undefined4 *)(original_frame_context + 0x70));
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x250);
    *(undefined4 *)(original_frame_context + 0x1470) = uVar3;
    pbStack00000010 = (byte *)0x0;
                    /* try { // try from 005706b8 to 005706bf has its CatchHandler @ 005706e0 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x36d0))
              (*(undefined4 *)(original_frame_context + 0x1470),
               *(undefined4 *)(original_frame_context + 0x70),original_frame_context + 0x1310,0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x6c) =
         *(undefined4 *)(original_frame_context + 0x1470);
    if (*(int *)(original_frame_context + 0x6c) != 0) {
      (**(code **)(iVar5 + -0x6114))(*(int *)(original_frame_context + 0x6c) + 0x170,0x11d1);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x39) = 0;
      *(undefined1 *)(*(int *)(original_frame_context + 0x6c) + 0x38) = 0;
      uVar3 = (**(code **)(iVar5 + -0x5868))(0);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x4c) = uVar3;
      uVar3 = (**(code **)(iVar5 + -0x5868))(0);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x50) = uVar3;
      uVar3 = (**(code **)(iVar5 + -0x5868))(0);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x54) = uVar3;
      uVar3 = (**(code **)(iVar5 + -0x5868))(0);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x58) = uVar3;
      uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x7c) = uVar3;
      uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x80) = uVar3;
      uVar3 = (**(code **)(iVar5 + -0x5868))(0x45);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x84) = uVar3;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9c) = uVar1;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45de);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x9e) = uVar1;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa0) = uVar1;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f5);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa2) = uVar1;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa4) = uVar1;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x45f9);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0xa6) = uVar1;
      *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x130) = 0x4ae;
      *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x13c) = 0x4ae;
      *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x148) = 0x4ae;
      *(undefined4 *)(*(int *)(original_frame_context + 0x6c) + 0x154) = 0x4ae;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x13a) = uVar1;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x146) = uVar1;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x6c) + 0x152) = uVar1;
      uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3215);
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
                 *(undefined4 *)(original_frame_context + 0x1324),original_frame_context + 0x1320);
      uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + 0x958))
                        (original_frame_context + 0x12b4);
      return uVar3;
    }
                    /* try { // try from 00570738 to 00570a4f has its CatchHandler @ 00570a74 */
    (**(code **)(iVar5 + -0x2400))
              (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
               *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xc9f);
                    /* WARNING: Subroutine does not return */
    (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
  }
                    /* try { // try from 00570114 to 0057043f has its CatchHandler @ 00570a74 */
  (**(code **)(iVar5 + -0x2400))
            (*(int *)(iVar5 + -0x7fdc) + 0x7b18,*(int *)(iVar5 + -0x7fdc) + 0x7b34,
             *(int *)(iVar5 + -0x7fdc) + 0x7cf8,0xc70);
                    /* WARNING: Subroutine does not return */
  (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
}

