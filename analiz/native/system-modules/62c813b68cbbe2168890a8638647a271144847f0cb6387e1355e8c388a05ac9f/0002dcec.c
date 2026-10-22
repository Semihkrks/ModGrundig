
uint FUN_0002dcec(int param_1,int *param_2,char *param_3,int param_4)

{
  char cVar1;
  int iVar2;
  char *local_res8;
  int local_40;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  
  local_2c = *(uint *)(param_1 + 0x14);
  local_24 = local_2c & 0xff;
  local_28 = local_2c >> 8 & 0xff;
  local_2c = local_2c >> 0x10;
  local_30 = 0;
  local_res8 = param_3;
  do {
    cVar1 = *local_res8;
    if (cVar1 == '\x1b') {
      if (param_4 < (int)(local_30 + 4)) break;
      if (local_res8[1] != '$') {
LAB_0002ded8:
        if ((local_res8[1] != 'N') || (local_2c == 0)) goto LAB_0002e350;
        if (local_2c == 1) {
          if (((-1 < local_res8[2]) && (-1 < local_res8[3])) &&
             (iVar2 = (*(code *)(PTR_LAB_001158e4 + 0x3438))(param_1,param_2,local_res8 + 2,2),
             iVar2 != -1)) {
            if (iVar2 != 2) {
              (*(code *)PTR_abort_00115994)();
            }
            *(uint *)(param_1 + 0x14) = local_28 << 8 | 0x10000 | local_24;
            return local_30 + 4;
          }
          goto LAB_0002e350;
        }
        (*(code *)PTR_abort_00115994)();
        goto LAB_0002dfec;
      }
      if (local_res8[2] == ')') {
        if (local_res8[3] != 'A') {
          if (local_res8[3] != 'G') goto LAB_0002de68;
          local_28 = 2;
          goto joined_r0x0002de58;
        }
        local_28 = 1;
        local_res8 = local_res8 + 4;
        iVar2 = local_30 + 5;
        local_30 = local_30 + 4;
      }
      else {
LAB_0002de68:
        if ((local_res8[2] != '*') || (local_res8[3] != 'H')) goto LAB_0002ded8;
        local_2c = 1;
joined_r0x0002de58:
        iVar2 = local_30 + 5;
        local_res8 = local_res8 + 4;
        local_30 = local_30 + 4;
      }
    }
    else {
LAB_0002dfec:
      if (cVar1 == '\x0e') {
        if ((local_28 != 1) && (local_28 != 2)) goto LAB_0002e350;
        local_24 = 1;
        local_res8 = local_res8 + 1;
        iVar2 = local_30 + 2;
        local_30 = local_30 + 1;
      }
      else {
        if (cVar1 != '\x0f') {
          if (local_24 == 0) {
            if ((-1 < cVar1) &&
               (iVar2 = (*(code *)(PTR_001158d4 + 0x1100))(param_1,param_2,local_res8,1),
               iVar2 != -1)) {
              if (iVar2 != 1) {
                (*(code *)PTR_abort_00115994)();
              }
              if ((*param_2 == 10) || (*param_2 == 0xd)) {
                local_28 = 0;
                local_2c = 0;
              }
              *(uint *)(param_1 + 0x14) = local_2c << 0x10 | local_28 << 8;
              return local_30 + 1;
            }
          }
          else {
            if (local_24 != 1) {
              (*(code *)PTR_abort_00115994)();
              break;
            }
            if (param_4 < (int)(local_30 + 2)) break;
            if ((-1 < *local_res8) && (-1 < local_res8[1])) {
              if (local_28 == 1) {
                local_40 = (*(code *)(PTR_LAB_001158e4 + 0xfbc))(param_1,param_2,local_res8,2);
              }
              else {
                if (local_28 == 0) goto LAB_0002e350;
                if (local_28 == 2) {
                  local_40 = (*(code *)(PTR_LAB_001158e4 + 0x31b0))(param_1,param_2,local_res8,2);
                }
                else {
                  (*(code *)PTR_abort_00115994)();
                }
              }
              if (local_40 != -1) {
                if (local_40 != 2) {
                  (*(code *)PTR_abort_00115994)();
                }
                *(uint *)(param_1 + 0x14) = local_2c << 0x10 | local_28 << 8 | 1;
                return local_30 + 2;
              }
            }
          }
LAB_0002e350:
          *(uint *)(param_1 + 0x14) = local_2c << 0x10 | local_28 << 8 | local_24;
          return ~(local_30 << 1);
        }
        local_24 = 0;
        local_res8 = local_res8 + 1;
        iVar2 = local_30 + 2;
        local_30 = local_30 + 1;
      }
    }
  } while (iVar2 <= param_4);
  *(uint *)(param_1 + 0x14) = local_2c << 0x10 | local_28 << 8 | local_24;
  return ~local_30 << 1;
}

