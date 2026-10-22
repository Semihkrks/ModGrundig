
undefined4 OS_SC_Init(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined *puVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  
  puVar1 = PTR_DAT_2f578508;
  if (-1 < *(int *)(PTR_DAT_2f578508 + -0x7b14)) {
    return 1;
  }
  iVar5 = (*(code *)PTR_MsOS_CreateEventGroup_2f5785cc)
                    (PTR___DT_MIPS_BASE_ADDRESS_2f578514 + 0x7b1c);
  puVar2 = PTR_DAT_2f578508;
  *(int *)(PTR_DAT_2f578508 + -0x7b10) = iVar5;
  if (-1 < iVar5) {
    iVar5 = (*(code *)PTR_MsOS_CreateMutex_2f578618)
                      (1,PTR___DT_MIPS_BASE_ADDRESS_2f578514 + 0x7b28,1);
    puVar4 = PTR_os_SC_MutexID_2f578538;
    *(int *)PTR_os_SC_MutexID_2f578538 = iVar5;
    if (iVar5 < 0) {
      (*(code *)PTR_MsOS_DeleteMutex_2f578608)(iVar5);
      *(undefined4 *)puVar4 = 0xffffffff;
      return 0;
    }
    iVar5 = (*(code *)PTR_MsOS_CreateMutex_2f578618)
                      (1,PTR___DT_MIPS_BASE_ADDRESS_2f578514 + 0x7b34,1);
    puVar8 = (undefined4 *)PTR_os_SC_MutexID_TX_2f5785d0;
    *(int *)PTR_os_SC_MutexID_TX_2f5785d0 = iVar5;
    if (-1 < iVar5) {
      iVar5 = (*(code *)PTR_MsOS_CreateMutex_2f578618)
                        (1,PTR___DT_MIPS_BASE_ADDRESS_2f578514 + 0x7b44,1);
      puVar8 = (undefined4 *)PTR_os_SC_MutexID_SHM_2f5785e4;
      *(int *)PTR_os_SC_MutexID_SHM_2f5785e4 = iVar5;
      puVar3 = PTR__os_SC_ThreadActive_2f578530;
      if (-1 < iVar5) {
        puVar6 = PTR_DAT_2f578508 + -0x795c;
        *PTR__os_SC_ThreadActive_2f578530 = 1;
        iVar5 = (*(code *)PTR_MsOS_CreateTask_2f5785a8)
                          (PTR___DT_MIPS_BASE_ADDRESS_2f578514 + 0x7064,0,0xc,1,puVar6,0x1000,
                           PTR___DT_MIPS_BASE_ADDRESS_2f578514 + 0x7b54);
        *(int *)(puVar1 + -0x7b14) = iVar5;
        if (iVar5 < 0) {
          (*(code *)PTR_MsOS_DeleteEventGroup_2f57854c)(*(undefined4 *)(puVar2 + -0x7b10));
          puVar1 = PTR_MsOS_DeleteMutex_2f578608;
          uVar7 = *(undefined4 *)puVar4;
          *(undefined4 *)(puVar2 + -0x7b10) = 0xffffffff;
          (*(code *)puVar1)(uVar7);
          puVar1 = PTR_MsOS_DeleteMutex_2f578608;
          uVar7 = *puVar8;
          *(undefined4 *)puVar4 = 0xffffffff;
          (*(code *)puVar1)(uVar7);
          *puVar8 = 0xffffffff;
          *puVar3 = 0;
          return 0;
        }
        return 1;
      }
    }
    (*(code *)PTR_MsOS_DeleteMutex_2f578608)(iVar5);
    *puVar8 = 0xffffffff;
  }
  return 0;
}

