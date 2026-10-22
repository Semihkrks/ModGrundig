
/* WARNING: Control flow encountered bad instruction data */

void usb_ehci_mstar_remove(undefined4 param_1)

{
  (*(code *)&remove_port_idle_hcd)();
  (*(code *)&usb_remove_hcd)(param_1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

