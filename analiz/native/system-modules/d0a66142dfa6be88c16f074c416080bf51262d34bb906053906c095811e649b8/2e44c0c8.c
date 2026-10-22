
int MMSDK_Initialize(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  code *pcVar9;
  
  puVar6 = PTR_DAT_2e4b25b8;
  if (3 < *(int *)(PTR_DAT_2e4b25b8 + 0x2584)) {
    (*(code *)PTR_printf_2e4b32c0)
              (PTR_LAB_2e4b25c8 + 0x7bf8,PTR_s_e___Done__2e49ffe4_0x1c_2e4b25ec + -0x7e10,
               *(undefined4 *)(PTR_DAT_2e4b25b8 + 0x3c34));
  }
  if (*(int *)(puVar6 + 0x3c34) != 0) {
    *(int *)(PTR_DAT_2e4b25b8 + 0x3c34) = *(int *)(puVar6 + 0x3c34) + 1;
    return 1;
  }
  puVar2 = (undefined4 *)(PTR_DAT_2e4b25b8 + 0x3bc4);
  puVar4 = (undefined4 *)(PTR_DAT_2e4b25b8 + 0x3c14);
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar1 = PTR_DAT_2e4b25b8;
    puVar2 = puVar2 + 2;
  } while (puVar4 != puVar2);
  (*(code *)PTR_PT_MsOS_MemoryInit_2e4b3484)(0,0);
  if (*(int *)(puVar1 + 0x3c2c) == 0) {
    iVar3 = (*(code *)PTR_PT_Thread_MutexInit_2e4b3188)(puVar1 + 0x3c2c);
    if (iVar3 == 0) {
      *(undefined4 *)(puVar1 + 0x3c2c) = 0;
    }
  }
  (*(code *)PTR_FUN_2e4b2a48)();
  (*(code *)PTR_FUN_2e4b2738)();
  iVar3 = (*(code *)PTR_PT_MsOS_AllocateMemory_2e4b32e0)(0xc);
  pcVar9 = (code *)PTR_printf_2e4b32c0;
  puVar8 = PTR_s_e___Done__2e49ffe4_0x1c_2e4b25ec;
  puVar7 = PTR_LAB_2e4b25c8;
  puVar1 = PTR_DAT_2e4b25b8;
  if (iVar3 == 0) {
    *(undefined4 *)(PTR_DAT_2e4b25b8 + 0x3c20) = 0;
    puVar6 = puVar7 + 0x4e54;
    puVar7 = puVar7 + 0x7c68;
    puVar8 = puVar8 + -0x7e10;
    uVar5 = 0x1f8;
  }
  else {
    (*(code *)PTR_LAB_2e4b2a4c)(iVar3);
    *(int *)(puVar1 + 0x3c20) = iVar3;
    iVar3 = (*(code *)PTR_LAB_2e4b2a50)(iVar3);
    if (iVar3 == 0) {
      if (0 < *(int *)(puVar6 + 0x2584)) {
        (*(code *)PTR_printf_2e4b32c0)
                  (PTR_LAB_2e4b25c8 + 0x7c20,PTR_s_e___Done__2e49ffe4_0x1c_2e4b25ec + -0x7e10,0x1fc,
                   PTR_LAB_2e4b25c8 + 0x7c50);
      }
      puVar7 = PTR_DAT_2e4b25b8;
      if (*(int *)(puVar1 + 0x3c20) != 0) {
        (*(code *)PTR_LAB_2e4b2a10)();
        (*(code *)PTR_PT_MsOS_FreeMemory_2e4b32b0)(*(undefined4 *)(puVar7 + 0x3c20));
        *(undefined4 *)(puVar7 + 0x3c20) = 0;
      }
    }
    iVar3 = (*(code *)PTR_PT_MsOS_AllocateMemory_2e4b32e0)(0x68);
    puVar1 = PTR_DAT_2e4b25b8;
    if (iVar3 == 0) goto LAB_2e44c430;
    (*(code *)PTR_LAB_2e4b2a54)(iVar3);
    *(int *)(puVar1 + 0x3c18) = iVar3;
    iVar3 = (*(code *)PTR_LAB_2e4b2a58)(iVar3);
    if (iVar3 == 0) {
      if (0 < *(int *)(puVar6 + 0x2584)) {
        (*(code *)PTR_printf_2e4b32c0)
                  (PTR_LAB_2e4b25c8 + 0x7c20,PTR_s_e___Done__2e49ffe4_0x1c_2e4b25ec + -0x7e10,0x205,
                   PTR_LAB_2e4b25c8 + 0x7c58);
      }
      puVar7 = PTR_DAT_2e4b25b8;
      if (*(int *)(puVar1 + 0x3c18) != 0) {
        (*(code *)PTR_LAB_2e4b2a18)();
        (*(code *)PTR_PT_MsOS_FreeMemory_2e4b32b0)(*(undefined4 *)(puVar7 + 0x3c18));
        *(undefined4 *)(puVar7 + 0x3c18) = 0;
      }
    }
    iVar3 = (*(code *)PTR_PT_MsOS_AllocateMemory_2e4b32e0)(0x30);
    pcVar9 = (code *)PTR_printf_2e4b32c0;
    puVar8 = PTR_s_e___Done__2e49ffe4_0x1c_2e4b25ec;
    puVar7 = PTR_LAB_2e4b25c8;
    puVar1 = PTR_DAT_2e4b25b8;
    if (iVar3 != 0) {
      (*(code *)PTR_LAB_2e4b2a5c)(iVar3);
      *(int *)(puVar1 + 0x3c30) = iVar3;
      iVar3 = (*(code *)PTR_LAB_2e4b2a60)(iVar3);
      if (iVar3 == 0) {
        if (0 < *(int *)(puVar6 + 0x2584)) {
          (*(code *)PTR_printf_2e4b32c0)
                    (PTR_LAB_2e4b25c8 + 0x7c20,PTR_s_e___Done__2e49ffe4_0x1c_2e4b25ec + -0x7e10,
                     0x20f,PTR_LAB_2e4b25c8 + 0x7c60);
        }
        puVar7 = PTR_DAT_2e4b25b8;
        if (*(int *)(puVar1 + 0x3c30) != 0) {
          (*(code *)PTR_LAB_2e4b2a08)();
          (*(code *)PTR_PT_MsOS_FreeMemory_2e4b32b0)(*(undefined4 *)(puVar7 + 0x3c30));
          *(undefined4 *)(puVar7 + 0x3c30) = 0;
        }
      }
      puVar1 = PTR_MMSDK_DebugMSGLevel_2e4b3360;
      uVar5 = *(undefined4 *)(puVar6 + 0x2584);
      *(undefined4 *)(PTR_DAT_2e4b25b8 + 0x3c28) = 0;
      (*(code *)puVar1)(uVar5);
      *(undefined4 *)(puVar6 + 0x3c34) = 1;
      return iVar3;
    }
    *(undefined4 *)(PTR_DAT_2e4b25b8 + 0x3c30) = 0;
    puVar6 = puVar7 + 0x4e54;
    puVar7 = puVar7 + 0x7c68;
    puVar8 = puVar8 + -0x7e10;
    uVar5 = 0x20b;
  }
  do {
    (*pcVar9)(puVar6,puVar7,puVar8,uVar5);
    (*(code *)PTR_abort_2e4b34a8)();
LAB_2e44c430:
    pcVar9 = (code *)PTR_printf_2e4b32c0;
    puVar8 = PTR_s_e___Done__2e49ffe4_0x1c_2e4b25ec;
    puVar7 = PTR_LAB_2e4b25c8;
    *(undefined4 *)(PTR_DAT_2e4b25b8 + 0x3c18) = 0;
    puVar6 = puVar7 + 0x4e54;
    puVar7 = puVar7 + 0x7c68;
    puVar8 = puVar8 + -0x7e10;
    uVar5 = 0x201;
  } while( true );
}

