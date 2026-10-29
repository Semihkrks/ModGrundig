
/* MenuBackgroundFrame::SetBreadCrumbs(int, std::string) */

void __thiscall
MenuBackgroundFrame::SetBreadCrumbs(MenuBackgroundFrame *this,int param_1,string *param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  char *pcVar3;
  ostream *poVar4;
  undefined3 extraout_var_00;
  string asStack_148 [4];
  allocator aaStack_144 [4];
  string asStack_140 [4];
  string asStack_13c [4];
  allocator aaStack_138 [4];
  string asStack_134 [4];
  string asStack_130 [4];
  allocator aaStack_12c [4];
  string asStack_128 [4];
  string asStack_124 [4];
  string asStack_120 [4];
  allocator aaStack_11c [4];
  string asStack_118 [4];
  allocator aaStack_114 [4];
  string asStack_110 [4];
  allocator aaStack_10c [4];
  string asStack_108 [4];
  ostringstream aoStack_104 [180];
  string *psStack_50;
  string *psStack_4c;
  string *psStack_48;
  string *psStack_44;
  string *psStack_40;
  string *psStack_3c;
  string *psStack_38;
  string *psStack_34;
  string *psStack_30;
  string *psStack_2c;
  string *psStack_28;
  string *psStack_24;
  string *psStack_20;
  
  std::ostringstream::ostringstream(aoStack_104,0x10);
  if (param_1 == 0) {
    std::allocator<char>::allocator();
                    /* try { // try from 00db53b8 to 00db53bf has its CatchHandler @ 00db548c */
    std::string::string(asStack_108,"",aaStack_10c);
                    /* try { // try from 00db53d8 to 00db53df has its CatchHandler @ 00db5430 */
    std::ostringstream::str((string *)aoStack_104);
    psStack_20 = asStack_108;
                    /* try { // try from 00db53f4 to 00db53fb has its CatchHandler @ 00db548c */
    std::string::~string(psStack_20);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_10c);
                    /* try { // try from 00db541c to 00db5423 has its CatchHandler @ 00db6674 */
    ArServiceSettingsManager::getInstance();
                    /* try { // try from 00db5478 to 00db579f has its CatchHandler @ 00db6674 */
    iVar2 = ArServiceSettingsManager::ArTvConf_GetOsdSelection();
    if (iVar2 == 4) {
      MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x260);
      MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x274);
      MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x288);
      MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x29c);
      MImg::Set((short)*(undefined4 *)(this + 0x1bc) + 0x260);
      MImg::Set((short)*(undefined4 *)(this + 0x1bc) + 0x274);
      MImg::Set((short)*(undefined4 *)(this + 0x1bc) + 0x288);
      MImg::Set((short)*(undefined4 *)(this + 0x1bc) + 0x29c);
    }
    else {
      ArServiceSettingsManager::getInstance();
      iVar2 = ArServiceSettingsManager::ArTvConf_GetOsdSelection();
      if (iVar2 == 3) {
        MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x260);
        MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x274);
        MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x288);
        MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x29c);
      }
      else {
        MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x260);
        MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x274);
        MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x288);
        MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x29c);
      }
    }
    MWidget::Invalidate();
    ArServiceSettingsManager::getInstance();
    iVar2 = ArServiceSettingsManager::ArTvConf_GetOsdSelection();
    if (iVar2 == 4) {
      psStack_24 = (string *)(*(int *)(this + 0x1c0) + 0x170);
      std::allocator<char>::allocator();
                    /* try { // try from 00db57fc to 00db5803 has its CatchHandler @ 00db58a0 */
      std::string::string(asStack_110,"",aaStack_114);
                    /* try { // try from 00db5818 to 00db581f has its CatchHandler @ 00db5860 */
      MString::Set(psStack_24);
      psStack_28 = asStack_110;
                    /* try { // try from 00db5834 to 00db583b has its CatchHandler @ 00db58a0 */
      std::string::~string(psStack_28);
      std::allocator<char>::~allocator((allocator<char> *)aaStack_114);
    }
    else {
      psStack_2c = (string *)(*(int *)(this + 0x1c0) + 0x170);
                    /* try { // try from 00db58f0 to 00db590b has its CatchHandler @ 00db6674 */
      ArTvSettingsManager::getInstance();
      pcVar3 = (char *)ArTvSettingsManager::GetTVName();
      std::allocator<char>::allocator();
                    /* try { // try from 00db5944 to 00db594b has its CatchHandler @ 00db59e8 */
      std::string::string(asStack_118,pcVar3,aaStack_11c);
                    /* try { // try from 00db5960 to 00db5967 has its CatchHandler @ 00db59a8 */
      MString::Set(psStack_2c);
      psStack_30 = asStack_118;
                    /* try { // try from 00db597c to 00db5983 has its CatchHandler @ 00db59e8 */
      std::string::~string(psStack_30);
      std::allocator<char>::~allocator((allocator<char> *)aaStack_11c);
    }
                    /* try { // try from 00db5a34 to 00db5a67 has its CatchHandler @ 00db6674 */
    MWidget::Invalidate();
    psStack_34 = (string *)(this + 0x1d8);
    std::ostringstream::str();
                    /* try { // try from 00db5a7c to 00db5a83 has its CatchHandler @ 00db5ad4 */
    std::string::operator=(psStack_34,asStack_120);
                    /* try { // try from 00db5a94 to 00db5ac7 has its CatchHandler @ 00db6674 */
    std::string::~string(asStack_120);
    psStack_38 = (string *)(this + 0x1dc);
    std::ostringstream::str();
                    /* try { // try from 00db5b20 to 00db5b27 has its CatchHandler @ 00db5b4c */
    std::string::operator=(psStack_38,asStack_124);
                    /* try { // try from 00db5b38 to 00db5b3f has its CatchHandler @ 00db6674 */
    std::string::~string(asStack_124);
  }
  if (param_1 == 1) {
    std::allocator<char>::allocator();
                    /* try { // try from 00db5bcc to 00db5bd3 has its CatchHandler @ 00db5cc4 */
    std::string::string(asStack_128,"",aaStack_12c);
                    /* try { // try from 00db5bec to 00db5bf3 has its CatchHandler @ 00db5c58 */
    std::ostringstream::str((string *)aoStack_104);
    psStack_3c = asStack_128;
                    /* try { // try from 00db5c08 to 00db5c0f has its CatchHandler @ 00db5cc4 */
    std::string::~string(psStack_3c);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_12c);
                    /* try { // try from 00db5c44 to 00db5c4b has its CatchHandler @ 00db6674 */
    MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x260);
                    /* try { // try from 00db5cb0 to 00db5e43 has its CatchHandler @ 00db6674 */
    MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x274);
    MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x288);
    MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x29c);
    MWidget::Invalidate();
    bVar1 = std::operator!=(param_3,"");
    if (CONCAT31(extraout_var,bVar1) != 0) {
      std::string::operator=((string *)(this + 0x1d8),param_3);
    }
    pcVar3 = (char *)GetRcEngine::RcGetString(0xf49);
    poVar4 = std::operator<<((ostream *)aoStack_104,pcVar3);
    poVar4 = std::operator<<(poVar4,"   >   ");
    std::operator<<(poVar4,(string *)(this + 0x1d8));
    psStack_40 = (string *)(*(int *)(this + 0x1c0) + 0x170);
    std::ostringstream::str();
                    /* try { // try from 00db5e58 to 00db5e5f has its CatchHandler @ 00db5ea0 */
    MString::Set(psStack_40);
                    /* try { // try from 00db5e70 to 00db5e93 has its CatchHandler @ 00db6674 */
    std::string::~string(asStack_130);
    MWidget::Invalidate();
  }
  if (param_1 == 2) {
    std::allocator<char>::allocator();
                    /* try { // try from 00db5f20 to 00db5f27 has its CatchHandler @ 00db6018 */
    std::string::string(asStack_134,"",aaStack_138);
                    /* try { // try from 00db5f40 to 00db5f47 has its CatchHandler @ 00db5fac */
    std::ostringstream::str((string *)aoStack_104);
    psStack_44 = asStack_134;
                    /* try { // try from 00db5f5c to 00db5f63 has its CatchHandler @ 00db6018 */
    std::string::~string(psStack_44);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_138);
                    /* try { // try from 00db5f98 to 00db5f9f has its CatchHandler @ 00db6674 */
    MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x260);
                    /* try { // try from 00db6004 to 00db61d7 has its CatchHandler @ 00db6674 */
    MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x274);
    MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x288);
    MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x29c);
    MWidget::Invalidate();
    bVar1 = std::operator!=(param_3,"");
    if (CONCAT31(extraout_var_00,bVar1) != 0) {
      std::string::operator=((string *)(this + 0x1dc),param_3);
    }
    pcVar3 = (char *)GetRcEngine::RcGetString(0xf49);
    poVar4 = std::operator<<((ostream *)aoStack_104,pcVar3);
    poVar4 = std::operator<<(poVar4,"   >   ");
    poVar4 = std::operator<<(poVar4,(string *)(this + 0x1d8));
    poVar4 = std::operator<<(poVar4,"   >   ");
    std::operator<<(poVar4,(string *)(this + 0x1dc));
    psStack_48 = (string *)(*(int *)(this + 0x1c0) + 0x170);
    std::ostringstream::str();
                    /* try { // try from 00db61ec to 00db61f3 has its CatchHandler @ 00db6234 */
    MString::Set(psStack_48);
                    /* try { // try from 00db6204 to 00db6227 has its CatchHandler @ 00db6674 */
    std::string::~string(asStack_13c);
    MWidget::Invalidate();
  }
  if (param_1 == 3) {
    std::allocator<char>::allocator();
                    /* try { // try from 00db62b4 to 00db62bb has its CatchHandler @ 00db63a8 */
    std::string::string(asStack_140,"",aaStack_144);
                    /* try { // try from 00db62d4 to 00db62db has its CatchHandler @ 00db633c */
    std::ostringstream::str((string *)aoStack_104);
    psStack_4c = asStack_140;
                    /* try { // try from 00db62f0 to 00db62f7 has its CatchHandler @ 00db63a8 */
    std::string::~string(psStack_4c);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_144);
                    /* try { // try from 00db6328 to 00db632f has its CatchHandler @ 00db6674 */
    std::string::operator=((string *)(this + 0x1e0),param_3);
                    /* try { // try from 00db6394 to 00db6587 has its CatchHandler @ 00db6674 */
    MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x260);
    MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x274);
    MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x288);
    MImg::Set((short)*(undefined4 *)(this + 0x1b8) + 0x29c);
    MWidget::Invalidate();
    pcVar3 = (char *)GetRcEngine::RcGetString(0xf49);
    poVar4 = std::operator<<((ostream *)aoStack_104,pcVar3);
    poVar4 = std::operator<<(poVar4,"   >   ");
    poVar4 = std::operator<<(poVar4,(string *)(this + 0x1d8));
    poVar4 = std::operator<<(poVar4,"   >   ");
    poVar4 = std::operator<<(poVar4,(string *)(this + 0x1dc));
    poVar4 = std::operator<<(poVar4,"   >   ");
    std::operator<<(poVar4,(string *)(this + 0x1e0));
    psStack_50 = (string *)(*(int *)(this + 0x1c0) + 0x170);
    std::ostringstream::str();
                    /* try { // try from 00db659c to 00db65a3 has its CatchHandler @ 00db65e4 */
    MString::Set(psStack_50);
                    /* try { // try from 00db65b4 to 00db65d7 has its CatchHandler @ 00db6674 */
    std::string::~string(asStack_148);
    MWidget::Invalidate();
  }
                    /* try { // try from 00db6630 to 00db6637 has its CatchHandler @ 00db6674 */
  MWidget::Invalidate();
  std::ostringstream::~ostringstream(aoStack_104);
  return;
}

