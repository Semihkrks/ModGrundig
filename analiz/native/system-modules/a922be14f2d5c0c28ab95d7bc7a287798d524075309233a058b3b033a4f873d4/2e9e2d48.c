
void SSL_CTX_set_verify(SSL_CTX *ctx,int mode,callback *callback)

{
  ctx->default_verify_callback = (_func_3238 *)callback;
  ctx->verify_mode = mode;
  return;
}

