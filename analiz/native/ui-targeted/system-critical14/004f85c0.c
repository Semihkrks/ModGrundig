
/* ArScanManager::stopAutoScan() */

void __thiscall ArScanManager::stopAutoScan(ArScanManager *this)

{
  int *piVar1;
  
  if (*(int *)(this + 0x6c) != 3) {
    this[0x94] = (ArScanManager)0x3;
    if (this[0x95] == (ArScanManager)0x1) {
      this[0x96] = (ArScanManager)0x1;
      piVar1 = (int *)MSrv_Control_TV::GetMSrvDtv(0);
      (**(code **)(*piVar1 + 0x114))(piVar1);
    }
    else {
      piVar1 = (int *)MSrv_Control_TV::GetMSrvAtv();
      (**(code **)(*piVar1 + 0xec))(piVar1);
    }
    HandleAutoSearchNextState(this);
  }
  return;
}

