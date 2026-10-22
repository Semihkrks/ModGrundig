
/* MResourcePkg::BuildMBAPathIndex() */

code * __thiscall MResourcePkg::BuildMBAPathIndex(MResourcePkg *this)

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
  int iStack_6c;
  
  iVar1 = (**(code **)(in_t9 + 0x740e0))
                    (*(int *)(this + 0x1c) << 2,*(undefined4 *)(in_t9 + 0x7468c));
  *(int *)(this + 0x7c) = iVar1;
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e24064c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar2 = (code *)(**(code **)(in_t9 + 0x7363c))
                               (this,iVar1,*(undefined4 *)(this + 0x1c),*(undefined4 *)(this + 0x4c)
                               );
    return pcVar2;
  }
  (**(code **)(in_t9 + 0x73850))(*(int *)(in_t9 + 0x73318) + -0x51e4);
  iVar5 = *(int *)(in_t9 + 0x73318) + -0x73a0;
  (**(code **)(in_t9 + 0x738f0))
            (iVar5,*(int *)(in_t9 + 0x73318) + -0x51fc,*(int *)(in_t9 + 0x73318) + -0x4e30,1099);
  pcVar2 = *(code **)(in_t9 + 0x735d8);
  (*pcVar2)();
  iVar1 = (**(code **)(pcVar2 + 0x74034))
                    (*(int *)(iVar5 + 0x14) << 2,*(undefined4 *)(pcVar2 + 0x745e0));
  *(int *)(iVar5 + 0x78) = iVar1;
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e2406f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar2 = (code *)(**(code **)(pcVar2 + 0x73590))
                               (iVar5,iVar1,*(undefined4 *)(iVar5 + 0x14),
                                *(undefined4 *)(iVar5 + 0x44));
    return pcVar2;
  }
  (**(code **)(pcVar2 + 0x737a4))(*(int *)(pcVar2 + 0x7326c) + -0x51e4);
  iVar5 = *(int *)(pcVar2 + 0x7326c) + -0x73a0;
  (**(code **)(pcVar2 + 0x73844))
            (iVar5,*(int *)(pcVar2 + 0x7326c) + -0x51fc,*(int *)(pcVar2 + 0x7326c) + -0x4e08,0x43c);
  pcVar2 = *(code **)(pcVar2 + 0x7352c);
  (*pcVar2)();
  iVar1 = (**(code **)(pcVar2 + 0x73f88))
                    (*(int *)(iVar5 + 0x10) << 2,*(undefined4 *)(pcVar2 + 0x74534));
  *(int *)(iVar5 + 0x74) = iVar1;
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e2407a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar2 = (code *)(**(code **)(pcVar2 + 0x734e4))
                               (iVar5,iVar1,*(undefined4 *)(iVar5 + 0x10),
                                *(undefined4 *)(iVar5 + 0x40));
    return pcVar2;
  }
  (**(code **)(pcVar2 + 0x736f8))(*(int *)(pcVar2 + 0x731c0) + -0x51c4);
  iVar5 = *(int *)(pcVar2 + 0x731c0) + -0x73a0;
  (**(code **)(pcVar2 + 0x73798))
            (iVar5,*(int *)(pcVar2 + 0x731c0) + -0x51fc,*(int *)(pcVar2 + 0x731c0) + -0x4de0,0x42d);
  pcVar2 = *(code **)(pcVar2 + 0x73480);
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
    pcVar4 = *(code **)(iStack_6c + uVar6 * 4);
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

