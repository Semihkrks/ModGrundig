
void ne_i18n_init(int param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_LAB_00049348;
  (*(code *)PTR_bindtextdomain_00049788)(PTR_LAB_00049348 + 0x52fc,PTR_LAB_00049348 + 0x7a60);
  if (param_1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00029f9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_bind_textdomain_codeset_00049410)(puVar1 + 0x52fc,param_1);
    return;
  }
  return;
}

