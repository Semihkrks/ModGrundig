
bool initMutex(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_init_2ef67ce0)(param_1,0);
  return iVar1 == 0;
}

