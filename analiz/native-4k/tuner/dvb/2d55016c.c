
/* MW_DVB_SI_PSI_Parser::_PmtReady(_DVB_PROGRAMINFO*, MW_DTV_CM_DB<_DVB_PROGRAMINFO, _DVB_MUXINFO,
   _ST_DVB_SAT_INFO, _ST_DVB_NETWORK_INFO>*, _DVB_MUXINFO*, _ST_DVB_NETWORK_INFO*, unsigned long) */

void __thiscall
MW_DVB_SI_PSI_Parser::_PmtReady
          (MW_DVB_SI_PSI_Parser *this,_DVB_PROGRAMINFO *param_1,MW_DTV_CM_DB *param_2,
          _DVB_MUXINFO *param_3,_ST_DVB_NETWORK_INFO *param_4,ulong param_5)

{
  MW_DVB_SI_PSI_Parser MVar1;
  short sVar2;
  uint uVar3;
  undefined4 *puVar4;
  MAPI_SI_TABLE_PMT *pMVar5;
  undefined2 uVar6;
  int iVar7;
  mapi_si_PMT_parser *this_00;
  _DVB_PROGRAMINFO *p_Var8;
  undefined4 uVar9;
  int *piVar10;
  uint uVar11;
  short *psVar12;
  MW_DVB_SI_PSI_Parser *pMVar13;
  MAPI_SI_TABLE_PMT *pMVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  MW_DVB_SI_PSI_Parser *pMVar17;
  MW_DVB_SI_PSI_Parser *pMVar18;
  MW_DVB_SI_ServicelInfo *pMVar19;
  MAPI_SI_TABLE_PMT *pMVar20;
  undefined4 *puVar21;
  int iVar22;
  MW_DVB_SI_PSI_Parser *pMVar23;
  MW_DVB_SI_ServicelInfo *pMVar24;
  code *pcVar25;
  undefined1 local_9d0 [4];
  MW_DTV_CM_DB_scope_lock aMStack_9cc [4];
  undefined2 local_9c8;
  undefined2 local_9c6;
  undefined2 local_9c4;
  byte local_9c2;
  MW_DVB_SI_PSI_Parser local_9c1;
  MW_DVB_SI_ServicelInfo aMStack_9c0 [744];
  undefined2 local_6d8;
  undefined2 local_6d4;
  undefined2 local_6d2;
  undefined2 local_6d0;
  undefined4 local_6cc [187];
  MAPI_SI_TABLE_PMT local_3e0 [4];
  byte local_3dc [4];
  undefined4 local_3d8;
  undefined4 local_3d4 [231];
  MW_DVB_SI_PSI_Parser local_38;
  undefined2 local_36;
  undefined4 local_30;
  MW_DVB_SI_PSI_Parser *local_2c;
  
  if (*(ushort *)(this + 0x408) != 0) {
    pMVar14 = *(MAPI_SI_TABLE_PMT **)(this + 0x224);
    iVar22 = 0;
    pMVar13 = this;
    while( true ) {
      if (pMVar14 == (MAPI_SI_TABLE_PMT *)param_5) {
        iVar7 = mapi_si_PMT_parser::GetTable(pMVar14);
        if (iVar7 != 0) {
          iVar22 = iVar22 + 0x100;
          pcVar25 = *(code **)(*(int *)this + 0x1c4);
          *(undefined2 *)(this + 0xc8c) = *(undefined2 *)(this + iVar22 * 4 + 0xc);
          (*pcVar25)(this,5,this + 0x5f8,this + 0x9a4);
          if (*(code **)(this + 0xd3744) != (code *)0x0) {
            (**(code **)(this + 0xd3744))(0xb,this + 0x9a4,*(undefined4 *)(this + 0xd3748),0);
          }
          uVar11 = (uint)*(ushort *)(this + 0x408);
          if (uVar11 != 0) {
            iVar7 = 0;
            pMVar13 = this;
            do {
              if (*(int *)(pMVar13 + 0x224) != 0) {
                (**(code **)(*(int *)this + 0x1c8))(this,*(int *)(pMVar13 + 0x224),0);
                uVar11 = (uint)*(ushort *)(this + 0x408);
              }
              iVar7 = iVar7 + 1;
              pMVar13 = pMVar13 + 4;
            } while (iVar7 < (int)uVar11);
          }
          *(undefined2 *)(this + 0x408) = 1;
          uVar6 = *(undefined2 *)(this + iVar22 * 4 + 10);
          *(undefined2 *)(this + 0x40c) = *(undefined2 *)(this + iVar22 * 4 + 0xc);
          *(undefined2 *)(this + 0x40a) = uVar6;
          return;
        }
        uVar11 = (uint)*(ushort *)(this + 0x408);
        if (uVar11 == 0) {
          return;
        }
        iVar22 = 0;
        pMVar13 = this;
        do {
          if (*(int *)(pMVar13 + 0x224) != 0) {
            (**(code **)(*(int *)this + 0x1c8))(this,*(int *)(pMVar13 + 0x224),0);
            uVar11 = (uint)*(ushort *)(this + 0x408);
          }
          iVar22 = iVar22 + 1;
          pMVar13 = pMVar13 + 4;
        } while (iVar22 < (int)uVar11);
        return;
      }
      iVar22 = iVar22 + 1;
      if ((int)(uint)*(ushort *)(this + 0x408) <= iVar22) break;
      pMVar14 = *(MAPI_SI_TABLE_PMT **)(pMVar13 + 0x228);
      pMVar13 = pMVar13 + 4;
    }
  }
  pMVar13 = this + 0xd37ec;
  iVar22 = 0;
  do {
    if (*(ulong *)pMVar13 == param_5) {
      iVar7 = mapi_si_PMT_parser::GetTable((MAPI_SI_TABLE_PMT *)param_5);
      if (iVar7 == 0) {
        (**(code **)(*(int *)this + 0x1c8))
                  (this,*(undefined4 *)(this + (iVar22 + 0x34dfa) * 4 + 4),0);
        return;
      }
      (**(code **)(*(int *)this + 0x1c8))(this,*(undefined4 *)(this + (iVar22 + 0x34dfa) * 4 + 4),0)
      ;
      if (local_3d8._2_2_ != *(short *)(this + iVar22 * 6 + 0xd37c0)) {
        return;
      }
      if (*(short *)(this + 0xf20) != *(short *)(this + iVar22 * 6 + 0xd37be)) {
        return;
      }
      MW_DTV_CM_DB_scope_lock::MW_DTV_CM_DB_scope_lock(aMStack_9cc,param_2);
                    /* try { // try from 2d550644 to 2d55066f has its CatchHandler @ 2d550c3c */
      p_Var8 = (_DVB_PROGRAMINFO *)
               (**(code **)(*(int *)param_2 + 0x44))
                         (param_2,*(undefined2 *)(this + iVar22 * 6 + 0xd37be),
                          *(undefined2 *)(this + iVar22 * 6 + 0xd37bc),
                          *(undefined2 *)(this + iVar22 * 6 + 0xd37c0));
      if (p_Var8 != (_DVB_PROGRAMINFO *)0x0) {
        _UpdateSpecialServicePmtInfo(this,p_Var8,param_2,param_3,local_3e0);
      }
      goto LAB_2d550674;
    }
    iVar22 = iVar22 + 1;
    pMVar13 = pMVar13 + 4;
  } while (iVar22 != 8);
  if ((*(ulong *)(this + 0x218) == 0) || (*(ulong *)(this + 0x218) != param_5)) {
    pMVar14 = *(MAPI_SI_TABLE_PMT **)(this + 0x214);
    if ((pMVar14 != (MAPI_SI_TABLE_PMT *)0x0) && (pMVar14 == (MAPI_SI_TABLE_PMT *)param_5)) {
      iVar22 = *(int *)(this + 0x1c248);
      MVar1 = this[0x1c24c];
      pMVar13 = this + 0x1c248;
      pMVar5 = local_3e0;
      do {
        pMVar20 = pMVar5;
        pMVar23 = pMVar13;
        uVar15 = *(undefined4 *)(pMVar23 + 8);
        uVar16 = *(undefined4 *)(pMVar23 + 0xc);
        uVar9 = *(undefined4 *)pMVar23;
        pMVar13 = pMVar23 + 0x10;
        *(undefined4 *)(pMVar20 + 4) = *(undefined4 *)(pMVar23 + 4);
        *(undefined4 *)pMVar20 = uVar9;
        *(undefined4 *)(pMVar20 + 8) = uVar15;
        *(undefined4 *)(pMVar20 + 0xc) = uVar16;
        pMVar5 = pMVar20 + 0x10;
      } while (pMVar13 != this + 0x1c5e8);
      uVar15 = *(undefined4 *)pMVar13;
      uVar9 = *(undefined4 *)(pMVar23 + 0x18);
      local_2c = this + 0x1c248;
      *(undefined4 *)(pMVar20 + 0x14) = *(undefined4 *)(pMVar23 + 0x14);
      *(undefined4 *)(pMVar20 + 0x18) = uVar9;
      *(undefined4 *)(pMVar20 + 0x10) = uVar15;
      iVar7 = mapi_si_PMT_parser::GetTable(pMVar14);
      if (iVar7 != 0) {
        (**(code **)(*(int *)this + 0x1c8))(this,*(undefined4 *)(this + 0x214),0);
        if (*(int *)(this + 0xd2d78) == 1) {
          return;
        }
        if (*(int *)(this + 0xd2d78) == 3) {
          pMVar13 = local_2c;
          pMVar23 = this + 0xd3194;
          do {
            pMVar18 = pMVar23;
            pMVar17 = pMVar13;
            uVar9 = *(undefined4 *)(pMVar17 + 4);
            uVar15 = *(undefined4 *)(pMVar17 + 8);
            uVar16 = *(undefined4 *)(pMVar17 + 0xc);
            pMVar13 = pMVar17 + 0x10;
            *(undefined4 *)pMVar18 = *(undefined4 *)pMVar17;
            *(undefined4 *)(pMVar18 + 4) = uVar9;
            *(undefined4 *)(pMVar18 + 8) = uVar15;
            *(undefined4 *)(pMVar18 + 0xc) = uVar16;
            pMVar23 = pMVar18 + 0x10;
          } while (pMVar13 != local_2c + 0x3a0);
          uVar15 = *(undefined4 *)(pMVar17 + 0x14);
          uVar9 = *(undefined4 *)pMVar13;
          *(undefined4 *)(pMVar18 + 0x18) = *(undefined4 *)(pMVar17 + 0x18);
          *(undefined4 *)(pMVar18 + 0x14) = uVar15;
          *(undefined4 *)(pMVar18 + 0x10) = uVar9;
          (**(code **)(this + 0xd3744))(0x10,0,*(undefined4 *)(this + 0xd3748),0);
          return;
        }
        iVar7 = _IsPmtContentDiff((MAPI_SI_TABLE_PMT *)this,local_3e0);
        if (iVar7 == 0) {
          return;
        }
        iVar7 = (**(code **)(*(int *)this + 0x1ac))(this);
        if ((iVar7 != 0) && (this[0x1c5f0] == (MW_DVB_SI_PSI_Parser)0x1)) {
          local_9c4 = *(undefined2 *)(this + 0x1c5f2);
          local_9c8 = (undefined2)*(undefined4 *)(param_3 + 0x10);
          local_9c6 = (undefined2)*(undefined4 *)(param_3 + 0x20);
          local_9c2 = (byte)((uint)(*(int *)(param_3 + 0x28) << 7) >> 0x1f);
          local_9c1 = this[0x1c5f0];
          piVar10 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
          (**(code **)(*piVar10 + 0x2a4))(piVar10,&local_9c8,0);
          (**(code **)(*(int *)this + 0x1a8))(this,*(undefined2 *)(this + 0x1c5f2));
          uVar6 = *(undefined2 *)(this + 0xd3784);
          pcVar25 = *(code **)(*(int *)this + 0x1a4);
          piVar10 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
          uVar9 = (**(code **)(*piVar10 + 0x27c))(piVar10);
          (*pcVar25)(this,0,uVar6,uVar9);
        }
        if (*(int *)(this + 0xd2d78) == 2) {
          return;
        }
        *(undefined2 *)(this + 0x10) = 0;
        *(undefined2 *)(this + 0x12) = 0;
        *(undefined4 *)(this + 0xc) = 0;
        uVar6 = __GetID(param_1,param_3,param_4,4);
        *(undefined2 *)(this + 0xd10f4) = uVar6;
        if ((this[0x186] != this[0x1c24c]) || (uVar9 = 0, *(int *)(this + 0x1c248) != iVar22)) {
          uVar9 = 2;
        }
        pMVar24 = (MW_DVB_SI_ServicelInfo *)(this + 0xd0e0c);
        (**(code **)(*(int *)this + 0x1c4))(this,uVar9,local_2c,pMVar24);
        if (this[0x186] == this[0x1c24c]) {
          if (*(int *)(this + 0x1c248) == iVar22) goto LAB_2d550ac4;
        }
        else {
          this[0x186] = this[0x1c24c];
          __SetVer(*(undefined4 *)(this + 0x150),2);
        }
        if (this[0xd0e16] != *(MW_DVB_SI_PSI_Parser *)(param_1 + 0x14)) {
          local_9d0[0] = 1;
        }
        iVar22 = __UpdateService(param_1,pMVar24,param_2,'\x01');
        if (((iVar22 == 0) && (*(int *)(this + 0xd0e10) == 2)) &&
           (MVar1 != (MW_DVB_SI_PSI_Parser)0xfe)) {
          *(undefined4 *)(this + 0xd0e10) = 5;
        }
        *(undefined4 *)(this + 0x50) = 0;
        if (*(int *)(this + 0xd0e10) == 1) {
          MW_DTV_CM_DB_scope_lock::MW_DTV_CM_DB_scope_lock
                    (aMStack_9cc,*(MW_DTV_CM_DB **)(this + 0x154));
                    /* try { // try from 2d550e90 to 2d550e97 has its CatchHandler @ 2d550fd8 */
          iVar22 = (**(code **)(**(int **)(this + 0x154) + 0x44))
                             (*(int **)(this + 0x154),*(undefined2 *)(this + 0x1c3ee),
                              *(undefined2 *)(this + 0x1c3ec),*(undefined2 *)(this + 0x1c3f0));
          if (iVar22 == 0) {
            MW_DTV_CM_DB_scope_lock::~MW_DTV_CM_DB_scope_lock(aMStack_9cc);
            if ((*(int *)(this + 0x38) - *(int *)(this + 0x34) >> 1) * 0x55555555 != 0) {
              uVar11 = 0;
              do {
                psVar12 = (short *)std::
                                   vector<MW_SI_SDT_OTHER_TS,std::allocator<MW_SI_SDT_OTHER_TS>>::at
                                             ((vector<MW_SI_SDT_OTHER_TS,std::allocator<MW_SI_SDT_OTHER_TS>>
                                               *)(this + 0x34),uVar11);
                if (*psVar12 == *(short *)(this + 0x1c3ee)) {
                  uVar3 = (*(int *)(this + 0x38) - *(int *)(this + 0x34) >> 1) * -0x55555555;
                  if (uVar11 < uVar3) {
                    uVar11 = uVar11 + 1 & 0xff;
                    if (uVar3 <= uVar11) {
                      uVar11 = 0;
                    }
                    if ((*(int *)(this + 0xc9c) != 0) && ((byte)this[0x30] != uVar11)) {
                      (**(code **)(*(int *)this + 0x1c8))(this,*(int *)(this + 0xc9c),0);
                    }
                    *(undefined4 *)(this + 0x1b0) = 0;
                  }
                  break;
                }
                uVar11 = uVar11 + 1 & 0xffff;
              } while (uVar11 < (uint)((*(int *)(this + 0x38) - *(int *)(this + 0x34) >> 1) *
                                      -0x55555555));
              uVar9 = (**(code **)(*(int *)this + 0x270))(this);
              *(undefined4 *)(this + 0x50) = uVar9;
              this[0x1c24c] = (MW_DVB_SI_PSI_Parser)0xfe;
              this[0x186] = (MW_DVB_SI_PSI_Parser)0xfe;
            }
          }
          else {
            MW_DTV_CM_DB_scope_lock::~MW_DTV_CM_DB_scope_lock(aMStack_9cc);
            if (*(code **)(this + 0xd3744) != (code *)0x0) {
              (**(code **)(this + 0xd3744))(6,pMVar24,*(undefined4 *)(this + 0xd3748),0);
            }
            *(undefined4 *)(this + 0xd0e10) = 0;
          }
        }
        else if (*(int *)(this + 0xd0e10) != 0) {
          uVar11 = __GetID(param_1,param_3,param_4,0);
          pMVar13 = this + 0xd37c0;
          iVar22 = 0;
LAB_2d550d8c:
          if ((*(ushort *)pMVar13 != uVar11) ||
             (*(ushort *)(this + 0xf20) != *(ushort *)(pMVar13 + -2))) goto LAB_2d550d84;
          pMVar19 = pMVar24;
          puVar4 = local_6cc;
          do {
            puVar21 = puVar4;
            pMVar13 = (MW_DVB_SI_PSI_Parser *)pMVar19;
            uVar9 = *(undefined4 *)(pMVar13 + 4);
            uVar15 = *(undefined4 *)(pMVar13 + 8);
            uVar16 = *(undefined4 *)(pMVar13 + 0xc);
            pMVar19 = (MW_DVB_SI_ServicelInfo *)(pMVar13 + 0x10);
            *puVar21 = *(undefined4 *)pMVar13;
            puVar21[1] = uVar9;
            puVar21[2] = uVar15;
            puVar21[3] = uVar16;
            puVar4 = puVar21 + 4;
          } while (pMVar19 != (MW_DVB_SI_ServicelInfo *)(this + 0xd10ec));
          uVar9 = *(undefined4 *)pMVar19;
          uVar15 = *(undefined4 *)(pMVar13 + 0x14);
          puVar21[6] = *(undefined4 *)(pMVar13 + 0x18);
          puVar21[4] = uVar9;
          puVar21[5] = uVar15;
          local_6d4 = *(undefined2 *)(this + iVar22 * 6 + 0xd37be);
          local_6d2 = *(undefined2 *)(this + iVar22 * 6 + 0xd37bc);
          pcVar25 = (code *)0x0;
          local_6d0 = *(undefined2 *)(this + iVar22 * 6 + 0xd37c0);
          if (*(code **)(this + 0xd3744) != (code *)0x0) {
            (**(code **)(this + 0xd3744))(0x18,&local_6d4,*(undefined4 *)(this + 0xd3748),local_9d0)
            ;
            pcVar25 = *(code **)(this + 0xd3744);
          }
          goto LAB_2d551068;
        }
        goto LAB_2d550ac4;
      }
      iVar22 = *(int *)this;
      uVar9 = *(undefined4 *)(this + 0x214);
      goto LAB_2d550ad8;
    }
  }
  else {
    iVar22 = mapi_si_PMT_parser::GetTable((MAPI_SI_TABLE_PMT *)param_5);
    if (iVar22 == 0) {
      iVar22 = *(int *)this;
      uVar9 = *(undefined4 *)(this + 0x218);
LAB_2d550ad8:
      (**(code **)(iVar22 + 0x1c8))(this,uVar9,0);
      return;
    }
    (**(code **)(*(int *)this + 0x1c8))(this,*(undefined4 *)(this + 0x218),0);
    local_30 = __GetID(param_1,param_3,param_4,2);
    uVar9 = __GetID(param_1,param_3,param_4,1);
    MW_DTV_CM_DB_scope_lock::MW_DTV_CM_DB_scope_lock(aMStack_9cc,param_2);
                    /* try { // try from 2d550778 to 2d55087f has its CatchHandler @ 2d550c60 */
    iVar22 = (**(code **)(*(int *)this + 0x1ac))(this);
    if ((iVar22 == 0) || (local_38 != (MW_DVB_SI_PSI_Parser)0x1)) {
      iVar22 = *(int *)param_2;
    }
    else {
      local_9c1 = local_38;
      local_9c4 = local_36;
      local_9c8 = (undefined2)*(undefined4 *)(param_3 + 0x10);
      local_9c6 = (undefined2)*(undefined4 *)(param_3 + 0x20);
      local_9c2 = (byte)((uint)(*(int *)(param_3 + 0x28) << 7) >> 0x1f);
                    /* try { // try from 2d550b2c to 2d550ba7 has its CatchHandler @ 2d550c60 */
      piVar10 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
      (**(code **)(*piVar10 + 0x2a4))(piVar10,&local_9c8,0);
      (**(code **)(*(int *)this + 0x1a8))(this,local_36);
      pcVar25 = *(code **)(*(int *)this + 0x1a4);
      uVar6 = *(undefined2 *)(this + 0xd3784);
      piVar10 = (int *)MSrv_Control_common::GetMSrvSystemDatabase();
      uVar15 = (**(code **)(*piVar10 + 0x27c))(piVar10);
      (*pcVar25)(this,0,uVar6,uVar15);
      iVar22 = *(int *)param_2;
    }
    p_Var8 = (_DVB_PROGRAMINFO *)
             (**(code **)(iVar22 + 0x44))(param_2,local_30,uVar9,local_3d8._2_2_);
    if (p_Var8 == (_DVB_PROGRAMINFO *)0x0) {
LAB_2d550674:
      MW_DTV_CM_DB_scope_lock::~MW_DTV_CM_DB_scope_lock(aMStack_9cc);
      return;
    }
    uVar11 = __GetVer(p_Var8,2);
    if (uVar11 != local_3dc[0]) {
      __SetVer(p_Var8,2);
      if (*(ushort *)(this + 0xf24) != 0) {
        iVar22 = 0;
        pMVar13 = this;
        do {
          if ((*(short *)(pMVar13 + 0xf26) != 0) && (*(short *)(pMVar13 + 0xf26) == local_3d8._2_2_)
             ) {
            uVar6 = *(undefined2 *)(this + (iVar22 + 0x3c8) * 4 + 8);
            goto LAB_2d55082c;
          }
          iVar22 = iVar22 + 1;
          pMVar13 = pMVar13 + 4;
        } while (iVar22 < (int)(uint)*(ushort *)(this + 0xf24));
      }
      uVar6 = 0x1fff;
LAB_2d55082c:
      memset(aMStack_9c0,0,0x2ec);
      local_6d8 = uVar6;
      (**(code **)(*(int *)this + 0x1c4))(this,2,local_3e0,aMStack_9c0);
      __UpdateService(p_Var8,aMStack_9c0,param_2,'\x01');
    }
    MW_DTV_CM_DB_scope_lock::~MW_DTV_CM_DB_scope_lock(aMStack_9cc);
  }
  iVar22 = 0;
  pMVar13 = this;
  do {
    if (((*(ulong *)(pMVar13 + 0xcbc) != 0) && (*(ulong *)(pMVar13 + 0xcbc) == param_5)) &&
       (iVar7 = mapi_si_PMT_parser::GetTable((MAPI_SI_TABLE_PMT *)param_5), iVar7 != 0)) {
      (**(code **)(*(int *)this + 0x1c8))(this,*(undefined4 *)(this + (iVar22 + 0x32e) * 4 + 4),0);
      this[iVar22 + 0xea8] = (MW_DVB_SI_PSI_Parser)0x0;
      break;
    }
    iVar22 = iVar22 + 1;
    pMVar13 = pMVar13 + 4;
  } while (iVar22 != 0x78);
  iVar22 = 0;
  pMVar13 = this;
  pMVar23 = this;
  do {
    while ((pMVar13[0xea8] != (MW_DVB_SI_PSI_Parser)0x1 || (*(int *)(pMVar23 + 0xcbc) != 0))) {
LAB_2d550314:
      iVar22 = iVar22 + 1;
      pMVar13 = pMVar13 + 1;
      pMVar23 = pMVar23 + 4;
      if (iVar22 == 0x78) {
        return;
      }
    }
    this_00 = operator_new(0x40c,(nothrow_t *)&DAT_2c7f5bd0);
    if (this_00 == (mapi_si_PMT_parser *)0x0) {
      *(undefined4 *)(this + (iVar22 + 0x32e) * 4 + 4) = 0;
      return;
    }
                    /* try { // try from 2d550364 to 2d55036b has its CatchHandler @ 2d550c90 */
    mapi_si_PMT_parser::mapi_si_PMT_parser
              (this_00,*(mapi_si_psi **)(this + 0x200),*(mapi_demux **)(this + 0xd37b8));
    iVar7 = *(int *)this_00;
    *(mapi_si_PMT_parser **)(pMVar23 + 0xcbc) = this_00;
    iVar7 = (**(code **)(iVar7 + 0x10))(this_00,0x400,_ParserCallback,this + 0xd10f8,0,0xff,0,0);
    if ((iVar7 != 0) &&
       (iVar7 = mapi_si_PMT_parser::Start
                          ((ushort)*(undefined4 *)(pMVar23 + 0xcbc),4000,
                           *(ushort *)(pMVar23 + 0xf26),(ulong)*(undefined2 *)(pMVar23 + 0xf28)),
       iVar7 != 0)) {
      sVar2 = *(short *)(this + 0x1d4);
      pMVar13[0xea8] = (MW_DVB_SI_PSI_Parser)0x0;
      *(short *)(this + 0x1d4) = sVar2 + 1;
      goto LAB_2d550314;
    }
    if (*(int **)(pMVar23 + 0xcbc) != (int *)0x0) {
      (**(code **)(**(int **)(pMVar23 + 0xcbc) + 4))();
    }
    iVar22 = iVar22 + 1;
    *(undefined4 *)(pMVar23 + 0xcbc) = 0;
    pMVar13 = pMVar13 + 1;
    pMVar23 = pMVar23 + 4;
    if (iVar22 == 0x78) {
      return;
    }
  } while( true );
LAB_2d550d84:
  iVar22 = iVar22 + 1;
  pMVar13 = pMVar13 + 6;
  if (iVar22 == 8) goto LAB_2d55105c;
  goto LAB_2d550d8c;
LAB_2d55105c:
  pcVar25 = *(code **)(this + 0xd3744);
LAB_2d551068:
  if (MVar1 == (MW_DVB_SI_PSI_Parser)0xfe) {
    if (pcVar25 != (code *)0x0) {
      (*pcVar25)(6,pMVar24,*(undefined4 *)(this + 0xd3748),0);
    }
  }
  else if (pcVar25 != (code *)0x0) {
    uVar9 = 1;
    if (*(int *)(this + 0xd3190) != *(int *)(this + 0x1c248)) {
      uVar9 = 0xd;
    }
    (*pcVar25)(uVar9,pMVar24,*(undefined4 *)(this + 0xd3748),local_9d0);
  }
  *(undefined4 *)(this + 0xd3190) = *(undefined4 *)(this + 0x1c248);
  *(undefined4 *)(this + 0xd0e10) = 0;
LAB_2d550ac4:
  this[0xd36fc] = (MW_DVB_SI_PSI_Parser)0x1;
  return;
}

