
undefined4 MDrv_VEC_GFLIPInit(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_DAT_2effec38;
  if (*(int *)(PTR_DAT_2effec38 + -7000) < 0) {
    iVar2 = (*(code *)PTR_open_2effef2c)(PTR_DAT_2effec48 + -0x2434,2);
    *(int *)(puVar1 + -7000) = iVar2;
    if (iVar2 < 0) {
      (*(code *)PTR_printf_2effedc0)(PTR_DAT_2effec48 + -0x2428,PTR_DAT_2effec48 + -0x1d7c,0x251);
      return 0;
    }
  }
  return 1;
}

