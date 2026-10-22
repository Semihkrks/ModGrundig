
void g_static_rec_mutex_free(int param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00094688. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_g_static_mutex_free_0014a8c4)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000946a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_IA__g_return_if_fail_warning_0014a43c)
            (PTR_LAB_0014a438 + 0x1fa0,PTR_DAT_0014a448 + -0xd04,PTR_DAT_0014a448 + -0xf60);
  return;
}

