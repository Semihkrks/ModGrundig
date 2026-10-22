
void remote_close(void)

{
                    /* WARNING: Could not recover jumptable at 0x0040343c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_close_00428104)(remote_desc);
  return;
}

