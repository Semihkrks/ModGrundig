
int pthread_spin_init(pthread_spinlock_t *__lock,int __pshared)

{
  *__lock = 0;
  return 0;
}

