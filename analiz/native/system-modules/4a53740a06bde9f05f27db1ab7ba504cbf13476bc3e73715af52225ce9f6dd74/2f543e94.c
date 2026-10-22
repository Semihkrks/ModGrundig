
void HAL_SAR_CfgSingleChannelEn(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x10;
  if (param_1 == '\0') {
    uVar1 = 0;
  }
  (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f555574 + 0x39a0))(0x1400,uVar1,0x10);
  return;
}

