
/* ArResourceManager::SetRemoteControl(unsigned long) */

undefined4 ArResourceManager::SetRemoteControl(ulong param_1)

{
  undefined4 uVar1;
  int in_t9;
  
  if (param_1 < 5) {
                    /* WARNING: Could not recover jumptable at 0x0061992c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(*(int *)(param_1 * 4 + *(int *)(in_t9 + 0xaaaa84) + -0x53e0) +
                      in_t9 + 0xab2a34))();
    return uVar1;
  }
  return 1;
}

