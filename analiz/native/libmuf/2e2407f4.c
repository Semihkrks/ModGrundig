
/* MResourcePkg::BuildStringIndex() */

int __thiscall MResourcePkg::BuildStringIndex(MResourcePkg *this)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int in_t9;
  code *pcVar4;
  int iStack_c;
  
  iVar1 = (**(code **)(in_t9 + 0x73edc))(*(int *)(this + 0xc) << 2,*(undefined4 *)(in_t9 + 0x74488))
  ;
  *(int *)(this + 0x70) = iVar1;
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x2e240850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(in_t9 + 0x73438))
                      (this,iVar1,*(undefined4 *)(this + 0xc),*(undefined4 *)(this + 0x3c));
    return iVar1;
  }
  (**(code **)(in_t9 + 0x7364c))(*(int *)(in_t9 + 0x73114) + -0x51a4);
  uVar3 = 0x41e;
  uVar2 = *(int *)(in_t9 + 0x73114) - 0x51fc;
  iVar1 = *(int *)(in_t9 + 0x73114) + -0x4db8;
  (**(code **)(in_t9 + 0x736ec))(*(int *)(in_t9 + 0x73114) + -0x73a0);
  pcVar4 = *(code **)(in_t9 + 0x733d4);
  (*pcVar4)();
  if ((iVar1 == 0) || (uVar3 <= uVar2)) {
    iVar1 = 0;
  }
  else {
    uVar2 = *(uint *)(iStack_c + uVar2 * 4);
    iVar1 = iVar1 + uVar2;
    if (in_t9 + 0x7b0ecU <= uVar2) {
      (**(code **)(pcVar4 + 0x73640))
                (*(int *)(pcVar4 + 0x73068) + -0x73a0,*(int *)(pcVar4 + 0x73068) + -0x51fc,
                 *(int *)(pcVar4 + 0x73068) + -0x4c84,0x261);
      pcVar4 = *(code **)(pcVar4 + 0x73328);
      (*pcVar4)();
      iVar1 = (**(code **)(pcVar4 + 0x73f84))();
      return iVar1;
    }
  }
  return iVar1;
}

