
/* ArSrvPowerManager::SetPowerState(POWER_STATE, bool) */

undefined4 __thiscall
ArSrvPowerManager::SetPowerState(ArSrvPowerManager *this,int param_2,uint param_3)

{
  int iVar1;
  code *pcVar2;
  
  printf("[PowerManager] SetPowerState: %s->%s Force:%u\n",(&PTR_s_BOOTING_2e027000)[*(int *)this],
         (&PTR_s_BOOTING_2e027000)[param_2],param_3 & 0xff);
  if ((param_3 & 0xff) != 0) {
    *(int *)this = param_2;
    return 1;
  }
  if (param_2 == 2) {
    iVar1 = *(int *)this;
    if (iVar1 == 3) {
      TaskFakeStandbyToSTR(this);
    }
    else if (iVar1 == 4) {
      TaskOnToSTR(this);
    }
    else {
      if (iVar1 != 0) {
        return 0;
      }
      TaskBootingToSTR(this);
    }
    pcVar2 = Suspend;
    *(undefined4 *)this = 2;
  }
  else {
    if (2 < param_2) {
      if (param_2 == 3) {
        iVar1 = *(int *)this;
        if (iVar1 == 2) {
          TaskSTRToFakeStandby();
        }
        else if (iVar1 == 4) {
          TaskOnToFakeStandby(this);
        }
        else {
          if (iVar1 != 0) {
            return 0;
          }
          TaskBootingToFakeStandby(this);
        }
        *(undefined4 *)this = 3;
        this[0xc] = (ArSrvPowerManager)0x0;
        return 1;
      }
      if (param_2 == 4) {
        iVar1 = *(int *)this;
        if (iVar1 == 2) {
          TaskSTRToOn(this);
        }
        else if (iVar1 == 3) {
          TaskFakeStandbyToOn(this);
        }
        else {
          if (iVar1 != 0) {
            return 0;
          }
          TaskBootingToOn(this);
        }
        *(undefined4 *)this = 4;
        return 1;
      }
      return 0;
    }
    if (param_2 != 1) {
      return 0;
    }
    if (*(int *)this == 3) {
      TaskFakeStandbyToOff();
    }
    else {
      if (*(int *)this != 4) {
        return 0;
      }
      TaskOnToPowerOff();
    }
    *(undefined4 *)this = 1;
    sync();
    pcVar2 = PowerDown;
  }
  (*pcVar2)(this);
  return 1;
}

