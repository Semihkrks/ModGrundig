
/* Analysis fragment only; external jumps/continuation are abstracted as exits. Not original
   standalone code. Original frame/GP context required. */

undefined4
Settings_fragment_root_containers
          (uint boundary_a0,uint boundary_a1,uint boundary_a2,uint boundary_a3,
          byte *original_frame_context)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  _Rect::set((_Rect *)(original_frame_context + 0x11e4),0x10f,0,0x562,0x5a);
  (**(code **)(*(int *)(original_frame_context + 0x20) + 0x948))(original_frame_context + 0x11f4);
  (**(code **)(*(int *)(original_frame_context + 0x20) + 0x948))(original_frame_context + 0x1240);
  iVar5 = *(int *)(original_frame_context + 0x20);
  *(undefined4 *)(original_frame_context + 0x1654) =
       *(undefined4 *)(original_frame_context + 0x16e4);
  if (*(int *)(original_frame_context + 0x1654) == 0) {
LAB_00565e9c:
    *(undefined4 *)(original_frame_context + 0x1650) =
         *(undefined4 *)(original_frame_context + 0x16e4);
    if (*(int *)(original_frame_context + 0x1650) != 0) {
      iVar1 = (**(code **)(iVar5 + -0x598c))
                        (*(undefined4 *)(original_frame_context + 0x1650),
                         *(undefined4 *)(iVar5 + -0x5444),*(undefined4 *)(iVar5 + -0x7420),0);
      iVar5 = *(int *)(original_frame_context + 0x20);
      if (iVar1 != 0) goto LAB_00565f8c;
    }
    *(undefined4 *)(original_frame_context + 0x164c) =
         *(undefined4 *)(original_frame_context + 0x16e4);
    if (*(int *)(original_frame_context + 0x164c) != 0) {
      iVar1 = (**(code **)(iVar5 + -0x598c))
                        (*(undefined4 *)(original_frame_context + 0x164c),
                         *(undefined4 *)(iVar5 + -0x5444),*(undefined4 *)(iVar5 + -0x5b6c),0);
      iVar5 = *(int *)(original_frame_context + 0x20);
      if (iVar1 != 0) goto LAB_00565f8c;
    }
    *(undefined4 *)(original_frame_context + 0x1648) =
         *(undefined4 *)(original_frame_context + 0x16e4);
    if (*(int *)(original_frame_context + 0x1648) != 0) {
      iVar1 = (**(code **)(iVar5 + -0x598c))
                        (*(undefined4 *)(original_frame_context + 0x1648),
                         *(undefined4 *)(iVar5 + -0x5444),*(undefined4 *)(iVar5 + -0x6228),0);
      iVar5 = *(int *)(original_frame_context + 0x20);
      if (iVar1 != 0) goto LAB_00565f8c;
    }
    *(undefined4 *)(original_frame_context + 0x1644) =
         *(undefined4 *)(original_frame_context + 0x16e4);
    if (*(int *)(original_frame_context + 0x1644) != 0) {
      iVar1 = (**(code **)(iVar5 + -0x598c))
                        (*(undefined4 *)(original_frame_context + 0x1644),
                         *(undefined4 *)(iVar5 + -0x5444),*(undefined4 *)(iVar5 + -0x4a68),0);
      iVar5 = *(int *)(original_frame_context + 0x20);
      if (iVar1 != 0) goto LAB_00565f8c;
    }
    original_frame_context[0x1658] = 0;
    original_frame_context[0x1659] = 0;
    original_frame_context[0x165a] = 0;
    original_frame_context[0x165b] = 0;
  }
  else {
    iVar1 = (**(code **)(iVar5 + -0x598c))
                      (*(undefined4 *)(original_frame_context + 0x1654),
                       *(undefined4 *)(iVar5 + -0x5444),*(undefined4 *)(iVar5 + -0x38e0),0);
    iVar5 = *(int *)(original_frame_context + 0x20);
    if (iVar1 == 0) goto LAB_00565e9c;
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
      uVar2 = (**(code **)(**(int **)(*(int *)(original_frame_context + 0x16e4) + 0x38) + 0x44))
                        (*(undefined4 *)(*(int *)(original_frame_context + 0x16e4) + 0x38));
      iVar5 = *(int *)(original_frame_context + 0x20);
      if (uVar2 <= *(uint *)(original_frame_context + 0xe4)) break;
                    /* try { // try from 00565fdc to 005663b7 has its CatchHandler @ 005792f4 */
      uVar4 = (**(code **)(**(int **)(*(int *)(original_frame_context + 0x16e4) + 0x38) + 0x40))
                        (*(undefined4 *)(*(int *)(original_frame_context + 0x16e4) + 0x38),
                         *(undefined4 *)(original_frame_context + 0xe4));
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined4 *)(original_frame_context + 0xe0) = uVar4;
      *(undefined4 *)(original_frame_context + 0x163c) =
           *(undefined4 *)(original_frame_context + 0xe0);
      if (*(int *)(original_frame_context + 0x163c) == 0) {
        original_frame_context[0x1640] = 0;
        original_frame_context[0x1641] = 0;
        original_frame_context[0x1642] = 0;
        original_frame_context[0x1643] = 0;
      }
      else {
        uVar4 = (**(code **)(iVar5 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x163c),
                           *(undefined4 *)(iVar5 + -0x2dd4),*(undefined4 *)(iVar5 + -0x6e84),0);
        iVar5 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x1640) = uVar4;
      }
      *(undefined4 *)(original_frame_context + 0x126c) =
           *(undefined4 *)(original_frame_context + 0x1640);
      if (*(int *)(original_frame_context + 0x126c) != 0) {
        if (*(char *)(*(int *)(original_frame_context + 0x126c) + 0x3a) == '\x01') {
          (**(code **)(iVar5 + -0x7790))
                    (original_frame_context + 0x11f4,original_frame_context + 0x126c);
        }
        else {
          (**(code **)(iVar5 + -0x6b0c))
                    (*(undefined4 *)(original_frame_context + 0x126c),
                     original_frame_context + 0x125c);
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
  iVar5 = (**(code **)(iVar5 + 0x8e4))(original_frame_context + 0x11f4);
  iVar1 = *(int *)(original_frame_context + 0x20);
  *(int *)(original_frame_context + 0x1270) = iVar5 + -1;
  do {
    if (*(int *)(original_frame_context + 0x1270) < 0) {
      uVar4 = (**(code **)(iVar1 + -0x7b0))(original_frame_context + 0x124c);
      return uVar4;
    }
    puVar3 = (undefined4 *)
             (**(code **)(iVar1 + -0x76a0))
                       (original_frame_context + 0x11f4,
                        *(undefined4 *)(original_frame_context + 0x1270));
    iVar1 = *(int *)(original_frame_context + 0x20);
    *(undefined4 *)(original_frame_context + 0xdc) = *puVar3;
    *(undefined4 *)(original_frame_context + 0x1634) =
         *(undefined4 *)(original_frame_context + 0x16e4);
    if (*(int *)(original_frame_context + 0x1634) == 0) {
LAB_00566240:
      *(undefined4 *)(original_frame_context + 0x1628) =
           *(undefined4 *)(original_frame_context + 0x16e4);
      if (*(int *)(original_frame_context + 0x1628) != 0) {
        iVar5 = (**(code **)(iVar1 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x1628),
                           *(undefined4 *)(iVar1 + -0x5444),*(undefined4 *)(iVar1 + -0x5b6c),0);
        iVar1 = *(int *)(original_frame_context + 0x20);
        if (iVar5 != 0) {
          *(undefined4 *)(original_frame_context + 0x1620) =
               *(undefined4 *)(original_frame_context + 0x16e4);
          if (*(int *)(original_frame_context + 0x1620) == 0) {
            original_frame_context[0x1624] = 0;
            original_frame_context[0x1625] = 0;
            original_frame_context[0x1626] = 0;
            original_frame_context[0x1627] = 0;
          }
          else {
            uVar4 = (**(code **)(iVar1 + -0x598c))
                              (*(undefined4 *)(original_frame_context + 0x1620),
                               *(undefined4 *)(iVar1 + -0x5444),*(undefined4 *)(iVar1 + -0x5b6c),0);
            iVar1 = *(int *)(original_frame_context + 0x20);
            *(undefined4 *)(original_frame_context + 0x1624) = uVar4;
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
      iVar5 = (**(code **)(iVar1 + -0x598c))
                        (*(undefined4 *)(original_frame_context + 0x1634),
                         *(undefined4 *)(iVar1 + -0x5444),*(undefined4 *)(iVar1 + -0x5b6c),0);
      iVar1 = *(int *)(original_frame_context + 0x20);
      if (iVar5 == 0) goto LAB_00566240;
      *(undefined4 *)(original_frame_context + 0x162c) =
           *(undefined4 *)(original_frame_context + 0x16e4);
      if (*(int *)(original_frame_context + 0x162c) == 0) {
        original_frame_context[0x1630] = 0;
        original_frame_context[0x1631] = 0;
        original_frame_context[0x1632] = 0;
        original_frame_context[0x1633] = 0;
      }
      else {
        uVar4 = (**(code **)(iVar1 + -0x598c))
                          (*(undefined4 *)(original_frame_context + 0x162c),
                           *(undefined4 *)(iVar1 + -0x5444),*(undefined4 *)(iVar1 + -0x5b6c),0);
        iVar1 = *(int *)(original_frame_context + 0x20);
        *(undefined4 *)(original_frame_context + 0x1630) = uVar4;
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
      (**(code **)(iVar1 + -0x2b00))(original_frame_context + 0x1274,0,0x31,0x780);
      (**(code **)(**(int **)(original_frame_context + 0xdc) + 0x24))
                (*(undefined4 *)(original_frame_context + 0xdc),
                 *(undefined4 *)(original_frame_context + 0x1274),
                 *(undefined4 *)(original_frame_context + 0x1278),original_frame_context + 0x1274);
      iVar5 = *(int *)(original_frame_context + 0x20);
      *(undefined1 *)(*(int *)(original_frame_context + 0xdc) + 0x39) = 0;
      *(undefined1 *)(*(int *)(original_frame_context + 0xdc) + 0x3a) = 0;
      (**(code **)(iVar5 + -0x464))(*(undefined4 *)(original_frame_context + 0xdc));
      uVar4 = (**(code **)(**(int **)(original_frame_context + 0xdc) + 0x40))
                        (*(undefined4 *)(original_frame_context + 0xdc),0);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x72a8))(uVar4);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x30a8))
                (original_frame_context + 0xaf8,original_frame_context + 0x11f4);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x467c))
                (original_frame_context + 0xafc,original_frame_context + 0xaf8,
                 original_frame_context + 0x1270);
      (**(code **)(*(int *)(original_frame_context + 0x20) + -0x6168))
                (original_frame_context + 0xb00,original_frame_context + 0x11f4,
                 *(undefined4 *)(original_frame_context + 0xafc));
      iVar1 = *(int *)(original_frame_context + 0x20);
    }
    *(int *)(original_frame_context + 0x1270) = *(int *)(original_frame_context + 0x1270) + -1;
  } while( true );
}

