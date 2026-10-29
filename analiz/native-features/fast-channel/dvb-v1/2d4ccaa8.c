
/* MSrv_DTV_Player_DVB::SetFastZapping(unsigned char) */

void __thiscall MSrv_DTV_Player_DVB::SetFastZapping(MSrv_DTV_Player_DVB *this,uchar param_1)

{
  undefined4 uVar1;
  
  printf("%s %d ... bEnable=%d \n",&UNK_2d597328,0x3708,param_1);
  if (*(int *)(this + 0x98) == 0) {
    puts("Error:m_pcAVMonitor is NULL ");
  }
  else {
    uVar1 = 2000;
    if (param_1 != '\0') {
      uVar1 = 200;
    }
    printf("Delay = %d\n",uVar1);
    MW_DTV_AVMonitor_Customer::SetAVSyncDelay(*(uint *)(this + 0x98));
  }
  printf("Exit %s %d ... bEnable=%d \n",&UNK_2d597328,0x371d,param_1);
  return;
}

