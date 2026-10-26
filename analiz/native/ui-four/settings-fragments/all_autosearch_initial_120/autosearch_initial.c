
/* Analysis fragment only; external jumps/continuation are abstracted as exits. Not original
   standalone code. Original frame/GP context required. */

undefined4
Settings_fragment_autosearch_initial
          (uint boundary_a0,uint boundary_a1,uint boundary_a2,uint boundary_a3,
          byte *original_frame_context)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined **ppuVar6;
  
  ppuVar6 = &_gp;
  *(undefined4 *)(original_frame_context + 0x16b4) =
       *(undefined4 *)(original_frame_context + 0x16e4);
  if (*(int *)(original_frame_context + 0x16b4) == 0) {
    original_frame_context[0x16b8] = 0;
    original_frame_context[0x16b9] = 0;
    original_frame_context[0x16ba] = 0;
    original_frame_context[0x16bb] = 0;
  }
  else {
    uVar3 = __dynamic_cast(*(undefined4 *)(original_frame_context + 0x16b4),&MMainFrame::typeinfo,
                           &AutoSearchFrame::typeinfo,0);
    ppuVar6 = *(undefined ***)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x16b8) = uVar3;
  }
  *(undefined4 *)(original_frame_context + 0x150) = *(undefined4 *)(original_frame_context + 0x16b8)
  ;
  if (*(int *)(original_frame_context + 0x150) != 0) {
    *(undefined4 *)(original_frame_context + 0x168) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x18c);
    (*(code *)ppuVar6[-0xac0])(original_frame_context + 0x11e4,0,0,0x780);
    (**(code **)(**(int **)(original_frame_context + 0x168) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x168),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x72a8))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1d4));
    iVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1d9c))
                      (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1d8),2);
    original_frame_context[0x16e] = iVar2 != 0;
    iVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1d9c))
                      (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1dc),2);
    original_frame_context[0x16d] = iVar2 != 0;
    iVar2 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1d9c))
                      (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1e0),2);
    original_frame_context[0x16c] = iVar2 != 0;
    *(undefined4 *)(original_frame_context + 0x15c) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1d8);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x11e4,0x10f,0x1e,0x562);
    *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb0) =
         *(undefined4 *)(original_frame_context + 0x15c);
    if (original_frame_context[0x16d] == 0) {
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb4) =
           *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1e0);
    }
    else {
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb4) =
           *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1dc);
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
              (original_frame_context + 0x11d0,0x125);
                    /* try { // try from 0055bab0 to 0055bab7 has its CatchHandler @ 0055bcbc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x11bc,0x125);
                    /* try { // try from 0055bacc to 0055bad3 has its CatchHandler @ 0055bc80 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x11a8,0x125);
                    /* try { // try from 0055bae8 to 0055baef has its CatchHandler @ 0055bbb4 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x1194,0x125);
                    /* try { // try from 0055bb14 to 0055bb1b has its CatchHandler @ 0055bb58 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1a5c))
              (*(undefined4 *)(original_frame_context + 0x15c),original_frame_context + 0x11d0,
               original_frame_context + 0x11bc,original_frame_context + 0x11a8);
                    /* try { // try from 0055bb2c to 0055bb33 has its CatchHandler @ 0055bbb4 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x1194);
                    /* try { // try from 0055bb44 to 0055bb4b has its CatchHandler @ 0055bc80 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x11a8);
                    /* try { // try from 0055bba0 to 0055bba7 has its CatchHandler @ 0055bcbc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x11bc);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x11d0);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x1e4) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1e4),
               *(int *)(original_frame_context + 0x11e4) + 0x6e,
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x150) + 0x1e4) + 0x128) = 0x21;
    *(undefined4 *)(original_frame_context + 0x15c) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1dc);
    if (original_frame_context[0x16e] == 0) {
      (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0x1e,0x562);
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb0) =
           *(undefined4 *)(original_frame_context + 0x15c);
    }
    else {
      (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0x78,0x562);
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb0) =
           *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1d8);
    }
    if (original_frame_context[0x16c] == 0) {
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb4) =
           *(undefined4 *)(original_frame_context + 0x15c);
    }
    else {
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb4) =
           *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1e0);
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
              (original_frame_context + 0x1180,0x126);
                    /* try { // try from 0055bf54 to 0055bf5b has its CatchHandler @ 0055c168 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x116c,0x126);
                    /* try { // try from 0055bf70 to 0055bf77 has its CatchHandler @ 0055c12c */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x1158,0x126);
                    /* try { // try from 0055bf8c to 0055bf93 has its CatchHandler @ 0055c058 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x1144,0x126);
                    /* try { // try from 0055bfb8 to 0055bfbf has its CatchHandler @ 0055bffc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1a5c))
              (*(undefined4 *)(original_frame_context + 0x15c),original_frame_context + 0x1180,
               original_frame_context + 0x116c,original_frame_context + 0x1158);
                    /* try { // try from 0055bfd0 to 0055bfd7 has its CatchHandler @ 0055c058 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x1144);
                    /* try { // try from 0055bfe8 to 0055bfef has its CatchHandler @ 0055c12c */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x1158);
                    /* try { // try from 0055c044 to 0055c04b has its CatchHandler @ 0055c168 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x116c);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x1180);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x1e8) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1e8),
               *(int *)(original_frame_context + 0x11e4) + 0x6e,
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x150) + 0x1e8) + 0x128) = 0x21;
    *(undefined4 *)(original_frame_context + 0x15c) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1e0);
    if ((original_frame_context[0x16e] == 1) && (original_frame_context[0x16d] == 1)) {
      (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0xd2,0x562);
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb0) =
           *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1dc);
    }
    else if ((original_frame_context[0x16e] == 0) && (original_frame_context[0x16d] == 1)) {
      (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0x78,0x562);
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb0) =
           *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1dc);
    }
    else if ((original_frame_context[0x16e] != 0) && (original_frame_context[0x16d] != 1)) {
      (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x11e4,0x10f,0x78,0x562);
      *(undefined4 *)(*(int *)(original_frame_context + 0x15c) + 0xb0) =
           *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1d8);
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
              (original_frame_context + 0x1130,0x12a);
                    /* try { // try from 0055c48c to 0055c493 has its CatchHandler @ 0055c7dc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x111c,0x12a);
                    /* try { // try from 0055c4a8 to 0055c4af has its CatchHandler @ 0055c784 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x1108,0x12a);
                    /* try { // try from 0055c4c4 to 0055c4cb has its CatchHandler @ 0055c590 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x10f4,0x12a);
                    /* try { // try from 0055c4f0 to 0055c4f7 has its CatchHandler @ 0055c534 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1a5c))
              (*(undefined4 *)(original_frame_context + 0x15c),original_frame_context + 0x1130,
               original_frame_context + 0x111c,original_frame_context + 0x1108);
                    /* try { // try from 0055c508 to 0055c50f has its CatchHandler @ 0055c590 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x10f4);
                    /* try { // try from 0055c520 to 0055c527 has its CatchHandler @ 0055c784 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x1108);
                    /* try { // try from 0055c57c to 0055c583 has its CatchHandler @ 0055c7dc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x111c);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x1130);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x1ec) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1ec),
               *(int *)(original_frame_context + 0x11e4) + 0x6e,
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x150) + 0x1ec) + 0x128) = 0x21;
    *(undefined4 *)(original_frame_context + 0x168) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x19c);
    (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x11e4,0,0,0x780);
    (**(code **)(**(int **)(original_frame_context + 0x168) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x168),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    (**(code **)(**(int **)(original_frame_context + 0x168) + 0x3c))
              (*(undefined4 *)(original_frame_context + 0x168),
               *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x250));
    (**(code **)(**(int **)(original_frame_context + 0x168) + 0x3c))
              (*(undefined4 *)(original_frame_context + 0x168),
               *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 600));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1200,0x10f,0,0x562);
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0xbf8);
    *(undefined4 *)(original_frame_context + 0x16b0) = uVar3;
                    /* try { // try from 0055c770 to 0055c777 has its CatchHandler @ 0055c820 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x605c))
              (*(undefined4 *)(original_frame_context + 0x16b0),
               *(undefined4 *)(original_frame_context + 0x168),original_frame_context + 0x1200,0);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x14c) =
         *(undefined4 *)(original_frame_context + 0x16b0);
    if (*(int *)(original_frame_context + 0x14c) == 0) {
      (**(code **)(iVar2 + -0x2400))
                (*(int *)(iVar2 + -0x7fdc) + 0x7b18,*(int *)(iVar2 + -0x7fdc) + 0x7b34,
                 *(int *)(iVar2 + -0x7fdc) + 0x7cf8,0x44f);
                    /* WARNING: Subroutine does not return */
      (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
    }
    *(undefined1 *)(*(int *)(original_frame_context + 0x14c) + 0x39) = 0;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x14c) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x14c) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x14c) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x14c) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x14c) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x14c) + 0xa6) = uVar1;
    (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x14c) + 0xb8,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x14c) + 0xcc,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x14c) + 0xe0,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x14c) + 0xf4,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5b08))
              (*(undefined4 *)(original_frame_context + 0x14c),0);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2820))
              (*(undefined4 *)(original_frame_context + 0x14c),6);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x10e0,0x5cd);
                    /* try { // try from 0055ca3c to 0055ca43 has its CatchHandler @ 0055cc34 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x10cc,0x5cd);
                    /* try { // try from 0055ca58 to 0055ca5f has its CatchHandler @ 0055cbd4 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x10b8,0x5cd);
                    /* try { // try from 0055ca74 to 0055ca7b has its CatchHandler @ 0055cb40 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x10a4,0x5cd);
                    /* try { // try from 0055caa0 to 0055caa7 has its CatchHandler @ 0055cae4 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x77c8))
              (*(undefined4 *)(original_frame_context + 0x14c),original_frame_context + 0x10e0,
               original_frame_context + 0x10cc,original_frame_context + 0x10b8);
                    /* try { // try from 0055cab8 to 0055cabf has its CatchHandler @ 0055cb40 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x10a4);
                    /* try { // try from 0055cad0 to 0055cad7 has its CatchHandler @ 0055cbd4 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x10b8);
                    /* try { // try from 0055cb2c to 0055cb33 has its CatchHandler @ 0055cc34 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x10cc);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x10e0);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x1090,0x5cd);
                    /* try { // try from 0055cbc0 to 0055cbc7 has its CatchHandler @ 0055ce48 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x107c,0x5cd);
                    /* try { // try from 0055cc20 to 0055cc27 has its CatchHandler @ 0055cde8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x1068,0x5cd);
                    /* try { // try from 0055cc88 to 0055cc8f has its CatchHandler @ 0055cd54 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x1054,0x5cd);
                    /* try { // try from 0055ccb4 to 0055ccbb has its CatchHandler @ 0055ccf8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x447c))
              (*(undefined4 *)(original_frame_context + 0x14c),original_frame_context + 0x1090,
               original_frame_context + 0x107c,original_frame_context + 0x1068);
                    /* try { // try from 0055cccc to 0055ccd3 has its CatchHandler @ 0055cd54 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x1054);
                    /* try { // try from 0055cce4 to 0055cceb has its CatchHandler @ 0055cde8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x1068);
                    /* try { // try from 0055cd40 to 0055cd47 has its CatchHandler @ 0055ce48 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x107c);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x1090);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x1040,0x5cd);
                    /* try { // try from 0055cdd4 to 0055cddb has its CatchHandler @ 0055d05c */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x102c,0x5cd);
                    /* try { // try from 0055ce34 to 0055ce3b has its CatchHandler @ 0055cffc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x1018,0x5cd);
                    /* try { // try from 0055ce9c to 0055cea3 has its CatchHandler @ 0055cf68 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x1004,0x5cd);
                    /* try { // try from 0055cec8 to 0055cecf has its CatchHandler @ 0055cf0c */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x17d4))
              (*(undefined4 *)(original_frame_context + 0x14c),original_frame_context + 0x1040,
               original_frame_context + 0x102c,original_frame_context + 0x1018);
                    /* try { // try from 0055cee0 to 0055cee7 has its CatchHandler @ 0055cf68 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x1004);
                    /* try { // try from 0055cef8 to 0055ceff has its CatchHandler @ 0055cffc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x1018);
                    /* try { // try from 0055cf54 to 0055cf5b has its CatchHandler @ 0055d05c */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x102c);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
              (original_frame_context + 0x1040);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xff0,0x5cd);
                    /* try { // try from 0055cfe8 to 0055cfef has its CatchHandler @ 0055d2c0 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xfdc,0x5cd);
                    /* try { // try from 0055d048 to 0055d04f has its CatchHandler @ 0055d268 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xfc8,0x5cd);
                    /* try { // try from 0055d0b0 to 0055d0b7 has its CatchHandler @ 0055d17c */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xfb4,0x5cd);
                    /* try { // try from 0055d0dc to 0055d0e3 has its CatchHandler @ 0055d120 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4bb4))
              (*(undefined4 *)(original_frame_context + 0x14c),original_frame_context + 0xff0,
               original_frame_context + 0xfdc,original_frame_context + 0xfc8);
                    /* try { // try from 0055d0f4 to 0055d0fb has its CatchHandler @ 0055d17c */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xfb4)
    ;
                    /* try { // try from 0055d10c to 0055d113 has its CatchHandler @ 0055d268 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xfc8)
    ;
                    /* try { // try from 0055d168 to 0055d16f has its CatchHandler @ 0055d2c0 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xfdc)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xff0)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x11d4))
              (*(undefined4 *)(original_frame_context + 0x14c),2,1);
    (**(code **)(**(int **)(original_frame_context + 0x168) + 0x34))
              (*(undefined4 *)(original_frame_context + 0x168),
               *(undefined4 *)(original_frame_context + 0x14c));
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0xbf8);
    *(undefined4 *)(original_frame_context + 0x16ac) = uVar3;
                    /* try { // try from 0055d254 to 0055d25b has its CatchHandler @ 0055d304 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x605c))
              (*(undefined4 *)(original_frame_context + 0x16ac),
               *(undefined4 *)(original_frame_context + 0x168),original_frame_context + 0x1200,0);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x148) =
         *(undefined4 *)(original_frame_context + 0x16ac);
    if (*(int *)(original_frame_context + 0x148) == 0) {
      (**(code **)(iVar2 + -0x2400))
                (*(int *)(iVar2 + -0x7fdc) + 0x7b18,*(int *)(iVar2 + -0x7fdc) + 0x7b34,
                 *(int *)(iVar2 + -0x7fdc) + 0x7cf8,0x466);
                    /* WARNING: Subroutine does not return */
      (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
    }
    *(undefined1 *)(*(int *)(original_frame_context + 0x148) + 0x39) = 0;
    *(undefined1 *)(*(int *)(original_frame_context + 0x148) + 0x38) = 0;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x148) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x148) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x148) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x148) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x148) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x148) + 0xa6) = uVar1;
    (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x148) + 0xb8,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x148) + 0xcc,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x148) + 0xe0,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x148) + 0xf4,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5b08))
              (*(undefined4 *)(original_frame_context + 0x148),0);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2820))
              (*(undefined4 *)(original_frame_context + 0x148),6);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 4000,0x5cd);
                    /* try { // try from 0055d528 to 0055d52f has its CatchHandler @ 0055d720 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xf8c,0x5cd);
                    /* try { // try from 0055d544 to 0055d54b has its CatchHandler @ 0055d6c0 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xf78,0x5cd);
                    /* try { // try from 0055d560 to 0055d567 has its CatchHandler @ 0055d62c */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xf64,0x5cd);
                    /* try { // try from 0055d58c to 0055d593 has its CatchHandler @ 0055d5d0 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x77c8))
              (*(undefined4 *)(original_frame_context + 0x148),original_frame_context + 4000,
               original_frame_context + 0xf8c,original_frame_context + 0xf78);
                    /* try { // try from 0055d5a4 to 0055d5ab has its CatchHandler @ 0055d62c */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xf64)
    ;
                    /* try { // try from 0055d5bc to 0055d5c3 has its CatchHandler @ 0055d6c0 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xf78)
    ;
                    /* try { // try from 0055d618 to 0055d61f has its CatchHandler @ 0055d720 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xf8c)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 4000);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xf50,0x5cd);
                    /* try { // try from 0055d6ac to 0055d6b3 has its CatchHandler @ 0055d934 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xf3c,0x5cd);
                    /* try { // try from 0055d70c to 0055d713 has its CatchHandler @ 0055d8d4 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xf28,0x5cd);
                    /* try { // try from 0055d774 to 0055d77b has its CatchHandler @ 0055d840 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xf14,0x5cd);
                    /* try { // try from 0055d7a0 to 0055d7a7 has its CatchHandler @ 0055d7e4 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x447c))
              (*(undefined4 *)(original_frame_context + 0x148),original_frame_context + 0xf50,
               original_frame_context + 0xf3c,original_frame_context + 0xf28);
                    /* try { // try from 0055d7b8 to 0055d7bf has its CatchHandler @ 0055d840 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xf14)
    ;
                    /* try { // try from 0055d7d0 to 0055d7d7 has its CatchHandler @ 0055d8d4 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xf28)
    ;
                    /* try { // try from 0055d82c to 0055d833 has its CatchHandler @ 0055d934 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xf3c)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xf50)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xf00,0x5cd);
                    /* try { // try from 0055d8c0 to 0055d8c7 has its CatchHandler @ 0055db48 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xeec,0x5cd);
                    /* try { // try from 0055d920 to 0055d927 has its CatchHandler @ 0055dae8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xed8,0x5cd);
                    /* try { // try from 0055d988 to 0055d98f has its CatchHandler @ 0055da54 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xec4,0x5cd);
                    /* try { // try from 0055d9b4 to 0055d9bb has its CatchHandler @ 0055d9f8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x17d4))
              (*(undefined4 *)(original_frame_context + 0x148),original_frame_context + 0xf00,
               original_frame_context + 0xeec,original_frame_context + 0xed8);
                    /* try { // try from 0055d9cc to 0055d9d3 has its CatchHandler @ 0055da54 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xec4)
    ;
                    /* try { // try from 0055d9e4 to 0055d9eb has its CatchHandler @ 0055dae8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xed8)
    ;
                    /* try { // try from 0055da40 to 0055da47 has its CatchHandler @ 0055db48 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xeec)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xf00)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xeb0,0x5cd);
                    /* try { // try from 0055dad4 to 0055dadb has its CatchHandler @ 0055ddd8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xe9c,0x5cd);
                    /* try { // try from 0055db34 to 0055db3b has its CatchHandler @ 0055dd80 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xe88,0x5cd);
                    /* try { // try from 0055db9c to 0055dba3 has its CatchHandler @ 0055dc68 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xe74,0x5cd);
                    /* try { // try from 0055dbc8 to 0055dbcf has its CatchHandler @ 0055dc0c */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4bb4))
              (*(undefined4 *)(original_frame_context + 0x148),original_frame_context + 0xeb0,
               original_frame_context + 0xe9c,original_frame_context + 0xe88);
                    /* try { // try from 0055dbe0 to 0055dbe7 has its CatchHandler @ 0055dc68 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xe74)
    ;
                    /* try { // try from 0055dbf8 to 0055dbff has its CatchHandler @ 0055dd80 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xe88)
    ;
                    /* try { // try from 0055dc54 to 0055dc5b has its CatchHandler @ 0055ddd8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xe9c)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xeb0)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x11d4))
              (*(undefined4 *)(original_frame_context + 0x148),2,1);
    (**(code **)(**(int **)(original_frame_context + 0x168) + 0x34))
              (*(undefined4 *)(original_frame_context + 0x168),
               *(undefined4 *)(original_frame_context + 0x148));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1200,0,0,0x562);
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
    *(undefined4 *)(original_frame_context + 0x16a8) = uVar3;
                    /* try { // try from 0055dd6c to 0055dd73 has its CatchHandler @ 0055de1c */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
              (*(undefined4 *)(original_frame_context + 0x16a8),
               *(undefined4 *)(original_frame_context + 0x14c),original_frame_context + 0x1200,0);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x144) =
         *(undefined4 *)(original_frame_context + 0x16a8);
    if (*(int *)(original_frame_context + 0x144) == 0) {
      (**(code **)(iVar2 + -0x2400))
                (*(int *)(iVar2 + -0x7fdc) + 0x7b18,*(int *)(iVar2 + -0x7fdc) + 0x7b34,
                 *(int *)(iVar2 + -0x7fdc) + 0x7cf8,0x47f);
                    /* WARNING: Subroutine does not return */
      (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
    }
    *(undefined1 *)(*(int *)(original_frame_context + 0x144) + 0x3a) = 1;
    *(undefined1 *)(*(int *)(original_frame_context + 0x144) + 0x38) = 0;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x144) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x144) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x144) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x144) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x144) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x144) + 0xa6) = uVar1;
    (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x144) + 0xb8,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x144) + 0xcc,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x144) + 0xe0,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x144) + 0xf4,0x5cd);
    (**(code **)(**(int **)(original_frame_context + 0x14c) + 0x34))
              (*(undefined4 *)(original_frame_context + 0x14c),
               *(undefined4 *)(original_frame_context + 0x144));
    (**(code **)(**(int **)(original_frame_context + 0x144) + 0x34))
              (*(undefined4 *)(original_frame_context + 0x144),
               *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x250));
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
    *(undefined4 *)(original_frame_context + 0x16a4) = uVar3;
                    /* try { // try from 0055e07c to 0055e083 has its CatchHandler @ 0055e0a4 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
              (*(undefined4 *)(original_frame_context + 0x16a4),
               *(undefined4 *)(original_frame_context + 0x148),original_frame_context + 0x1200,0);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x140) =
         *(undefined4 *)(original_frame_context + 0x16a4);
    if (*(int *)(original_frame_context + 0x140) == 0) {
      (**(code **)(iVar2 + -0x2400))
                (*(int *)(iVar2 + -0x7fdc) + 0x7b18,*(int *)(iVar2 + -0x7fdc) + 0x7b34,
                 *(int *)(iVar2 + -0x7fdc) + 0x7cf8,0x490);
                    /* WARNING: Subroutine does not return */
      (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
    }
    *(undefined1 *)(*(int *)(original_frame_context + 0x140) + 0x3a) = 1;
    *(undefined1 *)(*(int *)(original_frame_context + 0x140) + 0x38) = 0;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x140) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x140) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x140) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x140) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x140) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x140) + 0xa6) = uVar1;
    (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x140) + 0xb8,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x140) + 0xcc,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x140) + 0xe0,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x140) + 0xf4,0x5cd);
    (**(code **)(**(int **)(original_frame_context + 0x148) + 0x34))
              (*(undefined4 *)(original_frame_context + 0x148),
               *(undefined4 *)(original_frame_context + 0x140));
    iVar2 = *(int *)(*(int *)(original_frame_context + 0x150) + 0x250);
    uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x45f7);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(iVar2 + 0x9c) = uVar1;
    iVar2 = *(int *)(*(int *)(original_frame_context + 0x150) + 0x250);
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x13);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(iVar2 + 0x4c) = uVar3;
    *(undefined1 *)(*(int *)(*(int *)(original_frame_context + 0x150) + 0x250) + 0x39) = 1;
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x150) + 0x250) + 0x128) = 0x21;
    iVar2 = *(int *)(*(int *)(original_frame_context + 0x150) + 0x250);
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3214);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(iVar2 + 0x13a) = uVar1;
    iVar2 = *(int *)(*(int *)(original_frame_context + 0x150) + 0x250);
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3214);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(iVar2 + 0x146) = uVar1;
    iVar2 = *(int *)(*(int *)(original_frame_context + 0x150) + 0x250);
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3214);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(iVar2 + 0x152) = uVar1;
    iVar2 = *(int *)(*(int *)(original_frame_context + 0x150) + 0x250);
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3214);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(iVar2 + 0x15e) = uVar1;
    (**(code **)(iVar5 + -0x2b00))(original_frame_context + 0x1200,0,0,0x562);
    uVar3 = (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x254) + 0x44))
                      (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x254));
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x13c) = uVar3;
    original_frame_context[0x128] = 0;
    original_frame_context[0x129] = 0;
    original_frame_context[0x12a] = 0;
    original_frame_context[299] = 0;
    while (*(uint *)(original_frame_context + 0x128) < *(uint *)(original_frame_context + 0x13c)) {
      uVar3 = (**(code **)(iVar2 + -0x2a80))(0x2b4);
      *(undefined4 *)(original_frame_context + 0x16a0) = uVar3;
                    /* try { // try from 0055e430 to 0055e437 has its CatchHandler @ 0055e458 */
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0xb04))
                (*(undefined4 *)(original_frame_context + 0x16a0),
                 *(undefined4 *)(original_frame_context + 0x148),original_frame_context + 0x1200,0);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(original_frame_context + 0x124) =
           *(undefined4 *)(original_frame_context + 0x16a0);
      if (*(int *)(original_frame_context + 0x124) == 0) {
        (**(code **)(iVar2 + -0x2400))
                  (*(int *)(iVar2 + -0x7fdc) + 0x7b18,*(int *)(iVar2 + -0x7fdc) + 0x7b34,
                   *(int *)(iVar2 + -0x7fdc) + 0x7cf8,0x4ad);
                    /* WARNING: Subroutine does not return */
        (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
      }
      (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x124) + 0x260,0x242);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0x124) + 0x274,0x242);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0x124) + 0x288,0x242);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0x124) + 0x29c,0x242);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(undefined1 *)(*(int *)(original_frame_context + 0x124) + 0x39) = 0;
      *(undefined1 *)(*(int *)(original_frame_context + 0x124) + 0x38) = 0;
      uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x124) + 0x9c) = uVar1;
      uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x124) + 0x9e) = uVar1;
      uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x124) + 0xa0) = uVar1;
      uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x124) + 0xa2) = uVar1;
      uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x124) + 0xa4) = uVar1;
      uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x124) + 0xa6) = uVar1;
      (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x124) + 0xb8,0x5cd);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0x124) + 0xcc,0x5cd);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0x124) + 0xe0,0x5cd);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0x124) + 0xf4,0x5cd);
      (**(code **)(**(int **)(original_frame_context + 0x148) + 0x34))
                (*(undefined4 *)(original_frame_context + 0x148),
                 *(undefined4 *)(original_frame_context + 0x124));
      uVar3 = (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x254) + 0x40))
                        (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x254),0);
      *(undefined4 *)(original_frame_context + 0x120) = uVar3;
      uVar4 = *(undefined4 *)(original_frame_context + 0x124);
      uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1d9c))
                        (*(undefined4 *)(original_frame_context + 0x120),2);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x11d4))(uVar4,2,uVar3);
      uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x7414))
                        (*(undefined4 *)(original_frame_context + 0x120));
      *(undefined4 *)(original_frame_context + 0x11c) = uVar3;
      (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x254) + 0x3c))
                (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x254),
                 *(undefined4 *)(original_frame_context + 0x120));
      (**(code **)(**(int **)(original_frame_context + 0x14c) + 0x34))
                (*(undefined4 *)(original_frame_context + 0x14c),
                 *(undefined4 *)(original_frame_context + 0x120));
      uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x13);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))
                (*(undefined4 *)(original_frame_context + 0x120),1,uVar3,0xf);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(int *)(original_frame_context + 0x16c4) = *(int *)(original_frame_context + 0x11c) + -0x50;
      if (*(uint *)(original_frame_context + 0x16c4) < 5) {
                    /* WARNING: Switch is manually overridden */
        switch(*(int *)(*(int *)(original_frame_context + 0x16c4) * 4 +
                       *(int *)(iVar2 + -0x7fdc) + 0x7c80) + iVar2 & 0xfffffffe) {
        case 0x55e834:
          (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x124) + 0x260,0x127);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x124) + 0x274,0x127);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x124) + 0x288,0x127);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x124) + 0x29c,0x127);
          iVar2 = *(int *)(original_frame_context + 0x20);
          break;
        case 0x55e8bc:
          (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x124) + 0x260,0x129);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x124) + 0x274,0x129);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x124) + 0x288,0x129);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x124) + 0x29c,0x129);
          iVar2 = *(int *)(original_frame_context + 0x20);
          break;
        case 0x55e944:
          (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x124) + 0x260,0x124);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x124) + 0x274,0x124);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x124) + 0x288,0x124);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x124) + 0x29c,0x124);
          iVar2 = *(int *)(original_frame_context + 0x20);
          break;
        case 0x55e9cc:
          (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x124) + 0x260,0x128);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x124) + 0x274,0x128);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x124) + 0x288,0x128);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x124) + 0x29c,0x128);
          iVar2 = *(int *)(original_frame_context + 0x20);
          break;
        case 0x55ea54:
          (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x124) + 0x260,299);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x124) + 0x274,299);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x124) + 0x288,299);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x124) + 0x29c,299);
          iVar2 = *(int *)(original_frame_context + 0x20);
        }
      }
      *(int *)(original_frame_context + 0x128) = *(int *)(original_frame_context + 0x128) + 1;
    }
    (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x1200,0,0,0x562);
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
    *(undefined4 *)(original_frame_context + 0x169c) = uVar3;
                    /* try { // try from 0055eb58 to 0055eb5f has its CatchHandler @ 0055eb80 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
              (*(undefined4 *)(original_frame_context + 0x169c),
               *(undefined4 *)(original_frame_context + 0x14c),original_frame_context + 0x1200,0);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x138) =
         *(undefined4 *)(original_frame_context + 0x169c);
    if (*(int *)(original_frame_context + 0x138) == 0) {
      (**(code **)(iVar2 + -0x2400))
                (*(int *)(iVar2 + -0x7fdc) + 0x7b18,*(int *)(iVar2 + -0x7fdc) + 0x7b34,
                 *(int *)(iVar2 + -0x7fdc) + 0x7cf8,0x4ed);
                    /* WARNING: Subroutine does not return */
      (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
    }
    *(undefined1 *)(*(int *)(original_frame_context + 0x138) + 0x3a) = 1;
    *(undefined1 *)(*(int *)(original_frame_context + 0x138) + 0x38) = 0;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x138) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x138) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x138) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x138) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x138) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x138) + 0xa6) = uVar1;
    (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x138) + 0xb8,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x138) + 0xcc,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x138) + 0xe0,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x138) + 0xf4,0x5cd);
    (**(code **)(**(int **)(original_frame_context + 0x14c) + 0x34))
              (*(undefined4 *)(original_frame_context + 0x14c),
               *(undefined4 *)(original_frame_context + 0x138));
    (**(code **)(**(int **)(original_frame_context + 0x138) + 0x34))
              (*(undefined4 *)(original_frame_context + 0x138),
               *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 600));
    iVar2 = *(int *)(*(int *)(original_frame_context + 0x150) + 600);
    uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x45f7);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(iVar2 + 0x9c) = uVar1;
    iVar2 = *(int *)(*(int *)(original_frame_context + 0x150) + 600);
    uVar3 = (**(code **)(iVar5 + -0x5868))(0x13);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(iVar2 + 0x4c) = uVar3;
    *(undefined1 *)(*(int *)(*(int *)(original_frame_context + 0x150) + 600) + 0x39) = 1;
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x150) + 600) + 0x128) = 0x21;
    iVar2 = *(int *)(*(int *)(original_frame_context + 0x150) + 600);
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3214);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(iVar2 + 0x13a) = uVar1;
    iVar2 = *(int *)(*(int *)(original_frame_context + 0x150) + 600);
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3214);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(iVar2 + 0x146) = uVar1;
    iVar2 = *(int *)(*(int *)(original_frame_context + 0x150) + 600);
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3214);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(iVar2 + 0x152) = uVar1;
    iVar2 = *(int *)(*(int *)(original_frame_context + 0x150) + 600);
    uVar1 = (**(code **)(iVar5 + -0x38a4))(0x3214);
    iVar5 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(iVar2 + 0x15e) = uVar1;
    uVar3 = (**(code **)(iVar5 + -0x2a80))(0x264);
    *(undefined4 *)(original_frame_context + 0x1698) = uVar3;
                    /* try { // try from 0055eed4 to 0055eedb has its CatchHandler @ 0055eefc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
              (*(undefined4 *)(original_frame_context + 0x1698),
               *(undefined4 *)(original_frame_context + 0x148),original_frame_context + 0x1200,0);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x140) =
         *(undefined4 *)(original_frame_context + 0x1698);
    if (*(int *)(original_frame_context + 0x140) == 0) {
      (**(code **)(iVar2 + -0x2400))
                (*(int *)(iVar2 + -0x7fdc) + 0x7b18,*(int *)(iVar2 + -0x7fdc) + 0x7b34,
                 *(int *)(iVar2 + -0x7fdc) + 0x7cf8,0x507);
                    /* WARNING: Subroutine does not return */
      (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
    }
    *(undefined1 *)(*(int *)(original_frame_context + 0x140) + 0x3a) = 1;
    *(undefined1 *)(*(int *)(original_frame_context + 0x140) + 0x38) = 0;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x140) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x140) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x140) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x140) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x140) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x140) + 0xa6) = uVar1;
    (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x140) + 0xb8,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x140) + 0xcc,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x140) + 0xe0,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x140) + 0xf4,0x5cd);
    (**(code **)(**(int **)(original_frame_context + 0x148) + 0x34))
              (*(undefined4 *)(original_frame_context + 0x148),
               *(undefined4 *)(original_frame_context + 0x140));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1200,0,0,0x562);
    uVar3 = (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x25c) + 0x44))
                      (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x25c));
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x13c) = uVar3;
    original_frame_context[0x118] = 0;
    original_frame_context[0x119] = 0;
    original_frame_context[0x11a] = 0;
    original_frame_context[0x11b] = 0;
    while (*(uint *)(original_frame_context + 0x118) < *(uint *)(original_frame_context + 0x13c)) {
      uVar3 = (**(code **)(iVar2 + -0x2a80))(0x2b4);
      *(undefined4 *)(original_frame_context + 0x1694) = uVar3;
                    /* try { // try from 0055f194 to 0055f19b has its CatchHandler @ 0055f1bc */
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0xb04))
                (*(undefined4 *)(original_frame_context + 0x1694),
                 *(undefined4 *)(original_frame_context + 0x148),original_frame_context + 0x1200,0);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(original_frame_context + 0x114) =
           *(undefined4 *)(original_frame_context + 0x1694);
      if (*(int *)(original_frame_context + 0x114) == 0) {
        (**(code **)(iVar2 + -0x2400))
                  (*(int *)(iVar2 + -0x7fdc) + 0x7b18,*(int *)(iVar2 + -0x7fdc) + 0x7b34,
                   *(int *)(iVar2 + -0x7fdc) + 0x7cf8,0x51b);
                    /* WARNING: Subroutine does not return */
        (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
      }
      (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x114) + 0x260,0x242);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0x114) + 0x274,0x242);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0x114) + 0x288,0x242);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0x114) + 0x29c,0x242);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(undefined1 *)(*(int *)(original_frame_context + 0x114) + 0x39) = 0;
      *(undefined1 *)(*(int *)(original_frame_context + 0x114) + 0x38) = 0;
      uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x114) + 0x9c) = uVar1;
      uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x114) + 0x9e) = uVar1;
      uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x114) + 0xa0) = uVar1;
      uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x114) + 0xa2) = uVar1;
      uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x114) + 0xa4) = uVar1;
      uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0x114) + 0xa6) = uVar1;
      (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x114) + 0xb8,0x5cd);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0x114) + 0xcc,0x5cd);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0x114) + 0xe0,0x5cd);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0x114) + 0xf4,0x5cd);
      (**(code **)(**(int **)(original_frame_context + 0x148) + 0x34))
                (*(undefined4 *)(original_frame_context + 0x148),
                 *(undefined4 *)(original_frame_context + 0x114));
      uVar3 = (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x25c) + 0x40))
                        (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x25c),0);
      *(undefined4 *)(original_frame_context + 0x110) = uVar3;
      uVar4 = *(undefined4 *)(original_frame_context + 0x114);
      uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1d9c))
                        (*(undefined4 *)(original_frame_context + 0x110),2);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x11d4))(uVar4,2,uVar3);
      uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x7414))
                        (*(undefined4 *)(original_frame_context + 0x110));
      *(undefined4 *)(original_frame_context + 0x10c) = uVar3;
      (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x25c) + 0x3c))
                (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x25c),
                 *(undefined4 *)(original_frame_context + 0x110));
      (**(code **)(**(int **)(original_frame_context + 0x14c) + 0x34))
                (*(undefined4 *)(original_frame_context + 0x14c),
                 *(undefined4 *)(original_frame_context + 0x110));
      uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x13);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))
                (*(undefined4 *)(original_frame_context + 0x110),1,uVar3,0xf);
      iVar2 = *(int *)(original_frame_context + 0x20);
      *(int *)(original_frame_context + 0x16c8) = *(int *)(original_frame_context + 0x10c) + -0x50;
      if (*(uint *)(original_frame_context + 0x16c8) < 5) {
                    /* WARNING: Switch is manually overridden */
        switch(*(int *)(*(int *)(original_frame_context + 0x16c8) * 4 +
                       *(int *)(iVar2 + -0x7fdc) + 0x7c94) + iVar2 & 0xfffffffe) {
        case 0x55f598:
          (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x114) + 0x260,0x127);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x114) + 0x274,0x127);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x114) + 0x288,0x127);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x114) + 0x29c,0x127);
          iVar2 = *(int *)(original_frame_context + 0x20);
          break;
        case 0x55f620:
          (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x114) + 0x260,0x129);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x114) + 0x274,0x129);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x114) + 0x288,0x129);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x114) + 0x29c,0x129);
          iVar2 = *(int *)(original_frame_context + 0x20);
          break;
        case 0x55f6a8:
          (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x114) + 0x260,0x124);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x114) + 0x274,0x124);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x114) + 0x288,0x124);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x114) + 0x29c,0x124);
          iVar2 = *(int *)(original_frame_context + 0x20);
          break;
        case 0x55f730:
          (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x114) + 0x260,0x128);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x114) + 0x274,0x128);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x114) + 0x288,0x128);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x114) + 0x29c,0x128);
          iVar2 = *(int *)(original_frame_context + 0x20);
          break;
        case 0x55f7b8:
          (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x114) + 0x260,299);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x114) + 0x274,299);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x114) + 0x288,299);
          (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                    (*(int *)(original_frame_context + 0x114) + 0x29c,299);
          iVar2 = *(int *)(original_frame_context + 0x20);
        }
      }
      *(int *)(original_frame_context + 0x118) = *(int *)(original_frame_context + 0x118) + 1;
    }
    if (*(int *)(*(int *)(original_frame_context + 0x150) + 0x3c) ==
        *(int *)(*(int *)(original_frame_context + 0x150) + 0x180)) {
      (**(code **)(iVar2 + -0x36a0))
                (*(undefined4 *)(original_frame_context + 0x150),
                 *(undefined4 *)(original_frame_context + 0x14c));
      iVar2 = *(int *)(original_frame_context + 0x20);
    }
    *(undefined4 *)(original_frame_context + 0x168) =
         *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 400);
    (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x11e4,0,0,0x780);
    (**(code **)(**(int **)(original_frame_context + 0x168) + 0x24))
              (*(undefined4 *)(original_frame_context + 0x168),
               *(undefined4 *)(original_frame_context + 0x11e4),
               *(undefined4 *)(original_frame_context + 0x11e8),original_frame_context + 0x11e4);
    (**(code **)(**(int **)(original_frame_context + 0x168) + 0x3c))
              (*(undefined4 *)(original_frame_context + 0x168),
               *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1f0));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1200,0x10f,0x1e,0x562);
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0xbf8);
    *(undefined4 *)(original_frame_context + 0x1690) = uVar3;
                    /* try { // try from 0055f994 to 0055f99b has its CatchHandler @ 0055f9bc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x605c))
              (*(undefined4 *)(original_frame_context + 0x1690),
               *(undefined4 *)(original_frame_context + 0x168),original_frame_context + 0x1200,0);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x134) =
         *(undefined4 *)(original_frame_context + 0x1690);
    if (*(int *)(original_frame_context + 0x134) == 0) {
      (**(code **)(iVar2 + -0x2400))
                (*(int *)(iVar2 + -0x7fdc) + 0x7b18,*(int *)(iVar2 + -0x7fdc) + 0x7b34,
                 *(int *)(iVar2 + -0x7fdc) + 0x7cf8,0x564);
                    /* WARNING: Subroutine does not return */
      (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
    }
    *(undefined1 *)(*(int *)(original_frame_context + 0x134) + 0x39) = 0;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x134) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x134) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x134) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x134) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x134) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45dd);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x134) + 0xa6) = uVar1;
    (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x134) + 0xb8,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x134) + 0xcc,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x134) + 0xe0,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x134) + 0xf4,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5b08))
              (*(undefined4 *)(original_frame_context + 0x134),0);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2820))
              (*(undefined4 *)(original_frame_context + 0x134),6);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xe60,0x5cd);
                    /* try { // try from 0055fbd8 to 0055fbdf has its CatchHandler @ 0055fdd0 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xe4c,0x5cd);
                    /* try { // try from 0055fbf4 to 0055fbfb has its CatchHandler @ 0055fd70 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xe38,0x5cd);
                    /* try { // try from 0055fc10 to 0055fc17 has its CatchHandler @ 0055fcdc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xe24,0x5cd);
                    /* try { // try from 0055fc3c to 0055fc43 has its CatchHandler @ 0055fc80 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x77c8))
              (*(undefined4 *)(original_frame_context + 0x134),original_frame_context + 0xe60,
               original_frame_context + 0xe4c,original_frame_context + 0xe38);
                    /* try { // try from 0055fc54 to 0055fc5b has its CatchHandler @ 0055fcdc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xe24)
    ;
                    /* try { // try from 0055fc6c to 0055fc73 has its CatchHandler @ 0055fd70 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xe38)
    ;
                    /* try { // try from 0055fcc8 to 0055fccf has its CatchHandler @ 0055fdd0 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xe4c)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xe60)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xe10,0x5cd);
                    /* try { // try from 0055fd5c to 0055fd63 has its CatchHandler @ 0055ffe4 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xdfc,0x5cd);
                    /* try { // try from 0055fdbc to 0055fdc3 has its CatchHandler @ 0055ff84 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xde8,0x5cd);
                    /* try { // try from 0055fe24 to 0055fe2b has its CatchHandler @ 0055fef0 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xdd4,0x5cd);
                    /* try { // try from 0055fe50 to 0055fe57 has its CatchHandler @ 0055fe94 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x447c))
              (*(undefined4 *)(original_frame_context + 0x134),original_frame_context + 0xe10,
               original_frame_context + 0xdfc,original_frame_context + 0xde8);
                    /* try { // try from 0055fe68 to 0055fe6f has its CatchHandler @ 0055fef0 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xdd4)
    ;
                    /* try { // try from 0055fe80 to 0055fe87 has its CatchHandler @ 0055ff84 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xde8)
    ;
                    /* try { // try from 0055fedc to 0055fee3 has its CatchHandler @ 0055ffe4 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xdfc)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xe10)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xdc0,0x5cd);
                    /* try { // try from 0055ff70 to 0055ff77 has its CatchHandler @ 005601f8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xdac,0x5cd);
                    /* try { // try from 0055ffd0 to 0055ffd7 has its CatchHandler @ 00560198 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xd98,0x5cd);
                    /* try { // try from 00560038 to 0056003f has its CatchHandler @ 00560104 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xd84,0x5cd);
                    /* try { // try from 00560064 to 0056006b has its CatchHandler @ 005600a8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x17d4))
              (*(undefined4 *)(original_frame_context + 0x134),original_frame_context + 0xdc0,
               original_frame_context + 0xdac,original_frame_context + 0xd98);
                    /* try { // try from 0056007c to 00560083 has its CatchHandler @ 00560104 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xd84)
    ;
                    /* try { // try from 00560094 to 0056009b has its CatchHandler @ 00560198 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xd98)
    ;
                    /* try { // try from 005600f0 to 005600f7 has its CatchHandler @ 005601f8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xdac)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xdc0)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xd70,0x5cd);
                    /* try { // try from 00560184 to 0056018b has its CatchHandler @ 00560488 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xd5c,0x5cd);
                    /* try { // try from 005601e4 to 005601eb has its CatchHandler @ 00560430 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xd48,0x5cd);
                    /* try { // try from 0056024c to 00560253 has its CatchHandler @ 00560318 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xd34,0x5cd);
                    /* try { // try from 00560278 to 0056027f has its CatchHandler @ 005602bc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4bb4))
              (*(undefined4 *)(original_frame_context + 0x134),original_frame_context + 0xd70,
               original_frame_context + 0xd5c,original_frame_context + 0xd48);
                    /* try { // try from 00560290 to 00560297 has its CatchHandler @ 00560318 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xd34)
    ;
                    /* try { // try from 005602a8 to 005602af has its CatchHandler @ 00560430 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xd48)
    ;
                    /* try { // try from 00560304 to 0056030b has its CatchHandler @ 00560488 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xd5c)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xd70)
    ;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x11d4))
              (*(undefined4 *)(original_frame_context + 0x134),2,1);
    (**(code **)(**(int **)(original_frame_context + 0x168) + 0x34))
              (*(undefined4 *)(original_frame_context + 0x168),
               *(undefined4 *)(original_frame_context + 0x134));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1200,0,0,0x562);
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
    *(undefined4 *)(original_frame_context + 0x168c) = uVar3;
                    /* try { // try from 0056041c to 00560423 has its CatchHandler @ 005604cc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
              (*(undefined4 *)(original_frame_context + 0x168c),
               *(undefined4 *)(original_frame_context + 0x134),original_frame_context + 0x1200,0);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0x130) =
         *(undefined4 *)(original_frame_context + 0x168c);
    if (*(int *)(original_frame_context + 0x130) == 0) {
      (**(code **)(iVar2 + -0x2400))
                (*(int *)(iVar2 + -0x7fdc) + 0x7b18,*(int *)(iVar2 + -0x7fdc) + 0x7b34,
                 *(int *)(iVar2 + -0x7fdc) + 0x7cf8,0x57b);
                    /* WARNING: Subroutine does not return */
      (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
    }
    *(undefined1 *)(*(int *)(original_frame_context + 0x130) + 0x3a) = 1;
    *(undefined1 *)(*(int *)(original_frame_context + 0x130) + 0x38) = 0;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x130) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x130) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x130) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x130) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x130) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0x130) + 0xa6) = uVar1;
    (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 0x130) + 0xb8,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x130) + 0xcc,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x130) + 0xe0,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 0x130) + 0xf4,0x5cd);
    (**(code **)(**(int **)(original_frame_context + 0x134) + 0x34))
              (*(undefined4 *)(original_frame_context + 0x134),
               *(undefined4 *)(original_frame_context + 0x130));
    (**(code **)(**(int **)(original_frame_context + 0x130) + 0x34))
              (*(undefined4 *)(original_frame_context + 0x130),
               *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x1f0));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1200,0x10f,0x1e,0x562);
    uVar3 = (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 500) + 0x44))
                      (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 500));
    *(undefined4 *)(original_frame_context + 0x13c) = uVar3;
    original_frame_context[0x108] = 0;
    original_frame_context[0x109] = 0;
    original_frame_context[0x10a] = 0;
    original_frame_context[0x10b] = 0;
    while (*(uint *)(original_frame_context + 0x108) < *(uint *)(original_frame_context + 0x13c)) {
      uVar3 = (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 500) + 0x40))
                        (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 500),0);
      *(undefined4 *)(original_frame_context + 0x104) = uVar3;
      (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 500) + 0x3c))
                (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 500),
                 *(undefined4 *)(original_frame_context + 0x104));
      (**(code **)(**(int **)(original_frame_context + 0x134) + 0x34))
                (*(undefined4 *)(original_frame_context + 0x134),
                 *(undefined4 *)(original_frame_context + 0x104));
      uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x13);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))
                (*(undefined4 *)(original_frame_context + 0x104),1,uVar3,0xf);
      *(int *)(original_frame_context + 0x108) = *(int *)(original_frame_context + 0x108) + 1;
    }
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x194) + 0x3c))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x194),
               *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x200));
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x194) + 0x3c))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x194),
               *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x204));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1200,0x10f,0x1c,0x545);
    uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2a80))(0x264);
    *(undefined4 *)(original_frame_context + 0x1688) = uVar3;
                    /* try { // try from 00560938 to 0056093f has its CatchHandler @ 00560960 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5584))
              (*(undefined4 *)(original_frame_context + 0x1688),
               *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x194),
               original_frame_context + 0x1200,0);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 300) = *(undefined4 *)(original_frame_context + 0x1688)
    ;
    if (*(int *)(original_frame_context + 300) == 0) {
      (**(code **)(iVar2 + -0x2400))
                (*(int *)(iVar2 + -0x7fdc) + 0x7b18,*(int *)(iVar2 + -0x7fdc) + 0x7b34,
                 *(int *)(iVar2 + -0x7fdc) + 0x7cf8,0x59a);
                    /* WARNING: Subroutine does not return */
      (**(code **)(*(int *)(original_frame_context + 0x20) + 0x3b0))();
    }
    *(undefined1 *)(*(int *)(original_frame_context + 300) + 0x3a) = 1;
    *(undefined1 *)(*(int *)(original_frame_context + 300) + 0x38) = 0;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 300) + 0x9c) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 300) + 0x9e) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 300) + 0xa0) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f5);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 300) + 0xa2) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 300) + 0xa4) = uVar1;
    uVar1 = (**(code **)(iVar2 + -0x38a4))(0x45f9);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 300) + 0xa6) = uVar1;
    (**(code **)(iVar2 + -0x910))(*(int *)(original_frame_context + 300) + 0xb8,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 300) + 0xcc,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 300) + 0xe0,0x5cd);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
              (*(int *)(original_frame_context + 300) + 0xf4,0x5cd);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x194) + 0x34))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x194),
               *(undefined4 *)(original_frame_context + 300));
    (**(code **)(**(int **)(original_frame_context + 300) + 0x34))
              (*(undefined4 *)(original_frame_context + 300),
               *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x200));
    (**(code **)(**(int **)(original_frame_context + 300) + 0x34))
              (*(undefined4 *)(original_frame_context + 300),
               *(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x204));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1200,0x429,0,0x11e);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x200) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x200),
               *(undefined4 *)(original_frame_context + 0x1200),
               *(undefined4 *)(original_frame_context + 0x1204),original_frame_context + 0x1200);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x230) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x230),0,0,
               original_frame_context + 0x1200);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1200,0,0,0x91);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x228) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x228),
               *(undefined4 *)(original_frame_context + 0x1200),
               *(undefined4 *)(original_frame_context + 0x1204),original_frame_context + 0x1200);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x150) + 0x228) + 0x128) = 0x24;
    (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x1200,0x91,0,0x23);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x22c) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x22c),
               *(undefined4 *)(original_frame_context + 0x1200),
               *(undefined4 *)(original_frame_context + 0x1204),original_frame_context + 0x1200);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x150) + 0x22c) + 0x128) = 0x24;
    (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x1200,0x30d,0,0x11e);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x204) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x204),
               *(undefined4 *)(original_frame_context + 0x1200),
               *(undefined4 *)(original_frame_context + 0x1204),original_frame_context + 0x1200);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x23c) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x23c),0,0,
               original_frame_context + 0x1200);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2b00))
              (original_frame_context + 0x1200,0,0,0x91);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x234) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x234),
               *(undefined4 *)(original_frame_context + 0x1200),
               *(undefined4 *)(original_frame_context + 0x1204),original_frame_context + 0x1200);
    iVar2 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x150) + 0x234) + 0x128) = 0x24;
    (**(code **)(iVar2 + -0x2b00))(original_frame_context + 0x1200,0x91,0,0x23);
    (**(code **)(**(int **)(*(int *)(original_frame_context + 0x150) + 0x238) + 0x24))
              (*(undefined4 *)(*(int *)(original_frame_context + 0x150) + 0x238),
               *(undefined4 *)(original_frame_context + 0x1200),
               *(undefined4 *)(original_frame_context + 0x1204),original_frame_context + 0x1200);
    ppuVar6 = *(undefined ***)(original_frame_context + 0x20);
    *(undefined4 *)(*(int *)(*(int *)(original_frame_context + 0x150) + 0x238) + 0x128) = 0x24;
  }
  *(undefined4 *)(original_frame_context + 0x1680) =
       *(undefined4 *)(original_frame_context + 0x16e4);
  if (*(int *)(original_frame_context + 0x1680) == 0) {
    original_frame_context[0x1684] = 0;
    original_frame_context[0x1685] = 0;
    original_frame_context[0x1686] = 0;
    original_frame_context[0x1687] = 0;
    return *(undefined4 *)(original_frame_context + 0x16e4);
  }
  uVar3 = (*(code *)ppuVar6[-0x1663])
                    (*(undefined4 *)(original_frame_context + 0x1680),ppuVar6[-0x1511],
                     ppuVar6[-0x1d08],0);
  return uVar3;
}

