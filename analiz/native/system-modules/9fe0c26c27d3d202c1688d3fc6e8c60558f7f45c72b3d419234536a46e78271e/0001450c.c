
undefined4 usb_stor_reset_resume(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)&dev_get_drvdata)(param_1 + 0x20);
  usb_stor_report_bus_reset(uVar1);
  return 0;
}

