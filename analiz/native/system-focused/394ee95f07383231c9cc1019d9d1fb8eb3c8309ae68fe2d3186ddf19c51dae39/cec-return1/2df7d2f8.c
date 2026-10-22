
/* MSrv_CEC_Customer::ProccessUserRCInput(unsigned int) */

void __thiscall MSrv_CEC_Customer::ProccessUserRCInput(MSrv_CEC_Customer *this,uint param_1)

{
  MW_CEC_IrWrapper *this_00;
  
  this_00 = operator_new(1);
                    /* try { // try from 2df7d334 to 2df7d33b has its CatchHandler @ 2df7d398 */
  MW_CEC_IrWrapper::MW_CEC_IrWrapper(this_00);
  MW_CEC_IrWrapper::UnmappedIrEventReceivedCallbackFunc(this_00,param_1);
  if (this_00 != (MW_CEC_IrWrapper *)0x0) {
    MW_CEC_IrWrapper::~MW_CEC_IrWrapper(this_00);
                    /* WARNING: Could not recover jumptable at 0x2df7d37c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    operator_delete(this_00);
    return;
  }
  return;
}

