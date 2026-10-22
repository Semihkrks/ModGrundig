
/* MResourcePkg::BuildIndex(unsigned long*, unsigned long, unsigned char*) */

code * __thiscall
MResourcePkg::BuildIndex(MResourcePkg *this,ulong *param_1,ulong param_2,uchar *param_3)

{
  code *pcVar1;
  code *pcVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined *puVar10;
  code *pcVar11;
  int iStack_8c;
  
  if ((param_1 != (ulong *)0x0) && (param_3 != (uchar *)0x0)) {
    if (param_2 != 0) {
      uVar3 = 0;
      iVar5 = 0;
      while( true ) {
        iVar9 = *(int *)(param_3 + uVar3);
        if (iVar9 == 0) {
          *param_1 = uVar3;
        }
        else {
          *param_1 = uVar3 + 4;
        }
        if (param_2 <= iVar5 + 1U) break;
        param_1 = param_1 + 1;
        iVar5 = iVar5 + 1;
        uVar3 = uVar3 + iVar9 + 4;
      }
    }
    return (code *)0x1;
  }
  puVar6 = PTR_PTR_2e2b3908 + -0x73a0;
  (*(code *)PTR_printf_2e2b3ee0)(puVar6,PTR_PTR_2e2b3908 + -0x51fc,PTR_PTR_2e2b3908 + -0x4d90,0x400)
  ;
  puVar10 = PTR_abort_2e2b3bc8;
  (*(code *)PTR_abort_2e2b3bc8)();
  iVar5 = (**(code **)(puVar10 + 0x740e0))
                    (*(int *)(puVar6 + 0x1c) << 2,*(undefined4 *)(puVar10 + 0x7468c));
  *(int *)(puVar6 + 0x7c) = iVar5;
  if (iVar5 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e24064c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (code *)(**(code **)(puVar10 + 0x7363c))
                               (puVar6,iVar5,*(undefined4 *)(puVar6 + 0x1c),
                                *(undefined4 *)(puVar6 + 0x4c));
    return pcVar1;
  }
  (**(code **)(puVar10 + 0x73850))(*(int *)(puVar10 + 0x73318) + -0x51e4);
  iVar9 = *(int *)(puVar10 + 0x73318) + -0x73a0;
  (**(code **)(puVar10 + 0x738f0))
            (iVar9,*(int *)(puVar10 + 0x73318) + -0x51fc,*(int *)(puVar10 + 0x73318) + -0x4e30,1099)
  ;
  pcVar1 = *(code **)(puVar10 + 0x735d8);
  (*pcVar1)();
  iVar5 = (**(code **)(pcVar1 + 0x74034))
                    (*(int *)(iVar9 + 0x14) << 2,*(undefined4 *)(pcVar1 + 0x745e0));
  *(int *)(iVar9 + 0x78) = iVar5;
  if (iVar5 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e2406f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (code *)(**(code **)(pcVar1 + 0x73590))
                               (iVar9,iVar5,*(undefined4 *)(iVar9 + 0x14),
                                *(undefined4 *)(iVar9 + 0x44));
    return pcVar1;
  }
  (**(code **)(pcVar1 + 0x737a4))(*(int *)(pcVar1 + 0x7326c) + -0x51e4);
  iVar9 = *(int *)(pcVar1 + 0x7326c) + -0x73a0;
  (**(code **)(pcVar1 + 0x73844))
            (iVar9,*(int *)(pcVar1 + 0x7326c) + -0x51fc,*(int *)(pcVar1 + 0x7326c) + -0x4e08,0x43c);
  pcVar1 = *(code **)(pcVar1 + 0x7352c);
  (*pcVar1)();
  iVar5 = (**(code **)(pcVar1 + 0x73f88))
                    (*(int *)(iVar9 + 0x10) << 2,*(undefined4 *)(pcVar1 + 0x74534));
  *(int *)(iVar9 + 0x74) = iVar5;
  if (iVar5 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e2407a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (code *)(**(code **)(pcVar1 + 0x734e4))
                               (iVar9,iVar5,*(undefined4 *)(iVar9 + 0x10),
                                *(undefined4 *)(iVar9 + 0x40));
    return pcVar1;
  }
  (**(code **)(pcVar1 + 0x736f8))(*(int *)(pcVar1 + 0x731c0) + -0x51c4);
  iVar9 = *(int *)(pcVar1 + 0x731c0) + -0x73a0;
  (**(code **)(pcVar1 + 0x73798))
            (iVar9,*(int *)(pcVar1 + 0x731c0) + -0x51fc,*(int *)(pcVar1 + 0x731c0) + -0x4de0,0x42d);
  pcVar1 = *(code **)(pcVar1 + 0x73480);
  (*pcVar1)();
  iVar5 = (**(code **)(pcVar1 + 0x73edc))
                    (*(int *)(iVar9 + 0xc) << 2,*(undefined4 *)(pcVar1 + 0x74488));
  *(int *)(iVar9 + 0x70) = iVar5;
  if (iVar5 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e240850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (code *)(**(code **)(pcVar1 + 0x73438))
                               (iVar9,iVar5,*(undefined4 *)(iVar9 + 0xc),
                                *(undefined4 *)(iVar9 + 0x3c));
    return pcVar1;
  }
  (**(code **)(pcVar1 + 0x7364c))(*(int *)(pcVar1 + 0x73114) + -0x51a4);
  uVar8 = 0x41e;
  uVar7 = *(int *)(pcVar1 + 0x73114) - 0x51fc;
  iVar5 = *(int *)(pcVar1 + 0x73114) + -0x4db8;
  (**(code **)(pcVar1 + 0x736ec))(*(int *)(pcVar1 + 0x73114) + -0x73a0);
  pcVar11 = *(code **)(pcVar1 + 0x733d4);
  (*pcVar11)();
  if ((iVar5 == 0) || (uVar8 <= uVar7)) {
    pcVar2 = (code *)0x0;
  }
  else {
    pcVar4 = *(code **)(iStack_8c + uVar7 * 4);
    pcVar2 = pcVar4 + iVar5;
    if (pcVar1 + 0x7b0ec <= pcVar4) {
      (**(code **)(pcVar11 + 0x73640))
                (*(int *)(pcVar11 + 0x73068) + -0x73a0,*(int *)(pcVar11 + 0x73068) + -0x51fc,
                 *(int *)(pcVar11 + 0x73068) + -0x4c84,0x261);
      pcVar1 = *(code **)(pcVar11 + 0x73328);
      (*pcVar1)();
      pcVar1 = (code *)(**(code **)(pcVar1 + 0x73f84))();
      return pcVar1;
    }
  }
  return pcVar2;
}

