
/* MW_DVB_SI_PSI_Parser::_UpdateServiceType(unsigned char*, unsigned char*, unsigned char) */

void __thiscall
MW_DVB_SI_PSI_Parser::_UpdateServiceType
          (MW_DVB_SI_PSI_Parser *this,uchar *param_1,uchar *param_2,uchar param_3)

{
  int iVar1;
  uchar local_resc [4];
  uchar local_18 [8];
  
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
    break;
  case '\x01':
    *param_1 = '\x01';
    return;
  case '\x02':
    *param_1 = '\x02';
    return;
  case '\x03':
    if (*(int *)(this + 0x168) != 0x19) goto code_r0x2d53c1f0;
    break;
  case '\n':
    *param_2 = '\0';
    *param_1 = '\x02';
    return;
  case '\f':
  case '\x10':
code_r0x2d53c1f0:
    *param_1 = '\x03';
    return;
  case '\x11':
  case '\x19':
    *param_2 = '\0';
    *param_1 = '\x01';
    return;
  case '\x16':
    *param_2 = '\x01';
    *param_1 = '\x01';
    return;
  }
  *param_1 = '\a';
  return;
}

