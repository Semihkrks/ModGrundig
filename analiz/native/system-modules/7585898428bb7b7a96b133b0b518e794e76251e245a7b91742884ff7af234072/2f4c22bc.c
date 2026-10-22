
bool MDrv_PM_PWM_IRRecord_Init(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_MDrv_MBX_RegisterMSGWithCallBack_2f4d6104)
                    (0x38,8,PTR___DT_MIPS_BASE_ADDRESS_2f4d6064 + 0x1e70);
  if (iVar1 != 0) {
    return false;
  }
  iVar1 = (*(code *)PTR_MDrv_MBX_RegisterMSG_2f4d60ac)(0x37,8);
  return iVar1 == 0;
}

