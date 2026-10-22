
/* mlog_write_to_init(int, char const*, char const*) */

void mlog_write_to_init(int param_1,char *param_2,char *param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uVar6;
  
  puVar1 = PTR_DAT_2f5f4168;
  (*(code *)PTR_pthread_mutex_lock_2f5f41d0)(PTR_DAT_2f5f4168 + 0x42cc);
  if (*(undefined **)(puVar1 + 0x414c) == PTR_mlog_write_to_init_2f5f419c) {
    iVar5 = (*(code *)PTR___write_to_log_initialize_2f5f425c)();
    if (iVar5 < 0) {
      (*(code *)PTR_puts_2f5f41b0)(PTR___DT_MIPS_BASE_ADDRESS_2f5f4174 + 0x4074);
      uVar6 = (*(code *)PTR_open_2f5f4284)(PTR___DT_MIPS_BASE_ADDRESS_2f5f4174 + 0x40b4,0x80001);
      puVar4 = PTR_open_2f5f4284;
      puVar3 = PTR___DT_MIPS_BASE_ADDRESS_2f5f4174;
      puVar2 = PTR_DAT_2f5f4168;
      *(undefined4 *)(PTR_DAT_2f5f4168 + 0x4138) = uVar6;
      uVar6 = (*(code *)puVar4)(puVar3 + 0x40c4,0x80001);
      *(undefined4 *)(puVar2 + 0x4144) = uVar6;
      puVar3 = PTR_mlog_write_to_kernel_2f5f4264;
      iVar5 = *(int *)(puVar2 + 0x4138);
      *(undefined **)(PTR_DAT_2f5f4168 + 0x4148) = PTR___write_to_log_kernel_2f5f41c4;
      *(undefined **)(puVar1 + 0x414c) = puVar3;
      if (iVar5 < 0) {
        (*(code *)PTR_close_2f5f41ec)(iVar5);
        *(undefined4 *)(puVar2 + 0x4138) = 0xffffffff;
        *(undefined **)(puVar1 + 0x414c) = PTR_mlog_write_to_filter_2f5f4184;
      }
      if (*(int *)(puVar2 + 0x4144) < 0) {
        *(undefined4 *)(puVar2 + 0x4144) = *(undefined4 *)(PTR_DAT_2f5f4168 + 0x4138);
      }
    }
    else {
      (*(code *)PTR_puts_2f5f41b0)(PTR___DT_MIPS_BASE_ADDRESS_2f5f4174 + 0x40d4);
      puVar2 = PTR___write_to_log_kernel_hdr_2f5f4234;
      *(undefined **)(puVar1 + 0x414c) = PTR_mlog_write_to_kernel_2f5f4264;
      *(undefined **)(PTR_DAT_2f5f4168 + 0x4148) = puVar2;
    }
  }
  (*(code *)PTR_pthread_mutex_unlock_2f5f421c)(puVar1 + 0x42cc);
                    /* WARNING: Could not recover jumptable at 0x2f5e2cec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(puVar1 + 0x414c))(param_1,param_2,param_3);
  return;
}

