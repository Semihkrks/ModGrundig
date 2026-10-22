
void jinit_master_decompress(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x1c);
  *(undefined4 **)(param_1 + 0x1a4) = puVar1;
  *puVar1 = PTR_LAB_2eb7452c + 0x708c;
  puVar1[1] = PTR_LAB_2eb7452c + 0x742c;
  puVar1[2] = 0;
  (*(code *)(PTR_LAB_2eb7452c + 0x6b08))(param_1);
  return;
}

