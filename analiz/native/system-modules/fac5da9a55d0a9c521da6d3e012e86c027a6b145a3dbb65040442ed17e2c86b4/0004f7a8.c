
undefined4
ucol_normalizeShortDefinitionString_4_2
          (undefined4 param_1,int param_2,undefined4 param_3,undefined1 *param_4,undefined4 *param_5
          )

{
  int iVar1;
  undefined1 *local_resc;
  undefined1 auStack_2e8 [72];
  undefined1 auStack_2a0 [656];
  undefined4 local_10;
  
  iVar1 = (*(code *)(PTR_LAB_000b0be4 + -0x30c4))(*param_5);
  if (iVar1 == 0) {
    if (param_2 != 0) {
      (*(code *)PTR_memset_000b1ba8)(param_2,0,param_3);
    }
    local_resc = param_4;
    if (param_4 == (undefined1 *)0x0) {
      local_resc = auStack_2e8;
    }
    (*(code *)(PTR_LAB_000b0be4 + -0x1614))(auStack_2a0);
    (*(code *)(PTR_LAB_000b0be4 + -0x28f0))(auStack_2a0,param_1,local_resc,param_5);
    local_10 = (*(code *)(PTR_LAB_000b0be4 + -0xb48))(auStack_2a0,param_2,param_3,param_5);
  }
  else {
    local_10 = 0;
  }
  return local_10;
}

