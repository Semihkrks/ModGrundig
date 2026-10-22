
void MDrv_VE_InitVECapture(undefined4 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  
  puVar1 = PTR_DAT_2effec38;
  if (*(int *)(PTR_DAT_2effec38 + -0x108c) != 0) {
    puVar3 = (undefined4 *)(*(code *)PTR_malloc_2effed6c)(4);
    puVar2 = PTR_UtopiaIoctl_2effee18;
    uVar5 = *(undefined4 *)(puVar1 + -0x108c);
    *puVar3 = param_1;
    iVar4 = (*(code *)puVar2)(uVar5,0x1e,puVar3);
    if (iVar4 != 0) {
      (*(code *)PTR_printf_2effedc0)(PTR_DAT_2effec48 + -0x3194,PTR_DAT_2effec48 + -0x21f8,iVar4);
    }
    (*(code *)PTR_free_2effee68)(puVar3);
  }
  return;
}

