
/* ArUIManager::GetFrame(unsigned long) */

undefined4 ArUIManager::GetFrame(ulong param_1)

{
  int iVar1;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  if (param_1 == 1) {
    MSystem::GetInstance();
    MSystem::GetMWindowManager();
    MWindowManager::GetFocusedApp();
    MApplet::GetMainFrame();
    uStack_10 = MMainFrame::GetDFBSurface();
  }
  else {
    iVar1 = MSystem::GetInstance();
    (**(code **)(*(int *)(iVar1 + 0xc) + 0x20))(*(int *)(iVar1 + 0xc),&uStack_14);
    uStack_10 = uStack_14;
  }
  return uStack_10;
}

