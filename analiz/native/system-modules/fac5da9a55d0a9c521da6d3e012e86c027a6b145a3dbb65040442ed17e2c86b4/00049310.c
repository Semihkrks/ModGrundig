
undefined4 ucol_initInverseUCA_4_2(undefined4 *param_1)

{
  int iVar1;
  int local_1c;
  int local_18;
  undefined4 local_10;
  
  iVar1 = (*(code *)(PTR_LAB_000b0be4 + -0x7d44))(*param_1);
  if (iVar1 == 0) {
    (*(code *)PTR_umtx_lock_4_2_000b15a8)(0);
    iVar1 = *(int *)(PTR_PTR_000b0ab8 + 0x1e90);
    (*(code *)PTR_umtx_unlock_4_2_000b16b0)(0);
    if (iVar1 == 0) {
      local_1c = (*(code *)PTR_udata_openChoice_4_2_000b1a28)
                           (PTR_uhash_get_4_2_000b0ac8 + 0x13e0,PTR_uhash_get_4_2_000b0ac8 + 0x13f0,
                            PTR_uhash_get_4_2_000b0ac8 + 0x13f4,PTR_LAB_000b0be4 + -0x3258,0,param_1
                           );
      iVar1 = (*(code *)(PTR_LAB_000b0be4 + -0x7d44))(*param_1);
      if ((iVar1 != 0) && (local_1c != 0)) {
        (*(code *)PTR_udata_close_4_2_000b1d40)(local_1c);
      }
      if (local_1c != 0) {
        local_18 = (*(code *)PTR_udata_getMemory_4_2_000b1778)(local_1c);
        iVar1 = (*(code *)PTR_FUN_000b0be8)(param_1);
        iVar1 = (*(code *)PTR_memcmp_000b1cf0)(local_18 + 0x14,*(int *)(iVar1 + 0x24) + 0x48,4);
        if (iVar1 != 0) {
          *param_1 = 3;
          (*(code *)PTR_udata_close_4_2_000b1d40)(local_1c);
          return 0;
        }
        (*(code *)PTR_umtx_lock_4_2_000b15a8)(0);
        if (*(int *)(PTR_PTR_000b0ab8 + 0x1e90) == 0) {
          *(int *)(PTR_PTR_000b0ab8 + 0x1e94) = local_1c;
          *(int *)(PTR_PTR_000b0ab8 + 0x1e90) = local_18;
          local_1c = 0;
          local_18 = 0;
        }
        (*(code *)PTR_umtx_unlock_4_2_000b16b0)(0);
        if (local_18 == 0) {
          (*(code *)PTR_FUN_000b0b28)(0x11,PTR_LAB_000b0be4 + -0x6d58);
        }
        else {
          (*(code *)PTR_udata_close_4_2_000b1d40)(local_1c);
        }
      }
    }
    local_10 = *(undefined4 *)(PTR_PTR_000b0ab8 + 0x1e90);
  }
  else {
    local_10 = 0;
  }
  return local_10;
}

