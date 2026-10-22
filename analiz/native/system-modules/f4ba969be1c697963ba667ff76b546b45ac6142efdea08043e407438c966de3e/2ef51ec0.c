
undefined4 FrHslV2InitialiseGroupIdFiltering(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_FrHslDynamicGroupIdArray_2ef67db0;
  *PTR_FrHslDynamicGroupIdArray_2ef67db0 = 1;
  puVar1[0x308] = 0;
  puVar1[0x200] = 0;
  puVar1[0x300] = 0;
  puVar1[0xc] = 0;
  return 1;
}

