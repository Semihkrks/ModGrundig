
/* MDMPPlayer_SetVolume(int) */

undefined4 MDMPPlayer_SetVolume(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_GetMSrvSSSound_00033258)();
  (*(code *)PTR_SetVolume_000331f4)(uVar1,param_1 & 0xff);
  return 1;
}

