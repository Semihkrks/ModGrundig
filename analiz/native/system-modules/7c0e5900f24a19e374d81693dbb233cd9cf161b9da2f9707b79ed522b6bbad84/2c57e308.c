
int sched_setaffinity(__pid_t __pid,size_t __cpusetsize,cpu_set_t *__cpuset)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x2c57e31c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_sched_setaffinity_2c67dafc)(__pid,0x80,__cpusetsize);
  return iVar1;
}

