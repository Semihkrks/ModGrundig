
/* ArChannelListFrame::FilterTypeToStringID(FILTER_TYPE) */

undefined4 __thiscall
ArChannelListFrame::FilterTypeToStringID(undefined4 param_1,undefined4 param_2)

{
  undefined4 uStack_10;
  
  switch(param_2) {
  case 0:
    uStack_10 = 0xc0f;
    break;
  case 1:
    uStack_10 = 0xcdd;
    break;
  case 2:
    uStack_10 = 0xece;
    break;
  case 3:
    uStack_10 = 0xc17;
    break;
  case 4:
    uStack_10 = 0xd64;
    break;
  case 5:
    uStack_10 = 0xf1c;
    break;
  case 6:
    uStack_10 = 0xf07;
    break;
  case 7:
    uStack_10 = 0xd51;
    break;
  case 8:
    uStack_10 = 0xd52;
    break;
  case 9:
    uStack_10 = 0xd53;
    break;
  case 10:
    uStack_10 = 0xd54;
    break;
  case 0xb:
    uStack_10 = 0xf00;
    break;
  case 0xc:
    uStack_10 = 0x10ec;
    break;
  default:
    uStack_10 = 0x3f3;
  }
  return uStack_10;
}

