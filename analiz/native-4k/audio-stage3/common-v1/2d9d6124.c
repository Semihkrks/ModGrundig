
/* MW_DTV_AVMonitor::CheckAudioStatus() */

void __thiscall MW_DTV_AVMonitor::CheckAudioStatus(MW_DTV_AVMonitor *this)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = mapi_time_utility::GetTime0();
  uVar4 = *(uint *)(this + 0x84);
  uVar2 = uVar1 - uVar4;
  if (uVar1 <= uVar4) {
    uVar2 = uVar4 - uVar1;
  }
  if (((2000 < uVar2) && (this[0x6e] == (MW_DTV_AVMonitor)0x0)) &&
     (this[0x92] != (MW_DTV_AVMonitor)0x0)) {
    iVar3 = IsMadLock();
    if (iVar3 == 0) {
      this[0x113] = (MW_DTV_AVMonitor)0x1;
    }
    else {
      *(undefined4 *)(this + 0x84) = 0;
      SetMuteFlag(this,'\0',2);
      this[0x113] = (MW_DTV_AVMonitor)0x1;
    }
    return;
  }
  return;
}

