
/* CecSettingsFrame::OnKey(void*, void*, void*) */

undefined4 __thiscall
CecSettingsFrame::OnKey(CecSettingsFrame *this,void *param_1,void *param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int in_t9;
  
  if (param_2 != (void *)0xf003) {
    if ((void *)0xf003 < param_2) {
      if (param_2 == (void *)0xf062) {
        if (**(int **)(in_t9 + 0x842354) == 0) {
          uVar2 = (**(code **)(in_t9 + 0x8453ec))();
          (**(code **)(&UNK_00840d48 + in_t9))(uVar2,0,0,0);
          return 1;
        }
        return 1;
      }
      if (param_2 != (void *)0xf075) {
        if (param_2 != (void *)0xf045) {
          return 0;
        }
        if (*(int *)(this + 0x1ec) != 2) {
          return 0;
        }
        (**(code **)(&UNK_00841984 + in_t9))();
        *(undefined4 *)(this + 0x1ec) = 0;
        (**(code **)(in_t9 + 0x847ad4))(this,0,0,0);
        return 1;
      }
      iVar1 = *(int *)(this + 0x1ec);
      if (iVar1 == 1) {
        (**(code **)(in_t9 + 0x8427d4))();
        (**(code **)(&UNK_00841984 + in_t9))();
        *(undefined4 *)(this + 0x1ec) = 0;
      }
      else {
        if (iVar1 == 0) {
          if (*(int *)(this + 0x1f0) == 1) {
            (**(code **)(in_t9 + 0x8427d4))();
            *(undefined4 *)(this + 0x1f0) = 0;
            return 1;
          }
          if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
            uVar2 = (**(code **)(in_t9 + 0x8453ec))();
            (**(code **)(&UNK_00840d48 + in_t9))(uVar2,1,0,0);
            return 1;
          }
          uVar2 = (**(code **)(in_t9 + 0x8453ec))();
          (**(code **)(&UNK_00841100 + in_t9))(uVar2);
          uVar2 = (**(code **)(in_t9 + 0x8453ec))();
          (**(code **)(&UNK_00840d48 + in_t9))(uVar2,6,0,0);
          return 1;
        }
        if (iVar1 != 2) {
          return 1;
        }
      }
      (**(code **)(in_t9 + 0x8427d4))();
      *(undefined4 *)(this + 0x1ec) = 0;
      return 1;
    }
    if (param_2 < (void *)0xf000) {
      return 0;
    }
    if (param_2 < (void *)0xf002) {
      if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
        uVar2 = (**(code **)(in_t9 + 0x8453ec))();
        uVar2 = (**(code **)(in_t9 + 0x842a9c))(uVar2,param_1,param_2,param_3);
        return uVar2;
      }
      if (*(int *)(this + 0x3c) != *(int *)(this + 0x18c)) {
        return 0;
      }
      if (*(int *)(*(int *)(this + 0x18c) + 0x264) != 5) {
        return 0;
      }
      return 1;
    }
    if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
      return 1;
    }
    if (*(int *)(this + 0x3c) == *(int *)(this + 0x188)) {
      (**(code **)(in_t9 + 0x8441d4))(this,*(undefined4 *)(this + 0x180));
      uVar2 = (**(code **)(in_t9 + 0x8453ec))();
      (**(code **)(&UNK_00842c88 + in_t9))(uVar2,1);
      return 1;
    }
  }
  if (*(int *)(this + 0x3c) != *(int *)(this + 0x180)) {
    return 0;
  }
  (**(code **)(in_t9 + 0x8441d4))(this,*(undefined4 *)(this + 0x188));
  uVar2 = (**(code **)(in_t9 + 0x8453ec))();
  (**(code **)(&UNK_00842c88 + in_t9))(uVar2,0);
  return 1;
}

