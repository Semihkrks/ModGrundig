
void g_datalist_init(int param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00039c8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_g_atomic_pointer_set_0014af6c)(param_1,0);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00039cac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_IA__g_return_if_fail_warning_0014a43c)
            (PTR_LAB_0014a438 + 0x1fa0,PTR_LAB_0014a438 + 0x4318,PTR_LAB_0014a438 + 0x4200);
  return;
}

