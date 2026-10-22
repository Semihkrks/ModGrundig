
undefined4 cswift_init(void)

{
  undefined *puVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined *puVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 local_30 [3];
  
  puVar1 = PTR_DAT_00023c78;
  if (*(int *)(PTR_DAT_00023c78 + 0x3da4) == 0) {
    puVar7 = *(undefined **)(PTR_DAT_00023c78 + 0x3da8);
    if (puVar7 == (undefined *)0x0) {
      puVar7 = PTR_00023c84 + 0x385c;
    }
    iVar2 = (*(code *)PTR_DSO_load_00023cf4)(0,puVar7,0,0);
    *(int *)(puVar1 + 0x3da4) = iVar2;
    puVar7 = PTR_DAT_00023c78;
    if (iVar2 == 0) {
      uVar8 = 0x195;
      puVar7 = PTR_00023c84 + 0x382c;
      uVar6 = 0x6a;
    }
    else {
      pcVar3 = (code *)(*(code *)PTR_DSO_bind_func_00023cb4)
                                 (iVar2,*(undefined4 *)(PTR_DAT_00023c78 + 0x3ae8));
      if ((((pcVar3 != (code *)0x0) &&
           (iVar2 = (*(code *)PTR_DSO_bind_func_00023cb4)
                              (*(undefined4 *)(puVar7 + 0x3da4),
                               *(undefined4 *)(PTR_DAT_00023c78 + 0x3aec)), iVar2 != 0)) &&
          (iVar4 = (*(code *)PTR_DSO_bind_func_00023cb4)
                             (*(undefined4 *)(puVar7 + 0x3da4),
                              *(undefined4 *)(PTR_DAT_00023c78 + 0x3af0)), iVar4 != 0)) &&
         (iVar5 = (*(code *)PTR_DSO_bind_func_00023cb4)
                            (*(undefined4 *)(puVar7 + 0x3da4),
                             *(undefined4 *)(PTR_DAT_00023c78 + 0x3af4)),
         puVar12 = (undefined4 *)PTR_p_CSwift_AcquireAccContext_00023d70,
         puVar9 = (undefined4 *)PTR_p_CSwift_ReleaseAccContext_00023d68,
         puVar10 = (undefined4 *)PTR_p_CSwift_SimpleRequest_00023d34,
         puVar11 = (undefined4 *)PTR_p_CSwift_AttachKeyParam_00023d18, iVar5 != 0)) {
        *(int *)PTR_p_CSwift_AttachKeyParam_00023d18 = iVar2;
        *puVar10 = iVar4;
        *puVar9 = iVar5;
        *puVar12 = pcVar3;
        iVar2 = (*pcVar3)(local_30);
        if (iVar2 == 0) {
          (*(code *)*puVar9)(local_30[0]);
          return 1;
        }
        (*(code *)(PTR_00023c84 + 0x10c8))(0x68,0x6c,PTR_00023c84 + 0x382c,0x1ac);
        goto LAB_000131e8;
      }
      uVar6 = 0x6a;
      puVar7 = PTR_00023c84 + 0x382c;
      uVar8 = 0x1a0;
    }
  }
  else {
    uVar6 = 100;
    puVar7 = PTR_00023c84 + 0x382c;
    uVar8 = 399;
  }
  (*(code *)(PTR_00023c84 + 0x10c8))(0x68,uVar6,puVar7,uVar8);
  puVar9 = (undefined4 *)PTR_p_CSwift_ReleaseAccContext_00023d68;
  puVar10 = (undefined4 *)PTR_p_CSwift_SimpleRequest_00023d34;
  puVar11 = (undefined4 *)PTR_p_CSwift_AttachKeyParam_00023d18;
  puVar12 = (undefined4 *)PTR_p_CSwift_AcquireAccContext_00023d70;
LAB_000131e8:
  if (*(int *)(puVar1 + 0x3da4) != 0) {
    (*(code *)PTR_DSO_free_00023cb0)();
    *(undefined4 *)(PTR_DAT_00023c78 + 0x3da4) = 0;
  }
  *puVar12 = 0;
  *puVar11 = 0;
  *puVar10 = 0;
  *puVar9 = 0;
  return 0;
}

