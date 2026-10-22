
int usbhid_get_raw_report(int param_1,byte param_2,byte *param_3,short param_4,byte param_5)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  
  iVar1 = **(int **)(param_1 + 0xc58);
  uVar2 = (ushort)param_2;
  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0xe44) + 4) + 4);
  *param_3 = param_2;
  if (uVar2 == 0) {
    param_3 = param_3 + 1;
    param_4 = param_4 + -1;
  }
  iVar1 = (*(code *)&usb_control_msg)
                    (iVar1 + -0x70,*(int *)(iVar1 + -0x70) << 8 | 0x80000080,1,0xa1,
                     (param_5 + 1) * 0x100 | uVar2,*(undefined1 *)(iVar3 + 2),param_3,param_4,5000);
  if (0 < iVar1) {
    iVar1 = iVar1 + (uint)(uVar2 == 0);
  }
  return iVar1;
}

