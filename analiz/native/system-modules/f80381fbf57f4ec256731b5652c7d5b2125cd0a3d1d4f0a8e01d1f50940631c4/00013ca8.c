
bool hwcrhk_mutex_init(int *param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_CRYPTO_get_new_dynlockid_00024a3c)();
  *param_1 = iVar1;
  return iVar1 == 0;
}

