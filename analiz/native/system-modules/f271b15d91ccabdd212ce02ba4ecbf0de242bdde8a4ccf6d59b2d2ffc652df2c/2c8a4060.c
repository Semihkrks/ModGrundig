
void iw_print_txpower(char *buffer,int buflen,iw_param *txpower)

{
  undefined *puVar1;
  __s32 _Var2;
  
                    /* Unresolved local var: int dbm@[???] */
  if (txpower->disabled != '\0') {
                    /* WARNING: Could not recover jumptable at 0x2c8a40a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_snprintf_2c8b8294)(buffer,buflen,PTR___DT_MIPS_BASE_ADDRESS_2c8b8234 + 0x77f0);
    return;
  }
  if ((txpower->flags & 2) == 0) {
    _Var2 = txpower->value;
    if ((txpower->flags & 1) != 0) {
      _Var2 = (*(code *)PTR_iw_mwatt2dbm_2c8b8280)(_Var2);
    }
    puVar1 = PTR___DT_MIPS_BASE_ADDRESS_2c8b8234 + 0x77f4;
  }
  else {
    _Var2 = txpower->value;
    puVar1 = PTR___DT_MIPS_BASE_ADDRESS_2c8b8234 + 0x73f8;
  }
                    /* WARNING: Could not recover jumptable at 0x2c8a4110. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_snprintf_2c8b8294)(buffer,buflen,puVar1,_Var2);
  return;
}

