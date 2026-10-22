
/* MW_DTV_Scan_DVBC_Customer::SetOPVariableInit(unsigned char, void*) */

void __thiscall
MW_DTV_Scan_DVBC_Customer::SetOPVariableInit
          (MW_DTV_Scan_DVBC_Customer *this,uchar param_1,void *param_2)

{
  *(void **)(this + 0xd8) = param_2;
  this[0xc3] = (MW_DTV_Scan_DVBC_Customer)param_1;
  return;
}

