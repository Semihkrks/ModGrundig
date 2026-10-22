
/* ArScanManager::resumeAutoScan() */

void __thiscall ArScanManager::resumeAutoScan(ArScanManager *this)

{
  int *piVar1;
  
  if (*(int *)(this + 0x6c) == 1) {
    piVar1 = (int *)MSrv_Control_TV::GetMSrvDtv(0);
    (**(code **)(*piVar1 + 300))(piVar1);
  }
  else if (*(int *)(this + 0x6c) == 2) {
    piVar1 = (int *)MSrv_Control_TV::GetMSrvAtv();
    (**(code **)(*piVar1 + 0xe8))(piVar1);
  }
  else {
    if (*(int *)(this + 0x6c) != 0) {
      printf("ASSERT FAIL: %s %s %d\n",&UNK_00fe4454,&UNK_00fe47b8,0x5b0);
                    /* WARNING: Subroutine does not return */
      abort();
    }
    if (this[0x95] == (ArScanManager)0x1) {
      piVar1 = (int *)MSrv_Control_TV::GetMSrvDtv(0);
      (**(code **)(*piVar1 + 300))(piVar1);
    }
    else {
      if (this[0x95] != (ArScanManager)0x2) {
        printf("undefine current state: %d\n",(uint)(byte)this[0x95]);
        printf("ASSERT FAIL: %s %s %d\n",&UNK_00fe4454,&UNK_00fe47b8,0x5ab);
                    /* WARNING: Subroutine does not return */
        abort();
      }
      piVar1 = (int *)MSrv_Control_TV::GetMSrvAtv();
      (**(code **)(*piVar1 + 0xe8))(piVar1);
    }
  }
  return;
}

