
/* MSrv_DTV_Player_DVB::CheckProgramFilterType(_DVB_PROGRAMINFO&) */

bool MSrv_DTV_Player_DVB::CheckProgramFilterType(_DVB_PROGRAMINFO *param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int in_a1;
  byte bStack_1c;
  
  iVar2 = (**(code **)(*(int *)param_1 + 0x37c))();
  bVar1 = true;
  if (iVar2 != 0) {
    switch(iVar2) {
    case 2:
      bVar1 = *(char *)(in_a1 + 0x1d) == '\x01';
      break;
    case 3:
      bVar1 = *(char *)(in_a1 + 0x1d) == '\x02';
      break;
    case 6:
      bVar1 = *(char *)(in_a1 + 0x14) == '\0';
      break;
    case 7:
      bVar1 = *(char *)(in_a1 + 0x14) != '\0';
      break;
    case 0xc:
      iVar2 = (**(code **)(**(int **)(param_1 + 0x108) + 0x7c))();
      if (iVar2 != 0) {
        MSrv_Control_common::GetMSrvSystemDatabase();
        uVar3 = MSrv_System_Database::GetSatFilterID();
        return bStack_1c == uVar3;
      }
    default:
      bVar1 = false;
    }
  }
  return bVar1;
}

