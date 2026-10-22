
/* VolumeControlFrame::TimerEventHandler(void*, void*, void*) */

undefined4 VolumeControlFrame::TimerEventHandler(void *param_1,void *param_2,void *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (void *)0x0) {
    (*(code *)PTR_KillTimer_010c786c)(param_1,0);
    uVar1 = (*(code *)PTR_GetParentApp_010c98f8)(param_1);
    (*(code *)PTR_Kill_010c4dec)(uVar1);
    uVar1 = (*(code *)PTR_getInstance_010c909c)();
    iVar2 = (*(code *)PTR_IsMuted_010ca504)(uVar1);
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_GetMuteControlFrame_010c4ce4)();
      if (iVar2 == 0) {
        iVar2 = (*(code *)PTR_operator_new_010c9890)(0x3c);
                    /* try { // try from 00fb7bf4 to 00fb7bfb has its CatchHandler @ 00fb7c1c */
        (*(code *)PTR_MuteControlApp_010cae90)(iVar2);
        if (iVar2 == 0) {
          (*(code *)PTR_printf_010c9f10)
                    (PTR_DAT_010c4460 + -0x34c4,PTR_DAT_010c4460 + -0x34ac,
                     PTR_DAT_010c4460 + -0x3400,0xe9);
          (*(code *)PTR_abort_010cc6c0)();
        }
        (*(code *)PTR_Run_010c7470)(iVar2,0x10ff,0);
      }
      else {
        uVar1 = (*(code *)PTR_GetMuteControlFrame_010c4ce4)();
        uVar1 = (*(code *)PTR_GetParentApp_010c98f8)(uVar1);
        (*(code *)PTR_Show_010c856c)(uVar1,0);
      }
    }
  }
  return 1;
}

