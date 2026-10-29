
/* MW_DVB_SI_PSI_Parser_Customer::_GetBatLCN(_MAPI_SI_BAT_TS_INFO*, MW_DVB_PROGRAM_INFO&, unsigned
   short) */

undefined1 __thiscall
MW_DVB_SI_PSI_Parser_Customer::_GetBatLCN
          (MW_DVB_SI_PSI_Parser_Customer *this,_MAPI_SI_BAT_TS_INFO *param_1,
          MW_DVB_PROGRAM_INFO *param_2,ushort param_3)

{
  _MAPI_SI_BAT_TS_INFO *p_Var1;
  ushort uVar2;
  bool bVar3;
  undefined1 uVar4;
  _MAPI_SI_BAT_TS_INFO *p_Var5;
  int iVar6;
  undefined1 uVar7;
  
  if ((this[0x26] != (MW_DVB_SI_PSI_Parser_Customer)0x0) &&
     (iVar6 = 0, param_1 != (_MAPI_SI_BAT_TS_INFO *)0x0)) {
    do {
      p_Var5 = param_1 + iVar6;
      iVar6 = iVar6 + 4;
      if (*(ushort *)p_Var5 == param_3) {
        bVar3 = true;
        break;
      }
      bVar3 = false;
    } while (iVar6 != 0x1e0);
    if (*(ushort *)(param_1 + 0xfc36) == 0) {
LAB_2e191cc8:
      uVar4 = 0;
      uVar7 = 0;
    }
    else {
      iVar6 = 0;
      uVar2 = *(ushort *)(param_1 + 0x1e0);
      p_Var5 = param_1;
      while (uVar2 != param_3) {
        iVar6 = iVar6 + 1;
        if ((int)(uint)*(ushort *)(param_1 + 0xfc36) <= iVar6) goto LAB_2e191cc8;
        p_Var1 = p_Var5 + 0x1ee;
        p_Var5 = p_Var5 + 0xe;
        uVar2 = *(ushort *)p_Var1;
      }
      *(undefined2 *)(param_2 + 0x1c) = *(undefined2 *)(param_1 + iVar6 * 0xe + 0x1e2);
      *(undefined2 *)(param_2 + 0x164) = *(undefined2 *)(param_1 + iVar6 * 0xe + 0x1e2);
      *(_MAPI_SI_BAT_TS_INFO *)(param_2 + 4) = param_1[iVar6 * 0xe + 0x1ea];
      *(_MAPI_SI_BAT_TS_INFO *)(param_2 + 3) = param_1[iVar6 * 0xe + 0x1eb];
      uVar4 = 1;
      uVar7 = 1;
      if (*(int *)(this + 0xd2d70) == 6) {
        uVar4 = 1;
        uVar7 = 1;
        *(undefined2 *)(param_2 + 0x16c) = *(undefined2 *)(param_1 + iVar6 * 0xe + 0x1e8);
        *(undefined2 *)(param_2 + 0x16a) = *(undefined2 *)(param_1 + iVar6 * 0xe + 0x1e6);
      }
    }
    if (*(int *)(this + 0x170) != 2) {
      if ((*(int *)(this + 0x170) == 1) && (*(int *)(this + 0xd2d6c) == 0xd)) {
        if (!bVar3) {
          return 0;
        }
        return uVar7;
      }
      return 1;
    }
    iVar6 = *(int *)(this + 0xd2d70);
    if (iVar6 == 6) {
      return uVar4;
    }
    if (((iVar6 != 5) && (1 < iVar6 - 0xbU)) && (iVar6 != 0xd)) {
      return 1;
    }
    if (bVar3) {
      return uVar7;
    }
  }
  return 0;
}

