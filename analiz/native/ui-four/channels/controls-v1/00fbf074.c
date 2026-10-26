
/* ZappMenuFrame::SetZappChannel(ChannelInfo, unsigned char, int) */

void __thiscall
ZappMenuFrame::SetZappChannel
          (ZappMenuFrame *this,int param_2,ZappMenuFrame param_3,undefined4 param_4)

{
  char cVar1;
  void *pvVar2;
  PVRFrame *this_00;
  char *pcVar3;
  int iVar4;
  ostream *poVar5;
  string asStack_280 [4];
  allocator aaStack_27c [4];
  string asStack_278 [4];
  allocator aaStack_274 [4];
  string asStack_270 [4];
  string asStack_26c [4];
  string asStack_268 [4];
  string asStack_264 [4];
  string asStack_260 [4];
  string asStack_25c [4];
  string asStack_258 [4];
  string asStack_254 [4];
  undefined1 auStack_250 [100];
  allocator aaStack_1ec [4];
  string asStack_1e8 [4];
  char acStack_1e4 [64];
  ostringstream aoStack_1a4 [180];
  ostringstream aoStack_f0 [184];
  string *psStack_38;
  string *psStack_34;
  string *psStack_30;
  string *psStack_2c;
  string *psStack_28;
  string *psStack_24;
  string *psStack_20;
  string *psStack_1c;
  
  std::ostringstream::ostringstream(aoStack_1a4,0x10);
  std::allocator<char>::allocator();
                    /* try { // try from 00fbf100 to 00fbf107 has its CatchHandler @ 00fbf1b0 */
  std::string::string(asStack_1e8,"",aaStack_1ec);
                    /* try { // try from 00fbf120 to 00fbf127 has its CatchHandler @ 00fbf174 */
  std::operator<<((ostream *)aoStack_1a4,asStack_1e8);
                    /* try { // try from 00fbf138 to 00fbf13f has its CatchHandler @ 00fbf1b0 */
  std::string::~string(asStack_1e8);
  std::allocator<char>::~allocator((allocator<char> *)aaStack_1ec);
  if ((this[0x200] == (ZappMenuFrame)0x0) || (this[0x200] == (ZappMenuFrame)0x1)) {
    if (this[0x20c] == (ZappMenuFrame)0x0) {
      if ((this[0x200] == (ZappMenuFrame)0x0) && (param_3 != this[0x200])) {
                    /* try { // try from 00fbf238 to 00fbf36b has its CatchHandler @ 00fc03a4 */
        pvVar2 = (void *)ArTvManager::getInstance();
        ArTvManager::OnNtyKey_Button_DTV(pvVar2,(void *)0x0,(void *)0x0);
      }
      else if ((this[0x200] == (ZappMenuFrame)0x1) && (param_3 != this[0x200])) {
        pvVar2 = (void *)ArTvManager::getInstance();
        ArTvManager::OnNtyKey_Button_ATV(pvVar2,(void *)0x0,(void *)0x0);
      }
      this_00 = (PVRFrame *)PVRFrame::GetInstance();
      if (this_00 != (PVRFrame *)0x0) {
        PVRFrame::StopAllPVRFunctionsExceptRecording(this_00,'\x01');
      }
      cVar1 = ArChannelManager::SelectChannel
                        ((uint)*(ushort *)(this + 0x19e),(uchar)this[0x1a0],(uchar)this[0x1a1],'\0')
      ;
      if (cVar1 == '\0') {
        FUN_00fbed54(auStack_250,this + 0x19c);
                    /* try { // try from 00fbf398 to 00fbf39f has its CatchHandler @ 00fbf3c8 */
        SetZappChannel(this,auStack_250,this[0x200],*(undefined4 *)(this + 0x204));
                    /* try { // try from 00fbf3b4 to 00fbf3bb has its CatchHandler @ 00fc03a4 */
        FUN_00fbe710(auStack_250);
      }
    }
  }
  else if ((this[0x200] == (ZappMenuFrame)0x5) && ((byte)this[0x200] < 10)) {
    if (this[0x20c] == (ZappMenuFrame)0x0) {
                    /* try { // try from 00fbf444 to 00fbf76f has its CatchHandler @ 00fc03a4 */
      pvVar2 = (void *)ArTvManager::getInstance();
      ArTvManager::OnNtyKey_Button_HDMI(pvVar2,*(void **)(this + 0x204),(void *)0x0);
    }
  }
  else if (((byte)this[0x200] < 4) ||
          ((4 < (byte)this[0x200] || (this[0x20c] != (ZappMenuFrame)0x0)))) {
    if (((byte)this[0x200] < 0xc) ||
       ((0xc < (byte)this[0x200] || (this[0x20c] != (ZappMenuFrame)0x0)))) {
      if (((byte)this[0x200] < 2) ||
         ((2 < (byte)this[0x200] || (this[0x20c] != (ZappMenuFrame)0x0)))) {
        if (((byte)this[0x200] < 10) ||
           ((10 < (byte)this[0x200] || (this[0x20c] != (ZappMenuFrame)0x0)))) {
          if (((byte)this[0x200] < 0xb) ||
             ((0xb < (byte)this[0x200] || (this[0x20c] != (ZappMenuFrame)0x0)))) {
            if ((2 < (byte)this[0x200]) &&
               (((byte)this[0x200] < 4 && (this[0x20c] == (ZappMenuFrame)0x0)))) {
              pvVar2 = (void *)ArTvManager::getInstance();
              ArTvManager::OnNtyKey_Button_Component(pvVar2,(void *)0x0,(void *)0x0);
            }
          }
          else {
            pvVar2 = (void *)ArTvManager::getInstance();
            ArTvManager::OnNtyKey_Button_SV(pvVar2,(void *)0x0,(void *)0x0);
          }
        }
        else {
          pvVar2 = (void *)ArTvManager::getInstance();
          ArTvManager::OnNtyKey_Button_AV(pvVar2,(void *)0x0,(void *)0x0);
        }
      }
      else {
        pvVar2 = (void *)ArTvManager::getInstance();
        ArTvManager::OnNtyKey_Button_Scart(pvVar2,(void *)0x0,(void *)0x0);
      }
    }
  }
  else {
    pvVar2 = (void *)ArTvManager::getInstance();
    ArTvManager::OnNtyKey_Button_PCRGB(pvVar2,(void *)0x0,(void *)0x0);
  }
  if (param_3 == (ZappMenuFrame)0x5) {
    MImg::Set((short)*(undefined4 *)(this + 400) + 0x260);
    psStack_1c = (string *)(*(int *)(this + 0x18c) + 0x170);
    ArTvManager::getInstance();
    ArTvManager::GetSourceName((ulong)asStack_254);
                    /* try { // try from 00fbf784 to 00fbf78b has its CatchHandler @ 00fbf7b0 */
    MString::Set(psStack_1c);
                    /* try { // try from 00fbf79c to 00fbf7a3 has its CatchHandler @ 00fc03a4 */
    std::string::~string(asStack_254);
  }
  else if (((byte)param_3 < 4) || (4 < (byte)param_3)) {
    if (((byte)param_3 < 0xc) || (0xc < (byte)param_3)) {
      if (((byte)param_3 < 2) || (2 < (byte)param_3)) {
        if (((byte)param_3 < 10) || (10 < (byte)param_3)) {
          if (((byte)param_3 < 0xb) || (0xb < (byte)param_3)) {
            if (((byte)param_3 < 3) || (3 < (byte)param_3)) {
              if ((param_3 == (ZappMenuFrame)0x0) || (param_3 == (ZappMenuFrame)0x1)) {
                    /* try { // try from 00fbfe70 to 00fbfe77 has its CatchHandler @ 00fc03a4 */
                std::ostringstream::ostringstream(aoStack_f0,0x10);
                std::allocator<char>::allocator();
                    /* try { // try from 00fbfeb0 to 00fbfeb7 has its CatchHandler @ 00fbff7c */
                std::string::string(asStack_270,"",aaStack_274);
                    /* try { // try from 00fbfed0 to 00fbfed7 has its CatchHandler @ 00fbff28 */
                std::operator<<((ostream *)aoStack_f0,asStack_270);
                    /* try { // try from 00fbfee8 to 00fbfeef has its CatchHandler @ 00fbff7c */
                std::string::~string(asStack_270);
                std::allocator<char>::~allocator((allocator<char> *)aaStack_274);
                    /* try { // try from 00fbff14 to 00fbff1b has its CatchHandler @ 00fc0290 */
                iVar4 = ArChannelManager::GetChannelCount(0);
                if (iVar4 < 1) {
                    /* try { // try from 00fc0184 to 00fc01d7 has its CatchHandler @ 00fc0290 */
                  pcVar3 = (char *)GetRcEngine::RcGetString(0xe32);
                  std::operator<<((ostream *)aoStack_f0,pcVar3);
                }
                else {
                  if (param_3 == (ZappMenuFrame)0x1) {
                    sprintf(acStack_1e4,"%d",*(ushort *)(param_2 + 2) + 1);
                  }
                  else {
                    sprintf(acStack_1e4,"%d",(uint)*(ushort *)(param_2 + 2));
                  }
                  std::allocator<char>::allocator();
                    /* try { // try from 00fc0060 to 00fc0067 has its CatchHandler @ 00fc0140 */
                  std::string::string(asStack_278,acStack_1e4,aaStack_27c);
                    /* try { // try from 00fc0080 to 00fc00c7 has its CatchHandler @ 00fc0104 */
                  poVar5 = std::operator<<((ostream *)aoStack_f0,asStack_278);
                  poVar5 = std::operator<<(poVar5," ");
                  std::operator<<(poVar5,(string *)(param_2 + 8));
                    /* try { // try from 00fc00d8 to 00fc00df has its CatchHandler @ 00fc0140 */
                  std::string::~string(asStack_278);
                  std::allocator<char>::~allocator((allocator<char> *)aaStack_27c);
                }
                psStack_38 = (string *)(*(int *)(this + 0x18c) + 0x170);
                std::ostringstream::str();
                    /* try { // try from 00fc01ec to 00fc01f3 has its CatchHandler @ 00fc0234 */
                MString::Set(psStack_38);
                    /* try { // try from 00fc0204 to 00fc0227 has its CatchHandler @ 00fc0290 */
                std::string::~string(asStack_280);
                MWidget::Hide();
                    /* try { // try from 00fc027c to 00fc0283 has its CatchHandler @ 00fc03a4 */
                std::ostringstream::~ostringstream(aoStack_f0);
              }
            }
            else {
                    /* try { // try from 00fbfd60 to 00fbfdc7 has its CatchHandler @ 00fc03a4 */
              MImg::Set((short)*(undefined4 *)(this + 400) + 0x260);
              pcVar3 = (char *)GetRcEngine::RcGetString(0x9b8);
              std::operator<<((ostream *)aoStack_1a4,pcVar3);
              psStack_34 = (string *)(*(int *)(this + 0x18c) + 0x170);
              std::ostringstream::str();
                    /* try { // try from 00fbfddc to 00fbfde3 has its CatchHandler @ 00fbfe08 */
              MString::Set(psStack_34);
                    /* try { // try from 00fbfdf4 to 00fbfdfb has its CatchHandler @ 00fc03a4 */
              std::string::~string(asStack_26c);
            }
          }
          else {
                    /* try { // try from 00fbfc54 to 00fbfcab has its CatchHandler @ 00fc03a4 */
            MImg::Set((short)*(undefined4 *)(this + 400) + 0x260);
            std::operator<<((ostream *)aoStack_1a4,"S-VHS");
            psStack_30 = (string *)(*(int *)(this + 0x18c) + 0x170);
            std::ostringstream::str();
                    /* try { // try from 00fbfcc0 to 00fbfcc7 has its CatchHandler @ 00fbfcec */
            MString::Set(psStack_30);
                    /* try { // try from 00fbfcd8 to 00fbfcdf has its CatchHandler @ 00fc03a4 */
            std::string::~string(asStack_268);
          }
        }
        else {
                    /* try { // try from 00fbfb48 to 00fbfb9f has its CatchHandler @ 00fc03a4 */
          MImg::Set((short)*(undefined4 *)(this + 400) + 0x260);
          std::operator<<((ostream *)aoStack_1a4,"AV");
          psStack_2c = (string *)(*(int *)(this + 0x18c) + 0x170);
          std::ostringstream::str();
                    /* try { // try from 00fbfbb4 to 00fbfbbb has its CatchHandler @ 00fbfbe0 */
          MString::Set(psStack_2c);
                    /* try { // try from 00fbfbcc to 00fbfbd3 has its CatchHandler @ 00fc03a4 */
          std::string::~string(asStack_264);
        }
      }
      else {
                    /* try { // try from 00fbfa3c to 00fbfa93 has its CatchHandler @ 00fc03a4 */
        MImg::Set((short)*(undefined4 *)(this + 400) + 0x260);
        std::operator<<((ostream *)aoStack_1a4,"Scart");
        psStack_28 = (string *)(*(int *)(this + 0x18c) + 0x170);
        std::ostringstream::str();
                    /* try { // try from 00fbfaa8 to 00fbfaaf has its CatchHandler @ 00fbfad4 */
        MString::Set(psStack_28);
                    /* try { // try from 00fbfac0 to 00fbfac7 has its CatchHandler @ 00fc03a4 */
        std::string::~string(asStack_260);
      }
    }
    else {
                    /* try { // try from 00fbf930 to 00fbf987 has its CatchHandler @ 00fc03a4 */
      MImg::Set((short)*(undefined4 *)(this + 400) + 0x260);
      std::operator<<((ostream *)aoStack_1a4,"Storage");
      psStack_24 = (string *)(*(int *)(this + 0x18c) + 0x170);
      std::ostringstream::str();
                    /* try { // try from 00fbf99c to 00fbf9a3 has its CatchHandler @ 00fbf9c8 */
      MString::Set(psStack_24);
                    /* try { // try from 00fbf9b4 to 00fbf9bb has its CatchHandler @ 00fc03a4 */
      std::string::~string(asStack_25c);
    }
  }
  else {
                    /* try { // try from 00fbf820 to 00fbf87b has its CatchHandler @ 00fc03a4 */
    std::operator<<((ostream *)aoStack_1a4,"PC");
    MImg::Set((short)*(undefined4 *)(this + 400) + 0x260);
    psStack_20 = (string *)(*(int *)(this + 0x18c) + 0x170);
    std::ostringstream::str();
                    /* try { // try from 00fbf890 to 00fbf897 has its CatchHandler @ 00fbf8bc */
    MString::Set(psStack_20);
                    /* try { // try from 00fbf8a8 to 00fbf8af has its CatchHandler @ 00fc03a4 */
    std::string::~string(asStack_258);
  }
                    /* try { // try from 00fc02dc to 00fc0367 has its CatchHandler @ 00fc03a4 */
  MWidget::Invalidate();
  MWidget::Invalidate();
  FUN_00fbe348(this + 0x19c,param_2);
  this[0x200] = param_3;
  *(undefined4 *)(this + 0x204) = param_4;
  if (this[0x20c] == (ZappMenuFrame)0x0) {
    ArProgramInfoApp::Summon(1,'\x01','\x01');
  }
  std::ostringstream::~ostringstream(aoStack_1a4);
  return;
}

