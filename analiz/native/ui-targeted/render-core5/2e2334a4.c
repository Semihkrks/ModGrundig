
/* WARNING: Type propagation algorithm not settling */
/* MMainFrame::CreateDFBWindow(_IDirectFBDisplayLayer*, unsigned char) */

undefined4 __thiscall
MMainFrame::CreateDFBWindow(MMainFrame *this,_IDirectFBDisplayLayer *param_1,uchar param_2)

{
  int iVar1;
  MSystem *pMVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 uVar5;
  float local_50;
  float local_4c [3];
  int local_40;
  int local_3c;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  if (param_1 == (_IDirectFBDisplayLayer *)0x0) {
    uVar5 = 0x402;
  }
  else {
    local_34 = *(undefined4 *)(this + 0x1c);
    local_40 = *(int *)(this + 0x24);
    local_30 = *(undefined4 *)(this + 0x20);
    local_3c = *(int *)(this + 0x28);
    local_4c[1] = 1.66755e-43;
    iVar1 = MSystem::GetInstance();
    if (param_2 == '\0' && *(char *)(iVar1 + 0x1e0) == '\0') {
      local_4c[2] = 1.4013e-45;
    }
    else {
      local_4c[2] = 4.2039e-45;
    }
    local_2c = 4;
    if ((0 < *(int *)(this + 0x24)) && (0 < *(int *)(this + 0x28))) {
      iVar1 = (**(code **)(param_1 + 0x78))(param_1,local_4c + 1,this + 0x90);
      if (iVar1 == 0) {
        (**(code **)(*(int *)(this + 0x90) + 0x54))(*(int *)(this + 0x90),0);
        iVar1 = MSystem::GetInstance();
        if (*(char *)(iVar1 + 0x21) == '\0') {
          (**(code **)(*(int *)(this + 0x90) + 0x40))(*(int *)(this + 0x90),2);
          iVar1 = *(int *)(this + 0x90);
        }
        else {
          local_50 = 1.0;
          local_4c[0] = local_50;
          pMVar2 = (MSystem *)MSystem::GetInstance();
          MSystem::GetFrameScaleRatio(pMVar2,&local_50,local_4c);
          (**(code **)(*(int *)(this + 0x90) + 0x40))(*(int *)(this + 0x90),0x10002);
          (**(code **)(*(int *)(this + 0x90) + 0x68))
                    (*(int *)(this + 0x90),(int)((float)*(int *)(this + 0x1c) * local_50),
                     (int)((float)*(int *)(this + 0x20) * local_4c[0]));
          (**(code **)(*(int *)(this + 0x90) + 0x6c))
                    (*(int *)(this + 0x90),(int)((float)local_40 * local_50),
                     (int)((float)local_3c * local_4c[0]));
          iVar1 = *(int *)(this + 0x90);
        }
        (**(code **)(iVar1 + 0x74))(iVar1,0);
        (**(code **)(*(int *)(this + 0x90) + 0x80))();
        iVar1 = (**(code **)(*(int *)(this + 0x90) + 0x24))(*(int *)(this + 0x90),this + 0x5c);
        if (iVar1 == 0) {
          (**(code **)(*(int *)(this + 0x90) + 0x2c))(*(int *)(this + 0x90),this + 0x60);
          pMVar2 = (MSystem *)MSystem::GetInstance();
          uVar3 = MSystem::GetGlobalTransparentColor(pMVar2);
          (**(code **)(*(int *)(this + 0x5c) + 0x48))
                    (*(int *)(this + 0x5c),(uVar3 & 0xffffff) >> 0x10,(uVar3 & 0xffff) >> 8,
                     uVar3 & 0xff,uVar3 >> 0x18);
          (**(code **)(*(int *)(this + 0x5c) + 0x90))(*(int *)(this + 0x5c),1);
          (**(code **)(*(int *)(this + 0x5c) + 0x78))(*(int *)(this + 0x5c),1);
          return 1;
        }
        pcVar4 = "IDirectFBWindow::GetSurface failed";
      }
      else {
        pcVar4 = "IDirectFBDisplayLayer::CreateWindow() failed";
      }
      DirectFBError(pcVar4,iVar1);
                    /* WARNING: Subroutine does not return */
      exit(4);
    }
    puts(">> -----------------------------------------------------------------");
    puts(">> ERROR!! You must specify width and height for main frame.        ");
    puts(">> ERROR!! MainFrame\'s WxH should not be 0 x 0                      ");
    puts(">> ERROR!! MainFrame size must be specify and not equal to 0.       ");
    puts(">> -----------------------------------------------------------------");
    uVar5 = 0x42a;
  }
  printf("ASSERT FAIL: %s %s %d\n","./base/MMainFrame.cpp",
         "BOOL MMainFrame::CreateDFBWindow(IDirectFBDisplayLayer*, BOOL)",uVar5);
                    /* WARNING: Subroutine does not return */
  abort();
}

