
undefined1 png_get_channels(int param_1,int param_2)

{
  undefined1 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined1 *)(param_2 + 0x1d);
  }
  return uVar1;
}

