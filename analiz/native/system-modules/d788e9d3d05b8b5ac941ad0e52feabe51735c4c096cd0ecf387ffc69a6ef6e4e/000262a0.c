
void dbus_error_init(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = param_1[2] & 0xfffffffe | 1;
  return;
}

