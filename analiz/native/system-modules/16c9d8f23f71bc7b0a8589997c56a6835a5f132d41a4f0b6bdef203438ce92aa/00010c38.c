
void UnicableChannelChange
               (undefined4 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
               undefined1 param_5,undefined4 param_6,undefined2 param_7,undefined2 param_8,
               undefined1 *param_9)

{
  undefined *puVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  
  puVar1 = PTR_UnicableConvertUBSlot_00021188;
  *param_9 = 0x5a;
  bVar2 = (*(code *)puVar1)(param_5);
  puVar1 = PTR_UnicableGetInputBank_000211ac;
  param_9[1] = bVar2;
  bVar3 = (*(code *)puVar1)(param_2,param_3,param_4);
  param_9[1] = bVar3 | bVar2;
  uVar4 = (*(code *)PTR_UnicableCalculateTuningWord_00021190)
                    (param_1,param_3,param_6,param_7,param_8,4);
  param_9[2] = (char)uVar4;
  param_9[1] = (byte)((ushort)uVar4 >> 8) | param_9[1];
  return;
}

