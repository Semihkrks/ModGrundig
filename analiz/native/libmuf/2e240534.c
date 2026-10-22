
/* MResourcePkg::BuildIndex(unsigned long*, unsigned long, unsigned char*) */

code * __thiscall
MResourcePkg::BuildIndex(MResourcePkg *this,ulong *param_1,ulong param_2,uchar *param_3)

{
  code *pcVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int in_t9;
  code *pcVar8;
  code *pcVar9;
  int iStack_8c;
  
  if ((param_1 != (ulong *)0x0) && (param_3 != (uchar *)0x0)) {
    if (param_2 != 0) {
      uVar2 = 0;
      iVar4 = 0;
      while( true ) {
        iVar7 = *(int *)(param_3 + uVar2);
        if (iVar7 == 0) {
          *param_1 = uVar2;
        }
        else {
          *param_1 = uVar2 + 4;
        }
        if (param_2 <= iVar4 + 1U) break;
        param_1 = param_1 + 1;
        iVar4 = iVar4 + 1;
        uVar2 = uVar2 + iVar7 + 4;
      }
    }
    return (code *)0x1;
  }
  iVar7 = *(int *)(in_t9 + 0x733d4) + -0x73a0;
  (**(code **)(in_t9 + 0x739ac))
            (iVar7,*(int *)(in_t9 + 0x733d4) + -0x51fc,*(int *)(in_t9 + 0x733d4) + -0x4d90,0x400);
  pcVar8 = *(code **)(in_t9 + 0x73694);
  (*pcVar8)();
  iVar4 = (**(code **)(pcVar8 + 0x740e0))
                    (*(int *)(iVar7 + 0x1c) << 2,*(undefined4 *)(pcVar8 + 0x7468c));
  *(int *)(iVar7 + 0x7c) = iVar4;
  if (iVar4 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e24064c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar8 = (code *)(**(code **)(pcVar8 + 0x7363c))
                               (iVar7,iVar4,*(undefined4 *)(iVar7 + 0x1c),
                                *(undefined4 *)(iVar7 + 0x4c));
    return pcVar8;
  }
  (**(code **)(pcVar8 + 0x73850))(*(int *)(pcVar8 + 0x73318) + -0x51e4);
  iVar7 = *(int *)(pcVar8 + 0x73318) + -0x73a0;
  (**(code **)(pcVar8 + 0x738f0))
            (iVar7,*(int *)(pcVar8 + 0x73318) + -0x51fc,*(int *)(pcVar8 + 0x73318) + -0x4e30,1099);
  pcVar8 = *(code **)(pcVar8 + 0x735d8);
  (*pcVar8)();
  iVar4 = (**(code **)(pcVar8 + 0x74034))
                    (*(int *)(iVar7 + 0x14) << 2,*(undefined4 *)(pcVar8 + 0x745e0));
  *(int *)(iVar7 + 0x78) = iVar4;
  if (iVar4 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e2406f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar8 = (code *)(**(code **)(pcVar8 + 0x73590))
                               (iVar7,iVar4,*(undefined4 *)(iVar7 + 0x14),
                                *(undefined4 *)(iVar7 + 0x44));
    return pcVar8;
  }
  (**(code **)(pcVar8 + 0x737a4))(*(int *)(pcVar8 + 0x7326c) + -0x51e4);
  iVar7 = *(int *)(pcVar8 + 0x7326c) + -0x73a0;
  (**(code **)(pcVar8 + 0x73844))
            (iVar7,*(int *)(pcVar8 + 0x7326c) + -0x51fc,*(int *)(pcVar8 + 0x7326c) + -0x4e08,0x43c);
  pcVar8 = *(code **)(pcVar8 + 0x7352c);
  (*pcVar8)();
  iVar4 = (**(code **)(pcVar8 + 0x73f88))
                    (*(int *)(iVar7 + 0x10) << 2,*(undefined4 *)(pcVar8 + 0x74534));
  *(int *)(iVar7 + 0x74) = iVar4;
  if (iVar4 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e2407a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar8 = (code *)(**(code **)(pcVar8 + 0x734e4))
                               (iVar7,iVar4,*(undefined4 *)(iVar7 + 0x10),
                                *(undefined4 *)(iVar7 + 0x40));
    return pcVar8;
  }
  (**(code **)(pcVar8 + 0x736f8))(*(int *)(pcVar8 + 0x731c0) + -0x51c4);
  iVar7 = *(int *)(pcVar8 + 0x731c0) + -0x73a0;
  (**(code **)(pcVar8 + 0x73798))
            (iVar7,*(int *)(pcVar8 + 0x731c0) + -0x51fc,*(int *)(pcVar8 + 0x731c0) + -0x4de0,0x42d);
  pcVar8 = *(code **)(pcVar8 + 0x73480);
  (*pcVar8)();
  iVar4 = (**(code **)(pcVar8 + 0x73edc))
                    (*(int *)(iVar7 + 0xc) << 2,*(undefined4 *)(pcVar8 + 0x74488));
  *(int *)(iVar7 + 0x70) = iVar4;
  if (iVar4 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e240850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar8 = (code *)(**(code **)(pcVar8 + 0x73438))
                               (iVar7,iVar4,*(undefined4 *)(iVar7 + 0xc),
                                *(undefined4 *)(iVar7 + 0x3c));
    return pcVar8;
  }
  (**(code **)(pcVar8 + 0x7364c))(*(int *)(pcVar8 + 0x73114) + -0x51a4);
  uVar6 = 0x41e;
  uVar5 = *(int *)(pcVar8 + 0x73114) - 0x51fc;
  iVar4 = *(int *)(pcVar8 + 0x73114) + -0x4db8;
  (**(code **)(pcVar8 + 0x736ec))(*(int *)(pcVar8 + 0x73114) + -0x73a0);
  pcVar9 = *(code **)(pcVar8 + 0x733d4);
  (*pcVar9)();
  if ((iVar4 == 0) || (uVar6 <= uVar5)) {
    pcVar1 = (code *)0x0;
  }
  else {
    pcVar3 = *(code **)(iStack_8c + uVar5 * 4);
    pcVar1 = pcVar3 + iVar4;
    if (pcVar8 + 0x7b0ec <= pcVar3) {
      (**(code **)(pcVar9 + 0x73640))
                (*(int *)(pcVar9 + 0x73068) + -0x73a0,*(int *)(pcVar9 + 0x73068) + -0x51fc,
                 *(int *)(pcVar9 + 0x73068) + -0x4c84,0x261);
      pcVar8 = *(code **)(pcVar9 + 0x73328);
      (*pcVar8)();
      pcVar8 = (code *)(**(code **)(pcVar8 + 0x73f84))();
      return pcVar8;
    }
  }
  return pcVar1;
}

