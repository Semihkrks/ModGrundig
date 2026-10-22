
undefined4 hwcrhk_init(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined *puVar12;
  undefined4 uVar13;
  undefined *puVar14;
  undefined *puVar15;
  undefined *puVar16;
  int iVar17;
  
  if (*(int *)(PTR_DAT_000249c8 + 0x4b34) == 0) {
    puVar12 = *(undefined **)(PTR_DAT_000249c8 + 0x4b4c);
    if (puVar12 == (undefined *)0x0) {
      puVar12 = PTR_000249d4 + 0x4304;
    }
    iVar2 = (*(code *)PTR_DSO_load_00024a84)(0,puVar12,0,0);
    puVar12 = PTR_DAT_000249c8;
    *(int *)(PTR_DAT_000249c8 + 0x4b34) = iVar2;
    if (iVar2 == 0) {
      uVar11 = 0x68;
      puVar12 = PTR_000249d4 + 0x428c;
      uVar13 = 0x22d;
    }
    else {
      iVar2 = (*(code *)PTR_DSO_bind_func_00024a14)
                        (iVar2,*(undefined4 *)(PTR_DAT_000249c8 + 0x47d8));
      if (((((iVar2 != 0) &&
            (iVar3 = (*(code *)PTR_DSO_bind_func_00024a14)
                               (*(undefined4 *)(puVar12 + 0x4b34),
                                *(undefined4 *)(PTR_DAT_000249c8 + 0x47dc)), iVar3 != 0)) &&
           (iVar4 = (*(code *)PTR_DSO_bind_func_00024a14)
                              (*(undefined4 *)(puVar12 + 0x4b34),
                               *(undefined4 *)(PTR_DAT_000249c8 + 0x47e0)), iVar4 != 0)) &&
          (((iVar5 = (*(code *)PTR_DSO_bind_func_00024a14)
                               (*(undefined4 *)(puVar12 + 0x4b34),
                                *(undefined4 *)(PTR_DAT_000249c8 + 0x47e4)), iVar5 != 0 &&
            (iVar6 = (*(code *)PTR_DSO_bind_func_00024a14)
                               (*(undefined4 *)(puVar12 + 0x4b34),
                                *(undefined4 *)(PTR_DAT_000249c8 + 0x47e8)), iVar6 != 0)) &&
           ((iVar7 = (*(code *)PTR_DSO_bind_func_00024a14)
                               (*(undefined4 *)(puVar12 + 0x4b34),
                                *(undefined4 *)(PTR_DAT_000249c8 + 0x47ec)), iVar7 != 0 &&
            ((iVar8 = (*(code *)PTR_DSO_bind_func_00024a14)
                                (*(undefined4 *)(puVar12 + 0x4b34),
                                 *(undefined4 *)(PTR_DAT_000249c8 + 0x47f0)), iVar8 != 0 &&
             (iVar9 = (*(code *)PTR_DSO_bind_func_00024a14)
                                (*(undefined4 *)(puVar12 + 0x4b34),
                                 *(undefined4 *)(PTR_DAT_000249c8 + 0x47f4)), iVar9 != 0)))))))) &&
         (iVar10 = (*(code *)PTR_DSO_bind_func_00024a14)
                             (*(undefined4 *)(puVar12 + 0x4b34),
                              *(undefined4 *)(PTR_DAT_000249c8 + 0x47f8)),
         puVar12 = PTR_DAT_000249c8, iVar10 != 0)) {
        iVar17 = *(int *)(PTR_DAT_000249c8 + 0x4b48);
        *(int *)(PTR_DAT_000249c8 + 0x4b50) = iVar2;
        *(int *)(puVar12 + 0x4b54) = iVar3;
        *(int *)(puVar12 + 0x4b1c) = iVar4;
        *(int *)(puVar12 + 0x4b24) = iVar5;
        *(int *)(puVar12 + 0x4b2c) = iVar6;
        *(int *)(puVar12 + 0x4b30) = iVar7;
        *(int *)(puVar12 + 0x4b20) = iVar8;
        *(int *)(puVar12 + 0x4b14) = iVar9;
        *(int *)(puVar12 + 0x4b28) = iVar10;
        if ((((iVar17 == 0) &&
             (iVar2 = (*(code *)PTR_CRYPTO_get_dynlock_create_callback_00024a44)(), iVar2 != 0)) &&
            (iVar2 = (*(code *)PTR_CRYPTO_get_dynlock_lock_callback_00024a5c)(), iVar2 != 0)) &&
           (iVar2 = (*(code *)PTR_CRYPTO_get_dynlock_destroy_callback_00024a34)(),
           puVar1 = PTR_DAT_000249c8, iVar2 != 0)) {
          puVar16 = PTR_000249d4 + 0x3ca8;
          puVar15 = PTR_000249d4 + 0x2478;
          puVar14 = PTR_000249d4 + 0x2450;
          *(undefined **)(PTR_DAT_000249c8 + 0x4990) = PTR_000249d4 + 0x3c90;
          *(undefined **)(puVar1 + 0x4984) = puVar16;
          *(undefined **)(puVar1 + 0x4988) = puVar15;
          *(undefined **)(puVar1 + 0x498c) = puVar14;
        }
        iVar2 = (*(code *)(PTR_000249d4 + 0x13b0))
                          (PTR_DAT_000249c8 + 0x4b10,PTR_DAT_000249c8 + 0x4b3c);
        puVar1 = PTR_DAT_000249c8;
        if (iVar2 != 0) {
          if (*(int *)(PTR_DAT_000249c8 + 0x4800) != -1) {
            return 1;
          }
          uVar11 = (*(code *)PTR_RSA_get_ex_new_index_00024a74)(0,PTR_000249d4 + 0x4310,0,0,0);
          *(undefined4 *)(puVar1 + 0x4800) = uVar11;
          return 1;
        }
        (*(code *)(PTR_000249d4 + 0x1434))(0x67,0x71,PTR_000249d4 + 0x428c,0x267);
        goto LAB_00013904;
      }
      uVar11 = 0x68;
      puVar12 = PTR_000249d4 + 0x428c;
      uVar13 = 0x244;
    }
  }
  else {
    uVar11 = 100;
    puVar12 = PTR_000249d4 + 0x428c;
    uVar13 = 0x227;
  }
  (*(code *)(PTR_000249d4 + 0x1434))(0x67,uVar11,puVar12,uVar13);
  puVar12 = PTR_DAT_000249c8;
LAB_00013904:
  if (*(int *)(PTR_DAT_000249c8 + 0x4b34) != 0) {
    (*(code *)PTR_DSO_free_00024a0c)();
  }
  puVar1 = PTR_DAT_000249c8;
  *(undefined4 *)(puVar12 + 0x4b50) = 0;
  *(undefined4 *)(puVar12 + 0x4b54) = 0;
  *(undefined4 *)(puVar1 + 0x4b34) = 0;
  *(undefined4 *)(puVar12 + 0x4b1c) = 0;
  *(undefined4 *)(puVar12 + 0x4b24) = 0;
  *(undefined4 *)(puVar12 + 0x4b2c) = 0;
  *(undefined4 *)(puVar12 + 0x4b30) = 0;
  *(undefined4 *)(puVar12 + 0x4b20) = 0;
  *(undefined4 *)(puVar12 + 0x4b28) = 0;
  *(undefined4 *)(puVar12 + 0x4b14) = 0;
  return 0;
}

