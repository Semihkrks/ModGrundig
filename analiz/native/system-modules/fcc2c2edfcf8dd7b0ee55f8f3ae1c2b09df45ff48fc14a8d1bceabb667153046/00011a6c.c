
undefined4 atalla_init(void)

{
  undefined *puVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined4 uVar7;
  undefined1 auStack_1020 [4100];
  
  puVar1 = PTR_DAT_000223f8;
  if (*(int *)(PTR_DAT_000223f8 + 0x24e0) == 0) {
    puVar6 = *(undefined **)(PTR_DAT_000223f8 + 0x24ec);
    if (puVar6 == (undefined *)0x0) {
      puVar6 = PTR_00022404 + 0x2088;
    }
    iVar2 = (*(code *)PTR_DSO_load_00022470)(0,puVar6,0,0);
    *(int *)(puVar1 + 0x24e0) = iVar2;
    puVar6 = PTR_DAT_000223f8;
    if (iVar2 == 0) {
      uVar7 = 0x17f;
      puVar6 = PTR_00022404 + 0x207c;
      uVar5 = 0x69;
    }
    else {
      pcVar3 = (code *)(*(code *)PTR_DSO_bind_func_00022434)
                                 (iVar2,*(undefined4 *)(PTR_DAT_000223f8 + 0x22ac));
      if (((pcVar3 != (code *)0x0) &&
          (iVar2 = (*(code *)PTR_DSO_bind_func_00022434)
                             (*(undefined4 *)(puVar6 + 0x24e0),
                              *(undefined4 *)(PTR_DAT_000223f8 + 0x22b0)), iVar2 != 0)) &&
         (iVar4 = (*(code *)PTR_DSO_bind_func_00022434)
                            (*(undefined4 *)(puVar6 + 0x24e0),
                             *(undefined4 *)(PTR_DAT_000223f8 + 0x22b4)), puVar6 = PTR_DAT_000223f8,
         iVar4 != 0)) {
        *(code **)(PTR_DAT_000223f8 + 0x24f0) = pcVar3;
        *(int *)(puVar6 + 0x24e4) = iVar2;
        *(int *)(puVar6 + 0x24f4) = iVar4;
        iVar2 = (*pcVar3)(0,auStack_1020);
        if (iVar2 == 0) {
          return 1;
        }
        (*(code *)(PTR_00022404 + 0xe60))(0x66,0x6b,PTR_00022404 + 0x207c,0x194);
        goto LAB_00011adc;
      }
      uVar5 = 0x69;
      puVar6 = PTR_00022404 + 0x207c;
      uVar7 = 0x189;
    }
  }
  else {
    uVar5 = 100;
    puVar6 = PTR_00022404 + 0x207c;
    uVar7 = 0x170;
  }
  (*(code *)(PTR_00022404 + 0xe60))(0x66,uVar5,puVar6,uVar7);
  puVar6 = PTR_DAT_000223f8;
LAB_00011adc:
  if (*(int *)(puVar1 + 0x24e0) != 0) {
    (*(code *)PTR_DSO_free_00022430)();
  }
  *(undefined4 *)(puVar1 + 0x24e0) = 0;
  *(undefined4 *)(puVar6 + 0x24f0) = 0;
  *(undefined4 *)(puVar6 + 0x24e4) = 0;
  *(undefined4 *)(puVar6 + 0x24f4) = 0;
  return 0;
}

