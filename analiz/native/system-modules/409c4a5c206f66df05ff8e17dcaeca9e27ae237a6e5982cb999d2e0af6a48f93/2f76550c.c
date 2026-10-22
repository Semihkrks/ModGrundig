
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void init_mq_netlink(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 local_c0;
  undefined1 auStack_bc [36];
  undefined1 auStack_98 [128];
  
                    /* Unresolved local var: int err@[???] */
  puVar1 = PTR_DAT_2f777058;
  if (*(int *)(PTR_DAT_2f777058 + 0x7040) == -1) {
    iVar3 = (*(code *)PTR_socket_2f777158)(0x10,3,0);
    *(int *)(puVar1 + 0x7040) = iVar3;
    if (iVar3 == -1) {
      return;
    }
    iVar3 = (*(code *)PTR_fcntl_2f7770f4)(iVar3,2,1);
    if (iVar3 != 0) goto LAB_2f765568;
  }
  iVar3 = (*(code *)PTR_pthread_barrier_init_2f777174)(PTR_DAT_2f777058 + 0x7268,0,2);
  if (iVar3 == 0) {
                    /* Unresolved local var: pthread_attr_t attr@[???]
                       Unresolved local var: sigset_t oss@[???]
                       Unresolved local var: int have_no_oss@[???]
                       Unresolved local var: pthread_t th@[???] */
    (*(code *)PTR_pthread_attr_init_2f77718c)(auStack_bc);
    (*(code *)PTR_pthread_attr_setdetachstate_2f7771ac)(auStack_bc,1);
    (*(code *)PTR_pthread_attr_setstacksize_2f777124)(auStack_bc,0x20000);
    iVar3 = (*(code *)(PTR___DT_MIPS_BASE_ADDRESS_2f777064 + 0x549c))(1,auStack_98);
    iVar4 = (*(code *)PTR_pthread_create_2f7770d8)
                      (&local_c0,auStack_bc,PTR___DT_MIPS_BASE_ADDRESS_2f777064 + 0x56e0,0);
    if (iVar3 == 0) {
      (*(code *)PTR_pthread_sigmask_2f777128)(3,auStack_98,0);
    }
    (*(code *)PTR_pthread_attr_destroy_2f7770f0)(auStack_bc);
    puVar2 = PTR_DAT_2f777058;
    if (iVar4 == 0) {
      if ((*(int *)(PTR_DAT_2f777058 + 0x7264) != 0) ||
         (iVar3 = (*(code *)PTR___pthread_atfork_2f7770bc)
                            (0,0,PTR___DT_MIPS_BASE_ADDRESS_2f777064 + 0x52a0), iVar3 == 0)) {
        *(undefined4 *)(puVar2 + 0x7264) = 1;
        return;
      }
      (*(code *)PTR_pthread_cancel_2f7770dc)(local_c0);
    }
  }
LAB_2f765568:
                    /* Unresolved local var: long __v0@[???]
                       Unresolved local var: long __a0@[???]
                       Unresolved local var: long __a3@[???] */
  syscall(0);
  *(undefined4 *)(puVar1 + 0x7040) = 0xffffffff;
  return;
}

