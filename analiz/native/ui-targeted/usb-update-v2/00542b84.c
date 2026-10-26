
/* ArTvSettingsManager::CheckCustomerSWUpdate() */

undefined4 ArTvSettingsManager::CheckCustomerSWUpdate(void)

{
  IEnvManager *pIVar1;
  uint uVar2;
  int iVar3;
  char *__s1;
  undefined1 auStack_70 [16];
  IEnvManager_scope_lock aIStack_4c [4];
  undefined1 *puStack_48;
  char *pcStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  puStack_48 = auStack_70;
                    /* try { // try from 00542bbc to 00542c17 has its CatchHandler @ 00543068 */
  pIVar1 = (IEnvManager *)IEnvManager::Instance();
  if (pIVar1 == (IEnvManager *)0x0) {
    printf("\x1b[33m ERR:Environment Manager is NULL!\n\x1b[m");
    uStack_20 = 1;
  }
  else {
    IEnvManager_scope_lock::IEnvManager_scope_lock(aIStack_4c,pIVar1);
                    /* try { // try from 00542c2c to 00542ff7 has its CatchHandler @ 0054300c */
    uVar2 = IEnvManager::QueryLength((char *)pIVar1);
    printf("\x1b[33m .sZr size=%d!\n\x1b[m",uVar2);
    uStack_24 = 0;
    uStack_30 = uVar2 + 1;
    uStack_2c = (uint)(uStack_30 < uVar2);
    uStack_34 = 0;
    uStack_40 = uVar2 + 1;
    uStack_3c = (uint)(uStack_40 < uVar2);
    __s1 = &stack0xffffffa0 + -(uVar2 + 0xf & 0xfffffff8);
    pcStack_44 = __s1;
    uStack_38 = uVar2;
    uStack_28 = uVar2;
    memset(__s1,0,uVar2 + 1);
    (**(code **)(*(int *)pIVar1 + 0x20))(pIVar1,&UNK_00fe6740,__s1,uVar2);
    if (*__s1 == '\0') {
      printf("\x1b[33m No environment var, create one!\n\x1b[m");
      (**(code **)(*(int *)pIVar1 + 0x1c))(pIVar1,&UNK_00fe6740,&UNK_00fe6798);
      (**(code **)(*(int *)pIVar1 + 0xc))(pIVar1);
      uStack_20 = 2;
    }
    else {
      iVar3 = strcmp(__s1,"0");
      if (iVar3 == 0) {
        uStack_20 = 1;
      }
      else {
        iVar3 = strcmp(__s1,"1");
        if (iVar3 == 0) {
          (**(code **)(*(int *)pIVar1 + 0x1c))(pIVar1,&UNK_00fe6740,&UNK_00fe6798);
          (**(code **)(*(int *)pIVar1 + 0xc))(pIVar1);
          uStack_20 = 0;
        }
        else {
          (**(code **)(*(int *)pIVar1 + 0x1c))(pIVar1,&UNK_00fe6740,&UNK_00fe6798);
          (**(code **)(*(int *)pIVar1 + 0xc))(pIVar1);
          uStack_20 = 1;
        }
      }
    }
                    /* try { // try from 00543054 to 0054305b has its CatchHandler @ 00543068 */
    IEnvManager_scope_lock::~IEnvManager_scope_lock(aIStack_4c);
  }
  return uStack_20;
}

