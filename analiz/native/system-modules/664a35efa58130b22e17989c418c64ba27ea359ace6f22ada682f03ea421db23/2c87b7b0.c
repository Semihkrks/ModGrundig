
int pthread_rwlockattr_init(pthread_rwlockattr_t *__attr)

{
  *(char *)((int)__attr + 4) = '\0';
  *(char *)((int)__attr + 5) = '\0';
  *(char *)((int)__attr + 6) = '\0';
  *(char *)((int)__attr + 7) = '\0';
  __attr->__align = 0;
  return 0;
}

