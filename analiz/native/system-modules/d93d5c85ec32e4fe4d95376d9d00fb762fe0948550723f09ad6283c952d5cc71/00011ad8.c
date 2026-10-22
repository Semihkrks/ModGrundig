
uint cswift_dsa_verify(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  undefined *puVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 local_88;
  int local_84;
  int local_80;
  int *local_7c;
  undefined1 auStack_78 [16];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  
  iVar1 = (*(code *)PTR_BN_CTX_new_00023cdc)();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  iVar2 = (**(code **)PTR_p_CSwift_AcquireAccContext_00023d70)(&local_88);
  if (iVar2 != 0) {
    (*(code *)(PTR_00023c84 + 0x10c8))(0x66,0x6c,PTR_00023c84 + 0x382c,0x393);
    uVar12 = 0xffffffff;
    goto LAB_00011e28;
  }
  (*(code *)PTR_BN_CTX_start_00023cc0)(iVar1);
  puVar3 = (undefined4 *)(*(code *)PTR_BN_CTX_get_00023cbc)(iVar1);
  puVar4 = (undefined4 *)(*(code *)PTR_BN_CTX_get_00023cbc)(iVar1);
  puVar5 = (undefined4 *)(*(code *)PTR_BN_CTX_get_00023cbc)(iVar1);
  puVar6 = (undefined4 *)(*(code *)PTR_BN_CTX_get_00023cbc)(iVar1);
  piVar7 = (int *)(*(code *)PTR_BN_CTX_get_00023cbc)(iVar1);
  if (piVar7 == (int *)0x0) {
    uVar11 = 0x39f;
    puVar10 = PTR_00023c84 + 0x382c;
    uVar13 = 0x66;
LAB_00011ea0:
    uVar12 = 0xffffffff;
    (*(code *)(PTR_00023c84 + 0x10c8))(0x66,uVar13,puVar10,uVar11);
  }
  else {
    if (((int)puVar3[2] < *(int *)(*(int *)(param_4 + 0xc) + 4)) &&
       (iVar2 = (*(code *)PTR_bn_expand2_00023ce4)(puVar3), iVar2 == 0)) {
LAB_00011e90:
      uVar13 = 0x67;
      puVar10 = PTR_00023c84 + 0x382c;
      uVar11 = 0x3a7;
      goto LAB_00011ea0;
    }
    if ((int)puVar4[2] < *(int *)(*(int *)(param_4 + 0x10) + 4)) {
      iVar2 = (*(code *)PTR_bn_expand2_00023ce4)(puVar4);
      if (iVar2 != 0) {
        if ((int)puVar5[2] < *(int *)(*(int *)(param_4 + 0x14) + 4)) goto LAB_00011f5c;
        goto LAB_00011c14;
      }
      goto LAB_00011e90;
    }
    if ((int)puVar5[2] < *(int *)(*(int *)(param_4 + 0x14) + 4)) {
LAB_00011f5c:
      iVar2 = (*(code *)PTR_bn_expand2_00023ce4)(puVar5);
      if (iVar2 == 0) goto LAB_00011e90;
      if (*(int *)(*(int *)(param_4 + 0x18) + 4) <= (int)puVar6[2]) goto LAB_00011c2c;
LAB_00011f84:
      iVar2 = (*(code *)PTR_bn_expand2_00023ce4)(puVar6);
      if (iVar2 == 0) goto LAB_00011e90;
      iVar2 = piVar7[2];
    }
    else {
LAB_00011c14:
      if ((int)puVar6[2] < *(int *)(*(int *)(param_4 + 0x18) + 4)) goto LAB_00011f84;
LAB_00011c2c:
      iVar2 = piVar7[2];
    }
    if ((iVar2 < 0x28) && (iVar2 = (*(code *)PTR_bn_expand2_00023ce4)(piVar7,0x28), iVar2 == 0))
    goto LAB_00011e90;
    local_58 = 3;
    local_54 = (*(code *)PTR_BN_bn2bin_00023d28)(*(undefined4 *)(param_4 + 0xc),*puVar3);
    local_50 = *puVar3;
    local_4c = (*(code *)PTR_BN_bn2bin_00023d28)(*(undefined4 *)(param_4 + 0x10),*puVar4);
    local_48 = *puVar4;
    local_44 = (*(code *)PTR_BN_bn2bin_00023d28)(*(undefined4 *)(param_4 + 0x14),*puVar5);
    local_40 = *puVar5;
    local_3c = (*(code *)PTR_BN_bn2bin_00023d28)(*(undefined4 *)(param_4 + 0x18),*puVar6);
    local_38 = *puVar6;
    iVar2 = (**(code **)PTR_p_CSwift_AttachKeyParam_00023d18)(local_88,&local_58);
    if (iVar2 == -0x2716) {
      uVar13 = 0x65;
      puVar10 = PTR_00023c84 + 0x382c;
      uVar11 = 0x3ba;
      goto LAB_00011ea0;
    }
    if (iVar2 == 0) {
      local_5c = *piVar7;
      local_60 = 0x28;
      local_68 = param_2;
      local_64 = param_1;
      (*(code *)PTR_memset_00023d30)(local_5c,0,0x28);
      iVar2 = local_5c;
      uVar13 = *param_3;
      iVar8 = (*(code *)PTR_BN_num_bits_00023d5c)(uVar13);
      iVar9 = iVar8 + 7;
      if (iVar8 + 7 < 0) {
        iVar9 = iVar8 + 0xe;
      }
      (*(code *)PTR_BN_bn2bin_00023d28)(uVar13,(iVar2 - (iVar9 >> 3)) + 0x14);
      iVar2 = local_5c;
      uVar13 = param_3[1];
      iVar8 = (*(code *)PTR_BN_num_bits_00023d5c)(uVar13);
      iVar9 = iVar8 + 7;
      if (iVar8 + 7 < 0) {
        iVar9 = iVar8 + 0xe;
      }
      (*(code *)PTR_BN_bn2bin_00023d28)(uVar13,(iVar2 - (iVar9 >> 3)) + 0x28);
      local_7c = &local_84;
      local_80 = 4;
      iVar2 = (**(code **)PTR_p_CSwift_SimpleRequest_00023d34)(local_88,4,&local_68,2,&local_80,1);
      if (iVar2 != 0) {
        uVar13 = 0x3d4;
        goto LAB_00011ed0;
      }
      uVar12 = (uint)(local_84 != 0);
    }
    else {
      uVar13 = 0x3bf;
LAB_00011ed0:
      (*(code *)(PTR_00023c84 + 0x10c8))(0x66,0x6b,PTR_00023c84 + 0x382c,uVar13);
      (*(code *)PTR_sprintf_00023d6c)(auStack_78,PTR_00023c84 + 0x3838,iVar2);
      uVar12 = 0xffffffff;
      (*(code *)PTR_ERR_add_error_data_00023c98)(2,PTR_00023c84 + 0x383c,auStack_78);
    }
  }
  (**(code **)PTR_p_CSwift_ReleaseAccContext_00023d68)(local_88);
LAB_00011e28:
  (*(code *)PTR_BN_CTX_end_00023ce8)(iVar1);
  (*(code *)PTR_BN_CTX_free_00023d24)(iVar1);
  return uVar12;
}

