
bool usb_serial_device_match(int param_1,int param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if (param_1 != 0xf8) {
    bVar1 = *(int *)(*(int *)(param_1 + -0xf8) + 4) == param_2 + -0x14;
  }
  return bVar1;
}

