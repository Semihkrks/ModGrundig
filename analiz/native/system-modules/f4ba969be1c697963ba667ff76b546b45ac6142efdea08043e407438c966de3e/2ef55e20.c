
bool initCondition(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_cond_init_2ef67d50)(param_1,0);
  return iVar1 == 0;
}

