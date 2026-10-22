
/* std::stringbuf::_M_stringbuf_init(std::_Ios_Openmode) */

void __thiscall std::stringbuf::_M_stringbuf_init(stringbuf *this,uint param_2)

{
  *(uint *)(this + 0x20) = param_2;
  if ((param_2 & 3) != 0) {
                    /* WARNING: Could not recover jumptable at 0x2c7b9950. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR__M_sync_2c826d78)
              (this,*(int *)(this + 0x24),0,*(undefined4 *)(*(int *)(this + 0x24) + -0xc));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x2c7b9964. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__M_sync_2c826d78)(this,*(undefined4 *)(this + 0x24),0,0);
  return;
}

