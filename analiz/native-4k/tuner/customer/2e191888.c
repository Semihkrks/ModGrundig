
/* MW_DVB_SI_PSI_Parser_Customer::_CheckService(MW_DVB_TS_INFO&, MW_DVB_PROGRAM_INFO&) */

bool __thiscall
MW_DVB_SI_PSI_Parser_Customer::_CheckService
          (MW_DVB_SI_PSI_Parser_Customer *this,MW_DVB_TS_INFO *param_1,MW_DVB_PROGRAM_INFO *param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  bVar4 = param_2[0xe] != (MW_DVB_PROGRAM_INFO)0x7;
  if ((((*(int *)(this + 0x174) == 2) && (this[0x18788] == (MW_DVB_SI_PSI_Parser_Customer)0xff)) &&
      (*(short *)(param_2 + 0x16) == 0x1fff)) && (*(short *)(param_2 + 0x26) != 0x1fff)) {
    param_2[0xe] = (MW_DVB_PROGRAM_INFO)0x2;
  }
  else if ((param_2[0xe] == (MW_DVB_PROGRAM_INFO)0x3) &&
          (iVar2 = (**(code **)(*(int *)this + 700))(this,3,this + 0x168,0), iVar2 == 0)) {
    param_2[3] = (MW_DVB_PROGRAM_INFO)0x0;
    param_2[4] = (MW_DVB_PROGRAM_INFO)0x0;
    param_2[8] = (MW_DVB_PROGRAM_INFO)0x0;
  }
  iVar2 = *(int *)(this + 0xd2d6c);
  if ((iVar2 == 7) || (iVar2 == 4)) {
    iVar3 = *(int *)(this + 0x170);
    if (iVar3 == 1) {
      if (iVar2 == 4) {
        uVar1 = *(ushort *)(param_2 + 0x1c);
        bVar4 = uVar1 < 0x400 && bVar4;
        if (param_2[4] != (MW_DVB_PROGRAM_INFO)0x0) goto LAB_2e191900;
        param_2[3] = (MW_DVB_PROGRAM_INFO)0x0;
        iVar3 = *(int *)(this + 0x170);
      }
      else {
        if (param_2[4] == (MW_DVB_PROGRAM_INFO)0x0) {
          param_2[3] = (MW_DVB_PROGRAM_INFO)0x0;
          iVar3 = *(int *)(this + 0x170);
        }
        uVar1 = *(ushort *)(param_2 + 0x1c);
        bVar4 = uVar1 < 1000 && bVar4;
      }
    }
    else {
      uVar1 = *(ushort *)(param_2 + 0x1c);
    }
  }
  else {
    iVar3 = *(int *)(this + 0x170);
    uVar1 = *(ushort *)(param_2 + 0x1c);
  }
  if ((((iVar3 == 2) && (*(int *)(this + 0x1d8) != 4)) &&
      (param_2[0xd] != (MW_DVB_PROGRAM_INFO)0xd3)) &&
     (((*(short *)(param_2 + 0x16) == 0x1fff && (*(short *)(param_2 + 0x26) != 0x1fff)) &&
      (param_2[0xe] == (MW_DVB_PROGRAM_INFO)0x1)))) {
    param_2[0xe] = (MW_DVB_PROGRAM_INFO)0x2;
  }
LAB_2e191900:
  if (uVar1 == 0) {
    if (*(int *)(this + 0x168) == 8) {
      if ((*(int *)(this + 0x170) == 2) && (*(int *)(this + 0x1d8) == 0xc)) {
        return bVar4;
      }
    }
    else if ((*(int *)(this + 0x168) == 0xc) && (*(int *)(this + 0x170) == 0)) {
      return bVar4;
    }
    bVar4 = false;
  }
  return bVar4;
}

