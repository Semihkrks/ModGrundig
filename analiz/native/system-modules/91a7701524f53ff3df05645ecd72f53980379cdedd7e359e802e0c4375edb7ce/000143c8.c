
int init_module(void)

{
  int iVar1;
  
  iVar1 = (*(code *)&__hid_register_driver)(hid_usb_driver,__this_module,&_LC26);
  if (iVar1 == 0) {
    iVar1 = usbhid_quirks_init(quirks_param);
    if (iVar1 == 0) {
      iVar1 = (*(code *)&usb_register_driver)(hid_driver,__this_module,&_LC26);
      if (iVar1 == 0) {
        (*(code *)&printk)("<6>usbhid: USB HID core driver\n");
        return 0;
      }
      usbhid_quirks_exit();
    }
    (*(code *)&hid_unregister_driver)(hid_usb_driver);
  }
  return iVar1;
}

