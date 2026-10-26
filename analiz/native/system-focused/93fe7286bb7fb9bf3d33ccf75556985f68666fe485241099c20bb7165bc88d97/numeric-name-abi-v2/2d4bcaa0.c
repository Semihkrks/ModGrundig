
undefined4 FUN_2d4bcaa0(ushort *param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  
  *(uint *)(param_2 + 4) = (uint)*param_1;
  *(char *)(param_2 + 0xc) = (char)param_1[1];
  *(undefined1 *)(param_2 + 0xf) = *(undefined1 *)((int)param_1 + 7);
  *(char *)(param_2 + 0xd) = (char)param_1[2];
  *(undefined1 *)(param_2 + 0xe) = *(undefined1 *)((int)param_1 + 5);
  *(char *)(param_2 + 0x10) = (char)param_1[4];
  *(undefined1 *)(param_2 + 0x12) = *(undefined1 *)((int)param_1 + 9);
  *(char *)(param_2 + 0x13) = (char)param_1[10];
  *(ushort *)(param_2 + 0x20) = param_1[8];
  *(ushort *)(param_2 + 0x22) = param_1[9];
  *(ushort *)(param_2 + 0x26) = param_1[0x19];
  *(undefined1 *)(param_2 + 0x11) = *(undefined1 *)((int)param_1 + 3);
  std::string::assign((string *)(param_2 + 0x18));
  uVar2 = *(undefined4 *)(param_1 + 6);
  *(ushort *)(param_2 + 0x28) = param_1[0x1c];
  uVar1 = param_1[0x1d];
  *(undefined4 *)(param_2 + 0x1c) = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  *(ushort *)(param_2 + 0x2a) = uVar1;
  uVar1 = param_1[0x1e];
  *(undefined4 *)(param_2 + 0x14) = uVar2;
  *(ushort *)(param_2 + 0x2c) = uVar1;
  *(ushort *)(param_2 + 0x2e) = param_1[0x1f];
  *(ushort *)(param_2 + 0x30) = param_1[0x1a];
  *(ushort *)(param_2 + 0x32) = param_1[0x22];
  return 1;
}

