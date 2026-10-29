
undefined4 _HVD_EX_Init_(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (cRam2d73e804 == '\0') {
    printf("[%s] .. STOP and Contact VDEC team!!!\n","_HVD_EX_Init_");
    return 0;
  }
  uVar1 = _HVD_EX_Rst(param_1,0);
  return uVar1;
}

