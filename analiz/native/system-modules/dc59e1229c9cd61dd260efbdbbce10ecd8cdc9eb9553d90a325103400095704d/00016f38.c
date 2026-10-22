
undefined4 sawman_update_focus(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_68 [4];
  undefined4 local_64;
  int local_58;
  int local_54;
  
  if (*(int *)(param_1 + 0xa0) == 0) {
    iVar2 = *(int *)(param_1 + 0xac);
    iVar1 = (*(code *)PTR_sawman_window_at_pointer_0002c08c)(param_1,param_2,0xffffffff,0xffffffff);
    if (iVar2 != iVar1) {
      if (iVar2 != 0) {
        local_58 = *(int *)(param_2 + 0x38) - *(int *)(iVar2 + 0x34);
        local_64 = 0x100000;
        local_54 = *(int *)(param_2 + 0x3c) - *(int *)(iVar2 + 0x38);
        (*(code *)PTR_sawman_post_event_0002c1f0)(param_1,iVar2,auStack_68);
      }
      (*(code *)PTR_sawman_switch_focus_0002c0e8)(param_1,iVar1);
      if (iVar1 != 0) {
        local_58 = *(int *)(param_2 + 0x38) - *(int *)(iVar1 + 0x34);
        local_64 = 0x80000;
        local_54 = *(int *)(param_2 + 0x3c) - *(int *)(iVar1 + 0x38);
        (*(code *)PTR_sawman_post_event_0002c1f0)(param_1,iVar1,auStack_68);
      }
      *(int *)(param_1 + 0xac) = iVar1;
      return 1;
    }
  }
  return 0;
}

