
undefined4 usbhid_open(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xe44);
  (*(code *)&mutex_lock)(hid_open_mut);
  iVar1 = *(int *)(param_1 + 0xd40);
  *(int *)(param_1 + 0xd40) = iVar1 + 1;
  if (iVar1 == 0) {
    iVar1 = *(int *)(iVar2 + 4);
    *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & 0xfffffff7 | 8;
    iVar1 = hid_start_in(param_1);
    if (iVar1 != 0) {
      hid_io_error(param_1);
      (*(code *)&mutex_unlock)(hid_open_mut);
      return 0;
    }
  }
  (*(code *)&mutex_unlock)(hid_open_mut);
  return 0;
}

