
/* MW_DTV_CM_DVB_Customer::GetProgramInfoByIndex(unsigned long, _DVB_PROGRAMINFO&, unsigned char) */

undefined4 __thiscall
MW_DTV_CM_DVB_Customer::GetProgramInfoByIndex
          (MW_DTV_CM_DVB_Customer *this,ulong param_1,_DVB_PROGRAMINFO *param_2,uchar param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  iVar1 = (**(code **)(**(int **)(this + 4) + 8))();
  if (iVar1 == 0) {
    uVar4 = (**(code **)(**(int **)(this + 4) + 8))();
    uVar5 = 0x32a;
  }
  else {
    uVar2 = (**(code **)(**(int **)(this + 4) + 0x50))();
    if (uVar2 <= param_1) {
      printf("MW_DTV_CM_DVB::GetProgramInfoByIndex Index(%ld) too big\n",param_1);
      memset(param_2,0,0x1a4);
      iVar1 = (**(code **)(**(int **)(this + 4) + 0xc))();
      if (iVar1 != 0) {
        return 0;
      }
      uVar4 = (**(code **)(**(int **)(this + 4) + 0xc))();
      printf("CHECK RESULT FAIL: %s %s %d RESULT 0x%lx\n",
             "./middleware/src/MW_DTV_CM_DVB_Customer.cpp",
             "virtual BOOL MW_DTV_CM_DVB_Customer::GetProgramInfoByIndex(U32, ST_DVB_PROGRAMINFO&, BOOL)"
             ,0x330,uVar4);
      return 0;
    }
    puVar9 = (undefined4 *)0x0;
    if (param_3 == '\x01') {
      puVar9 = (undefined4 *)(**(code **)(**(int **)(this + 4) + 0x3c))(*(int **)(this + 4),param_1)
      ;
    }
    else {
      iVar1 = 0;
      for (uVar2 = 0; uVar3 = (**(code **)(**(int **)(this + 4) + 0x50))(), uVar2 < uVar3;
          uVar2 = uVar2 + 1) {
        puVar9 = (undefined4 *)(**(code **)(**(int **)(this + 4) + 0x3c))(*(int **)(this + 4),uVar2)
        ;
        if (puVar9 == (undefined4 *)0x0) {
          printf("ASSERT FAIL: %s %s %d\n","./middleware/src/MW_DTV_CM_DVB_Customer.cpp",
                 "virtual BOOL MW_DTV_CM_DVB_Customer::GetProgramInfoByIndex(U32, ST_DVB_PROGRAMINFO&, BOOL)"
                 ,0x34f);
                    /* WARNING: Subroutine does not return */
          abort();
        }
        if (*(char *)((int)puVar9 + 0x11) == '\0') {
          iVar1 = iVar1 + (uint)(*(char *)((int)puVar9 + 0xf) == '\x01');
        }
        if (iVar1 - 1U == param_1) goto LAB_2e1779e4;
      }
    }
    if (puVar9 != (undefined4 *)0x0) {
LAB_2e1779e4:
      puVar8 = puVar9 + 0x68;
      do {
        uVar4 = *puVar9;
        uVar5 = puVar9[1];
        uVar6 = puVar9[2];
        uVar7 = puVar9[3];
        puVar9 = puVar9 + 4;
        *(undefined4 *)param_2 = uVar4;
        *(undefined4 *)(param_2 + 4) = uVar5;
        *(undefined4 *)(param_2 + 8) = uVar6;
        *(undefined4 *)(param_2 + 0xc) = uVar7;
        param_2 = param_2 + 0x10;
      } while (puVar9 != puVar8);
      *(undefined4 *)param_2 = *puVar9;
      iVar1 = (**(code **)(**(int **)(this + 4) + 0xc))();
      if (iVar1 != 0) {
        return 1;
      }
      uVar4 = (**(code **)(**(int **)(this + 4) + 0xc))();
      printf("CHECK RESULT FAIL: %s %s %d RESULT 0x%lx\n",
             "./middleware/src/MW_DTV_CM_DVB_Customer.cpp",
             "virtual BOOL MW_DTV_CM_DVB_Customer::GetProgramInfoByIndex(U32, ST_DVB_PROGRAMINFO&, BOOL)"
             ,0x35b,uVar4);
      return 0;
    }
    uVar4 = 0;
    uVar5 = 0x357;
  }
  printf("CHECK_RESULT_UNLOCK FAIL: %s %s %d RESULT 0x%lx\n",
         "./middleware/src/MW_DTV_CM_DVB_Customer.cpp",
         "virtual BOOL MW_DTV_CM_DVB_Customer::GetProgramInfoByIndex(U32, ST_DVB_PROGRAMINFO&, BOOL)"
         ,uVar5,uVar4);
  (**(code **)(**(int **)(this + 4) + 0xc))();
  return 0;
}

