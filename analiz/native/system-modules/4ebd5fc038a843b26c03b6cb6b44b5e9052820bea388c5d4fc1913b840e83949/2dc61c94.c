
/* mapi_audio_customer::GetAudioUSBDECStatus(MM_AUDIO_TYPE*) */

undefined4 __thiscall
mapi_audio_customer::GetAudioUSBDECStatus(mapi_audio_customer *this,MM_AUDIO_TYPE *param_1)

{
  *(undefined4 *)param_1 = *(undefined4 *)(this + 0x16c);
  return 1;
}

