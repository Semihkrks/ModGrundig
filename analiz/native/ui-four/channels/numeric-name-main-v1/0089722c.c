
/* ChannelControlFrame::ChannelControlFrame(MApplet*, _Rect&) */

void __thiscall
ChannelControlFrame::ChannelControlFrame(ChannelControlFrame *this,MApplet *param_1,_Rect *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  CommonFrame::CommonFrame((CommonFrame *)this,param_1,param_2);
  *(undefined ***)this = &PTR_FUN_010bacd0;
  strncpy((char *)(this + 0x11c),"[UI]ChannelControl",99);
  *(undefined4 *)(this + 0x118) = 0;
                    /* try { // try from 008972c4 to 008972ef has its CatchHandler @ 00897388 */
  piVar1 = (int *)MSrv_Control_common::GetMSrvChannelManager();
  uVar2 = (**(code **)(*piVar1 + 0x44))(piVar1,0);
  *(undefined4 *)(this + 0x18c) = uVar2;
  *(undefined4 *)(this + 0x194) = 999;
  *(undefined4 *)(this + 0x198) = 1;
  *(undefined4 *)(this + 0x19c) = 1;
  *(int *)(this + 400) = *(int *)(this + 0x194) + 1;
  this[0x1a0] = (ChannelControlFrame)0x4;
  *(undefined2 *)(this + 0x1a2) = 0;
  this[0x1a4] = (ChannelControlFrame)0x0;
  this[0x1a5] = (ChannelControlFrame)0x1;
  this[0x1a6] = (ChannelControlFrame)0x0;
  return;
}

