
/* VolumeControlApp::Summon(unsigned long, unsigned long) */

void VolumeControlApp::Summon(ulong param_1,ulong param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_t9;
  
  if (**(int **)(in_t9 + 0x7f4ca0) == 0) {
    iVar1 = (**(code **)(in_t9 + 0x7f5a34))(0x3c,*(undefined4 *)(in_t9 + 0x7fae78));
    if (iVar1 != 0) {
                    /* try { // try from 008d1518 to 008d151f has its CatchHandler @ 008d1534 */
      (**(code **)(&LAB_007f7b10 + in_t9))(iVar1);
    }
    **(int **)(in_t9 + 0x7f4ca0) = iVar1;
    (**(code **)(in_t9 + 0x7f6038))(**(undefined4 **)(in_t9 + 0x7f4ca0),0x1000,param_2);
  }
  else {
    iVar1 = (**(code **)(in_t9 + 0x7fbcac))();
    if (iVar1 != 0) {
      uVar2 = (**(code **)(in_t9 + 0x7fbcac))();
      uVar3 = (**(code **)(in_t9 + 0x7fbcac))();
      (**(code **)(in_t9 + 0x7f97b4))(uVar2,uVar3,0x14,param_2,0);
    }
  }
  return;
}

