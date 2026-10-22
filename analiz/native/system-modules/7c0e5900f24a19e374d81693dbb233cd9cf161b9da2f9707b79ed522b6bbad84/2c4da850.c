
int mbsinit(mbstate_t *__ps)

{
  uint uVar1;
  
  uVar1 = 1;
  if (__ps != (mbstate_t *)0x0) {
    uVar1 = (uint)(__ps->__count == 0);
  }
  return uVar1;
}

