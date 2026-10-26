
undefined4 FUN_00896b88(ChannelControlFrame *param_1,undefined4 param_2,uint param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_3 == 0xf047) {
    piVar1 = (int *)MSrv_Control_common::GetMSrvChannelManager();
    iVar3 = (**(code **)(*piVar1 + 0x24))(piVar1,0xe);
    if (iVar3 != 0) {
      MWnd::GetParentApp();
      ArProgramInfoApp::Summon(3,'\x01','\x01');
      MApplet::Kill();
      return 1;
    }
    return 1;
  }
  if (param_3 < 0xf048) {
    if (param_3 != 0xf012) {
      if (param_3 < 0xf013) {
        if (0x39 < param_3) {
          if (param_3 != 0xf00f) {
            return 1;
          }
          return 0;
        }
        if (param_3 < 0x30) {
          if (param_3 != 0xd) {
            return 1;
          }
          if ((param_1[0x1a4] != (ChannelControlFrame)0x0) && ((byte)param_1[0x1a4] < 5)) {
            ChannelControlFrame::OnTimer(param_1,(void *)0x0,(void *)0x0);
          }
          return 1;
        }
        uVar2 = ChannelControlFrame::TenKeyHandle(param_1,param_3);
        return uVar2;
      }
      if (param_3 != 0xf020) {
        if (param_3 < 0xf021) {
          if (param_3 == 0xf014) {
            MWnd::GetParentApp();
            ArProgramInfoApp::Summon(1,'\x01','\x01');
            MApplet::Kill();
            return 1;
          }
          if (param_3 != 0xf01b) {
            return 1;
          }
        }
        else if (param_3 != 0xf022) {
          if (param_3 != 0xf046) {
            return 1;
          }
          piVar1 = (int *)MSrv_Control_common::GetMSrvChannelManager();
          iVar3 = (**(code **)(*piVar1 + 0x20))(piVar1,0xe);
          if (iVar3 != 0) {
            MWnd::GetParentApp();
            ArProgramInfoApp::Summon(3,'\x01','\x01');
            MApplet::Kill();
            return 1;
          }
          return 1;
        }
      }
    }
  }
  else if (param_3 < 0xf075) {
    if ((param_3 < 0xf073) && (param_3 != 0xf068)) {
      if (param_3 < 0xf069) {
        if (param_3 - 0xf04c < 3) {
          return 0;
        }
      }
      else if (param_3 == 0xf070) goto LAB_00896ff0;
      return 1;
    }
  }
  else if (param_3 != 0xf078) {
    if (param_3 < 0xf079) {
      if (param_3 != 0xf075) {
        return 1;
      }
      MWnd::GetParentApp();
      MApplet::Kill();
      return 1;
    }
    if (param_3 != 0xf07d) {
      if (param_3 != 0xf550) {
        return 1;
      }
      return 0;
    }
  }
LAB_00896ff0:
  iVar3 = MWnd::GetParentApp();
  if (iVar3 == 0) {
    printf("ASSERT FAIL: %s %s %d\n",&UNK_00ff1e48,&UNK_00ff1f00,0x12f);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  MEvtHandle::PostEvent((MEvtHandle *)param_1,0,0x14,param_3);
  MApplet::Kill();
  return 1;
}

