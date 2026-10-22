
undefined4 FUN_00ea1e5c(undefined4 param_1)

{
  char cVar1;
  ArTvSettingsManager *this;
  char *pcVar2;
  allocator aaStack_104 [4];
  string asStack_100 [4];
  string asStack_fc [4];
  allocator aaStack_f8 [4];
  string asStack_f4 [4];
  vector<std::string,std::allocator<std::string>> avStack_f0 [12];
  string asStack_e4 [4];
  ostringstream aoStack_e0 [184];
  undefined4 uStack_28;
  string *psStack_24;
  string *psStack_20;
  
  std::vector<std::string,std::allocator<std::string>>::vector(avStack_f0);
                    /* try { // try from 00ea1ebc to 00ea1ec3 has its CatchHandler @ 00ea2548 */
  std::ostringstream::ostringstream(aoStack_e0,0x10);
                    /* try { // try from 00ea1ed4 to 00ea1edb has its CatchHandler @ 00ea250c */
  std::string::string(asStack_e4);
                    /* try { // try from 00ea1ee4 to 00ea1fbf has its CatchHandler @ 00ea2494 */
  this = (ArTvSettingsManager *)ArTvSettingsManager::getInstance();
  cVar1 = ArTvSettingsManager::GetRestorePoint(this,asStack_e4);
  if (cVar1 == '\x01') {
    pcVar2 = (char *)GetRcEngine::RcGetString(0x119f);
    std::operator<<((ostream *)aoStack_e0,pcVar2);
    std::operator<<((ostream *)aoStack_e0," (");
    std::operator<<((ostream *)aoStack_e0,asStack_e4);
    std::operator<<((ostream *)aoStack_e0,")");
    pcVar2 = (char *)GetRcEngine::RcGetString(0x10e5);
    std::allocator<char>::allocator();
                    /* try { // try from 00ea1ff8 to 00ea1fff has its CatchHandler @ 00ea20e8 */
    std::string::string(asStack_f4,pcVar2,aaStack_f8);
                    /* try { // try from 00ea2018 to 00ea201f has its CatchHandler @ 00ea2080 */
    std::vector<std::string,std::allocator<std::string>>::push_back(avStack_f0,asStack_f4);
    psStack_20 = asStack_f4;
                    /* try { // try from 00ea2034 to 00ea203b has its CatchHandler @ 00ea20e8 */
    std::string::~string(psStack_20);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_f8);
                    /* try { // try from 00ea206c to 00ea2073 has its CatchHandler @ 00ea2494 */
    std::ostringstream::str();
                    /* try { // try from 00ea20d4 to 00ea20db has its CatchHandler @ 00ea2154 */
    std::vector<std::string,std::allocator<std::string>>::push_back(avStack_f0,asStack_fc);
                    /* try { // try from 00ea2130 to 00ea2147 has its CatchHandler @ 00ea2494 */
    std::string::~string(asStack_fc);
    PopUpManager::Clean();
                    /* try { // try from 00ea2198 to 00ea2263 has its CatchHandler @ 00ea2494 */
    pcVar2 = (char *)GetRcEngine::RcGetString(0x11b4);
    std::string::operator=((string *)PopUpManager::itemSelectData,pcVar2);
    std::vector<std::string,std::allocator<std::string>>::operator=
              ((vector<std::string,std::allocator<std::string>> *)(PopUpManager::itemSelectData + 8)
               ,(vector *)avStack_f0);
    PopUpManager::itemSelectData._4_4_ = 0;
    PopUpManager::popupID = 0x2c;
    PopUpManager::handleBackInPopUp = 1;
    PopUpManager::parentFrame = param_1;
    PopUpManager::ShowButton(7,0xf37);
    PopUpManager::ShowButton(0xe,0xc42);
    PopUpManager::Summon(1);
  }
  else {
    pcVar2 = (char *)GetRcEngine::RcGetString(0x10e5);
    std::allocator<char>::allocator();
                    /* try { // try from 00ea229c to 00ea22a3 has its CatchHandler @ 00ea2370 */
    std::string::string(asStack_100,pcVar2,aaStack_104);
                    /* try { // try from 00ea22bc to 00ea22c3 has its CatchHandler @ 00ea2314 */
    std::vector<std::string,std::allocator<std::string>>::push_back(avStack_f0,asStack_100);
    psStack_24 = asStack_100;
                    /* try { // try from 00ea22d8 to 00ea22df has its CatchHandler @ 00ea2370 */
    std::string::~string(psStack_24);
    std::allocator<char>::~allocator((allocator<char> *)aaStack_104);
                    /* try { // try from 00ea2300 to 00ea2307 has its CatchHandler @ 00ea2494 */
    PopUpManager::Clean();
                    /* try { // try from 00ea235c to 00ea244f has its CatchHandler @ 00ea2494 */
    pcVar2 = (char *)GetRcEngine::RcGetString(0x11b4);
    std::string::operator=((string *)PopUpManager::itemSelectData,pcVar2);
    std::vector<std::string,std::allocator<std::string>>::operator=
              ((vector<std::string,std::allocator<std::string>> *)(PopUpManager::itemSelectData + 8)
               ,(vector *)avStack_f0);
    PopUpManager::itemSelectData._4_4_ = 0;
    PopUpManager::popupID = 0x2c;
    PopUpManager::handleBackInPopUp = 1;
    PopUpManager::parentFrame = param_1;
    PopUpManager::ShowButton(7,0xf37);
    PopUpManager::ShowButton(0xe,0xc42);
    PopUpManager::Summon(1);
  }
  uStack_28 = 1;
                    /* try { // try from 00ea2468 to 00ea246f has its CatchHandler @ 00ea250c */
  std::string::~string(asStack_e4);
                    /* try { // try from 00ea2480 to 00ea2487 has its CatchHandler @ 00ea2548 */
  std::ostringstream::~ostringstream(aoStack_e0);
  std::vector<std::string,std::allocator<std::string>>::~vector(avStack_f0);
  return uStack_28;
}

