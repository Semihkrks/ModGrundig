
/* MW_DTV_CM_DVB_Customer::_IsMatchedProgramTypeByFilterLoopType(_DVB_PROGRAMINFO const&,
   EN_SERVICE_QUERY_TYPE) */

bool __thiscall
MW_DTV_CM_DVB_Customer::_IsMatchedProgramTypeByFilterLoopType
          (MW_DTV_CM_DVB_Customer *this,int param_1,undefined4 param_3)

{
  int iVar1;
  
  switch(param_3) {
  default:
    return true;
  case 2:
    return *(char *)(param_1 + 0x1d) == '\x01';
  case 3:
    return *(char *)(param_1 + 0x1d) == '\x02';
  case 5:
    return *(char *)(param_1 + 0x1d) == '\x03';
  case 6:
    return *(char *)(param_1 + 0x14) == '\0';
  case 7:
    return *(char *)(param_1 + 0x14) != '\0';
  case 0xc:
    iVar1 = (**(code **)(*(int *)this + 0xd0))(this);
    return iVar1 != 0;
  }
}

