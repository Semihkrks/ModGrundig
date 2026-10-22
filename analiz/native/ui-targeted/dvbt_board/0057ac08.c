
/* ArUIManager::CloseWithSwipe(MWidget*, OSD_ANI_DIRECTION_TYPE, unsigned long, unsigned long) */

undefined4
ArUIManager::CloseWithSwipe(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

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
  
  if (param_2 != 0) {
    (*(code *)PTR_GetRect_010c5804)(param_1,auStack_3c);
    uStack_40 = uStack_34;
    uStack_44 = uStack_30;
    (*(code *)PTR_printf_010c9f10)(PTR_LAB_010c4334 + 0x7c48,uStack_34,uStack_30);
    uStack_20 = (*(code *)PTR_operator_new_010c9890)(0x34);
                    /* try { // try from 0057acbc to 0057acc3 has its CatchHandler @ 0057ace8 */
    (*(code *)PTR_MAnimationSet_010c4ee8)(uStack_20);
    uVar2 = uStack_20;
    if (param_2 != 1) {
      uStack_24 = (*(code *)PTR_operator_new_010c9890)(0x30);
                    /* try { // try from 0057ad48 to 0057ad4f has its CatchHandler @ 0057ad74 */
      (*(code *)PTR_MTranslateAnimation_010cb6ac)(uStack_24);
      uVar1 = uStack_24;
      if (0x6c < uStack_30) {
        uStack_44 = 0x6c;
      }
      if (0x180 < uStack_34) {
        uStack_40 = 0x180;
      }
      (*(code *)PTR_SetStartPosition_010c6af4)(uStack_24,0,0);
      if (param_2 == 2) {
        (*(code *)PTR_SetEndPosition_010c923c)(uVar1,0,uStack_44);
      }
      else if (param_2 == 3) {
        (*(code *)PTR_SetEndPosition_010c923c)(uVar1,0,-uStack_44);
      }
      else if (param_2 == 5) {
        (*(code *)PTR_SetEndPosition_010c923c)(uVar1,uStack_40,0);
      }
      else if (param_2 == 4) {
        (*(code *)PTR_SetEndPosition_010c923c)(uVar1,-uStack_40,0);
      }
      (*(code *)PTR_SetDuration_010c49e8)(uVar1,param_3);
      (*(code *)PTR_addAnimation_010cbc60)(uVar2,uVar1);
    }
    uStack_28 = (*(code *)PTR_operator_new_010c9890)(0x28);
                    /* try { // try from 0057af28 to 0057af2f has its CatchHandler @ 0057b018 */
    (*(code *)PTR_MAlphaAnimation_010c880c)(uStack_28);
    uVar1 = uStack_28;
    (*(code *)PTR_SetStartAlpha_010ca18c)(uStack_28,0xff);
    (*(code *)PTR_SetEndAlpha_010c8d3c)(uVar1,0);
    (*(code *)PTR_SetDuration_010c49e8)(uVar1,param_3);
    (*(code *)PTR_addAnimation_010cbc60)(uVar2,uVar1);
    (*(code *)PTR_SetStartTime_010c85a0)(uVar2,param_4);
    (*(code *)PTR_SetDuration_010c49e8)(uVar2,param_3);
    (*(code *)PTR_SetSequence_010cac98)(uVar2,0);
    (*(code *)PTR_SetAnimation_010c9700)(param_1,uVar2);
  }
  return 1;
}

