
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* factoryuart_initMessageTable() */

void factoryuart_initMessageTable(void)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  
  puVar1 = PTR_cie_2f670040_2f670978;
  iVar2 = 0;
  piVar3 = (int *)(PTR_cie_2f670040_2f670978 + -0x1878);
  do {
    puVar1[*piVar3 + 0xd8c] = (char)iVar2;
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 9;
  } while (iVar2 != 0x92);
  return;
}

