
/* ArUIManager::ShowWithSwipe(MWidget*, OSD_ANI_DIRECTION_TYPE, unsigned long, unsigned long) */

undefined4
ArUIManager::ShowWithSwipe(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uStack_44;
  uint uStack_40;
  undefined1 auStack_3c [8];
  uint uStack_34;
  uint uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  if (param_2 == 0) {
    (*(code *)PTR_Show_010cc98c)(param_1);
  }
  else {
    (*(code *)PTR_GetRect_010c5804)(param_1,auStack_3c);
    uStack_40 = uStack_34;
    uStack_44 = uStack_30;
    (*(code *)PTR_Hide_010c5068)(param_1);
    uStack_20 = (*(code *)PTR_operator_new_010c9890)(0x34);
                    /* try { // try from 0057b124 to 0057b12b has its CatchHandler @ 0057b150 */
    (*(code *)PTR_MAnimationSet_010c4ee8)(uStack_20);
    uVar2 = uStack_20;
    if (param_2 != 1) {
      uStack_24 = (*(code *)PTR_operator_new_010c9890)(0x30);
                    /* try { // try from 0057b1b0 to 0057b1b7 has its CatchHandler @ 0057b1dc */
      (*(code *)PTR_MTranslateAnimation_010cb6ac)(uStack_24);
      uVar1 = uStack_24;
      if (0x6c < uStack_30) {
        uStack_44 = 0x6c;
      }
      if (0x180 < uStack_34) {
        uStack_40 = 0x180;
      }
      if (param_2 == 2) {
        (*(code *)PTR_SetStartPosition_010c6af4)(uStack_24,0,-uStack_44);
      }
      else if (param_2 == 3) {
        (*(code *)PTR_SetStartPosition_010c6af4)(uStack_24,0,uStack_44);
      }
      else if (param_2 == 5) {
        (*(code *)PTR_SetStartPosition_010c6af4)(uStack_24,-uStack_40,0);
      }
      else if (param_2 == 4) {
        (*(code *)PTR_SetStartPosition_010c6af4)(uStack_24,uStack_40,0);
      }
      else {
        (*(code *)PTR_SetStartPosition_010c6af4)(uStack_24,0,0);
      }
      (*(code *)PTR_SetEndPosition_010c923c)(uVar1,0,0);
      (*(code *)PTR_SetDuration_010c49e8)(uVar1,param_3);
      (*(code *)PTR_addAnimation_010cbc60)(uVar2,uVar1);
    }
    uStack_28 = (*(code *)PTR_operator_new_010c9890)(0x28);
                    /* try { // try from 0057b3b4 to 0057b3bb has its CatchHandler @ 0057b4a4 */
    (*(code *)PTR_MAlphaAnimation_010c880c)(uStack_28);
    uVar1 = uStack_28;
    (*(code *)PTR_SetStartAlpha_010ca18c)(uStack_28,0);
    (*(code *)PTR_SetEndAlpha_010c8d3c)(uVar1,0xff);
    (*(code *)PTR_SetDuration_010c49e8)(uVar1,param_3);
    (*(code *)PTR_addAnimation_010cbc60)(uVar2,uVar1);
    (*(code *)PTR_SetStartTime_010c85a0)(uVar2,param_4);
    (*(code *)PTR_SetDuration_010c49e8)(uVar2,param_3);
    (*(code *)PTR_SetSequence_010cac98)(uVar2,0);
    (*(code *)PTR_SetAnimation_010c9700)(param_1,uVar2);
  }
  return 1;
}

