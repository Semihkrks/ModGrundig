
/* MW_DVB_SI_PSI_Parser_Customer::_UpdateServiceType(unsigned char*, unsigned char*, unsigned char)
    */

void __thiscall
MW_DVB_SI_PSI_Parser_Customer::_UpdateServiceType
          (MW_DVB_SI_PSI_Parser_Customer *this,uchar *param_1,uchar *param_2,uchar param_3)

{
  int iVar1;
  uchar local_resc [4];
  uchar local_18 [12];
  
  local_resc[0] = param_3;
  iVar1 = (**(code **)(*(int *)this + 700))(this,0,local_resc,local_18);
  if (iVar1 == 0) {
    local_resc[0] = '\0';
  }
  else {
    local_resc[0] = local_18[0];
  }
  *param_2 = '\x02';
  switch(local_resc[0]) {
  default:
    *param_1 = '\a';
    return;
  case '\x01':
    *param_2 = '\x03';
    *param_1 = '\x01';
    return;
  case '\x02':
    *param_1 = '\x02';
    return;
  case '\x03':
  case '\f':
    *param_1 = '\x03';
    return;
  case '\n':
    *param_2 = '\0';
    *param_1 = '\x02';
    return;
  case '\x11':
  case '\x19':
    *param_2 = '\x01';
    *param_1 = '\x01';
    return;
  case '\x16':
    *param_2 = '\x02';
    *param_1 = '\x01';
    return;
  case '\x1f':
    *param_2 = '\0';
    *param_1 = '\x01';
    return;
  }
}

