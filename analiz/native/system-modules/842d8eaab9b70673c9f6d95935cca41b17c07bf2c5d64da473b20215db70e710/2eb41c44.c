
void jinit_phuff_encoder(int param_1)

{
  undefined4 *puVar1;
  int local_10;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x6c);
  *(undefined4 **)(param_1 + 0x16c) = puVar1;
  *puVar1 = PTR_LAB_2eb7452c + -0x10;
  for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
    puVar1[local_10 + 0x13] = 0;
    puVar1[local_10 + 0x17] = 0;
  }
  puVar1[0x10] = 0;
  return;
}

