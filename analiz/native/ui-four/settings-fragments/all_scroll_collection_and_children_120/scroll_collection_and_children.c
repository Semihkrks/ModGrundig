
/* Analysis fragment only; external jumps/continuation are abstracted as exits. Not original
   standalone code. Original frame/GP context required. */

undefined4
Settings_fragment_scroll_collection_and_children
          (uint boundary_a0,uint boundary_a1,uint boundary_a2,uint boundary_a3,
          byte *original_frame_context)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  std::vector<ScrollListContainer*,std::allocator<ScrollListContainer*>>::vector
            ((vector<ScrollListContainer*,std::allocator<ScrollListContainer*>> *)
             (original_frame_context + 0x124c));
                    /* try { // try from 00566474 to 00566acb has its CatchHandler @ 005792b8 */
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5260))
            (*(undefined4 *)(original_frame_context + 0x16e0),
             *(undefined4 *)(*(int *)(original_frame_context + 0x16e4) + 0x38),
             original_frame_context + 0x124c,original_frame_context + 0x11f4);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x1194))(original_frame_context + 0x1258);
  (**(code **)(*(int *)(original_frame_context + 0x20) + -0x6f50))
            (original_frame_context + 0x13c0,original_frame_context + 0x124c);
  iVar6 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x1258) =
       *(undefined4 *)(original_frame_context + 0x13c0);
  do {
    (**(code **)(iVar6 + -0x2774))(original_frame_context + 0xaf4,original_frame_context + 0x124c);
    iVar6 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x6ca8))
                      (original_frame_context + 0x1258,original_frame_context + 0xaf4);
    iVar7 = *(int *)(original_frame_context + 0x20);
    if (iVar6 == 0) {
      *(undefined4 *)(original_frame_context + 0x1518) =
           *(undefined4 *)(original_frame_context + 0x16e4);
      if (*(int *)(original_frame_context + 0x1518) != 0) {
        uVar5 = (**(code **)(iVar7 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x1518),
                           *(undefined4 *)(iVar7 + -0x5444),*(undefined4 *)(iVar7 + -0x38e0),0);
        return uVar5;
      }
      original_frame_context[0x151c] = 0;
      original_frame_context[0x151d] = 0;
      original_frame_context[0x151e] = 0;
      original_frame_context[0x151f] = 0;
      return 0;
    }
    puVar2 = (undefined4 *)(**(code **)(iVar7 + 0x81c))(original_frame_context + 0x1258);
    iVar6 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0xd8) = *puVar2;
    *(undefined4 *)(original_frame_context + 0x1618) =
         *(undefined4 *)(original_frame_context + 0x16e4);
    if (*(int *)(original_frame_context + 0x1618) == 0) {
LAB_0056657c:
      *(undefined4 *)(original_frame_context + 0x160c) =
           *(undefined4 *)(original_frame_context + 0x16e4);
      if (*(int *)(original_frame_context + 0x160c) != 0) {
        iVar7 = (**(code **)(iVar6 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x160c),
                           *(undefined4 *)(iVar6 + -0x5444),*(undefined4 *)(iVar6 + -0x5b6c),0);
        iVar6 = *(int *)(original_frame_context + 0x20);
        if (iVar7 != 0) {
          *(undefined4 *)(original_frame_context + 0x1604) =
               *(undefined4 *)(original_frame_context + 0x16e4);
          if (*(int *)(original_frame_context + 0x1604) == 0) {
            original_frame_context[0x1608] = 0;
            original_frame_context[0x1609] = 0;
            original_frame_context[0x160a] = 0;
            original_frame_context[0x160b] = 0;
          }
          else {
            uVar5 = (**(code **)(iVar6 + -0x598c))
                              (*(undefined4 *)(original_frame_context + 0x1604),
                               *(undefined4 *)(iVar6 + -0x5444),*(undefined4 *)(iVar6 + -0x5b6c),0);
            iVar6 = *(int *)(original_frame_context + 0x20);
            *(undefined4 *)(original_frame_context + 0x1608) = uVar5;
          }
          if (*(int *)(*(int *)(original_frame_context + 0x1608) + 0x19c) ==
              *(int *)(original_frame_context + 0xd8)) goto LAB_005666a4;
        }
      }
      *(undefined4 *)(original_frame_context + 0x1600) =
           *(undefined4 *)(original_frame_context + 0x16e4);
      if (*(int *)(original_frame_context + 0x1600) != 0) {
        iVar7 = (**(code **)(iVar6 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x1600),
                           *(undefined4 *)(iVar6 + -0x5444),*(undefined4 *)(iVar6 + -0x6228),0);
        iVar6 = *(int *)(original_frame_context + 0x20);
        if (iVar7 != 0) {
          *(undefined4 *)(original_frame_context + 0x15f8) =
               *(undefined4 *)(original_frame_context + 0x16e4);
          if (*(int *)(original_frame_context + 0x15f8) == 0) {
            original_frame_context[0x15fc] = 0;
            original_frame_context[0x15fd] = 0;
            original_frame_context[0x15fe] = 0;
            original_frame_context[0x15ff] = 0;
          }
          else {
            uVar5 = (**(code **)(iVar6 + -0x598c))
                              (*(undefined4 *)(original_frame_context + 0x15f8),
                               *(undefined4 *)(iVar6 + -0x5444),*(undefined4 *)(iVar6 + -0x6228),0);
            iVar6 = *(int *)(original_frame_context + 0x20);
            *(undefined4 *)(original_frame_context + 0x15fc) = uVar5;
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
      iVar7 = (**(code **)(iVar6 + -0x598c))
                        (*(undefined4 *)(original_frame_context + 0x1618),
                         *(undefined4 *)(iVar6 + -0x5444),*(undefined4 *)(iVar6 + -0x7420),0);
      iVar6 = *(int *)(original_frame_context + 0x20);
      if (iVar7 == 0) goto LAB_0056657c;
      *(undefined4 *)(original_frame_context + 0x1610) =
           *(undefined4 *)(original_frame_context + 0x16e4);
      if (*(int *)(original_frame_context + 0x1610) == 0) {
        original_frame_context[0x1614] = 0;
        original_frame_context[0x1615] = 0;
        original_frame_context[0x1616] = 0;
        original_frame_context[0x1617] = 0;
      }
      else {
        uVar5 = (**(code **)(iVar6 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x1610),
                           *(undefined4 *)(iVar6 + -0x5444),*(undefined4 *)(iVar6 + -0x7420),0);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x1614) = uVar5;
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
        iVar7 = (**(code **)(iVar6 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x15e0),
                           *(undefined4 *)(iVar6 + -0x5444),*(undefined4 *)(iVar6 + -0x38e0),0);
        iVar6 = *(int *)(original_frame_context + 0x20);
        if (iVar7 == 0) goto LAB_005669e8;
        *(undefined4 *)(original_frame_context + 0x15d8) =
             *(undefined4 *)(original_frame_context + 0x16e4);
        if (*(int *)(original_frame_context + 0x15d8) == 0) {
          original_frame_context[0x15dc] = 0;
          original_frame_context[0x15dd] = 0;
          original_frame_context[0x15de] = 0;
          original_frame_context[0x15df] = 0;
        }
        else {
          uVar5 = (**(code **)(iVar6 + -0x598c))
                            (*(undefined4 *)(original_frame_context + 0x15d8),
                             *(undefined4 *)(iVar6 + -0x5444),*(undefined4 *)(iVar6 + -0x38e0),0);
          iVar6 = *(int *)(original_frame_context + 0x20);
          *(undefined4 *)(original_frame_context + 0x15dc) = uVar5;
        }
        if (*(int *)(*(int *)(original_frame_context + 0x15dc) + 0x1f8) !=
            *(int *)(original_frame_context + 0xd8)) goto LAB_005669e8;
        original_frame_context[0x15e4] = 1;
        original_frame_context[0x15e5] = 0;
        original_frame_context[0x15e6] = 0;
        original_frame_context[0x15e7] = 0;
      }
      if (((*(uint *)(original_frame_context + 0x15e4) ^ 1) & 0xff) != 0) {
        (**(code **)(iVar6 + -0x2b00))(original_frame_context + 0x1284,0x10f,0x1e,0x562);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2820))
                  (*(undefined4 *)(original_frame_context + 0xd8),6);
        (**(code **)(**(int **)(original_frame_context + 0xd8) + 0x24))
                  (*(undefined4 *)(original_frame_context + 0xd8),
                   *(undefined4 *)(original_frame_context + 0x1284),
                   *(undefined4 *)(original_frame_context + 0x1288),original_frame_context + 0x1284)
        ;
        iVar6 = *(int *)(original_frame_context + 0x20);
      }
    }
    else {
      uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45dd);
      iVar6 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xd8) + 0x9c) = uVar1;
      uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45dd);
      iVar6 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xd8) + 0x9e) = uVar1;
      uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45dd);
      iVar6 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xd8) + 0xa0) = uVar1;
      uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45dd);
      iVar6 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xd8) + 0xa2) = uVar1;
      uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45dd);
      iVar6 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xd8) + 0xa4) = uVar1;
      uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45dd);
      iVar6 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xd8) + 0xa6) = uVar1;
      (**(code **)(iVar6 + -0x2b00))(original_frame_context + 0x1284,0x10f,0x4f,0x562);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2820))
                (*(undefined4 *)(original_frame_context + 0xd8),6);
      (**(code **)(**(int **)(original_frame_context + 0xd8) + 0x24))
                (*(undefined4 *)(original_frame_context + 0xd8),
                 *(undefined4 *)(original_frame_context + 0x1284),
                 *(undefined4 *)(original_frame_context + 0x1288),original_frame_context + 0x1284);
      iVar6 = *(int *)(original_frame_context + 0x20);
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
        iVar7 = (**(code **)(iVar6 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x15f0),
                           *(undefined4 *)(iVar6 + -0x5444),*(undefined4 *)(iVar6 + -0x6228),0);
        iVar6 = *(int *)(original_frame_context + 0x20);
        if (iVar7 == 0) goto LAB_005668a4;
        *(undefined4 *)(original_frame_context + 0x15e8) =
             *(undefined4 *)(original_frame_context + 0x16e4);
        if (*(int *)(original_frame_context + 0x15e8) == 0) {
          original_frame_context[0x15ec] = 0;
          original_frame_context[0x15ed] = 0;
          original_frame_context[0x15ee] = 0;
          original_frame_context[0x15ef] = 0;
        }
        else {
          uVar5 = (**(code **)(iVar6 + -0x598c))
                            (*(undefined4 *)(original_frame_context + 0x15e8),
                             *(undefined4 *)(iVar6 + -0x5444),*(undefined4 *)(iVar6 + -0x6228),0);
          iVar6 = *(int *)(original_frame_context + 0x20);
          *(undefined4 *)(original_frame_context + 0x15ec) = uVar5;
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
          iVar6 = *(int *)(original_frame_context + 0x20);
          if (uVar3 <= *(uint *)(original_frame_context + 0xd4)) break;
          iVar6 = (**(code **)(**(int **)(original_frame_context + 0xd8) + 0x40))
                            (*(undefined4 *)(original_frame_context + 0xd8),
                             *(undefined4 *)(original_frame_context + 0xd4));
          *(undefined1 *)(iVar6 + 0x38) = 1;
          *(int *)(original_frame_context + 0xd4) = *(int *)(original_frame_context + 0xd4) + 1;
        }
      }
    }
    uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45ea);
    iVar6 = *(int *)(original_frame_context + 0x20);
    *(undefined2 *)(*(int *)(original_frame_context + 0xd8) + 0x9e) = uVar1;
    (**(code **)(iVar6 + -0x5b08))(*(undefined4 *)(original_frame_context + 0xd8),8);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xae0,0x5cd);
                    /* try { // try from 00566ae0 to 00566ae7 has its CatchHandler @ 00566c98 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xacc,0x5cd);
                    /* try { // try from 00566afc to 00566b03 has its CatchHandler @ 00566c40 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xab8,0x5cd);
                    /* try { // try from 00566b18 to 00566b1f has its CatchHandler @ 00566be4 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xaa4,0x5cd);
                    /* try { // try from 00566b44 to 00566b4b has its CatchHandler @ 00566b88 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x77c8))
              (*(undefined4 *)(original_frame_context + 0xd8),original_frame_context + 0xae0,
               original_frame_context + 0xacc,original_frame_context + 0xab8);
                    /* try { // try from 00566b5c to 00566b63 has its CatchHandler @ 00566be4 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xaa4)
    ;
                    /* try { // try from 00566b74 to 00566b7b has its CatchHandler @ 00566c40 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xab8)
    ;
                    /* try { // try from 00566bd0 to 00566bd7 has its CatchHandler @ 00566c98 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xacc)
    ;
                    /* try { // try from 00566c2c to 00566c33 has its CatchHandler @ 005792b8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xae0)
    ;
                    /* try { // try from 00566c84 to 00566c8b has its CatchHandler @ 005792b8 */
    uVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(1);
    *(undefined4 *)(original_frame_context + 0x15d4) = uVar5;
                    /* try { // try from 00566ce0 to 00566d57 has its CatchHandler @ 005792b8 */
    uVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(1);
    *(undefined4 *)(original_frame_context + 0x15d0) = uVar5;
    uVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(1);
    *(undefined4 *)(original_frame_context + 0x15cc) = uVar5;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(1);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x769c))
              (*(undefined4 *)(original_frame_context + 0xd8),
               *(undefined4 *)(original_frame_context + 0x15d4),
               *(undefined4 *)(original_frame_context + 0x15d0),
               *(undefined4 *)(original_frame_context + 0x15cc));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xa90,0x5cd);
                    /* try { // try from 00566d6c to 00566d73 has its CatchHandler @ 00566f24 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xa7c,0x5cd);
                    /* try { // try from 00566d88 to 00566d8f has its CatchHandler @ 00566ecc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xa68,0x5cd);
                    /* try { // try from 00566da4 to 00566dab has its CatchHandler @ 00566e70 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xa54,0x5cd);
                    /* try { // try from 00566dd0 to 00566dd7 has its CatchHandler @ 00566e14 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x447c))
              (*(undefined4 *)(original_frame_context + 0xd8),original_frame_context + 0xa90,
               original_frame_context + 0xa7c,original_frame_context + 0xa68);
                    /* try { // try from 00566de8 to 00566def has its CatchHandler @ 00566e70 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xa54)
    ;
                    /* try { // try from 00566e00 to 00566e07 has its CatchHandler @ 00566ecc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xa68)
    ;
                    /* try { // try from 00566e5c to 00566e63 has its CatchHandler @ 00566f24 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xa7c)
    ;
                    /* try { // try from 00566eb8 to 00566ebf has its CatchHandler @ 005792b8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xa90)
    ;
                    /* try { // try from 00566f10 to 00566f17 has its CatchHandler @ 005792b8 */
    uVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x51);
    *(undefined4 *)(original_frame_context + 0x15c8) = uVar5;
                    /* try { // try from 00566f6c to 00566fe3 has its CatchHandler @ 005792b8 */
    uVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x51);
    *(undefined4 *)(original_frame_context + 0x15c4) = uVar5;
    uVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x51);
    *(undefined4 *)(original_frame_context + 0x15c0) = uVar5;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x51);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4e28))
              (*(undefined4 *)(original_frame_context + 0xd8),
               *(undefined4 *)(original_frame_context + 0x15c8),
               *(undefined4 *)(original_frame_context + 0x15c4),
               *(undefined4 *)(original_frame_context + 0x15c0));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xa40,0x5cd);
                    /* try { // try from 00566ff8 to 00566fff has its CatchHandler @ 005671b0 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xa2c,0x5cd);
                    /* try { // try from 00567014 to 0056701b has its CatchHandler @ 00567158 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xa18,0x5cd);
                    /* try { // try from 00567030 to 00567037 has its CatchHandler @ 005670fc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0xa04,0x5cd);
                    /* try { // try from 0056705c to 00567063 has its CatchHandler @ 005670a0 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x17d4))
              (*(undefined4 *)(original_frame_context + 0xd8),original_frame_context + 0xa40,
               original_frame_context + 0xa2c,original_frame_context + 0xa18);
                    /* try { // try from 00567074 to 0056707b has its CatchHandler @ 005670fc */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xa04)
    ;
                    /* try { // try from 0056708c to 00567093 has its CatchHandler @ 00567158 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xa18)
    ;
                    /* try { // try from 005670e8 to 005670ef has its CatchHandler @ 005671b0 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xa2c)
    ;
                    /* try { // try from 00567144 to 0056714b has its CatchHandler @ 005792b8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0xa40)
    ;
                    /* try { // try from 0056719c to 005671a3 has its CatchHandler @ 005792b8 */
    uVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x46);
    *(undefined4 *)(original_frame_context + 0x15bc) = uVar5;
                    /* try { // try from 005671f8 to 0056726f has its CatchHandler @ 005792b8 */
    uVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x46);
    *(undefined4 *)(original_frame_context + 0x15b8) = uVar5;
    uVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x46);
    *(undefined4 *)(original_frame_context + 0x15b4) = uVar5;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x46);
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5334))
              (*(undefined4 *)(original_frame_context + 0xd8),
               *(undefined4 *)(original_frame_context + 0x15bc),
               *(undefined4 *)(original_frame_context + 0x15b8),
               *(undefined4 *)(original_frame_context + 0x15b4));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x9f0,0x5cd);
                    /* try { // try from 00567284 to 0056728b has its CatchHandler @ 0056743c */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x9dc,0x5cd);
                    /* try { // try from 005672a0 to 005672a7 has its CatchHandler @ 005673e4 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x9c8,0x5cd);
                    /* try { // try from 005672bc to 005672c3 has its CatchHandler @ 00567388 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
              (original_frame_context + 0x9b4,0x5cd);
                    /* try { // try from 005672e8 to 005672ef has its CatchHandler @ 0056732c */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x4bb4))
              (*(undefined4 *)(original_frame_context + 0xd8),original_frame_context + 0x9f0,
               original_frame_context + 0x9dc,original_frame_context + 0x9c8);
                    /* try { // try from 00567300 to 00567307 has its CatchHandler @ 00567388 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x9b4)
    ;
                    /* try { // try from 00567318 to 0056731f has its CatchHandler @ 005673e4 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x9c8)
    ;
                    /* try { // try from 00567374 to 0056737b has its CatchHandler @ 0056743c */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x9dc)
    ;
                    /* try { // try from 005673d0 to 005673d7 has its CatchHandler @ 005792b8 */
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))(original_frame_context + 0x9f0)
    ;
                    /* try { // try from 00567428 to 0056742f has its CatchHandler @ 005792b8 */
    uVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x51);
    *(undefined4 *)(original_frame_context + 0x15b0) = uVar5;
                    /* try { // try from 00567484 to 00567dbb has its CatchHandler @ 005792b8 */
    uVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x51);
    *(undefined4 *)(original_frame_context + 0x15ac) = uVar5;
    uVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x51);
    *(undefined4 *)(original_frame_context + 0x15a8) = uVar5;
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x51);
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
      uVar5 = (**(code **)(**(int **)(original_frame_context + 0xd8) + 0x40))
                        (*(undefined4 *)(original_frame_context + 0xd8),
                         *(undefined4 *)(original_frame_context + 0xd0));
      *(undefined4 *)(original_frame_context + 0xcc) = uVar5;
      uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x45f7);
      iVar6 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0x9c) = uVar1;
      uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45f7);
      iVar6 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0x9e) = uVar1;
      uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45dd);
      iVar6 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0xa0) = uVar1;
      uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45dd);
      iVar6 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0xa2) = uVar1;
      uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45dd);
      iVar6 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0xa4) = uVar1;
      uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45dd);
      iVar6 = *(int *)(original_frame_context + 0x20);
      *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0xa6) = uVar1;
      (**(code **)(iVar6 + -0x910))(*(int *)(original_frame_context + 0xcc) + 0xb8,0x4ac);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0xcc) + 0xcc,0x122);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0xcc) + 0xe0,0x122);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                (*(int *)(original_frame_context + 0xcc) + 0xf4,0x122);
      uVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x5e);
      iVar6 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(*(int *)(original_frame_context + 0xcc) + 0x84) = uVar5;
      uVar5 = (**(code **)(iVar6 + -0x5868))(0x13);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x2790))
                (*(undefined4 *)(original_frame_context + 0xcc),1,uVar5,0xf);
      iVar6 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(original_frame_context + 0x15a0) =
           *(undefined4 *)(original_frame_context + 0xcc);
      if (*(int *)(original_frame_context + 0x15a0) == 0) {
        original_frame_context[0x15a4] = 0;
        original_frame_context[0x15a5] = 0;
        original_frame_context[0x15a6] = 0;
        original_frame_context[0x15a7] = 0;
      }
      else {
        uVar5 = (**(code **)(iVar6 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x15a0),
                           *(undefined4 *)(iVar6 + -0x2dd4),*(undefined4 *)(iVar6 + -0x7558),0);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x15a4) = uVar5;
      }
      *(undefined4 *)(original_frame_context + 200) =
           *(undefined4 *)(original_frame_context + 0x15a4);
      if (*(int *)(original_frame_context + 200) != 0) {
        *(undefined2 *)(*(int *)(*(int *)(original_frame_context + 200) + 0x260) + 0x9e) = 0x46;
        *(undefined4 *)(original_frame_context + 0x159c) =
             *(undefined4 *)(*(int *)(original_frame_context + 200) + 0x25c);
        uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45f7);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x159c) + 0x9c) = uVar1;
        *(undefined4 *)(original_frame_context + 0x1598) =
             *(undefined4 *)(*(int *)(original_frame_context + 200) + 0x25c);
        uVar5 = (**(code **)(iVar6 + -0x5868))(0x5e);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1598) + 0x84) = uVar5;
        *(undefined4 *)(original_frame_context + 0x1594) =
             *(undefined4 *)(*(int *)(original_frame_context + 200) + 0x260);
        uVar5 = (**(code **)(iVar6 + -0x5868))(0x5e);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1594) + 0x84) = uVar5;
        (**(code **)(iVar6 + -0x910))(*(int *)(original_frame_context + 200) + 0xb8,0x4ac);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 200) + 0xcc,0x122);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 200) + 0xe0,0x122);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 200) + 0xf4,0x122);
        iVar6 = *(int *)(original_frame_context + 0x20);
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
        uVar5 = (**(code **)(iVar6 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x158c),
                           *(undefined4 *)(iVar6 + -0x2dd4),*(undefined4 *)(iVar6 + -0x71d0),0);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x1590) = uVar5;
      }
      *(undefined4 *)(original_frame_context + 0xc4) =
           *(undefined4 *)(original_frame_context + 0x1590);
      if (*(int *)(original_frame_context + 0xc4) != 0) {
        *(undefined2 *)(*(int *)(original_frame_context + 0xc4) + 0x9e) = 0x46;
        uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45f7);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0xc4) + 0x9c) = uVar1;
        (**(code **)(iVar6 + -0x910))(*(int *)(original_frame_context + 0xc4) + 0xb8,0x4ac);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xc4) + 0xcc,0x122);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xc4) + 0xe0,0x122);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xc4) + 0xf4,0x122);
        iVar6 = *(int *)(original_frame_context + 0x20);
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
        uVar5 = (**(code **)(iVar6 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x1584),
                           *(undefined4 *)(iVar6 + -0x2dd4),*(undefined4 *)(iVar6 + -0x7878),0);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x1588) = uVar5;
      }
      *(undefined4 *)(original_frame_context + 0xc0) =
           *(undefined4 *)(original_frame_context + 0x1588);
      if (*(int *)(original_frame_context + 0xc0) != 0) {
        *(undefined2 *)(*(int *)(*(int *)(original_frame_context + 0xc0) + 0x264) + 0x9e) = 0x46;
        *(undefined4 *)(original_frame_context + 0x1580) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xc0) + 0x260);
        uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45f7);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0x1580) + 0x9c) = uVar1;
        *(undefined4 *)(original_frame_context + 0x157c) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xc0) + 0x260);
        uVar5 = (**(code **)(iVar6 + -0x5868))(0x5e);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x157c) + 0x84) = uVar5;
        *(undefined4 *)(original_frame_context + 0x1578) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xc0) + 0x264);
        uVar5 = (**(code **)(iVar6 + -0x5868))(0x5e);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1578) + 0x84) = uVar5;
        (**(code **)(iVar6 + -0x910))(*(int *)(original_frame_context + 0xc0) + 0xb8,0x4ac);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xc0) + 0xcc,0x122);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xc0) + 0xe0,0x122);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xc0) + 0xf4,0x122);
        iVar6 = *(int *)(original_frame_context + 0x20);
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
        uVar5 = (**(code **)(iVar6 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x1570),
                           *(undefined4 *)(iVar6 + -0x2dd4),*(undefined4 *)(iVar6 + -0x16c),0);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x1574) = uVar5;
      }
      *(undefined4 *)(original_frame_context + 0xbc) =
           *(undefined4 *)(original_frame_context + 0x1574);
      if (*(int *)(original_frame_context + 0xbc) != 0) {
        *(undefined2 *)(*(int *)(original_frame_context + 0xbc) + 0x9e) = 0x46;
        uVar1 = (**(code **)(iVar6 + -0x38a4))(0x45f7);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0xbc) + 0x9c) = uVar1;
        (**(code **)(iVar6 + -0x910))(*(int *)(original_frame_context + 0xbc) + 0xb8,0x4ac);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xbc) + 0xcc,0x122);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xbc) + 0xe0,0x122);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x910))
                  (*(int *)(original_frame_context + 0xbc) + 0xf4,0x122);
        uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0xbc) + 0x13a) = uVar1;
        uVar1 = (**(code **)(iVar6 + -0x38a4))(0x3215);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0xbc) + 0x146) = uVar1;
        uVar1 = (**(code **)(iVar6 + -0x38a4))(0x3215);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0xbc) + 0x152) = uVar1;
        uVar1 = (**(code **)(iVar6 + -0x38a4))(0x3215);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined2 *)(*(int *)(original_frame_context + 0xbc) + 0x15e) = uVar1;
        uVar3 = (**(code **)(iVar6 + -0x38a4))(0x3215);
        *(uint *)(original_frame_context + 0x156c) = uVar3 & 0xffff;
        uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
        *(uint *)(original_frame_context + 0x1568) = uVar3 & 0xffff;
        uVar3 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
        *(uint *)(original_frame_context + 0x1564) = uVar3 & 0xffff;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x3215);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x78fc))
                  (*(undefined4 *)(original_frame_context + 0xbc),
                   *(undefined4 *)(original_frame_context + 0x156c),
                   *(undefined4 *)(original_frame_context + 0x1568),
                   *(undefined4 *)(original_frame_context + 0x1564));
        uVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x5e);
        *(undefined4 *)(original_frame_context + 0x1560) = uVar5;
        uVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x54);
        *(undefined4 *)(original_frame_context + 0x155c) = uVar5;
        uVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x5e);
        *(undefined4 *)(original_frame_context + 0x1558) = uVar5;
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x5e);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x7160))
                  (*(undefined4 *)(original_frame_context + 0xbc),
                   *(undefined4 *)(original_frame_context + 0x1560),
                   *(undefined4 *)(original_frame_context + 0x155c),
                   *(undefined4 *)(original_frame_context + 0x1558));
        *(undefined4 *)(original_frame_context + 0x1554) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xbc) + 0x250);
        uVar5 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x5868))(0x5e);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1554) + 0x84) = uVar5;
        *(undefined4 *)(original_frame_context + 0x1550) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xbc) + 0x254);
        uVar5 = (**(code **)(iVar6 + -0x5868))(0x5e);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1550) + 0x84) = uVar5;
        (**(code **)(iVar6 + -0x22f8))(*(undefined4 *)(original_frame_context + 0xbc),1);
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x9a0,0x5cd);
                    /* try { // try from 00567dd0 to 00567dd7 has its CatchHandler @ 00567f74 */
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x98c,0x5cd);
                    /* try { // try from 00567dec to 00567df3 has its CatchHandler @ 00567f30 */
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x978,0x5cd);
                    /* try { // try from 00567e08 to 00567e0f has its CatchHandler @ 00567ed4 */
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x45a8))
                  (original_frame_context + 0x964,0x135);
                    /* try { // try from 00567e34 to 00567e3b has its CatchHandler @ 00567e78 */
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x47f0))
                  (*(undefined4 *)(original_frame_context + 0xbc),original_frame_context + 0x9a0,
                   original_frame_context + 0x98c,original_frame_context + 0x978);
                    /* try { // try from 00567e4c to 00567e53 has its CatchHandler @ 00567ed4 */
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x964);
                    /* try { // try from 00567e64 to 00567e6b has its CatchHandler @ 00567f30 */
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x978);
                    /* try { // try from 00567ec0 to 00567ec7 has its CatchHandler @ 00567f74 */
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x98c);
                    /* try { // try from 00567f1c to 00567f23 has its CatchHandler @ 005792b8 */
        (**(code **)(*(int *)(original_frame_context + 0x20) + -0x3ecc))
                  (original_frame_context + 0x9a0);
        iVar6 = *(int *)(original_frame_context + 0x20);
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
        uVar5 = (**(code **)(iVar6 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x1548),
                           *(undefined4 *)(iVar6 + -0x2dd4),*(undefined4 *)(iVar6 + -0x4d04),0);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x154c) = uVar5;
      }
      *(undefined4 *)(original_frame_context + 0xb8) =
           *(undefined4 *)(original_frame_context + 0x154c);
      if (*(int *)(original_frame_context + 0xb8) != 0) {
        *(undefined2 *)(*(int *)(*(int *)(original_frame_context + 0xb8) + 0x268) + 0x9c) = 0x5a;
        *(undefined4 *)(original_frame_context + 0x1544) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xb8) + 0x268);
                    /* try { // try from 0056802c to 005685df has its CatchHandler @ 005792b8 */
        uVar5 = (**(code **)(iVar6 + -0x5868))(0x45);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1544) + 0x7c) = uVar5;
        *(undefined4 *)(original_frame_context + 0x1540) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xb8) + 0x268);
        uVar5 = (**(code **)(iVar6 + -0x5868))(0x54);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1540) + 0x80) = uVar5;
        *(undefined4 *)(original_frame_context + 0x153c) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xb8) + 0x268);
        uVar5 = (**(code **)(iVar6 + -0x5868))(0x45);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x153c) + 0x84) = uVar5;
        *(undefined4 *)(original_frame_context + 0x1538) =
             *(undefined4 *)(*(int *)(original_frame_context + 0xb8) + 0x268);
        uVar5 = (**(code **)(iVar6 + -0x5868))(0x45);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(*(int *)(original_frame_context + 0x1538) + 0x88) = uVar5;
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
        uVar5 = (**(code **)(iVar6 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x1530),
                           *(undefined4 *)(iVar6 + -0x2dd4),*(undefined4 *)(iVar6 + -0x6e84),0);
        iVar6 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x1534) = uVar5;
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
          iVar7 = (**(code **)(iVar6 + -0x598c))
                            (*(undefined4 *)(original_frame_context + 0x1528),
                             *(undefined4 *)(iVar6 + -0x5444),*(undefined4 *)(iVar6 + -0x7420),0);
          iVar6 = *(int *)(original_frame_context + 0x20);
          if (iVar7 == 0) goto LAB_0056816c;
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
            uVar5 = (**(code **)(iVar6 + -0x598c))
                              (*(undefined4 *)(original_frame_context + 0x1520),
                               *(undefined4 *)(iVar6 + -0x5444),*(undefined4 *)(iVar6 + -0x7420),0);
            iVar6 = *(int *)(original_frame_context + 0x20);
            *(undefined4 *)(original_frame_context + 0x1524) = uVar5;
          }
          if (*(int *)(*(int *)(original_frame_context + 0x1524) + 0x200) ==
              *(int *)(original_frame_context + 0xb4)) {
            original_frame_context[0xb0] = 1;
          }
        }
        if (original_frame_context[0xb0] == 1) {
          (**(code **)(iVar6 + -0x910))(*(int *)(original_frame_context + 0xb4) + 0xb8,0x4ac);
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
          iVar6 = *(int *)(original_frame_context + 0x20);
        }
        else {
          (**(code **)(iVar6 + -0x910))(*(int *)(original_frame_context + 0xb4) + 0xb8,0x4ac);
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
            iVar6 = *(int *)(original_frame_context + 0x20);
            if (uVar3 <= *(uint *)(original_frame_context + 0xac)) break;
            uVar5 = (**(code **)(**(int **)(original_frame_context + 0xb4) + 0x40))
                              (*(undefined4 *)(original_frame_context + 0xb4),
                               *(undefined4 *)(original_frame_context + 0xac));
            *(undefined4 *)(original_frame_context + 0xcc) = uVar5;
            (**(code **)(**(int **)(original_frame_context + 0xcc) + 0x24))
                      (*(undefined4 *)(original_frame_context + 0xcc),
                       *(undefined4 *)(original_frame_context + 0x1294),
                       *(undefined4 *)(original_frame_context + 0x1298),
                       original_frame_context + 0x1294);
            iVar6 = *(int *)(original_frame_context + 0x20);
            *(undefined1 *)(*(int *)(original_frame_context + 0xcc) + 0x3a) = 1;
            (**(code **)(iVar6 + -0x910))(*(int *)(original_frame_context + 0xcc) + 0xb8,0x6d);
            uVar1 = (**(code **)(*(int *)(original_frame_context + 0x20) + -0x38a4))(0x45f7);
            iVar6 = *(int *)(original_frame_context + 0x20);
            *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0x9c) = uVar1;
            uVar1 = (**(code **)(iVar6 + -0x38a4))(0x3214);
            iVar6 = *(int *)(original_frame_context + 0x20);
            *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0x13a) = uVar1;
            uVar1 = (**(code **)(iVar6 + -0x38a4))(0x3214);
            iVar6 = *(int *)(original_frame_context + 0x20);
            *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0x146) = uVar1;
            uVar1 = (**(code **)(iVar6 + -0x38a4))(0x3214);
            iVar6 = *(int *)(original_frame_context + 0x20);
            *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0x152) = uVar1;
            uVar1 = (**(code **)(iVar6 + -0x38a4))(0x3214);
            *(undefined2 *)(*(int *)(original_frame_context + 0xcc) + 0x15e) = uVar1;
            *(int *)(original_frame_context + 0xac) = *(int *)(original_frame_context + 0xac) + 1;
          }
        }
        (**(code **)(iVar6 + -0x74e8))(*(undefined4 *)(original_frame_context + 0xb4));
      }
      *(int *)(original_frame_context + 0xd0) = *(int *)(original_frame_context + 0xd0) + 1;
    }
    (**(code **)(**(int **)(original_frame_context + 0xd8) + 0x48))
              (*(undefined4 *)(original_frame_context + 0xd8));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x74e8))
              (*(undefined4 *)(original_frame_context + 0xd8));
    (**(code **)(*(int *)(original_frame_context + 0x20) + -0x20cc))
              (original_frame_context + 0x960,original_frame_context + 0x1258,0);
    iVar6 = *(int *)(original_frame_context + 0x20);
  } while( true );
}

