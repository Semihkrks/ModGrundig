
/* MSrv_ChannelManager_DVB_Customer::ProgramSelForTV(unsigned long, unsigned char, unsigned char) */

undefined4
MSrv_ChannelManager_DVB_Customer::ProgramSelForTV(ulong param_1,uchar param_2,uchar param_3)

{
  int *piVar1;
  int iVar2;
  undefined3 in_register_00000015;
  uint uVar3;
  
  uVar3 = CONCAT31(in_register_00000015,param_2);
  printf("ProgramSelForTV Number[%ld] Type[%d] \n",uVar3,param_3);
  (**(code **)(*(int *)param_1 + 0x140))(param_1,uVar3 & 0xffff,param_3);
  MSrv_Control_common::GetMSrvSSSound();
  MSrv_SSSound::SetAbsoluteVolume();
  (**(code **)(*(int *)param_1 + 0x110))(param_1,param_3);
  if (*(char *)(param_1 + 0xdd) == '\0') {
    if (*(char *)(param_1 + 0xde) == '\0') {
      if (*(char *)(param_1 + 0xdc) == '\0') {
        return 1;
      }
    }
    else {
      if (param_3 != '\0') goto LAB_2e157f94;
      piVar1 = (int *)(**(code **)(*(int *)param_1 + 0x10c))(param_1);
      iVar2 = (**(code **)(*piVar1 + 0x8ac))(piVar1,uVar3 & 0xffff,0,0);
      if (iVar2 == 0) {
        puts("ProgramSelForTV error: PVR running!");
        return 0;
      }
      piVar1 = (int *)(**(code **)(*(int *)param_1 + 0x10c))(param_1);
      iVar2 = (**(code **)(*piVar1 + 0x428))(piVar1);
      if (iVar2 != 0) {
        piVar1 = (int *)(**(code **)(*(int *)param_1 + 0x10c))(param_1);
        (**(code **)(*piVar1 + 0x8b0))(piVar1);
      }
    }
    piVar1 = (int *)MSrv_Control::GetInstance();
    iVar2 = (**(code **)(*piVar1 + 0x90))(piVar1,1,1,0,0,0,0);
    if (iVar2 == 1) {
      piVar1 = (int *)MSrv_Control_TV::GetMSrvAtv();
      (**(code **)(*piVar1 + 0x130))(piVar1,param_2,1);
      return 1;
    }
  }
  else {
LAB_2e157f94:
    piVar1 = (int *)MSrv_Control::GetInstance();
    iVar2 = (**(code **)(*piVar1 + 0x90))(piVar1,0x1c,1,0,0,0,0);
    if (iVar2 == 1) {
      piVar1 = (int *)(**(code **)(*(int *)param_1 + 0x10c))(param_1);
      (**(code **)(*piVar1 + 0x148))(piVar1,uVar3,param_3,1,0,0);
      return 1;
    }
  }
  return 1;
}

