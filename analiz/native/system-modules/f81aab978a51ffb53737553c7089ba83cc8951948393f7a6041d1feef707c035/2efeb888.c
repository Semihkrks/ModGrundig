
void Hal_VE_set_v_initfactor(char param_1,uint param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  ushort uVar4;
  
  puVar2 = PTR_g_bVeDisableRegWrite_2effecb8;
  puVar1 = PTR__VE_RIU_BASE_2effec54;
  uVar4 = 0;
  if (param_2 != 0) {
    if (param_2 == 0) {
      trap(7);
    }
    uVar3 = 0x100000 / param_2 - 0x200;
    uVar4 = (ushort)uVar3;
    if (0x7fe < (uVar3 & 0xffff)) {
      uVar4 = 0x7ff;
    }
  }
  if (param_1 == '\0') {
    if (*PTR_g_bVeDisableRegWrite_2effecb8 != '\x01') {
      *(undefined2 *)(*(int *)PTR__VE_RIU_BASE_2effec54 + 0x207664) = 0x8000;
    }
  }
  else if (*PTR_g_bVeDisableRegWrite_2effecb8 != '\x01') {
    *(ushort *)(*(int *)PTR__VE_RIU_BASE_2effec54 + 0x207664) =
         uVar4 & 0x7ff | *(ushort *)(*(int *)PTR__VE_RIU_BASE_2effec54 + 0x207664) & 0xf800;
    if (*puVar2 != '\x01') {
      *(ushort *)(*(int *)puVar1 + 0x207664) =
           *(ushort *)(*(int *)puVar1 + 0x207664) & 0x7fff | 0x8000;
      return;
    }
  }
  return;
}

