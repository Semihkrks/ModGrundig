
/* RegEng<(MUF_Keycode_t)61517, VolumeControlApp, (EN_MAPP_HOTKEY_FLAG)0>::RegEng() */

void __thiscall
RegEng<(MUF_Keycode_t)61517,VolumeControlApp,(EN_MAPP_HOTKEY_FLAG)0>::RegEng
          (RegEng<(MUF_Keycode_t)61517,VolumeControlApp,(EN_MAPP_HOTKEY_FLAG)0> *this)

{
  int in_t9;
  
  (**(code **)(in_t9 + 0xffc70))(this);
  (**(code **)(in_t9 + 0x104964))(this + 0xc);
  *(undefined4 *)(this + 4) = 0xf04d;
  *(RegEng<(MUF_Keycode_t)61517,VolumeControlApp,(EN_MAPP_HOTKEY_FLAG)0> **)(this + 8) = this + 0xc;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}

