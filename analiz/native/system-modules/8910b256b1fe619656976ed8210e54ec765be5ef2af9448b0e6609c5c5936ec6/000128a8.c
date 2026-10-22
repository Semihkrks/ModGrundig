
undefined4 aep_init(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined *puVar10;
  undefined4 uVar11;
  
  puVar1 = PTR_DAT_00023328;
  if (*(int *)(PTR_DAT_00023328 + 0x3430) == 0) {
    puVar10 = *(undefined **)(PTR_DAT_00023328 + 0x3438);
    if (puVar10 == (undefined *)0x0) {
      puVar10 = PTR_00023334 + 0x2e84;
    }
    iVar2 = (*(code *)PTR_DSO_load_00023398)(0,puVar10,0,0);
    *(int *)(puVar1 + 0x3430) = iVar2;
    puVar10 = PTR_DAT_00023328;
    if (iVar2 == 0) {
      uVar11 = 0x1d3;
      puVar10 = PTR_00023334 + 0x2e7c;
      uVar9 = 0x6f;
    }
    else {
      iVar2 = (*(code *)PTR_DSO_bind_func_00023368)
                        (iVar2,*(undefined4 *)(PTR_DAT_00023328 + 0x3184));
      if ((((iVar2 != 0) &&
           (iVar3 = (*(code *)PTR_DSO_bind_func_00023368)
                              (*(undefined4 *)(puVar10 + 0x3430),
                               *(undefined4 *)(PTR_DAT_00023328 + 0x3188)), iVar3 != 0)) &&
          (iVar4 = (*(code *)PTR_DSO_bind_func_00023368)
                             (*(undefined4 *)(puVar10 + 0x3430),
                              *(undefined4 *)(PTR_DAT_00023328 + 0x318c)), iVar4 != 0)) &&
         (((iVar5 = (*(code *)PTR_DSO_bind_func_00023368)
                              (*(undefined4 *)(puVar10 + 0x3430),
                               *(undefined4 *)(PTR_DAT_00023328 + 0x3190)), iVar5 != 0 &&
           (iVar6 = (*(code *)PTR_DSO_bind_func_00023368)
                              (*(undefined4 *)(puVar10 + 0x3430),
                               *(undefined4 *)(PTR_DAT_00023328 + 0x3194)), iVar6 != 0)) &&
          ((iVar7 = (*(code *)PTR_DSO_bind_func_00023368)
                              (*(undefined4 *)(puVar10 + 0x3430),
                               *(undefined4 *)(PTR_DAT_00023328 + 0x3198)), iVar7 != 0 &&
           (iVar8 = (*(code *)PTR_DSO_bind_func_00023368)
                              (*(undefined4 *)(puVar10 + 0x3430),
                               *(undefined4 *)(PTR_DAT_00023328 + 0x319c)),
           puVar10 = PTR_DAT_00023328, iVar8 != 0)))))) {
        *(int *)(PTR_DAT_00023328 + 0x3410) = iVar2;
        *(int *)(puVar10 + 0x3434) = iVar3;
        puVar1 = PTR_DAT_00023328;
        *(int *)(puVar10 + 0x3418) = iVar4;
        *(int *)(puVar1 + 0x341c) = iVar5;
        *(int *)(puVar1 + 0x3424) = iVar6;
        *(int *)(puVar1 + 0x3420) = iVar7;
        *(int *)(puVar1 + 0x3428) = iVar8;
        return 1;
      }
      uVar9 = 0x6f;
      puVar10 = PTR_00023334 + 0x2e7c;
      uVar11 = 0x1e1;
    }
  }
  else {
    uVar9 = 100;
    puVar10 = PTR_00023334 + 0x2e7c;
    uVar11 = 0x1cb;
  }
  (*(code *)(PTR_00023334 + 0x15e4))(0x67,uVar9,puVar10,uVar11);
  if (*(int *)(puVar1 + 0x3430) != 0) {
    (*(code *)PTR_DSO_free_00023364)();
  }
  puVar10 = PTR_DAT_00023328;
  *(undefined4 *)(puVar1 + 0x3430) = 0;
  *(undefined4 *)(puVar10 + 0x3424) = 0;
  *(undefined4 *)(puVar10 + 0x3410) = 0;
  *(undefined4 *)(puVar10 + 0x3434) = 0;
  *(undefined4 *)(puVar10 + 0x341c) = 0;
  *(undefined4 *)(puVar10 + 0x3418) = 0;
  *(undefined4 *)(puVar10 + 0x3420) = 0;
  *(undefined4 *)(puVar10 + 0x3428) = 0;
  return 0;
}

