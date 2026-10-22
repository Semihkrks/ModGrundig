
void MDrv_HDCP22_InitCBFunc(int param_1)

{
  if (param_1 != 0) {
    *(int *)PTR_fpHdcp22RecMsgCBFunc_2de29858 = param_1;
  }
  return;
}

