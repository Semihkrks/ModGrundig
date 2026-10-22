
/* WARNING: Removing unreachable block (ram,0x2e242fc8) */
/* WARNING: Removing unreachable block (ram,0x2e242fa8) */
/* WARNING: Removing unreachable block (ram,0x2e242f98) */
/* WARNING: Removing unreachable block (ram,0x2e242fb8) */
/* WARNING: Removing unreachable block (ram,0x2e242f88) */
/* MResourcePkg::BuildNumData() */

undefined4 __thiscall MResourcePkg::BuildNumData(MResourcePkg *this)

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
  
                    /* try { // try from 2e242cfc to 2e242d03 has its CatchHandler @ 2e243018 */
  psVar3 = *(string **)(this + 0x28);
  std::string::string((string *)&local_34,"/",aaStack_58);
                    /* try { // try from 2e242d18 to 2e242d1f has its CatchHandler @ 2e242ffc */
  std::operator+((string *)&local_30,psVar3);
                    /* try { // try from 2e242d38 to 2e242d3f has its CatchHandler @ 2e243074 */
  std::string::string((string *)&local_2c,"Num_res.bin",aaStack_54);
                    /* try { // try from 2e242d54 to 2e242d5b has its CatchHandler @ 2e243048 */
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
                    /* try { // try from 2e242db0 to 2e242db7 has its CatchHandler @ 2e243040 */
    std::string::string((string *)local_28,"Num_res.bin",aaStack_50);
                    /* try { // try from 2e242dc8 to 2e242dcf has its CatchHandler @ 2e243024 */
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
                    /* try { // try from 2e242dec to 2e242df3 has its CatchHandler @ 2e242fd8 */
  uVar1 = BuildData(this,local_38,1);
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

