
undefined4 MDrv_IR_InitCfg(char *param_1)

{
  if (*param_1 != -0x20) {
    return 0;
  }
  _u8IRHeaderCode0 = param_1[5];
  _u8IRHeaderCode1 = param_1[6];
  if (param_1[1] == -0x12) {
    _u8FactoryIRHeaderCode0 = param_1[2];
    _u8FactoryIRHeaderCode1 = param_1[3];
  }
  uRambf007b48 = (uint)CONCAT11(param_1[6],param_1[5]);
  return 1;
}

