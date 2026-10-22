
/* WARNING: Removing unreachable block (ram,0x2e242828) */
/* WARNING: Removing unreachable block (ram,0x2e242808) */
/* WARNING: Removing unreachable block (ram,0x2e2427f8) */
/* WARNING: Removing unreachable block (ram,0x2e242818) */
/* WARNING: Removing unreachable block (ram,0x2e2427e8) */
/* MResourcePkg::BuildFontPathData() */

undefined4 __thiscall MResourcePkg::BuildFontPathData(MResourcePkg *this)

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
  
                    /* try { // try from 2e24255c to 2e242563 has its CatchHandler @ 2e242878 */
  psVar3 = *(string **)(this + 0x28);
  std::string::string((string *)&local_34,"/",aaStack_58);
                    /* try { // try from 2e242578 to 2e24257f has its CatchHandler @ 2e24285c */
  std::operator+((string *)&local_30,psVar3);
                    /* try { // try from 2e242598 to 2e24259f has its CatchHandler @ 2e2428d4 */
  std::string::string((string *)&local_2c,"font_res.bin",aaStack_54);
                    /* try { // try from 2e2425b4 to 2e2425bb has its CatchHandler @ 2e2428a8 */
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
                    /* try { // try from 2e242610 to 2e242617 has its CatchHandler @ 2e2428a0 */
    std::string::string((string *)local_28,"font_res.bin",aaStack_50);
                    /* try { // try from 2e242628 to 2e24262f has its CatchHandler @ 2e242884 */
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
                    /* try { // try from 2e24264c to 2e242653 has its CatchHandler @ 2e242838 */
  uVar1 = BuildData(this,local_38,4);
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

