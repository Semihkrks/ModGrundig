
/* std::stringbuf::_M_update_egptr() */

void __thiscall std::stringbuf::_M_update_egptr(stringbuf *this)

{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0x14);
  if ((uVar1 != 0) && (*(uint *)(this + 0xc) < uVar1)) {
    if ((*(uint *)(this + 0x20) & 8) != 0) {
      *(uint *)(this + 0xc) = uVar1;
      return;
    }
    *(uint *)(this + 0xc) = uVar1;
    *(uint *)(this + 4) = uVar1;
    *(uint *)(this + 8) = uVar1;
  }
  return;
}

