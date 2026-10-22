
/* VolumeControlFrame::VolumeControlFrame(MApplet*, _Rect&) */

void __thiscall
VolumeControlFrame::VolumeControlFrame(VolumeControlFrame *this,MApplet *param_1,_Rect *param_2)

{
  int in_t9;
  
  (**(code **)(in_t9 + 0x10d614))(this,param_1,param_2);
  *(int *)this = *(int *)(in_t9 + 0x109458) + 8;
  (**(code **)(in_t9 + 0x10e288))(this + 0x11c,*(int *)(in_t9 + 0x1068b0) + -0x346c,99);
  *(undefined4 *)(this + 0x118) = 0;
  *(undefined4 *)(this + 0x1c0) = 0;
  **(undefined1 **)(in_t9 + 0x10f488) = 1;
  **(undefined4 **)(in_t9 + 0x10cff0) = this;
  return;
}

