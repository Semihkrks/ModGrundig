
int ntfs_volume_alloc(void)

{
  int iVar1;
  
  iVar1 = 0x10;
  if ((iRam0004b254 == 0) ||
     (iVar1 = (*(code *)&kmem_cache_alloc_trace)(iRam0004b254,0x50,0xf0), iVar1 != 0)) {
    (*(code *)&memset)(iVar1,0,0xf0);
  }
  return iVar1;
}

