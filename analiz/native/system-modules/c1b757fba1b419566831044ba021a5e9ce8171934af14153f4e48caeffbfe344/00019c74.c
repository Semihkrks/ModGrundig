
int init_module(void)

{
  int iVar1;
  
  if (hid_debug != 0) {
    (*(code *)&printk)(
                      "<4>hid: hid_debug is now used solely for parser and driver debugging.\ndebugfs is now used for inspecting the device (report descriptor, reports)\n"
                      );
  }
  iVar1 = (*(code *)&bus_register)(hid_bus_type);
  if (iVar1 == 0) {
    hid_debug_init();
  }
  else {
    (*(code *)&printk)("<3>hid: can\'t register hid bus\n");
  }
  return iVar1;
}

