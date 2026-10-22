
/* MSrv_Network_Control::RegisterWanStatusCheckCb(unsigned char (*)()) */

undefined4 __thiscall
MSrv_Network_Control::RegisterWanStatusCheckCb(MSrv_Network_Control *this,_func_uchar *param_1)

{
  *(_func_uchar **)(this + 0x1c64) = param_1;
  return 0;
}

