
void MDrv_IR_Init(int param_1)

{
  ir_irq_depth = 1;
  _u8PrevSystemCode = 0;
  (*(code *)&proc_create_data)(&_LC7,0x180,0,ir_ctrl_proc_fops,0);
  (*(code *)&proc_create_data)("factory_ir_ctrl",0x1b6,0,factory_ir_ctrl_proc_fops,0);
  if (param_1 == 0) {
    fantasy_protocol._8_4_ = 1;
    fantasy_protocol._16_4_ = 0x1278c;
    fantasy_protocol._12_4_ = 0x1278c;
    (*(code *)&__init_waitqueue_head)(fantasy_protocol,0x10000);
  }
  uRambf007b48 = (uint)CONCAT11(_u8IRHeaderCode1,_u8IRHeaderCode0);
  fantasy_protocol._20_4_ = 0;
  uRambf007b00 = 0x1bf;
  uRambf007b04 = 0x26f1;
  uRambf007b08 = 0x19f6;
  uRambf007b0c = 0x1378;
  uRambf007b10 = 0xcfb;
  uRambf007b14 = 0xad1;
  uRambf007b18 = 0x736;
  uRambf007b1c = 0x2b9;
  uRambf007b20 = 0x169;
  uRambf007b24 = 0x4d8;
  uRambf007b28 = 0x33b;
  uRambf007b2c = 0x9b1;
  uRambf007b30 = 0x676;
  uRambf007b3c = 0xf8ce;
  uRambf007b40 = 0x9f31;
  uRambf007b50 = 0xc;
  uRambf007b4c = 0x1804;
  uRambf007b44 = 0x3f00;
  _u32IRCount = 0;
  _u32_1stDelayTimeMs = 0;
  _u32_2ndDelayTimeMs = 0;
  _ePrevKeyProperty = 0;
  (*(code *)&memset)(&_KeyReceived,0,4);
  if (param_1 == 0) {
    (*(code *)&request_threaded_irq)(0x43,_MDrv_IR_ISR,0,0,&_LC9,0);
    ir_irq_depth = 0;
  }
  uRambf003214 = uRambf003214 & 0xf7ff;
  return;
}

