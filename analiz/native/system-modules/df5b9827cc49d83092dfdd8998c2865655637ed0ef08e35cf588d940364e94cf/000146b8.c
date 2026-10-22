
void MHAL_MBX_Init(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  
  puVar1 = PTR_MHAL_MBX_SetConfig_00026930;
  *(undefined4 *)(PTR_DAT_00026888 + 0x6ef0) = param_2;
  (*(code *)puVar1)();
  return;
}

