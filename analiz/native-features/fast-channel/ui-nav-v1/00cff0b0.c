
/* GeneralSettingsFrame::OnKey(void*, void*, void*) */

undefined4 __thiscall
GeneralSettingsFrame::OnKey(GeneralSettingsFrame *this,void *param_1,void *param_2,void *param_3)

{
  int iVar1;
  uint uVar2;
  FirstTimeFrame *this_00;
  ulong uVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  MenuBackgroundFrame *pMVar7;
  char *pcVar8;
  undefined4 *puVar9;
  uint uVar10;
  PopUpManagerFrame *pPVar11;
  uint uStack_1e0;
  MWidget *pMStack_1dc;
  uint uStack_1d8;
  int iStack_1d4;
  __normal_iterator a_Stack_1cc [4];
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined1 auStack_1bc [4];
  __normal_iterator a_Stack_1b8 [4];
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined1 auStack_1a8 [4];
  vector avStack_1a4 [12];
  __normal_iterator a_Stack_198 [4];
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined1 auStack_188 [4];
  __normal_iterator a_Stack_184 [4];
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined1 auStack_174 [4];
  vector avStack_170 [12];
  __normal_iterator a_Stack_164 [4];
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined1 auStack_154 [4];
  __normal_iterator a_Stack_150 [4];
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined1 auStack_140 [4];
  vector avStack_13c [12];
  __normal_iterator a_Stack_130 [4];
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined1 auStack_120 [4];
  __normal_iterator a_Stack_11c [4];
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined1 auStack_10c [4];
  vector avStack_108 [12];
  vector<std::string,std::allocator<std::string>> avStack_fc [12];
  vector<std::string,std::allocator<std::string>> avStack_f0 [12];
  vector<std::string,std::allocator<std::string>> avStack_e4 [12];
  vector<std::string,std::allocator<std::string>> avStack_d8 [12];
  char acStack_cc [100];
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  void *pvStack_24;
  void *pvStack_20;
  
  if (param_2 == (void *)0xf014) {
    CommonFrame::EnableBubbleHelp((CommonFrame *)this);
    return 1;
  }
  iVar1 = ArTvSettingsManager::IsTvInFirstTime();
  if (iVar1 != 0) {
    pvStack_24 = param_2;
    if (param_2 == (void *)0xf003) {
      if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
        this_00 = (FirstTimeFrame *)FirstTimeFrame::getFrame();
        FirstTimeFrame::focusToBar(this_00,'\0');
        MMainFrame::SwitchFocusTo((MWidget *)this);
        return 1;
      }
    }
    else if (param_2 < (void *)0xf004) {
      if ((void *)0xefff < param_2) {
        if (param_2 < (void *)0xf002) {
          if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
            pvVar4 = (void *)FirstTimeFrame::getFrame();
            uVar5 = FirstTimeFrame::OnKey(pvVar4,param_1,param_2);
            return uVar5;
          }
          if (*(int *)(this + 0x3c) == *(int *)(this + 0x1fc)) {
            return 1;
          }
        }
        else {
          if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
            return 1;
          }
          for (uStack_1d8 = 0;
              uVar2 = (**(code **)(**(int **)(this + 0x198) + 0x44))(*(undefined4 *)(this + 0x198)),
              uStack_1d8 < uVar2; uStack_1d8 = uStack_1d8 + 1) {
            iStack_1d4 = (**(code **)(**(int **)(this + 0x198) + 0x40))
                                   (*(undefined4 *)(this + 0x198),uStack_1d8);
            iVar1 = MWidget::QueryFlag((uchar)iStack_1d4);
            if ((iVar1 == 0) || (*(char *)(iStack_1d4 + 0x38) != '\x01')) {
              iStack_2c = 0;
            }
            else {
              iStack_2c = 1;
            }
            if (iStack_2c != 0) break;
          }
          iVar1 = MWidget::QueryFlag((uchar)iStack_1d4);
          if (iVar1 != 0) {
            return 1;
          }
        }
      }
    }
    else {
      if (param_2 == (void *)0xf062) {
        uVar3 = FirstTimeFrame::getFrame();
        FirstTimeFrame::openMenu(uVar3,'\0');
        return 1;
      }
      if (param_2 == (void *)0xf075) {
        pvVar4 = (void *)FirstTimeFrame::getFrame();
        uVar5 = FirstTimeFrame::OnKey(pvVar4,param_1,(void *)0xf075);
        return uVar5;
      }
      if (param_2 == (void *)0xf045) {
        pvVar4 = (void *)FirstTimeFrame::getFrame();
        uVar5 = FirstTimeFrame::OnKey(pvVar4,param_1,(void *)0xf045);
        return uVar5;
      }
    }
  }
  pvStack_20 = param_2;
  if (param_2 == (void *)0xf003) {
    if (*(int *)(this + 0x3c) != *(int *)(this + 0x180)) {
      return 0;
    }
    ArServiceSettingsManager::getInstance();
    iVar1 = ArServiceSettingsManager::ArTvConf_GetBasicMode();
    if (iVar1 == 1) {
      ArTvSettingsManager::getInstance();
      iVar1 = ArTvSettingsManager::GetBasicMode();
      if (iVar1 == 1) {
        iStack_34 = 1;
        goto LAB_00cffcf8;
      }
    }
    iStack_34 = 0;
LAB_00cffcf8:
    if (iStack_34 == 0) {
      MMainFrame::SwitchFocusTo((MWidget *)this);
    }
    else {
      MMainFrame::SwitchFocusTo((MWidget *)this);
    }
    pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
    MenuBackgroundFrame::focusToBar(pMVar7,'\0');
    return 1;
  }
  if ((void *)0xf003 < param_2) {
    if (param_2 == (void *)0xf043) {
      if (*(int *)(this + 0x294) == 1) {
        puVar9 = (undefined4 *)
                 std::vector<unsigned_long,std::allocator<unsigned_long>>::at
                           ((vector<unsigned_long,std::allocator<unsigned_long>> *)(this + 0x288),
                            (uint)param_3);
        ArResourceManager::SetSecondaryAudioLanguage(*puVar9);
        std::vector<std::string,std::allocator<std::string>>::vector(avStack_e4);
                    /* try { // try from 00d00b2c to 00d00b33 has its CatchHandler @ 00d00e88 */
        PushSubtitleAudioLanguagetoVector();
                    /* try { // try from 00d00b4c to 00d00b53 has its CatchHandler @ 00d00bd0 */
        std::vector<std::string,std::allocator<std::string>>::operator=(avStack_e4,avStack_170);
                    /* try { // try from 00d00b64 to 00d00bc3 has its CatchHandler @ 00d00e88 */
        std::vector<std::string,std::allocator<std::string>>::~vector
                  ((vector<std::string,std::allocator<std::string>> *)avStack_170);
        std::vector<unsigned_long,std::allocator<unsigned_long>>::begin();
        std::vector<unsigned_long,std::allocator<unsigned_long>>::end();
        uStack_180 = ArResourceManager::GetPrimaryAudioLanguage();
        std::
        find<__gnu_cxx::__normal_iterator<unsigned_long*,std::vector<unsigned_long,std::allocator<unsigned_long>>>,unsigned_long>
                  (auStack_174,uStack_178,uStack_17c,&uStack_180);
        std::vector<unsigned_long,std::allocator<unsigned_long>>::begin();
        uVar2 = __gnu_cxx::operator-(auStack_174,a_Stack_184);
        std::vector<unsigned_long,std::allocator<unsigned_long>>::begin();
        std::vector<unsigned_long,std::allocator<unsigned_long>>::end();
                    /* try { // try from 00d00ccc to 00d00e5b has its CatchHandler @ 00d00e88 */
        uStack_194 = ArResourceManager::GetSecondaryAudioLanguage();
        std::
        find<__gnu_cxx::__normal_iterator<unsigned_long*,std::vector<unsigned_long,std::allocator<unsigned_long>>>,unsigned_long>
                  (auStack_188,uStack_18c,uStack_190,&uStack_194);
        std::vector<unsigned_long,std::allocator<unsigned_long>>::begin();
        uVar10 = __gnu_cxx::operator-(auStack_188,a_Stack_198);
        uStack_54 = GetRcEngine::RcGetString(0xec1);
        std::vector<std::string,std::allocator<std::string>>::operator[](avStack_e4,uVar2);
        uStack_58 = std::string::c_str();
        uStack_5c = GetRcEngine::RcGetString(0xf20);
        std::vector<std::string,std::allocator<std::string>>::operator[](avStack_e4,uVar10);
        uVar5 = std::string::c_str();
        sprintf(acStack_cc,"%s %s, %s %s",uStack_54,uStack_58,uStack_5c,uVar5);
        std::string::operator=((string *)(PopUpManager::gridSelectData + 0xc),acStack_cc);
        pPVar11 = (PopUpManagerFrame *)PopUpManagerFrame::GetInstance();
        PopUpManagerFrame::RefreshGridInfo(pPVar11);
        uStack_28 = 1;
        std::vector<std::string,std::allocator<std::string>>::~vector(avStack_e4);
        return uStack_28;
      }
      if (*(int *)(this + 0x294) != 2) {
        return 0;
      }
      puVar9 = (undefined4 *)
               std::vector<unsigned_long,std::allocator<unsigned_long>>::at
                         ((vector<unsigned_long,std::allocator<unsigned_long>> *)(this + 0x288),
                          (uint)param_3);
      ArResourceManager::SetSecondarySubtitleLanguage(*puVar9);
      std::vector<std::string,std::allocator<std::string>>::vector(avStack_d8);
                    /* try { // try from 00d00f48 to 00d00f4f has its CatchHandler @ 00d012a4 */
      PushSubtitleAudioLanguagetoVector();
                    /* try { // try from 00d00f68 to 00d00f6f has its CatchHandler @ 00d00fec */
      std::vector<std::string,std::allocator<std::string>>::operator=(avStack_d8,avStack_1a4);
                    /* try { // try from 00d00f80 to 00d00fdf has its CatchHandler @ 00d012a4 */
      std::vector<std::string,std::allocator<std::string>>::~vector
                ((vector<std::string,std::allocator<std::string>> *)avStack_1a4);
      std::vector<unsigned_long,std::allocator<unsigned_long>>::begin();
      std::vector<unsigned_long,std::allocator<unsigned_long>>::end();
      uStack_1b4 = ArResourceManager::GetPrimarySubtitleLanguage();
      std::
      find<__gnu_cxx::__normal_iterator<unsigned_long*,std::vector<unsigned_long,std::allocator<unsigned_long>>>,unsigned_long>
                (auStack_1a8,uStack_1ac,uStack_1b0,&uStack_1b4);
      std::vector<unsigned_long,std::allocator<unsigned_long>>::begin();
      uVar2 = __gnu_cxx::operator-(auStack_1a8,a_Stack_1b8);
      std::vector<unsigned_long,std::allocator<unsigned_long>>::begin();
      std::vector<unsigned_long,std::allocator<unsigned_long>>::end();
                    /* try { // try from 00d010e8 to 00d01277 has its CatchHandler @ 00d012a4 */
      uStack_1c8 = ArResourceManager::GetSecondarySubtitleLanguage();
      std::
      find<__gnu_cxx::__normal_iterator<unsigned_long*,std::vector<unsigned_long,std::allocator<unsigned_long>>>,unsigned_long>
                (auStack_1bc,uStack_1c0,uStack_1c4,&uStack_1c8);
      std::vector<unsigned_long,std::allocator<unsigned_long>>::begin();
      uVar10 = __gnu_cxx::operator-(auStack_1bc,a_Stack_1cc);
      uStack_60 = GetRcEngine::RcGetString(0xec1);
      std::vector<std::string,std::allocator<std::string>>::operator[](avStack_d8,uVar2);
      uStack_64 = std::string::c_str();
      uStack_68 = GetRcEngine::RcGetString(0xf20);
      std::vector<std::string,std::allocator<std::string>>::operator[](avStack_d8,uVar10);
      uVar5 = std::string::c_str();
      sprintf(acStack_cc,"%s %s, %s %s",uStack_60,uStack_64,uStack_68,uVar5);
      std::string::operator=((string *)(PopUpManager::gridSelectData + 0xc),acStack_cc);
      pPVar11 = (PopUpManagerFrame *)PopUpManagerFrame::GetInstance();
      PopUpManagerFrame::RefreshGridInfo(pPVar11);
      uStack_28 = 1;
      std::vector<std::string,std::allocator<std::string>>::~vector(avStack_d8);
      return uStack_28;
    }
    if ((void *)0xf043 < param_2) {
      if (param_2 == (void *)0xf062) {
        if (*(int *)(this + 0x294) == 0) {
          uVar3 = MenuBackgroundFrame::getMenuBackgroundFrame();
          MenuBackgroundFrame::openMenu(uVar3,'\0',(void *)0x0);
          return 1;
        }
        PopUpManager::ClosePopUp();
        *(undefined4 *)(this + 0x294) = 0;
        return 1;
      }
      if (param_2 != (void *)0xf075) {
        return 0;
      }
      if (*(int *)(this + 0x294) == 0) {
        if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
          uVar3 = MenuBackgroundFrame::getMenuBackgroundFrame();
          MenuBackgroundFrame::openMenu(uVar3,'\x01',(void *)0x0);
        }
        else {
          pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
          iVar1 = MenuBackgroundFrame::getBackgroundMode(pMVar7);
          if (iVar1 == 2) {
            iVar1 = MWidget::QueryFlag((uchar)*(undefined4 *)(this + 0x194));
            if (iVar1 == 0) {
              iVar1 = MWidget::QueryFlag((uchar)*(undefined4 *)(this + 0x198));
              if (iVar1 == 0) {
                iVar1 = MWidget::QueryFlag((uchar)*(undefined4 *)(this + 0x19c));
                if (iVar1 == 0) {
                  iVar1 = MWidget::QueryFlag((uchar)*(undefined4 *)(this + 0x1a0));
                  if (iVar1 == 0) {
                    HideAllShowSubmenu(this,3,*(MWidget **)(this + 0x1a8));
                  }
                  else {
                    HideAllShowSubmenu(this,3,*(MWidget **)(this + 0x1b8));
                  }
                }
                else {
                  HideAllShowSubmenu(this,3,*(MWidget **)(this + 0x1b4));
                }
              }
              else {
                HideAllShowSubmenu(this,3,*(MWidget **)(this + 0x1b0));
              }
            }
            else {
              HideAllShowSubmenu(this,3,*(MWidget **)(this + 0x1ac));
            }
            pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
            MenuBackgroundFrame::hideBarSubmenuTitle(pMVar7);
          }
          else {
            MWidget::SetFlag(*(undefined4 *)(this + 0x18c),2,1);
            MWidget::SetFlag(*(undefined4 *)(this + 400),2,0);
            MWidget::SetFlag(*(undefined4 *)(this + 0x194),2,0);
            MWidget::SetFlag(*(undefined4 *)(this + 0x198),2,0);
            MWidget::SetFlag(*(undefined4 *)(this + 0x19c),2,0);
            MWidget::SetFlag(*(undefined4 *)(this + 0x1a0),2,0);
            MMainFrame::SwitchFocusTo((MWidget *)this);
            pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
            MenuBackgroundFrame::focusToBar(pMVar7,'\x01');
            MWidget::Hide();
            MEvtHandle::PostEvent((MEvtHandle *)this,(ulong)this,0xc0000020,0);
            pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
            MenuBackgroundFrame::hideBarSubmenuTitle(pMVar7);
          }
        }
      }
      else {
        PopUpManager::ClosePopUp();
        *(undefined4 *)(this + 0x294) = 0;
      }
      return 1;
    }
    if (param_2 == (void *)0xf012) {
      if (PopUpManager::popupType == 0) {
        return 0;
      }
      return 1;
    }
    if (param_2 != (void *)0xf042) {
      return 0;
    }
    if (*(int *)(this + 0x294) == 1) {
      puVar9 = (undefined4 *)
               std::vector<unsigned_long,std::allocator<unsigned_long>>::at
                         ((vector<unsigned_long,std::allocator<unsigned_long>> *)(this + 0x288),
                          (uint)param_3);
      ArResourceManager::SetPrimaryAudioLanguage(*puVar9);
      std::vector<std::string,std::allocator<std::string>>::vector(avStack_fc);
                    /* try { // try from 00d002f4 to 00d002fb has its CatchHandler @ 00d00650 */
      PushSubtitleAudioLanguagetoVector();
                    /* try { // try from 00d00314 to 00d0031b has its CatchHandler @ 00d00398 */
      std::vector<std::string,std::allocator<std::string>>::operator=(avStack_fc,avStack_108);
                    /* try { // try from 00d0032c to 00d0038b has its CatchHandler @ 00d00650 */
      std::vector<std::string,std::allocator<std::string>>::~vector
                ((vector<std::string,std::allocator<std::string>> *)avStack_108);
      std::vector<unsigned_long,std::allocator<unsigned_long>>::begin();
      std::vector<unsigned_long,std::allocator<unsigned_long>>::end();
      uStack_118 = ArResourceManager::GetPrimaryAudioLanguage();
      std::
      find<__gnu_cxx::__normal_iterator<unsigned_long*,std::vector<unsigned_long,std::allocator<unsigned_long>>>,unsigned_long>
                (auStack_10c,uStack_110,uStack_114,&uStack_118);
      std::vector<unsigned_long,std::allocator<unsigned_long>>::begin();
      uVar2 = __gnu_cxx::operator-(auStack_10c,a_Stack_11c);
      std::vector<unsigned_long,std::allocator<unsigned_long>>::begin();
      std::vector<unsigned_long,std::allocator<unsigned_long>>::end();
                    /* try { // try from 00d00494 to 00d00623 has its CatchHandler @ 00d00650 */
      uStack_12c = ArResourceManager::GetSecondaryAudioLanguage();
      std::
      find<__gnu_cxx::__normal_iterator<unsigned_long*,std::vector<unsigned_long,std::allocator<unsigned_long>>>,unsigned_long>
                (auStack_120,uStack_124,uStack_128,&uStack_12c);
      std::vector<unsigned_long,std::allocator<unsigned_long>>::begin();
      uVar10 = __gnu_cxx::operator-(auStack_120,a_Stack_130);
      uStack_3c = GetRcEngine::RcGetString(0xec1);
      std::vector<std::string,std::allocator<std::string>>::operator[](avStack_fc,uVar2);
      uStack_40 = std::string::c_str();
      uStack_44 = GetRcEngine::RcGetString(0xf20);
      std::vector<std::string,std::allocator<std::string>>::operator[](avStack_fc,uVar10);
      uVar5 = std::string::c_str();
      sprintf(acStack_cc,"%s %s, %s %s",uStack_3c,uStack_40,uStack_44,uVar5);
      std::string::operator=((string *)(PopUpManager::gridSelectData + 0xc),acStack_cc);
      pPVar11 = (PopUpManagerFrame *)PopUpManagerFrame::GetInstance();
      PopUpManagerFrame::RefreshGridInfo(pPVar11);
      uStack_28 = 1;
      std::vector<std::string,std::allocator<std::string>>::~vector(avStack_fc);
      return uStack_28;
    }
    if (*(int *)(this + 0x294) != 2) {
      return 0;
    }
    puVar9 = (undefined4 *)
             std::vector<unsigned_long,std::allocator<unsigned_long>>::at
                       ((vector<unsigned_long,std::allocator<unsigned_long>> *)(this + 0x288),
                        (uint)param_3);
    ArResourceManager::SetPrimarySubtitleLanguage(*puVar9);
    std::vector<std::string,std::allocator<std::string>>::vector(avStack_f0);
                    /* try { // try from 00d00710 to 00d00717 has its CatchHandler @ 00d00a6c */
    PushSubtitleAudioLanguagetoVector();
                    /* try { // try from 00d00730 to 00d00737 has its CatchHandler @ 00d007b4 */
    std::vector<std::string,std::allocator<std::string>>::operator=(avStack_f0,avStack_13c);
                    /* try { // try from 00d00748 to 00d007a7 has its CatchHandler @ 00d00a6c */
    std::vector<std::string,std::allocator<std::string>>::~vector
              ((vector<std::string,std::allocator<std::string>> *)avStack_13c);
    std::vector<unsigned_long,std::allocator<unsigned_long>>::begin();
    std::vector<unsigned_long,std::allocator<unsigned_long>>::end();
    uStack_14c = ArResourceManager::GetPrimarySubtitleLanguage();
    std::
    find<__gnu_cxx::__normal_iterator<unsigned_long*,std::vector<unsigned_long,std::allocator<unsigned_long>>>,unsigned_long>
              (auStack_140,uStack_144,uStack_148,&uStack_14c);
    std::vector<unsigned_long,std::allocator<unsigned_long>>::begin();
    uVar2 = __gnu_cxx::operator-(auStack_140,a_Stack_150);
    std::vector<unsigned_long,std::allocator<unsigned_long>>::begin();
    std::vector<unsigned_long,std::allocator<unsigned_long>>::end();
                    /* try { // try from 00d008b0 to 00d00a3f has its CatchHandler @ 00d00a6c */
    uStack_160 = ArResourceManager::GetSecondarySubtitleLanguage();
    std::
    find<__gnu_cxx::__normal_iterator<unsigned_long*,std::vector<unsigned_long,std::allocator<unsigned_long>>>,unsigned_long>
              (auStack_154,uStack_158,uStack_15c,&uStack_160);
    std::vector<unsigned_long,std::allocator<unsigned_long>>::begin();
    uVar10 = __gnu_cxx::operator-(auStack_154,a_Stack_164);
    uStack_48 = GetRcEngine::RcGetString(0xec1);
    std::vector<std::string,std::allocator<std::string>>::operator[](avStack_f0,uVar2);
    uStack_4c = std::string::c_str();
    uStack_50 = GetRcEngine::RcGetString(0xf20);
    std::vector<std::string,std::allocator<std::string>>::operator[](avStack_f0,uVar10);
    uVar5 = std::string::c_str();
    sprintf(acStack_cc,"%s %s, %s %s",uStack_48,uStack_4c,uStack_50,uVar5);
    std::string::operator=((string *)(PopUpManager::gridSelectData + 0xc),acStack_cc);
    pPVar11 = (PopUpManagerFrame *)PopUpManagerFrame::GetInstance();
    PopUpManagerFrame::RefreshGridInfo(pPVar11);
    uStack_28 = 1;
    std::vector<std::string,std::allocator<std::string>>::~vector(avStack_f0);
    return uStack_28;
  }
  if (param_2 < (void *)0xf002) {
    if ((void *)0xefff < param_2) {
      if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
        pvVar4 = (void *)MenuBackgroundFrame::getMenuBackgroundFrame();
        uVar5 = MenuBackgroundFrame::OnKey(pvVar4,param_1,param_2);
        return uVar5;
      }
      if (*(int *)(this + 0x3c) != *(int *)(this + 0x1fc)) {
        return 0;
      }
      return 1;
    }
    if (param_2 != (void *)0xd) {
      return 0;
    }
    iVar1 = Container::GetFocusedWdgIdx();
    iVar6 = ScrollListContainer::GetChildIdx(*(MWidget **)(this + 0x18c));
    if (iVar1 == iVar6) {
      HideAllShowSubmenu(this,4,*(MWidget **)(this + 0x1d0));
      pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
      pcVar8 = (char *)GetRcEngine::RcGetString(0x1147);
      MenuBackgroundFrame::showBarSubmenuTitle(pMVar7,pcVar8);
      return 1;
    }
    iVar1 = Container::GetFocusedWdgIdx();
    iVar6 = ScrollListContainer::GetChildIdx(*(MWidget **)(this + 0x18c));
    if (iVar1 == iVar6) {
      HideAllShowSubmenu(this,5,*(MWidget **)(this + 0x1e4));
      pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
      pcVar8 = (char *)GetRcEngine::RcGetString(0xbf2);
      MenuBackgroundFrame::showBarSubmenuTitle(pMVar7,pcVar8);
      return 1;
    }
    iVar1 = Container::GetFocusedWdgIdx();
    iVar6 = ScrollListContainer::GetChildIdx(*(MWidget **)(this + 0x18c));
    if (iVar1 != iVar6) {
      iVar1 = Container::GetFocusedWdgIdx();
      iVar6 = ScrollListContainer::GetChildIdx(*(MWidget **)(this + 0x18c));
      if (iVar1 == iVar6) {
        HideAllShowSubmenu(this,7,*(MWidget **)(this + 0x240));
        pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
        pcVar8 = (char *)GetRcEngine::RcGetString(0x80);
        MenuBackgroundFrame::showBarSubmenuTitle(pMVar7,pcVar8);
        return 1;
      }
      iVar1 = Container::GetFocusedWdgIdx();
      iVar6 = ScrollListContainer::GetChildIdx(*(MWidget **)(this + 0x18c));
      if (iVar1 != iVar6) {
        return 0;
      }
      HideAllShowSubmenu(this,8,*(MWidget **)(this + 0x264));
      pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
      pcVar8 = (char *)GetRcEngine::RcGetString(0x106e);
      MenuBackgroundFrame::showBarSubmenuTitle(pMVar7,pcVar8);
      return 1;
    }
    for (uStack_1e0 = 0;
        uVar2 = (**(code **)(**(int **)(this + 0x198) + 0x44))(*(undefined4 *)(this + 0x198)),
        uStack_1e0 < uVar2; uStack_1e0 = uStack_1e0 + 1) {
      pMStack_1dc = (MWidget *)
                    (**(code **)(**(int **)(this + 0x198) + 0x40))
                              (*(undefined4 *)(this + 0x198),uStack_1e0);
      iVar1 = MWidget::QueryFlag((uchar)pMStack_1dc);
      if ((iVar1 == 0) || (pMStack_1dc[0x38] != (MWidget)0x1)) {
        iStack_38 = 0;
      }
      else {
        iStack_38 = 1;
      }
      if (iStack_38 != 0) break;
    }
    HideAllShowSubmenu(this,6,pMStack_1dc);
    pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
    pcVar8 = (char *)GetRcEngine::RcGetString(0x1071);
    MenuBackgroundFrame::showBarSubmenuTitle(pMVar7,pcVar8);
    return 1;
  }
  if (*(int *)(this + 0x3c) == *(int *)(this + 0x180)) {
    return 1;
  }
  if (*(int *)(this + 0x3c) == *(int *)(this + 0x1a8)) {
    MMainFrame::SwitchFocusTo((MWidget *)this);
    pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
    MenuBackgroundFrame::focusToBar(pMVar7,'\x01');
    return 1;
  }
  ArServiceSettingsManager::getInstance();
  iVar1 = ArServiceSettingsManager::ArTvConf_GetBasicMode();
  if (iVar1 == 1) {
    ArTvSettingsManager::getInstance();
    iVar1 = ArTvSettingsManager::GetBasicMode();
    if ((iVar1 == 1) && (*(int *)(this + 0x3c) == *(int *)(this + 0x1ac))) {
      iStack_30 = 1;
      goto LAB_00cffbfc;
    }
  }
  iStack_30 = 0;
LAB_00cffbfc:
  if (iStack_30 == 0) {
    return 0;
  }
  MMainFrame::SwitchFocusTo((MWidget *)this);
  pMVar7 = (MenuBackgroundFrame *)MenuBackgroundFrame::getMenuBackgroundFrame();
  MenuBackgroundFrame::focusToBar(pMVar7,'\x01');
  return 1;
}

