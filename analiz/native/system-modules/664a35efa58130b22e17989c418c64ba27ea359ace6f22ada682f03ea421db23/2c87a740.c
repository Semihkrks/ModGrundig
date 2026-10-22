
int pthread_mutexattr_getpshared(pthread_mutexattr_t *__attr,int *__pshared)

{
  *__pshared = (uint)__attr->__align >> 0x1f;
  return 0;
}

