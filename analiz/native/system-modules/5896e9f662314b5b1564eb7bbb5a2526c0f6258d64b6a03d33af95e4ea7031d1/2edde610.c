
/* MW_DTV_Scan_DVBC::StartAutoUpdateScan(EN_DTV_AUTO_UPDATE_TYPE) */

bool MW_DTV_Scan_DVBC::StartAutoUpdateScan(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined2 local_10;
  
  if (*(char *)(param_1 + 0xc) == '\0') {
    (*(code *)PTR_puts_2edf486c)(PTR_typeinfo_name_2edf4558 + -0x580);
    uVar2 = 0x247;
    goto LAB_2edde6d0;
  }
  if (*(char *)(param_1 + 0x4a) != '\0') {
    local_30 = PTR_vtable_2edf5128 + 8;
    local_18 = 2;
    local_14 = 0xc;
    local_28 = 1;
    local_2c = 6;
    local_20 = 0;
    local_10 = 0;
    local_24 = 0;
    local_1c = 0;
                    /* try { // try from 2edde684 to 2edde68b has its CatchHandler @ 2edde720 */
    iVar1 = (*(code *)PTR_Send_2edf4768)(*(undefined4 *)(param_1 + 0x58),&local_30,0);
    return iVar1 == 0;
  }
  do {
    (*(code *)PTR_puts_2edf486c)(PTR_typeinfo_name_2edf4558 + -0x5c4);
    uVar2 = 0x248;
LAB_2edde6d0:
    (*(code *)PTR_printf_2edf48ec)
              (PTR_typeinfo_name_2edf4558 + -0x13d4,PTR_typeinfo_name_2edf4558 + -0x878,
               PTR_typeinfo_name_2edf4558 + 0x280,uVar2);
    (*(code *)PTR_abort_2edf46f0)();
  } while( true );
}

