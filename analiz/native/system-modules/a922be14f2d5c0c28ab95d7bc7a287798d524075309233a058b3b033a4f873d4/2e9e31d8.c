
int SSL_CTX_load_verify_locations(SSL_CTX *ctx,char *CAfile,char *CApath)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x2e9e31e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509_STORE_load_locations_2ea0e434)(ctx->cert_store);
  return iVar1;
}

