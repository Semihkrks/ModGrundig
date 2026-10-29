
/* MW_DTV_Scan_DVBS_Customer::SavePrograms(unsigned long, MW_DVB_TS_INFO*, MW_DVB_PROGRAM_INFO*) */

undefined4 __thiscall
MW_DTV_Scan_DVBS_Customer::SavePrograms
          (MW_DTV_Scan_DVBS_Customer *this,ulong param_1,MW_DVB_TS_INFO *param_2,
          MW_DVB_PROGRAM_INFO *param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 uVar15;
  uint uVar16;
  uint uVar17;
  code *pcVar18;
  undefined4 local_2e8;
  undefined4 local_2e4;
  uint local_2e0;
  uint local_2dc;
  ulong local_2d8;
  undefined4 local_2d4;
  undefined4 local_2d0;
  undefined4 local_2cc;
  ulong local_2c8;
  undefined4 local_2c4;
  undefined4 local_2c0;
  undefined4 local_2bc;
  undefined4 local_2b8;
  undefined4 local_2b4;
  undefined4 local_2b0;
  undefined4 local_2ac;
  undefined4 local_2a8;
  undefined4 local_2a4;
  undefined4 local_2a0;
  undefined4 local_29c;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_290;
  undefined4 local_28c;
  undefined4 local_288;
  undefined4 local_284;
  undefined4 local_280;
  undefined4 local_27c;
  undefined1 auStack_278 [68];
  undefined1 auStack_234 [72];
  undefined4 local_1ec;
  undefined2 local_1e8;
  undefined1 uStack_1dd;
  undefined1 uStack_1db;
  undefined1 uStack_1da;
  undefined1 local_1d7;
  undefined1 local_1d6;
  byte local_1c4;
  undefined2 local_1c0;
  undefined2 local_1ba;
  short local_1b8;
  short local_1b2;
  short local_5a;
  undefined2 local_54;
  short local_52;
  undefined2 local_50;
  undefined2 local_4e;
  undefined2 local_4c;
  undefined2 local_4a;
  uint local_48;
  uint local_44;
  uint local_40;
  int *local_3c;
  undefined4 *local_38;
  undefined1 *local_34;
  undefined4 *local_30;
  
  local_30 = &local_1ec;
  local_2e8 = 0;
  local_2e4 = 0;
  local_2e0 = 0;
  local_2dc = 0;
  local_2d8 = 0;
  local_2d4 = 0;
  local_2d0 = 0;
  local_2cc = 0;
  local_2c8 = 0;
  local_2c4 = 0;
  local_2c0 = 0;
  local_2bc = 0;
  local_2b8 = 0;
  local_2b4 = 0;
  memset(local_30,0,0x1a4);
  local_2b0 = 0;
  local_2ac = 0;
  local_2a8 = 0;
  local_2a4 = 0;
  local_2a0 = 0;
  local_29c = 0;
  local_298 = 0;
  local_294 = 0;
  local_290 = 0;
  local_28c = 0;
  local_288 = 0;
  local_284 = 0;
  local_280 = 0;
  local_27c = 0;
  if (*(int *)(this + 0xe0) == 2) {
    iVar4 = (**(code **)(*(int *)this + 0xf0))(this);
    if ((iVar4 == 0) && (param_3[2] != (MW_DVB_PROGRAM_INFO)0x0)) {
      return 0;
    }
    iVar4 = (**(code **)(*(int *)this + 0xf0))(this);
    if (iVar4 == 2) {
      if (param_3[2] == (MW_DVB_PROGRAM_INFO)0x0) {
        return 0;
      }
      iVar4 = *(int *)this;
    }
    else {
      iVar4 = *(int *)this;
    }
    iVar4 = (**(code **)(iVar4 + 0xf8))(this);
    if ((iVar4 == 0) && (param_3[0xe] != (MW_DVB_PROGRAM_INFO)0x1)) {
      return 0;
    }
    pcVar18 = *(code **)(*(int *)this + 0xf8);
  }
  else {
    iVar4 = (**(code **)(*(int *)this + 0xec))(this);
    if ((iVar4 == 0) && (param_3[2] != (MW_DVB_PROGRAM_INFO)0x0)) {
      return 0;
    }
    iVar4 = (**(code **)(*(int *)this + 0xec))(this);
    if ((iVar4 == 2) && (param_3[2] == (MW_DVB_PROGRAM_INFO)0x0)) {
      return 0;
    }
    iVar4 = (**(code **)(*(int *)this + 0xf4))(this);
    if ((iVar4 == 0) && (param_3[0xe] != (MW_DVB_PROGRAM_INFO)0x1)) {
      return 0;
    }
    pcVar18 = *(code **)(*(int *)this + 0xf4);
  }
  iVar4 = (*pcVar18)(this);
  if ((iVar4 == 2) && (param_3[0xe] != (MW_DVB_PROGRAM_INFO)0x2)) {
    return 0;
  }
  MSrv_Control_common::GetMSrvSystemDatabase();
  iVar4 = MSrv_System_Database::GetSatOperator();
  if (((iVar4 == 0xb) && (iVar4 = (**(code **)(**(int **)(this + 0x130) + 0x70))(), iVar4 == 2)) &&
     (*(short *)(param_2 + 0x4c) == 0x82)) {
    iVar4 = (**(code **)(**(int **)(this + 0x130) + 0x48))(*(int **)(this + 0x130),1,auStack_278);
    if (iVar4 == 0) {
      return 0;
    }
    local_38 = &local_2e8;
    (**(code **)(*(int *)this + 0x18c))(this,local_38,&local_2b0,param_2,auStack_278);
    local_34 = auStack_234;
    (**(code **)(*(int *)this + 0x188))(this,local_34,auStack_278);
    iVar4 = *(int *)this;
  }
  else {
    local_38 = &local_2e8;
    (**(code **)(*(int *)this + 0x18c))(this,local_38,&local_2b0,param_2,this + 0x1c8);
    local_34 = auStack_234;
    (**(code **)(*(int *)this + 0x188))(this,local_34,this + 0x1c8);
    iVar4 = *(int *)this;
  }
  (**(code **)(iVar4 + 0x184))(this,local_30,param_3);
  MSrv_Control_common::GetMSrvSystemDatabase();
  iVar4 = MSrv_System_Database::GetSatOperator();
  if (iVar4 == 8) {
    if (*(int *)(this + 0xe0) == 0xd) {
      bVar1 = true;
      goto LAB_2e973d18;
    }
    if (*(int *)(this + 0xe0) != 2) goto LAB_2e973d14;
    bVar1 = false;
    iVar7 = (**(code **)(**(int **)(this + 0x130) + 0x70))();
    local_40 = (uint)(iVar7 == 0);
LAB_2e973d30:
    if (((iVar4 - 0xbU < 2) && (*(int *)(this + 0xe0) == 2)) &&
       (iVar7 = (**(code **)(**(int **)(this + 0x130) + 0x70))(), iVar7 == 2)) {
      local_44 = 0;
      local_48 = 1;
      uVar17 = 0;
    }
    else {
      local_44 = 0;
      local_48 = 0;
      uVar17 = 0;
    }
  }
  else {
LAB_2e973d14:
    bVar1 = false;
LAB_2e973d18:
    if ((iVar4 == 0xd) && (*(int *)(this + 0xe0) == 2)) {
      local_44 = 0;
      uVar17 = 1;
      iVar7 = (**(code **)(**(int **)(this + 0x130) + 0x70))();
      if (iVar7 != 2) {
LAB_2e9742e0:
        uVar17 = 0;
        local_40 = 0;
        local_48 = 0;
        goto LAB_2e973d4c;
      }
    }
    else {
      local_40 = 0;
      if (iVar4 != 9) goto LAB_2e973d30;
      uVar17 = 0;
      if (*(int *)(this + 0xe0) == 2) {
        local_44 = 1;
        iVar7 = (**(code **)(**(int **)(this + 0x130) + 0x70))();
        if (iVar7 != 2) {
          local_44 = 0;
          local_48 = 0;
          uVar17 = local_40;
          goto LAB_2e973d4c;
        }
        goto LAB_2e9742e0;
      }
    }
    local_44 = 0;
    local_40 = 0;
    local_48 = 0;
  }
LAB_2e973d4c:
  uVar3 = local_44;
  uVar2 = local_48;
  local_3c = *(int **)(this + 300);
  uVar16 = 0;
  (**(code **)(*local_3c + 8))(local_3c);
LAB_2e973d74:
  do {
    piVar10 = *(int **)(this + 300);
    while( true ) {
                    /* try { // try from 2e973d80 to 2e973da7 has its CatchHandler @ 2e9744f4 */
      uVar5 = (**(code **)(*piVar10 + 0x50))();
      if (uVar5 <= uVar16) goto LAB_2e973f70;
      puVar6 = (undefined4 *)
               (**(code **)(**(int **)(this + 300) + 0x3c))(*(int **)(this + 300),uVar16);
      if (puVar6 == (undefined4 *)0x0) {
                    /* try { // try from 2e974284 to 2e97428b has its CatchHandler @ 2e9744f4 */
        puts("MW_DTV_Scan_DVBS_Customer::SavePrograms Null");
        uVar16 = uVar16 + 1;
        goto LAB_2e973d74;
      }
      if ((bVar1) &&
         (((local_5a != *(short *)((int)puVar6 + 0x192) || (local_5a == 0)) ||
          (*(short *)((int)puVar6 + 0x19a) != local_52)))) goto LAB_2e973dc8;
                    /* try { // try from 2e973e7c to 2e973fab has its CatchHandler @ 2e9744f4 */
      iVar7 = (**(code **)(**(int **)(this + 300) + 0x84))
                        (*(int **)(this + 300),*(undefined2 *)(puVar6 + 1));
      if (iVar7 == 0) {
                    /* try { // try from 2e97440c to 2e974413 has its CatchHandler @ 2e9744f4 */
        printf("ASSERT FAIL: %s %s %d\n","./middleware/src/MW_DTV_Scan_DVBS_Customer.cpp",
               "virtual BOOL MW_DTV_Scan_DVBS_Customer::SavePrograms(U32, MW_DVB_TS_INFO*, MW_DVB_PROGRAM_INFO*)"
               ,0x149f);
                    /* WARNING: Subroutine does not return */
        abort();
      }
      iVar8 = CheckRange(*(ulong *)(iVar7 + 0x10),local_2d8,3);
      if (((iVar8 != 0) &&
          ((*(uint *)(iVar7 + 0x28) & 0x1ffffff) >> 0x18 == (local_2c0 & 0x1ffffff) >> 0x18)) &&
         ((((*(char *)(iVar7 + 0x29) == local_2c0._1_1_ &&
            (((uint)*(ushort *)(iVar7 + 8) == (local_2e0 & 0xffff) &&
             ((uint)*(ushort *)(iVar7 + 0xc) == (local_2dc & 0xffff))))) &&
           (*(short *)(iVar7 + 6) == local_2e4._2_2_)) &&
          ((*(short *)((int)puVar6 + 0x3a) == local_1b2 &&
           (iVar8 = CheckRange(*(ulong *)(iVar7 + 0x20),local_2c8,10), iVar8 != 0)))))) {
        if ((local_40 != 0) &&
           ((*(short *)((int)puVar6 + 0x192) != 0 && (*(char *)((int)puVar6 + 0x11) == '\0'))))
        goto LAB_2e973fb4;
        if ((uVar17 != 0) ||
           (((iVar4 != 10 && (iVar4 != 0xd)) || (*(short *)((int)puVar6 + 0x19a) == local_52)))) {
          local_1e8 = *(undefined2 *)(puVar6 + 1);
          local_1ec = *puVar6;
          if (((local_44 | local_48 | uVar17) & 0xff) == 0) {
            if (local_1b8 == -1) {
              *(byte *)(puVar6 + 10) = *(byte *)(puVar6 + 10) | 0x10;
            }
            else {
              *(byte *)(puVar6 + 10) = *(byte *)(puVar6 + 10) & 0xef;
            }
          }
          else {
            local_1b8 = *(short *)(puVar6 + 0xd);
            local_52 = *(short *)((int)puVar6 + 0x19a);
          }
          if (local_1b8 == -2) {
            *(byte *)(puVar6 + 10) = *(byte *)(puVar6 + 10) | 8;
          }
          else {
            *(byte *)(puVar6 + 10) = *(byte *)(puVar6 + 10) & 0xf7;
          }
          local_1c4 = *(byte *)(puVar6 + 10);
          if (*(char *)((int)puVar6 + 0x11) == '\0') {
            if ((iVar4 != 0) && (local_1b8 != *(short *)(puVar6 + 0xd))) {
              local_1c4 = local_1c4 | 1;
            }
            local_1ba = *(undefined2 *)((int)puVar6 + 0x32);
            local_1d7 = *(undefined1 *)((int)puVar6 + 0x15);
            local_1d6 = *(undefined1 *)((int)puVar6 + 0x16);
          }
          else {
            if (local_40 != 0) {
              uStack_1db = 0;
            }
            local_1c4 = local_1c4 | 1;
          }
          local_4e = *(undefined2 *)((int)puVar6 + 0x19e);
          local_50 = *(undefined2 *)(puVar6 + 0x67);
          local_4c = *(undefined2 *)(puVar6 + 0x68);
          local_4a = *(undefined2 *)((int)puVar6 + 0x1a2);
          local_54 = *(undefined2 *)(puVar6 + 0x66);
          local_1c0 = *(undefined2 *)(puVar6 + 0xb);
          if (local_48 != 0) {
            uStack_1dd = 1;
          }
          puVar13 = local_30;
          puVar14 = puVar6;
          do {
            uVar15 = *puVar13;
            uVar9 = puVar13[1];
            uVar11 = puVar13[2];
            uVar12 = puVar13[3];
            puVar13 = puVar13 + 4;
            *puVar14 = uVar15;
            puVar14[1] = uVar9;
            puVar14[2] = uVar11;
            puVar14[3] = uVar12;
            puVar14 = puVar14 + 4;
          } while (puVar13 != (undefined4 *)&local_4c);
          *puVar14 = *puVar13;
          (**(code **)(**(int **)(this + 300) + 0x28))(*(int **)(this + 300),puVar6);
          uVar15 = 1;
          goto LAB_2e973fb8;
        }
        goto LAB_2e973dc8;
      }
                    /* try { // try from 2e97400c to 2e97423f has its CatchHandler @ 2e9744f4 */
      if (((uVar3 == 0 && uVar2 == 0) ||
          (iVar8 = CheckRange(*(ulong *)(iVar7 + 0x10),local_2d8,3), iVar8 == 0)) ||
         (((*(uint *)(iVar7 + 0x28) & 0x1ffffff) >> 0x18 != (local_2c0 & 0x1ffffff) >> 0x18 ||
          ((((*(char *)(iVar7 + 0x29) != local_2c0._1_1_ ||
             ((uint)*(ushort *)(iVar7 + 0xc) != (local_2dc & 0xffff))) ||
            (*(short *)((int)puVar6 + 0x3a) != local_1b2)) ||
           (iVar7 = CheckRange(*(ulong *)(iVar7 + 0x20),local_2c8,10), iVar7 == 0)))))) break;
      if ((local_48 == 0) || (uVar16 = uVar16 + 1, *(char *)((int)puVar6 + 0xf) != '\0'))
      goto LAB_2e973fb4;
      piVar10 = *(int **)(this + 300);
    }
    if (bVar1) {
      uStack_1db = *(undefined1 *)((int)puVar6 + 0x11);
      uStack_1da = *(undefined1 *)((int)puVar6 + 0x12);
      local_1d7 = *(undefined1 *)((int)puVar6 + 0x15);
      local_1d6 = *(undefined1 *)((int)puVar6 + 0x16);
      local_1ba = *(undefined2 *)((int)puVar6 + 0x32);
      if (local_1b8 == -1) {
        *(byte *)(puVar6 + 10) = *(byte *)(puVar6 + 10) | 0x10;
      }
      else {
        *(byte *)(puVar6 + 10) = *(byte *)(puVar6 + 10) & 0xef;
      }
      if (local_1b8 == -2) {
        *(byte *)(puVar6 + 10) = *(byte *)(puVar6 + 10) | 8;
      }
      else {
        *(byte *)(puVar6 + 10) = *(byte *)(puVar6 + 10) & 0xf7;
      }
      local_1c4 = *(byte *)(puVar6 + 10);
      local_50 = *(undefined2 *)(puVar6 + 0x67);
      local_4e = *(undefined2 *)((int)puVar6 + 0x19e);
      local_4c = *(undefined2 *)(puVar6 + 0x68);
      local_4a = *(undefined2 *)((int)puVar6 + 0x1a2);
      local_54 = *(undefined2 *)(puVar6 + 0x66);
      (**(code **)(**(int **)(this + 300) + 0x24))(*(int **)(this + 300),puVar6);
LAB_2e973f70:
      if (((iVar4 == 0xd) || (iVar4 == 9)) && (*(int *)(this + 0xe0) == 2)) {
        local_1c4 = local_1c4 | 2;
      }
      iVar4 = (**(code **)(**(int **)(this + 300) + 0x18))
                        (*(int **)(this + 300),1,local_30,local_38,&local_2b0,local_34,0);
      uVar15 = 0;
      if (iVar4 != 0) {
LAB_2e973fb4:
        uVar15 = 1;
      }
LAB_2e973fb8:
      (**(code **)(*local_3c + 0xc))(local_3c);
      return uVar15;
    }
LAB_2e973dc8:
    uVar16 = uVar16 + 1;
  } while( true );
}

