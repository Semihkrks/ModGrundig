
undefined4 surewarehk_init(undefined4 param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  code *local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  undefined4 *local_40;
  undefined *local_3c;
  undefined *local_38;
  undefined *local_34;
  undefined *local_30;
  int local_2c;
  
  local_a8 = *(undefined4 *)(PTR_00025204 + 0x4d94);
  local_ac = *(undefined4 *)(PTR_00025204 + 0x4d90);
  local_b0 = *(undefined4 *)(PTR_00025204 + 0x4d8c);
  local_a4 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  if (*(int *)(PTR_DAT_000251f8 + 0x5370) == 0) {
    iVar2 = (*(code *)PTR_DSO_load_000252a0)(0,*(undefined4 *)(PTR_DAT_000251f8 + 0x501c),0,0);
    *(int *)(PTR_DAT_000251f8 + 0x5370) = iVar2;
    if (iVar2 == 0) {
      uVar3 = 0x1df;
    }
    else {
      local_54 = (code *)(*(code *)PTR_DSO_bind_func_00025248)
                                   (iVar2,*(undefined4 *)(PTR_DAT_000251f8 + 0x5020));
      if (((((local_54 != (code *)0x0) &&
            (local_58 = (*(code *)PTR_DSO_bind_func_00025248)
                                  (*(undefined4 *)(PTR_DAT_000251f8 + 0x5370),
                                   *(undefined4 *)(PTR_DAT_000251f8 + 0x5024)), local_58 != 0)) &&
           (local_5c = (*(code *)PTR_DSO_bind_func_00025248)
                                 (*(undefined4 *)(PTR_DAT_000251f8 + 0x5370),
                                  *(undefined4 *)(PTR_DAT_000251f8 + 0x5028)), local_5c != 0)) &&
          (((local_60 = (*(code *)PTR_DSO_bind_func_00025248)
                                  (*(undefined4 *)(PTR_DAT_000251f8 + 0x5370),
                                   *(undefined4 *)(PTR_DAT_000251f8 + 0x502c)), local_60 != 0 &&
            (local_64 = (*(code *)PTR_DSO_bind_func_00025248)
                                  (*(undefined4 *)(PTR_DAT_000251f8 + 0x5370),
                                   *(undefined4 *)(PTR_DAT_000251f8 + 0x5030)), local_64 != 0)) &&
           ((local_68 = (*(code *)PTR_DSO_bind_func_00025248)
                                  (*(undefined4 *)(PTR_DAT_000251f8 + 0x5370),
                                   *(undefined4 *)(PTR_DAT_000251f8 + 0x5034)), local_68 != 0 &&
            ((local_6c = (*(code *)PTR_DSO_bind_func_00025248)
                                   (*(undefined4 *)(PTR_DAT_000251f8 + 0x5370),
                                    *(undefined4 *)(PTR_DAT_000251f8 + 0x5038)), local_6c != 0 &&
             (local_70 = (*(code *)PTR_DSO_bind_func_00025248)
                                   (*(undefined4 *)(PTR_DAT_000251f8 + 0x5370),
                                    *(undefined4 *)(PTR_DAT_000251f8 + 0x503c)),
             puVar4 = PTR_DAT_000251f8, local_70 != 0)))))))) &&
         ((local_44 = (*(code *)PTR_DSO_bind_func_00025248)
                                (*(undefined4 *)(PTR_DAT_000251f8 + 0x5370),
                                 *(undefined4 *)(PTR_DAT_000251f8 + 0x5040)), local_44 != 0 &&
          ((((local_48 = (*(code *)PTR_DSO_bind_func_00025248)
                                   (*(undefined4 *)(puVar4 + 0x5370),
                                    *(undefined4 *)(PTR_DAT_000251f8 + 0x5044)), local_48 != 0 &&
             (local_4c = (*(code *)PTR_DSO_bind_func_00025248)
                                   (*(undefined4 *)(puVar4 + 0x5370),
                                    *(undefined4 *)(PTR_DAT_000251f8 + 0x5048)), local_4c != 0)) &&
            (local_50 = (*(code *)PTR_DSO_bind_func_00025248)
                                  (*(undefined4 *)(puVar4 + 0x5370),
                                   *(undefined4 *)(PTR_DAT_000251f8 + 0x504c)), local_50 != 0)) &&
           (iVar2 = (*(code *)PTR_DSO_bind_func_00025248)
                              (*(undefined4 *)(puVar4 + 0x5370),
                               *(undefined4 *)(PTR_DAT_000251f8 + 0x5050)),
           puVar4 = PTR_DAT_000251f8, iVar2 != 0)))))) {
        local_34 = PTR_DAT_000251f8;
        local_3c = PTR_DAT_000251f8;
        local_38 = PTR_DAT_000251f8;
        local_30 = PTR_DAT_000251f8;
        local_40 = &local_b0;
        uVar3 = *(undefined4 *)(PTR_DAT_000251f8 + 0x506c);
        *(int *)(PTR_DAT_000251f8 + 0x5374) = local_58;
        *(int *)(puVar4 + 0x5360) = local_4c;
        *(int *)(puVar4 + 0x5340) = local_5c;
        *(int *)(puVar4 + 0x534c) = local_60;
        *(int *)(puVar4 + 0x536c) = local_64;
        *(int *)(puVar4 + 0x5364) = local_68;
        *(int *)(puVar4 + 0x537c) = local_6c;
        *(int *)(puVar4 + 0x5358) = local_70;
        *(int *)(puVar4 + 0x535c) = local_44;
        *(int *)(puVar4 + 0x5354) = local_48;
        *(int *)(puVar4 + 0x5368) = local_50;
        *(int *)(puVar4 + 0x5350) = iVar2;
        *(code **)(puVar4 + 0x5378) = local_54;
        iVar2 = (*local_54)(local_40,uVar3);
        if (iVar2 == -3) {
          uVar3 = 0x21c;
        }
        else {
          local_2c = -3;
          iVar2 = (**(code **)(local_3c + 0x5378))
                            (local_40,*(undefined4 *)(PTR_DAT_000251f8 + 0x506c));
          puVar1 = PTR_DAT_000251f8;
          if (iVar2 != local_2c) {
            (*(code *)(PTR_00025204 + 0x3754))(param_1,0,0,0);
            if (*(int *)(puVar1 + 0x5064) == -1) {
              uVar3 = (*(code *)PTR_RSA_get_ex_new_index_00025294)
                                (0,PTR_00025204 + 0x4740,0,0,PTR_00025204 + 0x139c);
              *(undefined4 *)(puVar1 + 0x5064) = uVar3;
            }
            puVar4 = PTR_DAT_000251f8;
            if (*(int *)(PTR_DAT_000251f8 + 0x5060) != -1) {
              return 1;
            }
            uVar3 = (*(code *)PTR_DSA_get_ex_new_index_00025250)
                              (0,PTR_00025204 + 0x475c,0,0,PTR_00025204 + 0x139c);
            *(undefined4 *)(puVar4 + 0x5060) = uVar3;
            return 1;
          }
          uVar3 = 0x220;
        }
        (*(code *)(PTR_00025204 + 0x1300))(0x68,0x68,PTR_00025204 + 0x4730,uVar3);
        goto LAB_00013ccc;
      }
      uVar3 = 0x209;
    }
    (*(code *)(PTR_00025204 + 0x1300))(0x68,0x68,PTR_00025204 + 0x4730,uVar3);
    puVar4 = PTR_DAT_000251f8;
    local_3c = PTR_DAT_000251f8;
    local_38 = PTR_DAT_000251f8;
    local_34 = PTR_DAT_000251f8;
    local_30 = PTR_DAT_000251f8;
  }
  else {
    (*(code *)(PTR_00025204 + 0x1300))(0x68,100,PTR_00025204 + 0x4730,0x1d9);
    puVar4 = PTR_DAT_000251f8;
    local_3c = PTR_DAT_000251f8;
    local_38 = PTR_DAT_000251f8;
    local_34 = PTR_DAT_000251f8;
    local_30 = PTR_DAT_000251f8;
  }
LAB_00013ccc:
  if (*(int *)(PTR_DAT_000251f8 + 0x5370) != 0) {
    (*(code *)PTR_DSO_free_00025240)();
  }
  puVar1 = PTR_DAT_000251f8;
  *(undefined4 *)(local_30 + 0x534c) = 0;
  *(undefined4 *)(puVar1 + 0x5370) = 0;
  *(undefined4 *)(local_3c + 0x5378) = 0;
  *(undefined4 *)(local_34 + 0x5374) = 0;
  *(undefined4 *)(local_38 + 0x5340) = 0;
  *(undefined4 *)(puVar4 + 0x536c) = 0;
  *(undefined4 *)(puVar4 + 0x5364) = 0;
  *(undefined4 *)(puVar4 + 0x537c) = 0;
  *(undefined4 *)(puVar4 + 0x5358) = 0;
  *(undefined4 *)(puVar4 + 0x535c) = 0;
  *(undefined4 *)(puVar4 + 0x5354) = 0;
  *(undefined4 *)(puVar4 + 0x5360) = 0;
  *(undefined4 *)(puVar4 + 0x5368) = 0;
  *(undefined4 *)(puVar4 + 0x5350) = 0;
  return 0;
}

