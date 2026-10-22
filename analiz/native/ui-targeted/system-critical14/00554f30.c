
/* ArCecController::PutDeviceIntoStandby() */

void ArCecController::PutDeviceIntoStandby(void)

{
  MSrv_CEC_Customer::GetInstance();
  MSrv_CEC_Customer::Set_CECStandbyDevice();
  return;
}

