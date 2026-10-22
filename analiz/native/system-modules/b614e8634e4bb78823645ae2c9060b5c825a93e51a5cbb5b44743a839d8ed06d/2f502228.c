
void HAL_PWS_Init(uint param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined *puVar5;
  char *pcVar6;
  short *psVar7;
  char *pcVar8;
  
  if (param_1 < 4) {
    *(uint *)PTR_SelectVifTable_2f513d6c = param_1;
  }
  else {
    *(undefined4 *)PTR_SelectVifTable_2f513d6c = 2;
  }
  puVar2 = PTR_PWS_RegCBinfo_2f513dd8;
  *(undefined2 *)PTR_u16OutOfRange_PWS_Items_2f513db0 = 0x43;
  puVar5 = PTR_PWS_flag_2f513df4;
  puVar1 = PTR_u16PWS_First_Items_2f513dc8;
  *(undefined4 *)(puVar2 + 0x28) = 4;
  puVar2[0x2c] = 10;
  *(undefined4 *)(puVar2 + 0x4c) = 0;
  *(undefined2 *)puVar1 = 0;
  *(undefined4 *)puVar2 = 4;
  puVar2[4] = 10;
  *(undefined4 *)(puVar2 + 0x24) = 0;
  puVar3 = puVar5 + 0x43;
  do {
    *puVar5 = 1;
    puVar5 = puVar5 + 1;
  } while (puVar3 != puVar5);
  pcVar6 = PTR___DT_MIPS_BASE_ADDRESS_2f513d24 + 0x3c35;
  psVar7 = (short *)(PTR___DT_MIPS_BASE_ADDRESS_2f513d24 + 0x3ca8);
  pcVar8 = PTR___DT_MIPS_BASE_ADDRESS_2f513d24 + 0x3cad;
  do {
    if (*pcVar6 == '\x01') {
      uVar4 = 0;
      if (*psVar7 != 0) goto LAB_2f502330;
      (*(code *)PTR_HAL_PWS_WriteByteMask_2f513e08)(*(undefined4 *)(pcVar6 + -5),0xff,pcVar6[-1]);
    }
    else {
      uVar4 = 0xff;
      if (*psVar7 == 0) {
        (*(code *)PTR_HAL_PWS_WriteByteMask_2f513e08)(*(undefined4 *)(pcVar6 + -5),0,pcVar6[-1]);
      }
      else {
LAB_2f502330:
        (*(code *)PTR_HAL_PWS_WriteByteMask_2f513e08)(*(undefined4 *)(pcVar6 + -5),uVar4,pcVar6[-1])
        ;
      }
    }
    pcVar6 = pcVar6 + 0x28;
    psVar7 = psVar7 + 1;
    if (pcVar8 == pcVar6) {
      return;
    }
  } while( true );
}

