
/* ArCecController::ProccessUserRCInput(unsigned long) */

void __thiscall ArCecController::ProccessUserRCInput(ArCecController *this,ulong param_1)

{
  uint uVar1;
  
  uVar1 = MSrv_CEC_Customer::GetInstance();
  MSrv_CEC_Customer::ProccessUserRCInput(uVar1);
  return;
}

