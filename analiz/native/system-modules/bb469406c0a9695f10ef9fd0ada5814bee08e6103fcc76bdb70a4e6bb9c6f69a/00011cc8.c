
undefined4 ubsec_dsa_verify(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 local_60;
  undefined4 local_5c [2];
  int local_54;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  code *local_34;
  undefined4 *local_30;
  
  local_30 = local_5c;
  (*(code *)PTR_BN_init_0002386c)(local_30);
  iVar6 = *(int *)(param_4 + 0xc);
  if (local_54 < *(int *)(iVar6 + 4)) {
    iVar6 = (*(code *)PTR_bn_expand2_0002380c)(local_30);
    if (iVar6 == 0) {
      (*(code *)(PTR_000237b4 + 0xef0))(0x67,0x65,PTR_000237b4 + 0x325c,0x350);
      uVar1 = 0;
      goto LAB_00011ed8;
    }
    iVar6 = *(int *)(param_4 + 0xc);
  }
  local_60 = (*(code *)PTR_BN_num_bits_00023868)(iVar6);
  local_48 = (**(code **)(PTR_DAT_000237a8 + 0x38b0))(param_1,param_2);
  iVar6 = (**(code **)(PTR_DAT_000237a8 + 0x3894))(PTR_000237b4 + 0x3268);
  if (iVar6 < 1) {
    (*(code *)(PTR_000237b4 + 0xef0))(0x67,0x6c,PTR_000237b4 + 0x325c,0x35b);
  }
  else {
    local_38 = **(undefined4 **)(param_4 + 0xc);
    local_34 = *(code **)(PTR_DAT_000237a8 + 0x38b4);
    local_3c = (*(code *)PTR_BN_num_bits_00023868)(*(undefined4 **)(param_4 + 0xc));
    local_40 = **(undefined4 **)(param_4 + 0x10);
    local_44 = (*(code *)PTR_BN_num_bits_00023868)(*(undefined4 **)(param_4 + 0x10));
    uVar10 = **(undefined4 **)(param_4 + 0x14);
    uVar1 = (*(code *)PTR_BN_num_bits_00023868)(*(undefined4 **)(param_4 + 0x14));
    uVar9 = **(undefined4 **)(param_4 + 0x18);
    uVar2 = (*(code *)PTR_BN_num_bits_00023868)(*(undefined4 **)(param_4 + 0x18));
    uVar8 = *(undefined4 *)*param_3;
    uVar3 = (*(code *)PTR_BN_num_bits_00023868)((undefined4 *)*param_3);
    uVar7 = *(undefined4 *)param_3[1];
    uVar4 = (*(code *)PTR_BN_num_bits_00023868)((undefined4 *)param_3[1]);
    iVar5 = (*local_34)(iVar6,0,param_1,local_48,local_38,local_3c,local_40,local_44,uVar10,uVar1,
                        uVar9,uVar2,uVar8,uVar3,uVar7,uVar4,local_5c[0],&local_60);
    if (iVar5 == 0) {
      uVar1 = 1;
      (**(code **)(PTR_DAT_000237a8 + 0x389c))(iVar6);
      goto LAB_00011ed8;
    }
    (*(code *)(PTR_000237b4 + 0xef0))(0x67,0x6a,PTR_000237b4 + 0x325c,0x371);
    (**(code **)(PTR_DAT_000237a8 + 0x389c))(iVar6);
  }
  iVar6 = (*(code *)PTR_DSA_OpenSSL_00023810)();
  uVar1 = (**(code **)(iVar6 + 0xc))(param_1,param_2,param_3,param_4);
LAB_00011ed8:
  (*(code *)PTR_BN_clear_free_00023804)(local_30);
  return uVar1;
}

