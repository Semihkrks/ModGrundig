
void MDrv_GOP_GWIN_ForceWrite_Update(int param_1,uint param_2,undefined1 param_3)

{
  if (*(char *)(*(int *)(param_1 + 4) + 0x12) != '\0') {
    *(undefined1 *)(param_1 + (param_2 & 0xff) + 0x18a2) = param_3;
  }
  *(undefined1 *)(param_1 + 0x18a0) = param_3;
  return;
}

