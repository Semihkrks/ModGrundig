
/* ArResourceManager::SetRemoteControl(unsigned long) */

undefined4 ArResourceManager::SetRemoteControl(ulong param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 5) {
                    /* WARNING: Could not emulate address calculation at 0x00619920 */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)((int)&_gp + *(int *)(PTR_s_13AutoSearchApp_010c4360 + param_1 * 4 + -0x53e0))
            )();
    return uVar1;
  }
  return 1;
}

