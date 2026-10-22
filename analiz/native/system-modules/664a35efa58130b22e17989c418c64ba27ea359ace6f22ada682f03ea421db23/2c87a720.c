
int pthread_mutexattr_init(pthread_mutexattr_t *__attr)

{
  __attr->__align = 0;
  return 0;
}

