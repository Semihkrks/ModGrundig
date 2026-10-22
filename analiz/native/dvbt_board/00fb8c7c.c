
/* VolumeControlFrame::OnKey(void*, void*, void*) */

undefined4 __thiscall
VolumeControlFrame::OnKey(VolumeControlFrame *this,void *param_1,void *param_2,void *param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int in_t9;
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [8];
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  void *pvStack_18;
  
  **(int **)(in_t9 + 0x1115b8) = **(int **)(in_t9 + 0x1115b8) + 1;
  if ((**(char **)(in_t9 + 0x10df4c) == '\0') && (2 < **(int **)(in_t9 + 0x1115b8))) {
    return 1;
  }
  **(undefined4 **)(in_t9 + 0x10be8c) = param_2;
  uVar2 = (**(code **)(in_t9 + 0x110420))();
  uVar2 = (**(code **)(in_t9 + 0x114494))(uVar2);
  (**(code **)(in_t9 + 0x110b38))(auStack_38,*(int *)(in_t9 + 0x10b7e4) + -0x348c,uVar2);
  iStack_28 = *(int *)(this + 0x1ac) + 0x170;
  (**(code **)(in_t9 + 0x10dca4))(auStack_40);
                    /* try { // try from 00fb8da0 to 00fb8da7 has its CatchHandler @ 00fb8f58 */
  (**(code **)(in_t9 + 0x10c320))(auStack_3c,auStack_38,auStack_40);
                    /* try { // try from 00fb8dbc to 00fb8dc3 has its CatchHandler @ 00fb8e38 */
  (**(code **)(in_t9 + 0x112720))(iStack_28,auStack_3c);
                    /* try { // try from 00fb8dd4 to 00fb8ddb has its CatchHandler @ 00fb8f58 */
  (**(code **)(in_t9 + 0x10c3f4))(auStack_3c);
  (**(code **)(in_t9 + 0x10bccc))(auStack_40);
  (**(code **)(in_t9 + 0x10c1ac))(*(undefined4 *)(this + 0x1ac));
  pvStack_18 = param_2;
  if (param_2 < (void *)0xf04e) {
    if ((void *)0xf04b < param_2) {
LAB_00fb8fcc:
      uVar1 = **(undefined1 **)(in_t9 + 0x1143bc);
      *(undefined4 *)(this + 0x214) = 0;
      if ((int)param_3 < 0) {
        uVar3 = (**(code **)(in_t9 + 0x10e97c))(*(undefined4 *)(this + 0x1c0));
        if (1000 < uVar3) {
          uVar1 = 4;
        }
      }
      else {
        uVar2 = (**(code **)(in_t9 + 0x10fde0))();
        *(undefined4 *)(this + 0x1c0) = uVar2;
      }
      uVar2 = (**(code **)(in_t9 + 0x10c710))();
      iVar4 = (**(code **)(in_t9 + 0x10f910))(uVar2);
      if (((iVar4 == 0) || (iVar4 = (**(code **)(in_t9 + 0x112c20))(uVar2), iVar4 == 0)) ||
         (iVar4 = (**(code **)(in_t9 + 0x10f8e0))(uVar2), iVar4 == 0)) {
        iStack_2c = 0;
      }
      else {
        iStack_2c = 1;
      }
      if (iStack_2c != 0) {
        (**(code **)(in_t9 + 0x10eed4))(uVar2,param_2);
        iVar4 = (**(code **)(in_t9 + 0x10e3bc))(uVar2);
        if (iVar4 != 0) {
          iVar4 = (**(code **)(in_t9 + 0x10c068))();
          if (iVar4 != 0) {
            uVar2 = (**(code **)(in_t9 + 0x10c068))();
            uVar2 = (**(code **)(in_t9 + 0x110c7c))(uVar2);
            (**(code **)(in_t9 + 0x10c170))(uVar2);
          }
          *(undefined4 *)(this + 0x214) = 2;
          (**(code **)(in_t9 + 0x10d30c))(this);
          return 1;
        }
        *(undefined4 *)(this + 0x214) = 2;
        (**(code **)(in_t9 + 0x10d30c))(this);
        return 1;
      }
      if (((param_2 == (void *)0xf04c) || (param_2 == (void *)0xf551)) ||
         ((param_2 == (void *)0xf001 || (param_2 == (void *)0xf554)))) {
        uVar2 = (**(code **)(in_t9 + 0x110420))();
        (**(code **)(in_t9 + 0x113670))(uVar2,uVar1);
      }
      else {
        uVar2 = (**(code **)(in_t9 + 0x110420))();
        (**(code **)(in_t9 + 0x1130c4))(uVar2,uVar1);
      }
      if (**(char **)(in_t9 + 0x1143bc) != '\x01') {
        **(undefined1 **)(in_t9 + 0x1143bc) = 1;
      }
      (**(code **)(in_t9 + 0x10d30c))(this);
      return 1;
    }
    if (param_2 != (void *)0xf012) {
      if (param_2 < (void *)0xf013) {
        if ((int)param_2 - 0xf000U < 2) goto LAB_00fb8fcc;
      }
      else if (param_2 == (void *)0xf014) {
        (**(code **)(in_t9 + 0x10d30c))(this);
        return 1;
      }
      goto LAB_00fb9454;
    }
  }
  else if (param_2 != (void *)0xf075) {
    if (param_2 < (void *)0xf076) {
      if (param_2 == (void *)0xf04e) {
        uVar2 = (**(code **)(in_t9 + 0x10c710))();
        iVar4 = (**(code **)(in_t9 + 0x10f910))(uVar2);
        if (((iVar4 == 0) || (iVar4 = (**(code **)(in_t9 + 0x112c20))(uVar2), iVar4 == 0)) ||
           (iVar4 = (**(code **)(in_t9 + 0x10f8e0))(uVar2), iVar4 == 0)) {
          iStack_30 = 0;
        }
        else {
          iStack_30 = 1;
        }
        if (iStack_30 != 0) {
          (**(code **)(in_t9 + 0x10eed4))(uVar2,0xf04e);
          iVar4 = (**(code **)(in_t9 + 0x10e3bc))(uVar2);
          if (iVar4 != 0) {
            *(undefined4 *)(this + 0x214) = 3;
            (**(code **)(in_t9 + 0x10d30c))(this);
            return 1;
          }
        }
        *(undefined4 *)(this + 0x214) = 1;
        uVar2 = (**(code **)(in_t9 + 0x110420))();
        uVar5 = (**(code **)(in_t9 + 0x110420))();
        iVar4 = (**(code **)(in_t9 + 0x111888))(uVar5);
        (**(code **)(in_t9 + 0x1143e8))(uVar2,iVar4 == 0);
        (**(code **)(in_t9 + 0x10d30c))(this);
        return 1;
      }
      if (param_2 == (void *)0xf062) goto LAB_00fb8f9c;
    }
    else if ((int)param_2 - 0xf551U < 4) goto LAB_00fb8fcc;
LAB_00fb9454:
    iVar4 = (**(code **)(in_t9 + 0x10e8cc))();
    if (iVar4 != 0) {
      (**(code **)(in_t9 + 0x113560))(this,0,0,0);
      uVar2 = (**(code **)(in_t9 + 0x10e8cc))();
      uVar5 = (**(code **)(in_t9 + 0x10e8cc))();
      (**(code **)(in_t9 + 0x111f70))(uVar2,uVar5,0x14,param_2,param_3);
      return 1;
    }
    iVar4 = (**(code **)(in_t9 + 0x10c8dc))();
    if (iVar4 != 0) {
      (**(code **)(in_t9 + 0x113560))(this,0,0,0);
      uVar2 = (**(code **)(in_t9 + 0x10c8dc))();
      uVar5 = (**(code **)(in_t9 + 0x10c8dc))();
      (**(code **)(in_t9 + 0x111f70))(uVar2,uVar5,0x14,param_2,param_3);
      return 1;
    }
    iVar4 = (**(code **)(in_t9 + 0x111b6c))();
    if (iVar4 != 0) {
      (**(code **)(in_t9 + 0x113560))(this,0,0,0);
      uVar2 = (**(code **)(in_t9 + 0x111b6c))();
      uVar5 = (**(code **)(in_t9 + 0x111b6c))();
      (**(code **)(in_t9 + 0x111f70))(uVar2,uVar5,0x14,param_2,param_3);
      return 1;
    }
    (**(code **)(in_t9 + 0x113ed8))();
    iVar4 = (**(code **)(in_t9 + 0x11276c))();
    if (iVar4 != 0) {
      (**(code **)(in_t9 + 0x113560))(this,0,0,0);
      uVar2 = (**(code **)(in_t9 + 0x113ed8))();
      uVar5 = (**(code **)(in_t9 + 0x113ed8))();
      (**(code **)(in_t9 + 0x111f70))(uVar2,uVar5,0x14,param_2,param_3);
      return 1;
    }
    iVar4 = (**(code **)(in_t9 + 0x10dde8))();
    if (iVar4 == 0) {
      return 1;
    }
    (**(code **)(in_t9 + 0x113560))(this,0,0,0);
    uVar2 = (**(code **)(in_t9 + 0x10dde8))();
    uVar5 = (**(code **)(in_t9 + 0x10dde8))();
    (**(code **)(in_t9 + 0x111f70))(uVar2,uVar5,0x14,param_2,param_3);
    return 1;
  }
LAB_00fb8f9c:
  (**(code **)(in_t9 + 0x113560))(this,0,0,0);
  return 1;
}

