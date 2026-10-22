
void usb_stor_Bulk_reset(int param_1)

{
  usb_stor_reset_common(param_1,0xff,0x21,0,*(undefined1 *)(param_1 + 0x43),0,0);
  return;
}

