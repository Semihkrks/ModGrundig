
/* WARNING: Removing unreachable block (ram,0x00fc8d04) */
/* MAppHotKeyFacTemplate<VolumeControlApp>::~MAppHotKeyFacTemplate() */

void __thiscall
MAppHotKeyFacTemplate<VolumeControlApp>::~MAppHotKeyFacTemplate
          (MAppHotKeyFacTemplate<VolumeControlApp> *this)

{
  int in_t9;
  
  *(int *)this = *(int *)(in_t9 + 0x1004dc) + 8;
  (**(code **)(in_t9 + 0x103424))(this);
  return;
}

