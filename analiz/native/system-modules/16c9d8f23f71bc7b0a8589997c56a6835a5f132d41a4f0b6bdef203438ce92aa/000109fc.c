
void UnicablePowerOFF(undefined1 param_1,undefined1 *param_2)

{
  undefined *puVar1;
  undefined1 uVar2;
  
  puVar1 = PTR_UnicableConvertUBSlot_00021188;
  *param_2 = 0x5a;
  uVar2 = (*(code *)puVar1)(param_1);
  param_2[1] = uVar2;
  param_2[2] = 0;
  return;
}

