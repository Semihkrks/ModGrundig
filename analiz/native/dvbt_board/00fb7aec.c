
/* VolumeControlFrame::TimerEventHandler(void*, void*, void*) */

undefined4 VolumeControlFrame::TimerEventHandler(void *param_1,void *param_2,void *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int in_t9;
  
  if (param_3 == (void *)0x0) {
    (**(code **)(in_t9 + 0x10fd80))(param_1,0);
    uVar1 = (**(code **)(in_t9 + 0x111e0c))(param_1);
    (**(code **)(in_t9 + 0x10d300))(uVar1);
    uVar1 = (**(code **)(in_t9 + 0x1115b0))();
    iVar2 = (**(code **)(in_t9 + 0x112a18))(uVar1);
    if (iVar2 != 0) {
      iVar2 = (**(code **)(in_t9 + 0x10d1f8))();
      if (iVar2 == 0) {
        iVar2 = (**(code **)(in_t9 + 0x111da4))(0x3c);
                    /* try { // try from 00fb7bf4 to 00fb7bfb has its CatchHandler @ 00fb7c1c */
        (**(code **)(in_t9 + 0x1133a4))(iVar2);
        if (iVar2 == 0) {
          (**(code **)(in_t9 + 0x112424))
                    (*(int *)(in_t9 + 0x10c974) + -0x34c4,*(int *)(in_t9 + 0x10c974) + -0x34ac,
                     *(int *)(in_t9 + 0x10c974) + -0x3400,0xe9);
          (**(code **)(in_t9 + 0x114bd4))();
        }
        (**(code **)(in_t9 + 0x10f984))(iVar2,0x10ff,0);
      }
      else {
        uVar1 = (**(code **)(in_t9 + 0x10d1f8))();
        uVar1 = (**(code **)(in_t9 + 0x111e0c))(uVar1);
        (**(code **)(in_t9 + 0x110a80))(uVar1,0);
      }
    }
  }
  return 1;
}

