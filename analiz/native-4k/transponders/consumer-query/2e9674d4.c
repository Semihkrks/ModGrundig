
/* MW_DTV_FREQUENCYTABLE_DVBS_Customer::Init() */

void __thiscall MW_DTV_FREQUENCYTABLE_DVBS_Customer::Init(MW_DTV_FREQUENCYTABLE_DVBS_Customer *this)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  undefined4 local_18;
  
  uVar3 = mapi_interface_TV::Get_mapi_storage_dtv_cmdb_sat();
  *(undefined4 *)(this + 0x84) = uVar3;
  uVar3 = mapi_interface_TV::Get_mapi_storage_dtv_cmdb_sat_backup();
  *(undefined4 *)(this + 0x88) = uVar3;
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(this + 0x94);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(this + 0xac);
  pvVar4 = operator_new__(4,(nothrow_t *)&DAT_2c7f5bd0);
  *(void **)(this + 0xe4) = pvVar4;
  if (pvVar4 == (void *)0x0) {
    uVar3 = 0x6b8;
  }
  else {
    pvVar4 = operator_new__(0x178,(nothrow_t *)&DAT_2c7f5bd0);
    *(void **)(this + 0xf0) = pvVar4;
    if (pvVar4 != (void *)0x0) {
      *(undefined4 *)(this + 0xdc) = 0x10;
      *(undefined4 *)(this + 0xe0) = 4;
      *(undefined4 *)(this + 0xe8) = 0x14;
      *(undefined4 *)(this + 0xec) = 0x178;
      *(undefined4 *)(this + 0xf4) = 0x18c;
      *(undefined4 *)(this + 0xf8) = 0x20;
      *(undefined4 *)(this + 0xcc) = 0x1ac;
      *(undefined4 *)(this + 0xd0) = 0x660;
      *(undefined4 *)(this + 200) = 8;
      *(undefined4 *)(this + 0xd8) = 48000;
      *(undefined4 *)(this + 0xc4) = 8;
      *(undefined4 *)(this + 0xd4) = 0x80c;
      **(undefined4 **)(this + 0xe4) = 0;
      memset(*(void **)(this + 0xf0),0,0x178);
      *(undefined4 *)(this + 0x8c) = 0;
      *(undefined4 *)(this + 0x90) = 0;
      *(undefined4 *)(this + 0xf4) = 0;
      *(undefined4 *)(this + 0xf8) = 0;
      local_18 = 0;
      iVar5 = mapi_storage::Read(*(ulong *)(this + 0x84),(uchar *)0x0,(ulong)&local_18);
      if (iVar5 == 0) {
        puts("@@@@ Can not read version size. Reset sat DB @@@");
      }
      else {
        iVar5 = 0;
        pcVar7 = (char *)&local_18;
        do {
          pcVar8 = &_fdata + iVar5;
          iVar5 = iVar5 + 1;
          if (*pcVar7 != *pcVar8) {
            puts("@@@ Sat DB version check error, reset Sat DB@@@");
            goto LAB_2e967768;
          }
          pcVar7 = (char *)((int)&local_18 + iVar5);
        } while (iVar5 != 4);
        bVar1 = (**(code **)(*(int *)this + 0xc4))(this,0);
        bVar2 = (**(code **)(*(int *)this + 0xc4))(this,1);
        if ((bVar2 & bVar1) != 0) {
          uVar9 = 0;
          (**(code **)(*(int *)this + 0xcc))(this,this + 0x8c,this + 0x90);
          uVar6 = **(uint **)(this + 0xe4);
          while( true ) {
            if ((uVar6 & 1) != 0) {
              (**(code **)(*(int *)this + 0xd8))(this,uVar9);
            }
            if (uVar9 == 0x17) break;
            uVar9 = uVar9 + 1;
            uVar6 = **(uint **)(this + 0xe4) >> (uVar9 & 0x1f);
          }
          uVar9 = 0;
          do {
            if ((*(uint *)(*(int *)(this + 0xf0) + (uVar9 >> 5) * 4) >> (uVar9 & 0x1f) & 1) != 0) {
              (**(code **)(*(int *)this + 0xdc))(this,uVar9);
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 != 3000);
          return;
        }
      }
LAB_2e967768:
      puts("\x1b[7m    Sat DB is not OK. Should be reloaded!       \x1b[0m");
      (**(code **)(*(int *)this + 0x3c))(this);
      return;
    }
    uVar3 = 0x6ba;
  }
  printf("ASSERT FAIL: %s %s %d\n","./middleware/src/MW_DTV_FreqTable_DVBS_Customer.cpp",
         "virtual void MW_DTV_FREQUENCYTABLE_DVBS_Customer::Init()",uVar3);
                    /* WARNING: Subroutine does not return */
  abort();
}

