
int _dl_allocate_tls_init(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  uint local_30;
  
  puVar2 = PTR__rtld_global_2c02f038;
  if (param_1 == 0) {
    return 0;
  }
  puVar12 = *(uint **)(param_1 + -8);
  local_30 = 0;
  puVar11 = *(uint **)(PTR__rtld_global_2c02f038 + 0x638);
  uVar4 = *(uint *)(PTR__rtld_global_2c02f038 + 0x634);
  uVar10 = 0;
LAB_2c012a58:
  uVar5 = *puVar11;
  uVar8 = (uint)(local_30 == 0);
  if (uVar5 <= uVar8) goto LAB_2c012ba0;
  if (uVar8 + local_30 <= uVar4) {
    puVar9 = puVar11 + (uVar8 + 1) * 2 + 1;
    uVar4 = local_30 + 1 + uVar8;
    do {
      uVar7 = *puVar9;
      if (uVar7 == 0) {
LAB_2c012b10:
        if (uVar5 <= uVar8 + 1) goto LAB_2c012b98;
      }
      else {
        if (uVar10 < puVar9[-1]) {
          uVar10 = puVar9[-1];
        }
        if (1 < *(int *)(uVar7 + 0x30c) + 2U) {
          puVar6 = PTR_DAT_2c02f04c;
          if (*(uint *)(uVar7 + 0x310) == uVar8) {
            if (*(uint *)(uVar7 + 0x2fc) <= *(uint *)(uVar7 + 0x300)) {
              uVar5 = param_1 + *(int *)(uVar7 + 0x30c);
              puVar12[uVar8 * 2] = uVar5;
              puVar6 = PTR_FUN_2c02f150;
              *(undefined1 *)(puVar12 + *(int *)(uVar7 + 0x310) * 2 + 1) = 1;
              uVar3 = (*(code *)puVar6)(uVar5,*(undefined4 *)(uVar7 + 0x2f8),
                                        *(undefined4 *)(uVar7 + 0x2fc));
              (*(code *)PTR_LAB_2c02f17c)(uVar3,0,*(int *)(uVar7 + 0x300) - *(int *)(uVar7 + 0x2fc))
              ;
              uVar5 = *puVar11;
              goto LAB_2c012b10;
            }
            goto LAB_2c012c04;
          }
          goto LAB_2c012be4;
        }
        puVar12[*(int *)(uVar7 + 0x310) * 2] = 0xffffffff;
        *(undefined1 *)(puVar12 + *(int *)(uVar7 + 0x310) * 2 + 1) = 0;
        uVar5 = *puVar11;
        if (uVar5 <= uVar8 + 1) goto LAB_2c012b98;
      }
      uVar8 = uVar8 + 1;
      puVar9 = puVar9 + 2;
      bVar1 = *(uint *)(puVar2 + 0x634) < uVar4;
      uVar4 = uVar4 + 1;
      if (bVar1) break;
    } while( true );
  }
  goto LAB_2c012c28;
LAB_2c012b98:
  uVar8 = uVar8 + 1;
  uVar4 = *(uint *)(puVar2 + 0x634);
LAB_2c012ba0:
  local_30 = local_30 + uVar8;
  if (uVar4 <= local_30) goto LAB_2c012c28;
  puVar11 = (uint *)puVar11[1];
  if (puVar11 == (uint *)0x0) {
    puVar6 = PTR_DAT_2c02f04c + -0x2070;
    (*(code *)PTR_LAB_2c02f084)(puVar6,PTR_DAT_2c02f04c + -0x2124,0x1c2,PTR_DAT_2c02f04c + -0x1ebc);
LAB_2c012be4:
    (*(code *)PTR_LAB_2c02f084)
              (puVar6 + -0x20bc,PTR_DAT_2c02f04c + -0x2124,0x1aa,PTR_DAT_2c02f04c + -0x1ebc);
LAB_2c012c04:
    (*(code *)PTR_LAB_2c02f084)
              (PTR_DAT_2c02f04c + -0x20a4,PTR_DAT_2c02f04c + -0x2124,0x1ab,
               PTR_DAT_2c02f04c + -0x1ebc);
LAB_2c012c28:
    *puVar12 = uVar10;
    return param_1;
  }
  goto LAB_2c012a58;
}

