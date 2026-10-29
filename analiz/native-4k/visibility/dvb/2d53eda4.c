
/* MW_DVB_SI_PSI_Parser::_AddCommonProgramInfo(_DVB_PROGRAMINFO&, MW_DVB_PROGRAM_INFO*) */

void __thiscall
MW_DVB_SI_PSI_Parser::_AddCommonProgramInfo
          (MW_DVB_SI_PSI_Parser *this,_DVB_PROGRAMINFO *param_1,MW_DVB_PROGRAM_INFO *param_2)

{
  _DVB_PROGRAMINFO _Var1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  MW_DVB_PROGRAM_INFO *pMVar10;
  _DVB_PROGRAMINFO *p_Var11;
  
  if (param_2 != (MW_DVB_PROGRAM_INFO *)0x0) {
    pMVar10 = param_2 + 0x20;
    p_Var11 = param_1 + 0x4e;
    *(undefined2 *)(param_1 + 0x2e) = *(undefined2 *)(param_2 + 0x12);
    *(undefined2 *)(param_1 + 0x30) = *(undefined2 *)(param_2 + 0x16);
    *(undefined2 *)(param_1 + 0x34) = *(undefined2 *)(param_2 + 0x1c);
    *(undefined2 *)(param_1 + 0x32) = *(undefined2 *)(param_2 + 0x1c);
    *(undefined2 *)(param_1 + 0x38) = *(undefined2 *)(param_2 + 0x10);
    *(undefined2 *)(param_1 + 0x3a) = *(undefined2 *)param_2;
    *(undefined2 *)(param_1 + 0x3c) = *(undefined2 *)(param_2 + 0x1e);
    param_1[8] = *(_DVB_PROGRAMINFO *)(param_2 + 0xc);
    param_1[6] = *(_DVB_PROGRAMINFO *)(param_2 + 9);
    param_1[7] = *(_DVB_PROGRAMINFO *)(param_2 + 10);
    _Var1 = *(_DVB_PROGRAMINFO *)(param_2 + 0xb);
    *(undefined2 *)(param_1 + 0xc) = 0xfffd;
    param_1[9] = _Var1;
    param_1[0xf] = *(_DVB_PROGRAMINFO *)(param_2 + 4);
    _Var1 = *(_DVB_PROGRAMINFO *)(param_2 + 3);
    param_1[0x11] = (_DVB_PROGRAMINFO)0x0;
    param_1[0x12] = (_DVB_PROGRAMINFO)0x0;
    param_1[0x10] = _Var1;
    _Var1 = *(_DVB_PROGRAMINFO *)(param_2 + 2);
    param_1[0x15] = (_DVB_PROGRAMINFO)0x0;
    param_1[0x16] = (_DVB_PROGRAMINFO)0x0;
    param_1[0x14] = _Var1;
    param_1[0x13] = (_DVB_PROGRAMINFO)0x0;
    param_1[0x17] = *(_DVB_PROGRAMINFO *)(param_2 + 0x1a);
    param_1[0x18] = *(_DVB_PROGRAMINFO *)(param_2 + 5);
    param_1[0x1a] = *(_DVB_PROGRAMINFO *)(param_2 + 7);
    _Var1 = *(_DVB_PROGRAMINFO *)(param_2 + 6);
    param_1[0x1c] = (_DVB_PROGRAMINFO)0x0;
    param_1[0x1b] = _Var1;
    param_1[0x1d] = *(_DVB_PROGRAMINFO *)(param_2 + 0xe);
    param_1[0x1f] = *(_DVB_PROGRAMINFO *)(param_2 + 0xf);
    _Var1 = *(_DVB_PROGRAMINFO *)(param_2 + 0x14);
    param_1[0x1e] = (_DVB_PROGRAMINFO)0x0;
    param_1[0x19] = _Var1;
    param_1[0x22] = *(_DVB_PROGRAMINFO *)(param_2 + 8);
    do {
      uVar2 = *(undefined2 *)pMVar10;
      uVar3 = *(undefined2 *)(pMVar10 + 2);
      uVar4 = *(undefined2 *)(pMVar10 + 4);
      uVar5 = *(undefined2 *)(pMVar10 + 6);
      uVar6 = *(undefined2 *)(pMVar10 + 8);
      uVar7 = *(undefined2 *)(pMVar10 + 10);
      uVar8 = *(undefined2 *)(pMVar10 + 0xc);
      uVar9 = *(undefined2 *)(pMVar10 + 0xe);
      pMVar10 = pMVar10 + 0x10;
      *(undefined2 *)p_Var11 = uVar2;
      *(undefined2 *)(p_Var11 + 2) = uVar3;
      *(undefined2 *)(p_Var11 + 4) = uVar4;
      *(undefined2 *)(p_Var11 + 6) = uVar5;
      *(undefined2 *)(p_Var11 + 8) = uVar6;
      *(undefined2 *)(p_Var11 + 10) = uVar7;
      *(undefined2 *)(p_Var11 + 0xc) = uVar8;
      *(undefined2 *)(p_Var11 + 0xe) = uVar9;
      p_Var11 = p_Var11 + 0x10;
    } while (pMVar10 != param_2 + 0x100);
    p_Var11 = param_1 + 0x12e;
    do {
      uVar2 = *(undefined2 *)pMVar10;
      uVar3 = *(undefined2 *)(pMVar10 + 2);
      uVar4 = *(undefined2 *)(pMVar10 + 4);
      uVar5 = *(undefined2 *)(pMVar10 + 6);
      uVar6 = *(undefined2 *)(pMVar10 + 8);
      uVar7 = *(undefined2 *)(pMVar10 + 10);
      uVar8 = *(undefined2 *)(pMVar10 + 0xc);
      uVar9 = *(undefined2 *)(pMVar10 + 0xe);
      pMVar10 = pMVar10 + 0x10;
      *(undefined2 *)p_Var11 = uVar2;
      *(undefined2 *)(p_Var11 + 2) = uVar3;
      *(undefined2 *)(p_Var11 + 4) = uVar4;
      *(undefined2 *)(p_Var11 + 6) = uVar5;
      *(undefined2 *)(p_Var11 + 8) = uVar6;
      *(undefined2 *)(p_Var11 + 10) = uVar7;
      *(undefined2 *)(p_Var11 + 0xc) = uVar8;
      *(undefined2 *)(p_Var11 + 0xe) = uVar9;
      p_Var11 = p_Var11 + 0x10;
    } while (pMVar10 != param_2 + 0x130);
    *(undefined2 *)p_Var11 = *(undefined2 *)pMVar10;
  }
  return;
}

