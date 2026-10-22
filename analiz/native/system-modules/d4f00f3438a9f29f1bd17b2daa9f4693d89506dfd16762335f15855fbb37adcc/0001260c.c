
void g_thread_init(int *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  if (*(int *)(PTR_DAT_000236d8 + 0x37d0) != 0) {
    if (param_1 == (int *)0x0) {
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x00012664. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_g_log_00023700)(PTR_000236e4 + 0x2d48,0x10,PTR_000236e4 + 0x3414);
    return;
  }
  *(undefined4 *)(PTR_DAT_000236d8 + 0x37d0) = 1;
  if (param_1 == (int *)0x0) {
    (*(code *)(PTR_000236e4 + 0x24f4))();
    param_1 = (int *)(PTR_DAT_000236d8 + 0x3670);
  }
  else {
    *(undefined4 *)PTR_g_thread_use_default_impl_00023708 = 0;
  }
  piVar5 = param_1;
  piVar6 = (int *)PTR_g_thread_functions_for_glib_use_0002375c;
  do {
    iVar10 = *piVar5;
    iVar9 = piVar5[1];
    iVar8 = piVar5[2];
    iVar7 = piVar5[3];
    piVar5 = piVar5 + 4;
    *piVar6 = iVar10;
    piVar6[1] = iVar9;
    piVar6[2] = iVar8;
    piVar6[3] = iVar7;
    puVar2 = PTR_g_thread_gettime_00023718;
    puVar1 = PTR_000236e4;
    piVar6 = piVar6 + 4;
  } while (piVar5 != param_1 + 0x14);
  *piVar6 = *piVar5;
  iVar7 = *param_1;
  *(undefined **)puVar2 = puVar1 + 0x16fc;
  puVar1 = PTR_DAT_000236d8;
  if (((((((iVar7 != 0) && (param_1[1] != 0)) && (param_1[2] != 0)) &&
        ((param_1[3] != 0 && (param_1[4] != 0)))) &&
       (((param_1[5] != 0 && ((param_1[6] != 0 && (param_1[7] != 0)))) && (param_1[8] != 0)))) &&
      ((((param_1[9] != 0 && (param_1[10] != 0)) && (param_1[0xb] != 0)) &&
       (((param_1[0xc] != 0 && (param_1[0xd] != 0)) &&
        ((param_1[0xe] != 0 && ((param_1[0xf] != 0 && (param_1[0x10] != 0)))))))))) &&
     ((param_1[0x11] != 0 && ((param_1[0x12] != 0 && (param_1[0x13] != 0)))))) {
    uVar4 = (*(code *)PTR_sched_get_priority_min_00023724)(0);
    puVar3 = PTR_sched_get_priority_max_00023780;
    puVar2 = PTR_DAT_000236d8;
    *(undefined4 *)(PTR_DAT_000236d8 + 0x37ec) = *(undefined4 *)(puVar1 + 0x37f8);
    *(undefined4 *)(puVar2 + 0x37e8) = uVar4;
    iVar7 = (*(code *)puVar3)(0);
    puVar3 = PTR_sched_get_priority_max_00023780;
    *(int *)(puVar2 + 0x37f0) = (iVar7 * 2 + *(int *)(puVar1 + 0x37f8)) / 3;
    uVar4 = (*(code *)puVar3)(0);
    *(undefined4 *)(puVar2 + 0x37f4) = uVar4;
                    /* WARNING: Could not recover jumptable at 0x00012850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_g_thread_init_glib_00023714)();
    return;
  }
  if (*(int *)PTR_g_thread_use_default_impl_00023708 == 0) {
    (*(code *)PTR_g_log_00023700)(PTR_000236e4 + 0x2d48,4,PTR_000236e4 + 0x348c);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  (*(code *)PTR_g_log_00023700)(PTR_000236e4 + 0x2d48,4,PTR_000236e4 + 0x3460);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

