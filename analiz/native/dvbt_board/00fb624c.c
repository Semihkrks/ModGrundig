
/* VolumeControlFrame::GetThisMessageMap() */

int VolumeControlFrame::GetThisMessageMap(void)

{
  int in_t9;
  
  return *(int *)(in_t9 + 0x10e0ec) + 0x3a7c;
}

