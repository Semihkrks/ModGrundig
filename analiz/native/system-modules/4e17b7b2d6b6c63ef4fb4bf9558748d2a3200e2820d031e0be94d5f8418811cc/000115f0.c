
bool cca_rsa_verify(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
                   ,undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined4 uVar6;
  int local_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  int local_5c;
  undefined1 auStack_58 [8];
  undefined4 local_50;
  undefined4 local_4c;
  int *local_48;
  int *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 *local_34;
  int local_30 [2];
  undefined4 local_28;
  
  local_4c = *(undefined4 *)(PTR_00023424 + 0x32a0);
  local_50 = *(undefined4 *)(PTR_00023424 + 0x329c);
  local_70 = param_5;
  local_68 = 1;
  local_6c = 0;
  puVar1 = (undefined4 *)
           (*(code *)PTR_RSA_get_ex_data_0002345c)
                     (param_6,*(undefined4 *)(PTR_DAT_00023418 + 0x3310));
  local_60 = 0x24;
  local_64 = *puVar1;
  if ((param_1 == 4) || (param_1 == 0x40)) {
    local_48 = &local_38;
    local_38 = (*(code *)PTR_OBJ_nid2obj_00023464)(param_1);
    if (local_38 == 0) {
      uVar4 = 0x6d;
      puVar5 = PTR_00023424 + 0x302c;
      uVar6 = 0x288;
      goto LAB_000117a8;
    }
    if (*(int *)(local_38 + 0xc) == 0) {
      uVar4 = 0x65;
      puVar5 = PTR_00023424 + 0x302c;
      uVar6 = 0x28e;
      goto LAB_000117a8;
    }
    local_34 = &local_40;
    local_44 = local_30;
    local_40 = 5;
    local_3c = 0;
    local_30[0] = param_3;
    local_28 = param_2;
    local_60 = (*(code *)PTR_i2d_X509_SIG_00023468)(&local_48,0);
    iVar2 = (*(code *)PTR_RSA_size_000234d4)(param_6);
    if (iVar2 < local_60 + -1) goto LAB_00011794;
  }
  else {
    iVar2 = (*(code *)PTR_RSA_size_000234d4)(param_6);
    if (iVar2 < local_60 + -1) {
LAB_00011794:
      uVar4 = 0x6b;
      puVar5 = PTR_00023424 + 0x302c;
      uVar6 = 0x2a1;
      goto LAB_000117a8;
    }
  }
  puVar5 = PTR_00023424;
  if (param_1 == 0x40) {
    iVar3 = (*(code *)PTR_CRYPTO_malloc_000234c0)(iVar2 + 1,PTR_00023424 + 0x302c,0x2bf);
    if (iVar3 == 0) {
      puVar5 = puVar5 + 0x302c;
      uVar4 = 0x41;
      uVar6 = 0x2c1;
      local_5c = 0;
      goto LAB_000117a8;
    }
  }
  else {
    if (param_1 == 0x72) {
      if (param_3 != 0x24) {
        uVar4 = 0x6b;
        puVar5 = PTR_00023424 + 0x302c;
        uVar6 = 0x2a9;
LAB_000117a8:
        (*(code *)(PTR_00023424 + 0x1554))(0x6a,uVar4,puVar5,uVar6);
        return false;
      }
      local_60 = param_3;
      (**(code **)(PTR_DAT_00023418 + 0x3524))
                (&local_78,&local_74,&local_6c,auStack_58,&local_68,&local_50,&local_64,puVar1 + 1,
                 &local_60,param_2,&local_70,param_4);
      goto LAB_0001189c;
    }
    if (param_1 != 4) {
      return false;
    }
    iVar3 = (*(code *)PTR_CRYPTO_malloc_000234c0)(iVar2 + 1,PTR_00023424 + 0x302c,0x2b3);
    if (iVar3 == 0) {
      puVar5 = puVar5 + 0x302c;
      uVar4 = 0x41;
      uVar6 = 0x2b5;
      local_5c = 0;
      goto LAB_000117a8;
    }
  }
  local_5c = iVar3;
  (*(code *)PTR_i2d_X509_SIG_00023468)(&local_48,&local_5c);
  (**(code **)(PTR_DAT_00023418 + 0x3524))
            (&local_78,&local_74,&local_6c,auStack_58,&local_68,&local_50,&local_64,puVar1 + 1,
             &local_60,iVar3,&local_70,param_4);
  (*(code *)PTR_OPENSSL_cleanse_000234cc)(iVar3,iVar2 + 1);
  (*(code *)PTR_CRYPTO_free_000234ac)(iVar3);
LAB_0001189c:
  if (local_78 != 0) {
    return false;
  }
  return local_74 == 0;
}

