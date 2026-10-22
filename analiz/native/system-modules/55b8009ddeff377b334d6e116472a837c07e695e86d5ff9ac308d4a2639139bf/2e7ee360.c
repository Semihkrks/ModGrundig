
/* MSrv_Network_Control::UnregisterWanStatusCheckCb() */

undefined4 __thiscall MSrv_Network_Control::UnregisterWanStatusCheckCb(MSrv_Network_Control *this)

{
  *(undefined4 *)(this + 0x1c64) = 0;
  return 0;
}

