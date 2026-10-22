
bool_t xdr_ypupdate_args(XDR *param_1,ypupdate_args *param_2)

{
  int iVar1;
  bool_t bVar2;
  
  iVar1 = (*(code *)PTR_xdr_string_00035224)(param_1,param_2,0xffffffff);
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR_xdr_bytes_0003523c)
                      (param_1,&(param_2->key).yp_buf_val,&param_2->key,0xffffffff);
    if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x000159ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      bVar2 = (*(code *)PTR_xdr_bytes_0003523c)
                        (param_1,&(param_2->datum).yp_buf_val,&param_2->datum,0xffffffff);
      return bVar2;
    }
  }
  return 0;
}

