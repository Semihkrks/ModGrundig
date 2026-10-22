
/* WARNING: Control flow encountered bad instruction data */

void usb_serial_bus_register(int param_1)

{
  *(undefined1 **)(param_1 + 0x18) = usb_serial_bus_type;
  *(int *)(param_1 + 0x54) = param_1 + 0x50;
  *(int *)(param_1 + 0x50) = param_1 + 0x50;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

