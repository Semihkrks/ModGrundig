
/* MMAPInfo::Init() */

void __thiscall MMAPInfo::Init(MMAPInfo *this)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  uint uVar7;
  undefined1 *unaff_s1;
  uint unaff_s2;
  undefined *unaff_s4;
  int iVar8;
  int iVar9;
  undefined *unaff_s7;
  ushort local_2950;
  ushort local_294e;
  undefined4 local_294c;
  undefined4 local_2948;
  ushort *local_2944;
  undefined1 *local_2940;
  ushort *local_293c;
  undefined1 *local_2938;
  undefined1 auStack_2934 [100];
  undefined1 auStack_28d0 [10400];
  uint local_30;
  
  puVar4 = PTR_memset_2f617e00;
  this[0x3450] = (MMAPInfo)0x0;
  *(undefined4 *)(this + 0x3438) = 0;
  *(undefined4 *)(this + 0x343c) = 0;
  *(undefined4 *)(this + 0x3440) = 0;
  *(undefined4 *)(this + 0x3444) = 0;
  this[0x3451] = (MMAPInfo)0x0;
  this[0x3452] = (MMAPInfo)0x0;
  *(undefined4 *)(this + 0x3448) = 0;
  *(undefined4 *)(this + 0x344c) = 0;
  *(undefined4 *)(this + 0x3454) = 0;
  *(undefined4 *)(this + 0x3458) = 0;
  *(undefined4 *)(this + 0x345c) = 0;
  *(undefined4 *)(this + 0x3460) = 0;
  *(undefined4 *)(this + 0x3464) = 0;
  *(undefined4 *)(this + 0x3468) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  this[0x1c] = (MMAPInfo)0x0;
  (*(code *)puVar4)(this + 0x3474,0,0x85);
  local_2950 = 0;
  puVar1 = (undefined1 *)(*(code *)PTR_malloc_2f617d84)(0xf7d0);
  if (puVar1 == (undefined1 *)0x0) {
    puVar4 = PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x65c0;
    puVar5 = PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x65d8;
    puVar6 = PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6f94;
    uVar3 = 0x121;
    goto LAB_2f6049ec;
  }
  (*(code *)PTR_memset_2f617e00)(puVar1,0,0xf7d0);
  unaff_s1 = auStack_28d0;
  local_294e = 0;
  (*(code *)PTR_memset_2f617e00)(unaff_s1,0,0x28a0);
  (*(code *)PTR_memset_2f617e00)(this + 0x34fc,0,0x540);
  puVar4 = PTR_DAT_2f617ce8;
  local_2944 = &local_2950;
  local_293c = &local_294e;
  local_2940 = puVar1;
  local_2938 = unaff_s1;
  iVar2 = (*(code *)PTR_MMAPFileParser_2f617d40)
                    (*(undefined4 *)(PTR_DAT_2f617ce8 + *(int *)(this + 0x24) * 4 + 0x7cd0),
                     &local_2944);
  if (iVar2 == -1) {
    (*(code *)PTR_printf_2f617db4)
              (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6b78,
               *(undefined4 *)(puVar4 + *(int *)(this + 0x24) * 4 + 0x7cd0));
    (*(code *)PTR_puts_2f617d50)(PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6b98);
    return;
  }
  *(undefined4 *)(this + 0x346c) = 0;
  *(undefined4 *)(this + 0x3470) = 0;
  if (local_294e != 0) {
    uVar7 = 0;
    do {
      (*(code *)PTR_strcpy_2f617db8)(this + uVar7 * 100 + 0x28,unaff_s1 + uVar7 * 0x68);
      uVar7 = uVar7 + 1;
    } while (uVar7 < local_294e);
  }
  if (local_2950 == 0) goto LAB_2f604754;
  unaff_s7 = PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6be8;
  unaff_s2 = 0;
  unaff_s1 = puVar1;
  unaff_s4 = PTR___DT_MIPS_BASE_ADDRESS_2f617cf4;
  do {
    do {
      iVar2 = (*(code *)PTR_Is_StrFullCmp_2f617d08)(unaff_s4 + 0x6bd8,unaff_s1);
      if (iVar2 != 0) {
        *(undefined4 *)(this + 0x3438) = *(undefined4 *)(unaff_s1 + 100);
        goto LAB_2f6046f8;
      }
      iVar2 = (*(code *)PTR_Is_StrFullCmp_2f617d08)(unaff_s7,unaff_s1);
      if (iVar2 == 0) {
        iVar2 = (*(code *)PTR_Is_StrFullCmp_2f617d08)
                          (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6bf8,unaff_s1);
        if (iVar2 != 0) {
          *(undefined4 *)(this + 0x3440) = *(undefined4 *)(unaff_s1 + 100);
          goto LAB_2f6046f8;
        }
        iVar2 = (*(code *)PTR_Is_StrFullCmp_2f617d08)
                          (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6c08,unaff_s1);
        if (iVar2 != 0) {
          *(undefined4 *)(this + 0x3444) = *(undefined4 *)(unaff_s1 + 100);
          goto LAB_2f6046f8;
        }
        iVar2 = (*(code *)PTR_Is_StrFullCmp_2f617d08)
                          (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6c18,unaff_s1);
        if (iVar2 != 0) {
          this[0x3451] = (MMAPInfo)(*(int *)(unaff_s1 + 100) != 0);
          goto LAB_2f6046f8;
        }
        iVar2 = (*(code *)PTR_Is_StrFullCmp_2f617d08)
                          (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6c28,unaff_s1);
        if (iVar2 == 0) {
          iVar2 = (*(code *)PTR_Is_StrFullCmp_2f617d08)
                            (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6c38,unaff_s1);
          if (iVar2 == 0) goto LAB_2f604a04;
          *(undefined4 *)(this + 0x3448) = *(undefined4 *)(unaff_s1 + 100);
          goto LAB_2f6046f8;
        }
        this[0x3452] = (MMAPInfo)(*(int *)(unaff_s1 + 100) != 0);
        goto LAB_2f6046f8;
      }
      unaff_s2 = unaff_s2 + 1;
      *(undefined4 *)(this + 0x343c) = *(undefined4 *)(unaff_s1 + 100);
      unaff_s1 = unaff_s1 + 0x68;
    } while (unaff_s2 < local_2950);
LAB_2f604754:
    do {
      (*(code *)PTR_free_2f617df0)(puVar1);
      *(undefined4 *)this = *(undefined4 *)(this + 0x3438);
      *(undefined4 *)(this + 4) = *(undefined4 *)(this + 0x343c);
      *(undefined4 *)(this + 8) = *(undefined4 *)(this + 0x3440);
      *(undefined4 *)(this + 0xc) = *(undefined4 *)(this + 0x3444);
      *(undefined4 *)(this + 0x10) = *(undefined4 *)(this + 0x3448);
      *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 0x344c);
      *(undefined4 *)(this + 0x18) = *(undefined4 *)(this + 0x3470);
      this[0x1c] = this[0x3450];
      iVar2 = (*(code *)PTR_operator_new___2f617d10)(*(int *)(this + 0x18) * 0x19,PTR_DAT_2f617d14);
      *(int *)(this + 0x20) = iVar2;
      if (iVar2 != 0) {
        (*(code *)PTR_memcpy_2f617dd0)(iVar2,this + 0x2738,*(int *)(this + 0x18) * 0x19);
        uVar3 = (*(code *)PTR_StrToMMAPID_2f617d78)
                          (this,PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6cf4);
        iVar2 = (*(code *)PTR_CheckSize_2f617da4)(this,uVar3,0x1400000);
        if (iVar2 == 0) {
          (*(code *)PTR_puts_2f617d50)(PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6d00);
        }
        (*(code *)PTR_CheckLayout_2f617dbc)(this);
        (*(code *)PTR_CheckMiuSelectRule_2f617d7c)(this);
        return;
      }
      puVar4 = PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x65c0;
      puVar5 = PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x65d8;
      puVar6 = PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6f94;
      uVar3 = 0x1f0;
LAB_2f6049ec:
      while( true ) {
        (*(code *)PTR_printf_2f617db4)(puVar4,puVar5,puVar6,uVar3);
        (*(code *)PTR_abort_2f617e2c)();
LAB_2f604a04:
        iVar2 = (*(code *)PTR_Is_StrFullCmp_2f617d08)
                          (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6c48,unaff_s1);
        if (iVar2 != 0) {
          *(undefined4 *)(this + 0x344c) = *(undefined4 *)(unaff_s1 + 100);
          goto LAB_2f6046f8;
        }
        iVar2 = (*(code *)PTR_Is_StrFullCmp_2f617d08)
                          (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6c58,unaff_s1);
        if (iVar2 != 0) {
          *(undefined4 *)(this + 0x3454) = *(undefined4 *)(unaff_s1 + 100);
          goto LAB_2f6046f8;
        }
        iVar2 = (*(code *)PTR_Is_StrFullCmp_2f617d08)
                          (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6c60,unaff_s1);
        if (iVar2 != 0) {
          *(undefined4 *)(this + 0x3458) = *(undefined4 *)(unaff_s1 + 100);
          goto LAB_2f6046f8;
        }
        iVar2 = (*(code *)PTR_Is_StrFullCmp_2f617d08)
                          (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6c68,unaff_s1);
        if (iVar2 != 0) {
          *(undefined4 *)(this + 0x345c) = *(undefined4 *)(unaff_s1 + 100);
          goto LAB_2f6046f8;
        }
        iVar2 = (*(code *)PTR_Is_StrFullCmp_2f617d08)
                          (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6c70,unaff_s1);
        if (iVar2 != 0) {
          *(undefined4 *)(this + 0x3460) = *(undefined4 *)(unaff_s1 + 100);
          goto LAB_2f6046f8;
        }
        iVar2 = (*(code *)PTR_Is_StrFullCmp_2f617d08)
                          (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6c80,unaff_s1);
        if (iVar2 != 0) {
          *(undefined4 *)(this + 0x3464) = *(undefined4 *)(unaff_s1 + 100);
          goto LAB_2f6046f8;
        }
        iVar2 = (*(code *)PTR_Is_StrFullCmp_2f617d08)
                          (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6c90,unaff_s1);
        if (iVar2 != 0) {
          *(undefined4 *)(this + 0x3468) = *(undefined4 *)(unaff_s1 + 100);
          goto LAB_2f6046f8;
        }
        iVar2 = (*(code *)PTR_Is_StrFullCmp_2f617d08)
                          (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6ca0,unaff_s1);
        if (iVar2 != 0) {
          *(undefined4 *)(this + 0x346c) = *(undefined4 *)(unaff_s1 + 100);
          goto LAB_2f6046f8;
        }
        iVar2 = (*(code *)PTR_Is_StrFullCmp_2f617d08)
                          (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6cac,unaff_s1);
        if (iVar2 != 0) {
          this[0x3450] = (MMAPInfo)(*(int *)(unaff_s1 + 100) != 0);
          goto LAB_2f6046f8;
        }
        iVar2 = (*(code *)PTR_strstr_2f617d94)
                          (unaff_s1,PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6cbc);
        if (iVar2 == 0) break;
        iVar2 = (*(code *)PTR_strlen_2f617dc4)(unaff_s1);
        local_30 = (int)(char)unaff_s1[iVar2 + -1] - 0x30;
        if (local_30 < 7) {
          local_294c = 0;
          iVar2 = (*(code *)PTR_strtok_r_2f617d70)
                            (unaff_s1,PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6ccc,&local_294c);
          if (iVar2 == 0) goto LAB_2f6046f8;
          local_2948 = 0;
          uVar3 = (*(code *)PTR_strtok_r_2f617d70)
                            (iVar2,PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6cd0,&local_2948);
          uVar7 = (*(code *)PTR_strtoul_2f617dc8)(uVar3,0,0);
          if (uVar7 < 3) {
            uVar7 = *(uint *)(unaff_s1 + 100);
            iVar2 = (*(code *)PTR_strtoul_2f617dc8)(uVar3,0,0);
            iVar8 = 0;
            *(uint *)(this + (iVar2 * 7 + local_30) * 0x40 + 0x34fc) = uVar7 & 1;
            do {
              uVar7 = (int)uVar7 / 2;
              if (uVar7 == 0) goto LAB_2f6046f8;
              iVar2 = (*(code *)PTR_strtoul_2f617dc8)(uVar3,0,0);
              iVar8 = iVar8 + 1;
              *(uint *)(this + ((iVar2 * 7 + local_30) * 0x10 + iVar8 + 0xd3e) * 4 + 4) = uVar7 & 1;
            } while (iVar8 != 0x10);
            puVar4 = PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x65c0;
            puVar5 = PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x65d8;
            puVar6 = PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6f94;
            uVar3 = 0x1a1;
          }
          else {
            puVar4 = PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x65c0;
            puVar5 = PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x65d8;
            puVar6 = PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6f94;
            uVar3 = 0x197;
          }
        }
        else {
          puVar4 = PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x65c0;
          puVar5 = PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x65d8;
          puVar6 = PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6f94;
          uVar3 = 0x18d;
        }
      }
      iVar2 = (*(code *)PTR_strlen_2f617dc4)(unaff_s1);
      iVar8 = (*(code *)PTR_memcmp_2f617e24)
                        (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6cd4,unaff_s1 + iVar2 + -6,6);
      if (iVar8 == 0) {
        *(undefined4 *)(PTR_DAT_2f617ce8 + 0x7e74) = *(undefined4 *)(unaff_s1 + 100);
      }
      else {
        iVar8 = (*(code *)PTR_memcmp_2f617e24)
                          (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6cdc,unaff_s1 + iVar2 + -6,6);
        if (iVar8 == 0) {
          *(undefined4 *)(PTR_DAT_2f617ce8 + 0x7e70) = *(undefined4 *)(unaff_s1 + 100);
        }
        else {
          iVar9 = iVar2 + -4;
          iVar8 = (*(code *)PTR_memcmp_2f617e24)
                            (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6c78,unaff_s1 + iVar9,4);
          if (iVar8 == 0) {
            (*(code *)PTR_strncpy_2f617e08)(auStack_2934,unaff_s1,iVar9);
            iVar2 = (*(code *)PTR_strlen_2f617dc4)(unaff_s1);
            auStack_2934[iVar2 + -4] = 0;
            iVar2 = (*(code *)PTR_SaveInfo_2f617d0c)(this,auStack_2934,1);
            if (iVar2 != 0) {
              *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(unaff_s1 + 100);
              puVar4 = PTR_DAT_2f617ce8;
              *(char *)(iVar2 + 0xc) = (char)*(undefined4 *)(PTR_DAT_2f617ce8 + 0x7e74);
              *(undefined4 *)(iVar2 + 0xd) = *(undefined4 *)(puVar4 + 0x7e70);
            }
          }
          else {
            iVar8 = (*(code *)PTR_memcmp_2f617e24)
                              (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6be0,unaff_s1 + iVar9,4);
            if (iVar8 == 0) {
              (*(code *)PTR_strncpy_2f617e08)(auStack_2934,unaff_s1,iVar9);
              iVar2 = (*(code *)PTR_strlen_2f617dc4)(unaff_s1);
              auStack_2934[iVar2 + -4] = 0;
              iVar2 = (*(code *)PTR_SaveInfo_2f617d0c)(this,auStack_2934,1);
              if (iVar2 != 0) {
                *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(unaff_s1 + 100);
              }
            }
            else {
              iVar8 = (*(code *)PTR_memcmp_2f617e24)
                                (PTR___DT_MIPS_BASE_ADDRESS_2f617cf4 + 0x6ce4,
                                 unaff_s1 + iVar2 + -0xc,0xc);
              if (iVar8 == 0) {
                (*(code *)PTR_strncpy_2f617e08)(auStack_2934,unaff_s1,iVar2 + -0xc);
                iVar2 = (*(code *)PTR_strlen_2f617dc4)(unaff_s1);
                *(undefined1 *)((int)&local_2940 + iVar2) = 0;
                iVar2 = (*(code *)PTR_SaveInfo_2f617d0c)(this,auStack_2934,1);
                if (iVar2 != 0) {
                  uVar7 = *(uint *)(unaff_s1 + 100);
                  *(uint *)(iVar2 + 0x11) = uVar7;
                  uVar7 = (*(uint *)(this + 0x345c) | *(uint *)(this + 0x3458)) & uVar7;
                  *(uint *)(iVar2 + 0x15) = uVar7;
                  if (uVar7 == 1) {
                    *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + *(int *)(this + 0x3448);
                  }
                  else if (uVar7 == 2) {
                    *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + *(int *)(this + 0x344c);
                  }
                }
              }
            }
          }
        }
      }
LAB_2f6046f8:
      unaff_s2 = unaff_s2 + 1;
      unaff_s1 = unaff_s1 + 0x68;
    } while (local_2950 <= unaff_s2);
  } while( true );
}

