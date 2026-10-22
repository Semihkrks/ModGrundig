
undefined4 nuron_init(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  
  puVar4 = PTR_DAT_00021cc8;
  if (*(int *)(PTR_DAT_00021cc8 + 0x1d90) == 0) {
    puVar3 = *(undefined **)(PTR_DAT_00021cc8 + 0x1d9c);
    if (puVar3 == (undefined *)0x0) {
      puVar3 = PTR_00021cd4 + 0x19f8;
    }
    iVar1 = (*(code *)PTR_DSO_load_00021d30)(0,puVar3,0,2);
    *(int *)(puVar4 + 0x1d90) = iVar1;
    if (iVar1 == 0) {
      uVar5 = 0x8b;
      puVar4 = PTR_00021cd4 + 0x19ec;
      uVar2 = 0x68;
    }
    else {
      iVar1 = (*(code *)PTR_DSO_bind_func_00021d04)
                        (iVar1,*(undefined4 *)(PTR_DAT_00021cc8 + 0x1ba8));
      *(int *)(PTR_DAT_00021cc8 + 0x1d94) = iVar1;
      if (iVar1 != 0) {
        return 1;
      }
      uVar2 = 0x67;
      puVar4 = PTR_00021cd4 + 0x19ec;
      uVar5 = 0x91;
    }
  }
  else {
    uVar2 = 100;
    puVar4 = PTR_00021cd4 + 0x19ec;
    uVar5 = 0x84;
  }
  (*(code *)(PTR_00021cd4 + 0xd40))(0x66,uVar2,puVar4,uVar5);
  return 0;
}

