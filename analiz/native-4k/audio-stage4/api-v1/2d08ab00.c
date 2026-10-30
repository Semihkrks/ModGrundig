
uint MApi_AUDIO_IsMadLock(void)

{
  undefined4 local_10;
  uint local_c;
  
  local_10 = 0;
  local_c = 0;
  FUN_2d086d90();
  UtopiaIoctl(uRam2d233280,0x3d,&local_10);
  return local_c & 0xff;
}

