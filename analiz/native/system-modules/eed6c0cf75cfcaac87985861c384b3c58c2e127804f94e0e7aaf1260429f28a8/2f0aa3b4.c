
undefined4 QRinput_setVersionAndErrorCorrectionLevel(uint *param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_1[4] == 0) {
    if ((param_2 < 0x29) && ((int)param_3 < 4)) {
      param_1[1] = param_3;
      goto LAB_2f0aa46c;
    }
  }
  else if ((param_2 - 1 < 4) &&
          (iVar2 = (*(code *)PTR_MQRspec_getECCLength_2f0c0a78)(param_2,param_3), iVar2 != 0)) {
    param_1[1] = param_3;
LAB_2f0aa46c:
    *param_1 = param_2;
    return 0;
  }
  puVar1 = (undefined4 *)(*(code *)PTR___errno_location_2f0c0c54)();
  *puVar1 = 0x16;
  return 0xffffffff;
}

