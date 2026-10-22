
void msAPI_StillImage_BMBuffer_UpdateBase(void)

{
  int iVar1;
  
  iVar1 = *(int *)(PTR_DAT_2dbaaba8 + -0x5480);
  *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(iVar1 + 0x3c);
  *(undefined2 *)(iVar1 + 0x40) = *(undefined2 *)(iVar1 + 0x44);
  return;
}

