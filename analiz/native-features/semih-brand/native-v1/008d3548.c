
/* CommonFrame::CommonFrame(MApplet*, _Rect&) */

void __thiscall CommonFrame::CommonFrame(CommonFrame *this,MApplet *param_1,_Rect *param_2)

{
  bool bVar1;
  int iVar2;
  ArVideoManager *this_00;
  
  MMainFrame::MMainFrame((MMainFrame *)this,param_1,param_2);
  *(undefined ***)this = &PTR_FUN_010bb000;
  std::vector<bubblehelppair,std::allocator<bubblehelppair>>::vector
            ((vector<bubblehelppair,std::allocator<bubblehelppair>> *)(this + 0x10c));
  strncpy((char *)(this + 0xa8),"Common",99);
  *(undefined4 *)(this + 0xa4) = 0;
  if ((((param_1 == (MApplet *)0x0) ||
       (iVar2 = __dynamic_cast(param_1,&MApplet::typeinfo,&IdleAppApp::typeinfo,0), iVar2 == 0)) &&
      ((param_1 == (MApplet *)0x0 ||
       (iVar2 = __dynamic_cast(param_1,&MApplet::typeinfo,&VolumeControlApp::typeinfo,0), iVar2 == 0
       )))) && (((param_1 == (MApplet *)0x0 ||
                 (iVar2 = __dynamic_cast(param_1,&MApplet::typeinfo,&MuteControlApp::typeinfo,0),
                 iVar2 == 0)) &&
                ((param_1 == (MApplet *)0x0 ||
                 (iVar2 = __dynamic_cast(param_1,&MApplet::typeinfo,&ZappMenuApp::typeinfo,0),
                 iVar2 == 0)))))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    if (((param_1 == (MApplet *)0x0) ||
        (iVar2 = __dynamic_cast(param_1,&MApplet::typeinfo,&PictureAdjustApp::typeinfo,0),
        iVar2 == 0)) &&
       ((param_1 == (MApplet *)0x0 ||
        (iVar2 = __dynamic_cast(param_1,&MApplet::typeinfo,&DMPMoviePlayerApp::typeinfo,0),
        iVar2 == 0)))) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
                    /* try { // try from 008d37ac to 008d3873 has its CatchHandler @ 008d3880 */
      this_00 = (ArVideoManager *)ArVideoManager::getInstance();
      ArVideoManager::RestoreMEMC(this_00);
    }
    else {
      IdleAppFrame::GetIdleAppFrame();
      iVar2 = IdleAppFrame::IsScreenEmpty('\x01');
      if (iVar2 == 0) {
        iVar2 = DMPMoviePlayerFrame::GetDMPMoviePlayerFrame();
        if (iVar2 != 0) {
          ArVideoManager::getInstance();
          ArVideoManager::SetMfcOff();
        }
      }
      else {
        ArVideoManager::getInstance();
        ArVideoManager::SetMfcOff();
      }
    }
    return;
  }
  return;
}

