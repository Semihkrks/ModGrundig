
/* MW_DTV_Scan_DVBS_Customer::SetOPVariableInit(unsigned char, void*) */

void __thiscall
MW_DTV_Scan_DVBS_Customer::SetOPVariableInit
          (MW_DTV_Scan_DVBS_Customer *this,uchar param_1,void *param_2)

{
  *(void **)(this + 300) = param_2;
  this[0x1c7] = (MW_DTV_Scan_DVBS_Customer)param_1;
  return;
}

