
/* SoftwareUpdateFrame::OADYesNoSelection(unsigned long) */

undefined4 __thiscall
SoftwareUpdateFrame::OADYesNoSelection(SoftwareUpdateFrame *this,ulong param_1)

{
  if (param_1 == 0xf043) {
    if (*(int *)(this + 0x238) == 1) {
      printf("[OADFRAME %s:%d]> Accept Download\n",&UNK_0100a070,0x9fb);
      ArSoftwareUpdateManager::getInstance();
      ArSoftwareUpdateManager::SetUIOadDownload();
      OpenMenu(this,0xd);
    }
    else if (*(int *)(this + 0x238) == 0xb) {
      printf("[OADFRAME %s:%d]> Green key received: Write Downloaded\n",&UNK_0100a070,0xa03);
      ArSoftwareUpdateManager::getInstance();
      ArSoftwareUpdateManager::StartOADUpgrade();
      MWnd::GetParentApp();
      MApplet::Kill();
    }
    else if (*(int *)(this + 0x238) == 6) {
      printf("[OADFRAME %s:%d]> Green key received: Search and Accept Downloaded\n",&UNK_0100a070,
             0xa0c);
      OpenMenu(this,0xc);
    }
    else if ((*(int *)(this + 0x238) == 3) || (*(int *)(this + 0x238) == 4)) {
      printf("[OADFRAME %s:%d]> Green key received to accept schedule\n",&UNK_0100a070,0xa13);
      ArSoftwareUpdateManager::getInstance();
      ArSoftwareUpdateManager::SetUIOadDownload();
      if (*(int *)(this + 0x238) == 3) {
        ArSoftwareUpdateManager::getInstance();
        ArSoftwareUpdateManager::PlayCurrentProgram();
      }
      else if (*(int *)(this + 0x238) == 4) {
        ArSoftwareUpdateManager::getInstance();
        ArSoftwareUpdateManager::ResetWakeupInfo();
      }
      MWnd::GetParentApp();
      MApplet::Kill();
    }
  }
  else if (param_1 == 0xf042) {
    if ((*(int *)(this + 0x238) == 3) || (*(int *)(this + 0x238) == 1)) {
      printf("[OADFRAME %s:%d]> Red key received: Reject Download\n",&UNK_0100a070,0xa27);
      ArSoftwareUpdateManager::getInstance();
      ArSoftwareUpdateManager::SetUIStopOad();
      if (*(int *)(this + 0x238) == 3) {
        ArSoftwareUpdateManager::getInstance();
        ArSoftwareUpdateManager::ResetOADInfo();
      }
      ArSoftwareUpdateManager::getInstance();
      ArSoftwareUpdateManager::PlayCurrentProgram();
      MWnd::GetParentApp();
      MApplet::Kill();
    }
    else if ((*(int *)(this + 0x238) == 0xb) || (*(int *)(this + 0x238) == 6)) {
      printf("[OADFRAME %s:%d]> Red key received: Erase Downloaded\n",&UNK_0100a070,0xa36);
      ArSoftwareUpdateManager::getInstance();
      ArSoftwareUpdateManager::ResetStandbyOADInfo();
      MWnd::GetParentApp();
      MApplet::Kill();
    }
    else if (*(int *)(this + 0x238) == 4) {
      printf("[OADFRAME %s:%d]> Red key received: Erase found Sch OAD\n",&UNK_0100a070,0xa3e);
      ArSoftwareUpdateManager::getInstance();
      ArSoftwareUpdateManager::SetUIStopOad();
      ArSoftwareUpdateManager::getInstance();
      ArSoftwareUpdateManager::ResetStandbyOADInfo();
      MWnd::GetParentApp();
      MApplet::Kill();
    }
  }
  return 1;
}

