
/* unsigned char MW_DTV_CM_DVB::_GetNextProgramInfo<EN_SERVICE_QUERY_TYPE>(unsigned char, unsigned
   short, _DVB_PROGRAMINFO&, EN_SERVICE_QUERY_TYPE) */

uchar __thiscall
MW_DTV_CM_DVB::_GetNextProgramInfo<EN_SERVICE_QUERY_TYPE>
          (MW_DTV_CM_DVB *this,undefined1 param_1,undefined2 param_2,undefined4 *param_3,
          undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  
  iVar1 = (**(code **)(**(int **)(this + 4) + 8))();
  if (iVar1 == 0) {
    uVar3 = (**(code **)(**(int **)(this + 4) + 8))(*(int **)(this + 4),param_1);
    uVar5 = 0x4e0;
  }
  else {
    puVar2 = (undefined4 *)
             (**(code **)(**(int **)(this + 4) + 0x40))(*(int **)(this + 4),param_1,param_2);
    if (puVar2 != (undefined4 *)0x0) {
      do {
        puVar2 = (undefined4 *)
                 (**(code **)(**(int **)(this + 4) + 0x34))(*(int **)(this + 4),puVar2);
        if (puVar2 == (undefined4 *)0x0) {
          uVar10 = 0;
          goto LAB_2d507470;
        }
        iVar1 = (**(code **)(*(int *)this + 0x9c))(this,puVar2);
      } while ((iVar1 == 0) ||
              (iVar1 = (**(code **)(*(int *)this + 0xb8))(this,puVar2,param_5), iVar1 == 0));
      goto LAB_2d507314;
    }
    uVar3 = 0;
    uVar5 = 0x4e3;
  }
  printf("CHECK_RESULT_UNLOCK FAIL: %s %s %d RESULT 0x%lx\n",&UNK_2d59ac70,&UNK_2d59bbc4,uVar5,uVar3
        );
  (**(code **)(**(int **)(this + 4) + 0xc))();
  return '\0';
  while( true ) {
    while( true ) {
      uVar10 = uVar11 + 1;
      puVar2 = (undefined4 *)(**(code **)(**(int **)(this + 4) + 0x3c))(*(int **)(this + 4),uVar11);
      if (puVar2 == (undefined4 *)0x0) {
        printf("[%s][%d] No match Program\n",&UNK_2d59bbc4,0x511);
        piVar7 = *(int **)(this + 4);
        goto LAB_2d50754c;
      }
      iVar1 = (**(code **)(*(int *)this + 0x9c))(this,puVar2);
      if (iVar1 != 0) break;
      puVar2 = (undefined4 *)0x0;
      uVar4 = (**(code **)(**(int **)(this + 4) + 0x50))();
      uVar11 = uVar10;
      if (uVar4 <= uVar10) goto LAB_2d5074f8;
    }
    iVar1 = (**(code **)(*(int *)this + 0xb8))(this,puVar2,param_5);
    if (iVar1 != 0) break;
LAB_2d507470:
    uVar4 = (**(code **)(**(int **)(this + 4) + 0x50))();
    uVar11 = uVar10;
    if (uVar4 <= uVar10) {
LAB_2d5074f8:
      if (puVar2 == (undefined4 *)0x0) {
        piVar7 = *(int **)(this + 4);
LAB_2d50754c:
        puVar2 = (undefined4 *)(**(code **)(*piVar7 + 0x40))(piVar7,param_1,param_2);
        puts("MW_DTV_CM_DVB::GetNextProgramInfo() No match Program");
        if (puVar2 == (undefined4 *)0x0) {
          iVar1 = (**(code **)(**(int **)(this + 4) + 0xc))();
          if (iVar1 != 0) {
            return '\0';
          }
          uVar3 = (**(code **)(**(int **)(this + 4) + 0xc))();
          printf("CHECK RESULT FAIL: %s %s %d RESULT 0x%lx\n",&UNK_2d59ac70,&UNK_2d59bbc4,0x521,
                 uVar3);
          return '\0';
        }
      }
      break;
    }
  }
LAB_2d507314:
  puVar9 = puVar2 + 0x68;
  do {
    uVar3 = *puVar2;
    uVar5 = puVar2[1];
    uVar6 = puVar2[2];
    uVar8 = puVar2[3];
    puVar2 = puVar2 + 4;
    *param_3 = uVar3;
    param_3[1] = uVar5;
    param_3[2] = uVar6;
    param_3[3] = uVar8;
    param_3 = param_3 + 4;
  } while (puVar2 != puVar9);
  *param_3 = *puVar2;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0xc))();
  if (iVar1 != 0) {
    return '\x01';
  }
  uVar3 = (**(code **)(**(int **)(this + 4) + 0xc))();
  printf("CHECK RESULT FAIL: %s %s %d RESULT 0x%lx\n",&UNK_2d59ac70,&UNK_2d59bbc4,0x526,uVar3);
  return '\0';
}

