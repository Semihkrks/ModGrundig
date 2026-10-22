
undefined4 * init_buffer(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(*(code *)PTR_ck_malloc_00444730)(0xc);
  uVar2 = (*(code *)PTR_ck_malloc_00444730)(0x32);
  puVar1[2] = uVar2;
  *puVar1 = 0x32;
  puVar1[1] = 0;
  return puVar1;
}

