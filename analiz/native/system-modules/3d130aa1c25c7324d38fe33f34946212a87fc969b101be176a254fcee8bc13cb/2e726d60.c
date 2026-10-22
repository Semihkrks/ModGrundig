
undefined4 Curl_ssl_init(void)

{
  undefined *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  
  UNRECOVERED_JUMPTABLE = PTR_Curl_ossl_init_2e74fb5c;
  if (PTR_PTR_2e74f9e8[0x490] != '\0') {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x2e726d8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PTR_PTR_2e74f9e8[0x490] = 1;
  uVar1 = (*(code *)UNRECOVERED_JUMPTABLE)();
  return uVar1;
}

