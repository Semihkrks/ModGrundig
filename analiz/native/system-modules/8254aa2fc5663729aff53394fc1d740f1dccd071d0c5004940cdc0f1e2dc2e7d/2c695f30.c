
int feupdateenv(fenv_t *__envp)

{
  uint in_fcsr;
  
  (*(code *)PTR_fesetenv_2c719070)();
  (*(code *)PTR_feraiseexcept_2c719074)(in_fcsr & 0x7c);
  return 0;
}

