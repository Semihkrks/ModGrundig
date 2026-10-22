
bool deleteMutex(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutex_destroy_2ef67d00)();
  return iVar1 == 0;
}

