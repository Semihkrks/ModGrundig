
/* WARNING: Removing unreachable block (ram,0x2e243b7c) */
/* WARNING: Removing unreachable block (ram,0x2e243b5c) */
/* WARNING: Removing unreachable block (ram,0x2e243b4c) */
/* WARNING: Removing unreachable block (ram,0x2e243b3c) */
/* WARNING: Removing unreachable block (ram,0x2e243b6c) */
/* MResourcePkg::BuildBoolData() */

undefined4 __thiscall MResourcePkg::BuildBoolData(MResourcePkg *this)

{
  FILE *__stream;
  undefined4 uVar1;
  int iVar2;
  string *psVar3;
  allocator aaStack_58 [4];
  allocator aaStack_54 [4];
  allocator aaStack_50 [24];
  char *local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28 [3];
  
                    /* try { // try from 2e24386c to 2e243873 has its CatchHandler @ 2e243c28 */
  psVar3 = *(string **)(this + 0x28);
  std::string::string((string *)&local_34,"/",aaStack_58);
                    /* try { // try from 2e243888 to 2e24388f has its CatchHandler @ 2e243bc0 */
  std::operator+((string *)&local_30,psVar3);
                    /* try { // try from 2e2438a8 to 2e2438af has its CatchHandler @ 2e243b8c */
  std::string::string((string *)&local_2c,"Bool_res.bin",aaStack_54);
                    /* try { // try from 2e2438c4 to 2e2438cb has its CatchHandler @ 2e243c0c */
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
                    /* try { // try from 2e243910 to 2e24394b has its CatchHandler @ 2e243c04 */
  __stream = fopen(local_38,"rb");
  if (__stream == (FILE *)0x0) {
                    /* try { // try from 2e243a1c to 2e243a23 has its CatchHandler @ 2e243c04 */
    puts("[Warning] MResourcePkg::BuildBoolData, Bool_res.bin doesn\'t exist");
    uVar1 = 0;
  }
  else {
    fclose(__stream);
    if (this[0x2d] != (MResourcePkg)0x0) {
                    /* try { // try from 2e24399c to 2e2439a3 has its CatchHandler @ 2e243bcc */
      std::string::string((string *)local_28,"Bool_res.bin",aaStack_50);
                    /* try { // try from 2e2439b4 to 2e2439bb has its CatchHandler @ 2e243be8 */
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
    uVar1 = BuildData(this,local_38,0);
  }
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

