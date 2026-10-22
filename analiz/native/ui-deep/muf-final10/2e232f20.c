
/* MMainFrame::UnsetFocus(unsigned long) */

undefined4 MMainFrame::UnsetFocus(ulong param_1)

{
  undefined4 *puVar1;
  MWidget *pMVar2;
  undefined4 *puVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0x7c);
  puVar3 = *(undefined4 **)(param_1 + 0x80);
  if (puVar1 != puVar3) {
    do {
      pMVar2 = (MWidget *)*puVar1;
      puVar1 = puVar1 + 2;
      if (pMVar2 != (MWidget *)0x0) {
        MWidget::SetFlag(pMVar2,4,0);
        puVar3 = *(undefined4 **)(param_1 + 0x80);
      }
    } while (puVar1 != puVar3);
  }
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return 1;
}

