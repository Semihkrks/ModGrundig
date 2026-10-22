
/* MResourcePkg::SetDefaultRcDir(char const*) */

undefined4 MResourcePkg::SetDefaultRcDir(char *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int in_t9;
  code *pcVar5;
  
  iVar4 = *(int *)(in_t9 + 0x726c4);
  if (*(int *)(iVar4 + 0x3a94) != 0) {
    (**(code **)(in_t9 + 0x72ef8))();
    *(undefined4 *)(iVar4 + 0x3a94) = 0;
  }
  iVar1 = (**(code **)(in_t9 + 0x73740))(param_1);
  if (0 < iVar1) {
    iVar2 = (**(code **)(in_t9 + 0x7349c))(iVar1 + 1,*(undefined4 *)(in_t9 + 0x73a48));
    *(int *)(iVar4 + 0x3a94) = iVar2;
    if (iVar2 != 0) {
      (**(code **)(in_t9 + 0x734ac))(iVar2,param_1,iVar1);
      *(undefined1 *)(*(int *)(*(int *)(in_t9 + 0x726c4) + 0x3a94) + iVar1) = 0;
      return 1;
    }
    do {
      (**(code **)(in_t9 + 0x72c0c))(*(int *)(in_t9 + 0x726d4) + -0x5104);
      uVar3 = 0x12f;
      iVar4 = *(int *)(in_t9 + 0x726d4);
      iVar1 = *(int *)(in_t9 + 0x726d4);
      iVar2 = *(int *)(in_t9 + 0x726d4);
      pcVar5 = *(code **)(in_t9 + 0x72cac);
LAB_2e241314:
      (*pcVar5)(iVar4 + -0x73a0,iVar1 + -0x51fc,iVar2 + -0x4c1c,uVar3);
      (**(code **)(in_t9 + 0x72994))();
    } while( true );
  }
  iVar4 = *(int *)(in_t9 + 0x726d4);
  iVar1 = *(int *)(in_t9 + 0x726d4);
  iVar2 = *(int *)(in_t9 + 0x726d4);
  pcVar5 = *(code **)(in_t9 + 0x72cac);
  uVar3 = 0x136;
  goto LAB_2e241314;
}

