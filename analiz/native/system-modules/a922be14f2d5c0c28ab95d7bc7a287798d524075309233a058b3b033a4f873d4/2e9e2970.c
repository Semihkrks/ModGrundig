
void SSL_set_verify(SSL *s,int mode,callback *callback)

{
  s->generate_session_id = (GEN_SESSION_CB)mode;
  if (callback != (callback *)0x0) {
    s->verify_mode = (int)callback;
  }
  return;
}

