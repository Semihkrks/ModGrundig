
/* WARNING: Removing unreachable block (ram,0x2d4bf114) */
/* MSrv_ChannelManager_DVB::GetProgramName(unsigned long, unsigned char, unsigned short,
   std::string&) */

int __thiscall
MSrv_ChannelManager_DVB::GetProgramName
          (MSrv_ChannelManager_DVB *this,ulong param_1,uchar param_2,ushort param_3,string *param_4)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_44 [4];
  ulong local_40;
  uchar local_31;
  int local_2c;
  
  local_2c = 0x2c828ac4;
  local_40 = param_1;
  local_31 = param_2;
                    /* try { // try from 2d4bf070 to 2d4bf0c7 has its CatchHandler @ 2d4bf124 */
  iVar1 = (**(code **)(*(int *)this + 0x3c))(this,4,auStack_44);
  if (iVar1 == 1) {
    std::string::assign(param_4);
  }
  if ((allocator *)(local_2c + -0xc) != (allocator *)&DAT_2c828ab8) {
    SYNC(0);
    iVar2 = *(int *)(local_2c + -4);
    *(int *)(local_2c + -4) = iVar2 + -1;
    SYNC(0);
    if (iVar2 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_2c + -0xc));
    }
  }
  return iVar1;
}

