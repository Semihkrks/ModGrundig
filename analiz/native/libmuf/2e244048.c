
/* MResourcePkg::Build(char const*) */

byte __thiscall MResourcePkg::Build(MResourcePkg *this,char *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  int iVar9;
  int in_t9;
  code *pcVar10;
  undefined1 auStack_30 [12];
  
  iVar9 = (**(code **)(in_t9 + 0x6ffb4))(4,*(undefined4 *)(in_t9 + 0x70c34));
  if (iVar9 != 0) {
                    /* try { // try from 2e2440b0 to 2e2440b7 has its CatchHandler @ 2e2441fc */
    (**(code **)(in_t9 + 0x7028c))(iVar9,param_1,auStack_30);
    *(int *)(this + 0x28) = iVar9;
    bVar1 = (**(code **)(in_t9 + 0x6fb94))(this);
    bVar2 = (**(code **)(in_t9 + 0x6fc70))(this);
    bVar3 = (**(code **)(in_t9 + 0x70dfc))(this);
    bVar4 = (**(code **)(in_t9 + 0x6fe24))(this);
    bVar5 = (**(code **)(in_t9 + 0x70a4c))(this);
    bVar6 = (**(code **)(in_t9 + 0x7043c))(this);
    bVar7 = (**(code **)(in_t9 + 0x702b8))(this);
    bVar8 = (**(code **)(in_t9 + 0x70470))(this);
    this[0x24] = (MResourcePkg)0x1;
    return bVar2 & bVar1 & bVar3 & bVar4 & bVar5 & bVar6 & bVar7 & bVar8;
  }
  iVar9 = *(int *)(in_t9 + 0x6f8c0);
  pcVar10 = *(code **)(in_t9 + 0x6fdf8);
  *(undefined4 *)(this + 0x28) = 0;
  (*pcVar10)(iVar9 + -0x4ea4);
  iVar9 = *(int *)(in_t9 + 0x6f8c0) + -0x73a0;
  (**(code **)(in_t9 + 0x6fe98))
            (iVar9,*(int *)(in_t9 + 0x6f8c0) + -0x51fc,*(int *)(in_t9 + 0x6f8c0) + -0x4d18,0x2d1);
  (**(code **)(in_t9 + 0x6fb80))();
                    /* catch() { ... } // from try @ 2e2440b0 with catch @ 2e2441fc */
  (**(code **)(in_t9 + 0x70894))(0,*(undefined4 *)(in_t9 + 0x70c34));
  pcVar10 = *(code **)(in_t9 + 0x6fb54);
  (*pcVar10)();
  pcVar10 = *(code **)(pcVar10 + 0x6fc98);
  *(undefined1 *)(iVar9 + 0x2c) = 1;
  (*pcVar10)();
  *(undefined1 *)(iVar9 + 0x2c) = 0;
  return 1;
}

