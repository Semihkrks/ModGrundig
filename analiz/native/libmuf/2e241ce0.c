
/* MResourcePkg::~MResourcePkg() */

void __thiscall MResourcePkg::~MResourcePkg(MResourcePkg *this)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int in_t9;
  code *pcVar4;
  undefined1 auStack_18 [12];
  
  iVar2 = *(int *)(in_t9 + 0x71c18);
  if (*(int *)(iVar2 + 0x3a94) != 0) {
    (**(code **)(in_t9 + 0x7244c))();
    *(undefined4 *)(iVar2 + 0x3a94) = 0;
  }
  piVar3 = *(int **)(this + 0x28);
  if (piVar3 == (int *)0x0) goto LAB_2e241d54;
  iVar2 = *piVar3;
  if (iVar2 + -0xc == *(int *)(in_t9 + 0x72fb0)) {
LAB_2e241d40:
    pcVar4 = *(code **)(in_t9 + 0x72804);
  }
  else {
    if (*(int *)(in_t9 + 0x72eb8) == 0) {
      iVar1 = *(int *)(iVar2 + -4);
      *(int *)(iVar2 + -4) = iVar1 + -1;
    }
    else {
      SYNC(0);
      iVar1 = *(int *)(iVar2 + -4);
      *(int *)(iVar2 + -4) = iVar1 + -1;
      SYNC(0);
    }
    pcVar4 = *(code **)(in_t9 + 0x72804);
    if (iVar1 < 1) {
      (**(code **)(in_t9 + 0x729f8))(iVar2 + -0xc,auStack_18);
      goto LAB_2e241d40;
    }
  }
  (*pcVar4)(piVar3);
  *(undefined4 *)(this + 0x28) = 0;
LAB_2e241d54:
  if (*(int *)(this + 0x30) != 0) {
    (**(code **)(in_t9 + 0x7244c))();
    *(undefined4 *)(this + 0x30) = 0;
  }
  if (*(int *)(this + 0x34) != 0) {
    (**(code **)(in_t9 + 0x7244c))();
    *(undefined4 *)(this + 0x34) = 0;
  }
  if (*(int *)(this + 0x38) != 0) {
    (**(code **)(in_t9 + 0x7244c))();
    *(undefined4 *)(this + 0x38) = 0;
  }
  if (*(int *)(this + 0x3c) != 0) {
    (**(code **)(in_t9 + 0x7244c))();
    *(undefined4 *)(this + 0x3c) = 0;
  }
  if (*(int *)(this + 0x40) != 0) {
    (**(code **)(in_t9 + 0x7244c))();
    *(undefined4 *)(this + 0x40) = 0;
  }
  if (*(int *)(this + 0x44) != 0) {
    (**(code **)(in_t9 + 0x7244c))();
    *(undefined4 *)(this + 0x44) = 0;
  }
  if (*(int *)(this + 0x70) != 0) {
    (**(code **)(in_t9 + 0x7244c))();
    *(undefined4 *)(this + 0x70) = 0;
  }
  if (*(int *)(this + 0x74) != 0) {
    (**(code **)(in_t9 + 0x7244c))();
    *(undefined4 *)(this + 0x74) = 0;
  }
  if (*(int *)(this + 0x78) != 0) {
    (**(code **)(in_t9 + 0x7244c))();
    *(undefined4 *)(this + 0x78) = 0;
  }
  if (*(int *)(this + 0x48) != 0) {
    (**(code **)(in_t9 + 0x7244c))();
    *(undefined4 *)(this + 0x48) = 0;
  }
  if (*(int *)(this + 0x4c) != 0) {
    (**(code **)(in_t9 + 0x7244c))();
    *(undefined4 *)(this + 0x4c) = 0;
  }
  if (*(int *)(this + 0x7c) != 0) {
    (**(code **)(in_t9 + 0x7244c))();
    *(undefined4 *)(this + 0x7c) = 0;
  }
  this[0x24] = (MResourcePkg)0x0;
  return;
}

