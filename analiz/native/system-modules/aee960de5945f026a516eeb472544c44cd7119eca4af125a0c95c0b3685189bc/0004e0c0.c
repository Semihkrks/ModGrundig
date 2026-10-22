
int * g_value_init(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  if (param_1 == (int *)0x0) {
    (*(code *)PTR_g_return_if_fail_warning_0006cb24)
              (PTR_LAB_0006c728 + 0x45d0,PTR_DAT_0006c888 + -0x4850,PTR_DAT_0006c888 + -0x499c);
    return (int *)0x0;
  }
  iVar1 = (*(code *)PTR_IA__g_type_check_is_value_type_0006c730)(param_2);
  puVar3 = PTR_IA__g_type_name_0006c748;
  if (iVar1 == 0) {
    if (*param_1 == 0) {
      uVar2 = (*(code *)PTR_IA__g_type_name_0006c748)(param_2);
      iVar1 = (*(code *)PTR_IA__g_type_value_table_peek_0006c740)(param_2);
      if (iVar1 == 0) {
        puVar3 = PTR_DAT_0006c888 + -0x4a64;
      }
      else {
        puVar3 = PTR_DAT_0006c888 + -0x4a34;
      }
      (*(code *)PTR_g_log_0006ca44)
                (PTR_LAB_0006c728 + 0x45d0,0x10,PTR_DAT_0006c888 + -0x49dc,
                 PTR_DAT_0006c888 + -0x49ac,uVar2,puVar3);
      return param_1;
    }
  }
  else if (*param_1 == 0) {
    puVar5 = (undefined4 *)(*(code *)PTR_IA__g_type_value_table_peek_0006c740)(param_2);
    *param_1 = param_2;
    param_1[2] = 0;
    param_1[5] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    (*(code *)*puVar5)(param_1);
    return param_1;
  }
  uVar2 = (*(code *)PTR_IA__g_type_name_0006c748)(param_2);
  uVar4 = (*(code *)puVar3)(*param_1);
  (*(code *)PTR_g_log_0006ca44)
            (PTR_LAB_0006c728 + 0x45d0,0x10,PTR_DAT_0006c888 + -0x4ad0,PTR_DAT_0006c888 + -0x4a74,
             uVar2,uVar4);
  return param_1;
}

