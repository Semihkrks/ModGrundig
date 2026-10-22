
int MDrv_IR_Init(undefined4 param_1)

{
  uint *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  code *pcVar7;
  undefined1 auStack_50 [12];
  undefined4 local_44;
  undefined4 local_40;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined4 local_34;
  undefined4 local_30;
  
  (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f4723c4 + 0x1108))();
  puVar4 = PTR_MDrv_MBX_RegisterMSGWithCallBack_2f472414;
  puVar3 = PTR___DT_MIPS_BASE_ADDRESS_2f4723c4;
  puVar2 = PTR_DAT_2f4723b8;
  PTR_DAT_2f4723b8[0x3014] = 0;
  iVar5 = (*(code *)puVar4)(0x31,8,puVar3 + 0xcb0);
  if ((iVar5 == 0) || (iVar5 == 4)) {
    iVar5 = (*(code *)PTR_MDrv_MBX_RegisterMSG_2f4723e4)(0x22,8);
    puVar3 = PTR_DAT_2f4723b8;
    if ((iVar5 != 0) && (iVar5 != 4)) {
      return 0;
    }
    puVar1 = (uint *)(PTR_DAT_2f4723b8 + 0x302c);
    *(undefined4 *)(PTR_DAT_2f4723b8 + 0x303c) = param_1;
    *(uint *)(puVar3 + 0x302c) = *puVar1 | 1;
    local_44 = 2;
    local_40 = 1;
    local_38 = (undefined1)((uint)param_1 >> 0x18);
    local_3b = 0x31;
    local_39 = 4;
    local_37 = (undefined1)((uint)param_1 >> 0x10);
    local_36 = (undefined1)((uint)param_1 >> 8);
    local_35 = (undefined1)param_1;
    local_34 = 0;
    local_30 = 0;
    local_3c = 0;
    local_3a = 0;
    iVar5 = (*(code *)PTR_MDrv_MBX_SendMsg_2f472400)(&local_44);
    puVar4 = PTR_DAT_2f4723b8;
    if (iVar5 == 0) {
      pcVar7 = (code *)(PTR___DT_MIPS_BASE_ADDRESS_2f4723c4 + 0x1160);
      uVar6 = 0;
      do {
        if (uVar6 < 10) {
          (*pcVar7)(0x22,auStack_50);
          uVar6 = uVar6 + 1;
        }
        else {
          uVar6 = 0;
          iVar5 = (*(code *)PTR_MDrv_MBX_SendMsg_2f472400)(&local_44);
          if (iVar5 != 0) {
            return 0;
          }
        }
      } while (((*(uint *)(puVar3 + 0x302c) & 1) != 0) && (*(int *)(puVar4 + 0x3038) != 0xd));
      iVar5 = *(int *)(PTR_DAT_2f4723b8 + 0x3034);
      if (iVar5 == 0) {
        return 0;
      }
      puVar2[0x3014] = 1;
      return iVar5;
    }
  }
  return 0;
}

