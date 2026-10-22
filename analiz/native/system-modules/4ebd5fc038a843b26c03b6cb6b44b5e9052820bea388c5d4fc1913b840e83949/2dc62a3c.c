
/* mapi_audio_customer::GetDeviceCount() */

int __thiscall mapi_audio_customer::GetDeviceCount(mapi_audio_customer *this)

{
  return (*(int *)(this + 0x1bc) - *(int *)(this + 0x1b8) >> 2) * -0x33333333;
}

