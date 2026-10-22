
/* MResourcePkg::BuildFontPathIndex() */

code * __thiscall MResourcePkg::BuildFontPathIndex(MResourcePkg *this)

{
  int iVar1;
  code *pcVar2;
  code *pcVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int in_t9;
  code *pcVar8;
  int iStack_2c;
  
  iVar1 = (**(code **)(in_t9 + 0x73f88))
                    (*(int *)(this + 0x10) << 2,*(undefined4 *)(in_t9 + 0x74534));
  *(int *)(this + 0x74) = iVar1;
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e2407a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar2 = (code *)(**(code **)(in_t9 + 0x734e4))
                               (this,iVar1,*(undefined4 *)(this + 0x10),*(undefined4 *)(this + 0x40)
                               );
    return pcVar2;
  }
  (**(code **)(in_t9 + 0x736f8))(*(int *)(in_t9 + 0x731c0) + -0x51c4);
  iVar5 = *(int *)(in_t9 + 0x731c0) + -0x73a0;
  (**(code **)(in_t9 + 0x73798))
            (iVar5,*(int *)(in_t9 + 0x731c0) + -0x51fc,*(int *)(in_t9 + 0x731c0) + -0x4de0,0x42d);
  pcVar2 = *(code **)(in_t9 + 0x73480);
  (*pcVar2)();
  iVar1 = (**(code **)(pcVar2 + 0x73edc))
                    (*(int *)(iVar5 + 0xc) << 2,*(undefined4 *)(pcVar2 + 0x74488));
  *(int *)(iVar5 + 0x70) = iVar1;
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e240850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar2 = (code *)(**(code **)(pcVar2 + 0x73438))
                               (iVar5,iVar1,*(undefined4 *)(iVar5 + 0xc),
                                *(undefined4 *)(iVar5 + 0x3c));
    return pcVar2;
  }
  (**(code **)(pcVar2 + 0x7364c))(*(int *)(pcVar2 + 0x73114) + -0x51a4);
  uVar7 = 0x41e;
  uVar6 = *(int *)(pcVar2 + 0x73114) - 0x51fc;
  iVar1 = *(int *)(pcVar2 + 0x73114) + -0x4db8;
  (**(code **)(pcVar2 + 0x736ec))(*(int *)(pcVar2 + 0x73114) + -0x73a0);
  pcVar8 = *(code **)(pcVar2 + 0x733d4);
  (*pcVar8)();
  if ((iVar1 == 0) || (uVar7 <= uVar6)) {
    pcVar3 = (code *)0x0;
  }
  else {
    pcVar4 = *(code **)(iStack_2c + uVar6 * 4);
    pcVar3 = pcVar4 + iVar1;
    if (pcVar2 + 0x7b0ec <= pcVar4) {
      (**(code **)(pcVar8 + 0x73640))
                (*(int *)(pcVar8 + 0x73068) + -0x73a0,*(int *)(pcVar8 + 0x73068) + -0x51fc,
                 *(int *)(pcVar8 + 0x73068) + -0x4c84,0x261);
      pcVar2 = *(code **)(pcVar8 + 0x73328);
      (*pcVar2)();
      pcVar2 = (code *)(**(code **)(pcVar2 + 0x73f84))();
      return pcVar2;
    }
  }
  return pcVar3;
}

