
undefined4 usb_stor_huawei_e220_init(int param_1)

{
  usb_stor_control_msg(param_1,*(undefined4 *)(param_1 + 0x28),3,0,1,0,0,0,1000);
  return 0;
}

