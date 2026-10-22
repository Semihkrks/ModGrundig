
/* MResourcePkg::MResourcePkg(char const*) */

void __thiscall MResourcePkg::MResourcePkg(MResourcePkg *this,char *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int in_t9;
  code *pcVar6;
  
  this[0x2d] = (MResourcePkg)0x1;
  this[0x2c] = (MResourcePkg)0x0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  this[0x24] = (MResourcePkg)0x0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  if (param_1 == (char *)0x0) {
    iVar4 = *(int *)(in_t9 + 0x6f688);
    iVar5 = *(int *)(in_t9 + 0x6f688);
    if (*(int *)(iVar4 + 0x3a94) == 0) {
      iVar1 = (**(code **)(in_t9 + 0x70704))(*(undefined4 *)(iVar5 + 0x3a90));
      iVar2 = (**(code **)(in_t9 + 0x70460))(iVar1 + 1,*(undefined4 *)(in_t9 + 0x70a0c));
      *(int *)(iVar4 + 0x3a94) = iVar2;
      if (iVar2 == 0) goto LAB_2e244430;
      iVar5 = (**(code **)(in_t9 + 0x70470))(iVar2,*(undefined4 *)(iVar5 + 0x3a90),iVar1);
      *(undefined1 *)(*(int *)(iVar4 + 0x3a94) + iVar1) = 0;
      if (iVar5 == 0) {
        iVar4 = *(int *)(in_t9 + 0x6f698);
        iVar5 = *(int *)(in_t9 + 0x6f698);
        iVar1 = *(int *)(in_t9 + 0x6f698);
        pcVar6 = *(code **)(in_t9 + 0x6fc70);
        uVar3 = 0x18e;
        do {
          (*pcVar6)(iVar4 + -0x73a0,iVar5 + -0x51fc,iVar1 + -0x4c44,uVar3);
          (**(code **)(in_t9 + 0x6f958))();
LAB_2e244430:
          (**(code **)(in_t9 + 0x6fbd0))(*(int *)(in_t9 + 0x6f698) + -0x5104);
          uVar3 = 0x185;
          iVar4 = *(int *)(in_t9 + 0x6f698);
          iVar5 = *(int *)(in_t9 + 0x6f698);
          iVar1 = *(int *)(in_t9 + 0x6f698);
          pcVar6 = *(code **)(in_t9 + 0x6fc70);
        } while( true );
      }
    }
    (**(code **)(in_t9 + 0x6fc4c))(this,*(undefined4 *)(iVar4 + 0x3a94));
  }
  else {
    (**(code **)(in_t9 + 0x6fc4c))();
  }
  (**(code **)(in_t9 + 0x706b4))
            (**(undefined4 **)(in_t9 + 0x6f7fc),*(int *)(in_t9 + 0x6f698) + -0x4e80,
             *(undefined4 *)(this + 0x20));
  this[0x2d] = (MResourcePkg)0x0;
  return;
}

