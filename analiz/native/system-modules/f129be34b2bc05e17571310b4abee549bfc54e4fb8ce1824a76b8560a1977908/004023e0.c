
int set_power_info(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  code *pcVar7;
  undefined8 uVar8;
  char *local_298;
  undefined1 auStack_294 [16];
  undefined4 local_284;
  undefined1 local_27f;
  ushort local_27e [5];
  undefined1 auStack_274 [216];
  ushort local_19c;
  ushort local_19a;
  byte local_15c;
  ushort local_34;
  
  uVar6 = *param_3;
  iVar3 = (*(code *)PTR_strcasecmp_004162e0)(uVar6,PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x55f4);
  if (iVar3 == 0) {
    local_27f = 1;
  }
  else {
    iVar3 = (*(code *)PTR_strcasecmp_004162e0)(uVar6,PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x5d64);
    if (iVar3 != 0) {
      iVar3 = (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x1244))
                        (param_3,param_4,local_27e,PTR_DAT_0041628c + 0x6224,5);
      if (iVar3 < 0) {
        return iVar3;
      }
      local_27f = 0;
      uVar8 = (*(code *)PTR_strtod_00416358)(*param_3,&local_298);
      bVar1 = false;
      if (local_298 != (char *)*param_3) {
        iVar4 = (*(code *)PTR_iw_get_range_info_00416314)(param_1,param_2,auStack_274);
        if (iVar4 < 0) {
          (*(code *)PTR_memset_0041633c)(auStack_274,0,0x24c);
        }
        if (((local_27e[0] & 0xf000) != 0x2000) &&
           (local_19a = local_34, (local_27e[0] & 0xf000) != 0x4000)) {
          local_19a = local_19c;
        }
        if ((local_19a & 4) == 0) {
          uVar6 = *(undefined4 *)(PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x5e08);
          uVar5 = *(undefined4 *)(PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x5e0c);
          uVar8 = (*(code *)PTR___muldf3_0041637c)
                            ((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar6,uVar5);
          pcVar7 = (code *)PTR___divdf3_004162e8;
          if (*local_298 != 'u') {
            uVar2 = local_27e[0];
            if (*local_298 != 'm') goto LAB_00402650;
            uVar6 = *(undefined4 *)(PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x5e10);
            uVar5 = *(undefined4 *)(PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x5e14);
          }
LAB_00402638:
          uVar8 = (*pcVar7)((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar6,uVar5);
          uVar2 = local_27e[0];
        }
        else {
          uVar2 = local_27e[0] | 4;
          if (local_15c < 0x15) {
            uVar6 = *(undefined4 *)(PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x5e08);
            uVar5 = *(undefined4 *)(PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x5e0c);
            pcVar7 = (code *)PTR___muldf3_0041637c;
            goto LAB_00402638;
          }
        }
LAB_00402650:
        local_27e[0] = uVar2;
        local_284 = (*(code *)PTR___fixdfsi_00416318)((int)uVar8,(int)((ulonglong)uVar8 >> 0x20));
        if ((local_27e[0] & 0xf000) == 0) {
          local_27e[0] = local_27e[0] | 0x1000;
        }
        iVar3 = iVar3 + 1;
        bVar1 = true;
      }
      if (iVar3 < param_4) {
        param_3 = param_3 + iVar3;
        iVar4 = (*(code *)PTR_strcasecmp_004162e0)
                          (*param_3,PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x561c);
        if (iVar4 == 0) {
          local_27e[0] = local_27e[0] | 0x300;
        }
        iVar4 = (*(code *)PTR_strncasecmp_004162c8)
                          (*param_3,PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x5608,4);
        if (iVar4 == 0) {
          local_27e[0] = local_27e[0] | 0x100;
        }
        iVar4 = (*(code *)PTR_strncasecmp_004162c8)
                          (*param_3,PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x5620,5);
        if (iVar4 == 0) {
          local_27e[0] = local_27e[0] | 0x200;
        }
        iVar4 = (*(code *)PTR_strncasecmp_004162c8)
                          (*param_3,PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x562c,5);
        if (iVar4 == 0) {
          local_27e[0] = local_27e[0] | 0x400;
        }
        iVar4 = (*(code *)PTR_strcasecmp_004162e0)
                          (*param_3,PTR___DT_MIPS_BASE_ADDRESS_00416288 + 0x5634);
        if (iVar4 == 0) {
          local_27e[0] = local_27e[0] | 0x800;
        }
        if ((local_27e[0] & 0xf00) != 0) {
          iVar3 = iVar3 + 1;
          goto LAB_00402798;
        }
      }
      if (!bVar1) {
        *(int *)(PTR_DAT_0041628c + 0x63a0) = iVar3;
        return -3;
      }
      goto LAB_00402798;
    }
    local_27e[0] = 0;
    (*(code *)PTR_strncpy_00416350)(auStack_294,param_2,0x10);
    iVar3 = (*(code *)PTR_ioctl_00416320)(param_1,0x8b2d,auStack_294);
    if (iVar3 < 0) {
      return -7;
    }
    local_27f = 0;
  }
  iVar3 = 1;
LAB_00402798:
  (*(code *)PTR_strncpy_00416350)(auStack_294,param_2,0x10);
  iVar4 = (*(code *)PTR_ioctl_00416320)(param_1,0x8b2c,auStack_294);
  if (iVar4 < 0) {
    iVar3 = -6;
  }
  return iVar3;
}

