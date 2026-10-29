
/* MW_DTV_FREQUENCYTABLE_DVBS_Customer::ReloadSatList() */

void __thiscall
MW_DTV_FREQUENCYTABLE_DVBS_Customer::ReloadSatList(MW_DTV_FREQUENCYTABLE_DVBS_Customer *this)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  char local_18 [8];
  
  uVar1 = mapi_interface_TV::Get_mapi_storage_dtv_cmdb_sat();
  *(undefined4 *)(this + 0x84) = uVar1;
  uVar1 = mapi_interface_TV::Get_mapi_storage_dtv_cmdb_sat_backup();
  *(undefined4 *)(this + 0x88) = uVar1;
  mapi_storage::Finalize();
  mapi_storage::Finalize();
  mapi_storage::Init();
  mapi_storage::Init();
  puVar5 = *(undefined4 **)(this + 0xe4);
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(this + 0x94);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = operator_new__(4,(nothrow_t *)&DAT_2c7f5bd0);
    *(undefined4 **)(this + 0xe4) = puVar5;
    if (puVar5 == (undefined4 *)0x0) {
      printf("ASSERT FAIL: %s %s %d\n","./middleware/src/MW_DTV_FreqTable_DVBS_Customer.cpp",
             "void MW_DTV_FREQUENCYTABLE_DVBS_Customer::ReloadSatList()",0x74c);
                    /* WARNING: Subroutine does not return */
      abort();
    }
  }
  *(undefined4 *)(this + 0xdc) = 0x10;
  *(undefined4 *)(this + 0xe0) = 4;
  *(undefined4 *)(this + 0xe8) = 0x14;
  *(undefined4 *)(this + 0xec) = 0x178;
  *(undefined4 *)(this + 0xcc) = 0x1ac;
  *(undefined4 *)(this + 0xd0) = 0x660;
  *(undefined4 *)(this + 200) = 8;
  *(undefined4 *)(this + 0xc4) = 8;
  *(undefined4 *)(this + 0xd4) = 0x80c;
  *(undefined4 *)(this + 0xd8) = 48000;
  *puVar5 = 0;
  *(undefined4 *)(this + 0xf4) = 0;
  *(undefined4 *)(this + 0xf8) = 0;
  local_18[0] = '\0';
  local_18[1] = '\0';
  local_18[2] = '\0';
  local_18[3] = '\0';
  iVar2 = mapi_storage::Read(*(ulong *)(this + 0x84),(uchar *)0x0,(ulong)local_18);
  if (iVar2 == 0) {
    puts("@@@@ ReloadSatList. Can not read version size. Reset sat DB @@@");
  }
  else {
    iVar2 = 0;
    pcVar3 = local_18;
    do {
      pcVar4 = &_fdata + iVar2;
      iVar2 = iVar2 + 1;
      if (*pcVar3 != *pcVar4) {
        puts("@@@ ReloadSatList. Sat DB version check error, reset Sat DB@@@");
        goto LAB_2e96743c;
      }
      pcVar3 = local_18 + iVar2;
    } while (iVar2 != 4);
    iVar2 = (**(code **)(*(int *)this + 0xc4))(this,0);
    if (iVar2 != 0) {
      uVar6 = 0;
      do {
        while ((**(uint **)(this + 0xe4) >> (uVar6 & 0x1f) & 1) != 0) {
          uVar7 = uVar6 + 1;
          (**(code **)(*(int *)this + 0xd8))(this,uVar6);
          uVar6 = uVar7;
          if (uVar7 == 0x18) {
            return;
          }
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 != 0x18);
      return;
    }
  }
LAB_2e96743c:
  puts("\x1b[7m    ReloadSatList: Sat DB is not OK. Should be reloaded!       \x1b[0m");
  return;
}

