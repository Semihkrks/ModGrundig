
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 usb_serial_handle_break(int param_1)

{
  if (*(int *)(param_1 + 0xf0) != 0) {
    *(undefined4 *)(param_1 + 0xf0) = 0;
    return 0;
  }
  *(int *)(param_1 + 0xf0) = _jiffies + 0x4e2;
  return 1;
}

