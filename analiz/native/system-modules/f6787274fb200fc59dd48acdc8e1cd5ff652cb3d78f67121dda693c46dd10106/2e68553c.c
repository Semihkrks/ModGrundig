
void MDrv_BW_LoadInitTable(void)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined *local_38;
  undefined1 local_34;
  undefined1 local_33;
  undefined4 local_30 [4];
  undefined2 local_20 [12];
  
  puVar6 = (undefined4 *)(PTR_DAT_2e6ccdcc + -0x4aac);
  local_34 = 1;
  local_33 = 0;
  local_38 = PTR_BWTABLE_COM_2e6cdeac;
  puVar7 = local_30;
  do {
    uVar1 = *puVar6;
    uVar3 = puVar6[1];
    uVar4 = puVar6[2];
    uVar5 = puVar6[3];
    puVar6 = puVar6 + 4;
    *puVar7 = uVar1;
    puVar7[1] = uVar3;
    puVar7[2] = uVar4;
    puVar7[3] = uVar5;
    puVar7 = puVar7 + 4;
  } while (puVar6 != (undefined4 *)(PTR_DAT_2e6ccdcc + -0x4a8c));
  *(undefined2 *)puVar7 = *(undefined2 *)puVar6;
  puVar2 = (undefined *)(*(code *)PTR_Open_bandwidthtable_Bin_2e6ce094)(local_30);
  if (puVar2 != (undefined *)0x0) {
    local_38 = puVar2;
    (*(code *)PTR_puts_2e6cd450)(PTR_DAT_2e6ccdcc + -0x4ac4);
  }
  (*(code *)(PTR_LAB_2e6ccdc8 + 0x4d30))(&local_38);
  (*(code *)PTR_free_2e6ce1cc)(puVar2);
  (*(code *)(PTR_LAB_2e6ccdc8 + 0x52c4))(0xc);
  return;
}

