
void MDrv_TIMER_Init(void)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 local_10;
  undefined1 auStack_c [4];
  
  puVar2 = PTR_DAT_2f5d2608;
  cVar1 = PTR_DAT_2f5d2608[0x26c0];
  *(undefined4 *)(PTR_DAT_2f5d2608 + 0x26c4) = 0;
  *(undefined4 *)(puVar2 + 0x26e4) = 0xffffffff;
  *(undefined4 *)(puVar2 + 0x26e8) = 0;
  puVar2[0x26dc] = 0;
  *(undefined4 *)(puVar2 + 0x26c8) = 0xffffffff;
  *(undefined4 *)(puVar2 + 0x26cc) = 0;
  puVar2[0x26f8] = 0;
  *(undefined4 *)(puVar2 + 0x26e0) = 0;
  if (cVar1 == '\0') {
    iVar3 = (*(code *)PTR_MDrv_MMIO_GetBASE_2f5d2674)(&local_10,auStack_c,300);
    if (iVar3 != 0) {
      (*(code *)PTR_HAL_WDT_SetIOMapBase_2f5d266c)(local_10);
      puVar2[0x26c0] = 1;
      return;
    }
  }
  return;
}

