
undefined4 MDrv_RTC_Init(uint param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 local_20;
  undefined1 auStack_1c [4];
  
  puVar2 = PTR_DAT_2f532c68;
  if ((param_2 <= param_3) && (param_2 != 0)) {
    *(uint *)(PTR_DAT_2f532c68 + 0x2d44) = param_1;
    puVar3 = PTR_DAT_2f532c68;
    bVar1 = puVar2[0x2d40];
    *(uint *)(puVar2 + 0x2d48) = param_2;
    puVar4 = PTR_DAT_2f532c68;
    *(uint *)(puVar3 + 0x2d4c) = param_3;
    *(int *)(puVar4 + 0x2d50) = param_4;
    *(int *)(PTR_DAT_2f532c68 + 0x2d54) = param_5;
    if (((int)(uint)bVar1 >> (param_1 & 0x1f) & 1U) == 0) {
      iVar5 = (*(code *)PTR_MDrv_MMIO_GetBASE_2f532cdc)(&local_20,auStack_1c,300);
      if (iVar5 == 0) {
        (*(code *)PTR_puts_2f532ca8)(PTR___DT_MIPS_BASE_ADDRESS_2f532c74 + 0x2a44);
        return 0;
      }
      (*(code *)PTR_HAL_RTC_SetIOMapBase_2f532cac)(local_20);
      puVar3 = PTR_HAL_RTC_RESET_2f532c88;
      *(uint *)(PTR_DAT_2f532c68 + param_1 * 4 + 0x2d58) = param_3;
      (*(code *)puVar3)(param_1,1);
      (*(code *)PTR_HAL_RTC_Set_Frequency_2f532cb4)(param_1,param_2,param_3);
      (*(code *)PTR_HAL_RTC_Set_Counter_2f532cd4)(param_1,0);
      (*(code *)PTR_HAL_RTC_Loading_2f532cd0)(param_1,1);
      (*(code *)PTR_HAL_RTC_Match_Counter_2f532ce0)(param_1,param_4 * param_2);
      if (param_5 == 0) {
        (*(code *)PTR_HAL_RTC_IntMask_2f532c94)(param_1,1);
        (*(code *)PTR_MsOS_DetachInterrupt_2f532cb0)(0x17);
        (*(code *)PTR_MsOS_DisableInterrupt_2f532ca0)(0x17);
      }
      else {
        (*(code *)PTR_HAL_RTC_IntMask_2f532c94)(param_1,0);
        (*(code *)PTR_MsOS_AttachInterrupt_2f532cc0)(0x17,param_5);
        (*(code *)PTR_MsOS_EnableInterrupt_2f532d00)(0x17);
      }
      (*(code *)PTR_HAL_RTC_Reading_2f532c98)(param_1,1);
      (*(code *)PTR_HAL_RTC_Counter_2f532d18)(param_1,1);
      (*(code *)PTR_HAL_RTC_Wrap_Count_2f532ca4)(param_1,1);
      puVar2[0x2d40] = (byte)(1 << (param_1 & 0x1f)) | puVar2[0x2d40];
      return 1;
    }
  }
  return 0;
}

