
void MDrv_AVD_SetChannelChange(void)

{
  if (*(int *)(PTR_DAT_2efac2f8 + -0x3a3c) != 1) {
    return;
  }
  (*(code *)PTR_UtopiaIoctl_2efac458)(*(undefined4 *)PTR_ppAVDInstant_2efac41c,0x10,0);
  return;
}

