
void MApi_MPlayer_Initialize(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined1 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  code *pcVar15;
  
  puVar2 = PTR_semget_0003e474;
  puVar7 = PTR_DAT_0003e278;
  PTR_DAT_0003e278[-0x14d0] = 0;
  puVar1 = PTR_DAT_0003e278;
  *(undefined4 *)(puVar7 + -0x14ac) = 0;
  *(undefined4 *)(puVar7 + -0x14b4) = 0;
  *(undefined4 *)(puVar7 + -0x14b0) = 0;
  puVar7[-0x14ce] = 0;
  puVar7[-0x14cf] = 0;
  uVar3 = (*(code *)puVar2)(0x5500aabb,3,0x3b6);
  puVar7 = PTR_DAT_0003e278;
  iVar5 = *(int *)(puVar1 + -0x1e04);
  *(undefined4 *)(PTR_DAT_0003e278 + -0x1da0) = uVar3;
  if (1 < iVar5) {
    (*(code *)PTR_printf_0003e328)(PTR_LAB_0003e28c + 0x423c,uVar3);
  }
  puVar2 = PTR_DAT_0003e278;
  if (*(int *)(puVar7 + -0x1da0) == -1) {
    if (*(int *)(puVar1 + -0x1e04) < 1) {
      return;
    }
    puVar7 = PTR_LAB_0003e28c + 0x4248;
LAB_0001f784:
                    /* WARNING: Could not recover jumptable at 0x0001f790. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_puts_0003e314)(puVar7);
    return;
  }
  (*(code *)PTR_semctl_0003e440)(*(int *)(puVar7 + -0x1da0),0,0x10,1);
  (*(code *)PTR_semctl_0003e440)(*(undefined4 *)(puVar2 + -0x1da0),1,0x10,1);
  (*(code *)PTR_semctl_0003e440)(*(undefined4 *)(puVar2 + -0x1da0),2,0x10,1);
  *(undefined4 *)(PTR_DAT_0003e278 + -0x1248) = 0x10000;
  puVar7 = PTR_DAT_0003e278;
  *(undefined4 *)(PTR_DAT_0003e278 + -0x1db8) = 500;
  puVar1 = PTR_DAT_0003e278;
  *(undefined4 *)(puVar7 + -0x1db0) = 1;
  puVar2 = PTR_DAT_0003e278;
  *(undefined4 *)(puVar1 + -0x1db4) = 0x20000;
  puVar1 = PTR_DAT_0003e278;
  *(undefined4 *)(puVar2 + -0x1de4) = 1;
  *(undefined4 *)(puVar1 + -0x1dac) = 5;
  puVar1 = PTR_DAT_0003e278;
  PTR_DAT_0003e278[-0x12f7] = 0;
  puVar1[-0x1100] = 0;
  puVar1 = PTR_DAT_0003e278;
  *(undefined4 *)(puVar7 + -0x13f0) = 0;
  *(undefined4 *)(puVar7 + -0x13f4) = 0;
  puVar2 = PTR_DAT_0003e278;
  puVar9 = puVar1 + -0x1360;
  *(undefined4 *)(puVar7 + -0x13f8) = 0;
  iVar5 = 0;
  do {
    puVar4 = (undefined4 *)(puVar1 + iVar5 + -0x13d0);
    puVar6 = (undefined4 *)(puVar2 + iVar5 + -0x13b8);
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
    *puVar4 = 0;
    puVar4[1] = 0;
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar8 = PTR_pfCmdCbFunc_0003e35c;
    puVar7 = PTR_DAT_0003e278;
    iVar5 = iVar5 + 8;
  } while (puVar2 + -0x135d != puVar9);
  puVar4 = (undefined4 *)(PTR_DAT_0003e278 + -0x147c);
  iVar5 = 0;
  do {
    puVar6 = (undefined4 *)(puVar8 + iVar5);
    iVar10 = iVar5 + -0x1de0;
    iVar5 = iVar5 + 4;
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4[4] = 0;
    puVar4[5] = 0;
    puVar4[6] = 0;
    puVar4[7] = 0;
    puVar4[8] = 0;
    puVar4[9] = 0;
    puVar4[10] = 0;
    *puVar6 = 0;
    *(undefined4 *)(puVar7 + iVar10) = 1;
    puVar4 = puVar4 + 0xb;
  } while (iVar5 != 0xc);
  iVar5 = (*(code *)PTR_malloc_0003e400)(0x600000);
  *(int *)(PTR_DAT_0003e278 + -0x14a4) = iVar5;
  if (iVar5 == 0) {
    puVar7 = PTR_LAB_0003e28c + 0x4260;
    goto LAB_0001f784;
  }
  iVar5 = (*(code *)PTR_malloc_0003e400)(*(undefined4 *)(PTR_DAT_0003e278 + -0x1dec));
  puVar7 = PTR_DAT_0003e278;
  *(int *)(PTR_DAT_0003e278 + -0x123c) = iVar5;
  *(int *)(puVar7 + -0x1240) = iVar5;
  puVar7 = PTR_DAT_0003e278;
  if (iVar5 == 0) {
    puVar7 = PTR_LAB_0003e28c + 0x4298;
    goto LAB_0001f784;
  }
  iVar5 = (*(code *)PTR_pthread_mutexattr_init_0003e354)(PTR_DAT_0003e278 + -0x10c8);
  if (iVar5 != 0) {
    return;
  }
  iVar5 = (*(code *)PTR_pthread_mutexattr_settype_0003e444)(puVar7 + -0x10c8,1);
  if (iVar5 != 0) {
    return;
  }
  iVar5 = (*(code *)PTR_pthread_mutex_init_0003e388)(PTR_DAT_0003e278 + -0x1640,puVar7 + -0x10c8);
  if (iVar5 != 0) {
    return;
  }
  iVar5 = (*(code *)PTR_pthread_mutex_init_0003e388)(PTR_DAT_0003e278 + -0x1230,0);
  if (iVar5 != 0) {
    return;
  }
  iVar5 = (*(code *)PTR_pthread_cond_init_0003e36c)(PTR_DAT_0003e278 + -0x1218,0);
  if (iVar5 != 0) {
    return;
  }
  iVar5 = (*(code *)PTR_pthread_cond_init_0003e36c)(PTR_DAT_0003e278 + -0x11b0,0);
  if (iVar5 != 0) {
    return;
  }
  iVar5 = (*(code *)PTR_pthread_cond_init_0003e36c)(PTR_DAT_0003e278 + -0x1180,0);
  if (iVar5 != 0) {
    return;
  }
  iVar5 = (*(code *)PTR_pthread_mutex_init_0003e388)(PTR_DAT_0003e278 + -0x114c,0);
  if (iVar5 != 0) {
    return;
  }
  iVar5 = (*(code *)PTR_pthread_cond_init_0003e36c)(PTR_DAT_0003e278 + -0x1130,0);
  puVar7 = PTR_DAT_0003e278;
  if (iVar5 != 0) {
    return;
  }
  if (*(int *)(PTR_DAT_0003e278 + -0x1650) != 0) {
LAB_0001fa54:
    puVar7 = PTR_DAT_0003e278;
    PTR_DAT_0003e278[-0x114e] = 0;
    puVar7[-0x10d6] = 0;
    *(undefined4 *)(puVar7 + -0x1dc4) = 0;
    puVar7[-0x12f8] = 0;
    puVar7[-0x12f5] = 0;
    puVar7[-0x1150] = 0;
    puVar7[-0x114f] = 0;
    puVar7[-0x10d8] = 0;
    puVar7[-0x10d7] = 0;
    *(undefined4 *)(puVar7 + -0x1dcc) = 0;
    *(undefined4 *)(puVar7 + -0x1dc8) = 0;
    return;
  }
  iVar5 = (*(code *)PTR_operator_new_0003e330)(0x40,PTR_nothrow_0003e450);
  puVar2 = PTR_printf_0003e328;
  puVar1 = PTR_LAB_0003e28c;
  if (iVar5 != 0) {
    (*(code *)PTR_MSrv_MM_PlayerInterface_0003e2c0)(iVar5);
    *(int *)(puVar7 + -0x1650) = iVar5;
    iVar5 = (*(code *)PTR_MM_Initialize_0003e468)(iVar5,0);
    if (iVar5 != 0) {
      (*(code *)PTR_puts_0003e314)(PTR_LAB_0003e28c + 0x42d0);
    }
    goto LAB_0001fa54;
  }
  *(undefined4 *)(puVar7 + -0x1650) = 0;
  puVar8 = puVar1 + 0x31c8;
  (*(code *)puVar2)(puVar8,puVar1 + 0x31e0,puVar1 + 0x4f80,0x633);
  (*(code *)PTR_abort_0003e2cc)();
  (*(code *)PTR_operator_delete_0003e3e0)(0,PTR_nothrow_0003e450);
  puVar7 = PTR__Unwind_Resume_0003e2c8;
  (*(code *)PTR__Unwind_Resume_0003e2c8)(puVar8);
  iVar11 = *(int *)(puVar7 + 0x1e6e4);
  iVar5 = *(int *)(puVar7 + 0x1e6e4);
  iVar10 = *(int *)(iVar11 + -0x12e4);
  *(undefined1 *)(iVar5 + -0x14ce) = 1;
  *(undefined1 *)(iVar5 + -0x14d0) = 1;
  *(undefined1 *)(iVar5 + -0x14cf) = 1;
  if (iVar10 == 0) {
    iVar10 = *(int *)(puVar7 + 0x1e6e4);
    iVar14 = *(int *)(puVar7 + 0x1e6f8);
LAB_0001fbec:
    pcVar15 = *(code **)(puVar7 + 0x1e81c);
    if (*(int *)(iVar11 + -0x12e0) == 0) goto LAB_0001fbfc;
LAB_0001ffa4:
    (*pcVar15)(iVar10 + -0x1230,iVar14 + 0x4fa0,0x559);
    iVar5 = *(int *)(puVar7 + 0x1e6e4);
    pcVar15 = *(code **)(puVar7 + 0x1e8f8);
    *(undefined4 *)(*(int *)(puVar7 + 0x1e6e4) + -0x1dc0) = 0xe;
    (*pcVar15)(iVar5 + -0x11b0);
    (**(code **)(puVar7 + 0x1e888))(iVar10 + -0x1230);
    iVar5 = (**(code **)(puVar7 + 0x1e798))(*(undefined4 *)(iVar11 + -0x12e0),0);
    if (iVar5 != 0) {
      (**(code **)(puVar7 + 0x1e794))(*(int *)(puVar7 + 0x1e6f8) + 0x3798);
      goto LAB_0001fbfc;
    }
    *(undefined4 *)(iVar11 + -0x12e0) = 0;
    if (*(int *)(iVar11 + -0x12dc) != 0) {
      pcVar15 = *(code **)(puVar7 + 0x1e81c);
      goto LAB_00020010;
    }
LAB_0001fc08:
    iVar12 = *(int *)(puVar7 + 0x1e6e4);
  }
  else {
    iVar10 = *(int *)(puVar7 + 0x1e6e4);
    iVar14 = *(int *)(puVar7 + 0x1e6f8);
    (**(code **)(puVar7 + 0x1e81c))(iVar10 + -0x1230,iVar14 + 0x4fa0,0x53a);
    iVar5 = *(int *)(puVar7 + 0x1e6e4);
    pcVar15 = *(code **)(puVar7 + 0x1e8f8);
    *(undefined4 *)(*(int *)(puVar7 + 0x1e6e4) + -0x1dbc) = 0xe;
    (*pcVar15)(iVar5 + -0x1180);
    (**(code **)(puVar7 + 0x1e888))(iVar10 + -0x1230);
    iVar5 = (**(code **)(puVar7 + 0x1e798))(*(undefined4 *)(iVar11 + -0x12e4),0);
    if (iVar5 == 0) {
      *(undefined4 *)(iVar11 + -0x12e4) = 0;
    }
    else {
      (**(code **)(puVar7 + 0x1e794))(*(int *)(puVar7 + 0x1e6f8) + 0x4300);
    }
    iVar12 = *(int *)(puVar7 + 0x1e6e4);
    (**(code **)(puVar7 + 0x1e81c))(iVar12 + -0x114c,iVar14 + 0x4fa0,0x548);
    iVar5 = *(int *)(puVar7 + 0x1e6e4);
    pcVar15 = *(code **)(puVar7 + 0x1e8f8);
    *(undefined1 *)(*(int *)(puVar7 + 0x1e6e4) + -0x1134) = 1;
    (*pcVar15)(iVar5 + -0x1130);
    iVar13 = *(int *)(puVar7 + 0x1e6e4);
    (**(code **)(puVar7 + 0x1e888))(iVar12 + -0x114c);
    iVar5 = (**(code **)(puVar7 + 0x1e798))(*(undefined4 *)(iVar13 + -0x12d8),0);
    if (iVar5 != 0) {
      (**(code **)(puVar7 + 0x1e794))(*(int *)(puVar7 + 0x1e6f8) + 0x433c);
      goto LAB_0001fbec;
    }
    iVar5 = *(int *)(iVar11 + -0x12e0);
    *(undefined4 *)(iVar13 + -0x12d8) = 0;
    if (iVar5 != 0) {
      pcVar15 = *(code **)(puVar7 + 0x1e81c);
      goto LAB_0001ffa4;
    }
LAB_0001fbfc:
    pcVar15 = *(code **)(puVar7 + 0x1e81c);
    if (*(int *)(iVar11 + -0x12dc) == 0) goto LAB_0001fc08;
LAB_00020010:
    (*pcVar15)(iVar10 + -0x1230,iVar14 + 0x4fa0,0x56a);
    iVar12 = *(int *)(puVar7 + 0x1e6e4);
    pcVar15 = *(code **)(puVar7 + 0x1e8f8);
    *(undefined4 *)(*(int *)(puVar7 + 0x1e6e4) + -0x1dd0) = 0xe;
    (*pcVar15)(iVar12 + -0x1218);
    (**(code **)(puVar7 + 0x1e888))(iVar10 + -0x1230);
    iVar5 = (**(code **)(puVar7 + 0x1e798))(*(undefined4 *)(iVar11 + -0x12dc),0);
    if (iVar5 == 0) {
      *(undefined4 *)(iVar11 + -0x12dc) = 0;
    }
    else {
      (**(code **)(puVar7 + 0x1e794))(*(int *)(puVar7 + 0x1e6f8) + 0x4378);
    }
  }
  iVar11 = *(int *)(puVar7 + 0x1e6e4);
  iVar5 = *(int *)(puVar7 + 0x1e6e4);
  (**(code **)(puVar7 + 0x1e81c))(iVar11 + -0x1640,iVar14 + 0x4fa0,0x579);
  if (*(int *)(iVar5 + -0x10dc) != 0) {
    (**(code **)(puVar7 + 0x1e7d0))();
    *(undefined4 *)(iVar5 + -0x10dc) = 0;
  }
  iVar5 = *(int *)(puVar7 + 0x1e6e4);
  if (*(int *)(iVar5 + -0x10e4) != 0) {
    (**(code **)(puVar7 + 0x1e7d0))();
    *(undefined4 *)(iVar5 + -0x10e4) = 0;
  }
  iVar5 = *(int *)(puVar7 + 0x1e6e4);
  if (*(int *)(iVar5 + -0x14a4) != 0) {
    (**(code **)(puVar7 + 0x1e7d0))();
    *(undefined4 *)(iVar5 + -0x14a4) = 0;
  }
  iVar5 = *(int *)(puVar7 + 0x1e6e4);
  if (*(int *)(iVar5 + -0x1240) != 0) {
    (**(code **)(puVar7 + 0x1e7d0))();
    *(undefined4 *)(iVar5 + -0x1240) = 0;
    *(undefined4 *)(*(int *)(puVar7 + 0x1e6e4) + -0x123c) = 0;
  }
  (**(code **)(puVar7 + 0x1e888))(iVar11 + -0x1640);
  (**(code **)(puVar7 + 0x1e8f4))(iVar10 + -0x1230);
  iVar5 = (**(code **)(puVar7 + 0x1e70c))(iVar12 + -0x1218);
  if (iVar5 != 0) {
    pcVar15 = *(code **)(puVar7 + 0x1e794);
    iVar5 = *(int *)(puVar7 + 0x1e6f8) + 0x31c8;
    iVar10 = *(int *)(puVar7 + 0x1e6f8) + 0x31e0;
    uVar3 = 0x593;
    goto LAB_000200f0;
  }
  iVar5 = (**(code **)(puVar7 + 0x1e70c))(*(int *)(puVar7 + 0x1e6e4) + -0x11b0);
  if (iVar5 != 0) goto LAB_00020108;
  iVar5 = (**(code **)(puVar7 + 0x1e7bc))(*(int *)(puVar7 + 0x1e6e4) + -0x10c8);
  if (iVar5 == 0) {
LAB_0001fd60:
    pcVar15 = *(code **)(puVar7 + 0x1e8f4);
  }
  else {
    pcVar15 = *(code **)(puVar7 + 0x1e8f4);
    if (iVar5 != 0x91) {
      uVar3 = (**(code **)(puVar7 + 0x1e790))();
      (**(code **)(puVar7 + 0x1e794))
                (*(int *)(puVar7 + 0x1e6f8) + 0x43b4,*(int *)(puVar7 + 0x1e6f8) + 0x31e0,0x598,
                 *(int *)(puVar7 + 0x1e6f8) + 0x43d0,uVar3);
      goto LAB_0001fd60;
    }
  }
  iVar5 = (*pcVar15)(iVar11 + -0x1640);
  if ((iVar5 != 0) && (iVar5 != 0x91)) {
    uVar3 = (**(code **)(puVar7 + 0x1e790))();
    (**(code **)(puVar7 + 0x1e794))
              (*(int *)(puVar7 + 0x1e6f8) + 0x43b4,*(int *)(puVar7 + 0x1e6f8) + 0x31e0,0x599,
               *(int *)(puVar7 + 0x1e6f8) + 0x4400,uVar3);
  }
  iVar5 = (**(code **)(puVar7 + 0x1e70c))(*(int *)(puVar7 + 0x1e6e4) + -0x1180);
  if (iVar5 == 0) {
    (**(code **)(puVar7 + 0x1e8f4))(*(int *)(puVar7 + 0x1e6e4) + -0x114c);
    iVar5 = (**(code **)(puVar7 + 0x1e70c))(*(int *)(puVar7 + 0x1e6e4) + -0x1130);
    if (iVar5 == 0) {
      iVar5 = *(int *)(puVar7 + 0x1e6e4);
      if (*(int *)(iVar5 + -0x1da0) != -1) {
        (**(code **)(puVar7 + 0x1e8ac))(*(int *)(iVar5 + -0x1da0),0,0);
        (**(code **)(puVar7 + 0x1e8ac))(*(undefined4 *)(iVar5 + -0x1da0),1,0);
        (**(code **)(puVar7 + 0x1e8ac))(*(undefined4 *)(iVar5 + -0x1da0),2,0);
        *(undefined4 *)(iVar5 + -0x1da0) = 0xffffffff;
      }
      iVar5 = *(int *)(puVar7 + 0x1e6e4);
      if (*(int *)(iVar5 + -0x1650) != 0) {
        (**(code **)(puVar7 + 0x1e75c))();
        if (*(int **)(iVar5 + -0x1650) != (int *)0x0) {
          (**(code **)(**(int **)(iVar5 + -0x1650) + 8))();
        }
        *(undefined4 *)(iVar5 + -0x1650) = 0;
      }
      return;
    }
    pcVar15 = *(code **)(puVar7 + 0x1e794);
    iVar5 = *(int *)(puVar7 + 0x1e6f8) + 0x31c8;
    iVar10 = *(int *)(puVar7 + 0x1e6f8) + 0x31e0;
    uVar3 = 0x59d;
  }
  else {
    pcVar15 = *(code **)(puVar7 + 0x1e794);
    iVar5 = *(int *)(puVar7 + 0x1e6f8) + 0x31c8;
    iVar10 = *(int *)(puVar7 + 0x1e6f8) + 0x31e0;
    uVar3 = 0x59a;
  }
LAB_000200f0:
  do {
    (*pcVar15)(iVar5,iVar10,iVar14 + 0x4fa0,uVar3);
    (**(code **)(puVar7 + 0x1e738))();
LAB_00020108:
    pcVar15 = *(code **)(puVar7 + 0x1e794);
    iVar5 = *(int *)(puVar7 + 0x1e6f8) + 0x31c8;
    iVar10 = *(int *)(puVar7 + 0x1e6f8) + 0x31e0;
    uVar3 = 0x596;
  } while( true );
}

