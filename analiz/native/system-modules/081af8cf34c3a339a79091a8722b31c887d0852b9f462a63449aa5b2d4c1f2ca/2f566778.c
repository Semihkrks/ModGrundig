
undefined4 MDrv_SC_SetPowerState(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  puVar5 = PTR__scInfo_2f5785b8;
  puVar4 = PTR_DAT_2f578508;
  if (param_1 == 1) {
    if (PTR__scInfo_2f5785b8[0x3a] == '\x01') {
      (*(code *)PTR_printf_2f57858c)
                (PTR___DT_MIPS_BASE_ADDRESS_2f578514 + 0x7a3c,
                 PTR___DT_MIPS_BASE_ADDRESS_2f578514 + 0x7aa8,0x152d,1);
      puVar6 = PTR_MDrv_SC_Close_2f578600;
      puVar4 = PTR_DAT_2f578508;
      uVar7 = *(undefined4 *)(puVar5 + 0x460);
      uVar8 = *(undefined4 *)(puVar5 + 0x40);
      uVar1 = puVar5[0x44];
      uVar9 = *(undefined4 *)(puVar5 + 0x48);
      uVar3 = *(undefined2 *)(puVar5 + 0x4e);
      uVar2 = puVar5[0x54];
      PTR_DAT_2f578508[-0x79b0] = *puVar5;
      *(undefined4 *)(puVar4 + -0x79ac) = uVar8;
      puVar4[-0x79a8] = uVar1;
      *(undefined4 *)(puVar4 + -0x79a4) = uVar9;
      *(undefined2 *)(puVar4 + -0x79a0) = uVar3;
      puVar4[-0x7998] = uVar2;
      *(undefined4 *)(puVar4 + -0x799c) = 0;
      *(undefined4 *)(puVar4 + -0x7970) = uVar7;
      (*(code *)puVar6)(0);
      (*(code *)PTR_MDrv_SC_Exit_2f578584)(0);
      *(undefined4 *)(PTR_DAT_2f578508 + -0x7b54) = 1;
      return 0;
    }
  }
  else {
    if (param_1 != 2) {
      (*(code *)PTR_printf_2f57858c)
                (PTR___DT_MIPS_BASE_ADDRESS_2f578514 + 0x7a90,
                 PTR___DT_MIPS_BASE_ADDRESS_2f578514 + 0x7aa8,0x154f,param_1);
      return 1;
    }
    if (*(int *)(PTR_DAT_2f578508 + -0x7b54) != 1) {
      (*(code *)PTR_printf_2f57858c)
                (PTR___DT_MIPS_BASE_ADDRESS_2f578514 + 0x7a58,
                 PTR___DT_MIPS_BASE_ADDRESS_2f578514 + 0x7aa8,0x1549);
      return 1;
    }
    (*(code *)PTR_printf_2f57858c)
              (PTR___DT_MIPS_BASE_ADDRESS_2f578514 + 0x7a3c,
               PTR___DT_MIPS_BASE_ADDRESS_2f578514 + 0x7aa8,0x1541,2);
    (*(code *)PTR_MDrv_SC_Init_2f578590)(0);
    (*(code *)PTR_MDrv_SC_Open_2f5785d4)
              (0,PTR_DAT_2f578508[-0x79b0],PTR_DAT_2f578508 + -0x79b0,
               *(undefined4 *)(PTR_DAT_2f578508 + -0x7970));
    *(undefined4 *)(puVar4 + -0x7b54) = 2;
  }
  return 0;
}

