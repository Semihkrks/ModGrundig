
undefined4 _VPU_EX_GetFrameBufferDefaultSize(undefined4 param_1)

{
  switch(param_1) {
  default:
    return 0;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
    return 0x1e00000;
  case 7:
  case 8:
    return 0x6c00000;
  case 9:
  case 10:
  case 0xc:
    return 0x1b00000;
  case 0xb:
    return 0x8200000;
  case 0xd:
    return 0x2800000;
  case 0xe:
    return 0x4200000;
  case 0xf:
    return 0x1500000;
  case 0x10:
    return 0xa000000;
  case 0x11:
    return 0x7800000;
  }
}

