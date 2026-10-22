
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void init(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 in_a2;
  undefined4 in_a3;
  code *pcVar4;
  undefined1 *puVar5;
  undefined4 in_stack_ffffffec;
  
                    /* Unresolved local var: void * resume@[???]
                       Unresolved local var: void * personality@[???]
                       Unresolved local var: void * handle@[???] */
  puVar5 = &_gp;
  iVar3 = -0x7fffffff;
  iVar1 = (*(code *)PTR___libc_dlopen_mode_2f777130)
                    (PTR___DT_MIPS_BASE_ADDRESS_2f777064 + 0x69d8,0x80000001);
  if (iVar1 != 0) {
    iVar3 = *(int *)(puVar5 + -0x7fdc) + 0x69e8;
    iVar2 = (**(code **)(puVar5 + -0x7e74))(iVar1,iVar3);
    if (iVar2 != 0) {
      iVar3 = *(int *)(puVar5 + -0x7fdc) + 0x69f8;
      iVar1 = (**(code **)(puVar5 + -0x7e74))(iVar1,iVar3);
      if (iVar1 != 0) {
        iVar3 = *(int *)(puVar5 + -0x7fe8);
        *(int *)(*(int *)(puVar5 + -0x7fe8) + 0x72a0) = iVar2;
        *(int *)(iVar3 + 0x72a4) = iVar1;
        return;
      }
    }
  }
  pcVar4 = *(code **)(puVar5 + -0x7f54);
  iVar1 = *(int *)(puVar5 + -0x7fdc) + 0x6a10;
  (*pcVar4)(iVar1);
  iVar2 = *(int *)(pcVar4 + 0x10ff0);
  if (*(int *)(iVar2 + 0x72a4) == 0) {
    (*(code *)(*(int *)(pcVar4 + 0x10ffc) + 0x5fb0))();
  }
                    /* WARNING: Could not recover jumptable at 0x2f7660fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar2 + 0x72a4))(iVar1,iVar3,in_a2,in_a3,puVar5,in_stack_ffffffec);
  return;
}

