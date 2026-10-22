
undefined4 FUN_008d15d4(undefined4 param_1,undefined4 param_2,uchar param_3)

{
  int iVar1;
  ArAudioManager *this;
  
  ArAudioManager::getInstance();
  iVar1 = ArAudioManager::IsMuted();
  if (iVar1 != 0) {
    MuteControlFrame::SetMute(false);
    iVar1 = MuteControlFrame::GetMuteControlFrame();
    if (iVar1 != 0) {
      MuteControlFrame::GetMuteControlFrame();
      MWnd::GetParentApp();
      MApplet::Kill();
    }
  }
  this = (ArAudioManager *)ArAudioManager::getInstance();
  ArAudioManager::SetMainVolume(this,param_3);
  VolumeControlApp::Summon(0xff,0xf014);
  return 1;
}

