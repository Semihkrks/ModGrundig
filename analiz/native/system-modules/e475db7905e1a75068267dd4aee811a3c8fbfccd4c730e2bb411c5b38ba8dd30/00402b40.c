
undefined4 print_txpower_info(undefined4 param_1,undefined *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  code *pcVar7;
  undefined1 auStack_290 [16];
  undefined *local_280;
  char local_27c;
  char local_27b;
  ushort local_27a;
  undefined1 auStack_270 [242];
  ushort local_17e;
  byte local_17c;
  undefined4 local_178 [8];
  byte local_158;
  
  iVar1 = (*(code *)PTR_iw_get_range_info_004167e8)(param_1,param_2,auStack_270);
  if ((iVar1 < 0) || (local_158 < 10)) {
    puVar3 = *(undefined **)PTR_DAT_004167e4;
    local_280 = PTR___DT_MIPS_BASE_ADDRESS_0041676c + 0x5748;
    pcVar7 = (code *)PTR_fprintf_004167b8;
  }
  else {
    if ((byte)(local_17c - 1) < 8) {
      puVar5 = local_178;
      (*(code *)PTR_printf_004167cc)(PTR___DT_MIPS_BASE_ADDRESS_0041676c + 0x57a4,param_2);
      puVar6 = PTR___DT_MIPS_BASE_ADDRESS_0041676c + 0x57e4;
      puVar3 = PTR___DT_MIPS_BASE_ADDRESS_0041676c + 0x57d0;
      for (iVar1 = 0; iVar1 < (int)(uint)local_17c; iVar1 = iVar1 + 1) {
        if ((local_17e & 2) == 0) {
          uVar4 = *puVar5;
          if ((local_17e & 1) == 0) {
            uVar2 = (*(code *)PTR_iw_dbm2mwatt_00416808)(uVar4);
          }
          else {
            uVar4 = (*(code *)PTR_iw_mwatt2dbm_00416788)(uVar4);
            uVar2 = *puVar5;
          }
          (*(code *)PTR_printf_004167cc)(puVar6,uVar4,uVar2);
        }
        else {
          (*(code *)PTR_printf_004167cc)(puVar3,*puVar5);
        }
        puVar5 = puVar5 + 1;
      }
    }
    else {
      (*(code *)PTR_printf_004167cc)(PTR___DT_MIPS_BASE_ADDRESS_0041676c + 0x5774,param_2);
    }
    (*(code *)PTR_strncpy_00416818)(auStack_290,param_2,0x10);
    iVar1 = (*(code *)PTR_ioctl_004167f0)(param_1,0x8b27,auStack_290);
    if (iVar1 < 0) {
      return 0;
    }
    (*(code *)PTR_printf_004167cc)(PTR___DT_MIPS_BASE_ADDRESS_0041676c + 0x57fc);
    if (local_27b != '\0') {
      (*(code *)PTR_puts_004167a8)(PTR___DT_MIPS_BASE_ADDRESS_0041676c + 0x5818);
      return 0;
    }
    uVar4 = 0x3d;
    if (local_27c == '\0') {
      uVar4 = 0x3a;
    }
    (*(code *)PTR_putchar_00416814)(uVar4);
    if ((local_27a & 2) != 0) {
      (*(code *)PTR_printf_004167cc)(PTR___DT_MIPS_BASE_ADDRESS_0041676c + 0x57d0,local_280);
      return 0;
    }
    if ((local_27a & 1) == 0) {
      param_2 = (undefined *)(*(code *)PTR_iw_dbm2mwatt_00416808)();
    }
    else {
      puVar3 = (undefined *)(*(code *)PTR_iw_mwatt2dbm_00416788)();
      param_2 = local_280;
      local_280 = puVar3;
    }
    puVar3 = PTR___DT_MIPS_BASE_ADDRESS_0041676c + 0x5820;
    pcVar7 = (code *)PTR_printf_004167cc;
  }
  (*pcVar7)(puVar3,local_280,param_2);
  return 0;
}

