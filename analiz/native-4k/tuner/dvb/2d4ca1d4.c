
/* MSrv_DTV_Player_DVB::_CheckFilterType(unsigned char, _DVB_PROGRAMINFO&) */

undefined4 MSrv_DTV_Player_DVB::_CheckFilterType(uchar param_1,_DVB_PROGRAMINFO *param_2)

{
  int iVar1;
  int *piVar2;
  undefined3 in_register_00000011;
  int *piVar3;
  char *__s;
  int in_a2;
  
  piVar3 = (int *)CONCAT31(in_register_00000011,param_1);
  iVar1 = (**(code **)(*piVar3 + 0x37c))();
  if (((uint)param_2 & 0xff) == 0) {
    if (iVar1 == 0) {
      return 1;
    }
    __s = "\n@@ _CheckFilterType: Program Change fail reset filter type to all @@";
  }
  else {
    switch(iVar1) {
    case 0:
      return 1;
    case 2:
      if (*(char *)(in_a2 + 0x1d) == '\x01') {
        return 1;
      }
      break;
    case 3:
      if (*(char *)(in_a2 + 0x1d) == '\x02') {
        return 1;
      }
      break;
    case 5:
      if (*(char *)(in_a2 + 0x1d) == '\x03') {
        return 1;
      }
      break;
    case 6:
      if (*(char *)(in_a2 + 0x14) == '\0') {
        return 1;
      }
      break;
    case 7:
      if (*(char *)(in_a2 + 0x14) != '\0') {
        return 1;
      }
      break;
    case 0xc:
      if (piVar3[0x42] == 0) {
        return 1;
      }
      piVar2 = (int *)__dynamic_cast(piVar3[0x42],&MW_DTV_CM_DVB::typeinfo,
                                     &MW_DTV_CM_DVB_Customer::typeinfo,0);
      if (piVar2 == (int *)0x0) {
        return 1;
      }
      iVar1 = (**(code **)(*piVar2 + 0xd0))(piVar2);
      if (iVar1 != 0) {
        return 1;
      }
    default:
    }
    __s = "\n@@ _CheckFilterType: Filter Type check fail reset filter type to all @@";
  }
  puts(__s);
  (**(code **)(*piVar3 + 0x378))(piVar3,0);
  return 0;
}

