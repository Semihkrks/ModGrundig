
/* RegEng<(MUF_Keycode_t)61516, VolumeControlApp, (EN_MAPP_HOTKEY_FLAG)0>::RegEng() */

void __thiscall
RegEng<(MUF_Keycode_t)61516,VolumeControlApp,(EN_MAPP_HOTKEY_FLAG)0>::RegEng
          (RegEng<(MUF_Keycode_t)61516,VolumeControlApp,(EN_MAPP_HOTKEY_FLAG)0> *this)

{
  int in_t9;
  
  (**(code **)(in_t9 + 0xffd04))(this);
  (**(code **)(in_t9 + 0x1049f8))(this + 0xc);
  *(undefined4 *)(this + 4) = 0xf04c;
  *(RegEng<(MUF_Keycode_t)61516,VolumeControlApp,(EN_MAPP_HOTKEY_FLAG)0> **)(this + 8) = this + 0xc;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}

