
/* MResourcePkg::BuildImgPathIndex() */

code * __thiscall MResourcePkg::BuildImgPathIndex(MResourcePkg *this)

{
  int iVar1;
  code *pcVar2;
  code *pcVar3;
  code *pcVar4;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined *puVar9;
  code *pcVar10;
  int iStack_4c;
  
  iVar1 = (*(code *)PTR_operator_new___2e2b46d0)(*(int *)(this + 0x14) << 2,PTR_DAT_2e2b4c7c);
  *(int *)(this + 0x78) = iVar1;
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e2406f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar2 = (code *)(*(code *)PTR_BuildIndex_2e2b3c2c)
                               (this,iVar1,*(undefined4 *)(this + 0x14),*(undefined4 *)(this + 0x44)
                               );
    return pcVar2;
  }
  (*(code *)PTR_puts_2e2b3e40)(PTR_PTR_2e2b3908 + -0x51e4);
  puVar5 = PTR_PTR_2e2b3908 + -0x73a0;
  (*(code *)PTR_printf_2e2b3ee0)(puVar5,PTR_PTR_2e2b3908 + -0x51fc,PTR_PTR_2e2b3908 + -0x4e08,0x43c)
  ;
  puVar9 = PTR_abort_2e2b3bc8;
  (*(code *)PTR_abort_2e2b3bc8)();
  iVar1 = (**(code **)(puVar9 + 0x73f88))
                    (*(int *)(puVar5 + 0x10) << 2,*(undefined4 *)(puVar9 + 0x74534));
  *(int *)(puVar5 + 0x74) = iVar1;
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e2407a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar2 = (code *)(**(code **)(puVar9 + 0x734e4))
                               (puVar5,iVar1,*(undefined4 *)(puVar5 + 0x10),
                                *(undefined4 *)(puVar5 + 0x40));
    return pcVar2;
  }
  (**(code **)(puVar9 + 0x736f8))(*(int *)(puVar9 + 0x731c0) + -0x51c4);
  iVar6 = *(int *)(puVar9 + 0x731c0) + -0x73a0;
  (**(code **)(puVar9 + 0x73798))
            (iVar6,*(int *)(puVar9 + 0x731c0) + -0x51fc,*(int *)(puVar9 + 0x731c0) + -0x4de0,0x42d);
  pcVar2 = *(code **)(puVar9 + 0x73480);
  (*pcVar2)();
  iVar1 = (**(code **)(pcVar2 + 0x73edc))
                    (*(int *)(iVar6 + 0xc) << 2,*(undefined4 *)(pcVar2 + 0x74488));
  *(int *)(iVar6 + 0x70) = iVar1;
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e240850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar2 = (code *)(**(code **)(pcVar2 + 0x73438))
                               (iVar6,iVar1,*(undefined4 *)(iVar6 + 0xc),
                                *(undefined4 *)(iVar6 + 0x3c));
    return pcVar2;
  }
  (**(code **)(pcVar2 + 0x7364c))(*(int *)(pcVar2 + 0x73114) + -0x51a4);
  uVar8 = 0x41e;
  uVar7 = *(int *)(pcVar2 + 0x73114) - 0x51fc;
  iVar1 = *(int *)(pcVar2 + 0x73114) + -0x4db8;
  (**(code **)(pcVar2 + 0x736ec))(*(int *)(pcVar2 + 0x73114) + -0x73a0);
  pcVar10 = *(code **)(pcVar2 + 0x733d4);
  (*pcVar10)();
  if ((iVar1 == 0) || (uVar8 <= uVar7)) {
    pcVar3 = (code *)0x0;
  }
  else {
    pcVar4 = *(code **)(iStack_4c + uVar7 * 4);
    pcVar3 = pcVar4 + iVar1;
    if (pcVar2 + 0x7b0ec <= pcVar4) {
      (**(code **)(pcVar10 + 0x73640))
                (*(int *)(pcVar10 + 0x73068) + -0x73a0,*(int *)(pcVar10 + 0x73068) + -0x51fc,
                 *(int *)(pcVar10 + 0x73068) + -0x4c84,0x261);
      pcVar2 = *(code **)(pcVar10 + 0x73328);
      (*pcVar2)();
      pcVar2 = (code *)(**(code **)(pcVar2 + 0x73f84))();
      return pcVar2;
    }
  }
  return pcVar3;
}

