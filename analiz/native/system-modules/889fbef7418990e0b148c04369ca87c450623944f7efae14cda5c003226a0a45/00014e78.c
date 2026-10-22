
int yp_update(char *param_1,char *param_2,uint param_3,char *param_4,int param_5,char *param_6,
             int param_7)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined *puVar6;
  undefined4 uVar7;
  int local_158;
  undefined4 local_154;
  undefined1 auStack_150 [16];
  char *local_140;
  int local_13c;
  char *local_138;
  int local_134;
  char *local_130;
  undefined1 auStack_12c [260];
  
  if (param_1 == (char *)0x0) {
    return 1;
  }
  if (param_2 == (char *)0x0) {
    return 1;
  }
  if (param_4 == (char *)0x0) {
    return 1;
  }
  if ((param_3 != 3) && (param_6 == (char *)0x0)) {
    return 1;
  }
  local_13c = param_5;
  local_134 = param_7;
  local_130 = param_6;
  local_158 = 0;
  local_140 = param_2;
  local_138 = param_4;
  iVar1 = (*(code *)PTR_yp_master_0003504c)(param_1,param_2,&local_154);
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_host2netname_00035334)(auStack_12c,local_154,param_1);
    if (iVar1 == 0) {
      uVar2 = (*(code *)PTR___dcgettext_000352fc)
                        (PTR__libc_intl_domainname_00035228,PTR_LAB_00035018 + 0x2db8,5);
      (*(code *)PTR_fputs_00035350)(uVar2,*(undefined4 *)PTR_stderr_00035270);
      (*(code *)PTR_free_000352ac)(local_154);
      return 6;
    }
    piVar3 = (int *)(*(code *)PTR_clnt_create_000351cc)
                              (local_154,0x186bc,1,PTR_LAB_00035018 + 0x2de4);
    (*(code *)PTR_free_000352ac)(local_154);
    if (piVar3 == (int *)0x0) {
      (*(code *)PTR_clnt_pcreateerror_000351e4)(PTR_LAB_00035018 + 0x2de8);
      iVar1 = 2;
    }
    else {
      iVar1 = (**(code **)(piVar3[1] + 0x14))(piVar3,3,auStack_150);
      if (iVar1 == 0) {
        uVar2 = (*(code *)PTR___dcgettext_000352fc)
                          (PTR__libc_intl_domainname_00035228,PTR_LAB_00035018 + 0x2e00,5);
        (*(code *)PTR_fputs_00035350)(uVar2,*(undefined4 *)PTR_stderr_00035270);
        iVar1 = 2;
      }
      else {
        puVar6 = PTR_xdr_ypdelete_args_00035054;
        if (param_3 != 3) {
          puVar6 = PTR_xdr_ypupdate_args_00035050;
          if (param_3 < 4) {
            if (param_3 == 0) {
              return 1;
            }
          }
          else if (param_3 != 4) {
            return 1;
          }
        }
        iVar1 = (*(code *)PTR_authdes_create_00035264)(auStack_12c,0x3c,auStack_150,0);
        *piVar3 = iVar1;
        if (iVar1 == 0) {
          iVar1 = (*(code *)PTR_authunix_create_default_000352c0)();
          *piVar3 = iVar1;
        }
        uVar7 = *(undefined4 *)(PTR_LAB_00035018 + 0x2e94);
        uVar2 = *(undefined4 *)(PTR_LAB_00035018 + 0x2e98);
        while (iVar4 = (**(code **)piVar3[1])
                                 (piVar3,param_3,puVar6,&local_140,PTR_xdr_u_int_000351f8,&local_158
                                  ,uVar7,uVar2), iVar4 == 7) {
          piVar5 = (int *)*piVar3;
          if (*piVar5 != 3) {
            return 0xf;
          }
          (**(code **)(piVar5[8] + 0x10))(piVar5);
          iVar1 = (*(code *)PTR_authunix_create_default_000352c0)();
          *piVar3 = iVar1;
        }
        iVar1 = local_158;
        if (iVar4 != 0) {
          (*(code *)PTR_clnt_perror_000351c8)(piVar3,PTR_LAB_00035018 + 0x2e28);
          iVar1 = 2;
        }
      }
    }
  }
  return iVar1;
}

