
/* WARNING: Removing unreachable block (ram,0x2e242bf8) */
/* WARNING: Removing unreachable block (ram,0x2e242bd8) */
/* WARNING: Removing unreachable block (ram,0x2e242bc8) */
/* WARNING: Removing unreachable block (ram,0x2e242be8) */
/* WARNING: Removing unreachable block (ram,0x2e242bb8) */
/* MResourcePkg::BuildImgPathData() */

undefined4 __thiscall MResourcePkg::BuildImgPathData(MResourcePkg *this)

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
  
                    /* try { // try from 2e24292c to 2e242933 has its CatchHandler @ 2e242c48 */
  psVar3 = *(string **)(this + 0x28);
  std::string::string((string *)&local_34,"/",aaStack_58);
                    /* try { // try from 2e242948 to 2e24294f has its CatchHandler @ 2e242c2c */
  std::operator+((string *)&local_30,psVar3);
                    /* try { // try from 2e242968 to 2e24296f has its CatchHandler @ 2e242ca4 */
  std::string::string((string *)&local_2c,"Image_res.bin",aaStack_54);
                    /* try { // try from 2e242984 to 2e24298b has its CatchHandler @ 2e242c78 */
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
                    /* try { // try from 2e2429e0 to 2e2429e7 has its CatchHandler @ 2e242c70 */
    std::string::string((string *)local_28,"Image_res.bin",aaStack_50);
                    /* try { // try from 2e2429f8 to 2e2429ff has its CatchHandler @ 2e242c54 */
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
                    /* try { // try from 2e242a1c to 2e242a23 has its CatchHandler @ 2e242c08 */
  uVar1 = BuildData(this,local_38,5);
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

