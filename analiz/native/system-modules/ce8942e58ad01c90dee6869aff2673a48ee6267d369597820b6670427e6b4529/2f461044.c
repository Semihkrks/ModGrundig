
void MDrv_IR_InitCfg(undefined4 *param_1)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_1c = param_1[1];
  local_18 = param_1[2];
  local_10 = param_1[4];
  local_20 = *param_1;
  local_14 = param_1[3];
  (*(code *)PTR_ioctl_2f472404)(*(undefined4 *)(PTR_DAT_2f4723b8 + 0x3010),0x8014750b,&local_20);
  return;
}

