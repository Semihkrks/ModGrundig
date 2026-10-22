
/* WARNING: Control flow encountered bad instruction data */

void usbhid_disconnect(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)&dev_get_drvdata)(param_1 + 0x20);
  if (iVar1 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  (*(code *)&hid_destroy_device)(iVar1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

