
/* VolumeControlFrame::OnKey(void*, void*, void*) */

undefined4 __thiscall
VolumeControlFrame::OnKey(VolumeControlFrame *this,void *param_1,void *param_2,void *param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [8];
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  void *pvStack_18;
  
  *(int *)PTR_keyCount_010ca234 = *(int *)PTR_keyCount_010ca234 + 1;
  if ((*PTR_isAnimationDone_010c6bc8 == '\0') && (2 < *(int *)PTR_keyCount_010ca234)) {
    return 1;
  }
  *(void **)PTR_volumeKeyVal_010c4b08 = param_2;
  uVar2 = (*(code *)PTR_getInstance_010c909c)();
  uVar2 = (*(code *)PTR_GetMainVolume_010cd110)(uVar2);
  (*(code *)PTR_sprintf_010c97b4)(auStack_38,PTR_DAT_010c4460 + -0x348c,uVar2);
  iStack_28 = *(int *)(this + 0x1ac) + 0x170;
  (*(code *)PTR_allocator_010c6920)(auStack_40);
                    /* try { // try from 00fb8da0 to 00fb8da7 has its CatchHandler @ 00fb8f58 */
  (*(code *)PTR_string_010c4f9c)(auStack_3c,auStack_38,auStack_40);
                    /* try { // try from 00fb8dbc to 00fb8dc3 has its CatchHandler @ 00fb8e38 */
  (*(code *)PTR_Set_010cb39c)(iStack_28,auStack_3c);
                    /* try { // try from 00fb8dd4 to 00fb8ddb has its CatchHandler @ 00fb8f58 */
  (*(code *)PTR__string_010c5070)(auStack_3c);
  (*(code *)PTR__allocator_010c4948)(auStack_40);
  (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)(this + 0x1ac));
  pvStack_18 = param_2;
  if (param_2 < (void *)0xf04e) {
    if ((void *)0xf04b < param_2) {
LAB_00fb8fcc:
      uVar1 = *PTR_n_stepValue_010cd038;
      *(undefined4 *)(this + 0x214) = 0;
      if ((int)param_3 < 0) {
        uVar3 = (*(code *)PTR_GetTimeDiffFromNow_010c75f8)(*(undefined4 *)(this + 0x1c0));
        if (1000 < uVar3) {
          uVar1 = 4;
        }
      }
      else {
        uVar2 = (*(code *)PTR_GetSystemTime_010c8a5c)();
        *(undefined4 *)(this + 0x1c0) = uVar2;
      }
      uVar2 = (*(code *)PTR_getInstance_010c538c)();
      iVar4 = (*(code *)PTR_IsARCActive_010c858c)(uVar2);
      if (((iVar4 == 0) || (iVar4 = (*(code *)PTR_IsCECInitCompleted_010cb89c)(uVar2), iVar4 == 0))
         || (iVar4 = (*(code *)PTR_GetHDMIDevPlugged_010c855c)(uVar2), iVar4 == 0)) {
        iStack_2c = 0;
      }
      else {
        iStack_2c = 1;
      }
      if (iStack_2c != 0) {
        (*(code *)PTR_ProccessUserRCInput_010c7b50)(uVar2,param_2);
        iVar4 = (*(code *)PTR_IsRcKeyProcessedByCec_010c7038)(uVar2);
        if (iVar4 != 0) {
          iVar4 = (*(code *)PTR_GetMuteControlFrame_010c4ce4)();
          if (iVar4 != 0) {
            uVar2 = (*(code *)PTR_GetMuteControlFrame_010c4ce4)();
            uVar2 = (*(code *)PTR_GetParentApp_010c98f8)(uVar2);
            (*(code *)PTR_Kill_010c4dec)(uVar2);
          }
          *(undefined4 *)(this + 0x214) = 2;
          (*(code *)PTR_RefreshVolumeUI_010c5f88)(this);
          return 1;
        }
        *(undefined4 *)(this + 0x214) = 2;
        (*(code *)PTR_RefreshVolumeUI_010c5f88)(this);
        return 1;
      }
      if (((param_2 == (void *)0xf04c) || (param_2 == (void *)0xf551)) ||
         ((param_2 == (void *)0xf001 || (param_2 == (void *)0xf554)))) {
        uVar2 = (*(code *)PTR_getInstance_010c909c)();
        (*(code *)PTR_MainVolumeUp_010cc2ec)(uVar2,uVar1);
      }
      else {
        uVar2 = (*(code *)PTR_getInstance_010c909c)();
        (*(code *)PTR_MainVolumeDown_010cbd40)(uVar2,uVar1);
      }
      if (*PTR_n_stepValue_010cd038 != '\x01') {
        *PTR_n_stepValue_010cd038 = 1;
      }
      (*(code *)PTR_RefreshVolumeUI_010c5f88)(this);
      return 1;
    }
    if (param_2 != (void *)0xf012) {
      if (param_2 < (void *)0xf013) {
        if ((int)param_2 - 0xf000U < 2) goto LAB_00fb8fcc;
      }
      else if (param_2 == (void *)0xf014) {
        (*(code *)PTR_RefreshVolumeUI_010c5f88)(this);
        return 1;
      }
      goto LAB_00fb9454;
    }
  }
  else if (param_2 != (void *)0xf075) {
    if (param_2 < (void *)0xf076) {
      if (param_2 == (void *)0xf04e) {
        uVar2 = (*(code *)PTR_getInstance_010c538c)();
        iVar4 = (*(code *)PTR_IsARCActive_010c858c)(uVar2);
        if (((iVar4 == 0) || (iVar4 = (*(code *)PTR_IsCECInitCompleted_010cb89c)(uVar2), iVar4 == 0)
            ) || (iVar4 = (*(code *)PTR_GetHDMIDevPlugged_010c855c)(uVar2), iVar4 == 0)) {
          iStack_30 = 0;
        }
        else {
          iStack_30 = 1;
        }
        if (iStack_30 != 0) {
          (*(code *)PTR_ProccessUserRCInput_010c7b50)(uVar2,0xf04e);
          iVar4 = (*(code *)PTR_IsRcKeyProcessedByCec_010c7038)(uVar2);
          if (iVar4 != 0) {
            *(undefined4 *)(this + 0x214) = 3;
            (*(code *)PTR_RefreshVolumeUI_010c5f88)(this);
            return 1;
          }
        }
        *(undefined4 *)(this + 0x214) = 1;
        uVar2 = (*(code *)PTR_getInstance_010c909c)();
        uVar5 = (*(code *)PTR_getInstance_010c909c)();
        iVar4 = (*(code *)PTR_IsMuted_010ca504)(uVar5);
        (*(code *)PTR_SetMute_010cd064)(uVar2,iVar4 == 0);
        (*(code *)PTR_RefreshVolumeUI_010c5f88)(this);
        return 1;
      }
      if (param_2 == (void *)0xf062) goto LAB_00fb8f9c;
    }
    else if ((int)param_2 - 0xf551U < 4) goto LAB_00fb8fcc;
LAB_00fb9454:
    iVar4 = (*(code *)PTR_GetDMPMoviePlayerFrame_010c7548)();
    if (iVar4 != 0) {
      (*(code *)PTR_TimerEventHandler_010cc1dc)(this,0,0,0);
      uVar2 = (*(code *)PTR_GetDMPMoviePlayerFrame_010c7548)();
      uVar5 = (*(code *)PTR_GetDMPMoviePlayerFrame_010c7548)();
      (*(code *)PTR_PostEvent_010cabec)(uVar2,uVar5,0x14,param_2,param_3);
      return 1;
    }
    iVar4 = (*(code *)PTR_GetDMPMusicPlayerFrame_010c5558)();
    if (iVar4 != 0) {
      (*(code *)PTR_TimerEventHandler_010cc1dc)(this,0,0,0);
      uVar2 = (*(code *)PTR_GetDMPMusicPlayerFrame_010c5558)();
      uVar5 = (*(code *)PTR_GetDMPMusicPlayerFrame_010c5558)();
      (*(code *)PTR_PostEvent_010cabec)(uVar2,uVar5,0x14,param_2,param_3);
      return 1;
    }
    iVar4 = (*(code *)PTR_GetDMPPhotoPlayerFrame_010ca7e8)();
    if (iVar4 != 0) {
      (*(code *)PTR_TimerEventHandler_010cc1dc)(this,0,0,0);
      uVar2 = (*(code *)PTR_GetDMPPhotoPlayerFrame_010ca7e8)();
      uVar5 = (*(code *)PTR_GetDMPPhotoPlayerFrame_010ca7e8)();
      (*(code *)PTR_PostEvent_010cabec)(uVar2,uVar5,0x14,param_2,param_3);
      return 1;
    }
    (*(code *)PTR_GetIdleAppFrame_010ccb54)();
    iVar4 = (*(code *)PTR_IsBackgroundScreenEmpty_010cb3e8)();
    if (iVar4 != 0) {
      (*(code *)PTR_TimerEventHandler_010cc1dc)(this,0,0,0);
      uVar2 = (*(code *)PTR_GetIdleAppFrame_010ccb54)();
      uVar5 = (*(code *)PTR_GetIdleAppFrame_010ccb54)();
      (*(code *)PTR_PostEvent_010cabec)(uVar2,uVar5,0x14,param_2,param_3);
      return 1;
    }
    iVar4 = (*(code *)PTR_GetInstance_010c6a64)();
    if (iVar4 == 0) {
      return 1;
    }
    (*(code *)PTR_TimerEventHandler_010cc1dc)(this,0,0,0);
    uVar2 = (*(code *)PTR_GetInstance_010c6a64)();
    uVar5 = (*(code *)PTR_GetInstance_010c6a64)();
    (*(code *)PTR_PostEvent_010cabec)(uVar2,uVar5,0x14,param_2,param_3);
    return 1;
  }
LAB_00fb8f9c:
  (*(code *)PTR_TimerEventHandler_010cc1dc)(this,0,0,0);
  return 1;
}

