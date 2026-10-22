
/* MEvtHandle::SetTimer(unsigned long, unsigned long, EN_TIMER_MODE) */

undefined4 MEvtHandle::SetTimer(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  int iVar6;
  int *piVar7;
  undefined *puVar8;
  int iVar9;
  undefined *puVar10;
  int iVar11;
  undefined *puVar12;
  code *pcVar13;
  code *pcVar14;
  undefined1 auStack_e0 [4];
  undefined4 uStack_dc;
  undefined4 *puStack_d8;
  undefined4 *puStack_d4;
  undefined4 *puStack_d0;
  int iStack_cc;
  undefined4 uStack_c4;
  int iStack_c0;
  int iStack_bc;
  int iStack_b8;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = (*(code *)PTR_GetMTimerManager_2e2b460c)();
  if (iVar1 != 0) {
    uVar2 = (*(code *)PTR_AddTimer_2e2b41b0)(iVar1,param_1,param_2,param_3);
    return uVar2;
  }
  puVar5 = PTR_PTR_2e2b3908 + -0x73a0;
  puVar8 = PTR_PTR_2e2b3908 + -0x5d04;
  puVar10 = PTR_PTR_2e2b3908 + -0x5c6c;
  (*(code *)PTR_printf_2e2b3ee0)();
  puVar12 = PTR_abort_2e2b3bc8;
  (*(code *)PTR_abort_2e2b3bc8)();
  (**(code **)(puVar12 + 0x838ec))();
  iVar1 = (**(code **)(puVar12 + 0x845b4))();
  if (iVar1 != 0) {
    uVar2 = (**(code **)(puVar12 + 0x84410))(iVar1,puVar5,puVar8,puVar10);
    return uVar2;
  }
  iVar6 = *(int *)(puVar12 + 0x8389c) + -0x73a0;
  iVar9 = *(int *)(puVar12 + 0x8389c) + -0x5d04;
  iVar11 = *(int *)(puVar12 + 0x8389c) + -0x5c38;
  uVar2 = 0xbd;
  (**(code **)(puVar12 + 0x83e74))();
  pcVar13 = *(code **)(puVar12 + 0x83b5c);
  (*pcVar13)();
  (**(code **)(pcVar13 + 0x8381c))();
  iVar1 = (**(code **)(pcVar13 + 0x844e4))();
  if (iVar1 != 0) {
    (**(code **)(pcVar13 + 0x841dc))(iVar1,iVar6,iVar9,iVar11);
    return 1;
  }
  piVar7 = (int *)(*(int *)(pcVar13 + 0x837cc) + -0x73a0);
  (**(code **)(pcVar13 + 0x83da4))
            (piVar7,*(int *)(pcVar13 + 0x837cc) + -0x5d04,*(int *)(pcVar13 + 0x837cc) + -0x5c00,0xac
            );
  pcVar13 = *(code **)(pcVar13 + 0x83a8c);
  (*pcVar13)();
  pcVar14 = *(code **)(pcVar13 + 0x84c2c);
  *piVar7 = *(int *)(pcVar13 + 0x84650) + 8;
  uStack_c4 = uVar2;
  iStack_c0 = iVar6;
  iStack_bc = iVar9;
  iStack_b8 = iVar11;
  (*pcVar14)();
  (**(code **)(pcVar13 + 0x83748))();
  iVar1 = (**(code **)(pcVar13 + 0x84410))();
  if (iVar1 != 0) {
    (**(code **)(pcVar13 + 0x83ae8))(iVar1,piVar7);
    iStack_cc = 0;
    uStack_dc = 0;
    puStack_d8 = (undefined4 *)0x0;
    puStack_d4 = &uStack_dc;
    puStack_d0 = &uStack_dc;
    if (piVar7[3] == 0) {
      iVar1 = piVar7[6];
    }
    else {
      puStack_d8 = (undefined4 *)(**(code **)(pcVar13 + 0x84a60))(auStack_e0,piVar7[3],&uStack_dc);
      puVar4 = puStack_d8;
      do {
        puStack_d4 = puVar4;
        puVar4 = (undefined4 *)puStack_d4[2];
        puVar3 = puStack_d8;
      } while (puVar4 != (undefined4 *)0x0);
      do {
        puStack_d0 = puVar3;
        puVar3 = (undefined4 *)puStack_d0[3];
      } while (puVar3 != (undefined4 *)0x0);
      iVar1 = piVar7[6];
      iStack_cc = iVar1;
    }
    puVar4 = puStack_d4;
    if (iVar1 != 0) {
      for (; &uStack_dc != puVar4; puVar4 = (undefined4 *)(**(code **)(pcVar13 + 0x8406c))(puVar4))
      {
        if (puVar4[4] != 0) {
          (**(code **)(pcVar13 + 0x84340))(puVar4[4],piVar7);
        }
      }
      (**(code **)(pcVar13 + 0x848e8))(piVar7 + 1,piVar7[3]);
      pcVar14 = *(code **)(pcVar13 + 0x848e8);
      piVar7[5] = (int)(piVar7 + 2);
      piVar7[4] = (int)(piVar7 + 2);
      piVar7[3] = 0;
      piVar7[6] = 0;
      (*pcVar14)(auStack_e0,puStack_d8);
      puStack_d8 = (undefined4 *)0x0;
      iStack_cc = 0;
      puStack_d4 = &uStack_dc;
      puStack_d0 = &uStack_dc;
    }
    (**(code **)(pcVar13 + 0x848e8))(auStack_e0,puStack_d8);
    (**(code **)(pcVar13 + 0x848e8))(piVar7 + 1,piVar7[3]);
    uVar2 = (**(code **)(pcVar13 + 0x849cc))(piVar7);
    return uVar2;
  }
  iVar1 = *(int *)(pcVar13 + 0x836f8) + -0x73a0;
  (**(code **)(pcVar13 + 0x83cd0))
            (iVar1,*(int *)(pcVar13 + 0x836f8) + -0x5d04,*(int *)(pcVar13 + 0x836f8) + -0x5bc8,0x72)
  ;
  (**(code **)(pcVar13 + 0x839b8))();
  do {
    (**(code **)(pcVar13 + 0x84604))(piVar7 + 1);
    (**(code **)(pcVar13 + 0x849cc))(piVar7);
    (**(code **)(pcVar13 + 0x8398c))(iVar1);
  } while( true );
}

