
/* MW_DTV_Scan_DVBC_Customer::ResetChannelDBScanParameters() */

void __thiscall
MW_DTV_Scan_DVBC_Customer::ResetChannelDBScanParameters(MW_DTV_Scan_DVBC_Customer *this)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (**(code **)(**(int **)(this + 0xd8) + 0x50))();
    uVar4 = uVar3;
    if (uVar1 <= uVar3) {
      return;
    }
    while( true ) {
      uVar3 = uVar4 + 1;
      iVar2 = (**(code **)(**(int **)(this + 0xd8) + 0x3c))(*(int **)(this + 0xd8),uVar4);
      if (iVar2 == 0) break;
      *(undefined1 *)(iVar2 + 0x25) = 0;
      uVar1 = (**(code **)(**(int **)(this + 0xd8) + 0x50))();
      uVar4 = uVar3;
      if (uVar1 <= uVar3) {
        return;
      }
    }
  } while( true );
}

