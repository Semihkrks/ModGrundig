
/* RegEng<(MUF_Keycode_t)61518, VolumeControlApp, (EN_MAPP_HOTKEY_FLAG)0>::RegEng() */

void __thiscall
RegEng<(MUF_Keycode_t)61518,VolumeControlApp,(EN_MAPP_HOTKEY_FLAG)0>::RegEng
          (RegEng<(MUF_Keycode_t)61518,VolumeControlApp,(EN_MAPP_HOTKEY_FLAG)0> *this)

{
  int in_t9;
  
  (**(code **)(in_t9 + 0xffbdc))(this);
  (**(code **)(in_t9 + 0x1048d0))(this + 0xc);
  *(undefined4 *)(this + 4) = 0xf04e;
  *(RegEng<(MUF_Keycode_t)61518,VolumeControlApp,(EN_MAPP_HOTKEY_FLAG)0> **)(this + 8) = this + 0xc;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}

