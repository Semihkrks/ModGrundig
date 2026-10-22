
void HAL_SAR_CfgHighChannel(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 8;
  if (param_1 == '\0') {
    uVar1 = 0;
  }
  (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f555574 + 0x39a0))(0x1401,uVar1,8);
  return;
}

