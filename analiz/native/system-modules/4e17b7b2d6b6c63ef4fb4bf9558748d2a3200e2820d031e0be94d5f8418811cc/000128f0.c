
undefined4 ibm_4758_cca_init(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined *puVar11;
  
  puVar1 = PTR_DAT_00023418;
  if (*(int *)(PTR_DAT_00023418 + 0x3514) == 0) {
    puVar4 = *(undefined **)(PTR_DAT_00023418 + 0x3518);
    if (puVar4 == (undefined *)0x0) {
      puVar4 = PTR_00023424 + 0x3038;
    }
    iVar2 = (*(code *)PTR_DSO_load_00023494)(0,puVar4,0,0);
    *(int *)(puVar1 + 0x3514) = iVar2;
    puVar4 = PTR_DAT_00023418;
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_DSO_bind_func_00023454)
                        (iVar2,*(undefined4 *)(PTR_DAT_00023418 + 0x32f4));
      *(int *)(puVar4 + 0x351c) = iVar2;
      puVar11 = PTR_DAT_00023418;
      puVar6 = PTR_DAT_00023418;
      puVar7 = PTR_DAT_00023418;
      puVar8 = PTR_DAT_00023418;
      puVar9 = PTR_DAT_00023418;
      puVar10 = PTR_DAT_00023418;
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_DSO_bind_func_00023454)
                          (*(undefined4 *)(puVar4 + 0x3514),
                           *(undefined4 *)(PTR_DAT_00023418 + 0x32f8));
        *(int *)(puVar11 + 0x3534) = iVar2;
        puVar10 = PTR_DAT_00023418;
        puVar6 = PTR_DAT_00023418;
        puVar7 = PTR_DAT_00023418;
        puVar8 = PTR_DAT_00023418;
        puVar9 = PTR_DAT_00023418;
        if (iVar2 != 0) {
          iVar2 = (*(code *)PTR_DSO_bind_func_00023454)
                            (*(undefined4 *)(puVar4 + 0x3514),
                             *(undefined4 *)(PTR_DAT_00023418 + 0x32fc));
          *(int *)(puVar10 + 0x3520) = iVar2;
          puVar9 = PTR_DAT_00023418;
          puVar6 = PTR_DAT_00023418;
          puVar7 = PTR_DAT_00023418;
          puVar8 = PTR_DAT_00023418;
          if (iVar2 != 0) {
            iVar2 = (*(code *)PTR_DSO_bind_func_00023454)
                              (*(undefined4 *)(puVar4 + 0x3514),
                               *(undefined4 *)(PTR_DAT_00023418 + 0x3300));
            *(int *)(puVar9 + 0x3524) = iVar2;
            puVar8 = PTR_DAT_00023418;
            puVar6 = PTR_DAT_00023418;
            puVar7 = PTR_DAT_00023418;
            if (iVar2 != 0) {
              iVar2 = (*(code *)PTR_DSO_bind_func_00023454)
                                (*(undefined4 *)(puVar4 + 0x3514),
                                 *(undefined4 *)(PTR_DAT_00023418 + 0x3304));
              *(int *)(puVar8 + 0x3528) = iVar2;
              puVar7 = PTR_DAT_00023418;
              puVar6 = PTR_DAT_00023418;
              if (iVar2 != 0) {
                iVar2 = (*(code *)PTR_DSO_bind_func_00023454)
                                  (*(undefined4 *)(puVar4 + 0x3514),
                                   *(undefined4 *)(PTR_DAT_00023418 + 0x3308));
                *(int *)(puVar7 + 0x352c) = iVar2;
                puVar6 = PTR_DAT_00023418;
                if (iVar2 != 0) {
                  iVar2 = (*(code *)PTR_DSO_bind_func_00023454)
                                    (*(undefined4 *)(puVar4 + 0x3514),
                                     *(undefined4 *)(PTR_DAT_00023418 + 0x330c));
                  *(int *)(puVar6 + 0x3530) = iVar2;
                  if (iVar2 != 0) {
                    uVar3 = (*(code *)PTR_RSA_get_ex_new_index_00023488)
                                      (0,PTR_00023424 + 0x3044,0,0,PTR_00023424 + 0x152c);
                    *(undefined4 *)(PTR_DAT_00023418 + 0x3310) = uVar3;
                    return 1;
                  }
                }
              }
            }
          }
        }
      }
      (*(code *)(PTR_00023424 + 0x1554))(0x66,0x67,PTR_00023424 + 0x302c,0x135);
      goto LAB_00012978;
    }
    uVar5 = 0x122;
    uVar3 = 0x67;
  }
  else {
    uVar3 = 100;
    uVar5 = 0x11c;
  }
  (*(code *)(PTR_00023424 + 0x1554))(0x66,uVar3,PTR_00023424 + 0x302c,uVar5);
  puVar6 = PTR_DAT_00023418;
  puVar7 = PTR_DAT_00023418;
  puVar8 = PTR_DAT_00023418;
  puVar9 = PTR_DAT_00023418;
  puVar10 = PTR_DAT_00023418;
  puVar11 = PTR_DAT_00023418;
  puVar4 = PTR_DAT_00023418;
LAB_00012978:
  if (*(int *)(puVar1 + 0x3514) != 0) {
    (*(code *)PTR_DSO_free_0002344c)();
  }
  *(undefined4 *)(puVar1 + 0x3514) = 0;
  *(undefined4 *)(puVar4 + 0x351c) = 0;
  *(undefined4 *)(puVar10 + 0x3520) = 0;
  *(undefined4 *)(puVar9 + 0x3524) = 0;
  *(undefined4 *)(puVar8 + 0x3528) = 0;
  *(undefined4 *)(puVar7 + 0x352c) = 0;
  *(undefined4 *)(puVar6 + 0x3530) = 0;
  *(undefined4 *)(puVar11 + 0x3534) = 0;
  return 0;
}

