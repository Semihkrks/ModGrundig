
/* MW_DVB_SI_PSI_Parser_Customer::_GetNitLCN(MAPI_SI_TS_INFO*, MW_DVB_PROGRAM_INFO&, unsigned short)
    */

undefined4 __thiscall
MW_DVB_SI_PSI_Parser_Customer::_GetNitLCN
          (MW_DVB_SI_PSI_Parser_Customer *this,MAPI_SI_TS_INFO *param_1,MW_DVB_PROGRAM_INFO *param_2
          ,ushort param_3)

{
  MAPI_SI_TS_INFO *pMVar1;
  short sVar2;
  MAPI_SI_TS_INFO *pMVar3;
  int iVar4;
  
  if (this[0x1114] != (MW_DVB_SI_PSI_Parser_Customer)0xff) {
    iVar4 = 0;
    pMVar3 = param_1;
    do {
      pMVar1 = pMVar3 + 0x1ea;
      pMVar3 = pMVar3 + 10;
      if (*(ushort *)pMVar1 == param_3) {
        sVar2 = *(short *)(param_1 + iVar4 * 10 + 0x1ec);
        *(short *)(param_2 + 0x1c) = sVar2;
        *(undefined2 *)(param_2 + 0x1e) = *(undefined2 *)(param_1 + iVar4 * 10 + 0x1ee);
        if ((sVar2 == 0) && (1 < *(int *)(this + 0x168) - 0x19U)) {
          param_1[iVar4 * 10 + 0x1f0] = (MAPI_SI_TS_INFO)0x0;
          param_1[iVar4 * 10 + 0x1f1] = (MAPI_SI_TS_INFO)0x0;
        }
        *(MAPI_SI_TS_INFO *)(param_2 + 3) = param_1[iVar4 * 10 + 0x1f1];
        *(MAPI_SI_TS_INFO *)(param_2 + 4) = param_1[iVar4 * 10 + 0x1f0];
        *(MAPI_SI_TS_INFO *)(param_2 + 0x166) = param_1[iVar4 * 10 + 499];
        *(MAPI_SI_TS_INFO *)(param_2 + 8) = param_1[iVar4 * 10 + 0x1f2];
        return 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0x78);
  }
  return 1;
}

