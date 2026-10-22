
/* WARNING: Removing unreachable block (ram,0x2e243768) */
/* WARNING: Removing unreachable block (ram,0x2e243748) */
/* WARNING: Removing unreachable block (ram,0x2e243738) */
/* WARNING: Removing unreachable block (ram,0x2e243758) */
/* WARNING: Removing unreachable block (ram,0x2e243728) */
/* MResourcePkg::BuildColorData() */

undefined4 __thiscall MResourcePkg::BuildColorData(MResourcePkg *this)

{
  undefined4 uVar1;
  int iVar2;
  string *psVar3;
  allocator aaStack_58 [4];
  allocator aaStack_54 [4];
  allocator aaStack_50 [24];
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28 [3];
  
                    /* try { // try from 2e24349c to 2e2434a3 has its CatchHandler @ 2e2437b8 */
  psVar3 = *(string **)(this + 0x28);
  std::string::string((string *)&local_34,"/",aaStack_58);
                    /* try { // try from 2e2434b8 to 2e2434bf has its CatchHandler @ 2e24379c */
  std::operator+((string *)&local_30,psVar3);
                    /* try { // try from 2e2434d8 to 2e2434df has its CatchHandler @ 2e243814 */
  std::string::string((string *)&local_2c,"Color_res.bin",aaStack_54);
                    /* try { // try from 2e2434f4 to 2e2434fb has its CatchHandler @ 2e2437e8 */
  std::operator+((string *)&local_38,(string *)&local_30);
  if ((allocator *)(local_2c + -0xc) != (allocator *)&DAT_2c828ab8) {
    SYNC(0);
    iVar2 = *(int *)(local_2c + -4);
    *(int *)(local_2c + -4) = iVar2 + -1;
    SYNC(0);
    if (iVar2 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_2c + -0xc));
    }
  }
  if ((allocator *)(local_30 + -0xc) != (allocator *)&DAT_2c828ab8) {
    SYNC(0);
    iVar2 = *(int *)(local_30 + -4);
    *(int *)(local_30 + -4) = iVar2 + -1;
    SYNC(0);
    if (iVar2 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_30 + -0xc));
    }
  }
  if ((allocator *)(local_34 + -0xc) != (allocator *)&DAT_2c828ab8) {
    SYNC(0);
    iVar2 = *(int *)(local_34 + -4);
    *(int *)(local_34 + -4) = iVar2 + -1;
    SYNC(0);
    if (iVar2 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_34 + -0xc));
    }
  }
  if (this[0x2d] != (MResourcePkg)0x0) {
                    /* try { // try from 2e243550 to 2e243557 has its CatchHandler @ 2e2437e0 */
    std::string::string((string *)local_28,"Color_res.bin",aaStack_50);
                    /* try { // try from 2e243568 to 2e24356f has its CatchHandler @ 2e2437c4 */
    CheckInitialPath(this,(string *)&local_38,(string *)local_28);
    if ((allocator *)(local_28[0] + -0xc) != (allocator *)&DAT_2c828ab8) {
      SYNC(0);
      iVar2 = *(int *)(local_28[0] + -4);
      *(int *)(local_28[0] + -4) = iVar2 + -1;
      SYNC(0);
      if (iVar2 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_28[0] + -0xc));
      }
    }
  }
                    /* try { // try from 2e24358c to 2e243593 has its CatchHandler @ 2e243778 */
  uVar1 = BuildData(this,local_38,2);
  if ((allocator *)(local_38 + -0xc) != (allocator *)&DAT_2c828ab8) {
    SYNC(0);
    iVar2 = *(int *)(local_38 + -4);
    *(int *)(local_38 + -4) = iVar2 + -1;
    SYNC(0);
    if (iVar2 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_38 + -0xc));
    }
  }
  return uVar1;
}

