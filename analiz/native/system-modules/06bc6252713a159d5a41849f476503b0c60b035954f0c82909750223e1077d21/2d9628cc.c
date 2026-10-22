
/* MSrv_CEC::CheckInputAMPExist() */

bool __thiscall MSrv_CEC::CheckInputAMPExist(MSrv_CEC *this)

{
  return *(int *)(this + 0x200) != 0;
}

