
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* MDMPPlayer_GetVolume() */

void MDMPPlayer_GetVolume(void)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_GetMSrvSSSound_00033258)();
  (*(code *)PTR_GetVolume_00033270)(uVar1);
  return;
}

