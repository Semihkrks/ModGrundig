
/* MSrv_CEC::GetIsAMPExist() */

bool __thiscall MSrv_CEC::GetIsAMPExist(MSrv_CEC *this)

{
  return *(int *)(this + 0x200) != 0;
}

