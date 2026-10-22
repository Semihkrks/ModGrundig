
void jinit_input_controller(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x1c);
  *(undefined4 **)(param_1 + 0x1b4) = puVar1;
  *puVar1 = PTR_LAB_2eb74530 + -0x7e54;
  puVar1[1] = PTR_LAB_2eb74530 + -0x7c64;
  puVar1[2] = PTR_LAB_2eb74530 + -0x7f54;
  puVar1[3] = PTR_LAB_2eb74530 + -0x7e98;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 1;
  return;
}

