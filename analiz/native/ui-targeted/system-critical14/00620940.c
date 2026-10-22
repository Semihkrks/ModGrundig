
/* ArResourceManager::SetLNBPower(unsigned short) */

undefined4 __thiscall ArResourceManager::SetLNBPower(ArResourceManager *this,ushort param_1)

{
  undefined1 uVar1;
  int *piVar2;
  undefined4 uVar3;
  MSrv_DTV_Player_DVB_DVBS_Sat_Info aMStack_50 [15];
  undefined1 uStack_41;
  undefined4 uStack_28;
  code *pcStack_24;
  int iStack_20;
  int *piStack_1c;
  
  MSrv_DTV_Player_DVB_DVBS_Sat_Info::MSrv_DTV_Player_DVB_DVBS_Sat_Info(aMStack_50);
                    /* try { // try from 00620998 to 00620bfb has its CatchHandler @ 00620c40 */
  iStack_20 = MSrv_Control_TV::GetMSrvDtv(0);
  if (iStack_20 == 0) {
    piStack_1c = (int *)0x0;
  }
  else {
    piStack_1c = (int *)__dynamic_cast(iStack_20,&DAT_2da86f20,&DAT_2e99cf18,0);
  }
  piVar2 = piStack_1c;
  if (piStack_1c == (int *)0x0) {
    printf("ASSERT FAIL: %s %s %d\n",&UNK_00fe9dc8,&UNK_00feb374,0x9ff);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  uVar3 = (**(code **)(*piStack_1c + 0x944))(piStack_1c);
  (**(code **)(*piVar2 + 0x958))(piVar2,uVar3,aMStack_50);
  DAT_2e99e994 = 1;
  if (param_1 == 1) {
    uVar1 = 1;
  }
  else if (param_1 == 2) {
    uVar1 = 4;
  }
  else {
    uVar1 = 0;
  }
  uStack_41 = uVar1;
  arSatTuningParams[0x16] = uVar1;
  (**(code **)(*piVar2 + 0x964))(piVar2,uVar3,aMStack_50);
  (**(code **)(*piVar2 + 0x9b0))(piVar2,uVar1);
  MSrv_DTV_Player_DVB::SatelliteUserInteraction(piVar2,2);
  pcStack_24 = *(code **)(*piVar2 + 0xa34);
  uStack_28 = (**(code **)(*piVar2 + 0x944))(piVar2);
  uVar3 = (**(code **)(*piVar2 + 0x94c))(piVar2);
  (*pcStack_24)(piVar2,uStack_28,uVar3,0);
  SetTuningParamsChangedFlag(this,'\x01');
  MSrv_DTV_Player_DVB_DVBS_Sat_Info::~MSrv_DTV_Player_DVB_DVBS_Sat_Info(aMStack_50);
  return 1;
}

