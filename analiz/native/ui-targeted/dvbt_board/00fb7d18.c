
/* VolumeControlFrame::RefreshVolumeUI() */

void __thiscall VolumeControlFrame::RefreshVolumeUI(VolumeControlFrame *this)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uStack_94;
  undefined1 auStack_90 [4];
  undefined1 auStack_8c [4];
  undefined1 auStack_88 [8];
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  
  iVar3 = (*(code *)PTR_GetMuteControlFrame_010c4ce4)();
  if (iVar3 != 0) {
    uVar4 = (*(code *)PTR_GetMuteControlFrame_010c4ce4)();
    uVar4 = (*(code *)PTR_GetParentApp_010c98f8)(uVar4);
    (*(code *)PTR_Kill_010c4dec)(uVar4);
  }
  (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x180));
  (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x184));
  (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x188));
  uVar4 = (*(code *)PTR_getInstance_010c909c)();
  uStack_94 = (*(code *)PTR_GetMainVolume_010cd110)(uVar4);
  uVar4 = (*(code *)PTR_getInstance_010c909c)();
  cVar1 = (*(code *)PTR_IsMuted_010ca504)(uVar4);
  uVar4 = (*(code *)PTR_getInstance_010c538c)();
  cVar2 = (*(code *)PTR_IsARCMuteOn_010c966c)(uVar4);
  if (*(int *)(this + 0x214) == 0) {
    (*(code *)PTR_KillTimer_010c786c)(this,0);
    (*(code *)PTR_SetTimer_010cb058)(this,3000,0,1);
    (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(this + 0x184));
    (*(code *)PTR_sprintf_010c97b4)(auStack_88,PTR_DAT_010c4460 + -0x348c,uStack_94);
    iStack_24 = *(int *)(this + 0x1ac) + 0x170;
    (*(code *)PTR_allocator_010c6920)(auStack_90);
                    /* try { // try from 00fb7f44 to 00fb7f4b has its CatchHandler @ 00fb800c */
    (*(code *)PTR_string_010c4f9c)(auStack_8c,auStack_88,auStack_90);
                    /* try { // try from 00fb7f60 to 00fb7f67 has its CatchHandler @ 00fb7fd0 */
    (*(code *)PTR_Set_010cb39c)(iStack_24,auStack_8c);
                    /* try { // try from 00fb7f78 to 00fb7f7f has its CatchHandler @ 00fb800c */
    (*(code *)PTR__string_010c5070)(auStack_8c);
    (*(code *)PTR__allocator_010c4948)(auStack_90);
    (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)(this + 0x1ac));
    if (*(int *)(this + 0x1bc) != 0) {
      if (uStack_94 == 0) {
        (*(code *)PTR_SetCurValue_010caa64)(*(undefined4 *)(this + 0x1bc),0);
      }
      else {
        if (100 < uStack_94) {
          uStack_94 = 100;
        }
        (*(code *)PTR_SetCurValue_010caa64)(*(undefined4 *)(this + 0x1bc),uStack_94);
      }
      (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)(this + 0x1bc));
    }
    iVar3 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6a);
    iVar5 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6d);
    iVar6 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6a);
    uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a70);
    uVar7 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6f);
    uVar8 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a6e);
    (*(code *)PTR_set_010c9810)
              (&uStack_80,uVar4,((iVar3 + iVar5) - (iVar6 * uStack_94) / 100) + -10,uVar7,uVar8);
    (**(code **)(**(int **)(this + 0x1b4) + 0x24))
              (*(undefined4 *)(this + 0x1b4),uStack_80,uStack_7c,&uStack_80);
    if (cVar1 == '\0') {
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1a8) + 0xb8,0x2aa);
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1a8) + 0xcc,0x2aa);
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1a8) + 0xe0,0x2aa);
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1a8) + 0xf4,0x2aa);
    }
    else {
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1a8) + 0xb8,0x2a8);
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1a8) + 0xcc,0x2a8);
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1a8) + 0xe0,0x2a8);
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1a8) + 0xf4,0x2a8);
    }
    (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)(this + 0x1a8));
  }
  else if (*(int *)(this + 0x214) == 1) {
    if (cVar1 == '\0') {
      (*(code *)PTR_KillTimer_010c786c)(this,0);
      (*(code *)PTR_SetTimer_010cb058)(this,3000,0,1);
    }
    else {
      (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(this + 0x180));
    }
  }
  else if (*(int *)(this + 0x214) == 3) {
    if (cVar2 == '\0') {
      uVar4 = (*(code *)PTR_GetMSrvSSSound_010cb3d8)();
      (*(code *)PTR_SetMuteStatus_010c94cc)(uVar4,4,0,0);
      (*(code *)PTR_KillTimer_010c786c)(this,0);
      (*(code *)PTR_TimerEventHandler_010cc1dc)(this,0,0,0);
    }
    else {
      uVar4 = (*(code *)PTR_GetMSrvSSSound_010cb3d8)();
      (*(code *)PTR_SetMuteStatus_010c94cc)(uVar4,4,1,0);
      (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(this + 0x188));
      (*(code *)PTR_GetRect_010c5804)(*(undefined4 *)(this + 0x188),&uStack_70);
      uStack_68 = 0x9e;
      uStack_64 = 0x5a;
      (**(code **)(**(int **)(this + 0x188) + 0x24))
                (*(undefined4 *)(this + 0x188),uStack_70,uStack_6c,&uStack_70);
      (*(code *)PTR_GetRect_010c5804)(*(undefined4 *)(this + 0x1b8),&uStack_60);
      uStack_58 = 0x9e;
      uStack_54 = 0x59;
      (**(code **)(**(int **)(this + 0x1b8) + 0x24))
                (*(undefined4 *)(this + 0x1b8),uStack_60,uStack_5c,&uStack_60);
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1b8) + 0x260,5);
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1b8) + 0x274,5);
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1b8) + 0x288,5);
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1b8) + 0x29c,5);
      (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)(this + 0x1b8));
      (*(code *)PTR_KillTimer_010c786c)(this,0);
    }
  }
  else {
    (*(code *)PTR_Show_010cc98c)(*(undefined4 *)(this + 0x188));
    (*(code *)PTR_KillTimer_010c786c)(this,0);
    (*(code *)PTR_SetTimer_010cb058)(this,3000,0,1);
    uVar4 = (*(code *)PTR_GetMSrvSSSound_010cb3d8)();
    (*(code *)PTR_SetMuteStatus_010c94cc)(uVar4,4,0,0);
    uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a48);
    uVar7 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a49);
    uVar8 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a47);
    uVar9 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a46);
    (*(code *)PTR_set_010c9810)(&uStack_50,uVar4,uVar7,uVar8,uVar9);
    (**(code **)(**(int **)(this + 0x188) + 0x24))
              (*(undefined4 *)(this + 0x188),uStack_50,uStack_4c,&uStack_50);
    uVar4 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a74);
    uVar7 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a75);
    uVar8 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a73);
    uVar9 = (*(code *)PTR_RcGetNum_010c8a6c)(0x5a72);
    (*(code *)PTR_set_010c9810)(&uStack_40,uVar4,uVar7,uVar8,uVar9);
    (**(code **)(**(int **)(this + 0x1b8) + 0x24))
              (*(undefined4 *)(this + 0x1b8),uStack_40,uStack_3c,&uStack_40);
    iStack_28 = *(int *)PTR_volumeKeyVal_010c4b08;
    if (iStack_28 == 0xf04c) {
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1b8) + 0x260,6);
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1b8) + 0x274,6);
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1b8) + 0x288,6);
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1b8) + 0x29c,6);
    }
    else if (iStack_28 == 0xf04d) {
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1b8) + 0x260,4);
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1b8) + 0x274,4);
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1b8) + 0x288,4);
      (*(code *)PTR_Set_010cba00)(*(int *)(this + 0x1b8) + 0x29c,4);
    }
    (*(code *)PTR_Invalidate_010c4e28)(*(undefined4 *)(this + 0x1b8));
    uVar4 = (*(code *)PTR_getInstance_010c538c)();
    iVar3 = (*(code *)PTR_IsARCActive_010c858c)(uVar4);
    if (((iVar3 == 0) || (iVar3 = (*(code *)PTR_IsCECInitCompleted_010cb89c)(uVar4), iVar3 == 0)) ||
       (iVar3 = (*(code *)PTR_GetHDMIDevPlugged_010c855c)(uVar4), iVar3 == 0)) {
      iStack_2c = 0;
    }
    else {
      iStack_2c = 1;
    }
    if (((iStack_2c != 0) && (uStack_30 = *(uint *)PTR_volumeKeyVal_010c4b08, 0xefff < uStack_30))
       && ((uStack_30 < 0xf002 || (uStack_30 - 0xf551 < 4)))) {
      (*(code *)PTR_Hide_010c5068)(*(undefined4 *)(this + 0x188));
    }
  }
  return;
}

