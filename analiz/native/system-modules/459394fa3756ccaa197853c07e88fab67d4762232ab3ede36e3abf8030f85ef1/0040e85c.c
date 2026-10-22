
void initialize_mbcs(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (*(code *)PTR_locale_charset_00444660)();
  iVar2 = (*(code *)PTR_strcmp_004445dc)(uVar1,PTR_LAB_00444578 + 0x3460);
  *PTR_is_utf8_004445ac = iVar2 == 0;
  uVar1 = (*(code *)PTR___ctype_get_mb_cur_max_00444858)();
  *(undefined4 *)PTR_mb_cur_max_00444710 = uVar1;
  return;
}

