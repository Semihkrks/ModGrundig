
int SSL_CTX_set_default_verify_paths(SSL_CTX *ctx)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x2e9e3200. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509_STORE_set_default_paths_2ea0db18)(ctx->cert_store);
  return iVar1;
}

