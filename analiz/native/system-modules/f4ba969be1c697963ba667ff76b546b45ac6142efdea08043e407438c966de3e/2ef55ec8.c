
bool initThread(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_create_2ef67d08)
                    (param_1 + 4,0,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
  return iVar1 == 0;
}

