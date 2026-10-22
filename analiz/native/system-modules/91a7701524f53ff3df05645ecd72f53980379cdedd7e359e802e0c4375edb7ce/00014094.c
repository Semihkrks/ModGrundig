
/* WARNING: Control flow encountered bad instruction data */

void usbhid_quirks_exit(void)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  undefined4 *puVar3;
  undefined **ppuVar4;
  
  (*(code *)&down_write)(dquirks_rwsem);
  ppuVar2 = *(undefined ***)dquirks_list;
  ppuVar1 = (undefined **)dquirks_list;
  if ((undefined **)dquirks_list != &dquirks_list) {
    do {
      ppuVar4 = ppuVar2;
      puVar3 = (undefined4 *)ppuVar1[1];
      *puVar3 = ppuVar4;
      ppuVar4[1] = (undefined *)puVar3;
      *ppuVar1 = (undefined *)0x100100;
      ppuVar1[1] = (undefined *)0x200200;
      (*(code *)&kfree)(ppuVar1 + -2);
      ppuVar2 = (undefined **)*ppuVar4;
      ppuVar1 = ppuVar4;
    } while (ppuVar4 != &dquirks_list);
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

