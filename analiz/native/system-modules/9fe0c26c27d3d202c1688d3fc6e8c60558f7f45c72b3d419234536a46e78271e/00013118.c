
undefined4 usb_stor_pre_reset(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)&dev_get_drvdata)(param_1 + 0x20);
  (*(code *)&mutex_lock)(uVar1);
  return 0;
}

