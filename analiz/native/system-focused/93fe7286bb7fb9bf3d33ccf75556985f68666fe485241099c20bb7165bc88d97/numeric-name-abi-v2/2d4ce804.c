
/* MSrv_DTV_Player_DVB::GetProgramInfoByNumber(unsigned short, unsigned char, ST_DTV_PROGRAM_INFO&)
    */

int __thiscall
MSrv_DTV_Player_DVB::GetProgramInfoByNumber
          (MSrv_DTV_Player_DVB *this,ushort param_1,uchar param_2,ST_DTV_PROGRAM_INFO *param_3)

{
  int iVar1;
  _DVB_MUXINFO a_Stack_1f8 [56];
  _DVB_PROGRAMINFO a_Stack_1c0 [424];
  
  iVar1 = (**(code **)(**(int **)(this + 0x108) + 0x28))
                    (*(int **)(this + 0x108),param_2,param_1,a_Stack_1c0,0);
  if (iVar1 == 0) {
    printf("CHECK RESULT FAIL: %s %s %d RESULT 0x%lx\n",&UNK_2d593dc0,&UNK_2d598bbc,0x1903,0);
    return 0;
  }
  iVar1 = (**(code **)(**(int **)(this + 0x108) + 0x74))
                    (*(int **)(this + 0x108),a_Stack_1c0,a_Stack_1f8);
  if (iVar1 == 0) {
    printf("CHECK RESULT FAIL: %s %s %d RESULT 0x%lx\n",&UNK_2d593dc0,&UNK_2d598bbc,0x1905,0);
    iVar1 = 0;
  }
  else {
    iVar1 = _SetDtvProgramInfoByDvbProgramAndMux(this,a_Stack_1c0,a_Stack_1f8,param_3);
    if (iVar1 == 0) {
      printf("CHECK RESULT FAIL: %s %s %d RESULT 0x%lx\n",&UNK_2d593dc0,&UNK_2d598bbc,0x1908,0);
      return 0;
    }
  }
  return iVar1;
}

