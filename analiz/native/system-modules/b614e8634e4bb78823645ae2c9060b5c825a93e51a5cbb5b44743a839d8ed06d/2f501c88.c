
undefined4 MDrv_PWS_Init(undefined4 param_1)

{
  char *pcVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar2 = PTR_DAT_2f513d18;
  pcVar1 = PTR_DAT_2f513d18 + 0x3e40;
  *(undefined4 *)(PTR_DAT_2f513d18 + 0x3e44) = param_1;
  if (*pcVar1 == '\0') {
    iVar3 = (*(code *)PTR_MDrv_PWS_SetIOMapBase_2f513d4c)();
    if (iVar3 != 1) {
      return 0;
    }
    (*(code *)PTR_HAL_PWS_Init_2f513d68)(param_1);
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  puVar2[0x3e40] = 1;
  return uVar4;
}

