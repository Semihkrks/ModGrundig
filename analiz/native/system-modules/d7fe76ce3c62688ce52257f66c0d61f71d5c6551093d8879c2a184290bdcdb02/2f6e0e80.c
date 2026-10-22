
undefined4 dlsym(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint unaff_retaddr;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  
  puVar1 = PTR_DAT_2f6f2038;
  if (*(int *)PTR__dlfcn_hook_2f6f2018 == 0) {
    local_18 = unaff_retaddr & 0xfffffffe;
    local_20 = param_1;
    local_1c = param_2;
    (**(code **)(PTR_DAT_2f6f2038 + 0x620))(PTR_DAT_2f6f2038 + 0x240);
    iVar2 = (*(code *)PTR_FUN_2f6f201c)(PTR___DT_MIPS_BASE_ADDRESS_2f6f2014 + 0xf44,&local_20);
    uVar3 = 0;
    if (iVar2 == 0) {
      uVar3 = local_14;
    }
    (**(code **)(puVar1 + 0x624))(puVar1 + 0x240);
  }
  else {
    uVar3 = (**(code **)(*(int *)PTR__dlfcn_hook_2f6f2018 + 8))
                      (param_1,param_2,unaff_retaddr & 0xfffffffe);
  }
  return uVar3;
}

