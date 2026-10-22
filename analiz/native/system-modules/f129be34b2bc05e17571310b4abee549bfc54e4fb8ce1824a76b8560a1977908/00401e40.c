
int set_txpower_info(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_290;
  undefined1 auStack_28c [16];
  undefined4 local_27c;
  undefined1 local_278;
  undefined1 local_277;
  undefined2 local_276;
  undefined1 auStack_26c [242];
  ushort local_17a;
  
  uVar5 = *param_3;
  local_27c = 0xffffffff;
  local_278 = 1;
  local_277 = 0;
  local_276 = 0;
  iVar3 = (*(code *)PTR_strcasecmp_004162e0)(uVar5,PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x55f4);
  if (iVar3 == 0) {
    local_277 = 1;
  }
  else {
    iVar3 = (*(code *)PTR_strcasecmp_004162e0)(uVar5,PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x55e4);
    if (iVar3 == 0) {
      local_278 = 0;
    }
    else {
      iVar3 = (*(code *)PTR_strcasecmp_004162e0)(uVar5,PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x5d64)
      ;
      if (iVar3 == 0) {
        (*(code *)PTR_strncpy_00416350)(auStack_28c,param_2,0x10);
        iVar3 = (*(code *)PTR_ioctl_00416320)(param_1,0x8b27,auStack_28c);
        if (iVar3 < 0) {
          return -7;
        }
      }
      else {
        iVar3 = (*(code *)PTR_strcasecmp_004162e0)
                          (uVar5,PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x55ec);
        if (iVar3 != 0) {
          iVar3 = (*(code *)PTR_iw_get_range_info_00416314)(param_1,param_2,auStack_26c);
          if (iVar3 < 0) {
            (*(code *)PTR_memset_0041633c)(auStack_26c,0,0x24c);
          }
          iVar3 = (*(code *)PTR_sscanf_004162c4)
                            (*param_3,PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x55fc,&local_290);
          if (iVar3 != 1) {
LAB_00402050:
            *(undefined4 *)(PTR_DAT_0041628c + 0x63a0) = 0;
            return -3;
          }
          uVar5 = *param_3;
          iVar3 = (*(code *)PTR_strchr_00416354)(uVar5,0x6d);
          bVar1 = false;
          if (iVar3 != 0) {
            iVar3 = (*(code *)PTR_strchr_00416354)(uVar5,100);
            bVar1 = iVar3 == 0;
          }
          if ((local_17a & 2) == 0) {
            if ((local_17a & 1) == 0) {
              if (bVar1) {
                local_290 = (*(code *)PTR_iw_mwatt2dbm_004162ac)(local_290);
                local_276 = 0;
                uVar2 = local_276;
              }
              else {
                local_276 = 0;
                uVar2 = local_276;
              }
            }
            else {
              uVar2 = 1;
              if (!bVar1) {
                local_290 = (*(code *)PTR_iw_dbm2mwatt_00416338)(local_290);
                uVar2 = 1;
              }
            }
          }
          else {
            uVar2 = 2;
            if (bVar1) goto LAB_00402050;
          }
          local_276 = uVar2;
          iVar3 = 1;
          local_27c = local_290;
          if (1 < param_4) {
            iVar4 = (*(code *)PTR_strcasecmp_004162e0)
                              (param_3[1],PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x55e4);
            if (iVar4 == 0) {
              local_278 = 0;
              iVar3 = 2;
              if (param_4 == 2) goto LAB_00402124;
              iVar3 = 2;
            }
            iVar4 = (*(code *)PTR_strcasecmp_004162e0)
                              (param_3[iVar3],PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x55ec);
            if (iVar4 == 0) {
              local_278 = 1;
              iVar3 = iVar3 + 1;
            }
          }
          goto LAB_00402124;
        }
        (*(code *)PTR_strncpy_00416350)(auStack_28c,param_2,0x10);
        iVar3 = (*(code *)PTR_ioctl_00416320)(param_1,0x8b27,auStack_28c);
        if (iVar3 < 0) {
          return -7;
        }
        local_278 = 1;
      }
      local_277 = 0;
    }
  }
  iVar3 = 1;
LAB_00402124:
  (*(code *)PTR_strncpy_00416350)(auStack_28c,param_2,0x10);
  iVar4 = (*(code *)PTR_ioctl_00416320)(param_1,0x8b26,auStack_28c);
  if (iVar4 < 0) {
    iVar3 = -6;
  }
  return iVar3;
}

