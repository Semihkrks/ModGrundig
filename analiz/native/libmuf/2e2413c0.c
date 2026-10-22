
/* MResourcePkg::ReadResProfile() */

undefined4 MResourcePkg::ReadResProfile(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int in_t9;
  code *pcVar7;
  undefined1 auStack_88 [4];
  undefined1 auStack_84 [4];
  int local_80;
  int local_7c;
  int local_78;
  undefined1 auStack_74 [4];
  undefined1 auStack_70 [4];
  undefined1 auStack_6c [12];
  undefined1 auStack_60 [68];
  
  local_80 = *(int *)(in_t9 + 0x738d0) + 0xc;
                    /* try { // try from 2e241410 to 2e241417 has its CatchHandler @ 2e241cac */
  (**(code **)(in_t9 + 0x72f14))(&local_7c,*(int *)(in_t9 + 0x72548) + -0x4eec,auStack_88);
  iVar6 = *(int *)(in_t9 + 0x72548);
                    /* try { // try from 2e241430 to 2e241917 has its CatchHandler @ 2e241c90 */
  iVar1 = (**(code **)(in_t9 + 0x73824))(iVar6 + -0x50e8,*(int *)(in_t9 + 0x72548) + -0x5160);
  if (iVar1 == 0) {
    (**(code **)(in_t9 + 0x72b20))(*(int *)(in_t9 + 0x72548) + -0x50cc,iVar6 + -0x50e8);
    (**(code **)(in_t9 + 0x72b20))
              (*(int *)(in_t9 + 0x72548) + -0x73a0,*(int *)(in_t9 + 0x72548) + -0x51fc,
               *(int *)(in_t9 + 0x72548) + -0x4be4,0x7b);
  }
  else {
    iVar2 = (**(code **)(in_t9 + 0x73a40))(auStack_6c,0xc,1,iVar1);
    if (iVar2 == 1) goto LAB_2e2414d4;
    (**(code **)(in_t9 + 0x72b20))(*(int *)(in_t9 + 0x72548) + -0x50ac,iVar6 + -0x50e8);
    (**(code **)(in_t9 + 0x73324))(iVar1);
    (**(code **)(in_t9 + 0x72b20))
              (*(int *)(in_t9 + 0x72548) + -0x73a0,*(int *)(in_t9 + 0x72548) + -0x51fc,
               *(int *)(in_t9 + 0x72548) + -0x4be4,0x86);
  }
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            while( true ) {
              while( true ) {
                while( true ) {
                  while( true ) {
                    while( true ) {
                      (**(code **)(in_t9 + 0x72808))();
LAB_2e2414d4:
                      local_78 = 0;
                      iVar6 = (**(code **)(in_t9 + 0x73a40))(&local_78,4,1,iVar1);
                      if (iVar6 == 1) break;
                      (**(code **)(in_t9 + 0x73324))(iVar1);
                      (**(code **)(in_t9 + 0x72a80))(*(int *)(in_t9 + 0x72548) + -0x5088);
                      (**(code **)(in_t9 + 0x72b20))
                                (*(int *)(in_t9 + 0x72548) + -0x73a0,
                                 *(int *)(in_t9 + 0x72548) + -0x51fc,
                                 *(int *)(in_t9 + 0x72548) + -0x4be4,0x91);
                    }
                    if (local_78 - 1U < 0xff) break;
                    (**(code **)(in_t9 + 0x73324))(iVar1);
                    (**(code **)(in_t9 + 0x72a80))(*(int *)(in_t9 + 0x72548) + -0x5088);
                    (**(code **)(in_t9 + 0x72b20))
                              (*(int *)(in_t9 + 0x72548) + -0x73a0,
                               *(int *)(in_t9 + 0x72548) + -0x51fc,
                               *(int *)(in_t9 + 0x72548) + -0x4be4,0xa7);
                  }
                  iVar6 = (**(code **)(in_t9 + 0x73310))(local_78,*(undefined4 *)(in_t9 + 0x738bc));
                  if (iVar6 != 0) break;
                  (**(code **)(in_t9 + 0x73324))(iVar1);
                  (**(code **)(in_t9 + 0x72a80))(*(int *)(in_t9 + 0x72548) + -0x5060);
                  (**(code **)(in_t9 + 0x72b20))
                            (*(int *)(in_t9 + 0x72548) + -0x73a0,*(int *)(in_t9 + 0x72548) + -0x51fc
                             ,*(int *)(in_t9 + 0x72548) + -0x4be4,0x9e);
                }
                iVar2 = (**(code **)(in_t9 + 0x73a40))(iVar6,1,local_78,iVar1);
                if (iVar2 == local_78) break;
                (**(code **)(in_t9 + 0x73324))(iVar1);
                (**(code **)(in_t9 + 0x72a80))(*(int *)(in_t9 + 0x72548) + -0x5088);
                (**(code **)(in_t9 + 0x72b20))
                          (*(int *)(in_t9 + 0x72548) + -0x73a0,*(int *)(in_t9 + 0x72548) + -0x51fc,
                           *(int *)(in_t9 + 0x72548) + -0x4be4,0xb0);
              }
              pcVar7 = *(code **)(in_t9 + 0x73a40);
              *(undefined1 *)(iVar6 + iVar2 + -1) = 0;
              iVar2 = (*pcVar7)(&local_78,4,1,iVar1);
              if (iVar2 == 1) break;
              (**(code **)(in_t9 + 0x73324))(iVar1);
              (**(code **)(in_t9 + 0x72a80))(*(int *)(in_t9 + 0x72548) + -0x5088);
              (**(code **)(in_t9 + 0x72b20))
                        (*(int *)(in_t9 + 0x72548) + -0x73a0,*(int *)(in_t9 + 0x72548) + -0x51fc,
                         *(int *)(in_t9 + 0x72548) + -0x4be4,0xba);
            }
            if (local_78 - 1U < 0xff) break;
            (**(code **)(in_t9 + 0x73324))(iVar1);
            (**(code **)(in_t9 + 0x72a80))(*(int *)(in_t9 + 0x72548) + -0x5088);
            (**(code **)(in_t9 + 0x72b20))
                      (*(int *)(in_t9 + 0x72548) + -0x73a0,*(int *)(in_t9 + 0x72548) + -0x51fc,
                       *(int *)(in_t9 + 0x72548) + -0x4be4,0xd0);
          }
          iVar2 = (**(code **)(in_t9 + 0x73310))(local_78,*(undefined4 *)(in_t9 + 0x738bc));
          if (iVar2 != 0) break;
                    /* try { // try from 2e241b40 to 2e241c63 has its CatchHandler @ 2e241c90 */
          (**(code **)(in_t9 + 0x73324))(iVar1);
          (**(code **)(in_t9 + 0x72a80))(*(int *)(in_t9 + 0x72548) + -0x5040);
          (**(code **)(in_t9 + 0x72b20))
                    (*(int *)(in_t9 + 0x72548) + -0x73a0,*(int *)(in_t9 + 0x72548) + -0x51fc,
                     *(int *)(in_t9 + 0x72548) + -0x4be4,199);
        }
        iVar3 = (**(code **)(in_t9 + 0x73a40))(iVar2,1,local_78,iVar1);
        if (iVar3 == local_78) break;
        (**(code **)(in_t9 + 0x73324))(iVar1);
        (**(code **)(in_t9 + 0x72a80))(*(int *)(in_t9 + 0x72548) + -0x5088);
        (**(code **)(in_t9 + 0x72b20))
                  (*(int *)(in_t9 + 0x72548) + -0x73a0,*(int *)(in_t9 + 0x72548) + -0x51fc,
                   *(int *)(in_t9 + 0x72548) + -0x4be4,0xd8);
      }
      pcVar7 = *(code **)(in_t9 + 0x735c8);
      *(undefined1 *)(iVar2 + iVar3 + -1) = 0;
      (*pcVar7)(iVar6);
      iVar3 = (**(code **)(in_t9 + 0x72b84))(iVar2);
      if (iVar3 != 0) break;
      (**(code **)(in_t9 + 0x73324))(iVar1);
      (**(code **)(in_t9 + 0x72a80))(*(int *)(in_t9 + 0x72548) + -0x5020);
      (**(code **)(in_t9 + 0x72b20))
                (*(int *)(in_t9 + 0x72548) + -0x73a0,*(int *)(in_t9 + 0x72548) + -0x51fc,
                 *(int *)(in_t9 + 0x72548) + -0x4be4,0xe2);
    }
    (**(code **)(in_t9 + 0x72d6c))(iVar2);
    (**(code **)(in_t9 + 0x72d6c))(iVar6);
    (**(code **)(in_t9 + 0x73324))(iVar1);
                    /* try { // try from 2e241934 to 2e24193b has its CatchHandler @ 2e241cd8 */
    (**(code **)(in_t9 + 0x72f14))
              (auStack_74,*(undefined4 *)(*(int *)(in_t9 + 0x72538) + 0x3a94),auStack_84);
                    /* try { // try from 2e24194c to 2e241953 has its CatchHandler @ 2e241cbc */
    (**(code **)(in_t9 + 0x72d50))(&local_80,auStack_74);
                    /* try { // try from 2e24195c to 2e241963 has its CatchHandler @ 2e241cd8 */
    (**(code **)(in_t9 + 0x72a1c))(auStack_74);
                    /* try { // try from 2e241974 to 2e241aeb has its CatchHandler @ 2e241c90 */
    uVar4 = (**(code **)(in_t9 + 0x72724))(&local_80,&local_7c,0);
    (**(code **)(in_t9 + 0x72ec4))
              (&local_80,uVar4,*(undefined4 *)(local_7c + -0xc),*(int *)(in_t9 + 0x72548) + -0x5004)
    ;
    iVar6 = (**(code **)(in_t9 + 0x73824))(local_80,*(int *)(in_t9 + 0x72548) + -0x402c);
    if (iVar6 == 0) break;
    iVar1 = *(int *)(in_t9 + 0x72548);
    iVar2 = *(int *)(in_t9 + 0x72548);
    do {
      iVar3 = (**(code **)(in_t9 + 0x72a84))(iVar6);
      if (iVar3 != 0) goto LAB_2e241ae0;
      (**(code **)(in_t9 + 0x7304c))(iVar6,iVar1 + -0x4fd0,auStack_60);
      iVar3 = (**(code **)(in_t9 + 0x7389c))(auStack_60,iVar2 + -0x4fc8);
    } while (iVar3 == 0);
    iVar2 = *(int *)(in_t9 + 0x72548);
    iVar1 = (**(code **)(in_t9 + 0x73134))(auStack_60,0x3b);
    iVar1 = (**(code **)(in_t9 + 0x73370))(iVar1 + 1,iVar2 + -0x4fbc,auStack_70);
    if (iVar1 == 0) {
      (**(code **)(in_t9 + 0x72b20))
                (*(int *)(in_t9 + 0x72548) + -0x73a0,*(int *)(in_t9 + 0x72548) + -0x51fc,
                 *(int *)(in_t9 + 0x72548) + -0x4be4,0x103);
    }
    else {
      iVar2 = (**(code **)(in_t9 + 0x73370))(0,iVar2 + -0x4fbc,auStack_70);
      if (iVar2 != 0) {
        piVar5 = *(int **)(in_t9 + 0x7300c);
        iVar1 = (**(code **)(in_t9 + 0x72ee8))(iVar1,0,10);
        pcVar7 = *(code **)(in_t9 + 0x72ee8);
        *piVar5 = iVar1;
        uVar4 = (*pcVar7)(iVar2,0,10);
        iVar1 = *piVar5;
        **(undefined4 **)(in_t9 + 0x728a4) = uVar4;
        if (iVar1 == 0x556) {
          *piVar5 = 0x550;
        }
        (**(code **)(in_t9 + 0x72b20))(*(int *)(in_t9 + 0x72548) + -0x4fb8,*piVar5);
LAB_2e241ae0:
        (**(code **)(in_t9 + 0x73324))(iVar6);
LAB_2e241af0:
                    /* try { // try from 2e241af4 to 2e241afb has its CatchHandler @ 2e241c6c */
        (**(code **)(in_t9 + 0x72a1c))(&local_7c);
        (**(code **)(in_t9 + 0x72a1c))(&local_80);
        return 1;
      }
      (**(code **)(in_t9 + 0x72b20))
                (*(int *)(in_t9 + 0x72548) + -0x73a0,*(int *)(in_t9 + 0x72548) + -0x51fc,
                 *(int *)(in_t9 + 0x72548) + -0x4be4,0x106);
    }
  }
  (**(code **)(in_t9 + 0x72b20))(*(int *)(in_t9 + 0x72548) + -0x4ff8);
  goto LAB_2e241af0;
}

