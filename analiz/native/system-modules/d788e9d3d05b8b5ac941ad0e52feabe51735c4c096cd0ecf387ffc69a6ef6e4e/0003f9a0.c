
void dbus_signature_iter_init(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[1] = param_1[1] & 0xfffffffe;
  param_1[1] = param_1[1] & 0xfffffffd;
  return;
}

