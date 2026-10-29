
/* MW_DVB_SI_PSI_Parser_Customer::_IsSpecificSupport(MW_DVB_SPECIFIC_SUPPORT, void*, void*) */

bool MW_DVB_SI_PSI_Parser_Customer::_IsSpecificSupport
               (int param_1,undefined4 param_2,byte *param_3,byte *param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  byte bVar4;
  undefined4 uVar5;
  uint uVar6;
  
  if (param_3 == (byte *)0x0) {
    uVar5 = 0x3baf;
    goto LAB_2e1978ac;
  }
  switch(param_2) {
  case 0:
    bVar4 = *param_3;
    uVar6 = (uint)bVar4;
    if (param_4 != (byte *)0x0) {
      if ((uVar6 < 0x20) && ((1 << (uVar6 & 0x1f) & 0x8242140eU) != 0)) {
        if ((*(int *)(param_1 + 0x170) != 1) || (*(int *)(param_1 + 0xd2d6c) != 8)) {
          *param_4 = bVar4;
          return true;
        }
        if ((uVar6 - 1 & 0xff) < 2) {
          *param_4 = bVar4;
          return true;
        }
      }
      else if (*(int *)(param_1 + 0x170) == 1) {
        if ((*(int *)(param_1 + 0x168) == 9) && (uVar6 == 0xd3)) {
          *param_4 = 1;
          return true;
        }
      }
      else if (*(int *)(param_1 + 0x170) == 2) {
        piVar2 = (int *)MSrv_Control_TV::GetMSrvDtv(0);
        cVar1 = (**(code **)(*piVar2 + 0x944))(piVar2);
        if (cVar1 == '\0') {
          if (uVar6 == 0xd3) {
            *param_4 = 1;
            return true;
          }
        }
        else if ((cVar1 == '\x02') || (cVar1 == '\b')) {
          if (uVar6 == 0x82) {
            *param_4 = 2;
            return true;
          }
          if (uVar6 == 0x83) {
            *param_4 = 7;
            return true;
          }
          if ((uVar6 ^ 0x80) < 0x10) {
            *param_4 = 0xc;
            return true;
          }
          if (uVar6 == 0x1c) {
            *param_4 = 1;
            return true;
          }
        }
      }
      *param_4 = 7;
      return false;
    }
    uVar5 = 0x3bb5;
    goto LAB_2e1978ac;
  case 1:
    iVar3 = *(int *)param_3;
    if (((((*(int *)(param_1 + 0x170) == 1) || (iVar3 == 0x19)) || (iVar3 == 0x1a)) ||
        ((iVar3 == 0xf || (iVar3 == 0x17)))) || ((iVar3 == 7 || (iVar3 == 6)))) {
      return true;
    }
    if (*(int *)(param_1 + 0x170) == 2) {
      return *(int *)(param_1 + 0xd2d70) == 0xb;
    }
    break;
  case 2:
    if (1 < *(int *)param_3 - 0x19U) {
      iVar3 = MW_DVB_SI_PSI_Parser::_IsZiggoOperator();
      return iVar3 != 0;
    }
    return true;
  case 3:
    iVar3 = *(int *)param_3;
    if (*(int *)(param_1 + 0x170) == 0) {
      if (iVar3 == 6) {
        return true;
      }
      if (iVar3 != 0x17) {
        return iVar3 == 0x19;
      }
      return true;
    }
    break;
  case 4:
    if (*(short *)param_3 == 0x1fff) {
      return *(int *)(param_1 + 0x170) == 3;
    }
    break;
  case 5:
    break;
  case 6:
    if ((*(int *)(param_1 + 0xd2d6c) == 6) && (bVar4 = 1, *(int *)(param_1 + 0x170) == 1)) {
      iVar3 = *(int *)(param_1 + 0x168);
    }
    else {
      iVar3 = *(int *)(param_1 + 0x168);
      bVar4 = 0;
      if (iVar3 == 7) {
        return *(int *)(param_1 + 0x170) != 0;
      }
    }
    if (iVar3 != 0xe) {
      return (bool)(bVar4 ^ 1);
    }
    if (*(int *)(param_1 + 0xd2d6c) != 7) {
      return (bool)(bVar4 ^ 1);
    }
    if (*(int *)(param_1 + 0x170) != 1) {
      return (bool)(bVar4 ^ 1);
    }
    break;
  default:
    uVar5 = 0x3cae;
LAB_2e1978ac:
    printf("ASSERT FAIL: %s %s %d\n","./middleware/src/MW_DVB_SI_PSI_Parser_Customer.cpp",
           "virtual MAPI_BOOL MW_DVB_SI_PSI_Parser_Customer::_IsSpecificSupport(MW_DVB_SPECIFIC_SUPPORT, void*, void*)"
           ,uVar5);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  return false;
}

