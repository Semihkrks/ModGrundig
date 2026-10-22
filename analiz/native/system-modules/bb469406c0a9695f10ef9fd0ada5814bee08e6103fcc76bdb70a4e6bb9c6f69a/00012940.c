
undefined4 ubsec_init(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined *puVar15;
  undefined *local_34;
  
  if (*(int *)(PTR_DAT_000237a8 + 0x3890) == 0) {
    puVar15 = *(undefined **)(PTR_DAT_000237a8 + 0x38c0);
    if (puVar15 == (undefined *)0x0) {
      puVar15 = PTR_000237b4 + 0x3274;
    }
    iVar2 = (*(code *)PTR_DSO_load_0002381c)(0,puVar15,0,0);
    puVar15 = PTR_DAT_000237a8;
    *(int *)(PTR_DAT_000237a8 + 0x3890) = iVar2;
    if (iVar2 == 0) {
      (*(code *)(PTR_000237b4 + 0xef0))(0x69,0x67,PTR_000237b4 + 0x325c,0x19e);
      local_34 = PTR_DAT_000237a8;
    }
    else {
      iVar2 = (*(code *)PTR_DSO_bind_func_000237e4)
                        (iVar2,*(undefined4 *)(PTR_DAT_000237a8 + 0x35f8));
      if ((((((iVar2 == 0) ||
             (iVar3 = (*(code *)PTR_DSO_bind_func_000237e4)
                                (*(undefined4 *)(puVar15 + 0x3890),
                                 *(undefined4 *)(PTR_DAT_000237a8 + 0x35fc)), iVar3 == 0)) ||
            (pcVar4 = (code *)(*(code *)PTR_DSO_bind_func_000237e4)
                                        (*(undefined4 *)(puVar15 + 0x3890),
                                         *(undefined4 *)(PTR_DAT_000237a8 + 0x3600)),
            pcVar4 == (code *)0x0)) ||
           (((iVar5 = (*(code *)PTR_DSO_bind_func_000237e4)
                                (*(undefined4 *)(puVar15 + 0x3890),
                                 *(undefined4 *)(PTR_DAT_000237a8 + 0x3604)), iVar5 == 0 ||
             (iVar6 = (*(code *)PTR_DSO_bind_func_000237e4)
                                (*(undefined4 *)(puVar15 + 0x3890),
                                 *(undefined4 *)(PTR_DAT_000237a8 + 0x3608)), iVar6 == 0)) ||
            ((iVar7 = (*(code *)PTR_DSO_bind_func_000237e4)
                                (*(undefined4 *)(puVar15 + 0x3890),
                                 *(undefined4 *)(PTR_DAT_000237a8 + 0x360c)), iVar7 == 0 ||
             ((iVar8 = (*(code *)PTR_DSO_bind_func_000237e4)
                                 (*(undefined4 *)(puVar15 + 0x3890),
                                  *(undefined4 *)(PTR_DAT_000237a8 + 0x3610)), iVar8 == 0 ||
              (iVar9 = (*(code *)PTR_DSO_bind_func_000237e4)
                                 (*(undefined4 *)(puVar15 + 0x3890),
                                  *(undefined4 *)(PTR_DAT_000237a8 + 0x3614)), iVar9 == 0)))))))) ||
          (iVar10 = (*(code *)PTR_DSO_bind_func_000237e4)
                              (*(undefined4 *)(puVar15 + 0x3890),
                               *(undefined4 *)(PTR_DAT_000237a8 + 0x3618)),
          puVar15 = PTR_DAT_000237a8, iVar10 == 0)) ||
         ((((iVar11 = (*(code *)PTR_DSO_bind_func_000237e4)
                                (*(undefined4 *)(PTR_DAT_000237a8 + 0x3890),
                                 *(undefined4 *)(PTR_DAT_000237a8 + 0x361c)), iVar11 == 0 ||
            (iVar12 = (*(code *)PTR_DSO_bind_func_000237e4)
                                (*(undefined4 *)(puVar15 + 0x3890),
                                 *(undefined4 *)(PTR_DAT_000237a8 + 0x3620)), iVar12 == 0)) ||
           (iVar13 = (*(code *)PTR_DSO_bind_func_000237e4)
                               (*(undefined4 *)(puVar15 + 0x3890),
                                *(undefined4 *)(PTR_DAT_000237a8 + 0x3624)), iVar13 == 0)) ||
          (iVar14 = (*(code *)PTR_DSO_bind_func_000237e4)
                              (*(undefined4 *)(puVar15 + 0x3890),
                               *(undefined4 *)(PTR_DAT_000237a8 + 0x3628)),
          puVar15 = PTR_DAT_000237a8, iVar14 == 0)))) {
        (*(code *)(PTR_000237b4 + 0xef0))(0x69,0x67,PTR_000237b4 + 0x325c,0x1c2);
        local_34 = PTR_DAT_000237a8;
      }
      else {
        local_34 = PTR_DAT_000237a8;
        *(int *)(PTR_DAT_000237a8 + 0x38b0) = iVar2;
        puVar1 = PTR_000237b4;
        *(int *)(puVar15 + 0x38a4) = iVar7;
        *(int *)(puVar15 + 0x38b8) = iVar10;
        *(int *)(puVar15 + 0x38a8) = iVar3;
        *(int *)(puVar15 + 0x389c) = iVar5;
        *(int *)(puVar15 + 0x38ac) = iVar6;
        *(int *)(puVar15 + 0x3898) = iVar8;
        *(int *)(puVar15 + 0x38bc) = iVar9;
        *(int *)(puVar15 + 0x38b4) = iVar11;
        *(int *)(puVar15 + 0x38c4) = iVar12;
        *(int *)(puVar15 + 0x38c8) = iVar13;
        *(int *)(puVar15 + 0x38cc) = iVar14;
        *(code **)(puVar15 + 0x3894) = pcVar4;
        iVar2 = (*pcVar4)(puVar1 + 0x3268);
        if ((0 < iVar2) &&
           (iVar3 = (**(code **)(puVar15 + 0x38cc))(iVar2,PTR_DAT_000237a8 + 0x3630), iVar3 == 0)) {
          (**(code **)(puVar15 + 0x389c))(iVar2);
          return 1;
        }
        (*(code *)(PTR_000237b4 + 0xef0))(0x69,0x6c,PTR_000237b4 + 0x325c,0x1e1);
      }
    }
  }
  else {
    (*(code *)(PTR_000237b4 + 0xef0))(0x69,100,PTR_000237b4 + 0x325c,0x196);
    local_34 = PTR_DAT_000237a8;
  }
  if (*(int *)(PTR_DAT_000237a8 + 0x3890) != 0) {
    (*(code *)PTR_DSO_free_000237e0)();
  }
  *(undefined4 *)(PTR_DAT_000237a8 + 0x3890) = 0;
  *(undefined4 *)(local_34 + 0x38b0) = 0;
  *(undefined4 *)(local_34 + 0x38a8) = 0;
  *(undefined4 *)(local_34 + 0x3894) = 0;
  *(undefined4 *)(local_34 + 0x389c) = 0;
  *(undefined4 *)(local_34 + 0x38ac) = 0;
  *(undefined4 *)(local_34 + 0x38a4) = 0;
  *(undefined4 *)(local_34 + 0x3898) = 0;
  *(undefined4 *)(local_34 + 0x38bc) = 0;
  *(undefined4 *)(local_34 + 0x38b8) = 0;
  *(undefined4 *)(local_34 + 0x38b4) = 0;
  *(undefined4 *)(local_34 + 0x38c4) = 0;
  *(undefined4 *)(local_34 + 0x38c8) = 0;
  *(undefined4 *)(local_34 + 0x38cc) = 0;
  return 0;
}

